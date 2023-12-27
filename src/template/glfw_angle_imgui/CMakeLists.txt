cmake_minimum_required(VERSION 3.25)
project(raia_gui)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
        # macOSの場合
        set(CMAKE_INSTALL_RPATH "@loader_path")
else()
        # Linuxの場合
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

#add_library(raia_gui SHARED
add_executable(raia_gui
        src/raia_gui.cpp
        src/static/static_callback.c
        src/util/util_math.c
        ../../../third_party/cpp/ocornut/imgui/imgui.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_impl_glfw.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_impl_opengl3.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_draw.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_widgets.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_tables.cpp
        ../../../third_party/cpp/ocornut/imgui/imgui_demo.cpp
        ../../../third_party/c/ibireme/yyjson/yyjson.c
        ../../../common/c/wrapper/wrapper_yyjson.c)

# 現在のRPATH設定を取得（もしあれば）
get_property(CURRENT_RPATH TARGET raia_gui PROPERTY INSTALL_RPATH)

# 特定のディレクトリ（この場合は作成されたライブラリがあるディレクトリ）を最優先にする
list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

# 更新されたRPATH設定をターゲットに適用
set_target_properties(raia_gui PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}")

target_link_libraries(raia_gui
        $<$<PLATFORM_ID:Darwin>: egl glfw.3.4 GLESv2>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

#set_target_properties(raia_gui PROPERTIES PREFIX "")