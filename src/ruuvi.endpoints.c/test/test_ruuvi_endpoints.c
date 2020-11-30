#include "unity.h"

#include "ruuvi_endpoints.h"

void setUp (void)
{
}

void tearDown (void)
{
}


/**
 * @brief Get current time for log read command to compensate timestamps.
 *
 * @param[in] raw_message 11-byte payload from central.
 * @return u32 timestamp, 0 if raw_message was NULL.
 */
void test_re_std_log_current_time_ok (void)
{
    uint8_t message[11] = {0, 0, 0, 0x5F, 0x32, 0xAE, 0xB0, 0, 0, 0, 0};
    uint32_t ts = re_std_log_current_time (message);
    TEST_ASSERT (1597157040 == ts);
}

void test_re_std_log_current_time_null (void)
{
    uint32_t ts = re_std_log_current_time (NULL);
    TEST_ASSERT (0 == ts);
}

/**
 * @brief Get start time for log read command.
 *
 * @param[in] raw_message 11-byte payload from central.
 * @return u32 timestamp, 0 if raw_message was NULL.
 */
void test_re_std_log_start_time_ok (void)
{
    uint8_t message[11] = {0, 0, 0, 0, 0, 0, 0, 0x5F, 0x32, 0xAE, 0xB0};
    uint32_t ts = re_std_log_start_time (message);
    TEST_ASSERT (1597157040 == ts);
}

void test_re_std_log_start_time_null (void)
{
    uint32_t ts = re_std_log_start_time (NULL);
    TEST_ASSERT (0 == ts);
}

/**
 * @brief Write a log write header to given buffer.
 *
 * @param[out] buffer 11-byte buffer to which header will be written.
 * @param[in]  source Source endpoint of data.
 * @retval RE_SUCCESS Header was written successfully.
 * @retval RE_ERROR_NULL Buffer was NULL.
 */
void test_re_log_write_header_ok (void)
{
    uint8_t buffer[11] = {0};
    re_status_t err_code = re_log_write_header (buffer, RE_ACC_Y);
    TEST_ASSERT (buffer[RE_STANDARD_DESTINATION_INDEX] = RE_ACC_Y);
    TEST_ASSERT (buffer[RE_STANDARD_OPERATION_INDEX] = RE_STANDARD_LOG_VALUE_WRITE);
    TEST_ASSERT (RE_SUCCESS == err_code);
}

void test_re_log_write_header_null (void)
{
    re_status_t err_code = re_log_write_header (NULL, RE_ACC_Y);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief write a log element timestamp to the given buffer.
 *
 * @param[out] 11-byte buffer to write data to.
 * @param[in]  timestamp_ms Timestamp as it will be sent to remote.
 * @retval RE_SUCCESS encoding was successful.
 * @retval RE_ERROR_NULL buffer was NULL
 * @retval RE_ERROR_INVALID_PARAM timestamp cannot be encoded as 32-bit second value.
 */
void test_re_log_write_timestamp_ok (void)
{
    uint8_t buffer[11] = {0};
    uint64_t ts = ( (uint64_t) 1597157040) * 1000;
    re_status_t err_code = re_log_write_timestamp (buffer, ts);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer[RE_LOG_WRITE_TS_MSB_IDX] == 0x5F);
    TEST_ASSERT (buffer[RE_LOG_WRITE_TS_B2_IDX] == 0x32);
    TEST_ASSERT (buffer[RE_LOG_WRITE_TS_B3_IDX] == 0xAE);
    TEST_ASSERT (buffer[RE_LOG_WRITE_TS_LSB_IDX] == 0xB0);
}

void test_re_log_write_timestamp_null (void)
{
    uint64_t ts = ( (uint64_t) 1597157040) * 1000;
    re_status_t err_code = re_log_write_timestamp (NULL, ts);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

void test_re_log_write_timestamp_overflow (void)
{
    uint8_t buffer[11] = {0};
    uint64_t ts = ( (uint64_t) 0x100000000) * 1000;
    re_status_t err_code = re_log_write_timestamp (buffer, ts);
    TEST_ASSERT (RE_ERROR_INVALID_PARAM == err_code);
}

void test_re_log_write_timestamp_max (void)
{
    uint8_t buffer[11] = {0};
    uint64_t ts = ( (uint64_t) 0xFFFFFFFF) * 1000;
    re_status_t err_code = re_log_write_timestamp (buffer, ts);
    TEST_ASSERT (RE_SUCCESS == err_code);
}

/**
 * @brief Encode given float to the given buffer.
 *
 * @param[out] buffer 11-byte buffer to which data is encoded. 0xFFFFFFFF on error.
 * @param[in]  data Float value to encode.
 * @param[in]  source Ruuvi Endpoint data source, e.g. RE_STANDARD_DESTINATION_ACCELERATION_X.
 *
 * @retval RE_SUCCESS Data was encoded successfully.
 * @retval RE_ERROR_NULL Buffer was NULL.
 * @retval RE_ERROR_INVALID_PARAMETER if data is NAN or inf.
 * @retval RE_NOT_IMPLEMENTED if there's no encoding for given data source.
 */
void test_log_write_data_temperature_positive_round_down (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 22.554F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x8U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0xCFU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 22.546F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x8U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0xCFU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_negative_round_down (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, -22.554F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0xF7U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x31U == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_negative_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, -22.546F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0xF7U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x31U == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_positive_max (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 21474836.47F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0x7FU == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_negative_min (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, -21474836.47F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0x80U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x01U == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_positive_overflow (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 21474837.0F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0x7FU == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0xFFU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_temperature_negative_undeflow (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, -21474847.0F, RE_ENV_TEMP);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0x80U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x01U == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_humidity_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 22.546F, RE_ENV_HUMI);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x8U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0xCFU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_pressure_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 100101.546F, RE_ENV_PRES);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x01U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x87U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_accx_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_ACC_X);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_accy_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_ACC_Y);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_accz_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_ACC_Z);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_gyrx_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_GYR_X);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_gyry_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_GYR_Y);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}

void test_log_write_data_gyrz_positive_round_up (void)
{
    uint8_t buffer[11U] = {0};
    re_status_t err_code = re_log_write_data (buffer, 1.5466F, RE_GYR_Z);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (0U == buffer[RE_LOG_WRITE_VALUE_MSB_IDX]);
    TEST_ASSERT (0x00U == buffer[RE_LOG_WRITE_VALUE_B2_IDX]);
    TEST_ASSERT (0x06U == buffer[RE_LOG_WRITE_VALUE_B3_IDX]);
    TEST_ASSERT (0x0BU == buffer[RE_LOG_WRITE_VALUE_LSB_IDX]);
}