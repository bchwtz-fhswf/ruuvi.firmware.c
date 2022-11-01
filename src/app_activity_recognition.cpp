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
#include "dsp/filtering_functions.h"
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
static tflite::MicroMutableOpResolver<8> micro_op_resolver;

// Create an area of memory to use for input, output, and other TensorFlow
// arrays. You'll need to adjust this by compiling, running, and looking
// for errors.
constexpr int kTensorArenaSize = 7 * 1024;
static __attribute__((aligned(16)))uint8_t tensor_arena[kTensorArenaSize];

// Highpass
#if APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
static arm_biquad_casd_df1_inst_f32 highpass[3];
static float32_t highpass_state[3][4*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];
#else
static q31_t highpass_coefficients_q31[5*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];
static arm_biquad_casd_df1_inst_q31 highpass[3];
static q31_t highpass_state[3][4*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];
#endif

static uint8_t current_size;
static uint8_t model_input_size;
static float accdatastore[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];


rd_status_t app_har_predict(uint8_t *argmax, uint8_t output_to_save[]) {

  // copy datastore to input tensor
  float* model_input_buffer = interpreter->typed_input_tensor<float>(0);

  for(uint16_t i; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    model_input_buffer[i] = accdatastore[i];
  }

  // Run inference
  // Tensorflow overwrites its input tensor during Invoke
  TfLiteStatus tflite_status = interpreter->Invoke();
  if (tflite_status != kTfLiteOk)
  {
    LOGD("Invoke failed\r\n");
    return RD_ERROR_INTERNAL;
  }

  // Read output (predicted y) of neural network
  float* model_output = interpreter->typed_output_tensor<float>(0);
  float y_max = 0;
  *argmax = 0;

  // find argmax
  for(int i=0; i<APP_ACTIVITY_RECOGNITION_CLASS_COUNT; i++) {
    //LOGDf("Activity %d is %f\r\n", i, model_output[i]);
    output_to_save[i] = (uint8_t)(model_output[i]*255);
    if(model_output[i]>y_max) {
      y_max = model_output[i];
      *argmax = i;
    }
  }

  current_size = model_input_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE;

  return RD_SUCCESS;
}

rd_status_t model_init(void) {

  rd_status_t err_code = RD_SUCCESS;

  // See: https://www.tensorflow.org/lite/api_docs/cc/class/tflite/interpreter

  // Set up logging (modify tensorflow/lite/micro/debug_log.cc)
  error_reporter = new tflite::MicroErrorReporter();

  LOGD("Initializing TensorFlow Lite\r\n");

  // Map the model into a usable data structure
  model = tflite::GetModel(APP_ACTIVITY_MODEL_NAME);
  if (model->version() != TFLITE_SCHEMA_VERSION)
  {
    LOG("Model version does not match Schema\r\n");
    return RD_ERROR_INTERNAL;
  }

  TfLiteStatus tflite_status; 

  if(micro_op_resolver.GetRegistrationLength()==0) {
    // Pull in only needed operations (should match NN layers). Template parameter <n>
    // is number of ops to be added. Available ops:
    // tensorflow/lite/micro/kernels/micro_ops.h

    LOGD("Add FullyConnected\r\n");
    tflite_status = micro_op_resolver.AddFullyConnected();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add FullyConnected op\r\n");
      return RD_ERROR_INTERNAL;
    }

    LOGD("Add Maxpool2D\r\n");
    tflite_status = micro_op_resolver.AddMaxPool2D();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Maxpool2D op\r\n");
      return RD_ERROR_INTERNAL;
    }

    LOGD("Add Reshape\r\n");
    tflite_status = micro_op_resolver.AddReshape();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Reshape op\r\n");
      return RD_ERROR_INTERNAL;
    }

    LOGD("Add Conv2D\r\n");
    tflite_status = micro_op_resolver.AddConv2D();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Conv2D op\r\n");
      return RD_ERROR_INTERNAL;
    }

    LOGD("Add Softmax\r\n");
    tflite_status = micro_op_resolver.AddSoftmax();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add Softmax op\r\n");
      return RD_ERROR_INTERNAL;
    }

    LOGD("Add AddReduceMax\r\n"); // GlobalMaxPooling
    tflite_status = micro_op_resolver.AddReduceMax();
    if (tflite_status != kTfLiteOk)
    {
      LOG("Could not add AddReduceMax op\r\n");
      return RD_ERROR_INTERNAL;
    }

    #if !APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
      LOGD("Add Quatinze\r\n");
      tflite_status = micro_op_resolver.AddQuantize();
      if (tflite_status != kTfLiteOk)
      {
        LOG("Could not add Quantize op\r\n");
        return RD_ERROR_INTERNAL;
      }

      LOGD("Add Dequantize\r\n");
      tflite_status = micro_op_resolver.AddDequantize();
      if (tflite_status != kTfLiteOk)
      {
        LOG("Could not add Dequantize op\r\n");
        return RD_ERROR_INTERNAL;
      }
    #endif
  }

  // Build an interpreter to run the model with.
  LOGD("Allocate Interpreter\r\n");
  interpreter = new tflite::MicroInterpreter(
      model, micro_op_resolver, tensor_arena, kTensorArenaSize, error_reporter);

  // Allocate memory from the tensor_arena for the model's tensors.
  LOGD("Allocate Tensors\r\n");
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

  current_size = model_input_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE;

  // Instantiate High Pass Filter
#if APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
  for(int i=0; i<3; i++) {
    arm_biquad_cascade_df1_init_f32(&highpass[i], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients, highpass_state[i]);
  }
#else
  arm_float_to_q31(highpass_coefficients, highpass_coefficients_q31, sizeof(highpass_coefficients)/sizeof(float));
  for(int i=0; i<3; i++) {
    arm_biquad_cascade_df1_init_q31(&highpass[i], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients_q31, highpass_state[i], 2);
  }
#endif

  return err_code;
}

rd_status_t app_har_init(void) {

  rd_status_t err_code = RD_SUCCESS;

  // do selftest
  err_code |= app_har_selftest();

  if(err_code!=RD_SUCCESS) {
    return RD_ERROR_SELFTEST | err_code;
  }

  LOGD("HAR: Initialization\r\n");

  // Setup Model
  err_code |= model_init();

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
  err_code |= app_acc_logging_configuration_set(lis2dh12, &newConfiguration);

  return err_code;
}

rd_status_t app_har_uninit(void) {

  if(interpreter!=nullptr) {
    LOGD("HAR: Uninitialization\r\n");

    delete interpreter;
    delete error_reporter;

    interpreter = nullptr;
    error_reporter = nullptr;
  }

  return RD_SUCCESS;
}

void prepare_data(const float* const accdata) {

  for(int j=0; j<3; j++) {
    // copy old value to front
    accdatastore[j+(current_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE)*3] =  accdatastore[j+current_size*3];

#if APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
    arm_biquad_cascade_df1_f32(&highpass[j], &accdata[j], &accdatastore[j+current_size*3], 1);
#else
    // In order to avoid overflows completely the input signal must be scaled down by 2 bits and lie in the range [-0.25 +0.25).
    // see: https://www.keil.com/pack/doc/CMSIS/DSP/html/group__BiquadCascadeDF1.html#ga4e7dad0ee6949005909fd4fcf1249b79
    float accdata_output = accdata[j]*0.25f;
    if(accdata_output>0.249999999f) {
      accdata_output = 0.249999999f;
    } else if(accdata_output<-0.25f) {
      accdata_output = -0.25f;
    }
    q31_t filter_input;
    q31_t filter_output;
    arm_float_to_q31(&accdata_output, &filter_input, 1);
    arm_biquad_cascade_df1_q31(&highpass[j], &filter_input, &filter_output, 1);
    arm_q31_to_float(&filter_output, &accdatastore[j+current_size*3], 1);
#endif
  }

  current_size += 1;
}

rd_status_t app_har_collect_data(const float* const accdata) {

  rd_status_t err_code = RD_SUCCESS;

  prepare_data(accdata);

  if(current_size==model_input_size) {

    LOGD("HAR: Start prediction\r\n");

    uint8_t argmax;
    uint8_t output_to_save[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
    err_code |= app_har_predict(&argmax, output_to_save);

    LOGDf("Current activity is %s\r\n", APP_ACTIVITY_RECOGNITION_CLASSES[argmax]);

    // Save output
    err_code |= rt_flash_ringbuffer_write(APP_ACTIVITY_RECOGNITION_CLASS_COUNT, output_to_save);
  }

  return err_code;
}

#if 1 //RUUVI_RUN_TESTS
#include "app_activity_recognition_testdata.h"
rd_status_t app_har_selftest(void) {

    uint8_t confusion_matrix[APP_ACTIVITY_RECOGNITION_CLASS_COUNT][APP_ACTIVITY_RECOGNITION_CLASS_COUNT] = { 0 };

    LOGD("HAR: Start selftest\r\n");

    rd_status_t err_code = RD_SUCCESS;
    float accdatainput[3];

    err_code |= model_init();
    if(err_code!=RD_SUCCESS) {
        LOGD("Error initializing model\r\n");
        return err_code;
    }

    uint16_t y_count = 1;
    uint16_t ok = 0;
    uint16_t nok = 0;
    	
    for(uint16_t i=0; i<sizeof(har_x_test); i+=3) {
      accdatainput[0] = ((float)har_x_test[i]) * SCALING_FACTOR;
      accdatainput[1] = ((float)har_x_test[i+1]) * SCALING_FACTOR;
      accdatainput[2] = ((float)har_x_test[i+2]) * SCALING_FACTOR;
      prepare_data(accdatainput);

      if(current_size==model_input_size) {
        // Run inference
        uint8_t argmax;
        uint8_t output_to_save[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
        err_code |= app_har_predict(&argmax, output_to_save);

        if(y_count>-1 && har_y_test[y_count]>-1) {
          LOGDf("predicted %d/%d activity %s should be %s\r\n", 
            y_count+1, sizeof(har_y_test), APP_ACTIVITY_RECOGNITION_CLASSES[argmax], 
            APP_ACTIVITY_RECOGNITION_CLASSES[har_y_test[y_count]]);

          confusion_matrix[har_y_test[y_count]][argmax]++;

          if(argmax==har_y_test[y_count]) {
            ok++;
          } else {
            nok++;
          }
        }

        y_count++;

        if(y_count>=sizeof(har_y_test) || err_code!=RD_SUCCESS) {
          break;
        }
      }
    }

    err_code |= app_har_uninit();

    // print prediction result
    for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_CLASS_COUNT; i++) {
      for(uint8_t j=0; j<APP_ACTIVITY_RECOGNITION_CLASS_COUNT; j++) {
        LOGDf("%d   ", confusion_matrix[i][j]);
      }
      LOGD("\r\n");
    }

    float correct = 100.0f*ok/(ok+nok);

    LOGDf("HAR selftest: OK %d, NOK %d, correct %f%%\r\n", ok, nok, correct);

    LOGD("HAR: End selftest\r\n");

    return err_code;
}
#else
rd_status_t app_har_selftest(void) {
  return RD_SUCCESS;
}
#endif
