/**
* @file ruuvi_library_enabled_modules.h
* @author Otso Jousimaa <otso@ojousima.net>
* @date 2020-06-22
* @copyright Ruuvi Innovations Ltd, license BSD-3-Clause.
* @brief Header to enable and disable module compilation.
*
* Use this header to select which libraries will be included in project.
*
* By default everything is disabled to save resources, application should
* have "app_config.h" which is in the include search path.
* If application has configuration, define
* APPLICATION_LIBRARIES_CONFIGURED 1 in preprocessor.
*/

#ifndef RUUVI_DRIVER_ENABLED_MODULES_H
#define RUUVI_DRIVER_ENABLED_MODULES_H

#ifdef APPLICATION_DRIVER_CONFIGURED
#include "app_config.h"
#endif

#ifdef CEEDLING
#  define ENABLE_DEFAULT 1
#elif defined(DOXYGEN)
#  define ENABLE_DEFAULT 1
#elif defined(RUUVI_RUN_TESTS)
#  define ENABLE_DEFAULT 1
#else
#  define ENABLE_DEFAULT 0
#endif

#ifndef RL_INTEGRATION_TEST_ENABLED
#   define RL_INTEGRATION_TEST_ENABLED ENABLE_DEFAULT
#endif

#ifndef RL_LIBLZF_ENABLED
#   define RL_LIBLZF_ENABLED 0
#endif

#endif