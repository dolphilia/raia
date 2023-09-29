cmake_minimum_required(VERSION 3.25)
project(raia_duktape C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_duktape SHARED
        src/raia_duktape.c
        src/util/util_file.c
        src/duktape/duktape.c
        src/duktape-module/duk_module_duktape.c
        src/static/static_func_hash.c
        src/static/static_plugin_hash.c
        src/static/static_entrust.c
        src/static/static_entrust.h
        ../../../thirdparty/c/ibireme/yyjson.c
        ../../../share/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_duktape PROPERTIES PREFIX "")