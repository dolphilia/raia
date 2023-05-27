cmake_minimum_required(VERSION 3.24)
project(raia_core C)

set(CMAKE_C_STANDARD 11)

add_executable(raia_core
        src/raia-core.c
        src/yyjson/yyjson.c)

target_link_libraries(raia_core)

set_target_properties(raia_core PROPERTIES PREFIX "")