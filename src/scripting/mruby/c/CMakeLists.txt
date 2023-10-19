cmake_minimum_required(VERSION 3.25)
project(raia_mruby C)

include(${PROJECT_SOURCE_DIR}/../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_mruby SHARED
        src/raia_mruby.c
        ../../../common/c/utility/util_file.c
        ../../../third_party/c/ibireme/yyjson/yyjson.c
        ../../../common/c/static/static_func_hash.c
        ../../../common/c/static/static_plugin_hash.c
        ../../../common/c/wrapper/wrapper_yyjson.c
        )

target_link_libraries(raia_mruby
        $<$<PLATFORM_ID:Darwin>: mruby>
        $<$<PLATFORM_ID:Linux>: mruby>
        $<$<PLATFORM_ID:Windows>: mruby wsock32 ws2_32>
        )

set_target_properties(raia_mruby PROPERTIES PREFIX "")