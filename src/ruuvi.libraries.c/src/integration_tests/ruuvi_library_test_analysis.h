/**
 * @file test_analysis.h
 * @author Otso Jousimaa
 * @date 2019-01-24
 * @brief Function for testing analysis functions.
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * Run tests for analysis functions.
 */
#ifndef RUUVI_LIBRARY_TEST_ANALYSIS_H
#define RUUVI_LIBRARY_TEST_ANALYSIS_H
#include <float.h>
#include <stdbool.h>

/** @defgroup analysis Analysis
 *  Functions to analyze signals without HW dependencies.
 */
/**
 * @ingroup test_library
 * @defgroup test_analysis Analysis tests
 *  Functions to test analysis functions for correctness.
 *  @{
 */
#define RLT_P2P_OK_VECTOR       {0.02f, 0.05f, -0.01f, -0.10f, 0.0f}
#define RLT_P2P_OK_EXPECT       (0.15f)
#define RLT_P2P_OK_DECIMALS     (2)
#define RLT_P2P_NAN_VECTOR      {0.02f, 0.05f, NAN, -0.10f, 0.0f}
#define RLT_P2P_OVERFLOW_VECTOR {0.02f, 0.05f, FLT_MAX, 0-FLT_MAX, 0.0f}

/**
 * @brief Tests if peak-to-peak value is calculated correctly on valid data.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_peak2peak_ok (void);

/**
 * @brief Tests if peak-to-peak is reported as NAN if series contains NAN.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_peak2peak_nan (void);

/**
 * @brief Tests if peak-to-peak value is reported as NAN if float overflows.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_peak2peak_overflow (void);

/**
 * @brief Tests if peak-to-peak returns NAN on invalid input arguments
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_peak2peak_input_check (void);

#define RLT_RMS_OK_VECTOR       {0.02f, 0.05f, -0.01f, -0.10f, 0.0f}
#define RLT_RMS_OK_EXPECT       (0.051f)
#define RLT_RMS_OK_DECIMALS     (3)
#define RLT_RMS_NAN_VECTOR      {0.02f, 0.05f, NAN, -0.10f, 0.0f}
#define RLT_RMS_OVERFLOW_VECTOR {0.02f, 0.05f, FLT_MAX, 0-FLT_MAX, 0.0f}

/**
 * @brief Tests if rms value is calculated correctly on valid data.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_rms_ok (void);

/**
 * @brief Tests ifrms is reported as NAN if series contains NAN.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_rms_nan (void);

/**
 * @brief Tests ifrms value is reported as NAN if float overflows.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_rms_overflow (void);

/**
 * @brief Tests if rms returns NAN on invalid input arguments
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_rms_input_check (void);

#define RLT_VARIANCE_OK_VECTOR       {0.02f, 0.05f, -0.01f, -0.10f, 0.0f}
#define RLT_VARIANCE_OK_EXPECT       (0.0025)
#define RLT_VARIANCE_OK_DECIMALS     (4)
#define RLT_VARIANCE_NAN_VECTOR      {0.02f, 0.05f, NAN, -0.10f, 0.0f}
#define RLT_VARIANCE_OVERFLOW_VECTOR {0.02f, 0.05f, FLT_MAX, 0-FLT_MAX, 0.0f}

/**
 * @brief Tests if variance value is calculated correctly on valid data.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_variance_ok (void);

/**
 * @brief Tests if variance is reported as NAN if series contains NAN.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_variance_nan (void);

/**
 * @brief Tests if variance value is reported as NAN if float overflows.
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_variance_overflow (void);

/**
 * @brief Tests if variance returns NAN on invalid input arguments
 *
 * @return True if yes, false if not. True is "pass" value.
 */
bool rl_test_variance_input_check (void);

/** @} */ // End of group Analysis tests
#endif