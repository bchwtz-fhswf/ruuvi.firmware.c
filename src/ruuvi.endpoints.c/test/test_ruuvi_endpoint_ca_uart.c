#include "unity.h"

#include "ruuvi_endpoints.h"
#include "ruuvi_endpoint_ca_uart.h"

#include <string.h>

void setUp (void)
{
    // No action needed.
}

void tearDown (void)
{
    // No action needed.
}

// Ignore tests of unimplemented functionality.
#if 0
void test_ruuvi_endpoint_ca_uart_encode_filter_ruuvi (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        2 + CMD_IN_LEN,
        RE_CA_UART_SET_FLTR,
        0x99U, 0x04U,
        RE_CA_UART_ETX
    };
    uint8_t expected_size = sizeof (expected);
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_FLTR;
    re_ca_uart_ble_filter_t params = { .manufacturer_id = 0x0499};
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.filter = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_encode (buffer, &expected_size, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (expected_size == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_encode_filter_clear (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_CLR_FLTR,
        RE_CA_UART_ETX
    };
    uint8_t expected_size = sizeof (expected);
    re_ca_uart_cmd_t cmd = RE_CA_UART_CLR_FLTR;
    re_ca_uart_ble_filter_t params = { .manufacturer_id = RE_CA_UART_BLE_NOFILTER};
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.filter = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_encode (buffer, &expected_size, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (expected_size == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_channels_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        5 + CMD_IN_LEN,
        RE_CA_UART_SET_CH,
        0x00U, 0x00U, 0x00U, 0x00U, 0xA0U,
        RE_CA_UART_ETX
    };
    uint8_t expected_size = sizeof (expected);
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_CH;
    re_ca_uart_ble_ch_t params =
    {
        .ch37 = 1,
        .ch38 = 0,
        .ch39 = 1
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.channels = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_encode (buffer, &expected_size, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (expected_size == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_phy_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        1 + CMD_IN_LEN,
        RE_CA_UART_SET_PHY,
        0x07U,
        RE_CA_UART_ETX
    };
    uint8_t expected_size = sizeof (expected);
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_PHY;
    re_ca_uart_ble_phy_t params =
    {
        .ble_125kbps = 1,
        .ble_1mbps = 0,
        .ble_2mbps = 1
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.phys = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_encode (buffer, &expected_size, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (expected_size == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}
#endif

void test_ruuvi_endpoint_ca_uart_encode_null (void)
{
    re_status_t err_code = RE_SUCCESS;
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_CH_37;
    re_ca_uart_ble_bool_t params =
    {
        .state = 0x01U
    };
    re_ca_uart_payload_t payload = {0};
    uint8_t size = 255U;
    payload.cmd = cmd;
    payload.params.bool_param = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_encode (NULL, &size, &payload);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
    err_code = re_ca_uart_encode (buffer, NULL, &payload);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
    err_code = re_ca_uart_encode (buffer, &size, NULL);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

void test_ruuvi_endpoint_ca_uart_device_id_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 18 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_DEVICE_ID,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xF5U, 0x95U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_DEVICE_ID;
    re_ca_uart_ble_id_t params =
    {
        .id = 0x2C0CCCE151217DE8,
        .addr = 0x2C0CCCE151217DE8
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.device_id = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_device_id_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 18 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_DEVICE_ID,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xF5U, 0x95U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_DEVICE_ID;
    re_ca_uart_ble_id_t params =
    {
        .id = 0x2C0CCCE151217DE8,
        .addr = 0x2C0CCCE151217DE8
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.device_id = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_get_device_id_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 0 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_GET_DEVICE_ID,
        0x36U, 0x8EU, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_GET_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_get_device_id_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 0 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_GET_DEVICE_ID,
        0x36U, 0x8EU, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_GET_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_ack_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 4 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_ACK,
        RE_CA_UART_SET_ALL,
        RE_CA_UART_FIELD_DELIMITER,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x93U, 0xF1U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_ACK;
    re_ca_uart_ble_ack_t params =
    {
        .cmd = RE_CA_UART_SET_ALL,
        .ack_state.state = 0x01
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.ack = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_ack_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 4 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_ACK,
        RE_CA_UART_SET_ALL,
        RE_CA_UART_FIELD_DELIMITER,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x93U, 0xF1U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_ACK;
    re_ca_uart_ble_ack_t params =
    {
        .cmd = RE_CA_UART_SET_ALL,
        .ack_state.state = 0x01
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.ack = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_all_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 5 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_ALL,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x7FU,
        RE_CA_UART_FIELD_DELIMITER,
        0xA1U, 0x9FU, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_ALL;
    re_ca_uart_ble_all_t params = {0};
    params.fltr_id.id = 0x101;
    params.bools.fltr_tags.state = 1;
    params.bools.coded_phy.state = 1;
    params.bools.scan_phy.state = 1;
    params.bools.ext_payload.state = 1;
    params.bools.ch_37.state = 1;
    params.bools.ch_38.state = 1;
    params.bools.ch_39.state = 1;
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.all_params = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_all_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 5 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_ALL,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xFFU,
        RE_CA_UART_FIELD_DELIMITER,
        0x39U, 0x84U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_ALL;
    re_ca_uart_ble_all_t params = {0};
    params.fltr_id.id = 0x101;
    params.bools.fltr_tags.state = 1;
    params.bools.coded_phy.state = 1;
    params.bools.scan_phy.state = 1;
    params.bools.ext_payload.state = 1;
    params.bools.ch_37.state = 1;
    params.bools.ch_38.state = 1;
    params.bools.ch_39.state = 1;
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.all_params = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_fltr_id_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 3 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_FLTR_ID,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xA8U, 0x39U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_FLTR_ID;
    re_ca_uart_ble_fltr_id_t params =
    {
        .id = 0x101
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.fltr_id_param = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_fltr_id_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 3 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_FLTR_ID,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xA8U, 0x39U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_FLTR_ID;
    re_ca_uart_ble_fltr_id_t params =
    {
        .id = 0x101
    };
    re_ca_uart_payload_t payload = {0};
    payload.cmd = cmd;
    payload.params.fltr_id_param = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_bool_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 2 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_CH_37,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xB6U, 0x78U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_CH_37;
    re_ca_uart_ble_bool_t params =
    {
        .state = 0x01U
    };
    re_ca_uart_payload_t payload = {0};;
    payload.cmd = cmd;
    payload.params.bool_param = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_bool_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 2 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_SET_CH_37,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xB6U, 0x78U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_SET_CH_37;
    re_ca_uart_ble_bool_t params =
    {
        .state = 0x01U
    };
    re_ca_uart_payload_t payload = {0};;
    payload.cmd = cmd;
    payload.params.bool_param = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_adv_encode (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 41 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0x50U, 0x00U, 0xC8U, 0xFCU,
        0x20U, 0xA4U, 0x56U, 0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U,
        0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0xB3U, 0x0CU, //crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_ble_adv_t params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0x50U, 0x00U, 0xC8U, 0xFCU,
            0x20U, 0xA4U, 0x56U, 0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U,
            0x8DU
        }, //!< Data
        31, //!< Data length
        -40//RSSI
    };
    re_ca_uart_payload_t payload = {0};;
    payload.cmd = cmd;
    payload.params.adv = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = sizeof (buffer);
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (buffer_len == sizeof (expected));
    TEST_ASSERT (!memcmp (expected, buffer, sizeof (expected)));
}

void test_ruuvi_endpoint_ca_uart_adv_encode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    const uint8_t expected_size = 41 + CMD_IN_LEN;
    uint8_t expected[] =
    {
        RE_CA_UART_STX,
        expected_size,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0x50U, 0x00U, 0xC8U, 0xFCU,
        0x20U, 0xA4U, 0x56U, 0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U,
        0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0xB3U, 0x0CU, //crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_ble_adv_t params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0x50U, 0x00U, 0xC8U, 0xFCU,
            0x20U, 0xA4U, 0x56U, 0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U,
            0x8DU
        }, //!< Data
        31, //!< Data length
        -40//RSSI
    };
    re_ca_uart_payload_t payload = {0};;
    payload.cmd = cmd;
    payload.params.adv = params;
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    uint8_t buffer_len = 1;
    err_code = re_ca_uart_encode (buffer, &buffer_len, &payload);
    TEST_ASSERT (RE_ERROR_DATA_SIZE == err_code);
    TEST_ASSERT (buffer_len != sizeof (expected));
    TEST_ASSERT (memcmp (expected, buffer, sizeof (expected)));
}

#ifdef RE_CA_SUPPORT_OLD_CMD
void test_ruuvi_endpoint_ca_uart_decode_filter_ruuvi (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        2 + CMD_IN_LEN,
        RE_CA_UART_SET_FLTR,
        0x99U, 0x04U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_filter_t expect_params = { .manufacturer_id = 0x0499U};
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_FLTR;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.filter, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_decode_filter_invalid_ruuvi (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_SET_FLTR,
        0x99U, 0x04U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_filter_t expect_params = { .manufacturer_id = 0x0499U};
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_FLTR;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.filter, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_decode_filter_clear (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_CLR_FLTR,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_filter_t expect_params = { .manufacturer_id = 0x0000};
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_CLR_FLTR;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.filter, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_decode_filter_invalid_clear (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        2 + CMD_IN_LEN,
        RE_CA_UART_CLR_FLTR,
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_CLR_FLTR;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING == err_code);
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}
#endif

void test_ruuvi_endpoint_ca_uart_decode_null (void)
{
    re_status_t err_code = RE_SUCCESS;
    re_ca_uart_payload_t payload = {0};
    uint8_t buffer[RE_CA_UART_TX_MAX_LEN] = {0};
    err_code = re_ca_uart_decode (NULL, &payload);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
    err_code = re_ca_uart_decode (buffer, NULL);
    TEST_ASSERT (RE_ERROR_NULL == err_code);
}

#ifdef RE_CA_SUPPORT_OLD_CMD
void test_ruuvi_endpoint_ca_uart_channels_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        5 + CMD_IN_LEN,
        RE_CA_UART_SET_CH,
        0x00U, 0x00U, 0x00U, 0x00U, 0xA0U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_ch_t expect_params =
    {
        .ch37 = 1,
        .ch38 = 0,
        .ch39 = 1
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_CH;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.channels, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_channels_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_SET_CH,
        0x00U, 0x00U, 0x00U, 0x00U, 0xA0U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_ch_t expect_params =
    {
        .ch37 = 1,
        .ch38 = 0,
        .ch39 = 1
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_CH;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.channels, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_phy_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        1 + CMD_IN_LEN,
        RE_CA_UART_SET_PHY,
        0x05U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_phy_t expect_params =
    {
        .ble_125kbps = 1,
        .ble_1mbps = 0,
        .ble_2mbps = 1
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_PHY;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.phys, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_phy_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_SET_PHY,
        0x05U,
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_phy_t expect_params =
    {
        .ble_125kbps = 1,
        .ble_1mbps = 0,
        .ble_2mbps = 1
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_PHY;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.phys, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}
#endif

void test_ruuvi_endpoint_ca_ack_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        4 + CMD_IN_LEN,
        RE_CA_UART_ACK,
        RE_CA_UART_SET_ALL,
        RE_CA_UART_FIELD_DELIMITER,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x93U, 0xF1U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_ack_t expect_params = {0};
    expect_params.cmd = RE_CA_UART_SET_ALL;
    expect_params.ack_state.state = 1;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ACK;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.ack, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_ack_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        5 + CMD_IN_LEN,
        RE_CA_UART_ACK,
        RE_CA_UART_SET_ALL,
        RE_CA_UART_FIELD_DELIMITER,
        RE_CA_ACK_ERROR,
        RE_CA_ACK_ERROR,
        RE_CA_UART_FIELD_DELIMITER,
        0x0BU, 0x41U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_ack_t expect_params = {0};
    expect_params.cmd = RE_CA_UART_SET_ALL;
    expect_params.ack_state.state = 1;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ACK;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.ack, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_all_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        5 + CMD_IN_LEN,
        RE_CA_UART_SET_ALL,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xFFU,
        RE_CA_UART_FIELD_DELIMITER,
        0x39U, 0x84U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_all_t expect_params = {0};
    expect_params.fltr_id.id = 0x101;
    expect_params.bools.fltr_tags.state = 1;
    expect_params.bools.coded_phy.state = 1;
    expect_params.bools.scan_phy.state = 1;
    expect_params.bools.ext_payload.state = 1;
    expect_params.bools.ch_37.state = 1;
    expect_params.bools.ch_38.state = 1;
    expect_params.bools.ch_39.state = 1;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_ALL;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.all_params,
                          sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_all_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        6 + CMD_IN_LEN,
        RE_CA_UART_SET_ALL,
        0x01U, 0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x21U, 0x87U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_all_t expect_params = {0};
    expect_params.fltr_id.id = 0x101;
    expect_params.bools.fltr_tags.state = 1;
    expect_params.bools.coded_phy.state = 0;
    expect_params.bools.scan_phy.state = 0;
    expect_params.bools.ext_payload.state = 0;
    expect_params.bools.ch_37.state = 0;
    expect_params.bools.ch_38.state = 0;
    expect_params.bools.ch_39.state = 0;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_ALL;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.all_params, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_id_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        3 + CMD_IN_LEN,
        RE_CA_UART_SET_FLTR_ID,
        0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xA8U, 0x39U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_fltr_id_t expect_params =
    {
        .id = 0x101
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_FLTR_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.fltr_id_param,
                          sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_id_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        4 + CMD_IN_LEN,
        RE_CA_UART_SET_FLTR_ID,
        0x01U, 0x01U, 0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0x6FU, 0x52U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_fltr_id_t expect_params =
    {
        .id = 0x101
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_FLTR_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.fltr_id_param,
                         sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_device_id_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        18 + CMD_IN_LEN,
        RE_CA_UART_DEVICE_ID,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xF5U, 0x95U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_id_t expect_params = {0};
    expect_params.id = 0x2C0CCCE151217DE8;
    expect_params.addr = 0x2C0CCCE151217DE8;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.device_id,
                          sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_device_id_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        19 + CMD_IN_LEN,
        RE_CA_UART_DEVICE_ID,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0xE8U, 0x7DU, 0x21U, 0x51U, 0XE1U, 0xCCU, 0x0CU, 0x2CU, 0x2CU,
        RE_CA_UART_FIELD_DELIMITER,
        0x04U, 0x16U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_id_t expect_params = {0};
    expect_params.id = 0x2C0CCCE151217DE8;
    expect_params.addr = 0x2C0CCCE151217DE8;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.device_id, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_get_device_id_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        0 + CMD_IN_LEN,
        RE_CA_UART_GET_DEVICE_ID,
        0x36U, 0x8EU, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_GET_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_get_device_id_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        1 + CMD_IN_LEN,
        RE_CA_UART_GET_DEVICE_ID,
        0x01U,
        0x57U, 0x61U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_GET_DEVICE_ID;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_bool_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        2 + CMD_IN_LEN,
        RE_CA_UART_SET_CH_37,
        0x01U,
        RE_CA_UART_FIELD_DELIMITER,
        0xB6U, 0x78U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_bool_t expect_params = {0};
    expect_params.state = 0x01;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_CH_37;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.bool_param,
                          sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_bool_decode_invalid (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        3 + CMD_IN_LEN,
        RE_CA_UART_SET_CH_37,
        0x01U, 0x00,
        RE_CA_UART_FIELD_DELIMITER,
        0xABU, 0x45U, //crc
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_bool_t expect_params = {0};
    expect_params.state = 0x01;
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_SET_CH_37;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.bool_param, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_decode_invalid_crc (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        41U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0x61U, 0xF0U, //crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U,
            0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_CRC == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}


void test_ruuvi_endpoint_ca_uart_decode_no_stx (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        41U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0x61U, 0xF2U, //crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U,
            0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_STX == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}


void test_ruuvi_endpoint_ca_uart_decode_noetx (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        41U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0x61U, 0xF2U //crc16
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U,
            0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_ETX == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        41U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0x61U, 0xF2U,//crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, RE_CA_UART_FIELD_DELIMITER, 0xE3U,
            0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode_nodelimiter1 (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        38U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, //!< Data
        0xD8U, //RSSI
        0x9EU, 0x63U,//crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_DELIMITER == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode_nodelimiter2 (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        40U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0xF0U, 0xFCU,//crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_DELIMITER == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode_nodelimiter3 (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        41U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_ETX, //RSSI
        0xC4U, 0xF5U, //crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_DELIMITER == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode_toolong (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        72U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU,
        0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
        0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
        0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU,
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //!< Data//RSSI
        0x1DU, 0xD6U,//crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
            0x02U, 0x01U, 0x04U, 0x1BU, 0xFFU, 0x99U, 0x04U, 0x05U, 0x0FU, 0x27U, 0x40U,
            0x35U, 0xC4U, 0x54U, 0x00U, 0x50U, 0x00U, 0xC8U, 0xFCU, 0x20U, 0xA4U, 0x56U,
            0xF0U, 0x30U, 0xE5U, 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU
        },   //!< Data
        31U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_ERROR_DECODING_LEN == err_code);
    TEST_ASSERT (memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}

void test_ruuvi_endpoint_ca_uart_adv_decode_nodata (void)
{
    re_status_t err_code = RE_SUCCESS;
    uint8_t data[] =
    {
        RE_CA_UART_STX,
        10U + CMD_IN_LEN,
        RE_CA_UART_ADV_RPRT,
        0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU, RE_CA_UART_FIELD_DELIMITER, //!< MAC
        RE_CA_UART_FIELD_DELIMITER, //!< Data
        0xD8U, RE_CA_UART_FIELD_DELIMITER, //RSSI
        0x6AU, 0x89U,//crc16
        RE_CA_UART_ETX
    };
    re_ca_uart_ble_adv_t expect_params =
    {
        { 0xC9U, 0x44U, 0x54U, 0x29U, 0xE3U, 0x8DU }, //!< MAC
        {
        },   //!< Data
        0U, //!< Data length
        -40  //RSSI
    };
    re_ca_uart_cmd_t expect_cmd = RE_CA_UART_ADV_RPRT;
    re_ca_uart_payload_t payload = {0};
    err_code = re_ca_uart_decode (data, &payload);
    TEST_ASSERT (RE_SUCCESS == err_code);
    TEST_ASSERT (!memcmp (&expect_params, &payload.params.adv, sizeof (expect_params)));
    TEST_ASSERT (!memcmp (&expect_cmd, &payload.cmd, sizeof (expect_cmd)));
}
