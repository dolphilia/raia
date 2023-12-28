cmake_minimum_required(VERSION 3.26)
project(raia_font C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_font SHARED src/raia_font.c
        src/util/util_pixel.c
        src/util/util_utf8.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c
        )

set_target_properties(raia_font PROPERTIES PREFIX "")