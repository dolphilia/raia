cmake_minimum_required(VERSION 3.27)
project(luau)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(luau main.cpp)

target_link_libraries(luau
        $<$<PLATFORM_ID:Darwin>: Luau.VM Luau.Compiler Luau.Ast Luau.CodeGen>
        $<$<PLATFORM_ID:Linux>: >
        $<$<PLATFORM_ID:Windows>: >
)
