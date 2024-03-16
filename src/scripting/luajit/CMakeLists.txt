cmake_minimum_required(VERSION 3.25)
project(raia_luajit C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")

#add_executable(raia_luajit
add_library(raia_luajit SHARED
        src/raia_luajit.c
        ../../common/c/utility/util_file.c
        ../../common/c/static/shared_library_loader.c
        ../../common/c/wrapper/wrapper_yyjson.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/static/static_args_hash.c
        ../../common/c/wrapper/wrapper_ffi.c
)

target_link_libraries(raia_luajit
        $<$<PLATFORM_ID:Darwin>: ffi luajit-5.1>
        $<$<PLATFORM_ID:Linux>: ffi luajit-5.1>
        $<$<PLATFORM_ID:Windows>: ffi luajit-5.1>
)

set_target_properties(raia_luajit PROPERTIES PREFIX "")
