/**
 * Copyright (c) 2014 - 2017, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * Default values for board configuration. 
 */
#ifndef RUUVI_BOARD_DEFAULTS_H
#define RUUVI_BOARD_DEFAULTS_H
#include "ruuvi_boards.h"
#ifndef RB_MODEL_STRING
#   define RB_MODEL_STRING              "DEFAULT_BOARD"
#endif 
#ifndef RB_MANUFACTURER_STRING
#   define RB_MANUFACTURER_STRING       "No Company"
#endif 
#ifndef RB_BLE_NAME_STRING
#   define RB_BLE_NAME_STRING           "Devel"
#endif

// Radio definitions
#ifndef RB_BLE_MANUFACTURER_ID
#   define RB_BLE_MANUFACTURER_ID 0xFFFF // Interoperability testing ID.
#endif

#ifndef RB_TX_POWER_LIST
#   define RB_TX_POWER_0 -40
#   define RB_TX_POWER_1 -30
#   define RB_TX_POWER_2 -20
#   define RB_TX_POWER_3 -12
#   define RB_TX_POWER_4 -8
#   define RB_TX_POWER_5 -4
#   define RB_TX_POWER_6 -0
#   define RB_TX_POWER_7  4
#   define RB_TX_POWER_LIST { RB_TX_POWER_0 \\
                                    RB_TX_POWER_1 \\
                                    RB_TX_POWER_2 \\
                                    RB_TX_POWER_3 \\
                                    RB_TX_POWER_4 \\
                                    RB_TX_POWER_5 \\
                                    RB_TX_POWER_6 \\
                                    RB_TX_POWER_7 }
#   define RB_TX_POWER_MIN RB_TX_POWER_0
#   define RB_TX_POWER_MAX RB_TX_POWER_7
#endif 

#ifndef RB_BLE_2MBPS_SUPPORTED
#   define RB_BLE_2MBPS_SUPPORTED     0
#endif

#ifndef RB_BLE_CODED_SUPPORTED
#   define RB_BLE_CODED_SUPPORTED     0
#endif

// LED defaults
#ifndef RB_LEDS_NUMBER
#   define RB_LEDS_NUMBER               0
#endif
#ifndef RB_LEDS_ACTIVE_STATE
#   define RB_LEDS_ACTIVE_STATE         { }
#endif
#ifndef RB_LEDS_LIST
#   define RB_LEDS_LIST                 { }
#endif
#ifndef RB_LED_ACTIVITY
#   define RB_LED_ACTIVITY              RB_PIN_UNUSED
#endif
#ifndef RB_LED_STATUS_OK
#   define RB_LED_STATUS_OK             RB_PIN_UNUSED
#endif
#ifndef RB_LED_STATUS_ERROR
#   define RB_LED_STATUS_ERROR          RB_PIN_UNUSED
#endif
#ifndef RB_LED_BUTTON_PRESS
#   define RB_LED_BUTTON_PRESS          RB_PIN_UNUSED
#endif
#ifndef RB_LED_CONFIG_ENABLED
#   define RB_LED_CONFIG_ENABLED        RB_PIN_UNUSED
#endif

// Button defaults
#ifndef RB_BUTTON_PWR_PIN_NUMBER
#   define RB_BUTTON_PWR_PIN_NUMBER     0
#endif
#ifndef RB_BUTTON_PWR_PINS
#   define RB_BUTTON_PWR_PINS           {  }
#endif
#ifndef RB_BUTTONS_NUMBER
#   define RB_BUTTONS_NUMBER            0
#endif
#ifndef RB_BUTTONS_ACTIVE_STATE
#   define RB_BUTTONS_ACTIVE_STATE      { }
#endif
#ifndef RB_BUTTONS_LIST
#   define RB_BUTTONS_LIST              {  }
#endif
#ifndef RB_BUTTON_DEBOUNCE_PERIOD_MS
#   define RB_BUTTON_DEBOUNCE_PERIOD_MS 50
#endif
#ifndef RB_BUTTON_ENABLE_CONFIG
#   define RB_BUTTON_ENABLE_CONFIG      RB_PIN_UNUSED
#endif
#ifndef RB_BUTTON_CHANGE_MODE
#   define RB_BUTTON_CHANGE_MODE        RB_PIN_UNUSED
#endif

// SPI defaults
#ifndef RB_SPI_SCLK_PIN
#   define RB_SPI_SCLK_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_SPI_MOSI_PIN
#   define RB_SPI_MOSI_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_SPI_MISO_PIN
#   define RB_SPI_MISO_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_SPI_SS_ACCELEROMETER_PIN
#   define RB_SPI_SS_ACCELEROMETER_PIN  RB_PIN_UNUSED
#endif
#ifndef RB_SPI_SS_ENVIRONMENTAL_PIN
#   define RB_SPI_SS_ENVIRONMENTAL_PIN  RB_PIN_UNUSED
#endif
#ifndef RB_SPI_SS_LIST
#   define RB_SPI_SS_LIST               { }
#endif
#ifndef RB_SPI_SS_NUMBER
#   define RB_SPI_SS_NUMBER             2
#endif
#ifndef RB_SPI_FREQUENCY_1M
#   define RB_SPI_FREQUENCY_1M          0
#endif
#ifndef RB_SPI_FREQUENCY_2M
#   define RB_SPI_FREQUENCY_2M          1
#endif
#ifndef RB_SPI_FREQUENCY_4M
#   define RB_SPI_FREQUENCY_4M          2
#endif
#ifndef RB_SPI_FREQUENCY_8M
#   define RB_SPI_FREQUENCY_8M          3
#endif
#ifndef RB_SPI_FREQ
#   define RB_SPI_FREQ                  RB_SPI_FREQUENCY_1M
#endif

// I2C defaults
#ifndef RB_I2C_SDA_PIN
#   define RB_I2C_SDA_PIN               RB_PORT_PIN_MAP(0, 4)
#endif
#ifndef RB_I2C_SCL_PIN
#   define RB_I2C_SCL_PIN               RB_PORT_PIN_MAP(0, 5)
#endif
#ifndef RB_I2C_FREQUENCY_100k
#   define RB_I2C_FREQUENCY_100k        0
#endif
#ifndef RB_I2C_FREQUENCY_250k
#   define RB_I2C_FREQUENCY_250k        1
#endif
#ifndef RB_I2C_FREQUENCY_400k
#   define RB_I2C_FREQUENCY_400k        2
#endif
#ifndef RB_I2C_FREQ
#   define RB_I2C_FREQ                  RB_I2C_FREQUENCY_100k
#endif

// UART defaults
#ifndef RB_UART_TX_PIN
#   define RB_UART_TX_PIN               RB_PIN_UNUSED
#endif
#ifndef RB_UART_RX_PIN
#   define RB_UART_RX_PIN               RB_PIN_UNUSED
#endif
#ifndef RB_UART_CTS_PIN
#   define RB_UART_CTS_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_UART_RTS_PIN
#   define RB_UART_RTS_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_HWFC_ENABLED
#   define RB_HWFC_ENABLED              0
#endif
#ifndef RB_PARITY_ENABLED
#   define RB_PARITY_ENABLED            0
#endif
#ifndef RB_UART_BAUDRATE_9600
#   define RB_UART_BAUDRATE_9600        0
#endif
#ifndef RB_UART_BAUDRATE_115200
#   define RB_UART_BAUDRATE_115200      1
#endif
#ifndef RB_UART_BAUDRATE
#   define RB_UART_BAUDRATE             RB_UART_BAUDRATE_115200
#endif

// Interrupt defaults
#ifndef RB_INT_ACC1_PIN
#   define RB_INT_ACC1_PIN              RB_PIN_UNUSED
#endif
#ifndef RB_INT_ACC2_PIN
#   define RB_INT_ACC2_PIN              RB_PIN_UNUSED
#endif

// Total number of GPIO pins
#ifndef RB_GPIO_NUMBER
#   define RB_GPIO_NUMBER               32
#endif
// GPIO integration test I/O, connect these on devkit or GPIO test fails.
#ifndef RB_GPIO_TEST_INPUT
#   define RB_GPIO_TEST_INPUT           RB_PIN_UNUSED
#endif
#ifndef RB_GPIO_TEST_OUTPUT
#   define RB_GPIO_TEST_OUTPUT          RB_PIN_UNUSED
#endif

// Peripherals
#ifndef RB_DCDC_INTERNAL_INSTALLED
#   define RB_DCDC_INTERNAL_INSTALLED 0
#endif
#ifndef RB_NFC_INTERNAL_INSTALLED
#   define RB_NFC_INTERNAL_INSTALLED  0
#endif
#ifndef RB_FLASH_PAGE_SIZE
#   define RB_FLASH_PAGE_SIZE          0x1000 //!< Bytes
#endif
#ifndef RB_FLASH_SPACE_SMALL
#   define RB_FLASH_SPACE_SMALL        0      //!< Relative, "conserve all flash you can"
#endif
#ifndef RB_FLASH_SPACE_MEDIUM
#   define RB_FLASH_SPACE_MEDIUM       1      //!< Relative, "No need to optimize"
#endif
#ifndef RB_FLASH_SPACE_LARGE
#   define RB_FLASH_SPACE_LARGE        2      //!< Relative, "Lots of free storage"
#endif
#ifndef RB_FLASH_SPACE_AVAILABLE
#   define RB_FLASH_SPACE_AVAILABLE    RB_FLASH_SPACE_MEDIUM
#endif
#ifndef RB_RTC_INSTANCES
#   define RB_RTC_INSTANCES           2
#endif
#ifndef RB_FPU_ENABLED
#   define RB_FPU_ENABLED             0      //!< HW Floating Point Unit
#endif

// Available sensors
#ifndef RB_ENVIRONMENTAL_BME280_PRESENT
#   define RB_ENVIRONMENTAL_BME280_PRESENT   0
#endif
#ifndef RB_ENVIRONMENTAL_BME280_SPI_USE
#   define RB_ENVIRONMENTAL_BME280_SPI_USE   0
#endif
#ifndef RB_ENVIRONMENTAL_BME280_I2C_USE
#   define RB_ENVIRONMENTAL_BME280_I2C_USE   0
#endif
#ifndef RB_ENVIRONMENTAL_MCU_PRESENT
#   define RB_ENVIRONMENTAL_MCU_PRESENT      0
#endif
#ifndef RB_ENVIRONMENTAL_SHTCX_PRESENT
#   define RB_ENVIRONMENTAL_SHTCX_PRESENT    0
#endif
#ifndef RB_ACCELEROMETER_LIS2DH12_PRESENT
#   define RB_ACCELEROMETER_LIS2DH12_PRESENT 0
#endif
#ifndef RB_ACCELEROMETER_LIS2DH12_SPI_USE
#   define RB_ACCELEROMETER_LIS2DH12_SPI_USE 0
#endif
#ifndef RB_ACCELEROMETER_LIS2DH12_I2C_USE
#   define RB_ACCELEROMETER_LIS2DH12_I2C_USE 0
#endif

#ifndef RB_INT_LEVEL_PIN
#   define RB_INT_LEVEL_PIN RB_PIN_UNUSED
#endif
#ifndef RB_INT_FIFO_PIN
#   define RB_INT_FIFO_PIN  RB_PIN_UNUSED
#endif

#ifndef RB_TMP117_SENSOR_POWER_PIN
#   define RB_TMP117_SENSOR_POWER_PIN        RB_PIN_UNUSED
#endif
#ifndef RB_SHTCX_SENSOR_POWER_PIN
#   define RB_SHTCX_SENSOR_POWER_PIN         RB_PIN_UNUSED
#endif
#ifndef RB_DPS310_SENSOR_POWER_PIN
#   define RB_DPS310_SENSOR_POWER_PIN        RB_PIN_UNUSED
#endif
#ifndef RB_BME280_SENSOR_POWER_PIN
#   define RB_BME280_SENSOR_POWER_PIN        RB_PIN_UNUSED
#endif
#ifndef RB_LIS2DH12_SENSOR_POWER_PIN
#   define RB_LIS2DH12_SENSOR_POWER_PIN      RB_PIN_UNUSED
#endif
#ifndef RB_I2C_BUS_POWER_PIN
#   define RB_I2C_BUS_POWER_PIN              RB_PIN_UNUSED
#endif

#endif