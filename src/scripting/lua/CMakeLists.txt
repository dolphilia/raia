cmake_minimum_required(VERSION 3.25)
project(raia_lua)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

#set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "")

add_executable(raia_lua
#add_library(raia_lua SHARED
        src/raia_lua.cpp
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
        #src/lua/luac.c
        src/lua/lundump.c
        src/lua/lutf8lib.c
        src/lua/lvm.c
        src/lua/lzio.c
        src/list/list.c
        src/list/list_iterator.c
        src/list/list_node.c
        ../../common/c/utility/util_file.c
        ../../common/c/static/shared_library_loader.c
        ../../common/c/wrapper/wrapper_yyjson.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/static/static_args_hash.c
        ../../common/c/wrapper/wrapper_ffi.c
)

target_link_libraries(raia_lua
        $<$<PLATFORM_ID:Darwin>: ffi>
        $<$<PLATFORM_ID:Linux>: ffi>
        $<$<PLATFORM_ID:Windows>: ffi>
)

set_target_properties(raia_lua PROPERTIES PREFIX "")
