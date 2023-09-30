cmake_minimum_required(VERSION 3.26)
project(raia_image C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_image SHARED
        src/raia_image.c
        src/wrapper/wrapper_stb_image.c
        src/wrapper/wrapper_lodepng.c
        src/wrapper/wrapper_lodepng.h
        ../../../thirdparty/c/lvandeve/lodepng/lodepng.c
        ../../../thirdparty/c/nothings/stb/stb_image.c
        ../../../thirdparty/c/ibireme/yyjson/yyjson.c
        ../../../share/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_image PROPERTIES PREFIX "")