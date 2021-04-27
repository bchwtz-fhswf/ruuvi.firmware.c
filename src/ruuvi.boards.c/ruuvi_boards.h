/**
 * Ruuvi board selection header, inspired by Nordic Semiconductor "boards.h" and "custom_board.h"
 *
 * If you wish to compile for your proprietary board, please define BOARD_PROPIETARY in C preprocessor macros.
 * You should also define the board name, for example BOARD_RUUVITAG_B for the preprocessor.
 *
 * License: BSD-3
 * Author: Otso Jousimaa <otso@ojousima.net>
 */
#ifndef RUUVI_BOARDS_H
#define RUUVI_BOARDS_H

#define RUUVI_BOARDS_SEMVER "3.7.0"
/** @brief Port+pin definition for GPIO pin. */
#define RB_PORT_PIN_MAP(PORT, PIN) (((PORT) << 8U) + (PIN))
/** @brief Pin not in use on this board. */
#define RB_PIN_UNUSED              (0xFFFFU)

#ifdef BOARD_PROPRIETARY
#   include "proprietary_board.h"
#elif defined BOARD_RAUNO
#   include "ruuvi_board_rauno.h"
#elif defined BOARD_RUUVITAG_B
#   include "ruuvi_board_ruuvitag_b.h"
#elif defined BOARD_KAARLE
#   include "ruuvi_board_kaarle.h"
#elif defined BOARD_KALERVO
#   include "ruuvi_board_kalervo.h"
#elif defined BOARD_KEIJO
#   include "ruuvi_board_keijo.h"
#elif defined BOARD_PCA10040
#   include "ruuvi_board_pca10040.h"
#elif defined BOARD_PCA10056E
#   include "ruuvi_board_pca10056e.h"
#elif defined BOARD_PCA10059
#   include "ruuvi_board_pca10059.h"
#elif defined BOARD_RUUVIGW_NRF
#   include "ruuvi_board_gwnrf.h"
#elif defined BOARD_RUUVIGW_ESP
#   include "ruuvi_board_gwesp.h"
#else
#   error "Define your board in preprocessor"
#endif

#include "ruuvi_board_defaults.h"

#endif
