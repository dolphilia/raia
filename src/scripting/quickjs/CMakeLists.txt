cmake_minimum_required(VERSION 3.27)
project(raia_quickjs C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

#add_library(raia_quickjs SHARED
add_executable(raia_quickjs
        src/raia_quickjs.c
        ../../common/c/static/shared_library_loader.c
        ../../common/c/static/shared_library_loader.h
        ../../common/c/static/static_args_hash.c
        ../../common/c/wrapper/wrapper_ffi.c
)

target_link_libraries(raia_quickjs
        $<$<PLATFORM_ID:Darwin>: quickjs ffi>
        $<$<PLATFORM_ID:Linux>: quickjs ffi>
        $<$<PLATFORM_ID:Windows>: quickjs ffi>
)

set_target_properties(raia_quickjs PROPERTIES PREFIX "")