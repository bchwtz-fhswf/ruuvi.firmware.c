/**
 * @file app_activity_recognition.h
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-12-20
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#ifndef APP_ACTIVITY_RECOGNITION_H
#define APP_ACTIVITY_RECOGNITION_H

#include "ruuvi_driver_error.h"
#include "model_67_tensorflow.h"

#ifndef APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT 1
#endif

/**
 * Initialize activity recognition
 */
rd_status_t app_har_init(void);

/**
 * Uninitialize activity recognition
 */
rd_status_t app_har_uninit(void);

/**
 * Collect and predict acceleration data
 * accdata: Acceleration data
 */
rd_status_t app_har_collect_data(const float* const accdata);

/**
 * Perform Selftest
 */
rd_status_t app_har_selftest(void);

#endif
