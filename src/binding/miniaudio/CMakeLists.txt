cmake_minimum_required(VERSION 3.25)
project(raia_miniaudio)

#include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_CXX_STANDARD 17)

#add_library(raia_miniaudio SHARED
add_executable(raia_miniaudio
        src/external/miniaudio.h
        src/raia_miniaudio.c
        src/raia_miniaudio.h
        #src/external/stb_vorbis.c
        #src/external/qoaplay.c
        #src/external/qoa.h
)

target_link_libraries(raia_miniaudio m)

# 現在のRPATH設定を取得（もしあれば）
#get_property(CURRENT_RPATH TARGET raia_imgui PROPERTY INSTALL_RPATH)

# システムによってRPATHの指定方法が異なる
#if(APPLE)
        # macOSの場合
#        set(SPECIAL_RPATH_KEYWORD "@loader_path")
#else()
        # Linuxの場合
#        set(SPECIAL_RPATH_KEYWORD "$ORIGIN")
#endif()

# 特定のディレクトリ（この場合は作成されたライブラリがあるディレクトリ）を最優先にする
#list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

# 更新されたRPATH設定をターゲットに適用
#set_target_properties(raia_imgui PROPERTIES
#        BUILD_WITH_INSTALL_RPATH TRUE
#        INSTALL_RPATH "${CURRENT_RPATH}")


#        $<$<PLATFORM_ID:Darwin>: egl glfw.3.4 GLESv2>
#        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
#        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
#        )

# 共有ライブラリが依存ライブラリを同じディレクトリから読み込むように設定
# プラットフォームごとにRPATHを設定
#if (UNIX AND NOT APPLE)
#        set_target_properties(raia_imgui PROPERTIES
#                BUILD_WITH_INSTALL_RPATH TRUE
#                INSTALL_RPATH "$ORIGIN")
#elseif (APPLE)
#        set_target_properties(raia_imgui PROPERTIES
#                BUILD_WITH_INSTALL_RPATH TRUE
#                INSTALL_RPATH "@loader_path")
#endif()

#set_target_properties(raia_imgui PROPERTIES PREFIX "")