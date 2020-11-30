#ifndef RUUVI_LIBRARY_H
#define RUUVI_LIBRARY_H

/**
 * @file ruuvi_library.h
 * @author Otso Jousimaa
 * @date 2020-07-21
 * @brief Common definitions for libraries
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 */
#include <stdint.h>


#define RUUVI_LIBRARIES_SEMVER "3.0.0"

#define RL_SUCCESS           (0U)        //!< Success
#define RL_ERROR_INTERNAL    (1U << 0U)  //!< Unknown error, some failed assumption.
#define RL_ERROR_NO_MEM      (1U << 1U)  //!< Not enough memory for operation
#define RL_ERROR_CONCURRENCY (1U << 2U)  //!< Failed to acquire mutex
#define RL_ERROR_NULL        (1U << 3U)  //!< Unexpected NULL pointer
#define RL_ERROR_NO_DATA     (1U << 4U)  //!< Unxpected end of data
#define RL_ERROR_SELFTEST    (1U << 5U)  //!< Self-test noticed invalid output
#define RL_ERROR_DATA_LENGTH (1U << 6U)  //!< Data length is invalid for any reason
#define RL_ERROR_FATAL       (1U << 31U) //!< Unrecoverable error, restart program

#define RL_I32_INVALID       INT32_MIN

typedef uint32_t rl_status_t;





#endif