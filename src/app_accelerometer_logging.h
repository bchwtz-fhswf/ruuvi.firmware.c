/**
 * @file app_accelerometer_logging.h
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#ifndef APP_ACCELEROMETER_LOGGING_H
#define APP_ACCELEROMETER_LOGGING_H

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
 * @brief Query state if logging is active
 *
 * @return RD_SUCCESS if logging is active
 * @return RD_ERROR_NOT_INITIALIZED if logging is not active
 */
rd_status_t app_acc_logging_state(void);

#endif
