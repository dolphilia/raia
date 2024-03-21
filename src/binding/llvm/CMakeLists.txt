cmake_minimum_required(VERSION 3.13)
project(raia_llvm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_executable(raia_llvm src/raia_llvm.cpp)

# 必要なLLVMコンポーネントを指定
llvm_map_components_to_libnames(llvm_libs support core irreader executionengine mcjit interpreter AArch64AsmParser AArch64CodeGen AArch64TargetInfo)

target_link_libraries(raia_llvm ${llvm_libs})