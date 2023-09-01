cmake_minimum_required(VERSION 3.25)
project(raia_imgui)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)

add_library(raia_imgui SHARED
#add_executable(raia_imgui
        src/raia_imgui.cpp
        src/imgui/imgui.cpp
        src/imgui/imgui_impl_glfw.cpp
        src/imgui/imgui_impl_opengl3.cpp
        src/imgui/imgui_draw.cpp
        src/imgui/imgui_widgets.cpp
        src/imgui/imgui_tables.cpp
        src/imgui/imgui_demo.cpp
        src/yyjson/yyjson.c
        src/wrapper/wrapper_yyjson.c
        src/raia_imgui.h)

target_link_libraries(raia_imgui
        $<$<PLATFORM_ID:Darwin>: egl glfw.3.3 GLESv2>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

set_target_properties(raia_imgui PROPERTIES PREFIX "")