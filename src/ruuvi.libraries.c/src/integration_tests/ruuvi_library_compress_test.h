#ifndef RUUVI_LIBRARY_COMPRESS_TEST_H
#define RUUVI_LIBRARY_COMPRESS_TEST_H

/**
 * @file ruuvi_library_compress_test.h
 * @author Oleg Protasevich
 * @date 2020-06-16
 * @brief Function for testing library functions.
 * @copyright Copyright 2020 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * Run tests for library functions.
 */

#include <stdbool.h>
#include <stdint.h>
#include "ruuvi_library_test.h"

/**
 * @brief Ruuvi Library test compress/decompress function.
 * Try to do compress/decompress operation over library API.
 *
 * @return true if test is valid, false if else.
 */
bool rl_test_compress_decompress (void);

/**
 * @brief Ruuvi Library test compress/decompress function.
 * Try to do compress/decompress operation 2 times over library API.
 *
 * @return true if test is valid, false if else.
 */
bool rl_test_compress_decompress_2_times (void);

/**
 * @brief Ruuvi Library test compress/decompress function.
 * Used to print compress ratio
 *
 * @return true if test is valid, false if else.
 */
bool rl_test_compress_decompress_ratio (const rl_test_print_fp
                                        printfp);

/**
 * @brief Ruuvi Library test compress/decompress function.
 * Try to cause errors in library API.
 *
 * @return true if test is valid, false if else.
 */
bool rl_test_invalid_input (void);

#endif