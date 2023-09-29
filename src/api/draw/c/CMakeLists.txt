#
# 新しいCmakeを使うように
# OpenMPに対応したGCCを使うように
#

cmake_minimum_required(VERSION 3.26.4)
project(raia_draw C)
#set(CMAKE_C_COMPILER "gcc")

include(../../../setting.cmake)

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
        src/util/util_pixel.h
        src/util/util_pixel.c
        src/stb/stb_image.c
        src/wrapper/wrapper_stb_image.c
        src/lodepng/lodepng.c
        src/util/util_primitive3d.c
        src/util/util_primitive3d.h
        src/wrapper/wrapper_stb_truetype.c
        src/wrapper/wrapper_stb_truetype.h
        src/util/util_utf8.c
        src/util/util_utf8.h
        src/stb/stb_truetype.h
        src/raia_draw.h
        ../../../thirdparty/c/ibireme/yyjson.c
        ../../../share/c/wrapper/wrapper_yyjson.c)

set_target_properties(raia_draw PROPERTIES PREFIX "")