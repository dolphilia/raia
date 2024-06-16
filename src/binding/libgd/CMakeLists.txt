cmake_minimum_required(VERSION 3.25)
project(raia_libgd C)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
        # macOSの場合
        set(CMAKE_INSTALL_RPATH "@loader_path")
else()
        # Linuxの場合
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

#add_executable(raia_libgd
add_library(raia_libgd SHARED
        src/raia_libgd.c
)

# 現在のRPATH設定を取得（もしあれば）
get_property(CURRENT_RPATH TARGET raia_libgd PROPERTY INSTALL_RPATH)

# 特定のディレクトリ（この場合は作成されたライブラリがあるディレクトリ）を最優先にする
list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

# 更新されたRPATH設定をターゲットに適用
set_target_properties(raia_libgd PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}"
)

target_link_libraries(raia_libgd
        $<$<PLATFORM_ID:Darwin>: gd>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
)