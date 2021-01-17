/**
 * @file app_accelerometer_logging.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2020-11-06
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */
 
#include "ruuvi_boards.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_lis2dh12.h"
#include "ruuvi_interface_scheduler.h"
#include "ruuvi_interface_gpio_interrupt.h"
#include "ruuvi_task_gpio.h"
#include "app_sensor.h"
#include "app_accelerometer_logging.h"
#include "ruuvi_library_compress.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static inline void LOG (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_INFO, msg);
}

static inline void LOGD (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_DEBUG, msg);
}

// store sensors logging data
static rd_sensor_logging_t *logging_sensors = NULL;

// find sensor by interrupt pin
static rd_sensor_logging_t *find_sensor(ri_gpio_id_t fifo_pin) {
    rd_sensor_logging_t *sensor = logging_sensors;
    while(sensor) {
        if(sensor->fifo_pin==fifo_pin) {
            return sensor;
        } else {
            sensor = sensor->next;
        }
    }
    return NULL;
}

static rd_status_t pack8(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  for(int i=0; i<sizeData/2; i++) {
    packeddata[i] = data[ 1 + i*2 ];
  }
}

static rd_status_t pack10(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  int j = 0;
  for(int i=0; i<sizeData/4; i++) {
    packeddata[j++] =     data[ i*4 ] & 0x03 << 6 + data[ 1 + i*4 ] & 0xfc >> 2; 
    packeddata[j++] = data[ 1 + i*4 ] & 0x03 << 6 + data[ 2 + i*4 ] & 0x03 << 4 + data[ 3 + i*4 ] & 0xf0 >> 4; 
    packeddata[j++] = data[ 3 + i*4 ] & 0x0f << 4 + data[ 4 + i*4 ] & 0x03 << 2 + data[ 5 + i*4 ] & 0xc0 >> 6;
    packeddata[j++] = data[ 5 + i*4 ] & 0x3f << 2 + data[ 6 + i*4 ] & 0x03;
    packeddata[j++] = data[ 7 + i*4 ];
  }
}

static rd_status_t pack12(uint16_t sizeData, uint8_t* data, uint8_t* packeddata) {
  int j = 0;
  for(int i=0; i<sizeData/2; i++) {
    packeddata[j++] =     data[ i*4 ] & 0x0f << 4 + data[ 1 + i*4 ] & 0xf0 >> 4; 
    packeddata[j++] = data[ 1 + i*4 ] & 0x0f << 4 + data[ 2 + i*4 ] & 0x0f; 
    packeddata[j++] = data[ 3 + i*4 ];
  }
}

static void fifo_full_handler (void * p_event_data, uint16_t event_size) {

    LOGD("FIFO full handler started\r\n");

    // 1st parameter is a GPIO event
    ri_gpio_evt_t *event = (ri_gpio_evt_t*)p_event_data;

    char dbgmsg[50];
    rd_status_t err_code = RD_SUCCESS;

    // find sensor by interrupt pin
    rd_sensor_logging_t *sensor;
    sensor = find_sensor(event->pin);

    if(sensor==NULL) {
        err_code |= RD_ERROR_NOT_FOUND;
    }

    if(err_code==RD_SUCCESS) {

        sensor->num_elements = sensor->fifo_size;
        
        if(sensor->data==NULL) {
            // reserve memory for data
            sensor->data = malloc(sensor->num_elements * sensor->size_element);
            if(sensor->data==NULL) {
                err_code |= RD_ERROR_NO_MEM;
            }
        }

        if(sensor->data!=NULL) {
            memset(sensor->data, 0, sensor->num_elements * sensor->size_element);

            // retrieve Resolution from sensor
            uint8_t resolution;
            err_code |= sensor->p_sensor->resolution_get(&resolution);

            // retrieve Data from sensor
            for( size_t ii=0 ; ii<sensor->num_elements ; ii++) {
                err_code |= sensor->raw_get(sensor->data + sensor->size_element*ii );
                sensor->element_pos = 0;

                //LOGD("\r\nQueuing RAW accelaration data");
                //ri_log_hex (RI_LOG_LEVEL_DEBUG, sensor->data + sensor->size_element*ii, 6);
/*
                *dbgmsg=0;
                snprintf(dbgmsg, sizeof(dbgmsg)-1, "\r\nValue %d from FIFO: ", ii);
                LOGD(dbgmsg);
                ri_log_hex (RI_LOG_LEVEL_DEBUG, sensor->data, sensor->size_element * 4);

                if(err_code==RD_SUCCESS) {
                    // do logging
                    *dbgmsg=0;
                    snprintf(dbgmsg, sizeof(dbgmsg)-1, "\r\nValue %d from FIFO\r\n", ii);
                    LOGD(dbgmsg);
                    LOG("ACC X raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, sensor->data + sensor->size_element*ii + 0, 2);
                    LOG("\tACC Y raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, sensor->data + sensor->size_element*ii + 2, 2);
                    LOG("\tACC Z raw: ");
                    ri_log_hex (RI_LOG_LEVEL_DEBUG, sensor->data + sensor->size_element*ii + 4, 2);
                }
*/
            }

            // pack the bits
            uint8_t sizeOfPackedData = (sensor->num_elements * sensor->size_element * resolution)/16; // how many bytes
            uint8_t* packeddata = malloc(sizeOfPackedData);

            if(packeddata!=NULL) {
              switch(resolution) {
                case 8:
                  err_code |= pack8(sensor->num_elements * sensor->size_element, sensor->data, packeddata);
                  break;
                case 10:
                  err_code |= pack10(sensor->num_elements * sensor->size_element, sensor->data, packeddata);
                  break;
                case 12:
                  err_code |= pack12(sensor->num_elements * sensor->size_element, sensor->data, packeddata);
                  break;
              }
            } else {
              err_code |= RD_ERROR_NO_MEM;
            }



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

rd_status_t app_disable_sensor_logging(const rd_sensor_logging_t *sensor) {

    if(sensor==NULL) { return RD_ERROR_NULL; }

    rd_status_t err_code = RD_SUCCESS;

    // disable GPIO interrupt
    err_code |= ri_gpio_interrupt_disable (sensor->fifo_pin);

    // enable fifo on sensor
    err_code |= sensor->p_sensor->fifo_enable(false);

    // enable generating interrupt on sensor
    err_code |= sensor->p_sensor->fifo_interrupt_enable(false);

    // remove from logging sensors
    rd_sensor_logging_t *logging_sensor = logging_sensors;
    rd_sensor_logging_t *nextnext;
    logging_sensors = NULL;
    while(logging_sensor) {
        nextnext = logging_sensor->next;
        if(logging_sensor->fifo_pin!=sensor->fifo_pin) {
            logging_sensor->next = logging_sensors;
            logging_sensors = logging_sensor;
        }
        logging_sensor = nextnext;
    }

    return err_code;
}

rd_status_t app_enable_sensor_logging( rd_sensor_logging_t *sensor) {

    if(sensor==NULL) { return RD_ERROR_NULL; }

    LOG("Start initializing sensor FIFO logging\r\n");

    if(!rt_gpio_is_init()) {
        return RD_ERROR_NOT_INITIALIZED;
    }

    rd_status_t err_code = RD_SUCCESS;

    // enable GPIO interrupt
    err_code |= ri_gpio_interrupt_enable (sensor->fifo_pin,
                                     RI_GPIO_SLOPE_LOTOHI, 
                                     RI_GPIO_MODE_INPUT_PULLUP,
                                     on_fifo_full);

    // enable fifo on sensor
    err_code |= sensor->p_sensor->fifo_enable(true);

    // enable generating interrupt on sensor
    err_code |= sensor->p_sensor->fifo_interrupt_enable(true);

    // save as logging sensor
    sensor->next = logging_sensors;
    logging_sensors = sensor;

    return err_code;
}

rd_status_t app_get_data_from_queue(rd_sensor_logging_t *sensor, uint8_t *data) {

    if (NULL == sensor || NULL == data) { return RD_ERROR_NULL; }

    rd_status_t err_code = RD_SUCCESS;

    if(sensor->element_pos < sensor->num_elements) {
      // memcpy(dest, src, size)
      memcpy(data, sensor->data + sensor->element_pos*sensor->size_element, sensor->size_element);

      //LOGD("\r\nQueued RAW accelaration data");
      //ri_log_hex (RI_LOG_LEVEL_DEBUG, data, 6);

      // position for next element
      sensor->element_pos++;
    }

    return err_code;
}

