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

#endif
