#include "ruuvi_library.h"
#include "ruuvi_library_ringbuffer.h"
#include <string.h>


rl_status_t rl_ringbuffer_queue (rl_ringbuffer_t * const buffer,
                                 const void * const data,
                                 const size_t data_length)
{
    if (NULL == buffer || NULL == data)         { return RL_ERROR_NULL; }

    if (rl_ringbuffer_full (buffer))  { return RL_ERROR_NO_MEM; }

    if (buffer->block_size < data_length)       { return RL_ERROR_DATA_LENGTH; }

    if (!buffer->lock (buffer->writelock, true)) { return RL_ERROR_CONCURRENCY; }

    memcpy ( (buffer->storage) + (buffer->head * buffer->block_size),
             data, data_length);
    buffer->head = ( (buffer->head + 1) & buffer->index_mask);

    if (!buffer->lock (buffer->writelock, false)) { return RL_ERROR_FATAL; }

    return RL_SUCCESS;
}

rl_status_t rl_ringbuffer_dequeue (rl_ringbuffer_t * const buffer,
                                   void * const data)
{
    rl_status_t err_code = RL_SUCCESS;

    if (NULL == buffer || NULL == data)
    {
        err_code |= RL_ERROR_NULL;
    }
    else if (rl_ringbuffer_empty (buffer))
    {
        err_code |= RL_ERROR_NO_DATA;
    }
    else if (!buffer->lock (buffer->readlock, true))
    {
        err_code |= RL_ERROR_CONCURRENCY;
    }
    else
    {
        void ** p_data = (void **) data;
        *p_data = buffer->storage + (buffer->tail * buffer->block_size);
        buffer->tail = ( (buffer->tail + 1) & buffer->index_mask);

        if (!buffer->lock (buffer->readlock, false))
        {
            err_code |= RL_ERROR_FATAL;
        }
    }

    return err_code;
}

rl_status_t rl_ringbuffer_peek (rl_ringbuffer_t * const
                                buffer,
                                const void * data, const size_t index)
{
    if (NULL == buffer || NULL == data)         { return RL_ERROR_NULL; }

    if ( ( (buffer->tail + index) & buffer->index_mask) == buffer->head)
    {
        return RL_ERROR_NO_DATA;
    }

    if (!buffer->lock (buffer->readlock, true))  {return RL_ERROR_CONCURRENCY; }

    void ** p_data = (void **) data;
    *p_data = buffer->storage + ( ( (buffer->tail + index) & buffer->index_mask) *
                                  buffer->block_size);

    if (!buffer->lock (buffer->readlock, false)) {return RL_ERROR_FATAL; }

    return RL_SUCCESS;
}

bool rl_ringbuffer_full (const rl_ringbuffer_t * const buffer)
{
    return ( (buffer->head - buffer->tail) & buffer->index_mask) == buffer->index_mask;
}

bool rl_ringbuffer_empty (const rl_ringbuffer_t * const buffer)
{
    return buffer->head == buffer->tail;
}
