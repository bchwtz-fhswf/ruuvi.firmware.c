/**
 * Compression library implementation on nRF52832.
 *
 * License: BSD-3
 * Author: Oleg Protasevich, Otso Jousimaa
 */
#include "ruuvi_library_compress.h"
#if RL_LIBLZF_ENABLED

#define  LZF_NO_RESULT                      0

ret_type_t rl_compress (const rl_data_t * const data,
                        uint8_t * const block,
                        const size_t block_size,
                        rl_compress_state_t * const state)
{
    ret_type_t err_code = RL_COMPRESS_SUCCESS;
    const unsigned int decompress_free = RL_COMPRESS_DECOMPRESS_SIZE -
                                         state->decompressed_size;
    size_t cmpr_len = 0;

    if (NULL == data || NULL == block || NULL == state)
    {
        err_code |= RL_COMPRESS_ERROR_NULL;
    }
    else
    {
        // If next decompression threshold is 0-initialized, try 1:1.
        if (0 == state->next_decompression)
        {
            state->next_decompression = RL_COMPRESS_COMPRESS_SIZE;
        }

        // Maximum compression ratio of reached?
        if (sizeof (rl_data_t) > (decompress_free - sizeof (rl_data_t)))
        {
            state->compress_state = RL_COMPRESS_START;
        }

        // Compress data to integers?
#     ifdef RL_COMPRESS_CONVERT_TO_INT
        {
            for (uint8_t i = 0; i < RL_COMPRESS_FIELD_NUM; i++)
            {
                data->payload[i] = (float) ( (int) (data->payload[i]));
            }
        }
#     endif
        memcpy ( (void *) (state->decompress_block + state->decompressed_size),
                 data, sizeof (rl_data_t));
        state->decompressed_size += sizeof (rl_data_t);

        // Compress if we're at threshold or if flush has been signaled
        if ( (state->decompressed_size > state->next_decompression)
                || (RL_COMPRESS_START == state->compress_state))
        {
            cmpr_len = lzf_compress (state->decompress_block, state->decompressed_size,
                                     block, RL_COMPRESS_COMPRESS_SIZE,
                                     state->algo_state);
            // Update state.
            state->compressed_size = cmpr_len;
            // Calculate next threshold for compression
            const size_t threshold_increment = RL_COMPRESS_COMPRESS_SIZE - cmpr_len -
                                               RL_COMPRESS_OVERHEAD;
            state->next_decompression += threshold_increment;

            // If compression fails, store uncompressed data instead.
            // This leads to missing samples if new data compresses as larger
            // than uncompressed data. Maximum compression size should be 103%
            // of original, so compression overhaed of 5% should quarantee this
            // cannot happen.
            if (0 == cmpr_len)
            {
                memcpy (state->compress_block, state->decompress_block, RL_COMPRESS_COMPRESS_SIZE);
                err_code |= RL_COMPRESS_OUT2BIG;
            }
            // If we're incrementing less than overhead, close the block.
            else if (RL_COMPRESS_OVERHEAD > threshold_increment)
            {
                err_code |= RL_COMPRESS_END;
            }
        }

        // Compression close enough to block size, we're ready
        if ( (RL_COMPRESS_COMPRESS_SIZE <= cmpr_len + RL_COMPRESS_OVERHEAD)
                || RL_COMPRESS_START == state->compress_state)
        {
            err_code |= RL_COMPRESS_END;
        }
    }

    return err_code;
}

/**
 * @brief Ruuvi Library decompress function.
 * Looks up next sample after given timestamp and returns it via output parameter.
 *
 *
 * @param[out] data Next sample from block. Not modified if no data was found in block.
 * @param[in]  block Pointer to compressed buffer with sensor data.
 * @param[in]  block_size Size of block.
 * @param[in,out] state In: State of decompression algorithm before decompressing next data point. Out: State of decompression algorithm after decompressing next data point.
 * @param[in,out] start_timestamp In: Earliest timestamp to accept. Out: Timestamp of returned data.
 * @return Status of decompression, such as more available or not_found.
 *
 * Usage:
 * ret_type_t status;
 * rl_data_t data;
 * uint8_t* block = get_next_block();
 * size_t block_size = DATA_BLOCK_SIZE;
 * rl_decompress_state_t state = { 0 }; // zeroed state initially.
 * timestamp_t start_timestamp = 0; // Get all the data from boot.
 * while(RL_COMPRESS_SUCCESS == status)
 * {
 *   // This pseudocode fails if no data is found and it misses last sample.
 *   status = rl_decompress(&data, block, block_size, &state, &start_timestamp);
 *   do_something_with_data(&data);
 * }
 *
 *
 */
ret_type_t rl_decompress (rl_data_t * data,
                          uint8_t * block,
                          size_t block_size,
                          rl_compress_state_t * state,
                          timestamp_t * start_timestamp)
{
    ret_type_t err_code = RL_COMPRESS_SUCCESS;

    if (NULL == data || NULL == block || NULL == state || NULL == start_timestamp)
    {
        err_code |= RL_COMPRESS_ERROR_NULL;
        return err_code;
    }
    else if (RL_COMPRESS_START == state->compress_state)
    {
        unsigned int decompressed_size = 0;
        decompressed_size = lzf_decompress (state->compress_block,
                                            state->compressed_size,
                                            state->decompress_block,
                                            RL_COMPRESS_DECOMPRESS_SIZE);

        // Decompression error
        if (0 == decompressed_size)
        {
            err_code |= RL_COMPRESS_ERROR_INTERNAL;
        }
        else
        {
            state->decompressed_size = decompressed_size;
            state->compress_state = RL_COMPRESS_SUCCESS;
            state->next_sample = (rl_data_t *) state->decompress_block;
        }
    }

    if (RL_COMPRESS_SUCCESS == state->compress_state)
    {
        // Search until block ends or we have fresh enough data.
        while ( ( (uint8_t *) state->next_sample < (state->decompress_block +
                  RL_COMPRESS_DECOMPRESS_SIZE))
                && (state->next_sample->time < *start_timestamp))
        {
            state->next_sample++;
        }

        // If sample was not found, return error
        if ( (uint8_t *) state->next_sample >= (state->decompress_block +
                                                RL_COMPRESS_DECOMPRESS_SIZE))
        {
            err_code |= RL_COMPRESS_ERROR_NOT_FOUND;
        }
        // If sample was found, update data.
        else
        {
            memcpy (data, state->next_sample, sizeof (rl_data_t));
            *start_timestamp = data->time;
            state->next_sample++;

            // If we're at last position, mark no more data available.
            if ( (uint8_t *) state->next_sample == (state->decompress_block +
                                                    state->decompressed_size))
            {
                state->compress_state = RL_COMPRESS_END;
                err_code |= RL_COMPRESS_END;
            }
        }
    }
    else
    {
        err_code |= RL_COMPRESS_ERROR_INVALID_STATE;
    }

    return err_code;
}
#endif
