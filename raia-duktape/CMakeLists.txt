cmake_minimum_required(VERSION 3.25)
project(raia_duktape C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_duktape SHARED
        src/raia_duktape.c
        src/parson/parson.c
        src/util/util_file.c
        src/list/list.c
        src/list/list_iterator.c
        src/list/list_node.c
        src/duktape/duktape.c
        src/duktape-module/duk_module_duktape.c
        src/static/static_func_hash.c
        src/static/static_plugin_loader.c)

set_target_properties(raia_duktape PROPERTIES PREFIX "")