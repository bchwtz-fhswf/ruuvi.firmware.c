/**
 * @file app_activity_recognition.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-12-20
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <stdlib.h>

#include "app_activity_recognition.h"

#ifndef ENABLE_HAR
#define ENABLE_HAR 1
#endif

#if ENABLE_HAR

#include "nnom.h"

#define INCLUDE_MODEL
#include "model_46_nnom.h"

// Ruuvi Includes
#include "app_sensor.h"
#include "app_accelerometer_logging.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_task_flash_ringbuffer.h"

// CMSIS
#include "dsp/filtering_functions.h"
#include "dsp/basic_math_functions.h"
#include "dsp/statistics_functions.h"

#ifdef APP_ACTIVITY_RECOGNITION_FFT_SIZE
#include "dsp/transform_functions.h"
#endif

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

// Store acceleration data
static q31_t accdatastore[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];

// highpass
static q31_t highpass_coefficients_q31[5*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];
static arm_biquad_casd_df1_inst_q31 highpass[3];
static q31_t highpass_state[3][4*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];

// Model
static nnom_model_t *model = NULL;
static uint16_t current_size;
static uint8_t tensor_arena[8*1024];


static rd_status_t nnom_to_ruuvi_error(nnom_status_t nnom_err) {
  switch(nnom_err) {
    case NN_SUCCESS: return RD_SUCCESS;
    case NN_ARGUMENT_ERROR: return RD_ERROR_INVALID_PARAM;
    case NN_LENGTH_ERROR: return RD_ERROR_INVALID_LENGTH;
    case NN_SIZE_MISMATCH: return RD_ERROR_DATA_SIZE;
    case NN_NANINF: return RD_ERROR_INVALID_DATA;
    case NN_SINGULAR: return RD_ERROR_INVALID_DATA;
    case NN_TEST_FAILURE: return RD_ERROR_SELFTEST;
    case NN_NO_MEMORY: return  RD_ERROR_NO_MEM;
    default: return RD_ERROR_INTERNAL;
  }
}

static rd_status_t model_init(void) {

  nnom_status_t nnom_err = NN_SUCCESS;

  // Create and initialize model
  nnom_set_static_buf(tensor_arena, sizeof(tensor_arena));
  model = nnom_model_create(&nnom_err);

  rd_status_t err_code = nnom_to_ruuvi_error(nnom_err);

  if(err_code!=RD_SUCCESS) {
    LOG("Creating of model failed\r\n");
    return err_code;
  }

  err_code |= nnom_to_ruuvi_error(model_run(model));

  if(err_code!=RD_SUCCESS) {
    LOG("Compiling of model failed\r\n");
    return err_code;
  }

  current_size = APP_ACTIVITY_RECOGNITION_INPUT_SIZE/3 - APP_ACTIVITY_RECOGNITION_STEP_SIZE;

  // Instantiate high pass Filter
  arm_float_to_q31(highpass_coefficients, highpass_coefficients_q31, 5*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES);
  arm_biquad_cascade_df1_init_q31(&highpass[0], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients_q31, highpass_state[0], 2);
  arm_biquad_cascade_df1_init_q31(&highpass[1], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients_q31, highpass_state[1], 2);
  arm_biquad_cascade_df1_init_q31(&highpass[2], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients_q31, highpass_state[2], 2);

  return err_code;
}

static void prepare_data(const float* const accdata) {

  for(int j=0; j<3; j++) {
    // copy old value to front
    if(current_size-APP_ACTIVITY_RECOGNITION_INPUT_SIZE>=0) {
      accdatastore[j+(current_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE)*3] =  accdatastore[j+current_size*3];
    }

    // In order to avoid overflows completely the input signal must be scaled down by 2 bits and lie in the range [-0.25 +0.25).
    // see: https://www.keil.com/pack/doc/CMSIS/DSP/html/group__BiquadCascadeDF1.html#ga4e7dad0ee6949005909fd4fcf1249b79
    float accdata_output = accdata[j]*0.25f;
    if(accdata_output>0.249999999f) {
      accdata_output = 0.249999999f;
    } else if(accdata_output<-0.25f) {
      accdata_output = -0.25f;
    }
    q31_t filter_input;
    arm_float_to_q31(&accdata_output, &filter_input, 1);
    arm_biquad_cascade_df1_q31(&highpass[j], &filter_input, &accdatastore[j+current_size*3], 1);
  }

  current_size += 1;
}

rd_status_t app_har_predict(uint8_t *argmax, uint8_t output_to_save[]) {

  rd_status_t err_code = RD_SUCCESS;

#ifndef APP_ACTIVITY_RECOGNITION_FFT
  // Read data from temp memory
  arm_q31_to_q7(accdatastore, nnom_input_data, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
#else
  q31_t clip_max_q31;
  q31_t clip_min_q31;
  float clip_max_f32 = 16;
  float clip_min_f32 = -16;
  arm_float_to_q31(&clip_max_f32, &clip_max_q31, 1);
  arm_float_to_q31(&clip_min_f32, &clip_min_q31, 1);

  q31_t fftSrc[APP_ACTIVITY_RECOGNITION_FFT_SIZE];
  q31_t fftDstQ31[APP_ACTIVITY_RECOGNITION_FFT_SIZE*2];
  q7_t fftDstQ7[64*2];

  arm_rfft_instance_q31 fft;
  if(arm_rfft_init_q31(&fft, APP_ACTIVITY_RECOGNITION_FFT_SIZE, 0, 0)!=ARM_MATH_SUCCESS) {
    LOGD("FFT init failed\r\n");
    return RD_ERROR_INVALID_LENGTH;
  }

  for(int j=0; j<3; j++) {
    for(int k=0; k<APP_ACTIVITY_RECOGNITION_FFT_SIZE; k++) {
      fftSrc[k] = accdatastore[k*3+j];
    }
    
    // FFT ausführen
    arm_rfft_q31(&fft, fftSrc, fftDstQ31);

    // auf 32 clippen
    arm_clip_q31(fftDstQ31, fftDstQ31, clip_min_q31, clip_max_q31, APP_ACTIVITY_RECOGNITION_FFT_SIZE*2);

    // upscaling
    arm_shift_q31(fftDstQ31, 6, fftDstQ31, APP_ACTIVITY_RECOGNITION_FFT_SIZE*2);

    // in Q7 umwandeln
    arm_q31_to_q7(fftDstQ31, fftDstQ7, 64*2);

    // nur die ersten 64 Koeffizienten verwenden
    for(int k=0; k<64; k++) {
      #if APP_ACTIVITY_RECOGNITION_FFT_SKIP_IMAG
      nnom_input_data[k*3+j] = fftDstQ7[k*2]; // real
      #else
      nnom_input_data[k*6+j] = fftDstQ7[k*2]; // real
      nnom_input_data[k*6+j+1] = fftDstQ7[k*2+1]; // imag
      #endif
    }
  }
#endif

  // Run inference
  err_code |= nnom_to_ruuvi_error(model_run(model));

  // Read output (predicted y) of neural network
  int8_t y_max = 0;
  *argmax = 0;

  // find argmax
  for(int i=0; i<tensor_output0_dim[0]; i++) {
    //LOGDf("Activity %d is %d\r\n", i, nnom_output_data[i]);
    output_to_save[i] = nnom_output_data[i];
    if(nnom_output_data[i]>y_max) {
      y_max = nnom_output_data[i];
      *argmax = i;
    }
  }

  current_size -= APP_ACTIVITY_RECOGNITION_STEP_SIZE;

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

  err_code |= model_init();

  // find LIS2DH12
  rt_sensor_ctx_t *lis2dh12 = app_sensor_find("LIS2DH12");

  // Setup Sensor
  rd_sensor_configuration_t newConfiguration = {
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

  if(model!=NULL) {
    model_delete(model);
    model = NULL;
  }

  return RD_SUCCESS;
}

rd_status_t app_har_collect_data(const float* const accdata) {

  rd_status_t err_code = RD_SUCCESS;

  prepare_data(accdata);

  if(current_size*3==APP_ACTIVITY_RECOGNITION_INPUT_SIZE) {

    LOGD("HAR: Start prediction\r\n");

    uint8_t argmax;
    uint8_t output_to_save[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
    err_code |= app_har_predict(&argmax, output_to_save);

    LOGDf("Current activity is %s\r\n", APP_ACTIVITY_RECOGNITION_CLASSES[argmax]);

    // Save output
    err_code |= rt_flash_ringbuffer_write(APP_ACTIVITY_RECOGNITION_CLASS_COUNT, output_to_save);

  } else {
    return RD_STATUS_MORE_AVAILABLE;
  }
}
#else
rd_status_t app_har_init(void) {
  return RD_ERROR_NOT_ENABLED;
}
rd_status_t app_har_uninit(void) {
  return RD_ERROR_NOT_ENABLED;
}
rd_status_t app_har_collect_data(const float* const accdata) {
  return RD_ERROR_NOT_ENABLED;
}
#endif

#if !defined(APP_ACTIVITY_RECOGNITION_FFT_SIZE) & ENABLE_HAR & 1 //RUUVI_RUN_TESTS
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

      if(current_size*3==APP_ACTIVITY_RECOGNITION_INPUT_SIZE) {
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
