#ifndef RUUVI_LIBRARY_RINGBUFFER_TEST_H
#define RUUVI_LIBRARY_RINGBUFFER_TEST_H
/**
 * @file ruuvi_library_ringbuffer_test.h
 * @author Otso Jousimaa
 * @date 2019-07-22
 * @brief Function for testing library functions.
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * Run tests for library functions.
 */

#include <stdbool.h>
#include <stdint.h>

/**
 * @ingroup test_library
 * @defgroup test_datastructures Data structure tests
 *  Functions to test data structures for correctness.
 *  @{
 */

/** Dummy function to lock/unlock buffer */
bool rl_test_ringbuffer_lock_dummy (volatile uint32_t * const flag, bool lock);

/**
 * Test that data can be queued and dequeued to/from buffer
 *
 * @return true if test passes
 */
bool rl_test_ringbuffer_put_get();

/**
 * Test that buffer returns RL_ERROR_NO_MEM once full
 *
 * @return true if test passes
 */
bool rl_test_ringbuffer_overflow();

/**
 * Test that buffer returns RL_ERROR_NO_DATA once empty
 *
 * @return true if test passes
 */
bool rl_test_ringbuffer_underflow();

/*@]*/

#endif