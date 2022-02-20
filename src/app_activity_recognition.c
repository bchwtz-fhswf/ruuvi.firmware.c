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

// Highpass Filter
#include "dsp/filtering_functions.h"

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


// Highpass
static q31_t lowpass_coefficients_q31[sizeof(lowpass_coefficients)/sizeof(float)];
static arm_biquad_casd_df1_inst_q31 lowpass[3];
static q31_t lowpass_state[3][4*APP_ACTIVITY_RECOGNITION_LOWPASS_ORDER];

// Model
static nnom_model_t *model = NULL;
static uint8_t current_size;
static uint8_t tensor_arena[8192];


rd_status_t nnom_to_ruuvi_error(nnom_status_t nnom_err) {
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

rd_status_t app_har_predict(void) {

  LOGD("HAR: Start prediction\r\n");

  //for(int i=0; i<192; i+=6) {
  //  LOGDf("%d: %04d %04d %04d %04d %04d %04d\r\n", (int8_t)(i/6), nnom_input_data[i+0], nnom_input_data[i+1]
  //    , nnom_input_data[i+2], nnom_input_data[i+3], nnom_input_data[i+4], nnom_input_data[i+5]);
  //}

  rd_status_t err_code = RD_SUCCESS;

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

  rd_status_t err_code = RD_SUCCESS;

  // Create and initialize model
  nnom_set_static_buf(tensor_arena, sizeof(tensor_arena));
  model = nnom_model_create();
  err_code |= nnom_to_ruuvi_error(model_run(model));

  current_size = 0;

  // Instantiate low pass Filter
  arm_float_to_q31(lowpass_coefficients, lowpass_coefficients_q31, sizeof(lowpass_coefficients)/sizeof(float));
  for(int i=0; i<3; i++) {
    arm_biquad_cascade_df1_init_q31(&lowpass[i], APP_ACTIVITY_RECOGNITION_LOWPASS_ORDER, lowpass_coefficients_q31, lowpass_state[i], 2);
  }

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
  }

  return RD_SUCCESS;
}

rd_status_t app_har_collect_data(float* const accdata) {

    rd_status_t err_code = RD_SUCCESS;

    // accdata is in the range +-1000*APP_ACTIVITY_RECOGNITION_SENSOR_SCALE

    for(uint8_t j=0; j<3; j++) {
      // In order to avoid overflows completely the input signal must be scaled down by 2 bits and lie in the range [-0.25 +0.25).
      // see: https://www.keil.com/pack/doc/CMSIS/DSP/html/group__BiquadCascadeDF1.html#ga4e7dad0ee6949005909fd4fcf1249b79
      accdata[j] = accdata[j]/(4.0f*1000.0f*APP_ACTIVITY_RECOGNITION_SENSOR_SCALE);
      q31_t filter_input;
      q31_t filter_output;
      float filter_output_f32;
      arm_float_to_q31(&accdata[j], &filter_input, 1);
      arm_biquad_cascade_df1_q31(&lowpass[j%3], &filter_input, &filter_output, 1);
      arm_q31_to_float(&filter_output, &filter_output_f32, 1);

      // Data must be feed to nnom_input_data which is defined in 3xCNN1d-GRU.h
      // Value should be in the range -127 to +127
      // multiply by 4 eleminates scale [-0.25 +0.25) which was needed for lowpass
      // divide by 2 eliminates possible addition when value after lowpass is subtracted from input value
      nnom_input_data[current_size] = (int8_t)roundf((accdata[j] - filter_output_f32) * 127.0f * 4.0f/2.0f);
      nnom_input_data[current_size+3] = (int8_t)roundf(filter_output_f32 * 127.0f * 4.0f/2.0f);

      current_size++;

      if(j%3==2) {
        current_size+=3;
      }
    }

    if(current_size==sizeof(nnom_input_data)) {
      err_code |= app_har_predict();

      // Copy data by step size
      uint8_t k=0;
      uint8_t copy_start = sizeof(nnom_input_data) - 6*APP_ACTIVITY_RECOGNITION_STEP_SIZE;
      for(uint8_t j=copy_start; j<sizeof(nnom_input_data); j++) {
        nnom_input_data[k++] = nnom_input_data[j];
      }
      current_size = 6*APP_ACTIVITY_RECOGNITION_STEP_SIZE;

      return err_code;

    } else {
      return RD_STATUS_MORE_AVAILABLE;
    }
}

