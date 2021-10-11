/*
 * @file ruuvi_task_flash_ringbuffer.h
 * @author Thomas Hoof
 * @date 2021-07-16
 */

#include "ruuvi_driver_enabled_modules.h"

#if APP_SENSOR_LOGGING
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_interface_communication.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_task_flash_ringbuffer.h"
#include "ruuvi_task_flashdb.h"
#include "fds.h"
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


/* TSDB object */
static struct fdb_tsdb tsdb;

rd_status_t rt_flash_ringbuffer_create (const char *partition, fdb_get_time get_time, const bool format_db)
{
  // change to high performance mode during flashDB initialization for quicker setup
  rt_macronix_high_performance_switch(true);

  /* Time Series database initialization
   */
  memset(&tsdb, 0, sizeof(tsdb));
  fdb_err_t result = fdb_tsdb_init(&tsdb, "acceleration_data", partition, get_time, 144, NULL);

  // Log result
  if (result==FDB_NO_ERR) {
      LOGD("Ringbuffer successfully initilized.\r\n");
  } else {
      LOGDf("Ringbuffer initialization error 0x%02X \r\n", result);
  }
  

  // Format DB in case of enabling logging and DB was not empty
  if(format_db && tsdb.last_time!=0) {
    rt_flash_ringbuffer_clear();
  }
  
  // change to low power mode after flashDB initialization for quicker setup
  rt_macronix_high_performance_switch(false);

  return rt_flashdb_to_ruuvi_error(result);
}

rd_status_t rt_flash_ringbuffer_write (const uint16_t size, const void* data) 
{
  fdb_err_t result;
  struct fdb_blob blob;
  
  result = fdb_tsl_append(&tsdb, fdb_blob_make(&blob, data, size));

  // Log result
  if (result!=FDB_NO_ERR) {
      LOGDf("Ringbuffer writing error 0x%02X \r\n", result);
  }

  return rt_flashdb_to_ruuvi_error(result);
}

void rt_flash_ringbuffer_read (const fdb_tsl_cb callback, const ri_comm_xfer_fp_t reply_fp, uint16_t* crc) 
{
  void *args[3] = { &tsdb, reply_fp, crc };
  fdb_tsl_iter(&tsdb, callback, args );
}

rd_status_t rt_flash_ringbuffer_clear (void) {

  // change to high performance mode during flashDB initialization for quicker setup
  rt_macronix_high_performance_switch(true);

  fdb_tsl_clean(&tsdb);
  LOGD("Ringbuffer cleared\r\n");

  // change to low power mode after flashDB initialization for quicker setup
  rt_macronix_high_performance_switch(false);

  return RD_SUCCESS;
}

rd_status_t rt_flash_ringbuffer_drop (void) {
  
  fdb_tsdb_deinit(&tsdb);
  LOGD("Ringbuffer droped\r\n");

  return RD_SUCCESS;
}

rd_status_t rt_flash_ringbuffer_statistic (uint8_t* const statistik) {

  rd_status_t err_code = RD_SUCCESS;
  int pos = 0;

  statistik[pos++] = 0xff;
  statistik[pos++] = 0xff;
  statistik[pos++] = 0xff;
      
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
  
  return err_code;
}

#endif
