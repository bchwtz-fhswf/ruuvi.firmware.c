#include "unity.h"

#include "dps310.h"
#include "dps310_reg.h"
#include <stdbool.h>
#include <string.h>

#define INIT_TIME_MS          (DPS310_POR_DELAY_MS + DPS310_COEF_DELAY_MS)
#define MEASURE_1_TIME_MS     (4U) // 3.6F to be exact, one sensor, one sample.
#define MEASURE_2_TIME_MS     (6U) // 5.2F to be exact, one sensor, oversample 2.
#define MEASURE_4_TIME_MS     (9U) // 8.24F to be exact, one sensor, oversample 4.
#define MEASURE_8_TIME_MS     (15U) // 14.8F to be exact, one sensor, oversample 8.
#define MEASURE_16_TIME_MS    (28U) // 27.6F to be exact, one sensor, oversample 16.
#define MEASURE_32_TIME_MS    (54U) // 53.2F to be exact, one sensor, oversample 32.
#define MEASURE_64_TIME_MS    (105U) // 104.4F to be exact, one sensor, oversample 64.
#define MEASURE_128_TIME_MS   (207U) // 206.8F to be exact, one sensor, oversample 128.
#define DPS310_SIM_TABLE_SIZE (0x63U)

static uint8_t dps310_registers[DPS310_SIM_TABLE_SIZE];
// FIFO registers, 32 measurements, 4 pressure measurements for one temperature measurement.
// Type of measurement is identified by least significant bit of 3-byte measurement.
// Last entry is FIFO EOF
static const uint8_t dps310_fifo_p4_t1[3U * 33U] =
{
    0x7AU, 0x10U, 0x01U, 0x7AU, 0x11U, 0x01U, 0x7AU, 0x12U, 0x01U, 0x7AU, 0x13U, 0x01U, 0x7AU, 0x10U, 0x00U,
    0x7AU, 0x14U, 0x01U, 0x7AU, 0x15U, 0x01U, 0x7AU, 0x16U, 0x01U, 0x7AU, 0x17U, 0x01U, 0x7AU, 0x11U, 0x00U,
    0x7AU, 0x18U, 0x01U, 0x7AU, 0x19U, 0x01U, 0x7AU, 0x1AU, 0x01U, 0x7AU, 0x1BU, 0x01U, 0x7AU, 0x12U, 0x00U,
    0x7AU, 0x1CU, 0x01U, 0x7AU, 0x1DU, 0x01U, 0x7AU, 0x1EU, 0x01U, 0x7AU, 0x1FU, 0x01U, 0x7AU, 0x13U, 0x00U,
    0x7AU, 0x20U, 0x01U, 0x7AU, 0x21U, 0x01U, 0x7AU, 0x22U, 0x01U, 0x7AU, 0x23U, 0x01U, 0x7AU, 0x14U, 0x00U,
    0x7AU, 0x24U, 0x01U, 0x7AU, 0x25U, 0x01U, 0x7AU, 0x26U, 0x01U, 0x7AU, 0x27U, 0x01U, 0x7AU, 0x15U, 0x00U,
    0x7AU, 0x28U, 0x01U, 0x7AU, 0x29U, 0x01U, 0x80U, 0x00U, 0x00U
};
static uint8_t fifo_idx;
static uint32_t time_ms;
static uint32_t drdy_ms;
static int32_t bus_code;
static uint8_t efuse_writes;
static uint8_t soft_resets;
static uint8_t rev_id;

static void check_reserved_registers (void)
{
    for (uint8_t ii = DPS310_RESERVED_START; ii <= DPS310_RESERVED_END; ii++)
    {
        TEST_ASSERT (0U == dps310_registers[ii]);
    }
}

/**
 * The register values here are heuristically iterated, i.e. guessed.
 * They produce some physically meaningless values, such as negative absolute pressure
 * and values which DPS310 could not measure, but they can be used to verify the
 * mathematics in driver.
 */
static void init_dps_regs (void)
{
    memset (dps310_registers, 0, sizeof (dps310_registers));
    dps310_registers[DPS310_MEAS_CFG_REG] = DPS310_MEAS_CFG_BOOT_VAL;
    dps310_registers[DPS310_PROD_ID_REG]  = rev_id;
    dps310_registers[0x10] = 0xF9U; // C0 = -100
    dps310_registers[0x11] = 0xC0U;
    dps310_registers[0x12] = 0x01U; // C1 = 1
    dps310_registers[0x13] = 0xFBU; // C00 = -20 000
    dps310_registers[0x14] = 0x1EU;
    dps310_registers[0x15] = 0x00U;
    dps310_registers[0x16] = 0x03U; // C10 = 1000
    dps310_registers[0x17] = 0xE8U;
    dps310_registers[0x18] = 0x07U; // C01 = 2000
    dps310_registers[0x19] = 0xD0U;
    dps310_registers[0x1A] = 0xFFU; // C11 = -250
    dps310_registers[0x1B] = 0x06U;
    dps310_registers[0x1C] = 0xFEU; // C20 = -350
    dps310_registers[0x1D] = 0xA2U;
    dps310_registers[0x1E] = 0x00U; // C21 = 5
    dps310_registers[0x1F] = 0x05U;
    dps310_registers[0x20] = 0x00U; // C30 = 10
    dps310_registers[0x21] = 0x0AU;
}

static void assert_on_write_error (const uint8_t reg, const uint8_t value)
{
    switch (reg)
    {
        case DPS310_PRES_CFG_REG:
            TEST_ASSERT (0U == (value & (~DPS310_PRES_CFG_WMASK)));
            break;

        case DPS310_TEMP_CFG_REG:
            TEST_ASSERT (0U == (value & (~DPS310_TEMP_CFG_WMASK)));
            break;

        case DPS310_MEAS_CFG_REG:
            TEST_ASSERT (0U == (value & (~DPS310_MEAS_CFG_WMASK)));
            break;

        case DPS310_CFG_REG:
            TEST_ASSERT (0U == (value & (~DPS310_CFG_WMASK)));
            break;

        case DPS310_RST_CFG_REG:
            TEST_ASSERT (0U == (value & (~DPS310_RST_CFG_WMASK)));
            break;

        case DPS310_EFUSE_0_REG:
            TEST_ASSERT ((DPS310_EFUSE_0_VAL == value) || (0 == value));
            efuse_writes++;
            break;

        case DPS310_EFUSE_1_REG:
            TEST_ASSERT ((DPS310_EFUSE_1_VAL == value) || (0 == value));
            efuse_writes++;
            break;

        case DPS310_EFUSE_2_REG:
            TEST_ASSERT ((DPS310_EFUSE_2_VAL == value));
            efuse_writes++;
            break;

        default:
            TEST_ASSERT (0U);
            break;
    }
}

static uint32_t get_meas_time_ms (const dps310_os_t os)
{
    uint32_t time = 0U;

    switch (os)
    {
        case DPS310_OS_1:
            time = 4U; // 3.6F to be exact
            break;

        default:
            break;
    }

    return time;
}

static dps310_os_t get_os_from_reg_val (const uint8_t val)
{
    dps310_os_t os =  DPS310_OS_INVALID;

    switch (val)
    {
        case 0:
            os = DPS310_OS_1;
            break;

        case 1:
            os = DPS310_OS_2;
            break;

        case 2:
            os = DPS310_OS_4;
            break;

        case 3:
            os = DPS310_OS_8;
            break;

        case 4:
            os = DPS310_OS_16;
            break;

        case 5:
            os = DPS310_OS_32;
            break;

        case 6:
            os = DPS310_OS_64;
            break;

        case 7:
            os = DPS310_OS_128;
            break;

        default:
            break;
    }

    return os;
}

static uint32_t get_temp_meas_time_ms (void)
{
    uint8_t temp_os_val = dps310_registers[DPS310_TEMP_CFG_REG] & DPS310_OS_MASK;
    dps310_os_t os =  get_os_from_reg_val (temp_os_val);
    return get_meas_time_ms (os);
}

static uint32_t get_pres_meas_time_ms (void)
{
    uint8_t pres_os_val = dps310_registers[DPS310_PRES_CFG_REG] & DPS310_OS_MASK;
    dps310_os_t os =  get_os_from_reg_val (pres_os_val);
    return get_meas_time_ms (os);
}


static void simulate_measurement_action (const uint8_t data)
{
    switch (data)
    {
        case DPS310_MODE_ONE_TEMP_VAL:
            drdy_ms += get_temp_meas_time_ms();
            // For OS 1 register value 0x7A1200 and C0 -100, C1 1 => -34.7412 C
            // scaled_raw 15.2587
            dps310_registers[DPS310_TEMP_VAL_REG] = 0x7AU;
            dps310_registers[DPS310_TEMP_VAL_REG + 1] = 0x12U;
            dps310_registers[DPS310_TEMP_VAL_REG + 2] = 0x00U;
            dps310_registers[DPS310_MEAS_CFG_REG] &= ~DPS310_MEAS_CFG_WMASK;
            break;

        case DPS310_MODE_ONE_PRES_VAL:
            drdy_ms += get_pres_meas_time_ms();
            // For OS 1 register value 0x7A1200 scaled_raw is 15.2587
            dps310_registers[DPS310_PRES_VAL_REG] = 0x7AU;
            dps310_registers[DPS310_PRES_VAL_REG + 1] = 0x12U;
            dps310_registers[DPS310_PRES_VAL_REG + 2] = 0x00U;
            dps310_registers[DPS310_MEAS_CFG_REG] &= ~DPS310_MEAS_CFG_WMASK;
            break;

        default:
            break;
    }
}

static void simulate_write_action (const uint8_t reg_addr, const uint8_t data)
{
    switch (reg_addr)
    {
        case DPS310_RST_CFG_REG:
            if (DPS310_SOFT_RST_VAL == (data & DPS310_SOFT_RST_MASK))
            {
                init_dps_regs();
                drdy_ms += DPS310_COEF_DELAY_MS;
                soft_resets++;
            }

            break;

        case DPS310_MEAS_CFG_REG:
            simulate_measurement_action (data);
            break;

        default:
            break;
    }
}

static void assert_on_read_error (void)
{
    TEST_ASSERT (time_ms >= drdy_ms);
}

static uint32_t mock_write (const void * const comm_ctx,
                            const uint8_t reg_addr,
                            const uint8_t * const data,
                            const uint8_t data_len)
{
    for (uint8_t ii = 0; ii < data_len; ii++)
    {
        assert_on_write_error (reg_addr + ii, data[ii]);
        dps310_registers[reg_addr + ii] = data[ii];
        simulate_write_action (reg_addr + ii, data[ii]);
    }

    return bus_code;
}

static void simulate_fifo_read (const uint8_t reg_addr)
{
    if ((DPS310_PRES_VAL_REG == reg_addr)
            && (DPS310_MODE_CONT_BOTH_VAL
                == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK)))
    {
        dps310_registers[DPS310_PRES_VAL_REG] = dps310_fifo_p4_t1[fifo_idx];
        dps310_registers[DPS310_PRES_VAL_REG + 1U] = dps310_fifo_p4_t1[fifo_idx + 1U];
        dps310_registers[DPS310_PRES_VAL_REG + 2U] = dps310_fifo_p4_t1[fifo_idx + 2U];
        fifo_idx += 3;
    }
}

static uint32_t mock_read (const void * const comm_ctx,
                           const uint8_t reg_addr,
                           uint8_t * const data,
                           const uint8_t data_len)
{
    for (uint8_t ii = 0; ii < data_len; ii++)
    {
        assert_on_read_error();

        if (0 == ii)
        {
            simulate_fifo_read (reg_addr);
        }

        data[ii] = dps310_registers[reg_addr + ii];
    }

    return bus_code;
}

static void mock_sleep (uint32_t ms)
{
    time_ms += ms;
}

static void reset_dps_ctx (dps310_ctx_t * const p_dps)
{
    //
    p_dps->device_status = DPS310_NOT_INITIALIZED;
    p_dps->product_id = 0;
    p_dps->revision_id = 0;
    //settings
    p_dps->temp_mr = 0;
    p_dps->temp_osr = 0;
    p_dps->pres_mr = 0;
    p_dps->pres_osr = 0;
    // compensation coefficients
    p_dps->c00 = 0;
    p_dps->c10 = 0;
    p_dps->c01 = 0;
    p_dps->c11 = 0;
    p_dps->c20 = 0;
    p_dps->c21 = 0;
    p_dps->c30 = 0;
    // last measured scaled temperature (necessary for pressure compensation)
    p_dps->last_temp_scal = 0;
}

static dps310_ctx_t dps =
{
    .sleep = &mock_sleep,
    .read  = &mock_read,
    .write = &mock_write
};

static const dps310_ctx_t dps_init_state =
{
    .sleep = &mock_sleep,
    .read  = &mock_read,
    .write = &mock_write
};

static void init_dps_coefs (void)
{
}

void setUp (void)
{
    rev_id = DPS310_PROD_ID_BOOT_VAL;
    init_dps_regs();
    init_dps_coefs();
    time_ms  = 0;
    drdy_ms  = DPS310_POR_DELAY_MS;;
    bus_code = 0;
    efuse_writes = 0;
    soft_resets = 0;
    fifo_idx = 0;
    reset_dps_ctx (&dps);
}

void tearDown (void)
{
    check_reserved_registers();
}

void test_dps310_init_ok (void)
{
    dps310_status_t err_code = dps310_init (&dps);
    TEST_ASSERT (0x00U == dps.product_id);
    TEST_ASSERT (0x01U == dps.revision_id);
    TEST_ASSERT (DPS310_MR_1 == dps.temp_mr);
    TEST_ASSERT (DPS310_OS_1 == dps.temp_osr);
    TEST_ASSERT (DPS310_MR_1 == dps.pres_mr);
    TEST_ASSERT (DPS310_OS_1 == dps.pres_osr);
    TEST_ASSERT (-100 == dps.c0);
    TEST_ASSERT (1 == dps.c1);
    TEST_ASSERT (-20000 == dps.c00);
    TEST_ASSERT (1000 == dps.c10);
    TEST_ASSERT (-350 == dps.c20);
    TEST_ASSERT (10 == dps.c30);
    TEST_ASSERT (2000 == dps.c01);
    TEST_ASSERT (-250 == dps.c11);
    TEST_ASSERT (5 == dps.c21);
    TEST_ASSERT (5U == efuse_writes);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MODE_MASK));
    TEST_ASSERT (1 == soft_resets);
    TEST_ASSERT (0U == dps310_registers[DPS310_EFUSE_0_REG]);
    TEST_ASSERT (0U == dps310_registers[DPS310_EFUSE_1_REG]);
    TEST_ASSERT (DPS310_EFUSE_2_VAL == dps310_registers[DPS310_EFUSE_2_REG]);
    TEST_ASSERT (time_ms >= (DPS310_POR_DELAY_MS + DPS310_COEF_DELAY_MS));
    TEST_ASSERT (DPS310_SUCCESS == err_code);
    TEST_ASSERT (DPS310_READY == dps.device_status);
}

void test_dps310_init_null (void)
{
    dps310_status_t err_code = dps310_init (NULL);
    TEST_ASSERT (DPS310_ERROR_NULL == err_code);
}

void test_dps310_init_invalid_ctx (void)
{
    dps310_ctx_t dps_null_all = { 0 };
    dps310_ctx_t dps_null_2 =
    {
        .sleep = &mock_sleep,
        .read  = NULL,
        .write = NULL
    };
    dps310_ctx_t dps_null_1 =
    {
        .sleep = &mock_sleep,
        .read  = &mock_read,
        .write = NULL
    };
    dps310_ctx_t dps_orig = { 0 };
    dps310_status_t err_code = dps310_init (&dps_null_all);
    TEST_ASSERT (DPS310_ERROR_NULL == err_code);
    TEST_ASSERT (!memcmp (&dps_null_all, &dps_orig, sizeof (dps310_ctx_t)));
    err_code = dps310_init (&dps_null_2);
    TEST_ASSERT (DPS310_ERROR_NULL == err_code);
    err_code = dps310_init (&dps_null_1);
    TEST_ASSERT (DPS310_ERROR_NULL == err_code);
}

void test_dps310_init_bus_error (void)
{
    bus_code = 11;
    dps310_status_t err_code = dps310_init (&dps);
    TEST_ASSERT ((DPS310_BUS_ERROR + bus_code) == err_code);
    TEST_ASSERT (DPS310_BUS_ERROR & dps.device_status);
}

void test_dps310_init_revision_error (void)
{
    rev_id = 0xFFU; // Invalid ID
    dps310_status_t err_code = dps310_init (&dps);
    TEST_ASSERT (DPS310_UNKNOWN_REV & err_code);
    TEST_ASSERT (DPS310_UNKNOWN_REV == dps.device_status);
}

void test_dps310_standby_ok (void)
{
    dps310_init (&dps);
    dps310_measure_continuous_async (&dps);
    dps310_status_t err_code = dps310_standby (&dps);
    TEST_ASSERT (DPS310_READY == dps.device_status);
    TEST_ASSERT (DPS310_SUCCESS == err_code);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
}

void test_dps310_standby_bus_error (void)
{
    dps310_init (&dps);
    bus_code = 11U;
    dps310_status_t err_code = dps310_standby (&dps);
    TEST_ASSERT ((DPS310_BUS_ERROR + bus_code) == err_code);
    TEST_ASSERT (DPS310_BUS_ERROR == dps.device_status);
}

void test_dps310_standby_not_init (void)
{
    dps310_status_t err_code = dps310_standby (&dps);
    TEST_ASSERT (DPS310_INVALID_STATE == err_code);
}

void test_dps310_standby_null (void)
{
    dps310_status_t err_code = dps310_standby (NULL);
    TEST_ASSERT (DPS310_ERROR_NULL == err_code);
}

void test_dps310_measure_temp_once_sync_ok (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -34.7412F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_1_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 15.2587F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
}

void test_dps310_measure_temp_once_sync_os_2 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_2);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 2
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -44.9137F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_2_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 5.086F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (1U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
}

void test_dps310_measure_temp_once_sync_os_4 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_4);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 4
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -47.8201F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_4_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 2.1798F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (2U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
}


void test_dps310_measure_temp_once_sync_os_8 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_8);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 8
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -48.9827F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_8_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 1.0172F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (3U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
    TEST_ASSERT (0U == (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_TEMPSH_MASK));
}


void test_dps310_measure_temp_once_sync_os_16 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_16);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 16
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -18.4979F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_16_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 31.5020F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (4U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_TEMPSH_MASK);
}


void test_dps310_measure_temp_once_sync_os_32 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_32);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 32
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -34.4990F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_32_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 15.5009F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (5U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_TEMPSH_MASK);
}

void test_dps310_measure_temp_once_sync_os_64 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_64);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 64
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -42.3105F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_64_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 7.6894F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (6U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_TEMPSH_MASK);
}

void test_dps310_measure_temp_once_sync_os_128 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_128);
    status |= dps310_measure_temp_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    // C0 -100, C1 1, tRAW 8 000 000, OS 64
    TEST_ASSERT_FLOAT_WITHIN (0.01F, -46.1703F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_128_TIME_MS));
    TEST_ASSERT_FLOAT_WITHIN (0.01F, 3.8296F, dps.last_temp_scal);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (7U == (dps310_registers[DPS310_TEMP_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_TEMPSH_MASK);
}

void test_dps310_measure_temp_once_sync_null (void)
{
    float result = 0;
    dps310_status_t status;
    status = dps310_measure_temp_once_sync (NULL, &result);
    TEST_ASSERT (DPS310_ERROR_NULL == status);
    dps310_init (&dps);
    status = dps310_measure_temp_once_sync (&dps, NULL);
    TEST_ASSERT (DPS310_ERROR_NULL == status);
}

void test_dps310_temp_coef_src_internal (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (0U == (dps310_registers[DPS310_TEMP_CFG_REG] & DPS310_COEF_SRC_MASK));
}

void test_dps310_temp_coef_src_external (void)
{
    dps310_init (&dps);
    dps310_registers[DPS310_COEF_SRC_REG] = DPS310_COEF_SRC_MASK;
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_COEF_SRC_MASK
                 == (dps310_registers[DPS310_TEMP_CFG_REG] & DPS310_COEF_SRC_MASK));
}

void test_dps310_measure_pres_once_sync_ok (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, -99495.603F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_1_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
}

void test_dps310_measure_pres_once_sync_null (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_measure_pres_once_sync (NULL, &result);
    TEST_ASSERT (DPS310_ERROR_NULL == status);
    status = dps310_measure_pres_once_sync (&dps, NULL);
    TEST_ASSERT (DPS310_ERROR_NULL == status);
}

void test_dps310_measure_pres_once_sync_os_2 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_2);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, 41681.403F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_2_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (1U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
}

void test_dps310_measure_pres_once_sync_os_4 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_4);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, 91530.439F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_4_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (2U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
}

void test_dps310_measure_pres_once_sync_os_8 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_8);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, 111980.16F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_8_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (3U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
    TEST_ASSERT (0U == (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_PRESSH_MASK));
}

void test_dps310_measure_pres_once_sync_os_16 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_16);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, -91732.592F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_16_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (4U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_PRESSH_MASK);
}

void test_dps310_measure_pres_once_sync_os_32 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_32);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, -101889.69F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_32_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (5U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_PRESSH_MASK);
}

void test_dps310_measure_pres_once_sync_os_64 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_64);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, -463.24456F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_64_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (6U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_PRESSH_MASK);
}

void test_dps310_measure_pres_once_sync_os_128 (void)
{
    float result = 0;
    // Setup measurement registers
    dps310_init (&dps);
    dps.last_temp_scal = 75.0F;
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_128);
    status |= dps310_measure_pres_once_sync (&dps, &result);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT_FLOAT_WITHIN (0.1F, 62951.915F, result);
    TEST_ASSERT (time_ms >= (INIT_TIME_MS + MEASURE_128_TIME_MS));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (7U == (dps310_registers[DPS310_PRES_CFG_REG] & 0x0FU));
    TEST_ASSERT (dps310_registers[DPS310_CFG_REG] & DPS310_CFG_PRESSH_MASK);
}

void test_dps310_config_pres_temp_os_m_16 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_pres (&dps, DPS310_MR_16, DPS310_OS_16);
    status = dps310_config_temp (&dps, DPS310_MR_16, DPS310_OS_16);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_MR_VAL_16 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                      DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_16 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                      DPS310_OS_MASK));
    TEST_ASSERT (DPS310_MR_VAL_16 == (dps310_registers[DPS310_TEMP_CFG_REG] &
                                      DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_16 == (dps310_registers[DPS310_TEMP_CFG_REG] &
                                      DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_both_ok (void)
{
    dps310_init (&dps);
    dps310_status_t status  = dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
}

void test_dps310_measure_continuous_async_temp_ok (void)
{
    dps310_init (&dps);
    dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    dps310_config_pres (&dps, DPS310_MR_NONE, DPS310_OS_1);
    dps310_status_t status  = dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_TEMP_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
}

void test_dps310_measure_continuous_async_pres_ok (void)
{
    dps310_init (&dps);
    dps310_config_temp (&dps, DPS310_MR_NONE, DPS310_OS_1);
    dps310_config_pres (&dps, DPS310_MR_1, DPS310_OS_1);
    dps310_status_t status  = dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_PRES_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
}

void test_dps310_measure_continuous_async_pres_mr_2 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_2, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_4 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_4, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_4 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_8 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_8, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_8 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_16 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_16, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_16 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                      DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_32 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_32, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_32 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                      DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_64 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_64, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_64 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                      DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_pres_mr_128 (void)
{
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_128, DPS310_OS_2);
    status |= dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_CONT_BOTH_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (DPS310_CONTINUOUS == dps.device_status);
    TEST_ASSERT (DPS310_MR_VAL_128 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                       DPS310_MR_MASK));
    TEST_ASSERT (DPS310_OS_VAL_2 == (dps310_registers[DPS310_PRES_CFG_REG] &
                                     DPS310_OS_MASK));
}

void test_dps310_measure_continuous_async_none_configured (void)
{
    dps310_init (&dps);
    dps310_config_temp (&dps, DPS310_MR_NONE, DPS310_OS_1);
    dps310_config_pres (&dps, DPS310_MR_NONE, DPS310_OS_1);
    dps310_status_t status  = dps310_measure_continuous_async (&dps);
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
    TEST_ASSERT (DPS310_INVALID_STATE == status);
    TEST_ASSERT (DPS310_READY == dps.device_status);
}

void test_dps310_get_continuous_results_ok (void)
{
    float temperature[32U] = {0};
    float pressure[32U] = {0};
    uint8_t pres_count = 32U;
    uint8_t temp_count = 32U;
    // Setup measurement registers
    dps310_init (&dps);
    dps310_status_t status = dps310_config_temp (&dps, DPS310_MR_1, DPS310_OS_1);
    status |= dps310_config_pres (&dps, DPS310_MR_4, DPS310_OS_1);
    status |= dps310_measure_continuous_async (&dps);
    status |= dps310_get_cont_results (&dps, temperature, &temp_count,
                                       pressure, &pres_count);
    TEST_ASSERT (DPS310_SUCCESS == status);
    TEST_ASSERT (6U == temp_count);
    TEST_ASSERT (26U == pres_count);
}

void test_dps310_get_last_result_ok (void)
{
    dps310_status_t dps_status;
    float temp;
    float pres;
    dps310_init (&dps);
    dps_status = dps310_get_last_result (&dps, &temp, &pres);
    TEST_ASSERT (DPS310_SUCCESS == dps_status);
}

void test_dps310_get_last_result_null (void)
{
    dps310_status_t dps_status;
    float temp;
    float pres;
    dps310_init (&dps);
    dps_status = dps310_get_last_result (NULL, &temp, &pres);
    TEST_ASSERT (DPS310_ERROR_NULL == dps_status);
    dps_status = dps310_get_last_result (&dps, NULL, &pres);
    TEST_ASSERT (DPS310_ERROR_NULL == dps_status);
    dps_status = dps310_get_last_result (&dps, &temp, NULL);
    TEST_ASSERT (DPS310_ERROR_NULL == dps_status);
}

void test_dps310_uninit (void)
{
    dps310_init (&dps);
    dps310_uninit (&dps);
    TEST_ASSERT (!memcmp (&dps_init_state, &dps, sizeof (dps310_ctx_t)));
    TEST_ASSERT (DPS310_MODE_STANDBY_VAL
                 == (dps310_registers[DPS310_MEAS_CFG_REG] & DPS310_MEAS_CFG_WMASK));
}