cmake_minimum_required(VERSION 3.25)
project(raia_luajit C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

#add_executable(raia_luajit
add_library(raia_luajit SHARED
        src/raia_luajit.c
)

target_link_libraries(raia_luajit
        $<$<PLATFORM_ID:Darwin>:  luajit-5.1>
        $<$<PLATFORM_ID:Linux>:   luajit-5.1>
        $<$<PLATFORM_ID:Windows>: luajit-5.1>
)

set_target_properties(raia_luajit PROPERTIES PREFIX "")
