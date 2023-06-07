cmake_minimum_required(VERSION 3.25)
project(raia_lua C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_lua SHARED
        src/raia_lua.c
        src/lua/lapi.c
        src/lua/lauxlib.c
        src/lua/lbaselib.c
        src/lua/lcode.c
        src/lua/lcorolib.c
        src/lua/lctype.c
        src/lua/ldblib.c
        src/lua/ldebug.c
        src/lua/ldo.c
        src/lua/ldump.c
        src/lua/lfunc.c
        src/lua/lgc.c
        src/lua/linit.c
        src/lua/liolib.c
        src/lua/llex.c
        src/lua/lmathlib.c
        src/lua/lmem.c
        src/lua/loadlib.c
        src/lua/lobject.c
        src/lua/lopcodes.c
        src/lua/loslib.c
        src/lua/lparser.c
        src/lua/lstate.c
        src/lua/lstring.c
        src/lua/lstrlib.c
        src/lua/ltable.c
        src/lua/ltablib.c
        src/lua/ltm.c
        src/lua/lua.c
        src/lua/luac.c
        src/lua/lundump.c
        src/lua/lutf8lib.c
        src/lua/lvm.c
        src/lua/lzio.c
        src/list/list.c
        src/list/list_iterator.c
        src/list/list_node.c
        src/static/static_func_hash.c
        src/util/util_file.c
        src/static/static_plugin_loader.c
        src/yyjson/yyjson.c
        )

set_target_properties(raia_lua PROPERTIES PREFIX "")
