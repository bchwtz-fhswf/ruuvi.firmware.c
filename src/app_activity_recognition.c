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

#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (10)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (64)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (32)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)
static const float highpass_coefficients[] = {0.8279712956223768f, -0.8279712956223768f, 0.0f, 0.8272719459724756f, -0.0f, 1.0f, -2.0f, 1.0f, 1.7962798606327628f, -0.8286706452722776f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};

// Store acceleration data
static uint8_t current_size;
static float accdatastore[3][APP_ACTIVITY_RECOGNITION_INPUT_SIZE];

// highpass
static arm_biquad_casd_df1_inst_f32  highpass[3];
static float highpass_state[3][4*APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES];

// Load generated source code
//#include "model/model_33_randomforest.c"
#include "model/model_66_1_svm_dual.c"

static rd_status_t model_init(void) {

  rd_status_t err_code = RD_SUCCESS;

  current_size = APP_ACTIVITY_RECOGNITION_STEP_SIZE;

  // Instantiate high pass Filter
  arm_biquad_cascade_df1_init_f32(&highpass[0], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients, highpass_state[0]);
  arm_biquad_cascade_df1_init_f32(&highpass[1], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients, highpass_state[1]);
  arm_biquad_cascade_df1_init_f32(&highpass[2], APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES, highpass_coefficients, highpass_state[2]);

  return err_code;
}

static void prepare_data(const float* const accdata) {

  for(int j=0; j<3; j++) {
    // copy old value to front
    accdatastore[j][current_size-APP_ACTIVITY_RECOGNITION_STEP_SIZE] = accdatastore[j][current_size];

    float accdata_output = accdata[j];
    if(accdata_output>0.999999999f) {
      accdata_output = 0.999999999f;
    } else if(accdata_output<-1.0f) {
      accdata_output = -1.0f;
    }

    arm_biquad_cascade_df1_f32(&highpass[j], &accdata_output, &accdatastore[j][current_size], 1);
  }

  current_size += 1;
}

uint8_t value_crossings(float *in, float value) {
  uint8_t result = 0;
  float a = in[0];
  float b;

  for(uint8_t i=1; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    b = in[i];

    if( (a<value && b>value) || (a>-value && b<-value) || (a>value && b<value) || (a<-value && b>-value) ) {
      result++;
    }
    a = b;
  }

  return result;
}

void calc_pctfeatures(float *in, float *features, float percentile) {
  
  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {

    if(in[i]>percentile) {
      features[0]++; // countAbove
      features[2] += in[i]; // sumAbove
      features[4] += in[i]*in[i]; // sqSumAbove
    } else {
      features[1]++; // countBelow
      features[3] += in[i]; // sumBelow
      features[5] += in[i]*in[i]; // sqSumBelow
    }
  }
}

void calc_features(float *in, float *features) {

  uint32_t index;

  arm_std_f32(in, APP_ACTIVITY_RECOGNITION_INPUT_SIZE, &features[0]); // 0

  float absin[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];
  arm_abs_f32(in, absin, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  arm_min_f32(absin, APP_ACTIVITY_RECOGNITION_INPUT_SIZE, &features[1], &index); // 1
  arm_max_f32(absin, APP_ACTIVITY_RECOGNITION_INPUT_SIZE, &features[2], &index); // 2

  calc_pctfeatures(absin, features+3, 0.10f);  // 3 ,4 ,5 ,6 ,7 ,8
  features[9 ] = value_crossings(in, 0.10f);   // 9
  calc_pctfeatures(absin, features+10, 0.25f); // 10,11,12,13,14,15
  features[16] = value_crossings(in, 0.25f);   // 16
  calc_pctfeatures(absin, features+17, 0.50f); // 17,18,19,20,21,22
  features[23] = value_crossings(in, 0.50f);   // 23
  calc_pctfeatures(absin, features+24, 0.75f); // 24,25,26,27,28,29
  features[30] = value_crossings(in, 0.75f);   // 30
  calc_pctfeatures(absin, features+31, 0.90f); // 31,32,33,34,35,36
  features[37] = value_crossings(in, 0.90f);   // 37
}

rd_status_t app_har_predict(uint8_t *argmax, uint8_t output_to_save[]) {

  rd_status_t err_code = RD_SUCCESS;

  // Compute Features
  float xsq[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];
  float ysq[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];
  float zsq[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];
  float mag[APP_ACTIVITY_RECOGNITION_INPUT_SIZE];

  arm_mult_f32(accdatastore[0], accdatastore[0], xsq, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  arm_mult_f32(accdatastore[1], accdatastore[1], ysq, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  arm_mult_f32(accdatastore[2], accdatastore[2], zsq, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);

  arm_add_f32(xsq, ysq, mag, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  arm_add_f32(mag, zsq, mag, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);

  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    arm_sqrt_f32(mag[i], &mag[i]);
  }

  float features[APP_ACTIVITY_RECOGNITION_FEATURE_COUNT] = { 0 };

  // XYZ Magnitude Features
  calc_features(mag, features);

  #if APP_ACTIVITY_RECOGNITION_FEATURE_COUNT==152
  // XY Magnitude
  arm_add_f32(xsq, ysq, mag, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    arm_sqrt_f32(mag[i], &mag[i]);
  }
  calc_features(mag, features+38);

  // XZ Magnitude
  arm_add_f32(xsq, zsq, mag, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    arm_sqrt_f32(mag[i], &mag[i]);
  }
  calc_features(mag, features+38+38);

  // YZ Magnitude
  arm_add_f32(ysq, zsq, mag, APP_ACTIVITY_RECOGNITION_INPUT_SIZE);
  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_INPUT_SIZE; i++) {
    arm_sqrt_f32(mag[i], &mag[i]);
  }
  calc_features(mag, features+38+38+38);
  #endif

  // Run inference
#ifdef APP_ACTIVITY_RECOGNITION_MODEL_PRECISION_FLOAT
  float y_max = 0;
  float output[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
  score(features, output);
#else
  double y_max = 0;
  double output[APP_ACTIVITY_RECOGNITION_CLASS_COUNT];
  double features_dbl[APP_ACTIVITY_RECOGNITION_FEATURE_COUNT];
  for(uint16_t i=0; i<APP_ACTIVITY_RECOGNITION_FEATURE_COUNT; i++) features_dbl[i] =  features[i];
  score(features_dbl, output);
#endif

  // Read output (predicted y) of neural network
  *argmax = 0;

  // find argmax
  for(uint8_t i=0; i<APP_ACTIVITY_RECOGNITION_CLASS_COUNT; i++) {
    //LOGDf("Activity %d is %f\r\n", i, output[i]);
    output_to_save[i] = output[i]*256;
    if(output[i]>y_max) {
      y_max = output[i];
      *argmax = i;
    }
  }

  current_size = APP_ACTIVITY_RECOGNITION_INPUT_SIZE - APP_ACTIVITY_RECOGNITION_STEP_SIZE;

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

  return RD_SUCCESS;
}

rd_status_t app_har_collect_data(const float* const accdata) {

  rd_status_t err_code = RD_SUCCESS;

  prepare_data(accdata);

  if(current_size==APP_ACTIVITY_RECOGNITION_INPUT_SIZE) {

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

#if ENABLE_HAR //& RUUVI_RUN_TESTS
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

      if(current_size==APP_ACTIVITY_RECOGNITION_INPUT_SIZE) {
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
