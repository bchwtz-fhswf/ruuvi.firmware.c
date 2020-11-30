#include "ruuvi_library_enabled_modules.h"
#if RL_INTEGRATION_TEST_ENABLED
#include "ruuvi_library_test.h"
#include "ruuvi_library_test_analysis.h"
#include "ruuvi_library_peak2peak.h"
#include "ruuvi_library_rms.h"
#include "ruuvi_library_variance.h"
#include <math.h>

bool rl_test_peak2peak_ok (void)
{
    float vector[] = RLT_P2P_OK_VECTOR;
    float p2p = 0;
    p2p = rl_peak2peak (vector, sizeof (vector) / sizeof (float));
    return rl_expect_close (RLT_P2P_OK_EXPECT, RLT_P2P_OK_DECIMALS, p2p);
}

bool rl_test_peak2peak_nan (void)
{
    float vector[] = RLT_P2P_NAN_VECTOR;
    float p2p = 0;
    p2p = rl_peak2peak (vector, sizeof (vector) / sizeof (float));
    return isnan (p2p);
}

bool rl_test_peak2peak_overflow (void)
{
    float vector[] = RLT_P2P_OVERFLOW_VECTOR;
    float p2p = 0;
    p2p = rl_peak2peak (vector, sizeof (vector) / sizeof (float));
    return isnan (p2p);
}

bool rl_test_peak2peak_input_check (void)
{
    float vector[] = RLT_P2P_OK_VECTOR;
    float t1 = 0;
    float t2 = 0;
    t1 = rl_peak2peak (NULL, 5);
    t2 = rl_peak2peak (vector, 0);
    return isnan (t1) && isnan (t2);
}


bool rl_test_rms_ok (void)
{
    float vector[] = RLT_RMS_OK_VECTOR;
    float rms = 0;
    rms = rl_rms (vector, sizeof (vector) / sizeof (float));
    return rl_expect_close (RLT_RMS_OK_EXPECT, RLT_RMS_OK_DECIMALS, rms);
}

bool rl_test_rms_nan (void)
{
    float vector[] = RLT_RMS_NAN_VECTOR;
    float rms = 0;
    rms = rl_rms (vector, sizeof (vector) / sizeof (float));
    return isnan (rms);
}

bool rl_test_rms_overflow (void)
{
    float vector[] = RLT_RMS_OVERFLOW_VECTOR;
    float rms = 0;
    rms = rl_rms (vector, sizeof (vector) / sizeof (float));
    return isnan (rms);
}

bool rl_test_rms_input_check (void)
{
    float vector[] = RLT_RMS_OK_VECTOR;
    float t1 = 0;
    float t2 = 0;
    t1 = rl_rms (NULL, 5);
    t2 = rl_rms (vector, 0);
    return isnan (t1) && isnan (t2);
}


bool rl_test_variance_ok (void)
{
    float vector[] = RLT_VARIANCE_OK_VECTOR;
    float variance = 0;
    variance = rl_variance (vector, sizeof (vector) / sizeof (float));
    return rl_expect_close (RLT_VARIANCE_OK_EXPECT, RLT_VARIANCE_OK_DECIMALS,
                            variance);
}

bool rl_test_variance_nan (void)
{
    float vector[] = RLT_VARIANCE_NAN_VECTOR;
    float variance = 0;
    variance = rl_variance (vector, sizeof (vector) / sizeof (float));
    return isnan (variance);
}

bool rl_test_variance_overflow (void)
{
    float vector[] = RLT_VARIANCE_OVERFLOW_VECTOR;
    float variance = 0;
    variance = rl_variance (vector, sizeof (vector) / sizeof (vector[0]));
    return isnan (variance);
}

bool rl_test_variance_input_check (void)
{
    float vector[] = RLT_VARIANCE_OK_VECTOR;
    float t1 = 0;
    float t2 = 0;
    t1 = rl_variance (NULL, 5);
    t2 = rl_variance (vector, 0);
    return isnan (t1) && isnan (t2);
}
#endif