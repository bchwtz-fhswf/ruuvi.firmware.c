/**
 * Nordic SDK expects to find a "custom_board.h" which defines a board to include.
 *
 * License: BSD-3
 * Author: Otso Jousimaa <otso@ojousima.net>
 */
#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef BOARD_PROPRIETARY
  #include "proprietary_board.h"
#else 
  #include "ruuvi_boards.h"
#endif

// Glue logic for Nordic SDK BSP package
#define BUTTON_PULL          NRF_GPIO_PIN_PULLUP
#define BUTTONS_NUMBER       RUUVI_BOARD_BUTTONS_NUMBER
#define BUTTONS_ACTIVE_STATE RUUVI_BOARD_BUTTONS_ACTIVE_STATE
#define BUTTONS_LIST         RUUVI_BOARD_BUTTONS_LIST

#define LEDS_NUMBER          RUUVI_BOARD_LEDS_NUMBER
#define LEDS_ACTIVE_STATE    RUUVI_BOARD_LEDS_ACTIVE_STATE
#define LEDS_LIST            RUUVI_BOARD_LEDS_LIST


#endif

