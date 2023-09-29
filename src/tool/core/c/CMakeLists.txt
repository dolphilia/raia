enable_testing()

cmake_minimum_required(VERSION 3.24)
project(raia_core C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_executable(raia_core
        src/raia-core.c
        ../../../thirdparty/c/ibireme/yyjson.c
)

# ctest
add_executable(my_test test/test.c)
add_test(NAME MyTest COMMAND my_test)

set_target_properties(raia_core PROPERTIES PREFIX "")