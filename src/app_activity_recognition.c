/**
 * @file app_activity_recognition.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-12-20
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <stdlib.h>

#include "app_activity_recognition.h"

#include "nnom.h"
#include "3xCNN1d-GRU.h"

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
static float accdatastore[3][APP_ACTIVITY_RECOGNITION_STEP_SIZE];
static q31_t after_lowpass[6][APP_ACTIVITY_RECOGNITION_STEP_SIZE];

// Lowpass
static q31_t lowpass_coefficients_q31[sizeof(lowpass_coefficients)/sizeof(float)];
static arm_biquad_casd_df1_inst_q31 lowpass[3];
static q31_t lowpass_state_x[4*2];
static q31_t lowpass_state_y[4*2];
static q31_t lowpass_state_z[4*2];

// highpass
static q31_t highpass_coefficients_q31[sizeof(highpass_coefficients)/sizeof(float)];
static arm_biquad_casd_df1_inst_q31 highpass[3];
static q31_t highpass_state_x[4*2];
static q31_t highpass_state_y[4*2];
static q31_t highpass_state_z[4*2];

// Model
static nnom_model_t *model = NULL;
static uint8_t current_size;
static uint8_t tensor_arena[8192];


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

  rd_status_t err_code = RD_SUCCESS;

  // Create and initialize model
  nnom_set_static_buf(tensor_arena, sizeof(tensor_arena));
  model = nnom_model_create();
  err_code |= nnom_to_ruuvi_error(model_run(model));

  current_size = 0;

  // Instantiate low pass Filter
  arm_float_to_q31(lowpass_coefficients, lowpass_coefficients_q31, 10);
  arm_biquad_cascade_df1_init_q31(&lowpass[0], 2, lowpass_coefficients_q31, lowpass_state_x, 1);
  arm_biquad_cascade_df1_init_q31(&lowpass[1], 2, lowpass_coefficients_q31, lowpass_state_y, 1);
  arm_biquad_cascade_df1_init_q31(&lowpass[2], 2, lowpass_coefficients_q31, lowpass_state_z, 1);

  // Instantiate high pass Filter
  arm_float_to_q31(highpass_coefficients, highpass_coefficients_q31, 10);
  arm_biquad_cascade_df1_init_q31(&highpass[0], 2, highpass_coefficients_q31, highpass_state_x, 1);
  arm_biquad_cascade_df1_init_q31(&highpass[1], 2, highpass_coefficients_q31, highpass_state_y, 1);
  arm_biquad_cascade_df1_init_q31(&highpass[2], 2, highpass_coefficients_q31, highpass_state_z, 1);

  return err_code;
}

static void prepare_data(void) {

  q31_t before_lowpass[APP_ACTIVITY_RECOGNITION_STEP_SIZE];
  q31_t accdata_q31[2*APP_ACTIVITY_RECOGNITION_STEP_SIZE];
  q31_t gravitation_q31[2*APP_ACTIVITY_RECOGNITION_STEP_SIZE];
  
  float low_f32 = -0.25f;
  float high_f32 = 0.25f;
  q31_t low;
  q31_t high;
  arm_float_to_q31(&low_f32, &low, 1);
  arm_float_to_q31(&high_f32, &high, 1);
  
  // Prepare data per Channel
  for(uint8_t i=0; i<3; i++) {
    // copy last APP_ACTIVITY_RECOGNITION_STEP_SIZE bytes to first position
    for(uint8_t j=0; j<APP_ACTIVITY_RECOGNITION_STEP_SIZE; j++) {
      accdata_q31[j] = after_lowpass[i][j];
      gravitation_q31[j] = after_lowpass[i+3][j];
    }

    // Lowpass with Block Size equal to APP_ACTIVITY_RECOGNITION_STEP_SIZE

    // Convert to Q31 Format
    arm_float_to_q31(accdatastore[i], before_lowpass, APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // Lowpass
    arm_biquad_cascade_df1_q31(&highpass[i], before_lowpass, after_lowpass[i], APP_ACTIVITY_RECOGNITION_STEP_SIZE);
    arm_biquad_cascade_df1_q31(&lowpass[i], before_lowpass, after_lowpass[i+3], APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // copy next APP_ACTIVITY_RECOGNITION_STEP_SIZE bytes to last position
    for(uint8_t j=0; j<APP_ACTIVITY_RECOGNITION_STEP_SIZE; j++) {
      accdata_q31[j+APP_ACTIVITY_RECOGNITION_STEP_SIZE] = after_lowpass[i][j];
      gravitation_q31[j+APP_ACTIVITY_RECOGNITION_STEP_SIZE] = after_lowpass[i+3][j];
    }

    // next preprocessing with blocksize equal to blocksize of neural network

    // mean of gravitation
    q31_t gmean;
    arm_mean_q31(gravitation_q31, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE, &gmean);

    // remove gmean from gravitation
    arm_offset_q31(gravitation_q31, -gmean, gravitation_q31, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // Clip to range -0.25 to +0.25
    arm_clip_q31(accdata_q31, accdata_q31, low, high, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);
    arm_clip_q31(gravitation_q31, gravitation_q31, low, high, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // Upscale
    arm_shift_q31(accdata_q31, 2, accdata_q31, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);
    arm_shift_q31(gravitation_q31, 2, gravitation_q31, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // Convert to Q7
    q7_t accdata_q7[2*APP_ACTIVITY_RECOGNITION_STEP_SIZE];
    q7_t gravitation_q7[2*APP_ACTIVITY_RECOGNITION_STEP_SIZE];
    arm_q31_to_q7(accdata_q31, accdata_q7, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);
    arm_q31_to_q7(gravitation_q31, gravitation_q7, 2*APP_ACTIVITY_RECOGNITION_STEP_SIZE);

    // Feed neural network
    uint8_t k=0;
    for(uint8_t j=0; j<6*2*APP_ACTIVITY_RECOGNITION_STEP_SIZE; j+=6) {
      nnom_input_data[i+j] = accdata_q7[k];
      nnom_input_data[i+3+j] = gravitation_q7[k++];
    }
  }
}

rd_status_t app_har_predict(void) {

  LOGD("HAR: Start prediction\r\n");

  rd_status_t err_code = RD_SUCCESS;

  prepare_data();

  // Run inference
  err_code |= nnom_to_ruuvi_error(model_run(model));

  // Read output (predicted y) of neural network
  int8_t y_max = 0;
  uint8_t argmax = 0;

  // find argmax
  for(int i=0; i<tensor_output0_dim[0]; i++) {
    LOGDf("Activity %d is %d\r\n", i, nnom_output_data[i]);
    if(nnom_output_data[i]>y_max) {
      y_max = nnom_output_data[i];
      argmax = i;
    }
  }

  LOGDf("Current activity is %s\r\n", APP_ACTIVITY_RECOGNITION_CLASSES[argmax]);

  // Save output
  err_code |= rt_flash_ringbuffer_write(tensor_output0_dim[0], nnom_output_data);

  return err_code;
}

rd_status_t app_har_init(void) {

  LOGD("HAR: Initialization\r\n");

  rd_status_t err_code = model_init();

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

rd_status_t app_har_collect_data(float* const accdata) {

    rd_status_t err_code = RD_SUCCESS;

    // Scale from mG to G, also scale down because of potential overflow in CMSIS
    // In order to avoid overflows completely the input signal must be scaled down by 2 bits and lie in the range [-0.25 +0.25).
    // see: https://www.keil.com/pack/doc/CMSIS/DSP/html/group__BiquadCascadeDF1.html#ga4e7dad0ee6949005909fd4fcf1249b79
    accdatastore[0][current_size] = accdata[0]/(1000.0f*4.0f);
    accdatastore[1][current_size] = accdata[1]/(1000.0f*4.0f);
    accdatastore[2][current_size] = accdata[2]/(1000.0f*4.0f);
    current_size++;

    if(current_size==APP_ACTIVITY_RECOGNITION_STEP_SIZE) {
      err_code |= app_har_predict();

      current_size = 0;

      return err_code;

    } else {
      return RD_STATUS_MORE_AVAILABLE;
    }
}

#if RUUVI_RUN_TESTS
#include "app_activity_recognition_testdata.h"
rd_status_t app_har_selftest(void) {

    float prob;
    uint32_t label;
    nnom_predict_t * pre;

    LOGD("HAR: Start selftest\r\n");

    rd_status_t err_code = RD_SUCCESS;

    err_code |= model_init();
    if(err_code!=RD_SUCCESS) {
        LOGD("Error initializing model\r\n");
        return err_code;
    }
	
    pre = prediction_create(model, nnom_output_data, sizeof(nnom_output_data), 0); 

    for(uint16_t i=0; i<sizeof(har_y_test); i++) {
      for(uint16_t j=0; j<APP_ACTIVITY_RECOGNITION_STEP_SIZE; j++) {
        for(uint16_t k=0; k<3; k++) {
          accdatastore[k][j] = ((float)har_x_test[i][j*3+k]) * SCALING_FACTOR;
        }
      }

      if(i%10==0) {
        LOGDf("predicting %d/%d\r\n", i, sizeof(har_y_test));
      }

      prepare_data();
	
      // Run inference
      err_code = model_run(model);
      prediction_run(pre, har_y_test[i], &label, &prob);  // this provide more infor but requires prediction API

      if(err_code!=RD_SUCCESS) {
        break;
      }
    }

    err_code |= app_har_uninit();

    // print prediction result
    prediction_end(pre);
    prediction_summary(pre);
    prediction_delete(pre);

    LOGD("HAR: End selftest\r\n");

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}
#endif
