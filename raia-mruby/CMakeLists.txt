cmake_minimum_required(VERSION 3.25)
project(raia_mruby C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/
        $<$<PLATFORM_ID:Darwin>: ${PROJECT_SOURCE_DIR}/lib/macos>
        $<$<PLATFORM_ID:Linux>: ${PROJECT_SOURCE_DIR}/lib/linux>
        $<$<PLATFORM_ID:Windows>: ${PROJECT_SOURCE_DIR}/lib/windows>
        )

set(CMAKE_C_STANDARD 11)

add_library(raia_mruby SHARED
        src/raia_mruby.c
        )

target_link_libraries(raia_mruby
        $<$<PLATFORM_ID:Darwin>: mruby>
        $<$<PLATFORM_ID:Linux>: "-lmruby">
        $<$<PLATFORM_ID:Windows>: "-lmruby" "-lwsock32" "-lws2_32">
        )

set_target_properties(raia_mruby PROPERTIES PREFIX "")