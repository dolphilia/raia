cmake_minimum_required(VERSION 3.25)
project(raia_file C CXX)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)


add_library(raia_file SHARED
        src/raia_file.c
        ../../common/c/utility/util_file.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c)

target_link_libraries(raia_file
        $<$<PLATFORM_ID:Darwin>: m>
        $<$<PLATFORM_ID:Linux>: m>
        #$<$<PLATFORM_ID:Windows>: >
        )

set_target_properties(raia_file PROPERTIES
        PREFIX "")

#-- test

enable_testing()

add_executable(test_raia_file
        test/test.cpp
        src/raia_file.c
        ../../common/c/utility/util_file.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c)

#target_link_libraries(test_raia_file fmt)

add_test(NAME UnitTest COMMAND test_raia_file)