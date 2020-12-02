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

#ifndef RT_FLASH_RINGBUFFER_MAXSIZE
#   define RT_FLASH_RINGBUFFER_MAXSIZE (8U)
#endif

// Ringbuffer state
typedef struct {
    uint8_t size;     // number of pages
    uint8_t start;    // which page is current begin of data
    uint8_t end;      // which page is current last page filled with data
    uint16_t pages[RT_FLASH_RINGBUFFER_MAXSIZE]; // Array of page numbers
} rt_flash_ringbuffer_state_t;


/*
 *  Creates a new ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] number_of_pages
 * @param[in] length_words (The length of the record data (in 4-byte words) the ringbuffer should store)
 */
rd_status_t rt_flash_ringbuffer_create (
    const uint32_t page_id,
    const uint32_t record_id,
    const uint8_t number_of_pages,
    const uint16_t length_words
);

/*
 *  Write data to ringbuffer
 *
 * @param[in] page_id PageID of the ringbuffer state
 * @param[in] record_id RecordID of the ringbuffer state
 * @param[in] size of data
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
 * @param[in] size of data
 * @param[in, out] data
 */
rd_status_t rt_flash_ringbuffer_read (
    const uint32_t page_id, 
    const uint32_t record_id, 
    const uint16_t size, 
    void* data);

#endif // RUUVI_TASK_FLASH_RINGBUFFER_H



