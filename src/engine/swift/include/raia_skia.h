//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_SKIA_H
#define RAIA_GUI_RAIA_SKIA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "binding/sk_alpha_type.h"
#include "binding/sk_android_codec.h"
#include "binding/sk_annotation.h"
#include "binding/sk_auto_canvas_restore.h"
// #include "binding/sk_avif_decoder.h.h"
#include "binding/sk_b_box_hierarchy.h"
#include "binding/sk_bitmap.h"
#include "binding/sk_blend_mode.h"
#include "binding/sk_blender.h"
#include "binding/sk_blenders.h"
#include "binding/sk_bmp_decoder.h"
#include "binding/sk_canvas.h"
#include "binding/sk_capabilities.h"
#include "binding/sk_codec.h"
#include "binding/sk_codecs.h"
#include "binding/sk_color_4f.h"
#include "binding/sk_color_filter.h"
#include "binding/sk_color_filters.h"
#include "binding/sk_color_info.h"
#include "binding/sk_color_matrix_filter.h"
#include "binding/sk_color_matrix.h"
#include "binding/sk_color_priv.h"
#include "binding/sk_color_space_primaries.h"
#include "binding/sk_color_space.h"
#include "binding/sk_color_table.h"
#include "binding/sk_color.h"
#include "binding/sk_contour_measure_iter.h"
#include "binding/sk_contour_measure.h"
#include "binding/sk_corner_path_effect.h"
#include "binding/sk_cubic_map.h"
#include "binding/sk_cubic_resampler.h"
#include "binding/sk_dash_path_effect.h"
#include "binding/sk_data_table.h"
#include "binding/sk_data.h"
#include "binding/sk_discrete_path_effect.h"
#include "binding/sk_document.h"
#include "binding/sk_drawable.h"
#include "binding/sk_dynamic_memory_w_stream.h"
#include "binding/sk_encoded_origin.h"
#include "binding/sk_encoder.h"
#include "binding/sk_executor.h"
#include "binding/sk_file_stream.h"
#include "binding/sk_file_w_stream.h"
#include "binding/sk_flattenable.h"
#include "binding/sk_font_arguments.h"
#include "binding/sk_font_metrics.h"
// #include "binding/sk_font_mgr_fontconfig.h"
#include "binding/sk_font_mgr.h"
#include "binding/sk_font_style_set.h"
#include "binding/sk_font_style.h"
#include "binding/sk_font.h"
// #include "binding/sk_gif_decoder.h"
#include "binding/sk_gradient_shader.h"
#include "binding/sk_graphics.h"
#include "binding/sk_high_contrast_config.h"
#include "binding/sk_high_contrast_filter.h"
#include "binding/sk_i_point.h"
#include "binding/sk_i_rect.h"
#include "binding/sk_i_size.h"
#include "binding/sk_icc.h"
#include "binding/sk_ico_cecoder.h"
#include "binding/sk_image_filter.h"
#include "binding/sk_image_filters.h"
#include "binding/sk_image_generator.h"
#include "binding/sk_image_info.h"
#include "binding/sk_image.h"
#include "binding/sk_images.h"
#include "binding/sk_jpeg_decoder.h"
// #include "binding/sk_jpeg_encoder.h"
// #include "binding/sk_jpegxl_decoder.h"
#include "binding/sk_line_2d_path_effect.h"
#include "binding/sk_luma_color_filter.h"
#include "binding/sk_m_44.h"
#include "binding/sk_malloc_pixel_ref.h"
#include "binding/sk_mask.h"
#include "binding/sk_mask_builder.h"
#include "binding/sk_mask_filter.h"
#include "binding/sk_matrix.h"
#include "binding/sk_memory_stream.h"
#include "binding/sk_mesh.h"
#include "binding/sk_mesh_specification.h"
#include "binding/sk_meshes.h"
#include "binding/sk_op_builder.h"
// #include "binding/sk_open_type_svg_decoder.h"
#include "binding/sk_overdraw_canvas.h"
#include "binding/sk_overdraw_color_filter.h"
#include "binding/sk_paint.h"
#include "binding/sk_path_1d_path_effect.h"
#include "binding/sk_path_2d_path_effect.h"
#include "binding/sk_path_builder.h"
#include "binding/sk_path_effect.h"
#include "binding/sk_path_measure.h"
#include "binding/sk_path.h"
// #include "binding/sk_pdf.h"
#include "binding/sk_perlin_noise_shader.h"
#include "binding/sk_picture_recorder.h"
#include "binding/sk_picture.h"
#include "binding/sk_pixel_ref.h"
#include "binding/sk_pixmap_utils.h"
#include "binding/sk_pixmap.h"
#include "binding/sk_png_decoder.h"
#include "binding/sk_png_encoder.h"
#include "binding/sk_point_3.h"
#include "binding/sk_point.h"
#include "binding/sk_r_rect.h"
// #include "binding/sk_raster_handle_allocator.h"
// #include "binding/sk_raw_decoder.h"
#include "binding/sk_read_buffer.h"
#include "binding/sk_rect.h"
#include "binding/sk_ref_cnt_base.h"
#include "binding/sk_ref_cnt.h"
#include "binding/sk_region.h"
#include "binding/sk_rsx_form.h"
#include "binding/sk_runtime_blend_builder.h"
#include "binding/sk_runtime_color_filter_builder.h"
#include "binding/sk_runtime_effect_builder.h"
#include "binding/sk_runtime_effect.h"
#include "binding/sk_runtime_shader_builder.h"
#include "binding/sk_sampling_options.h"
#include "binding/sk_shader_mask_filter.h"
#include "binding/sk_shader.h"
#include "binding/sk_shaders.h"
#include "binding/sk_size.h"
#include "binding/sk_stream_asset.h"
#include "binding/sk_stream_memory.h"
#include "binding/sk_stream_rewindable.h"
#include "binding/sk_stream_seekable.h"
#include "binding/sk_stream.h"
#include "binding/sk_string.h"
#include "binding/sk_stroke_rec.h"
#include "binding/sk_surface_props.h"
#include "binding/sk_surface.h"
#include "binding/sk_surfaces.h"
#include "binding/sk_table_mask_filter.h"
// #include "binding/sk_text_blob_builder_run_handler.h"
#include "binding/sk_text_blob_builder.h"
#include "binding/sk_text_blob.h"
#include "binding/sk_tiled_image_utils.h"
#include "binding/sk_trace_memory_dump.h"
#include "binding/sk_trim_path_effect.h"
#include "binding/sk_typeface_mac.h"
#include "binding/sk_typeface.h"
#include "binding/sk_un_pre_multiply.h"
#include "binding/sk_v2.h"
#include "binding/sk_v3.h"
#include "binding/sk_v4.h"
#include "binding/sk_vertices.h"
#include "binding/sk_w_stream.h"
#include "binding/sk_wbmp_decoder.h"
#include "binding/sk_webp_decoder.h"
// #include "binding/sk_webp_encoder.h"
#include "binding/sk_write_buffer.h"
#include "binding/sk_yuva_info.h"
#include "binding/sk_yuva_pixmap_info.h"
#include "binding/sk_yuva_pixmaps.h"

// Static

#include "static/static_sk_android_codec.h"
#include "static/static_sk_b_box_hierarchy.h"
#include "static/static_sk_blend_mode.h"
#include "static/static_sk_blender.h"
#include "static/static_sk_canvas.h"
#include "static/static_sk_capabilities.h"
#include "static/static_sk_codec.h"
#include "static/static_sk_codecs_decoder.h"
#include "static/static_sk_color_4f.h"
#include "static/static_sk_color_filter.h"
#include "static/static_sk_color_info.h"
#include "static/static_sk_color_matrix.h"
#include "static/static_sk_color_space.h"
#include "static/static_sk_color_table.h"
#include "static/static_sk_color.h"
#include "static/static_sk_contour_measure.h"
#include "static/static_sk_cubic_resampler.h"
#include "static/static_sk_data_table.h"
#include "static/static_sk_data.h"
#include "static/static_sk_document.h"
#include "static/static_sk_drawable_gpu_draw_handler.h"
#include "static/static_sk_drawable.h"
#include "static/static_sk_encoder_frame.h"
#include "static/static_sk_encoder.h"
#include "static/static_sk_executor.h"
#include "static/static_sk_file_stream.h"
#include "static/static_sk_flattenable_factory.h"
#include "static/static_sk_flattenable.h"
#include "static/static_sk_font_arguments_palette.h"
#include "static/static_sk_font_arguments_variation_position.h"
#include "static/static_sk_font_arguments.h"
#include "static/static_sk_font_mgr.h"
#include "static/static_sk_font_style_set.h"
#include "static/static_sk_font_style.h"
#include "static/static_sk_font.h"
#include "static/static_sk_i_point.h"
#include "static/static_sk_i_rect.h"
#include "static/static_sk_i_size.h"
#include "static/static_sk_id_change_listener.h"
#include "static/static_sk_image_filter.h"
#include "static/static_sk_image_generator.h"
#include "static/static_sk_image_info.h"
#include "static/static_sk_image_read_pixels_callback.h"
#include "static/static_sk_image_required_properties.h"
#include "static/static_sk_image.h"
#include "static/static_sk_m_44.h"
#include "static/static_sk_mask.h"
#include "static/static_sk_mask_builder.h"
#include "static/static_sk_mask_filter.h"
#include "static/static_sk_matrix.h"
#include "static/static_sk_memory_stream.h"
#include "static/static_sk_mesh_child_ptr.h"
#include "static/static_sk_mesh_index_buffer.h"
#include "static/static_sk_mesh_vertex_buffer.h"
#include "static/static_sk_mesh_result.h"
#include "static/static_sk_mesh_specification_attribute.h"
#include "static/static_sk_mesh_specification_result.h"
#include "static/static_sk_mesh_specification.h"
#include "static/static_sk_path_effect.h"
#include "static/static_sk_path.h"
#include "static/static_sk_picture.h"
#include "static/static_sk_pixel_ref.h"
#include "static/static_sk_pixmap.h"
#include "static/static_sk_point_3.h"
#include "static/static_sk_point_two.h"
#include "static/static_sk_point.h"
#include "static/static_sk_r_rect.h"
#include "static/static_sk_rect.h"
#include "static/static_sk_rsx_form.h"
#include "static/static_sk_runtime_effect_builder_builder_child.h"
#include "static/static_sk_runtime_effect_builder_builder_uniform.h"
#include "static/static_sk_runtime_effect_child_ptr.h"
#include "static/static_sk_runtime_effect_child.h"
#include "static/static_sk_runtime_effect_result.h"
#include "static/static_sk_runtime_effect_traced_shader.h"
#include "static/static_sk_runtime_effect_uniform.h"
#include "static/static_sk_runtime_effect.h"
#include "static/static_sk_sampling_options.h"
#include "static/static_sk_shader.h"
#include "static/static_sk_size_t.h"
#include "static/static_sk_stream_asset.h"
#include "static/static_sk_stream_memory.h"
#include "static/static_sk_stream_rewindable.h"
#include "static/static_sk_stream_seekable.h"
#include "static/static_sk_stream.h"
#include "static/static_sk_string.h"
#include "static/static_sk_stroke_rec.h"
#include "static/static_sk_surface_props.h"
#include "static/static_sk_surface.h"
#include "static/static_sk_text_blob.h"
#include "static/static_sk_typeface.h"
#include "static/static_sk_v2.h"
#include "static/static_sk_v3.h"
#include "static/static_sk_v4.h"
#include "static/static_sk_vertices.h"
#include "static/static_sk_yuva_info.h"
#include "static/static_sk_yuva_pixmap_info.h"
#include "static/static_sk_yuva_pixmaps.h"
#include "static/static_std_chrono_milliseconds.h"
#include "static/static_std_function_void_void.h"
#include "static/static_std_string_view.h"
#include "static/static_std_tuple_int_int.h"
#include "static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"
#include "static/static_std_tuple_sk_image_sk_codec_result.h"
#include "static/static_std_vector_int_ptr.h"
#include "static/static_std_vector_sk_codec_frame_info.h"
#include "static/static_std_vector_sk_scalar.h"

#ifdef __cplusplus
}
#endif

#endif //RAIA_GUI_RAIA_SKIA_H
