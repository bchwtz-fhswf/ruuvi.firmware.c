#include "unity.h"

#include "ruuvi_library.h"
#include "ruuvi_library_ringbuffer.h"

#include <string.h>



/**
 * @brief atomic flag check and set/clear function
 *
 * Uses whatever mechanism underlying platform provides to check and set
 * or clear flag. Used to implement mutex, check-and-set flag to reserve
 *
 * Generally used like this:
 * \code{.c}
 * if(!buffer->lock(&(buffer->readlock), true))  { return RL_ERROR_CONCURRENCY; }
 * do_some_critical_stuff();
 * if(!buffer->lock(&(buffer->readlock), false)) { return RL_ERROR_FATAL; }
 * \endcode
 *
 * It's important to return if lock can't be had rather than busylooping:
 * if the interrupt level which fails to get lock is higher than the call which has the lock
 * program will deadlock in the busyloop. Likewise failure to release the lock will
 * cause deadlock in the next execution, fail immediately.
 *
 * @param[in] flag uint32_t address of bitfield to check
 * @param[in] set true to set flag, false to clear flag.
 * @return    true if operation was successful
 */
static bool flag (volatile uint32_t * const flag, const bool lock)
{
    {
        bool * p_bool = (bool *) flag;

        if (*p_bool == lock) { return false; }

        *p_bool = lock;
        return true;
    }
}

static uint8_t buffer_data[64] = {0};
static bool buffer_wlock = false;
static bool buffer_rlock = false;
static rl_ringbuffer_t ringbuf =
{
    .head = 0,
    .tail = 0,
    .block_size = sizeof (buffer_data[0]),
    .storage_size = sizeof (buffer_data),
    .index_mask = (sizeof (buffer_data) / sizeof (buffer_data[0])) - 1,
    .storage = buffer_data,
    .lock = flag,
    .writelock = &buffer_wlock,
    .readlock  = &buffer_rlock
};

void setUp (void)
{
    buffer_wlock = false;
    buffer_rlock = false;
    memset (buffer_data, 0, sizeof (buffer_data));
    ringbuf.head = 0;
    ringbuf.tail = 0;
}

void tearDown (void)
{
}


/**
 * @brief Queue data into ringbuffer
 *
 * This function operates on the head of the buffer, and rejects operation if
 * there is no more room in the buffer.
 *
 * @param[in] buffer Pointer to ringbuffer to store data into
 * @param[in] data Data to store
 * @param[in] data_length length of data, at most @ref block_size.
 * @return    RL_SUCCESS if data was queued
 * @return    RL_ERROR_NO_MEM if the ringbuffer was full
 * @return    RL_ERROR_CONCURRENCY if could not obtain lock
 * @return    RL_ERROR_FATAL if lock could not be released
 * @return    RL_ERROR_NULL  if data or buffer are NULL
 * @return    RL_ERROR_DATA_LENGTH if data is bigger than buffer block size.
 */
void test_ruuvi_library_ringbuffer_queue_ok (void)
{
    uint8_t data[4] = {10, 20, 30, 40};
    uint8_t * p_readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = rl_ringbuffer_queue (&ringbuf,
                             data,
                             1);
    TEST_ASSERT (!rl_ringbuffer_empty (&ringbuf));
    lib_status |= rl_ringbuffer_dequeue (&ringbuf,
                                         &p_readback);
    TEST_ASSERT (RL_SUCCESS == lib_status);
    TEST_ASSERT (*p_readback == data[0]);
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
}

void test_ruuvi_library_ringbuffer_queue_overfill (void)
{
    uint8_t data[4] = {10, 20, 30, 40};
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;

    while (RL_SUCCESS == lib_status)
    {
        lib_status = rl_ringbuffer_queue (&ringbuf,
                                          data,
                                          1);
    }

    TEST_ASSERT (RL_ERROR_NO_MEM == lib_status);
}



void test_ruuvi_library_ringbuffer_queue_concurrency (void)
{
    uint8_t data[4] = {10, 20, 30, 40};
    buffer_wlock = true;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = rl_ringbuffer_queue (&ringbuf,
                             &data,
                             1);
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    TEST_ASSERT (RL_ERROR_CONCURRENCY == lib_status);
}

void test_ruuvi_library_ringbuffer_queue_null_data (void)
{
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = rl_ringbuffer_queue (&ringbuf,
                             NULL,
                             1);
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_queue_null_buf (void)
{
    uint8_t data[4] = {10, 20, 30, 40};
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = rl_ringbuffer_queue (NULL,
                             &data,
                             1);
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_queue_data_len (void)
{
    uint8_t data[400] = {0};
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = rl_ringbuffer_queue (&ringbuf,
                             &data,
                             sizeof (data));
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    TEST_ASSERT (RL_ERROR_DATA_LENGTH == lib_status);
}

void test_ruuvi_library_ringbuffer_overflow (void)
{
    uint8_t data[100] = {0};
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;

    for (size_t ii = 0; ii < sizeof (data); ii++)
    {
        data[ii] = ii;
        rl_ringbuffer_queue (&ringbuf,
                             &data[ii],
                             1);
    }

    TEST_ASSERT (!rl_ringbuffer_empty (&ringbuf));

    for (size_t ii = 0; ii < (sizeof (buffer_data) - 1); ii++)
    {
        lib_status |= rl_ringbuffer_peek (&ringbuf,
                                          &readback, ii);
        TEST_ASSERT (RL_SUCCESS == lib_status);
        TEST_ASSERT (*readback == data[ii]);
    }

    TEST_ASSERT (RL_SUCCESS == lib_status);
    TEST_ASSERT (!rl_ringbuffer_empty (&ringbuf));
}

/**
 * @brief Peek data in ringbuffer
 *
 * This function operates on the tail + offset of the buffer, and rejects operation if
 * there are no more elements in the buffer. Returns pointer to stored data,
 * does not copy it. The stored data can be overwritten by after function returns,
 * so take a deep copy of data if required.
 *
 * @param[in,out] buffer Pointer to ringbuffer to peek data from
 * @param[out]    data Pointer to data, will be assigned at the start of the stored object
 * @param[in]     index offset to read data, starting from tail.
 * @return        RL_SUCCESS if data was queued
 * @return        RL_ERROR_NO_data if the ringbuffer doesn't have element at the given index
 * @warning       This function has no input checking
 * @warning       Data returned by this function can be overwritten, take a deep copy if required.
 */
void test_ruuvi_library_ringbuffer_peek_ok (void)
{
    uint8_t data[4] = {10, 20, 30, 40};
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;

    for (size_t ii = 0; ii < sizeof (data); ii++)
    {
        lib_status |= rl_ringbuffer_queue (&ringbuf,
                                           &data[ii],
                                           1);
    }

    TEST_ASSERT (!rl_ringbuffer_empty (&ringbuf));
    lib_status |= rl_ringbuffer_peek (&ringbuf,
                                      &readback, 2);
    TEST_ASSERT (RL_SUCCESS == lib_status);
    TEST_ASSERT (*readback == data[2]);
    TEST_ASSERT (!rl_ringbuffer_empty (&ringbuf));
}

void test_ruuvi_library_ringbuffer_peek_null_all (void)
{
    rl_status_t lib_status = RL_SUCCESS;
    lib_status |= rl_ringbuffer_peek (NULL,
                                      NULL, 2);
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_peek_null_buf (void)
{
    uint8_t * readback = NULL;
    rl_status_t lib_status = RL_SUCCESS;
    lib_status |= rl_ringbuffer_peek (NULL,
                                      &readback, 2);
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_peek_null_data (void)
{
    rl_status_t lib_status = RL_SUCCESS;
    lib_status |= rl_ringbuffer_peek (&ringbuf,
                                      NULL, 2);
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_dequeue_removes_elements (void)
{
    uint8_t data[100] = { 0 };
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;

    for (size_t ii = 0; ii < sizeof (data); ii++)
    {
        data[ii] = ii;
        rl_ringbuffer_queue (&ringbuf,
                             &data[ii],
                             1);

        if (ii % 2)
        {
            lib_status |= rl_ringbuffer_dequeue (&ringbuf,
                                                 &readback);
        }
    }

    TEST_ASSERT (RL_SUCCESS == lib_status);

    for (size_t ii = 0; ii < (sizeof (data) / 2); ii++)
    {
        lib_status |= rl_ringbuffer_peek (&ringbuf,
                                          &readback, ii);
        TEST_ASSERT (RL_SUCCESS == lib_status);
        TEST_ASSERT (*readback == (ii + 50));
    }
}

void test_ruuvi_library_ringbuffer_dequeue_null (void)
{
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;
    lib_status = rl_ringbuffer_dequeue (NULL, &readback);
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
    lib_status = rl_ringbuffer_dequeue (&ringbuf, NULL);
    TEST_ASSERT (RL_ERROR_NULL == lib_status);
}

void test_ruuvi_library_ringbuffer_dequeue_empty (void)
{
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;
    lib_status = rl_ringbuffer_dequeue (&ringbuf, &readback);
    TEST_ASSERT (RL_ERROR_NO_DATA == lib_status);
}

void test_ruuvi_library_ringbuffer_dequeue_concurrency (void)
{
    uint8_t data[100] = { 0 };
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    data[0] = 1;
    rl_ringbuffer_queue (&ringbuf,
                         &data[0],
                         1);
    buffer_rlock = true;
    rl_status_t lib_status = rl_ringbuffer_dequeue (&ringbuf,
                             &data);
    TEST_ASSERT (RL_ERROR_CONCURRENCY == lib_status);
}



void test_ruuvi_library_ringbuffer_peek_no_data (void)
{
    uint8_t data[100] = { 0 };
    uint8_t * readback = NULL;
    TEST_ASSERT (rl_ringbuffer_empty (&ringbuf));
    rl_status_t lib_status = RL_SUCCESS;

    for (size_t ii = 0; ii < 50; ii++)
    {
        data[ii] = ii;
        rl_ringbuffer_queue (&ringbuf,
                             &data[ii],
                             1);
    }

    TEST_ASSERT (RL_SUCCESS == lib_status);
    lib_status |= rl_ringbuffer_peek (&ringbuf,
                                      &readback, 50);
    TEST_ASSERT (RL_ERROR_NO_DATA == lib_status);
}
