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
#ifndef RUUVI_BOARD_GWNRF_H
#define RUUVI_BOARD_GWNRF_H
#include "ruuvi_boards.h"
#include "ruuvi_board_gateway.h"
// Radio / BLE definitions
#define RB_MODEL_STRING        "RuuviGW" //!< Shown in device information.
#define RB_MANUFACTURER_STRING "Ruuvi Innovations Ltd" //!< Shown in device information.
#define RB_BLE_NAME_STRING     "RuuviGW" //!< Show in BLE scan response.
#define RB_BLE_MANUFACTURER_ID 0x0499 //!< Ruuvi Innovations.
#define RB_TX_POWER_0 (-40) //!< dBm to antenna.
#define RB_TX_POWER_1 (-30) //!< dBm to antenna.
#define RB_TX_POWER_2 (-20) //!< dBm to antenna.
#define RB_TX_POWER_3 (-12) //!< dBm to antenna.
#define RB_TX_POWER_4 (-8)  //!< dBm to antenna.
#define RB_TX_POWER_5 (-4)  //!< dBm to antenna.
#define RB_TX_POWER_6 (-0)  //!< dBm to antenna.
#define RB_TX_POWER_7 ( 4)  //!< dBm to antenna.
#define RB_TX_POWER_LIST { RB_TX_POWER_0 \\
                                    RB_TX_POWER_1 \\
                                    RB_TX_POWER_2 \\
                                    RB_TX_POWER_3 \\
                                    RB_TX_POWER_4 \\
                                    RB_TX_POWER_5 \\
                                    RB_TX_POWER_6 \\
                                    RB_TX_POWER_7 }
#define RB_TX_POWER_MIN             RB_TX_POWER_0
#define RB_TX_POWER_MAX             RB_TX_POWER_7
#define RB_BLE_2MBPS_SUPPORTED      (1U) //!< HW can use 2 MBit / s modulation.
#define RB_BLE_CODED_SUPPORTED      (1U) //!< HW can use Long Range modulation.

// PA/LNA definitions
#define RB_PA_CSD_PIN     RB_PORT_PIN_MAP(0U, 22U) //!< Power mode pin of PA/LNA.
#define RB_PA_CSD_ACTIVE  (1U) //!< PA/LNA is active when CSD is high.
#define RB_PA_CSD_SLEEP   (0U) //!< PA/LNA is sleeping when CSD is low. 


// LED definitions
#define RB_LEDS_NUMBER               (1U)
#define RB_LED_1                     RB_PORT_PIN_MAP(0U, 13U)
#define RB_LEDS_ACTIVE_STATE         { 1U }
#define RB_LEDS_LIST                 { RB_LED_1 }
#define RB_LED_GREEN                 RB_LED_1
#define RB_LED_ACTIVITY              RB_LED_1
#define RB_LED_STATUS_OK             RB_LED_1
#define RB_LED_STATUS_ERROR          RB_LED_1

// Button definitions
#define RB_BUTTONS_NUMBER            (0U)
#define RB_BUTTONS_ACTIVE_STATE      (0U)
#define RB_BUTTONS_LIST              {  }
#define RB_BUTTON_DEBOUNCE_PERIOD_MS (0U)

// Ruuvi Connector Bus
#define RB_RBUS_1                    RB_PORT_PIN_MAP(0U, 2U)
#define RB_RBUS_2                    RB_PORT_PIN_MAP(0U, 3U)
#define RB_RBUS_3                    RB_PORT_PIN_MAP(0U, 4U)
#define RB_RBUS_4                    RB_PORT_PIN_MAP(0U, 5U)
#define RB_RBUS_5                    RB_PORT_PIN_MAP(0U, 6U)
#define RB_RBUS_6                    RB_PORT_PIN_MAP(0U, 7U)

// Bus to ESP32
#define RB_GWBUS_1                   RB_PORT_PIN_MAP(0U, 11U)
#define RB_GWBUS_2                   RB_PORT_PIN_MAP(0U, 12U)
#define RB_GWBUS_3                   RB_PORT_PIN_MAP(0U, 31U) // ESP input only
#define RB_GWBUS_4                   RB_PORT_PIN_MAP(0U, 30U) // ESP input only
#define RB_GWBUS_5                   RB_PORT_PIN_MAP(0U, 29U) // ESP input only
#define RB_GWBUS_LNA                 RB_PORT_PIN_MAP(0U, 23U) //!< RX mode select pin.

// SPI definitions
#define RB_SPI_ENABLED               (0U)
#define RB_SPI_SCLK_PIN              RB_RBUS_1
#define RB_SPI_MOSI_PIN              RB_RBUS_3
#define RB_SPI_MISO_PIN              RB_RBUS_2
#define RB_SPI_SS_LIST               { RB_RBUS_4 }
#define RB_SPI_FREQUENCY_1M          (0U)
#define RB_SPI_FREQUENCY_2M          (1U)
#define RB_SPI_FREQUENCY_4M          (2U)
#define RB_SPI_FREQUENCY_8M          (3U)
#define RB_SPI_FREQ                  RB_SPI_FREQUENCY_1M

// I2C definitions
#define RB_I2C_SDA_PIN               RB_RBUS_1
#define RB_I2C_SCL_PIN               RB_RBUS_2
#define RB_I2C_FREQUENCY_100k        (0U)
#define RB_I2C_FREQUENCY_250k        (1U)
#define RB_I2C_FREQUENCY_400k        (2U)
#define RB_I2C_FREQ                  RB_I2C_FREQUENCY_100k

// UART definitions
#define RB_UART_CTS_PIN              RB_UART_ESP_RTS
#define RB_UART_RTS_PIN              RB_UART_ESP_CTS
#define RB_UART_TX_PIN               RB_UART_NRF2ESP
#define RB_UART_RX_PIN               RB_UART_ESP2NRF

// GPIO definitions
#define RB_GPIO_NUMBER               (32U)


// Peripherals
#define RB_DCDC_INTERNAL_INSTALLED   (1U)
#define RB_NFC_INTERNAL_INSTALLED    (0U)
#define RB_APP_FLASH_SIZE            (0x0000U) //!< Bytes
#define RB_APP_PAGES                 (0U)      //!< Erase units
#define RB_RTC_INSTANCES             (2U)
#define RB_FPU_ENABLED               (0U)      //!< HW Floating Point Unit

#define RB_ENVIRONMENTAL_MCU_PRESENT (1U)

#endif
