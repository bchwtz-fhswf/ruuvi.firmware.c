// See header file for copyright etc.

#include "ruuvi_library_peak2peak.h"
#include <float.h>
#include <math.h>

float rl_peak2peak (const float * const data, const size_t data_length)
{
    if (NULL == data || 0 == data_length) { return NAN; }

    float min = FLT_MAX;
    float max = FLT_MIN;

    for (size_t ii = 0; ii < data_length; ii++)
    {
        if (!isfinite (data[ii])) { return NAN; }

        if (data[ii] < min) { min = data[ii]; }

        if (data[ii] > max) { max = data[ii]; }
    }

    float result = max - min;

    if (!isfinite (result)) { return NAN; }

    return result;
}