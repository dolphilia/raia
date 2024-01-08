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
        src/static/static_sk_image_info.cpp
        src/static/static_sk_stream.cpp
        src/static/static_sk_image.cpp
        src/static/static_sk_data.cpp
        src/static/static_sk_shader.cpp
        src/static/static_sk_image_generator.cpp
        src/static/static_sk_mesh_child_ptr.cpp
        src/static/static_sk_blender.cpp
        src/static/static_sk_color_filter.cpp
        src/static/static_sk_color_space.cpp
        src/static/static_sk_color_table.cpp
        src/static/static_sk_image_filter.cpp
        src/static/static_sk_picture.cpp
        src/static/static_sk_pixel_ref.cpp
        src/static/static_sk_text_blob.cpp
        src/static/static_sk_typeface.cpp
        src/static/static_sk_vertices.cpp
        src/static/static_sk_capabilities.cpp
        src/static/static_sk_contour_measure.cpp
        src/static/static_sk_data_table.cpp
        src/static/static_sk_drawable.cpp
        src/static/static_sk_flattenable.cpp
        src/static/static_sk_font_mgr.cpp
        src/static/static_sk_font_style_set.cpp
        src/static/static_sk_mask_filter.cpp
        src/static/static_sk_mesh_index_buffer.cpp
        src/static/static_sk_mesh_vertex_buffer.cpp
        src/static/static_sk_path_effect.cpp
        src/static/static_sk_surface.cpp
        src/static/static_sk_canvas.cpp
        src/static/static_sk_drawable_gpu_draw_handler.cpp
        src/static/static_sk_executor.cpp
        src/static/static_sk_file_stream.cpp
        src/static/static_sk_memory_stream.cpp
        src/static/static_sk_stream_asset.cpp
        src/binding/sk_alpha_type.cpp
        src/binding/sk_alpha_type.h
        src/binding/sk_annotation.cpp
        src/binding/sk_annotation.h
        src/binding/sk_auto_canvas_restore.cpp
        src/binding/sk_auto_canvas_restore.h
        src/binding/sk_b_box_hierarchy.cpp
        src/binding/sk_b_box_hierarchy.h
        src/binding/sk_bitmap.cpp
        src/binding/sk_bitmap.h
        src/static/static_sk_pixmap.cpp
        src/static/static_sk_pixmap.h
        src/binding/sk_blender.cpp
        src/binding/sk_blender.h
        src/binding/sk_blenders.cpp
        src/binding/sk_blenders.h
        src/binding/sk_blend_mode.cpp
        src/binding/sk_blend_mode.h
        src/binding/sk_canvas.cpp
        src/binding/sk_canvas.h
        src/static/static_sk_surface_props.cpp
        src/static/static_sk_surface_props.h
        src/static/static_sk_m_44.cpp
        src/static/static_sk_m_44.h
        src/static/static_sk_matrix.cpp
        src/static/static_sk_matrix.h
        src/binding/sk_capabilities.cpp
        src/binding/sk_capabilities.h
        src/binding/sk_color.cpp
        src/binding/sk_color.h
        src/binding/sk_color_filter.cpp
        src/binding/sk_color_filter.h
        src/binding/sk_color_filters.cpp
        src/binding/sk_color_filters.h
        src/binding/sk_color_info.cpp
        src/binding/sk_color_info.h
        src/static/static_sk_color_info.cpp
        src/static/static_sk_color_info.h
        src/binding/sk_color_matrix.cpp
        src/binding/sk_color_matrix.h
        src/static/static_sk_color_matrix.cpp
        src/static/static_sk_color_matrix.h
        src/binding/sk_color_matrix_filter.cpp
        src/binding/sk_color_matrix_filter.h
        src/binding/sk_color_priv.cpp
        src/binding/sk_color_priv.h
        src/binding/sk_color_space.cpp
        src/binding/sk_color_space.h
        src/binding/sk_color_space_primaries.cpp
        src/binding/sk_color_space_primaries.h
        src/binding/sk_color_table.cpp
        src/binding/sk_color_table.h
        src/binding/sk_contour_measure.cpp
        src/binding/sk_contour_measure.h
        src/binding/sk_contour_measure_iter.cpp
        src/binding/sk_contour_measure_iter.h
        src/binding/sk_corner_path_effect.cpp
        src/binding/sk_corner_path_effect.h
        src/binding/sk_cubic_map.cpp
        src/binding/sk_cubic_map.h
        src/binding/sk_cubic_resampler.cpp
        src/binding/sk_cubic_resampler.h
        src/binding/sk_dash_path_effect.cpp
        src/binding/sk_dash_path_effect.h
        src/binding/sk_data.cpp
        src/binding/sk_data.h
        src/binding/sk_data_table.cpp
        src/binding/sk_data_table.h
        src/binding/sk_discrete_path_effect.cpp
        src/binding/sk_discrete_path_effect.h
        src/binding/sk_document.cpp
        src/binding/sk_document.h
        src/binding/sk_drawable.cpp
        src/binding/sk_drawable.h
        src/binding/sk_dynamic_memory_w_stream.cpp
        src/binding/sk_dynamic_memory_w_stream.h
        src/binding/sk_executor.cpp
        src/binding/sk_executor.h
        src/binding/sk_file_stream.cpp
        src/binding/sk_file_stream.h
        src/binding/sk_file_w_stream.cpp
        src/binding/sk_file_w_stream.h
        src/binding/sk_flattenable.cpp
        src/binding/sk_flattenable.h
        src/binding/sk_font.cpp
        src/binding/sk_font.h
        src/static/static_vector_sk_scalar.cpp
        src/static/static_vector_sk_scalar.h
        src/static/static_sk_font.cpp
        src/static/static_sk_font.h
        src/binding/sk_font_arguments.cpp
        src/binding/sk_font_arguments.h
        src/static/static_sk_font_arguments.cpp
        src/static/static_sk_font_arguments.h
        src/binding/sk_font_metrics.cpp
        src/binding/sk_font_metrics.h
        src/binding/sk_font_mgr.cpp
        src/binding/sk_font_mgr.h
        src/binding/sk_font_style.cpp
        src/binding/sk_font_style.h
        src/binding/sk_font_style_set.cpp
        src/binding/sk_font_style_set.h
        src/binding/sk_gradient_shader.cpp
        src/binding/sk_gradient_shader.h
        src/binding/sk_graphics.cpp
        src/binding/sk_graphics.h
        src/binding/sk_high_contrast_config.cpp
        src/binding/sk_high_contrast_config.h
        src/binding/sk_high_contrast_filter.cpp
        src/binding/sk_high_contrast_filter.h
        src/binding/sk_image.cpp
        src/binding/sk_image.h
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