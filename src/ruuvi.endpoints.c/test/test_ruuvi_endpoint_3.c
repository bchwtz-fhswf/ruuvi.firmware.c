#include "unity.h"

#include "ruuvi_endpoint_3.h"

#include <string.h>

static const re_3_data_t m_re_3_data_ok =
{
    .humidity_rh = 20.5,
    .pressure_pa = 102766,
    .temperature_c = 26.3,
    .accelerationx_g = -1.000,
    .accelerationy_g = -1.726,
    .accelerationz_g = 0.714,
    .battery_v = 2.899
};

static const uint8_t valid_data[] =
{
    0x03, 0x29, 0x1A, 0x1E, 0xCE, 0x1E, 0xFC, 0x18, 0xF9, 0x42, 0x02, 0xCA, 0x0B, 0x53
};

static const re_3_data_t m_re_3_data_max =
{
    .humidity_rh = 127.5,
    .pressure_pa = 115535,
    .temperature_c = 127.99,
    .accelerationx_g = 32.767,
    .accelerationy_g = 32.767,
    .accelerationz_g = 32.767,
    .battery_v = 65.535
};

static const re_3_data_t m_re_3_data_cap =
{
    .humidity_rh = 127.5,
    .pressure_pa = 115535,
    .temperature_c = 135,
    .accelerationx_g = 32.767,
    .accelerationy_g = 32.767,
    .accelerationz_g = 32.767,
    .battery_v = 65.535
};

static const uint8_t max_data[] =
{
    0x03, 0xFF, 0x7F, 0x63, 0xFF, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF
};

static const re_3_data_t m_re_3_data_min =
{
    .humidity_rh = 0.0,
    .pressure_pa = 50000,
    .temperature_c = -127.99,
    .accelerationx_g = -32.767,
    .accelerationy_g = -32.767,
    .accelerationz_g = -32.767,
    .battery_v = 0.000
};

static const uint8_t min_data[] =
{
    0x03, 0x00, 0xFF, 0x63, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00
};

static const re_3_data_t m_re_3_data_invalid =
{
    .humidity_rh = 0xffff,
    .pressure_pa = 0xffff,
    .temperature_c = 0xffff,
    .accelerationx_g = 0xffff,
    .accelerationy_g = 0xffff,
    .accelerationz_g = 0xffff,
    .battery_v = 0xffff
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
void test_ruuvi_endpoint_3_get_ok (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[14] = {0};
    const float invalid =  NAN;
    err_code = re_3_encode (test_buffer,
                            &m_re_3_data_ok, invalid);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, valid_data, sizeof (valid_data))));
}

void test_ruuvi_endpoint_3_get_ok_max (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[14] = {0};
    const float invalid =  NAN;
    err_code = re_3_encode (test_buffer,
                            &m_re_3_data_max, invalid);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, max_data, sizeof (valid_data))));
}

void test_ruuvi_endpoint_3_get_ok_cap (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[14] = {0};
    const float invalid =  NAN;
    err_code = re_3_encode (test_buffer,
                            &m_re_3_data_cap, invalid);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, max_data, sizeof (valid_data))));
}

void test_ruuvi_endpoint_3_get_ok_min (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[14] = {0};
    const float invalid =  NAN;
    err_code = re_3_encode (test_buffer,
                            &m_re_3_data_min, invalid);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, min_data, sizeof (valid_data))));
}

/**
 * @brief Null buffer
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_3_get_error_null_buffer (void)
{
    re_status_t err_code = RE_ERROR_NULL;
    uint8_t * const p_test_buffer = NULL;
    const float invalid =  NAN;
    err_code = re_3_encode (p_test_buffer,
                            (const re_3_data_t * const) &m_re_3_data_ok, invalid);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief Null data
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_3_get_error_null_data (void)
{
    re_status_t err_code = RE_ERROR_NULL;
    uint8_t test_buffer[14] = {0};
    const float invalid =  NAN;
    const re_3_data_t * const p_re_3_data = NULL;
    err_code = re_3_encode ( (uint8_t * const) &test_buffer,
                             p_re_3_data, invalid);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief True to test encode operation with invalid data
 *
 * @retval RD_SUCCESS on success test.
 */
void test_ruuvi_endpoint_3_get_invalid_data (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[14] = {0};
    const float invalid =  0xffff;
    err_code = re_3_encode ( (uint8_t * const) &test_buffer,
                             (const re_3_data_t * const) &m_re_3_data_invalid, invalid);
    TEST_ASSERT (RE_SUCCESS == err_code &&
                 RE_3_DESTINATION == test_buffer[0] &&
                 RE_3_INVALID_DATA == test_buffer[1] &&
                 RE_3_INVALID_DATA == test_buffer[2] &&
                 RE_3_INVALID_DATA == test_buffer[3] &&
                 RE_3_INVALID_DATA == test_buffer[4] &&
                 RE_3_INVALID_DATA == test_buffer[5] &&
                 RE_3_INVALID_DATA == test_buffer[6] &&
                 RE_3_INVALID_DATA == test_buffer[7] &&
                 RE_3_INVALID_DATA == test_buffer[8] &&
                 RE_3_INVALID_DATA == test_buffer[9] &&
                 RE_3_INVALID_DATA == test_buffer[10] &&
                 RE_3_INVALID_DATA == test_buffer[11] &&
                 RE_3_INVALID_DATA == test_buffer[12] &&
                 RE_3_INVALID_DATA == test_buffer[13]);
}
