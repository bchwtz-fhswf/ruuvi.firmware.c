/**
 * @file ruuvi_task_flashdb.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-07-14
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include "ruuvi_task_flashdb.h"
#include "ruuvi_interface_log.h"
#include "macronix_flash.h"

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
void fdb_log (const char * const msg, ...)
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
void fdb_log(const char * const msg, ...) {}
#endif

static rd_status_t is_macronix_present = RD_ERROR_NOT_INITIALIZED;

rd_status_t rt_flashdb_to_ruuvi_error(fdb_err_t fdb_err) {

  switch(fdb_err) {
    case FDB_NO_ERR:
      return RD_SUCCESS;
    case FDB_ERASE_ERR:
      return RD_ERROR_INTERNAL;
    case FDB_READ_ERR:
      return RD_ERROR_INTERNAL;
    case FDB_WRITE_ERR:
      return RD_ERROR_INTERNAL;
    case FDB_PART_NOT_FOUND:
      return RD_ERROR_NOT_FOUND;
    case FDB_KV_NAME_ERR:
      return RD_ERROR_INVALID_PARAM;
    case FDB_KV_NAME_EXIST:
      return RD_ERROR_INVALID_DATA;
    case FDB_SAVED_FULL:
      return RD_ERROR_NO_MEM;
    case FDB_INIT_FAILED:
      return RD_ERROR_NOT_INITIALIZED;
  }
  return RD_ERROR_NOT_INITIALIZED;
}

rd_status_t rt_macronix_flash_exists(void) {

  if(is_macronix_present == RD_ERROR_NOT_INITIALIZED) {
    uint8_t manufacturer_id;
    uint8_t device_id;

    LOGD("Checking external flash existence\r\n");

    while(mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }

    rd_status_t err_code = mx_read_rems(&manufacturer_id, &device_id);

    if(err_code==RD_SUCCESS) {
      LOGDf("manufacturer_id %x, device_id %x\r\n", manufacturer_id, device_id);

      if(manufacturer_id==0xc2 && device_id==0x17) {      
        is_macronix_present = RD_SUCCESS;
      } else {
        is_macronix_present = RD_ERROR_NOT_FOUND;
      }
    }
  }
  return is_macronix_present;
}

void rt_macronix_high_performance_switch(const bool enable) {
  if(rt_macronix_flash_exists()==RD_SUCCESS) {
    mx_high_performance_switch(enable);
  }
}

rd_status_t rt_reset_macronix_flash(void) {
  rd_status_t err_code;
  err_code = RD_SUCCESS;
  if(rt_macronix_flash_exists()==RD_SUCCESS) {
    LOGDf("Triggering Macronix flash chip erase\r\n");
    err_code |= mx_high_performance_switch(true);
    mx_spi_ready_for_transfer();
    err_code |= mx_chip_erase();
  }
  return err_code;
}