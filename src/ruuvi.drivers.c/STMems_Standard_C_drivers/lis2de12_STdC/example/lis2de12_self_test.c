/*
 ******************************************************************************
 * @file    self_test.c
 * @author  Sensors Software Solution Team
 * @brief   This file implement the self test procedure.
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/*
 * This example was developed using the following STMicroelectronics
 * evaluation boards:
 *
 * - STEVAL_MKI109V3 + STEVAL-MKI151V1
 * - NUCLEO_F411RE + X_NUCLEO_IKS01A3 + STEVAL-MKI151V1
 *
 * and STM32CubeMX tool with STM32CubeF4 MCU Package
 *
 * Used interfaces:
 *
 * STEVAL_MKI109V3    - Host side:   USB (Virtual COM)
 *                    - Sensor side: SPI(Default) / I2C(supported)
 *
 * NUCLEO_STM32F411RE - Host side: UART(COM) to USB bridge
 *                    - Sensor side: I2C(Default) / SPI(supported)
 *
 * If you need to run this example on a different hardware platform a
 * modification of the functions: `platform_write`, `platform_read`,
 * `tx_com` and 'platform_init' is required.
 *
 */

/* STMicroelectronics evaluation boards definition
 *
 * Please uncomment ONLY the evaluation boards in use.
 * If a different hardware is used please comment all
 * following target board and redefine yours.
 */
//#define STEVAL_MKI109V3
#define NUCLEO_F411RE

#if defined(STEVAL_MKI109V3)
/* MKI109V3: Define communication interface */
#define SENSOR_BUS hspi2

/* MKI109V3: Vdd and Vddio power supply values */
#define PWM_3V3 915

#elif defined(NUCLEO_F411RE)
/* NUCLEO_F411RE: Define communication interface */
#define SENSOR_BUS hi2c1

#endif

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "lis2de12_reg.h"
#include "gpio.h"
#include "i2c.h"
#if defined(STEVAL_MKI109V3)
#include "usbd_cdc_if.h"
#include "spi.h"
#elif defined(NUCLEO_F411RE)
#include "usart.h"
#endif

typedef union{
  int16_t i16bit[3];
  uint8_t u8bit[6];
} axis3bit16_t;

/* Private macro -------------------------------------------------------------*/
/* Self test limits converted from 8bit right-aligned to 16bit left-aligned. */
#define    MIN_ST_LIMIT_LSb     4*256
#define    MAX_ST_LIMIT_LSb    90*256

/* Private variables ---------------------------------------------------------*/
static axis3bit16_t data_raw_acceleration;
static float acceleration_st_mg[3];
static float acceleration_mg[3];
static uint8_t tx_buffer[1000];
static float test_val_mg[3];
static float max_st_limit_mg;
static float min_st_limit_mg;


/* Extern variables ----------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/*
 *   WARNING:
 *   Functions declare in this section are defined at the end of this file
 *   and are strictly related to the hardware platform used.
 *
 */
static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,
                              uint16_t len);
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len);
static void tx_com(uint8_t *tx_buffer, uint16_t len);
static void platform_delay(uint32_t ms);
static void platform_init(void);

/* Main Example --------------------------------------------------------------*/
void lis2de12_self_test(void)
{

  stmdev_ctx_t dev_ctx;
  lis2de12_reg_t reg;
  uint8_t i, j;

  /* Initialize mems driver interface */
  dev_ctx.write_reg = platform_write;
  dev_ctx.read_reg = platform_read;
  dev_ctx.handle = &SENSOR_BUS; 

  /* Wait boot time and initialize platform specific hardware */
  platform_init();

  /* Wait sensor boot time */
  platform_delay(5);

  /* Check device ID */
  lis2de12_device_id_get(&dev_ctx, &reg.byte);
  if (reg.byte != LIS2DE12_ID){
    while(1) {
      /* manage here device not found */
    }
  }

  /* Enable Block Data Update. */
  lis2de12_block_data_update_set(&dev_ctx, PROPERTY_ENABLE);

  /* Set full scale to 2g. */
  lis2de12_full_scale_set(&dev_ctx, LIS2DE12_2g);

  /* Set Output Data Rate to 1Hz. */
  lis2de12_data_rate_set(&dev_ctx, LIS2DE12_ODR_50Hz);

  /* Wait stable output */
  platform_delay(90);

  /* Check if new value available */
  do {
	  lis2de12_status_get(&dev_ctx, &reg.status_reg);
  } while(!reg.status_reg.zyxda);
  /* Read dummy data and discard it */
  lis2de12_acceleration_raw_get(&dev_ctx, data_raw_acceleration.u8bit);

  /* Read 5 sample and get the average vale for each axis */
  memset(acceleration_mg, 0x00, 3*sizeof(float));
  for (i = 0; i < 5; i++){
    /* Check if new value available */
    do {
        lis2de12_status_get(&dev_ctx, &reg.status_reg);
    } while(!reg.status_reg.zyxda);
    /* Read data and accumulate the mg value */
    lis2de12_acceleration_raw_get(&dev_ctx, data_raw_acceleration.u8bit);
    for (j=0; j<3; j++){
      acceleration_mg[j] += lis2de12_from_fs2_to_mg(data_raw_acceleration.i16bit[j]);
    }
  }
  /* Calculate the mg average values */
  for (i=0; i<3; i++){
	  acceleration_mg[i] /= 5.0f;
  }

  /* Enable Self Test positive (or negative) */
  lis2de12_self_test_set(&dev_ctx, LIS2DE12_ST_POSITIVE);
  //lis2de12_self_test_set(&dev_ctx, LIS2DE12_ST_NEGATIVE);

  /* Wait stable output */
  platform_delay(90);

  /* Check if new value available */
  do {
	  lis2de12_status_get(&dev_ctx, &reg.status_reg);
  } while(!reg.status_reg.zyxda);
  /* Read dummy data and discard it */
  lis2de12_acceleration_raw_get(&dev_ctx, data_raw_acceleration.u8bit);

  /* Read 5 sample and get the average vale for each axis */
  memset(acceleration_st_mg, 0x00, 3*sizeof(float));
  for (i = 0; i < 5; i++){
    /* Check if new value available */
    do {
        lis2de12_status_get(&dev_ctx, &reg.status_reg);
    } while(!reg.status_reg.zyxda);
    /* Read data and accumulate the mg value */
    lis2de12_acceleration_raw_get(&dev_ctx, data_raw_acceleration.u8bit);
    for (j=0; j<3; j++){
      acceleration_st_mg[j] += lis2de12_from_fs2_to_mg(data_raw_acceleration.i16bit[j]);
    }
  }
  /* Calculate the mg average values */
  for (i=0; i<3; i++){
    acceleration_st_mg[i] /= 5.0f;
  }

  /* Calculate the mg values for self test */
  for (i=0; i<3; i++){
    test_val_mg[i] = fabs((acceleration_st_mg[i] - acceleration_mg[i]));
  }
  min_st_limit_mg = lis2de12_from_fs2_to_mg(MIN_ST_LIMIT_LSb);
  max_st_limit_mg = lis2de12_from_fs2_to_mg(MAX_ST_LIMIT_LSb);

  /* Check self test limit */
  for (i=0; i<3; i++){
    if (( min_st_limit_mg < test_val_mg[i] ) && ( test_val_mg[i] < max_st_limit_mg)){
      sprintf((char*)tx_buffer, "Axis[%d]: lmt min %4.2f mg - lmt max %4.2f mg - val %4.2f mg - PASS\r\n",
              i, min_st_limit_mg, max_st_limit_mg, test_val_mg[i]);
    }
    else {
      sprintf((char*)tx_buffer, "Axis[%d]: lmt min %4.2f mg - lmt max %4.2f mg - val %4.2f mg - FAIL\r\n",
    		  i, min_st_limit_mg, max_st_limit_mg, test_val_mg[i]);
    }
    tx_com(tx_buffer, strlen((char const*)tx_buffer));
  }

  /* Disable Self Test */
  lis2de12_self_test_set(&dev_ctx, LIS2DE12_ST_DISABLE);

  /* Disable sensor. */
  lis2de12_data_rate_set(&dev_ctx, LIS2DE12_POWER_DOWN);

}

/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,
                              uint16_t len)
{
  if (handle == &hi2c1)
  {
    /* Write multiple command */
    reg |= 0x80;
    HAL_I2C_Mem_Write(handle, LIS2DE12_I2C_ADD_L, reg,
                      I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
  }
#ifdef STEVAL_MKI109V3
  else if (handle == &hspi2)
  {
    /* Write multiple command */
    reg |= 0x40;
    HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(handle, &reg, 1, 1000);
    HAL_SPI_Transmit(handle, bufp, len, 1000);
    HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_SET);
  }
#endif
  return 0;
}

/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len)
{
  if (handle == &hi2c1)
  {
    /* Read multiple command */
    reg |= 0x80;
    HAL_I2C_Mem_Read(handle, LIS2DE12_I2C_ADD_L, reg,
                     I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
  }
#ifdef STEVAL_MKI109V3
  else if (handle == &hspi2)
  {
    /* Read multiple command */
    reg |= 0xC0;
    HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(handle, &reg, 1, 1000);
    HAL_SPI_Receive(handle, bufp, len, 1000);
    HAL_GPIO_WritePin(CS_up_GPIO_Port, CS_up_Pin, GPIO_PIN_SET);
  }
#endif
  return 0;
}

/*
 * @brief  Send buffer to console (platform dependent)
 *
 * @param  tx_buffer     buffer to trasmit
 * @param  len           number of byte to send
 *
 */
static void tx_com(uint8_t *tx_buffer, uint16_t len)
{
  #ifdef NUCLEO_F411RE_X_NUCLEO_IKS01A2
  HAL_UART_Transmit(&huart2, tx_buffer, len, 1000);
  #endif
  #ifdef STEVAL_MKI109V3
  CDC_Transmit_FS(tx_buffer, len);
  #endif
}

/*
 * @brief  platform specific delay (platform dependent)
 */
static void platform_delay(uint32_t ms)
{
  HAL_Delay(ms);
}

/*
 * @brief  platform specific initialization (platform dependent)
 */
static void platform_init(void)
{
#if defined(STEVAL_MKI109V3)
  TIM3->CCR1 = PWM_3V3;
  TIM3->CCR2 = PWM_3V3;
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_Delay(1000);
#endif
}

