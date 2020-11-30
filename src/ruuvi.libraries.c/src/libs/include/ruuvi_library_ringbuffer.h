/**
 * @file ruuvi_library_ringbuffer.h
 * @author Otso Jousimaa
 * @date 2020-07-24
 * @brief Ringbuffer with emphasis on interrupt tolerance and speed.
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * This ringbuffer implementation is optimized for Bluetooth GATT connection usage.
 * It has special emphasis on being usable when data is read in interrupt context
 * - no locking between read / write, and thread-safe reads/writes.
 * The tradeoffs are that the data storage must have size of power of two and
 * the elemements are treated in chunks with size of power of two.
 */
/*@{*/

#ifndef  RUUVI_LIBRARY_RINGBUFFER_H
#define  RUUVI_LIBRARY_RINGBUFFER_H

#include "ruuvi_library.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief atomic flag check and set/clear function
 *
 * Uses whatever mechanism underlying platform provides to check and set
 * or clear flag. Used to implement mutex, check-and-set flag to reserve.
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
typedef bool (*rl_atomic_flag) (volatile uint32_t * const flag,
                                const bool set);

/* @brief Struct definition for ringbuffer.
 *
 * Initialization example:
 * \code{.c}
 * static uint8_t buffer_data[1024}; //!< Must be allocated on stack
 * static ruuvi_interface_atomic_t buffer_wlock = RUUVI_INTERFACE_ATOMIC_INIT;
 * static ruuvi_interface_atomic_t buffer_rlock = RUUVI_INTERFACE_ATOMIC_INIT;
 * static rl_ringbuffer_t ringbuf = {.head = 0,
 *                                              .tail = 0,
 *                                              .block_size = 32,
 *                                              .storage_size = sizeof(buffer_data),
 *                                              .index_mask = (sizeof(buffer_data) / 32) - 1,
 *                                              .storage = buffer_data;
 *                                              .lock = ruuvi_interface_atomic_flag
 *                                              .writelock = &buffer_wlock;
 *                                              .readlock  = &buffer_rlock};
 * \endcode
 */
typedef struct
{
    size_t head;               //!< Ringbuffer head index
    size_t tail;               //!< Ringbuffer tail index
    const size_t block_size;   //!< Block size of elements, must be power of two
    const size_t storage_size; //!< Size of storage element, must be power of two.
    const size_t index_mask;   //!< Bitmask of indexes. Must be (storege_size / block_size) -1
    void * const storage;      //!< Pointer to storage.
    /** @brief Function pointer to lock ringbuffer. Can be a dummy implementation which only
     *         returns true if buffer is used in single-thread environment without interrupts.
     */
    const rl_atomic_flag lock;
    volatile void * const writelock;    //!< Memory address for flag locking write function
    volatile void * const readlock;     //!< Memory address for flag locking read function.
} rl_ringbuffer_t;

/**
 * @brief Queue data into ringbuffer
 *
 * This function operates on the head of the buffer, and rejects operation if
 * there is no more room in the buffer.
 *
 * @param[in] buffer Pointer to ringbuffer to store data into
 * @param[in] data Data to store
 * @param[in] data_length length of data, at most @ref block_size.
 * @retval    RL_SUCCESS Data was queued.
 * @retval    RL_ERROR_NO_MEM The ringbuffer was full.
 * @retval    RL_ERROR_CONCURRENCY Could not obtain lock.
 * @retval    RL_ERROR_FATAL Lock could not be released.
 * @retval    RL_ERROR_NULL  Data or buffer are NULL.
 * @retval    RL_ERROR_DATA_LENGTH Data is bigger than buffer block size.
 */
rl_status_t rl_ringbuffer_queue (rl_ringbuffer_t * const buffer,
                                 const void * const data,
                                 const size_t data_length);

/**
 * @brief Dequeue data from ringbuffer
 *
 * This function operates on the tail of the buffer, and rejects operation if
 * there is no more elements in the buffer. Returns pointer to stored data,
 * does not copy it. The stored data can be overwritten by after function returns,
 * so take a deep copy of data if required. You can also use a peek function to
 * view the data without dequeuing
 *
 * @param[in,out] buffer Pointer to ringbuffer to load data from
 * @param[out]    data Pointer to data, will be assigned at the start of the stored object
 * @retval        RL_SUCCESS Data was dequeued.
 * @retval        RL_ERROR_NULL Any input pointer is NULL.
 * @retval        RL_ERROR_NO_DATA The ringbuffer was empty.
 * @warning       Data returned by this function can be overwritten, take a deep copy if required.
 */
rl_status_t rl_ringbuffer_dequeue (rl_ringbuffer_t * const buffer,
                                   void * const data);

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
 * @retval        RL_SUCCESS Data was peeked.
 * @retval        RL_ERROR_NULL Any input pointer is NULL.
 * @retval        RL_ERROR_NO_DATA The ringbuffer doesn't have element at the given index.
 * @warning       Data returned by this function can be overwritten, take a deep copy if required.
 */
rl_status_t rl_ringbuffer_peek (rl_ringbuffer_t * const buffer,
                                const void * data, const size_t index);

/*
 * return true if rinbuffer is full
 */
bool rl_ringbuffer_full (const rl_ringbuffer_t * const buffer);

/*
 * return true if rinbuffer is empty
 */
bool rl_ringbuffer_empty (const rl_ringbuffer_t * const buffer);

/*@}*/

#endif
