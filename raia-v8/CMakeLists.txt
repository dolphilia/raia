cmake_minimum_required(VERSION 3.25)
project(raia_v8)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " ")

# -DV8_COMPRESS_POINTERS
# -DV8_ENABLE_SANDBOX

add_library(raia_v8 SHARED
#add_executable(raia_v8
        src/raia_v8.cpp src/yyjson/yyjson.c src/wrapper/wrapper_yyjson.c src/util/util_file.c src/static/static_func_hash.c src/static/static_plugin_hash.c src/static/static_entrust.c src/tomlc99/toml.c)

add_compile_options(-pthread)

#clang++ -I. -Iinclude samples/hello-world.cc -o hello_world -Lout.gn/arm64.release.sample/obj/  -std=c++17

target_link_libraries(raia_v8 "-fno-rtti" "-luv" "-lv8_monolith" "-lv8_libbase" "-lv8_libplatform" "-ldl")

set_target_properties(raia_v8 PROPERTIES PREFIX "")