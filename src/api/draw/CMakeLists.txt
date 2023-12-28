#
# 新しいCmakeを使うように
# OpenMPに対応したGCCを使うように
#

cmake_minimum_required(VERSION 3.26.4)
project(raia_draw C)
#set(CMAKE_C_COMPILER "gcc")

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)


find_package(OpenMP REQUIRED)

if(NOT OpenMP_C_FOUND)
    message(FATAL_ERROR "OpenMP not found")
endif()

# CUDAアーキテクチャをターゲットにする場合のフラグを設定
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp-targets=nvptx64-nvidia-cuda")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
#add_compile_options(-fopenmp)

add_library(raia_draw SHARED
        src/raia_draw.c
        src/util/util_math.c
        src/util/util_pixel.c
        src/util/util_primitive3d.c
        src/util/util_utf8.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c
)

set_target_properties(raia_draw PROPERTIES PREFIX "")