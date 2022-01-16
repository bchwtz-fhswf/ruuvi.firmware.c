/**
 * @file app_activity_recognition.h
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-12-20
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <stdlib.h>

extern "C" {
#define INCLUDE_MODEL
#include "app_activity_recognition.h"

// Ruuvi Includes
#include "app_sensor.h"
#include "app_accelerometer_logging.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_task_flash_ringbuffer.h"

// Highpass Filter
#include "filter.h"
}

// Tensorflow Includes
#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"

#if RI_LOG_ENABLED
#include <stdio.h>
#include <stdarg.h>

static inline void LOG (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_INFO, msg);
}

static inline void LOGD (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_DEBUG, msg);
}

static inline void LOGDf (const char * const msg, ...)
{
    char fmsg[RD_LOG_BUFFER_SIZE];
    va_list args;
    *fmsg = 0;
    va_start(args, msg);
    vsnprintf(fmsg, RD_LOG_BUFFER_SIZE, msg, args);
    va_end(args);
    ri_log (RI_LOG_LEVEL_DEBUG, fmsg);
}
#else
#define LOG(...) 
#define LOGD(...)
#define LOGDf(...)
#define snprintf(...)
#endif

// TFLite globals
static tflite::ErrorReporter* error_reporter = nullptr;
static const tflite::Model* model = nullptr;
static tflite::MicroInterpreter* interpreter = nullptr;
static tflite::MicroMutableOpResolver<7> micro_op_resolver;

// Create an area of memory to use for input, output, and other TensorFlow
// arrays. You'll need to adjust this by compiling, running, and looking
// for errors.
constexpr int kTensorArenaSize = 18 * 1024;
static __attribute__((aligned(16)))uint8_t tensor_arena[kTensorArenaSize];

// Highpass
static BWHighPass* highpass[] = { nullptr,nullptr,nullptr };

static uint8_t current_size;
static uint8_t model_input_size;


rd_status_t app_har_predict(void) {

  LOGD("HAR: Start prediction\r\n");

  // Run inference
  TfLiteStatus tflite_status = interpreter->Invoke();
  if (tflite_status != kTfLiteOk)
  {
    LOGD("Invoke failed");
    return RD_ERROR_INTERNAL;
  }

  // Read output (predicted y) of neural network
  uint8_t output_to_save[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
  float* model_output = interpreter->typed_output_tensor<float>(0);
  float y_max = 0;
  uint8_t argmax = 0;

  // find argmax
  for(int i=0; i<APP_ACTIVITY_RECOGNITION_CLASS_COUNT; i++) {
    //LOGDf("Activity %d is %f\r\n", i, model_output[i]);
    output_to_save[i] = (uint8_t)(model_output[i]*255);
    if(model_output[i]>y_max) {
      y_max = model_output[i];
      argmax = i;
    }
  }

  LOGDf("Current activity is %s\r\n", APP_ACTIVITY_RECOGNITION_CLASSES[argmax]);

  // Save output
  rt_flash_ringbuffer_write(APP_ACTIVITY_RECOGNITION_CLASS_COUNT, output_to_save);

  return RD_SUCCESS;
}

rd_status_t app_har_init(void) {

  // See: https://www.tensorflow.org/lite/api_docs/cc/class/tflite/interpreter

  // Set up logging (modify tensorflow/lite/micro/debug_log.cc)
  error_reporter = new tflite::MicroErrorReporter();

  LOGD("Initializing TensorFlow Lite");

  // Map the model into a usable data structure
  model = tflite::GetModel(APP_ACTIVITY_MODEL_NAME);
  if (model->version() != TFLITE_SCHEMA_VERSION)
  {
    LOG("Model version does not match Schema");
    return RD_ERROR_INTERNAL;
  }

  // Pull in only needed operations (should match NN layers). Template parameter <n>
  // is number of ops to be added. Available ops:
  // tensorflow/lite/micro/kernels/micro_ops.h
  TfLiteStatus tflite_status; 

  tflite_status = micro_op_resolver.AddFullyConnected();
  if (tflite_status != kTfLiteOk)
  {
    LOG("Could not add FullyConnected op");
    return RD_ERROR_INTERNAL;
  }

  tflite_status = micro_op_resolver.AddMaxPool2D();
  if (tflite_status != kTfLiteOk)
  {
    LOG("Could not add Maxpool2D op");
    return RD_ERROR_INTERNAL;
  }

  tflite_status = micro_op_resolver.AddReshape();
  if (tflite_status != kTfLiteOk)
  {
    LOG("Could not add Reshape op");
    return RD_ERROR_INTERNAL;
  }

  tflite_status = micro_op_resolver.AddConv2D();
  if (tflite_status != kTfLiteOk)
  {
    LOG("Could not add Conv2D op");
    return RD_ERROR_INTERNAL;
  }

  tflite_status = micro_op_resolver.AddSoftmax();
  if (tflite_status != kTfLiteOk)
  {
    LOG("Could not add Softmax op");
    return RD_ERROR_INTERNAL;
  }

  #if !APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
    tflite_status = micro_op_resolver.AddQuantize();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Quantize op");
      return RD_ERROR_INTERNAL;
    }

    tflite_status = micro_op_resolver.AddDequantize();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Dequantize op");
      return RD_ERROR_INTERNAL;
    }
  #endif

  // Build an interpreter to run the model with.
  interpreter = new tflite::MicroInterpreter(
      model, micro_op_resolver, tensor_arena, kTensorArenaSize, error_reporter);

  // Allocate memory from the tensor_arena for the model's tensors.
  tflite_status = interpreter->AllocateTensors();
  if (tflite_status != kTfLiteOk)
  {
    LOG("AllocateTensors() failed");
    return RD_ERROR_INTERNAL;
  }

  // Assign model input and output buffers (tensors) to pointers
  TfLiteTensor* model_input = interpreter->input(0);
  TfLiteTensor* model_output = interpreter->output(0);
  model_input_size = model_input->dims->data[1];

  // Print number of inputs
  LOGDf("Model has %d inputs\r\n", interpreter->inputs().size());

  // Print Input Type, see c_api_types.h
  LOGDf("Type of Input Tensor %d\r\n", model_input->type);
  // Print Input Shape
  LOGDf("Dimension of Input Tensor (");
  for(int i=0; i<model_input->dims->size; i++) {
    LOGDf("%d, ", model_input->dims->data[i]);
  }
  LOGD(")\r\n");

  // Print Output Type, see c_api_types.h
  LOGDf("Type of Output Tensor %d\r\n", model_output->type);
  // Print Output Shape
  LOGDf("Dimension of Output Tensor (");
  for(int i=0; i<model_output->dims->size; i++) {
    LOGDf("%d, ", model_output->dims->data[i]);
  }
  LOGD(")\r\n");

  current_size = 0;

  // Instantiate High Pass Filter
  highpass[0] = create_bw_high_pass_filter(APP_ACTIVITY_RECOGNITION_HIGHPASS_ORDER, 
      APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY, APP_ACTIVITY_RECOGNITION_HIGHPASS_CUTOFF);
  highpass[1] = create_bw_high_pass_filter(APP_ACTIVITY_RECOGNITION_HIGHPASS_ORDER, 
      APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY, APP_ACTIVITY_RECOGNITION_HIGHPASS_CUTOFF);
  highpass[2] = create_bw_high_pass_filter(APP_ACTIVITY_RECOGNITION_HIGHPASS_ORDER, 
      APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY, APP_ACTIVITY_RECOGNITION_HIGHPASS_CUTOFF);

  // Setup Sensor

  // find LIS2DH12
  rt_sensor_ctx_t *lis2dh12 = app_sensor_find("LIS2DH12");
  rd_sensor_configuration_t newConfiguration {
        .samplerate = APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY,
        .resolution = APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION,
        .scale = APP_ACTIVITY_RECOGNITION_SENSOR_SCALE,
        .dsp_function = RD_SENSOR_CFG_NO_CHANGE,
        .dsp_parameter = RD_SENSOR_CFG_NO_CHANGE,
        .mode = RD_SENSOR_CFG_NO_CHANGE,
        .reserved0 = APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER,
        .reserved1 = 0
    };

  // set new sensor configuration
  return app_acc_logging_configuration_set(lis2dh12, &newConfiguration);

}

rd_status_t app_har_uninit(void) {

  if(interpreter!=nullptr) {
    delete interpreter;
    delete error_reporter;

    interpreter = nullptr;
    error_reporter = nullptr;
    free_bw_high_pass(highpass[0]);
    free_bw_high_pass(highpass[1]);
    free_bw_high_pass(highpass[2]);
  }

  return RD_SUCCESS;
}

rd_status_t app_har_collect_data(const APP_ACTIVITY_RECOGNITION_PRECISION* const accdata, const int samples) {

  rd_status_t err_code = RD_SUCCESS;
  int i=0;
  int block;

  float* input = interpreter->typed_input_tensor<float>(0);

  while(i<samples) {
    if(samples-i>=model_input_size-current_size) {
      block = model_input_size-current_size;
    } else {
      block = samples;
    }

    int copy_start = current_size*3;
    for(int j=0; j<block*3; j++) {
      input[j+copy_start] = bw_high_pass(highpass[j%3], accdata[j]);
    }

    current_size += block;
    i += block;

    if(current_size==model_input_size) {
      err_code |= app_har_predict();

      // Copy data by step size
      current_size = model_input_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE;
      int copy_end = 3*(model_input_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE);
      for(int j=0; j<copy_end; j++) {
        input[j] = input[j+APP_ACTIVITY_RECOGNITION_STEP_SIZE*3];
      }
    }
  }

  return err_code;
}

