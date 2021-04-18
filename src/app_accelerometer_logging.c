/**
 * @file app_accelerometer_logging.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include "app_accelerometer_logging.h"
#if APP_SENSOR_LOGGING

#include "ruuvi_boards.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_lis2dh12.h"
#include "ruuvi_interface_scheduler.h"
#include "ruuvi_interface_gpio_interrupt.h"
#include "ruuvi_task_gpio.h"
#include "ruuvi_task_flash.h"
#include "ruuvi_task_flash_ringbuffer.h"
#include "app_sensor.h"
#include "app_comms.h"
#include "crc16.h"

#include <stdlib.h>
#include <string.h>

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
 * @brief Structure for storing data from FIFO
 */
typedef struct logged_data_t
{
    /** @brief timestamp when the data is logged */
    uint64_t timestamp;
    /** @brief memory for storing data from fifo */
    uint8_t data[RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT];
    /** @brief memory for storing data from fifo */
    uint8_t data_to_store[RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT];
    /** @brief number of elements with data from fifo */
    uint8_t num_elements;
    /** @brief position of next element to read */
    uint8_t element_pos;
    /** @brief save last status */
    rd_status_t last_status;
    /** @brief pointer to sensor configuration */
    rd_sensor_configuration_t* config;
    /** @brief sample counter */
    uint8_t sample_counter;
    /** @brief flashpage for collecting data */
    rt_flash_ringbuffer_flashpage_t flashpage;
} logged_data_t;

// store logged data
static logged_data_t logged_data;

// store original data_get function pointer
static rd_sensor_data_fp nologging_data_get = NULL;


static void pack8(const uint16_t sizeData, const uint8_t* const data, uint8_t* const packeddata) {
  for(int i=0; i<sizeData/2; i++) {
    packeddata[i] = data[ 1 + i*2 ];
  }
}

static void pack10(const uint16_t sizeData, const uint8_t* const data, uint8_t* const packeddata) {
  int j = 0;
  for(int i=0; i<sizeData; i+=8) {
    packeddata[j++] = (data[ i ] & 0xc0) | ((data[ 1 + i ] & 0xfc) >> 2);
    packeddata[j++] = ((data[ 1 + i ] & 0x03) << 6) | ((data[ 2 + i ] & 0xc0) >> 2) | ((data[ 3 + i ] & 0xf0) >> 4);
    packeddata[j++] = ((data[ 3 + i ] & 0x0f) << 4) | ((data[ 4 + i ] & 0xc0) >> 4) | ((data[ 5 + i ] & 0xc0) >> 6);
    packeddata[j++] = ((data[ 5 + i ] & 0x3f) << 2) | ((data[ 6 + i ] & 0xc0) >> 6); 
    packeddata[j++] = data[ 7 + i ]; 
  }
}

static void pack12(const uint16_t sizeData, const uint8_t* const data, uint8_t* const packeddata) {
  int j = 0;
  for(int i=0; i<sizeData; i+=4) {
    packeddata[j++] =            (data[ i ] & 0xf0) | ((data[ 1 + i ] & 0xf0) >> 4); 
    packeddata[j++] = ((data[ 1 + i ] & 0x0f) << 4) | ((data[ 2 + i ] & 0xf0) >> 4); 
    packeddata[j++] = data[ 3 + i ];
  }
}

static void fifo_full_handler (void * p_event_data, uint16_t event_size) {

    LOGD("FIFO full handler started\r\n");

    rd_status_t err_code = RD_SUCCESS;

    memset (logged_data.data, 0, RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT);

    for( size_t ii=0 ; ii<RI_LIS2DH12_FIFO_SIZE && err_code==RD_SUCCESS ; ii++) {

        // retrieve Data from sensor
        err_code |= ri_lis2dh12_acceleration_raw_get( logged_data.data + SIZE_ELEMENT*ii );

        // increment sample counter
        logged_data.sample_counter++;

        if(logged_data.config->reserved0 == 0 || logged_data.sample_counter == logged_data.config->reserved0 ) {
            // store value
            memcpy(logged_data.data_to_store + SIZE_ELEMENT*logged_data.num_elements, logged_data.data + SIZE_ELEMENT*ii, SIZE_ELEMENT);

            logged_data.num_elements++;
            logged_data.sample_counter = 0;
        }

        if( ! (logged_data.num_elements<RI_LIS2DH12_FIFO_SIZE) ) {
            // retrieve timestamp
            logged_data.timestamp = rd_sensor_timestamp_get();

            // pack the bits
            uint8_t sizeOfPackedData = sizeof(uint64_t) + (RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT * logged_data.config->resolution)/16; // how many bytes
            uint8_t packeddata[sizeof(uint64_t) + (RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT)];

            // copy timestamp
            memcpy(packeddata, &logged_data.timestamp, sizeof(uint64_t));

            // copy compacted sensor data
            switch(logged_data.config->resolution) {
              case 8:
                pack8(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data_to_store, packeddata + sizeof(uint64_t));
                break;
              case 10:
                pack10(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data_to_store, packeddata + sizeof(uint64_t));
                break;
              case 12:
                pack12(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data_to_store, packeddata + sizeof(uint64_t));
                break;
              default:
                err_code |= RD_ERROR_INTERNAL;
                break;
            }

            // Collect Data in Flash page
            err_code |= rt_flash_ringbuffer_collect_flashpage (APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  APP_FLASH_RECORD_ACCELERATION_RINGBUFFER,
                sizeOfPackedData, packeddata, &logged_data.flashpage);

            // reset counter
            logged_data.num_elements = 0;

            LOGD("FIFO storing sample\r\n");
        }
    }

    LOGD("FIFO read\r\n");

    logged_data.last_status = err_code;
    logged_data.element_pos = 0;

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
}

static void on_fifo_full (const ri_gpio_evt_t evt) {

    LOGD("FIFO full interrupt occured\r\n");

    rd_status_t err_code = ri_scheduler_event_put (&evt, sizeof (ri_gpio_evt_t),
                           fifo_full_handler);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);
}

rd_status_t lis2dh12_logged_data_get (rd_sensor_data_t * const data)
{
    if (NULL == data) { return RD_ERROR_NULL; }

    rd_status_t err_code = RD_SUCCESS;

    if(logged_data.element_pos < RI_LIS2DH12_FIFO_SIZE) {

      axis3bit16_t* raw_acceleration = (axis3bit16_t*)logged_data.data + logged_data.element_pos*SIZE_ELEMENT;

      // Parse raw data
      err_code |= ri_lis2dh12_raw_data_parse(data, raw_acceleration, NULL);

      //LOGD("\r\nDequeued RAW accelaration data");
      //ri_log_hex (RI_LOG_LEVEL_DEBUG, raw_acceleration.u8bit, 6);

      // position for next element
      logged_data.element_pos++;
    }

    return err_code;
}

rd_status_t app_disable_sensor_logging(void) {

    // is it curently active ?
    if(nologging_data_get==NULL) {
        return RD_ERROR_INVALID_STATE;
    }

    // find LIS2DH12
    rt_sensor_ctx_t *lis2dh12 = app_sensor_find("LIS2DH12");

    if(lis2dh12==NULL) { return RD_ERROR_NOT_FOUND; }

    rd_status_t err_code = RD_SUCCESS;

    // disable GPIO interrupt
    err_code |= ri_gpio_interrupt_disable (lis2dh12->fifo_pin);

    // disable fifo on sensor
    err_code |= lis2dh12->sensor.fifo_enable(false);

    // disable generating interrupt on sensor
    err_code |= lis2dh12->sensor.fifo_interrupt_enable(false);

    // save nologging data_get function in sensor context
    lis2dh12->sensor.data_get = nologging_data_get;
    nologging_data_get = NULL;

    // Enable temperature
    lis2dh12->sensor.provides.datas.temperature_c = 1;

    // drop ringbuffer
    err_code = rt_flash_ringbuffer_delete(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  APP_FLASH_RECORD_ACCELERATION_RINGBUFFER);

    return err_code;
}

rd_status_t app_enable_sensor_logging(void) {

    // is it already active ?
    if(nologging_data_get!=NULL) {
        return RD_ERROR_INVALID_STATE;
    }

    // find LIS2DH12
    rt_sensor_ctx_t *lis2dh12 = app_sensor_find("LIS2DH12");

    if(lis2dh12==NULL) { return RD_ERROR_NOT_FOUND; }

    LOG("Start initializing sensor FIFO logging\r\n");

    if(!rt_gpio_is_init()) {
        return RD_ERROR_NOT_INITIALIZED;
    }

    rd_status_t err_code = RD_SUCCESS;

    // save original data_get function
    nologging_data_get = lis2dh12->sensor.data_get;

    // create ringbuffer
    // When reactivating acceleration logging after reboot the ringbuffer exists.
    // Ignore RD_ERROR_INVALID_STATE
    err_code = ~RD_ERROR_INVALID_STATE &
      rt_flash_ringbuffer_create(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  
          APP_FLASH_RECORD_ACCELERATION_RINGBUFFER,
          RT_FLASH_RINGBUFFER_MAXSIZE, 4073);

    if(err_code==RD_SUCCESS) {
      logged_data.flashpage.max_size = 4073;

      // enable GPIO interrupt
      err_code |= ri_gpio_interrupt_enable (lis2dh12->fifo_pin,
                                       RI_GPIO_SLOPE_LOTOHI, 
                                       RI_GPIO_MODE_INPUT_PULLUP,
                                       &on_fifo_full);

      // enable fifo on sensor
      err_code |= lis2dh12->sensor.fifo_enable(true);

      // enable generating interrupt on sensor
      err_code |= lis2dh12->sensor.fifo_interrupt_enable(true);

      // store new data_get function in sensor context
      lis2dh12->sensor.data_get = &lis2dh12_logged_data_get;

      // store pointer to config
      logged_data.config = &lis2dh12->configuration;

      // initialize
      logged_data.last_status = RD_SUCCESS;
      logged_data.sample_counter = 0;
      logged_data.num_elements = 0;
      logged_data.element_pos = 0xff;

      // with acceleration logging enabled we provide no temperature by LIS2DH12
      lis2dh12->sensor.provides.datas.temperature_c = 0;
    }

    if(err_code==RD_SUCCESS) {
      LOGD("Successfully initialized FIFO logging\r\n");
    } else {
      LOGD("Error initializing FIFO logging\r\n");
    }

    return err_code;
}

rd_status_t send_data_block(const ri_comm_xfer_fp_t reply_fp, uint32_t size_of_data, uint8_t *data, uint16_t *crc) {

    rd_status_t err_code = RD_SUCCESS;
    uint32_t pos = 0;
    ri_comm_message_t msg;
    msg.data_length = 20;
    msg.repeat_count = 1;

    while(pos<size_of_data && err_code==RD_SUCCESS) {
        LOGD("send block\r\n");
        if(pos+msg.data_length > size_of_data) {
            msg.data_length = 1 + size_of_data - pos;
        }

        msg.data[0] = 0xfc;
        memcpy(msg.data+1, data+pos, msg.data_length-1);
        err_code |= app_comms_blocking_send(reply_fp, &msg);
        pos += msg.data_length-1;

        // update crc
        *crc = crc16_compute(msg.data+1, msg.data_length-1, crc);
    }

    return err_code;
}


rd_status_t app_acc_logging_send_last_sample(const ri_comm_xfer_fp_t reply_fp) {

    // when logging is not active return error
    if(nologging_data_get==NULL) {
        return RD_ERROR_INVALID_STATE;
    }

    rd_status_t err_code = RD_SUCCESS;

    // pack the bits
    uint8_t sizeOfPackedData = sizeof(uint64_t) + (RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT * logged_data.config->resolution)/16; // how many bytes
    uint8_t packeddata[sizeof(uint64_t) + (RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT)];

    // copy timestamp
    memcpy(packeddata, &logged_data.timestamp, sizeof(uint64_t));

    // copy compacted sensor data
    switch(logged_data.config->resolution) {
      case 8:
        pack8(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
        break;
      case 10:
        pack10(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
        break;
      case 12:
        pack12(RI_LIS2DH12_FIFO_SIZE * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
        break;
      default:
        err_code |= RD_ERROR_INTERNAL;
        break;
    }

    uint16_t crc = 0xffff;

    // send data
    err_code |= send_data_block(reply_fp, sizeOfPackedData, packeddata, &crc);

    LOGD("send footer\r\n");
    ri_comm_message_t msg;
    msg.repeat_count = 1;
    msg.data[0] = 0xfb; // Header
    msg.data[2] = err_code;

    if(err_code==RD_SUCCESS) {
      msg.data[1] = 0x03;

      // Bytes 3 to 10: Config
      memcpy(msg.data+3, logged_data.config, sizeof(rd_sensor_configuration_t));

      // CRC
      msg.data[11] = (crc & 0xff00) >> 8; 
      msg.data[12] = crc & 0xff;
      msg.data_length = 13;

    } else {
      // in case of error only send error code
      msg.data[1] = 0x00;
      msg.data_length = 3;
    }

    err_code |= app_comms_blocking_send(reply_fp, &msg);

    return err_code;
}

rd_status_t app_acc_logging_send_logged_data(const ri_comm_xfer_fp_t reply_fp) {

    // when logging is not active return error
    if(nologging_data_get==NULL) {
        return RD_ERROR_INVALID_STATE;
    }

    rd_status_t err_code = RD_SUCCESS;
    uint16_t crc = 0xffff;
      
    // load first page from ringbuffer
    rt_flash_ringbuffer_flashpage_t flashpage;
    rd_status_t ringbuffer_status = rt_flash_ringbuffer_read(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  
        APP_FLASH_RECORD_ACCELERATION_RINGBUFFER, sizeof(rt_flash_ringbuffer_flashpage_t), &flashpage);

    // add ringbuffer error to err_code
    err_code |= ~RD_ERROR_DATA_SIZE & ringbuffer_status;

    while( !(ringbuffer_status & RD_ERROR_DATA_SIZE) && err_code==RD_SUCCESS ) {
        LOGD("send data from ringbuffer\r\n");

        // send data
        err_code |= send_data_block(reply_fp, flashpage.actual_size, flashpage.packeddata, &crc);

        // read next page from ringbuffer
        ringbuffer_status = rt_flash_ringbuffer_read(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  
            APP_FLASH_RECORD_ACCELERATION_RINGBUFFER, sizeof(rt_flash_ringbuffer_flashpage_t), &flashpage);

        // add ringbuffer error to err_code
        err_code |= ~RD_ERROR_DATA_SIZE & ringbuffer_status;
    }

    if(err_code==RD_SUCCESS) {
      LOGD("send data from memory\r\n");

      // copy and clear current flashpage
      memcpy(&flashpage, &logged_data.flashpage, sizeof(rt_flash_ringbuffer_flashpage_t));
      logged_data.flashpage.actual_size = 0;

      // send data
      err_code |= send_data_block(reply_fp, flashpage.actual_size, flashpage.packeddata, &crc);
    }

    LOGD("send footer\r\n");
    ri_comm_message_t msg;
    msg.repeat_count = 1;
    msg.data[0] = 0xfb; // Header
    msg.data[2] = err_code;

    if(err_code==RD_SUCCESS) {
      msg.data[1] = 0x03;

      // Bytes 3 to 10: Config
      memcpy(msg.data+3, logged_data.config, sizeof(rd_sensor_configuration_t));

      // CRC
      msg.data[11] = (crc & 0xff00) >> 8; 
      msg.data[12] = crc & 0xff;
      msg.data_length = 13;

    } else {
      // in case of error only send error code
      msg.data[1] = 0x00;
      msg.data_length = 3;
    }

    err_code |= app_comms_blocking_send(reply_fp, &msg);

    return err_code;
}

rd_status_t app_acc_logging_state(void) {

    // when logging is not active return error
    if(nologging_data_get!=NULL) {
        return RD_SUCCESS;
    } else {
        return RD_ERROR_NOT_INITIALIZED;
    }
}

rd_status_t app_acc_logging_configuration_set (rt_sensor_ctx_t* sensor, 
                          rd_sensor_configuration_t* new_config) {

    rd_status_t err_code = RD_SUCCESS;
    bool is_new_configuration = false;

    // check the parameters if they should be changed and 
    // if they are different from actual values
    if(new_config->samplerate!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.samplerate) {
      is_new_configuration = true;
      sensor->configuration.samplerate = new_config->samplerate;
    }
    if(new_config->resolution!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.resolution) {
      is_new_configuration = true;
      sensor->configuration.resolution = new_config->resolution;
    }
    if(new_config->scale!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.scale) {
      is_new_configuration = true;
      sensor->configuration.scale = new_config->scale;
    }
    if(new_config->dsp_function!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.dsp_function) {
      is_new_configuration = true;
      sensor->configuration.dsp_function = new_config->dsp_function;
    }
    if(new_config->dsp_parameter!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.dsp_parameter) {
      is_new_configuration = true;
      sensor->configuration.dsp_parameter = new_config->dsp_parameter;
    }
    if(new_config->mode!=RD_SENSOR_CFG_NO_CHANGE && new_config->samplerate!=sensor->configuration.mode) {
      is_new_configuration = true;
      sensor->configuration.mode = new_config->mode;
    }
    if(new_config->reserved0!=RD_SENSOR_CFG_NO_CHANGE && new_config->reserved0!=sensor->configuration.reserved0) {
      // frequency divider
      is_new_configuration = true;
      sensor->configuration.reserved0 = new_config->reserved0;
    }

    // if there is a new configuration
    if(is_new_configuration) {
        // set new sensor configuration
        err_code |= rd_sensor_configuration_set(&sensor->sensor, &sensor->configuration);
        // store configuration in flash
        err_code |= rt_sensor_store(sensor);
        // clear ringbuffer
        err_code = rt_flash_ringbuffer_clear(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  APP_FLASH_RECORD_ACCELERATION_RINGBUFFER);
        // clear logged but not saved data
        logged_data.num_elements = 0;
        logged_data.sample_counter = 0;
        logged_data.element_pos = 0xff;
    }

    logged_data.last_status = err_code;

    return err_code;
}

rd_status_t app_acc_logging_init(void) {

  rt_flash_ringbuffer_state_t state;

  // Load State
  rd_status_t err_code = rt_flash_load (APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  APP_FLASH_RECORD_ACCELERATION_RINGBUFFER, &state, sizeof(state));

  if(err_code==RD_SUCCESS) {
    // activate logging
    return app_enable_sensor_logging();

  } else {
    // Ringbuffer seems to be non existant
    // do not activate logging
    // but return RD_SUCCESS
    return RD_SUCCESS;
  }
}

rd_status_t app_acc_logging_uninit(void) {

  // disable logging
  // ignore error in case logging is not active
  return ~RD_ERROR_INVALID_STATE & app_disable_sensor_logging();
}

rd_status_t app_acc_logging_statistic (uint8_t* const statistik) {

    rd_status_t err_code = RD_SUCCESS;

    statistik[0] = logged_data.last_status;

    err_code |= rt_flash_ringbuffer_statistic(APP_FLASH_FILE_ACCELERATION_RINGBUFFER,  
                APP_FLASH_RECORD_ACCELERATION_RINGBUFFER, statistik+1);

    return err_code;
}

#else
rd_status_t app_acc_logging_state(void) { return RD_ERROR_NOT_ENABLED; }
#endif