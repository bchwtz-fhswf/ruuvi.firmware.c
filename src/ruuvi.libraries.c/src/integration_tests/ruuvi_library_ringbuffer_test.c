#include "ruuvi_library.h"
#include "ruuvi_library_ringbuffer.h"
#include "ruuvi_library_ringbuffer_test.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/** Dummy function to lock/unlock buffer */
bool rl_test_ringbuffer_lock_dummy (volatile uint32_t * const flag, bool lock)
{
    bool * p_bool = (bool *) flag;

    if (*p_bool == lock) { return false; }

    *p_bool = lock;
    return true;
}

/**
 * @brief Test that data can be queued, peeked and dequeued to/from buffer
 *
 * @return true if test passes
 * @return false if test fails.
 */
bool rl_test_ringbuffer_put_get()
{
    uint8_t buffer_data[64] = {0};
    bool buffer_wlock = false;
    bool buffer_rlock = false;
    rl_ringbuffer_t ringbuf = {.head = 0,
                               .tail = 0,
                               .block_size = 4,
                               .storage_size = sizeof (buffer_data),
                               .index_mask = (sizeof (buffer_data) / 4) - 1,
                               .storage = buffer_data,
                               .lock = rl_test_ringbuffer_lock_dummy,
                               .writelock = &buffer_wlock,
                               .readlock  = &buffer_rlock
                              };
    uint32_t test_data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    // Check that data can be pushed and returns error once buffer is full
    rl_status_t status = RL_SUCCESS;
    size_t index = 0;

    do
    {
        status = rl_ringbuffer_queue (&ringbuf, & (test_data[index++]),
                                      sizeof (uint32_t));
    } while (RL_SUCCESS == status);

    if (RL_ERROR_NO_MEM != status || index > 16) { return false; }

    // Check that data can be de- and requeued.
    const uint32_t * p_data;
    status =  rl_ringbuffer_dequeue (&ringbuf, &p_data);
    status |= rl_ringbuffer_queue (&ringbuf, & (test_data[index - 1]),
                                   sizeof (uint32_t));

    if (RL_SUCCESS != status) { return false; }

    // Check that elements are in place - peek
    index = 1;
    size_t peek = 0;
    status = RL_SUCCESS;

    do
    {
        // Data is offset by one in above de- and requeuing, increment peek index and
        // check against incremented peek index
        status = rl_ringbuffer_peek (&ringbuf, &p_data, peek++);

        if ( (RL_SUCCESS == status) && (*p_data != test_data[peek])) { return false; }
    } while (RL_SUCCESS == status);

    // Status should be NO_DATA
    if (RL_ERROR_NO_DATA != status) { return false; }

    // Check that elements are in place after peek, dequeue
    index = 1;
    status = RL_SUCCESS;

    do
    {
        status = rl_ringbuffer_dequeue (&ringbuf, &p_data);

        if ( (RL_SUCCESS == status) && (*p_data != test_data[index])) { return false; }

        // Increment here to avoid index not getting incremented due to lazy evaluation of above if clause
        index++;
    } while (RL_SUCCESS == status);

    // 15 is last success, 16 is failure and gets incremented. Status should be NO_DATA
    return (17 == index) && (RL_ERROR_NO_DATA == status);
}

/**
 * Test that buffer returns RL_ERROR_NO_MEM once full
 *
 * @return true if test passes
 */
bool rl_test_ringbuffer_overflow()
{
    uint8_t buffer_data[64];
    bool buffer_wlock = false;
    bool buffer_rlock = false;
    rl_ringbuffer_t ringbuf = {.head = 0,
                               .tail = 0,
                               .block_size = 4,
                               .storage_size = sizeof (buffer_data),
                               .index_mask = (sizeof (buffer_data) / 4) - 1,
                               .storage = buffer_data,
                               .lock = rl_test_ringbuffer_lock_dummy,
                               .writelock = &buffer_wlock,
                               .readlock  = &buffer_rlock
                              };
    uint32_t test_data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    rl_status_t status = RL_SUCCESS;
    size_t index = 0;

    do
    {
        status = rl_ringbuffer_queue (&ringbuf, & (test_data[index++]),
                                      sizeof (uint32_t));
    } while (RL_SUCCESS == status);

    // 14 is last success, 15 is failure and gets incremented
    return RL_ERROR_NO_MEM == status && 16 == index;
}

/**
 * Test that buffer returns RL_ERROR_NO_DATA once empty
 *
 * @return true if test passes
 */
bool rl_test_ringbuffer_underflow()
{
    uint8_t buffer_data[64];
    bool buffer_wlock = false;
    bool buffer_rlock = false;
    rl_ringbuffer_t ringbuf = {.head = 0,
                               .tail = 0,
                               .block_size = 4,
                               .storage_size = sizeof (buffer_data),
                               .index_mask = (sizeof (buffer_data) / 4) - 1,
                               .storage = buffer_data,
                               .lock = rl_test_ringbuffer_lock_dummy,
                               .writelock = &buffer_wlock,
                               .readlock  = &buffer_rlock
                              };
    uint32_t test_data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    rl_status_t status = RL_SUCCESS;
    size_t index = 0;

    do
    {
        status = rl_ringbuffer_queue (&ringbuf, & (test_data[index++]),
                                      sizeof (uint32_t));
    } while (RL_SUCCESS == status);

    index = 0;
    status = RL_SUCCESS;

    do
    {
        uint32_t * p_data;
        status = rl_ringbuffer_dequeue (&ringbuf, &p_data);
        index++;
    } while (RL_SUCCESS == status);

    // 14 is last success, 15 is failure and gets incremented
    return RL_ERROR_NO_DATA == status && 16 == index;
}