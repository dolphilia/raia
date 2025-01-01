cmake_minimum_required(VERSION 3.10)
project(Binding_AppKit)

set(SOURCES window.c)

add_executable(Binding_AppKit ${SOURCES})

# C言語の標準を設定
set_target_properties(Binding_AppKit PROPERTIES
        C_STANDARD 99
        C_STANDARD_REQUIRED YES
)

# 必要なフレームワークとライブラリをリンク
target_link_libraries(Binding_AppKit
        "-framework Cocoa"
        "-lobjc"
)