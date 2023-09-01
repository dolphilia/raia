cmake_minimum_required(VERSION 3.25)
project(raia_glfw C)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_library(raia_glfw SHARED
#add_executable(raia_glfw
        src/raia_glfw.c
        src/yyjson/yyjson.c
        src/wrapper/wrapper_yyjson.c
        src/static/static_callback.c)

target_link_libraries(raia_glfw
        $<$<PLATFORM_ID:Darwin>: glfw.3.3>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

set_target_properties(raia_glfw PROPERTIES PREFIX "")