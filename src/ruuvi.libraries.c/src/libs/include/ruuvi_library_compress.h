#ifndef RUUVI_LIBRARY_COMPRESS_H
#define RUUVI_LIBRARY_COMPRESS_H
/**
* @file ruuvi_library_compress.h
* @author Oleg Protasevich
* @date 2020-06-16
* @brief Compression API
* @copyright Copyright 2020 Ruuvi Innovations.
*   This project is released under the BSD-3-Clause License.
*
*
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "liblzf-3.6/lzf.h"

// #define RL_COMPRESS_CONVERT_TO_INT Drops floating precision.

#define RL_COMPRESS_SUCCESS                (0U)       ///< Success
#define RL_COMPRESS_ERROR_INVALID_PARAM    (1U<<4U)   ///< Invalid Parameter
#define RL_COMPRESS_ERROR_INVALID_STATE    (1U<<5U)   ///< Invalid state, operation disallowed in this state
#define RL_COMPRESS_ERROR_NULL             (1U<<11U)  ///< Null Pointer
#define RL_COMPRESS_ERROR_INTERNAL         (1U<<12U)  ///< Algorithm error
#define RL_COMPRESS_ERROR_NOT_FOUND        (1U<<13U)  ///< No matching data found.
#define RL_COMPRESS_END                    (1U<<22U)  ///< Compress/Decompress ended
#define RL_COMPRESS_LIMIT_REACHED          (1U<<23U)  ///< Maximum compression limit reached.
#define RL_COMPRESS_OUT2BIG                (1U<<24U)  ///< Compressed data is larger than input. Store uncompressed data. 
#define RL_COMPRESS_START                  (1U<<25U)  ///< Start de/compress operation
#define RL_COMPRESS_DECOMPRESS_DONE        (1U<<26U)  ///< Data is decompressed.

#define RL_COMPRESS_STATE_SIZE             (1U << (HLOG)) //!< hashtable size.
#define RL_COMPRESS_COMPRESS_SIZE          (4000U)        //!< Flash page is 4096 bytes, leave space for headers.
/**
 * @brief Maximum compression ratio is COMPRESS_SIZE/DECOMPRESS_SIZE, but increases RAM usage.
 */
#define RL_COMPRESS_DECOMPRESS_SIZE        (2U * RL_COMPRESS_COMPRESS_SIZE)
#define RL_COMPRESS_FIELD_NUM              (3U) //!< Number of fields to compress
/**
 * Compression overhead allows small percentage of wasted space in block.
 * Minimum should be 4 % of RL_COMPRESS_COMPRESS_SIZE to allow for incompressible data.
 * Larger values reduce algorithm reruns, but spend more space.
 */
#define RL_COMPRESS_OVERHEAD               (RL_COMPRESS_COMPRESS_SIZE / 20U)

typedef uint32_t timestamp_t;
typedef uint32_t ret_type_t;///< bitfield for representing errors
typedef LZF_HSLOT rl_compress_algo_state_t[RL_COMPRESS_STATE_SIZE];

#pragma pack(push, 1)
typedef struct
{
    timestamp_t time;
    float payload[RL_COMPRESS_FIELD_NUM];
} rl_data_t;

typedef struct
{
    rl_compress_algo_state_t algo_state; //!< Hashtable, memset to 0 to reset. 4 kB
    uint8_t compress_block[RL_COMPRESS_COMPRESS_SIZE]; // Compressed block.
    uint8_t decompress_block[RL_COMPRESS_DECOMPRESS_SIZE]; // Decompressed block.
    size_t compressed_size;   //!< Number of compressed bytes in compress block.
    size_t decompressed_size; //!< Number of uncompressed bytes in decompress block.
    size_t next_decompression; //!< Counter for number of decompressed bytes before trying next decompression.
    rl_data_t * next_sample;  //!< Pointer to next sample in decompression.
    ret_type_t compress_state; //!< State of compression.
} rl_compress_state_t;
#pragma pack(pop)

/**
 * @brief Ruuvi Library compress function.
 * Takes a sensor data sample in and appends it to given data block.
 *
 * It is assumed that data is appended in linear order,
 * new sample has always greater timestamp than previous.
 *
 * @param[in] data Sensor data to compress, 1 sample.
 * @param[out] block Pointer to buffer to which compressed data is placed.
 * @param[in] block_size Size of block.
 * @param[in,out] state In: State of compression algorithm before adding latest data.
 *                      Out: State of compression algorithm after adding latest data.
 * @retval RL_SUCCESS If compression was successful.
 * @retval RL_ERROR_NULL If given a NULL as a parameter.
 * @retval RL_COMPRESS_END If the block is considered full.
 *                         Block is ready to be stored to non-volatile memory.
 * @retval RL_COMPRESS_OUT2BIG If compressed data is larger than uncompressed data.
 *                             In this case uncompressed data should be stored,
 *                             compressed data may be invalid if it doesn't fit
 *                             into block.
 *
 *
 */
ret_type_t rl_compress (const rl_data_t * const data,
                        uint8_t * const block,
                        const size_t block_size,
                        rl_compress_state_t * const state);
/**
 * @brief Ruuvi Library decompress function.
 * Looks up next sample after given timestamp and returns it via output parameter.
 *
 * Usage:
 * @code
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
 * @endcode
 *
 * @param[out] data Next sample from block. Not modified if no data was found in block.
 * @param[in]  block Pointer to compressed buffer with sensor data.
 * @param[in]  block_size Size of block.
 * @param[in,out] state In: State of decompression algorithm before decompressing next data point. Out: State of decompression algorithm after decompressing next data point.
 * @param[in,out] start_timestamp In: Earliest timestamp to accept. Out: Timestamp of returned data.
 * @retval Status of decompression, such as more available or not_found.
 *
 *
 *
 */
ret_type_t rl_decompress (rl_data_t * data,
                          uint8_t * block,
                          size_t block_size,
                          rl_compress_state_t * state,
                          timestamp_t * start_timestamp);

#endif