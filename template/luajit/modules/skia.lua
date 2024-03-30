local ffi = require("ffi")

ffi.cdef[[
    // # static
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
    // ## static_sk_font
    void static_sk_font_delete(int key);
    // ## static_sk_font_arguments
    void static_sk_font_arguments_delete(int key);
    // ## static_sk_font_mgr
    void static_sk_font_mgr_delete(int key);
    void *static_sk_font_mgr_get(int key);
    // ## static_sk_font_style
    void static_sk_font_style_delete(int key);
    // ## static_sk_font_style_set
    void static_sk_font_style_set_delete(int key);
    void *static_sk_font_style_set_get(int key);
    // ## static_sk_i_rect
    void static_sk_i_rect_delete(int key);
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
    // ## static_sk_r_rect
    void static_sk_r_rect_delete(int key);
    // ## static_sk_rect
    void static_sk_rect_delete(int key);
    void *static_sk_rect_get_ptr(int key);
    // ## static_sk_runtime_effect
    void static_sk_runtime_effect_delete(int key);
    void *static_sk_runtime_effect_get(int key);
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
    // ## static_sk_shaper_script_run_iterator
    void static_sk_shaper_script_run_iterator_delete(int key);
    void *static_sk_shaper_script_run_iterator_get(int key);
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
    // ## static_sk_text_blob
    void static_sk_text_blob_delete(int key);
    void *static_sk_text_blob_get(int key);
    // ## static_sk_typeface
    void static_sk_typeface_delete(int key);
    void *static_sk_typeface_get(int key);
    // ## static_sk_vertices
    void static_sk_vertices_delete(int key);
    void *static_sk_vertices_get(int key);
    // ## static_sk_yuva_info
    void static_sk_yuva_info_delete(int key);
    // ## static_sk_yuva_pixmap_info
    void static_sk_yuva_pixmap_info_delete(int key);
    // ## static_sk_yuva_pixmaps
    void static_sk_yuva_pixmaps_delete(int key);
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
    // ## static_std_vector_sk_svg_length
    void static_vector_sk_svg_length_delete(int key);
    void static_vector_sk_svg_length_pop_back(int key);
    void static_vector_sk_svg_length_erase(int key, int index);
    //
    // # binding
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
//    typedef void (*)(GrGpuFinishedContext) GrGpuFinishedProc;
//    void GrDirectContext_delete(void *direct_context);
//    void GrDirectContext_resetContext(void *direct_context, uint32_t state);
//    void GrDirectContext_resetGLTextureBindings(void *direct_context);
//    void GrDirectContext_abandonContext(void *direct_context);
//    bool GrDirectContext_abandoned(void *direct_context);
//    bool GrDirectContext_isDeviceLost(void *direct_context);
//    int GrDirectContext_threadSafeProxy(void *direct_context);
//    bool GrDirectContext_oomed(void *direct_context);
//    void GrDirectContext_releaseResourcesAndAbandonContext(void *direct_context);
//    void GrDirectContext_getResourceCacheLimits(void *direct_context, int *maxResources, size_t *maxResourceBytes);
//    size_t GrDirectContext_getResourceCacheLimit(void *direct_context);
//    void GrDirectContext_getResourceCacheUsage(void *direct_context, int *resourceCount, size_t *resourceBytes);
//    size_t GrDirectContext_getResourceCachePurgeableBytes(void *direct_context);
//    void GrDirectContext_setResourceCacheLimits(void *direct_context, int maxResources, size_t maxResourceBytes);
//    void GrDirectContext_setResourceCacheLimit(void *direct_context, size_t maxResourceBytes);
//    void GrDirectContext_freeGpuResources(void *direct_context);
//    void GrDirectContext_performDeferredCleanup(void *direct_context, std::chrono::milliseconds msNotUsed, int opts);
//    void GrDirectContext_purgeResourcesNotUsedInMs(void *direct_context, std::chrono::milliseconds msNotUsed);
//    void GrDirectContext_purgeUnlockedResources(void *direct_context, size_t bytesToPurge, bool preferScratchResources);
//    void GrDirectContext_purgeUnlockedResources_2(void *direct_context, int opts);
//    bool GrDirectContext_wait(void *direct_context, int numSemaphores, const void *waitSemaphores, bool deleteSemaphoresAfterWait);
//    void GrDirectContext_flushAndSubmit(void *direct_context, bool sync);
//    void GrDirectContext_flushAndSubmit_2(void *direct_context, const void *image);
//    void GrDirectContext_flushAndSubmit_3(void *direct_context, void *surface, bool sync);
//    bool GrDirectContext_flush(void *direct_context, const void *info);
//    void GrDirectContext_flush_2(void *direct_context);
//    bool GrDirectContext_flush_3(void *direct_context, const void *image, const void *info);
//    void GrDirectContext_flush_4(void *direct_context, const void *image);
//    bool GrDirectContext_flush_5(void *direct_context, void *surface, int access, const void *info);
//    bool GrDirectContext_flush_6(void *direct_context, void *surface, const void *info, const void *newState);
//    void GrDirectContext_flush_7(void *direct_context, void *surface);
//    bool GrDirectContext_submit(void *direct_context, bool sync);
//    void GrDirectContext_checkAsyncWorkCompletion(void *direct_context);
//    void GrDirectContext_dumpMemoryStatistics(void *direct_context, void *traceMemoryDump);
//    bool GrDirectContext_supportsDistanceFieldText(void *direct_context);
//    void GrDirectContext_storeVkPipelineCacheData(void *direct_context);
//    int GrDirectContext_createBackendTexture(void *direct_context, int width, int height, const void *format, bool mipmapped, bool renderable, bool isProtected, std::string_view label);
//    int GrDirectContext_createBackendTexture_2(void *direct_context, int width, int height, int type, bool mipmapped, bool renderable, bool isProtected, std::string_view label);
//    int GrDirectContext_createBackendTexture_3(void *direct_context, int width, int height, const void *format, const void *color, bool mipmapped, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    int GrDirectContext_createBackendTexture_4(void *direct_context, int width, int height, int type, const void *color, bool mipmapped, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    int GrDirectContext_createBackendTexture_5(void *direct_context, const void *srcData, int numLevels, int textureOrigin, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    int GrDirectContext_createBackendTexture_6(void *direct_context, const void *srcData, int textureOrigin, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    int GrDirectContext_createBackendTexture_7(void *direct_context, const void *srcData, int numLevels, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    int GrDirectContext_createBackendTexture_8(void *direct_context, const void *srcData, bool renderable, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
//    bool GrDirectContext_updateBackendTexture(void *direct_context, const void *texture, const void *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateBackendTexture_2(void *direct_context, const void *texture, int skColorType, const void *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateBackendTexture_3(void *direct_context, const void *texture, const void *srcData, int numLevels, int textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateBackendTexture_4(void *direct_context, const void *texture, const void *srcData, int textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateBackendTexture_5(void *direct_context, const void *texture, const void *srcData, int numLevels, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    int GrDirectContext_createCompressedBackendTexture(void *direct_context, int width, int height, const void *format, const void *color, bool mipmapped, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    int GrDirectContext_createCompressedBackendTexture_2(void *direct_context, int width, int height, SkTextureCompressionType type, const void *color, bool mipmapped, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    int GrDirectContext_createCompressedBackendTexture_3(void *direct_context, int width, int height, const void *format, const void *data, size_t dataSize, bool mipmapped, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    int GrDirectContext_createCompressedBackendTexture_4(void *direct_context, int width, int height, SkTextureCompressionType type, const void *data, size_t dataSize, bool mipmapped, bool isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateCompressedBackendTexture(void *direct_context, const void *texture, const void *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_updateCompressedBackendTexture_2(void *direct_context, const void *texture, const void *data, size_t dataSize, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_setBackendTextureState(void *direct_context, const void *texture, const void *state, void *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    bool GrDirectContext_setBackendRenderTargetState(void *direct_context, const void *target, const void *state, void *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
//    void GrDirectContext_deleteBackendTexture(void *direct_context, const void *texture);
//    bool GrDirectContext_precompileShader(void *direct_context, const void *key, const void *data);
//    int GrDirectContext_directContextID(void *direct_context);
//    int GrDirectContext_maxTextureSize(void *direct_context);
//    int GrDirectContext_maxRenderTargetSize(void *direct_context);
//    bool GrDirectContext_colorTypeSupportedAsImage(void *direct_context, int colorType);
//    bool GrDirectContext_supportsProtectedContent(void *direct_context);
//    bool GrDirectContext_colorTypeSupportedAsSurface(void *direct_context, int colorType);
//    bool GrDirectContext_colorTypeSupportedAsSurface_2(void *direct_context, int colorType);
//    int GrDirectContext_maxSurfaceSampleCountForColorType(void *direct_context, int colorType);
//    int GrDirectContext_skCapabilities(void *direct_context);
//    int GrDirectContext_MakeMock(const void *mockOptions, const void *contextOptions);
//    int GrDirectContext_MakeMock_2(const void *mockOptions);
    // ## gr_driver_bug_workarounds
    // ## gr_recording_context
    // ## gr_yuva_backend_texture_info
    // ## gr_yuva_backend_textures
    // ## sk_alpha_type
    // ## sk_android_codec
    // ## sk_annotation
    // ## sk_auto_canvas_restore
    // ## sk_avif_decoder
    // ## sk_b_box_hierarchy
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
    bool SkBitmap_installPixels_2(void *bitmap, const void *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context);
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
    // ## sk_blenders
    // ## sk_bmp_decoder
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
    // ## sk_codec
    // ## sk_codecs
    // ## sk_color
    // ## sk_color_filter
    // ## sk_color_filters
    // ## sk_color_info
    // ## sk_color_matrix
    // ## sk_color_matrix_filter
    // ## sk_color_priv
    // ## sk_color_space
    // ## sk_color_space_primaries
    // ## sk_color_table
    // ## sk_contour_measure
    // ## sk_contour_measure_iter
    // ## sk_corner_path_effect
    // ## sk_cubic_map
    // ## sk_cubic_resampler
    // ## sk_dash_path_effect
    // ## sk_data
    int SkData_MakeFromStream(void *stream, size_t size);
    // ## sk_data_table
    // ## sk_discrete_path_effect
    // ## sk_document
    // ## sk_drawable
    // ## sk_dynamic_memory_w_stream
    // ## sk_encoded_origin
    // ## sk_encoder
    // ## sk_executor
    // ## sk_file_stream
    // ## sk_file_w_stream
    // ## sk_flattenable
    // ## sk_font
    // ## sk_font_arguments
    // ## sk_font_metrics
    // ## sk_font_mgr
    // ## sk_font_mgr_fontconfig
    // ## sk_font_style
    // ## sk_font_style_set
    // ## sk_gif_decoder
    // ## sk_gradient_shader
    // ## sk_graphics
    // ## sk_high_contrast_config
    // ## sk_high_contrast_filter
    // ## sk_i_rect
    // ## sk_i_size
    // ## sk_icc
    // ## sk_ico_cecoder
    // ## sk_image
    // ## sk_image_filter
    // ## sk_image_filters
    // ## sk_image_generator
    // ## sk_image_info
    // ## sk_images
    int SkImages_DeferredFromEncodedData(int data);
    // ## sk_jpeg_decoder
    // ## sk_jpeg_encoder
    // ## sk_jpegxl_decoder
    // ## sk_line_2d_path_effect
    // ## sk_luma_color_filter
    // ## sk_m_44
    // ## sk_malloc_pixel_ref
    // ## sk_mask_filter
    // ## sk_matrix
    // ## sk_memory_stream
    // ## sk_meshes
    // ## sk_op_builder
    // ## sk_open_type_svg_decoder
    // ## sk_overdraw_canvas
    // ## sk_overdraw_color_filter
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
    // ## sk_path_2d_path_effect
    // ## sk_path_builder
    // ## sk_path_effect
    // ## sk_path_measure
    // ## sk_pdf
    // ## sk_perlin_noise_shader
    // ## sk_picture
    // ## sk_picture_recorder
    // ## sk_pixel_ref
    // ## sk_pixmap
    // ## sk_pixmap_utils
    // ## sk_png_decoder
    // ## sk_png_encoder
    // ## sk_point
    // ## sk_point_3
    // ## sk_r_rect
    // ## sk_raster_handle_allocator
    // ## sk_raw_decoder
    // ## sk_rect
    int SkRect_MakeXYWH(float x, float y, float w, float h);
    // ## sk_ref_cnt
    // ## sk_ref_cnt_base
    // ## sk_region
    // ## sk_rsx_form
    // ## sk_runtime_blend_builder
    // ## sk_runtime_color_filter_builder
    // ## sk_runtime_effect
    // ## sk_runtime_effect_builder
    // ## sk_runtime_shader_builder
    // ## sk_sampling_options
    // ## sk_shader
    // ## sk_shader_mask_filter
    // ## sk_shaders
    // ## sk_shaper
    // ## sk_size
    // ## sk_stream
    int SkStream_MakeFromFile(const char path[]);
    size_t SkStream_getLength(void *stream);
    // ## sk_stream_asset
    size_t SkStreamAsset_getLength(void *stream_asset);
    // ## sk_stream_memory
    // ## sk_stream_rewindable
    // ## sk_stream_seekable
    // ## sk_string
    // ## sk_stroke_rec
    // ## sk_surface
    // ## sk_surface_props
    // ## sk_surfaces
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
    // ## sk_text_blob
    // ## sk_text_blob_builder
    // ## sk_text_blob_builder_run_handler
    // ## sk_tiled_image_utils
    // ## sk_trace_memory_dump
    // ## sk_trim_path_effect
    // ## sk_typeface
    // ## sk_typeface_mac
    // ## sk_un_pre_multiply
    // ## sk_v2
    // ## sk_v3
    // ## sk_v4
    // ## sk_vertices
    // ## sk_w_stream
    // ## sk_wbmp_decoder
    // ## sk_webp_decoder
    // ## sk_webp_encoder
    // ## sk_yuva_info
    // ## sk_yuva_pixmap_info
    // ## sk_yuva_pixmaps
    // ## skottie_animation
    //
]]

local lib = ffi.load("raia_skia")
local Skia = {}

-- # static
-- ## static_gr_backend_format
-- ## static_gr_backend_texture
-- ## static_gr_color_format_desc
-- ## static_gr_context_thread_safe_proxy
-- ## static_gr_direct_context
-- ## static_gr_direct_context_direct_context_id
-- ## static_sk_android_codec
-- ## static_sk_b_box_hierarchy
-- ## static_sk_blend_mode
-- ## static_sk_blender
-- ## static_sk_canvas
-- ## static_sk_capabilities
-- ## static_sk_codec
-- ## static_sk_codecs_decoder
-- ## static_sk_color
-- ## static_sk_color_filter
-- ## static_sk_color_info
-- ## static_sk_color_matrix
-- ## static_sk_color_space
-- ## static_sk_color_table
-- ## static_sk_contour_measure
-- ## static_sk_data
-- ## static_sk_data_table
-- ## static_sk_document
-- ## static_sk_drawable
-- ## static_sk_drawable_gpu_draw_handler
-- ## static_sk_encoder
-- ## static_sk_encoder_frame
-- ## static_sk_executor
-- ## static_sk_file_stream
-- ## static_sk_flattenable
-- ## static_sk_font
-- ## static_sk_font_arguments
-- ## static_sk_font_mgr
-- ## static_sk_font_style
-- ## static_sk_font_style_set
-- ## static_sk_i_rect
-- ## static_sk_id_change_listener
-- ## static_sk_image
-- ## static_sk_image_filter
-- ## static_sk_image_generator
-- ## static_sk_image_info
-- ## static_sk_m_44
-- ## static_sk_mask_filter
-- ## static_sk_matrix
-- ## static_sk_memory_stream
-- ## static_sk_mesh_child_ptr
-- ## static_sk_mesh_index_buffer
-- ## static_sk_mesh_vertex_buffer
-- ## static_sk_path
-- ## static_sk_path_effect
-- ## static_sk_picture
-- ## static_sk_pixel_ref
-- ## static_sk_pixmap
-- ## static_sk_r_rect
-- ## static_sk_rect
function Skia.static_sk_rect_delete(key)
    lib.static_sk_rect_delete(key)
end
-- ## static_sk_runtime_effect
-- ## static_sk_runtime_effect_child
-- ## static_sk_runtime_effect_child_ptr
-- ## static_sk_runtime_effect_result
-- ## static_sk_runtime_effect_traced_shader
-- ## static_sk_runtime_effect_uniform
-- ## static_sk_sampling_options
-- ## static_sk_shader
-- ## static_sk_shaper
-- ## static_sk_shaper_bi_di_run_iterator
-- ## static_sk_shaper_font_run_iterator
-- ## static_sk_shaper_language_run_iterator
-- ## static_sk_shaper_script_run_iterator
-- ## static_sk_stream
-- ## static_sk_stream_asset
-- ## static_sk_stream_memory
-- ## static_sk_stream_rewindable
-- ## static_sk_stream_seekable
-- ## static_sk_string
-- ## static_sk_stroke_rec
-- ## static_sk_surface
-- ## static_sk_surface_props
-- ## static_sk_svg_circle
-- ## static_sk_svg_clip_path
-- ## static_sk_svg_defs
-- ## static_sk_svg_dom
-- ## static_sk_svg_ellipse
-- ## static_sk_svg_fe_blend
-- ## static_sk_svg_fe_color_matrix
-- ## static_sk_svg_fe_composite
-- ## static_sk_svg_fe_diffuse_lighting
-- ## static_sk_svg_fe_displacement_map
-- ## static_sk_svg_fe_distant_light
-- ## static_sk_svg_fe_flood
-- ## static_sk_svg_fe_gaussian_blur
-- ## static_sk_svg_fe_image
-- ## static_sk_svg_fe_morphology
-- ## static_sk_svg_fe_offset
-- ## static_sk_svg_fe_point_light
-- ## static_sk_svg_fe_specular_lighting
-- ## static_sk_svg_fe_spot_light
-- ## static_sk_svg_fe_turbulence
-- ## static_sk_svg_g
-- ## static_sk_svg_image
-- ## static_sk_svg_line
-- ## static_sk_svg_linear_gradient
-- ## static_sk_svg_mask
-- ## static_sk_svg_node
-- ## static_sk_svg_path
-- ## static_sk_svg_pattern
-- ## static_sk_svg_poly
-- ## static_sk_svg_presentation_attributes
-- ## static_sk_svg_radial_gradient
-- ## static_sk_svg_rect
-- ## static_sk_svg_stop
-- ## static_sk_svg_svg
-- ## static_sk_svg_t_span
-- ## static_sk_svg_text
-- ## static_sk_svg_text_literal
-- ## static_sk_svg_text_path
-- ## static_sk_svg_use
-- ## static_sk_text_blob
-- ## static_sk_typeface
-- ## static_sk_vertices
-- ## static_sk_yuva_info
-- ## static_sk_yuva_pixmap_info
-- ## static_sk_yuva_pixmaps
-- ## static_std_function_void_void
-- ## static_std_string_view
-- ## static_std_tuple_int_int
-- ## static_std_tuple_int_sk_yuva_pixmap_info_data_type
-- ## static_std_tuple_sk_image_sk_codec_result
-- ## static_std_vector_sk_codec_frame_info
-- ## static_std_vector_sk_scalar
-- ## static_std_vector_sk_svg_length

-- # binding
-- ## gr_backend_drawable_info
-- ## gr_backend_format
-- ## gr_backend_render_target
-- ## gr_backend_semaphore
-- ## gr_backend_texture
-- ## gr_context_thread_safe_proxy
-- ## gr_direct_context
-- ## gr_driver_bug_workarounds
-- ## gr_recording_context
-- ## gr_yuva_backend_texture_info
-- ## gr_yuva_backend_textures
-- ## sk_alpha_type
-- ## sk_android_codec
-- ## sk_annotation
-- ## sk_auto_canvas_restore
-- ## sk_avif_decoder
-- ## sk_b_box_hierarchy
-- ## sk_bitmap
function Skia.SkBitmap_new()
    return lib.SkBitmap_new()
end
function Skia.SkBitmap_allocN32Pixels(bitmap, width, height, isOpaque)
    lib.SkBitmap_allocN32Pixels(bitmap, width, height, isOpaque)
end
function Skia.SkBitmap_getPixels(bitmap)
    return lib.SkBitmap_getPixels(bitmap)
end
-- ## sk_blend_mode
-- ## sk_blender
-- ## sk_blenders
-- ## sk_bmp_decoder
-- ## sk_canvas
function Skia.SkCanvas_new_3(bitmap)
    return lib.SkCanvas_new_3(bitmap)
end
function Skia.SkCanvas_drawRect(canvas, rect, paint)
    lib.SkCanvas_drawRect(canvas, rect, paint)
end
-- ## sk_capabilities
-- ## sk_codec
-- ## sk_codecs
-- ## sk_color
-- ## sk_color_filter
-- ## sk_color_filters
-- ## sk_color_info
-- ## sk_color_matrix
-- ## sk_color_matrix_filter
-- ## sk_color_priv
-- ## sk_color_space
-- ## sk_color_space_primaries
-- ## sk_color_table
-- ## sk_contour_measure
-- ## sk_contour_measure_iter
-- ## sk_corner_path_effect
-- ## sk_cubic_map
-- ## sk_cubic_resampler
-- ## sk_dash_path_effect
-- ## sk_data
-- ## sk_data_table
-- ## sk_discrete_path_effect
-- ## sk_document
-- ## sk_drawable
-- ## sk_dynamic_memory_w_stream
-- ## sk_encoded_origin
-- ## sk_encoder
-- ## sk_executor
-- ## sk_file_stream
-- ## sk_file_w_stream
-- ## sk_flattenable
-- ## sk_font
-- ## sk_font_arguments
-- ## sk_font_metrics
-- ## sk_font_mgr
-- ## sk_font_mgr_fontconfig
-- ## sk_font_style
-- ## sk_font_style_set
-- ## sk_gif_decoder
-- ## sk_gradient_shader
-- ## sk_graphics
-- ## sk_high_contrast_config
-- ## sk_high_contrast_filter
-- ## sk_i_rect
-- ## sk_i_size
-- ## sk_icc
-- ## sk_ico_cecoder
-- ## sk_image
-- ## sk_image_filter
-- ## sk_image_filters
-- ## sk_image_generator
-- ## sk_image_info
-- ## sk_images
-- ## sk_jpeg_decoder
-- ## sk_jpeg_encoder
-- ## sk_jpegxl_decoder
-- ## sk_line_2d_path_effect
-- ## sk_luma_color_filter
-- ## sk_m_44
-- ## sk_malloc_pixel_ref
-- ## sk_mask_filter
-- ## sk_matrix
-- ## sk_memory_stream
-- ## sk_meshes
-- ## sk_op_builder
-- ## sk_open_type_svg_decoder
-- ## sk_overdraw_canvas
-- ## sk_overdraw_color_filter
-- ## sk_paint
function Skia.SkPaint_new()
    return lib.SkPaint_new()
end
function Skia.SkPaint_setColor(paint, color)
    lib.SkPaint_setColor(paint, color)
end
-- ## sk_path
-- ## sk_path_1d_path_effect
-- ## sk_path_2d_path_effect
-- ## sk_path_builder
-- ## sk_path_effect
-- ## sk_path_measure
-- ## sk_pdf
-- ## sk_perlin_noise_shader
-- ## sk_picture
-- ## sk_picture_recorder
-- ## sk_pixel_ref
-- ## sk_pixmap
-- ## sk_pixmap_utils
-- ## sk_png_decoder
-- ## sk_png_encoder
-- ## sk_point
-- ## sk_point_3
-- ## sk_r_rect
-- ## sk_raster_handle_allocator
-- ## sk_raw_decoder
-- ## sk_rect
function Skia.SkRect_MakeXYWH(x, y, w, h)
    return lib.SkRect_MakeXYWH(x, y, w, h)
end
-- ## sk_ref_cnt
-- ## sk_ref_cnt_base
-- ## sk_region
-- ## sk_rsx_form
-- ## sk_runtime_blend_builder
-- ## sk_runtime_color_filter_builder
-- ## sk_runtime_effect
-- ## sk_runtime_effect_builder
-- ## sk_runtime_shader_builder
-- ## sk_sampling_options
-- ## sk_shader
-- ## sk_shader_mask_filter
-- ## sk_shaders
-- ## sk_shaper
-- ## sk_size
-- ## sk_stream.lua
-- ## sk_stream_asset
-- ## sk_stream_memory
-- ## sk_stream_rewindable
-- ## sk_stream_seekable
-- ## sk_string
-- ## sk_stroke_rec
-- ## sk_surface
-- ## sk_surface_props
-- ## sk_surfaces
-- ## sk_svg_attribute_parser
-- ## sk_svg_circle
-- ## sk_svg_clip_path
-- ## sk_svg_color
-- ## sk_svg_container
-- ## sk_svg_dash_array
-- ## sk_svg_defs
-- ## sk_svg_dom
-- ## sk_svg_ellipse
-- ## sk_svg_fe
-- ## sk_svg_fe_blend
-- ## sk_svg_fe_color_matrix
-- ## sk_svg_fe_composite
-- ## sk_svg_fe_diffuse_lighting
-- ## sk_svg_fe_displacement_map
-- ## sk_svg_fe_distant_light
-- ## sk_svg_fe_flood
-- ## sk_svg_fe_gaussian_blur
-- ## sk_svg_fe_image
-- ## sk_svg_fe_input_type
-- ## sk_svg_fe_light_source
-- ## sk_svg_fe_lighting
-- ## sk_svg_fe_morphology
-- ## sk_svg_fe_offset
-- ## sk_svg_fe_point_light
-- ## sk_svg_fe_specular_lighting
-- ## sk_svg_fe_spot_light
-- ## sk_svg_fe_turbulence
-- ## sk_svg_fe_turbulence_base_frequency
-- ## sk_svg_fe_turbulence_type
-- ## sk_svg_fill_rule
-- ## sk_svg_filter
-- ## sk_svg_filter_context
-- ## sk_svg_font_family
-- ## sk_svg_font_size
-- ## sk_svg_font_style
-- ## sk_svg_font_weight
-- ## sk_svg_func_iri
-- ## sk_svg_g
-- ## sk_svg_gradient
-- ## sk_svg_hidden_container
-- ## sk_svg_image
-- ## sk_svg_iri
-- ## sk_svg_length
-- ## sk_svg_length_context
-- ## sk_svg_line
-- ## sk_svg_line_join
-- ## sk_svg_linear_gradient
-- ## sk_svg_mask
-- ## sk_svg_node
-- ## sk_svg_object_bounding_box_units
-- ## sk_svg_open_type_svg_decoder
-- ## sk_svg_paint
-- ## sk_svg_path
-- ## sk_svg_pattern
-- ## sk_svg_poly
-- ## sk_svg_presentation_attributes
-- ## sk_svg_presentation_context
-- ## sk_svg_property
-- ## sk_svg_radial_gradient
-- ## sk_svg_rect
-- ## sk_svg_render_context
-- ## sk_svg_shape
-- ## sk_svg_spread_method
-- ## sk_svg_stop
-- ## sk_svg_stop_color
-- ## sk_svg_svg
-- ## sk_svg_t_span
-- ## sk_svg_text
-- ## sk_svg_text_anchor
-- ## sk_svg_text_container
-- ## sk_svg_text_fragment
-- ## sk_svg_text_literal
-- ## sk_svg_text_path
-- ## sk_svg_transformable_node
-- ## sk_svg_use
-- ## sk_svg_value
-- ## sk_svg_visibility
-- ## sk_svg_wrapper_value
-- ## sk_table_mask_filter
-- ## sk_text_blob
-- ## sk_text_blob_builder
-- ## sk_text_blob_builder_run_handler
-- ## sk_tiled_image_utils
-- ## sk_trace_memory_dump
-- ## sk_trim_path_effect
-- ## sk_typeface
-- ## sk_typeface_mac
-- ## sk_un_pre_multiply
-- ## sk_v2
-- ## sk_v3
-- ## sk_v4
-- ## sk_vertices
-- ## sk_w_stream
-- ## sk_wbmp_decoder
-- ## sk_webp_decoder
-- ## sk_webp_encoder
-- ## sk_yuva_info
-- ## sk_yuva_pixmap_info
-- ## sk_yuva_pixmaps
-- ## skottie_animation

return Skia