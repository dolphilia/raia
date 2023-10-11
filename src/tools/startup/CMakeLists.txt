cmake_minimum_required(VERSION 3.24)
project(raia_core C)

set(CMAKE_C_STANDARD 11)

add_executable(raia_core
        src/raia-core.c
        src/raia-core.h
        src/duktape/duktape.h
        src/duktape/duktape.c
        src/duktape/duk_config.h
        src/static/static_duk_ctx.c
        src/static/static_duk_ctx.h
        src/static/static_plugin_loader.c
        src/static/static_plugin_loader.h
        src/wrapper/wrapper_duktape.c
        src/wrapper/wrapper_duktape.h
        src/util/util_io.c
        src/util/util_io.h
        src/meta/platform.h
        src/raia/raia_duktape.c
        src/raia/raia_duktape.h
        src/duktape-module/duk_module_duktape.c
        src/duktape-module/duk_module_duktape.h
        src/list/list.c
        src/list/list_iterator.c
        src/list/list_node.c
        src/util/util_dir.c
        src/util/util_dir.h
        src/meta/version.h
        src/whereami/whereami.c
        src/whereami/whereami.h
        src/wrapper/wrapper_whereami.c
        src/static/static_arg.c
        src/static/static_arg.h src/util/util_string.c src/util/util_string.h)

target_link_libraries(raia_core m)