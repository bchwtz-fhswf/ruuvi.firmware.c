/*
 * @file ruuvi_task_flash_ringbuffer.h
 * @author Vanessa Blasko
 * @date 2020-11-20
 */

#include "ruuvi_driver_enabled_modules.h"

#if APP_SENSOR_LOGGING
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_task_flash_ringbuffer.h"
#include "ruuvi_interface_yield.h"
#include <string.h>

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

rd_status_t rt_flash_ringbuffer_free_flash (rt_flash_ringbuffer_state_t *state) {

    rd_status_t err_code = RD_SUCCESS;

    // Cancel reservation
    for (uint8_t i = 0; i < state->size; i++)
    {
      if(state->reserved_pages[i].length_words==0) {
        err_code |= rt_flash_free(state->reserved_pages[i].page, 0x0001);
        LOGDf("Page %d freed. Status %x\r\n", i, err_code);
      } else {
        err_code |= rt_flash_reserve_cancel(&state->reserved_pages[i]);
        LOGDf("Page %d reservation canceled. Status %x\r\n", i, err_code);
      }

      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }

    }

    return err_code;
}

rd_status_t rt_flash_ringbuffer_create (const uint32_t page_id, const uint32_t record_id, const uint8_t number_of_pages, const uint16_t page_size)
{
    rd_status_t err_code = RD_SUCCESS;
    rt_flash_ringbuffer_state_t state;
    fds_stat_t stat;

    // Try to load ringbuffer state
    err_code |= rt_flash_load (page_id, record_id, &state, sizeof (state));
    
    // Returns RD_ERROR_INVALID_STATE when the buffer already exists.
    if (RD_SUCCESS == err_code) {
      LOGD("Ringbuffer has already been initialized\r\n");
      return RD_ERROR_INVALID_STATE;
    }

    err_code = RD_SUCCESS;

    // run garbage collector
    rt_flash_gc_run();

    // Wait while flash is busy
    while (rt_flash_busy())
    {
        ri_yield();
    }

    // Set state attributes
    state.size = 0;
    state.start = 0;
    state.end = 0;

    // Reserve Flash Storage
    for (uint8_t i = 0; err_code==RD_SUCCESS && i<number_of_pages; i++)
    {
      err_code |= rt_flash_reserve(&state.reserved_pages[i], page_size);
      if(err_code==RD_SUCCESS) {
        state.size++;
      }
      LOGDf("Page %d reserved. Status %x\r\n", i, err_code);
    }

    if(err_code==RD_ERROR_NO_MEM && state.size>2) {
      // ignore RD_ERROR_NO_MEM in case of not enough flash memory to reserve the desired size of ringbuffer
      // and if a minimum of 3 pages were reserved
      err_code = RD_SUCCESS;
    }
  
    // Log result
    if (RD_SUCCESS == err_code) {
        // Store state on flash
        err_code |= rt_flash_store (page_id, record_id, &state, sizeof (state));

        // Wait while flash is busy
        while (rt_flash_busy())
        {
            ri_yield();
        }

        LOGD("Ringbuffer init\r\n");

    } else {
        rt_flash_ringbuffer_free_flash (&state);
        LOG("Ringbuffer initialization error\r\n");
    }

    return err_code;
}

rd_status_t rt_flash_ringbuffer_collect_flashpage (const uint32_t page_id, const uint32_t record_id, const uint16_t size, 
              const uint8_t* packeddata, rt_flash_ringbuffer_flashpage_t* flashpage) {
  
  rd_status_t err_code = RD_SUCCESS;

  // if flashpage is full, write pagedata in ringbuffer
  if(flashpage->actual_size + size > flashpage->max_size) {
    err_code = rt_flash_ringbuffer_write(page_id, record_id, flashpage->actual_size, flashpage);
    flashpage->actual_size = 0;
  } 
  // fill packeddata
  memcpy(flashpage->packeddata + flashpage->actual_size, packeddata, size);   
  flashpage->actual_size = flashpage->actual_size + size;

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
      if(state.reserved_pages[state.end].length_words==0) {
        err_code |= rt_flash_store(state.reserved_pages[state.end].page, 0x0001, data, size);
      } else {
        err_code |= rt_flash_write_reserved(&state.reserved_pages[state.end], 0x0001, size, data);
        state.reserved_pages[state.end].length_words = 0;
      }
      if (err_code != RD_SUCCESS) {
        LOGDf("Ringbuffer data writing error. PageID: 0x%02X RecordID: 0x0001 \r\n", state.reserved_pages[state.end].page);
        return err_code;
      }

      // Set end index
      if(state.end >= (state.size -1)) {
        state.end = 0;
      } else {
        state.end = state.end + 1;
      }

      // Set start index
      if(state.end == state.start) {
        if(state.start >= (state.size -1)) {
          state.start = 0;
        } else {
          state.start = state.end + 1;
        }
      }
      
      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }

      // Store state on flash
      err_code |= rt_flash_store (page_id, record_id, &state, sizeof (state));

      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }
  }

  // Log result
  if (RD_SUCCESS == err_code) {
      LOGD("Ringbuffer updated\r\n");
  } else {
      LOGDf("Ringbuffer state writing error. PageID: 0x%02X RecordID: 0x%02X \r\n", page_id, record_id);
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
      if(state.start == state.end) {
        LOGD("Ringbuffer is empty\r\n");
        return RD_ERROR_DATA_SIZE;
      }

      // Read data              
      err_code |= rt_flash_load (state.reserved_pages[state.start].page, 0x0001, data, size);
      if (err_code != RD_SUCCESS)
      {
         LOGDf("Ringbuffer data reading page error. PageID: 0x%02X RecordID: 0x0001 \r\n", state.reserved_pages[state.start].page);
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

      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }

  }

  // Log result
  if (RD_SUCCESS == err_code) {
    LOGD("Ringbuffer read\r\n");
  } else { 
    LOGDf("Ringbuffer state reading error. PageID: 0x%02X RecordID: 0x%02X \r\n", page_id, record_id);
  }

  return err_code;
}

rd_status_t rt_flash_ringbuffer_clear (const uint32_t page_id, const uint32_t record_id) {
  
  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;

  // Flash is always BUSY in this moment because sensor config was just written before
  // Wait while flash is busy
  while (rt_flash_busy())
  {
      ri_yield();
  }

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));
  if (RD_SUCCESS == err_code)
  {
    // Reset end and start
    state.start = 0;
    state.end = 0;
    
    // Store state on flash
    err_code |= rt_flash_store (page_id, record_id, &state, sizeof (state));  

    // Wait while flash is busy
    while (rt_flash_busy())
    {
        ri_yield();
    }
  }

  // Log result
  if (RD_SUCCESS == err_code) {
     LOGD("Ringbuffer cleared\r\n");
  } else {
     LOGDf("Ringbuffer clearing error. PageID: 0x%02X RecordID: 0x%02X \r\n", page_id, record_id);
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
     err_code |= rt_flash_ringbuffer_free_flash (&state);
     err_code |= rt_flash_free(page_id, record_id);  
  } else {
     LOGD("No ringbuffer to delete\r\n");
     return RD_SUCCESS;
  }

  // Log result
  if (RD_SUCCESS == err_code) {
     LOGD("Ringbuffer deleted\r\n");
  } else {
     LOGDf("Ringbuffer deleting error. PageID: 0x%02X RecordID: 0x%02X \r\n", page_id, record_id);
  }

  return err_code;
}

rd_status_t rt_flash_ringbuffer_statistic (const uint32_t page_id, 
          const uint32_t record_id, uint8_t* const statistik) {

  rd_status_t err_code = RD_SUCCESS;
  rt_flash_ringbuffer_state_t state;
  int pos = 0;

  // Load State
  err_code |= rt_flash_load (page_id, record_id, &state, sizeof(state));

  if(err_code & RD_ERROR_NOT_FOUND) {
    statistik[pos++] = 0xff;
    statistik[pos++] = 0xff;
    statistik[pos++] = 0xff;
  } else {
    statistik[pos++] = state.start;
    statistik[pos++] = state.end;
    statistik[pos++] = state.size;
  }

  // gather flash statistics
  fds_stat_t stat;
  fds_stat(&stat);

  memcpy(statistik+pos, &stat.valid_records, 2);
  pos+=2;
  memcpy(statistik+pos, &stat.dirty_records, 2);
  pos+=2;
  memcpy(statistik+pos, &stat.words_reserved, 2);
  pos+=2;
  memcpy(statistik+pos, &stat.words_used, 2);
  pos+=2;
  memcpy(statistik+pos, &stat.largest_contig, 2);
  pos+=2;
  memcpy(statistik+pos, &stat.freeable_words, 2);
  pos+=2;
  
  // ignore NOT_FOUND
  return err_code & ~RD_ERROR_NOT_FOUND;
}
#endif
