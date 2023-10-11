cmake_minimum_required(VERSION 3.26)
project(raia_cpp_dlfcn)

include(${PROJECT_SOURCE_DIR}/../../../setting.cmake)

set(CMAKE_CXX_STANDARD 17)

#add_executable(raia_cpp_dlfcn
add_library(raia_cpp_dlfcn SHARED
        src/raia_cpp_dlfcn.cpp)
