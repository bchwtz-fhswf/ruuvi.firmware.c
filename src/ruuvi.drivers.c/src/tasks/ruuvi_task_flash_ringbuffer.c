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

rd_status_t rt_flash_ringbuffer_create (const uint32_t page_id, const uint32_t record_id, const uint8_t number_of_pages, const uint16_t length_words)
{
    rd_status_t err_code = RD_SUCCESS;
    rt_flash_ringbuffer_state_t state;
    fds_stat_t stat;
    fds_reserve_token_t tok[number_of_pages];

    // Try to load ringbuffer state
    err_code |= rt_flash_load (page_id, record_id, &state, sizeof (state));
    
    // Returns RD_ERROR_INVALID_STATE when the buffer already exists.
    if (RD_SUCCESS == err_code) {
      return RD_ERROR_INVALID_STATE;
    }
    
    // Returns RD_ERROR_NO_MEM when there is not enough space in flash.
    fds_stat(&stat); 	
    if(stat.pages_available < number_of_pages) {
      return RD_ERROR_NO_MEM;
    }

    // Set state attributes
    state.size = number_of_pages;
    state.pages[number_of_pages];
    state.start = 0;
    state.end = 0;
    // Reserve Flash Storage
    for (uint8_t i = 0; i < number_of_pages; i++)
    {
      fds_reserve(&tok[i], length_words);
      state.pages[i] = tok[i].page;
    }
  
    // Store state on flash
    err_code = rt_flash_store (page_id, record_id, &state, sizeof (state));

    return err_code;
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
      err_code |= rt_flash_store(state.pages[state.end], 0x0001, data, size);
      if (err_code != RD_SUCCESS) {
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
      err_code |= rt_flash_load (state.pages[state.start], 0x0001, data, size);
      if (err_code != RD_SUCCESS)
      {
         return err_code;		
      }

      // Set start index
      if(state.start >= (state.size -1)) {
        state.start = 0;
      } else {
        state.start = state.start + 1;
      }

      // Store state on flash
      err_code = rt_flash_store (page_id, record_id, &state, sizeof (state));
  }

  return err_code;
}
#endif
