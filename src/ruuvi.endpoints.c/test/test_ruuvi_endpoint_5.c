#include "unity.h"

#include "ruuvi_endpoint_5.h"

static const re_5_data_t m_re_5_data_ok =
{
    .humidity_rh = 53.49,
    .pressure_pa = 100044,
    .temperature_c = 24.3,
    .accelerationx_g = 0.004,
    .accelerationy_g = -0.004,
    .accelerationz_g = 1.036,
    .battery_v = 2.977,
    .measurement_count = 205,
    .movement_count = 66,
    .address = 0xCBB8334C884F,
    .tx_power = 4
};

static const uint8_t valid_data[] =
{
    0x05, 0x12, 0xFC, 0x53, 0x94, 0xC3, 0x7C, 0x00,
    0x04, 0xFF, 0xFC, 0x04, 0x0C, 0xAC, 0x36, 0x42,
    0x00, 0xCD, 0xCB, 0xB8, 0x33, 0x4C, 0x88, 0x4F
};

static const re_5_data_t m_re_5_data_ok_max =
{
    .humidity_rh = 163.8350,
    .pressure_pa = 115534,
    .temperature_c = 163.8350,
    .accelerationx_g = 32.767,
    .accelerationy_g = 32.767,
    .accelerationz_g = 32.767,
    .battery_v = 3.646,
    .measurement_count = 65534,
    .movement_count = 254,
    .address = 0xCBB8334C884F,
    .tx_power = 20
};

static const uint8_t max_data[] =
{
    0x05, 0x7F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFE, 0x7F,
    0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0xDE, 0xFE,
    0xFF, 0xFE, 0xCB, 0xB8, 0x33, 0x4C, 0x88, 0x4F
};

static const re_5_data_t m_re_5_data_ok_min =
{
    .humidity_rh = 0.000,
    .pressure_pa = 50000,
    .temperature_c = -163.835,
    .accelerationx_g = -32.767,
    .accelerationy_g = -32.767,
    .accelerationz_g = -32.767,
    .battery_v = 1.600,
    .measurement_count = 0,
    .movement_count = 0,
    .address = 0xCBB8334C884F,
    .tx_power = -40
};

static const uint8_t min_data[] =
{
    0x05, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCB, 0xB8, 0x33, 0x4C, 0x88, 0x4F
};

static const re_5_data_t m_re_5_data_invalid_min_1 =
{
    .humidity_rh = 53.49,
    .pressure_pa = 49999,
    .temperature_c = 24.3,
    .accelerationx_g = 0.004,
    .accelerationy_g = -0.004,
    .accelerationz_g = 1.036,
    .battery_v = 1.500,
    .measurement_count = 205,
    .movement_count = 66,
    .address = 0xCBB8334C884F,
    .tx_power = 4
};

static const re_5_data_t m_re_5_data_invalid_min_2 =
{
    .humidity_rh = 53.49,
    .pressure_pa = 49999,
    .temperature_c = 24.3,
    .accelerationx_g = 0.004,
    .accelerationy_g = -0.004,
    .accelerationz_g = 1.036,
    .battery_v = 2.977,
    .measurement_count = 205,
    .movement_count = 66,
    .address = 0xCBB8334C884F,
    .tx_power = -41
};

static const re_5_data_t m_re_5_data_invalid_max =
{
    .humidity_rh = 53.49,
    .pressure_pa = 100044,
    .temperature_c = 24.3,
    .accelerationx_g = 0.004,
    .accelerationy_g = -0.004,
    .accelerationz_g = 1.036,
    .battery_v = 2.977,
    .measurement_count = 205,
    .movement_count = 66,
    .address = 0xCBB8334C884F,
    .tx_power = 25
};

static const re_5_data_t m_re_5_data_invalid =
{
    .humidity_rh = NAN,
    .pressure_pa = NAN,
    .temperature_c = NAN,
    .accelerationx_g = NAN,
    .accelerationy_g = NAN,
    .accelerationz_g = NAN,
    .battery_v = NAN,
    .measurement_count = 65535,
    .movement_count = 255,
    .address = 0xFFFFFFFFFFFF,
    .tx_power = 26
};

static const uint8_t invalid_data[] =
{
    0x05, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x80,
    0x00, 0x80, 0x00, 0x80, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
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
void test_ruuvi_endpoint_5_get_ok (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t *) &m_re_5_data_ok);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, valid_data, sizeof (valid_data))));
}

void test_ruuvi_endpoint_5_get_ok_max (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t *) &m_re_5_data_ok_max);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, max_data, sizeof (max_data))));
}

void test_ruuvi_endpoint_5_get_ok_min (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t *) &m_re_5_data_ok_min);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, min_data, sizeof (min_data))));
}

/**
 * @brief Null buffer
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_5_get_error_null_buffer (void)
{
    re_status_t err_code = RE_ERROR_NULL;
    uint8_t * const p_test_buffer = NULL;
    err_code = re_5_encode (p_test_buffer,
                            (const re_5_data_t *) &m_re_5_data_ok);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief Null data
 *
 * @retval RE_ERROR_NULL on success test.
 */
void test_ruuvi_endpoint_5_get_error_null_data (void)
{
    re_status_t err_code = RE_ERROR_NULL;
    uint8_t test_buffer[24] = {0};
    const re_5_data_t * p_re_5_data = NULL;
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             p_re_5_data);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

/**
 * @brief True to test encode operation with invalid data
 *
 * @retval RD_SUCCESS on success test.
 */
void test_ruuvi_endpoint_5_get_invalid_data (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t *) &m_re_5_data_invalid);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (! (memcmp (test_buffer, invalid_data, sizeof (invalid_data))));
}

void test_ruuvi_endpoint_5_get_min_1_invalid_data (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t * const) &m_re_5_data_invalid_min_1);
    TEST_ASSERT (RE_SUCCESS == err_code &&
                 (RE_5_INVALID_PRESSURE >> 8) == test_buffer[RE_5_OFFSET_PRESSURE_MSB] &&
                 (RE_5_INVALID_PRESSURE & 0xFF) == test_buffer[RE_5_OFFSET_PRESSURE_LSB] &&
                 0xFF == test_buffer[RE_5_OFFSET_POWER_MSB] &&
                 0x70 == (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x70) &&
                 RE_5_INVALID_POWER != (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x1F));
}

void test_ruuvi_endpoint_5_get_min_2_invalid_data (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t * const) &m_re_5_data_invalid_min_2);
    TEST_ASSERT (RE_SUCCESS == err_code &&
                 (RE_5_INVALID_PRESSURE >> 8) == test_buffer[RE_5_OFFSET_PRESSURE_MSB] &&
                 (RE_5_INVALID_PRESSURE & 0xFF) == test_buffer[RE_5_OFFSET_PRESSURE_LSB] &&
                 0xFF != test_buffer[RE_5_OFFSET_POWER_MSB] &&
                 0x70 != (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x70) &&
                 RE_5_INVALID_POWER == (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x1F));
}

void test_ruuvi_endpoint_5_get_max_invalid_data (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t test_buffer[24] = {0};
    err_code = re_5_encode ( (uint8_t * const) &test_buffer,
                             (const re_5_data_t * const) &m_re_5_data_invalid_max);
    TEST_ASSERT (RE_SUCCESS == err_code &&
                 0xFF != test_buffer[RE_5_OFFSET_POWER_MSB] &&
                 0x70 != (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x70) &&
                 RE_5_INVALID_POWER == (test_buffer[RE_5_OFFSET_POWER_LSB] & 0x1F));
}
