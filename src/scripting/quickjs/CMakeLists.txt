cmake_minimum_required(VERSION 3.27)
project(raia_quickjs C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

# add_library(raia_lua SHARED
add_executable(raia_quickjs
        main.c
)

target_link_libraries(raia_quickjs
        $<$<PLATFORM_ID:Darwin>: quickjs>
        $<$<PLATFORM_ID:Linux>: quickjs>
        $<$<PLATFORM_ID:Windows>: quickjs>
)

set_target_properties(raia_quickjs PROPERTIES PREFIX "")