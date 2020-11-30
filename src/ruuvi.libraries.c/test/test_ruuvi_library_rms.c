#include "unity.h"

#include "ruuvi_library_rms.h"

#include <math.h>

void setUp (void)
{
}

void tearDown (void)
{
}


const float nan_test_vector[] = {0.0F, 1.0F, -1.0F, NAN, 25.0F};
const float valid_test_vector[] = {0.0F, 1.0F, -1.0F, 50.0F, 25.0F};
const float vtv_rms = 25.0079987204F;

/**
 * @brief Calculate the RMS of a given sample set.
 *
 *
 * @param data[in] Pointer to floats with values to check
 * @param data_length[in] Number of values
 * @return RMS of values, NAN if any of given values is NAN or input parameters are invalid
 */
void test_ruuvi_library_rms_ok (void)
{
    float result = rl_rms (valid_test_vector,
                           sizeof (valid_test_vector) / sizeof (valid_test_vector[0]));
    TEST_ASSERT_EQUAL_FLOAT (vtv_rms, result);
}

void test_ruuvi_library_rms_zero_len (void)
{
    float result = rl_rms (valid_test_vector, 0);
    TEST_ASSERT (isnan (result));
}

void test_ruuvi_library_rms_null (void)
{
    float result = rl_rms (NULL, sizeof (valid_test_vector));
    TEST_ASSERT (isnan (result));
}

void test_ruuvi_library_rms_nan_input (void)
{
    float result = rl_rms (nan_test_vector,
                           sizeof (nan_test_vector) / sizeof (nan_test_vector[0]));
    TEST_ASSERT (isnan (result));
}