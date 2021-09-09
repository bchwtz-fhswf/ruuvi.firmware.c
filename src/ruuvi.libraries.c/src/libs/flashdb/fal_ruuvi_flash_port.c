/**
 * @file fal_ruuvi_flash_port.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-07-14
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <string.h>
//#include "fal.h"
#include "fal_def.h"
#include "ruuvi_interface_yield.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_driver_error.h"
#include "fal_ruuvi_flash_port.h"


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

// Cache current file/sector
static uint16_t current_fileId = 0xffff;
static uint8_t current_file_content[FDB_RUUVI_BLOCK_SIZE];

static int fal_ruuvi_flash_init(void)
{
    LOGDf("Initialize fal_ruuvi_flash_port.c with %d sectors of %d bytes\r\n", FDB_RUUVI_BLOCK_COUNT, FDB_RUUVI_BLOCK_SIZE);
    return 1;
}

static rd_status_t reserve_page(const uint16_t fileId) {
    uint8_t content[FDB_RUUVI_BLOCK_SIZE];
    rd_status_t err_code = RD_SUCCESS;

    memset(content, 0xff, FDB_RUUVI_BLOCK_SIZE);
    err_code |= rt_flash_store (FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, 1, content, FDB_RUUVI_BLOCK_SIZE);
    LOGDf("Flash Page %x successfully reserved\r\n", FDB_RUUVI_FLASH_BASE_FILE_ID + fileId);
    // Wait while flash is busy
    while (rt_flash_busy())
    {
        ri_yield();
    }
}

static int fal_ruuvi_flash_read(long offset, uint8_t *buf, size_t size)
{
    rd_status_t err_code = RD_SUCCESS;
    uint16_t fileId = offset / FDB_RUUVI_BLOCK_SIZE;
    uint16_t fileOffset = offset % FDB_RUUVI_BLOCK_SIZE;
    uint8_t content[FDB_RUUVI_BLOCK_SIZE];

    LOGDf("Read Page %x, size %d\r\n", FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, size);

    if(fileId==current_fileId) {
      // read from cache
      memcpy(buf, current_file_content + fileOffset, size);

    } else {
      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }

      // read from flash
      err_code |= rt_flash_load (FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, 1, content, FDB_RUUVI_BLOCK_SIZE);

      if(err_code==RD_ERROR_NOT_FOUND) {
        err_code = reserve_page(fileId);
      }

      memcpy(buf, content+fileOffset, size);
    }
        
    if(err_code==RD_SUCCESS) {
      return size;
    } else {
      RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
      return -1;
    }
}

static int fal_ruuvi_flash_write(long offset, const uint8_t *buf, size_t size) {

    rd_status_t err_code = RD_SUCCESS;
    uint16_t fileId = offset / FDB_RUUVI_BLOCK_SIZE;
    uint16_t fileOffset = offset % FDB_RUUVI_BLOCK_SIZE;

    LOGDf("Write Page %x, size %d\r\n", FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, size);

    if(current_fileId!=0xffff && current_fileId!=fileId) {
      // persist current sector to flash
      err_code |= rt_flash_store (FDB_RUUVI_FLASH_BASE_FILE_ID + current_fileId, 1, current_file_content, FDB_RUUVI_BLOCK_SIZE);
      RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
        
      // Wait while flash is busy
      while (rt_flash_busy())
      {
          ri_yield();
      }

      current_fileId = 0xffff;
    }

    // load new file
    if(current_fileId==0xffff) {
      err_code |= rt_flash_load (FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, 1, current_file_content, FDB_RUUVI_BLOCK_SIZE);
      RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
      current_fileId = fileId;
      if(err_code==RD_ERROR_NOT_FOUND) {
        err_code = reserve_page(fileId);
        RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
      }
    }

    memcpy(current_file_content + fileOffset, buf, size);

    if(err_code==RD_SUCCESS) {
      return size;
    } else {
      return -1;
    }
}

static int fal_ruuvi_flash_erase(long offset, size_t size)
{    
    uint8_t content[FDB_RUUVI_BLOCK_SIZE];
    uint16_t fileId = offset / FDB_RUUVI_BLOCK_SIZE;
    memset(content, 0xff, FDB_RUUVI_BLOCK_SIZE);

    LOGDf("Erase Page %x, Size %d\r\n", FDB_RUUVI_FLASH_BASE_FILE_ID + fileId, size);

    return fal_ruuvi_flash_write(offset, content, size);
}

const struct fal_flash_dev ruuvi_flash0 =
{
    .name       = "ruuviflash0",
    .addr       = 0,
    .len        = FDB_RUUVI_BLOCK_COUNT*FDB_RUUVI_BLOCK_SIZE,
    .blk_size   = FDB_RUUVI_BLOCK_SIZE,
    .ops        = {fal_ruuvi_flash_init, fal_ruuvi_flash_read, fal_ruuvi_flash_write, fal_ruuvi_flash_erase},
    .write_gran = 0 // not used
};
