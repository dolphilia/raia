cmake_minimum_required(VERSION 3.25)
project(raia_skia)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../../../sdk/macos/arm64/include/skia)
#include_directories(${PROJECT_SOURCE_DIR}/../../../../third_party/skia/)
#include_directories(${PROJECT_SOURCE_DIR}/skia)
#include_directories(/opt/homebrew/opt)
#link_directories(/opt/homebrew/opt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
        # macOSの場合
        set(CMAKE_INSTALL_RPATH "@loader_path")
else()
        # Linuxの場合
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

#add_library(raia_skia SHARED
add_executable(raia_skia
        src/raia_skia.cpp
        src/static/static_sk_rect.cpp
        src/static/static_sk_i_rect.cpp
        src/static/static_sk_i_rect.h
        src/static/static_sk_image_info.cpp
        src/static/static_sk_image_info.h
        src/static/static_sk_stream.cpp
        src/static/static_sk_stream.h
        src/static/static_sk_image.cpp
        src/static/static_sk_image.h
        src/static/static_sk_data.cpp
        src/static/static_sk_data.h
        src/static/static_sk_shader.cpp
        src/static/static_sk_shader.h
        src/static/static_sk_image_generator.cpp
        src/static/static_sk_image_generator.h
        src/static/static_sk_mesh_child_ptr.cpp
        src/static/static_sk_mesh_child_ptr.h
        src/static/static_sk_blender.cpp
        src/static/static_sk_blender.h
        src/static/static_sk_color_filter.cpp
        src/static/static_sk_color_filter.h
        src/static/static_sk_color_space.cpp
        src/static/static_sk_color_space.h
        src/static/static_sk_color_table.cpp
        src/static/static_sk_color_table.h
        src/static/static_sk_image_filter.cpp
        src/static/static_sk_image_filter.h
        src/static/static_sk_picture.cpp
        src/static/static_sk_picture.h
        src/static/static_sk_pixel_ref.cpp
        src/static/static_sk_pixel_ref.h
        src/static/static_sk_text_blob.cpp
        src/static/static_sk_text_blob.h
        src/static/static_sk_typeface.cpp
        src/static/static_sk_typeface.h
        src/static/static_sk_vertices.cpp
        src/static/static_sk_vertices.h
        src/static/static_sk_capabilities.cpp
        src/static/static_sk_capabilities.h
        src/static/static_sk_contour_measure.cpp
        src/static/static_sk_contour_measure.h
        src/static/static_sk_data_table.cpp
        src/static/static_sk_data_table.h
        src/static/static_sk_drawable.cpp
        src/static/static_sk_drawable.h
        src/static/static_sk_flattenable.cpp
        src/static/static_sk_flattenable.h
        src/static/static_sk_font_mgr.cpp
        src/static/static_sk_font_mgr.h
        src/static/static_sk_font_style_set.cpp
        src/static/static_sk_font_style_set.h
        src/static/static_sk_mask_filter.cpp
        src/static/static_sk_mask_filter.h
        src/static/static_sk_mesh_index_buffer.cpp
        src/static/static_sk_mesh_index_buffer.h
        src/static/static_sk_mesh_vertex_buffer.cpp
        src/static/static_sk_mesh_vertex_buffer.h
        src/static/static_sk_path_effect.cpp
        src/static/static_sk_path_effect.h
        src/static/static_sk_surface.cpp
        src/static/static_sk_surface.h
        src/static/static_sk_canvas.cpp
        src/static/static_sk_canvas.h
        src/static/static_sk_drawable_gpu_draw_handler.cpp
        src/static/static_sk_drawable_gpu_draw_handler.h
        src/static/static_sk_executor.cpp
        src/static/static_sk_executor.h
        src/static/static_sk_file_stream.cpp
        src/static/static_sk_file_stream.h
        src/static/static_sk_memory_stream.cpp
        src/static/static_sk_memory_stream.h
        src/static/static_sk_stream_asset.cpp
        src/static/static_sk_stream_asset.h
)

# 現在のRPATH設定を取得（もしあれば）
get_property(CURRENT_RPATH TARGET raia_skia PROPERTY INSTALL_RPATH)

# 特定のディレクトリ（この場合は作成されたライブラリがあるディレクトリ）を最優先にする
list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

# 更新されたRPATH設定をターゲットに適用
set_target_properties(raia_skia PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}")

target_link_libraries(raia_skia
        $<$<PLATFORM_ID:Darwin>: egl glfw.3.4 GLESv2 skia skshaper>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

set_target_properties(raia_skia PROPERTIES PREFIX "")