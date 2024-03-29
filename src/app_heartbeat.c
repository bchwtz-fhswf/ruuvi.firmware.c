/**
 * @file app_heartbeat.c
 * @author Otso Jousimaa <otso@ojousima.net>
 * @date 2020-06-17
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include "app_config.h"
#include "app_comms.h"
#include "app_dataformats.h"
#include "app_heartbeat.h"
#include "app_led.h"
#include "app_log.h"
#include "app_sensor.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_endpoint_5.h"
#include "ruuvi_interface_communication.h"
#include "ruuvi_interface_communication_radio.h"
#include "ruuvi_interface_rtc.h"
#include "ruuvi_interface_scheduler.h"
#include "ruuvi_interface_timer.h"
#include "ruuvi_interface_watchdog.h"
#include "ruuvi_task_adc.h"
#include "ruuvi_task_advertisement.h"
#include "ruuvi_task_gatt.h"
#include "ruuvi_task_nfc.h"
#include "ruuvi_task_flash.h"


#include <stdio.h>
#include <stdarg.h>


#define U8_MASK (0xFFU)
#define U8_MASK (0xFFU)
#define APP_DF_3_ENABLED 0
#define APP_DF_5_ENABLED 1
#define APP_DF_8_ENABLED 0
#define APP_DF_FA_ENABLED 0


static ri_timer_id_t heart_timer; //!< Timer for updating data.

static uint64_t last_heartbeat_timestamp_ms;

static app_dataformat_t m_dataformat_state; //!< State of heartbeat.

static app_dataformats_t m_dataformats_enabled =
{
    .DF_3  = APP_DF_3_ENABLED,
    .DF_5  = APP_DF_5_ENABLED,
    .DF_8  = APP_DF_8_ENABLED,
    .DF_FA = APP_DF_FA_ENABLED
}; //!< Flags of enabled formats



#ifndef CEEDLING
static
#endif
uint16_t m_measurement_count; //!< Increment on new samples.

static uint64_t last_heartbeat_timestamp_ms;
static uint16_t current_heartbeat_ms = APP_HEARTBEAT_INTERVAL_MS; //As inital value

static const uint16_t file_id = 24U;
static const uint16_t record_id = 24U;

static const uint16_t min_hearbeat = 100U; //minimum hearbeat in ms

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

static rd_status_t encode_to_5 (const rd_sensor_data_t * const data,
                                ri_comm_message_t * const msg)
{
    rd_status_t err_code = RD_SUCCESS;
    re_5_data_t ep_data = {0};
    ep_data.accelerationx_g   = rd_sensor_data_parse (data, RD_SENSOR_ACC_X_FIELD);
    ep_data.accelerationy_g   = rd_sensor_data_parse (data, RD_SENSOR_ACC_Y_FIELD);
    ep_data.accelerationz_g   = rd_sensor_data_parse (data, RD_SENSOR_ACC_Z_FIELD);
    ep_data.humidity_rh       = rd_sensor_data_parse (data, RD_SENSOR_HUMI_FIELD);
    ep_data.pressure_pa       = rd_sensor_data_parse (data, RD_SENSOR_PRES_FIELD);
    ep_data.temperature_c     = rd_sensor_data_parse (data, RD_SENSOR_TEMP_FIELD);
    ep_data.measurement_count = m_measurement_count;
    ep_data.movement_count    = (uint8_t) (app_sensor_event_count_get() & U8_MASK);
    err_code |= ri_radio_address_get (&ep_data.address);
    err_code |= ri_adv_tx_power_get (&ep_data.tx_power);
    err_code |= rt_adc_vdd_get (&ep_data.battery_v);
    re_5_encode (msg->data, &ep_data);
    msg->data_length = RE_5_DATA_LENGTH;
    return err_code;
}

static rd_status_t send_adv (ri_comm_message_t * const p_msg)
{
    rd_status_t err_code = RD_SUCCESS;
    const uint8_t repeat_count = app_comms_bleadv_send_count_get();

    if (APP_COMM_ADV_DISABLE != repeat_count)
    {
        if (APP_COMM_ADV_REPEAT_FOREVER == repeat_count)
        {
            p_msg->repeat_count = RI_COMM_MSG_REPEAT_FOREVER;
        }
        else
        {
            p_msg->repeat_count = repeat_count;
        }

        err_code |= rt_adv_send_data (p_msg);
    }
    else
    {
        rt_adv_stop();
    }

    return err_code;
}

/**
 * @brief When timer triggers, schedule reading sensors and sending data.
 *
 * @param[in] p_context Always NULL.
 */
#ifndef CEEDLING
static
#endif
void heartbeat (void * p_event, uint16_t event_size)
{
    ri_comm_message_t msg = {0};
    rd_status_t err_code = RD_SUCCESS;
    bool heartbeat_ok = false;
    rd_sensor_data_t data = { 0 };
    size_t buffer_len = RI_COMM_MESSAGE_MAX_LENGTH;
    data.fields = app_sensor_available_data();
    float data_values[rd_sensor_data_fieldcount (&data)];
    data.data = data_values;
    app_sensor_get (&data);
    // Sensor read takes a long while, indicate activity once data is read.
    app_led_activity_signal (true);
    m_dataformat_state = app_dataformat_next (m_dataformats_enabled, m_dataformat_state);
    // app_dataformat_encode (msg.data, &buffer_len, &data, m_dataformat_state); can't be called or else program crashes.
    msg.data_length = (uint8_t) buffer_len;
    encode_to_5 (&data, &msg);

    float humidity_rh = rd_sensor_data_parse (&data, RD_SENSOR_HUMI_FIELD);
    float pressure_pa = rd_sensor_data_parse (&data, RD_SENSOR_PRES_FIELD);
    float temperature_c = rd_sensor_data_parse (&data, RD_SENSOR_TEMP_FIELD);
    float accelerationx_g   = rd_sensor_data_parse (&data, RD_SENSOR_ACC_X_FIELD);
    float accelerationy_g   = rd_sensor_data_parse (&data, RD_SENSOR_ACC_Y_FIELD);
    float accelerationz_g   = rd_sensor_data_parse (&data, RD_SENSOR_ACC_Z_FIELD);
        
    //LOGDf("Heartbeat: Humidity Value %f\r\n", humidity_rh);
    //LOGDf("Heartbeat: Pressure Value %f\r\n", pressure_pa);
    //LOGDf("Heartbeat: Temperature Value %f\r\n", temperature_c);
    //LOGDf("Heartbeat: ACC Value X Value %f\r\n", accelerationx_g);
    //LOGDf("Heartbeat: ACC Value Y Value %f\r\n", accelerationy_g);
    //LOGDf("Heartbeat: ACC Value Z Value %f\r\n\r\n", accelerationz_g);

    if (RE_5_INVALID_SEQUENCE == ++m_measurement_count)
    {
        m_measurement_count = 0;
    }

    err_code = send_adv (&msg);
    // Advertising should always be successful
    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    if (RD_SUCCESS == err_code)
    {
        heartbeat_ok = true;
    }

    // Cut endpoint 5 data to fit into GATT msg.
    msg.data_length = 18;
    // Gatt Link layer takes care of delivery.
    msg.repeat_count = 1;
    err_code = rt_gatt_send_asynchronous (&msg);

    if (RD_SUCCESS == err_code)
    {
        heartbeat_ok = true;
    }

    // Restore original message length for NFC
    msg.data_length = (uint8_t) buffer_len;
    err_code = rt_nfc_send (&msg);

    if (RD_SUCCESS == err_code)
    {
        heartbeat_ok = true;
    }

    if (heartbeat_ok)
    {
        ri_watchdog_feed();
        last_heartbeat_timestamp_ms = ri_rtc_millis();
    }
    
    // Turn LED off before starting lengthy flash operations
    app_led_activity_signal (false);
    err_code = app_log_process (&data);
    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
}


static inline rd_status_t rt_heartbeat_store (uint16_t heartbeat_ms)
{
    rd_status_t err_code = RD_SUCCESS;
    
    if (rt_flash_busy())
    {
        err_code |= RD_ERROR_BUSY;
    }
    else if (heartbeat_ms < min_hearbeat)
    {
        err_code |= RD_ERROR_INVALID_PARAM;
    }
    else
    {
        current_heartbeat_ms = heartbeat_ms;
        err_code |= rt_flash_store (file_id, record_id,
                                    & (current_heartbeat_ms),
                                    sizeof (uint32_t));
    }

    return err_code;
}


static inline rd_status_t rt_heartbeat_load ()
{
    rd_status_t err_code = RD_SUCCESS;

    if (rt_flash_busy())
    {
        err_code |= RD_ERROR_BUSY;
    }
    else
    {
        err_code |= rt_flash_load (file_id, record_id,
                                   & (current_heartbeat_ms),
                                   sizeof (uint32_t));
        if(err_code == RD_ERROR_NOT_FOUND)
        {
            current_heartbeat_ms = APP_HEARTBEAT_INTERVAL_MS;
            err_code = RD_SUCCESS;
        }
    }
    return err_code;
}


/**
 * @brief When timer triggers, schedule reading sensors and sending data.
 *
 * @param[in] p_context Always NULL.
 */
#ifndef CEEDLING
static
#endif
void schedule_heartbeat_isr (void * const p_context)
{
    ri_scheduler_event_put (NULL, 0U, &heartbeat);
}

rd_status_t app_heartbeat_init ()
{
    rd_status_t err_code = RD_SUCCESS;

    if ( (!ri_timer_is_init()) || (!ri_scheduler_is_init()))
    {
        err_code |= RD_ERROR_INVALID_STATE;
    }
    else
    {
        err_code |= ri_timer_create (&heart_timer, RI_TIMER_MODE_REPEATED,
                                     &schedule_heartbeat_isr);

        if (RD_SUCCESS == err_code)
        {
            
            if(rt_heartbeat_load() == RD_SUCCESS) 
            {
                err_code |= ri_timer_start (heart_timer, current_heartbeat_ms, NULL);
            }
        }
    }

    return err_code;
}

rd_status_t app_heartbeat_start (uint16_t heartbeat_ms)
{
    rd_status_t err_code = RD_SUCCESS;

    if (NULL == heart_timer)
    {
        err_code |= RD_ERROR_INVALID_STATE;
    }
    else
    {
        heartbeat (NULL, 0);
        err_code |= rt_heartbeat_store(heartbeat_ms);
        err_code |= ri_timer_start (heart_timer, current_heartbeat_ms, NULL);
    }

    return err_code;
}

rd_status_t app_heartbeat_stop (void)
{
    rd_status_t err_code = RD_SUCCESS;

    if (NULL == heart_timer)
    {
        err_code |= RD_ERROR_INVALID_STATE;
    }
    else
    {
        err_code |= ri_timer_stop (heart_timer);
    }

    return err_code;
}

bool app_heartbeat_overdue (void)
{
    return ri_rtc_millis() > (last_heartbeat_timestamp_ms +
                              APP_HEARTBEAT_OVERDUE_INTERVAL_MS);
}

uint16_t get_current_heartbeat(void)
{
    return current_heartbeat_ms;
}


#ifdef CEEDLING
// Give CEEDLING a handle to state of module.
ri_timer_id_t * get_heart_timer (void)
{
    return &heart_timer;
}
#endif
