cmake_minimum_required(VERSION 3.25)
project(raia_sdk C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_sdk SHARED src/library.c src/duktape/duktape.c)

set_target_properties(raia_sdk PROPERTIES PREFIX "")