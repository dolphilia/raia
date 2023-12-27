cmake_minimum_required(VERSION 3.25)
project(raia_duktape C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_duktape SHARED
        src/raia_duktape.c
        src/duktape/duktape.c
        src/duktape-module/duk_module_duktape.c
        ../../common/c/utility/util_file.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/static/static_func_hash.c
        ../../common/c/static/static_plugin_hash.c
        ../../common/c/static/static_entrust.c
        ../../common/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_duktape PROPERTIES PREFIX "")