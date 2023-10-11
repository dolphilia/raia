cmake_minimum_required(VERSION 3.24)
project(raia_draw C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_draw SHARED
        src/raia_draw.c
        src/duktape/duktape.c src/util/util_math.c src/util/util_pixel.h src/util/util_pixel.c src/stb/stb_image.c src/wrapper/wrapper_stb_image.c)
