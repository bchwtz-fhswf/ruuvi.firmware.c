#include "unity.h"

#include "ruuvi_endpoint_ibeacon.h"

static re_ibeacon_data_t m_ibeacon_data_ok =
{
    .proximity_uuid = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    },
    .major = 1234,
    .minor = 1234,
    .tx_power = -40
};

static re_ibeacon_data_t m_ibeacon_data_invalid =
{
    .proximity_uuid = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    },
    .major = 1234,
    .minor = 1234,
    .tx_power = 127
};

void setUp (void)
{
}

void tearDown (void)
{
}

/**
 * @brief Typical encode operation
 *
 * @retval RD_SUCCESS on success test.
 */
void test_ruuvi_endpoint_ibeacon_get_ok (void)
{
    re_status_t err_code = RE_SUCCESS;
#ifndef RE_IBEACON_OFFSET_EXCEPT_HEADER
    uint8_t test_buffer[21] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer;
#else
    uint8_t test_buffer[30] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer[9];
#endif
    err_code = re_ibeacon_encode (p_test_buffer, &m_ibeacon_data_ok);
    TEST_ASSERT (RE_SUCCESS == err_code);
}

/**
 * @brief Incorrect value in tx_power
 *
 * @retval RE_ERROR_INVALID_PARAM on success test.
 */
void test_ruuvi_endpoint_ibeacon_get_error_invalid (void)
{
    re_status_t err_code = RE_ERROR_INVALID_PARAM;
#ifndef RE_IBEACON_OFFSET_EXCEPT_HEADER
    uint8_t test_buffer[21] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer;
#else
    uint8_t test_buffer[30] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer[9];
#endif
    err_code = re_ibeacon_encode (p_test_buffer, &m_ibeacon_data_invalid);
    TEST_ASSERT (RE_ERROR_INVALID_PARAM == err_code);
}

/**
 * @brief Null buffer
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_ibeacon_get_error_null_buffer (void)
{
    re_status_t err_code = RE_ERROR_NULL;
    uint8_t * const p_test_buffer = NULL;
    err_code = re_ibeacon_encode (p_test_buffer, &m_ibeacon_data_ok);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief Null data
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_ibeacon_get_error_null_data (void)
{
    re_status_t err_code = RE_ERROR_NULL;
#ifndef RE_IBEACON_OFFSET_EXCEPT_HEADER
    uint8_t test_buffer[21] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer;
#else
    uint8_t test_buffer[30] = {0};
    uint8_t * const p_test_buffer = (uint8_t * const) &test_buffer[9];
#endif
    re_ibeacon_data_t * p_ibeacon_data = NULL;
    err_code = re_ibeacon_encode (p_test_buffer, p_ibeacon_data);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}
