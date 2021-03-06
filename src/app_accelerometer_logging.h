/**
 * @file app_accelerometer_logging.h
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#ifndef APP_ACCELEROMETER_LOGGING_H
#define APP_ACCELEROMETER_LOGGING_H

#include "app_config.h" 
#if APP_SENSOR_LOGGING

#include "ruuvi_task_sensor.h"
#include "ruuvi_interface_communication.h"

/**
 * @brief Disable data logging for sensor
 *
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_disable_sensor_logging (void);

/**
 * @brief Disable data logging for sensor
 *
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_enable_sensor_logging(void);

/**
 * @brief Send last logged data sample using GATT
 *
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_acc_logging_send_last_sample(const ri_comm_xfer_fp_t reply_fp);

/**
 * @brief Send logged data from ringbuffer using GATT
 *
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_acc_logging_send_logged_data(const ri_comm_xfer_fp_t reply_fp);

/**
 * @brief Query state if logging is active
 *
 * @return RD_SUCCESS if logging is active
 * @return RD_ERROR_NOT_INITIALIZED if logging is not active
 */
rd_status_t app_acc_logging_state(void);

/**
 * @brief Handle Configuration Change
 * Check every configuration parameter if it should be changed 
 * and if its value is different than actual value. 
 * If a change is detected it clears the ringbuffer, updates the
 * configuration and stores the configuration in flash.
 *
 * @return Error code from stack
 */
rd_status_t app_acc_logging_configuration_set (rt_sensor_ctx_t* sensor, 
                          rd_sensor_configuration_t* new_config);

/**
 * @brief Initialize acceleration logging during boot.
 * When logging was not active before reboot this function 
 * return RD_SUCCESS without activiting acceleration logging.
 *
 * @return Error code from stack
 */
rd_status_t app_acc_logging_init(void);

/**
 * @brief Disable Logging when it is active.
 *
 * @return Error code from stack
 */
rd_status_t app_acc_logging_uninit(void);

#else
rd_status_t app_acc_logging_state(void);

#endif

#endif
