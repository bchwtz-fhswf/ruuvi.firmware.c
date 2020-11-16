/**
 * @file app_accelerometer_logging.h
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#ifndef APP_ACCELEROMETER_LOGGING_H
#define APP_ACCELEROMETER_LOGGING_H

#include "ruuvi_driver_error.h"
#include "ruuvi_task_sensor.h"

typedef rd_status_t (*rd_sensor_read_raw_fp) (uint8_t * const p_data);

/**
 * @brief Interface to sensor with logging to flash.
 */
typedef struct rd_sensor_logging_t
{
    /** @brief sensor */
    rd_sensor_t * p_sensor;
    /** @brief next element */
    void *next;
    /** @brief FIFO size */
    size_t fifo_size;
    /** @brief FIFO full interrupt pin */
    ri_gpio_id_t fifo_pin;
    /** @brief fields to log */
    rd_sensor_data_fields_t logfields;
    /** @brief function for reading raw data from fifo */
    rd_sensor_read_raw_fp raw_get;
    /** @brief memory for storing data from fifo */
    uint8_t *data;
    /** @brief size of one element */
    size_t size_element;
    /** @brief number of elements with data from fifo */
    size_t num_elements;
    /** @brief position of next element to read */
    size_t element_pos;
} rd_sensor_logging_t;



/**
 * @brief Disable data logging for sensor
 *
 * @param[in] sensor, pointer to logging structure which provides the context
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_disable_sensor_logging (const rd_sensor_logging_t *sensor);

/**
 * @brief Disable data logging for sensor
 *
 * @param[in] sensor, pointer to logging structure which provides the context
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_enable_sensor_logging(rd_sensor_logging_t *sensor);

/**
 * @brief get logged raw data from FIFO
 *
 * @param[in] sensor, pointer to logging structure which provides the context
 * @param[out] data, returns raw data from the sensor
 * @return RD_SUCCESS on success, error code from stack otherwise.
 */
rd_status_t app_get_data_from_queue(rd_sensor_logging_t *sensor, uint8_t *data);

#endif
