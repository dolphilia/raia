cmake_minimum_required(VERSION 3.20)
project(SwiftCIntegration LANGUAGES C Swift)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../../../sdk/macos/arm64/include/skia)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

# Swiftコンパイラにブリッジヘッダを指定
set(CMAKE_Swift_FLAGS "${CMAKE_Swift_FLAGS} -import-objc-header ${CMAKE_SOURCE_DIR}/bridging-header.h")

# C言語コードをライブラリとしてビルド
add_library(wrapper STATIC
    wrapper/cglm_wrapper.c
    wrapper/glfw_wrapper.c
    wrapper/noise.c
)
target_include_directories(wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Swiftの実行ファイルを作成し、C側のライブラリとリンク
add_executable(main 
    src/main.swift

    src/game/__game_namespace.swift
    src/game/_game_rendererprotocol.swift
    src/game/_game_struct.swift
    src/game/_game_typealias.swift
    src/game/game_renderer2d.swift
    src/game/game_renderer3d.swift
    src/game/game_window.swift

    src/glfw/__glfw_namespace.swift
    src/glfw/_glfw_const.swift
    src/glfw/_glfw_function.swift
    src/glfw/_glfw_typealias.swift
    src/glfw/glfw_corsor.swift
    src/glfw/glfw_initializer.swift
    src/glfw/glfw_input.swift
    src/glfw/glfw_monitor.swift
    src/glfw/glfw_system.swift
    src/glfw/glfw_time.swift
    src/glfw/glfw_window.swift

    src/gles/__gles_namespace.swift
    src/gles/_gles_const.swift
    src/gles/_gles_function.swift
    src/gles/_gles_helper.swift

    src/skia/__skia_namespace.swift
    src/skia/_skia_enum.swift
    src/skia/_skia_function.swift
    src/skia/_skia_type.swift
    src/skia/_skia_typealias.swift
    src/skia/skia_bitmap.swift
    src/skia/skia_blender.swift
    src/skia/skia_canvas.swift
    src/skia/skia_color.swift
    src/skia/skia_color4f.swift
    src/skia/skia_colorfilter.swift
    src/skia/skia_colorinfo.swift
    src/skia/skia_colormatrix.swift
    src/skia/skia_colorspace.swift
    src/skia/skia_cubicresampler.swift
    src/skia/skia_data.swift
    src/skia/skia_drawable.swift
    src/skia/skia_flattenable.swift
    src/skia/skia_font.swift
    src/skia/skia_fontarguments.swift
    src/skia/skia_fontmgr.swift
    src/skia/skia_fontstyle.swift
    src/skia/skia_image.swift
    src/skia/skia_imagefilter.swift
    src/skia/skia_imageinfo.swift
    src/skia/skia_ipoint.swift
    src/skia/skia_irect.swift
    src/skia/skia_isize.swift
    src/skia/skia_m44.swift
    src/skia/skia_mask.swift
    src/skia/skia_maskbuilder.swift
    src/skia/skia_maskfilter.swift
    src/skia/skia_matrix.swift
    src/skia/skia_mesh.swift
    src/skia/skia_paint.swift
    src/skia/skia_path.swift
    src/skia/skia_patheffect.swift
    src/skia/skia_picture.swift
    src/skia/skia_pixelref.swift
    src/skia/skia_point.swift
    src/skia/skia_point3.swift
    src/skia/skia_pixmap.swift
    src/skia/skia_rect.swift
    src/skia/skia_region.swift
    src/skia/skia_rrect.swift
    src/skia/skia_rsxform.swift
    src/skia/skia_samplingoptions.swift
    src/skia/skia_shader.swift
    src/skia/skia_size.swift
    src/skia/skia_stream.swift
    src/skia/skia_streamasset.swift
    src/skia/skia_string.swift
    src/skia/skia_surface.swift
    src/skia/skia_surfaceprops.swift
    src/skia/skia_textblob.swift
    src/skia/skia_typeface.swift
    src/skia/skia_v2.swift
    src/skia/skia_v3.swift
    src/skia/skia_v4.swift
    src/skia/skia_vertices.swift
    src/skia/skia_writebuffer.swift
    src/skia/skia_wstream.swift
)

target_link_libraries(main PRIVATE wrapper glfw.3.4 raia_glfw egl GLESv2 raia_gles cglm reskia)
