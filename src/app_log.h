#ifndef APP_LOG_H
#define APP_LOG_H
/**
 * @addtogroup app
 */
/** @{ */
/**
 * @defgroup app_log Storing sensor data to memory and reading logs.
 *
 */
/** @} */
/**
 * @addtogroup app_log
 */
/** @{ */
/**
 * @file app_log.h
 * @author Otso Jousimaa <otso@ojousima.net>
 * @date 2020-07-17
 * @copyright Ruuvi Innovations Ltd, license BSD-3-Clause.
 */

#include "ruuvi_boards.h"
#include "ruuvi_driver_error.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_interface_communication.h"

typedef struct
{
    float temperature_c;
    float humidity_rh;
    float pressure_pa;
} app_log_element_t;

/**
 * @brief Initialize logging.
 *
 * After initialization flash driver is ready to store data.
 * If there is a logging configuration stored to flash, stored configuration is used.
 * If not, default configuration is used and stored to flash.
 *
 * @retval RD_SUCCESS if logging was initialized or if logging is disabled in config.
 */
rd_status_t app_log_init();

/**
 * @brief Process data into log.
 *
 * If time elapsed since last logged element is larger than logging interval, data is
 * stored to RAM buffer. The RAM buffer may be compressed. When the buffer fills
 * @ref STORAGE_BLOCK_SIZE bytes it will be written to flash.
 * If there is no more room for new blocks in flash, oldest flash block is erased and
 * replaced with new data.
 *
 * @retval RD_SUCCESS Data was logged.
 * @retval RD_ERROR_NO_MEMORY Data cannot be stored to flash and overflow is configured
 *                            as false.
 * @retval RD_ERROR_BUSY Previous operation is in process, e.g. writing to flash.
 */
rd_status_t app_log_process (const rd_sensor_data_t * const sample);

/**
 * @brief Purge everything stored to flash.
 */
void app_log_purge_flash (void);

/**
 * @brief Send data element.
 *
 * This function sends given data element to given reply function pointer.
 *
 * @note This function blocks until all data is send
 */
rd_status_t app_log_send_data (const ri_comm_xfer_fp_t reply_fp,
        const int64_t start_time_ms, const int64_t current_time_ms);

/** @} */
#endif // APP_LOG_H
