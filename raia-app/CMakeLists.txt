cmake_minimum_required(VERSION 3.24)
project(raia_app C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_app SHARED
        src/raia_app.c
        src/static/static_callback.c
        src/static/static_callback.h
        src/yyjson/yyjson.c)

target_link_libraries(raia_app
        $<$<PLATFORM_ID:Darwin>: egl glfw GLESv2>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

set_target_properties(raia_app PROPERTIES PREFIX "")