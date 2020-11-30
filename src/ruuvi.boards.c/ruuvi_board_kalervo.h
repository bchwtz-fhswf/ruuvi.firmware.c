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
#ifndef RUUVI_BOARD_KALERVO_B_H
#define RUUVI_BOARD_KALERVO_B_H
#include "ruuvi_boards.h"
#define RB_MODEL_STRING              "Kalervo"
#define RB_MANUFACTURER_STRING       "Ruuvi Innovations Ltd"
#define RB_BLE_NAME_STRING           "Kale"
// Radio definitions
#define RB_BLE_MANUFACTURER_ID 0x0499 // Ruuvi Innovations
#define RB_TX_POWER_0 -40
#define RB_TX_POWER_1 -30
#define RB_TX_POWER_2 -20
#define RB_TX_POWER_3 -12
#define RB_TX_POWER_4 -8
#define RB_TX_POWER_5 -4
#define RB_TX_POWER_6 -0
#define RB_TX_POWER_7  4
#define RB_TX_POWER_LIST { RB_TX_POWER_0 \\
                                    RB_TX_POWER_1 \\
                                    RB_TX_POWER_2 \\
                                    RB_TX_POWER_3 \\
                                    RB_TX_POWER_4 \\
                                    RB_TX_POWER_5 \\
                                    RB_TX_POWER_6 \\
                                    RB_TX_POWER_7 }
#define RB_TX_POWER_MIN RB_TX_POWER_0
#define RB_TX_POWER_MAX RB_TX_POWER_7
#define RB_BLE_2MBPS_SUPPORTED     1
#define RB_BLE_CODED_SUPPORTED     1

// LED definitions for RuuviTag B
#define RB_LEDS_NUMBER               2
#define RB_LED_1                     RB_PORT_PIN_MAP(0, 17)
#define RB_LED_2                     RB_PORT_PIN_MAP(0, 19)
#define RB_LEDS_ACTIVE_STATE         { 0, 0 }
#define RB_LEDS_LIST                 { RB_LED_1, RB_LED_2 }
#define RB_LED_RED                   RB_LED_1
#define RB_LED_GREEN                 RB_LED_2
#define RB_LED_ACTIVITY              RB_LED_GREEN
#define RB_LED_STATUS_OK             RB_LED_GREEN
#define RB_LED_STATUS_ERROR          RB_LED_RED

// Button definitions for RuuviTag B
#define RB_BUTTONS_NUMBER            1
#define RB_BUTTON_1                  RB_PORT_PIN_MAP(0, 13)
#define RB_BUTTONS_ACTIVE_STATE      { 0 }
#define RB_BUTTONS_LIST              { RB_BUTTON_1 }
#define RB_BUTTON_DEBOUNCE_PERIOD_MS 50

// SPI definitions for RuuviTag B
#define RB_SPI_SCLK_PIN              RB_PORT_PIN_MAP(0, 29) // SPI clock GPIO pin number.
#define RB_SPI_MOSI_PIN              RB_PORT_PIN_MAP(0, 25) // SPI Master Out Slave In GPIO pin number.
#define RB_SPI_MISO_PIN              RB_PORT_PIN_MAP(0, 28) // SPI Master In Slave Out GPIO pin number.
#define RB_SPI_SS_ACCELEROMETER_PIN  RB_PORT_PIN_MAP(0,  8)  // SPI Slave Select (accelerometer)
#define RB_SPI_SS_ENVIRONMENTAL_PIN  RB_PORT_PIN_MAP(0,  3)  // SPI Slave Select (BME280)
#define RB_SPI_SS_LIST               {RB_SPI_SS_ACCELEROMETER_PIN, RB_SPI_SS_ENVIRONMENTAL_PIN}
#define RB_SPI_SS_NUMBER             2
#define RB_SPI_FREQUENCY_1M          0
#define RB_SPI_FREQUENCY_2M          1
#define RB_SPI_FREQUENCY_4M          2
#define RB_SPI_FREQUENCY_8M          3
#define RB_SPI_FREQ                  RB_SPI_FREQUENCY_8M

// I2C definitions for RuuviTag B
#define RB_I2C_SDA_PIN               RB_PORT_PIN_MAP(0, 4)
#define RB_I2C_SCL_PIN               RB_PORT_PIN_MAP(0, 5)
#define RB_I2C_FREQUENCY_100k        0
#define RB_I2C_FREQUENCY_250k        1
#define RB_I2C_FREQUENCY_400k        2
#define RB_I2C_FREQ                  RB_I2C_FREQUENCY_100k

// UART definitions for RuuviTag B
#define RB_UART_TX_PIN               RB_PORT_PIN_MAP(0, 4)
#define RB_UART_RX_PIN               RB_PORT_PIN_MAP(0, 5)
#define RB_UART_CTS_PIN              RB_PIN_UNUSED
#define RB_UART_RTS_PIN              RB_PIN_UNUSED
#define RB_HWFC_ENABLED              0
#define RB_PARITY_ENABLED            0
#define RB_UART_BAUDRATE_9600        0
#define RB_UART_BAUDRATE_115200      1
#define RB_UART_BAUDRATE             RB_UART_BAUDRATE_115200

// Interrupt definitions for RuuviTag B
#define RB_INT_ACC1_PIN              RB_PORT_PIN_MAP(0, 2)  // Accelerometer interrupt 1
#define RB_INT_ACC2_PIN              RB_PORT_PIN_MAP(0, 6)  // Accelerometer interrupt 2

// Total number of GPIO pins
#define RB_GPIO_NUMBER               32

// Peripherals
#define RB_DCDC_INTERNAL_INSTALLED 1
#define RB_NFC_INTERNAL_INSTALLED  0
#define RB_FLASH_SPACE_AVAILABLE   RB_FLASH_SPACE_SMALL
#define RB_RTC_INSTANCES           2
#define RB_FPU_ENABLED             0      //!< HW Floating Point Unit

// Available sensors
#define RB_ENVIRONMENTAL_BME280_PRESENT   0
#define RB_ENVIRONMENTAL_BME280_SPI_USE   0
#define RB_ENVIRONMENTAL_BME280_I2C_USE   0
#define RB_BME280_I2C_ADDRESS             0x76 //!< Depends on SDO pin setting, LOW 0x76 HIGH 0x77
#define RB_ENVIRONMENTAL_MCU_PRESENT      0
#define RB_ENVIRONMENTAL_SHTCX_PRESENT    1    //!< Some boards have both BME280 and SHTCX
#define RB_SHTCX_I2C_ADDRESS              0x70 //!< Static
#define RB_ACCELEROMETER_LIS2DH12_PRESENT 1
#define RB_ACCELEROMETER_LIS2DH12_SPI_USE 1
#define RB_ACCELEROMETER_LIS2DH12_I2C_USE 0

#endif
