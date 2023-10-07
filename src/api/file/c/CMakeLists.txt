cmake_minimum_required(VERSION 3.25)
project(raia_file C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_file SHARED
        src/raia_file.c
        ../../../common/c/utility/util_file.c
        ../../../third_party/c/ibireme/yyjson/yyjson.c
        ../../../common/c/wrapper/wrapper_yyjson.c)

target_link_libraries(raia_file
        $<$<PLATFORM_ID:Darwin>: m>
        $<$<PLATFORM_ID:Linux>: m>
        #$<$<PLATFORM_ID:Windows>: >
        )

set_target_properties(raia_file PROPERTIES
        PREFIX "")

#-- test

enable_testing()

add_executable(test_raia_file test/test.c)
add_test(NAME UnitTest COMMAND test_raia_file)