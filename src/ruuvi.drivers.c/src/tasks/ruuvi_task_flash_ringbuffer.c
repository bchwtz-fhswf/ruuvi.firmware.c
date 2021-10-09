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
#include "macronix_flash.h"
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
static rd_status_t is_macronix_present = RD_ERROR_NOT_INITIALIZED;

rd_status_t rt_flash_ringbuffer_create (const char *partition, fdb_get_time get_time, const bool format_db)
{
  bool with_ext_flash = (rt_flash_ringbuffer_ext_flash_exists()==RD_SUCCESS);

  // change to high performance mode during flashDB initialization for quicker setup
  bool high_power =1;
  if(with_ext_flash) {
    mx_high_performance_switch (high_power);
  }

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
  high_power =0;
  if(with_ext_flash) {
    mx_high_performance_switch (high_power);
  }

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

  bool with_ext_flash = (rt_flash_ringbuffer_ext_flash_exists()==RD_SUCCESS);

  // change to high performance mode during flashDB initialization for quicker setup
  bool high_power =1;
  if(with_ext_flash) {
    mx_high_performance_switch (high_power);
  }

  fdb_tsl_clean(&tsdb);
  LOGD("Ringbuffer cleared\r\n");

  // change to low power mode after flashDB initialization for quicker setup
  high_power =0;
  if(with_ext_flash) {
    mx_high_performance_switch (high_power);
  }

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

void rt_print_flash_statistic(void) {

  rd_status_t err_code = RD_SUCCESS;
      
  // gather flash statistics
  fds_stat_t stat;
  fds_stat(&stat);

  LOGDf("Open records %d \r\n", stat.open_records);
  LOGDf("Valid records %d \r\n", stat.valid_records);
  LOGDf("Dirty records %d \r\n", stat.dirty_records);
  LOGDf("Words reserved %d \r\n", stat.words_reserved);
  LOGDf("Words used %d \r\n", stat.words_used);
  LOGDf("Words available %d \r\n", stat.pages_available * FDS_VIRTUAL_PAGE_SIZE);
  LOGDf("Largest contig %d \r\n", stat.largest_contig);
  LOGDf("Freeable words %d \r\n", stat.freeable_words);
  LOGDf("Filesystem corruption %d \r\n", stat.corruption);
  
}

rd_status_t rt_flash_ringbuffer_ext_flash_exists(void) {

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

rd_status_t rt_reset_macronix_flash(void) {
  rd_status_t err_code;
  err_code = RD_SUCCESS;
  if(rt_flash_ringbuffer_ext_flash_exists()==RD_SUCCESS) {
    LOGDf("Triggering Macronix flash chip erase\r\n");
    err_code |= mx_high_performance_switch(true);
    mx_spi_ready_for_transfer();
    err_code |= mx_chip_erase();
  }
  return err_code;
}

#endif

