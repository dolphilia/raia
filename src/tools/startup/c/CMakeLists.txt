cmake_minimum_required(VERSION 3.24)
project(raia_startup C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_executable(raia_startup
        src/raia-startup.c
        ../../../third_party/c/ibireme/yyjson/yyjson.c
)

enable_testing()

add_executable(raia_test test/test.c)
add_test(NAME MyTest COMMAND raia_test)

set_target_properties(raia_startup PROPERTIES PREFIX "")