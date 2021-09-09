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

    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }

    mx_write_enable();
    while( mx_check_write_enable() == RD_ERROR_BUSY){
      ri_yield();
      LOGD("mx_write resend write_enable\r\n");
      mx_write_enable();
    }

    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }
    LOGDf("Write Page %x, size %d\r\n", offset, size);
    rd_status_t err_code = RD_SUCCESS;
    err_code = mx_program(offset, buf, size);

    if(err_code == RD_SUCCESS) {
      return size;
    } else {
      return -1;
    }
}

static int erase(long offset, size_t size)
{    
    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }

    mx_write_enable();
    while( mx_check_write_enable() == RD_ERROR_BUSY){
      ri_yield();
      LOGD("mx_erase resend write_enable\r\n");
      mx_write_enable();
    }

    //TODO Check if erase is called per sector or if size can exceed sector size -> implement erasing of multiple sectors
    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }
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



