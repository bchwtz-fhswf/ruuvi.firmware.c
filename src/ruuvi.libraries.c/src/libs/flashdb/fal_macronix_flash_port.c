/*
 * @file fal_macronix_flash_port.c
 * @author Jenny Kuhn & Jendrik Kraft, original: Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-08-31
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <string.h>
#include "fal_def.h"

#include "ruuvi_interface_yield.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_driver_error.h"
#include "fal_macronix_flash_port.h"
//TODO Check why here a path is necessary..
#include "..\ruuvi.drivers.c\macronix\macronix_flash.h"


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

static int init(void)
{
    LOGDf("Initialize fal_macronix_flash_port.c with %d sectors of %d bytes\r\n", FDB_MACRONIX_BLOCK_COUNT, FDB_MACRONIX_BLOCK_SIZE);
    rd_status_t status = mx_init();
    return status;
}

static int read(long offset, uint8_t *buf, size_t size)
{
    LOGDf("Read Page %x, size %d\r\n", offset, size);
    rd_status_t err_code = RD_SUCCESS;
    err_code = mx_read(offset, buf, size);
    if(err_code == RD_SUCCESS) {
      return size;
    } else {
      return -1;
    }
}



static int write(long offset, const uint8_t *buf, size_t size) {
  uint32_t start_page, start_page_end;
  uint32_t end_page, end_address;
  uint32_t end_address_copy, offset_copy;
  uint32_t start_page_data_length, data_length, rest_data_length;
  size_t initial_size;

  initial_size=size;

    LOGDf("Write Page %x, size %d\r\n", offset, size);
    rd_status_t err_code = RD_SUCCESS;

    while (size>0){
      mx_spi_ready_for_transfer();   

      end_address = offset + size;
      end_address_copy = end_address;
      offset_copy=offset;
      start_page = offset_copy & MACRONIX_PAGE_MASK;
      end_page = end_address_copy & MACRONIX_PAGE_MASK;
      // If start and end adress are in different pages, the data is devided to multiple write commands
      if (start_page != end_page) {
        start_page_end = start_page | MACRONIX_END_ADRESS_MASK;
        start_page_data_length = start_page_end - offset+1;
        rest_data_length = size - start_page_data_length;
        mx_program(offset, buf, start_page_data_length);
        buf+=start_page_data_length;
        size = rest_data_length;
        offset += start_page_data_length;

      }
      else{
        mx_program(offset, buf, size);
        buf+=size;
        size = 0;
      }
    }

    if(err_code == RD_SUCCESS) {
      return initial_size;
    } else {
      return -1;
    }
}

static int erase(long offset, size_t size)
{    
    mx_spi_ready_for_transfer();
    LOGDf("Erase Page %x, size %d\r\n", offset, size);
    rd_status_t err_code = RD_SUCCESS;
    err_code = mx_sector_erase(offset);
    if(err_code == RD_SUCCESS) {
      return size;
    } else {
      return -1;
    }
}

const struct fal_flash_dev macronix_flash0 =
{    
    .name       = "macronixflash0",
    .addr       = 0x000000,
    .len        = FDB_MACRONIX_BLOCK_COUNT*FDB_MACRONIX_BLOCK_SIZE,
    .blk_size   = FDB_MACRONIX_BLOCK_SIZE,
    .ops        = {init, read, write, erase},
    .write_gran = 0 // not used
 };



