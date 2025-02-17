extension Skia {
    typealias SkSerialProcsMutablePointer = UnsafeMutableRawPointer
    typealias sk_serial_procs_t = Int32
    struct SkSerialProcs {
        public var pointer: SkSerialProcsMutablePointer?
        public var handle: sk_serial_procs_t = -1

        init(pointer: SkSerialProcsMutablePointer?, handle: sk_serial_procs_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }

    typealias SkDeserialProcsMutablePointer = UnsafeMutableRawPointer
    typealias sk_deserial_procs_t = Int32
    struct SkDeserialProcs {
        public var pointer: SkDeserialProcsMutablePointer?
        public var handle: sk_deserial_procs_t = -1

        init(pointer: SkDeserialProcsMutablePointer?, handle: sk_deserial_procs_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
/*
    // #include "static/static_sk_android_codec.h"

    public final class AndroidCodecType {
        public let handle: sk_android_codec_t

        var pointer: AndroidCodecMutablePointer? {
            return static_sk_android_codec_get(handle)
        }

        public init(handle: sk_android_codec_t) {
            self.handle = handle
        }

        deinit {
            static_sk_android_codec_delete(handle)
        }
    }

    // #include "static/static_sk_b_box_hierarchy.h"

    public final class BBoxHierarchyType {
        public let handle: sk_b_box_hierarchy_t

        public init(handle: sk_b_box_hierarchy_t) {
            self.handle = handle
        }

        deinit {
            static_sk_b_box_hierarchy_delete(handle)
        }
    }

    // #include "static/static_sk_blend_mode.h"

    public final class OptionalBlendModeType {
        public let handle: optional_sk_blend_mode_t

        public init(handle: optional_sk_blend_mode_t) {
            self.handle = handle
        }

        deinit {
            static_optional_sk_blend_mode_delete(handle)
        }
    }

    // #include "static/static_sk_blender.h"

    public final class BlenderType {
        public let handle: sk_blender_t

        public init(handle: sk_blender_t) {
            self.handle = handle
        }

        deinit {
            static_sk_blender_delete(handle)
        }
    }

    // #include "static/static_sk_canvas.h"

    public final class CanvasType {
        public let handle: sk_canvas_t

        public init(handle: sk_canvas_t) {
            self.handle = handle
        }

        deinit {
            static_sk_canvas_delete(handle)
        }
    }

    // #include "static/static_sk_capabilities.h"

    public final class ConstCapabilitiesType {
        public let handle: const_sk_capabilities_t

        public init(handle: const_sk_capabilities_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_capabilities_delete(handle)
        }
    }

    // #include "static/static_sk_codec.h"

    public final class CodecType {
        public let handle: sk_codec_t

        public init(handle: sk_codec_t) {
            self.handle = handle
        }

        deinit {
            static_sk_codec_delete(handle)
        }
    }

    // #include "static/static_sk_codecs_decoder.h"

    public final class CodecsDecoderType {
        public let handle: sk_codecs_decoder_t

        public init(handle: sk_codecs_decoder_t) {
            self.handle = handle
        }

        deinit {
            static_sk_codecs_decoder_delete(handle)
        }
    }

    // #include "static/static_sk_color_4f.h"

    public final class Color4fType {
        public let handle: sk_color_4f_t

        public init(handle: sk_color_4f_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_4f_delete(handle)
        }
    }

    // #include "static/static_sk_color_filter.h"

    public final class ColorFilterType {
        public let handle: sk_color_filter_t

        public init(handle: sk_color_filter_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_filter_delete(handle)
        }
    }

    // #include "static/static_sk_color_info.h"

    public final class ColorInfoType {
        public let handle: sk_color_info_t

        public init(handle: sk_color_info_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_info_delete(handle)
        }
    }

    public final class ColorMatrixType {
        public let handle: sk_color_matrix_t

        public init(handle: sk_color_matrix_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_matrix_delete(handle)
        }
    }

    public final class ColorSpaceType {
        public let handle: sk_color_space_t

        public init(handle: sk_color_space_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_space_delete(handle)
        }
    }

    // #include "static/static_sk_color_table.h"

    public final class ColorTableType {
        public let handle: sk_color_table_t

        public init(handle: sk_color_table_t) {
            self.handle = handle
        }

        deinit {
            static_sk_color_table_delete(handle)
        }
    }

    // #include "static/static_sk_color.h"
    // #include "static/static_sk_contour_measure.h"

    public final class ContourMeasureType {
        public let handle: sk_contour_measure_t

        public init(handle: sk_contour_measure_t) {
            self.handle = handle
        }

        deinit {
            static_sk_contour_measure_delete(handle)
        }
    }

    // #include "static/static_sk_cubic_resampler.h"

    public final class CubicResamplerType {
        public let handle: sk_cubic_resampler_t

        public init(handle: sk_cubic_resampler_t) {
            self.handle = handle
        }

        deinit {
            static_sk_cubic_resampler_delete(handle)
        }
    }

    // #include "static/static_sk_data_table.h"

    public final class DataTableType {
        public let handle: sk_data_table_t

        public init(handle: sk_data_table_t) {
            self.handle = handle
        }

        deinit {
            static_sk_data_table_delete(handle)
        }
    }

    // #include "static/static_sk_data.h"

    public final class DataType {
        public let handle: sk_data_t

        public init(handle: sk_data_t) {
            self.handle = handle
        }

        deinit {
            static_sk_data_delete(handle)
        }
    }

    public final class ConstDataType {
        public let handle: const_sk_data_t

        public init(handle: const_sk_data_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_data_delete(handle)
        }
    }

    // #include "static/static_sk_document.h"

    public final class DocumentType {
        public let handle: sk_document_t

        public init(handle: sk_document_t) {
            self.handle = handle
        }

        deinit {
            static_sk_document_delete(handle)
        }
    }

    // #include "static/static_sk_drawable_gpu_draw_handler.h"

    public final class DrawableGpuDrawHandlerType {
        public let handle: sk_drawable_gpu_draw_handler_t

        public init(handle: sk_drawable_gpu_draw_handler_t) {
            self.handle = handle
        }

        deinit {
            static_sk_drawable_gpu_draw_handler_delete(handle)
        }
    }

    // #include "static/static_sk_drawable.h"

    public final class DrawableType {
        public let handle: sk_drawable_t

        public init(handle: sk_drawable_t) {
            self.handle = handle
        }

        deinit {
            static_sk_drawable_delete(handle)
        }
    }

    // #include "static/static_sk_encoder_frame.h"

    public final class ConstEncoderFrameType {
        public let handle: const_sk_encoder_frame_t

        public init(handle: const_sk_encoder_frame_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_encoder_frame_delete(handle)
        }
    }

    // #include "static/static_sk_encoder.h"

    public final class EncoderType {
        public let handle: sk_encoder_t

        public init(handle: sk_encoder_t) {
            self.handle = handle
        }

        deinit {
            static_sk_encoder_delete(handle)
        }
    }

    // #include "static/static_sk_executor.h"

    public final class ExecutorType {
        public let handle: sk_executor_t

        public init(handle: sk_executor_t) {
            self.handle = handle
        }

        deinit {
            static_sk_executor_delete(handle)
        }
    }

    // #include "static/static_sk_file_stream.h"

    public final class FileStreamType {
        public let handle: sk_file_stream_t

        public init(handle: sk_file_stream_t) {
            self.handle = handle
        }

        deinit {
            static_sk_file_stream_delete(handle)
        }
    }

    // #include "static/static_sk_flattenable_factory.h"

    public final class FlattenableFactoryType {
        public let handle: sk_flattenable_factory_t

        public init(handle: sk_flattenable_factory_t) {
            self.handle = handle
        }

        deinit {
            static_sk_flattenable_factory_delete(handle)
        }
    }

    // #include "static/static_sk_flattenable.h"

    public final class FlattenableType {
        public let handle: sk_flattenable_t

        public init(handle: sk_flattenable_t) {
            self.handle = handle
        }

        deinit {
            static_sk_flattenable_delete(handle)
        }
    }

    // #include "static/static_sk_font_arguments_palette.h"

    public final class FontArgumentsPaletteType {
        public let handle: sk_font_arguments_palette_t

        public init(handle: sk_font_arguments_palette_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_arguments_palette_delete(handle)
        }
    }

    // #include "static/static_sk_font_arguments_variation_position.h"

    public final class FontArgumentsVariationPositionType {
        public let handle: sk_font_arguments_variation_position_t

        public init(handle: sk_font_arguments_variation_position_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_arguments_variation_position_delete(handle)
        }
    }

    // #include "static/static_sk_font_arguments.h"

    public final class FontArgumentsType {
        public let handle: sk_font_arguments_t

        public init(handle: sk_font_arguments_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_arguments_delete(handle)
        }
    }

    // #include "static/static_sk_font_mgr.h"

    public final class FontMgrType {
        public let handle: sk_font_mgr_t

        public init(handle: sk_font_mgr_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_mgr_delete(handle)
        }
    }

    // #include "static/static_sk_font_style_set.h"

    public final class FontStyleSetType {
        public let handle: sk_font_style_set_t

        public init(handle: sk_font_style_set_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_style_set_delete(handle)
        }
    }

    // #include "static/static_sk_font_style.h"

    public final class FontStyleType {
        public let handle: sk_font_style_t

        public init(handle: sk_font_style_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_style_delete(handle)
        }
    }

    // #include "static/static_sk_font.h"

    public final class FontType {
        public let handle: sk_font_t

        public init(handle: sk_font_t) {
            self.handle = handle
        }

        deinit {
            static_sk_font_delete(handle)
        }
    }

    // #include "static/static_sk_i_point.h"

    public final class IPointType {
        public let handle: sk_i_point_t

        public init(handle: sk_i_point_t) {
            self.handle = handle
        }

        deinit {
            static_sk_i_point_delete(handle)
        }
    }

    // #include "static/static_sk_i_rect.h"

    public final class IRectType {
        public let handle: sk_i_rect_t

        public init(handle: sk_i_rect_t) {
            self.handle = handle
        }

        deinit {
            static_sk_i_rect_delete(handle)
        }
    }

    // #include "static/static_sk_i_size.h"

    public final class ISizeType {
        public let handle: sk_i_size_t

        public init(handle: sk_i_size_t) {
            self.handle = handle
        }

        deinit {
            static_sk_i_size_delete(handle)
        }
    }

    // #include "static/static_sk_id_change_listener.h"

    public final class IdChangeListenerType {
        public let handle: sk_id_change_listener_t

        public init(handle: sk_id_change_listener_t) {
            self.handle = handle
        }

        deinit {
            static_sk_id_change_listener_delete(handle)
        }
    }

    // #include "static/static_sk_image_filter.h"

    public final class ImageFilterType {
        public let handle: sk_image_filter_t

        public init(handle: sk_image_filter_t) {
            self.handle = handle
        }

        deinit {
            static_sk_image_filter_delete(handle)
        }
    }

    // #include "static/static_sk_image_generator.h"

    public final class ImageGeneratorType {
        public let handle: sk_image_generator_t

        public init(handle: sk_image_generator_t) {
            self.handle = handle
        }

        deinit {
            static_sk_image_generator_delete(handle)
        }
    }

    // #include "static/static_sk_image_info.h"

    public final class ImageInfoType {
        public let handle: sk_image_info_t

        public init(handle: sk_image_info_t) {
            self.handle = handle
        }

        deinit {
            static_sk_image_info_delete(handle)
        }
    }

    // #include "static/static_sk_image_read_pixels_callback.h"
    // #include "static/static_sk_image_required_properties.h"

    public final class ImageRequiredPropertiesType {
        public let handle: sk_image_required_properties_t

        public init(handle: sk_image_required_properties_t) {
            self.handle = handle
        }

        deinit {
            static_sk_image_required_properties_delete(handle)
        }
    }

    // #include "static/static_sk_image.h"

    public final class ImageType {
        public let handle: sk_image_t

        public init(handle: sk_image_t) {
            self.handle = handle
        }

        deinit {
            static_sk_image_delete(handle)
        }
    }

    // #include "static/static_sk_m_44.h"

    public final class M44Type {
        public let handle: sk_m_44_t

        public init(handle: sk_m_44_t) {
            self.handle = handle
        }

        deinit {
            static_sk_m_44_delete(handle)
        }
    }

    // #include "static/static_sk_mask_filter.h"

    public final class MaskFilterType {
        public let handle: sk_mask_filter_t

        public init(handle: sk_mask_filter_t) {
            self.handle = handle
        }

        deinit {
            static_sk_mask_filter_delete(handle)
        }
    }

    // #include "static/static_sk_matrix.h"

    public final class MatrixType {
        public let handle: sk_matrix_t

        public init(handle: sk_matrix_t) {
            self.handle = handle
        }

        deinit {
            static_sk_matrix_delete(handle)
        }
    }

    // #include "static/static_sk_memory_stream.h"

    public final class MemoryStreamType {
        public let handle: sk_memory_stream_t

        public init(handle: sk_memory_stream_t) {
            self.handle = handle
        }

        deinit {
            static_sk_memory_stream_delete(handle)
        }
    }

    // #include "static/static_sk_mesh_child_ptr.h"
    // #include "static/static_sk_mesh_index_buffer.h"

    public final class MeshIndexBufferType {
        public let handle: sk_mesh_index_buffer_t

        public init(handle: sk_mesh_index_buffer_t) {
            self.handle = handle
        }

        deinit {
            static_sk_mesh_index_buffer_delete(handle)
        }
    }

    // #include "static/static_sk_mesh_vertex_buffer.h"

    public final class MeshVertexBufferType {
        public let handle: sk_mesh_vertex_buffer_t

        public init(handle: sk_mesh_vertex_buffer_t) {
            self.handle = handle
        }

        deinit {
            static_sk_mesh_vertex_buffer_delete(handle)
        }
    }

    // #include "static/static_sk_path_effect.h"

    public final class PathEffectType {
        public let handle: sk_path_effect_t

        public init(handle: sk_path_effect_t) {
            self.handle = handle
        }

        deinit {
            static_sk_path_effect_delete(handle)
        }
    }

    // #include "static/static_sk_path.h"

    public final class PathType {
        public let handle: sk_path_t

        public init(handle: sk_path_t) {
            self.handle = handle
        }

        deinit {
            static_sk_path_delete(handle)
        }
    }

    // #include "static/static_sk_picture.h"

    public final class PictureType {
        public let handle: sk_picture_t

        public init(handle: sk_picture_t) {
            self.handle = handle
        }

        deinit {
            static_sk_picture_delete(handle)
        }
    }

    // #include "static/static_sk_pixel_ref.h"

    public final class PixelRefType {
        public let handle: sk_pixel_ref_t

        public init(handle: sk_pixel_ref_t) {
            self.handle = handle
        }

        deinit {
            static_sk_pixel_ref_delete(handle)
        }
    }

    // #include "static/static_sk_pixmap.h"

    public final class PixmapType {
        public let handle: sk_pixmap_t

        public init(handle: sk_pixmap_t) {
            self.handle = handle
        }

        deinit {
            static_sk_pixmap_delete(handle)
        }
    }

    // #include "static/static_sk_point_3.h"

    public final class Point3Type {
        public let handle: sk_point_3_t

        public init(handle: sk_point_3_t) {
            self.handle = handle
        }

        deinit {
            static_sk_point_3_delete(handle)
        }
    }

    // #include "static/static_sk_point_two.h"

    public final class PointTwo {
        public let handle: sk_point_two_t

        public init(handle: sk_point_two_t) {
            self.handle = handle
        }

        deinit {
            static_sk_point_two_delete(handle)
        }
    }

    // #include "static/static_sk_point.h"

    public final class PointType {
        public let handle: sk_point_t

        public init(handle: sk_point_t) {
            self.handle = handle
        }

        deinit {
            static_sk_point_delete(handle)
        }
    }

    // #include "static/static_sk_r_rect.h"

    public final class RRectType {
        public let handle: sk_r_rect_t

        public init(handle: sk_r_rect_t) {
            self.handle = handle
        }

        deinit {
            static_sk_r_rect_delete(handle)
        }
    }

    // #include "static/static_sk_rect.h"

    public final class RectType {
        public let handle: sk_rect_t

        public var pointer : SkRectMutablePointer? {
            return static_sk_rect_get_ptr(handle)
        }

        public init(handle: sk_rect_t) {
            self.handle = handle
        }

        deinit {
            static_sk_rect_delete(handle)
        }
    }

    // #include "static/static_sk_rsx_form.h"

    public final class RSXFormType {
        public let handle: sk_rsx_form_t

        public init(handle: sk_rsx_form_t) {
            self.handle = handle
        }

        deinit {
            static_sk_rsx_form_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_builder_builder_child.h"

    public final class RuntimeEffectBuilderBuilderChildType {
        public let handle: sk_runtime_effect_builder_builder_child_t

        public init(handle: sk_runtime_effect_builder_builder_child_t) {
            self.handle = handle
        }

        deinit {
            static_sk_runtime_effect_builder_builder_child_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_builder_builder_uniform.h"

    public final class RuntimeEffectBuilderBuilderUniformType {
        public let handle: sk_runtime_effect_builder_builder_uniform_t

        public init(handle: sk_runtime_effect_builder_builder_uniform_t) {
            self.handle = handle
        }

        deinit {
            static_sk_runtime_effect_builder_builder_uniform_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_child_ptr.h"

    public final class ConstRuntimeEffectChildPtrType {
        public let handle: const_sk_runtime_effect_child_ptr_t

        public init(handle: const_sk_runtime_effect_child_ptr_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_runtime_effect_child_ptr_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_child.h"

    public final class RuntimeEffectChildType {
        public let handle: const_sk_runtime_effect_child_t

        public init(handle: const_sk_runtime_effect_child_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_runtime_effect_child_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_result.h"

    public final class RuntimeEffectResultType {
        public let handle: sk_runtime_effect_result_t

        public init(handle: sk_runtime_effect_result_t) {
            self.handle = handle
        }

        deinit {
            static_sk_runtime_effect_result_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_traced_shader.h"

    public final class RuntimeEffectTracedShaderType {
        public let handle: sk_runtime_effect_traced_shader_t

        public init(handle: sk_runtime_effect_traced_shader_t) {
            self.handle = handle
        }

        deinit {
            static_sk_runtime_effect_traced_shader_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect_uniform.h"

    public final class RuntimeEffectUniformType {
        public let handle: const_sk_runtime_effect_uniform_t

        public init(handle: const_sk_runtime_effect_uniform_t) {
            self.handle = handle
        }

        deinit {
            static_const_sk_runtime_effect_uniform_delete(handle)
        }
    }

    // #include "static/static_sk_runtime_effect.h"

    public final class RuntimeEffectType {
        public let handle: sk_runtime_effect_t

        public init(handle: sk_runtime_effect_t) {
            self.handle = handle
        }

        deinit {
            static_sk_runtime_effect_delete(handle)
        }
    }

    // #include "static/static_sk_sampling_options.h"

    public final class SamplingOptionsType {
        public let handle: sk_sampling_options_t

        public init(handle: sk_sampling_options_t) {
            self.handle = handle
        }

        deinit {
            static_sk_sampling_options_delete(handle)
        }
    }

    // #include "static/static_sk_shader.h"

    public final class ShaderType {
        public let handle: sk_shader_t

        public init(handle: sk_shader_t) {
            self.handle = handle
        }

        deinit {
            static_sk_shader_delete(handle)
        }
    }

    // #include "static/static_sk_size_t.h"

    public final class SizeType {
        public let handle: sk_size_t

        public init(handle: sk_size_t) {
            self.handle = handle
        }

        deinit {
            static_sk_size_delete(handle)
        }
    }

    // #include "static/static_sk_stream_asset.h"

    public final class StreamAssetType {
        public let handle: sk_stream_asset_t

        public init(handle: sk_stream_asset_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_asset_delete(handle)
        }
    }

    // #include "static/static_sk_stream_memory.h"

    public final class StreamMemoryType {
        public let handle: sk_stream_memory_t

        public init(handle: sk_stream_memory_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_memory_delete(handle)
        }
    }

    // #include "static/static_sk_stream_rewindable.h"

    public final class StreamRewindableType {
        public let handle: sk_stream_rewindable_t

        public init(handle: sk_stream_rewindable_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_rewindable_delete(handle)
        }
    }

    // #include "static/static_sk_stream_seekable.h"

    public final class StreamSeekableType {
        public let handle: sk_stream_seekable_t

        public init(handle: sk_stream_seekable_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_seekable_delete(handle)
        }
    }

    // #include "static/static_sk_stream.h"

    public final class StreamType {
        public let handle: sk_stream_t

        public init(handle: sk_stream_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_delete(handle)
        }
    }

    public final class StreamPtrType {
        public let handle: sk_stream_ptr_t

        public init(handle: sk_stream_ptr_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stream_ptr_delete(handle)
        }
    }

    // #include "static/static_sk_string.h"

    public final class StringType {
        public let handle: sk_string_t

        public init(handle: sk_string_t) {
            self.handle = handle
        }

        deinit {
            static_sk_string_delete(handle)
        }
    }

    public final class SpanStringType {
        public let handle: sk_string_t

        public init(handle: sk_string_t) {
            self.handle = handle
        }

        deinit {
            static_sk_span_sk_string_delete(handle)
        }
    }

    // #include "static/static_sk_stroke_rec.h"

    public final class StrokeRecType {
        public let handle: sk_stroke_rec_t

        public init(handle: sk_stroke_rec_t) {
            self.handle = handle
        }

        deinit {
            static_sk_stroke_rec_delete(handle)
        }
    }

    // #include "static/static_sk_surface_props.h"

    public final class SurfacePropsType {
        public let handle: sk_surface_props_t

        public init(handle: sk_surface_props_t) {
            self.handle = handle
        }

        deinit {
            static_sk_surface_props_delete(handle)
        }
    }

    // #include "static/static_sk_surface.h"

    public final class SurfaceType {
        public let handle: sk_surface_t

        public init(handle: sk_surface_t) {
            self.handle = handle
        }

        deinit {
            static_sk_surface_delete(handle)
        }
    }

    // #include "static/static_sk_text_blob.h"

    public final class TextBlobType {
        public let handle: sk_text_blob_t

        public init(handle: sk_text_blob_t) {
            self.handle = handle
        }

        deinit {
            static_sk_text_blob_delete(handle)
        }
    }

    // #include "static/static_sk_typeface.h"

    public final class TypefaceType {
        public let handle: sk_typeface_t

        public init(handle: sk_typeface_t) {
            self.handle = handle
        }

        deinit {
            static_sk_typeface_delete(handle)
        }
    }

    // #include "static/static_sk_v2.h"

    public final class V2Type {
        public let handle: sk_v2_t

        public init(handle: sk_v2_t) {
            self.handle = handle
        }

        deinit {
            static_sk_v2_delete(handle)
        }
    }

    // #include "static/static_sk_v3.h"

    public final class V3Type {
        public let handle: sk_v3_t

        public init(handle: sk_v3_t) {
            self.handle = handle
        }

        deinit {
            static_sk_v3_delete(handle)
        }
    }

    // #include "static/static_sk_v4.h"

    public final class V4Type {
        public let handle: sk_v4_t

        public init(handle: sk_v4_t) {
            self.handle = handle
        }

        deinit {
            static_sk_v4_delete(handle)
        }
    }

    // #include "static/static_sk_vertices.h"

    public final class VerticesType {
        public let handle: sk_vertices_t

        public init(handle: sk_vertices_t) {
            self.handle = handle
        }

        deinit {
            static_sk_vertices_delete(handle)
        }
    }

    // #include "static/static_sk_yuva_info.h"

    public final class YuvaInfoType {
        public let handle: sk_yuva_info_t

        public init(handle: sk_yuva_info_t) {
            self.handle = handle
        }

        deinit {
            static_sk_yuva_info_delete(handle)
        }
    }

    // #include "static/static_sk_yuva_pixmap_info.h"

    public final class YuvaPixmapInfoType {
        public let handle: sk_yuva_pixmap_info_t

        public init(handle: sk_yuva_pixmap_info_t) {
            self.handle = handle
        }

        deinit {
            static_sk_yuva_pixmap_info_delete(handle)
        }
    }

    // #include "static/static_sk_yuva_pixmaps.h"

    public final class YuvaPixmapsType {
        public let handle: sk_yuva_pixmaps_t

        public init(handle: sk_yuva_pixmaps_t) {
            self.handle = handle
        }

        deinit {
            static_sk_yuva_pixmaps_delete(handle)
        }
    }

    // #include "static/static_std_chrono_milliseconds.h"

    public final class ChronoMillisecondsType {
        public let handle: chrono_milliseconds_t

        public init(handle: chrono_milliseconds_t) {
            self.handle = handle
        }

        deinit {
            static_chrono_milliseconds_delete(handle)
        }
    }

    // #include "static/static_std_function_void_void.h"

    public final class FunctionVoidVoidType {
        public let handle: function_void_void_t

        public init(handle: function_void_void_t) {
            self.handle = handle
        }

        deinit {
            static_function_void_void_delete(handle)
        }
    }

    // #include "static/static_std_string_view.h"

    public final class StringViewType {
        public let handle: string_view_t

        public init(handle: string_view_t) {
            self.handle = handle
        }

        deinit {
            static_string_view_delete(handle)
        }
    }

    // #include "static/static_std_tuple_int_int.h"

    public final class TupleIntIntType {
        public let handle: tuple_int_int_t

        public init(handle: tuple_int_int_t) {
            self.handle = handle
        }

        deinit {
            static_tuple_int_int_delete(handle)
        }
    }

    // #include "static/static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"

    public final class TupleIntYuvaPixmapInfoDataType {
        public let handle: tuple_int_sk_yuva_pixmap_info_data_type_t

        public init(handle: tuple_int_sk_yuva_pixmap_info_data_type_t) {
            self.handle = handle
        }

        deinit {
            static_tuple_int_sk_yuva_pixmap_info_data_type_delete(handle)
        }
    }

    // #include "static/static_std_tuple_sk_image_sk_codec_result.h"

    public final class TupleImageCodecResultType {
        public let handle: tuple_sk_image_sk_codec_result_t

        public init(handle: tuple_sk_image_sk_codec_result_t) {
            self.handle = handle
        }

        deinit {
            static_tuple_sk_image_sk_codec_result_delete(handle)
        }
    }

    // #include "static/static_std_vector_int_ptr.h"

    public final class VectorIntPtrType {
        public let handle: vector_int_ptr_t

        public init(handle: vector_int_ptr_t) {
            self.handle = handle
        }

        deinit {
            static_int_vector_ptr_delete(handle)
        }
    }

    // #include "static/static_std_vector_sk_codec_frame_info.h"

    public final class VectorCodecFrameInfoType {
        public let handle: vector_sk_codec_frame_info_t

        public init(handle: vector_sk_codec_frame_info_t) {
            self.handle = handle
        }

        deinit {
            static_vector_sk_codec_frame_info_delete(handle)
        }
    }

    // #include "static/static_std_vector_sk_scalar.h"

    public final class VectorScalarType {
        public let handle: vector_sk_scalar_t

        public init(handle: vector_sk_scalar_t) {
            self.handle = handle
        }

        deinit {
            static_vector_sk_scalar_delete(handle)
        }
    }
    */
}