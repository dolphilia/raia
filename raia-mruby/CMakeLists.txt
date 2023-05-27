cmake_minimum_required(VERSION 3.25)
project(raia_mruby C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_mruby SHARED
        src/raia_mruby.c
        )

target_link_libraries(raia_mruby "-lmruby")

set_target_properties(raia_mruby PROPERTIES PREFIX "")