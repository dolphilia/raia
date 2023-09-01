cmake_minimum_required(VERSION 3.25)
project(raia_v8)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "")

if(WIN32)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")
    add_definitions("-DNOMINMAX -DV8_ENABLE_SYSTEM_INSTRUMENTATION")
    # todo: for zlib, need to extract zlib when refactor
    add_definitions("-DX86_WINDOWS")
    add_definitions("-D_WIN32_WINNT=0x0602")
    add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)
endif()

# -DV8_COMPRESS_POINTERS
# -DV8_ENABLE_SANDBOX

add_library(raia_v8 SHARED
#add_executable(raia_v8
        src/raia_v8.cpp
        src/yyjson/yyjson.c
        src/wrapper/wrapper_yyjson.c
        src/util/util_file.c
        src/static/static_func_hash.c
        src/static/static_plugin_hash.c
        src/static/static_entrust.c
        src/tomlc99/toml.c
        src/typescript/typescript.cpp
        src/wrapper/wrapper_v8.cpp
        src/static/static_raia_config.cpp)

add_compile_options(-pthread -fno-rtti)

#clang++ -I. -Iinclude samples/hello-world.cc -o hello_world -Lout.gn/arm64.release.sample/obj/  -std=c++17

target_link_libraries(raia_v8
        $<$<PLATFORM_ID:Darwin>: "-fno-rtti" "-luv" "-lv8_monolith" "-lv8_libbase" "-lv8_libplatform" "-ldl" >
        $<$<PLATFORM_ID:Linux>: >
        $<$<PLATFORM_ID:Windows>: v8_monolith winmm dbghelp >
        )

#set_target_properties(raia_v8 PROPERTIES PREFIX "")