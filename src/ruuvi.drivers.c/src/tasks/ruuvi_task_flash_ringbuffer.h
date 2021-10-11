/*
 * @file ruuvi_task_flash_ringbuffer.h
 * @author Thomas Hoof
 * @date 2021-07-16
 */

#ifndef  RUUVI_TASK_FLASH_RINGBUFFER_H
#define  RUUVI_TASK_FLASH_RINGBUFFER_H

#include "app_config.h"

#if APP_SENSOR_LOGGING

#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "flashdb.h"

/*
 *  Creates a new ringbuffer, reserves the pages in flash and initializes the state
 *
 * @param[in] partition Name of the partition
 * @param[in] get_time Function pointer to function to retrieve timestamp
 */
rd_status_t rt_flash_ringbuffer_create (const char* partition, fdb_get_time get_time, const bool format_db);

/*
 *  Write data to ringbuffer
 *
 * @param[in] size Size of data
 * @param[in] data
 */
rd_status_t rt_flash_ringbuffer_write (
    const uint16_t size,
    const void* data
);

/*
 *  Read the whole ringbuffer
 *
 * @param[in] callback Callback function which processes the data
 * @param[in] reply_fp reply function for transmitting the data
 * @param[in] crc Pointer to CRC which gets calculated during sending the data
 */
void rt_flash_ringbuffer_read (const fdb_tsl_cb callback, const ri_comm_xfer_fp_t reply_fp, uint16_t* crc);

/*
 *  Clears the contents of the ringbuffer
 */
rd_status_t rt_flash_ringbuffer_clear (void);

/*
 *  Drops the whole ringbuffer
 */
rd_status_t rt_flash_ringbuffer_drop (void);

/*
 *  Return Ringbuffer and flash statistic
 *  Ignores error if Ringbuffer does not exist.
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in/out] statistik Memory for storing statistik about flash usage and ringbuffer usage.
 */
rd_status_t rt_flash_ringbuffer_statistic (
  uint8_t* const statistik
);

#endif // RUUVI_TASK_FLASH_RINGBUFFER_H

#endif

