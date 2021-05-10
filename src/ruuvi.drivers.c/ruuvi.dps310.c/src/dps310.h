/**
 * @defgroup DPS310 DPS310 driver
 * @brief Embedded C driver for DPS310 pressure and temperature sensor.
 *
 */
/** @{ */
/**
 * @file dps310.h
 * @author Otso Jousimaa <otso@ojousima.net>
 * @date 2020-11-23
 * @copyright Ruuvi Innovations, License MIT
 *
 */
#ifndef DPS310_H
#define DPS310_H

#include <stdint.h>

#define DPS310_PRODUCT_ID_VAL  (0U)        //!< Product ID read from DPS310 register
#define DPS310_REVISION_ID_VAL (0x01U)     //!< Revision ID read from DPS310 register
#define DPS310_SUCCESS         (0U)        //!< Return code on successful operation.
#define DPS310_NOT_INITIALIZED (0U)        //!< Status flag on uninitialized DPS context.
#define DPS310_READY           (1U << 0U)  //!< Flag for DPS310 struct, sensor can receive commands.
#define DPS310_CONTINUOUS      (1U << 2U)  //!< Flag for DPS310 struct, continuous measurement is in progress.
#define DPS310_TEMP_RDY        (1U << 3U)  //!< Flag for DPS310 struct, single temperature measurement is done.
#define DPS310_PRES_RDY        (1U << 4U)  //!< Flag for DPS310 struct, single pressure measurement is done.
#define DPS310_MAX_OK          (1U << 8U)  //!< Highest allowed value for "OK" status codes.
#define DPS310_ERROR_NULL      (1U << 9U)  //!< Return code on NULL context or interface function.
#define DPS310_INVALID_PARAM   (1U << 10U) //!< Return code on invalid configuration parameter
#define DPS310_UNKNOWN_REV     (1U << 11U) //!< Return code on mismatched revision code.
#define DPS310_OTHER_ERROR     (1U << 13U) //!< Error not elsewhere specified
#define DPS310_NOT_IMPLEMENTED (1U << 14U) //!< Functionality not implemented yet.
#define DPS310_BUS_ERROR       (1U << 30U) //!< Communication has failed on bus.
#define DPS310_INVALID_STATE   (1U << 31U) //!< Flag for DPS310 struct, sensor must be un- and reinitialized.
#define DPS310_POR_DELAY_MS    (12U)       //!< Milliseconds after power-on before comms.
#define DPS310_COEF_DELAY_MS   (40U)       //!< Milliseconds after reset before coefs can be read.
#define DPS310_DEFAULT_MR      (1U)        //!< One measurement per second by default.
#define DPS310_DEFAULT_OS      (1U)        //!< One oversample per measurement by default.

typedef uint32_t dps310_status_t; //!< Status code bitfield.

/**
 * @brief Sleep at least this many milliseconds.
 *
 * Function is allowed to sleep for longer, but not shorter time.
 */
typedef void (*dps310_sleep) (const uint32_t ms);

/**
 * @brief Read data from bus.
 *
 * If the read function returns non-zero value, it will get returned to caller in application.
 * Comm_ctx is given by application at dps310 initialization. Data is guaranteed to be non-NULL
 * and data_len is guaranteed to be non-zero.
 *
 * @param[in] comm_ctx A pointer to context for platform. E.g. I2C address or SPI SS pin. May be NULL.
 * @param[in] reg_addr Address of register to read.
 * @param[out] data Pointer to which data will be written. Must be data_len bytes long.
 * @param[in] data_len Length of data.
 * @retval 0 on success.
 * @return Application error code on error. Bit DPS310_BUS_ERROR should be 0.
 */
typedef uint32_t (*dps310_read) (const void * const comm_ctx, const uint8_t reg_addr,
                                 uint8_t * const data, const uint8_t data_len);

/**
 * @brief Write data from bus.
 *
 * If the write function returns non-zero value, it will get returned to caller in application.
 * Comm_ctx is given by application at dps310 initialization. Data is guaranteed to be non-NULL
 * and data_len is guaranteed to be non-zero.
 *
 * @param[in] comm_ctx A pointer to context for platform. E.g. I2C address or SPI SS pin.
 * @param[in] reg_addr Address of register to write.
 * @param[in] data Pointer to which data will be written. Must be data_len bytes long.
 * @param[in] data_len Length of data.
 * @return 0 on success.
 * @return Application error code on error. Bit DPS310_BUS_ERROR should be 0.
 */
typedef uint32_t (*dps310_write) (const void * const comm_ctx, const uint8_t reg_addr,
                                  const uint8_t * const data, const uint8_t data_len);

typedef enum
{
    DPS310_MR_INVALID = 0,
    DPS310_MR_1,
    DPS310_MR_2,
    DPS310_MR_4,
    DPS310_MR_8,
    DPS310_MR_16,
    DPS310_MR_32,
    DPS310_MR_64,
    DPS310_MR_128,
    DPS310_MR_NONE
} dps310_mr_t; // Measurement rate, Hz.

typedef enum
{
    DPS310_OS_INVALID = 0,
    DPS310_OS_1,
    DPS310_OS_2,
    DPS310_OS_4,
    DPS310_OS_8,
    DPS310_OS_16,
    DPS310_OS_32,
    DPS310_OS_64,
    DPS310_OS_128
} dps310_os_t; // Oversampling rate, number of samples taken internally.

typedef struct
{
    dps310_status_t device_status; //!< Internal status flag.

    uint8_t product_id;  //!< Read from device, should be DPS310_PRODUCT_ID_VAL.
    uint8_t revision_id; //!< Read from device, should be DPS310_REVISION_ID_VAL.

    //settings
    dps310_mr_t temp_mr;  //!< Temperature MR, configured by @ref dps310_config_temp.
    dps310_os_t temp_osr; //!< Temperature OS, configured by @ref dps310_config_temp.
    dps310_mr_t pres_mr;  //!< Pressure MR, configured by @ref dps310_config_pres.
    dps310_os_t pres_osr; //!< Pressure OS, configured by @ref dps310_config_pres.

    // compensation coefficients, read from device.
    int32_t c0;  //!< Temperature offset.
    int32_t c1;  //!< Temperature 1st degree.
    int32_t c00; //!< Pressure offset.
    int32_t c10; //!< Pressure 1st degree rel to pressure.
    int32_t c01; //!< Pressure 1st degree rel to temperature.
    int32_t c11; //!< Pressure 1st degree rel to temperature + pressure.
    int32_t c20; //!< Pressure 2nd degree rel to pressure.
    int32_t c21; //!< Pressure 2nd degree rel to pressure + 1st to temperature.
    int32_t c30; //!< Pressure 3rd degree rel to pressure.


    float last_temp_scal; //!< Temperature term for pressure compensation.

    // Communication interface.
    void * const comm_ctx;     //!< Context for application, may be NULL.
    const dps310_sleep sleep;  //!< Sleep function.
    const dps310_read  read;   //!< Read function.
    const dps310_write write;  //!< Write function.
} dps310_ctx_t; //!< Context for DPS310.

/**
 * @brief Set the DPS310 to standby mode.
 *
 * After calling this function, the context->device_state will be DPS310_READY.
 * Most configuration must be done while DPS310 is in standby mode, i.e. not
 * in continuous measurement mode or running a measurement.
 *
 * The state of sensor is undefined after error, run initialization to reset sensor.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized or has internal error.
 * @retval DPS310_BUS_ERROR + original code if read/write function returns non-zero value.
 */
dps310_status_t dps310_standby (dps310_ctx_t * const ctx);

/**
 * @brief Perform one temperature measurement.
 *
 * Uses the oversampling rate of given context and blocks until measurement is ready.
 * The sensor must be in standby before calling this function.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[out] result        Pointer to a float where the result will be written.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is busy or has internal error.
 */
dps310_status_t dps310_measure_temp_once_sync (dps310_ctx_t * const ctx,
        float * const result);

/**
 * @brief Starts a single temperature measurement.
 *
 * Uses the oversampling rate of given context and blocks until measurement is ready.
 * The sensor must be in standby before calling this function.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is busy or has internal error.
 */
dps310_status_t dps310_measure_temp_once_async (dps310_ctx_t * const ctx);

/**
 * @brief Perform one pressure measurement.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[out] result A poitner to a float value where the result will be written.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is busy or has internal error.
 */
dps310_status_t dps310_measure_pres_once_sync (dps310_ctx_t * const ctx,
        float * const result);

/**
 * @brief Start a single pressure measurement.
 *
 * The sensor must be in DPS310_READY mode before this is called.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is busy or has internal error.
 */
dps310_status_t dps310_measure_pres_once_async (dps310_ctx_t * const ctx);

/**
 * @brief Get the result async measurement, in C or Pa.
 *
 * This function must be called while DPS310 is marked as busy. It will return the
 * previous async measurement and mark DPS310 state as ready.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[out] result   A pointer to a float value where the result will be written.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is not busy or has internal error.
 */
dps310_status_t dps310_get_single_result (dps310_ctx_t * const ctx, float * const result);

/**
 * @brief Starts a continuous temperature and pressure measurement.
 *
 * Measurement rate and oversampling rate for temperature and pressure measurement are read from the context.
 * The sensor must be in DPS310_READY mode when this function is called. It is ok to configure
 * DPS310_MR_NONE into temperature or pressure to turn measurements off entirely.
 * However, accurate pressure measurements require recent temperature measurements for
 * compensation.
 *
 *
 * After this function has been called, only @ref dps310_get_cont_results, @ref dps310_standby
 * and @ref dps310_uninit are allowed and context device_status is @ref DPS310_CONTINUOUS.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @retval DPS310_SUCCESS on success.
 * @retval DPS310_ERROR_NULL if ctx or Function pointers are NULL.
 * @retval DPS310_INVALID_STATE if ctx is not initialized, is busy,
 *                              measurement rate on both temperature and pressure is NONE
 *                              or context has internal error.
 */
dps310_status_t dps310_measure_continuous_async (dps310_ctx_t * const ctx);

/**
 * @brief Get results stored to FIFO in continuous mode, oldest measurement first.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[out] temp A pointer to buffer where temperature results will be placed to, in C.
 * @param[in,out] temp_count Input: Number of elements in buffer.
 *                           Output: number of read elements, 0 if no elements were read.
 * @param[out] pres A pointer to buffer where pressure results will be placed to, in Pa.
 * @param[in,out] pres_count Input: Number of elements in buffer.
 *                           Output: number of read elements, 0 if no elements were read.
 * @return status code, 0 on success.
 *
 * @note If temperature and pressure have different measurement rates, the output values will not be even.
 * e.g. if temperature measurement rate is 1 and pressure measurement rate is 4, there's going to be 4 pressure
 * measurements for every temperature measurement.
 */
dps310_status_t dps310_get_cont_results (dps310_ctx_t * const ctx, float * const temp,
        uint8_t * const temp_count, float * const pres, uint8_t * const pres_count);

/**
 * @brief Get latest measurement in result registers.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[out] temp A pointer to float where temperature result will be placed to, in C.
 * @param[out] pres A pointer to float where pressure result will be placed to, in Pa.
 * @return status code, 0 on success.
 *
 */
dps310_status_t
dps310_get_last_result (dps310_ctx_t * const ctx, float * const temp, float * const pres);

/**
 * @brief Initialize DPS310 instance.
 *
 * Before calling this function you must setup the function pointers and the communication context.
 * On initialization, sensor reads product ID, revision, calibration coefficients and writes the efuse workaround to IC.
 * After initialization, sensor is placed in standby, with oversampling and measurement rate configured to 1.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @retval DPS310_SUCCESS on success
 * @retval DPS310_ERROR_NULL if ctx, ctx.write, read or sleep is null.
 * @retval DPS310_BUS_ERROR + original code if read/write function returns non-zero value.
 *
 */
dps310_status_t dps310_init (dps310_ctx_t * const ctx);

/**
 * @brief Uninitialize DPS310 instance.
 *
 * After uninitialization, sensor is placed in standby, with oversampling configured to 1.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @return Status code, 0 on success.
 *
 */
dps310_status_t dps310_uninit (dps310_ctx_t * const ctx);

/**
 * @brief Configure temperature measurement.
 *
 * @note (Pressure + temperature) * (oversampling * rate) must be lower than 620,
 * e.g. temperature OS 1 mr 4 and pressure OS 128 and MR 4
 * => temperature 4 OSMR + pressure 512 OSMR => 516 => ok.
 * Rationale is that sensor must be able to finish measurements in one second,
 * and 128 measurements (per value) take 206.8 ms.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[in] temp_mr Measurement rate.
 * @param[in] temp_osr Oversampling per measurement.
 */
dps310_status_t dps310_config_temp (dps310_ctx_t * const ctx, const dps310_mr_t temp_mr,
                                    const dps310_os_t temp_osr);

/**
 * @brief Configure pressure measurement.
 *
 * @note (Pressure + temperature) * (oversampling * rate) must be lower than 620,
 * e.g. temperature OS 1 mr 4 and pressure OS 128 and MR 4
 * => temperature 4 OSMR + pressure 512 OSMR => 516 => ok.
 * Rationale is that sensor must be able to finish measurements in one second,
 * and 128 measurements (per value) take 206.8 ms.
 *
 * @param[in,out] ctx Input: State of sensor. Output: Updated state of sensor.
 * @param[in] pres_mr Measurement rate.
 * @param[in] pres_osr Oversampling per measurement.
 *
 */
dps310_status_t dps310_config_pres (dps310_ctx_t * const ctx, const dps310_mr_t pres_mr,
                                    const dps310_os_t pres_osr);

#endif // DPS310_H
/** @} */
