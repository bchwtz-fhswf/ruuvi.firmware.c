# ruuvi.c.firmware - FH-Südwestfalen-Fork
# Setting up
## Prerequisites
## SDK 15.3
Download [Nordic SDK15.3](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/) and install it at the project root.
If you're working on multiple nRF projects, you can (and should) use softlinking instead.

## Submodules
Run `git submodule update --init --recursive`. This will search for and install the other git repositories referenced by this project. If any of the submodules has a changed remote, you'll need to run `git submodule sync --recursive` and again `git submodule update --init --recursive` to update the modules from new remotes. 

## Toolchain
ARMGCC is used for [Jenkins builds](http://jenkins.ruuvi.com/job/ruuvi.firmware.c/), it's recommended to use SES for developing. You can make the project and all variants by runnning "make" at top level of this repository. 
 
Segger Embedded Studio can be set up by installing [nRF Connect for Desktop](https://www.nordicsemi.com/?sc_itemid=%7BB935528E-8BFA-42D9-8BB5-83E2A5E1FF5C%7D) 
and following Getting Started plugin instructions.

Start SES and open `ruuvi_ruuvi.firmware.c.emProject` at root level, each of the target boards is in their own project.

## Code style
Code is formatted with [Artistic Style](http://astyle.sourceforge.net). 
Run `astyle --project=.astylerc ./target_file`. To format the entire project,
```
astyle --project=.astylerc "src/main.c"
astyle --project=.astylerc --recursive "src/application_config/*.h"
astyle --project=.astylerc --recursive "src/tasks/*.c"
astyle --project=.astylerc --recursive "src/tasks/*.h"
astyle --project=.astylerc --recursive "src/tests/*.c"
astyle --project=.astylerc --recursive "src/tests/*.h"
```

## Static analysis
The code can be checked with PVS Studio and Sonarcloud for some common errors, style issues and potential problems. [Here](https://ruuvi.github.io/ruuvi.firmware.c/fullhtml/index.html) is a link to generated report which gets pushed to GitHub.


### PVS
Obtain license and software from [Viva64](https://www.viva64.com/en/pvs-studio/).

Make runs PVS Studio scan and outputs results under doxygen/html/fullhtml. 

This results into hundreds of warnings, it is up to you to filter the data you're interested in. For example you probably want to filter out warnings related to 64-bit systems. 

### Sonar scan
Travis pushes the results to [SonarCloud.IO](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.firmware.c).
SonarCloud uses access token which is private to Ruuvi, you'll need to fork the project and setup
the SonarCloud under your own account if you wish to run Sonar Scan on your own code.

# Running unit tests
## Ceedling
Unit tests are implemented with Ceedling. Run the tests with
`ceedling test:all`

### Gcov
Ceedling can also generate Gcov reports with `ceedling gcov:all utils:gcov`.
The report can be found under _build/artifacts/gcov_.

## Unit test continuous integration
Travis will fail the build if unit test fails and Gcov results will get pushed to SonarCloud.

# Usage
Compile and flash the project to your board using SES. Instructions on how to use a bootloader will be added later on.
The project is not yet in a useful state for any practical purpose other than learning. 

Note: You should erase your board entirely in case there is a bootloader from a previous firmware.

# How to contribute
Please let us know your thoughts on the direction and structure of the project. Does the project help you to understand how to build code on RuuviTag?
Is the structure of the project sensible to you? 

If you want to assist in the project maintenance by fixing some issues _doxygen.error_ is
a good place to look for code which needs better commenting. Project badges at the top of the
readme point to issues which range from trivial clarifications to complex refactoring. 

If you want to add new features, please discuss the feature first, and then create ceedling
unit tests for the functionality. Once the functionality is agreed and testable in can be integrated
into project.

# Licensing
Ruuvi code is BSD-3 licensed. Submodules and external dependencies have their own licenses, which are BSD-compatible.

# Documentation
Document is generated with Doxygen. Run `make doxygen` to generate the docs locally, or
browse to [Travis built docs](https://ruuvi.github.io/ruuvi.firmware.c)

# Unix Builds via gcc and Makefile
## Prerequisites:
You need the following tools:  
* build-essentials (either via brew or your favorite linux package manager)
* gcc-arm-none-eabi-7 ([Get this here](https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2?revision=bc2c96c0-14b5-4bb4-9f18-bceb4050fee7?product=GNU%20Arm%20Embedded%20Toolchain%20Downloads,64-bit,,Linux,7-2018-q2-update))

## Building natively:
* `cd src`
* `make ruuvitag_b`
  
The binaries may be found in src/targets/ruuvitag_b/armgcc as hex-files.

# Memory error at build
In case you get in Segger this error message section .uicr_bootloader_start_address VMA [0000000000000ff8,0000000000000ffb] overlaps section .reserved_flash_sd VMA [0000000000000000,0000000000025fff] by trying to build under windows. You can define the memory space on your own. Search for the flash placement files under ses, e.g. ruuvi.firmware.c\nRF5_SDK_15.3.0_59ac345\config\nrf52811\ses and change the 4th line to this: ProgramSection load="no" name=".reserved_flash" start="$(FLASH_PH_START)+0x1000" size="$(FLASH_START)-$(FLASH_PH_START)-0x1000" 

# docker build
## Prerequisites
* Install docker onto your system (either package or Docker Desktop)
* Tag the latest commit by using `git tag 1.0.0` - note: 1.0.0 is just a placeholder
## Build
To build this project using docker, just execute the docker_build.bat file on windows or if you are using Linux or MacOS you just use the docker_build.sh file. Make shure you have bash installed on your MacOS or Linux system.
You will then find a zip-file which contains all of the binaries in your src/targets/ruuvitab_b/armgcc folder.

## Flash
You may either use Segger-Studio or nrfjprog to flash your new firmware to your device. The corresponding command on Linux or MacOS is:  
`cd src`  
`make -j 16 ruuvitag_b && make flash`  
  
On Windows please consider to use any bash emulator like GIT-Bash. The builds are OTA-capable.