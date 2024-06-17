local ffi = require("ffi")

-- 汎用ファイナライザ設定関数
local function setFinalizer(key, deleteFunction)
    ffi.gc(ffi.new("int[1]", key), function(k)
        deleteFunction(k[0])
    end)
end

ffi.cdef[[
    // # static
    /*
    // ## static_gr_backend_format
    void static_gr_backend_format_delete(int key);
    // ## static_gr_backend_texture
    void static_gr_backend_texture_delete(int key);
    // ## static_gr_color_format_desc
    void static_gr_color_format_desc_delete(int key);
    // ## static_gr_context_thread_safe_proxy
    void static_gr_context_thread_safe_proxy_delete(int key);
    void *static_gr_context_thread_safe_proxy_get(int key);
    // ## static_gr_direct_context
    void static_gr_direct_context_delete(int key);
    void *static_gr_direct_context_get(int key);
    // ## static_gr_direct_context_direct_context_id
    void static_gr_direct_context_direct_context_id_delete(int key);
    */
    // ## static_sk_android_codec
    void static_sk_android_codec_delete(int key);
    void *static_sk_android_codec_get(int key);
    // ## static_sk_b_box_hierarchy
    void static_sk_b_box_hierarchy_delete(int key);
    void *static_sk_b_box_hierarchy_get(int key);
    // ## static_sk_blend_mode
    void static_optional_sk_blend_mode_delete(int key);
    // ## static_sk_blender
    void static_sk_blender_delete(int key);
    void *static_sk_blender_get(int key);
    // ## static_sk_canvas
    void static_sk_canvas_delete(int key);
    void *static_sk_canvas_get(int key);
    // ## static_sk_capabilities
    void static_const_sk_capabilities_delete(int key);
    const void *static_const_sk_capabilities_get(int key);
    // ## static_sk_codec
    void static_sk_codec_delete(int key);
    void *static_sk_codec_get(int key);
    // ## static_sk_codecs_decoder
    void static_sk_codecs_decoder_delete(int key);
    // ## static_sk_color
    void static_sk_color_delete(int key);
    // // static_sk_color_4f
    void static_sk_color_4f_delete(int key);
    // ## static_sk_color_filter
    void static_sk_color_filter_delete(int key);
    void *static_sk_color_filter_get(int key);
    // ## static_sk_color_info
    void static_sk_color_info_delete(int key);
    // ## static_sk_color_matrix
    void static_sk_color_matrix_delete(int key);
    // ## static_sk_color_space
    void static_sk_color_space_delete(int key);
    void *static_sk_color_space_get(int key);
    // ## static_sk_color_table
    void static_sk_color_table_delete(int key);
    void *static_sk_color_table_get(int key);
    // ## static_sk_contour_measure
    void static_sk_contour_measure_delete(int key);
    void *static_sk_contour_measure_get(int key);
    // ## static_sk_cubic_resampler
    void static_sk_cubic_resampler_delete(int key);
    // ## static_sk_data
    void static_sk_data_delete(int key);
    void *static_sk_data_get(int key);
    void static_const_sk_data_delete(int key);
    const void *static_const_sk_data_get(int key);
    // ## static_sk_data_table
    void static_sk_data_table_delete(int key);
    void *static_sk_data_table_get(int key);
    // ## static_sk_document
    void static_sk_document_delete(int key);
    void *static_sk_document_get(int key);
    // ## static_sk_drawable
    void static_sk_drawable_delete(int key);
    void *static_sk_drawable_get(int key);
    // ## static_sk_drawable_gpu_draw_handler
    void static_sk_drawable_gpu_draw_handler_delete(int key);
    void *static_sk_drawable_gpu_draw_handler_get(int key);
    // ## static_sk_encoder
    void static_sk_encoder_delete(int key);
    void *static_sk_encoder_get(int key);
    // ## static_sk_encoder_frame
    void static_const_sk_encoder_frame_delete(int key);
    // ## static_sk_executor
    void static_sk_executor_delete(int key);
    void *static_sk_executor_get(int key);
    // ## static_sk_file_stream
    void static_sk_file_stream_delete(int key);
    void *static_sk_file_stream_get(int key);
    // ## static_sk_flattenable
    void static_sk_flattenable_delete(int key);
    void *static_sk_flattenable_get(int key);
    // ## static_sk_flattenable_factory
    void static_sk_flattenable_factory_delete(int key);
    // ## static_sk_font
    void static_sk_font_delete(int key);
    // ## static_sk_font_arguments
    void static_sk_font_arguments_delete(int key);
    // ## static_sk_font_arguments_pallete
    void static_sk_font_arguments_palette_delete(int key);
    // ## static_sk_font_arguments_variation_position
    void static_sk_font_arguments_variation_position_delete(int key);
    // ## static_sk_font_mgr
    void static_sk_font_mgr_delete(int key);
    void *static_sk_font_mgr_get(int key);
    // ## static_sk_font_style
    void static_sk_font_style_delete(int key);
    // ## static_sk_font_style_set
    void static_sk_font_style_set_delete(int key);
    void *static_sk_font_style_set_get(int key);
    // ## static_sk_i_point
    void static_sk_i_point_delete(int key);
    // ## static_sk_i_rect
    void static_sk_i_rect_delete(int key);
    // ## static_sk_i_size
    void static_sk_i_size_delete(int key);
    // ## static_sk_id_change_listener
    void static_sk_id_change_listener_delete(int key);
    void *static_sk_id_change_listener_get(int key);
    // ## static_sk_image
    void static_sk_image_delete(int key);
    void *static_sk_image_get(int key);
    // ## static_sk_image_filter
    void static_sk_image_filter_delete(int key);
    void *static_sk_image_filter_get(int key);
    // ## static_sk_image_generator
    void static_sk_image_generator_delete(int key);
    void *static_sk_image_generator_get(int key);
    // ## static_sk_image_info
    void static_sk_image_info_delete(int key);
    // ## static_sk_image_required_properties
    void static_sk_image_required_properties_delete(int key);
    // ## static_sk_m_44
    void static_sk_m_44_delete(int key);
    // ## static_sk_mask_filter
    void static_sk_mask_filter_delete(int key);
    void *static_sk_mask_filter_get(int key);
    // ## static_sk_matrix
    void static_sk_matrix_delete(int key);
    // ## static_sk_memory_stream
    void static_sk_memory_stream_delete(int key);
    void *static_sk_memory_stream_get(int key);
    // ## static_sk_mesh_child_ptr
    // ## static_sk_mesh_index_buffer
    void static_sk_mesh_index_buffer_delete(int key);
    void *static_sk_mesh_index_buffer_get(int key);
    // ## static_sk_mesh_vertex_buffer
    void static_sk_mesh_vertex_buffer_delete(int key);
    void *static_sk_mesh_vertex_buffer_get(int key);
    // ## static_sk_path
    void static_sk_path_delete(int key);
    // ## static_sk_path_effect
    void static_sk_path_effect_delete(int key);
    void *static_sk_path_effect_get(int key);
    // ## static_sk_picture
    void static_sk_picture_delete(int key);
    void *static_sk_picture_get(int key);
    // ## static_sk_pixel_ref
    void static_sk_pixel_ref_delete(int key);
    void *static_sk_pixel_ref_get(int key);
    // ## static_sk_pixmap
    void static_sk_pixmap_delete(int key);
    // ## static_sk_point
    void static_sk_point_delete(int key);
    // ## static_sk_point_3
    void static_sk_point_3_delete(int key);
    // ## static_sk_r_rect
    void static_sk_r_rect_delete(int key);
    // ## static_sk_rect
    void static_sk_rect_delete(int key);
    void *static_sk_rect_get_ptr(int key);
    // ## static_sk_rsx_form
    void static_sk_rsx_form_delete(int key);
    // ## static_sk_runtime_effect
    void static_sk_runtime_effect_delete(int key);
    void *static_sk_runtime_effect_get(int key);
    //
    void static_sk_runtime_effect_builder_builder_child_delete(int key);
    //
    void static_sk_runtime_effect_builder_builder_uniform_delete(int key);
    // ## static_sk_runtime_effect_child
    void static_const_sk_runtime_effect_child_delete(int key);
    // ## static_sk_runtime_effect_child_ptr
    void static_const_sk_runtime_effect_child_ptr_delete(int key);
    // ## static_sk_runtime_effect_result
    void static_sk_runtime_effect_result_delete(int key);
    // ## static_sk_runtime_effect_traced_shader
    void static_sk_runtime_effect_traced_shader_delete(int key);
    // ## static_sk_runtime_effect_uniform
    void static_const_sk_runtime_effect_uniform_delete(int key);
    // ## static_sk_sampling_options
    void static_sk_sampling_options_delete(int key);
    // ## static_sk_shader
    void static_sk_shader_delete(int key);
    void *static_sk_shader_get(int key);
    // ## static_sk_shaper
    void static_sk_shaper_delete(int key);
    void *static_sk_shaper_get(int key);
    // ## static_sk_shaper_bi_di_run_iterator
    void static_sk_shaper_bi_di_run_iterator_delete(int key);
    void *static_sk_shaper_bi_di_run_iterator_get(int key);
    // ## static_sk_shaper_font_run_iterator
    void static_sk_shaper_font_run_iterator_delete(int key);
    void *static_sk_shaper_font_run_iterator_get(int key);
    // ## static_sk_shaper_language_run_iterator
    void static_sk_shaper_language_run_iterator_delete(int key);
    void *static_sk_shaper_language_run_iterator_get(int key);
    // 
    void static_sk_shaper_run_handler_buffer_delete(int key);
    // ## static_sk_shaper_script_run_iterator
    void static_sk_shaper_script_run_iterator_delete(int key);
    void *static_sk_shaper_script_run_iterator_get(int key);
    //
    void static_sk_size_delete(int key);
    // ## static_sk_stream
    void static_sk_stream_delete(int key);
    void *static_sk_stream_get(int key);
    // ## static_sk_stream_asset
    void static_sk_stream_asset_delete(int key);
    void *static_sk_stream_asset_get(int key);
    // ## static_sk_stream_memory
    void static_sk_stream_memory_delete(int key);
    void *static_sk_stream_memory_get(int key);
    // ## static_sk_stream_rewindable
    void static_sk_stream_rewindable_delete(int key);
    void *static_sk_stream_rewindable_get(int key);
    // ## static_sk_stream_seekable
    void static_sk_stream_seekable_delete(int key);
    void *static_sk_stream_seekable_get(int key);
    // ## static_sk_string
    void static_sk_string_delete(int key);
    void static_sk_span_sk_string_delete(int key);
    // ## static_sk_stroke_rec
    void static_sk_stroke_rec_delete(int key);
    // ## static_sk_surface
    void static_sk_surface_delete(int key);
    void *static_sk_surface_get(int key);
    // ## static_sk_surface_props
    void static_sk_surface_props_delete(int key);
    /*
    // ## static_sk_svg_circle
    void static_sk_svg_circle_delete(int key);
    void *static_sk_svg_circle_get(int key);
    // ## static_sk_svg_clip_path
    void static_sk_svg_clip_path_delete(int key);
    void *static_sk_svg_clip_path_get(int key);
    // ## static_sk_svg_defs
    void static_sk_svg_defs_delete(int key);
    void *static_sk_svg_defs_get(int key);
    // ## static_sk_svg_dom
    void static_sk_svg_dom_delete(int key);
    void *static_sk_svg_dom_get(int key);
    // ## static_sk_svg_ellipse
    void static_sk_svg_ellipse_delete(int key);
    void *static_sk_svg_ellipse_get(int key);
    // ## static_sk_svg_fe_blend
    void static_sk_svg_fe_blend_delete(int key);
    void *static_sk_svg_fe_blend_get(int key);
    // ## static_sk_svg_fe_color_matrix
    void static_sk_svg_fe_color_matrix_delete(int key);
    void *static_sk_svg_fe_color_matrix_get(int key);
    // ## static_sk_svg_fe_composite
    void static_sk_svg_fe_composite_delete(int key);
    void *static_sk_svg_fe_composite_get(int key);
    // ## static_sk_svg_fe_diffuse_lighting
    void static_sk_svg_fe_diffuse_lighting_delete(int key);
    void *static_sk_svg_fe_diffuse_lighting_get(int key);
    // ## static_sk_svg_fe_displacement_map
    void static_sk_svg_fe_displacement_map_delete(int key);
    void *static_sk_svg_fe_displacement_map_get(int key);
    // ## static_sk_svg_fe_distant_light
    void static_sk_svg_fe_distant_light_delete(int key);
    void *static_sk_svg_fe_distant_light_get(int key);
    // ## static_sk_svg_fe_flood
    void static_sk_svg_fe_flood_delete(int key);
    void *static_sk_svg_fe_flood_get(int key);
    // ## static_sk_svg_fe_gaussian_blur
    void static_sk_svg_fe_gaussian_blur_delete(int key);
    void *static_sk_svg_fe_gaussian_blur_get(int key);
    // ## static_sk_svg_fe_image
    void static_sk_svg_fe_image_delete(int key);
    void *static_sk_svg_fe_image_get(int key);
    // ## static_sk_svg_fe_morphology
    void static_sk_svg_fe_morphology_delete(int key);
    void *static_sk_svg_fe_morphology_get(int key);
    // ## static_sk_svg_fe_offset
    void static_sk_svg_fe_offset_delete(int key);
    void *static_sk_svg_fe_offset_get(int key);
    // ## static_sk_svg_fe_point_light
    void static_sk_svg_fe_point_light_delete(int key);
    void *static_sk_svg_fe_point_light_get(int key);
    // ## static_sk_svg_fe_specular_lighting
    void static_sk_svg_fe_specular_lighting_delete(int key);
    void *static_sk_svg_fe_specular_lighting_get(int key);
    // ## static_sk_svg_fe_spot_light
    void static_sk_svg_fe_spot_light_delete(int key);
    void *static_sk_svg_fe_spot_light_get(int key);
    // ## static_sk_svg_fe_turbulence
    void static_sk_svg_fe_turbulence_delete(int key);
    void *static_sk_svg_fe_turbulence_get(int key);
    // ## static_sk_svg_g
    void static_sk_svg_g_delete(int key);
    void *static_sk_svg_g_get(int key);
    // ## static_sk_svg_image
    // ## static_sk_svg_line
    void static_sk_svg_line_delete(int key);
    void *static_sk_svg_line_get(int key);
    // ## static_sk_svg_linear_gradient
    void static_sk_svg_linear_gradient_delete(int key);
    void *static_sk_svg_linear_gradient_get(int key);
    // ## static_sk_svg_mask
    void static_sk_svg_mask_delete(int key);
    void *static_sk_svg_mask_get(int key);
    // ## static_sk_svg_node
    void static_sk_svg_node_delete(int key);
    void *static_sk_svg_node_get(int key);
    // ## static_sk_svg_path
    void static_sk_svg_path_delete(int key);
    void *static_sk_svg_path_get(int key);
    // ## static_sk_svg_pattern
    void static_sk_svg_pattern_delete(int key);
    void *static_sk_svg_pattern_get(int key);
    // ## static_sk_svg_poly
    void static_sk_svg_poly_delete(int key);
    void *static_sk_svg_poly_get(int key);
    // ## static_sk_svg_presentation_attributes
    void static_sk_svg_presentation_attributes_delete(int key);
    // ## static_sk_svg_radial_gradient
    void static_sk_svg_radial_gradient_delete(int key);
    void *static_sk_svg_radial_gradient_get(int key);
    // ## static_sk_svg_rect
    void static_sk_svg_rect_delete(int key);
    void *static_sk_svg_rect_get(int key);
    // ## static_sk_svg_stop
    void static_sk_svg_stop_delete(int key);
    void *static_sk_svg_stop_get(int key);
    // ## static_sk_svg_svg
    void static_sk_svg_svg_delete(int key);
    void *static_sk_svg_svg_get(int key);
    // ## static_sk_svg_t_span
    void static_sk_svg_t_span_delete(int key);
    void *static_sk_svg_t_span_get(int key);
    // ## static_sk_svg_text
    void static_sk_svg_text_delete(int key);
    void *static_sk_svg_text_get(int key);
    // ## static_sk_svg_text_literal
    void static_sk_svg_text_literal_delete(int key);
    void *static_sk_svg_text_literal_get(int key);
    // ## static_sk_svg_text_path
    void static_sk_svg_text_path_delete(int key);
    void *static_sk_svg_text_path_get(int key);
    // ## static_sk_svg_use
    void static_sk_svg_use_delete(int key);
    void *static_sk_svg_use_get(int key);
    */
    // ## static_sk_text_blob
    void static_sk_text_blob_delete(int key);
    void *static_sk_text_blob_get(int key);
    // ## static_sk_typeface
    void static_sk_typeface_delete(int key);
    void *static_sk_typeface_get(int key);
    //
    void static_sk_v2_delete(int key);
    //
    void static_sk_v3_delete(int key);
    //
    void static_sk_v4_delete(int key);
    // ## static_sk_vertices
    void static_sk_vertices_delete(int key);
    void *static_sk_vertices_get(int key);
    // ## static_sk_yuva_info
    void static_sk_yuva_info_delete(int key);
    // ## static_sk_yuva_pixmap_info
    void static_sk_yuva_pixmap_info_delete(int key);
    // ## static_sk_yuva_pixmaps
    void static_sk_yuva_pixmaps_delete(int key);
    //
    void static_chrono_milliseconds_delete(int key);
    // ## static_std_function_void_void
    void static_function_void_void_delete(int key);
    // ## static_std_string_view
    void static_string_view_delete(int key);
    // ## static_std_tuple_int_int
    void static_tuple_int_int_delete(int key);
    // ## static_std_tuple_int_sk_yuva_pixmap_info_data_type
    void static_tuple_int_sk_yuva_pixmap_info_data_type_delete(int key);
    // ## static_std_tuple_sk_image_sk_codec_result
    void static_tuple_sk_image_sk_codec_result_delete(int key);
    // ## static_std_vector_sk_codec_frame_info
    void static_vector_sk_codec_frame_into_delete(int key);
    void static_vector_sk_codec_frame_into_pop_back(int key);
    void static_vector_sk_codec_frame_into_erase(int key, int index);
    // ## static_std_vector_sk_scalar
    void static_vector_sk_scalar_delete(int key);
    float static_vector_sk_scalar_get(int key, int index);
    void static_vector_sk_scalar_push_back(int key, float value);
    void static_vector_sk_scalar_insert(int key, int index, float value);
    void static_vector_sk_scalar_pop_back(int key);
    void static_vector_sk_scalar_erase(int key, int index);
    /*
    // ## static_std_vector_sk_svg_length
    void static_vector_sk_svg_length_delete(int key);
    void static_vector_sk_svg_length_pop_back(int key);
    void static_vector_sk_svg_length_erase(int key, int index);
    */
    //
    // # binding
    /*
    // ## gr_backend_drawable_info
    void *GrBackendDrawableInfo_new();
    void *GrBackendDrawableInfo_new_2(const void *info);
    void GrBackendDrawableInfo_delete(void *backend_drawable_info);
    bool GrBackendDrawableInfo_isValid(void *backend_drawable_info);
    unsigned int GrBackendDrawableInfo_backend(void *backend_drawable_info);
    bool GrBackendDrawableInfo_getVkDrawableInfo(void *backend_drawable_info, void *outInfo);
    // ## gr_backend_format
    void *GrBackendFormat_new();
    void *GrBackendFormat_new_2(const void *format);
    void GrBackendFormat_delete(void *backend_format);
    unsigned int GrBackendFormat_backend(void *backend_format);
    int GrBackendFormat_textureType(void *backend_format);
    uint32_t GrBackendFormat_channelMask(void *backend_format);
    int GrBackendFormat_desc(void *backend_format);
    int GrBackendFormat_asMockColorType(void *backend_format);
    int GrBackendFormat_asMockCompressionType(void *backend_format);
    bool GrBackendFormat_isMockStencilFormat(void *backend_format);
    int GrBackendFormat_makeTexture2D(void *backend_format);
    bool GrBackendFormat_isValid(void *backend_format);
    int GrBackendFormat_MakeMock(int colorType, int compression, bool isStencilFormat);
    // ## gr_backend_render_target
    void *GrBackendRenderTarget_new();
    void *GrBackendRenderTarget_new_2(int width, int height, int sampleCnt, int stencilBits, const void *mockInfo);
    void *GrBackendRenderTarget_new_3(const void *that);
    void GrBackendRenderTarget_delete(void *backend_render_target);
    int GrBackendRenderTarget_dimensions(void *backend_render_target);
    int GrBackendRenderTarget_width(void *backend_render_target);
    int GrBackendRenderTarget_height(void *backend_render_target);
    int GrBackendRenderTarget_sampleCnt(void *backend_render_target);
    int GrBackendRenderTarget_stencilBits(void *backend_render_target);
    unsigned int GrBackendRenderTarget_backend(void *backend_render_target);
    bool GrBackendRenderTarget_isFramebufferOnly(void *backend_render_target);
    int GrBackendRenderTarget_getBackendFormat(void *backend_render_target);
    bool GrBackendRenderTarget_getMockRenderTargetInfo(void *backend_render_target, void *info);
    void GrBackendRenderTarget_setMutableState(void *backend_render_target, const void *state);
    bool GrBackendRenderTarget_isProtected(void *backend_render_target);
    bool GrBackendRenderTarget_isValid(void *backend_render_target);
    // ## gr_backend_semaphore
    void *GrBackendSemaphore_new();
    void *GrBackendSemaphore_new_2(const void *semaphore);
    void GrBackendSemaphore_delete(void *backend_semaphore);
    bool GrBackendSemaphore_isInitialized(void *backend_semaphore);
    unsigned int GrBackendSemaphore_backend(void *backend_semaphore);
    // ## gr_backend_texture
    void *GrBackendTexture_new();
    void *GrBackendTexture_new_2(int width, int height, bool midmapped, const void *mockInfo, int label);
    void *GrBackendTexture_new_3(const void *that);
    void GrBackendTexture_delete(void *backend_texture);
    int GrBackendTexture_dimensions(void *backend_texture);
    int GrBackendTexture_width(void *backend_texture);
    int GrBackendTexture_height(void *backend_texture);
    int GrBackendTexture_getLabel(void *backend_texture);
    bool GrBackendTexture_mipmapped(void *backend_texture);
    bool GrBackendTexture_hasMipmaps(void *backend_texture);
    bool GrBackendTexture_hasMipMaps(void *backend_texture);
    unsigned int GrBackendTexture_backend(void *backend_texture);
    int GrBackendTexture_textureType(void *backend_texture);
    int GrBackendTexture_getBackendFormat(void *backend_texture);
    bool GrBackendTexture_getMockTextureInfo(void *backend_texture, void *info);
    void GrBackendTexture_setMutableState(void *backend_texture, const void *state);
    bool GrBackendTexture_isProtected(void *backend_texture);
    bool GrBackendTexture_isValid(void *backend_texture);
    bool GrBackendTexture_isSameTexture(void *backend_texture, const void *texture);
    // ## gr_context_thread_safe_proxy
    void GrContextThreadSafeProxy_delete(void *context_thread_safe_proxy);
    bool GrContextThreadSafeProxy_unique(void *context_thread_safe_proxy);
    void GrContextThreadSafeProxy_ref(void *context_thread_safe_proxy);
    void GrContextThreadSafeProxy_unref(void *context_thread_safe_proxy);
    void GrContextThreadSafeProxy_deref(void *context_thread_safe_proxy);
    bool GrContextThreadSafeProxy_refCntGreaterThan(void *context_thread_safe_proxy, int32_t threadIsolatedTestCnt);
    // ## gr_direct_context
    void GrDirectContext_delete(void *direct_context);
    void GrDirectContext_resetContext(void *direct_context, uint32_t state);
    void GrDirectContext_resetGLTextureBindings(void *direct_context);
    void GrDirectContext_abandonContext(void *direct_context);
    bool GrDirectContext_abandoned(void *direct_context);
    bool GrDirectContext_isDeviceLost(void *direct_context);
    int GrDirectContext_threadSafeProxy(void *direct_context);
    bool GrDirectContext_oomed(void *direct_context);
    void GrDirectContext_releaseResourcesAndAbandonContext(void *direct_context);
    void GrDirectContext_getResourceCacheLimits(void *direct_context, int *maxResources, size_t *maxResourceBytes);
    size_t GrDirectContext_getResourceCacheLimit(void *direct_context);
    void GrDirectContext_getResourceCacheUsage(void *direct_context, int *resourceCount, size_t *resourceBytes);
    size_t GrDirectContext_getResourceCachePurgeableBytes(void *direct_context);
    void GrDirectContext_setResourceCacheLimits(void *direct_context, int maxResources, size_t maxResourceBytes);
    void GrDirectContext_setResourceCacheLimit(void *direct_context, size_t maxResourceBytes);
    void GrDirectContext_freeGpuResources(void *direct_context);
    void GrDirectContext_performDeferredCleanup(void *direct_context, int msNotUsed, int opts);
    void GrDirectContext_purgeResourcesNotUsedInMs(void *direct_context, int msNotUsed);
    void GrDirectContext_purgeUnlockedResources(void *direct_context, size_t bytesToPurge, bool preferScratchResources);
    void GrDirectContext_purgeUnlockedResources_2(void *direct_context, int opts);
    bool GrDirectContext_wait(void *direct_context, int numSemaphores, const void *waitSemaphores, bool deleteSemaphoresAfterWait);
    void GrDirectContext_flushAndSubmit(void *direct_context, bool sync);
    void GrDirectContext_flushAndSubmit_2(void *direct_context, const void *image);
    void GrDirectContext_flushAndSubmit_3(void *direct_context, void *surface, bool sync);
    bool GrDirectContext_flush(void *direct_context, const void *info);
    void GrDirectContext_flush_2(void *direct_context);
    bool GrDirectContext_flush_3(void *direct_context, const void *image, const void *info);
    void GrDirectContext_flush_4(void *direct_context, const void *image);
    bool GrDirectContext_flush_5(void *direct_context, void *surface, int access, const void *info);
    bool GrDirectContext_flush_6(void *direct_context, void *surface, const void *info, const void *newState);
    void GrDirectContext_flush_7(void *direct_context, void *surface);
    bool GrDirectContext_submit(void *direct_context, bool sync);
    void GrDirectContext_checkAsyncWorkCompletion(void *direct_context);
    void GrDirectContext_dumpMemoryStatistics(void *direct_context, void *traceMemoryDump);
    bool GrDirectContext_supportsDistanceFieldText(void *direct_context);
    void GrDirectContext_storeVkPipelineCacheData(void *direct_context);
    int GrDirectContext_createBackendTexture(void *direct_context, int width, int height, const void *format, bool mipmapped, bool renderable, bool isProtected, int label);
    int GrDirectContext_createBackendTexture_2(void *direct_context, int width, int height, int type, bool mipmapped, bool renderable, bool isProtected, int label);
    int GrDirectContext_createBackendTexture_3(void *direct_context, int width, int height, const void *format, const void *color, bool mipmapped, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    int GrDirectContext_createBackendTexture_4(void *direct_context, int width, int height, int type, const void *color, bool mipmapped, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    int GrDirectContext_createBackendTexture_5(void *direct_context, const void *srcData, int numLevels, int textureOrigin, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    int GrDirectContext_createBackendTexture_6(void *direct_context, const void *srcData, int textureOrigin, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    int GrDirectContext_createBackendTexture_7(void *direct_context, const void *srcData, int numLevels, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    int GrDirectContext_createBackendTexture_8(void *direct_context, const void *srcData, bool renderable, bool isProtected, void (*finishedProc)(void *), void * finishedContext, int label);
    bool GrDirectContext_updateBackendTexture(void *direct_context, const void *texture, const void *color, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateBackendTexture_2(void *direct_context, const void *texture, int skColorType, const void *color, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateBackendTexture_3(void *direct_context, const void *texture, const void *srcData, int numLevels, int textureOrigin, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateBackendTexture_4(void *direct_context, const void *texture, const void *srcData, int textureOrigin, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateBackendTexture_5(void *direct_context, const void *texture, const void *srcData, int numLevels, void (*finishedProc)(void *), void * finishedContext);
    int GrDirectContext_createCompressedBackendTexture(void *direct_context, int width, int height, const void *format, const void *color, bool mipmapped, bool isProtected, void (*finishedProc)(void *), void * finishedContext);
    int GrDirectContext_createCompressedBackendTexture_2(void *direct_context, int width, int height, int type, const void *color, bool mipmapped, bool isProtected, void (*finishedProc)(void *), void * finishedContext);
    int GrDirectContext_createCompressedBackendTexture_3(void *direct_context, int width, int height, const void *format, const void *data, size_t dataSize, bool mipmapped, bool isProtected, void (*finishedProc)(void *), void * finishedContext);
    int GrDirectContext_createCompressedBackendTexture_4(void *direct_context, int width, int height, int type, const void *data, size_t dataSize, bool mipmapped, bool isProtected, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateCompressedBackendTexture(void *direct_context, const void *texture, const void *color, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_updateCompressedBackendTexture_2(void *direct_context, const void *texture, const void *data, size_t dataSize, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_setBackendTextureState(void *direct_context, const void *texture, const void *state, void *previousState, void (*finishedProc)(void *), void * finishedContext);
    bool GrDirectContext_setBackendRenderTargetState(void *direct_context, const void *target, const void *state, void *previousState, void (*finishedProc)(void *), void * finishedContext);
    void GrDirectContext_deleteBackendTexture(void *direct_context, const void *texture);
    bool GrDirectContext_precompileShader(void *direct_context, const void *key, const void *data);
    int GrDirectContext_directContextID(void *direct_context);
    int GrDirectContext_maxTextureSize(void *direct_context);
    int GrDirectContext_maxRenderTargetSize(void *direct_context);
    bool GrDirectContext_colorTypeSupportedAsImage(void *direct_context, int colorType);
    bool GrDirectContext_supportsProtectedContent(void *direct_context);
    bool GrDirectContext_colorTypeSupportedAsSurface(void *direct_context, int colorType);
    bool GrDirectContext_colorTypeSupportedAsSurface_2(void *direct_context, int colorType);
    int GrDirectContext_maxSurfaceSampleCountForColorType(void *direct_context, int colorType);
    int GrDirectContext_skCapabilities(void *direct_context);
    int GrDirectContext_MakeMock(const void *mockOptions, const void *contextOptions);
    int GrDirectContext_MakeMock_2(const void *mockOptions);
    // ## gr_driver_bug_workarounds
    void *GrDriverBugWorkarounds_new();
    void *GrDriverBugWorkarounds_new_2(const void *driverBugWorkarounds);
    void *GrDriverBugWorkarounds_new_3(const void *workarounds);
    void GrDriverBugWorkarounds_delete(void *driverBugWorkarounds);
    void applyOverrides(void *driverBugWorkarounds, const void *workarounds);
    // ## gr_recording_context
    void GrRecordingContext_delete(void *recordingContext);
    bool GrRecordingContext_abandoned(void *recordingContext);
    bool GrRecordingContext_colorTypeSupportedAsSurface(void *recordingContext, int colorType);
    int GrRecordingContext_maxTextureSize(void *recordingContext);
    int GrRecordingContext_maxRenderTargetSize(void *recordingContext);
    bool GrRecordingContext_colorTypeSupportedAsImage(void *recordingContext, int colorType);
    bool GrRecordingContext_supportsProtectedContent(void *recordingContext);
    int GrRecordingContext_maxSurfaceSampleCountForColorType(void *recordingContext, int colorType);
    int GrRecordingContext_skCapabilities(void *recordingContext);
    // ## gr_yuva_backend_texture_info
    void *GrYUVABackendTextureInfo_new();
    void *GrYUVABackendTextureInfo_new_2(const void *yuvaInfo, const void *backendFormat, bool mipmapped, int surfaceOrigin);
    void *GrYUVABackendTextureInfo_new_3(const void *yuvaBackendTextureInfo);
    void GrYUVABackendTextureInfo_delete(void *yuvaBackendTextureInfo);
    const void * GrYUVABackendTextureInfo_yuvaInfo(void *yuvaBackendTextureInfo);
    int GrYUVABackendTextureInfo_yuvColorSpace(void *yuvaBackendTextureInfo);
    bool GrYUVABackendTextureInfo_mipmapped(void *yuvaBackendTextureInfo);
    int GrYUVABackendTextureInfo_textureOrigin(void *yuvaBackendTextureInfo);
    int GrYUVABackendTextureInfo_numPlanes(void *yuvaBackendTextureInfo);
    const void * GrYUVABackendTextureInfo_planeFormat(void *yuvaBackendTextureInfo, int i);
    bool GrYUVABackendTextureInfo_isValid(void *yuvaBackendTextureInfo);
    // ## gr_yuva_backend_textures
    void *GrYUVABackendTextures_new();
    void *GrYUVABackendTextures_new_2(const void *yuvaInfo, const void *backendTexture, int textureOrigin);
    void GrYUVABackendTextures_delete(void *yuvaBackendTextures);
    const void * GrYUVABackendTextures_textures(void *yuvaBackendTextures);
    int GrYUVABackendTextures_texture(void *yuvaBackendTextures, int i);
    const void * GrYUVABackendTextures_yuvaInfo(void *yuvaBackendTextures);
    int GrYUVABackendTextures_numPlanes(void *yuvaBackendTextures);
    int GrYUVABackendTextures_textureOrigin(void *yuvaBackendTextures);
    bool GrYUVABackendTextures_isValid(void *yuvaBackendTextures);
    */
    // ## sk_alpha_type
    bool SkAlphaType_SkAlphaTypeIsOpaque(int at);
    // ## sk_android_codec
    void SkAndroidCodec_delete(void *androidCodec);
    const void* SkAndroidCodec_getInfo(void *androidCodec);
    const void* SkAndroidCodec_getICCProfile(void *androidCodec);
    int SkAndroidCodec_getEncodedFormat(void *androidCodec);
    int SkAndroidCodec_computeOutputColorType(void *androidCodec, int requestedColorType);
    int SkAndroidCodec_computeOutputAlphaType(void *androidCodec, bool requestedUnpremul);
    int SkAndroidCodec_computeOutputColorSpace(void *androidCodec, int outputColorType, int prefColorSpace);
    int SkAndroidCodec_computeSampleSize(void *androidCodec, void* size);
    int SkAndroidCodec_getSampledDimensions(void *androidCodec, int sampleSize);
    bool SkAndroidCodec_getSupportedSubset(void *androidCodec, void* desiredSubset);
    int SkAndroidCodec_getSampledSubsetDimensions(void *androidCodec, int sampleSize, const void* subset);
    int SkAndroidCodec_getAndroidPixels(void *androidCodec, const void* info, void* pixels, size_t rowBytes, const void* options);
    int SkAndroidCodec_getAndroidPixels_2(void *androidCodec, const void* info, void* pixels, size_t rowBytes);
    int SkAndroidCodec_getPixels(void *androidCodec, const void* info, void* pixels, size_t rowBytes);
    void* SkAndroidCodec_codec(void *androidCodec);
    bool SkAndroidCodec_getAndroidGainmap(void *androidCodec, void* outInfo, void* outGainmapImageStream);
    int SkAndroidCodec_MakeFromCodec(int codec);
    int SkAndroidCodec_MakeFromStream(int codec, void* pngChunkReader);
    int SkAndroidCodec_MakeFromData(int codec, void* pngChunkReader);
    // ## sk_annotation
    void SkAnnotation_SkAnnotateLinkToDestination(void *canvas, const void *rect, void *data);
    void SkAnnotation_SkAnnotateNamedDestination(void *canvas, const void *point, void *data);
    void SkAnnotation_SkAnnotateRectWithURL(void *canvas, const void *rect, void *data);
    // ## sk_auto_canvas_restore
    void *SkAutoCanvasRestore_new(void * canvas, bool doSave);
    void SkAutoCanvasRestore_delete(void *autoCanvasRestore);
    void SkAutoCanvasRestore_restore(void *autoCanvasRestore);
    // ## sk_avif_decoder
    // ## sk_b_box_hierarchy
    void SkBBoxHierarchy_delete(void *b_box_hierarchy);
    void SkBBoxHierarchy_insert(void *b_box_hierarchy, const void *rect, int N);
    void SkBBoxHierarchy_insert_2(void *b_box_hierarchy, const void *rect, const void *metadata, int N);
    void SkBBoxHierarchy_search(void *b_box_hierarchy, const void *query, void *results);
    size_t SkBBoxHierarchy_bytesUsed(void *b_box_hierarchy);
    bool SkBBoxHierarchy_unique(void *b_box_hierarchy);
    void SkBBoxHierarchy_ref(void *b_box_hierarchy);
    void SkBBoxHierarchy_unref(void *b_box_hierarchy);
    // ## sk_bitmap
    void *SkBitmap_new(void);
    void *SkBitmap_new_2(const void *src);
    void SkBitmap_delete(void *bitmap);
    void SkBitmap_allocN32Pixels(void *bitmap, int width, int height, bool isOpaque);
    void SkBitmap_allocPixels(void *bitmap);
    void SkBitmap_allocPixels_2(void *bitmap, void *allocator);
    void SkBitmap_allocPixels_3(void *bitmap, const void *info);
    void SkBitmap_allocPixels_4(void *bitmap, const void *info, size_t rowBytes);
    void SkBitmap_allocPixelsFlags(void *bitmap, const void *info, uint32_t flags);
    int SkBitmap_alphaType(void *bitmap);
    int SkBitmap_asImage(void *bitmap);
    int SkBitmap_bounds(void *bitmap);
    int SkBitmap_bytesPerPixel(void *bitmap);
    void *SkBitmap_colorSpace(void *bitmap);
    int SkBitmap_colorType(void *bitmap);
    size_t SkBitmap_computeByteSize(void *bitmap);
    int SkBitmap_dimensions(void *bitmap);
    bool SkBitmap_drawsNothing(void *bitmap);
    bool SkBitmap_empty(void *bitmap);
    void SkBitmap_erase(void *bitmap, uint32_t c, const void *area);
    void SkBitmap_erase_2(void *bitmap, int c, const void *area);
    void SkBitmap_eraseArea(void *bitmap, const void *area, uint32_t c);
    void SkBitmap_eraseARGB(void *bitmap, unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    void SkBitmap_eraseColor(void *bitmap, uint32_t c);
    void SkBitmap_eraseColor_2(void *bitmap, int c);
    bool SkBitmap_extractAlpha(void *bitmap, void *dst);
    bool SkBitmap_extractAlpha_2(void *bitmap, void *dst, const void *paint, void *allocator, void *offset);
    bool SkBitmap_extractAlpha_3(void *bitmap, void *dst, const void *paint, void *offset);
    bool SkBitmap_extractSubset(void *bitmap, void *dst, const void *subset);
    void *SkBitmap_getAddr(void *bitmap, int x, int y);
    uint16_t *SkBitmap_getAddr16(void *bitmap, int x, int y);
    uint32_t *SkBitmap_getAddr32(void *bitmap, int x, int y);
    uint8_t *SkBitmap_getAddr8(void *bitmap, int x, int y);
    float SkBitmap_getAlphaf(void *bitmap, int x, int y);
    void SkBitmap_getBounds(void *bitmap, void *bounds);
    void SkBitmap_getBounds2(void *bitmap, void *bounds);
    uint32_t SkBitmap_getColor(void *bitmap, int x, int y);
    int SkBitmap_getColor4f(void *bitmap, int x, int y);
    uint32_t SkBitmap_getGenerationID(void *bitmap);
    void *SkBitmap_getPixels(void *bitmap);
    int SkBitmap_getSubset(void *bitmap);
    int SkBitmap_height(void *bitmap);
    int SkBitmap_info(void *bitmap);
    bool SkBitmap_installMaskPixels(void *bitmap, void *mask);
    bool SkBitmap_installPixels(void *bitmap, const void *info, void *pixels, size_t rowBytes) ;
    bool SkBitmap_installPixels_2(void *bitmap, const void *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *, void *), void *context);
    bool SkBitmap_installPixels_3(void *bitmap, const void *pixmap);
    bool SkBitmap_isImmutable(void *bitmap);
    bool SkBitmap_isNull(void *bitmap);
    bool SkBitmap_isOpaque(void *bitmap);
    int SkBitmap_makeShader(void *bitmap, const void *sampling, const void *lm);
    int SkBitmap_makeShader_2(void *bitmap, const void *sampling, const void *lm);
    int SkBitmap_makeShader_3(void *bitmap, int tmx, int tmy, const void *sampling, const void *localMatrix);
    int SkBitmap_makeShader_4(void *bitmap, int tmx, int tmy, const void *sampling, const void *lm);
    void SkBitmap_notifyPixelsChanged(void *bitmap);
    bool SkBitmap_peekPixels(void *bitmap, void *pixmap);
    void *SkBitmap_pixelRef(void *bitmap);
    int SkBitmap_pixelRefOrigin(void *bitmap);
    int SkBitmap_pixmap(void *bitmap);
    bool SkBitmap_readPixels(void *bitmap, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
    bool SkBitmap_readPixels_2(void *bitmap, const void *dst);
    bool SkBitmap_readPixels_3(void *bitmap, const void *dst, int srcX, int srcY);
    bool SkBitmap_readyToDraw(void *bitmap);
    int SkBitmap_refColorSpace(void *bitmap);
    void SkBitmap_reset(void *bitmap);
    size_t SkBitmap_rowBytes(void *bitmap);
    int SkBitmap_rowBytesAsPixels(void *bitmap);
    bool SkBitmap_setAlphaType(void *bitmap, int alphaType);
    void SkBitmap_setImmutable(void *bitmap);
    bool SkBitmap_setInfo(void *bitmap, const void *imageInfo, size_t rowBytes);
    void SkBitmap_setPixelRef(void *bitmap, int pixelRef, int dx, int dy);
    void SkBitmap_setPixels(void *bitmap, void *pixels);
    int SkBitmap_shiftPerPixel(void *bitmap);
    void SkBitmap_swap(void *bitmap, void *other);
    bool SkBitmap_tryAllocN32Pixels(void *bitmap, int width, int height, bool isOpaque);
    bool SkBitmap_tryAllocPixels(void *bitmap);
    bool SkBitmap_tryAllocPixels_2(void *bitmap, void *allocator);
    bool SkBitmap_tryAllocPixels_3(void *bitmap, const void *info);
    bool SkBitmap_tryAllocPixels_4(void *bitmap, const void *info, size_t rowBytes);
    bool SkBitmap_tryAllocPixelsFlags(void *bitmap, const void *info, uint32_t flags);
    int SkBitmap_width(void *bitmap);
    bool SkBitmap_writePixels(void *bitmap, const void *src);
    bool SkBitmap_writePixels_2(void *bitmap, const void *src, int dstX, int dstY);
    bool SkBitmap_ComputeIsOpaque(const void *bm);
    // ## sk_blend_mode
    bool SkBlendMode_SkBlendMode_AsCoeff(int mode, void *src, void *dst);
    const char *SkBlendMode_SkBlendMode_Name(int blendMode);
    // ## sk_blender
    void SkBlender_delete(void *blender);
    int SkBlender_getFactory(void *blender);
    const char *SkBlender_getTypeName(void *blender);
    void SkBlender_flatten(void *blender, void *write_buffer);
    int SkBlender_getFlattenableType(void *blender);
    int SkBlender_serialize(void *blender, const void *serial_procs);
    size_t SkBlender_serialize_2(void *blender, void *memory, size_t memory_size, const void *serial_procs);
    bool SkBlender_unique(void *blender);
    void SkBlender_ref(void *blender);
    void SkBlender_unref(void *blender);
    int SkBlender_Mode(int mode);
    int SkBlender_NameToFactory(const char name[]);
    const char *SkBlender_FactoryToName(int factory);
    void SkBlender_Register(const char *name, int factory);
    int SkBlender_Deserialize(int type, const void *data, size_t length, const int *procs);
    // ## sk_blenders
    int SkBlenders_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePremul);
    // ## sk_bmp_decoder
    bool SkBmpDecoder_IsBmp(const void* ptr, size_t size);
    int SkBmpDecoder_Decode(int stream, void *result, void *decodeContext);
    int SkBmpDecoder_Decode_2(int stream, void *result, void *decodeContext);
    int SkBmpDecoder_Decoder();
    // ## sk_canvas
    void *SkCanvas_new();
    void *SkCanvas_new_2(int width, int height, const void *props);
    void *SkCanvas_new_3(void *bitmap);
    void *SkCanvas_new_4(const void *bitmap, const void *props);
    void SkCanvas_delete(void *canvas);
    void *SkCanvas_accessTopLayerPixels(void *canvas, void *info, size_t *rowBytes, void *origin);
    void *SkCanvas_accessTopRasterHandle(void *canvas);
    void SkCanvas_androidFramework_setDeviceClipRestriction(void *canvas, const void *rect);
    void SkCanvas_clear(void *canvas, const void *color);
    void SkCanvas_clear_2(void *canvas, uint32_t color);
    void SkCanvas_clipIRect(void *canvas, const void *irect, int op);
    void SkCanvas_clipPath(void *canvas, const void *path, bool doAntiAlias);
    void SkCanvas_clipPath_2(void *canvas, const void *path, int op);
    void SkCanvas_clipPath_3(void *canvas, const void *path, int op, bool doAntiAlias);
    void SkCanvas_clipRect(void *canvas, const void *rect, bool doAntiAlias);
    void SkCanvas_clipRect_2(void *canvas, const void *rect, int op);
    void SkCanvas_clipRect_3(void *canvas, const void *rect, int op, bool doAntiAlias);
    void SkCanvas_clipRegion(void *canvas, const void *deviceRgn, int op);
    void SkCanvas_clipRRect(void *canvas, const void *rrect, bool doAntiAlias);
    void SkCanvas_clipRRect_2(void *canvas, const void *rrect, int op);
    void SkCanvas_clipRRect_3(void *canvas, const void *rrect, int op, bool doAntiAlias);
    void SkCanvas_clipShader(void *canvas, int shader, int op);
    void SkCanvas_concat(void *canvas, const void *m44);
    void SkCanvas_concat_2(void *canvas, const void *matrix);
    void SkCanvas_discard(void *canvas);
    void SkCanvas_drawAnnotation(void *canvas, const void *rect, const char *key, int data);
    void SkCanvas_drawAnnotation_2(void *canvas, const void *rect, const char *key, void *value);
    void SkCanvas_drawArc(void *canvas, const void *oval, float startAngle, float sweepAngle, bool useCenter, const void *paint);
    void SkCanvas_drawAtlas(void *canvas, const void *atlas, const void *xform, const void *tex, const void *colors, int count, int mode, const void *sampling, const void *cullRect, const void *paint);
    void SkCanvas_drawCircle(void *canvas, int center, float radius, const void *paint);
    void SkCanvas_drawCircle_2(void *canvas, float cx, float cy, float radius, const void *paint);
    void SkCanvas_drawColor(void *canvas, const void *color, int mode);
    void SkCanvas_drawColor_2(void *canvas, uint32_t color, int mode);
    void SkCanvas_drawDrawable(void *canvas, void *drawable, const void *matrix);
    void SkCanvas_drawDrawable_2(void *canvas, void *drawable, float x, float y);
    void SkCanvas_drawDRRect(void *canvas, const void *outer, const void *inner, const void *paint);
    void SkCanvas_drawGlyphs(void *canvas, int count, const void *glyphs, const void *positions, const uint32_t *clusters, int textByteCount, const char *utf8text, int origin, const void *font, const void *paint);
    void SkCanvas_drawGlyphs_2(void *canvas, int count, const void *glyphs, const void *positions, int origin, const void *font, const void *paint);
    void SkCanvas_drawGlyphs_3(void *canvas, int count, const void *glyphs, const void *xforms, int origin, const void *font, const void *paint);
    void SkCanvas_drawImage(void *canvas, int image, float left, float top);
    void SkCanvas_drawImage_2(void *canvas, int image, float x, float y, const void *sampling, const void *paint);
    void SkCanvas_drawImage_3(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint);
    void SkCanvas_drawImage_4(void *canvas, const void *image, float left, float top);
    void SkCanvas_drawImageLattice(void *canvas, const void *image, const void *lattice, const void *dst);
    void SkCanvas_drawImageLattice_2(void *canvas, const void *image, const void *lattice, const void *dst, int filter, const void *paint);
    void SkCanvas_drawImageNine(void *canvas, const void *image, const void *center, const void *dst, int filter, const void *paint);
    void SkCanvas_drawImageRect(void *canvas, int image, const void *dst, const void *sampling, const void *paint);
    void SkCanvas_drawImageRect_2(void *canvas, int image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkCanvas_drawImageRect_3(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint);
    void SkCanvas_drawImageRect_4(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkCanvas_drawIRect(void *canvas, const void *rect, const void *paint);
    void SkCanvas_drawLine(void *canvas, int p0, int p1, const void *paint);
    void SkCanvas_drawLine_2(void *canvas, float x0, float y0, float x1, float y1, const void *paint);
    void SkCanvas_drawMesh(void *canvas, const void *mesh, int blender, const void *paint);
    void SkCanvas_drawOval(void *canvas, const void *oval, const void *paint);
    void SkCanvas_drawPaint(void *canvas, const void *paint);
    void SkCanvas_drawPatch(void *canvas, const void *cubics, const void *colors, const void *texCoords, int mode, const void *paint);
    void SkCanvas_drawPath(void *canvas, const void *path, const void *paint);
    void SkCanvas_drawPicture(void *canvas, int picture);
    void SkCanvas_drawPicture_2(void *canvas, int picture, const void *matrix, const void *paint);
    void SkCanvas_drawPicture_3(void *canvas, const void *picture);
    void SkCanvas_drawPicture_4(void *canvas, const void *picture, const void *matrix, const void *paint);
    void SkCanvas_drawPoint(void *canvas, int p, const void *paint);
    void SkCanvas_drawPoint_2(void *canvas, float x, float y, const void *paint);
    void SkCanvas_drawPoints(void *canvas, int mode, size_t count, const void *pts, const void *paint);
    void SkCanvas_drawRect(void *canvas, int rect, const void *paint);
    void SkCanvas_drawRegion(void *canvas, const void *region, const void *paint);
    void SkCanvas_drawRoundRect(void *canvas, const void *rect, float rx, float ry, const void *paint);
    void SkCanvas_drawRRect(void *canvas, const void *rrect, const void *paint);
    void SkCanvas_drawSimpleText(void *canvas, const void *text, size_t byteLength, int encoding, float x, float y, const void *font, const void *paint);
    void SkCanvas_drawString(void *canvas, const char *str, float x, float y, const void *font, const void *paint);
    void SkCanvas_drawString_2(void *canvas, const void *str, float x, float y, const void *font, const void *paint);
    void SkCanvas_drawTextBlob(void *canvas, int text_blob, float x, float y, const void *paint);
    void SkCanvas_drawTextBlob_2(void *canvas, const void *blob, float x, float y, const void *paint);
    void SkCanvas_drawVertices(void *canvas, int vertices, int mode, const void *paint);
    void SkCanvas_drawVertices_2(void *canvas, const void *vertices, int mode, const void *paint);
    void SkCanvas_experimental_DrawEdgeAAImageSet(void *canvas, const void *imageSet, int cnt, const void *dstClips, const void *preViewMatrices, const void *sampling, const void *paint, int constraint);
    void SkCanvas_experimental_DrawEdgeAAQuad(void *canvas, const void *rect, const void *clip, unsigned int aaFlags, const void *color, int mode);
    void SkCanvas_experimental_DrawEdgeAAQuad_2(void *canvas, const void *rect, const void *clip, unsigned int aaFlags, uint32_t color, int mode);
    int SkCanvas_getBaseLayerSize(void *canvas);
    int SkCanvas_getBaseProps(void *canvas);
    int SkCanvas_getDeviceClipBounds(void *canvas);
    bool SkCanvas_getDeviceClipBounds_2(void *canvas, void *bounds);
    int SkCanvas_getLocalClipBounds(void *canvas);
    bool SkCanvas_getLocalClipBounds_2(void *canvas, void *bounds);
    int SkCanvas_getLocalToDevice(void *canvas);
    int SkCanvas_getLocalToDeviceAs3x3(void *canvas);
    bool SkCanvas_getProps(void *canvas, void *props);
    int SkCanvas_getSaveCount(void *canvas);
    void *SkCanvas_getSurface(void *canvas);
    int SkCanvas_getTopProps(void *canvas);
    int SkCanvas_getTotalMatrix(void *canvas);
    int SkCanvas_imageInfo(void *canvas);
    bool SkCanvas_isClipEmpty(void *canvas);
    bool SkCanvas_isClipRect(void *canvas);
    int SkCanvas_makeSurface(void *canvas, const void *info, const void *props);
    bool SkCanvas_peekPixels(void *canvas, void *pixmap);
    void SkCanvas_private_draw_shadow_rec(void *canvas, const void *path, const void *rec);
    bool SkCanvas_quickReject(void *canvas, const void *path);
    bool SkCanvas_quickReject_2(void *canvas, const void *rect);
    bool SkCanvas_readPixels(void *canvas, const void *bitmap, int srcX, int srcY);
    bool SkCanvas_readPixels_2(void *canvas, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
    bool SkCanvas_readPixels_3(void *canvas, const void *pixmap, int srcX, int srcY);
    void *SkCanvas_recorder(void *canvas);
    void *SkCanvas_recordingContext(void *canvas);
    void SkCanvas_resetMatrix(void *canvas);
    void SkCanvas_restore(void *canvas);
    void SkCanvas_restoreToCount(void *canvas, int saveCount);
    void SkCanvas_rotate(void *canvas, float degrees);
    void SkCanvas_rotate_2(void *canvas, float degrees, float px, float py);
    int SkCanvas_save(void *canvas);
    int SkCanvas_saveLayer(void *canvas, const void *layerRec);
    int SkCanvas_saveLayer_2(void *canvas, const void *bounds, const void *paint);
    int SkCanvas_saveLayer_3(void *canvas, const void *bounds, const void *paint);
    int SkCanvas_saveLayerAlpha(void *canvas, const void *bounds, void alpha);
    int SkCanvas_saveLayerAlphaf(void *canvas, const void *bounds, float alpha);
    void SkCanvas_scale(void *canvas, float sx, float sy);
    void SkCanvas_setMatrix(void *canvas, const void *matrix);
    void SkCanvas_setMatrix_2(void *canvas, const void *matrix);
    void SkCanvas_skew(void *canvas, float sx, float sy);
    void SkCanvas_temporary_internal_getRgnClip(void *canvas, void *region);
    void SkCanvas_translate(void *canvas, float dx, float dy);
    bool SkCanvas_writePixels(void *canvas, const void *bitmap, int x, int y);
    bool SkCanvas_writePixels_2(void *canvas, const void *info, const void *pixels, size_t rowBytes, int x, int y);
    int SkCanvas_MakeRasterDirect(const void *info, void *pixels, size_t rowBytes, const void *props);
    int SkCanvas_MakeRasterDirectN32(int width, int height, void *pixels, size_t rowBytes);
    // ## sk_capabilities
    void SkCapabilities_delete(void *capabilities);
    void SkCapabilities_ref(void *capabilities);
    int SkCapabilities_skslVersion(void *capabilities);
    bool SkCapabilities_unique(void *capabilities);
    void SkCapabilities_unref(void *capabilities);
    int SkCapabilities_RasterBackend();
    // ## sk_codec
    void SkCodec_delete(void* codec);
    int SkCodec_getInfo(void* codec);
    int SkCodec_dimensions(void* codec);
    int SkCodec_bounds(void* codec);
    const void* SkCodec_getICCProfile(void* codec);
    int SkCodec_getOrigin(void* codec);
    int SkCodec_getScaledDimensions(void* codec, float desiredScale);
    bool SkCodec_getValidSubset(void* codec, void* desiredSubset);
    int SkCodec_getEncodedFormat(void* codec);
    int SkCodec_getPixels(void* codec, const void* info, void* pixels, size_t rowBytes, const void* options);
    int SkCodec_getPixels_2(void* codec, const void* info, void* pixels, size_t rowBytes);
    int SkCodec_getPixels_3(void* codec, const void* pm, const void* opts);
    int SkCodec_getImage(void* codec, const void* info, const void* opts);
    int SkCodec_getImage_2(void* codec);
    bool SkCodec_queryYUVAInfo(void* codec, const void* supportedDataTypes, void* yuvaPixmapInfo);
    int SkCodec_getYUVAPlanes(void* codec, const void* yuvaPixmaps);
    int SkCodec_startIncrementalDecode(void* codec, const void* dstInfo, void* dst, size_t rowBytes, const void* options);
    int SkCodec_startIncrementalDecode_2(void* codec, const void* dstInfo, void* dst, size_t rowBytes);
    int SkCodec_incrementalDecode(void* codec, int* rowsDecoded);
    int SkCodec_startScanlineDecode(void* codec, const void* dstInfo, const void* options);
    int SkCodec_startScanlineDecode_2(void* codec, const void* dstInfo);
    int SkCodec_getScanlines(void* codec, void* dst, int countLines, size_t rowBytes);
    bool SkCodec_skipScanlines(void* codec, int countLines);
    int SkCodec_getScanlineOrder(void* codec);
    int SkCodec_nextScanline(void* codec);
    int SkCodec_outputScanline(void* codec, int inputScanline);
    int SkCodec_getFrameCount(void* codec);
    bool SkCodec_getFrameInfo(void* codec, int index, void* info);
    int SkCodec_getFrameInfo_2(void* codec);
    int SkCodec_getRepetitionCount(void* codec);
    size_t SkCodec_MinBufferedBytesNeeded();
    const char* SkCodec_ResultToString(int result);
    int SkCodec_MakeFromStream(int stream, void* result, void* pngChunkReader, int selectionPolicy);
    int SkCodec_MakeFromData(int stream, void* pngChunkReader);
    // ## sk_codecs
    // ## sk_color
    uint32_t SkColor_SkColorSetA(uint32_t c, unsigned int a);
    uint32_t SkColor_SkColorSetARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    void SkColor_SkColorToHSV(uint32_t color, float *hsv);
    uint32_t SkColor_SkHSVToColor(const float *hsv);
    uint32_t SkColor_SkHSVToColor_2(unsigned int alpha, const float *hsv);
    uint32_t SkColor_SkPreMultiplyARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    uint32_t SkColor_SkPreMultiplyColor(uint32_t c);
    void SkColor_SkRGBToHSV(unsigned int red, unsigned int green, unsigned int blue, float *hsv);
    // ## sk_color_filter
    void SkColorFilter_delete(void *color_filter);
    bool SkColorFilter_asAColorMode(void *color_filter, void *color, void *mode);
    bool SkColorFilter_asAColorMatrix(void *color_filter, float *matrix);
    bool SkColorFilter_isAlphaUnchanged(void *color_filter);
    uint32_t SkColorFilter_filterColor(void *color_filter, uint32_t color);
    int SkColorFilter_filterColor4f(void *color_filter, const void *srcColor, void *srcCS, void *dstCS);
    int SkColorFilter_makeComposed(void *color_filter, int inner);
    int SkColorFilter_makeWithWorkingColorSpace(void *color_filter, int colorSpace);
    int SkColorFilter_getFactory(void *color_filter);
    const char *SkColorFilter_getTypeName(void *color_filter);
    void SkColorFilter_flatten(void *color_filter, void *write_buffer);
    int SkColorFilter_getFlattenableType(void *color_filter);
    int SkColorFilter_serialize(void *color_filter, const void *serial_procs);
    size_t SkColorFilter_serialize_2(void *color_filter, void *memory, size_t memory_size, const void *serial_procs);
    bool SkColorFilter_unique(void *color_filter);
    void SkColorFilter_ref(void *color_filter);
    void SkColorFilter_unref(void *color_filter);
    int SkColorFilter_Deserialize(const void *data, size_t size, const void *procs);
    int SkColorFilter_NameToFactory(const char *name);
    const char *SkColorFilter_FactoryToName(int factory);
    void SkColorFilter_Register(const char *name, int factory);
    // ## sk_color_filters
    void SkColorFilters_delete(void *colorFilters);
    int SkColorFilters_Blend(const void *c, int color_space, int mode);
    int SkColorFilters_Blend_2(uint32_t c, int mode);
    int SkColorFilters_Compose(int color_filter1, int color_filter2);
    int SkColorFilters_HSLAMatrix(const float *rowMajor);
    int SkColorFilters_HSLAMatrix_2(const void *matrix);
    int SkColorFilters_Lerp(float t, int color_filter1, int color_filter2);
    int SkColorFilters_Lighting(uint32_t mul, uint32_t add);
    int SkColorFilters_LinearToSRGBGamma();
    int SkColorFilters_Matrix(const float *rowMajor);
    int SkColorFilters_Matrix_2(const void *matrix);
    int SkColorFilters_SRGBToLinearGamma();
    int SkColorFilters_Table(const uint8_t *table);
    int SkColorFilters_Table_2(int color_table);
    int SkColorFilters_TableARGB(const uint8_t *tableA, const uint8_t *tableR, const uint8_t *tableG, const uint8_t *tableB);
    // ## sk_color_info
    void *SkColorInfo_new();
    void *SkColorInfo_new_2(int ct, int at, int color_space);
    void *SkColorInfo_new_3(const void *color_info);
    void SkColorInfo_delete(void *color_info);
    int SkColorInfo_alphaType(void *color_info);
    int SkColorInfo_bytesPerPixel(void *color_info);
    void* SkColorInfo_colorSpace(void *color_info);
    int SkColorInfo_colorType(void *color_info);
    bool SkColorInfo_gammaCloseToSRGB(void *color_info);
    bool SkColorInfo_isOpaque(void *color_info);
    int SkColorInfo_makeAlphaType(void *color_info, int newAlphaType);
    int SkColorInfo_makeColorSpace(void *color_info, int color_space);
    int SkColorInfo_makeColorType(void *color_info, int newColorType);
    int SkColorInfo_refColorSpace(void *color_info);
    int SkColorInfo_shiftPerPixel(void *color_info);
    // ## sk_color_matrix
    void *SkColorMatrix_new();
    void *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34);
    void SkColorMatrix_delete(void *color_matrix);
    void SkColorMatrix_setIdentity(void *color_matrix);
    void SkColorMatrix_setScale(void *color_matrix, float rScale, float gScale, float bScale, float aScale);
    void SkColorMatrix_postTranslate(void *color_matrix, float dr, float dg, float db, float da);
    void SkColorMatrix_setConcat(void *color_matrix, const void *a, const void *b);
    void SkColorMatrix_preConcat(void *color_matrix, const void *mat);
    void SkColorMatrix_postConcat(void *color_matrix, const void *mat);
    void SkColorMatrix_setSaturation(void *color_matrix, float sat);
    void SkColorMatrix_setRowMajor(void *color_matrix, const float *src);
    void SkColorMatrix_getRowMajor(void *color_matrix, float *dst);
    int SkColorMatrix_RGBtoYUV(int color_space);
    int SkColorMatrix_YUVtoRGB(int color_space);
    // ## sk_color_matrix_filter
    void SkColorMatrixFilter_delete(void *color_matrix_filter);
    bool SkColorMatrixFilter_asAColorMode(void *color_matrix_filter, void *color, void *mode);
    bool SkColorMatrixFilter_asAColorMatrix(void *color_matrix_filter, float *matrix);
    bool SkColorMatrixFilter_isAlphaUnchanged(void *color_matrix_filter);
    uint32_t SkColorMatrixFilter_filterColor(void *color_matrix_filter, uint32_t color);
    int SkColorMatrixFilter_filterColor4f(void *color_matrix_filter, const void *srcColor, void *srcCS, void *dstCS);
    int SkColorMatrixFilter_makeComposed(void *color_matrix_filter, int colorFilter);
    int SkColorMatrixFilter_makeWithWorkingColorSpace(void *color_matrix_filter, int colorSpace);
    int SkColorMatrixFilter_getFactory(void *color_matrix_filter);
    const char * SkColorMatrixFilter_getTypeName(void *color_matrix_filter);
    void SkColorMatrixFilter_flatten(void *color_matrix_filter, void * write_buffer);
    int SkColorMatrixFilter_getFlattenableType(void *color_matrix_filter);
    int SkColorMatrixFilter_serialize(void *color_matrix_filter, const void *serial_procs);
    size_t SkColorMatrixFilter_serialize_2(void *color_matrix_filter, void *memory, size_t memory_size, const void *serial_procs);
    bool SkColorMatrixFilter_unique(void *color_matrix_filter);
    void SkColorMatrixFilter_ref(void *color_matrix_filter);
    void SkColorMatrixFilter_unref(void *color_matrix_filter);
    int SkColorMatrixFilter_MakeLightingFilter(uint32_t mul, uint32_t add);
    int SkColorMatrixFilter_Deserialize(const void *data, size_t size, const void *procs);
    int SkColorMatrixFilter_NameToFactory(const char *name);
    const char * SkColorMatrixFilter_FactoryToName(int factory);
    void SkColorMatrixFilter_Register(const char *name, int factory);
    // ## sk_color_priv
    unsigned SkColorPriv_SkAlpha255To256(unsigned int alpha);
    uint32_t SkColorPriv_SkAlphaMulQ(uint32_t c, unsigned scale);
    uint32_t SkColorPriv_SkPackARGB32(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    uint32_t SkColorPriv_SkPackARGB32NoCheck(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    uint32_t SkColorPriv_SkPMSrcOver(uint32_t src, uint32_t dst);
    uint32_t SkColorPriv_SkPremultiplyARGBInline(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    unsigned int SkColorPriv_SkUnitScalarClampToByte(float x);
    // ## sk_color_space
    void SkColorSpace_delete(void *color_space);
    void SkColorSpace_toProfile(void *color_space, void *profile);
    bool SkColorSpace_gammaCloseToSRGB(void *color_space);
    bool SkColorSpace_gammaIsLinear(void *color_space);
    bool SkColorSpace_isNumericalTransferFn(void *color_space, void *fn);
    bool SkColorSpace_toXYZD50(void *color_space, void *toXYZD50);
    uint32_t SkColorSpace_toXYZD50Hash(void *color_space);
    int SkColorSpace_makeLinearGamma(void *color_space);
    int SkColorSpace_makeSRGBGamma(void *color_space);
    int SkColorSpace_makeColorSpin(void *color_space);
    bool SkColorSpace_isSRGB(void *color_space);
    int SkColorSpace_serialize(void *color_space);
    size_t SkColorSpace_writeToMemory(void *color_space, void *memory);
    void SkColorSpace_transferFn(void *color_space, float *gabcdef);
    void SkColorSpace_transferFn_2(void *color_space, void *fn);
    void SkColorSpace_invTransferFn(void *color_space, void *fn);
    void SkColorSpace_gamutTransformTo(void *color_space, const void *dst, void *src_to_dst);
    uint32_t SkColorSpace_transferFnHash(void *color_space);
    uint64_t SkColorSpace_hash(void *color_space);
    bool SkColorSpace_unique(void *color_space);
    void SkColorSpace_ref(void *color_space);
    void SkColorSpace_unref(void *color_space);
    void SkColorSpace_deref(void *color_space);
    bool SkColorSpace_refCntGreaterThan(void *color_space, int32_t threadIsolatedTestCnt);
    int SkColorSpace_MakeSRGB();
    int SkColorSpace_MakeSRGBLinear();
    int SkColorSpace_MakeRGB(const void *transferFn, const void *toXYZ);
    int SkColorSpace_Make(const void * profile);
    int SkColorSpace_Deserialize(const void *data, size_t length);
    bool SkColorSpace_Equals(void *color_space_1, const void *color_space_2);
    // ## sk_color_space_primaries
    void SkColorSpacePrimaries_delete(void *color_pace_primaries);
    void SkColorSpacePrimaries_toXYZD50(void *color_pace_primaries, void *toXYZD50);
    // ## sk_color_table
    void SkColorTable_delete(void *color_table);
    const uint8_t * SkColorTable_alphaTable(void *color_table);
    const uint8_t * SkColorTable_redTable(void *color_table);
    const uint8_t * SkColorTable_greenTable(void *color_table);
    const uint8_t * SkColorTable_blueTable(void *color_table);
    void SkColorTable_flatten(void *color_table, void *buffer);
    bool SkColorTable_unique(void *color_table);
    void SkColorTable_ref(void *color_table);
    void SkColorTable_unref(void *color_table);
    int SkColorTable_Make(const uint8_t *table);
    int SkColorTable_Make_2(const uint8_t *tableA, const uint8_t *tableR, const uint8_t *tableG, const uint8_t *tableB);
    int SkColorTable_Deserialize(void *buffer);
    // ## sk_contour_measure
    void SkContourMeasure_delete(void *contour_measure);
    float SkContourMeasure_length(void *contour_measure);
    bool SkContourMeasure_getPosTan(void *contour_measure, float distance, void *position, void *tangent);
    bool SkContourMeasure_getMatrix(void *contour_measure, float distance, void *matrix, int flags);
    bool SkContourMeasure_getSegment(void *contour_measure, float startD, float stopD, void *dst, bool startWithMoveTo);
    bool SkContourMeasure_isClosed(void *contour_measure);
    bool SkContourMeasure_unique(void *contour_measure);
    void SkContourMeasure_ref(void *contour_measure);
    void SkContourMeasure_unref(void *contour_measure);
    // ## sk_contour_measure_iter
    void *SkContourMeasureIter_new();
    void *SkContourMeasureIter_new_2(const void *path, bool forceClosed, float resScale);
    void SkContourMeasureIter_delete(void *contour_measure_iter);
    void SkContourMeasureIter_reset(void *contour_measure_iter, const void *path, bool forceClosed, float resScale);
    int SkContourMeasureIter_next(void *contour_measure_iter);
    // ## sk_corner_path_effect
    void SkCornerPathEffect_delete(void * cornerPathEffect);
    int SkCornerPathEffect_Make(float radius);
    void SkCornerPathEffect_RegisterFlattenables();
    // ## sk_cubic_map
    void SkCubicMap_delete(void * cubic_map);
    void *SkCubicMap_new(int p1, int p2);
    float SkCubicMap_computeYFromX(void * cubic_map, float x);
    int SkCubicMap_computeFromT(void * cubic_map, float t);
    bool SkCubicMap_IsLinear(int p1, int p2);
    // ## sk_cubic_resampler
    void SkCubicResampler_delete(void *cubicResampler);
    int SkCubicResampler_Mitchell();
    int SkCubicResampler_CatmullRom();
    // ## sk_dash_path_effect
    void SkDashPathEffect_delete(void * dashPathEffect);
    int SkDashPathEffect_Make(const float *intervals, int count, float phase);
    // ## sk_data
    void SkData_delete(void *sk_data);
    size_t SkData_size(void *sk_data);
    bool SkData_isEmpty(void *sk_data);
    const void * SkData_data(void *sk_data);
    const uint8_t * SkData_bytes(void *sk_data);
    void * SkData_writable_data(void *sk_data);
    size_t SkData_copyRange(void *sk_data, size_t offset, size_t length, void *buffer);
    bool SkData_equals(void *sk_data, const void *other);
    bool SkData_unique(void *sk_data);
    void SkData_ref(void *sk_data);
    void SkData_unref(void *sk_data);
    void SkData_deref(void *sk_data);
    bool SkData_refCntGreaterThan(void *sk_data, int32_t threadIsolatedTestCnt);
    int SkData_MakeWithCopy(const void *data, size_t length);
    int SkData_MakeUninitialized(size_t length);
    int SkData_MakeZeroInitialized(size_t length);
    int SkData_MakeWithCString(const char *cstr);
    int SkData_MakeWithProc(const void *ptr, size_t length, void (*proc)(const void *, void *), void *ctx);
    int SkData_MakeWithoutCopy(const void *data, size_t length);
    int SkData_MakeFromMalloc(const void *data, size_t length);
    int SkData_MakeFromFileName(const char *path);
    int SkData_MakeFromFILE(void *f);
    int SkData_MakeFromFD(int fd);
    int SkData_MakeFromStream(void *stream, size_t size);
    int SkData_MakeSubset(const void *src, size_t offset, size_t length);
    int SkData_MakeEmpty();
    // ## sk_data_table
    void SkDataTable_delete(void *data_table);
    bool SkDataTable_isEmpty(void *data_table);
    int SkDataTable_count(void *data_table);
    size_t SkDataTable_atSize(void *data_table, int index);
    const void * SkDataTable_at(void *data_table, int index, size_t *size);
    const char * SkDataTable_atStr(void *data_table, int index);
    bool SkDataTable_unique(void *data_table);
    void SkDataTable_ref(void *data_table);
    void SkDataTable_unref(void *data_table);
    int SkDataTable_MakeEmpty();
    int SkDataTable_MakeCopyArrays(const void *const *ptrs, const size_t *sizes, int count);
    int SkDataTable_MakeCopyArray(const void *array, size_t elemSize, int count);
    int SkDataTable_MakeArrayProc(const void *array, size_t elemSize, int count, void (*proc)(void *), void *context);
    // ## sk_discrete_path_effect
    void SkDiscretePathEffect_delete(void * discretePathEffect);
    int SkDiscretePathEffect_Make(float segLength, float dev, uint32_t seedAssist);
    void SkDiscretePathEffect_RegisterFlattenables();
    // ## sk_document
    void SkDocument_delete(void *document);
    void * SkDocument_beginPage(void * document, float width, float height, const void *content);
    void SkDocument_endPage(void *document);
    void SkDocument_close(void *document);
    void SkDocument_abort(void *document);
    bool SkDocument_unique(void *document);
    void SkDocument_ref(void *document);
    void SkDocument_unref(void *document);
    // ## sk_drawable
    void SkDrawable_delete(void *drawable);
    void SkDrawable_draw(void *drawable, void * canvas, const void * matrix);
    void SkDrawable_draw_2(void *drawable, void *canvas, float x, float y);
    int SkDrawable_snapGpuDrawHandler(void *drawable, unsigned int backendApi, const void *matrix, const void *clipBounds, const void *bufferInfo);
    int SkDrawable_makePictureSnapshot(void *drawable);
    uint32_t SkDrawable_getGenerationID(void *drawable);
    int SkDrawable_getBounds(void *drawable);
    size_t SkDrawable_approximateBytesUsed(void *drawable);
    void SkDrawable_notifyDrawingChanged(void *drawable);
    int SkDrawable_getFlattenableType(void *drawable);
    int SkDrawable_getFactory(void *drawable);
    const char * SkDrawable_getTypeName(void *drawable);
    void SkDrawable_flatten(void *drawable, void *write_buffer);
    int SkDrawable_serialize(void *drawable, const void *serial_procs);
    size_t SkDrawable_serialize_2(void *drawable, void *memory, size_t memory_size, const void *serial_procs);
    bool SkDrawable_unique(void *drawable);
    void SkDrawable_ref(void *drawable);
    void SkDrawable_unref(void *drawable);
    int SkDrawable_GetFlattenableType();
    int SkDrawable_Deserialize(const void *data, size_t size, const void *procs);
    int SkDrawable_NameToFactory(const char name[]);
    const char * SkDrawable_FactoryToName(int factory);
    void SkDrawable_Register(const char name[], int factory);
    // ## sk_dynamic_memory_w_stream
    void *SkDynamicMemoryWStream_new();
    void SkDynamicMemoryWStream_delete(void *dynamic_memory_w_stream);
    bool SkDynamicMemoryWStream_write(void *dynamic_memory_w_stream, const void *buffer, size_t size);
    size_t SkDynamicMemoryWStream_bytesWritten(void *dynamic_memory_w_stream);
    bool SkDynamicMemoryWStream_read(void *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size);
    void SkDynamicMemoryWStream_copyTo(void *dynamic_memory_w_stream, void *dst);
    bool SkDynamicMemoryWStream_writeToStream(void *dynamic_memory_w_stream, void *dst);
    void SkDynamicMemoryWStream_copyToAndReset(void *dynamic_memory_w_stream, void *dst);
    bool SkDynamicMemoryWStream_writeToAndReset(void *dynamic_memory_w_stream, void *dst);
    bool SkDynamicMemoryWStream_writeToAndReset_2(void *dynamic_memory_w_stream, void *dst);
    void SkDynamicMemoryWStream_prependToAndReset(void *dynamic_memory_w_stream, void *dst);
    int SkDynamicMemoryWStream_detachAsData(void *dynamic_memory_w_stream);
    int SkDynamicMemoryWStream_detachAsStream(void *dynamic_memory_w_stream);
    void SkDynamicMemoryWStream_reset(void *dynamic_memory_w_stream);
    void SkDynamicMemoryWStream_padToAlign4(void *dynamic_memory_w_stream);
    void SkDynamicMemoryWStream_flush(void *dynamic_memory_w_stream);
    bool SkDynamicMemoryWStream_write8(void *dynamic_memory_w_stream, unsigned int value);
    bool SkDynamicMemoryWStream_write16(void *dynamic_memory_w_stream, unsigned int value);
    bool SkDynamicMemoryWStream_write32(void *dynamic_memory_w_stream, uint32_t v);
    bool SkDynamicMemoryWStream_writeText(void *dynamic_memory_w_stream, const char text[]);
    bool SkDynamicMemoryWStream_newline(void *dynamic_memory_w_stream);
    bool SkDynamicMemoryWStream_writeDecAsText(void *dynamic_memory_w_stream, int32_t v);
    bool SkDynamicMemoryWStream_writeBigDecAsText(void *dynamic_memory_w_stream, int64_t v, int minDigits);
    bool SkDynamicMemoryWStream_writeHexAsText(void *dynamic_memory_w_stream, uint32_t v, int minDigits);
    bool SkDynamicMemoryWStream_writeScalarAsText(void *dynamic_memory_w_stream, float scalar);
    bool SkDynamicMemoryWStream_writeBool(void *dynamic_memory_w_stream, bool v);
    bool SkDynamicMemoryWStream_writeScalar(void *dynamic_memory_w_stream, float scalar);
    bool SkDynamicMemoryWStream_writePackedUInt(void *dynamic_memory_w_stream, size_t length);
    bool SkDynamicMemoryWStream_writeStream(void *dynamic_memory_w_stream, void *input, size_t length);
    int SkDynamicMemoryWStream_SizeOfPackedUInt(size_t value);
    // ## sk_encoded_origin
    int SkEncodedOrigin_SkEncodedOriginToMatrix(int origin, int w, int h);
    bool SkEncodedOrigin_SkEncodedOriginSwapsWidthHeight(int origin);
    // ## sk_encoder
    void SkEncoder_delete(void *encoder);
    bool SkEncoder_encodeRows(void *encoder, int numRows);
    // ## sk_executor
    void SkExecutor_delete(void *executor);
    void SkExecutor_add(int function_void_void_key_in, void *executor);
    void SkExecutor_borrow(void *executor);
    int SkExecutor_MakeFIFOThreadPool(int threads, bool allowBorrowing);
    int SkExecutor_MakeLIFOThreadPool(int threads, bool allowBorrowing);
    void *SkExecutor_GetDefault();
    void SkExecutor_SetDefault(void * executor);
    // ## sk_file_stream
    void *SkFILEStream_new(const char path[]);
    void *SkFILEStream_new_2(void *file);
    void *SkFILEStream_new_3(void *file, size_t size);
    void SkFILEStream_delete(void *file_stream);
    bool SkFILEStream_isValid(void *file_stream);
    void SkFILEStream_close(void *file_stream);
    size_t SkFILEStream_read(void *file_stream, void *buffer, size_t size);
    bool SkFILEStream_isAtEnd(void *file_stream);
    bool SkFILEStream_rewind(void *file_stream);
    int SkFILEStream_duplicate(void *file_stream);
    size_t SkFILEStream_getPosition(void *file_stream);
    bool SkFILEStream_seek(void *file_stream, size_t position);
    bool SkFILEStream_move(void *file_stream, long offset);
    int SkFILEStream_fork(void *file_stream);
    size_t SkFILEStream_getLength(void *file_stream);
    bool SkFILEStream_hasLength(void *file_stream);
    bool SkFILEStream_hasPosition(void *file_stream);
    size_t SkFILEStream_skip(void *file_stream, size_t size);
    size_t SkFILEStream_peek(void *file_stream, void *ptr, size_t size);
    bool SkFILEStream_readS8(void *file_stream, int8_t *i);
    bool SkFILEStream_readS16(void *file_stream, int16_t *i);
    bool SkFILEStream_readS32(void *file_stream, int32_t *i);
    bool SkFILEStream_readU8(void *file_stream, uint8_t *i);
    bool SkFILEStream_readU16(void *file_stream, uint16_t *i);
    bool SkFILEStream_readU32(void *file_stream, uint32_t *i);
    bool SkFILEStream_readBool(void *file_stream, bool *b);
    bool SkFILEStream_readScalar(void *file_stream, float *scalar);
    bool SkFILEStream_readPackedUInt(void *file_stream, size_t *size);
    const void * SkFILEStream_getMemoryBase(void *file_stream);
    int SkFILEStream_Make(const char path[]);
    // ## sk_file_w_stream
    void *SkFILEWStream_new(const char path[]);
    void SkFILEWStream_delete(void *file_w_stream);
    bool SkFILEWStream_isValid(void *file_w_stream);
    bool SkFILEWStream_write(void *file_w_stream, const void *buffer, size_t size);
    void SkFILEWStream_flush(void *file_w_stream);
    void SkFILEWStream_fsync(void *file_w_stream);
    size_t SkFILEWStream_bytesWritten(void *file_w_stream);
    bool SkFILEWStream_write8(void *file_w_stream, unsigned int value);
    bool SkFILEWStream_write16(void *file_w_stream, unsigned int value);
    bool SkFILEWStream_write32(void *file_w_stream, uint32_t v);
    bool SkFILEWStream_writeText(void *file_w_stream, const char text[]);
    bool SkFILEWStream_newline(void *file_w_stream);
    bool SkFILEWStream_writeDecAsText(void *file_w_stream, int32_t v);
    bool SkFILEWStream_writeBigDecAsText(void *file_w_stream, int64_t v, int minDigits);
    bool SkFILEWStream_writeHexAsText(void *file_w_stream, uint32_t v, int minDigits);
    bool SkFILEWStream_writeScalarAsText(void *file_w_stream, float scalar);
    bool SkFILEWStream_writeBool(void *file_w_stream, bool v);
    bool SkFILEWStream_writeScalar(void *file_w_stream, float scalar);
    bool SkFILEWStream_writePackedUInt(void *file_w_stream, size_t size);
    bool SkFILEWStream_writeStream(void *file_w_stream, void *input, size_t length);
    int SkFILEWStream_SizeOfPackedUInt(size_t value);
    // ## sk_flattenable
    void SkFlattenable_delete(void *flattenable);
    int SkFlattenable_getFactory(void *flattenable);
    const char * SkFlattenable_getTypeName(void *flattenable);
    void SkFlattenable_flatten(void *flattenable, void *write_buffer);
    int SkFlattenable_getFlattenableType(void *flattenable);
    int SkFlattenable_serialize(void *flattenable, const void * serial_procs);
    size_t SkFlattenable_serialize_2(void *flattenable, void *memory, size_t memory_size, const void * serial_procs);
    bool SkFlattenable_unique(void *flattenable);
    void SkFlattenable_ref(void *flattenable);
    void SkFlattenable_unref(void *flattenable);
    int SkFlattenable_NameToFactory(const char name[]);
    const char * SkFlattenable_FactoryToName(int factory);
    void SkFlattenable_Register(const char name[], int factory);
    int SkFlattenable_Deserialize(int type, const void *data, size_t length, const void *procs);
    // ## sk_font
    void *SkFont_new();
    void *SkFont_new_2(int typeface, float size);
    void *SkFont_new_3(int typeface);
    void *SkFont_new_4(int typeface, float size, float scaleX, float skewX);
    void SkFont_delete(void *font);
    bool SkFont_isForceAutoHinting(void *font);
    bool SkFont_isEmbeddedBitmaps(void *font);
    bool SkFont_isSubpixel(void *font);
    bool SkFont_isLinearMetrics(void *font);
    bool SkFont_isEmbolden(void *font);
    bool SkFont_isBaselineSnap(void *font);
    void SkFont_setForceAutoHinting(void *font, bool forceAutoHinting);
    void SkFont_setEmbeddedBitmaps(void *font, bool embeddedBitmaps);
    void SkFont_setSubpixel(void *font, bool subpixel);
    void SkFont_setLinearMetrics(void *font, bool linearMetrics);
    void SkFont_setEmbolden(void *font, bool embolden);
    void SkFont_setBaselineSnap(void *font, bool baselineSnap);
    int SkFont_getEdging(void *font);
    void SkFont_setEdging(void *font, int edging);
    void SkFont_setHinting(void *font, int hintingLevel);
    int SkFont_getHinting(void *font);
    int SkFont_makeWithSize(void *font, float size);
    void * SkFont_getTypeface(void *font);
    float SkFont_getSize(void *font);
    float SkFont_getScaleX(void *font);
    float SkFont_getSkewX(void *font);
    int SkFont_refTypeface(void *font);
    void SkFont_setTypeface(void *font, int typeface);
    void SkFont_setSize(void *font, float textSize);
    void SkFont_setScaleX(void *font, float scaleX);
    void SkFont_setSkewX(void *font, float skewX);
    int SkFont_textToGlyphs(void *font, const void *text, size_t byteLength, int encoding, uint16_t *glyphs, int maxGlyphCount);
    uint16_t SkFont_unicharToGlyph(void *font, int32_t uni);
    void SkFont_unicharsToGlyphs(void *font, const int32_t *uni, int count, uint16_t *glyphs);
    int SkFont_countText(void *font, const void *text, size_t byteLength, int encoding);
    float SkFont_measureText(void *font, const void *text, size_t byteLength, int encoding, void *bounds);
    float SkFont_measureText_2(void *font, const void *text, size_t byteLength, int encoding, void *bounds, const void *paint);
    void SkFont_getWidths(void *font, const uint16_t *glyphs, int count, float *widths, void *bounds);
    void SkFont_getWidths_2(void *font, const uint16_t *glyphs, int count, float *widths, void *ptr);
    void SkFont_getWidths_3(void *font, const uint16_t *glyphs, int count, float *widths);
    void SkFont_getWidthsBounds(void *font, const uint16_t *glyphs, int count, float *widths, void *bounds, const void *paint);
    void SkFont_getBounds(void *font, const uint16_t *glyphs, int count, void *bounds, const void *paint);
    void SkFont_getPos(void *font, const uint16_t *glyphs, int count, void *pos, int origin);
    void SkFont_getXPos(void *font, const uint16_t *glyphs, int count, float *xpos, float origin);
    int SkFont_getIntercepts(void *font, const uint16_t *glyphs, int count, const void *pos, float top, float bottom, const void *paint);
    bool SkFont_getPath(void *font, uint16_t glyphID, void *path);
 //   void SkFont_getPaths(void *font, const uint16_t *glyphIDs, int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx);
    float SkFont_getMetrics(void *font, void *metrics);
    float SkFont_getSpacing(void *font);
    void SkFont_dump(void *font);
    // ## sk_font_arguments
    void *SkFontArguments_new();
    void SkFontArguments_delete(void *font_arguments);
    int SkFontArguments_setCollectionIndex(void *font_argments, int collectionIndex);
    int SkFontArguments_setVariationDesignPosition(void *font_argments, int position);
    int SkFontArguments_getCollectionIndex(void *font_argments);
    int SkFontArguments_getVariationDesignPosition(void *font_argments);
    int SkFontArguments_setPalette(void *font_argments, int palette);
    int SkFontArguments_getPalette(void *font_argments);
    // ## sk_font_metrics
    void SkFontMetrics_delete(void *font_metrics);
    bool SkFontMetrics_hasUnderlineThickness(void *font_metrics, float *thickness);
    bool SkFontMetrics_hasUnderlinePosition(void *font_metrics, float *position);
    bool SkFontMetrics_hasStrikeoutThickness(void *font_metrics, float *thickness);
    bool SkFontMetrics_hasStrikeoutPosition(void *font_metrics, float *position);
    bool SkFontMetrics_hasBounds(void *font_metrics);
    // ## sk_font_mgr
    void SkFontMgr_delete(void *font_mgr);
    int SkFontMgr_countFamilies(void *font_mgr);
    void SkFontMgr_getFamilyName(void *font_mgr, int index, void *familyName);
    void SkFontMgr_createStyleSet(int sk_font_style_set_out, void *font_mgr, int index);
    void SkFontMgr_matchFamily(int sk_font_style_set_out, void *font_mgr, const char *familyName);
    int SkFontMgr_matchFamilyStyle(void *font_mgr, const char *familyName, const void *font_style);
    int SkFontMgr_matchFamilyStyleCharacter(void *font_mgr, const char *familyName, const void *font_style, const char *bcp47[], int bcp47Count, int32_t character);
    int SkFontMgr_makeFromData(void *font_mgr, int data, int ttcIndex);
    int SkFontMgr_makeFromStream(void *font_mgr, int stream_asset, int ttcIndex);
    int SkFontMgr_makeFromStream_2(void *font_mgr, int stream_asset, const void *font_argments);
    int SkFontMgr_makeFromFile(void *font_mgr, const char *path, int ttcIndex);
    int SkFontMgr_legacyMakeTypeface(void *font_mgr, const char *familyName, int style);
    bool SkFontMgr_unique(void *font_mgr);
    void SkFontMgr_ref(void *font_mgr);
    void SkFontMgr_unref(void *font_mgr);
    int SkFontMgr_RefEmpty();
    int SkFontMgr_RefDefault();
    // ## sk_font_mgr_fontconfig
    // ## sk_font_style
    void SkFontStyle_delete(void *font_style);
    int SkFontStyle_weight(void *font_style);
    int SkFontStyle_width(void *font_style);
    int SkFontStyle_slant(void *font_style);
    // ## sk_font_style_set
    void SkFontStyleSet_delete(void *font_style_set);
    int SkFontStyleSet_count(void *font_style_set);
    void SkFontStyleSet_getStyle(void *font_style_set, int index, void * font_style, void *style);
    int SkFontStyleSet_createTypeface(void *font_style_set, int index);
    int SkFontStyleSet_matchStyle(void *font_style_set, const void *pattern);
    bool SkFontStyleSet_unique(void *font_style_set);
    void SkFontStyleSet_ref(void *font_style_set);
    void SkFontStyleSet_unref(void *font_style_set);
    int SkFontStyleSet_CreateEmpty();
    /*
    // ## sk_gif_decoder
    bool SkGifDecoder_IsGif(const void* ptr, size_t size);
    int SkGifDecoder_Decode(int static_stream, void* result, void *decodeContext);
    int SkGifDecoder_Decode_2(int static_data, void* result, void *decodeContext);
    int SkGifDecoder_Decoder();
    */
    // ## sk_gradient_shader
    void SkGradientShader_delete(void * gradientShader);
    int SkGradientShader_MakeLinear(const void *pts, const void *colors, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeLinear_2(const void *pts, const void *colors, int color_space, const float *pos, int count, int mode, const void *interpolation, const void *localMatrix);
    int SkGradientShader_MakeLinear_3(const void *pts, const void *colors, int color_space, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeRadial(const void *center, float radius, const void *colors, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeRadial_2(const void *center, float radius, const void *colors, int color_space, const float *pos, int count, int mode, const void *interpolation, const void *localMatrix);
    int SkGradientShader_MakeRadial_3(const void *center, float radius, const void *colors, int color_space, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeTwoPointConical(const void *start, float startRadius, const void *end, float endRadius, const void *colors, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeTwoPointConical_2(const void *start, float startRadius, const void *end, float endRadius, const void *colors, int color_space, const float *pos, int count, int mode, const void *interpolation, const void *localMatrix);
    int SkGradientShader_MakeTwoPointConical_3(const void *start, float startRadius, const void *end, float endRadius, const void *colors, int color_space, const float *pos, int count, int mode, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeSweep(float cx, float cy, const void *colors, const float *pos, int count, int mode, float startAngle, float endAngle, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeSweep_2(float cx, float cy, const void *colors, const float *pos, int count, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeSweep_3(float cx, float cy, const void *colors, int color_space, const float *pos, int count, int mode, float startAngle, float endAngle, const void *interpolation, const void *localMatrix);
    int SkGradientShader_MakeSweep_4(float cx, float cy, const void *colors, int color_space, const float *pos, int count, int mode, float startAngle, float endAngle, uint32_t flags, const void *localMatrix);
    int SkGradientShader_MakeSweep_5(float cx, float cy, const void *colors, int color_space, const float *pos, int count, uint32_t flags, const void *localMatrix);
    // ## sk_graphics
    void SkGraphics_delete(void * graphics);
    void SkGraphics_Init();
    size_t SkGraphics_GetFontCacheLimit();
    size_t SkGraphics_SetFontCacheLimit(size_t bytes);
    size_t SkGraphics_GetFontCacheUsed();
    int SkGraphics_GetFontCacheCountUsed();
    int SkGraphics_GetFontCacheCountLimit();
    int SkGraphics_SetFontCacheCountLimit(int count);
    void SkGraphics_PurgeFontCache();
    void SkGraphics_PurgePinnedFontCache();
    size_t SkGraphics_GetResourceCacheTotalBytesUsed();
    size_t SkGraphics_GetResourceCacheTotalByteLimit();
    size_t SkGraphics_SetResourceCacheTotalByteLimit(size_t newLimit);
    void SkGraphics_PurgeResourceCache();
    size_t SkGraphics_GetResourceCacheSingleAllocationByteLimit();
    size_t SkGraphics_SetResourceCacheSingleAllocationByteLimit(size_t newLimit);
    void SkGraphics_DumpMemoryStatistics(void *dump);
    void SkGraphics_PurgeAllCaches();
    //SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory);
    //SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory);
    //SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory();
    // ## sk_high_contrast_config
    void *SkHighContrastConfig_new();
    void *SkHighContrastConfig_new_2(bool grayscale, int invertStyle, float contrast);
    void SkHighContrastConfig_delete(void * highContrastConfig);
    bool isValid(void *high_contrast_config);
    // ## sk_high_contrast_filter
    void SkHighContrastFilter_delete(void * highContrastFilter);
    int SkHighContrastFilter_Make(const void * config);
    // ## sk_i_rect
    void SkIRect_delete(void *i_rect);
    int32_t SkIRect_left(void *i_rect);
    int32_t SkIRect_top(void *i_rect);
    int32_t SkIRect_right(void *i_rect);
    int32_t SkIRect_bottom(void *i_rect);
    int32_t SkIRect_x(void *i_rect);
    int32_t SkIRect_y(void *i_rect);
    int SkIRect_topLeft(void *i_rect);
    int32_t SkIRect_width(void *i_rect);
    int32_t SkIRect_height(void *i_rect);
    int SkIRect_size(void *i_rect);
    int64_t SkIRect_width64(void *i_rect);
    int64_t SkIRect_height64(void *i_rect);
    bool SkIRect_isEmpty64(void *i_rect);
    bool SkIRect_isEmpty(void *i_rect);
    void SkIRect_setEmpty(void *i_rect);
    void SkIRect_setLTRB(void *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom);
    void SkIRect_setXYWH(void *i_rect, int32_t x, int32_t y, int32_t width, int32_t height);
    void SkIRect_setWH(void *i_rect, int32_t width, int32_t height);
    void SkIRect_setSize(void *i_rect, int size);
    int SkIRect_makeOffset(void *i_rect, int32_t dx, int32_t dy);
    int SkIRect_makeOffset_2(void *i_rect, int offset);
    int SkIRect_makeInset(void *i_rect, int32_t dx, int32_t dy);
    int SkIRect_makeOutset(void *i_rect, int32_t dx, int32_t dy);
    void SkIRect_offset(void *i_rect, int32_t dx, int32_t dy);
    void SkIRect_offset_2(void *i_rect, const void *delta);
    void SkIRect_offsetTo(void *i_rect, int32_t newX, int32_t newY);
    void SkIRect_inset(void *i_rect, int32_t dx, int32_t dy);
    void SkIRect_outset(void *i_rect, int32_t dx, int32_t dy);
    void SkIRect_adjust(void *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB);
    bool SkIRect_contains(void *i_rect, int32_t x, int32_t y);
    bool SkIRect_contains_2(void *i_rect, const void *r);
    bool SkIRect_contains_3(void *i_rect, const void *r);
    bool SkIRect_containsNoEmptyCheck(void *i_rect, const void *r);
    bool SkIRect_intersect(void *i_rect, const void *r);
    bool SkIRect_intersect_2(void *i_rect, const void *a, const void *b);
    void SkIRect_join(void *i_rect, const void *r);
    void SkIRect_sort(void *i_rect);
    int SkIRect_makeSorted(void *i_rect);
    int SkIRect_MakeEmpty();
    int SkIRect_MakeWH(int32_t w, int32_t h);
    int SkIRect_MakeSize(const void *size);
    int SkIRect_MakePtSize(int pt, int size);
    int SkIRect_MakeLTRB(int32_t l, int32_t t, int32_t r, int32_t b);
    int SkIRect_MakeXYWH(int32_t x, int32_t y, int32_t w, int32_t h);
    bool SkIRect_Intersects(const void *a, const void *b);
    // ## sk_i_size
    void SkISize_delete(void *i_size);
    void SkISize_set(void *i_size, int32_t w, int32_t h) ;
    bool SkISize_isZero(void *i_size);
    bool SkISize_isEmpty(void *i_size);
    void SkISize_setEmpty(void *i_size);
    int32_t SkISize_width(void *i_size);
    int32_t SkISize_height(void *i_size);
    int64_t SkISize_area(void *i_size);
    bool SkISize_equals(void *i_size, int32_t w, int32_t h);
    int SkISize_Make(int32_t w, int32_t h);
    int SkISize_MakeEmpty();
    // ## sk_icc
    int SkICC_SkWriteICCProfile(const void* transferFunction, const void* toXYZD50);
    int SkICC_SkWriteICCProfile_2(const void* iccProfile, const char* description);
    void SkICC_SkICCFloatXYZD50ToGrid16Lab(const float* float_xyz, uint8_t* grid16_lab);
    void SkICC_SkICCFloatToTable16(const float f, uint8_t* table_16);
    // ## sk_ico_cecoder
    bool SkIcoDecoder_IsIco(const void* ptr, size_t size);
    int SkIcoDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkIcoDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkIcoDecoder_Decoder();
    // ## sk_image
    void SkImage_delete(void *image);
    const void * SkImage_imageInfo(void *image);
    int SkImage_width(void *image);
    int SkImage_height(void *image);
    int SkImage_dimensions(void *image);
    int SkImage_bounds(void *image);
    uint32_t SkImage_uniqueID(void *image);
    int SkImage_alphaType(void *image);
    int SkImage_colorType(void *image);
    void * SkImage_colorSpace(void *image);
    int SkImage_refColorSpace(void *image);
    bool SkImage_isAlphaOnly(void *image);
    bool SkImage_isOpaque(void *image);
    int SkImage_makeShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix);
    int SkImage_makeShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm);
    int SkImage_makeShader_3(void *image, const void *sampling, const void *lm);
    int SkImage_makeShader_4(void *image, const void *sampling, const void *lm);
    int SkImage_makeRawShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix);
    int SkImage_makeRawShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm);
    int SkImage_makeRawShader_3(void *image, const void *sampling, const void *lm);
    int SkImage_makeRawShader_4(void *image, const void *sampling, const void *lm);
    bool SkImage_peekPixels(void *image, void *pixmap);
    bool SkImage_isTextureBacked(void *image);
    size_t SkImage_textureSize(void *image);
    bool SkImage_isValid(void *image, void *context);
    bool SkImage_readPixels(void *image, void *context, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, int cachingHint);
    bool SkImage_readPixels_2(void *image, void *context, const void *dst, int srcX, int srcY, int cachingHint);
    bool SkImage_readPixels_3(void *image, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, int cachingHint);
    bool SkImage_readPixels_4(void *image, const void *dst, int srcX, int srcY, int cachingHint);
//    void SkImage_asyncRescaleAndReadPixels(void *image, const void *info, const void *srcRect, bool rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void *context);
//    void SkImage_asyncRescaleAndReadPixelsYUV420(void *image, int yuvColorSpace, int color_space, const void *srcRect, const void *dstSize, bool rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void *context);
//    void SkImage_asyncRescaleAndReadPixelsYUVA420(void *image, int yuvColorSpace, int color_space, const void *srcRect, const void *dstSize, bool rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void *context);
    bool SkImage_scalePixels(void *image, const void *dst, const void *sampling, int cachingHint);
    int SkImage_refEncodedData(void *image);
    int SkImage_makeSubset(void *image, void *direct, const void *subset);
    int SkImage_makeSubset_2(void *image, void *recorder, const void *subset, int properties);
    bool SkImage_hasMipmaps(void *image);
    bool SkImage_isProtected(void *image);
    int SkImage_withDefaultMipmaps(void *image);
    int SkImage_makeNonTextureImage(void *image, void *context);
    int SkImage_makeRasterImage(void *image, void *context, int cachingHint);
    int SkImage_makeRasterImage_2(void *image, int cachingHint);
    bool SkImage_asLegacyBitmap(void *image, void *bitmap, int legacyBitmapMode);
    bool SkImage_isLazyGenerated(void *image);
    int SkImage_makeColorSpace(void *image, void *direct, int color_space);
    int SkImage_makeColorSpace_2(void *image, void *recorder, int color_space, int properties);
    int SkImage_makeColorTypeAndColorSpace(void *image, void *direct, int targetColorType, int color_space);
    int SkImage_makeColorTypeAndColorSpace_2(void *image, void *recorder, int targetColorType, int color_space, int properties);
    int SkImage_reinterpretColorSpace(void *image, int color_space);
    bool SkImage_unique(void *image);
    void SkImage_ref(void *image);
    void SkImage_unref(void *image);
    // ## sk_image_filter
    void SkImageFilter_delete(void *image_filter);
    int SkImageFilter_filterBounds(void *image_filter, const void *src, const void *ctm, int direction, const void *inputRect);
    bool SkImageFilter_isColorFilterNode(void *image_filter, void **filterPtr);
    bool SkImageFilter_asColorFilter(void *image_filter, void **filterPtr);
    bool SkImageFilter_asAColorFilter(void *image_filter, void **filterPtr);
    int SkImageFilter_countInputs(void *image_filter);
    const void * SkImageFilter_getInput(void *image_filter, int i);
    int SkImageFilter_computeFastBounds(void *image_filter, const void *bounds);
    bool SkImageFilter_canComputeFastBounds(void *image_filter);
    int SkImageFilter_makeWithLocalMatrix(void *image_filter, const void *matrix);
    int SkImageFilter_getFactory(void *image_filter);
    const char * SkImageFilter_getTypeName(void *image_filter);
    void SkImageFilter_flatten(void *image_filter, void *buffer);
    int SkImageFilter_getFlattenableType(void *image_filter);
    int SkImageFilter_serialize(void *image_filter, const void *procs);
    size_t SkImageFilter_serialize_2(void *image_filter, void *memory, size_t memory_size, const void *procs);
    bool SkImageFilter_unique(void *image_filter);
    void SkImageFilter_ref(void *image_filter);
    void SkImageFilter_unref(void *image_filter);
    int SkImageFilter_Deserialize(const void *data, size_t size, const void *procs);
    int SkImageFilter_NameToFactory(const char *name);
    const char * SkImageFilter_FactoryToName(int factory);
    void SkImageFilter_Register(const char *name, int factory);
    // ## sk_image_filters
    void SkImageFilters_delete(void * imageFilters);
    int SkImageFilters_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePMColor, int background, int foreground, const void *cropRect);
    int SkImageFilters_Blend(int mode, int background, int foreground, const void *cropRect);
    int SkImageFilters_Blend_2(int blender, int background, int foreground, const void *cropRect);
    int SkImageFilters_Blur(float sigmaX, float sigmaY, int tileMode, int input, const void *cropRect);
    int SkImageFilters_Blur_2(float sigmaX, float sigmaY, int input, const void *cropRect);
    int SkImageFilters_ColorFilter(int cf, int input, const void *cropRect);
    int SkImageFilters_Compose(int outer, int inner);
    int SkImageFilters_Crop(const void *rect, int tileMode, int input);
    int SkImageFilters_Crop_2(const void *rect, int input);
    int SkImageFilters_DisplacementMap(int xChannelSelector, int yChannelSelector, float scale, int displacement, int color, const void *cropRect);
    int SkImageFilters_DropShadow(float dx, float dy, float sigmaX, float sigmaY, uint32_t color, int input, const void *cropRect);
    int SkImageFilters_DropShadowOnly(float dx, float dy, float sigmaX, float sigmaY, uint32_t color, int input, const void *cropRect);
    int SkImageFilters_Empty();
    int SkImageFilters_Image(int image, const void *srcRect, const void *dstRect, const void *sampling);
    int SkImageFilters_Image_2(int image, const void *sampling);
    int SkImageFilters_Magnifier(const void *lensBounds, float zoomAmount, float inset, const void *sampling, int input, const void *cropRect);
    int SkImageFilters_MatrixConvolution(const void *kernelSize, const void *kernel, float gain, float bias, const void *kernelOffset, int tileMode, bool convolveAlpha, int input, const void *cropRect);
    int SkImageFilters_MatrixTransform(const void *matrix, const void *sampling, int input);
    int SkImageFilters_Merge(void *filters, int count, const void *cropRect);
    int SkImageFilters_Merge_2(int first, int second, const void *cropRect);
    int SkImageFilters_Offset(float dx, float dy, int input, const void *cropRect);
    int SkImageFilters_Picture(int picture, const void *targetRect);
    int SkImageFilters_Picture_2(int picture);
    int SkImageFilters_RuntimeShader(const void *builder, int childShaderName, int input);
    int SkImageFilters_RuntimeShader_2(const void *builder, float sampleRadius, int childShaderName, int input);
    int SkImageFilters_RuntimeShader_3(const void *builder, void *childShaderNames, const void *inputs, int inputCount);
    int SkImageFilters_RuntimeShader_4(const void *builder, float maxSampleRadius, void *childShaderNames, const void *inputs, int inputCount);
    int SkImageFilters_Shader(int shader, const void *cropRect);
    int SkImageFilters_Shader_2(int shader, bool dither, const void *cropRect);
    int SkImageFilters_Tile(const void *src, const void *dst, int input);
    int SkImageFilters_Dilate(float radiusX, float radiusY, int input, const void *cropRect);
    int SkImageFilters_Erode(float radiusX, float radiusY, int input, const void *cropRect);
    int SkImageFilters_DistantLitDiffuse(const void *direction, uint32_t lightColor, float surfaceScale, float kd, int input, const void *cropRect);
    int SkImageFilters_PointLitDiffuse(const void *location, uint32_t lightColor, float surfaceScale, float kd, int input, const void *cropRect);
    int SkImageFilters_SpotLitDiffuse(const void *location, const void *target, float falloffExponent, float cutoffAngle, uint32_t lightColor, float surfaceScale, float kd, int input, const void *cropRect);
    int SkImageFilters_DistantLitSpecular(const void *direction, uint32_t lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect);
    int SkImageFilters_PointLitSpecular(const void *location, uint32_t lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect);
    int SkImageFilters_SpotLitSpecular(const void *location, const void *target, float falloffExponent, float cutoffAngle, uint32_t lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect);
    // ## sk_image_generator
    void SkImageGenerator_delete(void *image_generator);
    uint32_t SkImageGenerator_uniqueID(void *image_generator);
    int SkImageGenerator_refEncodedData(void *image_generator);
    int SkImageGenerator_getInfo(void *image_generator);
    bool SkImageGenerator_isValid(void *image_generator, void *context);
    bool SkImageGenerator_isProtected(void *image_generator);
    bool SkImageGenerator_getPixels(void *image_generator, const void *info, void *pixels, size_t rowBytes);
    bool SkImageGenerator_getPixels_2(void *image_generator, const void *pm);
    bool SkImageGenerator_queryYUVAInfo(void *image_generator, const void *supportedDataTypes, void *yuvaPixmapInfo);
    bool SkImageGenerator_getYUVAPlanes(void *image_generator, const void *yuvaPixmaps);
    bool SkImageGenerator_isTextureGenerator(void *image_generator);
    // ## sk_image_info
    void *SkImageInfo_new();
    void SkImageInfo_delete(void *image_info);
    int SkImageInfo_width(void *image_info);
    int SkImageInfo_height(void *image_info);
    int SkImageInfo_colorType(void *image_info);
    int SkImageInfo_alphaType(void *image_info);
    void * SkImageInfo_colorSpace(void *image_info);
    int SkImageInfo_refColorSpace(void *image_info);
    bool SkImageInfo_isEmpty(void *image_info);
    int SkImageInfo_colorInfo(void *image_info);
    bool SkImageInfo_isOpaque(void *image_info);
    int SkImageInfo_dimensions(void *image_info);
    int SkImageInfo_bounds(void *image_info);
    bool SkImageInfo_gammaCloseToSRGB(void *image_info);
    int SkImageInfo_makeWH(void *image_info, int newWidth, int newHeight);
    int SkImageInfo_makeDimensions(void *image_info, int newSize);
    int SkImageInfo_makeAlphaType(void *image_info, int newAlphaType);
    int SkImageInfo_makeColorType(void *image_info, int newColorType);
    int SkImageInfo_makeColorSpace(void *image_info, int color_space);
    int SkImageInfo_bytesPerPixel(void *image_info);
    int SkImageInfo_shiftPerPixel(void *image_info);
    uint64_t SkImageInfo_minRowBytes64(void *image_info);
    size_t SkImageInfo_minRowBytes(void *image_info);
    size_t SkImageInfo_computeOffset(void *image_info, int x, int y, size_t rowBytes);
    size_t SkImageInfo_computeByteSize(void *image_info, size_t rowBytes);
    size_t SkImageInfo_computeMinByteSize(void *image_info);
    bool SkImageInfo_validRowBytes(void *image_info, size_t rowBytes);
    void SkImageInfo_reset(void *image_info);
    int SkImageInfo_Make(int width, int height, int ct, int at);
    int SkImageInfo_Make_2(int width, int height, int ct, int at, int color_space);
    int SkImageInfo_Make_3(int dimensions, int ct, int at);
    int SkImageInfo_Make_4(int dimensions, int ct, int at, int color_space);
    int SkImageInfo_Make_5(int dimensions, const void *colorInfo);
    int SkImageInfo_MakeN32(int width, int height, int at);
    int SkImageInfo_MakeN32_2(int width, int height, int at, int color_space);
    int SkImageInfo_MakeS32(int width, int height, int at);
    int SkImageInfo_MakeN32Premul(int width, int height);
    int SkImageInfo_MakeN32Premul_2(int width, int height, int color_space);
    int SkImageInfo_MakeN32Premul_3(int dimensions);
    int SkImageInfo_MakeN32Premul_4(int dimensions, int color_space);
    int SkImageInfo_MakeA8(int width, int height);
    int SkImageInfo_MakeA8_2(int dimensions);
    int SkImageInfo_MakeUnknown(int width, int height);
    int SkImageInfo_MakeUnknown_2();
    bool SkImageInfo_ByteSizeOverflowed(size_t byteSize);
    // ## sk_images
    int SkImages_RasterFromBitmap(const void *bitmap);
    int SkImages_RasterFromCompressedTextureData(int data, int width, int height, int type);
    int SkImages_DeferredFromEncodedData(int data);
    int SkImages_DeferredFromGenerator(int image_generator);
    int SkImages_DeferredFromPicture(int picture, const void *dimensions, const void *matrix, const void *paint, int bitDepth, int color_space, int props);
    int SkImages_DeferredFromPicture_2(int picture, const void *dimensions, const void *matrix, const void *paint, int bitDepth, int color_space);
    int SkImages_RasterFromPixmapCopy(const void *pixmap);
    int SkImages_RasterFromPixmap(const void *pixmap, void(*rasterReleaseProc)(const void *, void *), void *releaseContext);
    int SkImages_RasterFromData(const void *info, int data, size_t rowBytes);
    int SkImages_MakeWithFilter(int image, const void *filter, const void *subset, const void *clipBounds, void *outSubset, void *offset);
    // ## sk_jpeg_decoder
    bool SkJpegDecoder_IsJpeg(const void *ptr, size_t size);
    int SkJpegDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkJpegDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkJpegDecoder_Decoder();
    /*
    // ## sk_jpeg_encoder
    bool SkJpegEncoder_Encode(void* dst, const void* src, const void* options);
    bool SkJpegEncoder_Encode_2(void* dst, const void* src, const void* srcColorSpace, const void *options);
    int SkJpegEncoder_Encode_3(void* ctx, const void* img, const void* options);
    int SkJpegEncoder_Make(void* dst, const void* src, const void* options);
    int SkJpegEncoder_Make_2(void* dst, const void* src, const void* srcColorSpace, const void *options);
    */
    // ## sk_jpegxl_decoder
    // ## sk_line_2d_path_effect
    void SkLine2DPathEffect_delete(void *line2DPathEffect);
    int SkLine2DPathEffect_Make(float width, const void *matrix);
    void SkLine2DPathEffect_RegisterFlattenables();
    // ## sk_luma_color_filter
    void SkLumaColorFilter_delete(void *lumaColorFilter);
    int SkLumaColorFilter_Make();
    // ## sk_m_44
    void *SkM44_new(const void *src);
    void *SkM44_new_2(const void *src);
    void *SkM44_new_3();
    void *SkM44_new_4(const void *a, const void *b);
    void *SkM44_new_5(float m0, float m4, float m8, float m12, float m1, float m5, float m9, float m13, float m2, float m6, float m10, float m14, float m3, float m7, float m11, float m15);
    void SkM44_delete(void *m44);
    void SkM44_getColMajor(void *m44, float *v);
    void SkM44_getRowMajor(void *m44, float *v);
    float SkM44_rc(void *m44, int r, int c);
    void SkM44_setRC(void *m44, int r, int c, float value);
    int SkM44_row(void *m44, int i);
    int SkM44_col(void *m44, int i);
    void SkM44_setRow(void *m44, int i, const void *v);
    void SkM44_setCol(void *m44, int i, const void *v);
    int SkM44_setIdentity(void *m44);
    int SkM44_setTranslate(void *m44, float x, float y, float z);
    int SkM44_setScale(void *m44, float x, float y, float z);
    int SkM44_setRotateUnitSinCos(void *m44, int axis, float sinAngle, float cosAngle);
    int SkM44_setRotateUnit(void *m44, int axis, float radians);
    int SkM44_setRotate(void *m44, int axis, float radians);
    int SkM44_setConcat(void *m44, const void *a, const void *b);
    int SkM44_preConcat(void *m44, const void *m);
    int SkM44_preConcat_2(void *m44, const void *matrix);
    int SkM44_postConcat(void *m44, const void *m);
    void SkM44_normalizePerspective(void *m44);
    bool SkM44_isFinite(void *m44);
    bool SkM44_invert(void *m44, void *inverse);
    int SkM44_transpose(void *m44);
    void SkM44_dump(void *m44);
    int SkM44_map(void *m44, float x, float y, float z, float w);
    int SkM44_asM33(void *m44);
    int SkM44_preTranslate(void *m44, float x, float y, float z);
    int SkM44_postTranslate(void *m44, float x, float y, float z);
    int SkM44_preScale(void *m44, float x, float y);
    int SkM44_preScale_2(void *m44, float x, float y, float z);
    int SkM44_Rows(const void *r0, const void *r1, const void *r2, const void *r3);
    int SkM44_Cols(const void *c0, const void *c1, const void *c2, const void *c3);
    int SkM44_RowMajor(const float *r);
    int SkM44_ColMajor(const float *c);
    int SkM44_Translate(float x, float y, float z);
    int SkM44_Scale(float x, float y, float z);
    int SkM44_Rotate(int axis, float radians);
    int SkM44_RectToRect(const void *src, const void *dst);
    int SkM44_LookAt(const void *eye, const void *center, const void *up);
    int SkM44_Perspective(float near, float far, float angle);
    // ## sk_malloc_pixel_ref
    int SkMallocPixelRef_MakeAllocate(const void *imageInfo, size_t rowBytes);
    int SkMallocPixelRef_MakeWithData(const void &imageInfo, size_t rowBytes, int data);
    // ## sk_mask_filter
    void SkMaskFilter_delete(void *maskFilter);
    int SkMaskFilter_approximateFilteredBounds(void *mask_filter, const void *src);
    int SkMaskFilter_getFactory(void *mask_filter);
    const char * SkMaskFilter_getTypeName(void *mask_filter);
    void SkMaskFilter_flatten(void *mask_filter, void *buffer);
    int SkMaskFilter_getFlattenableType(void *mask_filter);
    int SkMaskFilter_serialize(void *mask_filter, const void *procs);
    size_t SkMaskFilter_serialize_2(void *mask_filter, void *memory, size_t memory_size, const void *procs);
    bool SkMaskFilter_unique(void *mask_filter);
    void SkMaskFilter_ref(void *mask_filter);
    void SkMaskFilter_unref(void *mask_filter);
    int SkMaskFilter_MakeBlur(int style, float sigma, bool respectCTM);
    int SkMaskFilter_Deserialize(const void *data, size_t size, const void *procs);
    int SkMaskFilter_NameToFactory(const char *name);
    const char * SkMaskFilter_FactoryToName(int factory);
    void SkMaskFilter_Register(const char *name, int factory);
    // ## sk_matrix
    void *SkMatrix_new(void *matrix);
    void SkMatrix_delete(void *matrix);
    int SkMatrix_getType(void *matrix);
    bool SkMatrix_isIdentity(void *matrix);
    bool SkMatrix_isScaleTranslate(void *matrix);
    bool SkMatrix_isTranslate(void *matrix);
    bool SkMatrix_rectStaysRect(void *matrix);
    bool SkMatrix_preservesAxisAlignment(void *matrix);
    bool SkMatrix_hasPerspective(void *matrix);
    bool SkMatrix_isSimilarity(void *matrix, float tol);
    bool SkMatrix_preservesRightAngles(void *matrix, float tol);
    float SkMatrix_get(void *matrix, int index);
    float SkMatrix_rc(void *matrix, int r, int c);
    float SkMatrix_getScaleX(void *matrix);
    float SkMatrix_getScaleY(void *matrix);
    float SkMatrix_getSkewY(void *matrix);
    float SkMatrix_getSkewX(void *matrix);
    float SkMatrix_getTranslateX(void *matrix);
    float SkMatrix_getTranslateY(void *matrix);
    float SkMatrix_getPerspX(void *matrix);
    float SkMatrix_getPerspY(void *matrix);
    int SkMatrix_set(void *matrix, int index, float value);
    int SkMatrix_setScaleX(void *matrix, float v);
    int SkMatrix_setScaleY(void *matrix, float v);
    int SkMatrix_setSkewY(void *matrix, float v);
    int SkMatrix_setSkewX(void *matrix, float v);
    int SkMatrix_setTranslateX(void *matrix, float v);
    int SkMatrix_setTranslateY(void *matrix, float v);
    int SkMatrix_setPerspX(void *matrix, float v);
    int SkMatrix_setPerspY(void *matrix, float v);
    int SkMatrix_setAll(void *matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2);
    void SkMatrix_get9(void *matrix, float *buffer);
    int SkMatrix_set9(void *matrix, const float *buffer);
    int SkMatrix_reset(void *matrix);
    int SkMatrix_setIdentity(void *matrix);
    int SkMatrix_setTranslate(void *matrix, float dx, float dy);
    int SkMatrix_setTranslate_2(void *matrix, const void *v);
    int SkMatrix_setScale(void *matrix, float sx, float sy, float px, float py);
    int SkMatrix_setScale_2(void *matrix, float sx, float sy);
    int SkMatrix_setRotate(void *matrix, float degrees, float px, float py);
    int SkMatrix_setRotate_2(void *matrix, float degrees);
    int SkMatrix_setSinCos(void *matrix, float sinValue, float cosValue, float px, float py);
    int SkMatrix_setSinCos_2(void *matrix, float sinValue, float cosValue);
    int SkMatrix_setRSXform(void *matrix, const void *rsxForm);
    int SkMatrix_setSkew(void *matrix, float kx, float ky, float px, float py);
    int SkMatrix_setSkew_2(void *matrix, float kx, float ky);
    int SkMatrix_setConcat(void *matrix, const void *a, const void *b);
    int SkMatrix_preTranslate(void *matrix, float dx, float dy);
    int SkMatrix_preScale(void *matrix, float sx, float sy, float px, float py);
    int SkMatrix_preScale_2(void *matrix, float sx, float sy);
    int SkMatrix_preRotate(void *matrix, float degrees, float px, float py);
    int SkMatrix_preRotate_2(void *matrix, float degrees);
    int SkMatrix_preSkew(void *matrix, float kx, float ky, float px, float py);
    int SkMatrix_preSkew_2(void *matrix, float kx, float ky);
    int SkMatrix_preConcat(void *matrix, const void *other);
    int SkMatrix_postTranslate(void *matrix, float dx, float dy);
    int SkMatrix_postScale(void *matrix, float sx, float sy, float px, float py);
    int SkMatrix_postScale_2(void *matrix, float sx, float sy);
    int SkMatrix_postRotate(void *matrix, float degrees, float px, float py);
    int SkMatrix_postRotate_2(void *matrix, float degrees);
    int SkMatrix_postSkew(void *matrix, float kx, float ky, float px, float py);
    int SkMatrix_postSkew_2(void *matrix, float kx, float ky);
    int SkMatrix_postConcat(void *matrix, const void *other);
    bool SkMatrix_setRectToRect(void *matrix, const void *src, const void *dst, int stf);
    bool SkMatrix_setPolyToPoly(void *matrix, const void *src, const void *dst, int count);
    bool SkMatrix_invert(void *matrix, void *inverse);
    bool SkMatrix_asAffine(void *matrix, float *affine);
    int SkMatrix_setAffine(void *matrix, const float *affine);
    void SkMatrix_normalizePerspective(void *matrix);
    void SkMatrix_mapPoints(void *matrix, void *dst, const void *src, int count);
    void SkMatrix_mapPoints_2(void *matrix, void *pts, int count);
    void SkMatrix_mapHomogeneousPoints(void *matrix, void *dst, const void *src, int count);
    void SkMatrix_mapHomogeneousPoints_2(void *matrix, void *dst, const void *src, int count);
    int SkMatrix_mapPoint(void *matrix, int pt);
    void SkMatrix_mapXY(void *matrix, float x, float y, void *result);
    int SkMatrix_mapXY_2(void *matrix, float x, float y);
    int SkMatrix_mapOrigin(void *matrix);
    void SkMatrix_mapVectors(void *matrix, void *dst, const void *src, int count);
    void SkMatrix_mapVectors_2(void *matrix, void *vecs, int count);
    void SkMatrix_mapVector(void *matrix, float dx, float dy, void *result);
    int SkMatrix_mapVector_2(void *matrix, float dx, float dy);
    bool SkMatrix_mapRect(void *matrix, void *dst, const void *src, int pc);
    bool SkMatrix_mapRect_2(void *matrix, void *rect, int pc);
    int SkMatrix_mapRect_3(void *matrix, const void *src, int pc);
    void SkMatrix_mapRectToQuad(void *matrix, void *dst, const void *rect);
    void SkMatrix_mapRectScaleTranslate(void *matrix, void *dst, const void *src);
    float SkMatrix_mapRadius(void *matrix, float radius);
    void SkMatrix_dump(void *matrix);
    float SkMatrix_getMinScale(void *matrix);
    float SkMatrix_getMaxScale(void *matrix);
    bool SkMatrix_getMinMaxScales(void *matrix, float *scaleFactors);
    bool SkMatrix_decomposeScale(void *matrix, void *scale, void *remaining);
    void SkMatrix_dirtyMatrixTypeCache(void *matrix);
    void SkMatrix_setScaleTranslate(void *matrix, float sx, float sy, float tx, float ty);
    bool SkMatrix_isFinite(void *matrix);
    int SkMatrix_Scale(float sx, float sy);
    int SkMatrix_Translate(float dx, int dy);
    int SkMatrix_Translate_2(int t);
    int SkMatrix_Translate_3(int t);
    int SkMatrix_RotateDeg(float deg);
    int SkMatrix_RotateDeg_2(float deg, int pt);
    int SkMatrix_RotateRad(float rad);
    int SkMatrix_Skew(float kx, float ky);
    int SkMatrix_RectToRect(const void *src, const void *dst, int mode);
    int SkMatrix_MakeAll(float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float pers0, float pers1, float pers2);
    int SkMatrix_MakeRectToRect(const void *src, const void *dst, int stf);
    void SkMatrix_SetAffineIdentity(float *affine);
    int SkMatrix_I();
    int SkMatrix_InvalidMatrix();
    int SkMatrix_Concat(const void *a, const void *b);
    // ## sk_memory_stream
    void *SkMemoryStream_new();
    void *SkMemoryStream_new_2(size_t length);
    void *SkMemoryStream_new_3(const void *data, size_t length, bool copyData);
    void *SkMemoryStream_new_4(int data);
    void SkMemoryStream_delete(void *memoryStream);
    void SkMemoryStream_setMemory(void *memory_stream, const void *data, size_t length, bool copyData);
    void SkMemoryStream_setMemoryOwned(void *memory_stream, const void *data, size_t length);
    int SkMemoryStream_asData(void *memory_stream);
    void SkMemoryStream_setData(void *memory_stream, int data);
    void SkMemoryStream_skipToAlign4(void *memory_stream);
    const void * SkMemoryStream_getAtPos(void *memory_stream);
    size_t SkMemoryStream_read(void *memory_stream, void *buffer, size_t size);
    bool SkMemoryStream_isAtEnd(void *memory_stream);
    size_t SkMemoryStream_peek(void *memory_stream, void *buffer, size_t size);
    bool SkMemoryStream_rewind(void *memory_stream);
    int SkMemoryStream_duplicate(void *memory_stream);
    size_t SkMemoryStream_getPosition(void *memory_stream);
    bool SkMemoryStream_seek(void *memory_stream, size_t position);
    bool SkMemoryStream_move(void *memory_stream, long offset);
    int SkMemoryStream_fork(void *memory_stream);
    size_t SkMemoryStream_getLength(void *memory_stream);
    const void * SkMemoryStream_getMemoryBase(void *memory_stream);
    bool SkMemoryStream_hasLength(void *memory_stream);
    bool SkMemoryStream_hasPosition(void *memory_stream);
    size_t SkMemoryStream_skip(void *memory_stream, size_t size);
    bool SkMemoryStream_readS8(void *memory_stream, int8_t *i);
    bool SkMemoryStream_readS16(void *memory_stream, int16_t *i);
    bool SkMemoryStream_readS32(void *memory_stream, int32_t *i);
    bool SkMemoryStream_readU8(void *memory_stream, uint8_t *i);
    bool SkMemoryStream_readU16(void *memory_stream, uint16_t *i);
    bool SkMemoryStream_readU32(void *memory_stream, uint32_t *i);
    bool SkMemoryStream_readBool(void *memory_stream, bool *b);
    bool SkMemoryStream_readScalar(void *memory_stream, void *v);
    bool SkMemoryStream_readPackedUInt(void *memory_stream, size_t *size);
    int SkMemoryStream_MakeCopy(const void *data, size_t length);
    int SkMemoryStream_MakeDirect(const void *data, size_t length);
    int SkMemoryStream_Make(int data);
    // ## sk_meshes
    int SkMeshes_MakeIndexBuffer(const void *data, size_t size);
    int SkMeshes_CopyIndexBuffer(const void *indexBuffer);
    int SkMeshes_MakeVertexBuffer(const void *data, size_t size);
    int SkMeshes_CopyVertexBuffer(const void *vertexBuffer);
    // ## sk_op_builder
    void SkOpBuilder_delete(void *opBuilder);
    void SkOpBuilder_add(void *op_builder, const void *path, int path_operator);
    bool SkOpBuilder_resolve(void *op_builder, void *result);
    /*
    // ## sk_open_type_svg_decoder
    void SkOpenTypeSVGDecoder_delete(void *open_type_svg_decoder);
    size_t SkOpenTypeSVGDecoder_approximateSize(void *open_type_svg_decoder);
    bool SkOpenTypeSVGDecoder_render(void *open_type_svg_decoder, void *canvas, int upem, uint16_t glyphId, uint32_t foregroundColor, int color);
    */
    // ## sk_overdraw_canvas
    void SkOverdrawCanvas_delete(void *overdraw_canvas);
    void SkOverdrawCanvas_onDrawTextBlob(void *overdraw_canvas, const void *blob, float scalar1, float scalar2, const void *paint);
    void SkOverdrawCanvas_onDrawGlyphRunList(void *overdraw_canvas, const void *glyphRunList, const void *paint);
    void SkOverdrawCanvas_onDrawPatch(void *overdraw_canvas, const void *point1, const void *color, const void *point2, int mode, const void *paint);
    void SkOverdrawCanvas_onDrawPaint(void *overdraw_canvas, const void *paint);
    void SkOverdrawCanvas_onDrawBehind(void *overdraw_canvas, const void *paint);
    void SkOverdrawCanvas_onDrawRect(void *overdraw_canvas, const void *rect, const void *paint);
    void SkOverdrawCanvas_onDrawRegion(void *overdraw_canvas, const void *region, const void *paint);
    void SkOverdrawCanvas_onDrawOval(void *overdraw_canvas, const void *rect, const void *paint);
    void SkOverdrawCanvas_onDrawArc(void *overdraw_canvas, const void *rect, float scalar1, float scalar2, bool v, const void *paint);
    void SkOverdrawCanvas_onDrawDRRect(void *overdraw_canvas, const void *rect1, const void *rect2, const void *paint);
    void SkOverdrawCanvas_onDrawRRect(void *overdraw_canvas, const void *rect, const void *paint);
    void SkOverdrawCanvas_onDrawPoints(void *overdraw_canvas, int mode, size_t size, const void *point, const void *paint);
    void SkOverdrawCanvas_onDrawVerticesObject(void *overdraw_canvas, const void *vertices, int mode, const void *paint);
    void SkOverdrawCanvas_onDrawPath(void *overdraw_canvas, const void *path, const void *paint);
    void SkOverdrawCanvas_onDrawImage2(void *overdraw_canvas, const void *image, float scalar1, float scalar2, const void *options, const void *paint);
    void SkOverdrawCanvas_onDrawImageRect2(void *overdraw_canvas, const void *image, const void *rect1, const void *rect2, const void *options, const void *paint, int constraint);
    void SkOverdrawCanvas_onDrawImageLattice2(void *overdraw_canvas, const void *image, const void *lattice, const void *rect, int mode, const void *paint);
    void SkOverdrawCanvas_onDrawAtlas2(void *overdraw_canvas, const void * image, const void *form, const void *rect1, const void *color, int v, int mode, const void *options, const void *rect2, const void *paint);
    void SkOverdrawCanvas_onDrawDrawable(void *overdraw_canvas, void *drawable, const void *matrix);
    void SkOverdrawCanvas_onDrawPicture(void *overdraw_canvas, const void *picture, const void *matrix, const void *paint);
    void SkOverdrawCanvas_onDrawAnnotation(void *overdraw_canvas, const void *rect, const char *key, void *value);
    void SkOverdrawCanvas_onDrawShadowRec(void *overdraw_canvas, const void *path, const void *rec);
    void SkOverdrawCanvas_onDrawEdgeAAQuad(void *overdraw_canvas, const void *rect, const void *point, unsigned int flags, const void *color, int mode);
    void SkOverdrawCanvas_onDrawEdgeAAImageSet2(void *overdraw_canvas, const void *entry, int count, const void *point, const void *matrix, const void *options, const void *paint, int constraint);
    // ## sk_overdraw_color_filter
    void SkOverdrawColorFilter_delete(void * overdrawColorFilter);
    int SkOverdrawColorFilter_MakeWithSkColors(const void *color);
    // ## sk_paint
    void *SkPaint_new();
    void *SkPaint_new_2(const void *color, void *colorSpace);
    void *SkPaint_new_3(const void *paint);
    void SkPaint_delete(void *paint);
    void SkPaint_reset(void *paint);
    bool SkPaint_isAntiAlias(void *paint);
    void SkPaint_setAntiAlias(void *paint, bool aa);
    bool SkPaint_isDither(void *paint);
    void SkPaint_setDither(void *paint, bool dither);
    uint8_t SkPaint_getStyle(void *paint);
    void SkPaint_setStyle(void *paint, uint8_t style);
    void SkPaint_setStroke(void *paint, bool v);
    uint32_t SkPaint_getColor(void *paint);
    int SkPaint_getColor4f(void *paint);
    void SkPaint_setColor(void *paint, uint32_t color);
    void SkPaint_setColor_2(void *paint, const void *color, void *colorSpace);
    void SkPaint_setColor4f(void *paint, const void *color, void *colorSpace);
    float SkPaint_getAlphaf(void *paint);
    uint8_t SkPaint_getAlpha(void *paint);
    void SkPaint_setAlphaf(void *paint, float a);
    void SkPaint_setAlpha(void *paint, unsigned int a);
    void SkPaint_setARGB(void *paint, unsigned int a, unsigned int r, unsigned int g, unsigned int b);
    float SkPaint_getStrokeWidth(void *paint);
    void SkPaint_setStrokeWidth(void *paint, float width);
    float SkPaint_getStrokeMiter(void *paint);
    void SkPaint_setStrokeMiter(void *paint, float miter);
    int SkPaint_getStrokeCap(void *paint);
    void SkPaint_setStrokeCap(void *paint, int cap);
    uint8_t SkPaint_getStrokeJoin(void *paint);
    void SkPaint_setStrokeJoin(void *paint, uint8_t join);
    void *SkPaint_getShader(void *paint);
    int SkPaint_refShader(void *paint);
    void SkPaint_setShader(void *paint, int shader);
    void *SkPaint_getColorFilter(void *paint);
    int SkPaint_refColorFilter(void *paint);
    void SkPaint_setColorFilter(void *paint, int color_filter);
    int SkPaint_asBlendMode(void *paint);
    int SkPaint_getBlendMode_or(void *paint, int defaultMode);
    bool SkPaint_isSrcOver(void *paint);
    void SkPaint_setBlendMode(void *paint, int mode);
    void * SkPaint_getBlender(void *paint);
    int SkPaint_refBlender(void *paint);
    void SkPaint_setBlender(void *paint, int blender);
    void * SkPaint_getPathEffect(void *paint);
    int SkPaint_refPathEffect(void *paint);
    void SkPaint_setPathEffect(void *paint, int path_effect);
    void * SkPaint_getMaskFilter(void *paint);
    int SkPaint_refMaskFilter(void *paint);
    void SkPaint_setMaskFilter(void *paint, int mask_filter);
    void * SkPaint_getImageFilter(void *paint);
    int SkPaint_refImageFilter(void *paint);
    void SkPaint_setImageFilter(void *paint, int image_filter);
    bool SkPaint_nothingToDraw(void *paint);
    bool SkPaint_canComputeFastBounds(void *paint);
    const void * SkPaint_computeFastBounds(void *paint, const void *orig, void *storage);
    const void * SkPaint_computeFastStrokeBounds(void *paint, const void *orig, void *storage);
    const void * SkPaint_doComputeFastBounds(void *paint, const void *orig, void *storage, uint8_t style);
    // ## sk_path
    void *SkPath_new();
    void *SkPath_new_2(const void *path);
    void SkPath_delete(void *path);
    bool SkPath_isInterpolatable(void *path, const void *compare);
    bool SkPath_interpolate(void *path, const void *ending, float weight, void *out);
    int SkPath_getFillType(void *path);
    void SkPath_setFillType(void *path, int ft);
    bool SkPath_isInverseFillType(void *path);
    void SkPath_toggleInverseFillType(void *path);
    bool SkPath_isConvex(void *path);
    bool SkPath_isOval(void *path, void *bounds);
    bool SkPath_isRRect(void *path, void *rrect);
    void *SkPath_reset(void *path);
    void *SkPath_rewind(void *path);
    bool SkPath_isEmpty(void *path);
    bool SkPath_isLastContourClosed(void *path);
    bool SkPath_isFinite(void *path);
    bool SkPath_isVolatile(void *path);
    void *SkPath_setIsVolatile(void *path, bool isVolatile);
    bool SkPath_isLine(void *path, void *line);
    int SkPath_countPoints(void *path);
    int SkPath_getPoint(void *path, int index);
    int SkPath_getPoints(void *path, void *points, int max);
    int SkPath_countVerbs(void *path);
    int SkPath_getVerbs(void *path, uint8_t *verbs, int max);
    size_t SkPath_approximateBytesUsed(void *path);
    void SkPath_swap(void *path, void *other);
    const void *SkPath_getBounds(void *path);
    void SkPath_updateBoundsCache(void *path);
    int SkPath_computeTightBounds(void *path);
    bool SkPath_conservativelyContainsRect(void *path, const void *rect);
    void SkPath_incReserve(void *path, int extraPtCount);
    void *SkPath_moveTo(void *path, float x, float y);
    void *SkPath_moveTo_2(void *path, const void *p);
    void *SkPath_rMoveTo(void *path, float dx, float dy);
    void *SkPath_lineTo(void *path, float x, float y);
    void *SkPath_lineTo_2(void *path, const void *p);
    void *SkPath_rLineTo(void *path, float dx, float dy);
    void *SkPath_quadTo(void *path, float x1, float y1, float x2, float y2);
    void *SkPath_quadTo_2(void *path, const void *p1, const void *p2);
    void *SkPath_rQuadTo(void *path, float dx1, float dy1, float dx2, float dy2);
    void *SkPath_conicTo(void *path, float x1, float y1, float x2, float y2, float w);
    void *SkPath_conicTo_2(void *path, const void *p1, const void *p2, float w);
    void *SkPath_rConicTo(void *path, float dx1, float dy1, float dx2, float dy2, float w);
    void *SkPath_cubicTo(void *path, float x1, float y1, float x2, float y2, float x3, float y3);
    void *SkPath_cubicTo_2(void *path, const void *p1, const void *p2, const void *p3);
    void *SkPath_rCubicTo(void *path, float dx1, float dy1, float dx2, float dy2, float dx3, float dy3);
    void *SkPath_arcTo(void *path, const void *oval, float startAngle, float sweepAngle, bool forceMoveTo);
    void *SkPath_arcTo_2(void *path, float x1, float y1, float x2, float y2, float radius);
    void *SkPath_arcTo_3(void *path, int p1, int p2, float radius);
    void *SkPath_arcTo_4(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float x, float y);
    void *SkPath_arcTo_5(void *path, int r, float xAxisRotate, int largeArc, int sweep, int xy);
    void *SkPath_rArcTo(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float dx, float dy);
    void *SkPath_close(void *path);
    bool SkPath_isRect(void *path, void *rect, bool *isClosed, void *direction);
    void *SkPath_addRect(void *path, const void *rect, int dir, unsigned start);
    void *SkPath_addRect_2(void *path, const void *rect, int dir);
    void *SkPath_addRect_3(void *path, float left, float top, float right, float bottom, int dir);
    void *SkPath_addOval(void *path, const void *oval, int dir);
    void *SkPath_addOval_2(void *path, const void *oval, int dir, unsigned start);
    void *SkPath_addCircle(void *path, float x, float y, float radius, int dir);
    void *SkPath_addArc(void *path, const void *oval, float startAngle, float sweepAngle);
    void *SkPath_addRoundRect(void *path, const void *rect, float rx, float ry, int dir);
    void *SkPath_addRoundRect_2(void *path, const void *rect, const void *radii, int dir);
    void *SkPath_addRRect(void *path, const void *rrect, int dir);
    void *SkPath_addRRect_2(void *path, const void *rrect, int dir, unsigned start);
    void *SkPath_addPoly(void *path, const void *pts, int count, bool close);
    void *SkPath_addPoly_2(void *path, const void *list, bool close);
    void *SkPath_addPath(void *path, const void *src, float dx, float dy, int mode);
    void *SkPath_addPath_2(void *path, const void *src, int modeSkPath);
    void *SkPath_addPath_3(void *path, const void *src, const void *matrix, int mode);
    void *SkPath_reverseAddPath(void *path, const void *src);
    void SkPath_offset(void *path, float dx, float dy, void *dst);
    void SkPath_offset_2(void *path, float dx, float dy);
    void SkPath_transform(void *path, const void *matrix, void *dst, int pc);
    void SkPath_transform_2(void *path, const void *matrix, int pc);
    int SkPath_makeTransform(void *path, const void *m, int pc);
    int SkPath_makeScale(void *path, float sx, float sy);
    bool SkPath_getLastPt(void *path, void *lastPt);
    void SkPath_setLastPt(void *path, float x, float y);
    void SkPath_setLastPt_2(void *path, const void *p);
    uint32_t SkPath_getSegmentMasks(void *path);
    bool SkPath_contains(void *path, float x, float y);
    void SkPath_dump(void *path, void *stream, bool dumpAsHex);
    void SkPath_dump_2(void *path);
    void SkPath_dumpHex(void *path);
    void SkPath_dumpArrays(void *path, void *stream, bool dumpAsHex);
    void SkPath_dumpArrays_2(void *path);
    size_t SkPath_writeToMemory(void *path, void *buffer);
    int SkPath_serialize(void *path);
    size_t SkPath_readFromMemory(void *path, const void *buffer, size_t length);
    uint32_t SkPath_getGenerationID(void *path);
    bool SkPath_isValid(void *path);
    int SkPath_Make(const void *point, int pointCount, const uint8_t *i, int verbCount, const float *v, int conicWeightCount, int type, bool isVolatile);
    int SkPath_Rect(const void *rect, int dir, unsigned startIndex);
    int SkPath_Oval(const void *rect, int dir);
    int SkPath_Oval_2(const void *rect, int dir, unsigned startIndex);
    int SkPath_Circle(float center_x, float center_y, float radius, int dir);
    int SkPath_RRect(const void *rrect, int dir);
    int SkPath_RRect_2(const void *rrect, int dir, unsigned startIndex);
    int SkPath_RRect_3(const void *bounds, float rx, float ry, int dir);
    int SkPath_Polygon(const void *pts, int count, bool isClosed, int type, bool isVolatile);
    int SkPath_Polygon_2(const void *list, bool isClosed, int fillType, bool isVolatile);
    int SkPath_Line(int a, int b);
    bool SkPath_IsLineDegenerate(const void *p1, const void *p2, bool exact);
    bool SkPath_IsQuadDegenerate(const void *p1, const void *p2, const void *p3, bool exact);
    bool SkPath_IsCubicDegenerate(const void *p1, const void *p2, const void *p3, const void *p4, bool exact);
    int SkPath_ConvertConicToQuads(const void *p0, const void *p1, const void *p2, float w, void *pts, int pow2);
    // ## sk_path_1d_path_effect
    void SkPath1DPathEffect_delete(void * path1DPathEffect);
    int SkPath1DPathEffect_Make(const void *path, float advance, float phase, int style);
    void SkPath1DPathEffect_RegisterFlattenables();
    // ## sk_path_2d_path_effect
    void SkPath2DPathEffect_delete(void * path2DPathEffect);
    int SkPath2DPathEffect_Make(const void *matrix, const void *path);
    void SkPath2DPathEffect_RegisterFlattenables();
    // ## sk_path_builder
    void *SkPathBuilder_new();
    void *SkPathBuilder_new_2(int type);
    void *SkPathBuilder_new_3(const void *path);
    void *SkPathBuilder_new_4(const void *builder);
    void SkPathBuilder_delete(void *path_builder);
    int SkPathBuilder_fillType(void *path_builder);
    int SkPathBuilder_computeBounds(void *path_builder);
    int SkPathBuilder_snapshot(void *path_builder);
    int SkPathBuilder_detach(void *path_builder);
    void * SkPathBuilder_setFillType(void *path_builder, int ft);
    void * SkPathBuilder_setIsVolatile(void *path_builder, bool isVolatile);
    void * SkPathBuilder_reset(void *path_builder);
    void * SkPathBuilder_moveTo(void *path_builder, int pt);
    void * SkPathBuilder_moveTo_2(void *path_builder, float x, float y);
    void * SkPathBuilder_lineTo(void *path_builder, int pt);
    void * SkPathBuilder_lineTo_2(void *path_builder, float x, float y);
    void * SkPathBuilder_quadTo(void *path_builder, int pt1, int pt2);
    void * SkPathBuilder_quadTo_2(void *path_builder, float x1, float y1, float x2, float y2);
    void * SkPathBuilder_quadTo_3(void *path_builder, const void *pts);
    void * SkPathBuilder_conicTo(void *path_builder, int pt1, int pt2, float w);
    void * SkPathBuilder_conicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float w);
    void * SkPathBuilder_conicTo_3(void *path_builder, const void *pts, float w);
    void * SkPathBuilder_cubicTo(void *path_builder, int pt1, int pt2, int pt3);
    void * SkPathBuilder_cubicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float x3, float y3);
    void * SkPathBuilder_cubicTo_3(void *path_builder, const void *pts);
    void * SkPathBuilder_close(void *path_builder);
    void * SkPathBuilder_polylineTo(void *path_builder, const void *pts, int count);
    void * SkPathBuilder_polylineTo_2(void *path_builder, const void *list);
    void * SkPathBuilder_rLineTo(void *path_builder, int pt);
    void * SkPathBuilder_rLineTo_2(void *path_builder, float x, float y);
    void * SkPathBuilder_rQuadTo(void *path_builder, int pt1, int pt2);
    void * SkPathBuilder_rQuadTo_2(void *path_builder, float x1, float y1, float x2, float y2);
    void * SkPathBuilder_rConicTo(void *path_builder, int p1, int p2, float w);
    void * SkPathBuilder_rConicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float w);
    void * SkPathBuilder_rCubicTo(void *path_builder, int pt1, int pt2, int pt3);
    void * SkPathBuilder_rCubicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float x3, float y3);
    void * SkPathBuilder_arcTo(void *path_builder, const void *oval, float startAngleDeg, float sweepAngleDeg, bool forceMoveTo);
    void * SkPathBuilder_arcTo_2(void *path_builder, int p1, int p2, float radius);
    void * SkPathBuilder_arcTo_3(void *path_builder, int r, float xAxisRotate, int largeArc, int sweep, int xy);
    void * SkPathBuilder_addArc(void *path_builder, const void *oval, float startAngleDeg, float sweepAngleDeg);
    void * SkPathBuilder_addRect(void *path_builder, const void *rect, int dir, unsigned startIndex);
    void * SkPathBuilder_addRect_2(void *path_builder, const void *rect, int dir);
    void * SkPathBuilder_addOval(void *path_builder, const void *rect, int dir, unsigned startIndex);
    void * SkPathBuilder_addOval_2(void *path_builder, const void *rect, int dir);
    void * SkPathBuilder_addRRect(void *path_builder, const void *rect, int dir, unsigned startIndex);
    void * SkPathBuilder_addRRect_2(void *path_builder, const void *rrect, int dir);
    void * SkPathBuilder_addCircle(void *path_builder, float center_x, float center_y, float radius, int dir);
    void * SkPathBuilder_addPolygon(void *path_builder, const void *pts, int count, bool isClosed);
    void * SkPathBuilder_addPolygon_2(void *path_builder, const void *list, bool isClosed);
    void * SkPathBuilder_addPath(void *path_builder, const void *path);
    void SkPathBuilder_incReserve(void *path_builder, int extraPtCount, int extraVerbCount);
    void SkPathBuilder_incReserve_2(void *path_builder, int extraPtCount);
    void * SkPathBuilder_offset(void *path_builder, float dx, float dy);
    void * SkPathBuilder_toggleInverseFillType(void *path_builder);
    // ## sk_path_effect
    void SkPathEffect_delete(void * pathEffect);
    int SkPathEffect_asADash(void *path_effect, void *info);
    bool SkPathEffect_filterPath(void *path_effect, void *dst, const void *src, void *rec, const void *cullR);
    bool SkPathEffect_filterPath_2(void *path_effect, void *dst, const void *src, void *rec, const void *cullR, const void *ctm);
    bool SkPathEffect_needsCTM(void *path_effect);
    int SkPathEffect_getFactory(void *path_effect);
    const char * SkPathEffect_getTypeName(void *path_effect);
    void SkPathEffect_flatten(void *path_effect, void *buffer);
    int SkPathEffect_getFlattenableType(void *path_effect);
    int SkPathEffect_serialize(void *path_effect, const void *procs);
    size_t SkPathEffect_serialize_2(void *path_effect, void *memory, size_t memory_size, const void *procs);
    bool SkPathEffect_unique(void *path_effect);
    void SkPathEffect_ref(void *path_effect);
    void SkPathEffect_unref(void *path_effect);
    int SkPathEffect_MakeSum(int first, int second);
    int SkPathEffect_MakeCompose(int outer, int inner);
    int SkPathEffect_GetFlattenableType();
    int SkPathEffect_Deserialize(const void *data, size_t size, const void *procs);
    int SkPathEffect_NameToFactory(const char name[]);
    const char * SkPathEffect_FactoryToName(int factory);
    void SkPathEffect_Register(const char name[], int factory);
    // ## sk_path_measure
    void *SkPathMeasure_new();
    void *SkPathMeasure_new_2(const void *path, bool forceClosed, float resScale);
    void SkPathMeasure_delete(void *path_measure);
    void SkPathMeasure_setPath(void *path_measure, const void *path, bool forceClosed);
    float SkPathMeasure_getLength(void *path_measure);
    bool SkPathMeasure_getPosTan(void *path_measure, float distance, void *position, void *tangent);
    bool SkPathMeasure_getMatrix(void *path_measure, float distance, void *matrix, int flags);
    bool SkPathMeasure_getSegment(void *path_measure, float startD, float stopD, void *dst, bool startWithMoveTo);
    bool SkPathMeasure_isClosed(void *path_measure);
    bool SkPathMeasure_nextContour(void *path_measure);
    /*
    // ## sk_pdf
    void SkPDF_SetNodeId(void *dst, int nodeID);
    int SkPDF_MakeDocument(void *stream, const void *metadata);
    int SkPDF_MakeDocument_2(void *stream);
    */
    // ## sk_perlin_noise_shader
    int SkPerlinNoiseShader_MakeFractalNoise(float baseFrequencyX, float baseFrequencyY, int numOctaves, float seed, const void *tileSize);
    int SkPerlinNoiseShader_MakeTurbulence(float baseFrequencyX, float baseFrequencyY, int numOctaves, float seed, const void *tileSize);
    // ## sk_picture
    void SkPicture_delete(void *picture);
    void SkPicture_playback(void *picture, void *canvas, void *callback);
    int SkPicture_cullRect(void *picture);
    uint32_t SkPicture_uniqueID(void *picture);
    int SkPicture_serialize(void *picture, const void *procs);
    void SkPicture_serialize_2(void *picture, void *stream, const void *procs);
    size_t SkPicture_approximateOpCount(void *picture);
    size_t SkPicture_approximateBytesUsed(void *picture);
    int SkPicture_makeShader(void *picture, int tmx, int tmy, int mode, const void *localMatrix, const void *tileRect);
    int SkPicture_makeShader_2(void *picture, int tmx, int tmy, int mode);
    bool SkPicture_unique(void *picture);
    void SkPicture_ref(void *picture);
    void SkPicture_unref(void *picture);
    int SkPicture_MakeFromStream(void *stream, const void *procs);
    int SkPicture_MakeFromData(const void *data, const void *procs);
    int SkPicture_MakeFromData_2(const void *data, size_t size, const void *procs);
    int SkPicture_MakePlaceholder(int cull);
    // ## sk_picture_recorder
    void *SkPictureRecorder_new();
    void SkPictureRecorder_delete(void *picture_recorder);
    void *SkPictureRecorder_beginRecording(void *picture_recorder, const void *bounds, int b_box_hierarchy);
    void *SkPictureRecorder_beginRecording_2(void *picture_recorder, const void *bounds, void *bbhFactory);
    void *SkPictureRecorder_beginRecording_3(void *picture_recorder, float width, float height, void *bbhFactory);
    void *SkPictureRecorder_getRecordingCanvas(void *picture_recorder);
    int SkPictureRecorder_finishRecordingAsPicture(void *picture_recorder);
    int SkPictureRecorder_finishRecordingAsPictureWithCull(void *picture_recorder, const void *cullRect);
    int SkPictureRecorder_finishRecordingAsDrawable(void *picture_recorder);
    // ## sk_pixel_ref
    void *SkPixelRef_new(int width, int height, void *addr, size_t rowBytes);
    void SkPixelRef_delete(void *pixel_ref);
    int SkPixelRef_dimensions(void *pixel_ref);
    int SkPixelRef_width(void *pixel_ref);
    int SkPixelRef_height(void *pixel_ref);
    void *SkPixelRef_pixels(void *pixel_ref);
    size_t SkPixelRef_rowBytes(void *pixel_ref);
    uint32_t SkPixelRef_getGenerationID(void *pixel_ref);
    void SkPixelRef_notifyPixelsChanged(void *pixel_ref);
    bool SkPixelRef_isImmutable(void *pixel_ref);
    void SkPixelRef_setImmutable(void *pixel_ref);
    void SkPixelRef_addGenIDChangeListener(void *pixel_ref, int id_change_listener);
    void SkPixelRef_notifyAddedToCache(void *pixel_ref);
    void *SkPixelRef_diagnostic_only_getDiscardable(void *pixel_ref);
    bool SkPixelRef_unique(void *pixel_ref);
    void SkPixelRef_ref(void *pixel_ref);
    void SkPixelRef_unref(void *pixel_ref);
    // ## sk_pixmap
    void *SkPixmap_new();
    void *SkPixmap_new_2(const void *info, const void *addr, size_t rowBytes);
    void SkPixmap_delete(void *pixmap);
    void SkPixmap_reset(void *pixmap);
    void SkPixmap_reset_2(void *pixmap, const void *info, const void *addr, size_t rowBytes);
    bool SkPixmap_reset_3(void *pixmap, const void *mask);
    void SkPixmap_setColorSpace(void *pixmap, int color_space);
    bool SkPixmap_extractSubset(void *pixmap, void *subset, const void *area);
    const void * SkPixmap_info(void *pixmap);
    size_t SkPixmap_rowBytes(void *pixmap);
    const void * SkPixmap_addr(void *pixmap);
    int SkPixmap_width(void *pixmap);
    int SkPixmap_height(void *pixmap);
    int SkPixmap_dimensions(void *pixmap);
    int SkPixmap_colorType(void *pixmap);
    int SkPixmap_alphaType(void *pixmap);
    void * SkPixmap_colorSpace(void *pixmap);
    int SkPixmap_refColorSpace(void *pixmap);
    bool SkPixmap_isOpaque(void *pixmap);
    int SkPixmap_bounds(void *pixmap);
    int SkPixmap_rowBytesAsPixels(void *pixmap);
    int SkPixmap_shiftPerPixel(void *pixmap);
    size_t SkPixmap_computeByteSize(void *pixmap);
    bool SkPixmap_computeIsOpaque(void *pixmap);
    uint32_t SkPixmap_getColor(void *pixmap, int x, int y);
    int SkPixmap_getColor4f(void *pixmap, int x, int y);
    float SkPixmap_getAlphaf(void *pixmap, int x, int y);
    const void * SkPixmap_addr_2(void *pixmap, int x, int y);
    const uint8_t * SkPixmap_addr8(void *pixmap);
    const uint16_t * SkPixmap_addr16(void *pixmap);
    const uint32_t * SkPixmap_addr32(void *pixmap);
    const uint64_t * SkPixmap_addr64(void *pixmap);
    const uint16_t * SkPixmap_addrF16(void *pixmap);
    const uint8_t * SkPixmap_addr8_2(void *pixmap, int x, int y);
    const uint16_t * SkPixmap_addr16_2(void *pixmap, int x, int y);
    const uint32_t * SkPixmap_addr32_2(void *pixmap, int x, int y);
    const uint64_t * SkPixmap_addr64_2(void *pixmap, int x, int y);
    const uint16_t * SkPixmap_addrF16_2(void *pixmap, int x, int y);
    void * SkPixmap_writable_addr(void *pixmap);
    void * SkPixmap_writable_addr_2(void *pixmap, int x, int y);
    uint8_t * SkPixmap_writable_addr8(void *pixmap, int x, int y);
    uint16_t * SkPixmap_writable_addr16(void *pixmap, int x, int y);
    uint32_t * SkPixmap_writable_addr32(void *pixmap, int x, int y);
    uint64_t * SkPixmap_writable_addr64(void *pixmap, int x, int y);
    uint16_t * SkPixmap_writable_addrF16(void *pixmap, int x, int y);
    bool SkPixmap_readPixels(void *pixmap, const void *dstInfo, void *dstPixels, size_t dstRowBytes);
    bool SkPixmap_readPixels_2(void *pixmap, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
    bool SkPixmap_readPixels_3(void *pixmap, const void *dst, int srcX, int srcY);
    bool SkPixmap_readPixels_4(void *pixmap, const void *dst);
    bool SkPixmap_scalePixels(void *pixmap, const void *dst, const void *options);
    bool SkPixmap_erase(void *pixmap, uint32_t color, const void *subset);
    bool SkPixmap_erase_2(void *pixmap, uint32_t color);
    bool SkPixmap_erase_3(void *pixmap, const void *color, const void *subset);
    // ## sk_pixmap_utils
    bool SkPixmapUtils_Orient(const void* dst, const void* src, int origin);
    int SkPixmapUtils_SwapWidthHeight(const void* info);
    // ## sk_png_decoder
    bool SkPngDecoder_IsPng(const void* ptr, size_t size);
    int SkPngDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkPngDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkPngDecoder_Decoder();
    // ## sk_png_encoder
    bool SkPngEncoder_Encode(void* dst, const void* src, const void *options);
    int SkPngEncoder_Encode_2(void* ctx, const void* img, const void *options);
    int SkPngEncoder_Make(void* dst, const void* src, const void *options);
    // ## sk_point
    void SkPoint_delete(void *point);
    float SkPoint_x(int point);
    float SkPoint_y(int point);
    float SkPoint_dot(int point, const void *vec);
    float SkPoint_length(int point);
    float SkPoint_cross(int point, const void *vec);
    void SkPoint_set(int point, float x, float y);
    bool SkPoint_equals(int point, float x, float y);
    bool SkPoint_isZero(int point);
    void SkPoint_scale(int point, float value);
    void SkPoint_scale_2(int point, float scale, void *dst);
    bool SkPoint_isFinite(int point);
    float SkPoint_distanceToOrigin(int point);
    void SkPoint_iset(int point, const void *p);
    void SkPoint_iset_2(int point, int32_t x, int32_t y);
    void SkPoint_negate(int point);
    void SkPoint_setAbs(int point, const void *pt);
    bool SkPoint_setLength(int point, float length);
    bool SkPoint_setNormalize(int point, float x, float y);
    int SkPoint_Make(float x, float y);
    float SkPoint_Normalize(void *vec);
    float SkPoint_Length(float x, float y);
    float SkPoint_CrossProduct(const void *a, const void *b);
    float SkPoint_DotProduct(const void *a, const void *b);
    float SkPoint_Distance(const void *a, const void *b);
    void SkPoint_Offset(void *points, int count, float dx, float dy);
    void SkPoint_Offset_2(void *points, int count, const void *offset);
    // ## sk_point_3
    void SkPoint3_delete(void *point3);
    float SkPoint3_x(void *point3);
    float SkPoint3_y(void *point3);
    float SkPoint3_z(void *point3);
    void SkPoint3_set(void *point3, float x, float y, float z);
    float SkPoint3_length(void *point3);
    bool SkPoint3_normalize(void *point3);
    int SkPoint3_makeScale(void *point3, float scale);
    void SkPoint3_scale(void *point3, float value);
    bool SkPoint3_isFinite(void *point3);
    float SkPoint3_dot(void *point3, const void *vec);
    int SkPoint3_cross(void *point3, const void *vec);
    int SkPoint3_Make(float x, float y, float z);
    float SkPoint3_Length(float x, float y, float z);
    float SkPoint3_DotProduct(const void *a, const void *b);
    int SkPoint3_CrossProduct(const void *a, const void *b);
    // ## sk_r_rect
    void *SkRRect_new();
    void *SkRRect_new_2(const void *rrect);
    void SkRRect_delete(void *rrect);
    int getType(void *rrect);
    int type(void *rrect);
    bool SkRRect_isEmpty(void *rrect);
    bool SkRRect_isRect(void *rrect);
    bool SkRRect_isOval(void *rrect);
    bool SkRRect_isSimple(void *rrect);
    bool SkRRect_isNinePatch(void *rrect);
    bool SkRRect_isComplex(void *rrect);
    float SkRRect_width(void *rrect);
    float SkRRect_height(void *rrect);
    int SkRRect_getSimpleRadii(void *rrect);
    void SkRRect_setEmpty(void *rrect);
    void SkRRect_setRect(void *rrect, const void *rect);
    void SkRRect_setOval(void *rrect, const void *oval);
    void SkRRect_setRectXY(void *rrect, const void *rect, float xRad, float yRad);
    void SkRRect_setNinePatch(void *rrect, const void *rect, float leftRad, float topRad, float rightRad, float bottomRad);
    void SkRRect_setRectRadii(void *rrect, const void *rect, const void *radii);
    const void * SkRRect_rect(void *rrect);
    int SkRRect_radii(void *rrect, int corner);
    const void * SkRRect_getBounds(void *rrect);
    void SkRRect_inset(void *rrect, float dx, float dy, void *dst);
    void SkRRect_inset_2(void *rrect, float dx, float dy);
    void SkRRect_outset(void *rrect, float dx, float dy, void *dst);
    void SkRRect_outset_2(void *rrect, float dx, float dy);
    void SkRRect_offset(void *rrect, float dx, float dy);
    int SkRRect_makeOffset(void *rrect, float dx, float dy);
    bool SkRRect_contains(void *rrect, const void *rect);
    bool SkRRect_isValid(void *rrect);
    size_t SkRRect_writeToMemory(void *rrect, void *buffer);
    size_t SkRRect_readFromMemory(void *rrect, const void *buffer, size_t length);
    bool SkRRect_transform(void *rrect, const void *matrix, void *dst);
    void SkRRect_dump(void *rrect, bool asHex);
    int SkRRect_dumpToString(void *rrect, bool asHex);
    void SkRRect_dump_2(void *rrect);
    void SkRRect_dumpHex(void *rrect);
    int SkRRect_MakeEmpty();
    int SkRRect_MakeRect(const void *r);
    int SkRRect_MakeOval(const void *oval);
    int SkRRect_MakeRectXY(const void *rect, float xRad, float yRad);
    /*
    // ## sk_raster_handle_allocator
    void SkRasterHandleAllocator_delete(void *raster_handle_allocator);
    bool SkRasterHandleAllocator_allocHandle(void *raster_handle_allocator, const void *info, void *rec);
    void SkRasterHandleAllocator_updateHandle(void *raster_handle_allocator, void *handle, const void *matrix, const void *irect);
    // ## sk_raw_decoder
    bool SkRawDecoder_IsRaw(const void* ptr, size_t size);
    int SkRawDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkRawDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkRawDecoder_Decoder();
    */
    // ## sk_rect
    void SkRect_delete(void *rect);
    bool SkRect_isEmpty(void *rect);
    bool SkRect_isSorted(void *rect);
    bool SkRect_isFinite(void *rect);
    float SkRect_x(void *rect);
    float SkRect_y(void *rect);
    float SkRect_left(void *rect);
    float SkRect_top(void *rect);
    float SkRect_right(void *rect);
    float SkRect_bottom(void *rect);
    float SkRect_width(void *rect);
    float SkRect_height(void *rect);
    float SkRect_centerX(void *rect);
    float SkRect_centerY(void *rect);
    int SkRect_center(void *rect);
    void SkRect_toQuad(void *rect, void *quad);
    void SkRect_setEmpty(void *rect);
    void SkRect_set(void *rect, const void *src);
    void SkRect_setLTRB(void *rect, float left, float top, float right, float bottom);
    void SkRect_setBounds(void *rect, const void *pts, int count);
    bool SkRect_setBoundsCheck(void *rect, const void *pts, int count);
    void SkRect_setBoundsNoCheck(void *rect, const void *pts, int count);
    void SkRect_set_2(void *rect, const void *p0, const void *p1);
    void SkRect_setXYWH(void *rect, float x, float y, float width, float height);
    void SkRect_setWH(void *rect, float width, float height);
    void SkRect_setIWH(void *rect, int32_t width, int32_t height);
    int SkRect_makeOffset(void *rect, float dx, float dy);
    int SkRect_makeOffset_2(void *rect, int v);
    int SkRect_makeInset(void *rect, float dx, float dy);
    int SkRect_makeOutset(void *rect, float dx, float dy);
    void SkRect_offset(void *rect, float dx, float dy);
    void SkRect_offset_2(void *rect, const void *delta);
    void SkRect_offsetTo(void *rect, float newX, float newY);
    void SkRect_inset(void *rect, float dx, float dy);
    void SkRect_outset(void *rect, float dx, float dy);
    bool SkRect_intersect(void *rect, const void *r);
    bool SkRect_intersect_2(void *rect, const void *a, const void *b);
    bool SkRect_intersects(void *rect, const void *r);
    void SkRect_join(void *rect, const void *r);
    void SkRect_joinNonEmptyArg(void *rect, const void *r);
    void SkRect_joinPossiblyEmptyRect(void *rect, const void *r);
    bool SkRect_contains(void *rect, float x, float y);
    bool SkRect_contains_2(void *rect, const void *r);
    bool SkRect_contains_3(void *rect, const void *r);
    void SkRect_round(void *rect, void *dst);
    void SkRect_roundOut(void *rect, void *dst);
    void SkRect_roundOut_2(void *rect, void *dst);
    void SkRect_roundIn(void *rect, void *dst);
    int SkRect_round_2(void *rect);
    int SkRect_roundOut_3(void *rect);
    int SkRect_roundIn_2(void *rect);
    void SkRect_sort(void *rect);
    int SkRect_makeSorted(void *rect);
    const float * SkRect_asScalars(void *rect);
    void SkRect_dump(void *rect, bool asHex);
    void SkRect_dump_2(void *rect);
    void SkRect_dumpHex(void *rect);
    int SkRect_MakeEmpty();
    int SkRect_MakeWH(float w, float h);
    int SkRect_MakeIWH(int w, int h);
    int SkRect_MakeSize(const void *size);
    int SkRect_MakeLTRB(float l, float t, float r, float b);
    int SkRect_MakeXYWH(float x, float y, float w, float h);
    int SkRect_Make(const void *size);
    int SkRect_Make_2(const void *irect);
    bool SkRect_Intersects(const void *a, const void *b);
    // ## sk_ref_cnt
    void SkRefCnt_delete(void* refCnt);
    bool SkRefCnt_unique(void* ref_cnt);
    void SkRefCnt_ref(void* ref_cnt);
    void SkRefCnt_unref(void* ref_cnt);
    // ## sk_ref_cnt_base
    void *SkRefCntBase_new();
    void SkRefCntBase_delete(void *ref_cnt_base);
    bool SkRefCntBase_unique(void *ref_cnt_base);
    void SkRefCntBase_ref(void *ref_cnt_base);
    void SkRefCntBase_unref(void *ref_cnt_base);
    // ## sk_region
    void *SkRegion_new();
    void *SkRegion_new_2(const void *region);
    void *SkRegion_new_3(const void *rect);
    void SkRegion_delete(void *region);
    bool SkRegion_set(void *region, const void *src);
    void SkRegion_swap(void *region, void *other);
    bool SkRegion_isEmpty(void *region);
    bool SkRegion_isRect(void *region);
    bool SkRegion_isComplex(void *region);
    const void * SkRegion_getBounds(void *region);
    int SkRegion_computeRegionComplexity(void *region);
    bool SkRegion_getBoundaryPath(void *region, void *path);
    bool SkRegion_setEmpty(void *region);
    bool SkRegion_setRect(void *region, const void *rect);
    bool SkRegion_setRects(void *region, const void *rects, int count);
    bool SkRegion_setRegion(void *region, const void *region_2);
    bool SkRegion_setPath(void *region, const void *path, const void *clip);
    bool SkRegion_intersects(void *region, const void *rect);
    bool SkRegion_intersects_2(void *region, const void *other);
    bool SkRegion_contains(void *region, int32_t x, int32_t y);
    bool SkRegion_contains_2(void *region, const void *other);
    bool SkRegion_contains_3(void *region, const void *other);
    bool SkRegion_quickContains(void *region, const void *r);
    bool SkRegion_quickReject(void *region, const void *rect);
    bool SkRegion_quickReject_2(void *region, const void *rgn);
    void SkRegion_translate(void *region, int dx, int dy);
    void SkRegion_translate_2(void *region, int dx, int dy, void *dst);
    bool SkRegion_op(void *region, const void *rect, int op);
    bool SkRegion_op_2(void *region, const void *rgn, int op);
    bool SkRegion_op_3(void *region, const void *rect, const void *rgn, int op);
    bool SkRegion_op_4(void *region, const void *rgn, const void *rect, int op);
    bool SkRegion_op_5(void *region, const void *rgna, const void *rgnb, int op);
    size_t SkRegion_writeToMemory(void *region, void *buffer);
    size_t SkRegion_readFromMemory(void *region, const void *buffer, size_t length);
    // ## sk_rsx_form
    void SkRSXform_delete(void *rsx_form);
    bool SkRSXform_rectStaysRect(void *rsx_form);
    void SkRSXform_setIdentity(void *rsx_form);
    void SkRSXform_set(void *rsx_form, float scos, float ssin, float tx, float ty);
    void SkRSXform_toQuad(void *rsx_form, float width, float height, void *quad);
    void SkRSXform_toQuad_2(void *rsx_form, const void *size, void *quad);
    void SkRSXform_toTriStrip(void *rsx_form, float width, float height, void *strip);
    int SkRSXform_Make(float scos, float ssin, float tx, float ty);
    int SkRSXform_MakeFromRadians(float scale, float radians, float tx, float ty, float ax, float ay);
    // ## sk_runtime_blend_builder
    void *SkRuntimeBlendBuilder_new(int runtime_effect);
    void SkRuntimeBlendBuilder_delete(void *runtime_blend_builder);
    int SkRuntimeBlendBuilder_makeBlender(void *runtime_blend_builder);
    const void * SkRuntimeBlendBuilder_effect(void *runtime_blend_builder);
    int SkRuntimeBlendBuilder_uniform(void *runtime_blend_builder, int name);
    int SkRuntimeBlendBuilder_child(void *runtime_blend_builder, int name);
    int SkRuntimeBlendBuilder_uniforms(void *runtime_blend_builder);
    int SkRuntimeBlendBuilder_children(void *runtime_blend_builder);
    // ## sk_runtime_color_filter_builder
    void *SkRuntimeColorFilterBuilder_new(int runtime_effect);
    void SkRuntimeColorFilterBuilder_delete(void *runtime_color_filter_builder);
    int SkRuntimeColorFilterBuilder_makeColorFilter(void *runtime_color_filter_builder);
    const void * SkRuntimeColorFilterBuilder_effect(void *runtime_color_filter_builder);
    int SkRuntimeColorFilterBuilder_uniform(void *runtime_color_filter_builder, int name);
    int SkRuntimeColorFilterBuilder_child(void *runtime_color_filter_builder, int name);
    int SkRuntimeColorFilterBuilder_uniforms(void *runtime_color_filter_builder);
    int SkRuntimeColorFilterBuilder_children(void *runtime_color_filter_builder);
    // ## sk_runtime_effect
    void SkRuntimeEffect_delete(void *runtime_effect);
    int SkRuntimeEffect_makeShader(void *runtime_effect, int data, void *children, size_t childCount, const void *localMatrix);
    int SkRuntimeEffect_makeShader_2(void *runtime_effect, int data, int runtime_effect_child_ptr, const void *localMatrix);
    int SkRuntimeEffect_makeColorFilter(void *runtime_effect, int data);
    int SkRuntimeEffect_makeColorFilter_2(void *runtime_effect, int data, void *children, size_t childCount);
    int SkRuntimeEffect_makeColorFilter_3(void *runtime_effect, int data, int runtime_effect_child_ptr);
    int SkRuntimeEffect_makeBlender(void *runtime_effect, int data, int runtime_effect_child_ptr);
    const void * SkRuntimeEffect_source(void *runtime_effect);
    size_t SkRuntimeEffect_uniformSize(void *runtime_effect);
    int SkRuntimeEffect_uniforms(void *runtime_effect);
    int SkRuntimeEffect_children(void *runtime_effect);
    const void * SkRuntimeEffect_findUniform(void *runtime_effect, int name);
    const void * SkRuntimeEffect_findChild(void *runtime_effect, int name);
    bool SkRuntimeEffect_allowShader(void *runtime_effect);
    bool SkRuntimeEffect_allowColorFilter(void *runtime_effect);
    bool SkRuntimeEffect_allowBlender(void *runtime_effect);
    bool SkRuntimeEffect_unique(void *runtime_effect);
    void SkRuntimeEffect_ref(void *runtime_effect);
    void SkRuntimeEffect_unref(void *runtime_effect);
    int SkRuntimeEffect_MakeForColorFilter(int string, const void *options);
    int SkRuntimeEffect_MakeForColorFilter_2(int string);
    int SkRuntimeEffect_MakeForShader(int string, const void *options);
    int SkRuntimeEffect_MakeForShader_2(int string);
    int SkRuntimeEffect_MakeForBlender(int string, const void *options);
    int SkRuntimeEffect_MakeForBlender_2(int string);
    int SkRuntimeEffect_MakeTraced(int shader, const void *traceCoord);
    // ## sk_runtime_effect_builder
    void SkRuntimeEffectBuilder_delete(void *runtime_effect_builder);
    const void * SkRuntimeEffectBuilder_effect(void *runtime_effect_builder);
    int SkRuntimeEffectBuilder_uniform(void *runtime_effect_builder, int name);
    int SkRuntimeEffectBuilder_child(void *runtime_effect_builder, int name);
    int SkRuntimeEffectBuilder_uniforms(void *runtime_effect_builder);
    int SkRuntimeEffectBuilder_children(void *runtime_effect_builder);
    // ## sk_runtime_shader_builder
    void *SkRuntimeShaderBuilder_new(int runtime_effect);
    void *SkRuntimeShaderBuilder_new_2(const void *builder);
    void SkRuntimeShaderBuilder_delete(void *runtime_shader_builder);
    int SkRuntimeShaderBuilder_makeShader(void *runtime_shader_builder, const void *localMatrix);
    const void * SkRuntimeShaderBuilder_effect(void *runtime_shader_builder);
    int SkRuntimeShaderBuilder_uniform(void *runtime_shader_builder, int name);
    int SkRuntimeShaderBuilder_child(void *runtime_shader_builder, int name);
    int SkRuntimeShaderBuilder_uniforms(void *runtime_shader_builder);
    int SkRuntimeShaderBuilder_children(void *runtime_shader_builder);
    // ## sk_sampling_options
    void *SkSamplingOptions_new();
    void *SkSamplingOptions_new_2(const void *options);
    void *SkSamplingOptions_new_3(int fm, int mm);
    void *SkSamplingOptions_new_4(int fm);
    void *SkSamplingOptions_new_5(const void *c);
    void SkSamplingOptions_delete(void *sampling_options);
    bool SkSamplingOptions_isAniso(void *sampling_options);
    int SkSamplingOptions_Aniso(int maxAniso);
    // ## sk_shader
    void SkShader_delete(void *shader);
    bool SkShader_isOpaque(void *shader);
    void * SkShader_isAImage(void *shader, void *localMatrix, void *xy);
    bool SkShader_isAImage_2(void *shader);
    int SkShader_makeWithLocalMatrix(void *shader, const void *matrix);
    int SkShader_makeWithColorFilter(void *shader, int color_filter);
    int SkShader_makeWithWorkingColorSpace(void *shader, int color_space);
    int SkShader_getFactory(void *shader);
    const char * SkShader_getTypeName(void *shader);
    void SkShader_flatten(void *shader, void *buffer);
    int SkShader_getFlattenableType(void *shader);
    int SkShader_serialize(void *shader, const void *procs);
    size_t SkShader_serialize_2(void *shader, void *memory, size_t memory_size, const void *procs);
    bool SkShader_unique(void *shader);
    void SkShader_ref(void *shader);
    void SkShader_unref(void *shader);
    int SkShader_NameToFactory(const char name[]);
    const char * SkShader_FactoryToName(int factory);
    void SkShader_Register(const char name[], int factory);
    int SkShader_Deserialize(int type, const void *data, size_t length, const void *procs);
    // ## sk_shader_mask_filter
    void SkShaderMaskFilter_delete(void *shaderMaskFilter);
    int SkShaderMaskFilter_Make(int shader);
    // ## sk_shaders
    int SkShaders_Empty();
    int SkShaders_Color(uint32_t color);
    int SkShaders_Color_2(const void *color4f, int color_space);
    int SkShaders_Blend(int mode, int dst, int src);
    int SkShaders_Blend_2(int value, int dst, int src);
    int SkShaders_CoordClamp(int shader, const void *subset);
    // ## sk_shaper
    void SkShaper_delete(void *shaper);
    void SkShaper_shape(void *shaper, const char *utf8, size_t utf8Bytes, const void *srcFont, bool leftToRight, float width, void *handler);
    void SkShaper_shape_2(void *shaper, const char *utf8, size_t utf8Bytes, void *font, void *bidi, void *script, void *language, float width, void *handler);
    void SkShaper_shape_3(void *shaper, const char *utf8, size_t utf8Bytes, void *font, void *bidi, void *script, void *language, const void *features, size_t featuresSize, float width, void *handler);
    int SkShaper_MakePrimitive();
    int SkShaper_Make(int font_mgr);
    void SkShaper_PurgeCaches();
    int SkShaper_MakeFontMgrRunIterator(const char *utf8, size_t utf8Bytes, const void *font, int font_mgr);
    int SkShaper_MakeFontMgrRunIterator_2(const char *utf8, size_t utf8Bytes, const void *font, int font_mgr, const char *requestName, int requestStyle, const void *language_run_iterator);
    int SkShaper_MakeBiDiRunIterator(const char *utf8, size_t utf8Bytes, uint8_t bidiLevel);
    int SkShaper_MakeScriptRunIterator(const char *utf8, size_t utf8Bytes, uint32_t script);
    int SkShaper_MakeStdLanguageRunIterator(const char *utf8, size_t utf8Bytes);
    // ## sk_size
    void SkSize_delete(void *size);
    void SkSize_set(void *size, float w, float h);
    bool SkSize_isZero(void *size);
    bool SkSize_isEmpty(void *size);
    void SkSize_setEmpty(void *size);
    float SkSize_width(void *size);
    float SkSize_height(void *size);
    bool SkSize_equals(void *size, float w, float h);
    int SkSize_toRound(void *size);
    int SkSize_toCeil(void *size);
    int SkSize_toFloor(void *size);
    int SkSize_Make(float w, float h);
    int SkSize_Make_2(const void *src);
    int SkSize_MakeEmpty();
    // ## sk_stream
    void SkStream_delete(void *stream);
    size_t SkStream_read(void *stream, void *buffer, size_t size);
    size_t SkStream_skip(void *stream, size_t size);
    size_t SkStream_peek(void *stream, void *buffer, size_t size);
    bool SkStream_isAtEnd(void *stream);
    bool SkStream_readS8(void *stream, int8_t *i);
    bool SkStream_readS16(void *stream, int16_t *i);
    bool SkStream_readS32(void *stream, int32_t *i);
    bool SkStream_readU8(void *stream, uint8_t *i);
    bool SkStream_readU16(void *stream, uint16_t *i);
    bool SkStream_readU32(void *stream, uint32_t *i);
    bool SkStream_readBool(void *stream, bool *b);
    bool SkStream_readScalar(void *stream, float *v);
    bool SkStream_readPackedUInt(void *stream, size_t *size);
    bool SkStream_rewind(void *stream);
    int SkStream_duplicate(void *stream);
    int SkStream_fork(void *stream);
    bool SkStream_hasPosition(void *stream);
    size_t SkStream_getPosition(void *stream);
    bool SkStream_seek(void *stream, size_t size);
    bool SkStream_move(void *stream, long i);
    bool SkStream_hasLength(void *stream);
    size_t SkStream_getLength(void *stream);
    const void * SkStream_getMemoryBase(void *stream);
    int SkStream_MakeFromFile(const char *path);
    // ## sk_stream_asset
    void SkStreamAsset_delete(void *stream_asset);
    bool SkStreamAsset_hasLength(void *stream_asset);
    size_t SkStreamAsset_getLength(void *stream_asset);
    int SkStreamAsset_duplicate(void *stream_asset);
    int SkStreamAsset_fork(void *stream_asset);
    bool SkStreamAsset_hasPosition(void *stream_asset);
    size_t SkStreamAsset_getPosition(void *stream_asset);
    bool SkStreamAsset_seek(void *stream_asset, size_t position);
    bool SkStreamAsset_move(void *stream_asset, long offset);
    bool SkStreamAsset_rewind(void *stream_asset);
    size_t SkStreamAsset_read(void *stream_asset, void *buffer, size_t size);
    size_t SkStreamAsset_skip(void *stream_asset, size_t size);
    size_t SkStreamAsset_peek(void *stream_asset, void *buffer, size_t size);
    bool SkStreamAsset_isAtEnd(void *stream_asset);
    bool SkStreamAsset_readS8(void *stream_asset, int8_t *i) ;
    bool SkStreamAsset_readS16(void *stream_asset, int16_t *i);
    bool SkStreamAsset_readS32(void *stream_asset, int32_t *i);
    bool SkStreamAsset_readU8(void *stream_asset, uint8_t *i);
    bool SkStreamAsset_readU16(void *stream_asset, uint16_t *i);
    bool SkStreamAsset_readU32(void *stream_asset, uint32_t *i);
    bool SkStreamAsset_readBool(void *stream_asset, bool *b);
    bool SkStreamAsset_readScalar(void *stream_asset, void *v);
    bool SkStreamAsset_readPackedUInt(void *stream_asset, size_t *size);
    const void * SkStreamAsset_getMemoryBase(void *stream_asset);
    int SkStreamAsset_MakeFromFile(const char *path);
    // ## sk_stream_memory
    void SkStreamMemory_delete(void *stream_memory);
    const void * SkStreamMemory_getMemoryBase(void *stream_memory);
    int SkStreamMemory_duplicate(void *stream_memory);
    int SkStreamMemory_fork(void *stream_memory);
    bool SkStreamMemory_hasLength(void *stream_memory);
    size_t SkStreamMemory_getLength(void *stream_memory);
    bool SkStreamMemory_hasPosition(void *stream_memory);
    size_t SkStreamMemory_getPosition(void *stream_memory);
    bool SkStreamMemory_seek(void *stream_memory, size_t position);
    bool SkStreamMemory_move(void *stream_memory, long offset);
    bool SkStreamMemory_rewind(void *stream_memory);
    size_t SkStreamMemory_read(void *stream_memory, void *buffer, size_t size);
    size_t SkStreamMemory_skip(void *stream_memory, size_t size);
    size_t SkStreamMemory_peek(void *stream_memory, void *buffer, size_t size);
    bool SkStreamMemory_isAtEnd(void *stream_memory);
    bool SkStreamMemory_readS8(void *stream_memory, int8_t *i);
    bool SkStreamMemory_readS16(void *stream_memory, int16_t *i);
    bool SkStreamMemory_readS32(void *stream_memory, int32_t *i);
    bool SkStreamMemory_readU8(void *stream_memory, uint8_t *i);
    bool SkStreamMemory_readU16(void *stream_memory, uint16_t *i);
    bool SkStreamMemory_readU32(void *stream_memory, uint32_t *i);
    bool SkStreamMemory_readBool(void *stream_memory, bool *b);
    bool SkStreamMemory_readScalar(void *stream_memory, float *v);
    bool SkStreamMemory_readPackedUInt(void *stream_memory, size_t *size);
    int SkStreamMemory_MakeFromFile(const char path[]);
    // ## sk_stream_rewindable
    void SkStreamRewindable_delete(void *stream_rewindable);
    bool SkStreamRewindable_rewind(void *stream_rewindable);
    int SkStreamRewindable_duplicate(void *stream_rewindable);
    size_t SkStreamRewindable_read(void *stream_rewindable, void *buffer, size_t size);
    size_t SkStreamRewindable_skip(void *stream_rewindable, size_t size);
    size_t SkStreamRewindable_peek(void *stream_rewindable, void *buffer, size_t size);
    bool SkStreamRewindable_isAtEnd(void *stream_rewindable);
    bool SkStreamRewindable_readS8(void *stream_rewindable, int8_t *i);
    bool SkStreamRewindable_readS16(void *stream_rewindable, int16_t *i);
    bool SkStreamRewindable_readS32(void *stream_rewindable, int32_t *i);
    bool SkStreamRewindable_readU8(void *stream_rewindable, uint8_t *i);
    bool SkStreamRewindable_readU16(void *stream_rewindable, uint16_t *i);
    bool SkStreamRewindable_readU32(void *stream_rewindable, uint32_t *i);
    bool SkStreamRewindable_readBool(void *stream_rewindable, bool *b);
    bool SkStreamRewindable_readScalar(void *stream_rewindable, float *v);
    bool SkStreamRewindable_readPackedUInt(void *stream_rewindable, size_t *size);
    int SkStreamRewindable_fork(void *stream_rewindable);
    bool SkStreamRewindable_hasPosition(void *stream_rewindable);
    size_t SkStreamRewindable_getPosition(void *stream_rewindable);
    bool SkStreamRewindable_seek(void *stream_rewindable, size_t size);
    bool SkStreamRewindable_move(void *stream_rewindable, long i);
    bool SkStreamRewindable_hasLength(void *stream_rewindable);
    size_t SkStreamRewindable_getLength(void *stream_rewindable);
    const void * SkStreamRewindable_getMemoryBase(void *stream_rewindable);
    int SkStreamRewindable_MakeFromFile(const char path[]);
    // ## sk_stream_seekable
    void SkStreamSeekable_delete(void *stream_seekable);
    int SkStreamSeekable_duplicate(void *stream_seekable);
    bool SkStreamSeekable_hasPosition(void *stream_seekable);
    size_t SkStreamSeekable_getPosition(void *stream_seekable);
    bool SkStreamSeekable_seek(void *stream_seekable, size_t position);
    bool SkStreamSeekable_move(void *stream_seekable, long offset);
    int SkStreamSeekable_fork(void *stream_seekable);
    bool SkStreamSeekable_rewind(void *stream_seekable);
    size_t SkStreamSeekable_read(void *stream_seekable, void *buffer, size_t size);
    size_t SkStreamSeekable_skip(void *stream_seekable, size_t size);
    size_t SkStreamSeekable_peek(void *stream_seekable, void *buffer, size_t size);
    bool SkStreamSeekable_isAtEnd(void *stream_seekable);
    bool SkStreamSeekable_readS8(void *stream_seekable, int8_t *i);
    bool SkStreamSeekable_readS16(void *stream_seekable, int16_t *i);
    bool SkStreamSeekable_readS32(void *stream_seekable, int32_t *i);
    bool SkStreamSeekable_readU8(void *stream_seekable, uint8_t *i);
    bool SkStreamSeekable_readU16(void *stream_seekable, uint16_t *i);
    bool SkStreamSeekable_readU32(void *stream_seekable, uint32_t *i);
    bool SkStreamSeekable_readBool(void *stream_seekable, bool *b);
    bool SkStreamSeekable_readScalar(void *stream_seekable, float *v);
    bool SkStreamSeekable_readPackedUInt(void *stream_seekable, size_t *size);
    bool SkStreamSeekable_hasLength(void *stream_seekable);
    size_t SkStreamSeekable_getLength(void *stream_seekable);
    const void * SkStreamSeekable_getMemoryBase(void *stream_seekable);
    int SkStreamSeekable_MakeFromFile(const char path[]);
    // ## sk_string
    void *SkString_new();
    void *SkString_new_2(size_t len);
    void *SkString_new_3(const char text[]);
    void *SkString_new_4(const char text[], size_t len);
    void *SkString_new_5(const void *str);
    void *SkString_new_6(const void *str);
    void *SkString_new_7(int view);
    void SkString_delete(void *string);
    bool SkString_isEmpty(void *string);
    size_t SkString_size(void *string);
    const char * SkString_data(void *string);
    char * SkString_data_2(void *string);
    const char * SkString_c_str(void *string);
    bool SkString_equals(void *string, const void *str);
    bool SkString_equals_2(void *string, const char text[]);
    bool SkString_equals_3(void *string, const char text[], size_t len);
    bool SkString_startsWith(void *string, const char prefixStr[]);
    bool SkString_startsWith_2(void *string, char prefixChar);
    bool SkString_contains(void *string, const char substring[]);
    bool SkString_contains_2(void *string, char subchar);
    int SkString_find(void *string, const char substring[]);
    int SkString_findLastOf(void *string, char subchar);
    void SkString_reset(void *string);
    void SkString_resize(void *string, size_t len);
    void SkString_set(void *string, const void *src);
    void SkString_set_2(void *string, const char text[]);
    void SkString_set_3(void *string, const char text[], size_t len);
    void SkString_set_4(void *string, int str);
    void SkString_insert(void *string, size_t offset, const char text[]);
    void SkString_insert_2(void *string, size_t offset, const char text[], size_t len);
    void SkString_insert_3(void *string, size_t offset, const void *str);
    void SkString_insert_4(void *string, size_t offset, int str);
    void SkString_insertUnichar(void *string, size_t offset, int32_t unichar);
    void SkString_insertS32(void *string, size_t offset, int32_t value);
    void SkString_insertS64(void *string, size_t offset, int64_t value, int minDigits);
    void SkString_insertU32(void *string, size_t offset, uint32_t value);
    void SkString_insertU64(void *string, size_t offset, uint64_t value, int minDigits);
    void SkString_insertHex(void *string, size_t offset, uint32_t value, int minDigits);
    void SkString_insertScalar(void *string, size_t offset, float v);
    void SkString_append(void *string, const char text[]);
    void SkString_append_2(void *string, const char text[], size_t len);
    void SkString_append_3(void *string, const void *str);
    void SkString_append_4(void *string, int str);
    void SkString_appendUnichar(void *string, int32_t uni);
    void SkString_appendS32(void *string, int32_t value);
    void SkString_appendS64(void *string, int64_t value, int minDigits);
    void SkString_appendU32(void *string, uint32_t value);
    void SkString_appendU64(void *string, uint64_t value, int minDigits);
    void SkString_appendHex(void *string, uint32_t value, int minDigits);
    void SkString_appendScalar(void *string, float value);
    void SkString_prepend(void *string, const char text[]);
    void SkString_prepend_2(void *string, const char text[], size_t len);
    void SkString_prepend_3(void *string, const void *str);
    void SkString_prepend_4(void *string, int str);
    void SkString_prependUnichar(void *string, int32_t uni);
    void SkString_prependS32(void *string, int32_t value);
    void SkString_prependS64(void *string, int32_t value, int minDigits);
    void SkString_prependHex(void *string, uint32_t value, int minDigits);
    void SkString_prependScalar(void *string, float value);
    void SkString_remove(void *string, size_t offset, size_t length);
    void SkString_swap(void *string, void *other);
    // ## sk_stroke_rec
    void SkStrokeRec_delete(void *stroke_rec);
    int SkStrokeRec_static(int style);
    int SkStrokeRec_static_2(const void *paint, int style, float resScale);
    int SkStrokeRec_static_3(const void *paint, float resScale);
    int SkStrokeRec_getStyle(void *stroke_rec);
    float SkStrokeRec_getWidth(void *stroke_rec);
    float SkStrokeRec_getMiter(void *stroke_rec);
    int SkStrokeRec_getCap(void *stroke_rec);
    int SkStrokeRec_getJoin(void *stroke_rec);
    bool SkStrokeRec_isHairlineStyle(void *stroke_rec);
    bool SkStrokeRec_isFillStyle(void *stroke_rec);
    void SkStrokeRec_setFillStyle(void *stroke_rec);
    void SkStrokeRec_setHairlineStyle(void *stroke_rec);
    void SkStrokeRec_setStrokeStyle(void *stroke_rec, float width, bool strokeAndFill);
    void SkStrokeRec_setStrokeParams(void *stroke_rec, int cap, int join, float miterLimit);
    float SkStrokeRec_getResScale(void *stroke_rec);
    void SkStrokeRec_setResScale(void *stroke_rec, float rs);
    bool SkStrokeRec_needToApply(void *stroke_rec);
    bool SkStrokeRec_applyToPath(void *stroke_rec, void *dst, const void *src);
    void SkStrokeRec_applyToPaint(void *stroke_rec, void *paint);
    float SkStrokeRec_getInflationRadius(void *stroke_rec);
    bool SkStrokeRec_hasEqualEffect(void *stroke_rec, const void *other);
    float SkStrokeRec_GetInflationRadius(const void *paint, int style);
    float SkStrokeRec_GetInflationRadius_2(int join, float miterLimit, int cap, float strokeWidth);
    // ## sk_surface
    void SkSurface_delete(void *surface);
    bool SkSurface_isCompatible(void *surface, const void *characterization);
    int SkSurface_width(void *surface);
    int SkSurface_height(void *surface);
    int SkSurface_imageInfo(void *surface);
    uint32_t SkSurface_generationID(void *surface);
    void SkSurface_notifyContentWillChange(void *surface, int mode);
    void * SkSurface_recordingContext(void *surface);
    void * SkSurface_recorder(void *surface);
    bool SkSurface_replaceBackendTexture(void *surface, const void *backendTexture, int origin, int mode, void(*proc)(void *), void *context);
    void * SkSurface_getCanvas(void *surface);
    int SkSurface_capabilities(void *surface);
    int SkSurface_makeSurface(void *surface, const void *imageInfo);
    int SkSurface_makeSurface_2(void *surface, int width, int height);
    int SkSurface_makeImageSnapshot(void *surface);
    int SkSurface_makeImageSnapshot_2(void *surface, const void *bounds);
    void SkSurface_draw(void *surface, void *canvas, float x, float y, const void *sampling, const void *paint);
    void SkSurface_draw_2(void *surface, void *canvas, float x, float y, const void *paint);
    bool SkSurface_peekPixels(void *surface, void *pixmap);
    bool SkSurface_readPixels(void *surface, const void *dst, int srcX, int srcY);
    bool SkSurface_readPixels_2(void *surface, const void *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
    bool SkSurface_readPixels_3(void *surface, const void *dst, int srcX, int srcY);
    //void SkSurface_asyncRescaleAndReadPixels(void *surface, const void *info, const void *srcRect, bool rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void *context);
    //void SkSurface_asyncRescaleAndReadPixelsYUV420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, bool rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void *context);
    //void SkSurface_asyncRescaleAndReadPixelsYUVA420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, bool rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void *context);
    void SkSurface_writePixels(void *surface, const void *src, int dstX, int dstY);
    void SkSurface_writePixels_2(void *surface, const void *src, int dstX, int dstY);
    const void * SkSurface_props(void *surface);
    bool SkSurface_wait(void *surface, int numSemaphores, const void *waitSemaphores, bool deleteSemaphoresAfterWait);
    bool SkSurface_characterize(void *surface, void *characterization);
    bool SkSurface_unique(void *surface);
    void SkSurface_ref(void *surface);
    void SkSurface_unref(void *surface);
    // ## sk_surface_props
    void *SkSurfaceProps_new();
    void *SkSurfaceProps_new_2(uint32_t flags, int geometry);
    void *SkSurfaceProps_new_3(const void *props);
    void SkSurfaceProps_delete(void *surface_props);
    int SkSurfaceProps_cloneWithPixelGeometry(void *surface_props, int newPixelGeometry);
    uint32_t SkSurfaceProps_flags(void *surface_props);
    int SkSurfaceProps_pixelGeometry(void *surface_props);
    bool SkSurfaceProps_isUseDeviceIndependentFonts(void *surface_props);
    bool SkSurfaceProps_isAlwaysDither(void *surface_props);
    // ## sk_surfaces
    int SkSurfaces_Null(int width, int height);
    int SkSurfaces_Raster(const void *imageInfo, size_t rowBytes, const void *surfaceProps);
    int SkSurfaces_Raster_2(const void *imageInfo, const void *props);
    int SkSurfaces_WrapPixels(const void *imageInfo, void *pixels, size_t rowBytes, const void *surfaceProps);
    int SkSurfaces_WrapPixels_2(const void *pm, const void *props);
    int SkSurfaces_WrapPixels_3(const void *imageInfo, void *pixels, size_t rowBytes,  void(*pixelsReleaseProc)(void *,void *), void *context, const void *surfaceProps);
    // ## sk_svg_attribute_parser
    // ## sk_svg_circle
    // ## sk_svg_clip_path
    // ## sk_svg_color
    // ## sk_svg_container
    // ## sk_svg_dash_array
    // ## sk_svg_defs
    // ## sk_svg_dom
    // ## sk_svg_ellipse
    // ## sk_svg_fe
    // ## sk_svg_fe_blend
    // ## sk_svg_fe_color_matrix
    // ## sk_svg_fe_composite
    // ## sk_svg_fe_diffuse_lighting
    // ## sk_svg_fe_displacement_map
    // ## sk_svg_fe_distant_light
    // ## sk_svg_fe_flood
    // ## sk_svg_fe_gaussian_blur
    // ## sk_svg_fe_image
    // ## sk_svg_fe_input_type
    // ## sk_svg_fe_light_source
    // ## sk_svg_fe_lighting
    // ## sk_svg_fe_morphology
    // ## sk_svg_fe_offset
    // ## sk_svg_fe_point_light
    // ## sk_svg_fe_specular_lighting
    // ## sk_svg_fe_spot_light
    // ## sk_svg_fe_turbulence
    // ## sk_svg_fe_turbulence_base_frequency
    // ## sk_svg_fe_turbulence_type
    // ## sk_svg_fill_rule
    // ## sk_svg_filter
    // ## sk_svg_filter_context
    // ## sk_svg_font_family
    // ## sk_svg_font_size
    // ## sk_svg_font_style
    // ## sk_svg_font_weight
    // ## sk_svg_func_iri
    // ## sk_svg_g
    // ## sk_svg_gradient
    // ## sk_svg_hidden_container
    // ## sk_svg_image
    // ## sk_svg_iri
    // ## sk_svg_length
    // ## sk_svg_length_context
    // ## sk_svg_line
    // ## sk_svg_line_join
    // ## sk_svg_linear_gradient
    // ## sk_svg_mask
    // ## sk_svg_node
    // ## sk_svg_object_bounding_box_units
    // ## sk_svg_open_type_svg_decoder
    // ## sk_svg_paint
    // ## sk_svg_path
    // ## sk_svg_pattern
    // ## sk_svg_poly
    // ## sk_svg_presentation_attributes
    // ## sk_svg_presentation_context
    // ## sk_svg_property
    // ## sk_svg_radial_gradient
    // ## sk_svg_rect
    // ## sk_svg_render_context
    // ## sk_svg_shape
    // ## sk_svg_spread_method
    // ## sk_svg_stop
    // ## sk_svg_stop_color
    // ## sk_svg_svg
    // ## sk_svg_t_span
    // ## sk_svg_text
    // ## sk_svg_text_anchor
    // ## sk_svg_text_container
    // ## sk_svg_text_fragment
    // ## sk_svg_text_literal
    // ## sk_svg_text_path
    // ## sk_svg_transformable_node
    // ## sk_svg_use
    // ## sk_svg_value
    // ## sk_svg_visibility
    // ## sk_svg_wrapper_value
    // ## sk_table_mask_filter
    void SkTableMaskFilter_delete(void *tableMaskFilter);
    void SkTableMaskFilter_MakeGammaTable(uint8_t *table, float gamma);
    void SkTableMaskFilter_MakeClipTable(uint8_t *table, uint8_t min, uint8_t max);
    void *SkTableMaskFilter_Create(const uint8_t *table);
    void *SkTableMaskFilter_CreateGamma(float gamma);
    void *SkTableMaskFilter_CreateClip(uint8_t min, uint8_t max);
    // ## sk_text_blob
    void SkTextBlob_delete(void *text_blob);
    const void * SkTextBlob_bounds(void *text_blob);
    uint32_t SkTextBlob_uniqueID(void *text_blob);
    int SkTextBlob_getIntercepts(void *text_blob, const float *bounds, float *intervals, const void *paint);
    size_t SkTextBlob_serialize(void *text_blob, const void *procs, void *memory, size_t memory_size);
    int SkTextBlob_serialize_2(void *text_blob, const void *procs);
    bool SkTextBlob_unique(void *text_blob);
    void SkTextBlob_ref(void *text_blob);
    void SkTextBlob_unref(void *text_blob);
    void SkTextBlob_deref(void *text_blob);
    bool SkTextBlob_refCntGreaterThan(void *text_blob, int32_t threadIsolatedTestCnt);
    int SkTextBlob_MakeFromText(const void *text, size_t byteLength, const void *font, int encoding);
    int SkTextBlob_MakeFromString(const char *string, const void *font, int encoding);
    int SkTextBlob_MakeFromPosTextH(const void *text, size_t byteLength, const float *xpos, float constY, const void *font, int encoding);
    int SkTextBlob_MakeFromPosText(const void *text, size_t byteLength, const void *pos, const void *font, int encoding);
    int SkTextBlob_MakeFromRSXform(const void *text, size_t byteLength, const void *xform, const void *font, int encoding);
    int SkTextBlob_Deserialize(const void *data, size_t size, const void *procs);
    // ## sk_text_blob_builder
    void *SkTextBlobBuilder_new();
    void SkTextBlobBuilder_delete(void *text_blob_builder);
    int SkTextBlobBuilder_make(void *text_blob_builder);
    const void * SkTextBlobBuilder_allocRun(void *text_blob_builder, const void *font, int count, float x, float y, const void *bounds);
    const void * SkTextBlobBuilder_allocRunPosH(void *text_blob_builder, const void *font, int count, float y, const void *bounds);
    const void * SkTextBlobBuilder_allocRunPos(void *text_blob_builder, const void *font, int count, const void *bounds);
    const void * SkTextBlobBuilder_allocRunRSXform(void *text_blob_builder, const void *font, int count);
    const void * SkTextBlobBuilder_allocRunText(void *text_blob_builder, const void *font, int count, float x, float y, int textByteCount, const void *bounds);
    const void * SkTextBlobBuilder_allocRunTextPosH(void *text_blob_builder, const void *font, int count, float y, int textByteCount, const void *bounds);
    const void * SkTextBlobBuilder_allocRunTextPos(void *text_blob_builder, const void *font, int count, int textByteCount, const void *bounds);
    const void * SkTextBlobBuilder_allocRunTextRSXform(void *text_blob_builder, const void *font, int count, int textByteCount, const void *bounds);
    /*
    // ## sk_text_blob_builder_run_handler
    void *SkTextBlobBuilderRunHandler_new(const char *utf8Text, int offset);
    void SkTextBlobBuilderRunHandler_delete(void *text_blob_builder_run_handler);
    int SkTextBlobBuilderRunHandler_makeBlob(void *text_blob_builder_run_handler);
    int SkTextBlobBuilderRunHandler_endPoint(void *text_blob_builder_run_handler);
    void SkTextBlobBuilderRunHandler_beginLine(void *text_blob_builder_run_handler);
    void SkTextBlobBuilderRunHandler_runInfo(void *text_blob_builder_run_handler, const void *run_info);
    void SkTextBlobBuilderRunHandler_commitRunInfo(void *text_blob_builder_run_handler);
    int SkTextBlobBuilderRunHandler_runBuffer(void *text_blob_builder_run_handler, const void *run_info);
    void SkTextBlobBuilderRunHandler_commitRunBuffer(void *text_blob_builder_run_handler, const void *run_info);
    void SkTextBlobBuilderRunHandler_commitLine(void *text_blob_builder_run_handler);
    */
    // ## sk_tiled_image_utils
    void SkTiledImageUtils_DrawImageRect(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_DrawImageRect_2(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_DrawImageRect_3(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_DrawImageRect_4(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_DrawImage(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_DrawImage_2(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint, int constraint);
    void SkTiledImageUtils_GetImageKeyValues(const void *image, uint32_t *keyValues);
    // ## sk_trace_memory_dump
    void SkTraceMemoryDump_delete(void * traceMemoryDump);
    void SkTraceMemoryDump_dumpNumericValue(void *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value);
    void SkTraceMemoryDump_dumpStringValue(void *trace_memory_dump, const char *dumpName, const char *str1, const char *str2);
    void SkTraceMemoryDump_setMemoryBacking(void *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId);
    void SkTraceMemoryDump_setDiscardableMemoryBacking(void *trace_memory_dump, const char *dumpName, const void *discardableMemoryObject);
    int SkTraceMemoryDump_getRequestedDetails(void *trace_memory_dump);
    bool SkTraceMemoryDump_shouldDumpWrappedObjects(void *trace_memory_dump);
    void SkTraceMemoryDump_dumpWrappedState(void *trace_memory_dump, const char *str, bool b);
    bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(void *trace_memory_dump);
    void SkTraceMemoryDump_dumpBudgetedState(void *trace_memory_dump, const char *str, bool b);
    // ## sk_trim_path_effect
    void SkTrimPathEffect_delete(void * trimPathEffect);
    int SkTrimPathEffect_Make(float startT, float stopT, int mode);
    // ## sk_typeface
    void SkTypeface_delete(void *typeface);
    int SkTypeface_fontStyle(void *typeface);
    bool SkTypeface_isBold(void *typeface);
    bool SkTypeface_isItalic(void *typeface);
    bool SkTypeface_isFixedPitch(void *typeface);
    int SkTypeface_getVariationDesignPosition(void *typeface, void *coordinates, int coordinateCount);
    int SkTypeface_getVariationDesignParameters(void *typeface, void *parameters, int parameterCount);
    uint32_t SkTypeface_uniqueID(void *typeface);
    int SkTypeface_makeClone(void *typeface, const void *arguments);
    void SkTypeface_serialize(void *typeface, void *stream, int behavior);
    int SkTypeface_serialize_2(void *typeface, int behavior);
    void SkTypeface_unicharsToGlyphs(void *typeface, const int32_t *uni, int count, void *glyphs);
    int SkTypeface_textToGlyphs(void *typeface, const void *text, size_t byteLength, int encoding, void *glyphs, int maxGlyphCount);
    uint16_t SkTypeface_unicharToGlyph(void *typeface, int32_t unichar);
    int SkTypeface_countGlyphs(void *typeface);
    int SkTypeface_countTables(void *typeface);
    int SkTypeface_getTableTags(void *typeface, uint32_t *tags);
    size_t SkTypeface_getTableSize(void *typeface, uint32_t tag);
    size_t SkTypeface_getTableData(void *typeface, uint32_t tag, size_t offset, size_t length, void *data);
    int SkTypeface_copyTableData(void *typeface, uint32_t tag);
    int SkTypeface_getUnitsPerEm(void *typeface);
    bool SkTypeface_getKerningPairAdjustments(void *typeface, const void *glyphs, int count, int32_t *adjustments);
    void * SkTypeface_createFamilyNameIterator(void *typeface);
    void SkTypeface_getFamilyName(void *typeface, void *name);
    bool SkTypeface_getPostScriptName(void *typeface, void *name);
    int SkTypeface_openStream(void *typeface, int *ttcIndex);
    int SkTypeface_openExistingStream(void *typeface, int *ttcIndex);
    //std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor);
    int SkTypeface_getBounds(void *typeface);
    void SkTypeface_filterRec(void *typeface, void *rec);
    void SkTypeface_getFontDescriptor(void *typeface, void *desc, bool *isLocal);
    void * SkTypeface_internal_private_getCTFontRef(void *typeface);
    bool SkTypeface_Equal(const void *facea, const void *faceb);
    int SkTypeface_MakeEmpty();
    int SkTypeface_MakeDeserialize(void *stream, int font_mgr);
    //void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &));
    int SkTypeface_MakeDefault();
    int SkTypeface_MakeFromName(const char familyName[], int fontStyle);
    int SkTypeface_MakeFromFile(const char path[], int index);
    int SkTypeface_MakeFromStream(int stream_asset, int index);
    int SkTypeface_MakeFromData(int data, int index);
    int SkTypeface_MakeDeserialize_2(void *stream);
    // ## sk_typeface_mac
    // ## sk_un_pre_multiply
    void SkUnPreMultiply_delete(void * unPreMultiply);
    const void * SkUnPreMultiply_GetScaleTable();
    uint32_t SkUnPreMultiply_GetScale(unsigned int alpha);
    unsigned int SkUnPreMultiply_ApplyScale(uint32_t scale, unsigned int component);
    uint32_t SkUnPreMultiply_PMColorToColor(uint32_t c);
    // ## sk_v2
    void SkV2_delete(void *v2);
    float SkV2_lengthSquared(void *v2);
    float SkV2_length(void *v2);
    float SkV2_dot(void *v2, int v);
    float SkV2_cross(void *v2, int v);
    int SkV2_normalize(void *v2);
    const float * SkV2_ptr(void *v2);
    float * SkV2_ptr_2(void *v2);
    float SkV2_Dot(int a, int b);
    float SkV2_Cross(int a, int b);
    int SkV2_Normalize(int v);
    // ## sk_v3
    void SkV3_delete(void *v3);
    float SkV3_lengthSquared(void *v3);
    float SkV3_length(void *v3);
    float SkV3_dot(void *v3, const void *v);
    int SkV3_cross(void *v3, const void *v);
    int SkV3_normalize(void *v3);
    const float * SkV3_ptr(void *v3);
    float * SkV3_ptr_2(void *v3);
    float SkV3_Dot(const void *a, const void *b);
    int SkV3_Cross(const void *a, const void *b);
    int SkV3_Normalize(const void *v);
    // ## sk_v4
    void SkV4_delete(void *v4);
    float SkV4_lengthSquared(void *v4);
    float SkV4_length(void *v4);
    float SkV4_dot(void *v4, const void *v);
    int SkV4_normalize(void *v4);
    const float * SkV4_ptr(void *v4);
    float * SkV4_ptr_2(void *v4);
    float SkV4_Dot(const void *a, const void *b);
    int SkV4_Normalize(const void *v);
    // ## sk_vertices
    void SkVertices_delete(void * vertices);
    uint32_t SkVertices_uniqueID(void *vertices);
    const void * SkVertices_bounds(void *vertices);
    size_t SkVertices_approximateSize(void *vertices);
    bool SkVertices_unique(void *vertices);
    void SkVertices_ref(void *vertices);
    void SkVertices_unref(void *vertices);
    void SkVertices_deref(void *vertices);
    bool SkVertices_refCntGreaterThan(void *vertices, int32_t threadIsolatedTestCnt);
    int SkVertices_MakeCopy(int mode, int vertexCount, const void *positions, const void *texs, const void *colors, int indexCount, const uint16_t *indices);
    int SkVertices_MakeCopy_2(int mode, int vertexCount, const void *positions, const void *texs, const void *colors);
    // ## sk_w_stream
    void SkWStream_delete(void *w_stream);
    bool SkWStream_write(void *w_stream, const void *buffer, size_t size);
    void SkWStream_flush(void *w_stream);
    size_t SkWStream_bytesWritten(void *w_stream);
    bool SkWStream_write8(void *w_stream, unsigned int value);
    bool SkWStream_write16(void *w_stream, unsigned int value);
    bool SkWStream_write32(void *w_stream, uint32_t v);
    bool SkWStream_writeText(void *w_stream, const char text[]);
    bool SkWStream_newline(void *w_stream);
    bool SkWStream_writeDecAsText(void *w_stream, int32_t i);
    bool SkWStream_writeBigDecAsText(void *w_stream, int64_t i, int minDigits);
    bool SkWStream_writeHexAsText(void *w_stream, uint32_t i, int minDigits);
    bool SkWStream_writeScalarAsText(void *w_stream, float v);
    bool SkWStream_writeBool(void *w_stream, bool v);
    bool SkWStream_writeScalar(void *w_stream, float v);
    bool SkWStream_writePackedUInt(void *w_stream, size_t size);
    bool SkWStream_writeStream(void *w_stream, void *input, size_t length);
    int SkWStream_SizeOfPackedUInt(size_t value);
    // ## sk_wbmp_decoder
    bool SkWbmpDecoder_IsWbmp(const void* ptr, size_t size);
    int SkWbmpDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkWbmpDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkWbmpDecoder_Decoder();
    // ## sk_webp_decoder
    bool SkWebpDecoder_IsWbmp(const void* ptr, size_t size);
    int SkWebpDecoder_Decode(int static_stream, void *result, void *decodeContext);
    int SkWebpDecoder_Decode_2(int static_data, void *result, void *decodeContext);
    int SkWebpDecoder_Decoder();
    /*
    // ## sk_webp_encoder
    bool SkWebpEncoder_Encode(void *dst, const void *src, const void *options);
    int SkWebpEncoder_Encode_2(void *ctx, const void *img, const void *options);
    bool SkWebpEncoder_EncodeAnimated(void *dst, int encoderFrame, const void *options);
    */
    // ## sk_yuva_info
    void *SkYUVAInfo_new();
    void *SkYUVAInfo_new_2(const void *info);
    void *SkYUVAInfo_new_3(int dimensions, int config, int subsampling, int space, int origin, int sitingX, int sitingY);
    void SkYUVAInfo_delete(void *yuvaInfo);
    int SkYUVAInfo_planeConfig(void * yuva_info);
    int SkYUVAInfo_subsampling(void * yuva_info);
    int SkYUVAInfo_planeSubsamplingFactors(void * yuva_info, int planeIdx);
    int SkYUVAInfo_dimensions(void * yuva_info);
    int SkYUVAInfo_width(void * yuva_info);
    int SkYUVAInfo_height(void * yuva_info);
    int SkYUVAInfo_yuvColorSpace(void * yuva_info);
    int SkYUVAInfo_sitingX(void * yuva_info);
    int SkYUVAInfo_sitingY(void * yuva_info);
    int SkYUVAInfo_origin(void * yuva_info);
    int SkYUVAInfo_originMatrix(void * yuva_info);
    bool SkYUVAInfo_hasAlpha(void * yuva_info);
    int SkYUVAInfo_planeDimensions(void * yuva_info, void *planeDimensions);
    size_t SkYUVAInfo_computeTotalBytes(void * yuva_info, const size_t *rowBytes, size_t *planeSizes);
    int SkYUVAInfo_numPlanes(void * yuva_info);
    int SkYUVAInfo_numChannelsInPlane(void * yuva_info, int i);
    int SkYUVAInfo_makeSubsampling(void * yuva_info, int subsampling);
    int SkYUVAInfo_makeDimensions(void * yuva_info, int size);
    bool SkYUVAInfo_isValid(void * yuva_info);
    int SkYUVAInfo_SubsamplingFactors(int subsampling);
    int SkYUVAInfo_PlaneSubsamplingFactors(int config, int subsampling, int planeIdx);
    int SkYUVAInfo_PlaneDimensions(int imageDimensions, int plane, int subsampling, int origin, void *planeDimensions);
    int SkYUVAInfo_NumPlanes(int config);
    int SkYUVAInfo_NumChannelsInPlane(int config, int i);
    bool SkYUVAInfo_HasAlpha(int config);
    // ## sk_yuva_pixmap_info
    void *SkYUVAPixmapInfo_new();
    void *SkYUVAPixmapInfo_new_2(const void *info, const void *type, const size_t *rowBytes);
    void *SkYUVAPixmapInfo_new_3(const void *info, int type, const size_t *rowBytes);
    void *SkYUVAPixmapInfo_new_4(const void *info);
    void SkYUVAPixmapInfo_delete(void *yuvaPixmapInfo);
    const void * SkYUVAPixmapInfo_yuvaInfo(void *yuva_pixmap_info);
    int SkYUVAPixmapInfo_yuvColorSpace(void *yuva_pixmap_info);
    int SkYUVAPixmapInfo_numPlanes(void *yuva_pixmap_info);
    int SkYUVAPixmapInfo_dataType(void *yuva_pixmap_info);
    size_t SkYUVAPixmapInfo_rowBytes(void *yuva_pixmap_info, int i);
    const void * SkYUVAPixmapInfo_planeInfo(void *yuva_pixmap_info, int i);
    size_t SkYUVAPixmapInfo_computeTotalBytes(void *yuva_pixmap_info, size_t *planeSizes);
    bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(void *yuva_pixmap_info, void *memory, void *pixmaps);
    bool SkYUVAPixmapInfo_isValid(void *yuva_pixmap_info);
    bool SkYUVAPixmapInfo_isSupported(void *yuva_pixmap_info, const void *type);
    int SkYUVAPixmapInfo_DefaultColorTypeForDataType(int dataType, int numChannels);
    int SkYUVAPixmapInfo_NumChannelsAndDataType(int type);
    // ## sk_yuva_pixmaps
    void *SkYUVAPixmaps_new();
    void *SkYUVAPixmaps_new_2(const void *pixmaps);
    void SkYUVAPixmaps_delete(void *yuva_pixmaps);
    bool SkYUVAPixmaps_isValid(void *yuva_pixmaps);
    const void * SkYUVAPixmaps_yuvaInfo(void *yuva_pixmaps);
    int SkYUVAPixmaps_dataType(void *yuva_pixmaps);
    int SkYUVAPixmaps_pixmapsInfo(void *yuva_pixmaps);
    int SkYUVAPixmaps_numPlanes(void *yuva_pixmaps);
    const void * SkYUVAPixmaps_planes(void *yuva_pixmaps);
    const void * SkYUVAPixmaps_plane(void *yuva_pixmaps, int i);
    bool SkYUVAPixmaps_ownsStorage(void *yuva_pixmaps);
    int SkYUVAPixmaps_RecommendedRGBAColorType(int type);
    int SkYUVAPixmaps_Allocate(const void *yuvaPixmapInfo);
    int SkYUVAPixmaps_FromData(const void *yuvaPixmapInfo, int data);
    int SkYUVAPixmaps_MakeCopy(const void *src);
    int SkYUVAPixmaps_FromExternalMemory(const void *yuvaPixmapInfo, void *memory);
    int SkYUVAPixmaps_FromExternalPixmaps(const void *yuvaInfo, const void *pixmaps);
    // ## skottie_animation
    //
]]

local lib = ffi.load("libreskia")
local Skia = {}

-- # static
Skia.Static = {}

-- void static_sk_flattenable_factory_delete(int key);
-- void static_sk_font_arguments_palette_delete(int key);
-- void static_sk_font_arguments_variation_position_delete(int key);
-- void static_sk_i_point_delete(int key);
-- void static_sk_i_size_delete(int key);
-- void static_sk_image_required_properties_delete(int key);
-- void static_sk_point_delete(int key);
-- void static_sk_point_3_delete(int key);
-- void static_sk_rsx_form_delete(int key);
-- void static_sk_runtime_effect_builder_builder_child_delete(int key);
-- void static_sk_runtime_effect_builder_builder_uniform_delete(int key);
-- void static_sk_shaper_run_handler_buffer_delete(int key);
-- void static_sk_size_delete(int key);
-- void static_sk_v2_delete(int key);
-- void static_sk_v3_delete(int key);
-- void static_sk_v4_delete(int key);
-- void static_chrono_milliseconds_delete(int key);

--[[

function Skia.Static.deleteGrBackendFormat(key)
    lib.static_gr_backend_format_delete(key)
end

function Skia.Static.deleteGrBackendTexture(key)
    lib.static_gr_backend_texture_delete(key)
end

function Skia.Static.deleteGrColorFormatDesc(key)
    lib.static_gr_color_format_desc_delete(key)
end

function Skia.Static.deleteGrContextThreadSafeProxy(key)
    lib.static_gr_context_thread_safe_proxy_delete(key)
end

function Skia.Static.getGrContextThreadSafeProxy(key)
    return lib.static_gr_context_thread_safe_proxy_get(key)
end

function Skia.Static.deleteGrDirectContext(key)
    lib.static_gr_direct_context_delete(key)
end

function Skia.Static.getGrDirectContext(key)
    return lib.static_gr_direct_context_get(key)
end

function Skia.Static.deleteGrDirectContextDirectContextId(key)
    lib.static_gr_direct_context_direct_context_id_delete(key)
end

]]

function Skia.Static.deleteSkAndroidCodec(key)
    lib.static_sk_android_codec_delete(key)
end

function Skia.Static.getSkAndroidCodec(key)
    return lib.static_sk_android_codec_get(key)
end

function Skia.Static.deleteSkBBoxHierarchy(key)
    lib.static_sk_b_box_hierarchy_delete(key)
end

function Skia.Static.getSkBBoxHierarchy(key)
    return lib.static_sk_b_box_hierarchy_get(key)
end

function Skia.Static.deleteOptionalSkBlendMode(key)
    lib.static_optional_sk_blend_mode_delete(key)
end

function Skia.Static.deleteSkBlender(key)
    lib.static_sk_blender_delete(key)
end

function Skia.Static.getSkBlender(key)
    return lib.static_sk_blender_get(key)
end

function Skia.Static.deleteSkCanvas(key)
    lib.static_sk_canvas_delete(key)
end

function Skia.Static.getSkCanvas(key)
    return lib.static_sk_canvas_get(key)
end

function Skia.Static.deleteConstSkCapabilities(key)
    lib.static_const_sk_capabilities_delete(key)
end

function Skia.Static.getConstSkCapabilities(key)
    return lib.static_const_sk_capabilities_get(key)
end

function Skia.Static.deleteSkCodec(key)
    lib.static_sk_codec_delete(key)
end

function Skia.Static.getSkCodec(key)
    return lib.static_sk_codec_get(key)
end

function Skia.Static.deleteSkCodecsDecoder(key)
    lib.static_sk_codecs_decoder_delete(key)
end

function Skia.Static.deleteSkColor(key)
    lib.static_sk_color_delete(key)
end

function Skia.Static.deleteSkColor4f(key)
    lib.static_sk_color_4f_delete(key)
end

function Skia.Static.deleteSkColorFilter(key)
    lib.static_sk_color_filter_delete(key)
end

function Skia.Static.getSkColorFilter(key)
    return lib.static_sk_color_filter_get(key)
end

function Skia.Static.deleteSkColorInfo(key)
    lib.static_sk_color_info_delete(key)
end

function Skia.Static.deleteSkColorMatrix(key)
    lib.static_sk_color_matrix_delete(key)
end

function Skia.Static.deleteSkColorSpace(key)
    lib.static_sk_color_space_delete(key)
end

function Skia.Static.getSkColorSpace(key)
    return lib.static_sk_color_space_get(key)
end

function Skia.Static.deleteSkColorTable(key)
    lib.static_sk_color_table_delete(key)
end

function Skia.Static.getSkColorTable(key)
    return lib.static_sk_color_table_get(key)
end

function Skia.Static.deleteSkContourMeasure(key)
    lib.static_sk_contour_measure_delete(key)
end

function Skia.Static.getSkContourMeasure(key)
    return lib.static_sk_contour_measure_get(key)
end

function Skia.Static.deleteSkCubicResampler(key)
    lib.static_sk_cubic_resampler_delete(key)
end

function Skia.Static.deleteSkData(key)
    lib.static_sk_data_delete(key)
end

function Skia.Static.getSkData(key)
    return lib.static_sk_data_get(key)
end

function Skia.Static.deleteConstSkData(key)
    lib.static_const_sk_data_delete(key)
end

function Skia.Static.getConstSkData(key)
    return lib.static_const_sk_data_get(key)
end

function Skia.Static.deleteSkDataTable(key)
    lib.static_sk_data_table_delete(key)
end

function Skia.Static.getSkDataTable(key)
    return lib.static_sk_data_table_get(key)
end

function Skia.Static.deleteSkDocument(key)
    lib.static_sk_document_delete(key)
end

function Skia.Static.getSkDocument(key)
    return lib.static_sk_document_get(key)
end

function Skia.Static.deleteSkDrawable(key)
    lib.static_sk_drawable_delete(key)
end

function Skia.Static.getSkDrawable(key)
    return lib.static_sk_drawable_get(key)
end

function Skia.Static.deleteSkDrawableGpuDrawHandler(key)
    lib.static_sk_drawable_gpu_draw_handler_delete(key)
end

function Skia.Static.getSkDrawableGpuDrawHandler(key)
    return lib.static_sk_drawable_gpu_draw_handler_get(key)
end

function Skia.Static.deleteSkEncoder(key)
    lib.static_sk_encoder_delete(key)
end

function Skia.Static.getSkEncoder(key)
    return lib.static_sk_encoder_get(key)
end

function Skia.Static.deleteConstSkEncoderFrame(key)
    lib.static_const_sk_encoder_frame_delete(key)
end

function Skia.Static.deleteSkExecutor(key)
    lib.static_sk_executor_delete(key)
end

function Skia.Static.getSkExecutor(key)
    return lib.static_sk_executor_get(key)
end

function Skia.Static.deleteSkFileStream(key)
    lib.static_sk_file_stream_delete(key)
end

function Skia.Static.getSkFileStream(key)
    return lib.static_sk_file_stream_get(key)
end

function Skia.Static.deleteSkFlattenable(key)
    lib.static_sk_flattenable_delete(key)
end

function Skia.Static.getSkFlattenable(key)
    return lib.static_sk_flattenable_get(key)
end

function Skia.Static.deleteSkFont(key)
    lib.static_sk_font_delete(key)
end

function Skia.Static.deleteSkFontArguments(key)
    lib.static_sk_font_arguments_delete(key)
end

function Skia.Static.deleteSkFontMgr(key)
    lib.static_sk_font_mgr_delete(key)
end

function Skia.Static.getSkFontMgr(key)
    return lib.static_sk_font_mgr_get(key)
end

function Skia.Static.deleteSkFontStyle(key)
    lib.static_sk_font_style_delete(key)
end

function Skia.Static.deleteSkFontStyleSet(key)
    lib.static_sk_font_style_set_delete(key)
end

function Skia.Static.getSkFontStyleSet(key)
    return lib.static_sk_font_style_set_get(key)
end

function Skia.Static.deleteSkIRect(key)
    lib.static_sk_i_rect_delete(key)
end

function Skia.Static.deleteSkIdChangeListener(key)
    lib.static_sk_id_change_listener_delete(key)
end

function Skia.Static.getSkIdChangeListener(key)
    return lib.static_sk_id_change_listener_get(key)
end

function Skia.Static.deleteSkImage(key)
    lib.static_sk_image_delete(key)
end

function Skia.Static.getSkImage(key)
    return lib.static_sk_image_get(key)
end

function Skia.Static.deleteSkImageFilter(key)
    lib.static_sk_image_filter_delete(key)
end

function Skia.Static.getSkImageFilter(key)
    return lib.static_sk_image_filter_get(key)
end

function Skia.Static.deleteSkImageGenerator(key)
    lib.static_sk_image_generator_delete(key)
end

function Skia.Static.getSkImageGenerator(key)
    return lib.static_sk_image_generator_get(key)
end

function Skia.Static.deleteSkImageInfo(key)
    lib.static_sk_image_info_delete(key)
end

function Skia.Static.deleteSkM44(key)
    lib.static_sk_m_44_delete(key)
end

function Skia.Static.deleteSkMaskFilter(key)
    lib.static_sk_mask_filter_delete(key)
end

function Skia.Static.getSkMaskFilter(key)
    return lib.static_sk_mask_filter_get(key)
end

function Skia.Static.deleteSkMatrix(key)
    lib.static_sk_matrix_delete(key)
end

function Skia.Static.deleteSkMemoryStream(key)
    lib.static_sk_memory_stream_delete(key)
end

function Skia.Static.getSkMemoryStream(key)
    return lib.static_sk_memory_stream_get(key)
end

function Skia.Static.deleteSkMeshIndexBuffer(key)
    lib.static_sk_mesh_index_buffer_delete(key)
end

function Skia.Static.getSkMeshIndexBuffer(key)
    return lib.static_sk_mesh_index_buffer_get(key)
end

function Skia.Static.deleteSkMeshVertexBuffer(key)
    lib.static_sk_mesh_vertex_buffer_delete(key)
end

function Skia.Static.getSkMeshVertexBuffer(key)
    return lib.static_sk_mesh_vertex_buffer_get(key)
end

function Skia.Static.deleteSkPath(key)
    lib.static_sk_path_delete(key)
end

function Skia.Static.deleteSkPathEffect(key)
    lib.static_sk_path_effect_delete(key)
end

function Skia.Static.getSkPathEffect(key)
    return lib.static_sk_path_effect_get(key)
end

function Skia.Static.deleteSkPicture(key)
    lib.static_sk_picture_delete(key)
end

function Skia.Static.getSkPicture(key)
    return lib.static_sk_picture_get(key)
end

function Skia.Static.deleteSkPixelRef(key)
    lib.static_sk_pixel_ref_delete(key)
end

function Skia.Static.getSkPixelRef(key)
    return lib.static_sk_pixel_ref_get(key)
end

function Skia.Static.deleteSkPixmap(key)
    lib.static_sk_pixmap_delete(key)
end

function Skia.Static.deleteSkRRect(key)
    lib.static_sk_r_rect_delete(key)
end

function Skia.Static.deleteSkRect(key)
    lib.static_sk_rect_delete(key)
end

function Skia.Static.getSkRectPtr(key)
    return lib.static_sk_rect_get_ptr(key)
end

function Skia.Static.deleteSkRuntimeEffect(key)
    lib.static_sk_runtime_effect_delete(key)
end

function Skia.Static.getSkRuntimeEffect(key)
    return lib.static_sk_runtime_effect_get(key)
end

function Skia.Static.deleteConstSkruntimeEffectChild(key)
    lib.static_const_sk_runtime_effect_child_delete(key)
end

function Skia.Static.deleteConstSkRuntimeEffectChildPtr(key)
    lib.static_const_sk_runtime_effect_child_ptr_delete(key)
end

function Skia.Static.deleteSkRuntimeEffectResult(key)
    lib.static_sk_runtime_effect_result_delete(key)
end

function Skia.Static.deleteSkRuntimeEffectTracedShader(key)
    lib.static_sk_runtime_effect_traced_shader_delete(key)
end

function Skia.Static.deleteConstSkRuntimeEffectUniform(key)
    lib.static_const_sk_runtime_effect_uniform_delete(key)
end

function Skia.Static.deleteSkSamplingOptions(key)
    lib.static_sk_sampling_options_delete(key)
end

function Skia.Static.deleteSkShader(key)
    lib.static_sk_shader_delete(key)
end

function Skia.Static.getSkShader(key)
    return lib.static_sk_shader_get(key)
end

--[[

function Skia.Static.deleteSkShaper(key)
    lib.static_sk_shaper_delete(key)
end

function Skia.Static.getSkShaper(key)
    return lib.static_sk_shaper_get(key)
end

function Skia.Static.deleteSkShaperBiDiRunIterator(key)
    lib.static_sk_shaper_bi_di_run_iterator_delete(key)
end

function Skia.Static.getSkShaperBiDiRunIterator(key)
    return lib.static_sk_shaper_bi_di_run_iterator_get(key)
end

function Skia.Static.deleteSkShaperFontRunIterator(key)
    lib.static_sk_shaper_font_run_iterator_delete(key)
end

function Skia.Static.getSkShaperFontRunIterator(key)
    return lib.static_sk_shaper_font_run_iterator_get(key)
end

function Skia.Static.deleteSkShaperLanguageRunIterator(key)
    lib.static_sk_shaper_language_run_iterator_delete(key)
end

function Skia.Static.getSkShaperLanguageRunIterator(key)
    return lib.static_sk_shaper_language_run_iterator_get(key)
end

function Skia.Static.deleteSkShaperScriptRunIterator(key)
    lib.static_sk_shaper_script_run_iterator_delete(key)
end

function Skia.Static.getSkShaperScriptRunIterator(key)
    return lib.static_sk_shaper_script_run_iterator_get(key)
end

]]

function Skia.Static.deleteSkStream(key)
    lib.static_sk_stream_delete(key)
end

function Skia.Static.getSkStream(key)
    return lib.static_sk_stream_get(key)
end

function Skia.Static.deleteSkStreamAsset(key)
    lib.static_sk_stream_asset_delete(key)
end

function Skia.Static.getSkStreamAsset(key)
    return lib.static_sk_stream_asset_get(key)
end

function Skia.Static.deleteSkStreamMemory(key)
    lib.static_sk_stream_memory_delete(key)
end

function Skia.Static.getSkStreamMemory(key)
    return lib.static_sk_stream_memory_get(key)
end

function Skia.Static.deleteSkStreamRewindable(key)
    lib.static_sk_stream_rewindable_delete(key)
end

function Skia.Static.getSkStreamRewindable(key)
    return lib.static_sk_stream_rewindable_get(key)
end

function Skia.Static.deleteSkStreamSeekable(key)
    lib.static_sk_stream_seekable_delete(key)
end

function Skia.Static.getSkStreamSeekable(key)
    return lib.static_sk_stream_seekable_get(key)
end

function Skia.Static.deleteSkString(key)
    lib.static_sk_string_delete(key)
end

function Skia.Static.deleteSkSpanSkString(key)
    lib.static_sk_span_sk_string_delete(key)
end

function Skia.Static.deleteSkStrokeRec(key)
    lib.static_sk_stroke_rec_delete(key)
end

function Skia.Static.deleteSkSurface(key)
    lib.static_sk_surface_delete(key)
end

function Skia.Static.getSkSurface(key)
    return lib.static_sk_surface_get(key)
end

function Skia.Static.deleteSkSurfaceProps(key)
    lib.static_sk_surface_props_delete(key)
end

--[[

function Skia.Static.deleteSkSvgCircle(key)
    lib.static_sk_svg_circle_delete(key)
end

function Skia.Static.getSkSvgCircle(key)
    return lib.static_sk_svg_circle_get(key)
end

function Skia.Static.deleteSkSvgClipPath(key)
    lib.static_sk_svg_clip_path_delete(key)
end

function Skia.Static.getSkSvgClipPath(key)
    return lib.static_sk_svg_clip_path_get(key)
end

function Skia.Static.deleteSkSVGDefs(key)
    lib.static_sk_svg_defs_delete(key)
end

function Skia.Static.getSkSVGDefs(key)
    return lib.static_sk_svg_defs_get(key)
end

function Skia.Static.deleteSkSVGDom(key)
    lib.static_sk_svg_dom_delete(key)
end

function Skia.Static.getSkSVGDom(key)
    return lib.static_sk_svg_dom_get(key)
end

function Skia.Static.deleteSkSVGEllipse(key)
    lib.static_sk_svg_ellipse_delete(key)
end

function Skia.Static.getSkSVGEllipse(key)
    return lib.static_sk_svg_ellipse_get(key)
end

function Skia.Static.deleteSkSVGFeBlend(key)
    lib.static_sk_svg_fe_blend_delete(key)
end

function Skia.Static.getSkSVGFeBlend(key)
    return lib.static_sk_svg_fe_blend_get(key)
end

function Skia.Static.deleteSkVGFeColorMatrix(key)
    lib.static_sk_svg_fe_color_matrix_delete(key)
end

function Skia.Static.getSkSVGFeColorMatrix(key)
    return lib.static_sk_svg_fe_color_matrix_get(key)
end

function Skia.Static.deleteSkSVGFeComposite(key)
    lib.static_sk_svg_fe_composite_delete(key)
end

function Skia.Static.getSkSVGFeComposite(key)
    return lib.static_sk_svg_fe_composite_get(key)
end

function Skia.Static.deleteSkSVGFeDiffuseLighting(key)
    lib.static_sk_svg_fe_diffuse_lighting_delete(key)
end

function Skia.Static.getSkSVGFeDiffuseLighting(key)
    return lib.static_sk_svg_fe_diffuse_lighting_get(key)
end

function Skia.Static.deleteSkSVGFeDisplacementMap(key)
    lib.static_sk_svg_fe_displacement_map_delete(key)
end

function Skia.Static.getSkSVGFeDisplacementMap(key)
    return lib.static_sk_svg_fe_displacement_map_get(key)
end

function Skia.Static.deleteSkSVGFeDistantLight(key)
    lib.static_sk_svg_fe_distant_light_delete(key)
end

function Skia.Static.getSkSVGFeDistantLight(key)
    return lib.static_sk_svg_fe_distant_light_get(key)
end

function Skia.Static.deleteSkSVGFeFlood(key)
    lib.static_sk_svg_fe_flood_delete(key)
end

function Skia.Static.getSkSVGFeFlood(key)
    return lib.static_sk_svg_fe_flood_get(key)
end

function Skia.Static.deleteSkSVGFeGaussianBlur(key)
    lib.static_sk_svg_fe_gaussian_blur_delete(key)
end

function Skia.Static.getSkSVGFeGaussianBlur(key)
    return lib.static_sk_svg_fe_gaussian_blur_get(key)
end

function Skia.Static.deleteSkSVGFeImage(key)
    lib.static_sk_svg_fe_image_delete(key)
end

function Skia.Static.getSkSVGFeImage(key)
    return lib.static_sk_svg_fe_image_get(key)
end

function Skia.Static.deleteSkSVGFeMorphology(key)
    lib.static_sk_svg_fe_morphology_delete(key)
end

function Skia.Static.getSkSVGFeMorphology(key)
    return lib.static_sk_svg_fe_morphology_get(key)
end

function Skia.Static.deleteSkSVGFeOffset(key)
    lib.static_sk_svg_fe_offset_delete(key)
end

function Skia.Static.getSkSVGFeOffset(key)
    return lib.static_sk_svg_fe_offset_get(key)
end

function Skia.Static.deleteSkSVGFePointLight(key)
    lib.static_sk_svg_fe_point_light_delete(key)
end

function Skia.Static.getSkSVGFePointLight(key)
    return lib.static_sk_svg_fe_point_light_get(key)
end

function Skia.Static.deleteSkSVGFeSpecularLighting(key)
    lib.static_sk_svg_fe_specular_lighting_delete(key)
end

function Skia.Static.getSkSVGFeSpecularLighting(key)
    return lib.static_sk_svg_fe_specular_lighting_get(key)
end

function Skia.Static.deleteSkSVGFeSpotLight(key)
    lib.static_sk_svg_fe_spot_light_delete(key)
end

function Skia.Static.getSkSVGFeSpotLight(key)
    return lib.static_sk_svg_fe_spot_light_get(key)
end

function Skia.Static.deleteSkSVGFeTurbulence(key)
    lib.static_sk_svg_fe_turbulence_delete(key)
end

function Skia.Static.getSkSVGFeTurbulence(key)
    return lib.static_sk_svg_fe_turbulence_get(key)
end

function Skia.Static.deleteSkSVGG(key)
    lib.static_sk_svg_g_delete(key)
end

function Skia.Static.getSkSVGG(key)
    return lib.static_sk_svg_g_get(key)
end

function Skia.Static.deleteSkSVGLine(key)
    lib.static_sk_svg_line_delete(key)
end

function Skia.Static.getSkSVGLine(key)
    return lib.static_sk_svg_line_get(key)
end

function Skia.Static.deleteSkSVGLinearGradient(key)
    lib.static_sk_svg_linear_gradient_delete(key)
end

function Skia.Static.getSkSVGLinearGradient(key)
    return lib.static_sk_svg_linear_gradient_get(key)
end

function Skia.Static.deleteSkSVGMask(key)
    lib.static_sk_svg_mask_delete(key)
end

function Skia.Static.getSkSVGMask(key)
    return lib.static_sk_svg_mask_get(key)
end

function Skia.Static.deleteSkSVGNode(key)
    lib.static_sk_svg_node_delete(key)
end

function Skia.Static.getSkSVGNode(key)
    return lib.static_sk_svg_node_get(key)
end

function Skia.Static.deleteSkSVGPath(key)
    lib.static_sk_svg_path_delete(key)
end

function Skia.Static.getSkSVGPath(key)
    return lib.static_sk_svg_path_get(key)
end

function Skia.Static.deleteSkSVGPattern(key)
    lib.static_sk_svg_pattern_delete(key)
end

function Skia.Static.getSkSVGPattern(key)
    return lib.static_sk_svg_pattern_get(key)
end

function Skia.Static.deleteSkSVGPoly(key)
    lib.static_sk_svg_poly_delete(key)
end

function Skia.Static.getSkSVGPoly(key)
    return lib.static_sk_svg_poly_get(key)
end

function Skia.Static.deleteSkSVGPresentationAttributes(key)
    lib.static_sk_svg_presentation_attributes_delete(key)
end

function Skia.Static.deleteSkSVGRadialGradient(key)
    lib.static_sk_svg_radial_gradient_delete(key)
end

function Skia.Static.getSkSVGRadialGradient(key)
    return lib.static_sk_svg_radial_gradient_get(key)
end

function Skia.Static.deleteSkSVGRect(key)
    lib.static_sk_svg_rect_delete(key)
end

function Skia.Static.getSkSVGRect(key)
    return lib.static_sk_svg_rect_get(key)
end

function Skia.Static.deleteSkSVGStop(key)
    lib.static_sk_svg_stop_delete(key)
end

function Skia.Static.getSkSVGStop(key)
    return lib.static_sk_svg_stop_get(key)
end

function Skia.Static.deleteSkSVGSVG(key)
    lib.static_sk_svg_svg_delete(key)
end

function Skia.Static.getSkSVGSVG(key)
    return lib.static_sk_svg_svg_get(key)
end

function Skia.Static.deleteSkSVTTSpan(key)
    lib.static_sk_svg_t_span_delete(key)
end

function Skia.Static.getSkSVGTSpan(key)
    return lib.static_sk_svg_t_span_get(key)
end

function Skia.Static.deleteSkSVGText(key)
    lib.static_sk_svg_text_delete(key)
end

function Skia.Static.getSkSVGText(key)
    return lib.static_sk_svg_text_get(key)
end

function Skia.Static.deleteSkSVGTextLiteral(key)
    lib.static_sk_svg_text_literal_delete(key)
end

function Skia.Static.getSkSVGTextLiteral(key)
    return lib.static_sk_svg_text_literal_get(key)
end

function Skia.Static.deleteSkSVGTextPath(key)
    lib.static_sk_svg_text_path_delete(key)
end

function Skia.Static.getSkSVGTextPath(key)
    return lib.static_sk_svg_text_path_get(key)
end

function Skia.Static.deleteSkSVGUse(key)
    lib.static_sk_svg_use_delete(key)
end

function Skia.Static.getSkSVGUse(key)
    return lib.static_sk_svg_use_get(key)
end

]]

function Skia.Static.deleteSkTextBlob(key)
    lib.static_sk_text_blob_delete(key)
end

function Skia.Static.getSkTextBlob(key)
    return lib.static_sk_text_blob_get(key)
end

function Skia.Static.deleteSkTypeface(key)
    lib.static_sk_typeface_delete(key)
end

function Skia.Static.getSkTypeface(key)
    return lib.static_sk_typeface_get(key)
end

function Skia.Static.deleteSkVertices(key)
    lib.static_sk_vertices_delete(key)
end

function Skia.Static.getSkVertices(key)
    return lib.static_sk_vertices_get(key)
end

function Skia.Static.deleteSkYUVAInfo(key)
    lib.static_sk_yuva_info_delete(key)
end

function Skia.Static.deleteSkYUVAPixmapInfo(key)
    lib.static_sk_yuva_pixmap_info_delete(key)
end

function Skia.Static.deleteSkYUVAPixmaps(key)
    lib.static_sk_yuva_pixmaps_delete(key)
end

function Skia.Static.deleteFunctionVoidVoid(key)
    lib.static_function_void_void_delete(key)
end

function Skia.Static.deleteStringView(key)
    lib.static_string_view_delete(key)
end

function Skia.Static.deleteTupleIntInt(key)
    lib.static_tuple_int_int_delete(key)
end

function Skia.Static.deleteTupleIntSkYUVAPixmapInfoDataType(key)
    lib.static_tuple_int_sk_yuva_pixmap_info_data_type_delete(key)
end

function Skia.Static.deleteTupleSkImageSkCodecResult(key)
    lib.static_tuple_sk_image_sk_codec_result_delete(key)
end

function Skia.Static.deleteVectorSkCodecFrameInto(key)
    lib.static_vector_sk_codec_frame_into_delete(key)
end

function Skia.Static.popBackVectorSkCodecFrameInto(key)
    lib.static_vector_sk_codec_frame_into_pop_back(key)
end

function Skia.Static.eraseVectorSkCodecFrameInto(key, index)
    lib.static_vector_sk_codec_frame_into_erase(key, index)
end

function Skia.Static.deleteVectorSkScalar(key)
    lib.static_vector_sk_scalar_delete(key)
end

function Skia.Static.getVectorSkScalar(key, index)
    return lib.static_vector_sk_scalar_get(key, index)
end

function Skia.Static.pushBackVectorSkScalar(key, value)
    lib.static_vector_sk_scalar_push_back(key, value)
end

function Skia.Static.insertVectorSkScalar(key, index, value)
    lib.static_vector_sk_scalar_insert(key, index, value)
end

function Skia.Static.popBackVectorSkScalar(key)
    lib.static_vector_sk_scalar_pop_back(key)
end

function Skia.Static.eraseVectorSkScalar(key, index)
    lib.static_vector_sk_scalar_erase(key, index)
end

--[[
function Skia.Static.deleteVectorSkSVGLength(key)
    lib.static_vector_sk_svg_length_delete(key)
end

function Skia.Static.popBackVectorSkSVGLength(key)
    lib.static_vector_sk_svg_length_pop_back(key)
end

function Skia.Static.eraseVectorSkSVGLength(key, index)
    lib.static_vector_sk_svg_length_erase(key, index)
end
]]

-- # binding

--[[

-- ## gr_backend_drawable_info
Skia.BackendDrawableInfo = {}

function Skia.BackendDrawableInfo.new()
    local obj = lib.GrBackendDrawableInfo_new()
    ffi.gc(obj, lib.GrBackendDrawableInfo_delete)
    return obj
end

function Skia.BackendDrawableInfo.new_2(info)
    local obj = lib.GrBackendDrawableInfo_new_2(info)
    ffi.gc(obj, lib.GrBackendDrawableInfo_delete)
    return obj
end

function Skia.BackendDrawableInfo.delete(backend_drawable_info)
    lib.GrBackendDrawableInfo_delete(backend_drawable_info)
end

function Skia.BackendDrawableInfo.isValid(backend_drawable_info)
    return lib.GrBackendDrawableInfo_isValid(backend_drawable_info)
end

function Skia.BackendDrawableInfo.backend(backend_drawable_info)
    return lib.GrBackendDrawableInfo_backend(backend_drawable_info)
end

function Skia.BackendDrawableInfo.getVkDrawableInfo(backend_drawable_info, outInfo)
    return lib.GrBackendDrawableInfo_getVkDrawableInfo(backend_drawable_info, outInfo)
end

-- ## gr_backend_format
Skia.BackendFormat = {}

function Skia.BackendFormat.new()
    local obj = lib.GrBackendFormat_new()
    ffi.gc(obj, lib.GrBackendFormat_delete)
    return obj
end

function Skia.BackendFormat.new_2(format)
    local obj = lib.GrBackendFormat_new_2(format)
    ffi.gc(obj, lib.GrBackendFormat_delete)
    return obj
end

function Skia.BackendFormat.delete(backend_format)
    lib.GrBackendFormat_delete(backend_format)
end

function Skia.BackendFormat.backend(backend_format)
    return lib.GrBackendFormat_backend(backend_format)
end

function Skia.BackendFormat.textureType(backend_format)
    return lib.GrBackendFormat_textureType(backend_format)
end

function Skia.BackendFormat.channelMask(backend_format)
    return lib.GrBackendFormat_channelMask(backend_format)
end

function Skia.BackendFormat.desc(backend_format)
    local obj = lib.GrBackendFormat_desc(backend_format)
    setFinalizer(obj, lib.static_gr_color_format_desc_delete)
    return obj
end

function Skia.BackendFormat.asMockColorType(backend_format)
    return lib.GrBackendFormat_asMockColorType(backend_format)
end

function Skia.BackendFormat.asMockCompressionType(backend_format)
    return lib.GrBackendFormat_asMockCompressionType(backend_format)
end

function Skia.BackendFormat.isMockStencilFormat(backend_format)
    return lib.GrBackendFormat_isMockStencilFormat(backend_format)
end

function Skia.BackendFormat.makeTexture2D(backend_format)
    local obj = lib.GrBackendFormat_makeTexture2D(backend_format)
    setFinalizer(obj, lib.static_gr_backend_format_delete)
    return obj
end

function Skia.BackendFormat.isValid(backend_format)
    return lib.GrBackendFormat_isValid(backend_format)
end

function Skia.BackendFormat.MakeMock(colorType, compression, isStencilFormat)
    local obj = lib.GrBackendFormat_MakeMock(colorType, compression, isStencilFormat)
    setFinalizer(obj, lib.static_gr_backend_format_delete)
    return obj
end

-- ## gr_backend_render_target
Skia.BackendRenderTarget = {}

function Skia.BackendRenderTarget.new()
    local obj = lib.GrBackendRenderTarget_new()
    ffi.gc(obj, lib.GrBackendRenderTarget_delete)
    return obj
end

function Skia.BackendRenderTarget.new_2(width, height, sampleCnt, stencilBits, mockInfo)
    local obj = lib.GrBackendRenderTarget_new_2(width, height, sampleCnt, stencilBits, mockInfo)
    ffi.gc(obj, lib.GrBackendRenderTarget_delete)
    return obj
end

function Skia.BackendRenderTarget.new_3(that)
    local obj = lib.GrBackendRenderTarget_new_3(that)
    ffi.gc(obj, lib.GrBackendRenderTarget_delete)
    return obj
end

function Skia.BackendRenderTarget.delete(backend_render_target)
    lib.GrBackendRenderTarget_delete(backend_render_target)
end

function Skia.BackendRenderTarget.dimensions(backend_render_target)
    local obj = lib.GrBackendRenderTarget_dimensions(backend_render_target)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.BackendRenderTarget.width(backend_render_target)
    return lib.GrBackendRenderTarget_width(backend_render_target)
end

function Skia.BackendRenderTarget.height(backend_render_target)
    return lib.GrBackendRenderTarget_height(backend_render_target)
end

function Skia.BackendRenderTarget.sampleCnt(backend_render_target)
    return lib.GrBackendRenderTarget_sampleCnt(backend_render_target)
end

function Skia.BackendRenderTarget.stencilBits(backend_render_target)
    return lib.GrBackendRenderTarget_stencilBits(backend_render_target)
end

function Skia.BackendRenderTarget.backend(backend_render_target)
    return lib.GrBackendRenderTarget_backend(backend_render_target)
end

function Skia.BackendRenderTarget.isFramebufferOnly(backend_render_target)
    return lib.GrBackendRenderTarget_isFramebufferOnly(backend_render_target)
end

function Skia.BackendRenderTarget.getBackendFormat(backend_render_target)
    local obj = lib.GrBackendRenderTarget_getBackendFormat(backend_render_target)
    setFinalizer(obj, lib.static_gr_backend_format_delete)
    return obj
end

function Skia.BackendRenderTarget.getMockRenderTargetInfo(backend_render_target, info)
    return lib.GrBackendRenderTarget_getMockRenderTargetInfo(backend_render_target, info)
end

function Skia.BackendRenderTarget.setMutableState(backend_render_target, state)
    lib.GrBackendRenderTarget_setMutableState(backend_render_target, state)
end

function Skia.BackendRenderTarget.isProtected(backend_render_target)
    return lib.GrBackendRenderTarget_isProtected(backend_render_target)
end

function Skia.BackendRenderTarget.isValid(backend_render_target)
    return lib.GrBackendRenderTarget_isValid(backend_render_target)
end

-- ## gr_backend_semaphore
Skia.BackendSemaphore = {}

function Skia.BackendSemaphore.new()
    local obj = lib.GrBackendSemaphore_new()
    ffi.gc(obj, lib.GrBackendSemaphore_delete)
    return obj
end

function Skia.BackendSemaphore.new_2(semaphore)
    local obj = lib.GrBackendSemaphore_new_2(semaphore)
    ffi.gc(obj, lib.GrBackendSemaphore_delete)
    return obj
end

function Skia.BackendSemaphore.delete(backend_semaphore)
    lib.GrBackendSemaphore_delete(backend_semaphore)
end

function Skia.BackendSemaphore.isInitialized(backend_semaphore)
    return lib.GrBackendSemaphore_isInitialized(backend_semaphore)
end

function Skia.BackendSemaphore.backend(backend_semaphore)
    return lib.GrBackendSemaphore_backend(backend_semaphore)
end

-- ## gr_backend_texture
Skia.BackendTexture = {}

function Skia.BackendTexture.new()
    local obj = lib.GrBackendTexture_new()
    ffi.gc(obj, lib.GrBackendTexture_delete)
    return obj 
end

function Skia.BackendTexture.new_2(width, height, midmapped, mockInfo, label)
    local obj = lib.GrBackendTexture_new_2(width, height, midmapped, mockInfo, label)
    ffi.gc(obj, lib.GrBackendTexture_delete)
    return obj  
end

function Skia.BackendTexture.new_3(that)
    local obj = lib.GrBackendTexture_new_3(that)
    ffi.gc(obj, lib.GrBackendTexture_delete)
    return obj  
end

function Skia.BackendTexture.delete(backend_texture)
    lib.GrBackendTexture_delete(backend_texture)
end

function Skia.BackendTexture.dimensions(backend_texture)
    local obj = lib.GrBackendTexture_dimensions(backend_texture)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.BackendTexture.width(backend_texture)
    return lib.GrBackendTexture_width(backend_texture)
end

function Skia.BackendTexture.height(backend_texture)
    return lib.GrBackendTexture_height(backend_texture)
end

function Skia.BackendTexture.getLabel(backend_texture)
    local obj = lib.GrBackendTexture_getLabel(backend_texture)
    setFinalizer(obj, lib.static_string_view_delete)
    return obj
end

function Skia.BackendTexture.mipmapped(backend_texture)
    return lib.GrBackendTexture_mipmapped(backend_texture)
end

function Skia.BackendTexture.hasMipmaps(backend_texture)
    return lib.GrBackendTexture_hasMipmaps(backend_texture)
end

function Skia.BackendTexture.hasMipMaps(backend_texture)
    return lib.GrBackendTexture_hasMipMaps(backend_texture)
end

function Skia.BackendTexture.backend(backend_texture)
    return lib.GrBackendTexture_backend(backend_texture)
end

function Skia.BackendTexture.textureType(backend_texture)
    return lib.GrBackendTexture_textureType(backend_texture)
end

function Skia.BackendTexture.getBackendFormat(backend_texture)
    local obj = lib.GrBackendTexture_getBackendFormat(backend_texture)
    setFinalizer(obj, lib.static_gr_backend_format_delete)
    return obj
end

function Skia.BackendTexture.getMockTextureInfo(backend_texture, info)
    return lib.GrBackendTexture_getMockTextureInfo(backend_texture, info)
end

function Skia.BackendTexture.setMutableState(backend_texture, state)
    lib.GrBackendTexture_setMutableState(backend_texture, state)
end

function Skia.BackendTexture.isProtected(backend_texture)
    return lib.GrBackendTexture_isProtected(backend_texture)
end

function Skia.BackendTexture.isValid(backend_texture)
    return lib.GrBackendTexture_isValid(backend_texture)
end

function Skia.BackendTexture.isSameTexture(backend_texture, texture)
    return lib.GrBackendTexture_isSameTexture(backend_texture, texture)
end

-- ## gr_context_thread_safe_proxy
Skia.ContextThreadSafeProxy = {}

function Skia.ContextThreadSafeProxy.delete(context_thread_safe_proxy)
    lib.GrContextThreadSafeProxy_delete(context_thread_safe_proxy)
end

function Skia.ContextThreadSafeProxy.unique(context_thread_safe_proxy)
    return lib.GrContextThreadSafeProxy_unique(context_thread_safe_proxy)
end

function Skia.ContextThreadSafeProxy.ref(context_thread_safe_proxy)
    lib.GrContextThreadSafeProxy_ref(context_thread_safe_proxy)
end

function Skia.ContextThreadSafeProxy.unref(context_thread_safe_proxy)
    lib.GrContextThreadSafeProxy_unref(context_thread_safe_proxy)
end

function Skia.ContextThreadSafeProxy.deref(context_thread_safe_proxy)
    lib.GrContextThreadSafeProxy_deref(context_thread_safe_proxy)
end

function Skia.ContextThreadSafeProxy.refCntGreaterThan(context_thread_safe_proxy, threadIsolatedTestCnt)
    return lib.GrContextThreadSafeProxy_refCntGreaterThan(context_thread_safe_proxy, threadIsolatedTestCnt)
end

-- ## gr_direct_context
Skia.DirectContext = {}

function Skia.DirectContext.delete(direct_context)
    lib.GrDirectContext_delete(direct_context)
end

function Skia.DirectContext.resetContext(direct_context, state)
    lib.GrDirectContext_resetContext(direct_context, state)
end

function Skia.DirectContext.resetGLTextureBindings(direct_context)
    lib.GrDirectContext_resetGLTextureBindings(direct_context)
end

function Skia.DirectContext.abandonContext(direct_context)
    lib.GrDirectContext_abandonContext(direct_context)
end

function Skia.DirectContext.abandoned(direct_context)
    return lib.GrDirectContext_abandoned(direct_context)
end

function Skia.DirectContext.isDeviceLost(direct_context)
    return lib.GrDirectContext_isDeviceLost(direct_context)
end

function Skia.DirectContext.threadSafeProxy(direct_context)
    local obj = lib.GrDirectContext_threadSafeProxy(direct_context)
    setFinalizer(obj, lib.static_gr_context_thread_safe_proxy_delete)
    return obj
end

function Skia.DirectContext.oomed(direct_context)
    return lib.GrDirectContext_oomed(direct_context)
end

function Skia.DirectContext.releaseResourcesAndAbandonContext(direct_context)
    lib.GrDirectContext_releaseResourcesAndAbandonContext(direct_context)
end

function Skia.DirectContext.getResourceCacheLimits(direct_context, maxResources, maxResourceBytes)
    lib.GrDirectContext_getResourceCacheLimits(direct_context, maxResources, maxResourceBytes)
end

function Skia.DirectContext.getResourceCacheLimit(direct_context)
    return lib.GrDirectContext_getResourceCacheLimit(direct_context)
end

function Skia.DirectContext.getResourceCacheUsage(direct_context, resourceCount, resourceBytes)
    lib.GrDirectContext_getResourceCacheUsage(direct_context, resourceCount, resourceBytes)
end

function Skia.DirectContext.getResourceCachePurgeableBytes(direct_context)
    return lib.GrDirectContext_getResourceCachePurgeableBytes(direct_context)
end

function Skia.DirectContext.setResourceCacheLimits(direct_context, maxResources, maxResourceBytes)
    lib.GrDirectContext_setResourceCacheLimits(direct_context, maxResources, maxResourceBytes)
end

function Skia.DirectContext.setResourceCacheLimit(direct_context, maxResourceBytes)
    lib.GrDirectContext_setResourceCacheLimit(direct_context, maxResourceBytes)
end

function Skia.DirectContext.freeGpuResources(direct_context)
    lib.GrDirectContext_freeGpuResources(direct_context)
end

function Skia.DirectContext.performDeferredCleanup(direct_context, msNotUsed, opts)
    lib.GrDirectContext_performDeferredCleanup(direct_context, msNotUsed, opts)
end

function Skia.DirectContext.purgeResourcesNotUsedInMs(direct_context, msNotUsed)
    lib.GrDirectContext_purgeResourcesNotUsedInMs(direct_context, msNotUsed)
end

function Skia.DirectContext.purgeUnlockedResources(direct_context, bytesToPurge, preferScratchResources)
    lib.GrDirectContext_purgeUnlockedResources(direct_context, bytesToPurge, preferScratchResources)
end

function Skia.DirectContext.purgeUnlockedResources_2(direct_context, opts)
    lib.GrDirectContext_purgeUnlockedResources_2(direct_context, opts)
end

function Skia.DirectContext.wait(direct_context, numSemaphores, waitSemaphores, deleteSemaphoresAfterWait)
    return lib.GrDirectContext_wait(direct_context, numSemaphores, waitSemaphores, deleteSemaphoresAfterWait)
end

function Skia.DirectContext.flushAndSubmit(direct_context, sync)
    lib.GrDirectContext_flushAndSubmit(direct_context, sync)
end

function Skia.DirectContext.flushAndSubmit_2(direct_context, image)
    lib.GrDirectContext_flushAndSubmit_2(direct_context, image)
end

function Skia.DirectContext.flushAndSubmit_3(direct_context, surface, sync)
    lib.GrDirectContext_flushAndSubmit_3(direct_context, surface, sync)
end

function Skia.DirectContext.flush(direct_context, info)
    return lib.GrDirectContext_flush(direct_context, info)
end

function Skia.DirectContext.flush_2(direct_context)
    lib.GrDirectContext_flush_2(direct_context)
end

function Skia.DirectContext.flush_3(direct_context, image, info)
    return lib.GrDirectContext_flush_3(direct_context, image, info)
end

function Skia.DirectContext.flush_4(direct_context, image)
    lib.GrDirectContext_flush_4(direct_context, image)
end

function Skia.DirectContext.flush_5(direct_context, surface, access, info)
    return lib.GrDirectContext_flush_5(direct_context, surface, access, info)
end

function Skia.DirectContext.flush_6(direct_context, surface, info, newState)
    return lib.GrDirectContext_flush_6(direct_context, surface, info, newState)
end

function Skia.DirectContext.flush_7(direct_context, surface)
    lib.GrDirectContext_flush_7(direct_context, surface)
end

function Skia.DirectContext.submit(direct_context, sync)
    return lib.GrDirectContext_submit(direct_context, sync)
end

function Skia.DirectContext.checkAsyncWorkCompletion(direct_context)
    lib.GrDirectContext_checkAsyncWorkCompletion(direct_context)
end

function Skia.DirectContext.dumpMemoryStatistics(direct_context, traceMemoryDump)
    lib.GrDirectContext_dumpMemoryStatistics(direct_context, traceMemoryDump)
end

function Skia.DirectContext.supportsDistanceFieldText(direct_context)
    return lib.GrDirectContext_supportsDistanceFieldText(direct_context)
end

function Skia.DirectContext.storeVkPipelineCacheData(direct_context)
    lib.GrDirectContext_storeVkPipelineCacheData(direct_context)
end

function Skia.DirectContext.createBackendTexture(direct_context, width, height, format, mipmapped, renderable, isProtected, label)
    local obj = lib.GrDirectContext_createBackendTexture(direct_context, width, height, format, mipmapped, renderable, isProtected, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_2(direct_context, width, height, type, mipmapped, renderable, isProtected, label)
    local obj = lib.GrDirectContext_createBackendTexture_2(direct_context, width, height, type, mipmapped, renderable, isProtected, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_3(direct_context, width, height, format, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_3(direct_context, width, height, format, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_4(direct_context, width, height, type, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_4(direct_context, width, height, type, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_5(direct_context, srcData, numLevels, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_5(direct_context, srcData, numLevels, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_6(direct_context, srcData, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_6(direct_context, srcData, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_7(direct_context, srcData, numLevels, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_7(direct_context, srcData, numLevels, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createBackendTexture_8(direct_context, srcData, renderable, isProtected, finishedProc, finishedContext, label)
    local obj = lib.GrDirectContext_createBackendTexture_8(direct_context, srcData, renderable, isProtected, finishedProc, finishedContext, label)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.updateBackendTexture(direct_context, texture, color, finishedProc, finishedContext)
    return lib.GrDirectContext_updateBackendTexture(direct_context, texture, color, finishedProc, finishedContext)
end

function Skia.DirectContext.updateBackendTexture_2(direct_context, texture, skColorType, color, finishedProc, finishedContext)
    return lib.GrDirectContext_updateBackendTexture_2(direct_context, texture, skColorType, color, finishedProc, finishedContext)
end

function Skia.DirectContext.updateBackendTexture_3(direct_context, texture, srcData, numLevels, textureOrigin, finishedProc, finishedContext)
    return lib.GrDirectContext_updateBackendTexture_3(direct_context, texture, srcData, numLevels, textureOrigin, finishedProc, finishedContext)
end

function Skia.DirectContext.updateBackendTexture_4(direct_context, texture, srcData, textureOrigin, finishedProc, finishedContext)
    return lib.GrDirectContext_updateBackendTexture_4(direct_context, texture, srcData, textureOrigin, finishedProc, finishedContext)
end

function Skia.DirectContext.updateBackendTexture_5(direct_context, texture, srcData, numLevels, finishedProc, finishedContext)
    return lib.GrDirectContext_updateBackendTexture_5(direct_context, texture, srcData, numLevels, finishedProc, finishedContext)
end

function Skia.DirectContext.createCompressedBackendTexture(direct_context, width, height, format, color, mipmapped, isProtected, finishedProc, finishedContext)
    local obj = lib.GrDirectContext_createCompressedBackendTexture(direct_context, width, height, format, color, mipmapped, isProtected, finishedProc, finishedContext)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createCompressedBackendTexture_2(direct_context, width, height, type, color, mipmapped, isProtected, finishedProc, finishedContext)
    local obj = lib.GrDirectContext_createCompressedBackendTexture_2(direct_context, width, height, type, color, mipmapped, isProtected, finishedProc, finishedContext)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createCompressedBackendTexture_3(direct_context, width, height, format, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    local obj = lib.GrDirectContext_createCompressedBackendTexture_3(direct_context, width, height, format, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.createCompressedBackendTexture_4(direct_context, width, height, type, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    local obj = lib.GrDirectContext_createCompressedBackendTexture_4(direct_context, width, height, type, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.DirectContext.updateCompressedBackendTexture(direct_context, texture, color, finishedProc, finishedContext)
    return lib.GrDirectContext_updateCompressedBackendTexture(direct_context, texture, color, finishedProc, finishedContext)
end

function Skia.DirectContext.updateCompressedBackendTexture_2(direct_context, texture, data, dataSize, finishedProc, finishedContext)
    return lib.GrDirectContext_updateCompressedBackendTexture_2(direct_context, texture, data, dataSize, finishedProc, finishedContext)
end

function Skia.DirectContext.setBackendTextureState(direct_context, texture, state, previousState, finishedProc, finishedContext)
    return lib.GrDirectContext_setBackendTextureState(direct_context, texture, state, previousState, finishedProc, finishedContext)
end

function Skia.DirectContext.setBackendRenderTargetState(direct_context, target, state, previousState, finishedProc, finishedContext)
    return lib.GrDirectContext_setBackendRenderTargetState(direct_context, target, state, previousState, finishedProc, finishedContext)
end

function Skia.DirectContext.deleteBackendTexture(direct_context, texture)
    lib.GrDirectContext_deleteBackendTexture(direct_context, texture)
end

function Skia.DirectContext.precompileShader(direct_context, key, data)
    return lib.GrDirectContext_precompileShader(direct_context, key, data)
end

function Skia.DirectContext.directContextID(direct_context)
    local obj = lib.GrDirectContext_directContextID(direct_context)
    setFinalizer(obj, lib.static_gr_direct_context_direct_context_id_delete)
    return obj
end

function Skia.DirectContext.maxTextureSize(direct_context)
    return lib.GrDirectContext_maxTextureSize(direct_context)
end

function Skia.DirectContext.maxRenderTargetSize(direct_context)
    return lib.GrDirectContext_maxRenderTargetSize(direct_context)
end

function Skia.DirectContext.colorTypeSupportedAsImage(direct_context, colorType)
    return lib.GrDirectContext_colorTypeSupportedAsImage(direct_context, colorType)
end

function Skia.DirectContext.supportsProtectedContent(direct_context)
    return lib.GrDirectContext_supportsProtectedContent(direct_context)
end

function Skia.DirectContext.colorTypeSupportedAsSurface(direct_context, colorType)
    return lib.GrDirectContext_colorTypeSupportedAsSurface(direct_context, colorType)
end

function Skia.DirectContext.colorTypeSupportedAsSurface_2(direct_context, colorType)
    return lib.GrDirectContext_colorTypeSupportedAsSurface_2(direct_context, colorType)
end

function Skia.DirectContext.maxSurfaceSampleCountForColorType(direct_context, colorType)
    return lib.GrDirectContext_maxSurfaceSampleCountForColorType(direct_context, colorType)
end

function Skia.DirectContext.skCapabilities(direct_context)
    local obj = lib.GrDirectContext_skCapabilities(direct_context)
    setFinalizer(obj, lib.static_const_sk_capabilities_delete)
    return obj
end

function Skia.DirectContext.MakeMock(mockOptions, contextOptions)
    local obj = lib.GrDirectContext_MakeMock(mockOptions, contextOptions)
    setFinalizer(obj, lib.static_gr_direct_context_delete)
    return obj
end

function Skia.DirectContext.MakeMock_2(mockOptions)
    local obj = lib.GrDirectContext_MakeMock_2(mockOptions)
    setFinalizer(obj, lib.static_gr_direct_context_delete)
    return obj
end

-- ## gr_driver_bug_workarounds
Skia.DriverBugWorkarounds = {}

function Skia.DriverBugWorkarounds.new()
    local obj = lib.GrDriverBugWorkarounds_new()
    ffi.gc(obj, lib.GrDriverBugWorkarounds_delete)
    return obj
end

function Skia.DriverBugWorkarounds.new_2(driverBugWorkarounds)
    local obj = lib.GrDriverBugWorkarounds_new_2(driverBugWorkarounds)
    ffi.gc(obj, lib.GrDriverBugWorkarounds_delete)
    return obj
end

function Skia.DriverBugWorkarounds.new_3(workarounds)
    local obj = lib.GrDriverBugWorkarounds_new_3(workarounds)
    ffi.gc(obj, lib.GrDriverBugWorkarounds_delete)
    return obj
end

function Skia.DriverBugWorkarounds.delete(driverBugWorkarounds)
    lib.GrDriverBugWorkarounds_delete(driverBugWorkarounds)
end

function applyOverrides(driverBugWorkarounds, workarounds)
    lib.applyOverrides(driverBugWorkarounds, workarounds)
end

-- ## gr_recording_context
Skia.RecordingContext = {}

function Skia.RecordingContext.delete(recordingContext)
    lib.GrRecordingContext_delete(recordingContext)
end

function Skia.RecordingContext.abandoned(recordingContext)
    return lib.GrRecordingContext_abandoned(recordingContext)
end

function Skia.RecordingContext.colorTypeSupportedAsSurface(recordingContext, colorType)
    return lib.GrRecordingContext_colorTypeSupportedAsSurface(recordingContext, colorType)
end

function Skia.RecordingContext.maxTextureSize(recordingContext)
    return lib.GrRecordingContext_maxTextureSize(recordingContext)
end

function Skia.RecordingContext.maxRenderTargetSize(recordingContext)
    return lib.GrRecordingContext_maxRenderTargetSize(recordingContext)
end

function Skia.RecordingContext.colorTypeSupportedAsImage(recordingContext, colorType)
    return lib.GrRecordingContext_colorTypeSupportedAsImage(recordingContext, colorType)
end

function Skia.RecordingContext.supportsProtectedContent(recordingContext)
    return lib.GrRecordingContext_supportsProtectedContent(recordingContext)
end

function Skia.RecordingContext.maxSurfaceSampleCountForColorType(recordingContext, colorType)
    return lib.GrRecordingContext_maxSurfaceSampleCountForColorType(recordingContext, colorType)
end

function Skia.RecordingContext.skCapabilities(recordingContext)
    local obj = lib.GrRecordingContext_skCapabilities(recordingContext)
    setFinalizer(obj, lib.static_const_sk_capabilities_delete)
    return obj
end

-- ## gr_yuva_backend_texture_info
Skia.YUVABackendTextureInfo = {}

function Skia.YUVABackendTextureInfo.new()
    local obj = lib.GrYUVABackendTextureInfo_new()
    ffi.gc(obj, lib.GrYUVABackendTextureInfo_delete)
    return obj
end

function Skia.YUVABackendTextureInfo.new_2(yuvaInfo, backendFormat, mipmapped, surfaceOrigin)
    local obj = lib.GrYUVABackendTextureInfo_new_2(yuvaInfo, backendFormat, mipmapped, surfaceOrigin)
    ffi.gc(obj, lib.GrYUVABackendTextureInfo_delete)
    return obj
end

function Skia.YUVABackendTextureInfo.new_3(yuvaBackendTextureInfo)
    local obj = lib.GrYUVABackendTextureInfo_new_3(yuvaBackendTextureInfo)
    ffi.gc(obj, lib.GrYUVABackendTextureInfo_delete)
    return obj
end

function Skia.YUVABackendTextureInfo.delete(yuvaBackendTextureInfo)
    lib.GrYUVABackendTextureInfo_delete(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.yuvaInfo(yuvaBackendTextureInfo)
    return lib. GrYUVABackendTextureInfo_yuvaInfo(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.yuvColorSpace(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_yuvColorSpace(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.mipmapped(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_mipmapped(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.textureOrigin(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_textureOrigin(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.numPlanes(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_numPlanes(yuvaBackendTextureInfo)
end

function Skia.YUVABackendTextureInfo.planeFormat(yuvaBackendTextureInfo, i)
    return lib. GrYUVABackendTextureInfo_planeFormat(yuvaBackendTextureInfo, i)
end

function Skia.YUVABackendTextureInfo.isValid(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_isValid(yuvaBackendTextureInfo)
end

-- ## gr_yuva_backend_textures
Skia.YUVABackendTextures = {}

function Skia.YUVABackendTextures.new()
    local obj = lib.GrYUVABackendTextures_new()
    ffi.gc(obj, lib.GrYUVABackendTextures_delete)
    return obj
end

function Skia.YUVABackendTextures.new_2(yuvaInfo, backendTexture, textureOrigin)
    local obj = lib.GrYUVABackendTextures_new_2(yuvaInfo, backendTexture, textureOrigin)
    ffi.gc(obj, lib.GrYUVABackendTextures_delete)
    return obj
end

function Skia.YUVABackendTextures.delete(yuvaBackendTextures)
    lib.GrYUVABackendTextures_delete(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.textures(yuvaBackendTextures)
    return lib. GrYUVABackendTextures_textures(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.texture(yuvaBackendTextures, i)
    local obj = lib.GrYUVABackendTextures_texture(yuvaBackendTextures, i)
    setFinalizer(obj, lib.static_gr_backend_texture_delete)
    return obj
end

function Skia.YUVABackendTextures.yuvaInfo(yuvaBackendTextures)
    return lib. GrYUVABackendTextures_yuvaInfo(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.numPlanes(yuvaBackendTextures)
    return lib.GrYUVABackendTextures_numPlanes(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.textureOrigin(yuvaBackendTextures)
    return lib.GrYUVABackendTextures_textureOrigin(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.isValid(yuvaBackendTextures)
    return lib.GrYUVABackendTextures_isValid(yuvaBackendTextures)
end
]]

-- ## sk_alpha_type
Skia.AlphaType = {}

function Skia.AlphaType.SkAlphaTypeIsOpaque(at)
    return lib.SkAlphaType_SkAlphaTypeIsOpaque(at)
end

-- ## sk_android_codec
Skia.AndroidCodec = {}

function Skia.AndroidCodec.delete(androidCodec)
    lib.SkAndroidCodec_delete(androidCodec)
end

function Skia.AndroidCodec.getInfo(androidCodec)
    return lib.SkAndroidCodec_getInfo(androidCodec)
end

function Skia.AndroidCodec.getICCProfile(androidCodec)
    return lib.SkAndroidCodec_getICCProfile(androidCodec)
end

function Skia.AndroidCodec.getEncodedFormat(androidCodec)
    return lib.SkAndroidCodec_getEncodedFormat(androidCodec)
end

function Skia.AndroidCodec.computeOutputColorType(androidCodec, requestedColorType)
    return lib.SkAndroidCodec_computeOutputColorType(androidCodec, requestedColorType)
end

function Skia.AndroidCodec.computeOutputAlphaType(androidCodec, requestedUnpremul)
    return lib.SkAndroidCodec_computeOutputAlphaType(androidCodec, requestedUnpremul)
end

function Skia.AndroidCodec.computeOutputColorSpace(androidCodec, outputColorType, prefColorSpace)
    local obj = lib.SkAndroidCodec_computeOutputColorSpace(androidCodec, outputColorType, prefColorSpace)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.AndroidCodec.computeSampleSize(androidCodec, size)
    return lib.SkAndroidCodec_computeSampleSize(androidCodec, size)
end

function Skia.AndroidCodec.getSampledDimensions(androidCodec, sampleSize)
    local obj = lib.SkAndroidCodec_getSampledDimensions(androidCodec, sampleSize)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.AndroidCodec.getSupportedSubset(androidCodec, desiredSubset)
    return lib.SkAndroidCodec_getSupportedSubset(androidCodec, desiredSubset)
end

function Skia.AndroidCodec.getSampledSubsetDimensions(androidCodec, sampleSize, subset)
    local obj = lib.SkAndroidCodec_getSampledSubsetDimensions(androidCodec, sampleSize, subset)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.AndroidCodec.getAndroidPixels(androidCodec, info, pixels, rowBytes, options)
    return lib.SkAndroidCodec_getAndroidPixels(androidCodec, info, pixels, rowBytes, options)
end

function Skia.AndroidCodec.getAndroidPixels_2(androidCodec, info, pixels, rowBytes)
    return lib.SkAndroidCodec_getAndroidPixels_2(androidCodec, info, pixels, rowBytes)
end

function Skia.AndroidCodec.getPixels(androidCodec, info, pixels, rowBytes)
    return lib.SkAndroidCodec_getPixels(androidCodec, info, pixels, rowBytes)
end

function Skia.AndroidCodec.codec(androidCodec)
    return lib.SkAndroidCodec_codec(androidCodec)
end

function Skia.AndroidCodec.getAndroidGainmap(androidCodec, outInfo, outGainmapImageStream)
    return lib.SkAndroidCodec_getAndroidGainmap(androidCodec, outInfo, outGainmapImageStream)
end

function Skia.AndroidCodec.MakeFromCodec(codec)
    local obj = lib.SkAndroidCodec_MakeFromCodec(codec)
    setFinalizer(obj, lib.static_sk_android_codec_delete)
    return obj
end

function Skia.AndroidCodec.MakeFromStream(codec, pngChunkReader)
    local obj = lib.SkAndroidCodec_MakeFromStream(codec, pngChunkReader)
    setFinalizer(obj, lib.static_sk_android_codec_delete)
    return obj
end

function Skia.AndroidCodec.MakeFromData(codec, pngChunkReader)
    local obj = lib.SkAndroidCodec_MakeFromData(codec, pngChunkReader)
    setFinalizer(obj, lib.static_sk_android_codec_delete)
    return obj
end

-- ## sk_annotation
Skia.Annotation = {}

function Skia.Annotation.SkAnnotateLinkToDestination(canvas, rect, data)
    lib.SkAnnotation_SkAnnotateLinkToDestination(canvas, rect, data)
end

function Skia.Annotation.SkAnnotateNamedDestination(canvas, point, data)
    lib.SkAnnotation_SkAnnotateNamedDestination(canvas, point, data)
end

function Skia.Annotation.SkAnnotateRectWithURL(canvas, rect, data)
    lib.SkAnnotation_SkAnnotateRectWithURL(canvas, rect, data)
end

-- ## sk_auto_canvas_restore
Skia.AutoCanvasRestore = {}

function Skia.AutoCanvasRestore.new(canvas, doSave)
    return lib.SkAutoCanvasRestore_new(canvas, doSave)
end

function Skia.AutoCanvasRestore.delete(autoCanvasRestore)
    lib.SkAutoCanvasRestore_delete(autoCanvasRestore)
end

function Skia.AutoCanvasRestore.restore(autoCanvasRestore)
    lib.SkAutoCanvasRestore_restore(autoCanvasRestore)
end

-- ## sk_avif_decoder
Skia.AvifDecoder = {}

-- ## sk_b_box_hierarchy
Skia.BBoxHierarchy = {}

function Skia.BBoxHierarchy.delete(b_box_hierarchy)
    lib.SkBBoxHierarchy_delete(b_box_hierarchy)
end

function Skia.BBoxHierarchy.insert(b_box_hierarchy, rect, N)
    lib.SkBBoxHierarchy_insert(b_box_hierarchy, rect, N)
end

function Skia.BBoxHierarchy.insert_2(b_box_hierarchy, rect, metadata, N)
    lib.SkBBoxHierarchy_insert_2(b_box_hierarchy, rect, metadata, N)
end

function Skia.BBoxHierarchy.search(b_box_hierarchy, query, results)
    lib.SkBBoxHierarchy_search(b_box_hierarchy, query, results)
end

function Skia.BBoxHierarchy.bytesUsed(b_box_hierarchy)
    return lib.SkBBoxHierarchy_bytesUsed(b_box_hierarchy)
end

function Skia.BBoxHierarchy.unique(b_box_hierarchy)
    return lib.SkBBoxHierarchy_unique(b_box_hierarchy)
end

function Skia.BBoxHierarchy.ref(b_box_hierarchy)
    lib.SkBBoxHierarchy_ref(b_box_hierarchy)
end

function Skia.BBoxHierarchy.unref(b_box_hierarchy)
    lib.SkBBoxHierarchy_unref(b_box_hierarchy)
end

-- ## sk_bitmap
Skia.Bitmap = {}

function Skia.Bitmap.new()
    local obj = lib.SkBitmap_new()
    ffi.gc(obj, lib.SkBitmap_delete)
    return obj
end

function Skia.Bitmap.new_2(src)
    return lib.SkBitmap_new_2(src)
end

function Skia.Bitmap.delete(bitmap)
    lib.SkBitmap_delete(bitmap)
end

function Skia.Bitmap.allocN32Pixels(bitmap, width, height, isOpaque)
    lib.SkBitmap_allocN32Pixels(bitmap, width, height, isOpaque)
end

function Skia.Bitmap.allocPixels(bitmap)
    lib.SkBitmap_allocPixels(bitmap)
end

function Skia.Bitmap.allocPixels_2(bitmap, allocator)
    lib.SkBitmap_allocPixels_2(bitmap, allocator)
end

function Skia.Bitmap.allocPixels_3(bitmap, info)
    lib.SkBitmap_allocPixels_3(bitmap, info)
end

function Skia.Bitmap.allocPixels_4(bitmap, info, rowBytes)
    lib.SkBitmap_allocPixels_4(bitmap, info, rowBytes)
end

function Skia.Bitmap.allocPixelsFlags(bitmap, info, flags)
    lib.SkBitmap_allocPixelsFlags(bitmap, info, flags)
end

function Skia.Bitmap.alphaType(bitmap)
    return lib.SkBitmap_alphaType(bitmap)
end

function Skia.Bitmap.asImage(bitmap)
    local obj = lib.SkBitmap_asImage(bitmap)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Bitmap.bounds(bitmap)
    local obj = lib.SkBitmap_bounds(bitmap)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Bitmap.bytesPerPixel(bitmap)
    return lib.SkBitmap_bytesPerPixel(bitmap)
end

function Skia.Bitmap.colorSpace(bitmap)
    return lib.SkBitmap_colorSpace(bitmap)
end

function Skia.Bitmap.colorType(bitmap)
    return lib.SkBitmap_colorType(bitmap)
end

function Skia.Bitmap.computeByteSize(bitmap)
    return lib.SkBitmap_computeByteSize(bitmap)
end

function Skia.Bitmap.dimensions(bitmap)
    local obj = lib.SkBitmap_dimensions(bitmap)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Bitmap.drawsNothing(bitmap)
    return lib.SkBitmap_drawsNothing(bitmap)
end

function Skia.Bitmap.empty(bitmap)
    return lib.SkBitmap_empty(bitmap)
end

function Skia.Bitmap.erase(bitmap, c, area)
    lib.SkBitmap_erase(bitmap, c, area)
end

function Skia.Bitmap.erase_2(bitmap, c, area)
    lib.SkBitmap_erase_2(bitmap, c, area)
end

function Skia.Bitmap.eraseArea(bitmap, area, c)
    lib.SkBitmap_eraseArea(bitmap, area, c)
end

function Skia.Bitmap.eraseARGB(bitmap, a, r, g, b)
    lib.SkBitmap_eraseARGB(bitmap, a, r, g, b)
end

function Skia.Bitmap.eraseColor(bitmap, c)
    lib.SkBitmap_eraseColor(bitmap, c)
end

function Skia.Bitmap.eraseColor_2(bitmap, c)
    lib.SkBitmap_eraseColor_2(bitmap, c)
end

function Skia.Bitmap.extractAlpha(bitmap, dst)
    return lib.SkBitmap_extractAlpha(bitmap, dst)
end

function Skia.Bitmap.extractAlpha_2(bitmap, dst, paint, allocator, offset)
    return lib.SkBitmap_extractAlpha_2(bitmap, dst, paint, allocator, offset)
end

function Skia.Bitmap.extractAlpha_3(bitmap, dst, paint, offset)
    return lib.SkBitmap_extractAlpha_3(bitmap, dst, paint, offset)
end

function Skia.Bitmap.extractSubset(bitmap, dst, subset)
    return lib.SkBitmap_extractSubset(bitmap, dst, subset)
end

function Skia.Bitmap.getAddr(bitmap, x, y)
    return lib.SkBitmap_getAddr(bitmap, x, y)
end

function Skia.Bitmap.getAddr16(bitmap, x, y)
    return lib.SkBitmap_getAddr16(bitmap, x, y)
end

function Skia.Bitmap.getAddr32(bitmap, x, y)
    return lib.SkBitmap_getAddr32(bitmap, x, y)
end

function Skia.Bitmap.getAddr8(bitmap, x, y)
    return lib.SkBitmap_getAddr8(bitmap, x, y)
end

function Skia.Bitmap.getAlphaf(bitmap, x, y)
    return lib.SkBitmap_getAlphaf(bitmap, x, y)
end

function Skia.Bitmap.getBounds(bitmap, bounds)
    lib.SkBitmap_getBounds(bitmap, bounds)
end

function Skia.Bitmap.getBounds2(bitmap, bounds)
    lib.SkBitmap_getBounds2(bitmap, bounds)
end

function Skia.Bitmap.getColor(bitmap, x, y)
    return lib.SkBitmap_getColor(bitmap, x, y)
end

function Skia.Bitmap.getColor4f(bitmap, x, y)
    local obj = lib.SkBitmap_getColor4f(bitmap, x, y)
    setFinalizer(obj, lib.static_sk_color_4f_delete)
    return obj
end

function Skia.Bitmap.getGenerationID(bitmap)
    return lib.SkBitmap_getGenerationID(bitmap)
end

function Skia.Bitmap.getPixels(bitmap)
    return lib.SkBitmap_getPixels(bitmap)
end

function Skia.Bitmap.getSubset(bitmap)
    local obj = lib.SkBitmap_getSubset(bitmap)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Bitmap.height(bitmap)
    return lib.SkBitmap_height(bitmap)
end

function Skia.Bitmap.info(bitmap)
    return lib.SkBitmap_info(bitmap)
end

function Skia.Bitmap.installMaskPixels(bitmap, mask)
    return lib.SkBitmap_installMaskPixels(bitmap, mask)
end

function Skia.Bitmap.installPixels(bitmap, info, pixels, rowBytes)
    return lib.SkBitmap_installPixels(bitmap, info, pixels, rowBytes)
end
 
function Skia.Bitmap.installPixels_2(bitmap, info, pixels, rowBytes, releaseProc, context)
    return lib.SkBitmap_installPixels_2(bitmap, info, pixels, rowBytes, releaseProc, context)
end

function Skia.Bitmap.installPixels_3(bitmap, pixmap)
    return lib.SkBitmap_installPixels_3(bitmap, pixmap)
end

function Skia.Bitmap.isImmutable(bitmap)
    return lib.SkBitmap_isImmutable(bitmap)
end

function Skia.Bitmap.isNull(bitmap)
    return lib.SkBitmap_isNull(bitmap)
end

function Skia.Bitmap.isOpaque(bitmap)
    return lib.SkBitmap_isOpaque(bitmap)
end

function Skia.Bitmap.makeShader(bitmap, sampling, lm)
    local obj = lib.SkBitmap_makeShader(bitmap, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Bitmap.makeShader_2(bitmap, sampling, lm)
    local obj = lib.SkBitmap_makeShader_2(bitmap, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Bitmap.makeShader_3(bitmap, tmx, tmy, sampling, localMatrix)
    local obj = lib.SkBitmap_makeShader_3(bitmap, tmx, tmy, sampling, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Bitmap.makeShader_4(bitmap, tmx, tmy, sampling, lm)
    local obj = lib.SkBitmap_makeShader_4(bitmap, tmx, tmy, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Bitmap.notifyPixelsChanged(bitmap)
    lib.SkBitmap_notifyPixelsChanged(bitmap)
end

function Skia.Bitmap.peekPixels(bitmap, pixmap)
    return lib.SkBitmap_peekPixels(bitmap, pixmap)
end

function Skia.Bitmap.pixelRef(bitmap)
    return lib.SkBitmap_pixelRef(bitmap)
end

function Skia.Bitmap.pixelRefOrigin(bitmap)
    local obj = lib.SkBitmap_pixelRefOrigin(bitmap)
    setFinalizer(obj, lib.static_sk_i_point_delete)
    return obj
end

function Skia.Bitmap.pixmap(bitmap)
    return lib.SkBitmap_pixmap(bitmap)
end

function Skia.Bitmap.readPixels(bitmap, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
    return lib.SkBitmap_readPixels(bitmap, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
end

function Skia.Bitmap.readPixels_2(bitmap, dst)
    return lib.SkBitmap_readPixels_2(bitmap, dst)
end

function Skia.Bitmap.readPixels_3(bitmap, dst, srcX, srcY)
    return lib.SkBitmap_readPixels_3(bitmap, dst, srcX, srcY)
end

function Skia.Bitmap.readyToDraw(bitmap)
    return lib.SkBitmap_readyToDraw(bitmap)
end

function Skia.Bitmap.refColorSpace(bitmap)
    local obj = lib.SkBitmap_refColorSpace(bitmap)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.Bitmap.reset(bitmap)
    lib.SkBitmap_reset(bitmap)
end

function Skia.Bitmap.rowBytes(bitmap)
    return lib.SkBitmap_rowBytes(bitmap)
end

function Skia.Bitmap.rowBytesAsPixels(bitmap)
    return lib.SkBitmap_rowBytesAsPixels(bitmap)
end

function Skia.Bitmap.setAlphaType(bitmap, alphaType)
    return lib.SkBitmap_setAlphaType(bitmap, alphaType)
end

function Skia.Bitmap.setImmutable(bitmap)
    lib.SkBitmap_setImmutable(bitmap)
end

function Skia.Bitmap.setInfo(bitmap, imageInfo, rowBytes)
    return lib.SkBitmap_setInfo(bitmap, imageInfo, rowBytes)
end

function Skia.Bitmap.setPixelRef(bitmap, pixelRef, dx, dy)
    lib.SkBitmap_setPixelRef(bitmap, pixelRef, dx, dy)
end

function Skia.Bitmap.setPixels(bitmap, pixels)
    lib.SkBitmap_setPixels(bitmap, pixels)
end

function Skia.Bitmap.shiftPerPixel(bitmap)
    return lib.SkBitmap_shiftPerPixel(bitmap)
end

function Skia.Bitmap.swap(bitmap, other)
    lib.SkBitmap_swap(bitmap, other)
end

function Skia.Bitmap.tryAllocN32Pixels(bitmap, width, height, isOpaque)
    return lib.SkBitmap_tryAllocN32Pixels(bitmap, width, height, isOpaque)
end

function Skia.Bitmap.tryAllocPixels(bitmap)
    return lib.SkBitmap_tryAllocPixels(bitmap)
end

function Skia.Bitmap.tryAllocPixels_2(bitmap, allocator)
    return lib.SkBitmap_tryAllocPixels_2(bitmap, allocator)
end

function Skia.Bitmap.tryAllocPixels_3(bitmap, info)
    return lib.SkBitmap_tryAllocPixels_3(bitmap, info)
end

function Skia.Bitmap.tryAllocPixels_4(bitmap, info, rowBytes)
    return lib.SkBitmap_tryAllocPixels_4(bitmap, info, rowBytes)
end

function Skia.Bitmap.tryAllocPixelsFlags(bitmap, info, flags)
    return lib.SkBitmap_tryAllocPixelsFlags(bitmap, info, flags)
end

function Skia.Bitmap.width(bitmap)
    return lib.SkBitmap_width(bitmap)
end

function Skia.Bitmap.writePixels(bitmap, src)
    return lib.SkBitmap_writePixels(bitmap, src)
end

function Skia.Bitmap.writePixels_2(bitmap, src, dstX, dstY)
    return lib.SkBitmap_writePixels_2(bitmap, src, dstX, dstY)
end

function Skia.Bitmap.ComputeIsOpaque(bm)
    return lib.SkBitmap_ComputeIsOpaque(bm)
end

-- ## sk_blend_mode
Skia.BlendMode = {}

function Skia.BlendMode.SkBlendMode_AsCoeff(mode, src, dst)
    return lib.SkBlendMode_SkBlendMode_AsCoeff(mode, src, dst)
end

function Skia.BlendMode.SkBlendMode_Name(blendMode)
    return lib.SkBlendMode_SkBlendMode_Name(blendMode)
end

-- ## sk_blender
Skia.Blender = {}

function Skia.Blender.delete(blender)
    lib.SkBlender_delete(blender)
end

function Skia.Blender.getFactory(blender)
    local obj = lib.SkBlender_getFactory(blender)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Blender.getTypeName(blender)
    return lib.SkBlender_getTypeName(blender)
end

function Skia.Blender.flatten(blender, write_buffer)
    lib.SkBlender_flatten(blender, write_buffer)
end

function Skia.Blender.getFlattenableType(blender)
    return lib.SkBlender_getFlattenableType(blender)
end

function Skia.Blender.serialize(blender, serial_procs)
    local obj = lib.SkBlender_serialize(blender, serial_procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Blender.serialize_2(blender, memory, memory_size, serial_procs)
    return lib.SkBlender_serialize_2(blender, memory, memory_size, serial_procs)
end

function Skia.Blender.unique(blender)
    return lib.SkBlender_unique(blender)
end

function Skia.Blender.ref(blender)
    lib.SkBlender_ref(blender)
end

function Skia.Blender.unref(blender)
    lib.SkBlender_unref(blender)
end

function Skia.Blender.Mode(mode)
    local obj = lib.SkBlender_Mode(mode)
    setFinalizer(obj, lib.static_sk_blender_delete)
    return obj
end

function Skia.Blender.NameToFactory(name)
    local obj = lib.SkBlender_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Blender.FactoryToName(factory)
    return lib.SkBlender_FactoryToName(factory)
end

function Skia.Blender.Register(name, factory)
    lib.SkBlender_Register(name, factory)
end

function Skia.Blender.Deserialize(type, data, length, procs)
    local obj = lib.SkBlender_Deserialize(type, data, length, procs)
    setFinalizer(obj, lib.static_sk_flattenable_delete)
    return obj
end

-- ## sk_blenders
Skia.Blenders = {}

function Skia.Blenders.Arithmetic(k1, k2, k3, k4, enforcePremul)
    local obj = lib.SkBlenders_Arithmetic(k1, k2, k3, k4, enforcePremul)
    setFinalizer(obj, lib.static_sk_blender_delete)
    return obj
end

-- ## sk_bmp_decoder
Skia.BmpDecoder = {}

function Skia.BmpDecoder.IsBmp(ptr, size)
    return lib.SkBmpDecoder_IsBmp(ptr, size)
end

function Skia.BmpDecoder.Decode(stream, result, decodeContext)
    local obj = lib.SkBmpDecoder_Decode(stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.BmpDecoder.Decode_2(stream, result, decodeContext)
    local obj = lib.SkBmpDecoder_Decode_2(stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.BmpDecoder.Decoder()
    local obj = lib.SkBmpDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

-- ## sk_canvas
Skia.Canvas = {}

function Skia.Canvas.new()
    local obj = lib.SkCanvas_new()
    ffi.gc(obj, lib.SkCanvas_delete)
    return obj
end

function Skia.Canvas.new_2(width, height, props)
    local obj = lib.SkCanvas_new_2(width, height, props)
    ffi.gc(obj, lib.SkCanvas_delete)
    return obj
end

function Skia.Canvas.new_3(bitmap)
    local obj = lib.SkCanvas_new_3(bitmap)
    ffi.gc(obj, lib.SkCanvas_delete)
    return obj
end

function Skia.Canvas.new_4(bitmap, props)
    local obj = lib.SkCanvas_new_4(bitmap, props)
    ffi.gc(obj, lib.SkCanvas_delete)
    return obj
end

function Skia.Canvas.delete(canvas)
    lib.SkCanvas_delete(canvas)
end

function Skia.Canvas.accessTopLayerPixels(canvas, info, rowBytes, origin)
    return lib.SkCanvas_accessTopLayerPixels(canvas, info, rowBytes, origin)
end

function Skia.Canvas.accessTopRasterHandle(canvas)
    return lib.SkCanvas_accessTopRasterHandle(canvas)
end

function Skia.Canvas.androidFramework_setDeviceClipRestriction(canvas, rect)
    lib.SkCanvas_androidFramework_setDeviceClipRestriction(canvas, rect)
end

function Skia.Canvas.clear(canvas, color)
    lib.SkCanvas_clear(canvas, color)
end

function Skia.Canvas.clear_2(canvas, color)
    lib.SkCanvas_clear_2(canvas, color)
end

function Skia.Canvas.clipIRect(canvas, irect, op)
    lib.SkCanvas_clipIRect(canvas, irect, op)
end

function Skia.Canvas.clipPath(canvas, path, doAntiAlias)
    lib.SkCanvas_clipPath(canvas, path, doAntiAlias)
end

function Skia.Canvas.clipPath_2(canvas, path, op)
    lib.SkCanvas_clipPath_2(canvas, path, op)
end

function Skia.Canvas.clipPath_3(canvas, path, op, doAntiAlias)
    lib.SkCanvas_clipPath_3(canvas, path, op, doAntiAlias)
end

function Skia.Canvas.clipRect(canvas, rect, doAntiAlias)
    lib.SkCanvas_clipRect(canvas, rect, doAntiAlias)
end

function Skia.Canvas.clipRect_2(canvas, rect, op)
    lib.SkCanvas_clipRect_2(canvas, rect, op)
end

function Skia.Canvas.clipRect_3(canvas, rect, op, doAntiAlias)
    lib.SkCanvas_clipRect_3(canvas, rect, op, doAntiAlias)
end

function Skia.Canvas.clipRegion(canvas, deviceRgn, op)
    lib.SkCanvas_clipRegion(canvas, deviceRgn, op)
end

function Skia.Canvas.clipRRect(canvas, rrect, doAntiAlias)
    lib.SkCanvas_clipRRect(canvas, rrect, doAntiAlias)
end

function Skia.Canvas.clipRRect_2(canvas, rrect, op)
    lib.SkCanvas_clipRRect_2(canvas, rrect, op)
end

function Skia.Canvas.clipRRect_3(canvas, rrect, op, doAntiAlias)
    lib.SkCanvas_clipRRect_3(canvas, rrect, op, doAntiAlias)
end

function Skia.Canvas.clipShader(canvas, shader, op)
    lib.SkCanvas_clipShader(canvas, shader, op)
end

function Skia.Canvas.concat(canvas, m44)
    lib.SkCanvas_concat(canvas, m44)
end

function Skia.Canvas.concat_2(canvas, matrix)
    lib.SkCanvas_concat_2(canvas, matrix)
end

function Skia.Canvas.discard(canvas)
    lib.SkCanvas_discard(canvas)
end

function Skia.Canvas.drawAnnotation(canvas, rect, key, data)
    lib.SkCanvas_drawAnnotation(canvas, rect, key, data)
end

function Skia.Canvas.drawAnnotation_2(canvas, rect, key, value)
    lib.SkCanvas_drawAnnotation_2(canvas, rect, key, value)
end

function Skia.Canvas.drawArc(canvas, oval, startAngle, sweepAngle, useCenter, paint)
    lib.SkCanvas_drawArc(canvas, oval, startAngle, sweepAngle, useCenter, paint)
end

function Skia.Canvas.drawAtlas(canvas, atlas, xform, tex, colors, count, mode, sampling, cullRect, paint)
    lib.SkCanvas_drawAtlas(canvas, atlas, xform, tex, colors, count, mode, sampling, cullRect, paint)
end

function Skia.Canvas.drawCircle(canvas, center, radius, paint)
    lib.SkCanvas_drawCircle(canvas, center, radius, paint)
end

function Skia.Canvas.drawCircle_2(canvas, cx, cy, radius, paint)
    lib.SkCanvas_drawCircle_2(canvas, cx, cy, radius, paint)
end

function Skia.Canvas.drawColor(canvas, color, mode)
    lib.SkCanvas_drawColor(canvas, color, mode)
end

function Skia.Canvas.drawColor_2(canvas, color, mode)
    lib.SkCanvas_drawColor_2(canvas, color, mode)
end

function Skia.Canvas.drawDrawable(canvas, drawable, matrix)
    lib.SkCanvas_drawDrawable(canvas, drawable, matrix)
end

function Skia.Canvas.drawDrawable_2(canvas, drawable, x, y)
    lib.SkCanvas_drawDrawable_2(canvas, drawable, x, y)
end

function Skia.Canvas.drawDRRect(canvas, outer, inner, paint)
    lib.SkCanvas_drawDRRect(canvas, outer, inner, paint)
end

function Skia.Canvas.drawGlyphs(canvas, count, glyphs, positions, clusters, textByteCount, utf8text, origin, font, paint)
    lib.SkCanvas_drawGlyphs(canvas, count, glyphs, positions, clusters, textByteCount, utf8text, origin, font, paint)
end

function Skia.Canvas.drawGlyphs_2(canvas, count, glyphs, positions, origin, font, paint)
    lib.SkCanvas_drawGlyphs_2(canvas, count, glyphs, positions, origin, font, paint)
end

function Skia.Canvas.drawGlyphs_3(canvas, count, glyphs, xforms, origin, font, paint)
    lib.SkCanvas_drawGlyphs_3(canvas, count, glyphs, xforms, origin, font, paint)
end

function Skia.Canvas.drawImage(canvas, image, left, top)
    lib.SkCanvas_drawImage(canvas, image, left, top)
end

function Skia.Canvas.drawImage_2(canvas, image, x, y, sampling, paint)
    lib.SkCanvas_drawImage_2(canvas, image, x, y, sampling, paint)
end

function Skia.Canvas.drawImage_3(canvas, image, x, y, sampling, paint)
    lib.SkCanvas_drawImage_3(canvas, image, x, y, sampling, paint)
end

function Skia.Canvas.drawImage_4(canvas, image, left, top)
    lib.SkCanvas_drawImage_4(canvas, image, left, top)
end

function Skia.Canvas.drawImageLattice(canvas, image, lattice, dst)
    lib.SkCanvas_drawImageLattice(canvas, image, lattice, dst)
end

function Skia.Canvas.drawImageLattice_2(canvas, image, lattice, dst, filter, paint)
    lib.SkCanvas_drawImageLattice_2(canvas, image, lattice, dst, filter, paint)
end

function Skia.Canvas.drawImageNine(canvas, image, center, dst, filter, paint)
    lib.SkCanvas_drawImageNine(canvas, image, center, dst, filter, paint)
end

function Skia.Canvas.drawImageRect(canvas, image, dst, sampling, paint)
    lib.SkCanvas_drawImageRect(canvas, image, dst, sampling, paint)
end

function Skia.Canvas.drawImageRect_2(canvas, image, src, dst, sampling, paint, constraint)
    lib.SkCanvas_drawImageRect_2(canvas, image, src, dst, sampling, paint, constraint)
end

function Skia.Canvas.drawImageRect_3(canvas, image, dst, sampling, paint)
    lib.SkCanvas_drawImageRect_3(canvas, image, dst, sampling, paint)
end

function Skia.Canvas.drawImageRect_4(canvas, image, src, dst, sampling, paint, constraint)
    lib.SkCanvas_drawImageRect_4(canvas, image, src, dst, sampling, paint, constraint)
end

function Skia.Canvas.drawIRect(canvas, rect, paint)
    lib.SkCanvas_drawIRect(canvas, rect, paint)
end

function Skia.Canvas.drawLine(canvas, p0, p1, paint)
    lib.SkCanvas_drawLine(canvas, p0, p1, paint)
end

function Skia.Canvas.drawLine_2(canvas, x0, y0, x1, y1, paint)
    lib.SkCanvas_drawLine_2(canvas, x0, y0, x1, y1, paint)
end

function Skia.Canvas.drawMesh(canvas, mesh, blender, paint)
    lib.SkCanvas_drawMesh(canvas, mesh, blender, paint)
end

function Skia.Canvas.drawOval(canvas, oval, paint)
    lib.SkCanvas_drawOval(canvas, oval, paint)
end

function Skia.Canvas.drawPaint(canvas, paint)
    lib.SkCanvas_drawPaint(canvas, paint)
end

function Skia.Canvas.drawPatch(canvas, cubics, colors, texCoords, mode, paint)
    lib.SkCanvas_drawPatch(canvas, cubics, colors, texCoords, mode, paint)
end

function Skia.Canvas.drawPath(canvas, path, paint)
    lib.SkCanvas_drawPath(canvas, path, paint)
end

function Skia.Canvas.drawPicture(canvas, picture)
    lib.SkCanvas_drawPicture(canvas, picture)
end

function Skia.Canvas.drawPicture_2(canvas, picture, matrix, paint)
    lib.SkCanvas_drawPicture_2(canvas, picture, matrix, paint)
end

function Skia.Canvas.drawPicture_3(canvas, picture)
    lib.SkCanvas_drawPicture_3(canvas, picture)
end

function Skia.Canvas.drawPicture_4(canvas, picture, matrix, paint)
    lib.SkCanvas_drawPicture_4(canvas, picture, matrix, paint)
end

function Skia.Canvas.drawPoint(canvas, p, paint)
    lib.SkCanvas_drawPoint(canvas, p, paint)
end

function Skia.Canvas.drawPoint_2(canvas, x, y, paint)
    lib.SkCanvas_drawPoint_2(canvas, x, y, paint)
end

function Skia.Canvas.drawPoints(canvas, mode, count, pts, paint)
    lib.SkCanvas_drawPoints(canvas, mode, count, pts, paint)
end

function Skia.Canvas.drawRect(canvas, rect, paint)
    lib.SkCanvas_drawRect(canvas, rect, paint)
end

function Skia.Canvas.drawRegion(canvas, region, paint)
    lib.SkCanvas_drawRegion(canvas, region, paint)
end

function Skia.Canvas.drawRoundRect(canvas, rect, rx, ry, paint)
    lib.SkCanvas_drawRoundRect(canvas, rect, rx, ry, paint)
end

function Skia.Canvas.drawRRect(canvas, rrect, paint)
    lib.SkCanvas_drawRRect(canvas, rrect, paint)
end

function Skia.Canvas.drawSimpleText(canvas, text, byteLength, encoding, x, y, font, paint)
    lib.SkCanvas_drawSimpleText(canvas, text, byteLength, encoding, x, y, font, paint)
end

function Skia.Canvas.drawString(canvas, str, x, y, font, paint)
    lib.SkCanvas_drawString(canvas, str, x, y, font, paint)
end

function Skia.Canvas.drawString_2(canvas, str, x, y, font, paint)
    lib.SkCanvas_drawString_2(canvas, str, x, y, font, paint)
end

function Skia.Canvas.drawTextBlob(canvas, text_blob, x, y, paint)
    lib.SkCanvas_drawTextBlob(canvas, text_blob, x, y, paint)
end

function Skia.Canvas.drawTextBlob_2(canvas, blob, x, y, paint)
    lib.SkCanvas_drawTextBlob_2(canvas, blob, x, y, paint)
end

function Skia.Canvas.drawVertices(canvas, vertices, mode, paint)
    lib.SkCanvas_drawVertices(canvas, vertices, mode, paint)
end

function Skia.Canvas.drawVertices_2(canvas, vertices, mode, paint)
    lib.SkCanvas_drawVertices_2(canvas, vertices, mode, paint)
end

function Skia.Canvas.experimental_DrawEdgeAAImageSet(canvas, imageSet, cnt, dstClips, preViewMatrices, sampling, paint, constraint)
    lib.SkCanvas_experimental_DrawEdgeAAImageSet(canvas, imageSet, cnt, dstClips, preViewMatrices, sampling, paint, constraint)
end

function Skia.Canvas.experimental_DrawEdgeAAQuad(canvas, rect, clip, aaFlags, color, mode)
    lib.SkCanvas_experimental_DrawEdgeAAQuad(canvas, rect, clip, aaFlags, color, mode)
end

function Skia.Canvas.experimental_DrawEdgeAAQuad_2(canvas, rect, clip, aaFlags, color, mode)
    lib.SkCanvas_experimental_DrawEdgeAAQuad_2(canvas, rect, clip, aaFlags, color, mode)
end

function Skia.Canvas.getBaseLayerSize(canvas)
    local obj = lib.SkCanvas_getBaseLayerSize(canvas)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Canvas.getBaseProps(canvas)
    local obj = lib.SkCanvas_getBaseProps(canvas)
    setFinalizer(obj, lib.static_sk_surface_props_delete)
    return obj
end

function Skia.Canvas.getDeviceClipBounds(canvas)
    local obj = lib.SkCanvas_getDeviceClipBounds(canvas)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Canvas.getDeviceClipBounds_2(canvas, bounds)
    return lib.SkCanvas_getDeviceClipBounds_2(canvas, bounds)
end

function Skia.Canvas.getLocalClipBounds(canvas)
    local obj = lib.SkCanvas_getLocalClipBounds(canvas)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Canvas.getLocalClipBounds_2(canvas, bounds)
    return lib.SkCanvas_getLocalClipBounds_2(canvas, bounds)
end

function Skia.Canvas.getLocalToDevice(canvas)
    local obj = lib.SkCanvas_getLocalToDevice(canvas)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.Canvas.getLocalToDeviceAs3x3(canvas)
    local obj = lib.SkCanvas_getLocalToDeviceAs3x3(canvas)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Canvas.getProps(canvas, props)
    return lib.SkCanvas_getProps(canvas, props)
end

function Skia.Canvas.getSaveCount(canvas)
    return lib.SkCanvas_getSaveCount(canvas)
end

function Skia.Canvas.getSurface(canvas)
    return lib.SkCanvas_getSurface(canvas)
end

function Skia.Canvas.getTopProps(canvas)
    local obj = lib.SkCanvas_getTopProps(canvas)
    setFinalizer(obj, lib.static_sk_surface_props_delete)
    return obj
end

function Skia.Canvas.getTotalMatrix(canvas)
    local obj = lib.SkCanvas_getTotalMatrix(canvas)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Canvas.imageInfo(canvas)
    local obj = lib.SkCanvas_imageInfo(canvas)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.Canvas.isClipEmpty(canvas)
    return lib.SkCanvas_isClipEmpty(canvas)
end

function Skia.Canvas.isClipRect(canvas)
    return lib.SkCanvas_isClipRect(canvas)
end

function Skia.Canvas.makeSurface(canvas, info, props)
    local obj = lib.SkCanvas_makeSurface(canvas, info, props)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Canvas.peekPixels(canvas, pixmap)
    return lib.SkCanvas_peekPixels(canvas, pixmap)
end

function Skia.Canvas.private_draw_shadow_rec(canvas, path, rec)
    lib.SkCanvas_private_draw_shadow_rec(canvas, path, rec)
end

function Skia.Canvas.quickReject(canvas, path)
    return lib.SkCanvas_quickReject(canvas, path)
end

function Skia.Canvas.quickReject_2(canvas, rect)
    return lib.SkCanvas_quickReject_2(canvas, rect)
end

function Skia.Canvas.readPixels(canvas, bitmap, srcX, srcY)
    return lib.SkCanvas_readPixels(canvas, bitmap, srcX, srcY)
end

function Skia.Canvas.readPixels_2(canvas, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
    return lib.SkCanvas_readPixels_2(canvas, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
end

function Skia.Canvas.readPixels_3(canvas, pixmap, srcX, srcY)
    return lib.SkCanvas_readPixels_3(canvas, pixmap, srcX, srcY)
end

function Skia.Canvas.recorder(canvas)
    return lib.SkCanvas_recorder(canvas)
end

function Skia.Canvas.recordingContext(canvas)
    return lib.SkCanvas_recordingContext(canvas)
end

function Skia.Canvas.resetMatrix(canvas)
    lib.SkCanvas_resetMatrix(canvas)
end

function Skia.Canvas.restore(canvas)
    lib.SkCanvas_restore(canvas)
end

function Skia.Canvas.restoreToCount(canvas, saveCount)
    lib.SkCanvas_restoreToCount(canvas, saveCount)
end

function Skia.Canvas.rotate(canvas, degrees)
    lib.SkCanvas_rotate(canvas, degrees)
end

function Skia.Canvas.rotate_2(canvas, degrees, px, py)
    lib.SkCanvas_rotate_2(canvas, degrees, px, py)
end

function Skia.Canvas.save(canvas)
    return lib.SkCanvas_save(canvas)
end

function Skia.Canvas.saveLayer(canvas, layerRec)
    return lib.SkCanvas_saveLayer(canvas, layerRec)
end

function Skia.Canvas.saveLayer_2(canvas, bounds, paint)
    return lib.SkCanvas_saveLayer_2(canvas, bounds, paint)
end

function Skia.Canvas.saveLayer_3(canvas, bounds, paint)
    return lib.SkCanvas_saveLayer_3(canvas, bounds, paint)
end

function Skia.Canvas.saveLayerAlpha(canvas, bounds, alpha)
    return lib.SkCanvas_saveLayerAlpha(canvas, bounds, alpha)
end

function Skia.Canvas.saveLayerAlphaf(canvas, bounds, alpha)
    return lib.SkCanvas_saveLayerAlphaf(canvas, bounds, alpha)
end

function Skia.Canvas.scale(canvas, sx, sy)
    lib.SkCanvas_scale(canvas, sx, sy)
end

function Skia.Canvas.setMatrix(canvas, matrix)
    lib.SkCanvas_setMatrix(canvas, matrix)
end

function Skia.Canvas.setMatrix_2(canvas, matrix)
    lib.SkCanvas_setMatrix_2(canvas, matrix)
end

function Skia.Canvas.skew(canvas, sx, sy)
    lib.SkCanvas_skew(canvas, sx, sy)
end

function Skia.Canvas.temporary_internal_getRgnClip(canvas, region)
    lib.SkCanvas_temporary_internal_getRgnClip(canvas, region)
end

function Skia.Canvas.translate(canvas, dx, dy)
    lib.SkCanvas_translate(canvas, dx, dy)
end

function Skia.Canvas.writePixels(canvas, bitmap, x, y)
    return lib.SkCanvas_writePixels(canvas, bitmap, x, y)
end

function Skia.Canvas.writePixels_2(canvas, info, pixels, rowBytes, x, y)
    return lib.SkCanvas_writePixels_2(canvas, info, pixels, rowBytes, x, y)
end

function Skia.Canvas.MakeRasterDirect(info, pixels, rowBytes, props)
    local obj = lib.SkCanvas_MakeRasterDirect(info, pixels, rowBytes, props)
    setFinalizer(obj, lib.static_sk_canvas_delete)
    return obj
end

function Skia.Canvas.MakeRasterDirectN32(width, height, pixels, rowBytes)
    local obj = lib.SkCanvas_MakeRasterDirectN32(width, height, pixels, rowBytes)
    setFinalizer(obj, lib.static_sk_canvas_delete)
    return obj
end

-- ## sk_capabilities
Skia.Capabilities = {}

function Skia.Capabilities.delete(capabilities)
    lib.SkCapabilities_delete(capabilities)
end

function Skia.Capabilities.ref(capabilities)
    lib.SkCapabilities_ref(capabilities)
end

function Skia.Capabilities.skslVersion(capabilities)
    return lib.SkCapabilities_skslVersion(capabilities)
end

function Skia.Capabilities.unique(capabilities)
    return lib.SkCapabilities_unique(capabilities)
end

function Skia.Capabilities.unref(capabilities)
    lib.SkCapabilities_unref(capabilities)
end

function Skia.Capabilities.RasterBackend()
    local obj = lib.SkCapabilities_RasterBackend()
    setFinalizer(obj, lib.static_const_sk_capabilities_delete)
    return obj
end

-- ## sk_codec
Skia.Codec = {}

function Skia.Codec.delete(codec)
    lib.SkCodec_delete(codec)
end

function Skia.Codec.getInfo(codec)
    local obj = lib.SkCodec_getInfo(codec)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.Codec.dimensions(codec)
    local obj = lib.SkCodec_dimensions(codec)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Codec.bounds(codec)
    local obj = lib.SkCodec_bounds(codec)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Codec.getICCProfile(codec)
    return lib.SkCodec_getICCProfile(codec)
end

function Skia.Codec.getOrigin(codec)
    return lib.SkCodec_getOrigin(codec)
end

function Skia.Codec.getScaledDimensions(codec, desiredScale)
    local obj = lib.SkCodec_getScaledDimensions(codec, desiredScale)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Codec.getValidSubset(codec, desiredSubset)
    return lib.SkCodec_getValidSubset(codec, desiredSubset)
end

function Skia.Codec.getEncodedFormat(codec)
    return lib.SkCodec_getEncodedFormat(codec)
end

function Skia.Codec.getPixels(codec, info, pixels, rowBytes, options)
    return lib.SkCodec_getPixels(codec, info, pixels, rowBytes, options)
end

function Skia.Codec.getPixels_2(codec, info, pixels, rowBytes)
    return lib.SkCodec_getPixels_2(codec, info, pixels, rowBytes)
end

function Skia.Codec.getPixels_3(codec, pm, opts)
    return lib.SkCodec_getPixels_3(codec, pm, opts)
end

function Skia.Codec.getImage(codec, info, opts)
    return lib.SkCodec_getImage(codec, info, opts)
end

function Skia.Codec.getImage_2(codec)
    return lib.SkCodec_getImage_2(codec)
end

function Skia.Codec.queryYUVAInfo(codec, supportedDataTypes, yuvaPixmapInfo)
    return lib.SkCodec_queryYUVAInfo(codec, supportedDataTypes, yuvaPixmapInfo)
end

function Skia.Codec.getYUVAPlanes(codec, yuvaPixmaps)
    return lib.SkCodec_getYUVAPlanes(codec, yuvaPixmaps)
end

function Skia.Codec.startIncrementalDecode(codec, dstInfo, dst, rowBytes, options)
    return lib.SkCodec_startIncrementalDecode(codec, dstInfo, dst, rowBytes, options)
end

function Skia.Codec.startIncrementalDecode_2(codec, dstInfo, dst, rowBytes)
    return lib.SkCodec_startIncrementalDecode_2(codec, dstInfo, dst, rowBytes)
end

function Skia.Codec.incrementalDecode(codec, rowsDecoded)
    return lib.SkCodec_incrementalDecode(codec, rowsDecoded)
end

function Skia.Codec.startScanlineDecode(codec, dstInfo, options)
    return lib.SkCodec_startScanlineDecode(codec, dstInfo, options)
end

function Skia.Codec.startScanlineDecode_2(codec, dstInfo)
    return lib.SkCodec_startScanlineDecode_2(codec, dstInfo)
end

function Skia.Codec.getScanlines(codec, dst, countLines, rowBytes)
    return lib.SkCodec_getScanlines(codec, dst, countLines, rowBytes)
end

function Skia.Codec.skipScanlines(codec, countLines)
    return lib.SkCodec_skipScanlines(codec, countLines)
end

function Skia.Codec.getScanlineOrder(codec)
    return lib.SkCodec_getScanlineOrder(codec)
end

function Skia.Codec.nextScanline(codec)
    return lib.SkCodec_nextScanline(codec)
end

function Skia.Codec.outputScanline(codec, inputScanline)
    return lib.SkCodec_outputScanline(codec, inputScanline)
end

function Skia.Codec.getFrameCount(codec)
    return lib.SkCodec_getFrameCount(codec)
end

function Skia.Codec.getFrameInfo(codec, index, info)
    return lib.SkCodec_getFrameInfo(codec, index, info)
end

function Skia.Codec.getFrameInfo_2(codec)
    return lib.SkCodec_getFrameInfo_2(codec)
end

function Skia.Codec.getRepetitionCount(codec)
    return lib.SkCodec_getRepetitionCount(codec)
end

function Skia.Codec.MinBufferedBytesNeeded()
    return lib.SkCodec_MinBufferedBytesNeeded()
end

function Skia.Codec.ResultToString(result)
    return lib.SkCodec_ResultToString(result)
end

function Skia.Codec.MakeFromStream(stream, result, pngChunkReader, selectionPolicy)
    local obj = lib.SkCodec_MakeFromStream(stream, result, pngChunkReader, selectionPolicy)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.Codec.MakeFromData(stream, pngChunkReader)
    local obj = lib.SkCodec_MakeFromData(stream, pngChunkReader)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

-- ## sk_codecs
Skia.Codecs = {}

-- ## sk_color
Skia.Color = {}

function Skia.Color.SkColorSetA(c, a)
    return lib.SkColor_SkColorSetA(c, a)
end

function Skia.Color.SkColorSetARGB(a, r, g, b)
    return lib.SkColor_SkColorSetARGB(a, r, g, b)
end

function Skia.Color.SkColorToHSV(color, hsv)
    lib.SkColor_SkColorToHSV(color, hsv)
end

function Skia.Color.SkHSVToColor(hsv)
    return lib.SkColor_SkHSVToColor(hsv)
end

function Skia.Color.SkHSVToColor_2(alpha, hsv)
    return lib.SkColor_SkHSVToColor_2(alpha, hsv)
end

function Skia.Color.SkPreMultiplyARGB(a, r, g, b)
    return lib.SkColor_SkPreMultiplyARGB(a, r, g, b)
end

function Skia.Color.SkPreMultiplyColor(c)
    return lib.SkColor_SkPreMultiplyColor(c)
end

function Skia.Color.SkRGBToHSV(red, green, blue, hsv)
    lib.SkColor_SkRGBToHSV(red, green, blue, hsv)
end

-- ## sk_color_filter
Skia.ColorFilter = {}

function Skia.ColorFilter.delete(color_filter)
    lib.SkColorFilter_delete(color_filter)
end

function Skia.ColorFilter.asAColorMode(color_filter, color, mode)
    return lib.SkColorFilter_asAColorMode(color_filter, color, mode)
end

function Skia.ColorFilter.asAColorMatrix(color_filter, matrix)
    return lib.SkColorFilter_asAColorMatrix(color_filter, matrix)
end

function Skia.ColorFilter.isAlphaUnchanged(color_filter)
    return lib.SkColorFilter_isAlphaUnchanged(color_filter)
end

function Skia.ColorFilter.filterColor(color_filter, color)
    return lib.SkColorFilter_filterColor(color_filter, color)
end

function Skia.ColorFilter.filterColor4f(color_filter, srcColor, srcCS, dstCS)
    local obj = lib.SkColorFilter_filterColor4f(color_filter, srcColor, srcCS, dstCS)
    setFinalizer(obj, lib.static_sk_color_4f_delete)
    return obj
end

function Skia.ColorFilter.makeComposed(color_filter, inner)
    local obj = lib.SkColorFilter_makeComposed(color_filter, inner)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilter.makeWithWorkingColorSpace(color_filter, colorSpace)
    local obj = lib.SkColorFilter_makeWithWorkingColorSpace(color_filter, colorSpace)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilter.getFactory(color_filter)
    local obj = lib.SkColorFilter_getFactory(color_filter)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ColorFilter.getTypeName(color_filter)
    return lib.SkColorFilter_getTypeName(color_filter)
end

function Skia.ColorFilter.flatten(color_filter, write_buffer)
    lib.SkColorFilter_flatten(color_filter, write_buffer)
end

function Skia.ColorFilter.getFlattenableType(color_filter)
    return lib.SkColorFilter_getFlattenableType(color_filter)
end

function Skia.ColorFilter.serialize(color_filter, serial_procs)
    local obj = lib.SkColorFilter_serialize(color_filter, serial_procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ColorFilter.serialize_2(color_filter, memory, memory_size, serial_procs)
    return lib.SkColorFilter_serialize_2(color_filter, memory, memory_size, serial_procs)
end

function Skia.ColorFilter.unique(color_filter)
    return lib.SkColorFilter_unique(color_filter)
end

function Skia.ColorFilter.ref(color_filter)
    lib.SkColorFilter_ref(color_filter)
end

function Skia.ColorFilter.unref(color_filter)
    lib.SkColorFilter_unref(color_filter)
end

function Skia.ColorFilter.Deserialize(data, size, procs)
    local obj = lib.SkColorFilter_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilter.NameToFactory(name)
    local obj = lib.SkColorFilter_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ColorFilter.FactoryToName(factory)
    return lib.SkColorFilter_FactoryToName(factory)
end

function Skia.ColorFilter.Register(name, factory)
    lib.SkColorFilter_Register(name, factory)
end

-- ## sk_color_filters
Skia.ColorFilters = {}

function Skia.ColorFilters.delete(colorFilters)
    lib.SkColorFilters_delete(colorFilters)
end

function Skia.ColorFilters.Blend(c, color_space, mode)
    local obj = lib.SkColorFilters_Blend(c, color_space, mode)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Blend_2(c, mode)
    local obj = lib.SkColorFilters_Blend_2(c, mode)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Compose(color_filter1, color_filter2)
    local obj = lib.SkColorFilters_Compose(color_filter1, color_filter2)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.HSLAMatrix(rowMajor)
    local obj = lib.SkColorFilters_HSLAMatrix(rowMajor)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.HSLAMatrix_2(matrix)
    local obj = lib.SkColorFilters_HSLAMatrix_2(matrix)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Lerp(t, color_filter1, color_filter2)
    local obj = lib.SkColorFilters_Lerp(t, color_filter1, color_filter2)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Lighting(mul, add)
    local obj = lib.SkColorFilters_Lighting(mul, add)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.LinearToSRGBGamma()
    local obj = lib.SkColorFilters_LinearToSRGBGamma()
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Matrix(rowMajor)
    local obj = lib.SkColorFilters_Matrix(rowMajor)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Matrix_2(matrix)
    local obj = lib.SkColorFilters_Matrix_2(matrix)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.SRGBToLinearGamma()
    local obj = lib.SkColorFilters_SRGBToLinearGamma()
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Table(utable)
    local obj = lib.SkColorFilters_Table(utable)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.Table_2(color_table)
    local obj = lib.SkColorFilters_Table_2(color_table)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorFilters.TableARGB(utableA, tableR, tableG, tableB)
    local obj = lib.SkColorFilters_TableARGB(utableA, tableR, tableG, tableB)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

-- ## sk_color_info
Skia.ColorInfo = {}

function Skia.ColorInfo.new()
    local obj = lib.SkColorInfo_new()
    ffi.gc(obj, lib.SkColorInfo_delete)
    return obj
end

function Skia.ColorInfo.new_2(ct, at, color_space)
    local obj = lib.SkColorInfo_new_2(ct, at, color_space)
    ffi.gc(obj, lib.SkColorInfo_delete)
    return obj
end

function Skia.ColorInfo.new_3(color_info)
    local obj = lib.SkColorInfo_new_3(color_info)
    ffi.gc(obj, lib.SkColorInfo_delete)
    return obj
end

function Skia.ColorInfo.delete(color_info)
    lib.SkColorInfo_delete(color_info)
end

function Skia.ColorInfo.alphaType(color_info)
    return lib.SkColorInfo_alphaType(color_info)
end

function Skia.ColorInfo.bytesPerPixel(color_info)
    return lib.SkColorInfo_bytesPerPixel(color_info)
end

function Skia.ColorInfo.colorSpace(color_info)
    return lib.SkColorInfo_colorSpace(color_info)
end

function Skia.ColorInfo.colorType(color_info)
    return lib.SkColorInfo_colorType(color_info)
end

function Skia.ColorInfo.gammaCloseToSRGB(color_info)
    return lib.SkColorInfo_gammaCloseToSRGB(color_info)
end

function Skia.ColorInfo.isOpaque(color_info)
    return lib.SkColorInfo_isOpaque(color_info)
end

function Skia.ColorInfo.makeAlphaType(color_info, newAlphaType)
    local obj = lib.SkColorInfo_makeAlphaType(color_info, newAlphaType)
    setFinalizer(obj, lib.static_sk_color_info_delete)
    return obj
end

function Skia.ColorInfo.makeColorSpace(color_info, color_space)
    local obj  lib.SkColorInfo_makeColorSpace(color_info, color_space)
    setFinalizer(obj, lib.static_sk_color_info_delete)
    return obj
end

function Skia.ColorInfo.makeColorType(color_info, newColorType)
    local obj  lib.SkColorInfo_makeColorType(color_info, newColorType)
    setFinalizer(obj, lib.static_sk_color_info_delete)
    return obj
end

function Skia.ColorInfo.refColorSpace(color_info)
    local obj  lib.SkColorInfo_refColorSpace(color_info)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorInfo.shiftPerPixel(color_info)
    return lib.SkColorInfo_shiftPerPixel(color_info)
end

-- ## sk_color_matrix
Skia.ColorMatrix = {}

function Skia.ColorMatrix.new()
    local obj = lib.SkColorMatrix_new()
    ffi.gc(obj, lib.SkColorMatrix_delete)
    return obj
end

function Skia.ColorMatrix.new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)
    local obj = lib.SkColorMatrix_new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)
    ffi.gc(obj, lib.SkColorMatrix_delete)
    return obj
end

function Skia.ColorMatrix.delete(color_matrix)
    lib.SkColorMatrix_delete(color_matrix)
end

function Skia.ColorMatrix.setIdentity(color_matrix)
    lib.SkColorMatrix_setIdentity(color_matrix)
end

function Skia.ColorMatrix.setScale(color_matrix, rScale, gScale, bScale, aScale)
    lib.SkColorMatrix_setScale(color_matrix, rScale, gScale, bScale, aScale)
end

function Skia.ColorMatrix.postTranslate(color_matrix, dr, dg, db, da)
    lib.SkColorMatrix_postTranslate(color_matrix, dr, dg, db, da)
end

function Skia.ColorMatrix.setConcat(color_matrix, a, b)
    lib.SkColorMatrix_setConcat(color_matrix, a, b)
end

function Skia.ColorMatrix.preConcat(color_matrix, mat)
    lib.SkColorMatrix_preConcat(color_matrix, mat)
end

function Skia.ColorMatrix.postConcat(color_matrix, mat)
    lib.SkColorMatrix_postConcat(color_matrix, mat)
end

function Skia.ColorMatrix.setSaturation(color_matrix, sat)
    lib.SkColorMatrix_setSaturation(color_matrix, sat)
end

function Skia.ColorMatrix.setRowMajor(color_matrix, src)
    lib.SkColorMatrix_setRowMajor(color_matrix, src)
end

function Skia.ColorMatrix.getRowMajor(color_matrix, dst)
    lib.SkColorMatrix_getRowMajor(color_matrix, dst)
end

function Skia.ColorMatrix.RGBtoYUV(color_space)
    local obj = lib.SkColorMatrix_RGBtoYUV(color_space)
    setFinalizer(obj, lib.static_sk_color_matrix_delete)
    return obj
end

function Skia.ColorMatrix.YUVtoRGB(color_space)
    local obj = lib.SkColorMatrix_YUVtoRGB(color_space)
    setFinalizer(obj, lib.static_sk_color_matrix_delete)
    return obj
end

-- ## sk_color_matrix_filter
Skia.ColorMatrixFilter = {}

function Skia.ColorMatrixFilter.delete(color_matrix_filter)
    lib.SkColorMatrixFilter_delete(color_matrix_filter)
end

function Skia.ColorMatrixFilter.asAColorMode(color_matrix_filter, color, mode)
    return lib.SkColorMatrixFilter_asAColorMode(color_matrix_filter, color, mode)
end

function Skia.ColorMatrixFilter.asAColorMatrix(color_matrix_filter, matrix)
    return lib.SkColorMatrixFilter_asAColorMatrix(color_matrix_filter, matrix)
end

function Skia.ColorMatrixFilter.isAlphaUnchanged(color_matrix_filter)
    return lib.SkColorMatrixFilter_isAlphaUnchanged(color_matrix_filter)
end

function Skia.ColorMatrixFilter.filterColor(color_matrix_filter, color)
    return lib.SkColorMatrixFilter_filterColor(color_matrix_filter, color)
end

function Skia.ColorMatrixFilter.filterColor4f(color_matrix_filter, srcColor, srcCS, dstCS)
    local obj = lib.SkColorMatrixFilter_filterColor4f(color_matrix_filter, srcColor, srcCS, dstCS)
    setFinalizer(obj, lib.static_sk_color_4f_delete)
    return obj
end

function Skia.ColorMatrixFilter.makeComposed(color_matrix_filter, colorFilter)
    local obj = lib.SkColorMatrixFilter_makeComposed(color_matrix_filter, colorFilter)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorMatrixFilter.makeWithWorkingColorSpace(color_matrix_filter, colorSpace)
    local obj = lib.SkColorMatrixFilter_makeWithWorkingColorSpace(color_matrix_filter, colorSpace)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorMatrixFilter.getFactory(color_matrix_filter)
    local obj = lib.SkColorMatrixFilter_getFactory(color_matrix_filter)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ColorMatrixFilter.getTypeName(color_matrix_filter)
    return lib. SkColorMatrixFilter_getTypeName(color_matrix_filter)
end

function Skia.ColorMatrixFilter.flatten(color_matrix_filter, write_buffer)
    lib.SkColorMatrixFilter_flatten(color_matrix_filter, write_buffer)
end

function Skia.ColorMatrixFilter.getFlattenableType(color_matrix_filter)
    return lib.SkColorMatrixFilter_getFlattenableType(color_matrix_filter)
end

function Skia.ColorMatrixFilter.serialize(color_matrix_filter, serial_procs)
    local obj = lib.SkColorMatrixFilter_serialize(color_matrix_filter, serial_procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ColorMatrixFilter.serialize_2(color_matrix_filter, memory, memory_size, serial_procs)
    return lib.SkColorMatrixFilter_serialize_2(color_matrix_filter, memory, memory_size, serial_procs)
end

function Skia.ColorMatrixFilter.unique(color_matrix_filter)
    return lib.SkColorMatrixFilter_unique(color_matrix_filter)
end

function Skia.ColorMatrixFilter.ref(color_matrix_filter)
    lib.SkColorMatrixFilter_ref(color_matrix_filter)
end

function Skia.ColorMatrixFilter.unref(color_matrix_filter)
    lib.SkColorMatrixFilter_unref(color_matrix_filter)
end

function Skia.ColorMatrixFilter.MakeLightingFilter(mul, add)
    local obj = lib.SkColorMatrixFilter_MakeLightingFilter(mul, add)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorMatrixFilter.Deserialize(data, size, procs)
    local obj = lib.SkColorMatrixFilter_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.ColorMatrixFilter.NameToFactory(name)
    local obj = lib.SkColorMatrixFilter_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ColorMatrixFilter.FactoryToName(factory)
    return lib. SkColorMatrixFilter_FactoryToName(factory)
end

function Skia.ColorMatrixFilter.Register(name, factory)
    lib.SkColorMatrixFilter_Register(name, factory)
end

-- ## sk_color_priv
Skia.ColorPriv = {}

function Skia.ColorPriv.SkAlpha255To256(alpha)
    return lib.SkColorPriv_SkAlpha255To256(alpha)
end

function Skia.ColorPriv.SkAlphaMulQ(c, scale)
    return lib.SkColorPriv_SkAlphaMulQ(c, scale)
end

function Skia.ColorPriv.SkPackARGB32(a, r, g, b)
    return lib.SkColorPriv_SkPackARGB32(a, r, g, b)
end

function Skia.ColorPriv.SkPackARGB32NoCheck(a, r, g, b)
    return lib.SkColorPriv_SkPackARGB32NoCheck(a, r, g, b)
end

function Skia.ColorPriv.SkPMSrcOver(src, dst)
    return lib.SkColorPriv_SkPMSrcOver(src, dst)
end

function Skia.ColorPriv.SkPremultiplyARGBInline(a, r, g, b)
    return lib.SkColorPriv_SkPremultiplyARGBInline(a, r, g, b)
end

function Skia.ColorPriv.SkUnitScalarClampToByte(x)
    return lib.SkColorPriv_SkUnitScalarClampToByte(x)
end

-- ## sk_color_space
Skia.ColorSpace = {}

function Skia.ColorSpace.delete(color_space)
    lib.SkColorSpace_delete(color_space)
end

function Skia.ColorSpace.toProfile(color_space, profile)
    lib.SkColorSpace_toProfile(color_space, profile)
end

function Skia.ColorSpace.gammaCloseToSRGB(color_space)
    return lib.SkColorSpace_gammaCloseToSRGB(color_space)
end

function Skia.ColorSpace.gammaIsLinear(color_space)
    return lib.SkColorSpace_gammaIsLinear(color_space)
end

function Skia.ColorSpace.isNumericalTransferFn(color_space, fn)
    return lib.SkColorSpace_isNumericalTransferFn(color_space, fn)
end

function Skia.ColorSpace.toXYZD50(color_space, toXYZD50)
    return lib.SkColorSpace_toXYZD50(color_space, toXYZD50)
end

function Skia.ColorSpace.toXYZD50Hash(color_space)
    return lib.SkColorSpace_toXYZD50Hash(color_space)
end

function Skia.ColorSpace.makeLinearGamma(color_space)
    local obj = lib.SkColorSpace_makeLinearGamma(color_space)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.makeSRGBGamma(color_space)
    local obj = lib.SkColorSpace_makeSRGBGamma(color_space)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.makeColorSpin(color_space)
    local obj = lib.SkColorSpace_makeColorSpin(color_space)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.isSRGB(color_space)
    return lib.SkColorSpace_isSRGB(color_space)
end

function Skia.ColorSpace.serialize(color_space)
    local obj = lib.SkColorSpace_serialize(color_space)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ColorSpace.writeToMemory(color_space, memory)
    return lib.SkColorSpace_writeToMemory(color_space, memory)
end

function Skia.ColorSpace.transferFn(color_space, gabcdef)
    lib.SkColorSpace_transferFn(color_space, gabcdef)
end

function Skia.ColorSpace.transferFn_2(color_space, fn)
    lib.SkColorSpace_transferFn_2(color_space, fn)
end

function Skia.ColorSpace.invTransferFn(color_space, fn)
    lib.SkColorSpace_invTransferFn(color_space, fn)
end

function Skia.ColorSpace.gamutTransformTo(color_space, dst, src_to_dst)
    lib.SkColorSpace_gamutTransformTo(color_space, dst, src_to_dst)
end

function Skia.ColorSpace.transferFnHash(color_space)
    return lib.SkColorSpace_transferFnHash(color_space)
end

function Skia.ColorSpace.hash(color_space)
    return lib.SkColorSpace_hash(color_space)
end

function Skia.ColorSpace.unique(color_space)
    return lib.SkColorSpace_unique(color_space)
end

function Skia.ColorSpace.ref(color_space)
    lib.SkColorSpace_ref(color_space)
end

function Skia.ColorSpace.unref(color_space)
    lib.SkColorSpace_unref(color_space)
end

function Skia.ColorSpace.deref(color_space)
    lib.SkColorSpace_deref(color_space)
end

function Skia.ColorSpace.refCntGreaterThan(color_space, threadIsolatedTestCnt)
    return lib.SkColorSpace_refCntGreaterThan(color_space, threadIsolatedTestCnt)
end

function Skia.ColorSpace.MakeSRGB()
    local obj = lib.SkColorSpace_MakeSRGB()
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.MakeSRGBLinear()
    local obj = lib.SkColorSpace_MakeSRGBLinear()
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.MakeRGB(transferFn, toXYZ)
    local obj = lib.SkColorSpace_MakeRGB(transferFn, toXYZ)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.Make(profile)
    local obj = lib.SkColorSpace_Make(profile)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.Deserialize(data, length)
    local obj = lib.SkColorSpace_Deserialize(data, length)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ColorSpace.Equals(color_space_1, color_space_2)
    return lib.SkColorSpace_Equals(color_space_1, color_space_2)
end

-- ## sk_color_space_primaries
Skia.ColorSpacePrimaries = {}

function Skia.ColorSpacePrimaries.delete(color_pace_primaries)
    lib.SkColorSpacePrimaries_delete(color_pace_primaries)
end

function Skia.ColorSpacePrimaries.toXYZD50(color_pace_primaries, toXYZD50)
    lib.SkColorSpacePrimaries_toXYZD50(color_pace_primaries, toXYZD50)
end

-- ## sk_color_table
Skia.ColorTable = {}

function Skia.ColorTable.delete(color_table)
    lib.SkColorTable_delete(color_table)
end

function Skia.ColorTable.alphaTable(color_table)
    return lib. SkColorTable_alphaTable(color_table)
end

function Skia.ColorTable.redTable(color_table)
    return lib. SkColorTable_redTable(color_table)
end

function Skia.ColorTable.greenTable(color_table)
    return lib. SkColorTable_greenTable(color_table)
end

function Skia.ColorTable.blueTable(color_table)
    return lib. SkColorTable_blueTable(color_table)
end

function Skia.ColorTable.flatten(color_table, buffer)
    lib.SkColorTable_flatten(color_table, buffer)
end

function Skia.ColorTable.unique(color_table)
    return lib.SkColorTable_unique(color_table)
end

function Skia.ColorTable.ref(color_table)
    lib.SkColorTable_ref(color_table)
end

function Skia.ColorTable.unref(color_table)
    lib.SkColorTable_unref(color_table)
end

function Skia.ColorTable.Make(utable)
    local obj = lib.SkColorTable_Make(utable)
    setFinalizer(obj, lib.static_sk_color_table_delete)
    return obj
end

function Skia.ColorTable.Make_2(utableA, tableR, tableG, tableB)
    local obj = lib.SkColorTable_Make_2(utableA, tableR, tableG, tableB)
    setFinalizer(obj, lib.static_sk_color_table_delete)
    return obj
end

function Skia.ColorTable.Deserialize(buffer)
    local obj = lib.SkColorTable_Deserialize(buffer)
    setFinalizer(obj, lib.static_sk_color_table_delete)
    return obj
end

-- ## sk_contour_measure
Skia.ContourMeasure = {}

function Skia.ContourMeasure.delete(contour_measure)
    lib.SkContourMeasure_delete(contour_measure)
end

function Skia.ContourMeasure.length(contour_measure)
    return lib.SkContourMeasure_length(contour_measure)
end

function Skia.ContourMeasure.getPosTan(contour_measure, distance, position, tangent)
    return lib.SkContourMeasure_getPosTan(contour_measure, distance, position, tangent)
end

function Skia.ContourMeasure.getMatrix(contour_measure, distance, matrix, flags)
    return lib.SkContourMeasure_getMatrix(contour_measure, distance, matrix, flags)
end

function Skia.ContourMeasure.getSegment(contour_measure, startD, stopD, dst, startWithMoveTo)
    return lib.SkContourMeasure_getSegment(contour_measure, startD, stopD, dst, startWithMoveTo)
end

function Skia.ContourMeasure.isClosed(contour_measure)
    return lib.SkContourMeasure_isClosed(contour_measure)
end

function Skia.ContourMeasure.unique(contour_measure)
    return lib.SkContourMeasure_unique(contour_measure)
end

function Skia.ContourMeasure.ref(contour_measure)
    lib.SkContourMeasure_ref(contour_measure)
end

function Skia.ContourMeasure.unref(contour_measure)
    lib.SkContourMeasure_unref(contour_measure)
end

-- ## sk_contour_measure_iter
Skia.ContourMeasureIter = {}

function Skia.ContourMeasureIter.new()
    local obj = lib.SkContourMeasureIter_new()
    ffi.gc(obj, lib.SkContourMeasureIter_delete)
    return obj
end

function Skia.ContourMeasureIter.new_2(path, forceClosed, resScale)
    local obj = lib.SkContourMeasureIter_new_2(path, forceClosed, resScale)
    ffi.gc(obj, lib.SkContourMeasureIter_delete)
    return obj
end

function Skia.ContourMeasureIter.delete(contour_measure_iter)
    lib.SkContourMeasureIter_delete(contour_measure_iter)
end

function Skia.ContourMeasureIter.reset(contour_measure_iter, path, forceClosed, resScale)
    lib.SkContourMeasureIter_reset(contour_measure_iter, path, forceClosed, resScale)
end

function Skia.ContourMeasureIter.next(contour_measure_iter)
    local obj = lib.SkContourMeasureIter_next(contour_measure_iter)
    setFinalizer(obj, lib.static_sk_contour_measure_delete)
    return obj
end

-- ## sk_corner_path_effect
Skia.CornerPathEffect = {}

function Skia.CornerPathEffect.delete(cornerPathEffect)
    lib.SkCornerPathEffect_delete(cornerPathEffect)
end

function Skia.CornerPathEffect.Make(radius)
    local obj = lib.SkCornerPathEffect_Make(radius)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.CornerPathEffect.RegisterFlattenables()
    lib.SkCornerPathEffect_RegisterFlattenables()
end

-- ## sk_cubic_map
Skia.CubicMap = {}

function Skia.CubicMap.new(p1, p2)
    local obj = lib.SkCubicMap_new(p1, p2)
    ffi.gc(obj, lib.SkCubicMap_delete)
    return obj
end

function Skia.CubicMap.delete(cubic_map)
    lib.SkCubicMap_delete(cubic_map)
end

function Skia.CubicMap.computeYFromX(cubic_map, x)
    return lib.SkCubicMap_computeYFromX(cubic_map, x)
end

function Skia.CubicMap.computeFromT(cubic_map, t)
    local obj = lib.SkCubicMap_computeFromT(cubic_map, t)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.CubicMap.IsLinear(p1, p2)
    return lib.SkCubicMap_IsLinear(p1, p2)
end

-- ## sk_cubic_resampler
Skia.CubicResampler = {}

function Skia.CubicResampler.delete(cubicResampler)
    lib.SkCubicResampler_delete(cubicResampler)
end

function Skia.CubicResampler.Mitchell()
    local obj = lib.SkCubicResampler_Mitchell()
    setFinalizer(obj, lib.static_sk_cubic_resampler_delete)
    return obj
end

function Skia.CubicResampler.CatmullRom()
    local obj = lib.SkCubicResampler_CatmullRom()
    setFinalizer(obj, lib.static_sk_cubic_resampler_delete)
    return obj
end

-- ## sk_dash_path_effect
Skia.DashPathEffect = {}

function Skia.DashPathEffect.delete(dashPathEffect)
    lib.SkDashPathEffect_delete(dashPathEffect)
end

function Skia.DashPathEffect.Make(intervals, count, phase)
    local obj = lib.SkDashPathEffect_Make(intervals, count, phase)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

-- ## sk_data
Skia.Data = {}

function Skia.Data.delete(sk_data)
    lib.SkData_delete(sk_data)
end

function Skia.Data.size(sk_data)
    return lib.SkData_size(sk_data)
end

function Skia.Data.isEmpty(sk_data)
    return lib.SkData_isEmpty(sk_data)
end

function Skia.Data.data(sk_data)
    return lib. SkData_data(sk_data)
end

function Skia.Data.bytes(sk_data)
    return lib. SkData_bytes(sk_data)
end

function Skia.Data.writable_data(sk_data)
    return lib. SkData_writable_data(sk_data)
end

function Skia.Data.copyRange(sk_data, offset, length, buffer)
    return lib.SkData_copyRange(sk_data, offset, length, buffer)
end

function Skia.Data.equals(sk_data, other)
    return lib.SkData_equals(sk_data, other)
end

function Skia.Data.unique(sk_data)
    return lib.SkData_unique(sk_data)
end

function Skia.Data.ref(sk_data)
    lib.SkData_ref(sk_data)
end

function Skia.Data.unref(sk_data)
    lib.SkData_unref(sk_data)
end

function Skia.Data.deref(sk_data)
    lib.SkData_deref(sk_data)
end

function Skia.Data.refCntGreaterThan(sk_data, threadIsolatedTestCnt)
    return lib.SkData_refCntGreaterThan(sk_data, threadIsolatedTestCnt)
end

function Skia.Data.MakeWithCopy(data, length)
    local obj = lib.SkData_MakeWithCopy(data, length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeUninitialized(length)
    local obj = lib.SkData_MakeUninitialized(length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeZeroInitialized(length)
    local obj = lib.SkData_MakeZeroInitialized(length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeWithCString(cstr)
    local obj = lib.SkData_MakeWithCString(cstr)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeWithProc(ptr, length, proc, ctx)
    local obj = lib.SkData_MakeWithProc(ptr, length, proc, ctx)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeWithoutCopy(data, length)
    local obj = lib.SkData_MakeWithoutCopy(data, length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeFromMalloc(data, length)
    local obj = lib.SkData_MakeFromMalloc(data, length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeFromFileName(path)
    local obj = lib.SkData_MakeFromFileName(path)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeFromFILE(f)
    local obj = lib.SkData_MakeFromFILE(f)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeFromFD(fd)
    local obj = lib.SkData_MakeFromFD(fd)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeFromStream(stream, size)
    local obj = lib.SkData_MakeFromStream(stream, size)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeSubset(src, offset, length)
    local obj = lib.SkData_MakeSubset(src, offset, length)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Data.MakeEmpty()
    local obj = lib.SkData_MakeEmpty()
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

-- ## sk_data_table
Skia.DataTable = {}

function Skia.DataTable.delete(data_table)
    lib.SkDataTable_delete(data_table)
end

function Skia.DataTable.isEmpty(data_table)
    return lib.SkDataTable_isEmpty(data_table)
end

function Skia.DataTable.count(data_table)
    return lib.SkDataTable_count(data_table)
end

function Skia.DataTable.atSize(data_table, index)
    return lib.SkDataTable_atSize(data_table, index)
end

function Skia.DataTable.at(data_table, index, size)
    return lib. SkDataTable_at(data_table, index, size)
end

function Skia.DataTable.atStr(data_table, index)
    return lib. SkDataTable_atStr(data_table, index)
end

function Skia.DataTable.unique(data_table)
    return lib.SkDataTable_unique(data_table)
end

function Skia.DataTable.ref(data_table)
    lib.SkDataTable_ref(data_table)
end

function Skia.DataTable.unref(data_table)
    lib.SkDataTable_unref(data_table)
end

function Skia.DataTable.MakeEmpty()
    local obj = lib.SkDataTable_MakeEmpty()
    setFinalizer(obj, lib.static_sk_data_table_delete)
    return obj
end

function Skia.DataTable.MakeCopyArrays(ptrs, sizes, count)
    local obj = lib.SkDataTable_MakeCopyArrays(ptrs, sizes, count)
    setFinalizer(obj, lib.static_sk_data_table_delete)
    return obj
end

function Skia.DataTable.MakeCopyArray(array, elemSize, count)
    local obj = lib.SkDataTable_MakeCopyArray(array, elemSize, count)
    setFinalizer(obj, lib.static_sk_data_table_delete)
    return obj
end

function Skia.DataTable.MakeArrayProc(array, elemSize, count, proc, context)
    local obj = lib.SkDataTable_MakeArrayProc(array, elemSize, count, proc, context)
    setFinalizer(obj, lib.static_sk_data_table_delete)
    return obj
end

-- ## sk_discrete_path_effect
Skia.DiscretePathEffect = {}

function Skia.DiscretePathEffect.delete(discretePathEffect)
    lib.SkDiscretePathEffect_delete(discretePathEffect)
end

function Skia.DiscretePathEffect.Make(segLength, dev, seedAssist)
    local obj = lib.SkDiscretePathEffect_Make(segLength, dev, seedAssist)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.DiscretePathEffect.RegisterFlattenables()
    lib.SkDiscretePathEffect_RegisterFlattenables()
end

-- ## sk_document
Skia.Document = {}

function Skia.Document.delete(document)
    lib.SkDocument_delete(document)
end

function Skia.Document.beginPage(document, width, height, content)
    return lib. SkDocument_beginPage(document, width, height, content)
end

function Skia.Document.endPage(document)
    lib.SkDocument_endPage(document)
end

function Skia.Document.close(document)
    lib.SkDocument_close(document)
end

function Skia.Document.abort(document)
    lib.SkDocument_abort(document)
end

function Skia.Document.unique(document)
    return lib.SkDocument_unique(document)
end

function Skia.Document.ref(document)
    lib.SkDocument_ref(document)
end

function Skia.Document.unref(document)
    lib.SkDocument_unref(document)
end

-- ## sk_drawable
Skia.Drawable = {}

function Skia.Drawable.delete(drawable)
    lib.SkDrawable_delete(drawable)
end

function Skia.Drawable.draw(drawable, canvas, matrix)
    lib.SkDrawable_draw(drawable, canvas, matrix)
end

function Skia.Drawable.draw_2(drawable, canvas, x, y)
    lib.SkDrawable_draw_2(drawable, canvas, x, y)
end

function Skia.Drawable.snapGpuDrawHandler(drawable, backendApi, matrix, clipBounds, bufferInfo)
    local obj = lib.SkDrawable_snapGpuDrawHandler(drawable, backendApi, matrix, clipBounds, bufferInfo)
    setFinalizer(obj, lib.static_sk_drawable_gpu_draw_handler_delete)
    return obj
end

function Skia.Drawable.makePictureSnapshot(drawable)
    local obj = lib.SkDrawable_makePictureSnapshot(drawable)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.Drawable.getGenerationID(drawable)
    return lib.SkDrawable_getGenerationID(drawable)
end

function Skia.Drawable.getBounds(drawable)
    local obj = lib.SkDrawable_getBounds(drawable)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Drawable.approximateBytesUsed(drawable)
    return lib.SkDrawable_approximateBytesUsed(drawable)
end

function Skia.Drawable.notifyDrawingChanged(drawable)
    lib.SkDrawable_notifyDrawingChanged(drawable)
end

function Skia.Drawable.getFlattenableType(drawable)
    return lib.SkDrawable_getFlattenableType(drawable)
end

function Skia.Drawable.getFactory(drawable)
    local obj = lib.SkDrawable_getFactory(drawable)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Drawable.getTypeName(drawable)
    return lib. SkDrawable_getTypeName(drawable)
end

function Skia.Drawable.flatten(drawable, write_buffer)
    lib.SkDrawable_flatten(drawable, write_buffer)
end

function Skia.Drawable.serialize(drawable, serial_procs)
    local obj = lib.SkDrawable_serialize(drawable, serial_procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Drawable.serialize_2(drawable, memory, memory_size, serial_procs)
    return lib.SkDrawable_serialize_2(drawable, memory, memory_size, serial_procs)
end

function Skia.Drawable.unique(drawable)
    return lib.SkDrawable_unique(drawable)
end

function Skia.Drawable.ref(drawable)
    lib.SkDrawable_ref(drawable)
end

function Skia.Drawable.unref(drawable)
    lib.SkDrawable_unref(drawable)
end

function Skia.Drawable.GetFlattenableType()
    return lib.SkDrawable_GetFlattenableType()
end

function Skia.Drawable.Deserialize(data, size, procs)
    local obj = lib.SkDrawable_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_drawable_delete)
    return obj
end

function Skia.Drawable.NameToFactory(name)
    local obj = lib.SkDrawable_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Drawable.FactoryToName(factory)
    return lib. SkDrawable_FactoryToName(factory)
end

function Skia.Drawable.Register(name, factory)
    lib.SkDrawable_Register(name, factory)
end

-- ## sk_dynamic_memory_w_stream
Skia.DynamicMemoryWStream = {}

function Skia.DynamicMemoryWStream.new()
    local obj = lib.SkDynamicMemoryWStream_new()
    ffi.gc(obj, SkDynamicMemoryWStream_delete)
    return obj
end

function Skia.DynamicMemoryWStream.delete(dynamic_memory_w_stream)
    lib.SkDynamicMemoryWStream_delete(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.write(dynamic_memory_w_stream, buffer, size)
    return lib.SkDynamicMemoryWStream_write(dynamic_memory_w_stream, buffer, size)
end

function Skia.DynamicMemoryWStream.bytesWritten(dynamic_memory_w_stream)
    return lib.SkDynamicMemoryWStream_bytesWritten(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.read(dynamic_memory_w_stream, buffer, offset, size)
    return lib.SkDynamicMemoryWStream_read(dynamic_memory_w_stream, buffer, offset, size)
end

function Skia.DynamicMemoryWStream.copyTo(dynamic_memory_w_stream, dst)
    lib.SkDynamicMemoryWStream_copyTo(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.writeToStream(dynamic_memory_w_stream, dst)
    return lib.SkDynamicMemoryWStream_writeToStream(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.copyToAndReset(dynamic_memory_w_stream, dst)
    lib.SkDynamicMemoryWStream_copyToAndReset(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.writeToAndReset(dynamic_memory_w_stream, dst)
    return lib.SkDynamicMemoryWStream_writeToAndReset(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.writeToAndReset_2(dynamic_memory_w_stream, dst)
    return lib.SkDynamicMemoryWStream_writeToAndReset_2(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.prependToAndReset(dynamic_memory_w_stream, dst)
    lib.SkDynamicMemoryWStream_prependToAndReset(dynamic_memory_w_stream, dst)
end

function Skia.DynamicMemoryWStream.detachAsData(dynamic_memory_w_stream)
    local obj = lib.SkDynamicMemoryWStream_detachAsData(dynamic_memory_w_stream)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.DynamicMemoryWStream.detachAsStream(dynamic_memory_w_stream)
    local obj = lib.SkDynamicMemoryWStream_detachAsStream(dynamic_memory_w_stream)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.DynamicMemoryWStream.reset(dynamic_memory_w_stream)
    lib.SkDynamicMemoryWStream_reset(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.padToAlign4(dynamic_memory_w_stream)
    lib.SkDynamicMemoryWStream_padToAlign4(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.flush(dynamic_memory_w_stream)
    lib.SkDynamicMemoryWStream_flush(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.write8(dynamic_memory_w_stream, value)
    return lib.SkDynamicMemoryWStream_write8(dynamic_memory_w_stream, value)
end

function Skia.DynamicMemoryWStream.write16(dynamic_memory_w_stream, value)
    return lib.SkDynamicMemoryWStream_write16(dynamic_memory_w_stream, value)
end

function Skia.DynamicMemoryWStream.write32(dynamic_memory_w_stream, v)
    return lib.SkDynamicMemoryWStream_write32(dynamic_memory_w_stream, v)
end

function Skia.DynamicMemoryWStream.writeText(dynamic_memory_w_stream, text)
    return lib.SkDynamicMemoryWStream_writeText(dynamic_memory_w_stream, text)
end

function Skia.DynamicMemoryWStream.newline(dynamic_memory_w_stream)
    return lib.SkDynamicMemoryWStream_newline(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.writeDecAsText(dynamic_memory_w_stream, v)
    return lib.SkDynamicMemoryWStream_writeDecAsText(dynamic_memory_w_stream, v)
end

function Skia.DynamicMemoryWStream.writeBigDecAsText(dynamic_memory_w_stream, v, minDigits)
    return lib.SkDynamicMemoryWStream_writeBigDecAsText(dynamic_memory_w_stream, v, minDigits)
end

function Skia.DynamicMemoryWStream.writeHexAsText(dynamic_memory_w_stream, v, minDigits)
    return lib.SkDynamicMemoryWStream_writeHexAsText(dynamic_memory_w_stream, v, minDigits)
end

function Skia.DynamicMemoryWStream.writeScalarAsText(dynamic_memory_w_stream, scalar)
    return lib.SkDynamicMemoryWStream_writeScalarAsText(dynamic_memory_w_stream, scalar)
end

function Skia.DynamicMemoryWStream.writeBool(dynamic_memory_w_stream, v)
    return lib.SkDynamicMemoryWStream_writeBool(dynamic_memory_w_stream, v)
end

function Skia.DynamicMemoryWStream.writeScalar(dynamic_memory_w_stream, scalar)
    return lib.SkDynamicMemoryWStream_writeScalar(dynamic_memory_w_stream, scalar)
end

function Skia.DynamicMemoryWStream.writePackedUInt(dynamic_memory_w_stream, length)
    return lib.SkDynamicMemoryWStream_writePackedUInt(dynamic_memory_w_stream, length)
end

function Skia.DynamicMemoryWStream.writeStream(dynamic_memory_w_stream, input, length)
    return lib.SkDynamicMemoryWStream_writeStream(dynamic_memory_w_stream, input, length)
end

function Skia.DynamicMemoryWStream.SizeOfPackedUInt(value)
    return lib.SkDynamicMemoryWStream_SizeOfPackedUInt(value)
end

-- ## sk_encoded_origin
Skia.EncodedOrigin = {}

function Skia.EncodedOrigin.SkEncodedOriginToMatrix(origin, w, h)
    local obj = lib.SkEncodedOrigin_SkEncodedOriginToMatrix(origin, w, h)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.EncodedOrigin.SkEncodedOriginSwapsWidthHeight(origin)
    return lib.SkEncodedOrigin_SkEncodedOriginSwapsWidthHeight(origin)
end

-- ## sk_encoder
Skia.Encoder = {}

function Skia.Encoder.delete(encoder)
    lib.SkEncoder_delete(encoder)
end

function Skia.Encoder.encodeRows(encoder, numRows)
    return lib.SkEncoder_encodeRows(encoder, numRows)
end

-- ## sk_executor
Skia.Executor = {}

function Skia.Executor.delete(executor)
    lib.SkExecutor_delete(executor)
end

function Skia.Executor.add(function_void_void_key_in, executor)
    lib.SkExecutor_add(function_void_void_key_in, executor)
end

function Skia.Executor.borrow(executor)
    lib.SkExecutor_borrow(executor)
end

function Skia.Executor.MakeFIFOThreadPool(threads, allowBorrowing)
    local obj = lib.SkExecutor_MakeFIFOThreadPool(threads, allowBorrowing)
    setFinalizer(obj, lib.static_sk_executor_delete)
    return obj
end

function Skia.Executor.MakeLIFOThreadPool(threads, allowBorrowing)
    local obj = lib.SkExecutor_MakeLIFOThreadPool(threads, allowBorrowing)
    setFinalizer(obj, lib.static_sk_executor_delete)
    return obj
end

function Skia.Executor.GetDefault()
    return lib.SkExecutor_GetDefault()
end

function Skia.Executor.SetDefault(executor)
    lib.SkExecutor_SetDefault(executor)
end

-- ## sk_file_stream
Skia.FILEStream = {}

function Skia.FILEStream.new(path)
    local obj = lib.SkFILEStream_new(path)
    ffi.gc(obj, lib.SkFILEStream_delete)
    return obj
end

function Skia.FILEStream.new_2(file)
    local obj = lib.SkFILEStream_new_2(file)
    ffi.gc(obj, lib.SkFILEStream_delete)
    return obj
end

function Skia.FILEStream.new_3(file, size)
    local obj = lib.SkFILEStream_new_3(file, size)
    ffi.gc(obj, lib.SkFILEStream_delete)
    return obj
end

function Skia.FILEStream.delete(file_stream)
    lib.SkFILEStream_delete(file_stream)
end

function Skia.FILEStream.isValid(file_stream)
    return lib.SkFILEStream_isValid(file_stream)
end

function Skia.FILEStream.close(file_stream)
    lib.SkFILEStream_close(file_stream)
end

function Skia.FILEStream.read(file_stream, buffer, size)
    return lib.SkFILEStream_read(file_stream, buffer, size)
end

function Skia.FILEStream.isAtEnd(file_stream)
    return lib.SkFILEStream_isAtEnd(file_stream)
end

function Skia.FILEStream.rewind(file_stream)
    return lib.SkFILEStream_rewind(file_stream)
end

function Skia.FILEStream.duplicate(file_stream)
    local obj = lib.SkFILEStream_duplicate(file_stream)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.FILEStream.getPosition(file_stream)
    return lib.SkFILEStream_getPosition(file_stream)
end

function Skia.FILEStream.seek(file_stream, position)
    return lib.SkFILEStream_seek(file_stream, position)
end

function Skia.FILEStream.move(file_stream, offset)
    return lib.SkFILEStream_move(file_stream, offset)
end

function Skia.FILEStream.fork(file_stream)
    local obj = lib.SkFILEStream_fork(file_stream)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.FILEStream.getLength(file_stream)
    return lib.SkFILEStream_getLength(file_stream)
end

function Skia.FILEStream.hasLength(file_stream)
    return lib.SkFILEStream_hasLength(file_stream)
end

function Skia.FILEStream.hasPosition(file_stream)
    return lib.SkFILEStream_hasPosition(file_stream)
end

function Skia.FILEStream.skip(file_stream, size)
    return lib.SkFILEStream_skip(file_stream, size)
end

function Skia.FILEStream.peek(file_stream, ptr, size)
    return lib.SkFILEStream_peek(file_stream, ptr, size)
end

function Skia.FILEStream.readS8(file_stream, i)
    return lib.SkFILEStream_readS8(file_stream, i)
end

function Skia.FILEStream.readS16(file_stream, i)
    return lib.SkFILEStream_readS16(file_stream, i)
end

function Skia.FILEStream.readS32(file_stream, i)
    return lib.SkFILEStream_readS32(file_stream, i)
end

function Skia.FILEStream.readU8(file_stream, i)
    return lib.SkFILEStream_readU8(file_stream, i)
end

function Skia.FILEStream.readU16(file_stream, i)
    return lib.SkFILEStream_readU16(file_stream, i)
end

function Skia.FILEStream.readU32(file_stream, i)
    return lib.SkFILEStream_readU32(file_stream, i)
end

function Skia.FILEStream.readBool(file_stream, b)
    return lib.SkFILEStream_readBool(file_stream, b)
end

function Skia.FILEStream.readScalar(file_stream, scalar)
    return lib.SkFILEStream_readScalar(file_stream, scalar)
end

function Skia.FILEStream.readPackedUInt(file_stream, size)
    return lib.SkFILEStream_readPackedUInt(file_stream, size)
end

function Skia.FILEStream.getMemoryBase(file_stream)
    return lib. SkFILEStream_getMemoryBase(file_stream)
end

function Skia.FILEStream.Make(path)
    local obj = lib.SkFILEStream_Make(path)
    setFinalizer(obj, lib.static_sk_file_stream_delete)
    return obj
end

-- ## sk_file_w_stream
Skia.FILEWStream = {}

function Skia.FILEWStream.new(path)
    local obj = lib.SkFILEWStream_new(path)
    ffi.gc(obj, lib.SkFILEWStream_delete)
    return obj
end

function Skia.FILEWStream.delete(file_w_stream)
    lib.SkFILEWStream_delete(file_w_stream)
end

function Skia.FILEWStream.isValid(file_w_stream)
    return lib.SkFILEWStream_isValid(file_w_stream)
end

function Skia.FILEWStream.write(file_w_stream, buffer, size)
    return lib.SkFILEWStream_write(file_w_stream, buffer, size)
end

function Skia.FILEWStream.flush(file_w_stream)
    lib.SkFILEWStream_flush(file_w_stream)
end

function Skia.FILEWStream.fsync(file_w_stream)
    lib.SkFILEWStream_fsync(file_w_stream)
end

function Skia.FILEWStream.bytesWritten(file_w_stream)
    return lib.SkFILEWStream_bytesWritten(file_w_stream)
end

function Skia.FILEWStream.write8(file_w_stream, value)
    return lib.SkFILEWStream_write8(file_w_stream, value)
end

function Skia.FILEWStream.write16(file_w_stream, value)
    return lib.SkFILEWStream_write16(file_w_stream, value)
end

function Skia.FILEWStream.write32(file_w_stream, v)
    return lib.SkFILEWStream_write32(file_w_stream, v)
end

function Skia.FILEWStream.writeText(file_w_stream, text)
    return lib.SkFILEWStream_writeText(file_w_stream, text)
end

function Skia.FILEWStream.newline(file_w_stream)
    return lib.SkFILEWStream_newline(file_w_stream)
end

function Skia.FILEWStream.writeDecAsText(file_w_stream, v)
    return lib.SkFILEWStream_writeDecAsText(file_w_stream, v)
end

function Skia.FILEWStream.writeBigDecAsText(file_w_stream, v, minDigits)
    return lib.SkFILEWStream_writeBigDecAsText(file_w_stream, v, minDigits)
end

function Skia.FILEWStream.writeHexAsText(file_w_stream, v, minDigits)
    return lib.SkFILEWStream_writeHexAsText(file_w_stream, v, minDigits)
end

function Skia.FILEWStream.writeScalarAsText(file_w_stream, scalar)
    return lib.SkFILEWStream_writeScalarAsText(file_w_stream, scalar)
end

function Skia.FILEWStream.writeBool(file_w_stream, v)
    return lib.SkFILEWStream_writeBool(file_w_stream, v)
end

function Skia.FILEWStream.writeScalar(file_w_stream, scalar)
    return lib.SkFILEWStream_writeScalar(file_w_stream, scalar)
end

function Skia.FILEWStream.writePackedUInt(file_w_stream, size)
    return lib.SkFILEWStream_writePackedUInt(file_w_stream, size)
end

function Skia.FILEWStream.writeStream(file_w_stream, input, length)
    return lib.SkFILEWStream_writeStream(file_w_stream, input, length)
end

function Skia.FILEWStream.SizeOfPackedUInt(value)
    return lib.SkFILEWStream_SizeOfPackedUInt(value)
end

-- ## sk_flattenable
Skia.Flattenable = {}

function Skia.Flattenable.delete(flattenable)
    lib.SkFlattenable_delete(flattenable)
end

function Skia.Flattenable.getFactory(flattenable)
    local obj = lib.SkFlattenable_getFactory(flattenable)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Flattenable.getTypeName(flattenable)
    return lib. SkFlattenable_getTypeName(flattenable)
end

function Skia.Flattenable.flatten(flattenable, write_buffer)
    lib.SkFlattenable_flatten(flattenable, write_buffer)
end

function Skia.Flattenable.getFlattenableType(flattenable)
    return lib.SkFlattenable_getFlattenableType(flattenable)
end

function Skia.Flattenable.serialize(flattenable, serial_procs)
    local obj = lib.SkFlattenable_serialize(flattenable, serial_procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Flattenable.serialize_2(flattenable, memory, memory_size, serial_procs)
    return lib.SkFlattenable_serialize_2(flattenable, memory, memory_size, serial_procs)
end

function Skia.Flattenable.unique(flattenable)
    return lib.SkFlattenable_unique(flattenable)
end

function Skia.Flattenable.ref(flattenable)
    lib.SkFlattenable_ref(flattenable)
end

function Skia.Flattenable.unref(flattenable)
    lib.SkFlattenable_unref(flattenable)
end

function Skia.Flattenable.NameToFactory(name)
    local obj = lib.SkFlattenable_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Flattenable.FactoryToName(factory)
    return lib. SkFlattenable_FactoryToName(factory)
end

function Skia.Flattenable.Register(name, factory)
    lib.SkFlattenable_Register(name, factory)
end

function Skia.Flattenable.Deserialize(type, data, length, procs)
    return lib.SkFlattenable_Deserialize(type, data, length, procs)
end

-- ## sk_font
Skia.Font = {}

function Skia.Font.new()
    local obj = lib.SkFont_new()
    ffi.gc(obj, lib.SkFont_delete)
    return obj
end

function Skia.Font.new_2(typeface, size)
    local obj = lib.SkFont_new_2(typeface, size)
    ffi.gc(obj, lib.SkFont_delete)
    return obj
end

function Skia.Font.new_3(typeface)
    local obj = lib.SkFont_new_3(typeface)
    ffi.gc(obj, lib.SkFont_delete)
    return obj
end

function Skia.Font.new_4(typeface, size, scaleX, skewX)
    local obj = lib.SkFont_new_4(typeface, size, scaleX, skewX)
    ffi.gc(obj, lib.SkFont_delete)
    return obj
end

function Skia.Font.delete(font)
    lib.SkFont_delete(font)
end

function Skia.Font.isForceAutoHinting(font)
    return lib.SkFont_isForceAutoHinting(font)
end

function Skia.Font.isEmbeddedBitmaps(font)
    return lib.SkFont_isEmbeddedBitmaps(font)
end

function Skia.Font.isSubpixel(font)
    return lib.SkFont_isSubpixel(font)
end

function Skia.Font.isLinearMetrics(font)
    return lib.SkFont_isLinearMetrics(font)
end

function Skia.Font.isEmbolden(font)
    return lib.SkFont_isEmbolden(font)
end

function Skia.Font.isBaselineSnap(font)
    return lib.SkFont_isBaselineSnap(font)
end

function Skia.Font.setForceAutoHinting(font, forceAutoHinting)
    lib.SkFont_setForceAutoHinting(font, forceAutoHinting)
end

function Skia.Font.setEmbeddedBitmaps(font, embeddedBitmaps)
    lib.SkFont_setEmbeddedBitmaps(font, embeddedBitmaps)
end

function Skia.Font.setSubpixel(font, subpixel)
    lib.SkFont_setSubpixel(font, subpixel)
end

function Skia.Font.setLinearMetrics(font, linearMetrics)
    lib.SkFont_setLinearMetrics(font, linearMetrics)
end

function Skia.Font.setEmbolden(font, embolden)
    lib.SkFont_setEmbolden(font, embolden)
end

function Skia.Font.setBaselineSnap(font, baselineSnap)
    lib.SkFont_setBaselineSnap(font, baselineSnap)
end

function Skia.Font.getEdging(font)
    return lib.SkFont_getEdging(font)
end

function Skia.Font.setEdging(font, edging)
    lib.SkFont_setEdging(font, edging)
end

function Skia.Font.setHinting(font, hintingLevel)
    lib.SkFont_setHinting(font, hintingLevel)
end

function Skia.Font.getHinting(font)
    return lib.SkFont_getHinting(font)
end

function Skia.Font.makeWithSize(font, size)
    local obj = lib.SkFont_makeWithSize(font, size)
    setFinalizer(obj, lib.static_sk_font_delete)
    return obj
end

function Skia.Font.getTypeface(font)
    return lib. SkFont_getTypeface(font)
end

function Skia.Font.getSize(font)
    return lib.SkFont_getSize(font)
end

function Skia.Font.getScaleX(font)
    return lib.SkFont_getScaleX(font)
end

function Skia.Font.getSkewX(font)
    return lib.SkFont_getSkewX(font)
end

function Skia.Font.refTypeface(font)
    local obj = lib.SkFont_refTypeface(font)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Font.setTypeface(font, typeface)
    lib.SkFont_setTypeface(font, typeface)
end

function Skia.Font.setSize(font, textSize)
    lib.SkFont_setSize(font, textSize)
end

function Skia.Font.setScaleX(font, scaleX)
    lib.SkFont_setScaleX(font, scaleX)
end

function Skia.Font.setSkewX(font, skewX)
    lib.SkFont_setSkewX(font, skewX)
end

function Skia.Font.textToGlyphs(font, text, byteLength, encoding, glyphs, maxGlyphCount)
    return lib.SkFont_textToGlyphs(font, text, byteLength, encoding, glyphs, maxGlyphCount)
end

function Skia.Font.unicharToGlyph(font, uni)
    return lib.SkFont_unicharToGlyph(font, uni)
end

function Skia.Font.unicharsToGlyphs(font, uni, count, glyphs)
    lib.SkFont_unicharsToGlyphs(font, uni, count, glyphs)
end

function Skia.Font.countText(font, text, byteLength, encoding)
    return lib.SkFont_countText(font, text, byteLength, encoding)
end

function Skia.Font.measureText(font, text, byteLength, encoding, bounds)
    return lib.SkFont_measureText(font, text, byteLength, encoding, bounds)
end

function Skia.Font.measureText_2(font, text, byteLength, encoding, bounds, paint)
    return lib.SkFont_measureText_2(font, text, byteLength, encoding, bounds, paint)
end

function Skia.Font.getWidths(font, glyphs, count, widths, bounds)
    lib.SkFont_getWidths(font, glyphs, count, widths, bounds)
end

function Skia.Font.getWidths_2(font, glyphs, count, widths, ptr)
    lib.SkFont_getWidths_2(font, glyphs, count, widths, ptr)
end

function Skia.Font.getWidths_3(font, glyphs, count, widths)
    lib.SkFont_getWidths_3(font, glyphs, count, widths)
end

function Skia.Font.getWidthsBounds(font, glyphs, count, widths, bounds, paint)
    lib.SkFont_getWidthsBounds(font, glyphs, count, widths, bounds, paint)
end

function Skia.Font.getBounds(font, glyphs, count, bounds, paint)
    lib.SkFont_getBounds(font, glyphs, count, bounds, paint)
end

function Skia.Font.getPos(font, glyphs, count, pos, origin)
    lib.SkFont_getPos(font, glyphs, count, pos, origin)
end

function Skia.Font.getXPos(font, glyphs, count, xpos, origin)
    lib.SkFont_getXPos(font, glyphs, count, xpos, origin)
end

function Skia.Font.getIntercepts(font, glyphs, count, pos, top, bottom, paint)
    return lib.SkFont_getIntercepts(font, glyphs, count, pos, top, bottom, paint)
end

function Skia.Font.getPath(font, glyphID, path)
    return lib.SkFont_getPath(font, glyphID, path)
end

-- void SkFont_getPaths(font, glyphIDs, count, glyphPathProc, ctx)

function Skia.Font.getMetrics(font, metrics)
    return lib.SkFont_getMetrics(font, metrics)
end

function Skia.Font.getSpacing(font)
    return lib.SkFont_getSpacing(font)
end

function Skia.Font.dump(font)
    lib.SkFont_dump(font)
end

-- ## sk_font_arguments
Skia.FontArguments = {}

function Skia.FontArguments.new()
    local obj = lib.SkFontArguments_new()
    ffi.gc(obj, lib.SkFontArguments_delete)
    return obj
end

function Skia.FontArguments.delete(font_arguments)
    lib.SkFontArguments_delete(font_arguments)
end

function Skia.FontArguments.setCollectionIndex(font_argments, collectionIndex)
    local obj = lib.SkFontArguments_setCollectionIndex(font_argments, collectionIndex)
    setFinalizer(obj, lib.static_sk_font_arguments_delete)
    return obj
end

function Skia.FontArguments.setVariationDesignPosition(font_argments, position)
    local obj = lib.SkFontArguments_setVariationDesignPosition(font_argments, position)
    setFinalizer(obj, lib.static_sk_font_arguments_delete)
    return obj
end

function Skia.FontArguments.getCollectionIndex(font_argments)
    return lib.SkFontArguments_getCollectionIndex(font_argments)
end

function Skia.FontArguments.getVariationDesignPosition(font_argments)
    local obj = lib.SkFontArguments_getVariationDesignPosition(font_argments)
    setFinalizer(obj, lib.static_sk_font_arguments_variation_position_delete)
    return
end

function Skia.FontArguments.setPalette(font_argments, palette)
    local obj = lib.SkFontArguments_setPalette(font_argments, palette)
    setFinalizer(obj, lib.static_sk_font_arguments_delete)
    return obj
end

function Skia.FontArguments.getPalette(font_argments)
    local obj = lib.SkFontArguments_getPalette(font_argments)
    setFinalizer(obj, lib.static_sk_font_arguments_palette_delete)
    return obj
end

-- ## sk_font_metrics
Skia.FontMetrics = {}

function Skia.FontMetrics.delete(font_metrics)
    lib.SkFontMetrics_delete(font_metrics)
end

function Skia.FontMetrics.hasUnderlineThickness(font_metrics, thickness)
    return lib.SkFontMetrics_hasUnderlineThickness(font_metrics, thickness)
end

function Skia.FontMetrics.hasUnderlinePosition(font_metrics, position)
    return lib.SkFontMetrics_hasUnderlinePosition(font_metrics, position)
end

function Skia.FontMetrics.hasStrikeoutThickness(font_metrics, thickness)
    return lib.SkFontMetrics_hasStrikeoutThickness(font_metrics, thickness)
end

function Skia.FontMetrics.hasStrikeoutPosition(font_metrics, position)
    return lib.SkFontMetrics_hasStrikeoutPosition(font_metrics, position)
end

function Skia.FontMetrics.hasBounds(font_metrics)
    return lib.SkFontMetrics_hasBounds(font_metrics)
end

-- ## sk_font_mgr
Skia.FontMgr = {}

function Skia.FontMgr.delete(font_mgr)
    lib.SkFontMgr_delete(font_mgr)
end

function Skia.FontMgr.countFamilies(font_mgr)
    return lib.SkFontMgr_countFamilies(font_mgr)
end

function Skia.FontMgr.getFamilyName(font_mgr, index, familyName)
    lib.SkFontMgr_getFamilyName(font_mgr, index, familyName)
end

function Skia.FontMgr.createStyleSet(sk_font_style_set_out, font_mgr, index)
    lib.SkFontMgr_createStyleSet(sk_font_style_set_out, font_mgr, index)
end

function Skia.FontMgr.matchFamily(sk_font_style_set_out, font_mgr, familyName)
    lib.SkFontMgr_matchFamily(sk_font_style_set_out, font_mgr, familyName)
end

function Skia.FontMgr.matchFamilyStyle(font_mgr, familyName, font_style)
    local obj = lib.SkFontMgr_matchFamilyStyle(font_mgr, familyName, font_style)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.matchFamilyStyleCharacter(font_mgr, familyName, font_style, bcp47, bcp47Count, character)
    local obj = lib.SkFontMgr_matchFamilyStyleCharacter(font_mgr, familyName, font_style, bcp47, bcp47Count, character)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.makeFromData(font_mgr, data, ttcIndex)
    local obj = lib.SkFontMgr_makeFromData(font_mgr, data, ttcIndex)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.makeFromStream(font_mgr, stream_asset, ttcIndex)
    local obj = lib.SkFontMgr_makeFromStream(font_mgr, stream_asset, ttcIndex)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.makeFromStream_2(font_mgr, stream_asset, font_argments)
    local obj = lib.SkFontMgr_makeFromStream_2(font_mgr, stream_asset, font_argments)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.makeFromFile(font_mgr, path, ttcIndex)
    local obj = lib.SkFontMgr_makeFromFile(font_mgr, path, ttcIndex)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.legacyMakeTypeface(font_mgr, familyName, style)
    local obj = lib.SkFontMgr_legacyMakeTypeface(font_mgr, familyName, style)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontMgr.unique(font_mgr)
    return lib.SkFontMgr_unique(font_mgr)
end

function Skia.FontMgr.ref(font_mgr)
    lib.SkFontMgr_ref(font_mgr)
end

function Skia.FontMgr.unref(font_mgr)
    lib.SkFontMgr_unref(font_mgr)
end

function Skia.FontMgr.RefEmpty()
    local obj = lib.SkFontMgr_RefEmpty()
    setFinalizer(obj, lib.static_sk_font_mgr_delete)
    return obj
end

function Skia.FontMgr.RefDefault()
    local obj = lib.SkFontMgr_RefDefault()
    setFinalizer(obj, lib.static_sk_font_mgr_delete)
    return obj
end

-- ## sk_font_mgr_fontconfig
Skia.FontMgrFontconfig = {}

-- ## sk_font_style
Skia.FontStyle = {}

function Skia.FontStyle.delete(font_style)
    lib.SkFontStyle_delete(font_style)
end

function Skia.FontStyle.weight(font_style)
    return lib.SkFontStyle_weight(font_style)
end

function Skia.FontStyle.width(font_style)
    return lib.SkFontStyle_width(font_style)
end

function Skia.FontStyle.slant(font_style)
    return lib.SkFontStyle_slant(font_style)
end

-- ## sk_font_style_set
Skia.FontStyleSet = {}

function Skia.FontStyleSet.delete(font_style_set)
    lib.SkFontStyleSet_delete(font_style_set)
end

function Skia.FontStyleSet.count(font_style_set)
    return lib.SkFontStyleSet_count(font_style_set)
end

function Skia.FontStyleSet.getStyle(font_style_set, index, font_style, style)
    lib.SkFontStyleSet_getStyle(font_style_set, index, font_style, style)
end

function Skia.FontStyleSet.createTypeface(font_style_set, index)
    local obj = lib.SkFontStyleSet_createTypeface(font_style_set, index)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontStyleSet.matchStyle(font_style_set, pattern)
    local obj = lib.SkFontStyleSet_matchStyle(font_style_set, pattern)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.FontStyleSet.unique(font_style_set)
    return lib.SkFontStyleSet_unique(font_style_set)
end

function Skia.FontStyleSet.ref(font_style_set)
    lib.SkFontStyleSet_ref(font_style_set)
end

function Skia.FontStyleSet.unref(font_style_set)
    lib.SkFontStyleSet_unref(font_style_set)
end

function Skia.FontStyleSet.CreateEmpty()
    return lib.SkFontStyleSet_CreateEmpty()
end

--[[
-- ## sk_gif_decoder
Skia.GifDecoder = {}

function Skia.GifDecoder.IsGif(ptr, size)
    return lib.SkGifDecoder_IsGif(ptr, size)
end

function Skia.GifDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkGifDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.GifDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkGifDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.GifDecoder.Decoder()
    local obj = lib.SkGifDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end
]]

-- ## sk_gradient_shader
Skia.GradientShader = {}

function Skia.GradientShader.delete(gradientShader)
    lib.SkGradientShader_delete(gradientShader)
end

function Skia.GradientShader.MakeLinear(pts, colors, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeLinear(pts, colors, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeLinear_2(pts, colors, color_space, pos, count, mode, interpolation, localMatrix)
    local obj = lib.SkGradientShader_MakeLinear_2(pts, colors, color_space, pos, count, mode, interpolation, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeLinear_3(pts, colors, color_space, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeLinear_3(pts, colors, color_space, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeRadial(center, radius, colors, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeRadial(center, radius, colors, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeRadial_2(center, radius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    local obj = lib.SkGradientShader_MakeRadial_2(center, radius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeRadial_3(center, radius, colors, color_space, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeRadial_3(center, radius, colors, color_space, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeTwoPointConical(start, startRadius, end_, endRadius, colors, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeTwoPointConical(start, startRadius, end_, endRadius, colors, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeTwoPointConical_2(start, startRadius, end_, endRadius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    local obj = lib.SkGradientShader_MakeTwoPointConical_2(start, startRadius, end_, endRadius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeTwoPointConical_3(start, startRadius, end_, endRadius, colors, color_space, pos, count, mode, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeTwoPointConical_3(start, startRadius, end_, endRadius, colors, color_space, pos, count, mode, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeSweep_2(cx, cy, colors, pos, count, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeSweep_2(cx, cy, colors, pos, count, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeSweep_3(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, interpolation, localMatrix)
    local obj = lib.SkGradientShader_MakeSweep_3(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, interpolation, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeSweep_4(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeSweep_4(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.GradientShader.MakeSweep_5(cx, cy, colors, color_space, pos, count, flags, localMatrix)
    local obj = lib.SkGradientShader_MakeSweep_5(cx, cy, colors, color_space, pos, count, flags, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

-- ## sk_graphics
Skia.Graphics = {}

function Skia.Graphics.delete(graphics)
    lib.SkGraphics_delete(graphics)
end

function Skia.Graphics.Init()
    lib.SkGraphics_Init()
end

function Skia.Graphics.GetFontCacheLimit()
    return lib.SkGraphics_GetFontCacheLimit()
end

function Skia.Graphics.SetFontCacheLimit(bytes)
    return lib.SkGraphics_SetFontCacheLimit(bytes)
end

function Skia.Graphics.GetFontCacheUsed()
    return lib.SkGraphics_GetFontCacheUsed()
end

function Skia.Graphics.GetFontCacheCountUsed()
    return lib.SkGraphics_GetFontCacheCountUsed()
end

function Skia.Graphics.GetFontCacheCountLimit()
    return lib.SkGraphics_GetFontCacheCountLimit()
end

function Skia.Graphics.SetFontCacheCountLimit(count)
    return lib.SkGraphics_SetFontCacheCountLimit(count)
end

function Skia.Graphics.PurgeFontCache()
    lib.SkGraphics_PurgeFontCache()
end

function Skia.Graphics.PurgePinnedFontCache()
    lib.SkGraphics_PurgePinnedFontCache()
end

function Skia.Graphics.GetResourceCacheTotalBytesUsed()
    return lib.SkGraphics_GetResourceCacheTotalBytesUsed()
end

function Skia.Graphics.GetResourceCacheTotalByteLimit()
    return lib.SkGraphics_GetResourceCacheTotalByteLimit()
end

function Skia.Graphics.SetResourceCacheTotalByteLimit(newLimit)
    return lib.SkGraphics_SetResourceCacheTotalByteLimit(newLimit)
end

function Skia.Graphics.PurgeResourceCache()
    lib.SkGraphics_PurgeResourceCache()
end

function Skia.Graphics.GetResourceCacheSingleAllocationByteLimit()
    return lib.SkGraphics_GetResourceCacheSingleAllocationByteLimit()
end

function Skia.Graphics.SetResourceCacheSingleAllocationByteLimit(newLimit)
    return lib.SkGraphics_SetResourceCacheSingleAllocationByteLimit(newLimit)
end

function Skia.Graphics.DumpMemoryStatistics(dump)
    lib.SkGraphics_DumpMemoryStatistics(dump)
end

function Skia.Graphics.PurgeAllCaches()
    lib.SkGraphics_PurgeAllCaches()
end

--SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory)
--SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory)
--SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory()

-- ## sk_high_contrast_config
Skia.HighContrastConfig = {}

function Skia.HighContrastConfig.new()
    return lib.SkHighContrastConfig_new()
end

function Skia.HighContrastConfig.new_2(grayscale, invertStyle, contrast)
    return lib.SkHighContrastConfig_new_2(grayscale, invertStyle, contrast)
end

function Skia.HighContrastConfig.delete(highContrastConfig)
    lib.SkHighContrastConfig_delete(highContrastConfig)
end

function isValid(high_contrast_config)
    return lib.isValid(high_contrast_config)
end

-- ## sk_high_contrast_filter
Skia.HighContrastFilter = {}

function Skia.HighContrastFilter.delete(highContrastFilter)
    lib.SkHighContrastFilter_delete(highContrastFilter)
end

function Skia.HighContrastFilter.Make(config)
    local obj = lib.SkHighContrastFilter_Make(config)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

-- ## sk_i_rect
Skia.IRect = {}

function Skia.IRect.delete(i_rect)
    lib.SkIRect_delete(i_rect)
end

function Skia.IRect.left(i_rect)
    return lib.SkIRect_left(i_rect)
end

function Skia.IRect.top(i_rect)
    return lib.SkIRect_top(i_rect)
end

function Skia.IRect.right(i_rect)
    return lib.SkIRect_right(i_rect)
end

function Skia.IRect.bottom(i_rect)
    return lib.SkIRect_bottom(i_rect)
end

function Skia.IRect.x(i_rect)
    return lib.SkIRect_x(i_rect)
end

function Skia.IRect.y(i_rect)
    return lib.SkIRect_y(i_rect)
end

function Skia.IRect.topLeft(i_rect)
    local obj = lib.SkIRect_topLeft(i_rect)
    setFinalizer(obj, lib.static_sk_i_point_delete)
    return obj
end

function Skia.IRect.width(i_rect)
    return lib.SkIRect_width(i_rect)
end

function Skia.IRect.height(i_rect)
    return lib.SkIRect_height(i_rect)
end

function Skia.IRect.size(i_rect)
    local obj = lib.SkIRect_size(i_rect)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.IRect.width64(i_rect)
    return lib.SkIRect_width64(i_rect)
end

function Skia.IRect.height64(i_rect)
    return lib.SkIRect_height64(i_rect)
end

function Skia.IRect.isEmpty64(i_rect)
    return lib.SkIRect_isEmpty64(i_rect)
end

function Skia.IRect.isEmpty(i_rect)
    return lib.SkIRect_isEmpty(i_rect)
end

function Skia.IRect.setEmpty(i_rect)
    lib.SkIRect_setEmpty(i_rect)
end

function Skia.IRect.setLTRB(i_rect, left, top, right, bottom)
    lib.SkIRect_setLTRB(i_rect, left, top, right, bottom)
end

function Skia.IRect.setXYWH(i_rect, x, y, width, height)
    lib.SkIRect_setXYWH(i_rect, x, y, width, height)
end

function Skia.IRect.setWH(i_rect, width, height)
    lib.SkIRect_setWH(i_rect, width, height)
end

function Skia.IRect.setSize(i_rect, size)
    lib.SkIRect_setSize(i_rect, size)
end

function Skia.IRect.makeOffset(i_rect, dx, dy)
    local obj = lib.SkIRect_makeOffset(i_rect, dx, dy)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.makeOffset_2(i_rect, offset)
    local obj = lib.SkIRect_makeOffset_2(i_rect, offset)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.makeInset(i_rect, dx, dy)
    local obj = lib.SkIRect_makeInset(i_rect, dx, dy)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.makeOutset(i_rect, dx, dy)
    local obj = lib.SkIRect_makeOutset(i_rect, dx, dy)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.offset(i_rect, dx, dy)
    lib.SkIRect_offset(i_rect, dx, dy)
end

function Skia.IRect.offset_2(i_rect, delta)
    lib.SkIRect_offset_2(i_rect, delta)
end

function Skia.IRect.offsetTo(i_rect, newX, newY)
    lib.SkIRect_offsetTo(i_rect, newX, newY)
end

function Skia.IRect.inset(i_rect, dx, dy)
    lib.SkIRect_inset(i_rect, dx, dy)
end

function Skia.IRect.outset(i_rect, dx, dy)
    lib.SkIRect_outset(i_rect, dx, dy)
end

function Skia.IRect.adjust(i_rect, dL, dT, dR, dB)
    lib.SkIRect_adjust(i_rect, dL, dT, dR, dB)
end

function Skia.IRect.contains(i_rect, x, y)
    return lib.SkIRect_contains(i_rect, x, y)
end

function Skia.IRect.contains_2(i_rect, r)
    return lib.SkIRect_contains_2(i_rect, r)
end

function Skia.IRect.contains_3(i_rect, r)
    return lib.SkIRect_contains_3(i_rect, r)
end

function Skia.IRect.containsNoEmptyCheck(i_rect, r)
    return lib.SkIRect_containsNoEmptyCheck(i_rect, r)
end

function Skia.IRect.intersect(i_rect, r)
    return lib.SkIRect_intersect(i_rect, r)
end

function Skia.IRect.intersect_2(i_rect, a, b)
    return lib.SkIRect_intersect_2(i_rect, a, b)
end

function Skia.IRect.join(i_rect, r)
    lib.SkIRect_join(i_rect, r)
end

function Skia.IRect.sort(i_rect)
    lib.SkIRect_sort(i_rect)
end

function Skia.IRect.makeSorted(i_rect)
    local obj = lib.SkIRect_makeSorted(i_rect)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakeEmpty()
    local obj = lib.SkIRect_MakeEmpty()
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakeWH(w, h)
    local obj = lib.SkIRect_MakeWH(w, h)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakeSize(size)
    local obj = lib.SkIRect_MakeSize(size)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakePtSize(pt, size)
    local obj = lib.SkIRect_MakePtSize(pt, size)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakeLTRB(l, t, r, b)
    local obj = lib.SkIRect_MakeLTRB(l, t, r, b)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.MakeXYWH(x, y, w, h)
    local obj = lib.SkIRect_MakeXYWH(x, y, w, h)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.IRect.Intersects(a, b)
    return lib.SkIRect_Intersects(a, b)
end

-- ## sk_i_size
Skia.ISize = {}

function Skia.ISize.delete(i_size)
    lib.SkISize_delete(i_size)
end

function Skia.ISize.set(i_size, w, h)
    lib.SkISize_set(i_size, w, h)
end
 
function Skia.ISize.isZero(i_size)
    return lib.SkISize_isZero(i_size)
end

function Skia.ISize.isEmpty(i_size)
    return lib.SkISize_isEmpty(i_size)
end

function Skia.ISize.setEmpty(i_size)
    lib.SkISize_setEmpty(i_size)
end

function Skia.ISize.width(i_size)
    return lib.SkISize_width(i_size)
end

function Skia.ISize.height(i_size)
    return lib.SkISize_height(i_size)
end

function Skia.ISize.area(i_size)
    return lib.SkISize_area(i_size)
end

function Skia.ISize.equals(i_size, w, h)
    return lib.SkISize_equals(i_size, w, h)
end

function Skia.ISize.Make(w, h)
    local obj = lib.SkISize_Make(w, h)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.ISize.MakeEmpty()
    local obj = lib.SkISize_MakeEmpty()
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

-- ## sk_icc
Skia.ICC = {}

function Skia.ICC.SkWriteICCProfile(transferFunction, toXYZD50)
    local obj = lib.SkICC_SkWriteICCProfile(transferFunction, toXYZD50)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ICC.SkWriteICCProfile_2(iccProfile, description)
    local obj = lib.SkICC_SkWriteICCProfile_2(iccProfile, description)
    setFinalizer(obj, lib.static_const_sk_data_delete)
    return obj
end

function Skia.ICC.SkICCFloatXYZD50ToGrid16Lab(float_xyz, grid16_lab)
    lib.SkICC_SkICCFloatXYZD50ToGrid16Lab(float_xyz, grid16_lab)
end

function Skia.ICC.SkICCFloatToTable16(f, table_16)
    lib.SkICC_SkICCFloatToTable16(f, table_16)
end

-- ## sk_ico_cecoder
Skia.IcoDecoder = {}

function Skia.IcoDecoder.IsIco(ptr, size)
    return lib.SkIcoDecoder_IsIco(ptr, size)
end

function Skia.IcoDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkIcoDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.IcoDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkIcoDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.IcoDecoder.Decoder()
    local obj = lib.SkIcoDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

-- ## sk_image
Skia.Image = {}

function Skia.Image.delete(image)
    lib.SkImage_delete(image)
end

function Skia.Image.imageInfo(image)
    return lib. SkImage_imageInfo(image)
end

function Skia.Image.width(image)
    return lib.SkImage_width(image)
end

function Skia.Image.height(image)
    return lib.SkImage_height(image)
end

function Skia.Image.dimensions(image)
    local obj = lib.SkImage_dimensions(image)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Image.bounds(image)
    local obj = lib.SkImage_bounds(image)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Image.uniqueID(image)
    return lib.SkImage_uniqueID(image)
end

function Skia.Image.alphaType(image)
    return lib.SkImage_alphaType(image)
end

function Skia.Image.colorType(image)
    return lib.SkImage_colorType(image)
end

function SkImage_colorSpace(image)
    return lib.SkImage_colorSpace(image)
end

function Skia.Image.refColorSpace(image)
    local obj = lib.SkImage_refColorSpace(image)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.Image.isAlphaOnly(image)
    return lib.SkImage_isAlphaOnly(image)
end

function Skia.Image.isOpaque(image)
    return lib.SkImage_isOpaque(image)
end

function Skia.Image.makeShader(image, tmx, tmy, sampling, localMatrix)
    local obj = lib.SkImage_makeShader(image, tmx, tmy, sampling, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeShader_2(image, tmx, tmy, sampling, lm)
    local obj = lib.SkImage_makeShader_2(image, tmx, tmy, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeShader_3(image, sampling, lm)
    local obj = lib.SkImage_makeShader_3(image, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeShader_4(image, sampling, lm)
    local obj = lib.SkImage_makeShader_4(image, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeRawShader(image, tmx, tmy, sampling, localMatrix)
    local obj = lib.SkImage_makeRawShader(image, tmx, tmy, sampling, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeRawShader_2(image, tmx, tmy, sampling, lm)
    local obj = lib.SkImage_makeRawShader_2(image, tmx, tmy, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeRawShader_3(image, sampling, lm)
    local obj = lib.SkImage_makeRawShader_3(image, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.makeRawShader_4(image, sampling, lm)
    local obj = lib.SkImage_makeRawShader_4(image, sampling, lm)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Image.peekPixels(image, pixmap)
    return lib.SkImage_peekPixels(image, pixmap)
end

function Skia.Image.isTextureBacked(image)
    return lib.SkImage_isTextureBacked(image)
end

function Skia.Image.textureSize(image)
    return lib.SkImage_textureSize(image)
end

function Skia.Image.isValid(image, context)
    return lib.SkImage_isValid(image, context)
end

function Skia.Image.readPixels(image, context, dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint)
    return lib.SkImage_readPixels(image, context, dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint)
end

function Skia.Image.readPixels_2(image, context, dst, srcX, srcY, cachingHint)
    return lib.SkImage_readPixels_2(image, context, dst, srcX, srcY, cachingHint)
end

function Skia.Image.readPixels_3(image, dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint)
    return lib.SkImage_readPixels_3(image, dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint)
end

function Skia.Image.readPixels_4(image, dst, srcX, srcY, cachingHint)
    return lib.SkImage_readPixels_4(image, dst, srcX, srcY, cachingHint)
end

-- void SkImage_asyncRescaleAndReadPixels(image, info, srcRect, rescaleGamma, rescaleMode, SkImage::ReadPixelsCallback callback, context)
-- void SkImage_asyncRescaleAndReadPixelsYUV420(image, yuvColorSpace, color_space, srcRect, dstSize, rescaleGamma, rescaleMode, SkImage::ReadPixelsCallback callback, context)
-- void SkImage_asyncRescaleAndReadPixelsYUVA420(image, yuvColorSpace, color_space, srcRect, dstSize, rescaleGamma, rescaleMode, SkImage::ReadPixelsCallback callback, context)
function Skia.Image.scalePixels(image, dst, sampling, cachingHint)
    return lib.SkImage_scalePixels(image, dst, sampling, cachingHint)
end

function Skia.Image.refEncodedData(image)
    local obj = lib.SkImage_refEncodedData(image)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Image.makeSubset(image, direct, subset)
    local obj = lib.SkImage_makeSubset(image, direct, subset)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeSubset_2(image, recorder, subset, properties)
    local obj = lib.SkImage_makeSubset_2(image, recorder, subset, properties)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.hasMipmaps(image)
    return lib.SkImage_hasMipmaps(image)
end

function Skia.Image.isProtected(image)
    return lib.SkImage_isProtected(image)
end

function Skia.Image.withDefaultMipmaps(image)
    local obj = lib.SkImage_withDefaultMipmaps(image)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeNonTextureImage(image, context)
    local obj = lib.SkImage_makeNonTextureImage(image, context)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeRasterImage(image, context, cachingHint)
    local obj = lib.SkImage_makeRasterImage(image, context, cachingHint)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeRasterImage_2(image, cachingHint)
    local obj = lib.SkImage_makeRasterImage_2(image, cachingHint)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.asLegacyBitmap(image, bitmap, legacyBitmapMode)
    return lib.SkImage_asLegacyBitmap(image, bitmap, legacyBitmapMode)
end

function Skia.Image.isLazyGenerated(image)
    return lib.SkImage_isLazyGenerated(image)
end

function Skia.Image.makeColorSpace(image, direct, color_space)
    local obj = lib.SkImage_makeColorSpace(image, direct, color_space)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeColorSpace_2(image, recorder, color_space, properties)
    local obj = lib.SkImage_makeColorSpace_2(image, recorder, color_space, properties)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeColorTypeAndColorSpace(image, direct, targetColorType, color_space)
    local obj = lib.SkImage_makeColorTypeAndColorSpace(image, direct, targetColorType, color_space)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.makeColorTypeAndColorSpace_2(image, recorder, targetColorType, color_space, properties)
    local obj = lib.SkImage_makeColorTypeAndColorSpace_2(image, recorder, targetColorType, color_space, properties)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.reinterpretColorSpace(image, color_space)
    local obj = lib.SkImage_reinterpretColorSpace(image, color_space)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Image.unique(image)
    return lib.SkImage_unique(image)
end

function Skia.Image.ref(image)
    lib.SkImage_ref(image)
end

function Skia.Image.unref(image)
    lib.SkImage_unref(image)
end

-- ## sk_image_filter
Skia.ImageFilter = {}

function Skia.ImageFilter.delete(image_filter)
    lib.SkImageFilter_delete(image_filter)
end

function Skia.ImageFilter.filterBounds(image_filter, src, ctm, direction, inputRect)
    local obj = lib.SkImageFilter_filterBounds(image_filter, src, ctm, direction, inputRect)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.ImageFilter.isColorFilterNode(image_filter, filterPtr)
    return lib.SkImageFilter_isColorFilterNode(image_filter, filterPtr)
end

function Skia.ImageFilter.asColorFilter(image_filter, filterPtr)
    return lib.SkImageFilter_asColorFilter(image_filter, filterPtr)
end

function Skia.ImageFilter.asAColorFilter(image_filter, filterPtr)
    return lib.SkImageFilter_asAColorFilter(image_filter, filterPtr)
end

function Skia.ImageFilter.countInputs(image_filter)
    return lib.SkImageFilter_countInputs(image_filter)
end

function Skia.ImageFilter.getInput(image_filter, i)
    return lib. SkImageFilter_getInput(image_filter, i)
end

function Skia.ImageFilter.computeFastBounds(image_filter, bounds)
    local obj = lib.SkImageFilter_computeFastBounds(image_filter, bounds)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.ImageFilter.canComputeFastBounds(image_filter)
    return lib.SkImageFilter_canComputeFastBounds(image_filter)
end

function Skia.ImageFilter.makeWithLocalMatrix(image_filter, matrix)
    local obj = lib.SkImageFilter_makeWithLocalMatrix(image_filter, matrix)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilter.getFactory(image_filter)
    local obj = lib.SkImageFilter_getFactory(image_filter)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ImageFilter.getTypeName(image_filter)
    return lib. SkImageFilter_getTypeName(image_filter)
end

function Skia.ImageFilter.flatten(image_filter, buffer)
    lib.SkImageFilter_flatten(image_filter, buffer)
end

function Skia.ImageFilter.getFlattenableType(image_filter)
    return lib.SkImageFilter_getFlattenableType(image_filter)
end

function Skia.ImageFilter.serialize(image_filter, procs)
    local obj = lib.SkImageFilter_serialize(image_filter, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ImageFilter.serialize_2(image_filter, memory, memory_size, procs)
    return lib.SkImageFilter_serialize_2(image_filter, memory, memory_size, procs)
end

function Skia.ImageFilter.unique(image_filter)
    return lib.SkImageFilter_unique(image_filter)
end

function Skia.ImageFilter.ref(image_filter)
    lib.SkImageFilter_ref(image_filter)
end

function Skia.ImageFilter.unref(image_filter)
    lib.SkImageFilter_unref(image_filter)
end

function Skia.ImageFilter.Deserialize(data, size, procs)
    local obj = lib.SkImageFilter_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilter.NameToFactory(name)
    local obj = lib.SkImageFilter_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.ImageFilter.FactoryToName(factory)
    return lib. SkImageFilter_FactoryToName(factory)
end

function Skia.ImageFilter.Register(name, factory)
    lib.SkImageFilter_Register(name, factory)
end

-- ## sk_image_filters
Skia.ImageFilters = {}

function Skia.ImageFilters.delete(imageFilters)
    lib.SkImageFilters_delete(imageFilters)
end

function Skia.ImageFilters.Arithmetic(k1, k2, k3, k4, enforcePMColor, background, foreground, cropRect)
    local obj = lib.SkImageFilters_Arithmetic(k1, k2, k3, k4, enforcePMColor, background, foreground, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Blend(mode, background, foreground, cropRect)
    local obj = lib.SkImageFilters_Blend(mode, background, foreground, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Blend_2(blender, background, foreground, cropRect)
    local obj = lib.SkImageFilters_Blend_2(blender, background, foreground, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Blur(sigmaX, sigmaY, tileMode, input, cropRect)
    local obj = lib.SkImageFilters_Blur(sigmaX, sigmaY, tileMode, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Blur_2(sigmaX, sigmaY, input, cropRect)
    local obj = lib.SkImageFilters_Blur_2(sigmaX, sigmaY, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.ColorFilter(cf, input, cropRect)
    local obj = lib.SkImageFilters_ColorFilter(cf, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Compose(outer, inner)
    local obj = lib.SkImageFilters_Compose(outer, inner)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Crop(rect, tileMode, input)
    local obj = lib.SkImageFilters_Crop(rect, tileMode, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Crop_2(rect, input)
    local obj = lib.SkImageFilters_Crop_2(rect, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.DisplacementMap(xChannelSelector, yChannelSelector, scale, displacement, color, cropRect)
    local obj = lib.SkImageFilters_DisplacementMap(xChannelSelector, yChannelSelector, scale, displacement, color, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.DropShadow(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    local obj = lib.SkImageFilters_DropShadow(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.DropShadowOnly(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    local obj = lib.SkImageFilters_DropShadowOnly(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Empty()
    local obj = lib.SkImageFilters_Empty()
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Image(image, srcRect, dstRect, sampling)
    local obj = lib.SkImageFilters_Image(image, srcRect, dstRect, sampling)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Image_2(image, sampling)
    local obj = lib.SkImageFilters_Image_2(image, sampling)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Magnifier(lensBounds, zoomAmount, inset, sampling, input, cropRect)
    local obj = lib.SkImageFilters_Magnifier(lensBounds, zoomAmount, inset, sampling, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.MatrixConvolution(kernelSize, kernel, gain, bias, kernelOffset, tileMode, convolveAlpha, input, cropRect)
    local obj = lib.SkImageFilters_MatrixConvolution(kernelSize, kernel, gain, bias, kernelOffset, tileMode, convolveAlpha, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.MatrixTransform(matrix, sampling, input)
    local obj = lib.SkImageFilters_MatrixTransform(matrix, sampling, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Merge(filters, count, cropRect)
    local obj = lib.SkImageFilters_Merge(filters, count, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Merge_2(first, second, cropRect)
    local obj = lib.SkImageFilters_Merge_2(first, second, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Offset(dx, dy, input, cropRect)
    local obj = lib.SkImageFilters_Offset(dx, dy, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Picture(picture, targetRect)
    local obj = lib.SkImageFilters_Picture(picture, targetRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Picture_2(picture)
    local obj = lib.SkImageFilters_Picture_2(picture)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.RuntimeShader(builder, childShaderName, input)
    local obj = lib.SkImageFilters_RuntimeShader(builder, childShaderName, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.RuntimeShader_2(builder, sampleRadius, childShaderName, input)
    local obj = lib.SkImageFilters_RuntimeShader_2(builder, sampleRadius, childShaderName, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.RuntimeShader_3(builder, childShaderNames, inputs, inputCount)
    local obj = lib.SkImageFilters_RuntimeShader_3(builder, childShaderNames, inputs, inputCount)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.RuntimeShader_4(builder, maxSampleRadius, childShaderNames, inputs, inputCount)
    local obj = lib.SkImageFilters_RuntimeShader_4(builder, maxSampleRadius, childShaderNames, inputs, inputCount)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Shader(shader, cropRect)
    local obj = lib.SkImageFilters_Shader(shader, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Shader_2(shader, dither, cropRect)
    local obj = lib.SkImageFilters_Shader_2(shader, dither, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Tile(src, dst, input)
    local obj = lib.SkImageFilters_Tile(src, dst, input)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Dilate(radiusX, radiusY, input, cropRect)
    local obj = lib.SkImageFilters_Dilate(radiusX, radiusY, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.Erode(radiusX, radiusY, input, cropRect)
    local obj = lib.SkImageFilters_Erode(radiusX, radiusY, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.DistantLitDiffuse(direction, lightColor, surfaceScale, kd, input, cropRect)
    local obj = lib.SkImageFilters_DistantLitDiffuse(direction, lightColor, surfaceScale, kd, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.PointLitDiffuse(location, lightColor, surfaceScale, kd, input, cropRect)
    local obj = lib.SkImageFilters_PointLitDiffuse(location, lightColor, surfaceScale, kd, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.SpotLitDiffuse(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, input, cropRect)
    local obj = lib.SkImageFilters_SpotLitDiffuse(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.DistantLitSpecular(direction, lightColor, surfaceScale, ks, shininess, input, cropRect)
    local obj = lib.SkImageFilters_DistantLitSpecular(direction, lightColor, surfaceScale, ks, shininess, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.PointLitSpecular(location, lightColor, surfaceScale, ks, shininess, input, cropRect)
    local obj = lib.SkImageFilters_PointLitSpecular(location, lightColor, surfaceScale, ks, shininess, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.ImageFilters.SpotLitSpecular(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, input, cropRect)
    local obj = lib.SkImageFilters_SpotLitSpecular(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, input, cropRect)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

-- ## sk_image_generator
Skia.ImageGenerator = {}

function Skia.ImageGenerator.delete(image_generator)
    lib.SkImageGenerator_delete(image_generator)
end

function Skia.ImageGenerator.uniqueID(image_generator)
    return lib.SkImageGenerator_uniqueID(image_generator)
end

function Skia.ImageGenerator.refEncodedData(image_generator)
    local obj = lib.SkImageGenerator_refEncodedData(image_generator)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.ImageGenerator.getInfo(image_generator)
    local obj = lib.SkImageGenerator_getInfo(image_generator)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageGenerator.isValid(image_generator, context)
    return lib.SkImageGenerator_isValid(image_generator, context)
end

function Skia.ImageGenerator.isProtected(image_generator)
    return lib.SkImageGenerator_isProtected(image_generator)
end

function Skia.ImageGenerator.getPixels(image_generator, info, pixels, rowBytes)
    return lib.SkImageGenerator_getPixels(image_generator, info, pixels, rowBytes)
end

function Skia.ImageGenerator.getPixels_2(image_generator, pm)
    return lib.SkImageGenerator_getPixels_2(image_generator, pm)
end

function Skia.ImageGenerator.queryYUVAInfo(image_generator, supportedDataTypes, yuvaPixmapInfo)
    return lib.SkImageGenerator_queryYUVAInfo(image_generator, supportedDataTypes, yuvaPixmapInfo)
end

function Skia.ImageGenerator.getYUVAPlanes(image_generator, yuvaPixmaps)
    return lib.SkImageGenerator_getYUVAPlanes(image_generator, yuvaPixmaps)
end

function Skia.ImageGenerator.isTextureGenerator(image_generator)
    return lib.SkImageGenerator_isTextureGenerator(image_generator)
end

-- ## sk_image_info
Skia.ImageInfo = {}

function Skia.ImageInfo.new()
    return lib.SkImageInfo_new()
end

function Skia.ImageInfo.delete(image_info)
    lib.SkImageInfo_delete(image_info)
end

function Skia.ImageInfo.width(image_info)
    return lib.SkImageInfo_width(image_info)
end

function Skia.ImageInfo.height(image_info)
    return lib.SkImageInfo_height(image_info)
end

function Skia.ImageInfo.colorType(image_info)
    return lib.SkImageInfo_colorType(image_info)
end

function Skia.ImageInfo.alphaType(image_info)
    return lib.SkImageInfo_alphaType(image_info)
end

function Skia.ImageInfo.colorSpace(image_info)
    return lib. SkImageInfo_colorSpace(image_info)
end

function Skia.ImageInfo.refColorSpace(image_info)
    local obj = lib.SkImageInfo_refColorSpace(image_info)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.ImageInfo.isEmpty(image_info)
    return lib.SkImageInfo_isEmpty(image_info)
end

function Skia.ImageInfo.colorInfo(image_info)
    local obj = lib.SkImageInfo_colorInfo(image_info)
    setFinalizer(obj, lib.static_sk_color_info_delete)
    return obj
end

function Skia.ImageInfo.isOpaque(image_info)
    return lib.SkImageInfo_isOpaque(image_info)
end

function Skia.ImageInfo.dimensions(image_info)
    local obj = lib.SkImageInfo_dimensions(image_info)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.ImageInfo.bounds(image_info)
    local obj = lib.SkImageInfo_bounds(image_info)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.ImageInfo.gammaCloseToSRGB(image_info)
    return lib.SkImageInfo_gammaCloseToSRGB(image_info)
end

function Skia.ImageInfo.makeWH(image_info, newWidth, newHeight)
    local obj = lib.SkImageInfo_makeWH(image_info, newWidth, newHeight)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.makeDimensions(image_info, newSize)
    local obj = lib.SkImageInfo_makeDimensions(image_info, newSize)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.makeAlphaType(image_info, newAlphaType)
    local obj = lib.SkImageInfo_makeAlphaType(image_info, newAlphaType)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.makeColorType(image_info, newColorType)
    local obj = lib.SkImageInfo_makeColorType(image_info, newColorType)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.makeColorSpace(image_info, color_space)
    local obj = lib.SkImageInfo_makeColorSpace(image_info, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.bytesPerPixel(image_info)
    return lib.SkImageInfo_bytesPerPixel(image_info)
end

function Skia.ImageInfo.shiftPerPixel(image_info)
    return lib.SkImageInfo_shiftPerPixel(image_info)
end

function Skia.ImageInfo.minRowBytes64(image_info)
    return lib.SkImageInfo_minRowBytes64(image_info)
end

function Skia.ImageInfo.minRowBytes(image_info)
    return lib.SkImageInfo_minRowBytes(image_info)
end

function Skia.ImageInfo.computeOffset(image_info, x, y, rowBytes)
    return lib.SkImageInfo_computeOffset(image_info, x, y, rowBytes)
end

function Skia.ImageInfo.computeByteSize(image_info, rowBytes)
    return lib.SkImageInfo_computeByteSize(image_info, rowBytes)
end

function Skia.ImageInfo.computeMinByteSize(image_info)
    return lib.SkImageInfo_computeMinByteSize(image_info)
end

function Skia.ImageInfo.validRowBytes(image_info, rowBytes)
    return lib.SkImageInfo_validRowBytes(image_info, rowBytes)
end

function Skia.ImageInfo.reset(image_info)
    lib.SkImageInfo_reset(image_info)
end

function Skia.ImageInfo.Make(width, height, ct, at)
    local obj = lib.SkImageInfo_Make(width, height, ct, at)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.Make_2(width, height, ct, at, color_space)
    local obj = lib.SkImageInfo_Make_2(width, height, ct, at, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.Make_3(dimensions, ct, at)
    local obj = lib.SkImageInfo_Make_3(dimensions, ct, at)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.Make_4(dimensions, ct, at, color_space)
    local obj = lib.SkImageInfo_Make_4(dimensions, ct, at, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.Make_5(dimensions, colorInfo)
    local obj = lib.SkImageInfo_Make_5(dimensions, colorInfo)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32(width, height, at)
    local obj = lib.SkImageInfo_MakeN32(width, height, at)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32_2(width, height, at, color_space)
    local obj = lib.SkImageInfo_MakeN32_2(width, height, at, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeS32(width, height, at)
    local obj = lib.SkImageInfo_MakeS32(width, height, at)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32Premul(width, height)
    local obj = lib.SkImageInfo_MakeN32Premul(width, height)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32Premul_2(width, height, color_space)
    local obj = lib.SkImageInfo_MakeN32Premul_2(width, height, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32Premul_3(dimensions)
    local obj = lib.SkImageInfo_MakeN32Premul_3(dimensions)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeN32Premul_4(dimensions, color_space)
    local obj = lib.SkImageInfo_MakeN32Premul_4(dimensions, color_space)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeA8(width, height)
    local obj = lib.SkImageInfo_MakeA8(width, height)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeA8_2(dimensions)
    local obj = lib.SkImageInfo_MakeA8_2(dimensions)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeUnknown(width, height)
    local obj = lib.SkImageInfo_MakeUnknown(width, height)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.MakeUnknown_2()
    local obj = lib.SkImageInfo_MakeUnknown_2()
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.ImageInfo.ByteSizeOverflowed(byteSize)
    return lib.SkImageInfo_ByteSizeOverflowed(byteSize)
end

-- ## sk_images
Skia.Images = {}

function Skia.Images.RasterFromBitmap(bitmap)
    local obj = lib.SkImages_RasterFromBitmap(bitmap)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.RasterFromCompressedTextureData(data, width, height, type)
    local obj = lib.SkImages_RasterFromCompressedTextureData(data, width, height, type)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.DeferredFromEncodedData(data)
    local obj = lib.SkImages_DeferredFromEncodedData(data)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.DeferredFromGenerator(image_generator)
    local obj = lib.SkImages_DeferredFromGenerator(image_generator)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.DeferredFromPicture(picture, dimensions, matrix, paint, bitDepth, color_space, props)
    local obj = lib.SkImages_DeferredFromPicture(picture, dimensions, matrix, paint, bitDepth, color_space, props)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.DeferredFromPicture_2(picture, dimensions, matrix, paint, bitDepth, color_space)
    local obj = lib.SkImages_DeferredFromPicture_2(picture, dimensions, matrix, paint, bitDepth, color_space)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.RasterFromPixmapCopy(pixmap)
    local obj = lib.SkImages_RasterFromPixmapCopy(pixmap)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.RasterFromPixmap(pixmap, rasterReleaseProc, releaseContext)
    local obj = lib.SkImages_RasterFromPixmap(pixmap, rasterReleaseProc, releaseContext)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.RasterFromData(info, data, rowBytes)
    local obj = lib.SkImages_RasterFromData(info, data, rowBytes)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Images.MakeWithFilter(image, filter, subset, clipBounds, outSubset, offset)
    local obj = lib.SkImages_MakeWithFilter(image, filter, subset, clipBounds, outSubset, offset)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

-- ## sk_jpeg_decoder
Skia.JpegDecoder = {}

function Skia.JpegDecoder.IsJpeg(ptr, size)
    return lib.SkJpegDecoder_IsJpeg(ptr, size)
end

function Skia.JpegDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkJpegDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.JpegDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkJpegDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.JpegDecoder.Decoder()
    local obj = lib.SkJpegDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

--[[
-- ## sk_jpeg_encoder
Skia.JpegEncoder = {}

function Skia.JpegEncoder.Encode(dst, src, options)
    return lib.SkJpegEncoder_Encode(dst, src, options)
end

function Skia.JpegEncoder.Encode_2(dst, src, srcColorSpace, options)
    return lib.SkJpegEncoder_Encode_2(dst, src, srcColorSpace, options)
end

function Skia.JpegEncoder.Encode_3(ctx, img, options)
    local obj = lib.SkJpegEncoder_Encode_3(ctx, img, options)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.JpegEncoder.Make(dst, src, options)
    local obj = lib.SkJpegEncoder_Make(dst, src, options)
    setFinalizer(obj, lib.static_sk_encoder_delete)
    return obj
end

function Skia.JpegEncoder.Make_2(dst, src, srcColorSpace, options)
    local obj = lib.SkJpegEncoder_Make_2(dst, src, srcColorSpace, options)
    setFinalizer(obj, lib.static_sk_encoder_delete)
    return obj
end
]]

-- ## sk_jpegxl_decoder
Skia.JpegXLDecoder = {}

-- ## sk_line_2d_path_effect
Skia.Line2DPathEffect = {}

function Skia.Line2DPathEffect.delete(line2DPathEffect)
    lib.SkLine2DPathEffect_delete(line2DPathEffect)
end

function Skia.Line2DPathEffect.Make(width, matrix)
    local obj = lib.SkLine2DPathEffect_Make(width, matrix)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.Line2DPathEffect.RegisterFlattenables()
    lib.SkLine2DPathEffect_RegisterFlattenables()
end

-- ## sk_luma_color_filter
Skia.LumaColorFilter = {}

function Skia.LumaColorFilter.delete(lumaColorFilter)
    lib.SkLumaColorFilter_delete(lumaColorFilter)
end

function Skia.LumaColorFilter.Make()
    local obj = lib.SkLumaColorFilter_Make()
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

-- ## sk_m_44
Skia.M44 = {}

function Skia.M44.new(src)
    local obj = lib.SkM44_new(src)
    ffi.gc(obj, lib.SkM44_delete)
    return obj
end

function Skia.M44.new_2(src)
    local obj = lib.SkM44_new_2(src)
    ffi.gc(obj, lib.SkM44_delete)
    return obj
end

function Skia.M44.new_3()
    local obj = lib.SkM44_new_3()
    ffi.gc(obj, lib.SkM44_delete)
    return obj
end

function Skia.M44.new_4(a, b)
    local obj = lib.SkM44_new_4(a, b)
    ffi.gc(obj, lib.SkM44_delete)
    return obj
end

function Skia.M44.new_5(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15)
    local obj = lib.SkM44_new_5(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15)
    ffi.gc(obj, lib.SkM44_delete)
    return obj
end

function Skia.M44.delete(m44)
    lib.SkM44_delete(m44)
end

function Skia.M44.getColMajor(m44, v)
    lib.SkM44_getColMajor(m44, v)
end

function Skia.M44.getRowMajor(m44, v)
    lib.SkM44_getRowMajor(m44, v)
end

function Skia.M44.rc(m44, r, c)
    return lib.SkM44_rc(m44, r, c)
end

function Skia.M44.setRC(m44, r, c, value)
    lib.SkM44_setRC(m44, r, c, value)
end

function Skia.M44.row(m44, i)
    local obj = lib.SkM44_row(m44, i)
    setFinalizer(obj, lib.static_sk_v4_delete)
    return obj
end

function Skia.M44.col(m44, i)
    local obj = lib.SkM44_col(m44, i)
    setFinalizer(obj, lib.static_sk_v4_delete)
    return obj
end

function Skia.M44.setRow(m44, i, v)
    lib.SkM44_setRow(m44, i, v)
end

function Skia.M44.setCol(m44, i, v)
    lib.SkM44_setCol(m44, i, v)
end

function Skia.M44.setIdentity(m44)
    local obj = lib.SkM44_setIdentity(m44)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setTranslate(m44, x, y, z)
    local obj = lib.SkM44_setTranslate(m44, x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setScale(m44, x, y, z)
    local obj = lib.SkM44_setScale(m44, x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setRotateUnitSinCos(m44, axis, sinAngle, cosAngle)
    local obj = lib.SkM44_setRotateUnitSinCos(m44, axis, sinAngle, cosAngle)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setRotateUnit(m44, axis, radians)
    local obj = lib.SkM44_setRotateUnit(m44, axis, radians)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setRotate(m44, axis, radians)
    local obj = lib.SkM44_setRotate(m44, axis, radians)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.setConcat(m44, a, b)
    local obj = lib.SkM44_setConcat(m44, a, b)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.preConcat(m44, m)
    local obj = lib.SkM44_preConcat(m44, m)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.preConcat_2(m44, matrix)
    local obj = lib.SkM44_preConcat_2(m44, matrix)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.postConcat(m44, m)
    local obj = lib.SkM44_postConcat(m44, m)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.normalizePerspective(m44)
    lib.SkM44_normalizePerspective(m44)
end

function Skia.M44.isFinite(m44)
    return lib.SkM44_isFinite(m44)
end

function Skia.M44.invert(m44, inverse)
    return lib.SkM44_invert(m44, inverse)
end

function Skia.M44.transpose(m44)
    local obj = lib.SkM44_transpose(m44)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.dump(m44)
    lib.SkM44_dump(m44)
end

function Skia.M44.map(m44, x, y, z, w)
    local obj = lib.SkM44_map(m44, x, y, z, w)
    setFinalizer(obj, lib.static_sk_v4_delete)
    return obj
end

function Skia.M44.asM33(m44)
    local obj = lib.SkM44_asM33(m44)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.M44.preTranslate(m44, x, y, z)
    local obj = lib.SkM44_preTranslate(m44, x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.postTranslate(m44, x, y, z)
    local obj = lib.SkM44_postTranslate(m44, x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.preScale(m44, x, y)
    local obj = lib.SkM44_preScale(m44, x, y)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.preScale_2(m44, x, y, z)
    local obj = lib.SkM44_preScale_2(m44, x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Rows(r0, r1, r2, r3)
    local obj = lib.SkM44_Rows(r0, r1, r2, r3)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Cols(c0, c1, c2, c3)
    local obj = lib.SkM44_Cols(c0, c1, c2, c3)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.RowMajor(r)
    local obj = lib.SkM44_RowMajor(r)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.ColMajor(c)
    local obj = lib.SkM44_ColMajor(c)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Translate(x, y, z)
    local obj = lib.SkM44_Translate(x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Scale(x, y, z)
    local obj = lib.SkM44_Scale(x, y, z)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Rotate(axis, radians)
    local obj = lib.SkM44_Rotate(axis, radians)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.RectToRect(src, dst)
    local obj = lib.SkM44_RectToRect(src, dst)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.LookAt(eye, center, up)
    local obj = lib.SkM44_LookAt(eye, center, up)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

function Skia.M44.Perspective(near, far, angle)
    local obj = lib.SkM44_Perspective(near, far, angle)
    setFinalizer(obj, lib.static_sk_m_44_delete)
    return obj
end

-- ## sk_malloc_pixel_ref
Skia.MallocPixelRef = {}

function Skia.MallocPixelRef.MakeAllocate(imageInfo, rowBytes)
    local obj = lib.SkMallocPixelRef_MakeAllocate(imageInfo, rowBytes)
    setFinalizer(obj, lib.static_sk_pixel_ref_delete)
    return obj
end

function Skia.MallocPixelRef.MakeWithData(imageInfo, rowBytes, data)
    local obj = lib.SkMallocPixelRef_MakeWithData(imageInfo, rowBytes, data)
    setFinalizer(obj, lib.static_sk_pixel_ref_delete)
    return obj
end

-- ## sk_mask_filter
Skia.MaskFilter = {}

function Skia.MaskFilter.delete(maskFilter)
    lib.SkMaskFilter_delete(maskFilter)
end

function Skia.MaskFilter.approximateFilteredBounds(mask_filter, src)
    local obj = lib.SkMaskFilter_approximateFilteredBounds(mask_filter, src)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.MaskFilter.getFactory(mask_filter)
    local obj = lib.SkMaskFilter_getFactory(mask_filter)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.MaskFilter.getTypeName(mask_filter)
    return lib. SkMaskFilter_getTypeName(mask_filter)
end

function Skia.MaskFilter.flatten(mask_filter, buffer)
    lib.SkMaskFilter_flatten(mask_filter, buffer)
end

function Skia.MaskFilter.getFlattenableType(mask_filter)
    return lib.SkMaskFilter_getFlattenableType(mask_filter)
end

function Skia.MaskFilter.serialize(mask_filter, procs)
    local obj = lib.SkMaskFilter_serialize(mask_filter, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.MaskFilter.serialize_2(mask_filter, memory, memory_size, procs)
    return lib.SkMaskFilter_serialize_2(mask_filter, memory, memory_size, procs)
end

function Skia.MaskFilter.unique(mask_filter)
    return lib.SkMaskFilter_unique(mask_filter)
end

function Skia.MaskFilter.ref(mask_filter)
    lib.SkMaskFilter_ref(mask_filter)
end

function Skia.MaskFilter.unref(mask_filter)
    lib.SkMaskFilter_unref(mask_filter)
end

function Skia.MaskFilter.MakeBlur(style, sigma, respectCTM)
    local obj = lib.SkMaskFilter_MakeBlur(style, sigma, respectCTM)
    setFinalizer(obj, lib.static_sk_mask_filter_delete)
    return obj
end

function Skia.MaskFilter.Deserialize(data, size, procs)
    local obj = lib.SkMaskFilter_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_mask_filter_delete)
    return obj
end

function Skia.MaskFilter.NameToFactory(name)
    local obj = lib.SkMaskFilter_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.MaskFilter.FactoryToName(factory)
    return lib. SkMaskFilter_FactoryToName(factory)
end

function Skia.MaskFilter.Register(name, factory)
    lib.SkMaskFilter_Register(name, factory)
end

-- ## sk_matrix
Skia.Matrix = {}

function Skia.Matrix.new(matrix)
    local obj = lib.SkMatrix_new(matrix)
    ffi.gc(obj, lib.SkMatrix_delete)
    return obj
end

function Skia.Matrix.delete(matrix)
    lib.SkMatrix_delete(matrix)
end

function Skia.Matrix.getType(matrix)
    return lib.SkMatrix_getType(matrix)
end

function Skia.Matrix.isIdentity(matrix)
    return lib.SkMatrix_isIdentity(matrix)
end

function Skia.Matrix.isScaleTranslate(matrix)
    return lib.SkMatrix_isScaleTranslate(matrix)
end

function Skia.Matrix.isTranslate(matrix)
    return lib.SkMatrix_isTranslate(matrix)
end

function Skia.Matrix.rectStaysRect(matrix)
    return lib.SkMatrix_rectStaysRect(matrix)
end

function Skia.Matrix.preservesAxisAlignment(matrix)
    return lib.SkMatrix_preservesAxisAlignment(matrix)
end

function Skia.Matrix.hasPerspective(matrix)
    return lib.SkMatrix_hasPerspective(matrix)
end

function Skia.Matrix.isSimilarity(matrix, tol)
    return lib.SkMatrix_isSimilarity(matrix, tol)
end

function Skia.Matrix.preservesRightAngles(matrix, tol)
    return lib.SkMatrix_preservesRightAngles(matrix, tol)
end

function Skia.Matrix.get(matrix, index)
    return lib.SkMatrix_get(matrix, index)
end

function Skia.Matrix.rc(matrix, r, c)
    return lib.SkMatrix_rc(matrix, r, c)
end

function Skia.Matrix.getScaleX(matrix)
    return lib.SkMatrix_getScaleX(matrix)
end

function Skia.Matrix.getScaleY(matrix)
    return lib.SkMatrix_getScaleY(matrix)
end

function Skia.Matrix.getSkewY(matrix)
    return lib.SkMatrix_getSkewY(matrix)
end

function Skia.Matrix.getSkewX(matrix)
    return lib.SkMatrix_getSkewX(matrix)
end

function Skia.Matrix.getTranslateX(matrix)
    return lib.SkMatrix_getTranslateX(matrix)
end

function Skia.Matrix.getTranslateY(matrix)
    return lib.SkMatrix_getTranslateY(matrix)
end

function Skia.Matrix.getPerspX(matrix)
    return lib.SkMatrix_getPerspX(matrix)
end

function Skia.Matrix.getPerspY(matrix)
    return lib.SkMatrix_getPerspY(matrix)
end

function Skia.Matrix.set(matrix, index, value)
    local obj = lib.SkMatrix_set(matrix, index, value)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setScaleX(matrix, v)
    local obj = lib.SkMatrix_setScaleX(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setScaleY(matrix, v)
    local obj = lib.SkMatrix_setScaleY(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSkewY(matrix, v)
    local obj = lib.SkMatrix_setSkewY(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSkewX(matrix, v)
    local obj = lib.SkMatrix_setSkewX(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setTranslateX(matrix, v)
    local obj = lib.SkMatrix_setTranslateX(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setTranslateY(matrix, v)
    local obj = lib.SkMatrix_setTranslateY(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setPerspX(matrix, v)
    local obj = lib.SkMatrix_setPerspX(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setPerspY(matrix, v)
    local obj = lib.SkMatrix_setPerspY(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setAll(matrix, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2)
    local obj = lib.SkMatrix_setAll(matrix, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.get9(matrix, buffer)
    lib.SkMatrix_get9(matrix, buffer)
end

function Skia.Matrix.set9(matrix, buffer)
    local obj = lib.SkMatrix_set9(matrix, buffer)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.reset(matrix)
    local obj = lib.SkMatrix_reset(matrix)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setIdentity(matrix)
    local obj = lib.SkMatrix_setIdentity(matrix)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setTranslate(matrix, dx, dy)
    local obj = lib.SkMatrix_setTranslate(matrix, dx, dy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setTranslate_2(matrix, v)
    local obj = lib.SkMatrix_setTranslate_2(matrix, v)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setScale(matrix, sx, sy, px, py)
    local obj = lib.SkMatrix_setScale(matrix, sx, sy, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setScale_2(matrix, sx, sy)
    local obj = lib.SkMatrix_setScale_2(matrix, sx, sy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setRotate(matrix, degrees, px, py)
    local obj = lib.SkMatrix_setRotate(matrix, degrees, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setRotate_2(matrix, degrees)
    local obj = lib.SkMatrix_setRotate_2(matrix, degrees)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSinCos(matrix, sinValue, cosValue, px, py)
    local obj = lib.SkMatrix_setSinCos(matrix, sinValue, cosValue, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSinCos_2(matrix, sinValue, cosValue)
    local obj = lib.SkMatrix_setSinCos_2(matrix, sinValue, cosValue)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setRSXform(matrix, rsxForm)
    local obj = lib.SkMatrix_setRSXform(matrix, rsxForm)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSkew(matrix, kx, ky, px, py)
    local obj = lib.SkMatrix_setSkew(matrix, kx, ky, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setSkew_2(matrix, kx, ky)
    local obj = lib.SkMatrix_setSkew_2(matrix, kx, ky)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setConcat(matrix, a, b)
    local obj = lib.SkMatrix_setConcat(matrix, a, b)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preTranslate(matrix, dx, dy)
    local obj = lib.SkMatrix_preTranslate(matrix, dx, dy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preScale(matrix, sx, sy, px, py)
    local obj = lib.SkMatrix_preScale(matrix, sx, sy, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preScale_2(matrix, sx, sy)
    local obj = lib.SkMatrix_preScale_2(matrix, sx, sy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preRotate(matrix, degrees, px, py)
    local obj = lib.SkMatrix_preRotate(matrix, degrees, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preRotate_2(matrix, degrees)
    local obj = lib.SkMatrix_preRotate_2(matrix, degrees)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preSkew(matrix, kx, ky, px, py)
    local obj = lib.SkMatrix_preSkew(matrix, kx, ky, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preSkew_2(matrix, kx, ky)
    local obj = lib.SkMatrix_preSkew_2(matrix, kx, ky)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.preConcat(matrix, other)
    local obj = lib.SkMatrix_preConcat(matrix, other)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postTranslate(matrix, dx, dy)
    local obj = lib.SkMatrix_postTranslate(matrix, dx, dy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postScale(matrix, sx, sy, px, py)
    local obj = lib.SkMatrix_postScale(matrix, sx, sy, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postScale_2(matrix, sx, sy)
    local obj = lib.SkMatrix_postScale_2(matrix, sx, sy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postRotate(matrix, degrees, px, py)
    local obj = lib.SkMatrix_postRotate(matrix, degrees, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postRotate_2(matrix, degrees)
    local obj = lib.SkMatrix_postRotate_2(matrix, degrees)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postSkew(matrix, kx, ky, px, py)
    local obj = lib.SkMatrix_postSkew(matrix, kx, ky, px, py)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postSkew_2(matrix, kx, ky)
    local obj = lib.SkMatrix_postSkew_2(matrix, kx, ky)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.postConcat(matrix, other)
    local obj = lib.SkMatrix_postConcat(matrix, other)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.setRectToRect(matrix, src, dst, stf)
    return lib.SkMatrix_setRectToRect(matrix, src, dst, stf)
end

function Skia.Matrix.setPolyToPoly(matrix, src, dst, count)
    return lib.SkMatrix_setPolyToPoly(matrix, src, dst, count)
end

function Skia.Matrix.invert(matrix, inverse)
    return lib.SkMatrix_invert(matrix, inverse)
end

function Skia.Matrix.asAffine(matrix, affine)
    return lib.SkMatrix_asAffine(matrix, affine)
end

function Skia.Matrix.setAffine(matrix, affine)
    local obj = lib.SkMatrix_setAffine(matrix, affine)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.normalizePerspective(matrix)
    lib.SkMatrix_normalizePerspective(matrix)
end

function Skia.Matrix.mapPoints(matrix, dst, src, count)
    lib.SkMatrix_mapPoints(matrix, dst, src, count)
end

function Skia.Matrix.mapPoints_2(matrix, pts, count)
    lib.SkMatrix_mapPoints_2(matrix, pts, count)
end

function Skia.Matrix.mapHomogeneousPoints(matrix, dst, src, count)
    lib.SkMatrix_mapHomogeneousPoints(matrix, dst, src, count)
end

function Skia.Matrix.mapHomogeneousPoints_2(matrix, dst, src, count)
    lib.SkMatrix_mapHomogeneousPoints_2(matrix, dst, src, count)
end

function Skia.Matrix.mapPoint(matrix, pt)
    local obj = lib.SkMatrix_mapPoint(matrix, pt)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Matrix.mapXY(matrix, x, y, result)
    lib.SkMatrix_mapXY(matrix, x, y, result)
end

function Skia.Matrix.mapXY_2(matrix, x, y)
    local obj = lib.SkMatrix_mapXY_2(matrix, x, y)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Matrix.mapOrigin(matrix)
    local obj = lib.SkMatrix_mapOrigin(matrix)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Matrix.mapVectors(matrix, dst, src, count)
    lib.SkMatrix_mapVectors(matrix, dst, src, count)
end

function Skia.Matrix.mapVectors_2(matrix, vecs, count)
    lib.SkMatrix_mapVectors_2(matrix, vecs, count)
end

function Skia.Matrix.mapVector(matrix, dx, dy, result)
    lib.SkMatrix_mapVector(matrix, dx, dy, result)
end

function Skia.Matrix.mapVector_2(matrix, dx, dy)
    local obj = lib.SkMatrix_mapVector_2(matrix, dx, dy)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Matrix.mapRect(matrix, dst, src, pc)
    return lib.SkMatrix_mapRect(matrix, dst, src, pc)
end

function Skia.Matrix.mapRect_2(matrix, rect, pc)
    return lib.SkMatrix_mapRect_2(matrix, rect, pc)
end

function Skia.Matrix.mapRect_3(matrix, src, pc)
    local obj = lib.SkMatrix_mapRect_3(matrix, src, pc)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.mapRectToQuad(matrix, dst, rect)
    lib.SkMatrix_mapRectToQuad(matrix, dst, rect)
end

function Skia.Matrix.mapRectScaleTranslate(matrix, dst, src)
    lib.SkMatrix_mapRectScaleTranslate(matrix, dst, src)
end

function Skia.Matrix.mapRadius(matrix, radius)
    return lib.SkMatrix_mapRadius(matrix, radius)
end

function Skia.Matrix.dump(matrix)
    lib.SkMatrix_dump(matrix)
end

function Skia.Matrix.getMinScale(matrix)
    return lib.SkMatrix_getMinScale(matrix)
end

function Skia.Matrix.getMaxScale(matrix)
    return lib.SkMatrix_getMaxScale(matrix)
end

function Skia.Matrix.getMinMaxScales(matrix, scaleFactors)
    return lib.SkMatrix_getMinMaxScales(matrix, scaleFactors)
end

function Skia.Matrix.decomposeScale(matrix, scale, remaining)
    return lib.SkMatrix_decomposeScale(matrix, scale, remaining)
end

function Skia.Matrix.dirtyMatrixTypeCache(matrix)
    lib.SkMatrix_dirtyMatrixTypeCache(matrix)
end

function Skia.Matrix.setScaleTranslate(matrix, sx, sy, tx, ty)
    lib.SkMatrix_setScaleTranslate(matrix, sx, sy, tx, ty)
end

function Skia.Matrix.isFinite(matrix)
    return lib.SkMatrix_isFinite(matrix)
end

function Skia.Matrix.Scale(sx, sy)
    local obj = lib.SkMatrix_Scale(sx, sy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.Translate(dx, dy)
    local obj = lib.SkMatrix_Translate(dx, dy)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.Translate_2(t)
    local obj = lib.SkMatrix_Translate_2(t)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.Translate_3(t)
    local obj = lib.SkMatrix_Translate_3(t)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.RotateDeg(deg)
    local obj = lib.SkMatrix_RotateDeg(deg)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.RotateDeg_2(deg, pt)
    local obj = lib.SkMatrix_RotateDeg_2(deg, pt)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.RotateRad(rad)
    local obj = lib.SkMatrix_RotateRad(rad)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.Skew(kx, ky)
    local obj = lib.SkMatrix_Skew(kx, ky)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.RectToRect(src, dst, mode)
    local obj = lib.SkMatrix_RectToRect(src, dst, mode)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2)
    local obj = lib.SkMatrix_MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.MakeRectToRect(src, dst, stf)
    local obj = lib.SkMatrix_MakeRectToRect(src, dst, stf)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.SetAffineIdentity(affine)
    lib.SkMatrix_SetAffineIdentity(affine)
end

function Skia.Matrix.I()
    local obj = lib.SkMatrix_I()
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.InvalidMatrix()
    local obj = lib.SkMatrix_InvalidMatrix()
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.Matrix.Concat(a, b)
    local obj = lib.SkMatrix_Concat(a, b)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

-- ## sk_memory_stream
Skia.MemoryStream = {}

function Skia.MemoryStream.new()
    local obj = lib.SkMemoryStream_new()
    ffi.gc(obj, lib.SkMemoryStream_delete)
    return obj
end

function Skia.MemoryStream.new_2(length)
    local obj = lib.SkMemoryStream_new_2(length)
    ffi.gc(obj, lib.SkMemoryStream_delete)
    return obj
end

function Skia.MemoryStream.new_3(data, length, copyData)
    local obj = lib.SkMemoryStream_new_3(data, length, copyData)
    ffi.gc(obj, lib.SkMemoryStream_delete)
    return obj
end

function Skia.MemoryStream.new_4(data)
    local obj = lib.SkMemoryStream_new_4(data)
    ffi.gc(obj, lib.SkMemoryStream_delete)
    return obj
end

function Skia.MemoryStream.delete(memoryStream)
    lib.SkMemoryStream_delete(memoryStream)
end

function Skia.MemoryStream.setMemory(memory_stream, data, length, copyData)
    lib.SkMemoryStream_setMemory(memory_stream, data, length, copyData)
end

function Skia.MemoryStream.setMemoryOwned(memory_stream, data, length)
    lib.SkMemoryStream_setMemoryOwned(memory_stream, data, length)
end

function Skia.MemoryStream.asData(memory_stream)
    local obj = lib.SkMemoryStream_asData(memory_stream)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.MemoryStream.setData(memory_stream, data)
    lib.SkMemoryStream_setData(memory_stream, data)
end

function Skia.MemoryStream.skipToAlign4(memory_stream)
    lib.SkMemoryStream_skipToAlign4(memory_stream)
end

function Skia.MemoryStream.getAtPos(memory_stream)
    return lib. SkMemoryStream_getAtPos(memory_stream)
end

function Skia.MemoryStream.read(memory_stream, buffer, size)
    return lib.SkMemoryStream_read(memory_stream, buffer, size)
end

function Skia.MemoryStream.isAtEnd(memory_stream)
    return lib.SkMemoryStream_isAtEnd(memory_stream)
end

function Skia.MemoryStream.peek(memory_stream, buffer, size)
    return lib.SkMemoryStream_peek(memory_stream, buffer, size)
end

function Skia.MemoryStream.rewind(memory_stream)
    return lib.SkMemoryStream_rewind(memory_stream)
end

function Skia.MemoryStream.duplicate(memory_stream)
    local obj = lib.SkMemoryStream_duplicate(memory_stream)
    setFinalizer(obj, lib.static_sk_memory_stream_delete)
    return obj
end

function Skia.MemoryStream.getPosition(memory_stream)
    return lib.SkMemoryStream_getPosition(memory_stream)
end

function Skia.MemoryStream.seek(memory_stream, position)
    return lib.SkMemoryStream_seek(memory_stream, position)
end

function Skia.MemoryStream.move(memory_stream, offset)
    return lib.SkMemoryStream_move(memory_stream, offset)
end

function Skia.MemoryStream.fork(memory_stream)
    local obj = lib.SkMemoryStream_fork(memory_stream)
    setFinalizer(obj, lib.static_sk_memory_stream_delete)
    return obj
end

function Skia.MemoryStream.getLength(memory_stream)
    return lib.SkMemoryStream_getLength(memory_stream)
end

function Skia.MemoryStream.getMemoryBase(memory_stream)
    return lib. SkMemoryStream_getMemoryBase(memory_stream)
end

function Skia.MemoryStream.hasLength(memory_stream)
    return lib.SkMemoryStream_hasLength(memory_stream)
end

function Skia.MemoryStream.hasPosition(memory_stream)
    return lib.SkMemoryStream_hasPosition(memory_stream)
end

function Skia.MemoryStream.skip(memory_stream, size)
    return lib.SkMemoryStream_skip(memory_stream, size)
end

function Skia.MemoryStream.readS8(memory_stream, i)
    return lib.SkMemoryStream_readS8(memory_stream, i)
end

function Skia.MemoryStream.readS16(memory_stream, i)
    return lib.SkMemoryStream_readS16(memory_stream, i)
end

function Skia.MemoryStream.readS32(memory_stream, i)
    return lib.SkMemoryStream_readS32(memory_stream, i)
end

function Skia.MemoryStream.readU8(memory_stream, i)
    return lib.SkMemoryStream_readU8(memory_stream, i)
end

function Skia.MemoryStream.readU16(memory_stream, i)
    return lib.SkMemoryStream_readU16(memory_stream, i)
end

function Skia.MemoryStream.readU32(memory_stream, i)
    return lib.SkMemoryStream_readU32(memory_stream, i)
end

function Skia.MemoryStream.readBool(memory_stream, b)
    return lib.SkMemoryStream_readBool(memory_stream, b)
end

function Skia.MemoryStream.readScalar(memory_stream, v)
    return lib.SkMemoryStream_readScalar(memory_stream, v)
end

function Skia.MemoryStream.readPackedUInt(memory_stream, size)
    return lib.SkMemoryStream_readPackedUInt(memory_stream, size)
end

function Skia.MemoryStream.MakeCopy(data, length)
    local obj = lib.SkMemoryStream_MakeCopy(data, length)
    setFinalizer(obj, lib.static_sk_memory_stream_delete)
    return obj
end

function Skia.MemoryStream.MakeDirect(data, length)
    local obj = lib.SkMemoryStream_MakeDirect(data, length)
    setFinalizer(obj, lib.static_sk_memory_stream_delete)
    return obj
end

function Skia.MemoryStream.Make(data)
    local obj = lib.SkMemoryStream_Make(data)
    setFinalizer(obj, lib.static_sk_memory_stream_delete)
    return obj
end

-- ## sk_meshes
Skia.Meshes = {}

function Skia.Meshes.MakeIndexBuffer(data, size)
    local obj = lib.SkMeshes_MakeIndexBuffer(data, size)
    setFinalizer(obj, lib.static_sk_mesh_index_buffer_delete)
    return obj
end

function Skia.Meshes.CopyIndexBuffer(indexBuffer)
    local obj = lib.SkMeshes_CopyIndexBuffer(indexBuffer)
    setFinalizer(obj, lib.static_sk_mesh_index_buffer_delete)
    return obj
end

function Skia.Meshes.MakeVertexBuffer(data, size)
    local obj = lib.SkMeshes_MakeVertexBuffer(data, size)
    setFinalizer(obj, lib.static_sk_mesh_index_buffer_delete)
    return obj
end

function Skia.Meshes.CopyVertexBuffer(vertexBuffer)
    local obj = lib.SkMeshes_CopyVertexBuffer(vertexBuffer)
    setFinalizer(obj, lib.static_sk_mesh_index_buffer_delete)
    return obj
end

-- ## sk_op_builder
Skia.OpBuilder = {}

function Skia.OpBuilder.delete(opBuilder)
    lib.SkOpBuilder_delete(opBuilder)
end

function Skia.OpBuilder.add(op_builder, path, path_operator)
    lib.SkOpBuilder_add(op_builder, path, path_operator)
end

function Skia.OpBuilder.resolve(op_builder, result)
    return lib.SkOpBuilder_resolve(op_builder, result)
end

--[[
-- ## sk_open_type_svg_decoder
Skia.OpenTypeSVGDecoder = {}

function Skia.OpenTypeSVGDecoder.delete(open_type_svg_decoder)
    lib.SkOpenTypeSVGDecoder_delete(open_type_svg_decoder)
end

function Skia.OpenTypeSVGDecoder.approximateSize(open_type_svg_decoder)
    return lib.SkOpenTypeSVGDecoder_approximateSize(open_type_svg_decoder)
end

function Skia.OpenTypeSVGDecoder.render(open_type_svg_decoder, canvas, upem, glyphId, foregroundColor, color)
    return lib.SkOpenTypeSVGDecoder_render(open_type_svg_decoder, canvas, upem, glyphId, foregroundColor, color)
end
]]

-- ## sk_overdraw_canvas
Skia.OverdrawCanvas = {}

function Skia.OverdrawCanvas.delete(overdraw_canvas)
    lib.SkOverdrawCanvas_delete(overdraw_canvas)
end

function Skia.OverdrawCanvas.onDrawTextBlob(overdraw_canvas, blob, scalar1, scalar2, paint)
    lib.SkOverdrawCanvas_onDrawTextBlob(overdraw_canvas, blob, scalar1, scalar2, paint)
end

function Skia.OverdrawCanvas.onDrawGlyphRunList(overdraw_canvas, glyphRunList, paint)
    lib.SkOverdrawCanvas_onDrawGlyphRunList(overdraw_canvas, glyphRunList, paint)
end

function Skia.OverdrawCanvas.onDrawPatch(overdraw_canvas, point1, color, point2, mode, paint)
    lib.SkOverdrawCanvas_onDrawPatch(overdraw_canvas, point1, color, point2, mode, paint)
end

function Skia.OverdrawCanvas.onDrawPaint(overdraw_canvas, paint)
    lib.SkOverdrawCanvas_onDrawPaint(overdraw_canvas, paint)
end

function Skia.OverdrawCanvas.onDrawBehind(overdraw_canvas, paint)
    lib.SkOverdrawCanvas_onDrawBehind(overdraw_canvas, paint)
end

function Skia.OverdrawCanvas.onDrawRect(overdraw_canvas, rect, paint)
    lib.SkOverdrawCanvas_onDrawRect(overdraw_canvas, rect, paint)
end

function Skia.OverdrawCanvas.onDrawRegion(overdraw_canvas, region, paint)
    lib.SkOverdrawCanvas_onDrawRegion(overdraw_canvas, region, paint)
end

function Skia.OverdrawCanvas.onDrawOval(overdraw_canvas, rect, paint)
    lib.SkOverdrawCanvas_onDrawOval(overdraw_canvas, rect, paint)
end

function Skia.OverdrawCanvas.onDrawArc(overdraw_canvas, rect, scalar1, scalar2, v, paint)
    lib.SkOverdrawCanvas_onDrawArc(overdraw_canvas, rect, scalar1, scalar2, v, paint)
end

function Skia.OverdrawCanvas.onDrawDRRect(overdraw_canvas, rect1, rect2, paint)
    lib.SkOverdrawCanvas_onDrawDRRect(overdraw_canvas, rect1, rect2, paint)
end

function Skia.OverdrawCanvas.onDrawRRect(overdraw_canvas, rect, paint)
    lib.SkOverdrawCanvas_onDrawRRect(overdraw_canvas, rect, paint)
end

function Skia.OverdrawCanvas.onDrawPoints(overdraw_canvas, mode, size, point, paint)
    lib.SkOverdrawCanvas_onDrawPoints(overdraw_canvas, mode, size, point, paint)
end

function Skia.OverdrawCanvas.onDrawVerticesObject(overdraw_canvas, vertices, mode, paint)
    lib.SkOverdrawCanvas_onDrawVerticesObject(overdraw_canvas, vertices, mode, paint)
end

function Skia.OverdrawCanvas.onDrawPath(overdraw_canvas, path, paint)
    lib.SkOverdrawCanvas_onDrawPath(overdraw_canvas, path, paint)
end

function Skia.OverdrawCanvas.onDrawImage2(overdraw_canvas, image, scalar1, scalar2, options, paint)
    lib.SkOverdrawCanvas_onDrawImage2(overdraw_canvas, image, scalar1, scalar2, options, paint)
end

function Skia.OverdrawCanvas.onDrawImageRect2(overdraw_canvas, image, rect1, rect2, options, paint, constraint)
    lib.SkOverdrawCanvas_onDrawImageRect2(overdraw_canvas, image, rect1, rect2, options, paint, constraint)
end

function Skia.OverdrawCanvas.onDrawImageLattice2(overdraw_canvas, image, lattice, rect, mode, paint)
    lib.SkOverdrawCanvas_onDrawImageLattice2(overdraw_canvas, image, lattice, rect, mode, paint)
end

function Skia.OverdrawCanvas.onDrawAtlas2(overdraw_canvas, image, form, rect1, color, v, mode, options, rect2, paint)
    lib.SkOverdrawCanvas_onDrawAtlas2(overdraw_canvas, image, form, rect1, color, v, mode, options, rect2, paint)
end

function Skia.OverdrawCanvas.onDrawDrawable(overdraw_canvas, drawable, matrix)
    lib.SkOverdrawCanvas_onDrawDrawable(overdraw_canvas, drawable, matrix)
end

function Skia.OverdrawCanvas.onDrawPicture(overdraw_canvas, picture, matrix, paint)
    lib.SkOverdrawCanvas_onDrawPicture(overdraw_canvas, picture, matrix, paint)
end

function Skia.OverdrawCanvas.onDrawAnnotation(overdraw_canvas, rect, key, value)
    lib.SkOverdrawCanvas_onDrawAnnotation(overdraw_canvas, rect, key, value)
end

function Skia.OverdrawCanvas.onDrawShadowRec(overdraw_canvas, path, rec)
    lib.SkOverdrawCanvas_onDrawShadowRec(overdraw_canvas, path, rec)
end

function Skia.OverdrawCanvas.onDrawEdgeAAQuad(overdraw_canvas, rect, point, flags, color, mode)
    lib.SkOverdrawCanvas_onDrawEdgeAAQuad(overdraw_canvas, rect, point, flags, color, mode)
end

function Skia.OverdrawCanvas.onDrawEdgeAAImageSet2(overdraw_canvas, entry, count, point, matrix, options, paint, constraint)
    lib.SkOverdrawCanvas_onDrawEdgeAAImageSet2(overdraw_canvas, entry, count, point, matrix, options, paint, constraint)
end

-- ## sk_overdraw_color_filter
Skia.OverdrawColorFilter = {}

function Skia.OverdrawColorFilter.delete(overdrawColorFilter)
    lib.SkOverdrawColorFilter_delete(overdrawColorFilter)
end

function Skia.OverdrawColorFilter.MakeWithSkColors(color)
    local obj = lib.SkOverdrawColorFilter_MakeWithSkColors(color)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

-- ## sk_paint
Skia.Paint = {}

function Skia.Paint.new()
    local obj = lib.SkPaint_new()
    ffi.gc(obj, lib.SkPaint_delete)
    return obj
end

function Skia.Paint.new_2(color, colorSpace)
    local obj = lib.SkPaint_new_2(color, colorSpace)
    ffi.gc(obj, lib.SkPaint_delete)
    return obj
end

function Skia.Paint.new_3(paint)
    local obj = lib.SkPaint_new_3(paint)
    ffi.gc(obj, lib.SkPaint_delete)
    return obj
end

function Skia.Paint.delete(paint)
    lib.SkPaint_delete(paint)
end

function Skia.Paint.reset(paint)
    lib.SkPaint_reset(paint)
end

function Skia.Paint.isAntiAlias(paint)
    return lib.SkPaint_isAntiAlias(paint)
end

function Skia.Paint.setAntiAlias(paint, aa)
    lib.SkPaint_setAntiAlias(paint, aa)
end

function Skia.Paint.isDither(paint)
    return lib.SkPaint_isDither(paint)
end

function Skia.Paint.setDither(paint, dither)
    lib.SkPaint_setDither(paint, dither)
end

function Skia.Paint.getStyle(paint)
    return lib.SkPaint_getStyle(paint)
end

function Skia.Paint.setStyle(paint, style)
    lib.SkPaint_setStyle(paint, style)
end

function Skia.Paint.setStroke(paint, v)
    lib.SkPaint_setStroke(paint, v)
end

function Skia.Paint.getColor(paint)
    return lib.SkPaint_getColor(paint)
end

function Skia.Paint.getColor4f(paint)
    local obj = lib.SkPaint_getColor4f(paint)
    setFinalizer(obj, lib.static_sk_color_4f_delete)
    return obj
end

function Skia.Paint.setColor(paint, color)
    lib.SkPaint_setColor(paint, color)
end

function Skia.Paint.setColor_2(paint, color, colorSpace)
    lib.SkPaint_setColor_2(paint, color, colorSpace)
end

function Skia.Paint.setColor4f(paint, color, colorSpace)
    lib.SkPaint_setColor4f(paint, color, colorSpace)
end

function Skia.Paint.getAlphaf(paint)
    return lib.SkPaint_getAlphaf(paint)
end

function Skia.Paint.getAlpha(paint)
    return lib.SkPaint_getAlpha(paint)
end

function Skia.Paint.setAlphaf(paint, a)
    lib.SkPaint_setAlphaf(paint, a)
end

function Skia.Paint.setAlpha(paint, a)
    lib.SkPaint_setAlpha(paint, a)
end

function Skia.Paint.setARGB(paint, a, r, g, b)
    lib.SkPaint_setARGB(paint, a, r, g, b)
end

function Skia.Paint.getStrokeWidth(paint)
    return lib.SkPaint_getStrokeWidth(paint)
end

function Skia.Paint.setStrokeWidth(paint, width)
    lib.SkPaint_setStrokeWidth(paint, width)
end

function Skia.Paint.getStrokeMiter(paint)
    return lib.SkPaint_getStrokeMiter(paint)
end

function Skia.Paint.setStrokeMiter(paint, miter)
    lib.SkPaint_setStrokeMiter(paint, miter)
end

function Skia.Paint.getStrokeCap(paint)
    return lib.SkPaint_getStrokeCap(paint)
end

function Skia.Paint.setStrokeCap(paint, cap)
    lib.SkPaint_setStrokeCap(paint, cap)
end

function Skia.Paint.getStrokeJoin(paint)
    return lib.SkPaint_getStrokeJoin(paint)
end

function Skia.Paint.setStrokeJoin(paint, join)
    lib.SkPaint_setStrokeJoin(paint, join)
end

function Skia.Paint.getShader(paint)
    return lib.SkPaint_getShader(paint)
end

function Skia.Paint.refShader(paint)
    local obj = lib.SkPaint_refShader(paint)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Paint.setShader(paint, shader)
    lib.SkPaint_setShader(paint, shader)
end

function Skia.Paint.getColorFilter(paint)
    return lib.SkPaint_getColorFilter(paint)
end

function Skia.Paint.refColorFilter(paint)
    local obj = lib.SkPaint_refColorFilter(paint)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.Paint.setColorFilter(paint, color_filter)
    lib.SkPaint_setColorFilter(paint, color_filter)
end

function Skia.Paint.asBlendMode(paint)
    return lib.SkPaint_asBlendMode(paint)
end

function Skia.Paint.getBlendMode_or(paint, defaultMode)
    return lib.SkPaint_getBlendMode_or(paint, defaultMode)
end

function Skia.Paint.isSrcOver(paint)
    return lib.SkPaint_isSrcOver(paint)
end

function Skia.Paint.setBlendMode(paint, mode)
    lib.SkPaint_setBlendMode(paint, mode)
end

function Skia.Paint.getBlender(paint)
    return lib. SkPaint_getBlender(paint)
end

function Skia.Paint.refBlender(paint)
    local obj = lib.SkPaint_refBlender(paint)
    setFinalizer(obj, lib.static_sk_blender_delete)
    return obj
end

function Skia.Paint.setBlender(paint, blender)
    lib.SkPaint_setBlender(paint, blender)
end

function Skia.Paint.getPathEffect(paint)
    return lib. SkPaint_getPathEffect(paint)
end

function Skia.Paint.refPathEffect(paint)
    local obj = lib.SkPaint_refPathEffect(paint)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.Paint.setPathEffect(paint, path_effect)
    lib.SkPaint_setPathEffect(paint, path_effect)
end

function Skia.Paint.getMaskFilter(paint)
    return lib. SkPaint_getMaskFilter(paint)
end

function Skia.Paint.refMaskFilter(paint)
    local obj = lib.SkPaint_refMaskFilter(paint)
    setFinalizer(obj, lib.static_sk_mask_filter_delete)
    return obj
end

function Skia.Paint.setMaskFilter(paint, mask_filter)
    lib.SkPaint_setMaskFilter(paint, mask_filter)
end

function Skia.Paint.getImageFilter(paint)
    return lib. SkPaint_getImageFilter(paint)
end

function Skia.Paint.refImageFilter(paint)
    local obj = lib.SkPaint_refImageFilter(paint)
    setFinalizer(obj, lib.static_sk_image_filter_delete)
    return obj
end

function Skia.Paint.setImageFilter(paint, image_filter)
    lib.SkPaint_setImageFilter(paint, image_filter)
end

function Skia.Paint.nothingToDraw(paint)
    return lib.SkPaint_nothingToDraw(paint)
end

function Skia.Paint.canComputeFastBounds(paint)
    return lib.SkPaint_canComputeFastBounds(paint)
end

function Skia.Paint.computeFastBounds(paint, orig, storage)
    return lib. SkPaint_computeFastBounds(paint, orig, storage)
end

function Skia.Paint.computeFastStrokeBounds(paint, orig, storage)
    return lib. SkPaint_computeFastStrokeBounds(paint, orig, storage)
end

function Skia.Paint.doComputeFastBounds(paint, orig, storage, style)
    return lib. SkPaint_doComputeFastBounds(paint, orig, storage, style)
end

-- ## sk_path
Skia.Path = {}

function Skia.Path.new()
    local obj = lib.SkPath_new()
    ffi.gc(obj, lib.SkPath_delete)
    return obj
end

function Skia.Path.new_2(path)
    local obj = lib.SkPath_new_2(path)
    ffi.gc(obj, lib.SkPath_delete)
    return obj
end

function Skia.Path.delete(path)
    lib.SkPath_delete(path)
end

function Skia.Path.isInterpolatable(path, compare)
    return lib.SkPath_isInterpolatable(path, compare)
end

function Skia.Path.interpolate(path, ending, weight, out)
    return lib.SkPath_interpolate(path, ending, weight, out)
end

function Skia.Path.getFillType(path)
    return lib.SkPath_getFillType(path)
end

function Skia.Path.setFillType(path, ft)
    lib.SkPath_setFillType(path, ft)
end

function Skia.Path.isInverseFillType(path)
    return lib.SkPath_isInverseFillType(path)
end

function Skia.Path.toggleInverseFillType(path)
    lib.SkPath_toggleInverseFillType(path)
end

function Skia.Path.isConvex(path)
    return lib.SkPath_isConvex(path)
end

function Skia.Path.isOval(path, bounds)
    return lib.SkPath_isOval(path, bounds)
end

function Skia.Path.isRRect(path, rrect)
    return lib.SkPath_isRRect(path, rrect)
end

function Skia.Path.reset(path)
    return lib.SkPath_reset(path)
end

function Skia.Path.rewind(path)
    return lib.SkPath_rewind(path)
end

function Skia.Path.isEmpty(path)
    return lib.SkPath_isEmpty(path)
end

function Skia.Path.isLastContourClosed(path)
    return lib.SkPath_isLastContourClosed(path)
end

function Skia.Path.isFinite(path)
    return lib.SkPath_isFinite(path)
end

function Skia.Path.isVolatile(path)
    return lib.SkPath_isVolatile(path)
end

function Skia.Path.setIsVolatile(path, isVolatile)
    return lib.SkPath_setIsVolatile(path, isVolatile)
end

function Skia.Path.isLine(path, line)
    return lib.SkPath_isLine(path, line)
end

function Skia.Path.countPoints(path)
    return lib.SkPath_countPoints(path)
end

function Skia.Path.getPoint(path, index)
    local obj = lib.SkPath_getPoint(path, index)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Path.getPoints(path, points, max)
    return lib.SkPath_getPoints(path, points, max)
end

function Skia.Path.countVerbs(path)
    return lib.SkPath_countVerbs(path)
end

function Skia.Path.getVerbs(path, verbs, max)
    return lib.SkPath_getVerbs(path, verbs, max)
end

function Skia.Path.approximateBytesUsed(path)
    return lib.SkPath_approximateBytesUsed(path)
end

function Skia.Path.swap(path, other)
    lib.SkPath_swap(path, other)
end

function Skia.Path.getBounds(path)
    return lib.SkPath_getBounds(path)
end

function Skia.Path.updateBoundsCache(path)
    lib.SkPath_updateBoundsCache(path)
end

function Skia.Path.computeTightBounds(path)
    local obj = lib.SkPath_computeTightBounds(path)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Path.conservativelyContainsRect(path, rect)
    return lib.SkPath_conservativelyContainsRect(path, rect)
end

function Skia.Path.incReserve(path, extraPtCount)
    lib.SkPath_incReserve(path, extraPtCount)
end

function Skia.Path.moveTo(path, x, y)
    return lib.SkPath_moveTo(path, x, y)
end

function Skia.Path.moveTo_2(path, p)
    return lib.SkPath_moveTo_2(path, p)
end

function Skia.Path.rMoveTo(path, dx, dy)
    return lib.SkPath_rMoveTo(path, dx, dy)
end

function Skia.Path.lineTo(path, x, y)
    return lib.SkPath_lineTo(path, x, y)
end

function Skia.Path.lineTo_2(path, p)
    return lib.SkPath_lineTo_2(path, p)
end

function Skia.Path.rLineTo(path, dx, dy)
    return lib.SkPath_rLineTo(path, dx, dy)
end

function Skia.Path.quadTo(path, x1, y1, x2, y2)
    return lib.SkPath_quadTo(path, x1, y1, x2, y2)
end

function Skia.Path.quadTo_2(path, p1, p2)
    return lib.SkPath_quadTo_2(path, p1, p2)
end

function Skia.Path.rQuadTo(path, dx1, dy1, dx2, dy2)
    return lib.SkPath_rQuadTo(path, dx1, dy1, dx2, dy2)
end

function Skia.Path.conicTo(path, x1, y1, x2, y2, w)
    return lib.SkPath_conicTo(path, x1, y1, x2, y2, w)
end

function Skia.Path.conicTo_2(path, p1, p2, w)
    return lib.SkPath_conicTo_2(path, p1, p2, w)
end

function Skia.Path.rConicTo(path, dx1, dy1, dx2, dy2, w)
    return lib.SkPath_rConicTo(path, dx1, dy1, dx2, dy2, w)
end

function Skia.Path.cubicTo(path, x1, y1, x2, y2, x3, y3)
    return lib.SkPath_cubicTo(path, x1, y1, x2, y2, x3, y3)
end

function Skia.Path.cubicTo_2(path, p1, p2, p3)
    return lib.SkPath_cubicTo_2(path, p1, p2, p3)
end

function Skia.Path.rCubicTo(path, dx1, dy1, dx2, dy2, dx3, dy3)
    return lib.SkPath_rCubicTo(path, dx1, dy1, dx2, dy2, dx3, dy3)
end

function Skia.Path.arcTo(path, oval, startAngle, sweepAngle, forceMoveTo)
    return lib.SkPath_arcTo(path, oval, startAngle, sweepAngle, forceMoveTo)
end

function Skia.Path.arcTo_2(path, x1, y1, x2, y2, radius)
    return lib.SkPath_arcTo_2(path, x1, y1, x2, y2, radius)
end

function Skia.Path.arcTo_3(path, p1, p2, radius)
    return lib.SkPath_arcTo_3(path, p1, p2, radius)
end

function Skia.Path.arcTo_4(path, rx, ry, xAxisRotate, largeArc, sweep, x, y)
    return lib.SkPath_arcTo_4(path, rx, ry, xAxisRotate, largeArc, sweep, x, y)
end

function Skia.Path.arcTo_5(path, r, xAxisRotate, largeArc, sweep, xy)
    return lib.SkPath_arcTo_5(path, r, xAxisRotate, largeArc, sweep, xy)
end

function Skia.Path.rArcTo(path, rx, ry, xAxisRotate, largeArc, sweep, dx, dy)
    return lib.SkPath_rArcTo(path, rx, ry, xAxisRotate, largeArc, sweep, dx, dy)
end

function Skia.Path.close(path)
    return lib.SkPath_close(path)
end

function Skia.Path.isRect(path, rect, isClosed, direction)
    return lib.SkPath_isRect(path, rect, isClosed, direction)
end

function Skia.Path.addRect(path, rect, dir, start)
    return lib.SkPath_addRect(path, rect, dir, start)
end

function Skia.Path.addRect_2(path, rect, dir)
    return lib.SkPath_addRect_2(path, rect, dir)
end

function Skia.Path.addRect_3(path, left, top, right, bottom, dir)
    return lib.SkPath_addRect_3(path, left, top, right, bottom, dir)
end

function Skia.Path.addOval(path, oval, dir)
    return lib.SkPath_addOval(path, oval, dir)
end

function Skia.Path.addOval_2(path, oval, dir, start)
    return lib.SkPath_addOval_2(path, oval, dir, start)
end

function Skia.Path.addCircle(path, x, y, radius, dir)
    return lib.SkPath_addCircle(path, x, y, radius, dir)
end

function Skia.Path.addArc(path, oval, startAngle, sweepAngle)
    return lib.SkPath_addArc(path, oval, startAngle, sweepAngle)
end

function Skia.Path.addRoundRect(path, rect, rx, ry, dir)
    return lib.SkPath_addRoundRect(path, rect, rx, ry, dir)
end

function Skia.Path.addRoundRect_2(path, rect, radii, dir)
    return lib.SkPath_addRoundRect_2(path, rect, radii, dir)
end

function Skia.Path.addRRect(path, rrect, dir)
    return lib.SkPath_addRRect(path, rrect, dir)
end

function Skia.Path.addRRect_2(path, rrect, dir, start)
    return lib.SkPath_addRRect_2(path, rrect, dir, start)
end

function Skia.Path.addPoly(path, pts, count, close)
    return lib.SkPath_addPoly(path, pts, count, close)
end

function Skia.Path.addPoly_2(path, list, close)
    return lib.SkPath_addPoly_2(path, list, close)
end

function Skia.Path.addPath(path, src, dx, dy, mode)
    return lib.SkPath_addPath(path, src, dx, dy, mode)
end

function Skia.Path.addPath_2(path, src, modeSkPath)
    return lib.SkPath_addPath_2(path, src, modeSkPath)
end

function Skia.Path.addPath_3(path, src, matrix, mode)
    return lib.SkPath_addPath_3(path, src, matrix, mode)
end

function Skia.Path.reverseAddPath(path, src)
    return lib.SkPath_reverseAddPath(path, src)
end

function Skia.Path.offset(path, dx, dy, dst)
    lib.SkPath_offset(path, dx, dy, dst)
end

function Skia.Path.offset_2(path, dx, dy)
    lib.SkPath_offset_2(path, dx, dy)
end

function Skia.Path.transform(path, matrix, dst, pc)
    lib.SkPath_transform(path, matrix, dst, pc)
end

function Skia.Path.transform_2(path, matrix, pc)
    lib.SkPath_transform_2(path, matrix, pc)
end

function Skia.Path.makeTransform(path, m, pc)
    local obj = lib.SkPath_makeTransform(path, m, pc)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.makeScale(path, sx, sy)
    local obj = lib.SkPath_makeScale(path, sx, sy)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.getLastPt(path, lastPt)
    return lib.SkPath_getLastPt(path, lastPt)
end

function Skia.Path.setLastPt(path, x, y)
    lib.SkPath_setLastPt(path, x, y)
end

function Skia.Path.setLastPt_2(path, p)
    lib.SkPath_setLastPt_2(path, p)
end

function Skia.Path.getSegmentMasks(path)
    return lib.SkPath_getSegmentMasks(path)
end

function Skia.Path.contains(path, x, y)
    return lib.SkPath_contains(path, x, y)
end

function Skia.Path.dump(path, stream, dumpAsHex)
    lib.SkPath_dump(path, stream, dumpAsHex)
end

function Skia.Path.dump_2(path)
    lib.SkPath_dump_2(path)
end

function Skia.Path.dumpHex(path)
    lib.SkPath_dumpHex(path)
end

function Skia.Path.dumpArrays(path, stream, dumpAsHex)
    lib.SkPath_dumpArrays(path, stream, dumpAsHex)
end

function Skia.Path.dumpArrays_2(path)
    lib.SkPath_dumpArrays_2(path)
end

function Skia.Path.writeToMemory(path, buffer)
    return lib.SkPath_writeToMemory(path, buffer)
end

function Skia.Path.serialize(path)
    local obj = lib.SkPath_serialize(path)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Path.readFromMemory(path, buffer, length)
    return lib.SkPath_readFromMemory(path, buffer, length)
end

function Skia.Path.getGenerationID(path)
    return lib.SkPath_getGenerationID(path)
end

function Skia.Path.isValid(path)
    return lib.SkPath_isValid(path)
end

function Skia.Path.Make(point, pointCount, i, verbCount, v, conicWeightCount, type, isVolatile)
    local obj = lib.SkPath_Make(point, pointCount, i, verbCount, v, conicWeightCount, type, isVolatile)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Rect(rect, dir, startIndex)
    local obj = lib.SkPath_Rect(rect, dir, startIndex)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Oval(rect, dir)
    local obj = lib.SkPath_Oval(rect, dir)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Oval_2(rect, dir, startIndex)
    local obj = lib.SkPath_Oval_2(rect, dir, startIndex)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Circle(center_x, center_y, radius, dir)
    local obj = lib.SkPath_Circle(center_x, center_y, radius, dir)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.RRect(rrect, dir)
    local obj = lib.SkPath_RRect(rrect, dir)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.RRect_2(rrect, dir, startIndex)
    local obj = lib.SkPath_RRect_2(rrect, dir, startIndex)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.RRect_3(bounds, rx, ry, dir)
    local obj = lib.SkPath_RRect_3(bounds, rx, ry, dir)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Polygon(pts, count, isClosed, type, isVolatile)
    local obj = lib.SkPath_Polygon(pts, count, isClosed, type, isVolatile)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Polygon_2(list, isClosed, fillType, isVolatile)
    local obj = lib.SkPath_Polygon_2(list, isClosed, fillType, isVolatile)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.Line(a, b)
    local obj = lib.SkPath_Line(a, b)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.Path.IsLineDegenerate(p1, p2, exact)
    return lib.SkPath_IsLineDegenerate(p1, p2, exact)
end

function Skia.Path.IsQuadDegenerate(p1, p2, p3, exact)
    return lib.SkPath_IsQuadDegenerate(p1, p2, p3, exact)
end

function Skia.Path.IsCubicDegenerate(p1, p2, p3, p4, exact)
    return lib.SkPath_IsCubicDegenerate(p1, p2, p3, p4, exact)
end

function Skia.Path.ConvertConicToQuads(p0, p1, p2, w, pts, pow2)
    return lib.SkPath_ConvertConicToQuads(p0, p1, p2, w, pts, pow2)
end

-- ## sk_path_1d_path_effect
Skia.Path1DPathEffect = {}

function Skia.Path1DPathEffect.delete(path1DPathEffect)
    lib.SkPath1DPathEffect_delete(path1DPathEffect)
end

function Skia.Path1DPathEffect.Make(path, advance, phase, style)
    local obj = lib.SkPath1DPathEffect_Make(path, advance, phase, style)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.Path1DPathEffect.RegisterFlattenables()
    lib.SkPath1DPathEffect_RegisterFlattenables()
end

-- ## sk_path_2d_path_effect
Skia.Path2DPathEffect = {}

function Skia.Path2DPathEffect.delete(path2DPathEffect)
    lib.SkPath2DPathEffect_delete(path2DPathEffect)
end

function Skia.Path2DPathEffect.Make(matrix, path)
    local obj = lib.SkPath2DPathEffect_Make(matrix, path)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.Path2DPathEffect.RegisterFlattenables()
    lib.SkPath2DPathEffect_RegisterFlattenables()
end

-- ## sk_path_builder
Skia.PathBuilder = {}

function Skia.PathBuilder.new()
    local obj = lib.SkPathBuilder_new()
    ffi.gc(obj, lib.SkPathBuilder_delete)
    return obj
end

function Skia.PathBuilder.new_2(type)
    local obj = lib.SkPathBuilder_new_2(type)
    ffi.gc(obj, lib.SkPathBuilder_delete)
    return obj
end

function Skia.PathBuilder.new_3(path)
    local obj = lib.SkPathBuilder_new_3(path)
    ffi.gc(obj, lib.SkPathBuilder_delete)
    return obj
end

function Skia.PathBuilder.new_4(builder)
    local obj = lib.SkPathBuilder_new_4(builder)
    ffi.gc(obj, lib.SkPathBuilder_delete)
    return obj
end

function Skia.PathBuilder.delete(path_builder)
    lib.SkPathBuilder_delete(path_builder)
end

function Skia.PathBuilder.fillType(path_builder)
    return lib.SkPathBuilder_fillType(path_builder)
end

function Skia.PathBuilder.computeBounds(path_builder)
    local obj = lib.SkPathBuilder_computeBounds(path_builder)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.PathBuilder.snapshot(path_builder)
    local obj = lib.SkPathBuilder_snapshot(path_builder)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.PathBuilder.detach(path_builder)
    local obj = lib.SkPathBuilder_detach(path_builder)
    setFinalizer(obj, lib.static_sk_path_delete)
    return obj
end

function Skia.PathBuilder.setFillType(path_builder, ft)
    return lib. SkPathBuilder_setFillType(path_builder, ft)
end

function Skia.PathBuilder.setIsVolatile(path_builder, isVolatile)
    return lib. SkPathBuilder_setIsVolatile(path_builder, isVolatile)
end

function Skia.PathBuilder.reset(path_builder)
    return lib. SkPathBuilder_reset(path_builder)
end

function Skia.PathBuilder.moveTo(path_builder, pt)
    return lib. SkPathBuilder_moveTo(path_builder, pt)
end

function Skia.PathBuilder.moveTo_2(path_builder, x, y)
    return lib. SkPathBuilder_moveTo_2(path_builder, x, y)
end

function Skia.PathBuilder.lineTo(path_builder, pt)
    return lib. SkPathBuilder_lineTo(path_builder, pt)
end

function Skia.PathBuilder.lineTo_2(path_builder, x, y)
    return lib. SkPathBuilder_lineTo_2(path_builder, x, y)
end

function Skia.PathBuilder.quadTo(path_builder, pt1, pt2)
    return lib. SkPathBuilder_quadTo(path_builder, pt1, pt2)
end

function Skia.PathBuilder.quadTo_2(path_builder, x1, y1, x2, y2)
    return lib. SkPathBuilder_quadTo_2(path_builder, x1, y1, x2, y2)
end

function Skia.PathBuilder.quadTo_3(path_builder, pts)
    return lib. SkPathBuilder_quadTo_3(path_builder, pts)
end

function Skia.PathBuilder.conicTo(path_builder, pt1, pt2, w)
    return lib. SkPathBuilder_conicTo(path_builder, pt1, pt2, w)
end

function Skia.PathBuilder.conicTo_2(path_builder, x1, y1, x2, y2, w)
    return lib. SkPathBuilder_conicTo_2(path_builder, x1, y1, x2, y2, w)
end

function Skia.PathBuilder.conicTo_3(path_builder, pts, w)
    return lib. SkPathBuilder_conicTo_3(path_builder, pts, w)
end

function Skia.PathBuilder.cubicTo(path_builder, pt1, pt2, pt3)
    return lib. SkPathBuilder_cubicTo(path_builder, pt1, pt2, pt3)
end

function Skia.PathBuilder.cubicTo_2(path_builder, x1, y1, x2, y2, x3, y3)
    return lib. SkPathBuilder_cubicTo_2(path_builder, x1, y1, x2, y2, x3, y3)
end

function Skia.PathBuilder.cubicTo_3(path_builder, pts)
    return lib. SkPathBuilder_cubicTo_3(path_builder, pts)
end

function Skia.PathBuilder.close(path_builder)
    return lib. SkPathBuilder_close(path_builder)
end

function Skia.PathBuilder.polylineTo(path_builder, pts, count)
    return lib. SkPathBuilder_polylineTo(path_builder, pts, count)
end

function Skia.PathBuilder.polylineTo_2(path_builder, list)
    return lib. SkPathBuilder_polylineTo_2(path_builder, list)
end

function Skia.PathBuilder.rLineTo(path_builder, pt)
    return lib. SkPathBuilder_rLineTo(path_builder, pt)
end

function Skia.PathBuilder.rLineTo_2(path_builder, x, y)
    return lib. SkPathBuilder_rLineTo_2(path_builder, x, y)
end

function Skia.PathBuilder.rQuadTo(path_builder, pt1, pt2)
    return lib. SkPathBuilder_rQuadTo(path_builder, pt1, pt2)
end

function Skia.PathBuilder.rQuadTo_2(path_builder, x1, y1, x2, y2)
    return lib. SkPathBuilder_rQuadTo_2(path_builder, x1, y1, x2, y2)
end

function Skia.PathBuilder.rConicTo(path_builder, p1, p2, w)
    return lib. SkPathBuilder_rConicTo(path_builder, p1, p2, w)
end

function Skia.PathBuilder.rConicTo_2(path_builder, x1, y1, x2, y2, w)
    return lib. SkPathBuilder_rConicTo_2(path_builder, x1, y1, x2, y2, w)
end

function Skia.PathBuilder.rCubicTo(path_builder, pt1, pt2, pt3)
    return lib. SkPathBuilder_rCubicTo(path_builder, pt1, pt2, pt3)
end

function Skia.PathBuilder.rCubicTo_2(path_builder, x1, y1, x2, y2, x3, y3)
    return lib. SkPathBuilder_rCubicTo_2(path_builder, x1, y1, x2, y2, x3, y3)
end

function Skia.PathBuilder.arcTo(path_builder, oval, startAngleDeg, sweepAngleDeg, forceMoveTo)
    return lib. SkPathBuilder_arcTo(path_builder, oval, startAngleDeg, sweepAngleDeg, forceMoveTo)
end

function Skia.PathBuilder.arcTo_2(path_builder, p1, p2, radius)
    return lib. SkPathBuilder_arcTo_2(path_builder, p1, p2, radius)
end

function Skia.PathBuilder.arcTo_3(path_builder, r, xAxisRotate, largeArc, sweep, xy)
    return lib. SkPathBuilder_arcTo_3(path_builder, r, xAxisRotate, largeArc, sweep, xy)
end

function Skia.PathBuilder.addArc(path_builder, oval, startAngleDeg, sweepAngleDeg)
    return lib. SkPathBuilder_addArc(path_builder, oval, startAngleDeg, sweepAngleDeg)
end

function Skia.PathBuilder.addRect(path_builder, rect, dir, startIndex)
    return lib. SkPathBuilder_addRect(path_builder, rect, dir, startIndex)
end

function Skia.PathBuilder.addRect_2(path_builder, rect, dir)
    return lib. SkPathBuilder_addRect_2(path_builder, rect, dir)
end

function Skia.PathBuilder.addOval(path_builder, rect, dir, startIndex)
    return lib. SkPathBuilder_addOval(path_builder, rect, dir, startIndex)
end

function Skia.PathBuilder.addOval_2(path_builder, rect, dir)
    return lib. SkPathBuilder_addOval_2(path_builder, rect, dir)
end

function Skia.PathBuilder.addRRect(path_builder, rect, dir, startIndex)
    return lib. SkPathBuilder_addRRect(path_builder, rect, dir, startIndex)
end

function Skia.PathBuilder.addRRect_2(path_builder, rrect, dir)
    return lib. SkPathBuilder_addRRect_2(path_builder, rrect, dir)
end

function Skia.PathBuilder.addCircle(path_builder, center_x, center_y, radius, dir)
    return lib. SkPathBuilder_addCircle(path_builder, center_x, center_y, radius, dir)
end

function Skia.PathBuilder.addPolygon(path_builder, pts, count, isClosed)
    return lib. SkPathBuilder_addPolygon(path_builder, pts, count, isClosed)
end

function Skia.PathBuilder.addPolygon_2(path_builder, list, isClosed)
    return lib. SkPathBuilder_addPolygon_2(path_builder, list, isClosed)
end

function Skia.PathBuilder.addPath(path_builder, path)
    return lib. SkPathBuilder_addPath(path_builder, path)
end

function Skia.PathBuilder.incReserve(path_builder, extraPtCount, extraVerbCount)
    lib.SkPathBuilder_incReserve(path_builder, extraPtCount, extraVerbCount)
end

function Skia.PathBuilder.incReserve_2(path_builder, extraPtCount)
    lib.SkPathBuilder_incReserve_2(path_builder, extraPtCount)
end

function Skia.PathBuilder.offset(path_builder, dx, dy)
    return lib. SkPathBuilder_offset(path_builder, dx, dy)
end

function Skia.PathBuilder.toggleInverseFillType(path_builder)
    return lib. SkPathBuilder_toggleInverseFillType(path_builder)
end

-- ## sk_path_effect
Skia.PathEffect = {}

function Skia.PathEffect.delete(pathEffect)
    lib.SkPathEffect_delete(pathEffect)
end

function Skia.PathEffect.asADash(path_effect, info)
    return lib.SkPathEffect_asADash(path_effect, info)
end

function Skia.PathEffect.filterPath(path_effect, dst, src, rec, cullR)
    return lib.SkPathEffect_filterPath(path_effect, dst, src, rec, cullR)
end

function Skia.PathEffect.filterPath_2(path_effect, dst, src, rec, cullR, ctm)
    return lib.SkPathEffect_filterPath_2(path_effect, dst, src, rec, cullR, ctm)
end

function Skia.PathEffect.needsCTM(path_effect)
    return lib.SkPathEffect_needsCTM(path_effect)
end

function Skia.PathEffect.getFactory(path_effect)
    local obj = lib.SkPathEffect_getFactory(path_effect)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.PathEffect.getTypeName(path_effect)
    return lib. SkPathEffect_getTypeName(path_effect)
end

function Skia.PathEffect.flatten(path_effect, buffer)
    lib.SkPathEffect_flatten(path_effect, buffer)
end

function Skia.PathEffect.getFlattenableType(path_effect)
    return lib.SkPathEffect_getFlattenableType(path_effect)
end

function Skia.PathEffect.serialize(path_effect, procs)
    local obj = lib.SkPathEffect_serialize(path_effect, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.PathEffect.serialize_2(path_effect, memory, memory_size, procs)
    return lib.SkPathEffect_serialize_2(path_effect, memory, memory_size, procs)
end

function Skia.PathEffect.unique(path_effect)
    return lib.SkPathEffect_unique(path_effect)
end

function Skia.PathEffect.ref(path_effect)
    lib.SkPathEffect_ref(path_effect)
end

function Skia.PathEffect.unref(path_effect)
    lib.SkPathEffect_unref(path_effect)
end

function Skia.PathEffect.MakeSum(first, second)
    local obj = lib.SkPathEffect_MakeSum(first, second)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.PathEffect.MakeCompose(outer, inner)
    local obj = lib.SkPathEffect_MakeCompose(outer, inner)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.PathEffect.GetFlattenableType()
    return lib.SkPathEffect_GetFlattenableType()
end

function Skia.PathEffect.Deserialize(data, size, procs)
    local obj = lib.SkPathEffect_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

function Skia.PathEffect.NameToFactory(name)
    local obj = lib.SkPathEffect_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.PathEffect.FactoryToName(factory)
    return lib. SkPathEffect_FactoryToName(factory)
end

function Skia.PathEffect.Register(name, factory)
    lib.SkPathEffect_Register(name, factory)
end

-- ## sk_path_measure
Skia.PathMeasure = {}

function Skia.PathMeasure.new()
    local obj = lib.SkPathMeasure_new()
    ffi.gc(obj, lib.SkPathMeasure_delete)
    return obj
end

function Skia.PathMeasure.new_2(path, forceClosed, resScale)
    local obj = lib.SkPathMeasure_new_2(path, forceClosed, resScale)
    ffi.gc(obj, lib.SkPathMeasure_delete)
    return obj
end

function Skia.PathMeasure.delete(path_measure)
    lib.SkPathMeasure_delete(path_measure)
end

function Skia.PathMeasure.setPath(path_measure, path, forceClosed)
    lib.SkPathMeasure_setPath(path_measure, path, forceClosed)
end

function Skia.PathMeasure.getLength(path_measure)
    return lib.SkPathMeasure_getLength(path_measure)
end

function Skia.PathMeasure.getPosTan(path_measure, distance, position, tangent)
    return lib.SkPathMeasure_getPosTan(path_measure, distance, position, tangent)
end

function Skia.PathMeasure.getMatrix(path_measure, distance, matrix, flags)
    return lib.SkPathMeasure_getMatrix(path_measure, distance, matrix, flags)
end

function Skia.PathMeasure.getSegment(path_measure, startD, stopD, dst, startWithMoveTo)
    return lib.SkPathMeasure_getSegment(path_measure, startD, stopD, dst, startWithMoveTo)
end

function Skia.PathMeasure.isClosed(path_measure)
    return lib.SkPathMeasure_isClosed(path_measure)
end

function Skia.PathMeasure.nextContour(path_measure)
    return lib.SkPathMeasure_nextContour(path_measure)
end

--[[
-- ## sk_pdf
Skia.PDF = {}

function Skia.PDF.SetNodeId(dst, nodeID)
    lib.SkPDF_SetNodeId(dst, nodeID)
end

function Skia.PDF.MakeDocument(stream, metadata)
    local obj = lib.SkPDF_MakeDocument(stream, metadata)
    setFinalizer(obj, lib.static_sk_document_delete)
    return obj
end

function Skia.PDF.MakeDocument_2(stream)
    local obj = lib.SkPDF_MakeDocument_2(stream)
    setFinalizer(obj, lib.static_sk_document_delete)
    return obj
end
]]

-- ## sk_perlin_noise_shader
Skia.PerlinNoiseShader = {}

function Skia.PerlinNoiseShader.MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    local obj = lib.SkPerlinNoiseShader_MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.PerlinNoiseShader.MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    local obj = lib.SkPerlinNoiseShader_MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

-- ## sk_picture
Skia.Picture = {}

function Skia.Picture.delete(picture)
    lib.SkPicture_delete(picture)
end

function Skia.Picture.playback(picture, canvas, callback)
    lib.SkPicture_playback(picture, canvas, callback)
end

function Skia.Picture.cullRect(picture)
    local obj = lib.SkPicture_cullRect(picture)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Picture.uniqueID(picture)
    return lib.SkPicture_uniqueID(picture)
end

function Skia.Picture.serialize(picture, procs)
    local obj = lib.SkPicture_serialize(picture, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Picture.serialize_2(picture, stream, procs)
    lib.SkPicture_serialize_2(picture, stream, procs)
end

function Skia.Picture.approximateOpCount(picture)
    return lib.SkPicture_approximateOpCount(picture)
end

function Skia.Picture.approximateBytesUsed(picture)
    return lib.SkPicture_approximateBytesUsed(picture)
end

function Skia.Picture.makeShader(picture, tmx, tmy, mode, localMatrix, tileRect)
    local obj = lib.SkPicture_makeShader(picture, tmx, tmy, mode, localMatrix, tileRect)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Picture.makeShader_2(picture, tmx, tmy, mode)
    local obj = lib.SkPicture_makeShader_2(picture, tmx, tmy, mode)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Picture.unique(picture)
    return lib.SkPicture_unique(picture)
end

function Skia.Picture.ref(picture)
    lib.SkPicture_ref(picture)
end

function Skia.Picture.unref(picture)
    lib.SkPicture_unref(picture)
end

function Skia.Picture.MakeFromStream(stream, procs)
    local obj = lib.SkPicture_MakeFromStream(stream, procs)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.Picture.MakeFromData(data, procs)
    local obj = lib.SkPicture_MakeFromData(data, procs)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.Picture.MakeFromData_2(data, size, procs)
    local obj = lib.SkPicture_MakeFromData_2(data, size, procs)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.Picture.MakePlaceholder(cull)
    local obj = lib.SkPicture_MakePlaceholder(cull)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

-- ## sk_picture_recorder
Skia.PictureRecorder = {}

function Skia.PictureRecorder.new()
    local obj = lib.SkPictureRecorder_new()
    ffi.gc(obj, lib.SkPictureRecorder_delete)
    return obj
end

function Skia.PictureRecorder.delete(picture_recorder)
    lib.SkPictureRecorder_delete(picture_recorder)
end

function Skia.PictureRecorder.beginRecording(picture_recorder, bounds, b_box_hierarchy)
    return lib.SkPictureRecorder_beginRecording(picture_recorder, bounds, b_box_hierarchy)
end

function Skia.PictureRecorder.beginRecording_2(picture_recorder, bounds, bbhFactory)
    return lib.SkPictureRecorder_beginRecording_2(picture_recorder, bounds, bbhFactory)
end

function Skia.PictureRecorder.beginRecording_3(picture_recorder, width, height, bbhFactory)
    return lib.SkPictureRecorder_beginRecording_3(picture_recorder, width, height, bbhFactory)
end

function Skia.PictureRecorder.getRecordingCanvas(picture_recorder)
    return lib.SkPictureRecorder_getRecordingCanvas(picture_recorder)
end

function Skia.PictureRecorder.finishRecordingAsPicture(picture_recorder)
    local obj = lib.SkPictureRecorder_finishRecordingAsPicture(picture_recorder)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.PictureRecorder.finishRecordingAsPictureWithCull(picture_recorder, cullRect)
    local obj = lib.SkPictureRecorder_finishRecordingAsPictureWithCull(picture_recorder, cullRect)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

function Skia.PictureRecorder.finishRecordingAsDrawable(picture_recorder)
    local obj = lib.SkPictureRecorder_finishRecordingAsDrawable(picture_recorder)
    setFinalizer(obj, lib.static_sk_picture_delete)
    return obj
end

-- ## sk_pixel_ref
Skia.PixelRef = {}

function Skia.PixelRef.new(width, height, addr, rowBytes)
    return lib.SkPixelRef_new(width, height, addr, rowBytes)
end

function Skia.PixelRef.delete(pixel_ref)
    lib.SkPixelRef_delete(pixel_ref)
end

function Skia.PixelRef.dimensions(pixel_ref)
    local obj = lib.SkPixelRef_dimensions(pixel_ref)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.PixelRef.width(pixel_ref)
    return lib.SkPixelRef_width(pixel_ref)
end

function Skia.PixelRef.height(pixel_ref)
    return lib.SkPixelRef_height(pixel_ref)
end

function Skia.PixelRef.pixels(pixel_ref)
    return lib.SkPixelRef_pixels(pixel_ref)
end

function Skia.PixelRef.rowBytes(pixel_ref)
    return lib.SkPixelRef_rowBytes(pixel_ref)
end

function Skia.PixelRef.getGenerationID(pixel_ref)
    return lib.SkPixelRef_getGenerationID(pixel_ref)
end

function Skia.PixelRef.notifyPixelsChanged(pixel_ref)
    lib.SkPixelRef_notifyPixelsChanged(pixel_ref)
end

function Skia.PixelRef.isImmutable(pixel_ref)
    return lib.SkPixelRef_isImmutable(pixel_ref)
end

function Skia.PixelRef.setImmutable(pixel_ref)
    lib.SkPixelRef_setImmutable(pixel_ref)
end

function Skia.PixelRef.addGenIDChangeListener(pixel_ref, id_change_listener)
    lib.SkPixelRef_addGenIDChangeListener(pixel_ref, id_change_listener)
end

function Skia.PixelRef.notifyAddedToCache(pixel_ref)
    lib.SkPixelRef_notifyAddedToCache(pixel_ref)
end

function Skia.PixelRef.diagnostic_only_getDiscardable(pixel_ref)
    return lib.SkPixelRef_diagnostic_only_getDiscardable(pixel_ref)
end

function Skia.PixelRef.unique(pixel_ref)
    return lib.SkPixelRef_unique(pixel_ref)
end

function Skia.PixelRef.ref(pixel_ref)
    lib.SkPixelRef_ref(pixel_ref)
end

function Skia.PixelRef.unref(pixel_ref)
    lib.SkPixelRef_unref(pixel_ref)
end

-- ## sk_pixmap
Skia.Pixmap = {}

function Skia.Pixmap.new()
    local obj = lib.SkPixmap_new()
    ffi.gc(obj, lib.SkPixmap_delete)
    return obj
end

function Skia.Pixmap.new_2(info, addr, rowBytes)
    local obj = lib.SkPixmap_new_2(info, addr, rowBytes)
    ffi.gc(obj, lib.SkPixmap_delete)
    return obj
end

function Skia.Pixmap.delete(pixmap)
    lib.SkPixmap_delete(pixmap)
end

function Skia.Pixmap.reset(pixmap)
    lib.SkPixmap_reset(pixmap)
end

function Skia.Pixmap.reset_2(pixmap, info, addr, rowBytes)
    lib.SkPixmap_reset_2(pixmap, info, addr, rowBytes)
end

function Skia.Pixmap.reset_3(pixmap, mask)
    return lib.SkPixmap_reset_3(pixmap, mask)
end

function Skia.Pixmap.setColorSpace(pixmap, color_space)
    lib.SkPixmap_setColorSpace(pixmap, color_space)
end

function Skia.Pixmap.extractSubset(pixmap, subset, area)
    return lib.SkPixmap_extractSubset(pixmap, subset, area)
end

function Skia.Pixmap.info(pixmap)
    return lib. SkPixmap_info(pixmap)
end

function Skia.Pixmap.rowBytes(pixmap)
    return lib.SkPixmap_rowBytes(pixmap)
end

function Skia.Pixmap.addr(pixmap)
    return lib. SkPixmap_addr(pixmap)
end

function Skia.Pixmap.width(pixmap)
    return lib.SkPixmap_width(pixmap)
end

function Skia.Pixmap.height(pixmap)
    return lib.SkPixmap_height(pixmap)
end

function Skia.Pixmap.dimensions(pixmap)
    local obj = lib.SkPixmap_dimensions(pixmap)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Pixmap.colorType(pixmap)
    return lib.SkPixmap_colorType(pixmap)
end

function Skia.Pixmap.alphaType(pixmap)
    return lib.SkPixmap_alphaType(pixmap)
end

function Skia.Pixmap.colorSpace(pixmap)
    return lib. SkPixmap_colorSpace(pixmap)
end

function Skia.Pixmap.refColorSpace(pixmap)
    local obj = lib.SkPixmap_refColorSpace(pixmap)
    setFinalizer(obj, lib.static_sk_color_space_delete)
    return obj
end

function Skia.Pixmap.isOpaque(pixmap)
    return lib.SkPixmap_isOpaque(pixmap)
end

function Skia.Pixmap.bounds(pixmap)
    local obj = lib.SkPixmap_bounds(pixmap)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Pixmap.rowBytesAsPixels(pixmap)
    return lib.SkPixmap_rowBytesAsPixels(pixmap)
end

function Skia.Pixmap.shiftPerPixel(pixmap)
    return lib.SkPixmap_shiftPerPixel(pixmap)
end

function Skia.Pixmap.computeByteSize(pixmap)
    return lib.SkPixmap_computeByteSize(pixmap)
end

function Skia.Pixmap.computeIsOpaque(pixmap)
    return lib.SkPixmap_computeIsOpaque(pixmap)
end

function Skia.Pixmap.getColor(pixmap, x, y)
    return lib.SkPixmap_getColor(pixmap, x, y)
end

function Skia.Pixmap.getColor4f(pixmap, x, y)
    local obj = lib.SkPixmap_getColor4f(pixmap, x, y)
    setFinalizer(obj, lib.static_sk_color_4f_delete)
    return obj
end

function Skia.Pixmap.getAlphaf(pixmap, x, y)
    return lib.SkPixmap_getAlphaf(pixmap, x, y)
end

function Skia.Pixmap.addr_2(pixmap, x, y)
    return lib. SkPixmap_addr_2(pixmap, x, y)
end

function Skia.Pixmap.addr8(pixmap)
    return lib. SkPixmap_addr8(pixmap)
end

function Skia.Pixmap.addr16(pixmap)
    return lib. SkPixmap_addr16(pixmap)
end

function Skia.Pixmap.addr32(pixmap)
    return lib. SkPixmap_addr32(pixmap)
end

function Skia.Pixmap.addr64(pixmap)
    return lib. SkPixmap_addr64(pixmap)
end

function Skia.Pixmap.addrF16(pixmap)
    return lib. SkPixmap_addrF16(pixmap)
end

function Skia.Pixmap.addr8_2(pixmap, x, y)
    return lib. SkPixmap_addr8_2(pixmap, x, y)
end

function Skia.Pixmap.addr16_2(pixmap, x, y)
    return lib. SkPixmap_addr16_2(pixmap, x, y)
end

function Skia.Pixmap.addr32_2(pixmap, x, y)
    return lib. SkPixmap_addr32_2(pixmap, x, y)
end

function Skia.Pixmap.addr64_2(pixmap, x, y)
    return lib. SkPixmap_addr64_2(pixmap, x, y)
end

function Skia.Pixmap.addrF16_2(pixmap, x, y)
    return lib. SkPixmap_addrF16_2(pixmap, x, y)
end

function Skia.Pixmap.writable_addr(pixmap)
    return lib. SkPixmap_writable_addr(pixmap)
end

function Skia.Pixmap.writable_addr_2(pixmap, x, y)
    return lib. SkPixmap_writable_addr_2(pixmap, x, y)
end

function Skia.Pixmap.writable_addr8(pixmap, x, y)
    return lib. SkPixmap_writable_addr8(pixmap, x, y)
end

function Skia.Pixmap.writable_addr16(pixmap, x, y)
    return lib. SkPixmap_writable_addr16(pixmap, x, y)
end

function Skia.Pixmap.writable_addr32(pixmap, x, y)
    return lib. SkPixmap_writable_addr32(pixmap, x, y)
end

function Skia.Pixmap.writable_addr64(pixmap, x, y)
    return lib. SkPixmap_writable_addr64(pixmap, x, y)
end

function Skia.Pixmap.writable_addrF16(pixmap, x, y)
    return lib. SkPixmap_writable_addrF16(pixmap, x, y)
end

function Skia.Pixmap.readPixels(pixmap, dstInfo, dstPixels, dstRowBytes)
    return lib.SkPixmap_readPixels(pixmap, dstInfo, dstPixels, dstRowBytes)
end

function Skia.Pixmap.readPixels_2(pixmap, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
    return lib.SkPixmap_readPixels_2(pixmap, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
end

function Skia.Pixmap.readPixels_3(pixmap, dst, srcX, srcY)
    return lib.SkPixmap_readPixels_3(pixmap, dst, srcX, srcY)
end

function Skia.Pixmap.readPixels_4(pixmap, dst)
    return lib.SkPixmap_readPixels_4(pixmap, dst)
end

function Skia.Pixmap.scalePixels(pixmap, dst, options)
    return lib.SkPixmap_scalePixels(pixmap, dst, options)
end

function Skia.Pixmap.erase(pixmap, color, subset)
    return lib.SkPixmap_erase(pixmap, color, subset)
end

function Skia.Pixmap.erase_2(pixmap, color)
    return lib.SkPixmap_erase_2(pixmap, color)
end

function Skia.Pixmap.erase_3(pixmap, color, subset)
    return lib.SkPixmap_erase_3(pixmap, color, subset)
end

-- ## sk_pixmap_utils
Skia.PixmapUtils = {}

function Skia.PixmapUtils.Orient(dst, src, origin)
    return lib.SkPixmapUtils_Orient(dst, src, origin)
end

function Skia.PixmapUtils.SwapWidthHeight(info)
    local obj = lib.SkPixmapUtils_SwapWidthHeight(info)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

-- ## sk_png_decoder
Skia.PngDecoder = {}

function Skia.PngDecoder.IsPng(ptr, size)
    return lib.SkPngDecoder_IsPng(ptr, size)
end

function Skia.PngDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkPngDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.PngDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkPngDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.PngDecoder.Decoder()
    local obj = lib.SkPngDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

-- ## sk_png_encoder
Skia.PngEncoder = {}

function Skia.PngEncoder.Encode(dst, src, options)
    return lib.SkPngEncoder_Encode(dst, src, options)
end

function Skia.PngEncoder.Encode_2(ctx, img, options)
    local obj = lib.SkPngEncoder_Encode_2(ctx, img, options)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.PngEncoder.Make(dst, src, options)
    local obj = lib.SkPngEncoder_Make(dst, src, options)
    setFinalizer(obj, lib.static_sk_encoder_delete)
    return obj
end

-- ## sk_point
Skia.Point = {}

function Skia.Point.delete(point)
    lib.SkPoint_delete(point)
end

function Skia.Point.x(point)
    return lib.SkPoint_x(point)
end

function Skia.Point.y(point)
    return lib.SkPoint_y(point)
end

function Skia.Point.dot(point, vec)
    return lib.SkPoint_dot(point, vec)
end

function Skia.Point.length(point)
    return lib.SkPoint_length(point)
end

function Skia.Point.cross(point, vec)
    return lib.SkPoint_cross(point, vec)
end

function Skia.Point.set(point, x, y)
    lib.SkPoint_set(point, x, y)
end

function Skia.Point.equals(point, x, y)
    return lib.SkPoint_equals(point, x, y)
end

function Skia.Point.isZero(point)
    return lib.SkPoint_isZero(point)
end

function Skia.Point.scale(point, value)
    lib.SkPoint_scale(point, value)
end

function Skia.Point.scale_2(point, scale, dst)
    lib.SkPoint_scale_2(point, scale, dst)
end

function Skia.Point.isFinite(point)
    return lib.SkPoint_isFinite(point)
end

function Skia.Point.distanceToOrigin(point)
    return lib.SkPoint_distanceToOrigin(point)
end

function Skia.Point.iset(point, p)
    lib.SkPoint_iset(point, p)
end

function Skia.Point.iset_2(point, x, y)
    lib.SkPoint_iset_2(point, x, y)
end

function Skia.Point.negate(point)
    lib.SkPoint_negate(point)
end

function Skia.Point.setAbs(point, pt)
    lib.SkPoint_setAbs(point, pt)
end

function Skia.Point.setLength(point, length)
    return lib.SkPoint_setLength(point, length)
end

function Skia.Point.setNormalize(point, x, y)
    return lib.SkPoint_setNormalize(point, x, y)
end

function Skia.Point.Make(x, y)
    local obj = lib.SkPoint_Make(x, y)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Point.Normalize(vec)
    return lib.SkPoint_Normalize(vec)
end

function Skia.Point.Length(x, y)
    return lib.SkPoint_Length(x, y)
end

function Skia.Point.CrossProduct(a, b)
    return lib.SkPoint_CrossProduct(a, b)
end

function Skia.Point.DotProduct(a, b)
    return lib.SkPoint_DotProduct(a, b)
end

function Skia.Point.Distance(a, b)
    return lib.SkPoint_Distance(a, b)
end

function Skia.Point.Offset(points, count, dx, dy)
    lib.SkPoint_Offset(points, count, dx, dy)
end

function Skia.Point.Offset_2(points, count, offset)
    lib.SkPoint_Offset_2(points, count, offset)
end

-- ## sk_point_3
Skia.Point3 = {}

function Skia.Point3.delete(point3)
    lib.SkPoint3_delete(point3)
end

function Skia.Point3.x(point3)
    return lib.SkPoint3_x(point3)
end

function Skia.Point3.y(point3)
    return lib.SkPoint3_y(point3)
end

function Skia.Point3.z(point3)
    return lib.SkPoint3_z(point3)
end

function Skia.Point3.set(point3, x, y, z)
    lib.SkPoint3_set(point3, x, y, z)
end

function Skia.Point3.length(point3)
    return lib.SkPoint3_length(point3)
end

function Skia.Point3.normalize(point3)
    return lib.SkPoint3_normalize(point3)
end

function Skia.Point3.makeScale(point3, scale)
    local obj = lib.SkPoint3_makeScale(point3, scale)
    setFinalizer(obj, lib.static_sk_point_3_delete)
    return obj
end

function Skia.Point3.scale(point3, value)
    lib.SkPoint3_scale(point3, value)
end

function Skia.Point3.isFinite(point3)
    return lib.SkPoint3_isFinite(point3)
end

function Skia.Point3.dot(point3, vec)
    return lib.SkPoint3_dot(point3, vec)
end

function Skia.Point3.cross(point3, vec)
    local obj = lib.SkPoint3_cross(point3, vec)
    setFinalizer(obj, lib.static_sk_point_3_delete)
    return obj
end

function Skia.Point3.Make(x, y, z)
    local obj = lib.SkPoint3_Make(x, y, z)
    setFinalizer(obj, lib.static_sk_point_3_delete)
    return obj
end

function Skia.Point3.Length(x, y, z)
    return lib.SkPoint3_Length(x, y, z)
end

function Skia.Point3.DotProduct(a, b)
    return lib.SkPoint3_DotProduct(a, b)
end

function Skia.Point3.CrossProduct(a, b)
    local obj = lib.SkPoint3_CrossProduct(a, b)
    setFinalizer(obj, lib.static_sk_point_3_delete)
    return obj
end

-- ## sk_r_rect
Skia.RRect = {}

function Skia.RRect.new()
    local obj = lib.SkRRect_new()
    ffi.gc(obj. lib.SkRRect_delete)
    return obj
end

function Skia.RRect.new_2(rrect)
    local obj = lib.SkRRect_new_2(rrect)
    ffi.gc(obj. lib.SkRRect_delete)
    return obj
end

function Skia.RRect.delete(rrect)
    lib.SkRRect_delete(rrect)
end

function getType(rrect)
    return lib.getType(rrect)
end

function type(rrect)
    return lib.type(rrect)
end

function Skia.RRect.isEmpty(rrect)
    return lib.SkRRect_isEmpty(rrect)
end

function Skia.RRect.isRect(rrect)
    return lib.SkRRect_isRect(rrect)
end

function Skia.RRect.isOval(rrect)
    return lib.SkRRect_isOval(rrect)
end

function Skia.RRect.isSimple(rrect)
    return lib.SkRRect_isSimple(rrect)
end

function Skia.RRect.isNinePatch(rrect)
    return lib.SkRRect_isNinePatch(rrect)
end

function Skia.RRect.isComplex(rrect)
    return lib.SkRRect_isComplex(rrect)
end

function Skia.RRect.width(rrect)
    return lib.SkRRect_width(rrect)
end

function Skia.RRect.height(rrect)
    return lib.SkRRect_height(rrect)
end

function Skia.RRect.getSimpleRadii(rrect)
    local obj = lib.SkRRect_getSimpleRadii(rrect)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.RRect.setEmpty(rrect)
    lib.SkRRect_setEmpty(rrect)
end

function Skia.RRect.setRect(rrect, rect)
    lib.SkRRect_setRect(rrect, rect)
end

function Skia.RRect.setOval(rrect, oval)
    lib.SkRRect_setOval(rrect, oval)
end

function Skia.RRect.setRectXY(rrect, rect, xRad, yRad)
    lib.SkRRect_setRectXY(rrect, rect, xRad, yRad)
end

function Skia.RRect.setNinePatch(rrect, rect, leftRad, topRad, rightRad, bottomRad)
    lib.SkRRect_setNinePatch(rrect, rect, leftRad, topRad, rightRad, bottomRad)
end

function Skia.RRect.setRectRadii(rrect, rect, radii)
    lib.SkRRect_setRectRadii(rrect, rect, radii)
end

function Skia.RRect.rect(rrect)
    return lib. SkRRect_rect(rrect)
end

function Skia.RRect.radii(rrect, corner)
    local obj = lib.SkRRect_radii(rrect, corner)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.RRect.getBounds(rrect)
    return lib. SkRRect_getBounds(rrect)
end

function Skia.RRect.inset(rrect, dx, dy, dst)
    lib.SkRRect_inset(rrect, dx, dy, dst)
end

function Skia.RRect.inset_2(rrect, dx, dy)
    lib.SkRRect_inset_2(rrect, dx, dy)
end

function Skia.RRect.outset(rrect, dx, dy, dst)
    lib.SkRRect_outset(rrect, dx, dy, dst)
end

function Skia.RRect.outset_2(rrect, dx, dy)
    lib.SkRRect_outset_2(rrect, dx, dy)
end

function Skia.RRect.offset(rrect, dx, dy)
    lib.SkRRect_offset(rrect, dx, dy)
end

function Skia.RRect.makeOffset(rrect, dx, dy)
    local obj = lib.SkRRect_makeOffset(rrect, dx, dy)
    setFinalizer(obj, lib.static_sk_r_rect_delete)
    return obj
end

function Skia.RRect.contains(rrect, rect)
    return lib.SkRRect_contains(rrect, rect)
end

function Skia.RRect.isValid(rrect)
    return lib.SkRRect_isValid(rrect)
end

function Skia.RRect.writeToMemory(rrect, buffer)
    return lib.SkRRect_writeToMemory(rrect, buffer)
end

function Skia.RRect.readFromMemory(rrect, buffer, length)
    return lib.SkRRect_readFromMemory(rrect, buffer, length)
end

function Skia.RRect.transform(rrect, matrix, dst)
    return lib.SkRRect_transform(rrect, matrix, dst)
end

function Skia.RRect.dump(rrect, asHex)
    lib.SkRRect_dump(rrect, asHex)
end

function Skia.RRect.dumpToString(rrect, asHex)
    local obj = lib.SkRRect_dumpToString(rrect, asHex)
    setFinalizer(obj, lib.static_sk_string_delete)
    return obj
end

function Skia.RRect.dump_2(rrect)
    lib.SkRRect_dump_2(rrect)
end

function Skia.RRect.dumpHex(rrect)
    lib.SkRRect_dumpHex(rrect)
end

function Skia.RRect.MakeEmpty()
    local obj = lib.SkRRect_MakeEmpty()
    setFinalizer(obj, lib.static_sk_r_rect_delete)
    return obj
end

function Skia.RRect.MakeRect(r)
    local obj = lib.SkRRect_MakeRect(r)
    setFinalizer(obj, lib.static_sk_r_rect_delete)
    return obj
end

function Skia.RRect.MakeOval(oval)
    local obj = lib.SkRRect_MakeOval(oval)
    setFinalizer(obj, lib.static_sk_r_rect_delete)
    return obj
end

function Skia.RRect.MakeRectXY(rect, xRad, yRad)
    local obj = lib.SkRRect_MakeRectXY(rect, xRad, yRad)
    setFinalizer(obj, lib.static_sk_r_rect_delete)
    return obj
end

--[[

-- ## sk_raster_handle_allocator
Skia.RasterHandleAllocator = {}

function Skia.RasterHandleAllocator.delete(raster_handle_allocator)
    lib.SkRasterHandleAllocator_delete(raster_handle_allocator)
end

function Skia.RasterHandleAllocator.allocHandle(raster_handle_allocator, info, rec)
    return lib.SkRasterHandleAllocator_allocHandle(raster_handle_allocator, info, rec)
end

function Skia.RasterHandleAllocator.updateHandle(raster_handle_allocator, handle, matrix, irect)
    lib.SkRasterHandleAllocator_updateHandle(raster_handle_allocator, handle, matrix, irect)
end

-- ## sk_raw_decoder
Skia.RawDecoder = {}

function Skia.RawDecoder.IsRaw(ptr, size)
    return lib.SkRawDecoder_IsRaw(ptr, size)
end

function Skia.RawDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkRawDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.RawDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkRawDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.RawDecoder.Decoder()
    local obj = lib.SkRawDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end
]]

-- ## sk_rect
Skia.Rect = {}

function Skia.Rect.delete(rect)
    lib.SkRect_delete(rect)
end

function Skia.Rect.isEmpty(rect)
    return lib.SkRect_isEmpty(rect)
end

function Skia.Rect.isSorted(rect)
    return lib.SkRect_isSorted(rect)
end

function Skia.Rect.isFinite(rect)
    return lib.SkRect_isFinite(rect)
end

function Skia.Rect.x(rect)
    return lib.SkRect_x(rect)
end

function Skia.Rect.y(rect)
    return lib.SkRect_y(rect)
end

function Skia.Rect.left(rect)
    return lib.SkRect_left(rect)
end

function Skia.Rect.top(rect)
    return lib.SkRect_top(rect)
end

function Skia.Rect.right(rect)
    return lib.SkRect_right(rect)
end

function Skia.Rect.bottom(rect)
    return lib.SkRect_bottom(rect)
end

function Skia.Rect.width(rect)
    return lib.SkRect_width(rect)
end

function Skia.Rect.height(rect)
    return lib.SkRect_height(rect)
end

function Skia.Rect.centerX(rect)
    return lib.SkRect_centerX(rect)
end

function Skia.Rect.centerY(rect)
    return lib.SkRect_centerY(rect)
end

function Skia.Rect.center(rect)
    local obj = lib.SkRect_center(rect)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.Rect.toQuad(rect, quad)
    lib.SkRect_toQuad(rect, quad)
end

function Skia.Rect.setEmpty(rect)
    lib.SkRect_setEmpty(rect)
end

function Skia.Rect.set(rect, src)
    lib.SkRect_set(rect, src)
end

function Skia.Rect.setLTRB(rect, left, top, right, bottom)
    lib.SkRect_setLTRB(rect, left, top, right, bottom)
end

function Skia.Rect.setBounds(rect, pts, count)
    lib.SkRect_setBounds(rect, pts, count)
end

function Skia.Rect.setBoundsCheck(rect, pts, count)
    return lib.SkRect_setBoundsCheck(rect, pts, count)
end

function Skia.Rect.setBoundsNoCheck(rect, pts, count)
    lib.SkRect_setBoundsNoCheck(rect, pts, count)
end

function Skia.Rect.set_2(rect, p0, p1)
    lib.SkRect_set_2(rect, p0, p1)
end

function Skia.Rect.setXYWH(rect, x, y, width, height)
    lib.SkRect_setXYWH(rect, x, y, width, height)
end

function Skia.Rect.setWH(rect, width, height)
    lib.SkRect_setWH(rect, width, height)
end

function Skia.Rect.setIWH(rect, width, height)
    lib.SkRect_setIWH(rect, width, height)
end

function Skia.Rect.makeOffset(rect, dx, dy)
    local obj = lib.SkRect_makeOffset(rect, dx, dy)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.makeOffset_2(rect, v)
    local obj = lib.SkRect_makeOffset_2(rect, v)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.makeInset(rect, dx, dy)
    local obj = lib.SkRect_makeInset(rect, dx, dy)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.makeOutset(rect, dx, dy)
    local obj = lib.SkRect_makeOutset(rect, dx, dy)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.offset(rect, dx, dy)
    lib.SkRect_offset(rect, dx, dy)
end

function Skia.Rect.offset_2(rect, delta)
    lib.SkRect_offset_2(rect, delta)
end

function Skia.Rect.offsetTo(rect, newX, newY)
    lib.SkRect_offsetTo(rect, newX, newY)
end

function Skia.Rect.inset(rect, dx, dy)
    lib.SkRect_inset(rect, dx, dy)
end

function Skia.Rect.outset(rect, dx, dy)
    lib.SkRect_outset(rect, dx, dy)
end

function Skia.Rect.intersect(rect, r)
    return lib.SkRect_intersect(rect, r)
end

function Skia.Rect.intersect_2(rect, a, b)
    return lib.SkRect_intersect_2(rect, a, b)
end

function Skia.Rect.intersects(rect, r)
    return lib.SkRect_intersects(rect, r)
end

function Skia.Rect.join(rect, r)
    lib.SkRect_join(rect, r)
end

function Skia.Rect.joinNonEmptyArg(rect, r)
    lib.SkRect_joinNonEmptyArg(rect, r)
end

function Skia.Rect.joinPossiblyEmptyRect(rect, r)
    lib.SkRect_joinPossiblyEmptyRect(rect, r)
end

function Skia.Rect.contains(rect, x, y)
    return lib.SkRect_contains(rect, x, y)
end

function Skia.Rect.contains_2(rect, r)
    return lib.SkRect_contains_2(rect, r)
end

function Skia.Rect.contains_3(rect, r)
    return lib.SkRect_contains_3(rect, r)
end

function Skia.Rect.round(rect, dst)
    lib.SkRect_round(rect, dst)
end

function Skia.Rect.roundOut(rect, dst)
    lib.SkRect_roundOut(rect, dst)
end

function Skia.Rect.roundOut_2(rect, dst)
    lib.SkRect_roundOut_2(rect, dst)
end

function Skia.Rect.roundIn(rect, dst)
    lib.SkRect_roundIn(rect, dst)
end

function Skia.Rect.round_2(rect)
    local obj = lib.SkRect_round_2(rect)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Rect.roundOut_3(rect)
    local obj = lib.SkRect_roundOut_3(rect)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Rect.roundIn_2(rect)
    local obj = lib.SkRect_roundIn_2(rect)
    setFinalizer(obj, lib.static_sk_i_rect_delete)
    return obj
end

function Skia.Rect.sort(rect)
    lib.SkRect_sort(rect)
end

function Skia.Rect.makeSorted(rect)
    local obj = lib.SkRect_makeSorted(rect)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.asScalars(rect)
    return lib. SkRect_asScalars(rect)
end

function Skia.Rect.dump(rect, asHex)
    lib.SkRect_dump(rect, asHex)
end

function Skia.Rect.dump_2(rect)
    lib.SkRect_dump_2(rect)
end

function Skia.Rect.dumpHex(rect)
    lib.SkRect_dumpHex(rect)
end

function Skia.Rect.MakeEmpty()
    local obj = lib.SkRect_MakeEmpty()
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.MakeWH(w, h)
    local obj = lib.SkRect_MakeWH(w, h)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.MakeIWH(w, h)
    local obj = lib.SkRect_MakeIWH(w, h)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.MakeSize(size)
    local obj = lib.SkRect_MakeSize(size)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.MakeLTRB(l, t, r, b)
    local obj = lib.SkRect_MakeLTRB(l, t, r, b)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.MakeXYWH(x, y, w, h)
    local obj = lib.SkRect_MakeXYWH(x, y, w, h)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.Make(size)
    local obj = lib.SkRect_Make(size)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.Make_2(irect)
    local obj = lib.SkRect_Make_2(irect)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Rect.Intersects(a, b)
    return lib.SkRect_Intersects(a, b)
end

-- ## sk_ref_cnt
Skia.RefCnt = {}

function Skia.RefCnt.delete(refCnt)
    lib.SkRefCnt_delete(refCnt)
end

function Skia.RefCnt.unique(ref_cnt)
    return lib.SkRefCnt_unique(ref_cnt)
end

function Skia.RefCnt.ref(ref_cnt)
    lib.SkRefCnt_ref(ref_cnt)
end

function Skia.RefCnt.unref(ref_cnt)
    lib.SkRefCnt_unref(ref_cnt)
end

-- ## sk_ref_cnt_base
Skia.RefCntBase = {}

function Skia.RefCntBase.new()
    local obj = lib.SkRefCntBase_new()
    ffi.gc(obj, lib.SkRefCntBase_delete)
    return obj
end

function Skia.RefCntBase.delete(ref_cnt_base)
    lib.SkRefCntBase_delete(ref_cnt_base)
end

function Skia.RefCntBase.unique(ref_cnt_base)
    return lib.SkRefCntBase_unique(ref_cnt_base)
end

function Skia.RefCntBase.ref(ref_cnt_base)
    lib.SkRefCntBase_ref(ref_cnt_base)
end

function Skia.RefCntBase.unref(ref_cnt_base)
    lib.SkRefCntBase_unref(ref_cnt_base)
end

-- ## sk_region
Skia.Region = {}

function Skia.Region.new()
    local obj = lib.SkRegion_new()
    ffi.gc(obj, lib.SkRegion_delete)
    return obj
end

function Skia.Region.new_2(region)
    local obj = lib.SkRegion_new_2(region)
    ffi.gc(obj, lib.SkRegion_delete)
    return obj
end

function Skia.Region.new_3(rect)
    local obj = lib.SkRegion_new_3(rect)
    ffi.gc(obj, lib.SkRegion_delete)
    return obj
end

function Skia.Region.delete(region)
    lib.SkRegion_delete(region)
end

function Skia.Region.set(region, src)
    return lib.SkRegion_set(region, src)
end

function Skia.Region.swap(region, other)
    lib.SkRegion_swap(region, other)
end

function Skia.Region.isEmpty(region)
    return lib.SkRegion_isEmpty(region)
end

function Skia.Region.isRect(region)
    return lib.SkRegion_isRect(region)
end

function Skia.Region.isComplex(region)
    return lib.SkRegion_isComplex(region)
end

function Skia.Region.getBounds(region)
    return lib. SkRegion_getBounds(region)
end

function Skia.Region.computeRegionComplexity(region)
    return lib.SkRegion_computeRegionComplexity(region)
end

function Skia.Region.getBoundaryPath(region, path)
    return lib.SkRegion_getBoundaryPath(region, path)
end

function Skia.Region.setEmpty(region)
    return lib.SkRegion_setEmpty(region)
end

function Skia.Region.setRect(region, rect)
    return lib.SkRegion_setRect(region, rect)
end

function Skia.Region.setRects(region, rects, count)
    return lib.SkRegion_setRects(region, rects, count)
end

function Skia.Region.setRegion(region, region_2)
    return lib.SkRegion_setRegion(region, region_2)
end

function Skia.Region.setPath(region, path, clip)
    return lib.SkRegion_setPath(region, path, clip)
end

function Skia.Region.intersects(region, rect)
    return lib.SkRegion_intersects(region, rect)
end

function Skia.Region.intersects_2(region, other)
    return lib.SkRegion_intersects_2(region, other)
end

function Skia.Region.contains(region, x, y)
    return lib.SkRegion_contains(region, x, y)
end

function Skia.Region.contains_2(region, other)
    return lib.SkRegion_contains_2(region, other)
end

function Skia.Region.contains_3(region, other)
    return lib.SkRegion_contains_3(region, other)
end

function Skia.Region.quickContains(region, r)
    return lib.SkRegion_quickContains(region, r)
end

function Skia.Region.quickReject(region, rect)
    return lib.SkRegion_quickReject(region, rect)
end

function Skia.Region.quickReject_2(region, rgn)
    return lib.SkRegion_quickReject_2(region, rgn)
end

function Skia.Region.translate(region, dx, dy)
    lib.SkRegion_translate(region, dx, dy)
end

function Skia.Region.translate_2(region, dx, dy, dst)
    lib.SkRegion_translate_2(region, dx, dy, dst)
end

function Skia.Region.op(region, rect, op)
    return lib.SkRegion_op(region, rect, op)
end

function Skia.Region.op_2(region, rgn, op)
    return lib.SkRegion_op_2(region, rgn, op)
end

function Skia.Region.op_3(region, rect, rgn, op)
    return lib.SkRegion_op_3(region, rect, rgn, op)
end

function Skia.Region.op_4(region, rgn, rect, op)
    return lib.SkRegion_op_4(region, rgn, rect, op)
end

function Skia.Region.op_5(region, rgna, rgnb, op)
    return lib.SkRegion_op_5(region, rgna, rgnb, op)
end

function Skia.Region.writeToMemory(region, buffer)
    return lib.SkRegion_writeToMemory(region, buffer)
end

function Skia.Region.readFromMemory(region, buffer, length)
    return lib.SkRegion_readFromMemory(region, buffer, length)
end

-- ## sk_rsx_form
Skia.RSXform = {}

function Skia.RSXform.delete(rsx_form)
    lib.SkRSXform_delete(rsx_form)
end

function Skia.RSXform.rectStaysRect(rsx_form)
    return lib.SkRSXform_rectStaysRect(rsx_form)
end

function Skia.RSXform.setIdentity(rsx_form)
    lib.SkRSXform_setIdentity(rsx_form)
end

function Skia.RSXform.set(rsx_form, scos, ssin, tx, ty)
    lib.SkRSXform_set(rsx_form, scos, ssin, tx, ty)
end

function Skia.RSXform.toQuad(rsx_form, width, height, quad)
    lib.SkRSXform_toQuad(rsx_form, width, height, quad)
end

function Skia.RSXform.toQuad_2(rsx_form, size, quad)
    lib.SkRSXform_toQuad_2(rsx_form, size, quad)
end

function Skia.RSXform.toTriStrip(rsx_form, width, height, strip)
    lib.SkRSXform_toTriStrip(rsx_form, width, height, strip)
end

function Skia.RSXform.Make(scos, ssin, tx, ty)
    local obj = lib.SkRSXform_Make(scos, ssin, tx, ty)
    setFinalizer(obj, lib.static_sk_rsx_form_delete)
    return obj
end

function Skia.RSXform.MakeFromRadians(scale, radians, tx, ty, ax, ay)
    local obj = lib.SkRSXform_MakeFromRadians(scale, radians, tx, ty, ax, ay)
    setFinalizer(obj, lib.static_sk_rsx_form_delete)
    return obj
end

-- ## sk_runtime_blend_builder
Skia.RuntimeBlendBuilder = {}

function Skia.RuntimeBlendBuilder.new(runtime_effect)
    local obj = lib.SkRuntimeBlendBuilder_new(runtime_effect)
    ffi.gc(obj, lib.SkRuntimeBlendBuilder_delete)
    return obj
end

function Skia.RuntimeBlendBuilder.delete(runtime_blend_builder)
    lib.SkRuntimeBlendBuilder_delete(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.makeBlender(runtime_blend_builder)
    local obj = lib.SkRuntimeBlendBuilder_makeBlender(runtime_blend_builder)
    setFinalizer(obj, lib.static_sk_blender_delete)
    return obj
end

function Skia.RuntimeBlendBuilder.effect(runtime_blend_builder)
    return lib. SkRuntimeBlendBuilder_effect(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.uniform(runtime_blend_builder, name)
    local obj = lib.SkRuntimeBlendBuilder_uniform(runtime_blend_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_uniform_delete)
    return obj
end

function Skia.RuntimeBlendBuilder.child(runtime_blend_builder, name)
    local obj = lib.SkRuntimeBlendBuilder_child(runtime_blend_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_child_delete)
    return obj
end

function Skia.RuntimeBlendBuilder.uniforms(runtime_blend_builder)
    local obj = lib.SkRuntimeBlendBuilder_uniforms(runtime_blend_builder)
    setFinalizer(obj, lib.static_const_sk_data_delete)
    return obj
end

function Skia.RuntimeBlendBuilder.children(runtime_blend_builder)
    local obj = lib.SkRuntimeBlendBuilder_children(runtime_blend_builder)
    setFinalizer(obj, lib.static_const_sk_runtime_effect_child_ptr_delete)
    return obj
end

-- ## sk_runtime_color_filter_builder
Skia.RuntimeColorFilterBuilder = {}

function Skia.RuntimeColorFilterBuilder.new(runtime_effect)
    local obj = lib.SkRuntimeColorFilterBuilder_new(runtime_effect)
    ffi.gc(obj, lib.SkRuntimeColorFilterBuilder_delete)
    return obj
end

function Skia.RuntimeColorFilterBuilder.delete(runtime_color_filter_builder)
    lib.SkRuntimeColorFilterBuilder_delete(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.makeColorFilter(runtime_color_filter_builder)
    local obj = lib.SkRuntimeColorFilterBuilder_makeColorFilter(runtime_color_filter_builder)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.RuntimeColorFilterBuilder.effect(runtime_color_filter_builder)
    return lib.SkRuntimeColorFilterBuilder_effect(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.uniform(runtime_color_filter_builder, name)
    local obj = lib.SkRuntimeColorFilterBuilder_uniform(runtime_color_filter_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_uniform_delete)
    return obj
end

function Skia.RuntimeColorFilterBuilder.child(runtime_color_filter_builder, name)
    local obj = lib.SkRuntimeColorFilterBuilder_child(runtime_color_filter_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_child_delete)
    return obj
end

function Skia.RuntimeColorFilterBuilder.uniforms(runtime_color_filter_builder)
    local obj = lib.SkRuntimeColorFilterBuilder_uniforms(runtime_color_filter_builder)
    setFinalizer(obj, lib.static_const_sk_data_delete)
    return obj
end

function Skia.RuntimeColorFilterBuilder.children(runtime_color_filter_builder)
    local obj = lib.SkRuntimeColorFilterBuilder_children(runtime_color_filter_builder)
    setFinalizer(obj, lib.static_const_sk_runtime_effect_child_ptr_delete)
    return obj
end

-- ## sk_runtime_effect
Skia.RuntimeEffect = {}

function Skia.RuntimeEffect.delete(runtime_effect)
    lib.SkRuntimeEffect_delete(runtime_effect)
end

function Skia.RuntimeEffect.makeShader(runtime_effect, data, children, childCount, localMatrix)
    local obj = lib.SkRuntimeEffect_makeShader(runtime_effect, data, children, childCount, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.RuntimeEffect.makeShader_2(runtime_effect, data, runtime_effect_child_ptr, localMatrix)
    local obj = lib.SkRuntimeEffect_makeShader_2(runtime_effect, data, runtime_effect_child_ptr, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.RuntimeEffect.makeColorFilter(runtime_effect, data)
    local obj = lib.SkRuntimeEffect_makeColorFilter(runtime_effect, data)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.RuntimeEffect.makeColorFilter_2(runtime_effect, data, children, childCount)
    local obj = lib.SkRuntimeEffect_makeColorFilter_2(runtime_effect, data, children, childCount)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.RuntimeEffect.makeColorFilter_3(runtime_effect, data, runtime_effect_child_ptr)
    local obj = lib.SkRuntimeEffect_makeColorFilter_3(runtime_effect, data, runtime_effect_child_ptr)
    setFinalizer(obj, lib.static_sk_color_filter_delete)
    return obj
end

function Skia.RuntimeEffect.makeBlender(runtime_effect, data, runtime_effect_child_ptr)
    local obj = lib.SkRuntimeEffect_makeBlender(runtime_effect, data, runtime_effect_child_ptr)
    setFinalizer(obj, lib.static_sk_blender_delete)
    return obj
end

function Skia.RuntimeEffect.source(runtime_effect)
    return lib. SkRuntimeEffect_source(runtime_effect)
end

function Skia.RuntimeEffect.uniformSize(runtime_effect)
    return lib.SkRuntimeEffect_uniformSize(runtime_effect)
end

function Skia.RuntimeEffect.uniforms(runtime_effect)
    return lib.SkRuntimeEffect_uniforms(runtime_effect)
end

function Skia.RuntimeEffect.children(runtime_effect)
    return lib.SkRuntimeEffect_children(runtime_effect)
end

function Skia.RuntimeEffect.findUniform(runtime_effect, name)
    return lib. SkRuntimeEffect_findUniform(runtime_effect, name)
end

function Skia.RuntimeEffect.findChild(runtime_effect, name)
    return lib. SkRuntimeEffect_findChild(runtime_effect, name)
end

function Skia.RuntimeEffect.allowShader(runtime_effect)
    return lib.SkRuntimeEffect_allowShader(runtime_effect)
end

function Skia.RuntimeEffect.allowColorFilter(runtime_effect)
    return lib.SkRuntimeEffect_allowColorFilter(runtime_effect)
end

function Skia.RuntimeEffect.allowBlender(runtime_effect)
    return lib.SkRuntimeEffect_allowBlender(runtime_effect)
end

function Skia.RuntimeEffect.unique(runtime_effect)
    return lib.SkRuntimeEffect_unique(runtime_effect)
end

function Skia.RuntimeEffect.ref(runtime_effect)
    lib.SkRuntimeEffect_ref(runtime_effect)
end

function Skia.RuntimeEffect.unref(runtime_effect)
    lib.SkRuntimeEffect_unref(runtime_effect)
end

function Skia.RuntimeEffect.MakeForColorFilter(string, options)
    local obj = lib.SkRuntimeEffect_MakeForColorFilter(string, options)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeForColorFilter_2(string)
    local obj = lib.SkRuntimeEffect_MakeForColorFilter_2(string)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeForShader(string, options)
    local obj = lib.SkRuntimeEffect_MakeForShader(string, options)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeForShader_2(string)
    local obj = lib.SkRuntimeEffect_MakeForShader_2(string)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeForBlender(string, options)
    local obj = lib.SkRuntimeEffect_MakeForBlender(string, options)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeForBlender_2(string)
    local obj = lib.SkRuntimeEffect_MakeForBlender_2(string)
    setFinalizer(obj, lib.static_sk_runtime_effect_result_delete)
    return obj
end

function Skia.RuntimeEffect.MakeTraced(shader, traceCoord)
    return lib.SkRuntimeEffect_MakeTraced(shader, traceCoord)
end

-- ## sk_runtime_effect_builder
Skia.RuntimeEffectBuilder = {}

function Skia.RuntimeEffectBuilder.delete(runtime_effect_builder)
    lib.SkRuntimeEffectBuilder_delete(runtime_effect_builder)
end

function Skia.RuntimeEffectBuilder.effect(runtime_effect_builder)
    return lib. SkRuntimeEffectBuilder_effect(runtime_effect_builder)
end

function Skia.RuntimeEffectBuilder.uniform(runtime_effect_builder, name)
    local obj = lib.SkRuntimeEffectBuilder_uniform(runtime_effect_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_uniform_delete)
    return obj
end

function Skia.RuntimeEffectBuilder.child(runtime_effect_builder, name)
    local obj = lib.SkRuntimeEffectBuilder_child(runtime_effect_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_child_delete)
    return obj
end

function Skia.RuntimeEffectBuilder.uniforms(runtime_effect_builder)
    local obj = lib.SkRuntimeEffectBuilder_uniforms(runtime_effect_builder)
    setFinalizer(obj, lib.static_const_sk_data_delete)
    return obj
end

function Skia.RuntimeEffectBuilder.children(runtime_effect_builder)
    local obj = lib.SkRuntimeEffectBuilder_children(runtime_effect_builder)
    setFinalizer(obj, lib.static_const_sk_runtime_effect_child_ptr_delete)
    return obj
end

-- ## sk_runtime_shader_builder
Skia.RuntimeShaderBuilder = {}

function Skia.RuntimeShaderBuilder.new(runtime_effect)
    local obj = lib.SkRuntimeShaderBuilder_new(runtime_effect)
    ffi.gc(obj, lib.SkRuntimeShaderBuilder_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.new_2(builder)
    local obj = lib.SkRuntimeShaderBuilder_new_2(builder)
    ffi.gc(obj, lib.SkRuntimeShaderBuilder_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.delete(runtime_shader_builder)
    lib.SkRuntimeShaderBuilder_delete(runtime_shader_builder)
end

function Skia.RuntimeShaderBuilder.makeShader(runtime_shader_builder, localMatrix)
    local obj = lib.SkRuntimeShaderBuilder_makeShader(runtime_shader_builder, localMatrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.effect(runtime_shader_builder)
    return lib. SkRuntimeShaderBuilder_effect(runtime_shader_builder)
end

function Skia.RuntimeShaderBuilder.uniform(runtime_shader_builder, name)
    local obj = lib.SkRuntimeShaderBuilder_uniform(runtime_shader_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_uniform_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.child(runtime_shader_builder, name)
    local obj = lib.SkRuntimeShaderBuilder_child(runtime_shader_builder, name)
    setFinalizer(obj, lib.static_sk_runtime_effect_builder_builder_child_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.uniforms(runtime_shader_builder)
    local obj = lib.SkRuntimeShaderBuilder_uniforms(runtime_shader_builder)
    setFinalizer(obj, lib.static_const_sk_data_delete)
    return obj
end

function Skia.RuntimeShaderBuilder.children(runtime_shader_builder)
    local obj = lib.SkRuntimeShaderBuilder_children(runtime_shader_builder)
    setFinalizer(obj, lib.static_const_sk_runtime_effect_child_ptr_delete)
    return obj
end

-- ## sk_sampling_options
Skia.SamplingOptions = {}

function Skia.SamplingOptions.new()
    local obj = lib.SkSamplingOptions_new()
    ffi.gc(obj, lib.SkSamplingOptions_delete)
    return obj
end

function Skia.SamplingOptions.new_2(options)
    local obj = lib.SkSamplingOptions_new_2(options)
    ffi.gc(obj, lib.SkSamplingOptions_delete)
    return obj
end

function Skia.SamplingOptions.new_3(fm, mm)
    local obj = lib.SkSamplingOptions_new_3(fm, mm)
    ffi.gc(obj, lib.SkSamplingOptions_delete)
    return obj
end

function Skia.SamplingOptions.new_4(fm)
    local obj = lib.SkSamplingOptions_new_4(fm)
    ffi.gc(obj, lib.SkSamplingOptions_delete)
    return obj
end

function Skia.SamplingOptions.new_5(c)
    local obj = lib.SkSamplingOptions_new_5(c)
    ffi.gc(obj, lib.SkSamplingOptions_delete)
    return obj
end

function Skia.SamplingOptions.delete(sampling_options)
    lib.SkSamplingOptions_delete(sampling_options)
end

function Skia.SamplingOptions.isAniso(sampling_options)
    return lib.SkSamplingOptions_isAniso(sampling_options)
end

function Skia.SamplingOptions.Aniso(maxAniso)
    local obj = lib.SkSamplingOptions_Aniso(maxAniso)
    setFinalizer(obj, lib.static_sk_sampling_options_delete)
    return obj
end

-- ## sk_shader
Skia.Shader = {}

function Skia.Shader.delete(shader)
    lib.SkShader_delete(shader)
end

function Skia.Shader.isOpaque(shader)
    return lib.SkShader_isOpaque(shader)
end

function Skia.Shader.isAImage(shader, localMatrix, xy)
    return lib. SkShader_isAImage(shader, localMatrix, xy)
end

function Skia.Shader.isAImage_2(shader)
    return lib.SkShader_isAImage_2(shader)
end

function Skia.Shader.makeWithLocalMatrix(shader, matrix)
    local obj = lib.SkShader_makeWithLocalMatrix(shader, matrix)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shader.makeWithColorFilter(shader, color_filter)
    local obj = lib.SkShader_makeWithColorFilter(shader, color_filter)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shader.makeWithWorkingColorSpace(shader, color_space)
    local obj = lib.SkShader_makeWithWorkingColorSpace(shader, color_space)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shader.getFactory(shader)
    local obj = lib.SkShader_getFactory(shader)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Shader.getTypeName(shader)
    return lib. SkShader_getTypeName(shader)
end

function Skia.Shader.flatten(shader, buffer)
    lib.SkShader_flatten(shader, buffer)
end

function Skia.Shader.getFlattenableType(shader)
    return lib.SkShader_getFlattenableType(shader)
end

function Skia.Shader.serialize(shader, procs)
    local obj = lib.SkShader_serialize(shader, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Shader.serialize_2(shader, memory, memory_size, procs)
    return lib.SkShader_serialize_2(shader, memory, memory_size, procs)
end

function Skia.Shader.unique(shader)
    return lib.SkShader_unique(shader)
end

function Skia.Shader.ref(shader)
    lib.SkShader_ref(shader)
end

function Skia.Shader.unref(shader)
    lib.SkShader_unref(shader)
end

function Skia.Shader.NameToFactory(name)
    local obj = lib.SkShader_NameToFactory(name)
    setFinalizer(obj, lib.static_sk_flattenable_factory_delete)
    return obj
end

function Skia.Shader.FactoryToName(factory)
    return lib. SkShader_FactoryToName(factory)
end

function Skia.Shader.Register(name, factory)
    lib.SkShader_Register(name, factory)
end

function Skia.Shader.Deserialize(type, data, length, procs)
    local obj = lib.SkShader_Deserialize(type, data, length, procs)
    setFinalizer(obj, lib.static_sk_flattenable_delete)
    return obj
end

-- ## sk_shader_mask_filter
Skia.ShaderMaskFilter = {}

function Skia.ShaderMaskFilter.delete(shaderMaskFilter)
    lib.SkShaderMaskFilter_delete(shaderMaskFilter)
end

function Skia.ShaderMaskFilter.Make(shader)
    local obj = lib.SkShaderMaskFilter_Make(shader)
    setFinalizer(obj, lib.static_sk_mask_filter_delete)
    return obj
end

-- ## sk_shaders
Skia.Shaders = {}

function Skia.Shaders.Empty()
    local obj = lib.SkShaders_Empty()
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shaders.Color(color)
    local obj = lib.SkShaders_Color(color)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shaders.Color_2(color4f, color_space)
    local obj = lib.SkShaders_Color_2(color4f, color_space)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shaders.Blend(mode, dst, src)
    local obj = lib.SkShaders_Blend(mode, dst, src)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shaders.Blend_2(value, dst, src)
    local obj = lib.SkShaders_Blend_2(value, dst, src)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

function Skia.Shaders.CoordClamp(shader, subset)
    local obj = lib.SkShaders_CoordClamp(shader, subset)
    setFinalizer(obj, lib.static_sk_shader_delete)
    return obj
end

-- ## sk_shaper
Skia.Shaper = {}

function Skia.Shaper.delete(shaper)
    lib.SkShaper_delete(shaper)
end

function Skia.Shaper.shape(shaper, utf8, utf8Bytes, srcFont, leftToRight, width, handler)
    lib.SkShaper_shape(shaper, utf8, utf8Bytes, srcFont, leftToRight, width, handler)
end

function Skia.Shaper.shape_2(shaper, utf8, utf8Bytes, font, bidi, script, language, width, handler)
    lib.SkShaper_shape_2(shaper, utf8, utf8Bytes, font, bidi, script, language, width, handler)
end

function Skia.Shaper.shape_3(shaper, utf8, utf8Bytes, font, bidi, script, language, features, featuresSize, width, handler)
    lib.SkShaper_shape_3(shaper, utf8, utf8Bytes, font, bidi, script, language, features, featuresSize, width, handler)
end

function Skia.Shaper.MakePrimitive()
    local obj = lib.SkShaper_MakePrimitive()
    setFinalizer(obj, lib.static_sk_shaper_delete)
    return obj
end

function Skia.Shaper.Make(font_mgr)
    local obj = lib.SkShaper_Make(font_mgr)
    setFinalizer(obj, lib.static_sk_shaper_delete)
    return obj
end

function Skia.Shaper.PurgeCaches()
    lib.SkShaper_PurgeCaches()
end

function Skia.Shaper.MakeFontMgrRunIterator(utf8, utf8Bytes, font, font_mgr)
    local obj = lib.SkShaper_MakeFontMgrRunIterator(utf8, utf8Bytes, font, font_mgr)
    setFinalizer(obj, lib.static_sk_shaper_font_run_iterator_delete)
    return obj
end

function Skia.Shaper.MakeFontMgrRunIterator_2(utf8, utf8Bytes, font, font_mgr, requestName, requestStyle, language_run_iterator)
    local obj = lib.SkShaper_MakeFontMgrRunIterator_2(utf8, utf8Bytes, font, font_mgr, requestName, requestStyle, language_run_iterator)
    setFinalizer(obj, lib.static_sk_shaper_font_run_iterator_delete)
    return obj
end

function Skia.Shaper.MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel)
    local obj = lib.SkShaper_MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel)
    setFinalizer(obj, lib.static_sk_shaper_bi_di_run_iterator_delete)
    return obj
end

function Skia.Shaper.MakeScriptRunIterator(utf8, utf8Bytes, script)
    local obj = lib.SkShaper_MakeScriptRunIterator(utf8, utf8Bytes, script)
    setFinalizer(obj, lib.static_sk_shaper_script_run_iterator_delete)
    return obj
end

function Skia.Shaper.MakeStdLanguageRunIterator(utf8, utf8Bytes)
    local obj = lib.SkShaper_MakeStdLanguageRunIterator(utf8, utf8Bytes)
    setFinalizer(obj, lib.static_sk_shaper_language_run_iterator_delete)
    return obj
end

-- ## sk_size
Skia.Size = {}

function Skia.Size.delete(size)
    lib.SkSize_delete(size)
end

function Skia.Size.set(size, w, h)
    lib.SkSize_set(size, w, h)
end

function Skia.Size.isZero(size)
    return lib.SkSize_isZero(size)
end

function Skia.Size.isEmpty(size)
    return lib.SkSize_isEmpty(size)
end

function Skia.Size.setEmpty(size)
    lib.SkSize_setEmpty(size)
end

function Skia.Size.width(size)
    return lib.SkSize_width(size)
end

function Skia.Size.height(size)
    return lib.SkSize_height(size)
end

function Skia.Size.equals(size, w, h)
    return lib.SkSize_equals(size, w, h)
end

function Skia.Size.toRound(size)
    local obj = lib.SkSize_toRound(size)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Size.toCeil(size)
    local obj = lib.SkSize_toCeil(size)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Size.toFloor(size)
    local obj = lib.SkSize_toFloor(size)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.Size.Make(w, h)
    local obj = lib.SkSize_Make(w, h)
    setFinalizer(obj, lib.static_sk_size_delete)
    return obj
end

function Skia.Size.Make_2(src)
    local obj = lib.SkSize_Make_2(src)
    setFinalizer(obj, lib.static_sk_size_delete)
    return obj
end

function Skia.Size.MakeEmpty()
    local obj = lib.SkSize_MakeEmpty()
    setFinalizer(obj, lib.static_sk_size_delete)
    return obj
end

-- ## sk_stream
Skia.Stream = {}

function Skia.Stream.delete(stream)
    lib.SkStream_delete(stream)
end

function Skia.Stream.read(stream, buffer, size)
    return lib.SkStream_read(stream, buffer, size)
end

function Skia.Stream.skip(stream, size)
    return lib.SkStream_skip(stream, size)
end

function Skia.Stream.peek(stream, buffer, size)
    return lib.SkStream_peek(stream, buffer, size)
end

function Skia.Stream.isAtEnd(stream)
    return lib.SkStream_isAtEnd(stream)
end

function Skia.Stream.readS8(stream, i)
    return lib.SkStream_readS8(stream, i)
end

function Skia.Stream.readS16(stream, i)
    return lib.SkStream_readS16(stream, i)
end

function Skia.Stream.readS32(stream, i)
    return lib.SkStream_readS32(stream, i)
end

function Skia.Stream.readU8(stream, i)
    return lib.SkStream_readU8(stream, i)
end

function Skia.Stream.readU16(stream, i)
    return lib.SkStream_readU16(stream, i)
end

function Skia.Stream.readU32(stream, i)
    return lib.SkStream_readU32(stream, i)
end

function Skia.Stream.readBool(stream, b)
    return lib.SkStream_readBool(stream, b)
end

function Skia.Stream.readScalar(stream, v)
    return lib.SkStream_readScalar(stream, v)
end

function Skia.Stream.readPackedUInt(stream, size)
    return lib.SkStream_readPackedUInt(stream, size)
end

function Skia.Stream.rewind(stream)
    return lib.SkStream_rewind(stream)
end

function Skia.Stream.duplicate(stream)
    local obj = lib.SkStream_duplicate(stream)
    setFinalizer(obj, lib.static_sk_stream_delete)
    return obj
end

function Skia.Stream.fork(stream)
    local obj = lib.SkStream_fork(stream)
    setFinalizer(obj, lib.static_sk_stream_delete)
    return obj
end

function Skia.Stream.hasPosition(stream)
    return lib.SkStream_hasPosition(stream)
end

function Skia.Stream.getPosition(stream)
    return lib.SkStream_getPosition(stream)
end

function Skia.Stream.seek(stream, size)
    return lib.SkStream_seek(stream, size)
end

function Skia.Stream.move(stream, i)
    return lib.SkStream_move(stream, i)
end

function Skia.Stream.hasLength(stream)
    return lib.SkStream_hasLength(stream)
end

function Skia.Stream.getLength(stream)
    return lib.SkStream_getLength(stream)
end

function Skia.Stream.getMemoryBase(stream)
    return lib. SkStream_getMemoryBase(stream)
end

function Skia.Stream.MakeFromFile(path)
    local obj = lib.SkStream_MakeFromFile(path)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

-- ## sk_stream_asset
Skia.StreamAsset = {}

function Skia.StreamAsset.delete(stream_asset)
    lib.SkStreamAsset_delete(stream_asset)
end

function Skia.StreamAsset.hasLength(stream_asset)
    return lib.SkStreamAsset_hasLength(stream_asset)
end

function Skia.StreamAsset.getLength(stream_asset)
    return lib.SkStreamAsset_getLength(stream_asset)
end

function Skia.StreamAsset.duplicate(stream_asset)
    local obj = lib.SkStreamAsset_duplicate(stream_asset)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.StreamAsset.fork(stream_asset)
    local obj = lib.SkStreamAsset_fork(stream_asset)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.StreamAsset.hasPosition(stream_asset)
    return lib.SkStreamAsset_hasPosition(stream_asset)
end

function Skia.StreamAsset.getPosition(stream_asset)
    return lib.SkStreamAsset_getPosition(stream_asset)
end

function Skia.StreamAsset.seek(stream_asset, position)
    return lib.SkStreamAsset_seek(stream_asset, position)
end

function Skia.StreamAsset.move(stream_asset, offset)
    return lib.SkStreamAsset_move(stream_asset, offset)
end

function Skia.StreamAsset.rewind(stream_asset)
    return lib.SkStreamAsset_rewind(stream_asset)
end

function Skia.StreamAsset.read(stream_asset, buffer, size)
    return lib.SkStreamAsset_read(stream_asset, buffer, size)
end

function Skia.StreamAsset.skip(stream_asset, size)
    return lib.SkStreamAsset_skip(stream_asset, size)
end

function Skia.StreamAsset.peek(stream_asset, buffer, size)
    return lib.SkStreamAsset_peek(stream_asset, buffer, size)
end

function Skia.StreamAsset.isAtEnd(stream_asset)
    return lib.SkStreamAsset_isAtEnd(stream_asset)
end

function Skia.StreamAsset.readS8(stream_asset, i)
    return lib.SkStreamAsset_readS8(stream_asset, i)
end
 
function Skia.StreamAsset.readS16(stream_asset, i)
    return lib.SkStreamAsset_readS16(stream_asset, i)
end

function Skia.StreamAsset.readS32(stream_asset, i)
    return lib.SkStreamAsset_readS32(stream_asset, i)
end

function Skia.StreamAsset.readU8(stream_asset, i)
    return lib.SkStreamAsset_readU8(stream_asset, i)
end

function Skia.StreamAsset.readU16(stream_asset, i)
    return lib.SkStreamAsset_readU16(stream_asset, i)
end

function Skia.StreamAsset.readU32(stream_asset, i)
    return lib.SkStreamAsset_readU32(stream_asset, i)
end

function Skia.StreamAsset.readBool(stream_asset, b)
    return lib.SkStreamAsset_readBool(stream_asset, b)
end

function Skia.StreamAsset.readScalar(stream_asset, v)
    return lib.SkStreamAsset_readScalar(stream_asset, v)
end

function Skia.StreamAsset.readPackedUInt(stream_asset, size)
    return lib.SkStreamAsset_readPackedUInt(stream_asset, size)
end

function Skia.StreamAsset.getMemoryBase(stream_asset)
    return lib. SkStreamAsset_getMemoryBase(stream_asset)
end

function Skia.StreamAsset.MakeFromFile(path)
    local obj = lib.SkStreamAsset_MakeFromFile(path)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

-- ## sk_stream_memory
Skia.StreamMemory = {}

function Skia.StreamMemory.delete(stream_memory)
    lib.SkStreamMemory_delete(stream_memory)
end

function Skia.StreamMemory.getMemoryBase(stream_memory)
    return lib. SkStreamMemory_getMemoryBase(stream_memory)
end

function Skia.StreamMemory.duplicate(stream_memory)
    local obj = lib.SkStreamMemory_duplicate(stream_memory)
    setFinalizer(obj, lib.static_sk_stream_memory_delete)
    return obj
end

function Skia.StreamMemory.fork(stream_memory)
    local obj = lib.SkStreamMemory_fork(stream_memory)
    setFinalizer(obj, lib.static_sk_stream_memory_delete)
    return obj
end

function Skia.StreamMemory.hasLength(stream_memory)
    return lib.SkStreamMemory_hasLength(stream_memory)
end

function Skia.StreamMemory.getLength(stream_memory)
    return lib.SkStreamMemory_getLength(stream_memory)
end

function Skia.StreamMemory.hasPosition(stream_memory)
    return lib.SkStreamMemory_hasPosition(stream_memory)
end

function Skia.StreamMemory.getPosition(stream_memory)
    return lib.SkStreamMemory_getPosition(stream_memory)
end

function Skia.StreamMemory.seek(stream_memory, position)
    return lib.SkStreamMemory_seek(stream_memory, position)
end

function Skia.StreamMemory.move(stream_memory, offset)
    return lib.SkStreamMemory_move(stream_memory, offset)
end

function Skia.StreamMemory.rewind(stream_memory)
    return lib.SkStreamMemory_rewind(stream_memory)
end

function Skia.StreamMemory.read(stream_memory, buffer, size)
    return lib.SkStreamMemory_read(stream_memory, buffer, size)
end

function Skia.StreamMemory.skip(stream_memory, size)
    return lib.SkStreamMemory_skip(stream_memory, size)
end

function Skia.StreamMemory.peek(stream_memory, buffer, size)
    return lib.SkStreamMemory_peek(stream_memory, buffer, size)
end

function Skia.StreamMemory.isAtEnd(stream_memory)
    return lib.SkStreamMemory_isAtEnd(stream_memory)
end

function Skia.StreamMemory.readS8(stream_memory, i)
    return lib.SkStreamMemory_readS8(stream_memory, i)
end

function Skia.StreamMemory.readS16(stream_memory, i)
    return lib.SkStreamMemory_readS16(stream_memory, i)
end

function Skia.StreamMemory.readS32(stream_memory, i)
    return lib.SkStreamMemory_readS32(stream_memory, i)
end

function Skia.StreamMemory.readU8(stream_memory, i)
    return lib.SkStreamMemory_readU8(stream_memory, i)
end

function Skia.StreamMemory.readU16(stream_memory, i)
    return lib.SkStreamMemory_readU16(stream_memory, i)
end

function Skia.StreamMemory.readU32(stream_memory, i)
    return lib.SkStreamMemory_readU32(stream_memory, i)
end

function Skia.StreamMemory.readBool(stream_memory, b)
    return lib.SkStreamMemory_readBool(stream_memory, b)
end

function Skia.StreamMemory.readScalar(stream_memory, v)
    return lib.SkStreamMemory_readScalar(stream_memory, v)
end

function Skia.StreamMemory.readPackedUInt(stream_memory, size)
    return lib.SkStreamMemory_readPackedUInt(stream_memory, size)
end

function Skia.StreamMemory.MakeFromFile(path)
    local obj = lib.SkStreamMemory_MakeFromFile(path)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

-- ## sk_stream_rewindable
Skia.StreamRewindable = {}

function Skia.StreamRewindable.delete(stream_rewindable)
    lib.SkStreamRewindable_delete(stream_rewindable)
end

function Skia.StreamRewindable.rewind(stream_rewindable)
    return lib.SkStreamRewindable_rewind(stream_rewindable)
end

function Skia.StreamRewindable.duplicate(stream_rewindable)
    local obj = lib.SkStreamRewindable_duplicate(stream_rewindable)
    setFinalizer(obj, lib.static_sk_stream_rewindable_delete)
    return obj
end

function Skia.StreamRewindable.read(stream_rewindable, buffer, size)
    return lib.SkStreamRewindable_read(stream_rewindable, buffer, size)
end

function Skia.StreamRewindable.skip(stream_rewindable, size)
    return lib.SkStreamRewindable_skip(stream_rewindable, size)
end

function Skia.StreamRewindable.peek(stream_rewindable, buffer, size)
    return lib.SkStreamRewindable_peek(stream_rewindable, buffer, size)
end

function Skia.StreamRewindable.isAtEnd(stream_rewindable)
    return lib.SkStreamRewindable_isAtEnd(stream_rewindable)
end

function Skia.StreamRewindable.readS8(stream_rewindable, i)
    return lib.SkStreamRewindable_readS8(stream_rewindable, i)
end

function Skia.StreamRewindable.readS16(stream_rewindable, i)
    return lib.SkStreamRewindable_readS16(stream_rewindable, i)
end

function Skia.StreamRewindable.readS32(stream_rewindable, i)
    return lib.SkStreamRewindable_readS32(stream_rewindable, i)
end

function Skia.StreamRewindable.readU8(stream_rewindable, i)
    return lib.SkStreamRewindable_readU8(stream_rewindable, i)
end

function Skia.StreamRewindable.readU16(stream_rewindable, i)
    return lib.SkStreamRewindable_readU16(stream_rewindable, i)
end

function Skia.StreamRewindable.readU32(stream_rewindable, i)
    return lib.SkStreamRewindable_readU32(stream_rewindable, i)
end

function Skia.StreamRewindable.readBool(stream_rewindable, b)
    return lib.SkStreamRewindable_readBool(stream_rewindable, b)
end

function Skia.StreamRewindable.readScalar(stream_rewindable, v)
    return lib.SkStreamRewindable_readScalar(stream_rewindable, v)
end

function Skia.StreamRewindable.readPackedUInt(stream_rewindable, size)
    return lib.SkStreamRewindable_readPackedUInt(stream_rewindable, size)
end

function Skia.StreamRewindable.fork(stream_rewindable)
    local obj = lib.SkStreamRewindable_fork(stream_rewindable)
    setFinalizer(obj, lib.static_sk_stream_delete)
    return obj
end

function Skia.StreamRewindable.hasPosition(stream_rewindable)
    return lib.SkStreamRewindable_hasPosition(stream_rewindable)
end

function Skia.StreamRewindable.getPosition(stream_rewindable)
    return lib.SkStreamRewindable_getPosition(stream_rewindable)
end

function Skia.StreamRewindable.seek(stream_rewindable, size)
    return lib.SkStreamRewindable_seek(stream_rewindable, size)
end

function Skia.StreamRewindable.move(stream_rewindable, i)
    return lib.SkStreamRewindable_move(stream_rewindable, i)
end

function Skia.StreamRewindable.hasLength(stream_rewindable)
    return lib.SkStreamRewindable_hasLength(stream_rewindable)
end

function Skia.StreamRewindable.getLength(stream_rewindable)
    return lib.SkStreamRewindable_getLength(stream_rewindable)
end

function Skia.StreamRewindable.getMemoryBase(stream_rewindable)
    return lib. SkStreamRewindable_getMemoryBase(stream_rewindable)
end

function Skia.StreamRewindable.MakeFromFile(path)
    local obj = lib.SkStreamRewindable_MakeFromFile(path)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

-- ## sk_stream_seekable
Skia.StreamSeekable = {}

function Skia.StreamSeekable.delete(stream_seekable)
    lib.SkStreamSeekable_delete(stream_seekable)
end

function Skia.StreamSeekable.duplicate(stream_seekable)
    local obj = lib.SkStreamSeekable_duplicate(stream_seekable)
    setFinalizer(obj, lib.static_sk_stream_seekable_delete)
    return obj
end

function Skia.StreamSeekable.hasPosition(stream_seekable)
    return lib.SkStreamSeekable_hasPosition(stream_seekable)
end

function Skia.StreamSeekable.getPosition(stream_seekable)
    return lib.SkStreamSeekable_getPosition(stream_seekable)
end

function Skia.StreamSeekable.seek(stream_seekable, position)
    return lib.SkStreamSeekable_seek(stream_seekable, position)
end

function Skia.StreamSeekable.move(stream_seekable, offset)
    return lib.SkStreamSeekable_move(stream_seekable, offset)
end

function Skia.StreamSeekable.fork(stream_seekable)
    local obj = lib.SkStreamSeekable_fork(stream_seekable)
    setFinalizer(obj, lib.static_sk_stream_seekable_delete)
    return obj
end

function Skia.StreamSeekable.rewind(stream_seekable)
    return lib.SkStreamSeekable_rewind(stream_seekable)
end

function Skia.StreamSeekable.read(stream_seekable, buffer, size)
    return lib.SkStreamSeekable_read(stream_seekable, buffer, size)
end

function Skia.StreamSeekable.skip(stream_seekable, size)
    return lib.SkStreamSeekable_skip(stream_seekable, size)
end

function Skia.StreamSeekable.peek(stream_seekable, buffer, size)
    return lib.SkStreamSeekable_peek(stream_seekable, buffer, size)
end

function Skia.StreamSeekable.isAtEnd(stream_seekable)
    return lib.SkStreamSeekable_isAtEnd(stream_seekable)
end

function Skia.StreamSeekable.readS8(stream_seekable, i)
    return lib.SkStreamSeekable_readS8(stream_seekable, i)
end

function Skia.StreamSeekable.readS16(stream_seekable, i)
    return lib.SkStreamSeekable_readS16(stream_seekable, i)
end

function Skia.StreamSeekable.readS32(stream_seekable, i)
    return lib.SkStreamSeekable_readS32(stream_seekable, i)
end

function Skia.StreamSeekable.readU8(stream_seekable, i)
    return lib.SkStreamSeekable_readU8(stream_seekable, i)
end

function Skia.StreamSeekable.readU16(stream_seekable, i)
    return lib.SkStreamSeekable_readU16(stream_seekable, i)
end

function Skia.StreamSeekable.readU32(stream_seekable, i)
    return lib.SkStreamSeekable_readU32(stream_seekable, i)
end

function Skia.StreamSeekable.readBool(stream_seekable, b)
    return lib.SkStreamSeekable_readBool(stream_seekable, b)
end

function Skia.StreamSeekable.readScalar(stream_seekable, v)
    return lib.SkStreamSeekable_readScalar(stream_seekable, v)
end

function Skia.StreamSeekable.readPackedUInt(stream_seekable, size)
    return lib.SkStreamSeekable_readPackedUInt(stream_seekable, size)
end

function Skia.StreamSeekable.hasLength(stream_seekable)
    return lib.SkStreamSeekable_hasLength(stream_seekable)
end

function Skia.StreamSeekable.getLength(stream_seekable)
    return lib.SkStreamSeekable_getLength(stream_seekable)
end

function Skia.StreamSeekable.getMemoryBase(stream_seekable)
    return lib. SkStreamSeekable_getMemoryBase(stream_seekable)
end

function Skia.StreamSeekable.MakeFromFile(path)
    local obj = lib.SkStreamSeekable_MakeFromFile(path)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

-- ## sk_string
Skia.String = {}

function Skia.String.new()
    local obj = lib.SkString_new()
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_2(len)
    local obj = lib.SkString_new_2(len)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_3(text)
    local obj = lib.SkString_new_3(text)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_4(text, len)
    local obj = lib.SkString_new_4(text, len)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_5(str)
    local obj = lib.SkString_new_5(str)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_6(str)
    local obj = lib.SkString_new_6(str)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.new_7(view)
    local obj = lib.SkString_new_7(view)
    ffi.gc(obj, lib.SkString_delete)
    return obj
end

function Skia.String.delete(string)
    lib.SkString_delete(string)
end

function Skia.String.isEmpty(string)
    return lib.SkString_isEmpty(string)
end

function Skia.String.size(string)
    return lib.SkString_size(string)
end

function Skia.String.data(string)
    return lib. SkString_data(string)
end

function Skia.String.data_2(string)
    return lib. SkString_data_2(string)
end

function Skia.String.c_str(string)
    return lib. SkString_c_str(string)
end

function Skia.String.equals(string, str)
    return lib.SkString_equals(string, str)
end

function Skia.String.equals_2(string, text)
    return lib.SkString_equals_2(string, text)
end

function Skia.String.equals_3(string, text, len)
    return lib.SkString_equals_3(string, text, len)
end

function Skia.String.startsWith(string, prefixStr)
    return lib.SkString_startsWith(string, prefixStr)
end

function Skia.String.startsWith_2(string, prefixChar)
    return lib.SkString_startsWith_2(string, prefixChar)
end

function Skia.String.contains(string, substring)
    return lib.SkString_contains(string, substring)
end

function Skia.String.contains_2(string, subchar)
    return lib.SkString_contains_2(string, subchar)
end

function Skia.String.find(string, substring)
    return lib.SkString_find(string, substring)
end

function Skia.String.findLastOf(string, subchar)
    return lib.SkString_findLastOf(string, subchar)
end

function Skia.String.reset(string)
    lib.SkString_reset(string)
end

function Skia.String.resize(string, len)
    lib.SkString_resize(string, len)
end

function Skia.String.set(string, src)
    lib.SkString_set(string, src)
end

function Skia.String.set_2(string, text)
    lib.SkString_set_2(string, text)
end

function Skia.String.set_3(string, text, len)
    lib.SkString_set_3(string, text, len)
end

function Skia.String.set_4(string, str)
    lib.SkString_set_4(string, str)
end

function Skia.String.insert(string, offset, text)
    lib.SkString_insert(string, offset, text)
end

function Skia.String.insert_2(string, offset, text, len)
    lib.SkString_insert_2(string, offset, text, len)
end

function Skia.String.insert_3(string, offset, str)
    lib.SkString_insert_3(string, offset, str)
end

function Skia.String.insert_4(string, offset, str)
    lib.SkString_insert_4(string, offset, str)
end

function Skia.String.insertUnichar(string, offset, unichar)
    lib.SkString_insertUnichar(string, offset, unichar)
end

function Skia.String.insertS32(string, offset, value)
    lib.SkString_insertS32(string, offset, value)
end

function Skia.String.insertS64(string, offset, value, minDigits)
    lib.SkString_insertS64(string, offset, value, minDigits)
end

function Skia.String.insertU32(string, offset, value)
    lib.SkString_insertU32(string, offset, value)
end

function Skia.String.insertU64(string, offset, value, minDigits)
    lib.SkString_insertU64(string, offset, value, minDigits)
end

function Skia.String.insertHex(string, offset, value, minDigits)
    lib.SkString_insertHex(string, offset, value, minDigits)
end

function Skia.String.insertScalar(string, offset, v)
    lib.SkString_insertScalar(string, offset, v)
end

function Skia.String.append(string, text)
    lib.SkString_append(string, text)
end

function Skia.String.append_2(string, text, len)
    lib.SkString_append_2(string, text, len)
end

function Skia.String.append_3(string, str)
    lib.SkString_append_3(string, str)
end

function Skia.String.append_4(string, str)
    lib.SkString_append_4(string, str)
end

function Skia.String.appendUnichar(string, uni)
    lib.SkString_appendUnichar(string, uni)
end

function Skia.String.appendS32(string, value)
    lib.SkString_appendS32(string, value)
end

function Skia.String.appendS64(string, value, minDigits)
    lib.SkString_appendS64(string, value, minDigits)
end

function Skia.String.appendU32(string, value)
    lib.SkString_appendU32(string, value)
end

function Skia.String.appendU64(string, value, minDigits)
    lib.SkString_appendU64(string, value, minDigits)
end

function Skia.String.appendHex(string, value, minDigits)
    lib.SkString_appendHex(string, value, minDigits)
end

function Skia.String.appendScalar(string, value)
    lib.SkString_appendScalar(string, value)
end

function Skia.String.prepend(string, text)
    lib.SkString_prepend(string, text)
end

function Skia.String.prepend_2(string, text, len)
    lib.SkString_prepend_2(string, text, len)
end

function Skia.String.prepend_3(string, str)
    lib.SkString_prepend_3(string, str)
end

function Skia.String.prepend_4(string, str)
    lib.SkString_prepend_4(string, str)
end

function Skia.String.prependUnichar(string, uni)
    lib.SkString_prependUnichar(string, uni)
end

function Skia.String.prependS32(string, value)
    lib.SkString_prependS32(string, value)
end

function Skia.String.prependS64(string, value, minDigits)
    lib.SkString_prependS64(string, value, minDigits)
end

function Skia.String.prependHex(string, value, minDigits)
    lib.SkString_prependHex(string, value, minDigits)
end

function Skia.String.prependScalar(string, value)
    lib.SkString_prependScalar(string, value)
end

function Skia.String.remove(string, offset, length)
    lib.SkString_remove(string, offset, length)
end

function Skia.String.swap(string, other)
    lib.SkString_swap(string, other)
end

-- ## sk_stroke_rec
Skia.StrokeRec = {}

function Skia.StrokeRec.delete(stroke_rec)
    lib.SkStrokeRec_delete(stroke_rec)
end

function Skia.StrokeRec.static(style)
    local obj = lib.SkStrokeRec_static(style)
    setFinalizer(obj, lib.static_sk_stroke_rec_delete)
    return obj
end

function Skia.StrokeRec.static_2(paint, style, resScale)
    local obj = lib.SkStrokeRec_static_2(paint, style, resScale)
    setFinalizer(obj, lib.static_sk_stroke_rec_delete)
    return obj
end

function Skia.StrokeRec.static_3(paint, resScale)
    local obj = lib.SkStrokeRec_static_3(paint, resScale)
    setFinalizer(obj, lib.static_sk_stroke_rec_delete)
    return obj
end

function Skia.StrokeRec.getStyle(stroke_rec)
    return lib.SkStrokeRec_getStyle(stroke_rec)
end

function Skia.StrokeRec.getWidth(stroke_rec)
    return lib.SkStrokeRec_getWidth(stroke_rec)
end

function Skia.StrokeRec.getMiter(stroke_rec)
    return lib.SkStrokeRec_getMiter(stroke_rec)
end

function Skia.StrokeRec.getCap(stroke_rec)
    return lib.SkStrokeRec_getCap(stroke_rec)
end

function Skia.StrokeRec.getJoin(stroke_rec)
    return lib.SkStrokeRec_getJoin(stroke_rec)
end

function Skia.StrokeRec.isHairlineStyle(stroke_rec)
    return lib.SkStrokeRec_isHairlineStyle(stroke_rec)
end

function Skia.StrokeRec.isFillStyle(stroke_rec)
    return lib.SkStrokeRec_isFillStyle(stroke_rec)
end

function Skia.StrokeRec.setFillStyle(stroke_rec)
    lib.SkStrokeRec_setFillStyle(stroke_rec)
end

function Skia.StrokeRec.setHairlineStyle(stroke_rec)
    lib.SkStrokeRec_setHairlineStyle(stroke_rec)
end

function Skia.StrokeRec.setStrokeStyle(stroke_rec, width, strokeAndFill)
    lib.SkStrokeRec_setStrokeStyle(stroke_rec, width, strokeAndFill)
end

function Skia.StrokeRec.setStrokeParams(stroke_rec, cap, join, miterLimit)
    lib.SkStrokeRec_setStrokeParams(stroke_rec, cap, join, miterLimit)
end

function Skia.StrokeRec.getResScale(stroke_rec)
    return lib.SkStrokeRec_getResScale(stroke_rec)
end

function Skia.StrokeRec.setResScale(stroke_rec, rs)
    lib.SkStrokeRec_setResScale(stroke_rec, rs)
end

function Skia.StrokeRec.needToApply(stroke_rec)
    return lib.SkStrokeRec_needToApply(stroke_rec)
end

function Skia.StrokeRec.applyToPath(stroke_rec, dst, src)
    return lib.SkStrokeRec_applyToPath(stroke_rec, dst, src)
end

function Skia.StrokeRec.applyToPaint(stroke_rec, paint)
    lib.SkStrokeRec_applyToPaint(stroke_rec, paint)
end

function Skia.StrokeRec.getInflationRadius(stroke_rec)
    return lib.SkStrokeRec_getInflationRadius(stroke_rec)
end

function Skia.StrokeRec.hasEqualEffect(stroke_rec, other)
    return lib.SkStrokeRec_hasEqualEffect(stroke_rec, other)
end

function Skia.StrokeRec.GetInflationRadius(paint, style)
    return lib.SkStrokeRec_GetInflationRadius(paint, style)
end

function Skia.StrokeRec.GetInflationRadius_2(join, miterLimit, cap, strokeWidth)
    return lib.SkStrokeRec_GetInflationRadius_2(join, miterLimit, cap, strokeWidth)
end

-- ## sk_surface
Skia.Surface = {}

function Skia.Surface.delete(surface)
    lib.SkSurface_delete(surface)
end

function Skia.Surface.isCompatible(surface, characterization)
    return lib.SkSurface_isCompatible(surface, characterization)
end

function Skia.Surface.width(surface)
    return lib.SkSurface_width(surface)
end

function Skia.Surface.height(surface)
    return lib.SkSurface_height(surface)
end

function Skia.Surface.imageInfo(surface)
    local obj = lib.SkSurface_imageInfo(surface)
    setFinalizer(obj, lib.static_sk_image_info_delete)
    return obj
end

function Skia.Surface.generationID(surface)
    return lib.SkSurface_generationID(surface)
end

function Skia.Surface.notifyContentWillChange(surface, mode)
    lib.SkSurface_notifyContentWillChange(surface, mode)
end

function Skia.Surface.recordingContext(surface)
    return lib. SkSurface_recordingContext(surface)
end

function Skia.Surface.recorder(surface)
    return lib. SkSurface_recorder(surface)
end

function Skia.Surface.replaceBackendTexture(surface, backendTexture, origin, mode, proc, context)
    return lib.SkSurface_replaceBackendTexture(surface, backendTexture, origin, mode, proc, context)
end

function Skia.Surface.getCanvas(surface)
    return lib. SkSurface_getCanvas(surface)
end

function Skia.Surface.capabilities(surface)
    local obj = lib.SkSurface_capabilities(surface)
    setFinalizer(obj, lib.static_const_sk_capabilities_delete)
    return obj
end

function Skia.Surface.makeSurface(surface, imageInfo)
    local obj = lib.SkSurface_makeSurface(surface, imageInfo)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surface.makeSurface_2(surface, width, height)
    local obj = lib.SkSurface_makeSurface_2(surface, width, height)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surface.makeImageSnapshot(surface)
    local obj = lib.SkSurface_makeImageSnapshot(surface)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Surface.makeImageSnapshot_2(surface, bounds)
    local obj = lib.SkSurface_makeImageSnapshot_2(surface, bounds)
    setFinalizer(obj, lib.static_sk_image_delete)
    return obj
end

function Skia.Surface.draw(surface, canvas, x, y, sampling, paint)
    lib.SkSurface_draw(surface, canvas, x, y, sampling, paint)
end

function Skia.Surface.draw_2(surface, canvas, x, y, paint)
    lib.SkSurface_draw_2(surface, canvas, x, y, paint)
end

function Skia.Surface.peekPixels(surface, pixmap)
    return lib.SkSurface_peekPixels(surface, pixmap)
end

function Skia.Surface.readPixels(surface, dst, srcX, srcY)
    return lib.SkSurface_readPixels(surface, dst, srcX, srcY)
end

function Skia.Surface.readPixels_2(surface, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
    return lib.SkSurface_readPixels_2(surface, dstInfo, dstPixels, dstRowBytes, srcX, srcY)
end

function Skia.Surface.readPixels_3(surface, dst, srcX, srcY)
    return lib.SkSurface_readPixels_3(surface, dst, srcX, srcY)
end

--void SkSurface_asyncRescaleAndReadPixels(surface, info, srcRect, rescaleGamma, rescaleMode, SkSurface::ReadPixelsCallback callback, context)
--void SkSurface_asyncRescaleAndReadPixelsYUV420(surface, sk_color_space_t dstColorSpace, yuvColorSpace, srcRect, dstSize, rescaleGamma, rescaleMode, SkSurface::ReadPixelsCallback callback, context)
--void SkSurface_asyncRescaleAndReadPixelsYUVA420(surface, sk_color_space_t dstColorSpace, yuvColorSpace, srcRect, dstSize, rescaleGamma, rescaleMode, SkSurface::ReadPixelsCallback callback, context)
function Skia.Surface.writePixels(surface, src, dstX, dstY)
    lib.SkSurface_writePixels(surface, src, dstX, dstY)
end

function Skia.Surface.writePixels_2(surface, src, dstX, dstY)
    lib.SkSurface_writePixels_2(surface, src, dstX, dstY)
end

function Skia.Surface.props(surface)
    return lib. SkSurface_props(surface)
end

function Skia.Surface.wait(surface, numSemaphores, waitSemaphores, deleteSemaphoresAfterWait)
    return lib.SkSurface_wait(surface, numSemaphores, waitSemaphores, deleteSemaphoresAfterWait)
end

function Skia.Surface.characterize(surface, characterization)
    return lib.SkSurface_characterize(surface, characterization)
end

function Skia.Surface.unique(surface)
    return lib.SkSurface_unique(surface)
end

function Skia.Surface.ref(surface)
    lib.SkSurface_ref(surface)
end

function Skia.Surface.unref(surface)
    lib.SkSurface_unref(surface)
end

-- ## sk_surface_props
Skia.SurfaceProps = {}

function Skia.SurfaceProps.new()
    local obj = lib.SkSurfaceProps_new()
    ffi.gc(obj, lib.SkSurfaceProps_delete)
    return obj
end

function Skia.SurfaceProps.new_2(flags, geometry)
    local obj = lib.SkSurfaceProps_new_2(flags, geometry)
    ffi.gc(obj, lib.SkSurfaceProps_delete)
    return obj
end

function Skia.SurfaceProps.new_3(props)
    local obj = lib.SkSurfaceProps_new_3(props)
    ffi.gc(obj, lib.SkSurfaceProps_delete)
    return obj
end

function Skia.SurfaceProps.delete(surface_props)
    lib.SkSurfaceProps_delete(surface_props)
end

function Skia.SurfaceProps.cloneWithPixelGeometry(surface_props, newPixelGeometry)
    local obj = lib.SkSurfaceProps_cloneWithPixelGeometry(surface_props, newPixelGeometry)
    setFinalizer(obj, lib.static_sk_surface_props_delete)
    return obj
end

function Skia.SurfaceProps.flags(surface_props)
    return lib.SkSurfaceProps_flags(surface_props)
end

function Skia.SurfaceProps.pixelGeometry(surface_props)
    return lib.SkSurfaceProps_pixelGeometry(surface_props)
end

function Skia.SurfaceProps.isUseDeviceIndependentFonts(surface_props)
    return lib.SkSurfaceProps_isUseDeviceIndependentFonts(surface_props)
end

function Skia.SurfaceProps.isAlwaysDither(surface_props)
    return lib.SkSurfaceProps_isAlwaysDither(surface_props)
end

-- ## sk_surfaces
Skia.Surfaces = {}

function Skia.Surfaces.Null(width, height)
    local obj = lib.SkSurfaces_Null(width, height)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surfaces.Raster(imageInfo, rowBytes, surfaceProps)
    local obj = lib.SkSurfaces_Raster(imageInfo, rowBytes, surfaceProps)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surfaces.Raster_2(imageInfo, props)
    local obj = lib.SkSurfaces_Raster_2(imageInfo, props)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surfaces.WrapPixels(imageInfo, pixels, rowBytes, surfaceProps)
    local obj = lib.SkSurfaces_WrapPixels(imageInfo, pixels, rowBytes, surfaceProps)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surfaces.WrapPixels_2(pm, props)
    local obj = lib.SkSurfaces_WrapPixels_2(pm, props)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

function Skia.Surfaces.WrapPixels_3(imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps)
    local obj = lib.SkSurfaces_WrapPixels_3(imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps)
    setFinalizer(obj, lib.static_sk_surface_delete)
    return obj
end

-- ## sk_svg_attribute_parser
Skia.SVGAttributeParser = {}

-- ## sk_svg_circle
Skia.SVGCircle = {}

-- ## sk_svg_clip_path
Skia.SVGClipPath = {}

-- ## sk_svg_color
Skia.SVGColor = {}

-- ## sk_svg_container
Skia.SVGContainer = {}

-- ## sk_svg_dash_array
Skia.SVGDashArray = {}

-- ## sk_svg_defs
Skia.SVGDefs = {}

-- ## sk_svg_dom
Skia.SVGDOM = {}

-- ## sk_svg_ellipse
Skia.SVGEllipse = {}

-- ## sk_svg_fe
Skia.SVGFe = {}

-- ## sk_svg_fe_blend
Skia.SVGFeBlend = {}

-- ## sk_svg_fe_color_matrix
Skia.SVGFeColorMatrix = {}

-- ## sk_svg_fe_composite
Skia.SVGFeComposite = {}

-- ## sk_svg_fe_diffuse_lighting
Skia.SVGFeDiffuseLighting = {}

-- ## sk_svg_fe_displacement_map
Skia.SVGFeDisplacementMap = {}

-- ## sk_svg_fe_distant_light
Skia.SVGFeDistantLight = {}

-- ## sk_svg_fe_flood
Skia.SVGFeFlood = {}

-- ## sk_svg_fe_gaussian_blur
Skia.SVGFeGaussianBlur = {}

-- ## sk_svg_fe_image
Skia.SVGFeImage = {}

-- ## sk_svg_fe_input_type
Skia.SVGFeInputType = {}

-- ## sk_svg_fe_light_source
Skia.SVGFeLightSource = {}

-- ## sk_svg_fe_lighting
Skia.SVGFeLighting = {}

-- ## sk_svg_fe_morphology
Skia.SVGFeMorphology = {}

-- ## sk_svg_fe_offset
Skia.SVGFeOffset = {}

-- ## sk_svg_fe_point_light
Skia.SVGFePointLight = {}

-- ## sk_svg_fe_specular_lighting
Skia.SVGFeSpecularLighting = {}

-- ## sk_svg_fe_spot_light
Skia.SVGFeSpotLight = {}

-- ## sk_svg_fe_turbulence
Skia.SVGFeTurbulence = {}

-- ## sk_svg_fe_turbulence_base_frequency
Skia.SVGFeTurbulenceBaseFrequency = {}

-- ## sk_svg_fe_turbulence_type
Skia.SVGFeTurbulenceType = {}

-- ## sk_svg_fill_rule
Skia.SVGFillRule = {}

-- ## sk_svg_filter
Skia.SVGFilter = {}

-- ## sk_svg_filter_context
Skia.SVGFilterContext = {}

-- ## sk_svg_font_family
Skia.SVGFontFamily = {}

-- ## sk_svg_font_size
Skia.SVGFontSize = {}

-- ## sk_svg_font_style
Skia.SVGFontStyle = {}

-- ## sk_svg_font_weight
Skia.SVGFontWeight = {}

-- ## sk_svg_func_iri
Skia.SVGFuncIRI = {}

-- ## sk_svg_g
Skia.SVGG = {}

-- ## sk_svg_gradient
Skia.SVGGradient = {}

-- ## sk_svg_hidden_container
Skia.SVGHiddenContainer = {}

-- ## sk_svg_image
Skia.SVGImage = {}

-- ## sk_svg_iri
Skia.SVGIRI = {}

-- ## sk_svg_length
Skia.SVGlength = {}

-- ## sk_svg_length_context
Skia.SVGLengthContext = {}

-- ## sk_svg_line
Skia.SVGLine = {}

-- ## sk_svg_line_join
Skia.SVGLineJoin = {}

-- ## sk_svg_linear_gradient
Skia.SVGLinearGradient = {}

-- ## sk_svg_mask
Skia.SVGMask = {}

-- ## sk_svg_node
Skia.SVGNode = {}

-- ## sk_svg_object_bounding_box_units
Skia.SVGObjectBoundingBoxUnits = {}

-- ## sk_svg_open_type_svg_decoder
Skia.SVGOpenTypeSVGDecoder = {}

-- ## sk_svg_paint
Skia.SVGPaint = {}

-- ## sk_svg_path
Skia.SVGPath = {}

-- ## sk_svg_pattern
Skia.SVGPattern = {}

-- ## sk_svg_poly
Skia.SVGPoly = {}

-- ## sk_svg_presentation_attributes
Skia.SVGPresentationAttributes = {}

-- ## sk_svg_presentation_context
Skia.SVGPresentationContext = {}

-- ## sk_svg_property
Skia.SVGProperty = {}

-- ## sk_svg_radial_gradient
Skia.SVGRadialGradient = {}

-- ## sk_svg_rect
Skia.SVGRect = {}

-- ## sk_svg_render_context
Skia.SVGRenderContext = {}

-- ## sk_svg_shape
Skia.SVGShape = {}

-- ## sk_svg_spread_method
Skia.SVGSpreadMethod = {}

-- ## sk_svg_stop
Skia.SVGStop = {}

-- ## sk_svg_stop_color
Skia.SVGStopColor = {}

-- ## sk_svg_svg
Skia.SVGSVG = {}

-- ## sk_svg_t_span
Skia.SVGTSpan = {}

-- ## sk_svg_text
Skia.SVGText = {}

-- ## sk_svg_text_anchor
Skia.SVGTextAnchor = {}

-- ## sk_svg_text_container
Skia.SVGTextContainer = {}

-- ## sk_svg_text_fragment
Skia.SVGTextFragment = {}

-- ## sk_svg_text_literal
Skia.SVGTextLiteral = {}

-- ## sk_svg_text_path
Skia.SVGTextPath = {}

-- ## sk_svg_transformable_node
Skia.SVGTransformableNode = {}

-- ## sk_svg_use
Skia.SVGUse = {}

-- ## sk_svg_value
Skia.SVGValue= {}

-- ## sk_svg_visibility
Skia.SVGVisibility = {}

-- ## sk_svg_wrapper_value
Skia.SVGWrapperValue = {}

-- ## sk_table_mask_filter
Skia.TableMaskFilter = {}

function Skia.TableMaskFilter.delete(tableMaskFilter)
    lib.SkTableMaskFilter_delete(tableMaskFilter)
end

function Skia.TableMaskFilter.MakeGammaTable(table, gamma)
    lib.SkTableMaskFilter_MakeGammaTable(table, gamma)
end

function Skia.TableMaskFilter.MakeClipTable(table, min, max)
    lib.SkTableMaskFilter_MakeClipTable(table, min, max)
end

function Skia.TableMaskFilter.Create(table)
    return lib.SkTableMaskFilter_Create(table)
end

function Skia.TableMaskFilter.CreateGamma(gamma)
    return lib.SkTableMaskFilter_CreateGamma(gamma)
end

function Skia.TableMaskFilter.CreateClip(min, max)
    return lib.SkTableMaskFilter_CreateClip(min, max)
end

-- ## sk_text_blob
Skia.TextBlob = {}

function Skia.TextBlob.delete(text_blob)
    lib.SkTextBlob_delete(text_blob)
end

function Skia.TextBlob.bounds(text_blob)
    return lib. SkTextBlob_bounds(text_blob)
end

function Skia.TextBlob.uniqueID(text_blob)
    return lib.SkTextBlob_uniqueID(text_blob)
end

function Skia.TextBlob.getIntercepts(text_blob, bounds, intervals, paint)
    return lib.SkTextBlob_getIntercepts(text_blob, bounds, intervals, paint)
end

function Skia.TextBlob.serialize(text_blob, procs, memory, memory_size)
    return lib.SkTextBlob_serialize(text_blob, procs, memory, memory_size)
end

function Skia.TextBlob.serialize_2(text_blob, procs)
    local obj = lib.SkTextBlob_serialize_2(text_blob, procs)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.TextBlob.unique(text_blob)
    return lib.SkTextBlob_unique(text_blob)
end

function Skia.TextBlob.ref(text_blob)
    lib.SkTextBlob_ref(text_blob)
end

function Skia.TextBlob.unref(text_blob)
    lib.SkTextBlob_unref(text_blob)
end

function Skia.TextBlob.deref(text_blob)
    lib.SkTextBlob_deref(text_blob)
end

function Skia.TextBlob.refCntGreaterThan(text_blob, threadIsolatedTestCnt)
    return lib.SkTextBlob_refCntGreaterThan(text_blob, threadIsolatedTestCnt)
end

function Skia.TextBlob.MakeFromText(text, byteLength, font, encoding)
    local obj = lib.SkTextBlob_MakeFromText(text, byteLength, font, encoding)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlob.MakeFromString(string, font, encoding)
    local obj = lib.SkTextBlob_MakeFromString(string, font, encoding)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlob.MakeFromPosTextH(text, byteLength, xpos, constY, font, encoding)
    local obj = lib.SkTextBlob_MakeFromPosTextH(text, byteLength, xpos, constY, font, encoding)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlob.MakeFromPosText(text, byteLength, pos, font, encoding)
    local obj = lib.SkTextBlob_MakeFromPosText(text, byteLength, pos, font, encoding)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlob.MakeFromRSXform(text, byteLength, xform, font, encoding)
    local obj = lib.SkTextBlob_MakeFromRSXform(text, byteLength, xform, font, encoding)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlob.Deserialize(data, size, procs)
    local obj = lib.SkTextBlob_Deserialize(data, size, procs)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

-- ## sk_text_blob_builder
Skia.TextBlobBuilder = {}

function Skia.TextBlobBuilder.new()
    local obj = lib.SkTextBlobBuilder_new()
    ffi.gc(obj, lib.SkTextBlobBuilder_delete)
    return obj
end

function Skia.TextBlobBuilder.delete(text_blob_builder)
    lib.SkTextBlobBuilder_delete(text_blob_builder)
end

function Skia.TextBlobBuilder.make(text_blob_builder)
    local obj = lib.SkTextBlobBuilder_make(text_blob_builder)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlobBuilder.allocRun(text_blob_builder, font, count, x, y, bounds)
    return lib. SkTextBlobBuilder_allocRun(text_blob_builder, font, count, x, y, bounds)
end

function Skia.TextBlobBuilder.allocRunPosH(text_blob_builder, font, count, y, bounds)
    return lib. SkTextBlobBuilder_allocRunPosH(text_blob_builder, font, count, y, bounds)
end

function Skia.TextBlobBuilder.allocRunPos(text_blob_builder, font, count, bounds)
    return lib. SkTextBlobBuilder_allocRunPos(text_blob_builder, font, count, bounds)
end

function Skia.TextBlobBuilder.allocRunRSXform(text_blob_builder, font, count)
    return lib. SkTextBlobBuilder_allocRunRSXform(text_blob_builder, font, count)
end

function Skia.TextBlobBuilder.allocRunText(text_blob_builder, font, count, x, y, textByteCount, bounds)
    return lib. SkTextBlobBuilder_allocRunText(text_blob_builder, font, count, x, y, textByteCount, bounds)
end

function Skia.TextBlobBuilder.allocRunTextPosH(text_blob_builder, font, count, y, textByteCount, bounds)
    return lib. SkTextBlobBuilder_allocRunTextPosH(text_blob_builder, font, count, y, textByteCount, bounds)
end

function Skia.TextBlobBuilder.allocRunTextPos(text_blob_builder, font, count, textByteCount, bounds)
    return lib. SkTextBlobBuilder_allocRunTextPos(text_blob_builder, font, count, textByteCount, bounds)
end

function Skia.TextBlobBuilder.allocRunTextRSXform(text_blob_builder, font, count, textByteCount, bounds)
    return lib. SkTextBlobBuilder_allocRunTextRSXform(text_blob_builder, font, count, textByteCount, bounds)
end

--[[
-- ## sk_text_blob_builder_run_handler
Skia.TextBlobBuilderRunHandler = {}

function Skia.TextBlobBuilderRunHandler.new(utf8Text, offset)
    local obj = lib.SkTextBlobBuilderRunHandler_new(utf8Text, offset)
    ffi.gc(obj, lib.SkTextBlobBuilderRunHandler_delete)
    return obj
end

function Skia.TextBlobBuilderRunHandler.delete(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_delete(text_blob_builder_run_handler)
end

function Skia.TextBlobBuilderRunHandler.makeBlob(text_blob_builder_run_handler)
    local obj = lib.SkTextBlobBuilderRunHandler_makeBlob(text_blob_builder_run_handler)
    setFinalizer(obj, lib.static_sk_text_blob_delete)
    return obj
end

function Skia.TextBlobBuilderRunHandler.endPoint(text_blob_builder_run_handler)
    local obj = lib.SkTextBlobBuilderRunHandler_endPoint(text_blob_builder_run_handler)
    setFinalizer(obj, lib.static_sk_point_delete)
    return obj
end

function Skia.TextBlobBuilderRunHandler.beginLine(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_beginLine(text_blob_builder_run_handler)
end

function Skia.TextBlobBuilderRunHandler.runInfo(text_blob_builder_run_handler, run_info)
    lib.SkTextBlobBuilderRunHandler_runInfo(text_blob_builder_run_handler, run_info)
end

function Skia.TextBlobBuilderRunHandler.commitRunInfo(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_commitRunInfo(text_blob_builder_run_handler)
end

function Skia.TextBlobBuilderRunHandler.runBuffer(text_blob_builder_run_handler, run_info)
    local obj = lib.SkTextBlobBuilderRunHandler_runBuffer(text_blob_builder_run_handler, run_info)
    setFinalizer(obj, lib.static_sk_shaper_run_handler_buffer_delete)
    return obj
end

function Skia.TextBlobBuilderRunHandler.commitRunBuffer(text_blob_builder_run_handler, run_info)
    lib.SkTextBlobBuilderRunHandler_commitRunBuffer(text_blob_builder_run_handler, run_info)
end

function Skia.TextBlobBuilderRunHandler.commitLine(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_commitLine(text_blob_builder_run_handler)
end
]]

-- ## sk_tiled_image_utils
Skia.TiledImageUtils = {}

function Skia.TiledImageUtils.DrawImageRect(canvas, image, src, dst, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImageRect(canvas, image, src, dst, sampling, paint, constraint)
end

function Skia.TiledImageUtils.DrawImageRect_2(canvas, image, src, dst, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImageRect_2(canvas, image, src, dst, sampling, paint, constraint)
end

function Skia.TiledImageUtils.DrawImageRect_3(canvas, image, dst, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImageRect_3(canvas, image, dst, sampling, paint, constraint)
end

function Skia.TiledImageUtils.DrawImageRect_4(canvas, image, dst, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImageRect_4(canvas, image, dst, sampling, paint, constraint)
end

function Skia.TiledImageUtils.DrawImage(canvas, image, x, y, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImage(canvas, image, x, y, sampling, paint, constraint)
end

function Skia.TiledImageUtils.DrawImage_2(canvas, image, x, y, sampling, paint, constraint)
    lib.SkTiledImageUtils_DrawImage_2(canvas, image, x, y, sampling, paint, constraint)
end

function Skia.TiledImageUtils.GetImageKeyValues(image, keyValues)
    lib.SkTiledImageUtils_GetImageKeyValues(image, keyValues)
end

-- ## sk_trace_memory_dump
Skia.TraceMemoryDump = {}

function Skia.TraceMemoryDump.delete(traceMemoryDump)
    lib.SkTraceMemoryDump_delete(traceMemoryDump)
end

function Skia.TraceMemoryDump.dumpNumericValue(trace_memory_dump, dumpName, valueName, units, value)
    lib.SkTraceMemoryDump_dumpNumericValue(trace_memory_dump, dumpName, valueName, units, value)
end

function Skia.TraceMemoryDump.dumpStringValue(trace_memory_dump, dumpName, str1, str2)
    lib.SkTraceMemoryDump_dumpStringValue(trace_memory_dump, dumpName, str1, str2)
end

function Skia.TraceMemoryDump.setMemoryBacking(trace_memory_dump, dumpName, backingType, backingObjectId)
    lib.SkTraceMemoryDump_setMemoryBacking(trace_memory_dump, dumpName, backingType, backingObjectId)
end

function Skia.TraceMemoryDump.setDiscardableMemoryBacking(trace_memory_dump, dumpName, discardableMemoryObject)
    lib.SkTraceMemoryDump_setDiscardableMemoryBacking(trace_memory_dump, dumpName, discardableMemoryObject)
end

function Skia.TraceMemoryDump.getRequestedDetails(trace_memory_dump)
    return lib.SkTraceMemoryDump_getRequestedDetails(trace_memory_dump)
end

function Skia.TraceMemoryDump.shouldDumpWrappedObjects(trace_memory_dump)
    return lib.SkTraceMemoryDump_shouldDumpWrappedObjects(trace_memory_dump)
end

function Skia.TraceMemoryDump.dumpWrappedState(trace_memory_dump, str, b)
    lib.SkTraceMemoryDump_dumpWrappedState(trace_memory_dump, str, b)
end

function Skia.TraceMemoryDump.shouldDumpUnbudgetedObjects(trace_memory_dump)
    return lib.SkTraceMemoryDump_shouldDumpUnbudgetedObjects(trace_memory_dump)
end

function Skia.TraceMemoryDump.dumpBudgetedState(trace_memory_dump, str, b)
    lib.SkTraceMemoryDump_dumpBudgetedState(trace_memory_dump, str, b)
end

-- ## sk_trim_path_effect
Skia.TrimPathEffect = {}

function Skia.TrimPathEffect.delete(trimPathEffect)
    lib.SkTrimPathEffect_delete(trimPathEffect)
end

function Skia.TrimPathEffect.Make(startT, stopT, mode)
    local obj = lib.SkTrimPathEffect_Make(startT, stopT, mode)
    setFinalizer(obj, lib.static_sk_path_effect_delete)
    return obj
end

-- ## sk_typeface
Skia.Typeface = {}

function Skia.Typeface.delete(typeface)
    lib.SkTypeface_delete(typeface)
end

function Skia.Typeface.fontStyle(typeface)
    local obj = lib.SkTypeface_fontStyle(typeface)
    setFinalizer(obj, lib.static_sk_font_style_delete)
    return obj
end

function Skia.Typeface.isBold(typeface)
    return lib.SkTypeface_isBold(typeface)
end

function Skia.Typeface.isItalic(typeface)
    return lib.SkTypeface_isItalic(typeface)
end

function Skia.Typeface.isFixedPitch(typeface)
    return lib.SkTypeface_isFixedPitch(typeface)
end

function Skia.Typeface.getVariationDesignPosition(typeface, coordinates, coordinateCount)
    return lib.SkTypeface_getVariationDesignPosition(typeface, coordinates, coordinateCount)
end

function Skia.Typeface.getVariationDesignParameters(typeface, parameters, parameterCount)
    return lib.SkTypeface_getVariationDesignParameters(typeface, parameters, parameterCount)
end

function Skia.Typeface.uniqueID(typeface)
    return lib.SkTypeface_uniqueID(typeface)
end

function Skia.Typeface.makeClone(typeface, arguments)
    local obj = lib.SkTypeface_makeClone(typeface, arguments)
    setFinalizer(obj, lib.static_sk_font_style_delete)
    return obj
end

function Skia.Typeface.serialize(typeface, stream, behavior)
    lib.SkTypeface_serialize(typeface, stream, behavior)
end

function Skia.Typeface.serialize_2(typeface, behavior)
    local obj = lib.SkTypeface_serialize_2(typeface, behavior)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Typeface.unicharsToGlyphs(typeface, uni, count, glyphs)
    lib.SkTypeface_unicharsToGlyphs(typeface, uni, count, glyphs)
end

function Skia.Typeface.textToGlyphs(typeface, text, byteLength, encoding, glyphs, maxGlyphCount)
    return lib.SkTypeface_textToGlyphs(typeface, text, byteLength, encoding, glyphs, maxGlyphCount)
end

function Skia.Typeface.unicharToGlyph(typeface, unichar)
    return lib.SkTypeface_unicharToGlyph(typeface, unichar)
end

function Skia.Typeface.countGlyphs(typeface)
    return lib.SkTypeface_countGlyphs(typeface)
end

function Skia.Typeface.countTables(typeface)
    return lib.SkTypeface_countTables(typeface)
end

function Skia.Typeface.getTableTags(typeface, tags)
    return lib.SkTypeface_getTableTags(typeface, tags)
end

function Skia.Typeface.getTableSize(typeface, tag)
    return lib.SkTypeface_getTableSize(typeface, tag)
end

function Skia.Typeface.getTableData(typeface, tag, offset, length, data)
    return lib.SkTypeface_getTableData(typeface, tag, offset, length, data)
end

function Skia.Typeface.copyTableData(typeface, tag)
    local obj = lib.SkTypeface_copyTableData(typeface, tag)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.Typeface.getUnitsPerEm(typeface)
    return lib.SkTypeface_getUnitsPerEm(typeface)
end

function Skia.Typeface.getKerningPairAdjustments(typeface, glyphs, count, adjustments)
    return lib.SkTypeface_getKerningPairAdjustments(typeface, glyphs, count, adjustments)
end

function Skia.Typeface.createFamilyNameIterator(typeface)
    return lib. SkTypeface_createFamilyNameIterator(typeface)
end

function Skia.Typeface.getFamilyName(typeface, name)
    lib.SkTypeface_getFamilyName(typeface, name)
end

function Skia.Typeface.getPostScriptName(typeface, name)
    return lib.SkTypeface_getPostScriptName(typeface, name)
end

function Skia.Typeface.openStream(typeface, ttcIndex)
    local obj = lib.SkTypeface_openStream(typeface, ttcIndex)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

function Skia.Typeface.openExistingStream(typeface, ttcIndex)
    local obj = lib.SkTypeface_openExistingStream(typeface, ttcIndex)
    setFinalizer(obj, lib.static_sk_stream_asset_delete)
    return obj
end

--std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface typeface, SkScalerContextEffects &effects, SkDescriptor descriptor)

function Skia.Typeface.getBounds(typeface)
    local obj = lib.SkTypeface_getBounds(typeface)
    setFinalizer(obj, lib.static_sk_rect_delete)
    return obj
end

function Skia.Typeface.filterRec(typeface, rec)
    lib.SkTypeface_filterRec(typeface, rec)
end

function Skia.Typeface.getFontDescriptor(typeface, desc, isLocal)
    lib.SkTypeface_getFontDescriptor(typeface, desc, isLocal)
end

function Skia.Typeface.internal_private_getCTFontRef(typeface)
    return lib. SkTypeface_internal_private_getCTFontRef(typeface)
end

function Skia.Typeface.Equal(facea, faceb)
    return lib.SkTypeface_Equal(facea, faceb)
end

function Skia.Typeface.MakeEmpty()
    local obj = lib.SkTypeface_MakeEmpty()
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeDeserialize(stream, font_mgr)
    local obj = lib.SkTypeface_MakeDeserialize(stream, font_mgr)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

--void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(make)(std::unique_ptr<SkStreamAsset>, SkFontArguments &))

function Skia.Typeface.MakeDefault()
    local obj = lib.SkTypeface_MakeDefault()
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeFromName(familyName, fontStyle)
    local obj = lib.SkTypeface_MakeFromName(familyName, fontStyle)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeFromFile(path, index)
    local obj = lib.SkTypeface_MakeFromFile(path, index)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeFromStream(stream_asset, index)
    local obj = lib.SkTypeface_MakeFromStream(stream_asset, index)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeFromData(data, index)
    local obj = lib.SkTypeface_MakeFromData(data, index)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

function Skia.Typeface.MakeDeserialize_2(stream)
    local obj = lib.SkTypeface_MakeDeserialize_2(stream)
    setFinalizer(obj, lib.static_sk_typeface_delete)
    return obj
end

-- ## sk_typeface_mac
Skia.TypefaceMac = {}

-- ## sk_un_pre_multiply
Skia.UnPreMultiply = {}

function Skia.UnPreMultiply.delete(unPreMultiply)
    lib.SkUnPreMultiply_delete(unPreMultiply)
end

function Skia.UnPreMultiply.GetScaleTable()
    return lib. SkUnPreMultiply_GetScaleTable()
end

function Skia.UnPreMultiply.GetScale(alpha)
    return lib.SkUnPreMultiply_GetScale(alpha)
end

function Skia.UnPreMultiply.ApplyScale(scale, component)
    return lib.SkUnPreMultiply_ApplyScale(scale, component)
end

function Skia.UnPreMultiply.PMColorToColor(c)
    return lib.SkUnPreMultiply_PMColorToColor(c)
end

-- ## sk_v2
Skia.V2 = {}

function Skia.V2.delete(v2)
    lib.SkV2_delete(v2)
end

function Skia.V2.lengthSquared(v2)
    return lib.SkV2_lengthSquared(v2)
end

function Skia.V2.length(v2)
    return lib.SkV2_length(v2)
end

function Skia.V2.dot(v2, v)
    return lib.SkV2_dot(v2, v)
end

function Skia.V2.cross(v2, v)
    return lib.SkV2_cross(v2, v)
end

function Skia.V2.normalize(v2)
    local obj = lib.SkV2_normalize(v2)
    setFinalizer(obj, lib.static_sk_v2_delete)
    return obj
end

function Skia.V2.ptr(v2)
    return lib. SkV2_ptr(v2)
end

function Skia.V2.ptr_2(v2)
    return lib. SkV2_ptr_2(v2)
end

function Skia.V2.Dot(a, b)
    return lib.SkV2_Dot(a, b)
end

function Skia.V2.Cross(a, b)
    return lib.SkV2_Cross(a, b)
end

function Skia.V2.Normalize(v)
    local obj = lib.SkV2_Normalize(v)
    setFinalizer(obj, lib.static_sk_v2_delete)
    return obj
end

-- ## sk_v3
Skia.V3 = {}

function Skia.V3.delete(v3)
    lib.SkV3_delete(v3)
end

function Skia.V3.lengthSquared(v3)
    return lib.SkV3_lengthSquared(v3)
end

function Skia.V3.length(v3)
    return lib.SkV3_length(v3)
end

function Skia.V3.dot(v3, v)
    return lib.SkV3_dot(v3, v)
end

function Skia.V3.cross(v3, v)
    local obj = lib.SkV3_cross(v3, v)
    setFinalizer(obj, lib.static_sk_v3_delete)
    return obj
end

function Skia.V3.normalize(v3)
    local obj = lib.SkV3_normalize(v3)
    setFinalizer(obj, lib.static_sk_v3_delete)
    return obj
end

function Skia.V3.ptr(v3)
    return lib. SkV3_ptr(v3)
end

function Skia.V3.ptr_2(v3)
    return lib. SkV3_ptr_2(v3)
end

function Skia.V3.Dot(a, b)
    return lib.SkV3_Dot(a, b)
end

function Skia.V3.Cross(a, b)
    local obj = lib.SkV3_Cross(a, b)
    setFinalizer(obj, lib.static_sk_v3_delete)
    return obj
end

function Skia.V3.Normalize(v)
    local obj = lib.SkV3_Normalize(v)
    setFinalizer(obj, lib.static_sk_v3_delete)
    return obj
end

-- ## sk_v4
Skia.V4 = {}

function Skia.V4.delete(v4)
    lib.SkV4_delete(v4)
end

function Skia.V4.lengthSquared(v4)
    return lib.SkV4_lengthSquared(v4)
end

function Skia.V4.length(v4)
    return lib.SkV4_length(v4)
end

function Skia.V4.dot(v4, v)
    return lib.SkV4_dot(v4, v)
end

function Skia.V4.normalize(v4)
    local obj = lib.SkV4_normalize(v4)
    setFinalizer(obj, lib.static_sk_v4_delete)
    return obj
end

function Skia.V4.ptr(v4)
    return lib. SkV4_ptr(v4)
end

function Skia.V4.ptr_2(v4)
    return lib. SkV4_ptr_2(v4)
end

function Skia.V4.Dot(a, b)
    return lib.SkV4_Dot(a, b)
end

function Skia.V4.Normalize(v)
    local obj = lib.SkV4_Normalize(v)
    setFinalizer(obj, lib.static_sk_v4_delete)
    return obj
end

-- ## sk_vertices
Skia.Vertices = {}

function Skia.Vertices.delete(vertices)
    lib.SkVertices_delete(vertices)
end

function Skia.Vertices.uniqueID(vertices)
    return lib.SkVertices_uniqueID(vertices)
end

function Skia.Vertices.bounds(vertices)
    return lib. SkVertices_bounds(vertices)
end

function Skia.Vertices.approximateSize(vertices)
    return lib.SkVertices_approximateSize(vertices)
end

function Skia.Vertices.unique(vertices)
    return lib.SkVertices_unique(vertices)
end

function Skia.Vertices.ref(vertices)
    lib.SkVertices_ref(vertices)
end

function Skia.Vertices.unref(vertices)
    lib.SkVertices_unref(vertices)
end

function Skia.Vertices.deref(vertices)
    lib.SkVertices_deref(vertices)
end

function Skia.Vertices.refCntGreaterThan(vertices, threadIsolatedTestCnt)
    return lib.SkVertices_refCntGreaterThan(vertices, threadIsolatedTestCnt)
end

function Skia.Vertices.MakeCopy(mode, vertexCount, positions, texs, colors, indexCount, indices)
    local obj = lib.SkVertices_MakeCopy(mode, vertexCount, positions, texs, colors, indexCount, indices)
    setFinalizer(obj, lib.static_sk_vertices_delete)
    return obj
end

function Skia.Vertices.MakeCopy_2(mode, vertexCount, positions, texs, colors)
    local obj = lib.SkVertices_MakeCopy_2(mode, vertexCount, positions, texs, colors)
    setFinalizer(obj, lib.static_sk_vertices_delete)
    return obj
end

-- ## sk_w_stream
Skia.WStream = {}

function Skia.WStream.delete(w_stream)
    lib.SkWStream_delete(w_stream)
end

function Skia.WStream.write(w_stream, buffer, size)
    return lib.SkWStream_write(w_stream, buffer, size)
end

function Skia.WStream.flush(w_stream)
    lib.SkWStream_flush(w_stream)
end

function Skia.WStream.bytesWritten(w_stream)
    return lib.SkWStream_bytesWritten(w_stream)
end

function Skia.WStream.write8(w_stream, value)
    return lib.SkWStream_write8(w_stream, value)
end

function Skia.WStream.write16(w_stream, value)
    return lib.SkWStream_write16(w_stream, value)
end

function Skia.WStream.write32(w_stream, v)
    return lib.SkWStream_write32(w_stream, v)
end

function Skia.WStream.writeText(w_stream, text)
    return lib.SkWStream_writeText(w_stream, text)
end

function Skia.WStream.newline(w_stream)
    return lib.SkWStream_newline(w_stream)
end

function Skia.WStream.writeDecAsText(w_stream, i)
    return lib.SkWStream_writeDecAsText(w_stream, i)
end

function Skia.WStream.writeBigDecAsText(w_stream, i, minDigits)
    return lib.SkWStream_writeBigDecAsText(w_stream, i, minDigits)
end

function Skia.WStream.writeHexAsText(w_stream, i, minDigits)
    return lib.SkWStream_writeHexAsText(w_stream, i, minDigits)
end

function Skia.WStream.writeScalarAsText(w_stream, v)
    return lib.SkWStream_writeScalarAsText(w_stream, v)
end

function Skia.WStream.writeBool(w_stream, v)
    return lib.SkWStream_writeBool(w_stream, v)
end

function Skia.WStream.writeScalar(w_stream, v)
    return lib.SkWStream_writeScalar(w_stream, v)
end

function Skia.WStream.writePackedUInt(w_stream, size)
    return lib.SkWStream_writePackedUInt(w_stream, size)
end

function Skia.WStream.writeStream(w_stream, input, length)
    return lib.SkWStream_writeStream(w_stream, input, length)
end

function Skia.WStream.SizeOfPackedUInt(value)
    return lib.SkWStream_SizeOfPackedUInt(value)
end

-- ## sk_wbmp_decoder
Skia.WbmpDecoder = {}

function Skia.WbmpDecoder.IsWbmp(ptr, size)
    return lib.SkWbmpDecoder_IsWbmp(ptr, size)
end

function Skia.WbmpDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkWbmpDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.WbmpDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkWbmpDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.WbmpDecoder.Decoder()
    local obj = lib.SkWbmpDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

-- ## sk_webp_decoder
Skia.WebpDecoder = {}

function Skia.WebpDecoder.IsWbmp(ptr, size)
    return lib.SkWebpDecoder_IsWbmp(ptr, size)
end

function Skia.WebpDecoder.Decode(static_stream, result, decodeContext)
    local obj = lib.SkWebpDecoder_Decode(static_stream, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.WebpDecoder.Decode_2(static_data, result, decodeContext)
    local obj = lib.SkWebpDecoder_Decode_2(static_data, result, decodeContext)
    setFinalizer(obj, lib.static_sk_codec_delete)
    return obj
end

function Skia.WebpDecoder.Decoder()
    local obj = lib.SkWebpDecoder_Decoder()
    setFinalizer(obj, lib.static_sk_codecs_decoder_delete)
    return obj
end

--[[
-- ## sk_webp_encoder
Skia.WebpEncoder = {}

function Skia.WebpEncoder.Encode(dst, src, options)
    return lib.SkWebpEncoder_Encode(dst, src, options)
end

function Skia.WebpEncoder.Encode_2(ctx, img, options)
    local obj = lib.SkWebpEncoder_Encode_2(ctx, img, options)
    setFinalizer(obj, lib.static_sk_data_delete)
    return obj
end

function Skia.WebpEncoder.EncodeAnimated(dst, encoderFrame, options)
    return lib.SkWebpEncoder_EncodeAnimated(dst, encoderFrame, options)
end
]]

-- ## sk_yuva_info
Skia.YUVAInfo = {}

function Skia.YUVAInfo.new()
    local obj = lib.SkYUVAInfo_new()
    ffi.gc(obj, lib.SkYUVAInfo_delete)
    return obj
end

function Skia.YUVAInfo.new_2(info)
    local obj = lib.SkYUVAInfo_new_2(info)
    ffi.gc(obj, lib.SkYUVAInfo_delete)
    return obj
end

function Skia.YUVAInfo.new_3(dimensions, config, subsampling, space, origin, sitingX, sitingY)
    local obj = lib.SkYUVAInfo_new_3(dimensions, config, subsampling, space, origin, sitingX, sitingY)
    ffi.gc(obj, lib.SkYUVAInfo_delete)
    return obj
end

function Skia.YUVAInfo.delete(yuvaInfo)
    lib.SkYUVAInfo_delete(yuvaInfo)
end

function Skia.YUVAInfo.planeConfig(yuva_info)
    return lib.SkYUVAInfo_planeConfig(yuva_info)
end

function Skia.YUVAInfo.subsampling(yuva_info)
    return lib.SkYUVAInfo_subsampling(yuva_info)
end

function Skia.YUVAInfo.planeSubsamplingFactors(yuva_info, planeIdx)
    local obj = lib.SkYUVAInfo_planeSubsamplingFactors(yuva_info, planeIdx)
    setFinalizer(obj, lib.static_tuple_int_int_delete)
    return obj
end

function Skia.YUVAInfo.dimensions(yuva_info)
    local obj = lib.SkYUVAInfo_dimensions(yuva_info)
    setFinalizer(obj, lib.static_sk_i_size_delete)
    return obj
end

function Skia.YUVAInfo.width(yuva_info)
    return lib.SkYUVAInfo_width(yuva_info)
end

function Skia.YUVAInfo.height(yuva_info)
    return lib.SkYUVAInfo_height(yuva_info)
end

function Skia.YUVAInfo.yuvColorSpace(yuva_info)
    return lib.SkYUVAInfo_yuvColorSpace(yuva_info)
end

function Skia.YUVAInfo.sitingX(yuva_info)
    return lib.SkYUVAInfo_sitingX(yuva_info)
end

function Skia.YUVAInfo.sitingY(yuva_info)
    return lib.SkYUVAInfo_sitingY(yuva_info)
end

function Skia.YUVAInfo.origin(yuva_info)
    return lib.SkYUVAInfo_origin(yuva_info)
end

function Skia.YUVAInfo.originMatrix(yuva_info)
    local obj = lib.SkYUVAInfo_originMatrix(yuva_info)
    setFinalizer(obj, lib.static_sk_matrix_delete)
    return obj
end

function Skia.YUVAInfo.hasAlpha(yuva_info)
    return lib.SkYUVAInfo_hasAlpha(yuva_info)
end

function Skia.YUVAInfo.planeDimensions(yuva_info, planeDimensions)
    return lib.SkYUVAInfo_planeDimensions(yuva_info, planeDimensions)
end

function Skia.YUVAInfo.computeTotalBytes(yuva_info, rowBytes, planeSizes)
    return lib.SkYUVAInfo_computeTotalBytes(yuva_info, rowBytes, planeSizes)
end

function Skia.YUVAInfo.numPlanes(yuva_info)
    return lib.SkYUVAInfo_numPlanes(yuva_info)
end

function Skia.YUVAInfo.numChannelsInPlane(yuva_info, i)
    return lib.SkYUVAInfo_numChannelsInPlane(yuva_info, i)
end

function Skia.YUVAInfo.makeSubsampling(yuva_info, subsampling)
    local obj = lib.SkYUVAInfo_makeSubsampling(yuva_info, subsampling)
    setFinalizer(obj, lib.static_sk_yuva_info_delete)
    return obj
end

function Skia.YUVAInfo.makeDimensions(yuva_info, size)
    local obj = lib.SkYUVAInfo_makeDimensions(yuva_info, size)
    setFinalizer(obj, lib.static_sk_yuva_info_delete)
    return obj
end

function Skia.YUVAInfo.isValid(yuva_info)
    return lib.SkYUVAInfo_isValid(yuva_info)
end

function Skia.YUVAInfo.SubsamplingFactors(subsampling)
    local obj = lib.SkYUVAInfo_SubsamplingFactors(subsampling)
    setFinalizer(obj, lib.static_tuple_int_int_delete)
    return obj
end

function Skia.YUVAInfo.PlaneSubsamplingFactors(config, subsampling, planeIdx)
    local obj = lib.SkYUVAInfo_PlaneSubsamplingFactors(config, subsampling, planeIdx)
    setFinalizer(obj, lib.static_tuple_int_int_delete)
    return obj
end

function Skia.YUVAInfo.PlaneDimensions(imageDimensions, plane, subsampling, origin, planeDimensions)
    return lib.SkYUVAInfo_PlaneDimensions(imageDimensions, plane, subsampling, origin, planeDimensions)
end

function Skia.YUVAInfo.NumPlanes(config)
    return lib.SkYUVAInfo_NumPlanes(config)
end

function Skia.YUVAInfo.NumChannelsInPlane(config, i)
    return lib.SkYUVAInfo_NumChannelsInPlane(config, i)
end

function Skia.YUVAInfo.HasAlpha(config)
    return lib.SkYUVAInfo_HasAlpha(config)
end

-- ## sk_yuva_pixmap_info
Skia.YUVAPixmapInfo = {}

function Skia.YUVAPixmapInfo.new()
    local obj = lib.SkYUVAPixmapInfo_new()
    ffi.gc(obj, lib.SkYUVAPixmapInfo_delete)
    return obj
end

function Skia.YUVAPixmapInfo.new_2(info, type, rowBytes)
    local obj = lib.SkYUVAPixmapInfo_new_2(info, type, rowBytes)
    ffi.gc(obj, lib.SkYUVAPixmapInfo_delete)
    return obj
end

function Skia.YUVAPixmapInfo.new_3(info, type, rowBytes)
    local obj = lib.SkYUVAPixmapInfo_new_3(info, type, rowBytes)
    ffi.gc(obj, lib.SkYUVAPixmapInfo_delete)
    return obj
end

function Skia.YUVAPixmapInfo.new_4(info)
    local obj = lib.SkYUVAPixmapInfo_new_4(info)
    ffi.gc(obj, lib.SkYUVAPixmapInfo_delete)
    return obj
end

function Skia.YUVAPixmapInfo.delete(yuvaPixmapInfo)
    lib.SkYUVAPixmapInfo_delete(yuvaPixmapInfo)
end

function Skia.YUVAPixmapInfo.yuvaInfo(yuva_pixmap_info)
    return lib. SkYUVAPixmapInfo_yuvaInfo(yuva_pixmap_info)
end

function Skia.YUVAPixmapInfo.yuvColorSpace(yuva_pixmap_info)
    return lib.SkYUVAPixmapInfo_yuvColorSpace(yuva_pixmap_info)
end

function Skia.YUVAPixmapInfo.numPlanes(yuva_pixmap_info)
    return lib.SkYUVAPixmapInfo_numPlanes(yuva_pixmap_info)
end

function Skia.YUVAPixmapInfo.dataType(yuva_pixmap_info)
    return lib.SkYUVAPixmapInfo_dataType(yuva_pixmap_info)
end

function Skia.YUVAPixmapInfo.rowBytes(yuva_pixmap_info, i)
    return lib.SkYUVAPixmapInfo_rowBytes(yuva_pixmap_info, i)
end

function Skia.YUVAPixmapInfo.planeInfo(yuva_pixmap_info, i)
    return lib. SkYUVAPixmapInfo_planeInfo(yuva_pixmap_info, i)
end

function Skia.YUVAPixmapInfo.computeTotalBytes(yuva_pixmap_info, planeSizes)
    return lib.SkYUVAPixmapInfo_computeTotalBytes(yuva_pixmap_info, planeSizes)
end

function Skia.YUVAPixmapInfo.initPixmapsFromSingleAllocation(yuva_pixmap_info, memory, pixmaps)
    return lib.SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(yuva_pixmap_info, memory, pixmaps)
end

function Skia.YUVAPixmapInfo.isValid(yuva_pixmap_info)
    return lib.SkYUVAPixmapInfo_isValid(yuva_pixmap_info)
end

function Skia.YUVAPixmapInfo.isSupported(yuva_pixmap_info, type)
    return lib.SkYUVAPixmapInfo_isSupported(yuva_pixmap_info, type)
end

function Skia.YUVAPixmapInfo.DefaultColorTypeForDataType(dataType, numChannels)
    return lib.SkYUVAPixmapInfo_DefaultColorTypeForDataType(dataType, numChannels)
end

function Skia.YUVAPixmapInfo.NumChannelsAndDataType(type)
    local obj = lib.SkYUVAPixmapInfo_NumChannelsAndDataType(type)
    setFinalizer(obj, lib.static_tuple_int_sk_yuva_pixmap_info_data_type_delete)
    return obj
end

-- ## sk_yuva_pixmaps
Skia.YUVAPixmaps = {}

function Skia.YUVAPixmaps.new()
    local obj = lib.SkYUVAPixmaps_new()
    ffi.gc(obj, lib.SkYUVAPixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.new_2(pixmaps)
    local obj = lib.SkYUVAPixmaps_new_2(pixmaps)
    ffi.gc(obj, lib.SkYUVAPixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.delete(yuva_pixmaps)
    lib.SkYUVAPixmaps_delete(yuva_pixmaps)
end

function Skia.YUVAPixmaps.isValid(yuva_pixmaps)
    return lib.SkYUVAPixmaps_isValid(yuva_pixmaps)
end

function Skia.YUVAPixmaps.yuvaInfo(yuva_pixmaps)
    return lib. SkYUVAPixmaps_yuvaInfo(yuva_pixmaps)
end

function Skia.YUVAPixmaps.dataType(yuva_pixmaps)
    return lib.SkYUVAPixmaps_dataType(yuva_pixmaps)
end

function Skia.YUVAPixmaps.pixmapsInfo(yuva_pixmaps)
    local obj = lib.SkYUVAPixmaps_pixmapsInfo(yuva_pixmaps)
    setFinalizer(obj, lib.static_sk_yuva_pixmap_info_delete)
    return obj
end

function Skia.YUVAPixmaps.numPlanes(yuva_pixmaps)
    return lib.SkYUVAPixmaps_numPlanes(yuva_pixmaps)
end

function Skia.YUVAPixmaps.planes(yuva_pixmaps)
    return lib. SkYUVAPixmaps_planes(yuva_pixmaps)
end

function Skia.YUVAPixmaps.plane(yuva_pixmaps, i)
    return lib. SkYUVAPixmaps_plane(yuva_pixmaps, i)
end

function Skia.YUVAPixmaps.ownsStorage(yuva_pixmaps)
    return lib.SkYUVAPixmaps_ownsStorage(yuva_pixmaps)
end

function Skia.YUVAPixmaps.RecommendedRGBAColorType(type)
    return lib.SkYUVAPixmaps_RecommendedRGBAColorType(type)
end

function Skia.YUVAPixmaps.Allocate(yuvaPixmapInfo)
    local obj = lib.SkYUVAPixmaps_Allocate(yuvaPixmapInfo)
    setFinalizer(obj, lib.static_sk_yuva_pixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.FromData(yuvaPixmapInfo, data)
    local obj = lib.SkYUVAPixmaps_FromData(yuvaPixmapInfo, data)
    setFinalizer(obj, lib.static_sk_yuva_pixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.MakeCopy(src)
    local obj = lib.SkYUVAPixmaps_MakeCopy(src)
    setFinalizer(obj, lib.static_sk_yuva_pixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.FromExternalMemory(yuvaPixmapInfo, memory)
    local obj = lib.SkYUVAPixmaps_FromExternalMemory(yuvaPixmapInfo, memory)
    setFinalizer(obj, lib.static_sk_yuva_pixmaps_delete)
    return obj
end

function Skia.YUVAPixmaps.FromExternalPixmaps(yuvaInfo, pixmaps)
    local obj = lib.SkYUVAPixmaps_FromExternalPixmaps(yuvaInfo, pixmaps)
    setFinalizer(obj, lib.static_sk_yuva_pixmaps_delete)
    return obj
end

-- ## skottie_animation

return Skia