/*
 * @file ruuvi_task_flash_ringbuffer.h
 * @author Vanessa Blasko
 * @date 2020-11-20
 */

#include "ruuvi_driver_enabled_modules.h"

#if RT_FLASH_ENABLED
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "fds.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_task_flash_ringbuffer.h"

rd_status_t rt_flash_ringbuffer_create (const uint32_t page_id, const uint32_t record_id, const uint8_t number_of_pages, const uint16_t page_size)
{
    rd_status_t err_code = RD_SUCCESS;
    rt_flash_ringbuffer_state_t state;
    fds_stat_t stat;
    fds_reserve_token_t tok[number_of_pages];

    // Try to load ringbuffer state
    err_code |= rt_flash_load (page_id, record_id, &state, sizeof (state));
    
    // Returns RD_ERROR_INVALID_STATE when the buffer already exists.
    if (RD_SUCCESS == err_code) {
      ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer has already been initialized\r\n");
      return RD_ERROR_INVALID_STATE;
    }
    
    // Returns RD_ERROR_NO_MEM when there is not enough space in flash.
    fds_stat(&stat); 	
    if(stat.pages_available < number_of_pages) {
      return RD_ERROR_NO_MEM;
    }

    // Set state attributes
    state.size = number_of_pages;
    state.reserved_pages[number_of_pages];
    state.start = 0;
    state.end = 0;
    // Reserve Flash Storage
    for (uint8_t i = 0; i < number_of_pages; i++)
    {
      fds_reserve(&tok[i], page_size/4); // length of the record data in 4-byte words
      state.reserved_pages[i] = tok[i];
    }
  
    // Store state on flash
    err_code = rt_flash_store (page_id, record_id, &state, sizeof (state));

    // Log result
    if (RD_SUCCESS == err_code) {
       ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer init\r\n");
    } else {
       ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer initialization error\r\n");
    }

    return err_code;
}

void rt_flash_ringbuffer_collect_flashpage (const uint32_t page_id, const uint32_t record_id, const uint16_t size, const uint8_t* packeddata, rt_flash_ringbuffer_flashpage_t* flashpage) {
  
  // if flashpage is full, write pagedata in ringbuffer
  if(flashpage->actual_size + size > flashpage->max_size) {
    rt_flash_ringbuffer_write(page_id, record_id, flashpage->actual_size, flashpage->packeddata);
    flashpage->actual_size = 0;
  } 
  // fill packeddata
  memcpy(flashpage->packeddata + (flashpage->max_size - flashpage->actual_size - size), packeddata, size);   
  flashpage->actual_size = flashpage->actual_size + size;
}

rd_status_t rt_flash_ringbuffer_write (const uint32_t page_id, const uint32_t record_id, const uint16_t size, const void* data) 
{
  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));
  
  if (RD_SUCCESS == err_code)
  {
      // Store data
      err_code |= rt_flash_store(state.reserved_pages[state.end].page, 0x0001, data, size);
      if (err_code != RD_SUCCESS) {
        ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer writing error\r\n");
        return err_code;
      }
      
      // Set end index
      if(state.end >= (state.size -1)) {
        state.end = 0;
      } else {
        state.end = state.end + 1;
      }

      // Store state on flash
      err_code |= rt_flash_store (page_id, record_id, &state, sizeof (state));
  }

  // Log result
  if (RD_SUCCESS == err_code) {
    ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer updated\r\n");
  } else {
    ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer writing error\r\n");
  }

  return err_code;
}

rd_status_t rt_flash_ringbuffer_read (const uint32_t page_id, const uint32_t record_id, const uint16_t size, void* data) 
{
  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));

  if (RD_SUCCESS == err_code)
  {
      // Read data              
      err_code |= rt_flash_load (state.reserved_pages[state.start].page, 0x0001, data, size);
      if (err_code != RD_SUCCESS)
      {
         ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer reading error\r\n");
         return err_code;		
      }

      // Set start index
      if(state.start >= (state.size -1)) {
        state.start = 0;
      } else {
        state.start = state.start + 1;
      } 
  }

  // Store state on flash
  err_code = rt_flash_store (page_id, record_id, &state, sizeof (state));
  // Log result
  if (RD_SUCCESS == err_code) {
    ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer read\r\n");
  } else {
     ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer reading error\r\n");
  }

  return err_code;
}

rd_status_t rt_flash_ringbuffer_clear (const uint32_t page_id, const uint32_t record_id) {
  
  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));
  if (RD_SUCCESS == err_code)
  {
    // Reset end and start
    state.start = 0;
    state.end = 0;
    
    // Store state on flash
    err_code = rt_flash_store (page_id, record_id, &state, sizeof (state));  
  }

  // Log result
  if (RD_SUCCESS == err_code) {
    ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer cleared\r\n");
  } else {
     ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer clearing error\r\n");
  }

  return err_code;
}

rd_status_t rt_flash_ringbuffer_delete (const uint32_t page_id, const uint32_t record_id) {
  
  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));
  if (RD_SUCCESS == err_code)
  {
    // Cancel reservation
    for (uint8_t i = 0; i < state.size; i++)
    {
      err_code |= rt_flash_free(state.reserved_pages[i].page, 0x0001);
      err_code |= fds_reserve_cancel(&state.reserved_pages[i]);
    }

    err_code |= rt_flash_free(page_id, record_id);  
  } else {
     ri_log (RI_LOG_LEVEL_DEBUG, "No ringbuffer to delete\r\n");
     return RD_SUCCESS;
  }

  // Log result
  if (RD_SUCCESS == err_code) {
     ri_log (RI_LOG_LEVEL_DEBUG, "Ringbuffer deleted\r\n");
  } else {
     ri_log (RI_LOG_LEVEL_ERROR, "Ringbuffer deleting error\r\n");
  }

  return err_code;
}
#endif
