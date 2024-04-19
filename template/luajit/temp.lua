local lib = ffi.load("raia_skia")
local Skia = {}

-- # static
Skia.Static = {}

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

function Skia.Static.deleteVectorSkSVGLength(key)
    lib.static_vector_sk_svg_length_delete(key)
end

function Skia.Static.popBackVectorSkSVGLength(key)
    lib.static_vector_sk_svg_length_pop_back(key)
end

function Skia.Static.eraseVectorSkSVGLength(key, index)
    lib.static_vector_sk_svg_length_erase(key, index)
end

-- # binding

-- ## gr_backend_drawable_info
Skia.BackendDrawableInfo = {}

function Skia.BackendDrawableInfo.new()
    return lib.GrBackendDrawableInfo_new()
end

function Skia.BackendDrawableInfo.new_2(info)
    return lib.GrBackendDrawableInfo_new_2(info)
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
    return lib.GrBackendFormat_new()
end

function Skia.BackendFormat.new_2(format)
    return lib.GrBackendFormat_new_2(format)
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
    return lib.GrBackendFormat_desc(backend_format)
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
    return lib.GrBackendFormat_makeTexture2D(backend_format)
end

function Skia.BackendFormat.isValid(backend_format)
    return lib.GrBackendFormat_isValid(backend_format)
end

function Skia.BackendFormat.MakeMock(colorType, compression, isStencilFormat)
    return lib.GrBackendFormat_MakeMock(colorType, compression, isStencilFormat)
end

-- ## gr_backend_render_target
Skia.BackendRenderTarget = {}

function Skia.BackendRenderTarget.new()
    return lib.GrBackendRenderTarget_new()
end

function Skia.BackendRenderTarget.new_2(width, height, sampleCnt, stencilBits, mockInfo)
    return lib.GrBackendRenderTarget_new_2(width, height, sampleCnt, stencilBits, mockInfo)
end

function Skia.BackendRenderTarget.new_3(that)
    return lib.GrBackendRenderTarget_new_3(that)
end

function Skia.BackendRenderTarget.delete(backend_render_target)
    lib.GrBackendRenderTarget_delete(backend_render_target)
end

function Skia.BackendRenderTarget.dimensions(backend_render_target)
    return lib.GrBackendRenderTarget_dimensions(backend_render_target)
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
    return lib.GrBackendRenderTarget_getBackendFormat(backend_render_target)
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
    return lib.GrBackendSemaphore_new()
end

function Skia.BackendSemaphore.new_2(semaphore)
    return lib.GrBackendSemaphore_new_2(semaphore)
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
    return lib.GrBackendTexture_new()
end

function Skia.BackendTexture.new_2(width, height, midmapped, mockInfo, label)
    return lib.GrBackendTexture_new_2(width, height, midmapped, mockInfo, label)
end

function Skia.BackendTexture.new_3(that)
    return lib.GrBackendTexture_new_3(that)
end

function Skia.BackendTexture.delete(backend_texture)
    lib.GrBackendTexture_delete(backend_texture)
end

function Skia.BackendTexture.dimensions(backend_texture)
    return lib.GrBackendTexture_dimensions(backend_texture)
end

function Skia.BackendTexture.width(backend_texture)
    return lib.GrBackendTexture_width(backend_texture)
end

function Skia.BackendTexture.height(backend_texture)
    return lib.GrBackendTexture_height(backend_texture)
end

function Skia.BackendTexture.getLabel(backend_texture)
    return lib.GrBackendTexture_getLabel(backend_texture)
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
    return lib.GrBackendTexture_getBackendFormat(backend_texture)
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
    return lib.GrDirectContext_threadSafeProxy(direct_context)
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
    return lib.GrDirectContext_createBackendTexture(direct_context, width, height, format, mipmapped, renderable, isProtected, label)
end

function Skia.DirectContext.createBackendTexture_2(direct_context, width, height, type, mipmapped, renderable, isProtected, label)
    return lib.GrDirectContext_createBackendTexture_2(direct_context, width, height, type, mipmapped, renderable, isProtected, label)
end

function Skia.DirectContext.createBackendTexture_3(direct_context, width, height, format, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_3(direct_context, width, height, format, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
end

function Skia.DirectContext.createBackendTexture_4(direct_context, width, height, type, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_4(direct_context, width, height, type, color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label)
end

function Skia.DirectContext.createBackendTexture_5(direct_context, srcData, numLevels, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_5(direct_context, srcData, numLevels, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
end

function Skia.DirectContext.createBackendTexture_6(direct_context, srcData, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_6(direct_context, srcData, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label)
end

function Skia.DirectContext.createBackendTexture_7(direct_context, srcData, numLevels, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_7(direct_context, srcData, numLevels, renderable, isProtected, finishedProc, finishedContext, label)
end

function Skia.DirectContext.createBackendTexture_8(direct_context, srcData, renderable, isProtected, finishedProc, finishedContext, label)
    return lib.GrDirectContext_createBackendTexture_8(direct_context, srcData, renderable, isProtected, finishedProc, finishedContext, label)
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
    return lib.GrDirectContext_createCompressedBackendTexture(direct_context, width, height, format, color, mipmapped, isProtected, finishedProc, finishedContext)
end

function Skia.DirectContext.createCompressedBackendTexture_2(direct_context, width, height, type, color, mipmapped, isProtected, finishedProc, finishedContext)
    return lib.GrDirectContext_createCompressedBackendTexture_2(direct_context, width, height, type, color, mipmapped, isProtected, finishedProc, finishedContext)
end

function Skia.DirectContext.createCompressedBackendTexture_3(direct_context, width, height, format, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    return lib.GrDirectContext_createCompressedBackendTexture_3(direct_context, width, height, format, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
end

function Skia.DirectContext.createCompressedBackendTexture_4(direct_context, width, height, type, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
    return lib.GrDirectContext_createCompressedBackendTexture_4(direct_context, width, height, type, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext)
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
    return lib.GrDirectContext_directContextID(direct_context)
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
    return lib.GrDirectContext_skCapabilities(direct_context)
end

function Skia.DirectContext.MakeMock(mockOptions, contextOptions)
    return lib.GrDirectContext_MakeMock(mockOptions, contextOptions)
end

function Skia.DirectContext.MakeMock_2(mockOptions)
    return lib.GrDirectContext_MakeMock_2(mockOptions)
end

-- ## gr_driver_bug_workarounds
Skia.DriverBugWorkarounds = {}

function Skia.DriverBugWorkarounds.new()
    return lib.GrDriverBugWorkarounds_new()
end

function Skia.DriverBugWorkarounds.new_2(driverBugWorkarounds)
    return lib.GrDriverBugWorkarounds_new_2(driverBugWorkarounds)
end

function Skia.DriverBugWorkarounds.new_3(workarounds)
    return lib.GrDriverBugWorkarounds_new_3(workarounds)
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
    return lib.GrRecordingContext_skCapabilities(recordingContext)
end

-- ## gr_yuva_backend_texture_info
Skia.YUVABackendTextureInfo = {}

function Skia.YUVABackendTextureInfo.new()
    return lib.GrYUVABackendTextureInfo_new()
end

function Skia.YUVABackendTextureInfo.new_2(yuvaInfo, backendFormat, mipmapped, surfaceOrigin)
    return lib.GrYUVABackendTextureInfo_new_2(yuvaInfo, backendFormat, mipmapped, surfaceOrigin)
end

function Skia.YUVABackendTextureInfo.new_3(yuvaBackendTextureInfo)
    return lib.GrYUVABackendTextureInfo_new_3(yuvaBackendTextureInfo)
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
    return lib.GrYUVABackendTextures_new()
end

function Skia.YUVABackendTextures.new_2(yuvaInfo, backendTexture, textureOrigin)
    return lib.GrYUVABackendTextures_new_2(yuvaInfo, backendTexture, textureOrigin)
end

function Skia.YUVABackendTextures.delete(yuvaBackendTextures)
    lib.GrYUVABackendTextures_delete(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.textures(yuvaBackendTextures)
    return lib. GrYUVABackendTextures_textures(yuvaBackendTextures)
end

function Skia.YUVABackendTextures.texture(yuvaBackendTextures, i)
    return lib.GrYUVABackendTextures_texture(yuvaBackendTextures, i)
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
    return lib.SkAndroidCodec_computeOutputColorSpace(androidCodec, outputColorType, prefColorSpace)
end

function Skia.AndroidCodec.computeSampleSize(androidCodec, size)
    return lib.SkAndroidCodec_computeSampleSize(androidCodec, size)
end

function Skia.AndroidCodec.getSampledDimensions(androidCodec, sampleSize)
    return lib.SkAndroidCodec_getSampledDimensions(androidCodec, sampleSize)
end

function Skia.AndroidCodec.getSupportedSubset(androidCodec, desiredSubset)
    return lib.SkAndroidCodec_getSupportedSubset(androidCodec, desiredSubset)
end

function Skia.AndroidCodec.getSampledSubsetDimensions(androidCodec, sampleSize, subset)
    return lib.SkAndroidCodec_getSampledSubsetDimensions(androidCodec, sampleSize, subset)
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
    return lib.SkAndroidCodec_MakeFromCodec(codec)
end

function Skia.AndroidCodec.MakeFromStream(codec, pngChunkReader)
    return lib.SkAndroidCodec_MakeFromStream(codec, pngChunkReader)
end

function Skia.AndroidCodec.MakeFromData(codec, pngChunkReader)
    return lib.SkAndroidCodec_MakeFromData(codec, pngChunkReader)
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
Skia. = {}

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

function Skia.Bitmap.new(void)
    return lib.SkBitmap_new(void)
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
    return lib.SkBitmap_asImage(bitmap)
end

function Skia.Bitmap.bounds(bitmap)
    return lib.SkBitmap_bounds(bitmap)
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
    return lib.SkBitmap_dimensions(bitmap)
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
    return lib.SkBitmap_getColor4f(bitmap, x, y)
end

function Skia.Bitmap.getGenerationID(bitmap)
    return lib.SkBitmap_getGenerationID(bitmap)
end

function Skia.Bitmap.getPixels(bitmap)
    return lib.SkBitmap_getPixels(bitmap)
end

function Skia.Bitmap.getSubset(bitmap)
    return lib.SkBitmap_getSubset(bitmap)
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
    return lib.SkBitmap_makeShader(bitmap, sampling, lm)
end

function Skia.Bitmap.makeShader_2(bitmap, sampling, lm)
    return lib.SkBitmap_makeShader_2(bitmap, sampling, lm)
end

function Skia.Bitmap.makeShader_3(bitmap, tmx, tmy, sampling, localMatrix)
    return lib.SkBitmap_makeShader_3(bitmap, tmx, tmy, sampling, localMatrix)
end

function Skia.Bitmap.makeShader_4(bitmap, tmx, tmy, sampling, lm)
    return lib.SkBitmap_makeShader_4(bitmap, tmx, tmy, sampling, lm)
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
    return lib.SkBitmap_pixelRefOrigin(bitmap)
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
    return lib.SkBitmap_refColorSpace(bitmap)
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
    return lib.SkBlender_getFactory(blender)
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
    return lib.SkBlender_serialize(blender, serial_procs)
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
    return lib.SkBlender_Mode(mode)
end

function Skia.Blender.NameToFactory(char name)
    return lib.SkBlender_NameToFactory(char name)
end

function Skia.Blender.FactoryToName(factory)
    return lib.SkBlender_FactoryToName(factory)
end

function Skia.Blender.Register(name, factory)
    lib.SkBlender_Register(name, factory)
end

function Skia.Blender.Deserialize(type, data, length, procs)
    return lib.SkBlender_Deserialize(type, data, length, procs)
end

-- ## sk_blenders
Skia.Blenders = {}

function Skia.Blenders.Arithmetic(k1, k2, k3, k4, enforcePremul)
    return lib.SkBlenders_Arithmetic(k1, k2, k3, k4, enforcePremul)
end

-- ## sk_bmp_decoder
Skia.BmpDecoder = {}

function Skia.BmpDecoder.Decode(stream, result, decodeContext)
    return lib.SkBmpDecoder_Decode(stream, result, decodeContext)
end

function Skia.BmpDecoder.Decode_2(stream, result, decodeContext)
    return lib.SkBmpDecoder_Decode_2(stream, result, decodeContext)
end

function Skia.BmpDecoder.Decoder()
    return lib.SkBmpDecoder_Decoder()
end

-- ## sk_canvas
Skia.Canvas = {}

function Skia.Canvas.new()
    return lib.SkCanvas_new()
end

function Skia.Canvas.new_2(width, height, props)
    return lib.SkCanvas_new_2(width, height, props)
end

function Skia.Canvas.new_3(bitmap)
    return lib.SkCanvas_new_3(bitmap)
end

function Skia.Canvas.new_4(bitmap, props)
    return lib.SkCanvas_new_4(bitmap, props)
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
    return lib.SkCanvas_getBaseLayerSize(canvas)
end

function Skia.Canvas.getBaseProps(canvas)
    return lib.SkCanvas_getBaseProps(canvas)
end

function Skia.Canvas.getDeviceClipBounds(canvas)
    return lib.SkCanvas_getDeviceClipBounds(canvas)
end

function Skia.Canvas.getDeviceClipBounds_2(canvas, bounds)
    return lib.SkCanvas_getDeviceClipBounds_2(canvas, bounds)
end

function Skia.Canvas.getLocalClipBounds(canvas)
    return lib.SkCanvas_getLocalClipBounds(canvas)
end

function Skia.Canvas.getLocalClipBounds_2(canvas, bounds)
    return lib.SkCanvas_getLocalClipBounds_2(canvas, bounds)
end

function Skia.Canvas.getLocalToDevice(canvas)
    return lib.SkCanvas_getLocalToDevice(canvas)
end

function Skia.Canvas.getLocalToDeviceAs3x3(canvas)
    return lib.SkCanvas_getLocalToDeviceAs3x3(canvas)
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
    return lib.SkCanvas_getTopProps(canvas)
end

function Skia.Canvas.getTotalMatrix(canvas)
    return lib.SkCanvas_getTotalMatrix(canvas)
end

function Skia.Canvas.imageInfo(canvas)
    return lib.SkCanvas_imageInfo(canvas)
end

function Skia.Canvas.isClipEmpty(canvas)
    return lib.SkCanvas_isClipEmpty(canvas)
end

function Skia.Canvas.isClipRect(canvas)
    return lib.SkCanvas_isClipRect(canvas)
end

function Skia.Canvas.makeSurface(canvas, info, props)
    return lib.SkCanvas_makeSurface(canvas, info, props)
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

function Skia.Canvas.saveLayerAlpha(canvas, bounds, void alpha)
    return lib.SkCanvas_saveLayerAlpha(canvas, bounds, void alpha)
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
    return lib.SkCanvas_MakeRasterDirect(info, pixels, rowBytes, props)
end

function Skia.Canvas.MakeRasterDirectN32(width, height, pixels, rowBytes)
    return lib.SkCanvas_MakeRasterDirectN32(width, height, pixels, rowBytes)
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
    return lib.SkCapabilities_RasterBackend()
end

-- ## sk_codec
Skia.Codec = {}

function Skia.Codec.delete(codec)
    lib.SkCodec_delete(codec)
end

function Skia.Codec.getInfo(codec)
    return lib.SkCodec_getInfo(codec)
end

function Skia.Codec.dimensions(codec)
    return lib.SkCodec_dimensions(codec)
end

function Skia.Codec.bounds(codec)
    return lib.SkCodec_bounds(codec)
end

function Skia.Codec.getICCProfile(codec)
    return lib.SkCodec_getICCProfile(codec)
end

function Skia.Codec.getOrigin(codec)
    return lib.SkCodec_getOrigin(codec)
end

function Skia.Codec.getScaledDimensions(codec, desiredScale)
    return lib.SkCodec_getScaledDimensions(codec, desiredScale)
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

function Skia.Codec.incrementalDecode(codec, int rowsDecoded)
    return lib.SkCodec_incrementalDecode(codec, int rowsDecoded)
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

char* SkCodec_ResultToString(result)
function Skia.Codec.MakeFromStream(stream, result, pngChunkReader, selectionPolicy)
    return lib.SkCodec_MakeFromStream(stream, result, pngChunkReader, selectionPolicy)
end

function Skia.Codec.MakeFromData(stream, pngChunkReader)
    return lib.SkCodec_MakeFromData(stream, pngChunkReader)
end

-- ## sk_codecs
Skia. = {}

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
    return lib.SkColorFilter_filterColor4f(color_filter, srcColor, srcCS, dstCS)
end

function Skia.ColorFilter.makeComposed(color_filter, inner)
    return lib.SkColorFilter_makeComposed(color_filter, inner)
end

function Skia.ColorFilter.makeWithWorkingColorSpace(color_filter, colorSpace)
    return lib.SkColorFilter_makeWithWorkingColorSpace(color_filter, colorSpace)
end

function Skia.ColorFilter.getFactory(color_filter)
    return lib.SkColorFilter_getFactory(color_filter)
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
    return lib.SkColorFilter_serialize(color_filter, serial_procs)
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
    return lib.SkColorFilter_Deserialize(data, size, procs)
end

function Skia.ColorFilter.NameToFactory(name)
    return lib.SkColorFilter_NameToFactory(name)
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
    return lib.SkColorFilters_Blend(c, color_space, mode)
end

function Skia.ColorFilters.Blend_2(c, mode)
    return lib.SkColorFilters_Blend_2(c, mode)
end

function Skia.ColorFilters.Compose(color_filter1, color_filter2)
    return lib.SkColorFilters_Compose(color_filter1, color_filter2)
end

function Skia.ColorFilters.HSLAMatrix(rowMajor)
    return lib.SkColorFilters_HSLAMatrix(rowMajor)
end

function Skia.ColorFilters.HSLAMatrix_2(matrix)
    return lib.SkColorFilters_HSLAMatrix_2(matrix)
end

function Skia.ColorFilters.Lerp(t, color_filter1, color_filter2)
    return lib.SkColorFilters_Lerp(t, color_filter1, color_filter2)
end

function Skia.ColorFilters.Lighting(mul, add)
    return lib.SkColorFilters_Lighting(mul, add)
end

function Skia.ColorFilters.LinearToSRGBGamma()
    return lib.SkColorFilters_LinearToSRGBGamma()
end

function Skia.ColorFilters.Matrix(rowMajor)
    return lib.SkColorFilters_Matrix(rowMajor)
end

function Skia.ColorFilters.Matrix_2(matrix)
    return lib.SkColorFilters_Matrix_2(matrix)
end

function Skia.ColorFilters.SRGBToLinearGamma()
    return lib.SkColorFilters_SRGBToLinearGamma()
end

function Skia.ColorFilters.Table(utable)
    return lib.SkColorFilters_Table(utable)
end

function Skia.ColorFilters.Table_2(color_table)
    return lib.SkColorFilters_Table_2(color_table)
end

function Skia.ColorFilters.TableARGB(utableA, tableR, tableG, tableB)
    return lib.SkColorFilters_TableARGB(utableA, tableR, tableG, tableB)
end

-- ## sk_color_info
Skia.ColorInfo = {}

function Skia.ColorInfo.new()
    return lib.SkColorInfo_new()
end

function Skia.ColorInfo.new_2(ct, at, color_space)
    return lib.SkColorInfo_new_2(ct, at, color_space)
end

function Skia.ColorInfo.new_3(color_info)
    return lib.SkColorInfo_new_3(color_info)
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
    return lib.SkColorInfo_makeAlphaType(color_info, newAlphaType)
end

function Skia.ColorInfo.makeColorSpace(color_info, color_space)
    return lib.SkColorInfo_makeColorSpace(color_info, color_space)
end

function Skia.ColorInfo.makeColorType(color_info, newColorType)
    return lib.SkColorInfo_makeColorType(color_info, newColorType)
end

function Skia.ColorInfo.refColorSpace(color_info)
    return lib.SkColorInfo_refColorSpace(color_info)
end

function Skia.ColorInfo.shiftPerPixel(color_info)
    return lib.SkColorInfo_shiftPerPixel(color_info)
end

-- ## sk_color_matrix
Skia.ColorMatrix = {}

function Skia.ColorMatrix.new()
    return lib.SkColorMatrix_new()
end

function Skia.ColorMatrix.new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)
    return lib.SkColorMatrix_new_2(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34)
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
    return lib.SkColorMatrix_RGBtoYUV(color_space)
end

function Skia.ColorMatrix.YUVtoRGB(color_space)
    return lib.SkColorMatrix_YUVtoRGB(color_space)
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
    return lib.SkColorMatrixFilter_filterColor4f(color_matrix_filter, srcColor, srcCS, dstCS)
end

function Skia.ColorMatrixFilter.makeComposed(color_matrix_filter, colorFilter)
    return lib.SkColorMatrixFilter_makeComposed(color_matrix_filter, colorFilter)
end

function Skia.ColorMatrixFilter.makeWithWorkingColorSpace(color_matrix_filter, colorSpace)
    return lib.SkColorMatrixFilter_makeWithWorkingColorSpace(color_matrix_filter, colorSpace)
end

function Skia.ColorMatrixFilter.getFactory(color_matrix_filter)
    return lib.SkColorMatrixFilter_getFactory(color_matrix_filter)
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
    return lib.SkColorMatrixFilter_serialize(color_matrix_filter, serial_procs)
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
    return lib.SkColorMatrixFilter_MakeLightingFilter(mul, add)
end

function Skia.ColorMatrixFilter.Deserialize(data, size, procs)
    return lib.SkColorMatrixFilter_Deserialize(data, size, procs)
end

function Skia.ColorMatrixFilter.NameToFactory(name)
    return lib.SkColorMatrixFilter_NameToFactory(name)
end

function Skia.ColorMatrixFilter.FactoryToName(factory)
    return lib. SkColorMatrixFilter_FactoryToName(factory)
end

function Skia.ColorMatrixFilter.Register(name, factory)
    lib.SkColorMatrixFilter_Register(name, factory)
end

-- ## sk_color_priv
Skia. = {}

unsigned SkColorPriv_SkAlpha255To256(alpha)
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
    return lib.SkColorSpace_makeLinearGamma(color_space)
end

function Skia.ColorSpace.makeSRGBGamma(color_space)
    return lib.SkColorSpace_makeSRGBGamma(color_space)
end

function Skia.ColorSpace.makeColorSpin(color_space)
    return lib.SkColorSpace_makeColorSpin(color_space)
end

function Skia.ColorSpace.isSRGB(color_space)
    return lib.SkColorSpace_isSRGB(color_space)
end

function Skia.ColorSpace.serialize(color_space)
    return lib.SkColorSpace_serialize(color_space)
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
    return lib.SkColorSpace_MakeSRGB()
end

function Skia.ColorSpace.MakeSRGBLinear()
    return lib.SkColorSpace_MakeSRGBLinear()
end

function Skia.ColorSpace.MakeRGB(transferFn, toXYZ)
    return lib.SkColorSpace_MakeRGB(transferFn, toXYZ)
end

function Skia.ColorSpace.Make(profile)
    return lib.SkColorSpace_Make(profile)
end

function Skia.ColorSpace.Deserialize(data, length)
    return lib.SkColorSpace_Deserialize(data, length)
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
    return lib.SkColorTable_Make(utable)
end

function Skia.ColorTable.Make_2(utableA, tableR, tableG, tableB)
    return lib.SkColorTable_Make_2(utableA, tableR, tableG, tableB)
end

function Skia.ColorTable.Deserialize(buffer)
    return lib.SkColorTable_Deserialize(buffer)
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
    return lib.SkContourMeasureIter_new()
end

function Skia.ContourMeasureIter.new_2(path, forceClosed, resScale)
    return lib.SkContourMeasureIter_new_2(path, forceClosed, resScale)
end

function Skia.ContourMeasureIter.delete(contour_measure_iter)
    lib.SkContourMeasureIter_delete(contour_measure_iter)
end

function Skia.ContourMeasureIter.reset(contour_measure_iter, path, forceClosed, resScale)
    lib.SkContourMeasureIter_reset(contour_measure_iter, path, forceClosed, resScale)
end

function Skia.ContourMeasureIter.next(contour_measure_iter)
    return lib.SkContourMeasureIter_next(contour_measure_iter)
end

-- ## sk_corner_path_effect
Skia.CornerPathEffect = {}

function Skia.CornerPathEffect.delete(cornerPathEffect)
    lib.SkCornerPathEffect_delete(cornerPathEffect)
end

function Skia.CornerPathEffect.Make(radius)
    return lib.SkCornerPathEffect_Make(radius)
end

function Skia.CornerPathEffect.RegisterFlattenables()
    lib.SkCornerPathEffect_RegisterFlattenables()
end

-- ## sk_cubic_map
Skia.CubicMap = {}

function Skia.CubicMap.delete(cubic_map)
    lib.SkCubicMap_delete(cubic_map)
end

function Skia.CubicMap.new(p1, p2)
    return lib.SkCubicMap_new(p1, p2)
end

function Skia.CubicMap.computeYFromX(cubic_map, x)
    return lib.SkCubicMap_computeYFromX(cubic_map, x)
end

function Skia.CubicMap.computeFromT(cubic_map, t)
    return lib.SkCubicMap_computeFromT(cubic_map, t)
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
    return lib.SkCubicResampler_Mitchell()
end

function Skia.CubicResampler.CatmullRom()
    return lib.SkCubicResampler_CatmullRom()
end

-- ## sk_dash_path_effect
Skia.DashPathEffect = {}

function Skia.DashPathEffect.delete(dashPathEffect)
    lib.SkDashPathEffect_delete(dashPathEffect)
end

function Skia.DashPathEffect.Make(intervals, count, phase)
    return lib.SkDashPathEffect_Make(intervals, count, phase)
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
    return lib.SkData_MakeWithCopy(data, length)
end

function Skia.Data.MakeUninitialized(length)
    return lib.SkData_MakeUninitialized(length)
end

function Skia.Data.MakeZeroInitialized(length)
    return lib.SkData_MakeZeroInitialized(length)
end

function Skia.Data.MakeWithCString(cstr)
    return lib.SkData_MakeWithCString(cstr)
end

function Skia.Data.MakeWithProc(ptr, length, proc, ctx)
    return lib.SkData_MakeWithProc(ptr, length, proc, ctx)
end

function Skia.Data.MakeWithoutCopy(data, length)
    return lib.SkData_MakeWithoutCopy(data, length)
end

function Skia.Data.MakeFromMalloc(data, length)
    return lib.SkData_MakeFromMalloc(data, length)
end

function Skia.Data.MakeFromFileName(path)
    return lib.SkData_MakeFromFileName(path)
end

function Skia.Data.MakeFromFILE(f)
    return lib.SkData_MakeFromFILE(f)
end

function Skia.Data.MakeFromFD(fd)
    return lib.SkData_MakeFromFD(fd)
end

function Skia.Data.MakeFromStream(stream, size)
    return lib.SkData_MakeFromStream(stream, size)
end

function Skia.Data.MakeSubset(src, offset, length)
    return lib.SkData_MakeSubset(src, offset, length)
end

function Skia.Data.MakeEmpty()
    return lib.SkData_MakeEmpty()
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
    return lib.SkDataTable_MakeEmpty()
end

function Skia.DataTable.MakeCopyArrays(ptrs, sizes, count)
    return lib.SkDataTable_MakeCopyArrays(ptrs, sizes, count)
end

function Skia.DataTable.MakeCopyArray(array, elemSize, count)
    return lib.SkDataTable_MakeCopyArray(array, elemSize, count)
end

function Skia.DataTable.MakeArrayProc(array, elemSize, count, proc, context)
    return lib.SkDataTable_MakeArrayProc(array, elemSize, count, proc, context)
end

-- ## sk_discrete_path_effect
Skia.DiscretePathEffect = {}

function Skia.DiscretePathEffect.delete(discretePathEffect)
    lib.SkDiscretePathEffect_delete(discretePathEffect)
end

function Skia.DiscretePathEffect.Make(segLength, dev, seedAssist)
    return lib.SkDiscretePathEffect_Make(segLength, dev, seedAssist)
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
    return lib.SkDrawable_snapGpuDrawHandler(drawable, backendApi, matrix, clipBounds, bufferInfo)
end

function Skia.Drawable.makePictureSnapshot(drawable)
    return lib.SkDrawable_makePictureSnapshot(drawable)
end

function Skia.Drawable.getGenerationID(drawable)
    return lib.SkDrawable_getGenerationID(drawable)
end

function Skia.Drawable.getBounds(drawable)
    return lib.SkDrawable_getBounds(drawable)
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
    return lib.SkDrawable_getFactory(drawable)
end

function Skia.Drawable.getTypeName(drawable)
    return lib. SkDrawable_getTypeName(drawable)
end

function Skia.Drawable.flatten(drawable, write_buffer)
    lib.SkDrawable_flatten(drawable, write_buffer)
end

function Skia.Drawable.serialize(drawable, serial_procs)
    return lib.SkDrawable_serialize(drawable, serial_procs)
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
    return lib.SkDrawable_Deserialize(data, size, procs)
end

function Skia.Drawable.NameToFactory(char name)
    return lib.SkDrawable_NameToFactory(char name)
end

function Skia.Drawable.FactoryToName(factory)
    return lib. SkDrawable_FactoryToName(factory)
end

function Skia.Drawable.Register(char name, factory)
    lib.SkDrawable_Register(char name, factory)
end

-- ## sk_dynamic_memory_w_stream
Skia.DynamicMemoryWStream = {}

function Skia.DynamicMemoryWStream.new()
    return lib.SkDynamicMemoryWStream_new()
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
    return lib.SkDynamicMemoryWStream_detachAsData(dynamic_memory_w_stream)
end

function Skia.DynamicMemoryWStream.detachAsStream(dynamic_memory_w_stream)
    return lib.SkDynamicMemoryWStream_detachAsStream(dynamic_memory_w_stream)
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

function Skia.DynamicMemoryWStream.writeText(dynamic_memory_w_stream, char text)
    return lib.SkDynamicMemoryWStream_writeText(dynamic_memory_w_stream, char text)
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
    return lib.SkEncodedOrigin_SkEncodedOriginToMatrix(origin, w, h)
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
    return lib.SkExecutor_MakeFIFOThreadPool(threads, allowBorrowing)
end

function Skia.Executor.MakeLIFOThreadPool(threads, allowBorrowing)
    return lib.SkExecutor_MakeLIFOThreadPool(threads, allowBorrowing)
end

function Skia.Executor.GetDefault()
    return lib.SkExecutor_GetDefault()
end

function Skia.Executor.SetDefault(executor)
    lib.SkExecutor_SetDefault(executor)
end

-- ## sk_file_stream
Skia.FILEStream = {}

function Skia.FILEStream.new(char path)
    return lib.SkFILEStream_new(char path)
end

function Skia.FILEStream.new_2(file)
    return lib.SkFILEStream_new_2(file)
end

function Skia.FILEStream.new_3(file, size)
    return lib.SkFILEStream_new_3(file, size)
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
    return lib.SkFILEStream_duplicate(file_stream)
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
    return lib.SkFILEStream_fork(file_stream)
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

function Skia.FILEStream.Make(char path)
    return lib.SkFILEStream_Make(char path)
end

-- ## sk_file_w_stream
Skia.FILEWStream = {}

function Skia.FILEWStream.new(char path)
    return lib.SkFILEWStream_new(char path)
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

function Skia.FILEWStream.writeText(file_w_stream, char text)
    return lib.SkFILEWStream_writeText(file_w_stream, char text)
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
    return lib.SkFlattenable_getFactory(flattenable)
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
    return lib.SkFlattenable_serialize(flattenable, serial_procs)
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

function Skia.Flattenable.NameToFactory(char name)
    return lib.SkFlattenable_NameToFactory(char name)
end

function Skia.Flattenable.FactoryToName(factory)
    return lib. SkFlattenable_FactoryToName(factory)
end

function Skia.Flattenable.Register(char name, factory)
    lib.SkFlattenable_Register(char name, factory)
end

function Skia.Flattenable.Deserialize(type, data, length, procs)
    return lib.SkFlattenable_Deserialize(type, data, length, procs)
end

-- ## sk_font
Skia.Font = {}

function Skia.Font.new()
    return lib.SkFont_new()
end

function Skia.Font.new_2(typeface, size)
    return lib.SkFont_new_2(typeface, size)
end

function Skia.Font.new_3(typeface)
    return lib.SkFont_new_3(typeface)
end

function Skia.Font.new_4(typeface, size, scaleX, skewX)
    return lib.SkFont_new_4(typeface, size, scaleX, skewX)
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
    return lib.SkFont_makeWithSize(font, size)
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
    return lib.SkFont_refTypeface(font)
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
    return lib.SkFontArguments_new()
end

function Skia.FontArguments.delete(font_arguments)
    lib.SkFontArguments_delete(font_arguments)
end

function Skia.FontArguments.setCollectionIndex(font_argments, collectionIndex)
    return lib.SkFontArguments_setCollectionIndex(font_argments, collectionIndex)
end

function Skia.FontArguments.setVariationDesignPosition(font_argments, position)
    return lib.SkFontArguments_setVariationDesignPosition(font_argments, position)
end

function Skia.FontArguments.getCollectionIndex(font_argments)
    return lib.SkFontArguments_getCollectionIndex(font_argments)
end

function Skia.FontArguments.getVariationDesignPosition(font_argments)
    return lib.SkFontArguments_getVariationDesignPosition(font_argments)
end

function Skia.FontArguments.setPalette(font_argments, palette)
    return lib.SkFontArguments_setPalette(font_argments, palette)
end

function Skia.FontArguments.getPalette(font_argments)
    return lib.SkFontArguments_getPalette(font_argments)
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
    return lib.SkFontMgr_matchFamilyStyle(font_mgr, familyName, font_style)
end

function Skia.FontMgr.matchFamilyStyleCharacter(font_mgr, familyName, font_style, bcp47, bcp47Count, character)
    return lib.SkFontMgr_matchFamilyStyleCharacter(font_mgr, familyName, font_style, bcp47, bcp47Count, character)
end

function Skia.FontMgr.makeFromData(font_mgr, data, ttcIndex)
    return lib.SkFontMgr_makeFromData(font_mgr, data, ttcIndex)
end

function Skia.FontMgr.makeFromStream(font_mgr, stream_asset, ttcIndex)
    return lib.SkFontMgr_makeFromStream(font_mgr, stream_asset, ttcIndex)
end

function Skia.FontMgr.makeFromStream_2(font_mgr, stream_asset, font_argments)
    return lib.SkFontMgr_makeFromStream_2(font_mgr, stream_asset, font_argments)
end

function Skia.FontMgr.makeFromFile(font_mgr, path, ttcIndex)
    return lib.SkFontMgr_makeFromFile(font_mgr, path, ttcIndex)
end

function Skia.FontMgr.legacyMakeTypeface(font_mgr, familyName, style)
    return lib.SkFontMgr_legacyMakeTypeface(font_mgr, familyName, style)
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
    return lib.SkFontMgr_RefEmpty()
end

function Skia.FontMgr.RefDefault()
    return lib.SkFontMgr_RefDefault()
end

-- ## sk_font_mgr_fontconfig
Skia. = {}

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
    return lib.SkFontStyleSet_createTypeface(font_style_set, index)
end

function Skia.FontStyleSet.matchStyle(font_style_set, pattern)
    return lib.SkFontStyleSet_matchStyle(font_style_set, pattern)
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

-- ## sk_gif_decoder
Skia.GifDecoder = {}

function Skia.GifDecoder.IsGif(ptr, size)
    return lib.SkGifDecoder_IsGif(ptr, size)
end

function Skia.GifDecoder.Decode(static_stream, result, decodeContext)
    return lib.SkGifDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.GifDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkGifDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.GifDecoder.Decoder()
    return lib.SkGifDecoder_Decoder()
end

-- ## sk_gradient_shader
Skia.GradientShader = {}

function Skia.GradientShader.delete(gradientShader)
    lib.SkGradientShader_delete(gradientShader)
end

function Skia.GradientShader.MakeLinear(pts, colors, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeLinear(pts, colors, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeLinear_2(pts, colors, color_space, pos, count, mode, interpolation, localMatrix)
    return lib.SkGradientShader_MakeLinear_2(pts, colors, color_space, pos, count, mode, interpolation, localMatrix)
end

function Skia.GradientShader.MakeLinear_3(pts, colors, color_space, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeLinear_3(pts, colors, color_space, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeRadial(center, radius, colors, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeRadial(center, radius, colors, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeRadial_2(center, radius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    return lib.SkGradientShader_MakeRadial_2(center, radius, colors, color_space, pos, count, mode, interpolation, localMatrix)
end

function Skia.GradientShader.MakeRadial_3(center, radius, colors, color_space, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeRadial_3(center, radius, colors, color_space, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeTwoPointConical(start, startRadius, end, endRadius, colors, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeTwoPointConical(start, startRadius, end, endRadius, colors, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeTwoPointConical_2(start, startRadius, end, endRadius, colors, color_space, pos, count, mode, interpolation, localMatrix)
    return lib.SkGradientShader_MakeTwoPointConical_2(start, startRadius, end, endRadius, colors, color_space, pos, count, mode, interpolation, localMatrix)
end

function Skia.GradientShader.MakeTwoPointConical_3(start, startRadius, end, endRadius, colors, color_space, pos, count, mode, flags, localMatrix)
    return lib.SkGradientShader_MakeTwoPointConical_3(start, startRadius, end, endRadius, colors, color_space, pos, count, mode, flags, localMatrix)
end

function Skia.GradientShader.MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    return lib.SkGradientShader_MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix)
end

function Skia.GradientShader.MakeSweep_2(cx, cy, colors, pos, count, flags, localMatrix)
    return lib.SkGradientShader_MakeSweep_2(cx, cy, colors, pos, count, flags, localMatrix)
end

function Skia.GradientShader.MakeSweep_3(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, interpolation, localMatrix)
    return lib.SkGradientShader_MakeSweep_3(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, interpolation, localMatrix)
end

function Skia.GradientShader.MakeSweep_4(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, flags, localMatrix)
    return lib.SkGradientShader_MakeSweep_4(cx, cy, colors, color_space, pos, count, mode, startAngle, endAngle, flags, localMatrix)
end

function Skia.GradientShader.MakeSweep_5(cx, cy, colors, color_space, pos, count, flags, localMatrix)
    return lib.SkGradientShader_MakeSweep_5(cx, cy, colors, color_space, pos, count, flags, localMatrix)
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
    return lib.SkHighContrastFilter_Make(config)
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
    return lib.SkIRect_topLeft(i_rect)
end

function Skia.IRect.width(i_rect)
    return lib.SkIRect_width(i_rect)
end

function Skia.IRect.height(i_rect)
    return lib.SkIRect_height(i_rect)
end

function Skia.IRect.size(i_rect)
    return lib.SkIRect_size(i_rect)
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

function Skia.IRect.setLTRB(i_rect, int32_t left, top, right, bottom)
    lib.SkIRect_setLTRB(i_rect, int32_t left, top, right, bottom)
end

function Skia.IRect.setXYWH(i_rect, int32_t x, y, width, height)
    lib.SkIRect_setXYWH(i_rect, int32_t x, y, width, height)
end

function Skia.IRect.setWH(i_rect, width, height)
    lib.SkIRect_setWH(i_rect, width, height)
end

function Skia.IRect.setSize(i_rect, size)
    lib.SkIRect_setSize(i_rect, size)
end

function Skia.IRect.makeOffset(i_rect, dx, dy)
    return lib.SkIRect_makeOffset(i_rect, dx, dy)
end

function Skia.IRect.makeOffset_2(i_rect, offset)
    return lib.SkIRect_makeOffset_2(i_rect, offset)
end

function Skia.IRect.makeInset(i_rect, dx, dy)
    return lib.SkIRect_makeInset(i_rect, dx, dy)
end

function Skia.IRect.makeOutset(i_rect, dx, dy)
    return lib.SkIRect_makeOutset(i_rect, dx, dy)
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

function Skia.IRect.adjust(i_rect, int32_t dL, dT, dR, dB)
    lib.SkIRect_adjust(i_rect, int32_t dL, dT, dR, dB)
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
    return lib.SkIRect_makeSorted(i_rect)
end

function Skia.IRect.MakeEmpty()
    return lib.SkIRect_MakeEmpty()
end

function Skia.IRect.MakeWH(w, h)
    return lib.SkIRect_MakeWH(w, h)
end

function Skia.IRect.MakeSize(size)
    return lib.SkIRect_MakeSize(size)
end

function Skia.IRect.MakePtSize(pt, size)
    return lib.SkIRect_MakePtSize(pt, size)
end

function Skia.IRect.MakeLTRB(int32_t l, t, r, b)
    return lib.SkIRect_MakeLTRB(int32_t l, t, r, b)
end

function Skia.IRect.MakeXYWH(int32_t x, y, w, h)
    return lib.SkIRect_MakeXYWH(int32_t x, y, w, h)
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
    return lib.SkISize_Make(w, h)
end

function Skia.ISize.MakeEmpty()
    return lib.SkISize_MakeEmpty()
end

-- ## sk_icc
Skia.ICC = {}

function Skia.ICC.SkWriteICCProfile(transferFunction, toXYZD50)
    return lib.SkICC_SkWriteICCProfile(transferFunction, toXYZD50)
end

function Skia.ICC.SkWriteICCProfile_2(iccProfile, char description)
    return lib.SkICC_SkWriteICCProfile_2(iccProfile, char description)
end

function Skia.ICC.SkICCFloatXYZD50ToGrid16Lab(float float_xyz, grid16_lab)
    lib.SkICC_SkICCFloatXYZD50ToGrid16Lab(float float_xyz, grid16_lab)
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
    return lib.SkIcoDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.IcoDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkIcoDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.IcoDecoder.Decoder()
    return lib.SkIcoDecoder_Decoder()
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
    return lib.SkImage_dimensions(image)
end

function Skia.Image.bounds(image)
    return lib.SkImage_bounds(image)
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

function cSkImage_olorSpace(image)
    return lib. cSkImage_olorSpace(image)
end

function Skia.Image.refColorSpace(image)
    return lib.SkImage_refColorSpace(image)
end

function Skia.Image.isAlphaOnly(image)
    return lib.SkImage_isAlphaOnly(image)
end

function Skia.Image.isOpaque(image)
    return lib.SkImage_isOpaque(image)
end

function Skia.Image.makeShader(image, tmx, tmy, sampling, localMatrix)
    return lib.SkImage_makeShader(image, tmx, tmy, sampling, localMatrix)
end

function Skia.Image.makeShader_2(image, tmx, tmy, sampling, lm)
    return lib.SkImage_makeShader_2(image, tmx, tmy, sampling, lm)
end

function Skia.Image.makeShader_3(image, sampling, lm)
    return lib.SkImage_makeShader_3(image, sampling, lm)
end

function Skia.Image.makeShader_4(image, sampling, lm)
    return lib.SkImage_makeShader_4(image, sampling, lm)
end

function Skia.Image.makeRawShader(image, tmx, tmy, sampling, localMatrix)
    return lib.SkImage_makeRawShader(image, tmx, tmy, sampling, localMatrix)
end

function Skia.Image.makeRawShader_2(image, tmx, tmy, sampling, lm)
    return lib.SkImage_makeRawShader_2(image, tmx, tmy, sampling, lm)
end

function Skia.Image.makeRawShader_3(image, sampling, lm)
    return lib.SkImage_makeRawShader_3(image, sampling, lm)
end

function Skia.Image.makeRawShader_4(image, sampling, lm)
    return lib.SkImage_makeRawShader_4(image, sampling, lm)
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
    return lib.SkImage_refEncodedData(image)
end

function Skia.Image.makeSubset(image, direct, subset)
    return lib.SkImage_makeSubset(image, direct, subset)
end

function Skia.Image.makeSubset_2(image, recorder, subset, properties)
    return lib.SkImage_makeSubset_2(image, recorder, subset, properties)
end

function Skia.Image.hasMipmaps(image)
    return lib.SkImage_hasMipmaps(image)
end

function Skia.Image.isProtected(image)
    return lib.SkImage_isProtected(image)
end

function Skia.Image.withDefaultMipmaps(image)
    return lib.SkImage_withDefaultMipmaps(image)
end

function Skia.Image.makeNonTextureImage(image, context)
    return lib.SkImage_makeNonTextureImage(image, context)
end

function Skia.Image.makeRasterImage(image, context, cachingHint)
    return lib.SkImage_makeRasterImage(image, context, cachingHint)
end

function Skia.Image.makeRasterImage_2(image, cachingHint)
    return lib.SkImage_makeRasterImage_2(image, cachingHint)
end

function Skia.Image.asLegacyBitmap(image, bitmap, legacyBitmapMode)
    return lib.SkImage_asLegacyBitmap(image, bitmap, legacyBitmapMode)
end

function Skia.Image.isLazyGenerated(image)
    return lib.SkImage_isLazyGenerated(image)
end

function Skia.Image.makeColorSpace(image, direct, color_space)
    return lib.SkImage_makeColorSpace(image, direct, color_space)
end

function Skia.Image.makeColorSpace_2(image, recorder, color_space, properties)
    return lib.SkImage_makeColorSpace_2(image, recorder, color_space, properties)
end

function Skia.Image.makeColorTypeAndColorSpace(image, direct, targetColorType, color_space)
    return lib.SkImage_makeColorTypeAndColorSpace(image, direct, targetColorType, color_space)
end

function Skia.Image.makeColorTypeAndColorSpace_2(image, recorder, targetColorType, color_space, properties)
    return lib.SkImage_makeColorTypeAndColorSpace_2(image, recorder, targetColorType, color_space, properties)
end

function Skia.Image.reinterpretColorSpace(image, color_space)
    return lib.SkImage_reinterpretColorSpace(image, color_space)
end

-- ## sk_image_filter
Skia.ImageFilter = {}

function Skia.ImageFilter.delete(image_filter)
    lib.SkImageFilter_delete(image_filter)
end

function Skia.ImageFilter.filterBounds(image_filter, src, ctm, direction, inputRect)
    return lib.SkImageFilter_filterBounds(image_filter, src, ctm, direction, inputRect)
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
    return lib.SkImageFilter_computeFastBounds(image_filter, bounds)
end

function Skia.ImageFilter.canComputeFastBounds(image_filter)
    return lib.SkImageFilter_canComputeFastBounds(image_filter)
end

function Skia.ImageFilter.makeWithLocalMatrix(image_filter, matrix)
    return lib.SkImageFilter_makeWithLocalMatrix(image_filter, matrix)
end

function Skia.ImageFilter.getFactory(image_filter)
    return lib.SkImageFilter_getFactory(image_filter)
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
    return lib.SkImageFilter_serialize(image_filter, procs)
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
    return lib.SkImageFilter_Deserialize(data, size, procs)
end

function Skia.ImageFilter.NameToFactory(name)
    return lib.SkImageFilter_NameToFactory(name)
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
    return lib.SkImageFilters_Arithmetic(k1, k2, k3, k4, enforcePMColor, background, foreground, cropRect)
end

function Skia.ImageFilters.Blend(mode, background, foreground, cropRect)
    return lib.SkImageFilters_Blend(mode, background, foreground, cropRect)
end

function Skia.ImageFilters.Blend_2(blender, background, foreground, cropRect)
    return lib.SkImageFilters_Blend_2(blender, background, foreground, cropRect)
end

function Skia.ImageFilters.Blur(sigmaX, sigmaY, tileMode, input, cropRect)
    return lib.SkImageFilters_Blur(sigmaX, sigmaY, tileMode, input, cropRect)
end

function Skia.ImageFilters.Blur_2(sigmaX, sigmaY, input, cropRect)
    return lib.SkImageFilters_Blur_2(sigmaX, sigmaY, input, cropRect)
end

function Skia.ImageFilters.ColorFilter(cf, input, cropRect)
    return lib.SkImageFilters_ColorFilter(cf, input, cropRect)
end

function Skia.ImageFilters.Compose(outer, inner)
    return lib.SkImageFilters_Compose(outer, inner)
end

function Skia.ImageFilters.Crop(rect, tileMode, input)
    return lib.SkImageFilters_Crop(rect, tileMode, input)
end

function Skia.ImageFilters.Crop_2(rect, input)
    return lib.SkImageFilters_Crop_2(rect, input)
end

function Skia.ImageFilters.DisplacementMap(xChannelSelector, yChannelSelector, scale, displacement, color, cropRect)
    return lib.SkImageFilters_DisplacementMap(xChannelSelector, yChannelSelector, scale, displacement, color, cropRect)
end

function Skia.ImageFilters.DropShadow(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    return lib.SkImageFilters_DropShadow(dx, dy, sigmaX, sigmaY, color, input, cropRect)
end

function Skia.ImageFilters.DropShadowOnly(dx, dy, sigmaX, sigmaY, color, input, cropRect)
    return lib.SkImageFilters_DropShadowOnly(dx, dy, sigmaX, sigmaY, color, input, cropRect)
end

function Skia.ImageFilters.Empty()
    return lib.SkImageFilters_Empty()
end

function Skia.ImageFilters.Image(image, srcRect, dstRect, sampling)
    return lib.SkImageFilters_Image(image, srcRect, dstRect, sampling)
end

function Skia.ImageFilters.Image_2(image, sampling)
    return lib.SkImageFilters_Image_2(image, sampling)
end

function Skia.ImageFilters.Magnifier(lensBounds, zoomAmount, inset, sampling, input, cropRect)
    return lib.SkImageFilters_Magnifier(lensBounds, zoomAmount, inset, sampling, input, cropRect)
end

function Skia.ImageFilters.MatrixConvolution(kernelSize, kernel, gain, bias, kernelOffset, tileMode, convolveAlpha, input, cropRect)
    return lib.SkImageFilters_MatrixConvolution(kernelSize, kernel, gain, bias, kernelOffset, tileMode, convolveAlpha, input, cropRect)
end

function Skia.ImageFilters.MatrixTransform(matrix, sampling, input)
    return lib.SkImageFilters_MatrixTransform(matrix, sampling, input)
end

function Skia.ImageFilters.Merge(filters, count, cropRect)
    return lib.SkImageFilters_Merge(filters, count, cropRect)
end

function Skia.ImageFilters.Merge_2(first, second, cropRect)
    return lib.SkImageFilters_Merge_2(first, second, cropRect)
end

function Skia.ImageFilters.Offset(dx, dy, input, cropRect)
    return lib.SkImageFilters_Offset(dx, dy, input, cropRect)
end

function Skia.ImageFilters.Picture(picture, targetRect)
    return lib.SkImageFilters_Picture(picture, targetRect)
end

function Skia.ImageFilters.Picture_2(picture)
    return lib.SkImageFilters_Picture_2(picture)
end

function Skia.ImageFilters.RuntimeShader(builder, childShaderName, input)
    return lib.SkImageFilters_RuntimeShader(builder, childShaderName, input)
end

function Skia.ImageFilters.RuntimeShader_2(builder, sampleRadius, childShaderName, input)
    return lib.SkImageFilters_RuntimeShader_2(builder, sampleRadius, childShaderName, input)
end

function Skia.ImageFilters.RuntimeShader_3(builder, childShaderNames, inputs, inputCount)
    return lib.SkImageFilters_RuntimeShader_3(builder, childShaderNames, inputs, inputCount)
end

function Skia.ImageFilters.RuntimeShader_4(builder, maxSampleRadius, childShaderNames, inputs, inputCount)
    return lib.SkImageFilters_RuntimeShader_4(builder, maxSampleRadius, childShaderNames, inputs, inputCount)
end

function Skia.ImageFilters.Shader(shader, cropRect)
    return lib.SkImageFilters_Shader(shader, cropRect)
end

function Skia.ImageFilters.Shader_2(shader, dither, cropRect)
    return lib.SkImageFilters_Shader_2(shader, dither, cropRect)
end

function Skia.ImageFilters.Tile(src, dst, input)
    return lib.SkImageFilters_Tile(src, dst, input)
end

function Skia.ImageFilters.Dilate(radiusX, radiusY, input, cropRect)
    return lib.SkImageFilters_Dilate(radiusX, radiusY, input, cropRect)
end

function Skia.ImageFilters.Erode(radiusX, radiusY, input, cropRect)
    return lib.SkImageFilters_Erode(radiusX, radiusY, input, cropRect)
end

function Skia.ImageFilters.DistantLitDiffuse(direction, lightColor, surfaceScale, kd, input, cropRect)
    return lib.SkImageFilters_DistantLitDiffuse(direction, lightColor, surfaceScale, kd, input, cropRect)
end

function Skia.ImageFilters.PointLitDiffuse(location, lightColor, surfaceScale, kd, input, cropRect)
    return lib.SkImageFilters_PointLitDiffuse(location, lightColor, surfaceScale, kd, input, cropRect)
end

function Skia.ImageFilters.SpotLitDiffuse(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, input, cropRect)
    return lib.SkImageFilters_SpotLitDiffuse(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, input, cropRect)
end

function Skia.ImageFilters.DistantLitSpecular(direction, lightColor, surfaceScale, ks, shininess, input, cropRect)
    return lib.SkImageFilters_DistantLitSpecular(direction, lightColor, surfaceScale, ks, shininess, input, cropRect)
end

function Skia.ImageFilters.PointLitSpecular(location, lightColor, surfaceScale, ks, shininess, input, cropRect)
    return lib.SkImageFilters_PointLitSpecular(location, lightColor, surfaceScale, ks, shininess, input, cropRect)
end

function Skia.ImageFilters.SpotLitSpecular(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, input, cropRect)
    return lib.SkImageFilters_SpotLitSpecular(location, target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, input, cropRect)
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
    return lib.SkImageGenerator_refEncodedData(image_generator)
end

function Skia.ImageGenerator.getInfo(image_generator)
    return lib.SkImageGenerator_getInfo(image_generator)
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
    return lib.SkImageInfo_refColorSpace(image_info)
end

function Skia.ImageInfo.isEmpty(image_info)
    return lib.SkImageInfo_isEmpty(image_info)
end

function Skia.ImageInfo.colorInfo(image_info)
    return lib.SkImageInfo_colorInfo(image_info)
end

function Skia.ImageInfo.isOpaque(image_info)
    return lib.SkImageInfo_isOpaque(image_info)
end

function Skia.ImageInfo.dimensions(image_info)
    return lib.SkImageInfo_dimensions(image_info)
end

function Skia.ImageInfo.bounds(image_info)
    return lib.SkImageInfo_bounds(image_info)
end

function Skia.ImageInfo.gammaCloseToSRGB(image_info)
    return lib.SkImageInfo_gammaCloseToSRGB(image_info)
end

function Skia.ImageInfo.makeWH(image_info, newWidth, newHeight)
    return lib.SkImageInfo_makeWH(image_info, newWidth, newHeight)
end

function Skia.ImageInfo.makeDimensions(image_info, newSize)
    return lib.SkImageInfo_makeDimensions(image_info, newSize)
end

function Skia.ImageInfo.makeAlphaType(image_info, newAlphaType)
    return lib.SkImageInfo_makeAlphaType(image_info, newAlphaType)
end

function Skia.ImageInfo.makeColorType(image_info, newColorType)
    return lib.SkImageInfo_makeColorType(image_info, newColorType)
end

function Skia.ImageInfo.makeColorSpace(image_info, color_space)
    return lib.SkImageInfo_makeColorSpace(image_info, color_space)
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
    return lib.SkImageInfo_Make(width, height, ct, at)
end

function Skia.ImageInfo.Make_2(width, height, ct, at, color_space)
    return lib.SkImageInfo_Make_2(width, height, ct, at, color_space)
end

function Skia.ImageInfo.Make_3(dimensions, ct, at)
    return lib.SkImageInfo_Make_3(dimensions, ct, at)
end

function Skia.ImageInfo.Make_4(dimensions, ct, at, color_space)
    return lib.SkImageInfo_Make_4(dimensions, ct, at, color_space)
end

function Skia.ImageInfo.Make_5(dimensions, colorInfo)
    return lib.SkImageInfo_Make_5(dimensions, colorInfo)
end

function Skia.ImageInfo.MakeN32(width, height, at)
    return lib.SkImageInfo_MakeN32(width, height, at)
end

function Skia.ImageInfo.MakeN32_2(width, height, at, color_space)
    return lib.SkImageInfo_MakeN32_2(width, height, at, color_space)
end

function Skia.ImageInfo.MakeS32(width, height, at)
    return lib.SkImageInfo_MakeS32(width, height, at)
end

function Skia.ImageInfo.MakeN32Premul(width, height)
    return lib.SkImageInfo_MakeN32Premul(width, height)
end

function Skia.ImageInfo.MakeN32Premul_2(width, height, color_space)
    return lib.SkImageInfo_MakeN32Premul_2(width, height, color_space)
end

function Skia.ImageInfo.MakeN32Premul_3(dimensions)
    return lib.SkImageInfo_MakeN32Premul_3(dimensions)
end

function Skia.ImageInfo.MakeN32Premul_4(dimensions, color_space)
    return lib.SkImageInfo_MakeN32Premul_4(dimensions, color_space)
end

function Skia.ImageInfo.MakeA8(width, height)
    return lib.SkImageInfo_MakeA8(width, height)
end

function Skia.ImageInfo.MakeA8_2(dimensions)
    return lib.SkImageInfo_MakeA8_2(dimensions)
end

function Skia.ImageInfo.MakeUnknown(width, height)
    return lib.SkImageInfo_MakeUnknown(width, height)
end

function Skia.ImageInfo.MakeUnknown_2()
    return lib.SkImageInfo_MakeUnknown_2()
end

function Skia.ImageInfo.ByteSizeOverflowed(byteSize)
    return lib.SkImageInfo_ByteSizeOverflowed(byteSize)
end

-- ## sk_images
Skia.Images = {}

function Skia.Images.RasterFromBitmap(bitmap)
    return lib.SkImages_RasterFromBitmap(bitmap)
end

function Skia.Images.RasterFromCompressedTextureData(data, width, height, type)
    return lib.SkImages_RasterFromCompressedTextureData(data, width, height, type)
end

function Skia.Images.DeferredFromEncodedData(data)
    return lib.SkImages_DeferredFromEncodedData(data)
end

function Skia.Images.DeferredFromGenerator(image_generator)
    return lib.SkImages_DeferredFromGenerator(image_generator)
end

function Skia.Images.DeferredFromPicture(picture, dimensions, matrix, paint, bitDepth, color_space, props)
    return lib.SkImages_DeferredFromPicture(picture, dimensions, matrix, paint, bitDepth, color_space, props)
end

function Skia.Images.DeferredFromPicture_2(picture, dimensions, matrix, paint, bitDepth, color_space)
    return lib.SkImages_DeferredFromPicture_2(picture, dimensions, matrix, paint, bitDepth, color_space)
end

function Skia.Images.RasterFromPixmapCopy(pixmap)
    return lib.SkImages_RasterFromPixmapCopy(pixmap)
end

function Skia.Images.RasterFromPixmap(pixmap, rasterReleaseProc, releaseContext)
    return lib.SkImages_RasterFromPixmap(pixmap, rasterReleaseProc, releaseContext)
end

function Skia.Images.RasterFromData(info, data, rowBytes)
    return lib.SkImages_RasterFromData(info, data, rowBytes)
end

function Skia.Images.MakeWithFilter(image, filter, subset, clipBounds, outSubset, offset)
    return lib.SkImages_MakeWithFilter(image, filter, subset, clipBounds, outSubset, offset)
end

-- ## sk_jpeg_decoder
Skia.JpegDecoder = {}

function Skia.JpegDecoder.IsJpeg(ptr, size)
    return lib.SkJpegDecoder_IsJpeg(ptr, size)
end

function Skia.JpegDecoder.Decode(static_stream, result, decodeContext)
    return lib.SkJpegDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.JpegDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkJpegDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.JpegDecoder.Decoder()
    return lib.SkJpegDecoder_Decoder()
end

-- ## sk_jpeg_encoder
Skia.JpegEncoder = {}

function Skia.JpegEncoder.Encode(dst, src, options)
    return lib.SkJpegEncoder_Encode(dst, src, options)
end

function Skia.JpegEncoder.Encode_2(dst, src, srcColorSpace, options)
    return lib.SkJpegEncoder_Encode_2(dst, src, srcColorSpace, options)
end

function Skia.JpegEncoder.Encode_3(ctx, img, options)
    return lib.SkJpegEncoder_Encode_3(ctx, img, options)
end

function Skia.JpegEncoder.Make(dst, src, options)
    return lib.SkJpegEncoder_Make(dst, src, options)
end

function Skia.JpegEncoder.Make_2(dst, src, srcColorSpace, options)
    return lib.SkJpegEncoder_Make_2(dst, src, srcColorSpace, options)
end

-- ## sk_jpegxl_decoder
Skia. = {}

-- ## sk_line_2d_path_effect
Skia.Line2DPathEffect = {}

function Skia.Line2DPathEffect.delete(line2DPathEffect)
    lib.SkLine2DPathEffect_delete(line2DPathEffect)
end

function Skia.Line2DPathEffect.Make(width, matrix)
    return lib.SkLine2DPathEffect_Make(width, matrix)
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
    return lib.SkLumaColorFilter_Make()
end

-- ## sk_m_44
Skia.M44 = {}

function Skia.M44.new(src)
    return lib.SkM44_new(src)
end

function Skia.M44.new_2(src)
    return lib.SkM44_new_2(src)
end

function Skia.M44.new_3()
    return lib.SkM44_new_3()
end

function Skia.M44.new_4(a, b)
    return lib.SkM44_new_4(a, b)
end

function Skia.M44.new_5(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15)
    return lib.SkM44_new_5(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15)
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
    return lib.SkM44_row(m44, i)
end

function Skia.M44.col(m44, i)
    return lib.SkM44_col(m44, i)
end

function Skia.M44.setRow(m44, i, v)
    lib.SkM44_setRow(m44, i, v)
end

function Skia.M44.setCol(m44, i, v)
    lib.SkM44_setCol(m44, i, v)
end

function Skia.M44.setIdentity(m44)
    return lib.SkM44_setIdentity(m44)
end

function Skia.M44.setTranslate(m44, x, y, z)
    return lib.SkM44_setTranslate(m44, x, y, z)
end

function Skia.M44.setScale(m44, x, y, z)
    return lib.SkM44_setScale(m44, x, y, z)
end

function Skia.M44.setRotateUnitSinCos(m44, axis, sinAngle, cosAngle)
    return lib.SkM44_setRotateUnitSinCos(m44, axis, sinAngle, cosAngle)
end

function Skia.M44.setRotateUnit(m44, axis, radians)
    return lib.SkM44_setRotateUnit(m44, axis, radians)
end

function Skia.M44.setRotate(m44, axis, radians)
    return lib.SkM44_setRotate(m44, axis, radians)
end

function Skia.M44.setConcat(m44, a, b)
    return lib.SkM44_setConcat(m44, a, b)
end

function Skia.M44.preConcat(m44, m)
    return lib.SkM44_preConcat(m44, m)
end

function Skia.M44.preConcat_2(m44, matrix)
    return lib.SkM44_preConcat_2(m44, matrix)
end

function Skia.M44.postConcat(m44, m)
    return lib.SkM44_postConcat(m44, m)
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
    return lib.SkM44_transpose(m44)
end

function Skia.M44.dump(m44)
    lib.SkM44_dump(m44)
end

function Skia.M44.map(m44, x, y, z, w)
    return lib.SkM44_map(m44, x, y, z, w)
end

function Skia.M44.asM33(m44)
    return lib.SkM44_asM33(m44)
end

function Skia.M44.preTranslate(m44, x, y, z)
    return lib.SkM44_preTranslate(m44, x, y, z)
end

function Skia.M44.postTranslate(m44, x, y, z)
    return lib.SkM44_postTranslate(m44, x, y, z)
end

function Skia.M44.preScale(m44, x, y)
    return lib.SkM44_preScale(m44, x, y)
end

function Skia.M44.preScale_2(m44, x, y, z)
    return lib.SkM44_preScale_2(m44, x, y, z)
end

function Skia.M44.Rows(r0, r1, r2, r3)
    return lib.SkM44_Rows(r0, r1, r2, r3)
end

function Skia.M44.Cols(c0, c1, c2, c3)
    return lib.SkM44_Cols(c0, c1, c2, c3)
end

function Skia.M44.RowMajor(r)
    return lib.SkM44_RowMajor(r)
end

function Skia.M44.ColMajor(c)
    return lib.SkM44_ColMajor(c)
end

function Skia.M44.Translate(x, y, z)
    return lib.SkM44_Translate(x, y, z)
end

function Skia.M44.Scale(x, y, z)
    return lib.SkM44_Scale(x, y, z)
end

function Skia.M44.Rotate(axis, radians)
    return lib.SkM44_Rotate(axis, radians)
end

function Skia.M44.RectToRect(src, dst)
    return lib.SkM44_RectToRect(src, dst)
end

function Skia.M44.LookAt(eye, center, up)
    return lib.SkM44_LookAt(eye, center, up)
end

function Skia.M44.Perspective(near, far, angle)
    return lib.SkM44_Perspective(near, far, angle)
end

-- ## sk_malloc_pixel_ref
Skia.MallocPixelRef = {}

function Skia.MallocPixelRef.MakeAllocate(imageInfo, rowBytes)
    return lib.SkMallocPixelRef_MakeAllocate(imageInfo, rowBytes)
end

function Skia.MallocPixelRef.MakeWithData(void &imageInfo, rowBytes, data)
    return lib.SkMallocPixelRef_MakeWithData(void &imageInfo, rowBytes, data)
end

-- ## sk_mask_filter
Skia.MaskFilter = {}

function Skia.MaskFilter.delete(maskFilter)
    lib.SkMaskFilter_delete(maskFilter)
end

function Skia.MaskFilter.approximateFilteredBounds(mask_filter, src)
    return lib.SkMaskFilter_approximateFilteredBounds(mask_filter, src)
end

function Skia.MaskFilter.getFactory(mask_filter)
    return lib.SkMaskFilter_getFactory(mask_filter)
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
    return lib.SkMaskFilter_serialize(mask_filter, procs)
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
    return lib.SkMaskFilter_MakeBlur(style, sigma, respectCTM)
end

function Skia.MaskFilter.Deserialize(data, size, procs)
    return lib.SkMaskFilter_Deserialize(data, size, procs)
end

function Skia.MaskFilter.NameToFactory(name)
    return lib.SkMaskFilter_NameToFactory(name)
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
    return lib.SkMatrix_new(matrix)
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
    return lib.SkMatrix_set(matrix, index, value)
end

function Skia.Matrix.setScaleX(matrix, v)
    return lib.SkMatrix_setScaleX(matrix, v)
end

function Skia.Matrix.setScaleY(matrix, v)
    return lib.SkMatrix_setScaleY(matrix, v)
end

function Skia.Matrix.setSkewY(matrix, v)
    return lib.SkMatrix_setSkewY(matrix, v)
end

function Skia.Matrix.setSkewX(matrix, v)
    return lib.SkMatrix_setSkewX(matrix, v)
end

function Skia.Matrix.setTranslateX(matrix, v)
    return lib.SkMatrix_setTranslateX(matrix, v)
end

function Skia.Matrix.setTranslateY(matrix, v)
    return lib.SkMatrix_setTranslateY(matrix, v)
end

function Skia.Matrix.setPerspX(matrix, v)
    return lib.SkMatrix_setPerspX(matrix, v)
end

function Skia.Matrix.setPerspY(matrix, v)
    return lib.SkMatrix_setPerspY(matrix, v)
end

function Skia.Matrix.setAll(matrix, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2)
    return lib.SkMatrix_setAll(matrix, scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2)
end

function Skia.Matrix.get9(matrix, buffer)
    lib.SkMatrix_get9(matrix, buffer)
end

function Skia.Matrix.set9(matrix, buffer)
    return lib.SkMatrix_set9(matrix, buffer)
end

function Skia.Matrix.reset(matrix)
    return lib.SkMatrix_reset(matrix)
end

function Skia.Matrix.setIdentity(matrix)
    return lib.SkMatrix_setIdentity(matrix)
end

function Skia.Matrix.setTranslate(matrix, dx, dy)
    return lib.SkMatrix_setTranslate(matrix, dx, dy)
end

function Skia.Matrix.setTranslate_2(matrix, v)
    return lib.SkMatrix_setTranslate_2(matrix, v)
end

function Skia.Matrix.setScale(matrix, sx, sy, px, py)
    return lib.SkMatrix_setScale(matrix, sx, sy, px, py)
end

function Skia.Matrix.setScale_2(matrix, sx, sy)
    return lib.SkMatrix_setScale_2(matrix, sx, sy)
end

function Skia.Matrix.setRotate(matrix, degrees, px, py)
    return lib.SkMatrix_setRotate(matrix, degrees, px, py)
end

function Skia.Matrix.setRotate_2(matrix, degrees)
    return lib.SkMatrix_setRotate_2(matrix, degrees)
end

function Skia.Matrix.setSinCos(matrix, sinValue, cosValue, px, py)
    return lib.SkMatrix_setSinCos(matrix, sinValue, cosValue, px, py)
end

function Skia.Matrix.setSinCos_2(matrix, sinValue, cosValue)
    return lib.SkMatrix_setSinCos_2(matrix, sinValue, cosValue)
end

function Skia.Matrix.setRSXform(matrix, rsxForm)
    return lib.SkMatrix_setRSXform(matrix, rsxForm)
end

function Skia.Matrix.setSkew(matrix, kx, ky, px, py)
    return lib.SkMatrix_setSkew(matrix, kx, ky, px, py)
end

function Skia.Matrix.setSkew_2(matrix, kx, ky)
    return lib.SkMatrix_setSkew_2(matrix, kx, ky)
end

function Skia.Matrix.setConcat(matrix, a, b)
    return lib.SkMatrix_setConcat(matrix, a, b)
end

function Skia.Matrix.preTranslate(matrix, dx, dy)
    return lib.SkMatrix_preTranslate(matrix, dx, dy)
end

function Skia.Matrix.preScale(matrix, sx, sy, px, py)
    return lib.SkMatrix_preScale(matrix, sx, sy, px, py)
end

function Skia.Matrix.preScale_2(matrix, sx, sy)
    return lib.SkMatrix_preScale_2(matrix, sx, sy)
end

function Skia.Matrix.preRotate(matrix, degrees, px, py)
    return lib.SkMatrix_preRotate(matrix, degrees, px, py)
end

function Skia.Matrix.preRotate_2(matrix, degrees)
    return lib.SkMatrix_preRotate_2(matrix, degrees)
end

function Skia.Matrix.preSkew(matrix, kx, ky, px, py)
    return lib.SkMatrix_preSkew(matrix, kx, ky, px, py)
end

function Skia.Matrix.preSkew_2(matrix, kx, ky)
    return lib.SkMatrix_preSkew_2(matrix, kx, ky)
end

function Skia.Matrix.preConcat(matrix, other)
    return lib.SkMatrix_preConcat(matrix, other)
end

function Skia.Matrix.postTranslate(matrix, dx, dy)
    return lib.SkMatrix_postTranslate(matrix, dx, dy)
end

function Skia.Matrix.postScale(matrix, sx, sy, px, py)
    return lib.SkMatrix_postScale(matrix, sx, sy, px, py)
end

function Skia.Matrix.postScale_2(matrix, sx, sy)
    return lib.SkMatrix_postScale_2(matrix, sx, sy)
end

function Skia.Matrix.postRotate(matrix, degrees, px, py)
    return lib.SkMatrix_postRotate(matrix, degrees, px, py)
end

function Skia.Matrix.postRotate_2(matrix, degrees)
    return lib.SkMatrix_postRotate_2(matrix, degrees)
end

function Skia.Matrix.postSkew(matrix, kx, ky, px, py)
    return lib.SkMatrix_postSkew(matrix, kx, ky, px, py)
end

function Skia.Matrix.postSkew_2(matrix, kx, ky)
    return lib.SkMatrix_postSkew_2(matrix, kx, ky)
end

function Skia.Matrix.postConcat(matrix, other)
    return lib.SkMatrix_postConcat(matrix, other)
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
    return lib.SkMatrix_setAffine(matrix, affine)
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
    return lib.SkMatrix_mapPoint(matrix, pt)
end

function Skia.Matrix.mapXY(matrix, x, y, result)
    lib.SkMatrix_mapXY(matrix, x, y, result)
end

function Skia.Matrix.mapXY_2(matrix, x, y)
    return lib.SkMatrix_mapXY_2(matrix, x, y)
end

function Skia.Matrix.mapOrigin(matrix)
    return lib.SkMatrix_mapOrigin(matrix)
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
    return lib.SkMatrix_mapVector_2(matrix, dx, dy)
end

function Skia.Matrix.mapRect(matrix, dst, src, pc)
    return lib.SkMatrix_mapRect(matrix, dst, src, pc)
end

function Skia.Matrix.mapRect_2(matrix, rect, pc)
    return lib.SkMatrix_mapRect_2(matrix, rect, pc)
end

function Skia.Matrix.mapRect_3(matrix, src, pc)
    return lib.SkMatrix_mapRect_3(matrix, src, pc)
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
    return lib.SkMatrix_Scale(sx, sy)
end

function Skia.Matrix.Translate(dx, dy)
    return lib.SkMatrix_Translate(dx, dy)
end

function Skia.Matrix.Translate_2(t)
    return lib.SkMatrix_Translate_2(t)
end

function Skia.Matrix.Translate_3(t)
    return lib.SkMatrix_Translate_3(t)
end

function Skia.Matrix.RotateDeg(deg)
    return lib.SkMatrix_RotateDeg(deg)
end

function Skia.Matrix.RotateDeg_2(deg, pt)
    return lib.SkMatrix_RotateDeg_2(deg, pt)
end

function Skia.Matrix.RotateRad(rad)
    return lib.SkMatrix_RotateRad(rad)
end

function Skia.Matrix.Skew(kx, ky)
    return lib.SkMatrix_Skew(kx, ky)
end

function Skia.Matrix.RectToRect(src, dst, mode)
    return lib.SkMatrix_RectToRect(src, dst, mode)
end

function Skia.Matrix.MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2)
    return lib.SkMatrix_MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2)
end

function Skia.Matrix.MakeRectToRect(src, dst, stf)
    return lib.SkMatrix_MakeRectToRect(src, dst, stf)
end

function Skia.Matrix.SetAffineIdentity(affine)
    lib.SkMatrix_SetAffineIdentity(affine)
end

function Skia.Matrix.I()
    return lib.SkMatrix_I()
end

function Skia.Matrix.InvalidMatrix()
    return lib.SkMatrix_InvalidMatrix()
end

function Skia.Matrix.Concat(a, b)
    return lib.SkMatrix_Concat(a, b)
end

-- ## sk_memory_stream
Skia.MemoryStream = {}

function Skia.MemoryStream.new()
    return lib.SkMemoryStream_new()
end

function Skia.MemoryStream.new_2(length)
    return lib.SkMemoryStream_new_2(length)
end

function Skia.MemoryStream.new_3(data, length, copyData)
    return lib.SkMemoryStream_new_3(data, length, copyData)
end

function Skia.MemoryStream.new_4(data)
    return lib.SkMemoryStream_new_4(data)
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
    return lib.SkMemoryStream_asData(memory_stream)
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
    return lib.SkMemoryStream_duplicate(memory_stream)
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
    return lib.SkMemoryStream_fork(memory_stream)
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
    return lib.SkMemoryStream_MakeCopy(data, length)
end

function Skia.MemoryStream.MakeDirect(data, length)
    return lib.SkMemoryStream_MakeDirect(data, length)
end

function Skia.MemoryStream.Make(data)
    return lib.SkMemoryStream_Make(data)
end

-- ## sk_meshes
Skia.Meshes = {}

function Skia.Meshes.MakeIndexBuffer(data, size)
    return lib.SkMeshes_MakeIndexBuffer(data, size)
end

function Skia.Meshes.CopyIndexBuffer(indexBuffer)
    return lib.SkMeshes_CopyIndexBuffer(indexBuffer)
end

function Skia.Meshes.MakeVertexBuffer(data, size)
    return lib.SkMeshes_MakeVertexBuffer(data, size)
end

function Skia.Meshes.CopyVertexBuffer(vertexBuffer)
    return lib.SkMeshes_CopyVertexBuffer(vertexBuffer)
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
    return lib.SkOverdrawColorFilter_MakeWithSkColors(color)
end

-- ## sk_paint
Skia.Paint = {}

function Skia.Paint.new()
    return lib.SkPaint_new()
end

function Skia.Paint.new_2(color, colorSpace)
    return lib.SkPaint_new_2(color, colorSpace)
end

function Skia.Paint.new_3(paint)
    return lib.SkPaint_new_3(paint)
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
    return lib.SkPaint_getColor4f(paint)
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
    return lib.SkPaint_refShader(paint)
end

function Skia.Paint.setShader(paint, shader)
    lib.SkPaint_setShader(paint, shader)
end

function Skia.Paint.getColorFilter(paint)
    return lib.SkPaint_getColorFilter(paint)
end

function Skia.Paint.refColorFilter(paint)
    return lib.SkPaint_refColorFilter(paint)
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
    return lib.SkPaint_refBlender(paint)
end

function Skia.Paint.setBlender(paint, blender)
    lib.SkPaint_setBlender(paint, blender)
end

function Skia.Paint.getPathEffect(paint)
    return lib. SkPaint_getPathEffect(paint)
end

function Skia.Paint.refPathEffect(paint)
    return lib.SkPaint_refPathEffect(paint)
end

function Skia.Paint.setPathEffect(paint, path_effect)
    lib.SkPaint_setPathEffect(paint, path_effect)
end

function Skia.Paint.getMaskFilter(paint)
    return lib. SkPaint_getMaskFilter(paint)
end

function Skia.Paint.refMaskFilter(paint)
    return lib.SkPaint_refMaskFilter(paint)
end

function Skia.Paint.setMaskFilter(paint, mask_filter)
    lib.SkPaint_setMaskFilter(paint, mask_filter)
end

function Skia.Paint.getImageFilter(paint)
    return lib. SkPaint_getImageFilter(paint)
end

function Skia.Paint.refImageFilter(paint)
    return lib.SkPaint_refImageFilter(paint)
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
    return lib.SkPath_new()
end

function Skia.Path.new_2(path)
    return lib.SkPath_new_2(path)
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
    return lib.SkPath_getPoint(path, index)
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
    return lib.SkPath_computeTightBounds(path)
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
    return lib.SkPath_makeTransform(path, m, pc)
end

function Skia.Path.makeScale(path, sx, sy)
    return lib.SkPath_makeScale(path, sx, sy)
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
    return lib.SkPath_serialize(path)
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
    return lib.SkPath_Make(point, pointCount, i, verbCount, v, conicWeightCount, type, isVolatile)
end

function Skia.Path.Rect(rect, dir, startIndex)
    return lib.SkPath_Rect(rect, dir, startIndex)
end

function Skia.Path.Oval(rect, dir)
    return lib.SkPath_Oval(rect, dir)
end

function Skia.Path.Oval_2(rect, dir, startIndex)
    return lib.SkPath_Oval_2(rect, dir, startIndex)
end

function Skia.Path.Circle(center_x, center_y, radius, dir)
    return lib.SkPath_Circle(center_x, center_y, radius, dir)
end

function Skia.Path.RRect(rrect, dir)
    return lib.SkPath_RRect(rrect, dir)
end

function Skia.Path.RRect_2(rrect, dir, startIndex)
    return lib.SkPath_RRect_2(rrect, dir, startIndex)
end

function Skia.Path.RRect_3(bounds, rx, ry, dir)
    return lib.SkPath_RRect_3(bounds, rx, ry, dir)
end

function Skia.Path.Polygon(pts, count, isClosed, type, isVolatile)
    return lib.SkPath_Polygon(pts, count, isClosed, type, isVolatile)
end

function Skia.Path.Polygon_2(list, isClosed, fillType, isVolatile)
    return lib.SkPath_Polygon_2(list, isClosed, fillType, isVolatile)
end

function Skia.Path.Line(a, b)
    return lib.SkPath_Line(a, b)
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
    return lib.SkPath1DPathEffect_Make(path, advance, phase, style)
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
    return lib.SkPath2DPathEffect_Make(matrix, path)
end

function Skia.Path2DPathEffect.RegisterFlattenables()
    lib.SkPath2DPathEffect_RegisterFlattenables()
end

-- ## sk_path_builder
Skia.PathBuilder = {}

function Skia.PathBuilder.new()
    return lib.SkPathBuilder_new()
end

function Skia.PathBuilder.new_2(type)
    return lib.SkPathBuilder_new_2(type)
end

function Skia.PathBuilder.new_3(path)
    return lib.SkPathBuilder_new_3(path)
end

function Skia.PathBuilder.new_4(builder)
    return lib.SkPathBuilder_new_4(builder)
end

function Skia.PathBuilder.delete(path_builder)
    lib.SkPathBuilder_delete(path_builder)
end

function Skia.PathBuilder.fillType(path_builder)
    return lib.SkPathBuilder_fillType(path_builder)
end

function Skia.PathBuilder.computeBounds(path_builder)
    return lib.SkPathBuilder_computeBounds(path_builder)
end

function Skia.PathBuilder.snapshot(path_builder)
    return lib.SkPathBuilder_snapshot(path_builder)
end

function Skia.PathBuilder.detach(path_builder)
    return lib.SkPathBuilder_detach(path_builder)
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
    return lib.SkPathEffect_getFactory(path_effect)
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
    return lib.SkPathEffect_serialize(path_effect, procs)
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
    return lib.SkPathEffect_MakeSum(first, second)
end

function Skia.PathEffect.MakeCompose(outer, inner)
    return lib.SkPathEffect_MakeCompose(outer, inner)
end

function Skia.PathEffect.GetFlattenableType()
    return lib.SkPathEffect_GetFlattenableType()
end

function Skia.PathEffect.Deserialize(data, size, procs)
    return lib.SkPathEffect_Deserialize(data, size, procs)
end

function Skia.PathEffect.NameToFactory(char name)
    return lib.SkPathEffect_NameToFactory(char name)
end

function Skia.PathEffect.FactoryToName(factory)
    return lib. SkPathEffect_FactoryToName(factory)
end

function Skia.PathEffect.Register(char name, factory)
    lib.SkPathEffect_Register(char name, factory)
end

-- ## sk_path_measure
Skia.PathMeasure = {}

function Skia.PathMeasure.new()
    return lib.SkPathMeasure_new()
end

function Skia.PathMeasure.new_2(path, forceClosed, resScale)
    return lib.SkPathMeasure_new_2(path, forceClosed, resScale)
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

-- ## sk_pdf
Skia.PDF = {}

function Skia.PDF.SetNodeId(dst, nodeID)
    lib.SkPDF_SetNodeId(dst, nodeID)
end

function Skia.PDF.MakeDocument(stream, metadata)
    return lib.SkPDF_MakeDocument(stream, metadata)
end

function Skia.PDF.MakeDocument_2(stream)
    return lib.SkPDF_MakeDocument_2(stream)
end

-- ## sk_perlin_noise_shader
Skia.PerlinNoiseShader = {}

function Skia.PerlinNoiseShader.MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    return lib.SkPerlinNoiseShader_MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
end

function Skia.PerlinNoiseShader.MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
    return lib.SkPerlinNoiseShader_MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize)
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
    return lib.SkPicture_cullRect(picture)
end

function Skia.Picture.uniqueID(picture)
    return lib.SkPicture_uniqueID(picture)
end

function Skia.Picture.serialize(picture, procs)
    return lib.SkPicture_serialize(picture, procs)
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
    return lib.SkPicture_makeShader(picture, tmx, tmy, mode, localMatrix, tileRect)
end

function Skia.Picture.makeShader_2(picture, tmx, tmy, mode)
    return lib.SkPicture_makeShader_2(picture, tmx, tmy, mode)
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
    return lib.SkPicture_MakeFromStream(stream, procs)
end

function Skia.Picture.MakeFromData(data, procs)
    return lib.SkPicture_MakeFromData(data, procs)
end

function Skia.Picture.MakeFromData_2(data, size, procs)
    return lib.SkPicture_MakeFromData_2(data, size, procs)
end

function Skia.Picture.MakePlaceholder(cull)
    return lib.SkPicture_MakePlaceholder(cull)
end

-- ## sk_picture_recorder
Skia.PictureRecorder = {}

function Skia.PictureRecorder.new()
    return lib.SkPictureRecorder_new()
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
    return lib.SkPictureRecorder_finishRecordingAsPicture(picture_recorder)
end

function Skia.PictureRecorder.finishRecordingAsPictureWithCull(picture_recorder, cullRect)
    return lib.SkPictureRecorder_finishRecordingAsPictureWithCull(picture_recorder, cullRect)
end

function Skia.PictureRecorder.finishRecordingAsDrawable(picture_recorder)
    return lib.SkPictureRecorder_finishRecordingAsDrawable(picture_recorder)
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
    return lib.SkPixelRef_dimensions(pixel_ref)
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
    return lib.SkPixmap_new()
end

function Skia.Pixmap.new_2(info, addr, rowBytes)
    return lib.SkPixmap_new_2(info, addr, rowBytes)
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
    return lib.SkPixmap_dimensions(pixmap)
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
    return lib.SkPixmap_refColorSpace(pixmap)
end

function Skia.Pixmap.isOpaque(pixmap)
    return lib.SkPixmap_isOpaque(pixmap)
end

function Skia.Pixmap.bounds(pixmap)
    return lib.SkPixmap_bounds(pixmap)
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
    return lib.SkPixmap_getColor4f(pixmap, x, y)
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
    return lib.SkPixmapUtils_SwapWidthHeight(info)
end

-- ## sk_png_decoder
Skia.PngDecoder = {}

function Skia.PngDecoder.IsPng(ptr, size)
    return lib.SkPngDecoder_IsPng(ptr, size)
end

function Skia.PngDecoder.Decode(static_stream, result, decodeContext)
    return lib.SkPngDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.PngDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkPngDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.PngDecoder.Decoder()
    return lib.SkPngDecoder_Decoder()
end

-- ## sk_png_encoder
Skia.PngEncoder = {}

function Skia.PngEncoder.Encode(dst, src, options)
    return lib.SkPngEncoder_Encode(dst, src, options)
end

function Skia.PngEncoder.Encode_2(ctx, img, options)
    return lib.SkPngEncoder_Encode_2(ctx, img, options)
end

function Skia.PngEncoder.Make(dst, src, options)
    return lib.SkPngEncoder_Make(dst, src, options)
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
    return lib.SkPoint_Make(x, y)
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
    return lib.SkPoint3_makeScale(point3, scale)
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
    return lib.SkPoint3_cross(point3, vec)
end

function Skia.Point3.Make(x, y, z)
    return lib.SkPoint3_Make(x, y, z)
end

function Skia.Point3.Length(x, y, z)
    return lib.SkPoint3_Length(x, y, z)
end

function Skia.Point3.DotProduct(a, b)
    return lib.SkPoint3_DotProduct(a, b)
end

function Skia.Point3.CrossProduct(a, b)
    return lib.SkPoint3_CrossProduct(a, b)
end

-- ## sk_r_rect
Skia.RRect = {}

function Skia.RRect.new()
    return lib.SkRRect_new()
end

function Skia.RRect.new_2(rrect)
    return lib.SkRRect_new_2(rrect)
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
    return lib.SkRRect_getSimpleRadii(rrect)
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
    return lib.SkRRect_radii(rrect, corner)
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
    return lib.SkRRect_makeOffset(rrect, dx, dy)
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
    return lib.SkRRect_dumpToString(rrect, asHex)
end

function Skia.RRect.dump_2(rrect)
    lib.SkRRect_dump_2(rrect)
end

function Skia.RRect.dumpHex(rrect)
    lib.SkRRect_dumpHex(rrect)
end

function Skia.RRect.MakeEmpty()
    return lib.SkRRect_MakeEmpty()
end

function Skia.RRect.MakeRect(r)
    return lib.SkRRect_MakeRect(r)
end

function Skia.RRect.MakeOval(oval)
    return lib.SkRRect_MakeOval(oval)
end

function Skia.RRect.MakeRectXY(rect, xRad, yRad)
    return lib.SkRRect_MakeRectXY(rect, xRad, yRad)
end

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
    return lib.SkRawDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.RawDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkRawDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.RawDecoder.Decoder()
    return lib.SkRawDecoder_Decoder()
end

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
    return lib.SkRect_center(rect)
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
    return lib.SkRect_makeOffset(rect, dx, dy)
end

function Skia.Rect.makeOffset_2(rect, v)
    return lib.SkRect_makeOffset_2(rect, v)
end

function Skia.Rect.makeInset(rect, dx, dy)
    return lib.SkRect_makeInset(rect, dx, dy)
end

function Skia.Rect.makeOutset(rect, dx, dy)
    return lib.SkRect_makeOutset(rect, dx, dy)
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
    return lib.SkRect_round_2(rect)
end

function Skia.Rect.roundOut_3(rect)
    return lib.SkRect_roundOut_3(rect)
end

function Skia.Rect.roundIn_2(rect)
    return lib.SkRect_roundIn_2(rect)
end

function Skia.Rect.sort(rect)
    lib.SkRect_sort(rect)
end

function Skia.Rect.makeSorted(rect)
    return lib.SkRect_makeSorted(rect)
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
    return lib.SkRect_MakeEmpty()
end

function Skia.Rect.MakeWH(w, h)
    return lib.SkRect_MakeWH(w, h)
end

function Skia.Rect.MakeIWH(w, h)
    return lib.SkRect_MakeIWH(w, h)
end

function Skia.Rect.MakeSize(size)
    return lib.SkRect_MakeSize(size)
end

function Skia.Rect.MakeLTRB(l, t, r, b)
    return lib.SkRect_MakeLTRB(l, t, r, b)
end

function Skia.Rect.MakeXYWH(x, y, w, h)
    return lib.SkRect_MakeXYWH(x, y, w, h)
end

function Skia.Rect.Make(size)
    return lib.SkRect_Make(size)
end

function Skia.Rect.Make_2(irect)
    return lib.SkRect_Make_2(irect)
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
    return lib.SkRefCntBase_new()
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
    return lib.SkRegion_new()
end

function Skia.Region.new_2(region)
    return lib.SkRegion_new_2(region)
end

function Skia.Region.new_3(rect)
    return lib.SkRegion_new_3(rect)
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
    return lib.SkRSXform_Make(scos, ssin, tx, ty)
end

function Skia.RSXform.MakeFromRadians(scale, radians, tx, ty, ax, ay)
    return lib.SkRSXform_MakeFromRadians(scale, radians, tx, ty, ax, ay)
end

-- ## sk_runtime_blend_builder
Skia.RuntimeBlendBuilder = {}

function Skia.RuntimeBlendBuilder.new(runtime_effect)
    return lib.SkRuntimeBlendBuilder_new(runtime_effect)
end

function Skia.RuntimeBlendBuilder.delete(runtime_blend_builder)
    lib.SkRuntimeBlendBuilder_delete(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.makeBlender(runtime_blend_builder)
    return lib.SkRuntimeBlendBuilder_makeBlender(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.effect(runtime_blend_builder)
    return lib. SkRuntimeBlendBuilder_effect(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.uniform(runtime_blend_builder, name)
    return lib.SkRuntimeBlendBuilder_uniform(runtime_blend_builder, name)
end

function Skia.RuntimeBlendBuilder.child(runtime_blend_builder, name)
    return lib.SkRuntimeBlendBuilder_child(runtime_blend_builder, name)
end

function Skia.RuntimeBlendBuilder.uniforms(runtime_blend_builder)
    return lib.SkRuntimeBlendBuilder_uniforms(runtime_blend_builder)
end

function Skia.RuntimeBlendBuilder.children(runtime_blend_builder)
    return lib.SkRuntimeBlendBuilder_children(runtime_blend_builder)
end

-- ## sk_runtime_color_filter_builder
Skia.RuntimeColorFilterBuilder = {}

function Skia.RuntimeColorFilterBuilder.new(runtime_effect)
    return lib.SkRuntimeColorFilterBuilder_new(runtime_effect)
end

function Skia.RuntimeColorFilterBuilder.delete(runtime_color_filter_builder)
    lib.SkRuntimeColorFilterBuilder_delete(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.makeColorFilter(runtime_color_filter_builder)
    return lib.SkRuntimeColorFilterBuilder_makeColorFilter(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.effect(runtime_color_filter_builder)
    return lib. SkRuntimeColorFilterBuilder_effect(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.uniform(runtime_color_filter_builder, name)
    return lib.SkRuntimeColorFilterBuilder_uniform(runtime_color_filter_builder, name)
end

function Skia.RuntimeColorFilterBuilder.child(runtime_color_filter_builder, name)
    return lib.SkRuntimeColorFilterBuilder_child(runtime_color_filter_builder, name)
end

function Skia.RuntimeColorFilterBuilder.uniforms(runtime_color_filter_builder)
    return lib.SkRuntimeColorFilterBuilder_uniforms(runtime_color_filter_builder)
end

function Skia.RuntimeColorFilterBuilder.children(runtime_color_filter_builder)
    return lib.SkRuntimeColorFilterBuilder_children(runtime_color_filter_builder)
end

-- ## sk_runtime_effect
Skia.RuntimeEffect = {}

function Skia.RuntimeEffect.delete(runtime_effect)
    lib.SkRuntimeEffect_delete(runtime_effect)
end

function Skia.RuntimeEffect.makeShader(runtime_effect, data, children, childCount, localMatrix)
    return lib.SkRuntimeEffect_makeShader(runtime_effect, data, children, childCount, localMatrix)
end

function Skia.RuntimeEffect.makeShader_2(runtime_effect, data, runtime_effect_child_ptr, localMatrix)
    return lib.SkRuntimeEffect_makeShader_2(runtime_effect, data, runtime_effect_child_ptr, localMatrix)
end

function Skia.RuntimeEffect.makeColorFilter(runtime_effect, data)
    return lib.SkRuntimeEffect_makeColorFilter(runtime_effect, data)
end

function Skia.RuntimeEffect.makeColorFilter_2(runtime_effect, data, children, childCount)
    return lib.SkRuntimeEffect_makeColorFilter_2(runtime_effect, data, children, childCount)
end

function Skia.RuntimeEffect.makeColorFilter_3(runtime_effect, data, runtime_effect_child_ptr)
    return lib.SkRuntimeEffect_makeColorFilter_3(runtime_effect, data, runtime_effect_child_ptr)
end

function Skia.RuntimeEffect.makeBlender(runtime_effect, data, runtime_effect_child_ptr)
    return lib.SkRuntimeEffect_makeBlender(runtime_effect, data, runtime_effect_child_ptr)
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
    return lib.SkRuntimeEffect_MakeForColorFilter(string, options)
end

function Skia.RuntimeEffect.MakeForColorFilter_2(string)
    return lib.SkRuntimeEffect_MakeForColorFilter_2(string)
end

function Skia.RuntimeEffect.MakeForShader(string, options)
    return lib.SkRuntimeEffect_MakeForShader(string, options)
end

function Skia.RuntimeEffect.MakeForShader_2(string)
    return lib.SkRuntimeEffect_MakeForShader_2(string)
end

function Skia.RuntimeEffect.MakeForBlender(string, options)
    return lib.SkRuntimeEffect_MakeForBlender(string, options)
end

function Skia.RuntimeEffect.MakeForBlender_2(string)
    return lib.SkRuntimeEffect_MakeForBlender_2(string)
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
    return lib.SkRuntimeEffectBuilder_uniform(runtime_effect_builder, name)
end

function Skia.RuntimeEffectBuilder.child(runtime_effect_builder, name)
    return lib.SkRuntimeEffectBuilder_child(runtime_effect_builder, name)
end

function Skia.RuntimeEffectBuilder.uniforms(runtime_effect_builder)
    return lib.SkRuntimeEffectBuilder_uniforms(runtime_effect_builder)
end

function Skia.RuntimeEffectBuilder.children(runtime_effect_builder)
    return lib.SkRuntimeEffectBuilder_children(runtime_effect_builder)
end

-- ## sk_runtime_shader_builder
Skia.RuntimeShaderBuilder = {}

function Skia.RuntimeShaderBuilder.new(runtime_effect)
    return lib.SkRuntimeShaderBuilder_new(runtime_effect)
end

function Skia.RuntimeShaderBuilder.new_2(builder)
    return lib.SkRuntimeShaderBuilder_new_2(builder)
end

function Skia.RuntimeShaderBuilder.delete(runtime_shader_builder)
    lib.SkRuntimeShaderBuilder_delete(runtime_shader_builder)
end

function Skia.RuntimeShaderBuilder.makeShader(runtime_shader_builder, localMatrix)
    return lib.SkRuntimeShaderBuilder_makeShader(runtime_shader_builder, localMatrix)
end

function Skia.RuntimeShaderBuilder.effect(runtime_shader_builder)
    return lib. SkRuntimeShaderBuilder_effect(runtime_shader_builder)
end

function Skia.RuntimeShaderBuilder.uniform(runtime_shader_builder, name)
    return lib.SkRuntimeShaderBuilder_uniform(runtime_shader_builder, name)
end

function Skia.RuntimeShaderBuilder.child(runtime_shader_builder, name)
    return lib.SkRuntimeShaderBuilder_child(runtime_shader_builder, name)
end

function Skia.RuntimeShaderBuilder.uniforms(runtime_shader_builder)
    return lib.SkRuntimeShaderBuilder_uniforms(runtime_shader_builder)
end

function Skia.RuntimeShaderBuilder.children(runtime_shader_builder)
    return lib.SkRuntimeShaderBuilder_children(runtime_shader_builder)
end

-- ## sk_sampling_options
Skia.SamplingOptions = {}

function Skia.SamplingOptions.new()
    return lib.SkSamplingOptions_new()
end

function Skia.SamplingOptions.new_2(options)
    return lib.SkSamplingOptions_new_2(options)
end

function Skia.SamplingOptions.new_3(fm, mm)
    return lib.SkSamplingOptions_new_3(fm, mm)
end

function Skia.SamplingOptions.new_4(fm)
    return lib.SkSamplingOptions_new_4(fm)
end

function Skia.SamplingOptions.new_5(c)
    return lib.SkSamplingOptions_new_5(c)
end

function Skia.SamplingOptions.delete(sampling_options)
    lib.SkSamplingOptions_delete(sampling_options)
end

function Skia.SamplingOptions.isAniso(sampling_options)
    return lib.SkSamplingOptions_isAniso(sampling_options)
end

function Skia.SamplingOptions.Aniso(maxAniso)
    return lib.SkSamplingOptions_Aniso(maxAniso)
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
    return lib.SkShader_makeWithLocalMatrix(shader, matrix)
end

function Skia.Shader.makeWithColorFilter(shader, color_filter)
    return lib.SkShader_makeWithColorFilter(shader, color_filter)
end

function Skia.Shader.makeWithWorkingColorSpace(shader, color_space)
    return lib.SkShader_makeWithWorkingColorSpace(shader, color_space)
end

function Skia.Shader.getFactory(shader)
    return lib.SkShader_getFactory(shader)
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
    return lib.SkShader_serialize(shader, procs)
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

function Skia.Shader.NameToFactory(char name)
    return lib.SkShader_NameToFactory(char name)
end

function Skia.Shader.FactoryToName(factory)
    return lib. SkShader_FactoryToName(factory)
end

function Skia.Shader.Register(char name, factory)
    lib.SkShader_Register(char name, factory)
end

function Skia.Shader.Deserialize(type, data, length, procs)
    return lib.SkShader_Deserialize(type, data, length, procs)
end

-- ## sk_shader_mask_filter
Skia.ShaderMaskFilter = {}

function Skia.ShaderMaskFilter.delete(shaderMaskFilter)
    lib.SkShaderMaskFilter_delete(shaderMaskFilter)
end

function Skia.ShaderMaskFilter.Make(shader)
    return lib.SkShaderMaskFilter_Make(shader)
end

-- ## sk_shaders
Skia.Shaders = {}

function Skia.Shaders.Empty()
    return lib.SkShaders_Empty()
end

function Skia.Shaders.Color(color)
    return lib.SkShaders_Color(color)
end

function Skia.Shaders.Color_2(color4f, color_space)
    return lib.SkShaders_Color_2(color4f, color_space)
end

function Skia.Shaders.Blend(mode, dst, src)
    return lib.SkShaders_Blend(mode, dst, src)
end

function Skia.Shaders.Blend_2(value, dst, src)
    return lib.SkShaders_Blend_2(value, dst, src)
end

function Skia.Shaders.CoordClamp(shader, subset)
    return lib.SkShaders_CoordClamp(shader, subset)
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
    return lib.SkShaper_MakePrimitive()
end

function Skia.Shaper.Make(font_mgr)
    return lib.SkShaper_Make(font_mgr)
end

function Skia.Shaper.PurgeCaches()
    lib.SkShaper_PurgeCaches()
end

function Skia.Shaper.MakeFontMgrRunIterator(utf8, utf8Bytes, font, font_mgr)
    return lib.SkShaper_MakeFontMgrRunIterator(utf8, utf8Bytes, font, font_mgr)
end

function Skia.Shaper.MakeFontMgrRunIterator_2(utf8, utf8Bytes, font, font_mgr, requestName, requestStyle, language_run_iterator)
    return lib.SkShaper_MakeFontMgrRunIterator_2(utf8, utf8Bytes, font, font_mgr, requestName, requestStyle, language_run_iterator)
end

function Skia.Shaper.MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel)
    return lib.SkShaper_MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel)
end

function Skia.Shaper.MakeScriptRunIterator(utf8, utf8Bytes, script)
    return lib.SkShaper_MakeScriptRunIterator(utf8, utf8Bytes, script)
end

function Skia.Shaper.MakeStdLanguageRunIterator(utf8, utf8Bytes)
    return lib.SkShaper_MakeStdLanguageRunIterator(utf8, utf8Bytes)
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
    return lib.SkSize_toRound(size)
end

function Skia.Size.toCeil(size)
    return lib.SkSize_toCeil(size)
end

function Skia.Size.toFloor(size)
    return lib.SkSize_toFloor(size)
end

function Skia.Size.Make(w, h)
    return lib.SkSize_Make(w, h)
end

function Skia.Size.Make_2(src)
    return lib.SkSize_Make_2(src)
end

function Skia.Size.MakeEmpty()
    return lib.SkSize_MakeEmpty()
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
    return lib.SkStream_duplicate(stream)
end

function Skia.Stream.fork(stream)
    return lib.SkStream_fork(stream)
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
    return lib.SkStream_MakeFromFile(path)
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
    return lib.SkStreamAsset_duplicate(stream_asset)
end

function Skia.StreamAsset.fork(stream_asset)
    return lib.SkStreamAsset_fork(stream_asset)
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
    return lib.SkStreamAsset_MakeFromFile(path)
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
    return lib.SkStreamMemory_duplicate(stream_memory)
end

function Skia.StreamMemory.fork(stream_memory)
    return lib.SkStreamMemory_fork(stream_memory)
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

function Skia.StreamMemory.MakeFromFile(char path)
    return lib.SkStreamMemory_MakeFromFile(char path)
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
    return lib.SkStreamRewindable_duplicate(stream_rewindable)
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
    return lib.SkStreamRewindable_fork(stream_rewindable)
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

function Skia.StreamRewindable.MakeFromFile(char path)
    return lib.SkStreamRewindable_MakeFromFile(char path)
end

-- ## sk_stream_seekable
Skia.StreamSeekable = {}

function Skia.StreamSeekable.delete(stream_seekable)
    lib.SkStreamSeekable_delete(stream_seekable)
end

function Skia.StreamSeekable.duplicate(stream_seekable)
    return lib.SkStreamSeekable_duplicate(stream_seekable)
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
    return lib.SkStreamSeekable_fork(stream_seekable)
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

function Skia.StreamSeekable.MakeFromFile(char path)
    return lib.SkStreamSeekable_MakeFromFile(char path)
end

-- ## sk_string
Skia.String = {}

function Skia.String.new()
    return lib.SkString_new()
end

function Skia.String.new_2(len)
    return lib.SkString_new_2(len)
end

function Skia.String.new_3(char text)
    return lib.SkString_new_3(char text)
end

function Skia.String.new_4(char text, len)
    return lib.SkString_new_4(char text, len)
end

function Skia.String.new_5(str)
    return lib.SkString_new_5(str)
end

function Skia.String.new_6(str)
    return lib.SkString_new_6(str)
end

function Skia.String.new_7(view)
    return lib.SkString_new_7(view)
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

function Skia.String.equals_2(string, char text)
    return lib.SkString_equals_2(string, char text)
end

function Skia.String.equals_3(string, char text, len)
    return lib.SkString_equals_3(string, char text, len)
end

function Skia.String.startsWith(string, char prefixStr)
    return lib.SkString_startsWith(string, char prefixStr)
end

function Skia.String.startsWith_2(string, char prefixChar)
    return lib.SkString_startsWith_2(string, char prefixChar)
end

function Skia.String.contains(string, char substring)
    return lib.SkString_contains(string, char substring)
end

function Skia.String.contains_2(string, char subchar)
    return lib.SkString_contains_2(string, char subchar)
end

function Skia.String.find(string, char substring)
    return lib.SkString_find(string, char substring)
end

function Skia.String.findLastOf(string, char subchar)
    return lib.SkString_findLastOf(string, char subchar)
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

function Skia.String.set_2(string, char text)
    lib.SkString_set_2(string, char text)
end

function Skia.String.set_3(string, char text, len)
    lib.SkString_set_3(string, char text, len)
end

function Skia.String.set_4(string, str)
    lib.SkString_set_4(string, str)
end

function Skia.String.insert(string, offset, char text)
    lib.SkString_insert(string, offset, char text)
end

function Skia.String.insert_2(string, offset, char text, len)
    lib.SkString_insert_2(string, offset, char text, len)
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

function Skia.String.append(string, char text)
    lib.SkString_append(string, char text)
end

function Skia.String.append_2(string, char text, len)
    lib.SkString_append_2(string, char text, len)
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

function Skia.String.prepend(string, char text)
    lib.SkString_prepend(string, char text)
end

function Skia.String.prepend_2(string, char text, len)
    lib.SkString_prepend_2(string, char text, len)
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
    return lib.SkStrokeRec_static(style)
end

function Skia.StrokeRec.static_2(paint, style, resScale)
    return lib.SkStrokeRec_static_2(paint, style, resScale)
end

function Skia.StrokeRec.static_3(paint, resScale)
    return lib.SkStrokeRec_static_3(paint, resScale)
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
    return lib.SkSurface_imageInfo(surface)
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
    return lib.SkSurface_capabilities(surface)
end

function Skia.Surface.makeSurface(surface, imageInfo)
    return lib.SkSurface_makeSurface(surface, imageInfo)
end

function Skia.Surface.makeSurface_2(surface, width, height)
    return lib.SkSurface_makeSurface_2(surface, width, height)
end

function Skia.Surface.makeImageSnapshot(surface)
    return lib.SkSurface_makeImageSnapshot(surface)
end

function Skia.Surface.makeImageSnapshot_2(surface, bounds)
    return lib.SkSurface_makeImageSnapshot_2(surface, bounds)
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
    return lib.SkSurfaceProps_new()
end

function Skia.SurfaceProps.new_2(flags, geometry)
    return lib.SkSurfaceProps_new_2(flags, geometry)
end

function Skia.SurfaceProps.new_3(props)
    return lib.SkSurfaceProps_new_3(props)
end

function Skia.SurfaceProps.delete(surface_props)
    lib.SkSurfaceProps_delete(surface_props)
end

function Skia.SurfaceProps.cloneWithPixelGeometry(surface_props, newPixelGeometry)
    return lib.SkSurfaceProps_cloneWithPixelGeometry(surface_props, newPixelGeometry)
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
    return lib.SkSurfaces_Null(width, height)
end

function Skia.Surfaces.Raster(imageInfo, rowBytes, surfaceProps)
    return lib.SkSurfaces_Raster(imageInfo, rowBytes, surfaceProps)
end

function Skia.Surfaces.Raster_2(imageInfo, props)
    return lib.SkSurfaces_Raster_2(imageInfo, props)
end

function Skia.Surfaces.WrapPixels(imageInfo, pixels, rowBytes, surfaceProps)
    return lib.SkSurfaces_WrapPixels(imageInfo, pixels, rowBytes, surfaceProps)
end

function Skia.Surfaces.WrapPixels_2(pm, props)
    return lib.SkSurfaces_WrapPixels_2(pm, props)
end

function Skia.Surfaces.WrapPixels_3(imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps)
    return lib.SkSurfaces_WrapPixels_3(imageInfo, pixels, rowBytes, pixelsReleaseProc, context, surfaceProps)
end

-- ## sk_svg_attribute_parser
Skia. = {}

-- ## sk_svg_circle
Skia. = {}

-- ## sk_svg_clip_path
Skia. = {}

-- ## sk_svg_color
Skia. = {}

-- ## sk_svg_container
Skia. = {}

-- ## sk_svg_dash_array
Skia. = {}

-- ## sk_svg_defs
Skia. = {}

-- ## sk_svg_dom
Skia. = {}

-- ## sk_svg_ellipse
Skia. = {}

-- ## sk_svg_fe
Skia. = {}

-- ## sk_svg_fe_blend
Skia. = {}

-- ## sk_svg_fe_color_matrix
Skia. = {}

-- ## sk_svg_fe_composite
Skia. = {}

-- ## sk_svg_fe_diffuse_lighting
Skia. = {}

-- ## sk_svg_fe_displacement_map
Skia. = {}

-- ## sk_svg_fe_distant_light
Skia. = {}

-- ## sk_svg_fe_flood
Skia. = {}

-- ## sk_svg_fe_gaussian_blur
Skia. = {}

-- ## sk_svg_fe_image
Skia. = {}

-- ## sk_svg_fe_input_type
Skia. = {}

-- ## sk_svg_fe_light_source
Skia. = {}

-- ## sk_svg_fe_lighting
Skia. = {}

-- ## sk_svg_fe_morphology
Skia. = {}

-- ## sk_svg_fe_offset
Skia. = {}

-- ## sk_svg_fe_point_light
Skia. = {}

-- ## sk_svg_fe_specular_lighting
Skia. = {}

-- ## sk_svg_fe_spot_light
Skia. = {}

-- ## sk_svg_fe_turbulence
Skia. = {}

-- ## sk_svg_fe_turbulence_base_frequency
Skia. = {}

-- ## sk_svg_fe_turbulence_type
Skia. = {}

-- ## sk_svg_fill_rule
Skia. = {}

-- ## sk_svg_filter
Skia. = {}

-- ## sk_svg_filter_context
Skia. = {}

-- ## sk_svg_font_family
Skia. = {}

-- ## sk_svg_font_size
Skia. = {}

-- ## sk_svg_font_style
Skia. = {}

-- ## sk_svg_font_weight
Skia. = {}

-- ## sk_svg_func_iri
Skia. = {}

-- ## sk_svg_g
Skia. = {}

-- ## sk_svg_gradient
Skia. = {}

-- ## sk_svg_hidden_container
Skia. = {}

-- ## sk_svg_image
Skia. = {}

-- ## sk_svg_iri
Skia. = {}

-- ## sk_svg_length
Skia. = {}

-- ## sk_svg_length_context
Skia. = {}

-- ## sk_svg_line
Skia. = {}

-- ## sk_svg_line_join
Skia. = {}

-- ## sk_svg_linear_gradient
Skia. = {}

-- ## sk_svg_mask
Skia. = {}

-- ## sk_svg_node
Skia. = {}

-- ## sk_svg_object_bounding_box_units
Skia. = {}

-- ## sk_svg_open_type_svg_decoder
Skia. = {}

-- ## sk_svg_paint
Skia. = {}

-- ## sk_svg_path
Skia. = {}

-- ## sk_svg_pattern
Skia. = {}

-- ## sk_svg_poly
Skia. = {}

-- ## sk_svg_presentation_attributes
Skia. = {}

-- ## sk_svg_presentation_context
Skia. = {}

-- ## sk_svg_property
Skia. = {}

-- ## sk_svg_radial_gradient
Skia. = {}

-- ## sk_svg_rect
Skia. = {}

-- ## sk_svg_render_context
Skia. = {}

-- ## sk_svg_shape
Skia. = {}

-- ## sk_svg_spread_method
Skia. = {}

-- ## sk_svg_stop
Skia. = {}

-- ## sk_svg_stop_color
Skia. = {}

-- ## sk_svg_svg
Skia. = {}

-- ## sk_svg_t_span
Skia. = {}

-- ## sk_svg_text
Skia. = {}

-- ## sk_svg_text_anchor
Skia. = {}

-- ## sk_svg_text_container
Skia. = {}

-- ## sk_svg_text_fragment
Skia. = {}

-- ## sk_svg_text_literal
Skia. = {}

-- ## sk_svg_text_path
Skia. = {}

-- ## sk_svg_transformable_node
Skia. = {}

-- ## sk_svg_use
Skia. = {}

-- ## sk_svg_value
Skia. = {}

-- ## sk_svg_visibility
Skia. = {}

-- ## sk_svg_wrapper_value
Skia. = {}

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
    return lib.SkTextBlob_serialize_2(text_blob, procs)
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
    return lib.SkTextBlob_MakeFromText(text, byteLength, font, encoding)
end

function Skia.TextBlob.MakeFromString(string, font, encoding)
    return lib.SkTextBlob_MakeFromString(string, font, encoding)
end

function Skia.TextBlob.MakeFromPosTextH(text, byteLength, xpos, constY, font, encoding)
    return lib.SkTextBlob_MakeFromPosTextH(text, byteLength, xpos, constY, font, encoding)
end

function Skia.TextBlob.MakeFromPosText(text, byteLength, pos, font, encoding)
    return lib.SkTextBlob_MakeFromPosText(text, byteLength, pos, font, encoding)
end

function Skia.TextBlob.MakeFromRSXform(text, byteLength, xform, font, encoding)
    return lib.SkTextBlob_MakeFromRSXform(text, byteLength, xform, font, encoding)
end

function Skia.TextBlob.Deserialize(data, size, procs)
    return lib.SkTextBlob_Deserialize(data, size, procs)
end

-- ## sk_text_blob_builder
Skia.TextBlobBuilder = {}

function Skia.TextBlobBuilder.new()
    return lib.SkTextBlobBuilder_new()
end

function Skia.TextBlobBuilder.delete(text_blob_builder)
    lib.SkTextBlobBuilder_delete(text_blob_builder)
end

function Skia.TextBlobBuilder.make(text_blob_builder)
    return lib.SkTextBlobBuilder_make(text_blob_builder)
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

-- ## sk_text_blob_builder_run_handler
Skia.TextBlobBuilderRunHandler = {}

function Skia.TextBlobBuilderRunHandler.new(utf8Text, offset)
    return lib.SkTextBlobBuilderRunHandler_new(utf8Text, offset)
end

function Skia.TextBlobBuilderRunHandler.delete(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_delete(text_blob_builder_run_handler)
end

function Skia.TextBlobBuilderRunHandler.makeBlob(text_blob_builder_run_handler)
    return lib.SkTextBlobBuilderRunHandler_makeBlob(text_blob_builder_run_handler)
end

function Skia.TextBlobBuilderRunHandler.endPoint(text_blob_builder_run_handler)
    return lib.SkTextBlobBuilderRunHandler_endPoint(text_blob_builder_run_handler)
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
    return lib.SkTextBlobBuilderRunHandler_runBuffer(text_blob_builder_run_handler, run_info)
end

function Skia.TextBlobBuilderRunHandler.commitRunBuffer(text_blob_builder_run_handler, run_info)
    lib.SkTextBlobBuilderRunHandler_commitRunBuffer(text_blob_builder_run_handler, run_info)
end

function Skia.TextBlobBuilderRunHandler.commitLine(text_blob_builder_run_handler)
    lib.SkTextBlobBuilderRunHandler_commitLine(text_blob_builder_run_handler)
end

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
    return lib.SkTrimPathEffect_Make(startT, stopT, mode)
end

-- ## sk_typeface
Skia.Typeface = {}

function Skia.Typeface.delete(typeface)
    lib.SkTypeface_delete(typeface)
end

function Skia.Typeface.fontStyle(typeface)
    return lib.SkTypeface_fontStyle(typeface)
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
    return lib.SkTypeface_makeClone(typeface, arguments)
end

function Skia.Typeface.serialize(typeface, stream, behavior)
    lib.SkTypeface_serialize(typeface, stream, behavior)
end

function Skia.Typeface.serialize_2(typeface, behavior)
    return lib.SkTypeface_serialize_2(typeface, behavior)
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
    return lib.SkTypeface_copyTableData(typeface, tag)
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
    return lib.SkTypeface_openStream(typeface, ttcIndex)
end

function Skia.Typeface.openExistingStream(typeface, ttcIndex)
    return lib.SkTypeface_openExistingStream(typeface, ttcIndex)
end

--std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface typeface, SkScalerContextEffects &effects, SkDescriptor descriptor)
function Skia.Typeface.getBounds(typeface)
    return lib.SkTypeface_getBounds(typeface)
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
    return lib.SkTypeface_MakeEmpty()
end

function Skia.Typeface.MakeDeserialize(stream, font_mgr)
    return lib.SkTypeface_MakeDeserialize(stream, font_mgr)
end

--void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(make)(std::unique_ptr<SkStreamAsset>, SkFontArguments &))
function Skia.Typeface.MakeDefault()
    return lib.SkTypeface_MakeDefault()
end

function Skia.Typeface.MakeFromName(char familyName, fontStyle)
    return lib.SkTypeface_MakeFromName(char familyName, fontStyle)
end

function Skia.Typeface.MakeFromFile(char path, index)
    return lib.SkTypeface_MakeFromFile(char path, index)
end

function Skia.Typeface.MakeFromStream(stream_asset, index)
    return lib.SkTypeface_MakeFromStream(stream_asset, index)
end

function Skia.Typeface.MakeFromData(data, index)
    return lib.SkTypeface_MakeFromData(data, index)
end

function Skia.Typeface.MakeDeserialize_2(stream)
    return lib.SkTypeface_MakeDeserialize_2(stream)
end

-- ## sk_typeface_mac
Skia. = {}

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
    return lib.SkV2_normalize(v2)
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
    return lib.SkV2_Normalize(v)
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
    return lib.SkV3_cross(v3, v)
end

function Skia.V3.normalize(v3)
    return lib.SkV3_normalize(v3)
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
    return lib.SkV3_Cross(a, b)
end

function Skia.V3.Normalize(v)
    return lib.SkV3_Normalize(v)
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
    return lib.SkV4_normalize(v4)
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
    return lib.SkV4_Normalize(v)
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
    return lib.SkVertices_MakeCopy(mode, vertexCount, positions, texs, colors, indexCount, indices)
end

function Skia.Vertices.MakeCopy_2(mode, vertexCount, positions, texs, colors)
    return lib.SkVertices_MakeCopy_2(mode, vertexCount, positions, texs, colors)
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

function Skia.WStream.writeText(w_stream, char text)
    return lib.SkWStream_writeText(w_stream, char text)
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
    return lib.SkWbmpDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.WbmpDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkWbmpDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.WbmpDecoder.Decoder()
    return lib.SkWbmpDecoder_Decoder()
end

-- ## sk_webp_decoder
Skia.WebpDecoder = {}

function Skia.WebpDecoder.IsWbmp(ptr, size)
    return lib.SkWebpDecoder_IsWbmp(ptr, size)
end

function Skia.WebpDecoder.Decode(static_stream, result, decodeContext)
    return lib.SkWebpDecoder_Decode(static_stream, result, decodeContext)
end

function Skia.WebpDecoder.Decode_2(static_data, result, decodeContext)
    return lib.SkWebpDecoder_Decode_2(static_data, result, decodeContext)
end

function Skia.WebpDecoder.Decoder()
    return lib.SkWebpDecoder_Decoder()
end

-- ## sk_webp_encoder
Skia.WebpEncoder = {}

function Skia.WebpEncoder.Encode(dst, src, options)
    return lib.SkWebpEncoder_Encode(dst, src, options)
end

function Skia.WebpEncoder.Encode_2(ctx, img, options)
    return lib.SkWebpEncoder_Encode_2(ctx, img, options)
end

function Skia.WebpEncoder.EncodeAnimated(dst, encoderFrame, options)
    return lib.SkWebpEncoder_EncodeAnimated(dst, encoderFrame, options)
end

-- ## sk_yuva_info
Skia.YUVAInfo = {}

function Skia.YUVAInfo.new()
    return lib.SkYUVAInfo_new()
end

function Skia.YUVAInfo.new_2(info)
    return lib.SkYUVAInfo_new_2(info)
end

function Skia.YUVAInfo.new_3(dimensions, config, subsampling, space, origin, sitingX, sitingY)
    return lib.SkYUVAInfo_new_3(dimensions, config, subsampling, space, origin, sitingX, sitingY)
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
    return lib.SkYUVAInfo_planeSubsamplingFactors(yuva_info, planeIdx)
end

function Skia.YUVAInfo.dimensions(yuva_info)
    return lib.SkYUVAInfo_dimensions(yuva_info)
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
    return lib.SkYUVAInfo_originMatrix(yuva_info)
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
    return lib.SkYUVAInfo_makeSubsampling(yuva_info, subsampling)
end

function Skia.YUVAInfo.makeDimensions(yuva_info, size)
    return lib.SkYUVAInfo_makeDimensions(yuva_info, size)
end

function Skia.YUVAInfo.isValid(yuva_info)
    return lib.SkYUVAInfo_isValid(yuva_info)
end

function Skia.YUVAInfo.SubsamplingFactors(subsampling)
    return lib.SkYUVAInfo_SubsamplingFactors(subsampling)
end

function Skia.YUVAInfo.PlaneSubsamplingFactors(config, subsampling, planeIdx)
    return lib.SkYUVAInfo_PlaneSubsamplingFactors(config, subsampling, planeIdx)
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
    return lib.SkYUVAPixmapInfo_new()
end

function Skia.YUVAPixmapInfo.new_2(info, type, rowBytes)
    return lib.SkYUVAPixmapInfo_new_2(info, type, rowBytes)
end

function Skia.YUVAPixmapInfo.new_3(info, type, rowBytes)
    return lib.SkYUVAPixmapInfo_new_3(info, type, rowBytes)
end

function Skia.YUVAPixmapInfo.new_4(info)
    return lib.SkYUVAPixmapInfo_new_4(info)
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
    return lib.SkYUVAPixmapInfo_NumChannelsAndDataType(type)
end

-- ## sk_yuva_pixmaps
Skia.YUVAPixmaps = {}

function Skia.YUVAPixmaps.new()
    return lib.SkYUVAPixmaps_new()
end

function Skia.YUVAPixmaps.new_2(pixmaps)
    return lib.SkYUVAPixmaps_new_2(pixmaps)
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
    return lib.SkYUVAPixmaps_pixmapsInfo(yuva_pixmaps)
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
    return lib.SkYUVAPixmaps_Allocate(yuvaPixmapInfo)
end

function Skia.YUVAPixmaps.FromData(yuvaPixmapInfo, data)
    return lib.SkYUVAPixmaps_FromData(yuvaPixmapInfo, data)
end

function Skia.YUVAPixmaps.MakeCopy(src)
    return lib.SkYUVAPixmaps_MakeCopy(src)
end

function Skia.YUVAPixmaps.FromExternalMemory(yuvaPixmapInfo, memory)
    return lib.SkYUVAPixmaps_FromExternalMemory(yuvaPixmapInfo, memory)
end

function Skia.YUVAPixmaps.FromExternalPixmaps(yuvaInfo, pixmaps)
    return lib.SkYUVAPixmaps_FromExternalPixmaps(yuvaInfo, pixmaps)
end

-- ## skottie_animation

return Skia