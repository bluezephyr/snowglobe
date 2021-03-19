add_library(snow
    snow.c
    snow.h
    )

target_include_directories(snow PUBLIC .)
target_include_directories(snow PRIVATE ${BITLOOM_CORE}/include)
target_include_directories(snow PRIVATE ${BITLOOM_DRIVERS}/include)
target_include_directories(snow PRIVATE ${BITLOOM_CONFIG})

