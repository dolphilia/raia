cmake_minimum_required(VERSION 3.20)
project(SwiftCIntegration LANGUAGES C Swift)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../../../sdk/macos/arm64/include/skia)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

# Swiftコンパイラにブリッジヘッダを指定
set(CMAKE_Swift_FLAGS "${CMAKE_Swift_FLAGS} -import-objc-header ${CMAKE_SOURCE_DIR}/bridging-header.h")

# C言語コードをライブラリとしてビルド
add_library(wrapper STATIC
    wrapper/cglm_wrapper.c
    wrapper/glfw_wrapper.c
    wrapper/noise.c
)
target_include_directories(wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Swiftの実行ファイルを作成し、C側のライブラリとリンク
add_executable(main 
    src/main.swift

    src/game/__game_namespace.swift
    src/game/_game_rendererprotocol.swift
    src/game/_game_struct.swift
    src/game/_game_typealias.swift
    src/game/game_renderer2d.swift
    src/game/game_renderer3d.swift
    src/game/game_window.swift

    src/glfw/__glfw_namespace.swift
    src/glfw/_glfw_const.swift
    src/glfw/_glfw_function.swift
    src/glfw/_glfw_typealias.swift
    src/glfw/glfw_corsor.swift
    src/glfw/glfw_initializer.swift
    src/glfw/glfw_input.swift
    src/glfw/glfw_monitor.swift
    src/glfw/glfw_system.swift
    src/glfw/glfw_time.swift
    src/glfw/glfw_window.swift

    src/gles/__gles_namespace.swift
    src/gles/_gles_const.swift
    src/gles/_gles_function.swift
    src/gles/_gles_helper.swift
)

target_link_libraries(main PRIVATE wrapper glfw.3.4 raia_glfw egl GLESv2 raia_gles cglm)
