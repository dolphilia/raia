cmake_minimum_required(VERSION 3.25)
project(raia_skia)

#add_subdirectory(${PROJECT_SOURCE_DIR}/../../../third_party/googletest)

include(${PROJECT_SOURCE_DIR}/../../setting.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../../../sdk/macos/arm64/include/skia)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
if(APPLE)
        set(CMAKE_INSTALL_RPATH "@loader_path")
else()
        set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

#add_executable(raia_skia src/raia_skia.cpp
add_library(raia_skia SHARED
        src/binding/gr_backend_drawable_info.cpp
        src/binding/gr_backend_drawable_info.h
        src/binding/gr_backend_format.cpp
        src/binding/gr_backend_format.h
        src/binding/gr_backend_render_target.cpp
        src/binding/gr_backend_render_target.h
        src/binding/gr_backend_semaphore.cpp
        src/binding/gr_backend_semaphore.h
        src/binding/gr_backend_texture.cpp
        src/binding/gr_backend_texture.h
        src/binding/gr_context_thread_safe_proxy.cpp
        src/binding/gr_context_thread_safe_proxy.h
        src/binding/gr_direct_context.cpp
        src/binding/gr_direct_context.h
        src/binding/gr_driver_bug_workarounds.cpp
        src/binding/gr_driver_bug_workarounds.h
        src/binding/gr_recording_context.cpp
        src/binding/gr_recording_context.h
        src/binding/gr_yuva_backend_texture_info.cpp
        src/binding/gr_yuva_backend_texture_info.h
        src/binding/gr_yuva_backend_textures.cpp
        src/binding/gr_yuva_backend_textures.h
        src/binding/sk_alpha_type.cpp
        src/binding/sk_alpha_type.h
        src/binding/sk_android_codec.cpp
        src/binding/sk_android_codec.h
        src/binding/sk_annotation.cpp
        src/binding/sk_annotation.h
        src/binding/sk_auto_canvas_restore.cpp
        src/binding/sk_auto_canvas_restore.h
        src/binding/sk_avif_decoder.h.cpp
        src/binding/sk_avif_decoder.h.h
        src/binding/sk_b_box_hierarchy.cpp
        src/binding/sk_b_box_hierarchy.h
        src/binding/sk_bitmap.cpp
        src/binding/sk_bitmap.h
        src/binding/sk_blend_mode.cpp
        src/binding/sk_blend_mode.h
        src/binding/sk_blender.cpp
        src/binding/sk_blender.h
        src/binding/sk_blenders.cpp
        src/binding/sk_blenders.h
        src/binding/sk_bmp_decoder.h.cpp
        src/binding/sk_bmp_decoder.h.h
        src/binding/sk_canvas.cpp
        src/binding/sk_canvas.h
        src/binding/sk_capabilities.cpp
        src/binding/sk_capabilities.h
        src/binding/sk_codec.cpp
        src/binding/sk_codec.h
        src/binding/sk_codecs.cpp
        src/binding/sk_codecs.h
        src/binding/sk_color_filter.cpp
        src/binding/sk_color_filter.h
        src/binding/sk_color_filters.cpp
        src/binding/sk_color_filters.h
        src/binding/sk_color_info.cpp
        src/binding/sk_color_info.h
        src/binding/sk_color_matrix_filter.cpp
        src/binding/sk_color_matrix_filter.h
        src/binding/sk_color_matrix.cpp
        src/binding/sk_color_matrix.h
        src/binding/sk_color_priv.cpp
        src/binding/sk_color_priv.h
        src/binding/sk_color_space_primaries.cpp
        src/binding/sk_color_space_primaries.h
        src/binding/sk_color_space.cpp
        src/binding/sk_color_space.h
        src/binding/sk_color_table.cpp
        src/binding/sk_color_table.h
        src/binding/sk_color.cpp
        src/binding/sk_color.h
        src/binding/sk_contour_measure_iter.cpp
        src/binding/sk_contour_measure_iter.h
        src/binding/sk_contour_measure.cpp
        src/binding/sk_contour_measure.h
        src/binding/sk_corner_path_effect.cpp
        src/binding/sk_corner_path_effect.h
        src/binding/sk_cubic_map.cpp
        src/binding/sk_cubic_map.h
        src/binding/sk_cubic_resampler.cpp
        src/binding/sk_cubic_resampler.h
        src/binding/sk_dash_path_effect.cpp
        src/binding/sk_dash_path_effect.h
        src/binding/sk_data_table.cpp
        src/binding/sk_data_table.h
        src/binding/sk_data.cpp
        src/binding/sk_data.h
        src/binding/sk_discrete_path_effect.cpp
        src/binding/sk_discrete_path_effect.h
        src/binding/sk_document.cpp
        src/binding/sk_document.h
        src/binding/sk_drawable.cpp
        src/binding/sk_drawable.h
        src/binding/sk_dynamic_memory_w_stream.cpp
        src/binding/sk_dynamic_memory_w_stream.h
        src/binding/sk_encoded_origin.cpp
        src/binding/sk_encoded_origin.h
        src/binding/sk_encoder.cpp
        src/binding/sk_encoder.h
        src/binding/sk_executor.cpp
        src/binding/sk_executor.h
        src/binding/sk_file_stream.cpp
        src/binding/sk_file_stream.h
        src/binding/sk_file_w_stream.cpp
        src/binding/sk_file_w_stream.h
        src/binding/sk_flattenable.cpp
        src/binding/sk_flattenable.h
        src/binding/sk_font_arguments.cpp
        src/binding/sk_font_arguments.h
        src/binding/sk_font_metrics.cpp
        src/binding/sk_font_metrics.h
        src/binding/sk_font_mgr_fontconfig.cpp
        src/binding/sk_font_mgr_fontconfig.h
        src/binding/sk_font_mgr.cpp
        src/binding/sk_font_mgr.h
        src/binding/sk_font_style_set.cpp
        src/binding/sk_font_style_set.h
        src/binding/sk_font_style.cpp
        src/binding/sk_font_style.h
        src/binding/sk_font.cpp
        src/binding/sk_font.h
        src/binding/sk_gif_decoder.cpp
        src/binding/sk_gif_decoder.h
        src/binding/sk_gradient_shader.cpp
        src/binding/sk_gradient_shader.h
        src/binding/sk_graphics.cpp
        src/binding/sk_graphics.h
        src/binding/sk_high_contrast_config.cpp
        src/binding/sk_high_contrast_config.h
        src/binding/sk_high_contrast_filter.cpp
        src/binding/sk_high_contrast_filter.h
        src/binding/sk_i_rect.cpp
        src/binding/sk_i_rect.h
        src/binding/sk_i_size.cpp
        src/binding/sk_i_size.h
        src/binding/sk_icc.cpp
        src/binding/sk_icc.h
        src/binding/sk_ico_cecoder.cpp
        src/binding/sk_ico_cecoder.h
        src/binding/sk_image_filter.cpp
        src/binding/sk_image_filter.h
        src/binding/sk_image_filters.cpp
        src/binding/sk_image_filters.h
        src/binding/sk_image_generator.cpp
        src/binding/sk_image_generator.h
        src/binding/sk_image_info.cpp
        src/binding/sk_image_info.h
        src/binding/sk_image.cpp
        src/binding/sk_image.h
        src/binding/sk_images.cpp
        src/binding/sk_images.h
        src/binding/sk_jpeg_decoder.cpp
        src/binding/sk_jpeg_decoder.h
        src/binding/sk_jpeg_encoder.cpp
        src/binding/sk_jpeg_encoder.h
        src/binding/sk_jpegxl_decoder.cpp
        src/binding/sk_jpegxl_decoder.h
        src/binding/sk_line_2d_path_effect.cpp
        src/binding/sk_line_2d_path_effect.h
        src/binding/sk_luma_color_filter.cpp
        src/binding/sk_luma_color_filter.h
        src/binding/sk_m_44.cpp
        src/binding/sk_m_44.h
        src/binding/sk_malloc_pixel_ref.cpp
        src/binding/sk_malloc_pixel_ref.h
        src/binding/sk_mask_filter.cpp
        src/binding/sk_mask_filter.h
        src/binding/sk_matrix.cpp
        src/binding/sk_matrix.h
        src/binding/sk_memory_stream.cpp
        src/binding/sk_memory_stream.h
        src/binding/sk_meshes.cpp
        src/binding/sk_meshes.h
        src/binding/sk_op_builder.cpp
        src/binding/sk_op_builder.h
        src/binding/sk_open_type_svg_decoder.cpp
        src/binding/sk_open_type_svg_decoder.h
        src/binding/sk_overdraw_canvas.cpp
        src/binding/sk_overdraw_canvas.h
        src/binding/sk_overdraw_color_filter.cpp
        src/binding/sk_overdraw_color_filter.h
        src/binding/sk_paint.cpp
        src/binding/sk_paint.h
        src/binding/sk_path_1d_path_effect.cpp
        src/binding/sk_path_1d_path_effect.h
        src/binding/sk_path_2d_path_effect.cpp
        src/binding/sk_path_2d_path_effect.h
        src/binding/sk_path_builder.cpp
        src/binding/sk_path_builder.h
        src/binding/sk_path_effect.cpp
        src/binding/sk_path_effect.h
        src/binding/sk_path_measure.cpp
        src/binding/sk_path_measure.h
        src/binding/sk_path.cpp
        src/binding/sk_path.h
        src/binding/sk_pdf.cpp
        src/binding/sk_pdf.h
        src/binding/sk_perlin_noise_shader.cpp
        src/binding/sk_perlin_noise_shader.h
        src/binding/sk_picture_recorder.cpp
        src/binding/sk_picture_recorder.h
        src/binding/sk_picture.cpp
        src/binding/sk_picture.h
        src/binding/sk_pixel_ref.cpp
        src/binding/sk_pixel_ref.h
        src/binding/sk_pixmap_utils.cpp
        src/binding/sk_pixmap_utils.h
        src/binding/sk_pixmap.cpp
        src/binding/sk_pixmap.h
        src/binding/sk_png_decoder.cpp
        src/binding/sk_png_decoder.h
        src/binding/sk_png_encoder.cpp
        src/binding/sk_png_encoder.h
        src/binding/sk_point_3.cpp
        src/binding/sk_point_3.h
        src/binding/sk_point.cpp
        src/binding/sk_point.h
        src/binding/sk_r_rect.cpp
        src/binding/sk_r_rect.h
        src/binding/sk_raster_handle_allocator.cpp
        src/binding/sk_raster_handle_allocator.h
        src/binding/sk_raw_decoder.cpp
        src/binding/sk_raw_decoder.h
        src/binding/sk_rect.cpp
        src/binding/sk_rect.h
        src/binding/sk_ref_cnt_base.cpp
        src/binding/sk_ref_cnt_base.h
        src/binding/sk_ref_cnt.cpp
        src/binding/sk_ref_cnt.h
        src/binding/sk_region.cpp
        src/binding/sk_region.h
        src/binding/sk_rsx_form.cpp
        src/binding/sk_rsx_form.h
        src/binding/sk_runtime_blend_builder.cpp
        src/binding/sk_runtime_blend_builder.h
        src/binding/sk_runtime_color_filter_builder.cpp
        src/binding/sk_runtime_color_filter_builder.h
        src/binding/sk_runtime_effect_builder.cpp
        src/binding/sk_runtime_effect_builder.h
        src/binding/sk_runtime_effect.cpp
        src/binding/sk_runtime_effect.h
        src/binding/sk_runtime_shader_builder.cpp
        src/binding/sk_runtime_shader_builder.h
        src/binding/sk_sampling_options.cpp
        src/binding/sk_sampling_options.h
        src/binding/sk_shader_mask_filter.cpp
        src/binding/sk_shader_mask_filter.h
        src/binding/sk_shader.cpp
        src/binding/sk_shader.h
        src/binding/sk_shaders.cpp
        src/binding/sk_shaders.h
        src/binding/sk_shaper.cpp
        src/binding/sk_shaper.h
        src/binding/sk_size.cpp
        src/binding/sk_size.h
        src/binding/sk_stream_asset.cpp
        src/binding/sk_stream_asset.h
        src/binding/sk_stream_memory.cpp
        src/binding/sk_stream_memory.h
        src/binding/sk_stream_rewindable.cpp
        src/binding/sk_stream_rewindable.h
        src/binding/sk_stream_seekable.cpp
        src/binding/sk_stream_seekable.h
        src/binding/sk_stream.cpp
        src/binding/sk_stream.h
        src/binding/sk_string.cpp
        src/binding/sk_string.h
        src/binding/sk_stroke_rec.cpp
        src/binding/sk_stroke_rec.h
        src/binding/sk_surface_props.cpp
        src/binding/sk_surface_props.h
        src/binding/sk_surface.cpp
        src/binding/sk_surface.h
        src/binding/sk_surfaces.cpp
        src/binding/sk_surfaces.h
#        src/binding/sk_svg_attribute_parser.cpp
#        src/binding/sk_svg_attribute_parser.h
#        src/binding/sk_svg_circle.cpp
#        src/binding/sk_svg_circle.h
#        src/binding/sk_svg_clip_path.cpp
#        src/binding/sk_svg_clip_path.h
#        src/binding/sk_svg_color.cpp
#        src/binding/sk_svg_color.h
#        src/binding/sk_svg_container.cpp
#        src/binding/sk_svg_container.h
#        src/binding/sk_svg_dash_array.cpp
#        src/binding/sk_svg_dash_array.h
#        src/binding/sk_svg_defs.cpp
#        src/binding/sk_svg_defs.h
#        src/binding/sk_svg_dom.cpp
#        src/binding/sk_svg_dom.h
#        src/binding/sk_svg_ellipse.cpp
#        src/binding/sk_svg_ellipse.h
#        src/binding/sk_svg_fe_blend.cpp
#        src/binding/sk_svg_fe_blend.h
#        src/binding/sk_svg_fe_color_matrix.cpp
#        src/binding/sk_svg_fe_color_matrix.h
#        src/binding/sk_svg_fe_composite.cpp
#        src/binding/sk_svg_fe_composite.h
#        src/binding/sk_svg_fe_diffuse_lighting.cpp
#        src/binding/sk_svg_fe_diffuse_lighting.h
#        src/binding/sk_svg_fe_displacement_map.cpp
#        src/binding/sk_svg_fe_displacement_map.h
#        src/binding/sk_svg_fe_distant_light.cpp
#        src/binding/sk_svg_fe_distant_light.h
#        src/binding/sk_svg_fe_flood.cpp
#        src/binding/sk_svg_fe_flood.h
#        src/binding/sk_svg_fe_gaussian_blur.cpp
#        src/binding/sk_svg_fe_gaussian_blur.h
#        src/binding/sk_svg_fe_image.cpp
#        src/binding/sk_svg_fe_image.h
#        src/binding/sk_svg_fe_input_type.cpp
#        src/binding/sk_svg_fe_input_type.h
#        src/binding/sk_svg_fe_light_source.cpp
#        src/binding/sk_svg_fe_light_source.h
#        src/binding/sk_svg_fe_lighting.cpp
#        src/binding/sk_svg_fe_lighting.h
#        src/binding/sk_svg_fe_morphology.cpp
#        src/binding/sk_svg_fe_morphology.h
#        src/binding/sk_svg_fe_offset.cpp
#        src/binding/sk_svg_fe_offset.h
#        src/binding/sk_svg_fe_point_light.cpp
#        src/binding/sk_svg_fe_point_light.h
#        src/binding/sk_svg_fe_specular_lighting.cpp
#        src/binding/sk_svg_fe_specular_lighting.h
#        src/binding/sk_svg_fe_spot_light.cpp
#        src/binding/sk_svg_fe_spot_light.h
#        src/binding/sk_svg_fe_turbulence_base_frequency.cpp
#        src/binding/sk_svg_fe_turbulence_base_frequency.h
#        src/binding/sk_svg_fe_turbulence_type.cpp
#        src/binding/sk_svg_fe_turbulence_type.h
#        src/binding/sk_svg_fe_turbulence.cpp
#        src/binding/sk_svg_fe_turbulence.h
#        src/binding/sk_svg_fe.cpp
#        src/binding/sk_svg_fe.h
#        src/binding/sk_svg_fill_rule.cpp
#        src/binding/sk_svg_fill_rule.h
#        src/binding/sk_svg_filter_context.cpp
#        src/binding/sk_svg_filter_context.h
#        src/binding/sk_svg_filter.cpp
#        src/binding/sk_svg_filter.h
#        src/binding/sk_svg_font_family.cpp
#        src/binding/sk_svg_font_family.h
#        src/binding/sk_svg_font_size.cpp
#        src/binding/sk_svg_font_size.h
#        src/binding/sk_svg_font_style.cpp
#        src/binding/sk_svg_font_style.h
#        src/binding/sk_svg_font_weight.cpp
#        src/binding/sk_svg_font_weight.h
#        src/binding/sk_svg_func_iri.cpp
#        src/binding/sk_svg_func_iri.h
#        src/binding/sk_svg_g.cpp
#        src/binding/sk_svg_g.h
#        src/binding/sk_svg_gradient.cpp
#        src/binding/sk_svg_gradient.h
#        src/binding/sk_svg_hidden_container.cpp
#        src/binding/sk_svg_hidden_container.h
#        src/binding/sk_svg_image.cpp
#        src/binding/sk_svg_image.h
#        src/binding/sk_svg_iri.cpp
#        src/binding/sk_svg_iri.h
#        src/binding/sk_svg_length_context.cpp
#        src/binding/sk_svg_length_context.h
#        src/binding/sk_svg_length.cpp
#        src/binding/sk_svg_length.h
#        src/binding/sk_svg_line_join.cpp
#        src/binding/sk_svg_line_join.h
#        src/binding/sk_svg_line.cpp
#        src/binding/sk_svg_line.h
#        src/binding/sk_svg_linear_gradient.cpp
#        src/binding/sk_svg_linear_gradient.h
#        src/binding/sk_svg_mask.cpp
#        src/binding/sk_svg_mask.h
#        src/binding/sk_svg_node.cpp
#        src/binding/sk_svg_node.h
#        src/binding/sk_svg_object_bounding_box_units.cpp
#        src/binding/sk_svg_object_bounding_box_units.h
#        src/binding/sk_svg_open_type_svg_decoder.cpp
#        src/binding/sk_svg_open_type_svg_decoder.h
#        src/binding/sk_svg_paint.cpp
#        src/binding/sk_svg_paint.h
#        src/binding/sk_svg_path.cpp
#        src/binding/sk_svg_path.h
#        src/binding/sk_svg_pattern.cpp
#        src/binding/sk_svg_pattern.h
#        src/binding/sk_svg_poly.cpp
#        src/binding/sk_svg_poly.h
#        src/binding/sk_svg_presentation_attributes.cpp
#        src/binding/sk_svg_presentation_attributes.h
#        src/binding/sk_svg_presentation_context.cpp
#        src/binding/sk_svg_presentation_context.h
#        src/binding/sk_svg_property.cpp
#        src/binding/sk_svg_property.h
#        src/binding/sk_svg_radial_gradient.cpp
#        src/binding/sk_svg_radial_gradient.h
#        src/binding/sk_svg_rect.cpp
#        src/binding/sk_svg_rect.h
#        src/binding/sk_svg_render_context.cpp
#        src/binding/sk_svg_render_context.h
#        src/binding/sk_svg_shape.cpp
#        src/binding/sk_svg_shape.h
#        src/binding/sk_svg_spread_method.cpp
#        src/binding/sk_svg_spread_method.h
#        src/binding/sk_svg_stop_color.cpp
#        src/binding/sk_svg_stop_color.h
#        src/binding/sk_svg_stop.cpp
#        src/binding/sk_svg_stop.h
#        src/binding/sk_svg_svg.cpp
#        src/binding/sk_svg_svg.h
#        src/binding/sk_svg_t_span.cpp
#        src/binding/sk_svg_t_span.h
#        src/binding/sk_svg_text_anchor.cpp
#        src/binding/sk_svg_text_anchor.h
#        src/binding/sk_svg_text_container.cpp
#        src/binding/sk_svg_text_container.h
#        src/binding/sk_svg_text_fragment.cpp
#        src/binding/sk_svg_text_fragment.h
#        src/binding/sk_svg_text_literal.cpp
#        src/binding/sk_svg_text_literal.h
#        src/binding/sk_svg_text_path.cpp
#        src/binding/sk_svg_text_path.h
#        src/binding/sk_svg_text.cpp
#        src/binding/sk_svg_text.h
#        src/binding/sk_svg_transformable_node.cpp
#        src/binding/sk_svg_transformable_node.h
#        src/binding/sk_svg_use.cpp
#        src/binding/sk_svg_use.h
#        src/binding/sk_svg_value.cpp
#        src/binding/sk_svg_value.h
#        src/binding/sk_svg_visibility.cpp
#        src/binding/sk_svg_visibility.h
#        src/binding/sk_svg_wrapper_value.cpp
#        src/binding/sk_svg_wrapper_value.h
        src/binding/sk_table_mask_filter.cpp
        src/binding/sk_table_mask_filter.h
        src/binding/sk_text_blob_builder_run_handler.cpp
        src/binding/sk_text_blob_builder_run_handler.h
        src/binding/sk_text_blob_builder.cpp
        src/binding/sk_text_blob_builder.h
        src/binding/sk_text_blob.cpp
        src/binding/sk_text_blob.h
        src/binding/sk_tiled_image_utils.cpp
        src/binding/sk_tiled_image_utils.h
        src/binding/sk_trace_memory_dump.cpp
        src/binding/sk_trace_memory_dump.h
        src/binding/sk_trim_path_effect.cpp
        src/binding/sk_trim_path_effect.h
        src/binding/sk_typeface_mac.cpp
        src/binding/sk_typeface_mac.h
        src/binding/sk_typeface.cpp
        src/binding/sk_typeface.h
        src/binding/sk_un_pre_multiply.cpp
        src/binding/sk_un_pre_multiply.h
        src/binding/sk_v2.cpp
        src/binding/sk_v2.h
        src/binding/sk_v3.cpp
        src/binding/sk_v3.h
        src/binding/sk_v4.cpp
        src/binding/sk_v4.h
        src/binding/sk_vertices.cpp
        src/binding/sk_vertices.h
        src/binding/sk_w_stream.cpp
        src/binding/sk_w_stream.h
        src/binding/sk_wbmp_decoder.cpp
        src/binding/sk_wbmp_decoder.h
        src/binding/sk_webp_decoder.cpp
        src/binding/sk_webp_decoder.h
        src/binding/sk_webp_encoder.cpp
        src/binding/sk_webp_encoder.h
        src/binding/sk_yuva_info.cpp
        src/binding/sk_yuva_info.h
        src/binding/sk_yuva_pixmap_info.cpp
        src/binding/sk_yuva_pixmap_info.h
        src/binding/sk_yuva_pixmaps.cpp
        src/binding/sk_yuva_pixmaps.h
        src/binding/skottie_animation.cpp
        src/binding/skottie_animation.h
        src/static/static_gr_backend_format.cpp
        src/static/static_gr_backend_format.h
        src/static/static_gr_backend_texture.cpp
        src/static/static_gr_backend_texture.h
        src/static/static_gr_color_format_desc.cpp
        src/static/static_gr_color_format_desc.h
        src/static/static_gr_context_thread_safe_proxy.cpp
        src/static/static_gr_context_thread_safe_proxy.h
        src/static/static_gr_direct_context_direct_context_id.cpp
        src/static/static_gr_direct_context_direct_context_id.h
        src/static/static_gr_direct_context.cpp
        src/static/static_gr_direct_context.h
        src/static/static_sk_android_codec.cpp
        src/static/static_sk_android_codec.h
        src/static/static_sk_b_box_hierarchy.cpp
        src/static/static_sk_b_box_hierarchy.h
        src/static/static_sk_blend_mode.cpp
        src/static/static_sk_blend_mode.h
        src/static/static_sk_blender.cpp
        src/static/static_sk_canvas.cpp
        src/static/static_sk_capabilities.cpp
        src/static/static_sk_codec.cpp
        src/static/static_sk_codec.h
        src/static/static_sk_codecs_decoder.cpp
        src/static/static_sk_codecs_decoder.h
        src/static/static_sk_color_4f.cpp
        src/static/static_sk_color_4f.h
        src/static/static_sk_color_filter.cpp
        src/static/static_sk_color_info.cpp
        src/static/static_sk_color_info.h
        src/static/static_sk_color_matrix.cpp
        src/static/static_sk_color_matrix.h
        src/static/static_sk_color_space.cpp
        src/static/static_sk_color_table.cpp
        src/static/static_sk_color.cpp
        src/static/static_sk_color.h
        src/static/static_sk_contour_measure.cpp
        src/static/static_sk_cubic_resampler.cpp
        src/static/static_sk_cubic_resampler.h
        src/static/static_sk_data_table.cpp
        src/static/static_sk_data.cpp
        src/static/static_sk_document.cpp
        src/static/static_sk_document.h
        src/static/static_sk_drawable_gpu_draw_handler.cpp
        src/static/static_sk_drawable.cpp
        src/static/static_sk_encoder_frame.cpp
        src/static/static_sk_encoder_frame.h
        src/static/static_sk_encoder.cpp
        src/static/static_sk_encoder.h
        src/static/static_sk_executor.cpp
        src/static/static_sk_file_stream.cpp
        src/static/static_sk_flattenable_factory.cpp
        src/static/static_sk_flattenable_factory.h
        src/static/static_sk_flattenable.cpp
        src/static/static_sk_font_arguments_palette.cpp
        src/static/static_sk_font_arguments_palette.h
        src/static/static_sk_font_arguments_variation_position.cpp
        src/static/static_sk_font_arguments_variation_position.h
        src/static/static_sk_font_arguments.cpp
        src/static/static_sk_font_arguments.h
        src/static/static_sk_font_mgr.cpp
        src/static/static_sk_font_style_set.cpp
        src/static/static_sk_font_style.cpp
        src/static/static_sk_font_style.h
        src/static/static_sk_font.cpp
        src/static/static_sk_font.h
        src/static/static_sk_i_point.cpp
        src/static/static_sk_i_point.h
        src/static/static_sk_i_rect.cpp
        src/static/static_sk_i_size.cpp
        src/static/static_sk_i_size.h
        src/static/static_sk_id_change_listener.cpp
        src/static/static_sk_id_change_listener.h
        src/static/static_sk_image_filter.cpp
        src/static/static_sk_image_generator.cpp
        src/static/static_sk_image_info.cpp
        src/static/static_sk_image_read_pixels_callback.cpp
        src/static/static_sk_image_read_pixels_callback.h
        src/static/static_sk_image_required_properties.cpp
        src/static/static_sk_image_required_properties.h
        src/static/static_sk_image.cpp
        src/static/static_sk_m_44.cpp
        src/static/static_sk_m_44.h
        src/static/static_sk_mask_filter.cpp
        src/static/static_sk_matrix.cpp
        src/static/static_sk_matrix.h
        src/static/static_sk_memory_stream.cpp
        src/static/static_sk_mesh_child_ptr.cpp
        src/static/static_sk_mesh_index_buffer.cpp
        src/static/static_sk_mesh_vertex_buffer.cpp
        src/static/static_sk_path_effect.cpp
        src/static/static_sk_path.cpp
        src/static/static_sk_path.h
        src/static/static_sk_picture.cpp
        src/static/static_sk_pixel_ref.cpp
        src/static/static_sk_pixmap.cpp
        src/static/static_sk_pixmap.h
        src/static/static_sk_point_3.cpp
        src/static/static_sk_point_3.h
        src/static/static_sk_point.cpp
        src/static/static_sk_point.h
        src/static/static_sk_r_rect.cpp
        src/static/static_sk_r_rect.h
        src/static/static_sk_rect.cpp
        src/static/static_sk_rsx_form.cpp
        src/static/static_sk_rsx_form.h
        src/static/static_sk_runtime_effect_builder_builder_child.cpp
        src/static/static_sk_runtime_effect_builder_builder_child.h
        src/static/static_sk_runtime_effect_builder_builder_uniform.cpp
        src/static/static_sk_runtime_effect_builder_builder_uniform.h
        src/static/static_sk_runtime_effect_child_ptr.cpp
        src/static/static_sk_runtime_effect_child_ptr.h
        src/static/static_sk_runtime_effect_child.cpp
        src/static/static_sk_runtime_effect_child.h
        src/static/static_sk_runtime_effect_result.cpp
        src/static/static_sk_runtime_effect_result.h
        src/static/static_sk_runtime_effect_traced_shader.cpp
        src/static/static_sk_runtime_effect_traced_shader.h
        src/static/static_sk_runtime_effect_uniform.cpp
        src/static/static_sk_runtime_effect_uniform.h
        src/static/static_sk_runtime_effect.cpp
        src/static/static_sk_runtime_effect.h
        src/static/static_sk_sampling_options.cpp
        src/static/static_sk_sampling_options.h
        src/static/static_sk_shader.cpp
        src/static/static_sk_shaper_bi_di_run_iterator.cpp
        src/static/static_sk_shaper_bi_di_run_iterator.h
        src/static/static_sk_shaper_font_run_iterator.cpp
        src/static/static_sk_shaper_font_run_iterator.h
        src/static/static_sk_shaper_language_run_iterator.cpp
        src/static/static_sk_shaper_language_run_iterator.h
        src/static/static_sk_shaper_run_handler_buffer.cpp
        src/static/static_sk_shaper_run_handler_buffer.h
        src/static/static_sk_shaper_script_run_iterator.cpp
        src/static/static_sk_shaper_script_run_iterator.h
        src/static/static_sk_shaper.cpp
        src/static/static_sk_shaper.h
        src/static/static_sk_size_t.cpp
        src/static/static_sk_size_t.h
        src/static/static_sk_stream_asset.cpp
        src/static/static_sk_stream_memory.cpp
        src/static/static_sk_stream_memory.h
        src/static/static_sk_stream_rewindable.cpp
        src/static/static_sk_stream_rewindable.h
        src/static/static_sk_stream_seekable.cpp
        src/static/static_sk_stream_seekable.h
        src/static/static_sk_stream.cpp
        src/static/static_sk_string.cpp
        src/static/static_sk_string.h
        src/static/static_sk_stroke_rec.cpp
        src/static/static_sk_stroke_rec.h
        src/static/static_sk_surface_props.cpp
        src/static/static_sk_surface_props.h
        src/static/static_sk_surface.cpp
#        src/static/static_sk_svg_circle.cpp
#        src/static/static_sk_svg_circle.h
#        src/static/static_sk_svg_clip_path.cpp
#        src/static/static_sk_svg_clip_path.h
#        src/static/static_sk_svg_defs.cpp
#        src/static/static_sk_svg_defs.h
#        src/static/static_sk_svg_dom.cpp
#        src/static/static_sk_svg_dom.h
#        src/static/static_sk_svg_ellipse.cpp
#        src/static/static_sk_svg_ellipse.h
#        src/static/static_sk_svg_fe_blend.cpp
#        src/static/static_sk_svg_fe_blend.h
#        src/static/static_sk_svg_fe_color_matrix.cpp
#        src/static/static_sk_svg_fe_color_matrix.h
#        src/static/static_sk_svg_fe_composite.cpp
#        src/static/static_sk_svg_fe_composite.h
#        src/static/static_sk_svg_fe_diffuse_lighting.cpp
#        src/static/static_sk_svg_fe_diffuse_lighting.h
#        src/static/static_sk_svg_fe_displacement_map.cpp
#        src/static/static_sk_svg_fe_displacement_map.h
#        src/static/static_sk_svg_fe_distant_light.cpp
#        src/static/static_sk_svg_fe_distant_light.h
#        src/static/static_sk_svg_fe_flood.cpp
#        src/static/static_sk_svg_fe_flood.h
#        src/static/static_sk_svg_fe_gaussian_blur.cpp
#        src/static/static_sk_svg_fe_gaussian_blur.h
#        src/static/static_sk_svg_fe_image.cpp
#        src/static/static_sk_svg_fe_image.h
#        src/static/static_sk_svg_fe_morphology.cpp
#        src/static/static_sk_svg_fe_morphology.h
#        src/static/static_sk_svg_fe_offset.cpp
#        src/static/static_sk_svg_fe_offset.h
#        src/static/static_sk_svg_fe_point_light.cpp
#        src/static/static_sk_svg_fe_point_light.h
#        src/static/static_sk_svg_fe_specular_lighting.cpp
#        src/static/static_sk_svg_fe_specular_lighting.h
#        src/static/static_sk_svg_fe_spot_light.cpp
#        src/static/static_sk_svg_fe_spot_light.h
#        src/static/static_sk_svg_fe_turbulence.cpp
#        src/static/static_sk_svg_fe_turbulence.h
#        src/static/static_sk_svg_g.cpp
#        src/static/static_sk_svg_g.h
#        src/static/static_sk_svg_image.cpp
#        src/static/static_sk_svg_image.h
#        src/static/static_sk_svg_line.cpp
#        src/static/static_sk_svg_line.h
#        src/static/static_sk_svg_linear_gradient.cpp
#        src/static/static_sk_svg_linear_gradient.h
#        src/static/static_sk_svg_mask.cpp
#        src/static/static_sk_svg_mask.h
#        src/static/static_sk_svg_node.cpp
#        src/static/static_sk_svg_node.h
#        src/static/static_sk_svg_path.cpp
#        src/static/static_sk_svg_path.h
#        src/static/static_sk_svg_pattern.cpp
#        src/static/static_sk_svg_pattern.h
#        src/static/static_sk_svg_poly.cpp
#        src/static/static_sk_svg_poly.h
#        src/static/static_sk_svg_presentation_attributes.cpp
#        src/static/static_sk_svg_presentation_attributes.h
#        src/static/static_sk_svg_radial_gradient.cpp
#        src/static/static_sk_svg_radial_gradient.h
#        src/static/static_sk_svg_rect.cpp
#        src/static/static_sk_svg_rect.h
#        src/static/static_sk_svg_stop.cpp
#        src/static/static_sk_svg_stop.h
#        src/static/static_sk_svg_svg.cpp
#        src/static/static_sk_svg_svg.h
#        src/static/static_sk_svg_t_span.cpp
#        src/static/static_sk_svg_t_span.h
#        src/static/static_sk_svg_text_literal.cpp
#        src/static/static_sk_svg_text_literal.h
#        src/static/static_sk_svg_text_path.cpp
#        src/static/static_sk_svg_text_path.h
#        src/static/static_sk_svg_text.cpp
#        src/static/static_sk_svg_text.h
#        src/static/static_sk_svg_use.cpp
#        src/static/static_sk_svg_use.h
        src/static/static_sk_text_blob.cpp
        src/static/static_sk_typeface.cpp
        src/static/static_sk_v2.cpp
        src/static/static_sk_v2.h
        src/static/static_sk_v3.cpp
        src/static/static_sk_v3.h
        src/static/static_sk_v4.cpp
        src/static/static_sk_v4.h
        src/static/static_sk_vertices.cpp
        src/static/static_sk_yuva_info.cpp
        src/static/static_sk_yuva_info.h
        src/static/static_sk_yuva_pixmap_info.cpp
        src/static/static_sk_yuva_pixmap_info.h
        src/static/static_sk_yuva_pixmaps.cpp
        src/static/static_sk_yuva_pixmaps.h
        src/static/static_std_chrono_milliseconds.cpp
        src/static/static_std_chrono_milliseconds.h
        src/static/static_std_function_void_void.cpp
        src/static/static_std_function_void_void.h
        src/static/static_std_string_view.cpp
        src/static/static_std_string_view.h
        src/static/static_std_tuple_int_int.cpp
        src/static/static_std_tuple_int_int.h
        src/static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.cpp
        src/static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.h
        src/static/static_std_tuple_sk_image_sk_codec_result.cpp
        src/static/static_std_tuple_sk_image_sk_codec_result.h
        src/static/static_std_vector_sk_codec_frame_info.cpp
        src/static/static_std_vector_sk_codec_frame_info.h
        src/static/static_std_vector_sk_scalar.cpp
        src/static/static_std_vector_sk_scalar.h
        src/static/static_std_vector_sk_svg_length.cpp
        src/static/static_std_vector_sk_svg_length.h
)

get_property(CURRENT_RPATH TARGET raia_skia PROPERTY INSTALL_RPATH)

list(PREPEND CURRENT_RPATH "${SPECIAL_RPATH_KEYWORD}")

#add_library(raia_skia STATIC IMPORTED)
#set_target_properties(raia_skia PROPERTIES IMPORTED_LOCATION libskia.a libskshaper.a)


set_target_properties(raia_skia PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CURRENT_RPATH}")

target_link_libraries(raia_skia
        $<$<PLATFORM_ID:Darwin>: egl glfw.3.4 GLESv2 skia skshaper skparagraph skunicode "-framework CoreFoundation" "-framework CoreText" fontconfig>
        $<$<PLATFORM_ID:Linux>: m dl EGL glfw GLESv2 X11 Xxf86vm Xrandr Xinerama Xcursor pthread Xi>
        $<$<PLATFORM_ID:Windows>: EGL glfw3 GLESv2>
        )

#set_target_properties(raia_skia PROPERTIES PREFIX "")


#--- test
enable_testing()
add_executable(test_c_skia test/test.cpp)
if(APPLE)
find_library(CORE_FOUNDATION CoreFoundation)
find_library(CORE_TEXT CoreText)
target_link_libraries(test_c_skia raia_skia skia "-framework CoreFoundation" ${CORE_FOUNDATION} ${CORE_TEXT} fontconfig)
endif ()
add_test(NAME c_skia_test COMMAND test_c_skia)
#---