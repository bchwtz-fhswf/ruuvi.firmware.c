![build](https://github.com/bchwtz-fhswf/ruuvi.firmware.c/workflows/CI/badge.svg?branch=master)
# ruuvi.firmware.c by FH-SWF
## Submodules
You can just run `make pull`.  
If you do not have make installed you will need to proceed with these steps:  
Run `git submodule update --init --recursive`. This will search for and install the other git repositories referenced by this project. If any of the submodules has a changed remote, you'll need to run `git submodule sync --recursive` and again `git submodule update --init --recursive` to update the modules from new remotes. 
# Using the build-toolchain inside docker (recommended way)
## Prerequisites
### Linux
Install the docker package for your distribution and add your user to the "docker"-group. That's it - you're all set!  

### Windows and MacOS
You have to install Docker Desktop for your OS. If you are running Windows, please make shure WSL-2 is enabled. It will improve speed tremendously. If you are running MacOS, please make shure to provide a lot of RAM and CPU to your VM, so the Docker-build will be able to use your system's resources properly.  

## Building the firmware
Building the firmware is just basically one command. Your artifacts will be placed in src/targets/ruuvitag_b/arm_gcc/
### Linux, Git-Bash for Windows and MacOS (recommended)
`bash ./docker_build.sh`  
### Windows
`.\docker_build.bat`  

## Flashing the firmware
Flash the firmware via bluetooth after pressing and holding the boot-button of your Ruuvitag for at least 10 seconds. You will need to use the nrf connect app to flash the device.

# Development
## Setting up the toolchain locally and use whatever ide you like (linux and mac only)
Make shure you have all basic tools installed (e.g. built-essential).
Please refer to [the old readme](README-local-setup.md) for further information.

### Prerequisites:
You need the following tools:  
* build-essentials (either via brew or your favorite linux package manager)
* gcc-arm-none-eabi-7 ([Get this here](https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2?revision=bc2c96c0-14b5-4bb4-9f18-bceb4050fee7?product=GNU%20Arm%20Embedded%20Toolchain%20Downloads,64-bit,,Linux,7-2018-q2-update))
* pvs-studio

### Building and running natively on Linux and MacOS
* `make pull`
* `make build-and-run`
* [Nordic SDK 15.3](https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/)

## Using Segger Embedded Studio (SES)
Segger Embedded Studio can be set up by installing [nRF Connect for Desktop](https://www.nordicsemi.com/?sc_itemid=%7BB935528E-8BFA-42D9-8BB5-83E2A5E1FF5C%7D) 
and following Getting Started plugin instructions.

Start SES and open `ruuvi_ruuvi.firmware.c.emProject` at root level, each of the target boards is in their own project.
Segger Studio Builds are not DFU-capable. Please run all release builds via the docker toolchain.
