/**
 * @file ruuvi_library_rms.h
 * @author Otso Jousimaa
 * @date 2019-01-24
 * @brief Function for calculating RMS amplitude of a signal sample.
 * @copyright Copyright 2019 Ruuvi Innovations.
 *   This project is released under the BSD-3-Clause License.
 *
 * Calculate the RMS of a signal
 */

#ifndef RUUVI_LIBRARY_RMS_H
#define RUUVI_LIBRARY_RMS_H
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
 * @brief Calculate the RMS of a given sample set.
 *
 *
 * @param data[in] Pointer to floats with values to check
 * @param data_length[in] Number of values
 * @return RMS of values, NAN if any of given values is NAN or input parameters are invalid
 */
float rl_rms (const float * const data, const size_t data_length);

/** @} */ // End of group analysis
#endif