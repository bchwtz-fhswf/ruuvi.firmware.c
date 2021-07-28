/**
 * @file fal_dummy_flash_port.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-07-14
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include "ruuvi_task_flashdb.h"
#include "ruuvi_interface_log.h"

#if RI_LOG_ENABLED
#include <stdio.h>
#include <stdarg.h>
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
#define fdb_log(...) 
#endif

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
}
