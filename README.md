# Snowglobe

A digital snowglobe based on the BitLoom platform.

## ARM Cortex-M port (Bluepill)

The HAL for the ARM Cortex-M is available in the `bluepill-cmsis` submodule.
The configuration is available in the `config/bluepill_config` folder.

### Build for ARM

Follow the steps below to build for ARM. It is assumed that the cross
compilation toolchain is installed in the `/opt/gcc-arm` folder. For
instructions how to flash to target, see the `bluepill-cmsis` submodule README.

1. mkdir build
1. cd build
1. cmake -DCMAKE_PREFIX_PATH=/opt/gcc-arm -DCMAKE_TOOLCHAIN_FILE=../bluepill-cmsis/cmake/arm-none-eabi.cmake -DCONFIG=config/bluepill_config ..
1. make

## Configuration

The configuration of the snowglobe software is done in two different locations.
Board specific parameters, such as clock configuration and peripherals are
located in the target specific submodule. See, for example, the `bluepill-cmsis`
submodule for the Bluepill specific parts. Parameters that are specific for the
application and the specifics for the hardware in the application are located in
the config folder in this repository.

### ARM Cortex-M port (Bluepill)

The following Bluepill application specific configuration are located in the
config folder.

#### GPIO

APB2 peripheral clock for PORTB and PORTC is enabled.

The User LED mounted on the board and connected to PC13 is enabled as General
Purpose output push-pull. Note that the LED is active low.

I2C1 is used for the I2C communication. PB6 is configured as SCL and PB7 is
configured as SDA.
