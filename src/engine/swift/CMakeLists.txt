cmake_minimum_required(VERSION 3.20)
project(SwiftCIntegration LANGUAGES C Swift)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

# Swiftコンパイラにブリッジヘッダを指定
set(CMAKE_Swift_FLAGS "${CMAKE_Swift_FLAGS} -import-objc-header ${CMAKE_SOURCE_DIR}/bridging-header.h")

# C言語コードをライブラリとしてビルド
add_library(cfunc STATIC cfunc.c)
target_include_directories(cfunc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Swiftの実行ファイルを作成し、C側のライブラリとリンク
add_executable(main 
    src/main.swift
    src/glfw/_namespace.swift
    src/glfw/initializer.swift
    src/glfw/window.swift
)

target_link_libraries(main PRIVATE cfunc glfw.3.4 raia_glfw)
