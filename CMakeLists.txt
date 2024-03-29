cmake_minimum_required(VERSION 3.12)

project(snowglobe C ASM)
set(CMAKE_C_STANDARD 99)

# BITLOOM_CORE must be set to where the bitloom-core repo is located
set(BITLOOM_CORE "${CMAKE_CURRENT_SOURCE_DIR}/bitloom-core")

# BITLOOM_HAL needs to be set in order for the project to build correctly.
# For AVR, this is currently set in the toolchain file.

# BITLOOM_CONFIG should be set to the directory containing the configuration
# for the project's target environment as well as the processor specifics.
set(BITLOOM_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG})

# CUTIL is a library containing common c utilities.  CUTIL needs to be set.
set(CUTIL "${CMAKE_CURRENT_SOURCE_DIR}/cutil")

# BITLOOM_DRIVERS contains implementation of drivers for different peripherals
# that can be used in BitLoom products.
set(BITLOOM_DRIVERS ${CMAKE_CURRENT_SOURCE_DIR}/bitloom-drivers)

# Output BitLoom specific folders
message(STATUS "CMAKE SOURCE: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "BITLOOM_HAL: ${BITLOOM_HAL}")
message(STATUS "BITLOOM_CONFIG: ${BITLOOM_CONFIG}")
message(STATUS "CMAKE_CROSSCOMPILING: ${CMAKE_CROSSCOMPILING}")

# Make sure that all required variables have been set
if (NOT BITLOOM_HAL)
    message(FATAL_ERROR "BITLOOM_HAL directory not specified.")
endif(NOT BITLOOM_HAL)

if (NOT CONFIG)
    message(FATAL_ERROR "CONFIG directory not specified.")
endif(NOT CONFIG)

# Use the cross-compile version of add_executable defined in the toolchain
cc_add_executable(snowglobe src/main.c)

# The following directory includes the project specific configurations
# Hence it needs to be available for all targets.
include_directories(${BITLOOM_CONFIG})

add_subdirectory(bitloom-core/src/scheduler libs/core/scheduler)
add_subdirectory(bitloom-core/src/uart libs/core/uart)
add_subdirectory(${BITLOOM_HAL}/src/timer libs/hal/timer)
add_subdirectory(${BITLOOM_HAL}/src/pin_digital_io libs/hal/pin_digital_io)
add_subdirectory(${BITLOOM_HAL}/src/uart_hal libs/hal/uart_hal)
add_subdirectory(${BITLOOM_HAL}/src/i2c libs/hal/i2c)
add_subdirectory(${BITLOOM_CONFIG}/config libs/config)
add_subdirectory(${BITLOOM_DRIVERS}/src/ssd1306 drivers/ssd1306)
add_subdirectory(${BITLOOM_DRIVERS}/src/graphics drivers/graphics)
add_subdirectory(${CUTIL}/src/bytebuffer libs/bytebuffer)
add_subdirectory(src/blinktask libs/blinktask)
add_subdirectory(src/snow libs/snow)

cc_target_link_libraries(snowglobe blinktask)
cc_target_link_libraries(snowglobe snow)
cc_target_link_libraries(snowglobe scheduler)
cc_target_link_libraries(snowglobe uart)
cc_target_link_libraries(snowglobe timer)
cc_target_link_libraries(snowglobe pin_digital_io)
cc_target_link_libraries(snowglobe uart_hal)
cc_target_link_libraries(snowglobe config)
cc_target_link_libraries(snowglobe bytebuffer)
cc_target_link_libraries(snowglobe i2c)
cc_target_link_libraries(snowglobe ssd1306)
cc_target_link_libraries(snowglobe graphics)
