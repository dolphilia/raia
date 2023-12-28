cmake_minimum_required(VERSION 3.26)
project(raia_image C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_image SHARED
        src/raia_image.c
        src/wrapper/wrapper_stb_image.c
        src/wrapper/wrapper_lodepng.c
        src/wrapper/wrapper_lodepng.h
        ../../third_party/c/lvandeve/lodepng/lodepng.c
        ../../third_party/c/nothings/stb/stb_image.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_image PROPERTIES PREFIX "")