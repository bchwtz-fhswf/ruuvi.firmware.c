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
#ifndef RUUVI_BOARD_KAARLE_H
#define RUUVI_BOARD_KAARLE_H
#include "ruuvi_boards.h"
// Radio / BLE definitions
#define RB_MODEL_STRING        "Kaarle"
#define RB_MANUFACTURER_STRING "Ruuvi Innovations Ltd"
#define RB_BLE_NAME_STRING     "Kaarle"
#define RB_BLE_MANUFACTURER_ID (0x0499U) //!< Ruuvi Innovations
#define RB_TX_POWER_0 (-40)
#define RB_TX_POWER_1 (-30)
#define RB_TX_POWER_2 (-20)
#define RB_TX_POWER_3 (-12)
#define RB_TX_POWER_4 (-8)
#define RB_TX_POWER_5 (-4)
#define RB_TX_POWER_6 (-0)
#define RB_TX_POWER_7  (4)
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
#define RB_BLE_2MBPS_SUPPORTED     (1U)
#define RB_BLE_CODED_SUPPORTED     (0U)

// ADC pin definitions
#define RB_AIN0                     (1U)
#define RB_AIN1                     (RB_AIN0 + 1U)
#define RB_AIN2                     (RB_AIN1 + 1U)
#define RB_AIN3                     (RB_AIN2 + 1U)
#define RB_AIN4                     (RB_AIN3 + 1U)
#define RB_AIN5                     (RB_AIN4 + 1U)
#define RB_AIN6                     (RB_AIN5 + 1U)
#define RB_AIN7                     (RB_AIN6 + 1U)

// LED definitions
#define RB_LEDS_NUMBER               (1U)
#define RB_LED_1                     RB_PORT_PIN_MAP(0U, 25U)
#define RB_LEDS_ACTIVE_STATE         { 1 }
#define RB_LEDS_LIST                 { RB_LED_1 }
#define RB_LED_RED                   RB_LED_1
#define RB_LED_ACTIVITY              RB_LED_1
#define RB_LED_STATUS_OK             RB_LED_1
#define RB_LED_STATUS_ERROR          RB_LED_RED

// Button definitions
#define RB_BUTTONS_NUMBER            (0U)
#define RB_BUTTONS_ACTIVE_STATE      {  }
#define RB_BUTTONS_LIST              {  }
#define RB_BUTTON_DEBOUNCE_PERIOD_MS (0U)

// SPI definitions
#define RB_SPI_SCLK_PIN              RB_PORT_PIN_MAP(0U, 29U) // SPI clock GPIO pin number.
#define RB_SPI_MOSI_PIN              RB_PORT_PIN_MAP(0U, 26U) // SPI Master Out Slave In GPIO pin number.
#define RB_SPI_MISO_PIN              RB_PORT_PIN_MAP(0U, 27U) // SPI Master In Slave Out GPIO pin number.
#define RB_SPI_SS_ACCELEROMETER_PIN  RB_PORT_PIN_MAP(0U, 28U)  // SPI Slave Select (accelerometer)
#define RB_SPI_SS_LIST               {RB_SPI_SS_ACCELEROMETER_PIN}
#define RB_SPI_SS_NUMBER             (1U)
#define RB_SPI_FREQUENCY_1M          (0U)
#define RB_SPI_FREQUENCY_2M          (1U)
#define RB_SPI_FREQUENCY_4M          (2U)
#define RB_SPI_FREQUENCY_8M          (3U)
#define RB_SPI_FREQ                  RB_SPI_FREQUENCY_8M

// I2C definitions
#define RB_I2C_SDA_PIN               RB_PORT_PIN_MAP(0U, 8U)
#define RB_I2C_SCL_PIN               RB_PORT_PIN_MAP(0U, 5U)
#define RB_I2C_FREQUENCY_100k        (0U)
#define RB_I2C_FREQUENCY_250k        (1U)
#define RB_I2C_FREQUENCY_400k        (2U)
#define RB_I2C_FREQ                  RB_I2C_FREQUENCY_250k

// GPIO definitions
#define RB_GPIO_NUMBER   (32U)
#define RB_INT_ACC1_PIN  RB_PORT_PIN_MAP(0U, 30U)  // Accelerometer interrupt 1
#define RB_INT_ACC2_PIN  RB_PORT_PIN_MAP(0U, 31U)  // Accelerometer interrupt 2
#define RB_INT_TMP1_PIN  RB_PORT_PIN_MAP(0U, 22U)  // Temperature   interrupt 1
#define RB_INT_SHT3_PIN  RB_PORT_PIN_MAP(0U, 7U)   // SHT3 alert pin
#define RB_SHT3_RST_PIN  RB_PORT_PIN_MAP(0U, 6U)   // SHT3 reset pin
#define RB_ENVIRONMENTAL_PHOTO_PRESENT    (1U)
#define RB_PHOTO_ACTIVE                   (1U)                    // NTC active state
#define RB_PHOTO_PWR_PIN                  RB_PORT_PIN_MAP(0U, 12U) //!< Photodiode power pin
#define RB_PHOTO_ADC                      RB_AIN2                 //!< Photodiode ADC
#define RB_ENVIRONMENTAL_NTC_PRESENT      (1U)
#define RB_NTC_ACTIVE                     (1U)                    // NTC active state
#define RB_NTC_PWR_PIN                    RB_PORT_PIN_MAP(0U, 2U) //!< NTC power pin
#define RB_NTC_ADC                        RB_AIN1                 //!< NTC ADC

// Peripherals
#define RB_DCDC_INTERNAL_INSTALLED (1U)
#define RB_NFC_INTERNAL_INSTALLED  (0U)
#define RB_APP_FLASH_SIZE          (0x8000U) //!< Bytes
#define RB_APP_PAGES               (8U)      //!< Erase units
#define RB_RTC_INSTANCES           (3U)
#define RB_FPU_ENABLED             (1U)      //!< HW Floating Point Unit

// Available sensors
#define RB_ENVIRONMENTAL_BME280_PRESENT   (0U)
#define RB_ENVIRONMENTAL_BME280_SPI_USE   (0U)
#define RB_ENVIRONMENTAL_BME280_I2C_USE   (0U)
#define RB_ENVIRONMENTAL_MCU_PRESENT      (1U)
#define RB_ENVIRONMENTAL_SHTCX_PRESENT    (1U)
#define RB_SHTCX_I2C_ADDRESS              (0x70U) //!< Static
#define RB_ENVIRONMENTAL_SHT3_PRESENT     (1U)
#define RB_SHT3_I2C_ADDRESS               (0x44U) //!< 0x44-45 depending on ADDR pin
#define RB_ENVIRONMENTAL_TMP117_PRESENT   (1U)
#define RB_TMP117_I2C_ADDRESS             (0x48U) //!< 0x48-0x4B depending on ADD0 pin
#define RB_ACCELEROMETER_LIS2DH12_PRESENT (1U)
#define RB_ACCELEROMETER_LIS2DH12_SPI_USE (1U)
#define RB_ACCELEROMETER_LIS2DH12_I2C_USE (0U)

#endif
