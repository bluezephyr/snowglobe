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
