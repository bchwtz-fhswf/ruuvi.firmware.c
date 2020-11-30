/**
 * @file ruuvi_library_peak2peak.h
 * @author Otso Jousimaa
 * @date 2019-01-24
 * @brief Function for finding peak to peak amplitude of a signal sample.
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * Calculate the difference between lowest and highest value in given sample set.
 */

#ifndef RUUVI_LIBRARY_VARIANCE_H
#define RUUVI_LIBRARY_VARIANCE_H
#include <math.h>
#include <stdlib.h>
/// @cond 0
#ifndef NAN
error "NAN is not defined"
#endif
/// @endcond

/** @ingroup analysis
 *  @{
 */
/**
 * @brief Calculate the variance of a given sample set.
 *
 *
 * @param data[in] Pointer to floats with values
 * @param data_length[in] Number of values
 * @return Variance of samples, NAN if any of given values is NAN or input parameters are invalid
 */
float rl_variance (const float * const data, const size_t data_length);

/** @} */ // End of group analysis
#endif