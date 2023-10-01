cmake_minimum_required(VERSION 3.24)
project(raia_sound C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_sound SHARED
        src/raia_sound.c
        src/util/util_math.h
        src/util/util_math.c
        )

target_link_libraries(raia_sound
        $<$<PLATFORM_ID:Darwin>: "-framework OpenAL">
        $<$<PLATFORM_ID:Linux>: >
        $<$<PLATFORM_ID:Windows>: >
        )

set_target_properties(raia_sound PROPERTIES PREFIX "")