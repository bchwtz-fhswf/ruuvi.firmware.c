#include "app_log.h"

#include "app_config.h"
#include "app_comms.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_library.h"
#include "ruuvi_library_compress.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_interface_yield.h"
#include "ruuvi_task_flash.h"
#include "flashdb.h"
#include "ruuvi_task_flashdb.h"
#include "ruuvi_endpoints.h"

#define SIZE_ELEMENT (3 * sizeof(int16_t))

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


/**
 * @addtogroup app_log
 */
/** @{ */
/**
 * @file app_log.c
 * @author Otso Jousimaa <otso@ojousima.net>
 * @date 2020-07-17
 * @copyright Ruuvi Innovations Ltd, license BSD-3-Clause.
 */

#ifndef CEEDLING
static
#endif
uint64_t m_last_sample_ms; //!< Timestamp of last processed sample.

/* TSDB object */
static struct fdb_tsdb tsdb;

#ifndef CEEDLING
static
#endif
rd_status_t app_log_read_boot_count (void)
{
    rd_status_t err_code = RD_SUCCESS;
    uint32_t m_boot_count = 0;

    err_code |= rt_flash_load ("boot_counter",
                               &m_boot_count, sizeof (m_boot_count));

    if ( (RD_SUCCESS == err_code) || (RD_ERROR_NOT_FOUND == err_code))
    {
        m_boot_count++;
        err_code = rt_flash_store ("boot_counter",
                                   &m_boot_count, sizeof (m_boot_count));
    }

    char msg[128];
    snprintf (msg, sizeof (msg), "LOG: Boot count: %d\r\n", m_boot_count);
    LOG (msg);
    return err_code;
}

static int64_t app_log_timestamp_get(void) {
  return rd_sensor_timestamp_get();
}

rd_status_t app_log_init (void)
{
    rd_status_t err_code = RD_SUCCESS;

    rt_macronix_high_performance_switch(true);
    fdb_err_t result = fdb_tsdb_init(&tsdb, "environmental_data", "envdata_tsdb", app_log_timestamp_get, sizeof(app_log_element_t), NULL);
    rt_macronix_high_performance_switch(false);

    err_code |= rt_flashdb_to_ruuvi_error(result);

    err_code |= app_log_read_boot_count();
    return err_code;
}

rd_status_t app_log_process (const rd_sensor_data_t * const sample)
{
    rd_status_t err_code = RD_SUCCESS;

    uint64_t next_sample_ms = m_last_sample_ms + (5 * 1000U); // save environmental data every 5 seconds
    LOGD ("LOG: Sample received\r\n");

    // Always store first sample.
    if (0 == m_last_sample_ms)
    {
        next_sample_ms = 0;
    }

    //Check if new sample should be processed
    if (next_sample_ms <= sample->timestamp_ms)
    {
        LOGD ("LOG: Storing sample\r\n");
        app_log_element_t element =
        {
            .temperature_c = rd_sensor_data_parse (sample, RD_SENSOR_TEMP_FIELD),
            .humidity_rh = rd_sensor_data_parse (sample, RD_SENSOR_HUMI_FIELD),
            .pressure_pa = rd_sensor_data_parse (sample, RD_SENSOR_PRES_FIELD),
        };

        fdb_err_t result;
        struct fdb_blob blob;
  
        result = fdb_tsl_append(&tsdb, fdb_blob_make(&blob, &element, sizeof(element)));

        m_last_sample_ms = sample->timestamp_ms;
        err_code |= rt_flashdb_to_ruuvi_error(result);
    }
    else
    {
        // No action needed.
    }

    return err_code;
}

void app_log_purge_flash (void)
{
    fdb_tsl_clean(&tsdb);
}


/**
 * @brief encode log element into given buffer.
 *
 * @param[in] buffer Buffer to encode data into.
 * @param[in] timestamp_ms Float value to encode.
 * @param[in] data Float value to encode.
 * @param[in] type Type of data to encode. Only one type/message is implemented.
 *
 * @note This function will not set the destination endpoint in buffer.
 * @retval RD_SUCCESS Data was encoded successfully.
 * @retval RD_ERROR_NULL Buffer or data was NULL.
 * @retval RD_ERROR_INVALID_PARAM Type had no field set.
 * @retval RD_ERROR_NOT_IMPLEMENTED Type had > 1 field set or encoding type is not implemented.
 */
static rd_status_t app_log_encode_log (uint8_t * const buffer,
        const uint64_t timestamp_ms,
        const float data,
        const uint8_t source)
{
    rd_status_t err_code = RD_SUCCESS;

    if (0 != source)
    {
        re_log_write_header (buffer, source);
        re_log_write_timestamp (buffer, timestamp_ms);
        re_log_write_data (buffer, data, source);
    }
    else
    {
        err_code |= RD_ERROR_INVALID_PARAM;
    }

    return err_code;
}

/**
 * if valid data in sample
 * parse data type
 * parse data value
 * format msg
 * send msg
 */
static bool app_log_send_fields (fdb_tsl_t tsl, void *arg)
{
  if(tsl->status!=FDB_TSL_DELETED) {
    void** args = arg;
    fdb_tsdb_t db = args[0];
    ri_comm_xfer_fp_t reply_fp = args[1];
    rd_status_t *err_code = args[2];

    struct fdb_blob blob;
    app_log_element_t element;

    uint8_t data_size = fdb_blob_read((fdb_db_t) db, fdb_tsl_to_blob(tsl, fdb_blob_make(&blob, &element, sizeof(element))));

    ri_comm_message_t msg = {0};
    msg.repeat_count = 1;
    msg.data_length = RE_STANDARD_MESSAGE_LENGTH;
    msg.data[RE_STANDARD_DESTINATION_INDEX] = RE_ENV_ALL;

    // encode Humidity
    *err_code |= app_log_encode_log (msg.data, tsl->time, element.humidity_rh, RE_STANDARD_DESTINATION_HUMIDITY);

    if (RD_SUCCESS == *err_code) {
        // send humidity
        *err_code |= app_comms_blocking_send (reply_fp, &msg);

        // encode pressure
        *err_code |= app_log_encode_log (msg.data, tsl->time, element.pressure_pa, RE_STANDARD_DESTINATION_PRESSURE);

        if (RD_SUCCESS == *err_code) {
            // send pressure
            *err_code |= app_comms_blocking_send (reply_fp, &msg);

            // encode temperature
            *err_code |= app_log_encode_log (msg.data, tsl->time, element.temperature_c, RE_STANDARD_DESTINATION_TEMPERATURE);

            if (RD_SUCCESS == *err_code) {
                // send temperature
                *err_code |= app_comms_blocking_send (reply_fp, &msg);
            }
        }
    }
  }

  return false;
}


/**
 * @brief Send no more sensor log data message.
 */
static rd_status_t app_log_send_eof (const ri_comm_xfer_fp_t reply_fp)
{
    rd_status_t err_code = RD_SUCCESS;
    ri_comm_message_t msg = {0};
    msg.data_length = RE_STANDARD_MESSAGE_LENGTH;
    msg.data[RE_STANDARD_DESTINATION_INDEX] = RE_ENV_ALL;
    msg.data[RE_STANDARD_SOURCE_INDEX] = RE_ENV_ALL;
    msg.data[RE_STANDARD_OPERATION_INDEX] = RE_STANDARD_LOG_VALUE_WRITE;
    memset (&msg.data[RE_STANDARD_HEADER_LENGTH], 0xFF, RE_STANDARD_PAYLOAD_LENGTH);
    app_comms_blocking_send (reply_fp, &msg);
    return err_code;
}

/**
 * @brief Send data element.
 *
 * This function sends given data element to given reply function pointer.
 *
 * @note This function blocks until all data is send
 */
rd_status_t app_log_send_data (const ri_comm_xfer_fp_t reply_fp,
        const int64_t start_time_ms, const int64_t current_time_ms)
{
    rd_status_t err_code = RD_SUCCESS;

    void *args[3] = { &tsdb, reply_fp, &err_code };
    fdb_tsl_iter_by_time(&tsdb, start_time_ms, current_time_ms, app_log_send_fields, args );

    err_code |= app_log_send_eof (reply_fp);

    return err_code;
}
