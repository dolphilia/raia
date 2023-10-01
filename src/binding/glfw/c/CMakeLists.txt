cmake_minimum_required(VERSION 3.25)
project(raia_glfw C)

include(../../../setting.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
        # macOSの場合
        set(CMAKE_INSTALL_RPATH "@loader_path")
else()
        # Linuxの場合
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

add_library(raia_glfw SHARED
#add_executable(raia_glfw
        src/raia_glfw.c
        src/static/static_callback.c
        ../../../third_party/c/ibireme/yyjson/yyjson.c
        ../../../common/c/wrapper/wrapper_yyjson.c
)

# 現在のRPATH設定を取得（もしあれば）
get_property(CURRENT_RPATH TARGET raia_glfw PROPERTY INSTALL_RPATH)

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
set_target_properties(raia_glfw PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}")

target_link_libraries(raia_glfw
        $<$<PLATFORM_ID:Darwin>: glfw>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

# 共有ライブラリが依存ライブラリを同じディレクトリから読み込むように設定
# プラットフォームごとにRPATHを設定
#if (UNIX AND NOT APPLE)
#        set_target_properties(raia_glfw PROPERTIES
#                BUILD_WITH_INSTALL_RPATH TRUE
#                INSTALL_RPATH "$ORIGIN")
#elseif (APPLE)
#        set_target_properties(raia_glfw PROPERTIES
#                BUILD_WITH_INSTALL_RPATH TRUE
#                INSTALL_RPATH "@loader_path")
#endif()

set_target_properties(raia_glfw PROPERTIES PREFIX "")
#set_target_properties(raia_glfw PROPERTIES INSTALL_RPATH "@@executable_path")

# ビルド後に実行する
# install_name_tool -change /opt/homebrew/opt/glfw/lib/libglfw.3.dylib @executable_path/libglfw.3.dylib raia_glfw