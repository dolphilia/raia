cmake_minimum_required(VERSION 3.20)
project(SwiftCIntegration LANGUAGES C Swift)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

# Swiftコンパイラにブリッジヘッダを指定
set(CMAKE_Swift_FLAGS "${CMAKE_Swift_FLAGS} -import-objc-header ${CMAKE_SOURCE_DIR}/bridging-header.h")

# C言語コードをライブラリとしてビルド
add_library(wrapper STATIC wrapper.c)
target_include_directories(wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Swiftの実行ファイルを作成し、C側のライブラリとリンク
add_executable(main 
    src/main.swift

    src/glfw/glfw___namespace.swift
    src/glfw/glfw__const.swift
    src/glfw/glfw__function.swift
    src/glfw/glfw__typealias.swift
    src/glfw/glfw_context.swift
    src/glfw/glfw_corsor.swift
    src/glfw/glfw_initializer.swift
    src/glfw/glfw_input.swift
    src/glfw/glfw_monitor.swift
    src/glfw/glfw_system.swift
    src/glfw/glfw_time.swift
    src/glfw/glfw_window.swift

    src/gles/gles___namespace.swift
    src/gles/gles__const.swift
    src/gles/gles__function.swift
)

target_link_libraries(main PRIVATE wrapper glfw.3.4 raia_glfw egl GLESv2 raia_gles)
