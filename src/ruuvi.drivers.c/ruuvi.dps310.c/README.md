# ruuvi.dps310.c
MIT-licensed portable driver for Infineon DPS310 pressure and temperature sensor
[![Build Status](https://travis-ci.org/ruuvi/ruuvi.dps310.c.svg?branch=master)](https://travis-ci.org/ruuvi/ruuvi.dps310.c)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=alert_status)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=bugs)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=code_smells)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=coverage)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=ncloc)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)
[![Technical Debt](https://sonarcloud.io/api/project_badges/measure?project=ruuvi.dps310.c&metric=sqale_index)](https://sonarcloud.io/dashboard?id=ruuvi.dps310.c)

# Using the driver

The driver provides abstraction to register access in driver. You need to include dps310.h in your application, 
the header has functions for interacting with the sensor. 

Driver requires the user application to provide functions for reading and writing data on the bus as well as sleeping. 
The functions are provided through function pointers. 

## Interface functions

```
/**
 * @brief Sleep at least this many milliseconds.
 *
 * Function is allowed to sleep for longer, but not shorter time.
 */
typedef void (*dps310_sleep) (const uint32_t ms);

/**
 * @brief Read data from bus.
 *
 * If the read function returns non-zero value, it will get returned to caller in application.
 * Comm_ctx is given by application at dps310 initialization. Data is guaranteed to be non-NULL
 * and data_len is guaranteed to be non-zero.
 *
 * @param[in] comm_ctx A pointer to context for platform. E.g. I2C address or SPI SS pin. May be NULL.
 * @param[in] reg_addr Address of register to read.
 * @param[out] data Pointer to which data will be written. Must be data_len bytes long.
 * @param[in] data_len Length of data.
 * @retval 0 on success.
 * @return application error code on error. Bit DPS310_BUS_ERROR should be 0.
 */
typedef uint32_t (*dps310_read) (const void * const comm_ctx, const uint8_t reg_addr,
                                 uint8_t * const data, const uint8_t data_len);

/**
 * @brief Write data from bus.
 *
 * If the write function returns non-zero value, it will get returned to caller in application.
 * Comm_ctx is given by application at dps310 initialization. Data is guaranteed to be non-NULL
 * and data_len is guaranteed to be non-zero.
 *
 * @param[in] comm_ctx A pointer to context for platform. E.g. I2C address or SPI SS pin.
 * @param[in] reg_addr Address of register to write.
 * @param[in] data Pointer to which data will be written. Must be data_len bytes long.
 * @param[in] data_len Length of data.
 * @return 0 on success.
 * @return application error code on error. Bit DPS310_BUS_ERROR should be 0.
 */
typedef uint32_t (*dps310_write) (const void * const comm_ctx, const uint8_t reg_addr,
                                  const uint8_t * const data, const uint8_t data_len);
```

## Sample usage

```
int main(void)
{
  static platform_gpio_t spi_ss_pin = DPS310_SS;
  dps310_ctx_t dps = 
  {
    .sleep = &platform_sleep_function,
    .read  = &platform_read_function,
    .write = &platform_write_function,
    .comm_ctx = &platform_gpio_t // assuming SPI transfer needs only SS GPIO.
  };
  platform_spi_init();
  int32_t dps_error = dps310_init(&dps);

  // One high-precision temperature and pressure sample per second.
  if(DPS_SUCCESS == dps_error)
  {  
    dps_error = dps310_config_temp(&dps, DPS310_MR_1, DPS310_OS_64);
  }

  if(DPS_SUCCESS == dps_error)
  {  
    dps_error = dps310_config_pres(&dps, DPS310_MR_1, DPS310_OS_64);
  }

  if(DPS_SUCCESS == dps_error)
  {  
    dps_error = dps310_measure_continuous_async(&dsp310);
  }

  // As long as no error is detected, print sensor values
  while(DPS310_SUCCESS == dps_error)
  {
    platform_sleep_function(1000); // Sleep for 1000 ms
    float temp[2];
    float pres[2];
    uint8_t num_measurements = 2;
    // Read up to 2 measurements from DPS FIFO
    dps_error = dps310_get_cont_results(&dps, temp, pres, &num_measurements);
    // Print results from FIFO
    for(uint8_t ii = 0; ii < num_measurements; ii++)
    {
        // Temperature resolution of 0.01 C, pressure resolution 0.02 Pa
        printf("Temperature: %.2f Celcius. Pressure: %.1f Pascals", temp[ii], pres[ii]);
    }

  }
  dps310_uninit(&dps); // Try to uninit sensor after error.
  return dps_error;
}
```

## Features

 - [X] Single temperature and pressure measurement with and without oversampling.
 - [X] Synchronous (get result on return) and asynchronous (measure now, get result later) operation.
 - [X] Continuous temperature and pressure measurement
 - []  FIFO, with independent measurement rates
 - [] Interrupts

# Running unit tests
## Ceedling
Unit tests are implemented with Ceedling. Run the tests with
`ceedling test:all`

### Gcov
Ceedling can also generate Gcov reports with `ceedling gcov:all utils:gcov`.
The report can be foun under _build/artifacts/gcov_.

# Code style
Code shall be formatted with Artistic Style using .astylerc in project root as the
ruleset.
```
astyle --project=.astylerc --recursive "./src/*.c" "./src/*.h" "./test/*.c"
```

# Static code analysis
Run `make` to run PVS Studio on project. Report can be found at _doxygen/pvs/fullhtml/index.html_.
[Here](./fullhtml/index.html) is a link to documentation through Doxygen-generated documentation.

# Documentation
Run `make` to generate Doxygen docs with git version information. 

# Continuous integration pipeline
The project is built on Travis and build status is reflected on a badge on top of the 
header. SonarCloud generates additional analytics and badges for the project.

GitHub actions run Artistic Style and PVS Studio as well as publishes the Doxygen to [GitHub Pages](https://ruuvi.github.io/ruuvi.dps310.c/).
PVS Studio HTML-report can be found [under documentation](https://ruuvi.github.io/ruuvi.dps310.c/fullhtml).

# Using the project as a template. 
If you wish to use this project as a template for your own project, checkout tag v0.1.0
and change the project name and file names and setup the continuous integration pipeline
for the project.