cmake_minimum_required(VERSION 3.24)
project(raia_engine C)

include(../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_executable(raia_engine
        ../../third_party/c/ibireme/yyjson/yyjson.c
        src/raia-startup.c
)

set_target_properties(raia_engine PROPERTIES PREFIX "")

#-- test

enable_testing()
add_executable(test_raia_startup test/test.c)
add_test(NAME MyTest COMMAND test_raia_startup)