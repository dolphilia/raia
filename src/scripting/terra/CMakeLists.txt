cmake_minimum_required(VERSION 3.25)
project(raia_terra C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

#add_executable(raia_luajit
add_library(raia_terra SHARED
        src/raia_luajit.c
        #src/tinycthread.c
)

target_link_libraries(raia_terra
        $<$<PLATFORM_ID:Darwin>:  luajit-5.1.2.1.1725453128 terra uv>
        $<$<PLATFORM_ID:Linux>:   luajit-5.1>
        $<$<PLATFORM_ID:Windows>: luajit-5.1>
)

set_target_properties(raia_terra PROPERTIES PREFIX "")
