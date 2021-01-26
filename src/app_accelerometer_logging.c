/**
 * @file app_accelerometer_logging.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#include "ruuvi_boards.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_task_sensor.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_lis2dh12.h"
#include "ruuvi_interface_scheduler.h"
#include "ruuvi_interface_gpio_interrupt.h"
#include "ruuvi_task_gpio.h"
#include "app_sensor.h"
#include "app_comms.h"
#include "app_accelerometer_logging.h"
#include "crc16.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE_ELEMENT (3 * sizeof(int16_t))

static inline void LOG (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_INFO, msg);
}

static inline void LOGD (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_DEBUG, msg);
}

/**
 * @brief Structure for storing data from FIFO
 */
typedef struct logged_data_t
{
    /** @brief timestamp when the data is logged */
    uint64_t timestamp;
    /** @brief memory for storing data from fifo */
    uint8_t *data;
    /** @brief number of elements with data from fifo */
    size_t num_elements;
    /** @brief position of next element to read */
    size_t element_pos;
} logged_data_t;

// store logged data
static logged_data_t logged_data;

// store original sensor structure
static rd_sensor_data_fp nologging_data_get = NULL;


static void pack8(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  for(int i=0; i<sizeData/2; i++) {
    packeddata[i] = data[ 1 + i*2 ];
  }
}

static void pack10(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  char dbgmsg[50];
  uint16_t wert;

  int j = 0;
  for(int i=0; i<sizeData/8; i++) {
    packeddata[j++] = (data[ i*8 ] & 0xc0) | ((data[ 1 + i*8 ] & 0xfc) >> 2);
    packeddata[j++] = ((data[ 1 + i*8 ] & 0x03) << 6) | ((data[ 2 + i*8 ] & 0xc0) >> 2) | ((data[ 3 + i*8 ] & 0xf0) >> 4);
    packeddata[j++] = ((data[ 3 + i*8 ] & 0x0f) << 4) | ((data[ 4 + i*8 ] & 0xc0) >> 4) | ((data[ 5 + i*8 ] & 0xc0) >> 6);
    packeddata[j++] = ((data[ 5 + i*8 ] & 0x3f) << 2) | ((data[ 6 + i*8 ] & 0xc0) >> 6); 
    packeddata[j++] = data[ 7 + i*8 ]; 
  }
}

static void pack12(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  int j = 0;
  for(int i=0; i<sizeData/4; i++) {
    packeddata[j++] =     ((data[ i*4 ] & 0x0f) << 4) | ((data[ 1 + i*4 ] & 0xf0) >> 4); 
    packeddata[j++] = ((data[ 1 + i*4 ] & 0x0f) << 4) | (data[ 2 + i*4 ] & 0x0f); 
    packeddata[j++] = data[ 3 + i*4 ];
  }
}

static void fifo_full_handler (void * p_event_data, uint16_t event_size) {

    LOGD("FIFO full handler started\r\n");

    // 1st parameter is a GPIO event
    ri_gpio_evt_t *event = (ri_gpio_evt_t*)p_event_data;

    char dbgmsg[50];
    rd_status_t err_code = RD_SUCCESS;

    if(err_code==RD_SUCCESS) {

        logged_data.num_elements = RI_LIS2DH12_FIFO_SIZE;
        
        if(logged_data.data==NULL) {
            // reserve memory for data
            logged_data.data = malloc(logged_data.num_elements * SIZE_ELEMENT);
            if(logged_data.data==NULL) {
                err_code |= RD_ERROR_NO_MEM;
            }
        }

        if(logged_data.data!=NULL) {
            memset(logged_data.data, 0, logged_data.num_elements * SIZE_ELEMENT);
            logged_data.element_pos = 0;

            // retrieve Resolution from sensor
            uint8_t resolution;
            err_code |= ri_lis2dh12_resolution_get(&resolution);

            // retrieve timestamp
            logged_data.timestamp = rd_sensor_timestamp_get();

            // retrieve Data from sensor
            for( size_t ii=0 ; ii<logged_data.num_elements && err_code==RD_SUCCESS ; ii++) {
                err_code |= ri_lis2dh12_acceleration_raw_get(logged_data.data + SIZE_ELEMENT*ii );

                //LOGD("\r\nQueuing RAW accelaration data");
                //ri_log_hex (RI_LOG_LEVEL_DEBUG, logged_data.data + SIZE_ELEMENT*ii, SIZE_ELEMENT);
                //LOGD("\r\n\r\n");
/*
                *dbgmsg=0;
                snprintf(dbgmsg, sizeof(dbgmsg)-1, "\r\nValue %d from FIFO: ", ii);
                LOGD(dbgmsg);
                ri_log_hex (RI_LOG_LEVEL_DEBUG, logged_data.data, SIZE_ELEMENT * 4);

                if(err_code==RD_SUCCESS) {
                    // do logging
                    *dbgmsg=0;
                    snprintf(dbgmsg, sizeof(dbgmsg)-1, "\r\nValue %d from FIFO\r\n", ii);
                    LOGD(dbgmsg);
                    LOG("ACC X raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, logged_data.data + SIZE_ELEMENT*ii + 0, 2);
                    LOG("\tACC Y raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, logged_data.data + SIZE_ELEMENT*ii + 2, 2);
                    LOG("\tACC Z raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, logged_data.data + SIZE_ELEMENT*ii + 4, 2);
                }
*/
            }

            // pack the bits
            uint8_t sizeOfPackedData = (logged_data.num_elements * SIZE_ELEMENT * resolution)/16; // how many bytes
            uint8_t* packeddata = malloc(sizeOfPackedData);

            if(packeddata!=NULL) {
              switch(resolution) {
                case 8:
                  pack8(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata);
                  break;
                case 10:
                  pack10(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata);
                  break;
                case 12:
                  pack12(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata);
                  break;
                default:
                  err_code |= RD_ERROR_INTERNAL;
                  break;
              }
            } else {
              err_code |= RD_ERROR_NO_MEM;
            }

            free(packeddata);

        } else {
            err_code |= RD_ERROR_NO_MEM;
        }

    }

    //LOGD("\r\nFIFO read\r\n");

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

    if(logged_data.element_pos < logged_data.num_elements) {
      // memcpy(dest, src, size)
      axis3bit16_t raw_acceleration;
      memcpy(raw_acceleration.u8bit, logged_data.data + logged_data.element_pos*SIZE_ELEMENT, SIZE_ELEMENT);

      // Parse raw data
      err_code |= ri_lis2dh12_raw_data_parse(data, &raw_acceleration, NULL);

      //LOGD("\r\nDequeued RAW accelaration data");
      //ri_log_hex (RI_LOG_LEVEL_DEBUG, raw_acceleration.u8bit, 6);

      // position for next element
      logged_data.element_pos++;
    }

    return err_code;
}

rd_status_t app_disable_sensor_logging(void) {

    // is it already active ?
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

    // save nologging sensor in central structure
    lis2dh12->sensor.data_get = nologging_data_get;
    nologging_data_get = NULL;

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

    // save logging sensor in central structure
    nologging_data_get = lis2dh12->sensor.data_get;

    // enable GPIO interrupt
    err_code |= ri_gpio_interrupt_enable (lis2dh12->fifo_pin,
                                     RI_GPIO_SLOPE_LOTOHI, 
                                     RI_GPIO_MODE_INPUT_PULLUP,
                                     &on_fifo_full);

    // enable fifo on sensor
    err_code |= lis2dh12->sensor.fifo_enable(true);

    // enable generating interrupt on sensor
    err_code |= lis2dh12->sensor.fifo_interrupt_enable(true);

    // save new data_get function
    lis2dh12->sensor.data_get = &lis2dh12_logged_data_get;

    return err_code;
}


rd_status_t app_acc_logging_send_last_sample(const ri_comm_xfer_fp_t reply_fp) {

    // when logging is not active return error
    if(nologging_data_get==NULL) {
        return RD_ERROR_INVALID_STATE;
    }

    rd_status_t err_code = RD_SUCCESS;

    // read configuration
    rd_sensor_configuration_t currentConfiguration;
    memset(&currentConfiguration, 0, sizeof(rd_sensor_configuration_t));
    err_code |= ri_lis2dh12_samplerate_get (& (currentConfiguration.samplerate));
    err_code |= ri_lis2dh12_resolution_get (& (currentConfiguration.resolution));
    err_code |= ri_lis2dh12_scale_get (& (currentConfiguration.scale));
    err_code |= ri_lis2dh12_dsp_get (& (currentConfiguration.dsp_function), & (currentConfiguration.dsp_parameter));
    err_code |= ri_lis2dh12_mode_get (& (currentConfiguration.mode));
    
    // pack the bits
    uint8_t sizeOfPackedData = sizeof(uint64_t) + (logged_data.num_elements * SIZE_ELEMENT * currentConfiguration.resolution)/16; // how many bytes
    uint8_t* packeddata = malloc(sizeOfPackedData);

    if(packeddata!=NULL) {
      // copy timestamp
      memcpy(packeddata, &logged_data.timestamp, sizeof(uint64_t));

      // copy compacted sensor data
      switch(currentConfiguration.resolution) {
        case 8:
          pack8(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
          break;
        case 10:
          pack10(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
          break;
        case 12:
          pack12(logged_data.num_elements * SIZE_ELEMENT, logged_data.data, packeddata + sizeof(uint64_t));
          break;
        default:
          err_code |= RD_ERROR_INTERNAL;
          break;
      }
    } else {
      err_code |= RD_ERROR_NO_MEM;
    }

    uint16_t crc = 0xffff;
    uint8_t pos = 0;
    ri_comm_message_t msg;
    msg.data_length = 20;
    msg.repeat_count = 1;

    while(pos<sizeOfPackedData && err_code==RD_SUCCESS) {
        LOGD("sende Block\r\n");
        if(pos+msg.data_length > sizeOfPackedData) {
            msg.data_length = 1 + sizeOfPackedData - pos;
        }

        msg.data[0] = 0xfc;
        memcpy(msg.data+1, packeddata+pos, msg.data_length-1);
        err_code |= app_comms_blocking_send(reply_fp, &msg);
        pos += msg.data_length-1;

        // update crc
        crc = crc16_compute(msg.data+1, msg.data_length-1, &crc);
    }

    LOGD("send footer\r\n");
    msg.data[0] = 0xfb; // Header
    msg.data[2] = err_code;

    if(err_code==RD_SUCCESS) {
      msg.data[1] = 0x03;

      // Bytes 3 to 10: Config
      memcpy(msg.data+3, &currentConfiguration, sizeof(rd_sensor_configuration_t));

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

    free(packeddata);

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