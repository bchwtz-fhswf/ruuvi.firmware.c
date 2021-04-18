#ifndef  RUUVI_TASK_FLASH_RINGBUFFER_H
#define  RUUVI_TASK_FLASH_RINGBUFFER_H

/*
 * @file ruuvi_task_flash_ringbuffer.h
 * @author Vanessa Blasko
 * @date 2020-11-20
 */

#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "fds.h"

// Ringbuffer state
typedef struct {
    uint8_t size;     // number of pages
    uint8_t start;    // which page is current begin of data
    uint8_t end;      // which page is current last page filled with data
    fds_reserve_token_t reserved_pages[RT_FLASH_RINGBUFFER_MAXSIZE]; // Array of fds_revser_token
} rt_flash_ringbuffer_state_t;

// Ringbuffer flashpage
typedef struct __attribute__ ((packed, aligned (4))) {
    uint16_t max_size;
    uint16_t actual_size;
    uint8_t packeddata[4073];
} rt_flash_ringbuffer_flashpage_t;


/*
 *  Creates a new ringbuffer, reserves the pages in flash and initializes the state
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] number_of_pages Number of pages in the ringbuffer
 * @param[in] page_size Size of each page in the ringbuffer
 */
rd_status_t rt_flash_ringbuffer_create (
    const uint32_t page_id,
    const uint32_t record_id,
    const uint8_t number_of_pages,
    const uint16_t page_size
);

/*
 * Collect data to store in ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] size Size of packeddata
 * @param[in] packeddata Data to collect for flashpage 
 * @param[in, out] flashpage Flashpage Struct
 */
rd_status_t rt_flash_ringbuffer_collect_flashpage (
    const uint32_t page_id,
    const uint32_t record_id,
    const uint16_t size,
    const uint8_t* packeddata,
    rt_flash_ringbuffer_flashpage_t* flashpage
);

/*
 *  Write data to ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] size Size of data
 * @param[in] data
 */
rd_status_t rt_flash_ringbuffer_write (
    const uint32_t page_id,
    const uint32_t record_id,
    const uint16_t size,
    const void* data
);

/*
 *  Read a page from the ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] size Size of data
 * @param[in, out] data
 */
rd_status_t rt_flash_ringbuffer_read (
    const uint32_t page_id, 
    const uint32_t record_id, 
    const uint16_t size, 
    void* data);

/*
 *  Clears the contents of the ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 */
rd_status_t rt_flash_ringbuffer_clear (
    const uint32_t page_id, 
    const uint32_t record_id
);

/*
 *  Deletes the entire ring buffer 
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 */
rd_status_t rt_flash_ringbuffer_delete (
  const uint32_t page_id, 
  const uint32_t record_id
);

/*
 *  Return Ringbuffer and flash statistic
 *  Ignores error if Ringbuffer does not exist.
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in/out] statistik Memory for storing statistik about flash usage and ringbuffer usage.
 */
rd_status_t rt_flash_ringbuffer_statistic (
  const uint32_t page_id, 
  const uint32_t record_id,
  uint8_t* const statistik
);
#endif // RUUVI_TASK_FLASH_RINGBUFFER_H



