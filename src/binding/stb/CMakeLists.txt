cmake_minimum_required(VERSION 3.26)
project(raia_stb C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

#include_directories(${PROJECT_SOURCE_DIR}/../../../thirdparty/c)
#include_directories(${PROJECT_SOURCE_DIR}/../../../share/c)
#link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_stb SHARED
        src/raia_stb_image.c
        src/raia_stb_image_write.c
        stb/stb_image_write.c
        stb/stb_image.c
)

#set_target_properties(raia_stb PROPERTIES PREFIX "")