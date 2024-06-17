cmake_minimum_required(VERSION 3.25)
project(raia_gles C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)

add_library(raia_gles SHARED
#add_executable(raia_gles
        src/raia_gles.c
        ../../third_party/c/ibireme/yyjson/yyjson.c
        ../../common/c/wrapper/wrapper_yyjson.c)

target_link_libraries(raia_gles
        $<$<PLATFORM_ID:Darwin>: egl GLESv2>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

# 現在のRPATH設定を取得（もしあれば）
get_property(CURRENT_RPATH TARGET raia_gles PROPERTY INSTALL_RPATH)

# システムによってRPATHの指定方法が異なる
if(APPLE)
        # macOSの場合
        set(SPECIAL_RPATH_KEYWORD "@loader_path")
else()
        # Linuxの場合
        set(SPECIAL_RPATH_KEYWORD "$ORIGIN")
endif()

# 特定のディレクトリ（この場合は作成されたライブラリがあるディレクトリ）を最優先にする
list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

# 更新されたRPATH設定をターゲットに適用
set_target_properties(raia_gles PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}")

if(WIN32)
        set_target_properties(raia_gles PROPERTIES PREFIX "")
endif()