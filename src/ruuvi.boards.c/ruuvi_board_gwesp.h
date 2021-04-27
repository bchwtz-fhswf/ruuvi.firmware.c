#ifndef RUUVI_BOARD_GWESP
#define RUUVI_BOARD_GWESP

/** 
 * @file ruuvi_board_gwesp.h
 * @author Otso Jousimaa <otso@ojousima.net>
 * @copyright Ruuvi Innovatios Ltd, License BSD-3-Clause
 * @date 2020-06-05
 *
 * Ruuvi Gateway ESP pin definitions
 */

#include "ruuvi_board_gateway.h"

// Bus to NRF52
#define RB_GWBUS_1   GPIO_NUM_5
#define RB_GWBUS_2   GPIO_NUM_17
#define RB_GWBUS_3   GPIO_NUM_36
#define RB_GWBUS_4   GPIO_NUM_37
#define RB_GWBUS_5   GPIO_NUM_38
#define RB_GWBUS_LNA GPIO_NUM_4

// UART to nRF52
#define TXD_PIN    RB_UART_ESP2NRF
#define RXD_PIN    RB_UART_NRF2ESP

#define RB_BUTTON_RESET_PIN GPIO_NUM_35 //!< Reset button control

#define NRF52_NVMC_BASE                    0x4001E000UL
#define NRF52_NVMC_REG_READY               (NRF52_NVMC_BASE + 0x400U)
#define NRF52_NVMC_REG_CONFIG              (NRF52_NVMC_BASE + 0x504U)
#define NRF52_NVMC_REG_ERASEPAGE           (NRF52_NVMC_BASE + 0x508U)
#define NRF52_NVMC_REG_ERASEALL            (NRF52_NVMC_BASE + 0x50CU)
#define NRF52_NVMC_REG_ERASEUICR           (NRF52_NVMC_BASE + 0x514U)
#define NRF52_NVMC_REG_ERASEPAGEPARTIAL    (NRF52_NVMC_BASE + 0x518U)
#define NRF52_NVMC_REG_ERASEPAGEPARTIALCFG (NRF52_NVMC_BASE + 0x51CU)

#define NRF52_NVMC_REG_READY__MASK (0x00000001UL)

#define NRF52_NVMC_REG_CONFIG__WEN_MASK (0x03UL)
#define NRF52_NVMC_REG_CONFIG__WEN_REN  (0U)
#define NRF52_NVMC_REG_CONFIG__WEN_WEN  (1U)
#define NRF52_NVMC_REG_CONFIG__WEN_EEN  (2U)

#define NRF52_NVMC_REG_ERASEALL__NO_OP (0U)
#define NRF52_NVMC_REG_ERASEALL__ERASE (1U)

#define NRF52_GPIO_SWD_CLK GPIO_NUM_15
#define NRF52_GPIO_SWD_IO  GPIO_NUM_16
#define NRF52_GPIO_NRST    GPIO_NUM_17

#endif
