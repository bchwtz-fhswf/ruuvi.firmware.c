# ruuvi.boards.c
Ruuvi board definitions. Has pinouts of Ruuvi boards as well as default configuration for some peripherals.
In alpha stage, not recommended for any use yet.

# Versioning
Project has semantic versioning. Any patch update is a bugfix, minor update is a backwards compatible addition
and major update breaks backwards compatibility.

# How to contribute
Open an issue or pull request at GitHub.

# Licensing
BSD-3

# Changelog
## 3.4.0 
 - Support Gateway A2

## 0.8.1
 - Add definitions for button actions, e.g. enable_configuration, change_mode.
 - Add led state indication definitions, e.g. button_pressed.

## 0.8.0
 - Define available space as "small, medium, large" instead of absolute page number.

## 0.7.2
 - Fix RuuviTag B LIS2 interrupt pins

## 0.7.1
 - Add default definitions

## 0.7.0
 - Support using repository as ESP component
 - Add ESP GW pin definitions

## 0.6.2
 - Add support for PA/LNA on Gateway 

## 0.6.1
 - Add support for USB/UART Interface MCU on PCA10040

## 0.6.0 
 - Add support for PCA10040, PCA10056E, RuuviGW nRF

## 0.5.0 
 - Add support Bootloader BSP glue logic

## 0.4.0
 - Convert active states to arrays on Kaarle, Kalervo

## 0.3.4
 - Fix Rauno LED polarity

## 0.3.3
 - Add Rauno to inclusion list

## 0.3.2
 - Fix semver

## 0.3.1
 - Add button power pin definitions

## 0.3.0
 - Refactor RUUVI_BOARD -> RB in naming

## 0.2.0
 - Add "Rauno"

## 0.1.0 
 - Signal alpha status

## 3.3.0
Add semantic versioning string or automated checking.

## 3.0.0 ... 3.2.0
Alpha versions, do not use for anything.
