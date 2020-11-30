#include "ruuvi_library_enabled_modules.h"
#if RL_INTEGRATION_TEST_ENABLED
#include "ruuvi_library_test.h"
#include "ruuvi_library_test_analysis.h"
#include "ruuvi_library_ringbuffer_test.h"
#include "ruuvi_library_compress_test.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Run peak to peak tests
 *
 * @param[in, out] total Total number of tests which have been run. Gets incremented.
 * @param[in, out] passed Total number of tests which have passed. Gets incremented.
 */
static void rl_test_peak2peak (uint32_t * const total_tests,
                               uint32_t * const passed, const rl_test_print_fp printfp)
{
    bool pass = false;
    printfp ("\"peak2peak\":{\r\n");
    printfp ("\"valid_data\":");
    (*total_tests)++;
    pass = rl_test_peak2peak_ok();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"nan_data\":");
    (*total_tests)++;
    pass = rl_test_peak2peak_nan();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"overflow_fpu_errors\":\"");
    (*total_tests)++;
    pass = rl_test_peak2peak_overflow();
    (*passed) += pass;
    printfp ("\",\r\n");
    printfp ("\"overflow_data\":");
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"input_validation\":");
    (*total_tests)++;
    pass = rl_test_peak2peak_input_check();
    (*passed) += pass;
    pass ? printfp ("\"pass\"\r\n") : printfp ("\"fail\"\r\n");
    printfp ("}");
}

/**
 * @brief Run root mean square tests
 *
 * @param[in, out] total Total number of tests which have been run. Gets incremented.
 * @param[in, out] passed Total number of tests which have passed. Gets incremented.
 */
static void rl_test_rms (uint32_t * const total_tests, uint32_t * const passed,
                         const rl_test_print_fp printfp)
{
    bool pass = false;
    printfp ("\"rms\":{\r\n");
    printfp ("\"valid_data\":");
    (*total_tests)++;
    pass = rl_test_rms_ok();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    (*total_tests)++;
    printfp ("\"nan_data\":");
    pass = rl_test_rms_nan();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    (*total_tests)++;
    printfp ("\"overflow_fpu_errors\":\"");
    pass = rl_test_rms_overflow();
    (*passed) += pass;
    printfp ("\",\r\n");
    printfp ("\"overflow_data\":");
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    (*total_tests)++;
    printfp ("\"input_validation\":");
    pass = rl_test_rms_input_check();
    (*passed) += pass;
    pass ? printfp ("\"pass\"\r\n") : printfp ("\"fail\"\r\n");
    printfp ("}");
}

/**
 * @brief Run variance tests
 *
 * @param[in, out] total Total number of tests which have been run. Gets incremented.
 * @param[in, out] passed Total number of tests which have passed. Gets incremented.
 */
static void rl_test_variance (uint32_t * const total_tests,
                              uint32_t * const passed, const rl_test_print_fp printfp)
{
    bool pass = false;
    printfp ("\"variance\":{\r\n");
    printfp ("\"valid_data\":");
    (*total_tests)++;
    pass = rl_test_variance_ok();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"nan_data\":");
    (*total_tests)++;
    pass = rl_test_variance_nan();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"overflow_fpu_errors\":\"");
    (*total_tests)++;
    pass = rl_test_variance_overflow();
    (*passed) += pass;
    printfp ("\",\r\n");
    printfp ("\"overflow_data\":");
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"input_validation\":");
    (*total_tests)++;
    pass = rl_test_variance_input_check();
    (*passed) += pass;
    pass ? printfp ("\"pass\"\r\n") : printfp ("\"fail\"\r\n");
    printfp ("}");
}

/**
 * @brief Run Ringbuffer tests
 *
 * @param[in, out] total Total number of tests which have been run. Gets incremented.
 * @param[in, out] passed Total number of tests which have passed. Gets incremented.
 */
static void rl_test_ringbuffer (uint32_t * const total_tests,
                                uint32_t * const passed, const rl_test_print_fp printfp)
{
    bool pass = false;
    printfp ("\"ringbuffer\":{\r\n");
    printfp ("\"put_get\":");
    (*total_tests)++;
    pass = rl_test_ringbuffer_put_get();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"overflow\":");
    (*total_tests)++;
    pass =  rl_test_ringbuffer_overflow();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"overdrain\":");
    (*total_tests)++;
    pass =  rl_test_ringbuffer_underflow();
    (*passed) += pass;
    pass ? printfp ("\"pass\"\r\n") : printfp ("\"fail\"\r\n");
    printfp ("}");
}

#if RL_LIBLZF_ENABLED || DOXYGEN
/**
 * @brief Run compress tests
 *
 * @param[in, out] total Total number of tests which have been run. Gets incremented.
 * @param[in, out] passed Total number of tests which have passed. Gets incremented.
 */
static void rl_test_compress (uint32_t * const total_tests,
                              uint32_t * const passed, const rl_test_print_fp printfp)
{
    bool pass = false;
    printfp ("\"liblzf\":{\r\n");
    printfp ("\"compress_decompress\":");
    (*total_tests)++;
    pass = rl_test_compress_decompress();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    printfp ("\"decompress_twice\":");
    (*total_tests)++;
    pass = rl_test_compress_decompress_2_times();
    (*passed) += pass;
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    (*total_tests)++;
    pass = rl_test_compress_decompress_ratio (printfp);
    (*passed) += pass;
    printfp ("\"compress_ratio_test\":");
    pass ? printfp ("\"pass\",\r\n") : printfp ("\"fail\",\r\n");
    (*total_tests)++;
    printfp ("\"invalid_input\":");
    pass = rl_test_invalid_input();
    (*passed) += pass;
    pass ? printfp ("\"pass\"\r\n") : printfp ("\"fail\"\r\n");
    printfp ("}");
}
#endif

bool rl_test_all_run (const rl_test_print_fp printfp)
{
    uint32_t total_tests = 0;
    uint32_t passed = 0;
    rl_test_peak2peak (&total_tests, &passed, printfp);
    printfp (",\r\n");
    rl_test_rms (&total_tests, &passed, printfp);
    printfp (",\r\n");
    rl_test_variance (&total_tests, &passed, printfp);
    printfp (",\r\n");
    rl_test_ringbuffer (&total_tests, &passed, printfp);
    printfp (",\r\n");
#if RL_LIBLZF_ENABLED
    rl_test_compress (&total_tests, &passed, printfp);
    printfp (",\r\n");
#endif
    char msg[128] = {0};
    snprintf (msg, sizeof (msg), "\"total_tests\":\"%lu\",\r\n\"passed_tests\":\"%lu\"\r\n",
              total_tests, passed);
    printfp (msg);
    return (total_tests == passed);
}

bool rl_expect_close (const float expect, const int8_t precision,
                      const float check)
{
    if (!isfinite (expect) || !isfinite (check)) { return false; }

    const float max_delta = pow (10, -precision);
    float delta = fabs (expect - check);
    return max_delta > delta;
}

#endif
