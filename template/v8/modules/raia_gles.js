import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_GLES__ === undefined) {
        globalThis.__RAIA_GLES__ = {};
        globalThis.__RAIA_GLES__.handle = lib.open("raia_gles");
        //
        // GL ES 2.0
        //
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_active_texture");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_attach_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_attrib_location");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_framebuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_renderbuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_texture");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_color");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_equation");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_equation_separate");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_func");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_func_separate");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_buffer_data");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_buffer_sub_data");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_check_framebuffer_status");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_color");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_depth_f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_stencil");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_color_mask");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compile_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compressed_tex_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compressed_tex_sub_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_copy_tex_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_copy_tex_sub_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_create_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_create_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_cull_face");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_buffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_framebuffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_renderbuffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_textures");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_depth_func");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_depth_mask");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_depth_range_f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_detach_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_disable");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_disable_vertex_attrib_array");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_arrays");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_enable");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_enable_vertex_attrib_array");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_finish");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_flush");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_framebuffer_renderbuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_framebuffer_texture_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_front_face");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_buffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_generate_mipmap");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_framebuffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_renderbuffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_textures");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_active_attrib");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_active_uniform");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_attached_shaders");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_attrib_location");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_boolean_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_buffer_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_error");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_float_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_framebuffer_attachment_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_integer_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_info_log");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_renderbuffer_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_info_log");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_precision_format");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_source");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_string");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_parameter_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_location");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_vertex_attrib_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_vertex_attrib_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_vertex_attrib_pointer_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_hint");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_enabled");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_framebuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_renderbuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_shader");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_texture");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_line_width");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_link_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_pixel_store_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_polygon_offset");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_read_pixels");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_release_shader_compiler");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_renderbuffer_storage");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sample_coverage");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_scissor");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_shader_binary");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_shader_source");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_func");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_func_separate");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_mask");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_mask_separate");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_op");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_stencil_op_separate");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_sub_image_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_4f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_4i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform4iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_use_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_validate_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_1f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_1fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_2f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_3f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_4f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_pointer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_viewport");
        //
        // GL ES 3.0
        //
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_read_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_range_elements");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_image_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_sub_image_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_copy_tex_sub_image_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compressed_tex_image_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compressed_tex_sub_image_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_queries");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_queries");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_query");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_begin_query");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_end_query");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_query_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_query_object_uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_unmap_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_buffer_pointer_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_buffers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_2x3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_3x2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_2x4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_4x2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_3x4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_matrix_4x3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blit_framebuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_renderbuffer_storage_multisample");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_framebuffer_texture_layer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_map_buffer_range");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_flush_mapped_buffer_range");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_vertex_array");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_vertex_arrays");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_vertex_arrays");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_vertex_array");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_integer_i_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_begin_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_end_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_buffer_range");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_buffer_base");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_transform_feedback_varyings");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_transform_feedback_varying");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i_pointer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_vertex_attrib_iiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_vertex_attrib_iuiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i4i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i4ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i4iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i4uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_frag_data_location");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_4ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_2uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_3uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_4uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_buffer_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_buffer_uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_buffer_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_buffer_fi");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_string_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_copy_buffer_sub_data");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_indices");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_active_uniforms_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_block_index");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_active_uniform_block_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_active_uniform_block_name");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_block_binding");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_arrays_instanced");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_instanced");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_fence_sync");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_sync");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_sync");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_client_wait_sync");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_wait_sync");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_integer_64v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_sync_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_integer_64i_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_buffer_parameter_i64v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_samplers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_samplers");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_sampler");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_sampler");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_sampler_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_sampler_parameter_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_divisor");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_transform_feedbacks");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_transform_feedbacks");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_pause_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_resume_transform_feedback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_binary");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_binary");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_parameter_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_invalidate_framebuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_invalidate_sub_framebuffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_storage_2d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_storage_3d");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_internal_format_iv");
        //
        // GL ES 3.1
        //
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_dispatch_compute");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_dispatch_compute_indirect");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_arrays_indirect");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_indirect");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_framebuffer_parameter_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_framebuffer_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_interface_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_resource_index");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_resource_name");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_resource_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_resource_location");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_use_program_stages");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_active_shader_program");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_create_shader_program_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_program_pipeline");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_program_pipelines");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_program_pipelines");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_program_pipeline");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_pipeline_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4ui");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4f");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_1fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_2x3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_3x2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_2x4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_4x2fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_3x4fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_program_uniform_matrix_4x3fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_validate_program_pipeline");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_program_pipeline_info_log");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_image_texture");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_boolean_i_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_memory_barrier");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_memory_barrier_by_region");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_storage_2d_multisample");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_multisample_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sample_mask_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_level_parameter_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_level_parameter_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_vertex_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_format");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_i_format");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_binding");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_binding_divisor");
        //
        // GL ES 3.2
        //
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_barrier");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_copy_image_sub_data");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_debug_message_control");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_debug_message_insert");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_debug_message_callback");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_debug_message_log");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_push_debug_group");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_pop_debug_group");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_object_label");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_object_label");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_object_ptr_label");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_object_ptr_label");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_pointer_v");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_enable_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_disable_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_equation_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_equation_separate_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_func_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_blend_func_separate_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_color_mask_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_is_enabled_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_base_vertex");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_range_elements_base_vertex");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_instanced_base_vertex");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_framebuffer_texture");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_primitive_bounding_box");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_graphics_reset_status");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_read_n_pixels");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_n_uniform_fv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_n_uniform_iv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_n_uniform_uiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_min_sample_shading");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_patch_parameter_i");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_iiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_iuiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_parameter_iiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_tex_parameter_iuiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_iiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_sampler_parameter_iuiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_sampler_parameter_iiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_sampler_parameter_iuiv");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_buffer");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_buffer_range");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_storage_3d_multisample");        
        //
        // (代替関数)
        //
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_viewport_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_color_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_use_program_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_pointer_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_enable_vertex_attrib_array_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_image_2d_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_active_texture_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_texture_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1i_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_create_shader_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_shader_source_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_compile_shader_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_iv_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_create_program_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_attach_shader_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_shader_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_link_program_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_pixel_store_i_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_textures_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_i_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_attrib_location_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_location_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_vertex_arrays_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_buffers_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_vertex_array_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_buffer_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_buffer_data_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_vertex_arrays_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_buffers_alt");
        lib.add(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_textures_alt");
    }
})();

export class GLES {
    //
    // GL ES 2.0
    //
    static DEPTH_BUFFER_BIT = 0x00000100;
    static STENCIL_BUFFER_BIT = 0x00000400;
    static COLOR_BUFFER_BIT = 0x00004000;
    static FALSE = 0;
    static TRUE = 1;
    static POINTS = 0x0000;
    static LINES = 0x0001;
    static LINE_LOOP = 0x0002;
    static LINE_STRIP = 0x0003;
    static TRIANGLES = 0x0004;
    static TRIANGLE_STRIP = 0x0005;
    static TRIANGLE_FAN = 0x0006;
    static ZERO = 0;
    static ONE = 1;
    static SRC_COLOR = 0x0300;
    static ONE_MINUS_SRC_COLOR = 0x0301;
    static SRC_ALPHA = 0x0302;
    static ONE_MINUS_SRC_ALPHA = 0x0303;
    static DST_ALPHA = 0x0304;
    static ONE_MINUS_DST_ALPHA = 0x0305;
    static DST_COLOR = 0x0306;
    static ONE_MINUS_DST_COLOR = 0x0307;
    static SRC_ALPHA_SATURATE = 0x0308;
    static FUNC_ADD = 0x8006;
    static BLEND_EQUATION = 0x8009;
    static BLEND_EQUATION_RGB = 0x8009;
    static BLEND_EQUATION_ALPHA = 0x883D;
    static FUNC_SUBTRACT = 0x800A;
    static FUNC_REVERSE_SUBTRACT = 0x800B;
    static BLEND_DST_RGB = 0x80C8;
    static BLEND_SRC_RGB = 0x80C9;
    static BLEND_DST_ALPHA = 0x80CA;
    static BLEND_SRC_ALPHA = 0x80CB;
    static CONSTANT_COLOR = 0x8001;
    static ONE_MINUS_CONSTANT_COLOR = 0x8002;
    static CONSTANT_ALPHA = 0x8003;
    static ONE_MINUS_CONSTANT_ALPHA = 0x8004;
    static BLEND_COLOR = 0x8005;
    static ARRAY_BUFFER = 0x8892;
    static ELEMENT_ARRAY_BUFFER = 0x8893;
    static ARRAY_BUFFER_BINDING = 0x8894;
    static ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
    static STREAM_DRAW = 0x88E0;
    static STATIC_DRAW = 0x88E4;
    static DYNAMIC_DRAW = 0x88E8;
    static BUFFER_SIZE = 0x8764;
    static BUFFER_USAGE = 0x8765;
    static CURRENT_VERTEX_ATTRIB = 0x8626;
    static FRONT = 0x0404;
    static BACK = 0x0405;
    static FRONT_AND_BACK = 0x0408;
    static TEXTURE_2D = 0x0DE1;
    static CULL_FACE = 0x0B44;
    static BLEND = 0x0BE2;
    static DITHER = 0x0BD0;
    static STENCIL_TEST = 0x0B90;
    static DEPTH_TEST = 0x0B71;
    static SCISSOR_TEST = 0x0C11;
    static POLYGON_OFFSET_FILL = 0x8037;
    static SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
    static SAMPLE_COVERAGE = 0x80A0;
    static NO_ERROR = 0;
    static INVALID_ENUM = 0x0500;
    static INVALID_VALUE = 0x0501;
    static INVALID_OPERATION = 0x0502;
    static OUT_OF_MEMORY = 0x0505;
    static CW = 0x0900;
    static CCW = 0x0901;
    static LINE_WIDTH = 0x0B21;
    static ALIASED_POINT_SIZE_RANGE = 0x846D;
    static ALIASED_LINE_WIDTH_RANGE = 0x846E;
    static CULL_FACE_MODE = 0x0B45;
    static FRONT_FACE = 0x0B46;
    static DEPTH_RANGE = 0x0B70;
    static DEPTH_WRITEMASK = 0x0B72;
    static DEPTH_CLEAR_VALUE = 0x0B73;
    static DEPTH_FUNC = 0x0B74;
    static STENCIL_CLEAR_VALUE = 0x0B91;
    static STENCIL_FUNC = 0x0B92;
    static STENCIL_FAIL = 0x0B94;
    static STENCIL_PASS_DEPTH_FAIL = 0x0B95;
    static STENCIL_PASS_DEPTH_PASS = 0x0B96;
    static STENCIL_REF = 0x0B97;
    static STENCIL_VALUE_MASK = 0x0B93;
    static STENCIL_WRITEMASK = 0x0B98;
    static STENCIL_BACK_FUNC = 0x8800;
    static STENCIL_BACK_FAIL = 0x8801;
    static STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
    static STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
    static STENCIL_BACK_REF = 0x8CA3;
    static STENCIL_BACK_VALUE_MASK = 0x8CA4;
    static STENCIL_BACK_WRITEMASK = 0x8CA5;
    static VIEWPORT = 0x0BA2;
    static SCISSOR_BOX = 0x0C10;
    static COLOR_CLEAR_VALUE = 0x0C22;
    static COLOR_WRITEMASK = 0x0C23;
    static UNPACK_ALIGNMENT = 0x0CF5;
    static PACK_ALIGNMENT = 0x0D05;
    static MAX_TEXTURE_SIZE = 0x0D33;
    static MAX_VIEWPORT_DIMS = 0x0D3A;
    static SUBPIXEL_BITS = 0x0D50;
    static RED_BITS = 0x0D52;
    static GREEN_BITS = 0x0D53;
    static BLUE_BITS = 0x0D54;
    static ALPHA_BITS = 0x0D55;
    static DEPTH_BITS = 0x0D56;
    static STENCIL_BITS = 0x0D57;
    static POLYGON_OFFSET_UNITS = 0x2A00;
    static POLYGON_OFFSET_FACTOR = 0x8038;
    static TEXTURE_BINDING_2D = 0x8069;
    static SAMPLE_BUFFERS = 0x80A8;
    static SAMPLES = 0x80A9;
    static SAMPLE_COVERAGE_VALUE = 0x80AA;
    static SAMPLE_COVERAGE_INVERT = 0x80AB;
    static NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
    static COMPRESSED_TEXTURE_FORMATS = 0x86A3;
    static DONT_CARE = 0x1100;
    static FASTEST = 0x1101;
    static NICEST = 0x1102;
    static GENERATE_MIPMAP_HINT = 0x8192;
    static BYTE = 0x1400;
    static UNSIGNED_BYTE = 0x1401;
    static SHORT = 0x1402;
    static UNSIGNED_SHORT = 0x1403;
    static INT = 0x1404;
    static UNSIGNED_INT = 0x1405;
    static FLOAT = 0x1406;
    static FIXED = 0x140C;
    static DEPTH_COMPONENT = 0x1902;
    static ALPHA = 0x1906;
    static RGB = 0x1907;
    static RGBA = 0x1908;
    static LUMINANCE = 0x1909;
    static LUMINANCE_ALPHA = 0x190A;
    static UNSIGNED_SHORT_4_4_4_4 = 0x8033;
    static UNSIGNED_SHORT_5_5_5_1 = 0x8034;
    static UNSIGNED_SHORT_5_6_5 = 0x8363;
    static FRAGMENT_SHADER = 0x8B30;
    static VERTEX_SHADER = 0x8B31;
    static MAX_VERTEX_ATTRIBS = 0x8869;
    static MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
    static MAX_VARYING_VECTORS = 0x8DFC;
    static MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
    static MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
    static MAX_TEXTURE_IMAGE_UNITS = 0x8872;
    static MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
    static SHADER_TYPE = 0x8B4F;
    static DELETE_STATUS = 0x8B80;
    static LINK_STATUS = 0x8B82;
    static VALIDATE_STATUS = 0x8B83;
    static ATTACHED_SHADERS = 0x8B85;
    static ACTIVE_UNIFORMS = 0x8B86;
    static ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
    static ACTIVE_ATTRIBUTES = 0x8B89;
    static ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
    static SHADING_LANGUAGE_VERSION = 0x8B8C;
    static CURRENT_PROGRAM = 0x8B8D;
    static NEVER = 0x0200;
    static LESS = 0x0201;
    static EQUAL = 0x0202;
    static LEQUAL = 0x0203;
    static GREATER = 0x0204;
    static NOTEQUAL = 0x0205;
    static GEQUAL = 0x0206;
    static ALWAYS = 0x0207;
    static KEEP = 0x1E00;
    static REPLACE = 0x1E01;
    static INCR = 0x1E02;
    static DECR = 0x1E03;
    static INVERT = 0x150A;
    static INCR_WRAP = 0x8507;
    static DECR_WRAP = 0x8508;
    static VENDOR = 0x1F00;
    static RENDERER = 0x1F01;
    static VERSION = 0x1F02;
    static EXTENSIONS = 0x1F03;
    static NEAREST = 0x2600;
    static LINEAR = 0x2601;
    static NEAREST_MIPMAP_NEAREST = 0x2700;
    static LINEAR_MIPMAP_NEAREST = 0x2701;
    static NEAREST_MIPMAP_LINEAR = 0x2702;
    static LINEAR_MIPMAP_LINEAR = 0x2703;
    static TEXTURE_MAG_FILTER = 0x2800;
    static TEXTURE_MIN_FILTER = 0x2801;
    static TEXTURE_WRAP_S = 0x2802;
    static TEXTURE_WRAP_T = 0x2803;
    static TEXTURE = 0x1702;
    static TEXTURE_CUBE_MAP = 0x8513;
    static TEXTURE_BINDING_CUBE_MAP = 0x8514;
    static TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
    static TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
    static TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
    static TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
    static TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
    static TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
    static MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
    static TEXTURE0 = 0x84C0;
    static TEXTURE1 = 0x84C1;
    static TEXTURE2 = 0x84C2;
    static TEXTURE3 = 0x84C3;
    static TEXTURE4 = 0x84C4;
    static TEXTURE5 = 0x84C5;
    static TEXTURE6 = 0x84C6;
    static TEXTURE7 = 0x84C7;
    static TEXTURE8 = 0x84C8;
    static TEXTURE9 = 0x84C9;
    static TEXTURE10 = 0x84CA;
    static TEXTURE11 = 0x84CB;
    static TEXTURE12 = 0x84CC;
    static TEXTURE13 = 0x84CD;
    static TEXTURE14 = 0x84CE;
    static TEXTURE15 = 0x84CF;
    static TEXTURE16 = 0x84D0;
    static TEXTURE17 = 0x84D1;
    static TEXTURE18 = 0x84D2;
    static TEXTURE19 = 0x84D3;
    static TEXTURE20 = 0x84D4;
    static TEXTURE21 = 0x84D5;
    static TEXTURE22 = 0x84D6;
    static TEXTURE23 = 0x84D7;
    static TEXTURE24 = 0x84D8;
    static TEXTURE25 = 0x84D9;
    static TEXTURE26 = 0x84DA;
    static TEXTURE27 = 0x84DB;
    static TEXTURE28 = 0x84DC;
    static TEXTURE29 = 0x84DD;
    static TEXTURE30 = 0x84DE;
    static TEXTURE31 = 0x84DF;
    static ACTIVE_TEXTURE = 0x84E0;
    static REPEAT = 0x2901;
    static CLAMP_TO_EDGE = 0x812F;
    static MIRRORED_REPEAT = 0x8370;
    static FLOAT_VEC2 = 0x8B50;
    static FLOAT_VEC3 = 0x8B51;
    static FLOAT_VEC4 = 0x8B52;
    static INT_VEC2 = 0x8B53;
    static INT_VEC3 = 0x8B54;
    static INT_VEC4 = 0x8B55;
    static BOOL = 0x8B56;
    static BOOL_VEC2 = 0x8B57;
    static BOOL_VEC3 = 0x8B58;
    static BOOL_VEC4 = 0x8B59;
    static FLOAT_MAT2 = 0x8B5A;
    static FLOAT_MAT3 = 0x8B5B;
    static FLOAT_MAT4 = 0x8B5C;
    static SAMPLER_2D = 0x8B5E;
    static SAMPLER_CUBE = 0x8B60;
    static VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
    static VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
    static VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
    static VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
    static VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
    static VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
    static VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
    static IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
    static IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
    static COMPILE_STATUS = 0x8B81;
    static INFO_LOG_LENGTH = 0x8B84;
    static SHADER_SOURCE_LENGTH = 0x8B88;
    static SHADER_COMPILER = 0x8DFA;
    static SHADER_BINARY_FORMATS = 0x8DF8;
    static NUM_SHADER_BINARY_FORMATS = 0x8DF9;
    static LOW_FLOAT = 0x8DF0;
    static MEDIUM_FLOAT = 0x8DF1;
    static HIGH_FLOAT = 0x8DF2;
    static LOW_INT = 0x8DF3;
    static MEDIUM_INT = 0x8DF4;
    static HIGH_INT = 0x8DF5;
    static FRAMEBUFFER = 0x8D40;
    static RENDERBUFFER = 0x8D41;
    static RGBA4 = 0x8056;
    static RGB5_A1 = 0x8057;
    static RGB565 = 0x8D62;
    static DEPTH_COMPONENT16 = 0x81A5;
    static STENCIL_INDEX8 = 0x8D48;
    static RENDERBUFFER_WIDTH = 0x8D42;
    static RENDERBUFFER_HEIGHT = 0x8D43;
    static RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
    static RENDERBUFFER_RED_SIZE = 0x8D50;
    static RENDERBUFFER_GREEN_SIZE = 0x8D51;
    static RENDERBUFFER_BLUE_SIZE = 0x8D52;
    static RENDERBUFFER_ALPHA_SIZE = 0x8D53;
    static RENDERBUFFER_DEPTH_SIZE = 0x8D54;
    static RENDERBUFFER_STENCIL_SIZE = 0x8D55;
    static FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
    static FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
    static FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
    static FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
    static COLOR_ATTACHMENT0 = 0x8CE0;
    static DEPTH_ATTACHMENT = 0x8D00;
    static STENCIL_ATTACHMENT = 0x8D20;
    static NONE = 0;
    static FRAMEBUFFER_COMPLETE = 0x8CD5;
    static FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
    static FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
    static FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9;
    static FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
    static FRAMEBUFFER_BINDING = 0x8CA6;
    static RENDERBUFFER_BINDING = 0x8CA7;
    static MAX_RENDERBUFFER_SIZE = 0x84E8;
    static INVALID_FRAMEBUFFER_OPERATION = 0x0506;
    //
    // GL ES 3.0
    //
    static READ_BUFFER = 0x0C02;
    static UNPACK_ROW_LENGTH = 0x0CF2;
    static UNPACK_SKIP_ROWS = 0x0CF3;
    static UNPACK_SKIP_PIXELS = 0x0CF4;
    static PACK_ROW_LENGTH = 0x0D02;
    static PACK_SKIP_ROWS = 0x0D03;
    static PACK_SKIP_PIXELS = 0x0D04;
    static COLOR = 0x1800;
    static DEPTH = 0x1801;
    static STENCIL = 0x1802;
    static RED = 0x1903;
    static RGB8 = 0x8051;
    static RGBA8 = 0x8058;
    static RGB10_A2 = 0x8059;
    static TEXTURE_BINDING_3D = 0x806A;
    static UNPACK_SKIP_IMAGES = 0x806D;
    static UNPACK_IMAGE_HEIGHT = 0x806E;
    static TEXTURE_3D = 0x806F;
    static TEXTURE_WRAP_R = 0x8072;
    static MAX_3D_TEXTURE_SIZE = 0x8073;
    static UNSIGNED_INT_2_10_10_10_REV = 0x8368;
    static MAX_ELEMENTS_VERTICES = 0x80E8;
    static MAX_ELEMENTS_INDICES = 0x80E9;
    static TEXTURE_MIN_LOD = 0x813A;
    static TEXTURE_MAX_LOD = 0x813B;
    static TEXTURE_BASE_LEVEL = 0x813C;
    static TEXTURE_MAX_LEVEL = 0x813D;
    static MIN = 0x8007;
    static MAX = 0x8008;
    static DEPTH_COMPONENT24 = 0x81A6;
    static MAX_TEXTURE_LOD_BIAS = 0x84FD;
    static TEXTURE_COMPARE_MODE = 0x884C;
    static TEXTURE_COMPARE_FUNC = 0x884D;
    static CURRENT_QUERY = 0x8865;
    static QUERY_RESULT = 0x8866;
    static QUERY_RESULT_AVAILABLE = 0x8867;
    static BUFFER_MAPPED = 0x88BC;
    static BUFFER_MAP_POINTER = 0x88BD;
    static STREAM_READ = 0x88E1;
    static STREAM_COPY = 0x88E2;
    static STATIC_READ = 0x88E5;
    static STATIC_COPY = 0x88E6;
    static DYNAMIC_READ = 0x88E9;
    static DYNAMIC_COPY = 0x88EA;
    static MAX_DRAW_BUFFERS = 0x8824;
    static DRAW_BUFFER0 = 0x8825;
    static DRAW_BUFFER1 = 0x8826;
    static DRAW_BUFFER2 = 0x8827;
    static DRAW_BUFFER3 = 0x8828;
    static DRAW_BUFFER4 = 0x8829;
    static DRAW_BUFFER5 = 0x882A;
    static DRAW_BUFFER6 = 0x882B;
    static DRAW_BUFFER7 = 0x882C;
    static DRAW_BUFFER8 = 0x882D;
    static DRAW_BUFFER9 = 0x882E;
    static DRAW_BUFFER10 = 0x882F;
    static DRAW_BUFFER11 = 0x8830;
    static DRAW_BUFFER12 = 0x8831;
    static DRAW_BUFFER13 = 0x8832;
    static DRAW_BUFFER14 = 0x8833;
    static DRAW_BUFFER15 = 0x8834;
    static MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
    static MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
    static SAMPLER_3D = 0x8B5F;
    static SAMPLER_2D_SHADOW = 0x8B62;
    static FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
    static PIXEL_PACK_BUFFER = 0x88EB;
    static PIXEL_UNPACK_BUFFER = 0x88EC;
    static PIXEL_PACK_BUFFER_BINDING = 0x88ED;
    static PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
    static FLOAT_MAT2x3 = 0x8B65;
    static FLOAT_MAT2x4 = 0x8B66;
    static FLOAT_MAT3x2 = 0x8B67;
    static FLOAT_MAT3x4 = 0x8B68;
    static FLOAT_MAT4x2 = 0x8B69;
    static FLOAT_MAT4x3 = 0x8B6A;
    static SRGB = 0x8C40;
    static SRGB8 = 0x8C41;
    static SRGB8_ALPHA8 = 0x8C43;
    static COMPARE_REF_TO_TEXTURE = 0x884E;
    static MAJOR_VERSION = 0x821B;
    static MINOR_VERSION = 0x821C;
    static NUM_EXTENSIONS = 0x821D;
    static RGBA32F = 0x8814;
    static RGB32F = 0x8815;
    static RGBA16F = 0x881A;
    static RGB16F = 0x881B;
    static VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
    static MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
    static MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
    static MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
    static MAX_VARYING_COMPONENTS = 0x8B4B;
    static TEXTURE_2D_ARRAY = 0x8C1A;
    static TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
    static R11F_G11F_B10F = 0x8C3A;
    static UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
    static RGB9_E5 = 0x8C3D;
    static UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
    static TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
    static TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
    static MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
    static TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
    static TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
    static TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
    static TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
    static RASTERIZER_DISCARD = 0x8C89;
    static MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
    static MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
    static INTERLEAVED_ATTRIBS = 0x8C8C;
    static SEPARATE_ATTRIBS = 0x8C8D;
    static TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
    static TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
    static RGBA32UI = 0x8D70;
    static RGB32UI = 0x8D71;
    static RGBA16UI = 0x8D76;
    static RGB16UI = 0x8D77;
    static RGBA8UI = 0x8D7C;
    static RGB8UI = 0x8D7D;
    static RGBA32I = 0x8D82;
    static RGB32I = 0x8D83;
    static RGBA16I = 0x8D88;
    static RGB16I = 0x8D89;
    static RGBA8I = 0x8D8E;
    static RGB8I = 0x8D8F;
    static RED_INTEGER = 0x8D94;
    static RGB_INTEGER = 0x8D98;
    static RGBA_INTEGER = 0x8D99;
    static SAMPLER_2D_ARRAY = 0x8DC1;
    static SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
    static SAMPLER_CUBE_SHADOW = 0x8DC5;
    static UNSIGNED_INT_VEC2 = 0x8DC6;
    static UNSIGNED_INT_VEC3 = 0x8DC7;
    static UNSIGNED_INT_VEC4 = 0x8DC8;
    static INT_SAMPLER_2D = 0x8DCA;
    static INT_SAMPLER_3D = 0x8DCB;
    static INT_SAMPLER_CUBE = 0x8DCC;
    static INT_SAMPLER_2D_ARRAY = 0x8DCF;
    static UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
    static UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
    static UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
    static UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
    static BUFFER_ACCESS_FLAGS = 0x911F;
    static BUFFER_MAP_LENGTH = 0x9120;
    static BUFFER_MAP_OFFSET = 0x9121;
    static DEPTH_COMPONENT32F = 0x8CAC;
    static DEPTH32F_STENCIL8 = 0x8CAD;
    static FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
    static FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
    static FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
    static FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
    static FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
    static FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
    static FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
    static FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
    static FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
    static FRAMEBUFFER_DEFAULT = 0x8218;
    static FRAMEBUFFER_UNDEFINED = 0x8219;
    static DEPTH_STENCIL_ATTACHMENT = 0x821A;
    static DEPTH_STENCIL = 0x84F9;
    static UNSIGNED_INT_24_8 = 0x84FA;
    static DEPTH24_STENCIL8 = 0x88F0;
    static UNSIGNED_NORMALIZED = 0x8C17;
    static DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
    static READ_FRAMEBUFFER = 0x8CA8;
    static DRAW_FRAMEBUFFER = 0x8CA9;
    static READ_FRAMEBUFFER_BINDING = 0x8CAA;
    static RENDERBUFFER_SAMPLES = 0x8CAB;
    static FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
    static MAX_COLOR_ATTACHMENTS = 0x8CDF;
    static COLOR_ATTACHMENT1 = 0x8CE1;
    static COLOR_ATTACHMENT2 = 0x8CE2;
    static COLOR_ATTACHMENT3 = 0x8CE3;
    static COLOR_ATTACHMENT4 = 0x8CE4;
    static COLOR_ATTACHMENT5 = 0x8CE5;
    static COLOR_ATTACHMENT6 = 0x8CE6;
    static COLOR_ATTACHMENT7 = 0x8CE7;
    static COLOR_ATTACHMENT8 = 0x8CE8;
    static COLOR_ATTACHMENT9 = 0x8CE9;
    static COLOR_ATTACHMENT10 = 0x8CEA;
    static COLOR_ATTACHMENT11 = 0x8CEB;
    static COLOR_ATTACHMENT12 = 0x8CEC;
    static COLOR_ATTACHMENT13 = 0x8CED;
    static COLOR_ATTACHMENT14 = 0x8CEE;
    static COLOR_ATTACHMENT15 = 0x8CEF;
    static COLOR_ATTACHMENT16 = 0x8CF0;
    static COLOR_ATTACHMENT17 = 0x8CF1;
    static COLOR_ATTACHMENT18 = 0x8CF2;
    static COLOR_ATTACHMENT19 = 0x8CF3;
    static COLOR_ATTACHMENT20 = 0x8CF4;
    static COLOR_ATTACHMENT21 = 0x8CF5;
    static COLOR_ATTACHMENT22 = 0x8CF6;
    static COLOR_ATTACHMENT23 = 0x8CF7;
    static COLOR_ATTACHMENT24 = 0x8CF8;
    static COLOR_ATTACHMENT25 = 0x8CF9;
    static COLOR_ATTACHMENT26 = 0x8CFA;
    static COLOR_ATTACHMENT27 = 0x8CFB;
    static COLOR_ATTACHMENT28 = 0x8CFC;
    static COLOR_ATTACHMENT29 = 0x8CFD;
    static COLOR_ATTACHMENT30 = 0x8CFE;
    static COLOR_ATTACHMENT31 = 0x8CFF;
    static FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
    static MAX_SAMPLES = 0x8D57;
    static HALF_FLOAT = 0x140B;
    static MAP_READ_BIT = 0x0001;
    static MAP_WRITE_BIT = 0x0002;
    static MAP_INVALIDATE_RANGE_BIT = 0x0004;
    static MAP_INVALIDATE_BUFFER_BIT = 0x0008;
    static MAP_FLUSH_EXPLICIT_BIT = 0x0010;
    static MAP_UNSYNCHRONIZED_BIT = 0x0020;
    static RG = 0x8227;
    static RG_INTEGER = 0x8228;
    static R8 = 0x8229;
    static RG8 = 0x822B;
    static R16F = 0x822D;
    static R32F = 0x822E;
    static RG16F = 0x822F;
    static RG32F = 0x8230;
    static R8I = 0x8231;
    static R8UI = 0x8232;
    static R16I = 0x8233;
    static R16UI = 0x8234;
    static R32I = 0x8235;
    static R32UI = 0x8236;
    static RG8I = 0x8237;
    static RG8UI = 0x8238;
    static RG16I = 0x8239;
    static RG16UI = 0x823A;
    static RG32I = 0x823B;
    static RG32UI = 0x823C;
    static VERTEX_ARRAY_BINDING = 0x85B5;
    static R8_SNORM = 0x8F94;
    static RG8_SNORM = 0x8F95;
    static RGB8_SNORM = 0x8F96;
    static RGBA8_SNORM = 0x8F97;
    static SIGNED_NORMALIZED = 0x8F9C;
    static PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69;
    static COPY_READ_BUFFER = 0x8F36;
    static COPY_WRITE_BUFFER = 0x8F37;
    static COPY_READ_BUFFER_BINDING = 0x8F36;
    static COPY_WRITE_BUFFER_BINDING = 0x8F37;
    static UNIFORM_BUFFER = 0x8A11;
    static UNIFORM_BUFFER_BINDING = 0x8A28;
    static UNIFORM_BUFFER_START = 0x8A29;
    static UNIFORM_BUFFER_SIZE = 0x8A2A;
    static MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
    static MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
    static MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
    static MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
    static MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
    static MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
    static MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
    static UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
    static ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
    static ACTIVE_UNIFORM_BLOCKS = 0x8A36;
    static UNIFORM_TYPE = 0x8A37;
    static UNIFORM_SIZE = 0x8A38;
    static UNIFORM_NAME_LENGTH = 0x8A39;
    static UNIFORM_BLOCK_INDEX = 0x8A3A;
    static UNIFORM_OFFSET = 0x8A3B;
    static UNIFORM_ARRAY_STRIDE = 0x8A3C;
    static UNIFORM_MATRIX_STRIDE = 0x8A3D;
    static UNIFORM_IS_ROW_MAJOR = 0x8A3E;
    static UNIFORM_BLOCK_BINDING = 0x8A3F;
    static UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
    static UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
    static UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
    static UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
    static UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
    static UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
    static INVALID_INDEX = 0xFFFFFFFF;
    static MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
    static MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
    static MAX_SERVER_WAIT_TIMEOUT = 0x9111;
    static OBJECT_TYPE = 0x9112;
    static SYNC_CONDITION = 0x9113;
    static SYNC_STATUS = 0x9114;
    static SYNC_FLAGS = 0x9115;
    static SYNC_FENCE = 0x9116;
    static SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
    static UNSIGNALED = 0x9118;
    static SIGNALED = 0x9119;
    static ALREADY_SIGNALED = 0x911A;
    static TIMEOUT_EXPIRED = 0x911B;
    static CONDITION_SATISFIED = 0x911C;
    static WAIT_FAILED = 0x911D;
    static SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
    static TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
    static VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
    static ANY_SAMPLES_PASSED = 0x8C2F;
    static ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A;
    static SAMPLER_BINDING = 0x8919;
    static RGB10_A2UI = 0x906F;
    static TEXTURE_SWIZZLE_R = 0x8E42;
    static TEXTURE_SWIZZLE_G = 0x8E43;
    static TEXTURE_SWIZZLE_B = 0x8E44;
    static TEXTURE_SWIZZLE_A = 0x8E45;
    static GREEN = 0x1904;
    static BLUE = 0x1905;
    static INT_2_10_10_10_REV = 0x8D9F;
    static TRANSFORM_FEEDBACK = 0x8E22;
    static TRANSFORM_FEEDBACK_PAUSED = 0x8E23;
    static TRANSFORM_FEEDBACK_ACTIVE = 0x8E24;
    static TRANSFORM_FEEDBACK_BINDING = 0x8E25;
    static PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257;
    static PROGRAM_BINARY_LENGTH = 0x8741;
    static NUM_PROGRAM_BINARY_FORMATS = 0x87FE;
    static PROGRAM_BINARY_FORMATS = 0x87FF;
    static COMPRESSED_R11_EAC = 0x9270;
    static COMPRESSED_SIGNED_R11_EAC = 0x9271;
    static COMPRESSED_RG11_EAC = 0x9272;
    static COMPRESSED_SIGNED_RG11_EAC = 0x9273;
    static COMPRESSED_RGB8_ETC2 = 0x9274;
    static COMPRESSED_SRGB8_ETC2 = 0x9275;
    static COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276;
    static COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277;
    static COMPRESSED_RGBA8_ETC2_EAC = 0x9278;
    static COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279;
    static TEXTURE_IMMUTABLE_FORMAT = 0x912F;
    static MAX_ELEMENT_INDEX = 0x8D6B;
    static NUM_SAMPLE_COUNTS = 0x9380;
    static TEXTURE_IMMUTABLE_LEVELS = 0x82DF;
    //
    // GL ES 3.1
    //
    static COMPUTE_SHADER = 0x91B9;
    static MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;
    static MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;
    static MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;
    static MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;
    static MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;
    static MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;
    static MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;
    static MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;
    static MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;
    static MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;
    static MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;
    static COMPUTE_WORK_GROUP_SIZE = 0x8267;
    static DISPATCH_INDIRECT_BUFFER = 0x90EE;
    static DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;
    static COMPUTE_SHADER_BIT = 0x00000020;
    static DRAW_INDIRECT_BUFFER = 0x8F3F;
    static DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;
    static MAX_UNIFORM_LOCATIONS = 0x826E;
    static FRAMEBUFFER_DEFAULT_WIDTH = 0x9310;
    static FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311;
    static FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313;
    static FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314;
    static MAX_FRAMEBUFFER_WIDTH = 0x9315;
    static MAX_FRAMEBUFFER_HEIGHT = 0x9316;
    static MAX_FRAMEBUFFER_SAMPLES = 0x9318;
    static UNIFORM = 0x92E1;
    static UNIFORM_BLOCK = 0x92E2;
    static PROGRAM_INPUT = 0x92E3;
    static PROGRAM_OUTPUT = 0x92E4;
    static BUFFER_VARIABLE = 0x92E5;
    static SHADER_STORAGE_BLOCK = 0x92E6;
    static ATOMIC_COUNTER_BUFFER = 0x92C0;
    static TRANSFORM_FEEDBACK_VARYING = 0x92F4;
    static ACTIVE_RESOURCES = 0x92F5;
    static MAX_NAME_LENGTH = 0x92F6;
    static MAX_NUM_ACTIVE_VARIABLES = 0x92F7;
    static NAME_LENGTH = 0x92F9;
    static TYPE = 0x92FA;
    static ARRAY_SIZE = 0x92FB;
    static OFFSET = 0x92FC;
    static BLOCK_INDEX = 0x92FD;
    static ARRAY_STRIDE = 0x92FE;
    static MATRIX_STRIDE = 0x92FF;
    static IS_ROW_MAJOR = 0x9300;
    static ATOMIC_COUNTER_BUFFER_INDEX = 0x9301;
    static BUFFER_BINDING = 0x9302;
    static BUFFER_DATA_SIZE = 0x9303;
    static NUM_ACTIVE_VARIABLES = 0x9304;
    static ACTIVE_VARIABLES = 0x9305;
    static REFERENCED_BY_VERTEX_SHADER = 0x9306;
    static REFERENCED_BY_FRAGMENT_SHADER = 0x930A;
    static REFERENCED_BY_COMPUTE_SHADER = 0x930B;
    static TOP_LEVEL_ARRAY_SIZE = 0x930C;
    static TOP_LEVEL_ARRAY_STRIDE = 0x930D;
    static LOCATION = 0x930E;
    static VERTEX_SHADER_BIT = 0x00000001;
    static FRAGMENT_SHADER_BIT = 0x00000002;
    static ALL_SHADER_BITS = 0xFFFFFFFF;
    static PROGRAM_SEPARABLE = 0x8258;
    static ACTIVE_PROGRAM = 0x8259;
    static PROGRAM_PIPELINE_BINDING = 0x825A;
    static ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1;
    static ATOMIC_COUNTER_BUFFER_START = 0x92C2;
    static ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3;
    static MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC;
    static MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0;
    static MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1;
    static MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2;
    static MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6;
    static MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7;
    static MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8;
    static MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC;
    static ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9;
    static UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;
    static MAX_IMAGE_UNITS = 0x8F38;
    static MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA;
    static MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE;
    static MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF;
    static IMAGE_BINDING_NAME = 0x8F3A;
    static IMAGE_BINDING_LEVEL = 0x8F3B;
    static IMAGE_BINDING_LAYERED = 0x8F3C;
    static IMAGE_BINDING_LAYER = 0x8F3D;
    static IMAGE_BINDING_ACCESS = 0x8F3E;
    static IMAGE_BINDING_FORMAT = 0x906E;
    static VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001;
    static ELEMENT_ARRAY_BARRIER_BIT = 0x00000002;
    static UNIFORM_BARRIER_BIT = 0x00000004;
    static TEXTURE_FETCH_BARRIER_BIT = 0x00000008;
    static SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020;
    static COMMAND_BARRIER_BIT = 0x00000040;
    static PIXEL_BUFFER_BARRIER_BIT = 0x00000080;
    static TEXTURE_UPDATE_BARRIER_BIT = 0x00000100;
    static BUFFER_UPDATE_BARRIER_BIT = 0x00000200;
    static FRAMEBUFFER_BARRIER_BIT = 0x00000400;
    static TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800;
    static ATOMIC_COUNTER_BARRIER_BIT = 0x00001000;
    static ALL_BARRIER_BITS = 0xFFFFFFFF;
    static IMAGE_2D = 0x904D;
    static IMAGE_3D = 0x904E;
    static IMAGE_CUBE = 0x9050;
    static IMAGE_2D_ARRAY = 0x9053;
    static INT_IMAGE_2D = 0x9058;
    static INT_IMAGE_3D = 0x9059;
    static INT_IMAGE_CUBE = 0x905B;
    static INT_IMAGE_2D_ARRAY = 0x905E;
    static UNSIGNED_INT_IMAGE_2D = 0x9063;
    static UNSIGNED_INT_IMAGE_3D = 0x9064;
    static UNSIGNED_INT_IMAGE_CUBE = 0x9066;
    static UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;
    static IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7;
    static IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8;
    static IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9;
    static READ_ONLY = 0x88B8;
    static WRITE_ONLY = 0x88B9;
    static READ_WRITE = 0x88BA;
    static SHADER_STORAGE_BUFFER = 0x90D2;
    static SHADER_STORAGE_BUFFER_BINDING = 0x90D3;
    static SHADER_STORAGE_BUFFER_START = 0x90D4;
    static SHADER_STORAGE_BUFFER_SIZE = 0x90D5;
    static MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6;
    static MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA;
    static MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB;
    static MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC;
    static MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD;
    static MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE;
    static SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF;
    static SHADER_STORAGE_BARRIER_BIT = 0x00002000;
    static MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39;
    static DEPTH_STENCIL_TEXTURE_MODE = 0x90EA;
    static STENCIL_INDEX = 0x1901;
    static MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;
    static MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;
    static SAMPLE_POSITION = 0x8E50;
    static SAMPLE_MASK = 0x8E51;
    static SAMPLE_MASK_VALUE = 0x8E52;
    static TEXTURE_2D_MULTISAMPLE = 0x9100;
    static MAX_SAMPLE_MASK_WORDS = 0x8E59;
    static MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
    static MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
    static MAX_INTEGER_SAMPLES = 0x9110;
    static TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
    static TEXTURE_SAMPLES = 0x9106;
    static TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
    static TEXTURE_WIDTH = 0x1000;
    static TEXTURE_HEIGHT = 0x1001;
    static TEXTURE_DEPTH = 0x8071;
    static TEXTURE_INTERNAL_FORMAT = 0x1003;
    static TEXTURE_RED_SIZE = 0x805C;
    static TEXTURE_GREEN_SIZE = 0x805D;
    static TEXTURE_BLUE_SIZE = 0x805E;
    static TEXTURE_ALPHA_SIZE = 0x805F;
    static TEXTURE_DEPTH_SIZE = 0x884A;
    static TEXTURE_STENCIL_SIZE = 0x88F1;
    static TEXTURE_SHARED_SIZE = 0x8C3F;
    static TEXTURE_RED_TYPE = 0x8C10;
    static TEXTURE_GREEN_TYPE = 0x8C11;
    static TEXTURE_BLUE_TYPE = 0x8C12;
    static TEXTURE_ALPHA_TYPE = 0x8C13;
    static TEXTURE_DEPTH_TYPE = 0x8C16;
    static TEXTURE_COMPRESSED = 0x86A1;
    static SAMPLER_2D_MULTISAMPLE = 0x9108;
    static INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
    static UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
    static VERTEX_ATTRIB_BINDING = 0x82D4;
    static VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5;
    static VERTEX_BINDING_DIVISOR = 0x82D6;
    static VERTEX_BINDING_OFFSET = 0x82D7;
    static VERTEX_BINDING_STRIDE = 0x82D8;
    static VERTEX_BINDING_BUFFER = 0x8F4F;
    static MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9;
    static MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA;
    static MAX_VERTEX_ATTRIB_STRIDE = 0x82E5;
    //
    // GL ES 3.2
    //
    static MULTISAMPLE_LINE_WIDTH_RANGE = 0x9381;
    static MULTISAMPLE_LINE_WIDTH_GRANULARITY = 0x9382;
    static MULTIPLY = 0x9294;
    static SCREEN = 0x9295;
    static OVERLAY = 0x9296;
    static DARKEN = 0x9297;
    static LIGHTEN = 0x9298;
    static COLORDODGE = 0x9299;
    static COLORBURN = 0x929A;
    static HARDLIGHT = 0x929B;
    static SOFTLIGHT = 0x929C;
    static DIFFERENCE = 0x929E;
    static EXCLUSION = 0x92A0;
    static HSL_HUE = 0x92AD;
    static HSL_SATURATION = 0x92AE;
    static HSL_COLOR = 0x92AF;
    static HSL_LUMINOSITY = 0x92B0;
    static DEBUG_OUTPUT_SYNCHRONOUS = 0x8242;
    static DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243;
    static DEBUG_CALLBACK_FUNCTION = 0x8244;
    static DEBUG_CALLBACK_USER_PARAM = 0x8245;
    static DEBUG_SOURCE_API = 0x8246;
    static DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247;
    static DEBUG_SOURCE_SHADER_COMPILER = 0x8248;
    static DEBUG_SOURCE_THIRD_PARTY = 0x8249;
    static DEBUG_SOURCE_APPLICATION = 0x824A;
    static DEBUG_SOURCE_OTHER = 0x824B;
    static DEBUG_TYPE_ERROR = 0x824C;
    static DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D;
    static DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E;
    static DEBUG_TYPE_PORTABILITY = 0x824F;
    static DEBUG_TYPE_PERFORMANCE = 0x8250;
    static DEBUG_TYPE_OTHER = 0x8251;
    static DEBUG_TYPE_MARKER = 0x8268;
    static DEBUG_TYPE_PUSH_GROUP = 0x8269;
    static DEBUG_TYPE_POP_GROUP = 0x826A;
    static DEBUG_SEVERITY_NOTIFICATION = 0x826B;
    static MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C;
    static DEBUG_GROUP_STACK_DEPTH = 0x826D;
    static BUFFER = 0x82E0;
    static SHADER = 0x82E1;
    static PROGRAM = 0x82E2;
    static VERTEX_ARRAY = 0x8074;
    static QUERY = 0x82E3;
    static PROGRAM_PIPELINE = 0x82E4;
    static SAMPLER = 0x82E6;
    static MAX_LABEL_LENGTH = 0x82E8;
    static MAX_DEBUG_MESSAGE_LENGTH = 0x9143;
    static MAX_DEBUG_LOGGED_MESSAGES = 0x9144;
    static DEBUG_LOGGED_MESSAGES = 0x9145;
    static DEBUG_SEVERITY_HIGH = 0x9146;
    static DEBUG_SEVERITY_MEDIUM = 0x9147;
    static DEBUG_SEVERITY_LOW = 0x9148;
    static DEBUG_OUTPUT = 0x92E0;
    static CONTEXT_FLAG_DEBUG_BIT = 0x00000002;
    static STACK_OVERFLOW = 0x0503;
    static STACK_UNDERFLOW = 0x0504;
    static GEOMETRY_SHADER = 0x8DD9;
    static GEOMETRY_SHADER_BIT = 0x00000004;
    static GEOMETRY_VERTICES_OUT = 0x8916;
    static GEOMETRY_INPUT_TYPE = 0x8917;
    static GEOMETRY_OUTPUT_TYPE = 0x8918;
    static GEOMETRY_SHADER_INVOCATIONS = 0x887F;
    static LAYER_PROVOKING_VERTEX = 0x825E;
    static LINES_ADJACENCY = 0x000A;
    static LINE_STRIP_ADJACENCY = 0x000B;
    static TRIANGLES_ADJACENCY = 0x000C;
    static TRIANGLE_STRIP_ADJACENCY = 0x000D;
    static MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
    static MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
    static MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
    static MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
    static MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
    static MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
    static MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
    static MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;
    static MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
    static MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF;
    static MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5;
    static MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD;
    static MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7;
    static FIRST_VERTEX_CONVENTION = 0x8E4D;
    static LAST_VERTEX_CONVENTION = 0x8E4E;
    static UNDEFINED_VERTEX = 0x8260;
    static PRIMITIVES_GENERATED = 0x8C87;
    static FRAMEBUFFER_DEFAULT_LAYERS = 0x9312;
    static MAX_FRAMEBUFFER_LAYERS = 0x9317;
    static FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
    static FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
    static REFERENCED_BY_GEOMETRY_SHADER = 0x9309;
    static PRIMITIVE_BOUNDING_BOX = 0x92BE;
    static CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004;
    static CONTEXT_FLAGS = 0x821E;
    static LOSE_CONTEXT_ON_RESET = 0x8252;
    static GUILTY_CONTEXT_RESET = 0x8253;
    static INNOCENT_CONTEXT_RESET = 0x8254;
    static UNKNOWN_CONTEXT_RESET = 0x8255;
    static RESET_NOTIFICATION_STRATEGY = 0x8256;
    static NO_RESET_NOTIFICATION = 0x8261;
    static CONTEXT_LOST = 0x0507;
    static SAMPLE_SHADING = 0x8C36;
    static MIN_SAMPLE_SHADING_VALUE = 0x8C37;
    static MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;
    static MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;
    static FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;
    static PATCHES = 0x000E;
    static PATCH_VERTICES = 0x8E72;
    static TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;
    static TESS_GEN_MODE = 0x8E76;
    static TESS_GEN_SPACING = 0x8E77;
    static TESS_GEN_VERTEX_ORDER = 0x8E78;
    static TESS_GEN_POINT_MODE = 0x8E79;
    static ISOLINES = 0x8E7A;
    static QUADS = 0x0007;
    static FRACTIONAL_ODD = 0x8E7B;
    static FRACTIONAL_EVEN = 0x8E7C;
    static MAX_PATCH_VERTICES = 0x8E7D;
    static MAX_TESS_GEN_LEVEL = 0x8E7E;
    static MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;
    static MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;
    static MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;
    static MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;
    static MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;
    static MAX_TESS_PATCH_COMPONENTS = 0x8E84;
    static MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;
    static MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;
    static MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;
    static MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;
    static MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;
    static MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;
    static MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;
    static MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;
    static MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD;
    static MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE;
    static MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3;
    static MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4;
    static MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB;
    static MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC;
    static MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8;
    static MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9;
    static PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
    static IS_PER_PATCH = 0x92E7;
    static REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307;
    static REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308;
    static TESS_CONTROL_SHADER = 0x8E88;
    static TESS_EVALUATION_SHADER = 0x8E87;
    static TESS_CONTROL_SHADER_BIT = 0x00000008;
    static TESS_EVALUATION_SHADER_BIT = 0x00000010;
    static TEXTURE_BORDER_COLOR = 0x1004;
    static CLAMP_TO_BORDER = 0x812D;
    static TEXTURE_BUFFER = 0x8C2A;
    static TEXTURE_BUFFER_BINDING = 0x8C2A;
    static MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
    static TEXTURE_BINDING_BUFFER = 0x8C2C;
    static TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
    static TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F;
    static SAMPLER_BUFFER = 0x8DC2;
    static INT_SAMPLER_BUFFER = 0x8DD0;
    static UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
    static IMAGE_BUFFER = 0x9051;
    static INT_IMAGE_BUFFER = 0x905C;
    static UNSIGNED_INT_IMAGE_BUFFER = 0x9067;
    static TEXTURE_BUFFER_OFFSET = 0x919D;
    static TEXTURE_BUFFER_SIZE = 0x919E;
    static COMPRESSED_RGBA_ASTC_4x4 = 0x93B0;
    static COMPRESSED_RGBA_ASTC_5x4 = 0x93B1;
    static COMPRESSED_RGBA_ASTC_5x5 = 0x93B2;
    static COMPRESSED_RGBA_ASTC_6x5 = 0x93B3;
    static COMPRESSED_RGBA_ASTC_6x6 = 0x93B4;
    static COMPRESSED_RGBA_ASTC_8x5 = 0x93B5;
    static COMPRESSED_RGBA_ASTC_8x6 = 0x93B6;
    static COMPRESSED_RGBA_ASTC_8x8 = 0x93B7;
    static COMPRESSED_RGBA_ASTC_10x5 = 0x93B8;
    static COMPRESSED_RGBA_ASTC_10x6 = 0x93B9;
    static COMPRESSED_RGBA_ASTC_10x8 = 0x93BA;
    static COMPRESSED_RGBA_ASTC_10x10 = 0x93BB;
    static COMPRESSED_RGBA_ASTC_12x10 = 0x93BC;
    static COMPRESSED_RGBA_ASTC_12x12 = 0x93BD;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_4x4 = 0x93D0;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_5x4 = 0x93D1;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_5x5 = 0x93D2;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_6x5 = 0x93D3;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_6x6 = 0x93D4;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_8x5 = 0x93D5;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_8x6 = 0x93D6;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_8x8 = 0x93D7;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_10x5 = 0x93D8;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_10x6 = 0x93D9;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_10x8 = 0x93DA;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_10x10 = 0x93DB;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_12x10 = 0x93DC;
    static COMPRESSED_SRGB8_ALPHA8_ASTC_12x12 = 0x93DD;
    static TEXTURE_CUBE_MAP_ARRAY = 0x9009;
    static TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
    static SAMPLER_CUBE_MAP_ARRAY = 0x900C;
    static SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;
    static INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
    static UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;
    static IMAGE_CUBE_MAP_ARRAY = 0x9054;
    static INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;
    static UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;
    static TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
    static TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
    static SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
    static INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
    static UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;

    constructor() {
    }

//
// GL ES 2.0
//

    activeTexture(texture) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_active_texture",
            "void",
            [
                ["uint", "texture", texture]
            ]
        );
    }
    attachShader(program, shader) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_attach_shader",
            "void",
            [
                ["uint", "program", program],
                ["uint", "shader", shader]
            ]
        );
    }
    bindAttribLocation(program, index, name) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_attrib_location",
            "void",
            [
                ["uint", "program", program],
                ["uint", "index", index],
                ["string", "name", name]
            ]
        );
    }
    bindBuffer(target, buffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_buffer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "buffer", buffer]
            ]
        );
    }
    bindFramebuffer(target, framebuffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_framebuffer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "framebuffer", framebuffer]
            ]
        );
    }
    bindRenderbuffer(target, renderbuffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_renderbuffer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "renderbuffer", renderbuffer]
            ]
        );
    }
    bindTexture(target, texture) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_texture",
            "void",
            [
                ["uint", "target", target],
                ["uint", "texture", texture]
            ]
        );
    }
    blendColor(red, green, blue, alpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_color",
            "void",
            [
                ["float", "red", red],
                ["float", "green", green],
                ["float", "blue", blue],
                ["float", "alpha", alpha]
            ]
        );
    }
    blendEquation(mode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_equation",
            "void",
            [
                ["uint", "mode", mode]
            ]
        );
    }
    blendEquationSeparate(modeRGB, modeAlpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_equation_separate",
            "void",
            [
                ["uint", "modeRGB", modeRGB],
                ["uint", "modeAlpha", modeAlpha]
            ]
        );
    }
    blendFunc(sfactor, dfactor) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_func",
            "void",
            [
                ["uint", "sfactor", sfactor],
                ["uint", "dfactor", dfactor]
            ]
        );
    }
    blendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_func_separate",
            "void",
            [
                ["uint", "sfactorRGB", sfactorRGB],
                ["uint", "dfactorRGB", dfactorRGB],
                ["uint", "sfactorAlpha", sfactorAlpha],
                ["uint", "dfactorAlpha", dfactorAlpha]
            ]
        );
    }
    bufferData(target, size, data, usage) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_buffer_data",
            "void",
            [
                ["uint", "target", target],
                ["slong", "size", size],
                ["pointer", "data", data],
                ["uint", "usage", usage]
            ]
        );
    }
    bufferSubData(target, offset, size, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_buffer_sub_data",
            "void",
            [
                ["uint", "target", target],
                ["slong", "offset", offset],
                ["slong", "size", size],
                ["pointer", "data", data]
            ]
        );
    }
    checkFramebufferStatus(target) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_check_framebuffer_status",
            "uint",
            [
                ["uint", "target", target]
            ]
        );
    }
    clear(mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear",
            "void",
            [
                ["uint", "mask", mask]
            ]
        );
    }
    clearColor(red, green, blue, alpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_color",
            "void",
            [
                ["float", "red", red],
                ["float", "green", green],
                ["float", "blue", blue],
                ["float", "alpha", alpha]
            ]
        );
    }
    clearDepthf(d) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_depth_f",
            "void",
            [
                ["float", "d", d]
            ]
        );
    }
    clearStencil(s) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_stencil",
            "void",
            [
                ["sint", "s", s]
            ]
        );
    }
    colorMask(red, green, blue, alpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_color_mask",
            "void",
            [
                ["uchar", "red", red],
                ["uchar", "green", green],
                ["uchar", "blue", blue],
                ["uchar", "alpha", alpha]
            ]
        );
    }
    compileShader(shader) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_compile_shader",
            "void",
            [
                ["uint", "shader", shader]
            ]
        );
    }
    compressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_compressed_tex_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "border", border],
                ["sint", "imageSize", imageSize],
                ["pointer", "data", data]
            ]
        );
    }
    compressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_compressed_tex_sub_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "format", format],
                ["sint", "imageSize", imageSize],
                ["pointer", "data", data]
            ]
        );
    }
    copyTexImage2D(target, level, internalformat, x, y, width, height, border) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_copy_tex_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["uint", "internalformat", internalformat],
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "border", border]
            ]
        );
    }
    copyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_copy_tex_sub_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    createProgram() {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_create_program",
            "uint",
            null
        );
    }
    createShader(type) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_create_shader",
            "uint",
            [
                ["uint", "type", type]
            ]
        );
    }
    cullFace(mode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_cull_face",
            "void",
            [
                ["uint", "mode", mode]
            ]
        );
    }
    deleteBuffers(n, buffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_buffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "buffers", buffers]
            ]
        );
    }
    deleteFramebuffers(n, framebuffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_framebuffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "framebuffers", framebuffers]
            ]
        );
    }
    deleteProgram(program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_program",
            "void",
            [
                ["uint", "program", program]
            ]
        );
    }
    deleteRenderbuffers(n, renderbuffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_renderbuffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "renderbuffers", renderbuffers]
            ]
        );
    }
    deleteShader(shader) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_shader",
            "void",
            [
                ["uint", "shader", shader]
            ]
        );
    }
    deleteTextures(n, textures) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_textures",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "textures", textures]
            ]
        );
    }
    depthFunc(func) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_depth_func",
            "void",
            [
                ["uint", "func", func]
            ]
        );
    }
    depthMask(flag) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_depth_mask",
            "void",
            [
                ["uchar", "flag", flag]
            ]
        );
    }
    depthRangef(n, f) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_depth_range_f",
            "void",
            [
                ["float", "n", n],
                ["float", "f", f]
            ]
        );
    }
    detachShader(program, shader) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_detach_shader",
            "void",
            [
                ["uint", "program", program],
                ["uint", "shader", shader]
            ]
        );
    }
    disable(cap) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_disable",
            "void",
            [
                ["uint", "cap", cap]
            ]
        );
    }
    disableVertexAttribArray(index) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_disable_vertex_attrib_array",
            "void",
            [
                ["uint", "index", index]
            ]
        );
    }
    drawArrays(mode, first, count) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_arrays",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "first", first],
                ["sint", "count", count]
            ]
        );
    }
    drawElements(mode, count, type, indices) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_elements",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices]
            ]
        );
    }
    enable(cap) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_enable",
            "void",
            [
                ["uint", "cap", cap]
            ]
        );
    }
    enableVertexAttribArray(index) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_enable_vertex_attrib_array",
            "void",
            [
                ["uint", "index", index]
            ]
        );
    }
    finish() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_finish",
            "void",
            null
        );
    }
    flush() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_flush",
            "void",
            null
        );
    }
    framebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_framebuffer_renderbuffer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "attachment", attachment],
                ["uint", "renderbuffertarget", renderbuffertarget],
                ["uint", "renderbuffer", renderbuffer]
            ]
        );
    }
    framebufferTexture2D(target, attachment, textarget, texture, level) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_framebuffer_texture_2d",
            "void",
            [
                ["uint", "target", target],
                ["uint", "attachment", attachment],
                ["uint", "textarget", textarget],
                ["uint", "texture", texture],
                ["sint", "level", level]
            ]
        );
    }
    frontFace(mode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_front_face",
            "void",
            [
                ["uint", "mode", mode]
            ]
        );
    }
    genBuffers(n, buffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_buffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "buffers", buffers]
            ]
        );
    }
    generateMipmap(target) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_generate_mipmap",
            "void",
            [
                ["uint", "target", target]
            ]
        );
    }
    genFramebuffers(n, framebuffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_framebuffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "framebuffers", framebuffers]
            ]
        );
    }
    genRenderbuffers(n, renderbuffers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_renderbuffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "renderbuffers", renderbuffers]
            ]
        );
    }
    genTextures(n, textures) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_textures",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "pointer", textures]
            ]
        );
    }
    getActiveAttrib(program, index, bufSize, length, size, type, name) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_active_attrib",
            "void",
            [
                ["uint", "program", program],
                ["uint", "index", index],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "size", size],
                ["pointer", "type", type],
                ["pointer", "name", name]
            ]
        );
    }
    getActiveUniform(program, index, bufSize, length, size, type, name) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_active_uniform",
            "void",
            [
                ["uint", "program", program],
                ["uint", "index", index],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "size", size],
                ["pointer", "type", type],
                ["pointer", "name", name]
            ]
        );
    }
    getAttachedShaders(program, maxCount, count, shaders) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_attached_shaders",
            "void",
            [
                ["uint", "program", program],
                ["sint", "maxCount", maxCount],
                ["pointer", "count", count],
                ["pointer", "shaders", shaders]
            ]
        );
    }
    getAttribLocation(program, name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_attrib_location",
            "sint",
            [
                ["uint", "program", program],
                ["string", "name", name]
            ]
        );
    }
    getBooleanv(pname, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_boolean_v",
            "void",
            [
                ["uint", "pname", pname],
                ["pointer", "data", data]
            ]
        );
    }
    getBufferParameteriv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_buffer_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getError() {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_error",
            "uint",
            null
        );
    }
    getFloatv(pname, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_float_v",
            "void",
            [
                ["uint", "pname", pname],
                ["pointer", "data", data]
            ]
        );
    }
    getFramebufferAttachmentParameteriv(target, attachment, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_framebuffer_attachment_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "attachment", attachment],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getIntegerv(pname, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_integer_v",
            "void",
            [
                ["uint", "pname", pname],
                ["pointer", "data", data]
            ]
        );
    }
    getProgramiv(program, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_iv",
            "void",
            [
                ["uint", "program", program],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getProgramInfoLog(program, bufSize, length, infoLog) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_info_log",
            "void",
            [
                ["uint", "program", program],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "infoLog", infoLog]
            ]
        );
    }
    getRenderbufferParameteriv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_renderbuffer_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getShaderiv(shader, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_shader_iv",
            "void",
            [
                ["uint", "shader", shader],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getShaderInfoLog(shader, bufSize, length, infoLog) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_shader_info_log",
            "void",
            [
                ["uint", "shader", shader],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "infoLog", infoLog]
            ]
        );
    }
    getShaderPrecisionFormat(shadertype, precisiontype, range, precision) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_shader_precision_format",
            "void",
            [
                ["uint", "shadertype", shadertype],
                ["uint", "precisiontype", precisiontype],
                ["pointer", "range", range],
                ["pointer", "precision", precision]
            ]
        );
    }
    getShaderSource(shader, bufSize, length, source) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_shader_source",
            "void",
            [
                ["uint", "shader", shader],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "source", source]
            ]
        );
    }
    getString(name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_string",
            "string",
            [
                ["uint", "name", name]
            ]
        );
    }
    getTexParameterfv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_parameter_fv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getTexParameteriv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getUniformfv(program, location, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["pointer", "params", params]
            ]
        );
    }
    getUniformiv(program, location, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["pointer", "params", params]
            ]
        );
    }
    getUniformLocation(program, name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_location",
            "sint",
            [
                ["uint", "program", program],
                ["string", "name", name]
            ]
        );
    }
    getVertexAttribfv(index, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_vertex_attrib_fv",
            "void",
            [
                ["uint", "index", index],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getVertexAttribiv(index, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_vertex_attrib_iv",
            "void",
            [
                ["uint", "index", index],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getVertexAttribPointerv(index, pname, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_vertex_attrib_pointer_v",
            "void",
            [
                ["uint", "index", index],
                ["uint", "pname", pname],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    hint(target, mode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_hint",
            "void",
            [
                ["uint", "target", target],
                ["uint", "mode", mode]
            ]
        );
    }
    isBuffer(buffer) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_buffer",
            "uchar",
            [
                ["uint", "buffer", buffer]
            ]
        );
    }
    isEnabled(cap) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_enabled",
            "uchar",
            [
                ["uint", "cap", cap]
            ]
        );
    }
    isFramebuffer(framebuffer) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_framebuffer",
            "uchar",
            [
                ["uint", "framebuffer", framebuffer]
            ]
        );
    }
    isProgram(program) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_program",
            "uchar",
            [
                ["uint", "program", program]
            ]
        );
    }
    isRenderbuffer(renderbuffer) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_renderbuffer",
            "uchar",
            [
                ["uint", "renderbuffer", renderbuffer]
            ]
        );
    }
    isShader(shader) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_shader",
            "uchar",
            [
                ["uint", "shader", shader]
            ]
        );
    }
    isTexture(texture) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_texture",
            "uchar",
            [
                ["uint", "texture", texture]
            ]
        );
    }
    lineWidth(width) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_line_width",
            "void",
            [
                ["float", "width", width]
            ]
        );
    }
    linkProgram(program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_link_program",
            "void",
            [
                ["uint", "program", program]
            ]
        );
    }
    pixelStorei(pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_pixel_store_i",
            "void",
            [
                ["uint", "pname", pname],
                ["sint", "param", param]
            ]
        );
    }
    polygonOffset(factor, units) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_polygon_offset",
            "void",
            [
                ["float", "factor", factor],
                ["float", "units", units]
            ]
        );
    }
    readPixels(x, y, width, height, format, type, pixels) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_read_pixels",
            "void",
            [
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height],
                ["uint", "format", format],
                ["uint", "type", type],
                ["pointer", "pixels", pixels]
            ]
        );
    }
    releaseShaderCompiler() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_release_shader_compiler",
            "void",
            null
        );
    }
    renderbufferStorage(target, internalformat, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_renderbuffer_storage",
            "void",
            [
                ["uint", "target", target],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    sampleCoverage(value, invert) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sample_coverage",
            "void",
            [
                ["float", "value", value],
                ["uchar", "invert", invert]
            ]
        );
    }
    scissor(x, y, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_scissor",
            "void",
            [
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    shaderBinary(count, shaders, binaryformat, binary, length) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_shader_binary",
            "void",
            [
                ["sint", "count", count],
                ["pointer", "shaders", shaders],
                ["uint", "binaryformat", binaryformat],
                ["pointer", "binary", binary],
                ["sint", "length", length]
            ]
        );
    }
    shaderSource(shader, count, string, length) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_shader_source",
            "void",
            [
                ["uint", "shader", shader],
                ["sint", "count", count],
                ["pointer", "string", string],
                ["pointer", "length", length]
            ]
        );
    }
    stencilFunc(func, ref, mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_func",
            "void",
            [
                ["uint", "func", func],
                ["sint", "ref", ref],
                ["uint", "mask", mask]
            ]
        );
    }
    stencilFuncSeparate(face, func, ref, mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_func_separate",
            "void",
            [
                ["uint", "face", face],
                ["uint", "func", func],
                ["sint", "ref", ref],
                ["uint", "mask", mask]
            ]
        );
    }
    stencilMask(mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_mask",
            "void",
            [
                ["uint", "mask", mask]
            ]
        );
    }
    stencilMaskSeparate(face, mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_mask_separate",
            "void",
            [
                ["uint", "face", face],
                ["uint", "mask", mask]
            ]
        );
    }
    stencilOp(fail, zfail, zpass) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_op",
            "void",
            [
                ["uint", "fail", fail],
                ["uint", "zfail", zfail],
                ["uint", "zpass", zpass]
            ]
        );
    }
    stencilOpSeparate(face, sfail, dpfail, dppass) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_stencil_op_separate",
            "void",
            [
                ["uint", "face", face],
                ["uint", "sfail", sfail],
                ["uint", "dpfail", dpfail],
                ["uint", "dppass", dppass]
            ]
        );
    }
    texImage2D(target, level, internalformat, width, height, border, format, type, pixels) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "border", border],
                ["uint", "format", format],
                ["uint", "type", type],
                ["pointer", "pixels", pixels]
            ]
        );
    }
    texParameterf(target, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_f",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["float", "param", param]
            ]
        );
    }
    texParameterfv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_fv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    texParameteri(target, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_i",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["sint", "param", param]
            ]
        );
    }
    texParameteriv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    texSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_sub_image_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "width", width],
                ["sint", "height", height],
                ["uint", "format", format],
                ["uint", "type", type],
                ["pointer", "pixels", pixels]
            ]
        );
    }
    uniform1f(location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1f",
            "void",
            [
                ["sint", "location", location],
                ["float", "v0", v0]
            ]
        );
    }
    uniform1fv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform1i(location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1i",
            "void",
            [
                ["sint", "location", location],
                ["sint", "v0", v0]
            ]
        );
    }
    uniform1iv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1iv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform2f(location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2f",
            "void",
            [
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1]
            ]
        );
    }
    uniform2fv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform2i(location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2i",
            "void",
            [
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1]
            ]
        );
    }
    uniform2iv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2iv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform3f(location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3f",
            "void",
            [
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1],
                ["float", "v2", v2]
            ]
        );
    }
    uniform3fv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform3i(location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3i",
            "void",
            [
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1],
                ["sint", "v2", v2]
            ]
        );
    }
    uniform3iv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3iv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform4f(location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_4f",
            "void",
            [
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1],
                ["float", "v2", v2],
                ["float", "v3", v3]
            ]
        );
    }
    uniform4fv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_4fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform4i(location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_4i",
            "void",
            [
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1],
                ["sint", "v2", v2],
                ["sint", "v3", v3]
            ]
        );
    }
    uniform4iv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform4iv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix2fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_2fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix3fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_3fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix4fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_4fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    useProgram(program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_use_program",
            "void",
            [
                ["uint", "program", program]
            ]
        );
    }
    validateProgram(program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_validate_program",
            "void",
            [
                ["uint", "program", program]
            ]
        );
    }
    vertexAttrib1f(index, x) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_1f",
            "void",
            [
                ["uint", "index", index],
                ["float", "x", x]
            ]
        );
    }
    vertexAttrib1fv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_1fv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    vertexAttrib2f(index, x, y) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_2f",
            "void",
            [
                ["uint", "index", index],
                ["float", "x", x],
                ["float", "y", y]
            ]
        );
    }
    vertexAttrib2fv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_2fv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    vertexAttrib3f(index, x, y, z) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_3f",
            "void",
            [
                ["uint", "index", index],
                ["float", "x", x],
                ["float", "y", y],
                ["float", "z", z]
            ]
        );
    }
    vertexAttrib3fv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_3fv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    vertexAttrib4f(index, x, y, z, w) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_4f",
            "void",
            [
                ["uint", "index", index],
                ["float", "x", x],
                ["float", "y", y],
                ["float", "z", z],
                ["float", "w", w]
            ]
        );
    }
    vertexAttrib4fv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_4fv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    vertexAttribPointer(index, size, type, normalized, stride, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_pointer",
            "void",
            [
                ["uint", "index", index],
                ["sint", "size", size],
                ["uint", "type", type],
                ["uchar", "normalized", normalized],
                ["sint", "stride", stride],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    viewport(x, y, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_viewport",
            "void",
            [
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }

//
// GL ES 3.0
//

    readBuffer(src) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_read_buffer",
            "void",
            [
                ["uint", "src", src]
            ]
        );
    }
    drawRangeElements(mode, start, end, count, type, indices) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_range_elements",
            "void",
            [
                ["uint", "mode", mode],
                ["uint", "start", start],
                ["uint", "end", end],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices]
            ]
        );
    }
    texImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_image_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth],
                ["sint", "border", border],
                ["uint", "format", format],
                ["uint", "type", type],
                ["pointer", "pixels", pixels]
            ]
        );
    }
    texSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_sub_image_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "zoffset", zoffset],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth],
                ["uint", "format", format],
                ["uint", "type", type],
                ["pointer", "pixels", pixels]
            ]
        );
    }
    copyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_copy_tex_sub_image_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "zoffset", zoffset],
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    compressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_compressed_tex_image_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth],
                ["sint", "border", border],
                ["sint", "imageSize", imageSize],
                ["pointer", "data", data]
            ]
        );
    }
    compressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_compressed_tex_sub_image_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["sint", "xoffset", xoffset],
                ["sint", "yoffset", yoffset],
                ["sint", "zoffset", zoffset],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth],
                ["uint", "format", format],
                ["sint", "imageSize", imageSize],
                ["pointer", "data", data]
            ]
        );
    }
    genQueries(n, ids) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_queries",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "ids", ids]
            ]
        );
    }
    deleteQueries(n, ids) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_queries",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "ids", ids]
            ]
        );
    }
    isQuery(id) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_query",
            "uchar",
            [
                ["uint", "id", id]
            ]
        );
    }
    beginQuery(target, id) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_begin_query",
            "void",
            [
                ["uint", "target", target],
                ["uint", "id", id]
            ]
        );
    }
    endQuery(target) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_end_query",
            "void",
            [
                ["uint", "target", target]
            ]
        );
    }
    getQueryiv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_query_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getQueryObjectuiv(id, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_query_object_uiv",
            "void",
            [
                ["uint", "id", id],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    unmapBuffer(target) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_unmap_buffer",
            "uchar",
            [
                ["uint", "target", target]
            ]
        );
    }
    getBufferPointerv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_buffer_pointer_v",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    drawBuffers(n, bufs) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_buffers",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "bufs", bufs]
            ]
        );
    }
    uniformMatrix2x3fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_2x3fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix3x2fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_3x2fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix2x4fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_2x4fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix4x2fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_4x2fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix3x4fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_3x4fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    uniformMatrix4x3fv(location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_matrix_4x3fv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    blitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blit_framebuffer",
            "void",
            [
                ["sint", "srcX0", srcX0],
                ["sint", "srcY0", srcY0],
                ["sint", "srcX1", srcX1],
                ["sint", "srcY1", srcY1],
                ["sint", "dstX0", dstX0],
                ["sint", "dstY0", dstY0],
                ["sint", "dstX1", dstX1],
                ["sint", "dstY1", dstY1],
                ["uint", "mask", mask],
                ["uint", "filter", filter]
            ]
        );
    }
    renderbufferStorageMultisample(target, samples, internalformat, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_renderbuffer_storage_multisample",
            "void",
            [
                ["uint", "target", target],
                ["sint", "samples", samples],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    framebufferTextureLayer(target, attachment, texture, level, layer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_framebuffer_texture_layer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "attachment", attachment],
                ["uint", "texture", texture],
                ["sint", "level", level],
                ["sint", "layer", layer]
            ]
        );
    }
    mapBufferRange(target, offset, length, access) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_map_buffer_range",
            "pointer",
            [
                ["uint", "target", target],
                ["slong", "offset", offset],
                ["slong", "length", length],
                ["uint", "access", access]
            ]
        );
    }
    flushMappedBufferRange(target, offset, length) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_flush_mapped_buffer_range",
            "void",
            [
                ["uint", "target", target],
                ["slong", "offset", offset],
                ["slong", "length", length]
            ]
        );
    }
    bindVertexArray(array) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_vertex_array",
            "void",
            [
                ["uint", "array", array]
            ]
        );
    }
    deleteVertexArrays(n, arrays) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_vertex_arrays",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "arrays", arrays]
            ]
        );
    }
    genVertexArrays(n, arrays) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_vertex_arrays",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "arrays", arrays]
            ]
        );
    }
    isVertexArray(array) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_vertex_array",
            "uchar",
            [
                ["uint", "array", array]
            ]
        );
    }
    getIntegeri_v(target, index, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_integer_i_v",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index],
                ["pointer", "data", data]
            ]
        );
    }
    beginTransformFeedback(primitiveMode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_begin_transform_feedback",
            "void",
            [
                ["uint", "primitiveMode", primitiveMode]
            ]
        );
    }
    endTransformFeedback() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_end_transform_feedback",
            "void",
            null
        );
    }
    bindBufferRange(target, index, buffer, offset, size) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_buffer_range",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index],
                ["uint", "buffer", buffer],
                ["slong", "offset", offset],
                ["slong", "size", size]
            ]
        );
    }
    bindBufferBase(target, index, buffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_buffer_base",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index],
                ["uint", "buffer", buffer]
            ]
        );
    }
    transformFeedbackVaryings(program, count, varyings, bufferMode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_transform_feedback_varyings",
            "void",
            [
                ["uint", "program", program],
                ["sint", "count", count],
                ["pointer", "varyings", varyings],
                ["uint", "bufferMode", bufferMode]
            ]
        );
    }
    getTransformFeedbackVarying(program, index, bufSize, length, size, type, name) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_transform_feedback_varying",
            "void",
            [
                ["uint", "program", program],
                ["uint", "index", index],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "size", size],
                ["pointer", "type", type],
                ["string", "name", name]
            ]
        );
    }
    vertexAttribIPointer(index, size, type, stride, pointer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i_pointer",
            "void",
            [
                ["uint", "index", index],
                ["sint", "size", size],
                ["uint", "type", type],
                ["sint", "stride", stride],
                ["pointer", "pointer", pointer]
            ]
        );
    }
    getVertexAttribIiv(index, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_vertex_attrib_iiv",
            "void",
            [
                ["uint", "index", index],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getVertexAttribIuiv(index, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_vertex_attrib_iuiv",
            "void",
            [
                ["uint", "index", index],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    vertexAttribI4i(index, x, y, z, w) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i4i",
            "void",
            [
                ["uint", "index", index],
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "z", z],
                ["sint", "w", w]
            ]
        );
    }
    vertexAttribI4ui(index, x, y, z, w) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i4ui",
            "void",
            [
                ["uint", "index", index],
                ["uint", "x", x],
                ["uint", "y", y],
                ["uint", "z", z],
                ["uint", "w", w]
            ]
        );
    }
    vertexAttribI4iv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i4iv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    vertexAttribI4uiv(index, v) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i4uiv",
            "void",
            [
                ["uint", "index", index],
                ["pointer", "v", v]
            ]
        );
    }
    getUniformuiv(program, location, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["pointer", "params", params]
            ]
        );
    }
    getFragDataLocation(program, name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_frag_data_location",
            "sint",
            [
                ["uint", "program", program],
                ["string", "name", name]
            ]
        );
    }
    uniform1ui(location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1ui",
            "void",
            [
                ["sint", "location", location],
                ["uint", "v0", v0]
            ]
        );
    }
    uniform2ui(location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2ui",
            "void",
            [
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1]
            ]
        );
    }
    uniform3ui(location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3ui",
            "void",
            [
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1],
                ["uint", "v2", v2]
            ]
        );
    }
    uniform4ui(location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_4ui",
            "void",
            [
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1],
                ["uint", "v2", v2],
                ["uint", "v3", v3]
            ]
        );
    }
    uniform1uiv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_1uiv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform2uiv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_2uiv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform3uiv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_3uiv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    uniform4uiv(location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_4uiv",
            "void",
            [
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    clearBufferiv(buffer, drawbuffer, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_buffer_iv",
            "void",
            [
                ["uint", "buffer", buffer],
                ["sint", "drawbuffer", drawbuffer],
                ["pointer", "value", value]
            ]
        );
    }
    clearBufferuiv(buffer, drawbuffer, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_buffer_uiv",
            "void",
            [
                ["uint", "buffer", buffer],
                ["sint", "drawbuffer", drawbuffer],
                ["pointer", "value", value]
            ]
        );
    }
    clearBufferfv(buffer, drawbuffer, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_buffer_fv",
            "void",
            [
                ["uint", "buffer", buffer],
                ["sint", "drawbuffer", drawbuffer],
                ["pointer", "value", value]
            ]
        );
    }
    clearBufferfi(buffer, drawbuffer, depth, stencil) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_clear_buffer_fi",
            "void",
            [
                ["uint", "buffer", buffer],
                ["sint", "drawbuffer", drawbuffer],
                ["float", "depth", depth],
                ["sint", "stencil", stencil]
            ]
        );
    }
    getStringi(name, index) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_string_i",
            "string",
            [
                ["uint", "name", name],
                ["uint", "index", index]
            ]
        );
    }
    copyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_copy_buffer_sub_data",
            "void",
            [
                ["uint", "readTarget", readTarget],
                ["uint", "writeTarget", writeTarget],
                ["slong", "readOffset", readOffset],
                ["slong", "writeOffset", writeOffset],
                ["slong", "size", size]
            ]
        );
    }
    getUniformIndices(program, uniformCount, uniformNames, uniformIndices) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_indices",
            "void",
            [
                ["uint", "program", program],
                ["sint", "uniformCount", uniformCount],
                ["pointer", "uniformNames", uniformNames],
                ["pointer", "uniformIndices", uniformIndices]
            ]
        );
    }
    getActiveUniformsiv(program, uniformCount, uniformIndices, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_active_uniforms_iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "uniformCount", uniformCount],
                ["pointer", "uniformIndices", uniformIndices],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getUniformBlockIndex(program, uniformBlockName) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_uniform_block_index",
            "uint",
            [
                ["uint", "program", program],
                ["string", "uniformBlockName", uniformBlockName]
            ]
        );
    }
    getActiveUniformBlockiv(program, uniformBlockIndex, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_active_uniform_block_iv",
            "void",
            [
                ["uint", "program", program],
                ["uint", "uniformBlockIndex", uniformBlockIndex],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_active_uniform_block_name",
            "void",
            [
                ["uint", "program", program],
                ["uint", "uniformBlockIndex", uniformBlockIndex],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["string", "uniformBlockName", uniformBlockName]
            ]
        );
    }
    uniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_uniform_block_binding",
            "void",
            [
                ["uint", "program", program],
                ["uint", "uniformBlockIndex", uniformBlockIndex],
                ["uint", "uniformBlockBinding", uniformBlockBinding]
            ]
        );
    }
    drawArraysInstanced(mode, first, count, instancecount) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_arrays_instanced",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "first", first],
                ["sint", "count", count],
                ["sint", "instancecount", instancecount]
            ]
        );
    }
    drawElementsInstanced(mode, count, type, indices, instancecount) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_elements_instanced",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices],
                ["sint", "instancecount", instancecount]
            ]
        );
    }
    fenceSync(condition, flags) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_fence_sync",
            "pointer",
            [
                ["uint", "condition", condition],
                ["uint", "flags", flags]
            ]
        );
    }
    isSync(sync) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_sync",
            "void",
            [
                ["pointer", "sync", sync]
            ]
        );
    }
    deleteSync(sync) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_sync",
            "void",
            [
                ["pointer", "sync", sync]
            ]
        );
    }
    clientWaitSync(sync, flags, timeout) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_client_wait_sync",
            "uint",
            [
                ["pointer", "sync", sync],
                ["uint", "flags", flags],
                ["uint64", "timeout", timeout]
            ]
        );
    }
    waitSync(sync, flags, timeout) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_wait_sync",
            "void",
            [
                ["pointer", "sync", sync],
                ["uint", "flags", flags],
                ["uint64", "timeout", timeout]
            ]
        );
    }
    getInteger64v(pname, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_integer_64v",
            "void",
            [
                ["uint", "pname", pname],
                ["pointer", "data", data]
            ]
        );
    }
    getSynciv(sync, pname, bufSize, length, values) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_sync_iv",
            "void",
            [
                ["pointer", "sync", sync],
                ["uint", "pname", pname],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "values", values]
            ]
        );
    }
    getInteger64i_v(target, index, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_integer_64i_v",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index],
                ["pointer", "data", data]
            ]
        );
    }
    getBufferParameteri64v(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_buffer_parameter_i64v",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    genSamplers(count, samplers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_samplers",
            "void",
            [
                ["sint", "count", count],
                ["pointer", "samplers", samplers]
            ]
        );
    }
    deleteSamplers(count, samplers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_samplers",
            "void",
            [
                ["sint", "count", count],
                ["pointer", "samplers", samplers]
            ]
        );
    }
    isSampler(sampler) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_sampler",
            "uint",
            [
                ["uint", "sampler", sampler]
            ]
        );
    }
    bindSampler(unit, sampler) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_sampler",
            "void",
            [
                ["uint", "unit", unit],
                ["uint", "sampler", sampler]
            ]
        );
    }
    samplerParameteri(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_i",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["sint", "param", param]
            ]
        );
    }
    samplerParameteriv(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_iv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", param]
            ]
        );
    }
    samplerParameterf(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_f",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["float", "param", param]
            ]
        );
    }
    samplerParameterfv(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_fv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", param]
            ]
        );
    }
    getSamplerParameteriv(sampler, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_sampler_parameter_iv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getSamplerParameterfv(sampler, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_sampler_parameter_fv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    vertexAttribDivisor(index, divisor) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_divisor",
            "void",
            [
                ["uint", "index", index],
                ["uint", "divisor", divisor]
            ]
        );
    }
    bindTransformFeedback(target, id) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_transform_feedback",
            "void",
            [
                ["uint", "target", target],
                ["uint", "id", id]
            ]
        );
    }
    deleteTransformFeedbacks(n, ids) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_transform_feedbacks",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "ids", ids]
            ]
        );
    }
    genTransformFeedbacks(n, ids) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_transform_feedbacks",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "ids", ids]
            ]
        );
    }
    isTransformFeedback(id) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_transform_feedback",
            "uint",
            [
                ["uint", "id", id]
            ]
        );
    }
    pauseTransformFeedback() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_pause_transform_feedback",
            "void",
            null
        );
    }
    resumeTransformFeedback() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_resume_transform_feedback",
            "void",
            null
        );
    }
    getProgramBinary(program, bufSize, length, binaryFormat, binary) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_binary",
            "void",
            [
                ["uint", "program", program],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "binaryFormat", binaryFormat],
                ["pointer", "binary", binary]
            ]
        );
    }
    programBinary(program, binaryFormat, binary, length) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_binary",
            "void",
            [
                ["uint", "program", program],
                ["uint", "binaryFormat", binaryFormat],
                ["pointer", "binary", binary],
                ["sint", "length", length]
            ]
        );
    }
    programParameteri(program, pname, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_parameter_i",
            "void",
            [
                ["uint", "program", program],
                ["uint", "pname", pname],
                ["sint", "value", value]
            ]
        );
    }
    invalidateFramebuffer(target, numAttachments, attachments) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_invalidate_framebuffer",
            "void",
            [
                ["uint", "target", target],
                ["sint", "numAttachments", numAttachments],
                ["pointer", "attachments", attachments]
            ]
        );
    }
    invalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_invalidate_sub_framebuffer",
            "void",
            [
                ["uint", "target", target],
                ["sint", "numAttachments", numAttachments],
                ["pointer", "attachments", attachments],
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    texStorage2D(target, levels, internalformat, width, height) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_storage_2d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "levels", levels],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height]
            ]
        );
    }
    texStorage3D(target, levels, internalformat, width, height, depth) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_storage_3d",
            "void",
            [
                ["uint", "target", target],
                ["sint", "levels", levels],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth]
            ]
        );
    }
    getInternalformativ(target, internalformat, pname, bufSize, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_internal_format_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "internalformat", internalformat],
                ["uint", "pname", pname],
                ["sint", "bufSize", bufSize],
                ["pointer", "params", params]
            ]
        );
    }

//
// GL ES 3.1
//

    dispatchCompute(num_groups_x, num_groups_y, num_groups_z) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_dispatch_compute",
            "void",
            [
                ["uint", "num_groups_x", num_groups_x],
                ["uint", "num_groups_y", num_groups_y],
                ["uint", "num_groups_z", num_groups_z]
            ]
        );
    }
    dispatchComputeIndirect(indirect) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_dispatch_compute_indirect",
            "void",
            [
                ["slong", "indirect", indirect]
            ]
        );
    }
    drawArraysIndirect(mode, indirect) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_arrays_indirect",
            "void",
            [
                ["uint", "mode", mode],
                ["pointer", "indirect", indirect]
            ]
        );
    }
    drawElementsIndirect(mode, type, indirect) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_elements_indirect",
            "void",
            [
                ["uint", "mode", mode],
                ["uint", "type", type],
                ["pointer", "indirect", indirect]
            ]
        );
    }
    framebufferParameteri(target, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_framebuffer_parameter_i",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["sint", "param", param]
            ]
        );
    }
    getFramebufferParameteriv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_framebuffer_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getProgramInterfaceiv(program, programInterface, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_interface_iv",
            "void",
            [
                ["uint", "program", program],
                ["uint", "programInterface", programInterface],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getProgramResourceIndex(program, programInterface, name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_resource_index",
            "uint",
            [
                ["uint", "program", program],
                ["uint", "programInterface", programInterface],
                ["string", "name", name]
            ]
        );
    }
    getProgramResourceName(program, programInterface, index, bufSize, length, name) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_resource_name",
            "void",
            [
                ["uint", "program", program],
                ["uint", "programInterface", programInterface],
                ["uint", "index", index],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["string", "name", name]
            ]
        );
    }
    getProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_resource_iv",
            "void",
            [
                ["uint", "program", program],
                ["uint", "programInterface", programInterface],
                ["uint", "index", index],
                ["sint", "propCount", propCount],
                ["pointer", "props", props],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["pointer", "params", params]
            ]
        );
    }
    getProgramResourceLocation(program, programInterface, name) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_resource_location",
            "sint",
            [
                ["uint", "program", program],
                ["uint", "programInterface", programInterface],
                ["string", "name", name]
            ]
        );
    }
    useProgramStages(pipeline, stages, program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_use_program_stages",
            "void",
            [
                ["uint", "pipeline", pipeline],
                ["uint", "stages", stages],
                ["uint", "program", program]
            ]
        );
    }
    activeShaderProgram(pipeline, program) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_active_shader_program",
            "void",
            [
                ["uint", "pipeline", pipeline],
                ["uint", "program", program]
            ]
        );
    }
    createShaderProgramv(type, count, strings) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_create_shader_program_v",
            "uint",
            [
                ["uint", "type", type],
                ["sint", "count", count],
                ["pointer", "strings", strings]
            ]
        );
    }
    bindProgramPipeline(pipeline) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_program_pipeline",
            "void",
            [
                ["uint", "pipeline", pipeline]
            ]
        );
    }
    deleteProgramPipelines(n, pipelines) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_delete_program_pipelines",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "pipelines", pipelines]
            ]
        );
    }
    genProgramPipelines(n, pipelines) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_gen_program_pipelines",
            "void",
            [
                ["sint", "n", n],
                ["pointer", "pipelines", pipelines]
            ]
        );
    }
    isProgramPipeline(pipeline) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_program_pipeline",
            "uchar",
            [
                ["uint", "pipeline", pipeline]
            ]
        );
    }
    getProgramPipelineiv(pipeline, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_pipeline_iv",
            "void",
            [
                ["uint", "pipeline", pipeline],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    programUniform1i(program, location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1i",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "v0", v0]
            ]
        );
    }
    programUniform2i(program, location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2i",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1]
            ]
        );
    }
    programUniform3i(program, location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3i",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1],
                ["sint", "v2", v2]
            ]
        );
    }
    programUniform4i(program, location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4i",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "v0", v0],
                ["sint", "v1", v1],
                ["sint", "v2", v2],
                ["sint", "v3", v3]
            ]
        );
    }
    programUniform1ui(program, location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1ui",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["uint", "v0", v0]
            ]
        );
    }
    programUniform2ui(program, location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2ui",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1]
            ]
        );
    }
    programUniform3ui(program, location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3ui",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1],
                ["uint", "v2", v2]
            ]
        );
    }
    programUniform4ui(program, location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4ui",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["uint", "v0", v0],
                ["uint", "v1", v1],
                ["uint", "v2", v2],
                ["uint", "v3", v3]
            ]
        );
    }
    programUniform1f(program, location, v0) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1f",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["float", "v0", v0]
            ]
        );
    }
    programUniform2f(program, location, v0, v1) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2f",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1]
            ]
        );
    }
    programUniform3f(program, location, v0, v1, v2) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3f",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1],
                ["float", "v2", v2]
            ]
        );
    }
    programUniform4f(program, location, v0, v1, v2, v3) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4f",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["float", "v0", v0],
                ["float", "v1", v1],
                ["float", "v2", v2],
                ["float", "v3", v3]
            ]
        );
    }
    programUniform1iv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform2iv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform3iv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform4iv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform1uiv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform2uiv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform3uiv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform4uiv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform1fv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_1fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform2fv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_2fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform3fv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_3fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniform4fv(program, location, count, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_4fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix2fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_2fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix3fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_3fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix4fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_4fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix2x3fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_2x3fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix3x2fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_3x2fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix2x4fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_2x4fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix4x2fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_4x2fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix3x4fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_3x4fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    programUniformMatrix4x3fv(program, location, count, transpose, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_program_uniform_matrix_4x3fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "count", count],
                ["uchar", "transpose", transpose],
                ["pointer", "value", value]
            ]
        );
    }
    validateProgramPipeline(pipeline) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_validate_program_pipeline",
            "void",
            [
                ["uint", "pipeline", pipeline]
            ]
        );
    }
    getProgramPipelineInfoLog(pipeline, bufSize, length, infoLog) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_program_pipeline_info_log",
            "void",
            [
                ["uint", "pipeline", pipeline],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["string", "infoLog", infoLog]
            ]
        );
    }
    bindImageTexture(unit, texture, level, layered, layer, access, format) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_image_texture",
            "void",
            [
                ["uint", "unit", unit],
                ["uint", "texture", texture],
                ["sint", "level", level],
                ["uchar", "layered", layered],
                ["sint", "layer", layer],
                ["uint", "access", access],
                ["uint", "format", format]
            ]
        );
    }
    getBooleani_v(target, index, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_boolean_i_v",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index],
                ["pointer", "data", data]
            ]
        );
    }
    memoryBarrier(barriers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_memory_barrier",
            "void",
            [
                ["uint", "barriers", barriers]
            ]
        );
    }
    memoryBarrierByRegion(barriers) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_memory_barrier_by_region",
            "void",
            [
                ["uint", "barriers", barriers]
            ]
        );
    }
    texStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_storage_2d_multisample",
            "void",
            [
                ["uint", "target", target],
                ["sint", "samples", samples],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["uchar", "fixedsamplelocations", fixedsamplelocations]
            ]
        );
    }
    getMultisamplefv(pname, index, val) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_multisample_fv",
            "void",
            [
                ["uint", "pname", pname],
                ["uint", "index", index],
                ["pointer", "val", val]
            ]
        );
    }
    sampleMaski(maskNumber, mask) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sample_mask_i",
            "void",
            [
                ["uint", "maskNumber", maskNumber],
                ["uint", "mask", mask]
            ]
        );
    }
    getTexLevelParameteriv(target, level, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_level_parameter_iv",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getTexLevelParameterfv(target, level, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_level_parameter_fv",
            "void",
            [
                ["uint", "target", target],
                ["sint", "level", level],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    bindVertexBuffer(bindingindex, buffer, offset, stride) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_bind_vertex_buffer",
            "void",
            [
                ["uint", "bindingindex", bindingindex],
                ["uint", "buffer", buffer],
                ["slong", "offset", offset],
                ["sint", "stride", stride]
            ]
        );
    }
    vertexAttribFormat(attribindex, size, type, normalized, relativeoffset) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_format",
            "void",
            [
                ["uint", "attribindex", attribindex],
                ["sint", "size", size],
                ["uint", "type", type],
                ["uchar", "normalized", normalized],
                ["uint", "relativeoffset", relativeoffset]
            ]
        );
    }
    vertexAttribIFormat(attribindex, size, type, relativeoffset) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_i_format",
            "void",
            [
                ["uint", "attribindex", attribindex],
                ["sint", "size", size],
                ["uint", "type", type],
                ["uint", "relativeoffset", relativeoffset]
            ]
        );
    }
    vertexAttribBinding(attribindex, bindingindex) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_attrib_binding",
            "void",
            [
                ["uint", "attribindex", attribindex],
                ["uint", "bindingindex", bindingindex]
            ]
        );
    }
    vertexBindingDivisor(bindingindex, divisor) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_vertex_binding_divisor",
            "void",
            [
                ["uint", "bindingindex", bindingindex],
                ["uint", "divisor", divisor]
            ]
        );
    }

//
// GL ES 3.2
//

    blendBarrier() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_barrier",
            "void",
            null
        );
    }
    copyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_copy_image_sub_data",
            "void",
            [
                ["uint", "srcName", srcName],
                ["uint", "srcTarget", srcTarget],
                ["sint", "srcLevel", srcLevel],
                ["sint", "srcX", srcX],
                ["sint", "srcY", srcY],
                ["sint", "srcZ", srcZ],
                ["uint", "dstName", dstName],
                ["uint", "dstTarget", dstTarget],
                ["sint", "dstLevel", dstLevel],
                ["sint", "dstX", dstX],
                ["sint", "dstY", dstY],
                ["sint", "dstZ", dstZ],
                ["sint", "srcWidth", srcWidth],
                ["sint", "srcHeight", srcHeight],
                ["sint", "srcDepth", srcDepth]
            ]
        );
    }
    debugMessageControl(source, type, severity, count, ids, enabled) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_debug_message_control",
            "void",
            [
                ["uint", "source", source],
                ["uint", "type", type],
                ["uint", "severity", severity],
                ["sint", "count", count],
                ["pointer", "ids", ids],
                ["uchar", "enabled", enabled]
            ]
        );
    }
    debugMessageInsert(source, type, id, severity, length, buf) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_debug_message_insert",
            "void",
            [
                ["uint", "source", source],
                ["uint", "type", type],
                ["uint", "id", id],
                ["uint", "severity", severity],
                ["sint", "length", length],
                ["string", "buf", buf]
            ]
        );
    }
    debugMessageCallback(callback, userParam) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_debug_message_callback",
            "void",
            [
                ["pointer", "callback", callback],
                ["pointer", "userParam", userParam]
            ]
        );
    }
    getDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_debug_message_log",
            "uint",
            [
                ["uint", "count", count],
                ["sint", "bufSize", bufSize],
                ["pointer", "sources", sources],
                ["pointer", "types", types],
                ["pointer", "ids", ids],
                ["pointer", "severities", severities],
                ["pointer", "lengths", lengths],
                ["string", "messageLog", messageLog]
            ]
        );
    }
    pushDebugGroup(source, id, length, message) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_push_debug_group",
            "void",
            [
                ["uint", "source", source],
                ["uint", "id", id],
                ["sint", "length", length],
                ["string", "message", message]
            ]
        );
    }
    popDebugGroup() {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_pop_debug_group",
            "void",
            null
        );
    }
    objectLabel(identifier, name, length, label) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_object_label",
            "void",
            [
                ["uint", "identifier", identifier],
                ["uint", "name", name],
                ["sint", "length", length],
                ["string", "label", label]
            ]
        );
    }
    getObjectLabel(identifier, name, bufSize, length, label) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_object_label",
            "void",
            [
                ["uint", "identifier", identifier],
                ["uint", "name", name],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["string", "label", label]
            ]
        );
    }
    objectPtrLabel(ptr, length, label) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_object_ptr_label",
            "void",
            [
                ["pointer", "ptr", ptr],
                ["sint", "length", length],
                ["string", "label", label]
            ]
        );
    }
    getObjectPtrLabel(ptr, bufSize, length, label) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_object_ptr_label",
            "void",
            [
                ["pointer", "ptr", ptr],
                ["sint", "bufSize", bufSize],
                ["pointer", "length", length],
                ["string", "label", label]
            ]
        );
    }
    getPointerv(pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_pointer_v",
            "void",
            [
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    enablei(target, index) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_enable_i",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index",index ]
            ]
        );
    }
    disablei(target, index) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_disable_i",
            "void",
            [
                ["uint", "target", target],
                ["uint", "index", index]
            ]
        );
    }
    blendEquationi(buf, mode) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_equation_i",
            "void",
            [
                ["uint", "buf", buf],
                ["uint", "mode", mode]
            ]
        );
    }
    blendEquationSeparatei(buf, modeRGB, modeAlpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_equation_separate_i",
            "void",
            [
                ["uint", "buf", buf],
                ["uint", "modeRGB", modeRGB],
                ["uint", "modeAlpha", modeAlpha]
            ]
        );
    }
    blendFunci(buf, src, dst) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_func_i",
            "void",
            [
                ["uint", "buf", buf],
                ["uint", "src", src],
                ["uint", "dst", dst]
            ]
        );
    }
    blendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_blend_func_separate_i",
            "void",
            [
                ["uint", "buf", buf],
                ["uint", "srcRGB", srcRGB],
                ["uint", "dstRGB", dstRGB],
                ["uint", "srcAlpha", srcAlpha],
                ["uint", "dstAlpha", dstAlpha]
            ]
        );
    }
    colorMaski(index, r, g, b, a) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_color_mask_i",
            "void",
            [
                ["uint", "index", index],
                ["uchar", "r", r],
                ["uchar", "g", g],
                ["uchar", "b", b],
                ["uchar", "a", a]
            ]
        );
    }
    isEnabledi(target, index) {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_is_enabled_i",
            "uchar",
            [
                ["uint", "target", target],
                ["uint", "index", index]
            ]
        );
    }
    drawElementsBaseVertex(mode, count, type, indices, basevertex) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_elements_base_vertex",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices],
                ["sint", "basevertex", basevertex]
            ]
        );
    }
    drawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_range_elements_base_vertex",
            "void",
            [
                ["uint", "mode", mode],
                ["uint", "start", start],
                ["uint", "end", end],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices],
                ["sint", "basevertex", basevertex]
            ]
        );
    }
    drawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_draw_elements_instanced_base_vertex",
            "void",
            [
                ["uint", "mode", mode],
                ["sint", "count", count],
                ["uint", "type", type],
                ["pointer", "indices", indices],
                ["sint", "instancecount", instancecount],
                ["sint", "basevertex", basevertex]
            ]
        );
    }
    framebufferTexture(target, attachment, texture, level) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_framebuffer_texture",
            "void",
            [
                ["uint", "target", target],
                ["uint", "attachment", attachment],
                ["uint", "texture", texture],
                ["sint", "level", level]
            ]
        );
    }
    primitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_primitive_bounding_box",
            "void",
            [
                ["float", "minX", minX],
                ["float", "minY", minY],
                ["float", "minZ", minZ],
                ["float", "minW", minW],
                ["float", "maxX", maxX],
                ["float", "maxY", maxY],
                ["float", "maxZ", maxZ],
                ["float", "maxW", maxW]
            ]
        );
    }
    getGraphicsResetStatus() {
        return lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_graphics_reset_status",
            "uint",
            null
        );
    }
    readnPixels(x, y, width, height, format, type, bufSize, data) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_read_n_pixels",
            "void",
            [
                ["sint", "x", x],
                ["sint", "y", y],
                ["sint", "width", width],
                ["sint", "height", height],
                ["uint", "format", format],
                ["uint", "type", type],
                ["sint", "bufSize", bufSize],
                ["pointer", "data", data]
            ]
        );
    }
    getnUniformfv(program, location, bufSize, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_n_uniform_fv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "bufSize", bufSize],
                ["pointer", "params", params]
            ]
        );
    }
    getnUniformiv(program, location, bufSize, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_n_uniform_iv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "bufSize", bufSize],
                ["pointer", "params", params]
            ]
        );
    }
    getnUniformuiv(program, location, bufSize, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_n_uniform_uiv",
            "void",
            [
                ["uint", "program", program],
                ["sint", "location", location],
                ["sint", "bufSize", bufSize],
                ["pointer", "params", params]
            ]
        );
    }
    minSampleShading(value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_min_sample_shading",
            "void",
            [
                ["float", "value", value]
            ]
        );
    }
    patchParameteri(pname, value) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_patch_parameter_i",
            "void",
            [
                ["uint", "pname", pname],
                ["sint", "value", value]
            ]
        );
    }
    texParameterIiv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_iiv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    texParameterIuiv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_parameter_iuiv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getTexParameterIiv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_parameter_iiv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    getTexParameterIuiv(target, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_tex_parameter_iuiv",
            "void",
            [
                ["uint", "target", target],
                ["uint", "pname", pname],
                ["pointer", "params", params]
            ]
        );
    }
    samplerParameterIiv(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_iiv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", param]
            ]
        );
    }
    samplerParameterIuiv(sampler, pname, param) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_sampler_parameter_iuiv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", param]
            ]
        );
    }
    getSamplerParameterIiv(sampler, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_sampler_parameter_iiv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", params]
            ]
        );
    }
    getSamplerParameterIuiv(sampler, pname, params) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_get_sampler_parameter_iuiv",
            "void",
            [
                ["uint", "sampler", sampler],
                ["uint", "pname", pname],
                ["pointer", "param", params]
            ]
        );
    }
    texBuffer(target, internalformat, buffer) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_buffer",
            "void",
            [
                ["uint", "target", target],
                ["uint", "internalformat", internalformat],
                ["uint", "buffer", buffer]
            ]
        );
    }
    texBufferRange(target, internalformat, buffer, offset, size) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_buffer_range",
            "void",
            [
                ["uint", "target", target],
                ["uint", "internalformat", internalformat],
                ["uint", "buffer", buffer],
                ["slong", "offset", offset],
                ["slong", "size", size]
            ]
        );
    }
    texStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations) {
        lib.ffi(
            globalThis.__RAIA_GLES__.handle,
            "raia_gl_tex_storage_3d_multisample",
            "void",
            [
                ["uint", "target", target],
                ["sint", "samples", samples],
                ["uint", "internalformat", internalformat],
                ["sint", "width", width],
                ["sint", "height", height],
                ["sint", "depth", depth],
                ["uchar", "fixedsamplelocations", fixedsamplelocations]
            ]
        );
    }

    //
    // (代替関数)
    //

    /**
     * @param {int} x 
     * @param {int} y 
     * @param {int} width 
     * @param {int} height 
     */
    viewportAlt(x, y, width, height) {
        var args = JSON.stringify({
            "x": x,
            "y": y,
            "width": width,
            "height": height
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_viewport_alt", args);
    }
    /**
     * @param {real} red 0.0 ~ 1.0
     * @param {real} green 0.0 ~ 1.0
     * @param {real} blue 0.0 ~ 1.0
     * @param {real} alpha 0.0 ~ 1.0
     */
    clearColorAlt(red, green, blue, alpha) {
        var args = JSON.stringify({
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_color_alt", args);
    }
    /**
     * @param {uint} mask 
     */
    clearAlt(mask) {
        var args = JSON.stringify({
            "mask": mask
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_clear_alt", args);
    }
    /**
     * @param {uint} program 
     */
    useProgramAlt(program) {
        var args = JSON.stringify({
            "program": program
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_use_program_alt", args);
    }
    /**
     * @param {uint} index 
     * @param {int} size 
     * @param {uint} type 
     * @param {uint} normalized 0 or 1
     * @param {int} stride 
     * @param {uintptr} pointer 
     */
    vertexAttribPointerAlt(index, size, type, normalized, stride, pointer) {
        var args = JSON.stringify({
            "index": index,
            "size": size,
            "type": type,
            "normalized": normalized,
            "stride": stride,
            "pointer": pointer
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_vertex_attrib_pointer_alt", args);
    }
    /**
     * @param {uint} index 
     */
    enableVertexAttribArrayAlt(index) {
        var args = JSON.stringify({
            "index": index
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_enable_vertex_attrib_array_alt", args);
    }
    /**
     * @param {uint} target 
     * @param {int} level 
     * @param {int} internalformat 
     * @param {int} width 
     * @param {int} height 
     * @param {int} border 
     * @param {uint} format 
     * @param {uint} type 
     * @param {ArrayBuffer} pixels 
     */
    texImage2DAlt(target, level, internalformat, width, height, border, format, type, pixels) {
        var args = JSON.stringify({
            "target": target,
            "level": level,
            "internalformat": internalformat,
            "width": width,
            "height": height,
            "border": border,
            "format": format,
            "type": type,
            "pixels": std.bufToPtr(pixels)
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_image_2d_alt", args);
    }
    /**
     * @param {uint} texture 
     */
    activeTextureAlt(texture) {
        var args = JSON.stringify({
            "texture": texture
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_active_texture_alt", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} texture 
     */
    bindTextureAlt(target, texture) {
        var args = JSON.stringify({
            "target": target,
            "texture": texture
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_texture_alt", args);
    }
    /**
     * 
     * @param {int} location 
     * @param {int} v0 
     */
    uniform1iAlt(location, v0) {
        var args = JSON.stringify({
            "location": location,
            "v0": v0
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_uniform_1i_alt", args);
    }
    /**
     * 
     * @param {uint} mode 
     * @param {int} count 
     * @param {uint} type 
     * @param {uintptr | null} indices 
     */
    drawElementsAlt(mode, count, type, indices) {
        var args = JSON.stringify({
            "mode": mode,
            "count": count,
            "type": type,
            "indices": indices
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_draw_elements_alt", args);
    }
    /**
     * 
     * @param {uint} type 
     * @returns {uint} shader
     */
    createShaderAlt(type) {
        var args = JSON.stringify({
            "type": type
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_create_shader_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} shader 
     * @param {int} count 
     * @param {string} string 
     * @param {int | null} length 
     */
    shaderSourceAlt(shader, count, string, length) {
        var args = JSON.stringify({
            "shader": shader,
            "count": count,
            "string": string,
            "length": length
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_shader_source_alt", args);
    }
    /**
     * 
     * @param {uint} shader 
     */
    compileShaderAlt(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_compile_shader_alt", args);
    }
    /**
     * 
     * @param {uint} shader 
     * @param {uint} pname 
     * @returns {int} params
     */
    getShaderivAlt(shader, pname) {
        var args = JSON.stringify({
            "shader": shader,
            "pname": pname
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_get_shader_iv_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @returns {uint} program
     */
    createProgramAlt() {
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_create_program_alt");
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} program 
     * @param {uint} shader 
     */
    attachShaderAlt(program, shader) {
        var args = JSON.stringify({
            "program": program,
            "shader": shader
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_attach_shader_alt", args);
    }
    /**
     * 
     * @param {uint} shader 
     */
    deleteShaderAlt(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_shader_alt", args);
    }
    /**
     * 
     * @param {uint} program 
     */
    linkProgramAlt(program) {
        var args = JSON.stringify({
            "program": program
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_link_program_alt", args);
    }
    /**
     * 
     * @param {uint} pname 
     * @param {int} param 
     */
    pixelStoreiAlt(pname, param) {
        var args = JSON.stringify({
            "pname": pname,
            "param": param
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_pixel_store_i_alt", args);
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} textures
     */
    genTexturesAlt(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_textures_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} pname 
     * @param {int} param 
     */
    texParameteriAlt(target, pname, param) {
        var args = JSON.stringify({
            "target": target,
            "pname": pname,
            "param": param
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_tex_parameter_i_alt", args);
    }
    /**
     * 
     * @param {uint} program 
     * @param {string} name 
     * @returns {int} location
     */
    getAttribLocationAlt(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_get_attrib_location_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} program 
     * @param {string} name 
     * @returns {int} location
     */
    getUniformLocationAlt(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_get_uniform_location_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} arrays
     */
    genVertexArraysAlt(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_vertex_arrays_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} buffers
     */
    genBuffersAlt(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_gen_buffers_alt", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} array 
     */
    bindVertexArrayAlt(array) {
        var args = JSON.stringify({
            "array": array
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_vertex_array_alt", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} buffer 
     */
    bindBufferAlt(target, buffer) {
        var args = JSON.stringify({
            "target": target,
            "buffer": buffer
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_bind_buffer_alt", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} size 
     * @param {ArrayBuffer} data 
     * @param {uint} usage 
     */
    bufferDataAlt(target, size, data, usage) {
        var args = JSON.stringify({
            "target": target,
            "size": size,
            "data": std.bufToPtr(data),
            "usage": usage
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_buffer_data_alt", args);
    }
    /**
     * 
     * @param {uint} arrays 
     */
    deleteVertexArraysAlt(arrays) {
        var args = JSON.stringify({
            "arrays": arrays
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_vertex_arrays_alt", args);
    }
    /**
     * 
     * @param {uint} buffers 
     */
    deleteBuffersAlt(buffers) {
        var args = JSON.stringify({
            "buffers": buffers
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_buffers_alt", args);
    }
    /**
     * 
     * @param {uint} textures 
     */
    deleteTexturesAlt(textures) {
        var args = JSON.stringify({
            "textures": textures
        });
        lib.call(globalThis.__RAIA_GLES__.handle, "raia_gl_delete_textures_alt", args);
    }
}