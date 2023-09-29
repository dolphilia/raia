cmake_minimum_required(VERSION 3.26)
project(raia_c_dlfcn C)

include(../../../setting.cmake)

#include_directories(${PROJECT_SOURCE_DIR}/../../../thirdparty/c)
#include_directories(${PROJECT_SOURCE_DIR}/../../../share/c)
#link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_c_dlfcn SHARED
        src/raia_c_dlfcn.c
        ../../../thirdparty/c/ibireme/yyjson.c
        ../../../share/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_c_dlfcn PROPERTIES PREFIX "")