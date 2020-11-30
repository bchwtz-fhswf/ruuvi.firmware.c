// See header file for copyright etc.

#include "ruuvi_library_rms.h"
#include <float.h>
#include <math.h>

float rl_rms (const float * const data, const size_t data_length)
{
    float rvalue = NAN;

    if (NULL == data || 0 == data_length) { return NAN; }

    float delta_sum = 0;
    float mean = 0;

    // Calculate squares.
    for (size_t ii = 0; ii < data_length; ii++)
    {
        if (!isfinite (data[ii])) { return NAN; }

        delta_sum += powf (data[ii], 2);
    }

    // Calculate mean
    mean = delta_sum / data_length;

    if (!isfinite (delta_sum)) { return NAN; }

    // root
    rvalue = sqrtf (mean);
    return rvalue;
}