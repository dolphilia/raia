#include "raia_skia.h"

// Skiaヘッダのインクルード
#include "include/codec/SkPngDecoder.h"
#include "include/core/SkAnnotation.h"
#include "include/core/SkBBHFactory.h"
#include "include/core/SkBitmap.h"
#include "include/core/SkBlender.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkCapabilities.h"
#include "include/core/SkColorFilter.h"
#include "include/core/SkColorPriv.h"
#include "include/core/SkColorTable.h"
#include "include/core/SkContourMeasure.h"
#include "include/core/SkCubicMap.h"
#include "include/core/SkData.h"
#include "include/core/SkDataTable.h"
#include "include/core/SkDocument.h"
#include "include/core/SkDrawable.h"
//#include "include/core/SkDrawLooper.h"
#include "include/core/SkExecutor.h"
#include "include/core/SkFlattenable.h"
#include "include/core/SkFont.h"
#include "include/core/SkFontArguments.h"
#include "include/core/SkFontMetrics.h"
#include "include/core/SkFontMgr.h"
#include "include/core/SkFontStyle.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageGenerator.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkMesh.h"
#include "include/core/SkOpenTypeSVGDecoder.h"
#include "include/core/SkOverdrawCanvas.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPathBuilder.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPictureRecorder.h"
#include "include/core/SkPixelRef.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRect.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkRegion.h"
#include "include/core/SkShader.h"
#include "include/core/SkStream.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkVertices.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/Sk2DPathEffect.h"
#include "include/effects/SkBlenders.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkColorMatrixFilter.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/effects/SkDiscretePathEffect.h"
#include "include/effects/SkGradientShader.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
//#include "include/effects/SkLayerDrawLooper.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkOverdrawColorFilter.h"
#include "include/gpu/graphite/Recorder.h"
#include "include/pathops/SkPathOps.h"

#include <map>
#include <utility>

//
// static
//

// struct
static std::map<std::string, SkRect> static_sk_rect;

// class
static std::map<std::string, SkSpan<SkMesh::ChildPtr>> static_sk_mesh_child_ptr;
static std::map<std::string, SkSpan<const SkMesh::ChildPtr>> static_const_sk_mesh_child_ptr;
static std::map<std::string, sk_sp<const SkCapabilities>> static_const_sk_capabilities;
static std::map<std::string, sk_sp<const SkData>> static_const_sk_data;
static std::map<std::string, sk_sp<SkBlender>> static_sk_blender;
static std::map<std::string, sk_sp<SkColorFilter>> static_sk_color_filter;
static std::map<std::string, sk_sp<SkColorSpace>> static_sk_color_space;
static std::map<std::string, sk_sp<SkColorTable>> static_sk_color_table;
static std::map<std::string, sk_sp<SkContourMeasure>> static_sk_contour_measure;
static std::map<std::string, sk_sp<SkData>> static_sk_data;
static std::map<std::string, sk_sp<SkDataTable>> static_sk_data_table;
static std::map<std::string, sk_sp<SkDrawable>> static_sk_drawable;
static std::map<std::string, sk_sp<SkFlattenable>> static_sk_flattenable;
static std::map<std::string, sk_sp<SkFontMgr>> static_sk_font_mgr;
static std::map<std::string, sk_sp<SkFontStyleSet>> static_sk_font_style_set;
static std::map<std::string, sk_sp<SkImage>> static_sk_image;
static std::map<std::string, sk_sp<SkImageFilter>> static_sk_image_filter;
static std::map<std::string, sk_sp<SkMaskFilter>> static_sk_mask_filter;
static std::map<std::string, sk_sp<SkMesh::IndexBuffer>> static_sk_mesh_index_buffer;
static std::map<std::string, sk_sp<SkMesh::VertexBuffer>> static_sk_mesh_vertex_buffer;
//static std::map<std::string, sk_sp<SkMeshSpecification>> static_sk_mesh_specification;
static std::map<std::string, sk_sp<SkPathEffect>> static_sk_path_effect;
static std::map<std::string, sk_sp<SkPicture>> static_sk_picture;
static std::map<std::string, sk_sp<SkPixelRef>> static_sk_pixel_ref;
static std::map<std::string, sk_sp<SkShader>> static_sk_shader;
static std::map<std::string, sk_sp<SkSurface>> static_sk_surface;
static std::map<std::string, sk_sp<SkTextBlob>> static_sk_text_blob;
static std::map<std::string, sk_sp<SkTypeface>> static_sk_typeface;
static std::map<std::string, sk_sp<SkVertices>> static_sk_vertices;
static std::map<std::string, std::unique_ptr<SkCanvas>> static_sk_canvas;
static std::map<std::string, std::unique_ptr<SkDrawable::GpuDrawHandler>> static_gpu_draw_handler;
static std::map<std::string, std::unique_ptr<SkExecutor>> static_sk_executor;
static std::map<std::string, std::unique_ptr<SkFILEStream>> static_sk_file_stream;
static std::map<std::string, std::unique_ptr<SkImageGenerator>> static_sk_image_generator;
static std::map<std::string, std::unique_ptr<SkMemoryStream>> static_sk_memory_stream;
static std::map<std::string, std::unique_ptr<SkStream>> static_sk_stream;
static std::map<std::string, std::unique_ptr<SkStreamAsset>> static_sk_stream_asset;

extern "C" {

//
// SkMemoryStream
//

SkMemoryStream *SkMemoryStream_new() {
    return new SkMemoryStream();
}

SkMemoryStream *SkMemoryStream_new_2(size_t length) {
    return new SkMemoryStream(length);
}

SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData) {
    return new SkMemoryStream(data, length, copyData);
}

SkMemoryStream *SkMemoryStream_new_4(const char *sk_data_key_in) {
    return new SkMemoryStream(static_sk_data[sk_data_key_in]);
}


void SkMemoryStream_setMemory(SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData) {
    memory_stream->setMemory(data, length, copyData);
}

void SkMemoryStream_setMemoryOwned(SkMemoryStream *memory_stream, const void *data, size_t length) {
    memory_stream->setMemoryOwned(data, length);
}

void SkMemoryStream_asData(const char *sk_data_key_out, SkMemoryStream *memory_stream) {
    static_sk_data[sk_data_key_out] = memory_stream->asData();
}

void SkMemoryStream_setData(const char *sk_data_key_in, SkMemoryStream *memory_stream) {
    memory_stream->setData(static_sk_data[sk_data_key_in]);
}

void SkMemoryStream_skipToAlign4(SkMemoryStream *memory_stream) {
    memory_stream->skipToAlign4();
}

const void * SkMemoryStream_getAtPos(SkMemoryStream *memory_stream) {
    return memory_stream->getAtPos();
}

size_t SkMemoryStream_read(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->read(buffer, size);
}

bool SkMemoryStream_isAtEnd(SkMemoryStream *memory_stream) {
    return memory_stream->isAtEnd();
}

size_t SkMemoryStream_peek(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->peek(buffer, size);
}

bool SkMemoryStream_rewind(SkMemoryStream *memory_stream) {
    return memory_stream->rewind();
}

void SkMemoryStream_duplicate(const char *sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream[sk_memory_stream_key_out] = memory_stream->duplicate();
}

size_t SkMemoryStream_getPosition(SkMemoryStream *memory_stream) {
    return memory_stream->getPosition();
}

bool SkMemoryStream_seek(SkMemoryStream *memory_stream, size_t position) {
    return memory_stream->seek(position);
}

bool SkMemoryStream_move(SkMemoryStream *memory_stream, long offset) {
    return memory_stream->move(offset);
}

void SkMemoryStream_fork(const char *sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream[sk_memory_stream_key_out] = memory_stream->fork();
}

size_t SkMemoryStream_getLength(SkMemoryStream *memory_stream) {
    return memory_stream->getLength();
}

const void * SkMemoryStream_getMemoryBase(SkMemoryStream *memory_stream) {
    return memory_stream->getMemoryBase();
}

bool SkMemoryStream_hasLength(SkMemoryStream *memory_stream) {
    return memory_stream->hasLength();
}

bool SkMemoryStream_hasPosition(SkMemoryStream *memory_stream) {
    return memory_stream->hasPosition();
}

size_t SkMemoryStream_skip(SkMemoryStream *memory_stream, size_t size) {
    return memory_stream->skip(size);
}

bool SkMemoryStream_readS8(SkMemoryStream *memory_stream, int8_t *i) {
    return memory_stream->readS8(i);
}

bool SkMemoryStream_readS16(SkMemoryStream *memory_stream, int16_t *i) {
    return memory_stream->readS16(i);
}

bool SkMemoryStream_readS32(SkMemoryStream *memory_stream, int32_t *i) {
    return memory_stream->readS32(i);
}

bool SkMemoryStream_readU8(SkMemoryStream *memory_stream, uint8_t *i) {
    return memory_stream->readU8(i);
}

bool SkMemoryStream_readU16(SkMemoryStream *memory_stream, uint16_t *i) {
    return memory_stream->readU16(i);
}

bool SkMemoryStream_readU32(SkMemoryStream *memory_stream, uint32_t *i) {
    return memory_stream->readU32(i);
}

bool SkMemoryStream_readBool(SkMemoryStream *memory_stream, bool *b) {
    return memory_stream->readBool(b);
}

bool SkMemoryStream_readScalar(SkMemoryStream *memory_stream, SkScalar *v) {
    return memory_stream->readScalar(v);
}

bool SkMemoryStream_readPackedUInt(SkMemoryStream *memory_stream, size_t *size) {
    return memory_stream->readPackedUInt(size);
}


// static

void SkMemoryStream_MakeCopy(const char *sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::MakeCopy(data, length);
}

void SkMemoryStream_MakeDirect(const char *sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::MakeDirect(data, length);
}

void SkMemoryStream_Make(const char *sk_memory_stream_key_out, const char *sk_data_key_in) {
    static_sk_memory_stream[sk_memory_stream_key_out] = SkMemoryStream::Make(static_sk_data[sk_data_key_in]);
}

//
// SkMesh
//

// SkMesh & operator=(const SkMesh &)
// SkMesh & operator=(SkMesh &&)

/*
SkMesh *SkMesh_new() {
    return new SkMesh();
}

SkMesh *SkMesh_new_2(const SkMesh *mesh) {
    return new SkMesh(*mesh);
}

SkMesh *SkMesh_new_3(SkMesh &&mesh) { //@TODO
    return new SkMesh(mesh);
}

void SkMesh_delete(SkMesh *mesh) {
    delete mesh;
}

void SkMesh_refSpec(const char *sk_mesh_specification_key_out, SkMesh *mesh) {
    static_sk_mesh_specification[sk_mesh_specification_key_out] = mesh->refSpec();
}

SkMeshSpecification * SkMesh_spec(SkMesh *mesh) {
    return mesh->spec();
}

SkMesh::Mode SkMesh_mode(SkMesh *mesh) {
    return mesh->mode();
}

void SkMesh_refVertexBuffer(const char *sk_mesh_vertex_buffer_key_out, SkMesh *mesh) {
    static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_out] = mesh->refVertexBuffer();
}

SkMesh::VertexBuffer * SkMesh_vertexBuffer(SkMesh *mesh) {
    return mesh->vertexBuffer();
}

size_t SkMesh_vertexOffset(SkMesh *mesh) {
    return mesh->vertexOffset();
}

size_t SkMesh_vertexCount(SkMesh *mesh) {
    return mesh->vertexCount();
}

void SkMesh_refIndexBuffer(const char *sk_mesh_index_buffer_key_out, SkMesh *mesh) {
    static_sk_mesh_index_buffer[sk_mesh_index_buffer_key_out] = mesh->refIndexBuffer();
}

SkMesh::IndexBuffer * SkMesh_indexBuffer(SkMesh *mesh) {
    return mesh->indexBuffer();
}

size_t SkMesh_indexOffset(SkMesh *mesh) {
    return mesh->indexOffset();
}

size_t SkMesh_indexCount(SkMesh *mesh) {
    return mesh->indexCount();
}

void SkMesh_refUniforms(const char *sk_data_key_out, SkMesh *mesh) {
    static_const_sk_data[sk_data_key_out] = mesh->refUniforms();
}

const SkData * SkMesh_uniforms(SkMesh *mesh) {
    return mesh->uniforms();
}

void SkMesh_children(const char *sk_mesh_child_ptr_key_out, SkMesh *mesh) {
    static_const_sk_mesh_child_ptr[sk_mesh_child_ptr_key_out] = mesh->children();
}

SkRect SkMesh_bounds(SkMesh *mesh) {
    return mesh->bounds();
}

bool SkMesh_isValid(SkMesh *mesh) {
    return mesh->isValid();
}

SkMesh::Result SkMesh_Make(const char *sk_mesh_specification_key_in, const char *sk_mesh_vertex_buffer_key_in, const char *sk_data_key_in, const char *sk_mesh_child_ptr_key_in, SkMesh::Mode mode, size_t vertexCount, size_t vertexOffset, const SkRect *bounds) {
    return SkMesh::Make(static_sk_mesh_specification[sk_mesh_specification_key_in], mode, static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_in], vertexCount, vertexOffset, static_const_sk_data[sk_data_key_in], static_sk_mesh_child_ptr[sk_mesh_child_ptr_key_in], *bounds);
}

SkMesh::Result SkMesh_MakeIndexed(const char *sk_mesh_specification_key_in, const char *sk_mesh_vertex_buffer_key_in, const char *sk_mesh_index_buffer_key_in, const char *sk_data_key_in, const char *sk_mesh_child_ptr_key_in, SkMesh::Mode mode, size_t vertexCount, size_t vertexOffset, size_t indexCount, size_t indexOffset, const SkRect *bounds) {
    return SkMesh::MakeIndexed(static_sk_mesh_specification[sk_mesh_specification_key_in], mode, static_sk_mesh_vertex_buffer[sk_mesh_vertex_buffer_key_in], vertexCount, vertexOffset, static_sk_mesh_index_buffer[sk_mesh_index_buffer_key_in], indexCount, indexOffset, static_const_sk_data[sk_data_key_in], static_sk_mesh_child_ptr[sk_mesh_child_ptr_key_in], *bounds);
}
*/

//
// SkMeshSpecification
//

/*
void SkMeshSpecification_delete(SkMeshSpecification *mesh_specification) {
    delete mesh_specification;
}

SkSpan<const SkMeshSpecification::Attribute> SkMeshSpecification_attributes(SkMeshSpecification *mesh_specification) {
    return mesh_specification->attributes();
}

size_t SkMeshSpecification_uniformSize(SkMeshSpecification *mesh_specification) {
    return mesh_specification->uniformSize();
}

SkSpan<const SkMeshSpecification::Uniform> SkMeshSpecification_uniforms(SkMeshSpecification *mesh_specification) {
    return mesh_specification->uniforms();
}

SkSpan<const SkMeshSpecification::Child> SkMeshSpecification_children(SkMeshSpecification *mesh_specification) {
    return mesh_specification->children();
}

const SkMeshSpecification::Child * SkMeshSpecification_findChild(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findChild(name);
}

const SkMeshSpecification::Uniform * SkMeshSpecification_findUniform(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findUniform(name);
}

const SkMeshSpecification::Attribute * SkMeshSpecification_findAttribute(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findAttribute(name);
}

const SkMeshSpecification::Varying * SkMeshSpecification_findVarying(SkMeshSpecification *mesh_specification, std::string_view name) {
    return mesh_specification->findVarying(name);
}

size_t SkMeshSpecification_stride(SkMeshSpecification *mesh_specification) {
    return mesh_specification->stride();
}

bool SkMeshSpecification_unique(SkMeshSpecification *mesh_specification) {
    return mesh_specification->unique();
}

void SkMeshSpecification_ref(SkMeshSpecification *mesh_specification) {
    mesh_specification->ref();
}

void SkMeshSpecification_unref(SkMeshSpecification *mesh_specification) {
    mesh_specification->unref();
}

void SkMeshSpecification_deref(SkMeshSpecification *mesh_specification) {
    mesh_specification->deref();
}

bool SkMeshSpecification_refCntGreaterThan(SkMeshSpecification *mesh_specification, int32_t threadIsolatedTestCnt) {
    return mesh_specification->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

SkMeshSpecification::Result SkMeshSpecification_Make(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs);
}

SkMeshSpecification::Result SkMeshSpecification_Make_2(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs, cs);
}

SkMeshSpecification::Result SkMeshSpecification_Make_3(SkSpan<const SkMeshSpecification::Attribute> attributes, size_t vertexStride, SkSpan<const SkMeshSpecification::Varying> varyings, const SkString &vs, const SkString &fs, sk_sp<SkColorSpace> cs, SkAlphaType at) {
    return SkMeshSpecification::Make(attributes, vertexStride, varyings, vs, fs, cs, at);
}
*/

//
// SkNullWStream
//

/*
SkNullWStream *SkNullWStream_new(SkNullWStream *null_w_stream) {
    return new SkNullWStream();
}

void SkNullWStream_delete(SkNullWStream *null_w_stream) {
    delete null_w_stream;
}

bool SkNullWStream_write(SkNullWStream *null_w_stream, const void *v, size_t n) {
    return null_w_stream->write(v, n);
}

void SkNullWStream_flush(SkNullWStream *null_w_stream) {
    null_w_stream->flush();
}

size_t SkNullWStream_bytesWritten(SkNullWStream *null_w_stream) {
    return null_w_stream->bytesWritten();
}

bool SkNullWStream_write8(SkNullWStream *null_w_stream, U8CPU value) {
    return null_w_stream->write8(value);
}

bool SkNullWStream_write16(SkNullWStream *null_w_stream, U16CPU value) {
    return null_w_stream->write16(value);
}

bool SkNullWStream_write32(SkNullWStream *null_w_stream, uint32_t v) {
    return null_w_stream->write32(v);
}

bool SkNullWStream_writeText(SkNullWStream *null_w_stream, const char text[]) {
    return null_w_stream->writeText(text);
}

bool SkNullWStream_newline(SkNullWStream *null_w_stream) {
    return null_w_stream->newline();
}

bool SkNullWStream_writeDecAsText(SkNullWStream *null_w_stream, int32_t v) {
    return null_w_stream->writeDecAsText(v);
}

bool SkNullWStream_writeBigDecAsText(SkNullWStream *null_w_stream, int64_t v, int minDigits) {
    return null_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkNullWStream_writeHexAsText(SkNullWStream *null_w_stream, uint32_t v, int minDigits) {
    return null_w_stream->writeHexAsText(v, minDigits);
}

bool SkNullWStream_writeScalarAsText(SkNullWStream *null_w_stream, SkScalar v) {
    return null_w_stream->writeScalarAsText(v);
}

bool SkNullWStream_writeBool(SkNullWStream *null_w_stream, bool v) {
    return null_w_stream->writeBool(v);
}

bool SkNullWStream_writeScalar(SkNullWStream *null_w_stream, SkScalar v) {
    return null_w_stream->writeScalar(v);
}

bool SkNullWStream_writePackedUInt(SkNullWStream *null_w_stream, size_t v) {
    return null_w_stream->writePackedUInt(v);
}

bool SkNullWStream_writeStream(SkNullWStream *null_w_stream, SkStream *input, size_t length) {
    return null_w_stream->writeStream(input, length);
}

// static

int SkNullWStream_SizeOfPackedUInt(size_t value) {
    return SkNullWStream::SizeOfPackedUInt(value);
}
*/

//
// SkNVRefCnt<Derived>
//

/*
SkNVRefCnt *SkNVRefCnt_new(SkNVRefCnt *nv_ref_cnt) {
    return new SkNVRefCnt();
}

void SkNVRefCnt_delete(SkNVRefCnt *nv_ref_cnt) {
    delete nv_ref_cnt;
}

bool unique(SkNVRefCnt *nv_ref_cnt) {
    return nv_ref_cnt->
}

void ref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

void unref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

void deref(SkNVRefCnt *nv_ref_cnt) {
    nv_ref_cnt->
}

bool refCntGreaterThan(SkNVRefCnt *nv_ref_cnt, int32_t threadIsolatedTestCnt) {
    return nv_ref_cnt->
}
*/

//
// SkOpBuilder
//

void SkOpBuilder_add(SkOpBuilder *op_builder, const SkPath &path, SkPathOp _operator) {
    op_builder->add(path, _operator);
}

bool SkOpBuilder_resolve(SkOpBuilder *op_builder, SkPath *result) {
    return op_builder->resolve(result);
}

//
// SkOpenTypeSVGDecoder
//

void SkOpenTypeSVGDecoder_delete(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    delete open_type_svg_decoder;
}

size_t SkOpenTypeSVGDecoder_approximateSize(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    return open_type_svg_decoder->approximateSize();
}

bool SkOpenTypeSVGDecoder_render(SkOpenTypeSVGDecoder *open_type_svg_decoder, SkCanvas &canvas, int upem, SkGlyphID glyphId, SkColor foregroundColor, SkSpan<SkColor> palette) {
    return open_type_svg_decoder->render(canvas, upem, glyphId, foregroundColor, palette);
}

//
// SkOverdrawCanvas
//

void SkOverdrawCanvas_delete(SkOverdrawCanvas *overdraw_canvas) {
    delete overdraw_canvas;
}

void SkOverdrawCanvas_onDrawTextBlob(SkOverdrawCanvas *overdraw_canvas, const SkTextBlob *blob, SkScalar scalar1, SkScalar scalar2, const SkPaint &paint) {
    overdraw_canvas->onDrawTextBlob(blob, scalar1, scalar2, paint);
}

void SkOverdrawCanvas_onDrawGlyphRunList(SkOverdrawCanvas *overdraw_canvas, const sktext::GlyphRunList &glyphRunList, const SkPaint &paint) {
    overdraw_canvas->onDrawGlyphRunList(glyphRunList, paint);
}

void SkOverdrawCanvas_onDrawPatch(SkOverdrawCanvas *overdraw_canvas, const SkPoint point1[12], const SkColor color[4], const SkPoint point2[4], SkBlendMode mode, const SkPaint &paint) {
    overdraw_canvas->onDrawPatch(point1, color, point2, mode, paint);
}

void SkOverdrawCanvas_onDrawPaint(SkOverdrawCanvas *overdraw_canvas, const SkPaint &paint) {
    overdraw_canvas->onDrawPaint(paint);
}

void SkOverdrawCanvas_onDrawBehind(SkOverdrawCanvas *overdraw_canvas, const SkPaint &paint) {
    overdraw_canvas->onDrawBehind(paint);
}

void SkOverdrawCanvas_onDrawRect(SkOverdrawCanvas *overdraw_canvas, const SkRect &rect, const SkPaint &paint) {
    overdraw_canvas->onDrawRect(rect, paint);
}

void SkOverdrawCanvas_onDrawRegion(SkOverdrawCanvas *overdraw_canvas, const SkRegion &region, const SkPaint &paint) {
    overdraw_canvas->onDrawRegion(region, paint);
}

void SkOverdrawCanvas_onDrawOval(SkOverdrawCanvas *overdraw_canvas, const SkRect &rect, const SkPaint &paint) {
    overdraw_canvas->onDrawOval(rect, paint);
}

void SkOverdrawCanvas_onDrawArc(SkOverdrawCanvas *overdraw_canvas, const SkRect &rect, SkScalar scalar1, SkScalar scalar2, bool v, const SkPaint &paint) {
    overdraw_canvas->onDrawArc(rect, scalar1, scalar2, v, paint);
}

void SkOverdrawCanvas_onDrawDRRect(SkOverdrawCanvas *overdraw_canvas, const SkRRect &rect1, const SkRRect &rect2, const SkPaint &paint) {
    overdraw_canvas->onDrawDRRect(rect1, rect2, paint);
}

void SkOverdrawCanvas_onDrawRRect(SkOverdrawCanvas *overdraw_canvas, const SkRRect &rect, const SkPaint &paint) {
    overdraw_canvas->onDrawRRect(rect, paint);
}

void SkOverdrawCanvas_onDrawPoints(SkOverdrawCanvas *overdraw_canvas, SkOverdrawCanvas::PointMode mode, size_t size, const SkPoint point[], const SkPaint &paint) {
    overdraw_canvas->onDrawPoints(mode, size, point, paint);
}

void SkOverdrawCanvas_onDrawVerticesObject(SkOverdrawCanvas *overdraw_canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint &paint) {
    overdraw_canvas->onDrawVerticesObject(vertices, mode, paint);
}

void SkOverdrawCanvas_onDrawPath(SkOverdrawCanvas *overdraw_canvas, const SkPath &path, const SkPaint &paint) {
    overdraw_canvas->onDrawPath(path, paint);
}

void SkOverdrawCanvas_onDrawImage2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, SkScalar scalar1, SkScalar scalar2, const SkSamplingOptions &options, const SkPaint *paint) {
    overdraw_canvas->onDrawImage2(image, scalar1, scalar2, options, paint);
}

void SkOverdrawCanvas_onDrawImageRect2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkRect &rect1, const SkRect &rect2, const SkSamplingOptions &options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint) {
    overdraw_canvas->onDrawImageRect2(image, rect1, rect2, options, paint, constraint);
}

void SkOverdrawCanvas_onDrawImageLattice2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkOverdrawCanvas::Lattice &lattice, const SkRect &rect, SkFilterMode mode, const SkPaint *paint) {
    overdraw_canvas->onDrawImageLattice2(image, lattice, rect, mode, paint);
}

void SkOverdrawCanvas_onDrawAtlas2(SkOverdrawCanvas *overdraw_canvas, const SkImage * image, const SkRSXform form[], const SkRect rect1[], const SkColor color[], int v, SkBlendMode mode, const SkSamplingOptions &options, const SkRect *rect2, const SkPaint *paint) {
    overdraw_canvas->onDrawAtlas2(image, form, rect1, color, v, mode, options, rect2, paint);
}

void SkOverdrawCanvas_onDrawDrawable(SkOverdrawCanvas *overdraw_canvas, SkDrawable *drawable, const SkMatrix *matrix) {
    overdraw_canvas->onDrawDrawable(drawable, matrix);
}

void SkOverdrawCanvas_onDrawPicture(SkOverdrawCanvas *overdraw_canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint) {
    overdraw_canvas->onDrawPicture(picture, matrix, paint);
}

void SkOverdrawCanvas_onDrawAnnotation(SkOverdrawCanvas *overdraw_canvas, const SkRect &rect, const char key[], SkData *value) {
    overdraw_canvas->onDrawAnnotation(rect, key, value);
}

void SkOverdrawCanvas_onDrawShadowRec(SkOverdrawCanvas *overdraw_canvas, const SkPath &path, const SkDrawShadowRec &rec) {
    overdraw_canvas->onDrawShadowRec(path, rec);
}

void SkOverdrawCanvas_onDrawEdgeAAQuad(SkOverdrawCanvas *overdraw_canvas, const SkRect &rect, const SkPoint point[4], SkCanvas::QuadAAFlags flags, const SkColor4f & color, SkBlendMode mode) {
    overdraw_canvas->onDrawEdgeAAQuad(rect, point, flags, color, mode);
}

void SkOverdrawCanvas_onDrawEdgeAAImageSet2(SkOverdrawCanvas *overdraw_canvas, const SkOverdrawCanvas::ImageSetEntry entry[], int count, const SkPoint point[], const SkMatrix matrix[], const SkSamplingOptions &options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint) {
    overdraw_canvas->onDrawEdgeAAImageSet2(entry, count, point, matrix, options, paint, constraint);
}

//
// SkOverdrawColorFilter
//

// static
void SkOverdrawColorFilter_MakeWithSkColors(const char *sk_color_filter_key_out, const SkColor color[SkOverdrawColorFilter::kNumColors]) {
    static_sk_color_filter[sk_color_filter_key_out] = SkOverdrawColorFilter::MakeWithSkColors(color);
}

//
// SkPaint
//

//SkPaint & operator=(const SkPaint &paint)
//SkPaint & operator=(SkPaint &&paint)

SkPaint *SkPaint_new() {
    return new SkPaint();
}

SkPaint *SkPaint_new_2(const SkColor4f &color, SkColorSpace *colorSpace) {
    return new SkPaint(color, colorSpace);
}

SkPaint *SkPaint_new_3(const SkPaint &paint) {
    return new SkPaint(paint);
}

SkPaint *SkPaint_new_4(SkPaint &&paint) { //@TODO
    return new SkPaint(paint);
}

void SkPaint_delete(SkPaint *paint) {
    delete paint;
}

void SkPaint_reset(SkPaint *paint) {
    paint->reset();
}

bool SkPaint_isAntiAlias(SkPaint *paint) {
    return paint->isAntiAlias();
}

void SkPaint_setAntiAlias(SkPaint *paint, bool aa) {
    paint->setAntiAlias(aa);
}

bool SkPaint_isDither(SkPaint *paint) {
    return paint->isDither();
}

void SkPaint_setDither(SkPaint *paint, bool dither) {
    paint->setDither(dither);
}

SkPaint::Style SkPaint_getStyle(SkPaint *paint) {
    return paint->getStyle();
}

void SkPaint_setStyle(SkPaint *paint, SkPaint::Style style) {
    paint->setStyle(style);
}

void SkPaint_setStroke(SkPaint *paint, bool v) {
    paint->setStroke(v);
}

SkColor SkPaint_getColor(SkPaint *paint) {
    return paint->getColor();
}

SkColor4f SkPaint_getColor4f(SkPaint *paint) {
    return paint->getColor4f();
}

void SkPaint_setColor(SkPaint *paint, SkColor color) {
    paint->setColor(color);
}

void SkPaint_setColor_2(SkPaint *paint, const SkColor4f &color, SkColorSpace *colorSpace) {
    paint->setColor(color, colorSpace);
}

void SkPaint_setColor4f(SkPaint *paint, const SkColor4f &color, SkColorSpace *colorSpace) {
    paint->setColor4f(color, colorSpace);
}

float SkPaint_getAlphaf(SkPaint *paint) {
    return paint->getAlphaf();
}

uint8_t SkPaint_getAlpha(SkPaint *paint) {
    return paint->getAlpha();
}

void SkPaint_setAlphaf(SkPaint *paint, float a) {
    paint->setAlphaf(a);
}

void SkPaint_setAlpha(SkPaint *paint, U8CPU a) {
    paint->setAlpha(a);
}

void SkPaint_setARGB(SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    paint->setARGB(a, r, g, b);
}

SkScalar SkPaint_getStrokeWidth(SkPaint *paint) {
    return paint->getStrokeWidth();
}

void SkPaint_setStrokeWidth(SkPaint *paint, SkScalar width) {
    paint->setStrokeWidth(width);
}

SkScalar SkPaint_getStrokeMiter(SkPaint *paint) {
    return paint->getStrokeMiter();
}

void SkPaint_setStrokeMiter(SkPaint *paint, SkScalar miter) {
    paint->setStrokeMiter(miter);
}

SkPaint::Cap SkPaint_getStrokeCap(SkPaint *paint) {
    return paint->getStrokeCap();
}

void SkPaint_setStrokeCap(SkPaint *paint, SkPaint::Cap cap) {
    paint->setStrokeCap(cap);
}

SkPaint::Join SkPaint_getStrokeJoin(SkPaint *paint) {
    return paint->getStrokeJoin();
}

void SkPaint_setStrokeJoin(SkPaint *paint, SkPaint::Join join) {
    paint->setStrokeJoin(join);
}

SkShader * SkPaint_getShader(SkPaint *paint) {
    return paint->getShader();
}

sk_sp<SkShader> SkPaint_refShader(SkPaint *paint) {
    return paint->refShader();
}

void SkPaint_setShader(SkPaint *paint, sk_sp<SkShader> shader) {
    paint->setShader(shader);
}

SkColorFilter * SkPaint_getColorFilter(SkPaint *paint) {
    return paint->getColorFilter();
}

sk_sp<SkColorFilter> SkPaint_refColorFilter(SkPaint *paint) {
    return paint->refColorFilter();
}

void SkPaint_setColorFilter(SkPaint *paint, sk_sp<SkColorFilter> colorFilter) {
    paint->setColorFilter(colorFilter);
}

std::optional<SkBlendMode> SkPaint_asBlendMode(SkPaint *paint) {
    return paint->asBlendMode();
}

SkBlendMode SkPaint_getBlendMode_or(SkPaint *paint, SkBlendMode defaultMode) {
    return paint->getBlendMode_or(defaultMode);
}

bool SkPaint_isSrcOver(SkPaint *paint) {
    return paint->isSrcOver();
}

void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode) {
    paint->setBlendMode(mode);
}

SkBlender * SkPaint_getBlender(SkPaint *paint) {
    return paint->getBlender();
}

sk_sp<SkBlender> SkPaint_refBlender(SkPaint *paint) {
    return paint->refBlender();
}

void SkPaint_setBlender(SkPaint *paint, sk_sp<SkBlender> blender) {
    paint->setBlender(blender);
}

SkPathEffect * SkPaint_getPathEffect(SkPaint *paint) {
    return paint->getPathEffect();
}

sk_sp<SkPathEffect> SkPaint_refPathEffect(SkPaint *paint) {
    return paint->refPathEffect();
}

void SkPaint_setPathEffect(SkPaint *paint, sk_sp<SkPathEffect> pathEffect) {
    paint->setPathEffect(pathEffect);
}

SkMaskFilter * SkPaint_getMaskFilter(SkPaint *paint) {
    return paint->getMaskFilter();
}

sk_sp<SkMaskFilter> SkPaint_refMaskFilter(SkPaint *paint) {
    return paint->refMaskFilter();
}

void SkPaint_setMaskFilter(SkPaint *paint, sk_sp<SkMaskFilter> maskFilter) {
    paint->setMaskFilter(maskFilter);
}

SkImageFilter * SkPaint_getImageFilter(SkPaint *paint) {
    return paint->getImageFilter();
}

sk_sp<SkImageFilter> SkPaint_refImageFilter(SkPaint *paint) {
    return paint->refImageFilter();
}

void SkPaint_setImageFilter(SkPaint *paint, sk_sp<SkImageFilter> imageFilter) {
    paint->setImageFilter(imageFilter);
}

bool SkPaint_nothingToDraw(SkPaint *paint) {
    return paint->nothingToDraw();
}

bool SkPaint_canComputeFastBounds(SkPaint *paint) {
    return paint->canComputeFastBounds();
}

const SkRect & SkPaint_computeFastBounds(SkPaint *paint, const SkRect &orig, SkRect *storage) {
    return paint->computeFastBounds(orig, storage);
}

const SkRect & SkPaint_computeFastStrokeBounds(SkPaint *paint, const SkRect &orig, SkRect *storage) {
    return paint->computeFastStrokeBounds(orig, storage);
}

const SkRect & SkPaint_doComputeFastBounds(SkPaint *paint, const SkRect &orig, SkRect *storage, SkPaint::Style style) {
    return paint->doComputeFastBounds(orig, storage, style);
}

//
// SkPath
//

//SkPath & operator=(const SkPath &path)

SkPath *SkPath_new() {
    return new SkPath();
}

SkPath *SkPath_new_2(const SkPath &path) {
    return new SkPath();
}

void SkPath_delete(SkPath *path) {
    delete path;
}

bool SkPath_isInterpolatable(SkPath *path, const SkPath &compare) {
    return path->isInterpolatable(compare);
}

bool SkPath_interpolate(SkPath *path, const SkPath &ending, SkScalar weight, SkPath *out) {
    return path->interpolate(ending, weight, out);
}

SkPathFillType SkPath_getFillType(SkPath *path) {
    return path->getFillType();
}

void SkPath_setFillType(SkPath *path, SkPathFillType ft) {
    path->setFillType(ft);
}

bool SkPath_isInverseFillType(SkPath *path) {
    return path->isInverseFillType();
}

void SkPath_toggleInverseFillType(SkPath *path) {
    path->toggleInverseFillType();
}

bool SkPath_isConvex(SkPath *path) {
    return path->isConvex();
}

bool SkPath_isOval(SkPath *path, SkRect *bounds) {
    return path->isOval(bounds);
}

bool SkPath_isRRect(SkPath *path, SkRRect *rrect) {
    return path->isRRect(rrect);
}

SkPath & SkPath_reset(SkPath *path) {
    return path->reset();
}

SkPath & SkPath_rewind(SkPath *path) {
    return path->rewind();
}

bool SkPath_isEmpty(SkPath *path) {
    return path->isEmpty();
}

bool SkPath_isLastContourClosed(SkPath *path) {
    return path->isLastContourClosed();
}

bool SkPath_isFinite(SkPath *path) {
    return path->isFinite();
}

bool SkPath_isVolatile(SkPath *path) {
    return path->isVolatile();
}

SkPath & SkPath_setIsVolatile(SkPath *path, bool isVolatile) {
    return path->setIsVolatile(isVolatile);
}

bool SkPath_isLine(SkPath *path, SkPoint line[2]) {
    return path->isLine(line);
}

int SkPath_countPoints(SkPath *path) {
    return path->countPoints();
}

SkPoint SkPath_getPoint(SkPath *path, int index) {
    return path->getPoint(index);
}

int SkPath_getPoints(SkPath *path, SkPoint points[], int max) {
    return path->getPoints(points, max);
}

int SkPath_countVerbs(SkPath *path) {
    return path->countVerbs();
}

int SkPath_getVerbs(SkPath *path, uint8_t verbs[], int max) {
    return path->getVerbs(verbs, max);
}

size_t SkPath_approximateBytesUsed(SkPath *path) {
    return path->approximateBytesUsed();
}

void SkPath_swap(SkPath *path, SkPath &other) {
    path->swap(other);
}

const SkRect & SkPath_getBounds(SkPath *path) {
    return path->getBounds();
}

void SkPath_updateBoundsCache(SkPath *path) {
    path->updateBoundsCache();
}

SkRect SkPath_computeTightBounds(SkPath *path) {
    return path->computeTightBounds();
}

bool SkPath_conservativelyContainsRect(SkPath *path, const SkRect &rect) {
    return path->conservativelyContainsRect(rect);
}

void SkPath_incReserve(SkPath *path, int extraPtCount) {
    path->incReserve(extraPtCount);
}

SkPath & SkPath_moveTo(SkPath *path, SkScalar x, SkScalar y) {
    return path->moveTo(x, y);
}

SkPath & SkPath_moveTo_2(SkPath *path, const SkPoint &p) {
    return path->moveTo(p);
}

SkPath & SkPath_rMoveTo(SkPath *path, SkScalar dx, SkScalar dy) {
    return path->rMoveTo(dx, dy);
}

SkPath & SkPath_lineTo(SkPath *path, SkScalar x, SkScalar y) {
    return path->lineTo(x, y);
}

SkPath & SkPath_lineTo_2(SkPath *path, const SkPoint &p) {
    return path->lineTo(p);
}

SkPath & SkPath_rLineTo(SkPath *path, SkScalar dx, SkScalar dy) {
    return path->rLineTo(dx, dy);
}

SkPath & SkPath_quadTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return path->quadTo(x1, y1, x2, y2);
}

SkPath & SkPath_quadTo_2(SkPath *path, const SkPoint &p1, const SkPoint &p2) {
    return path->quadTo(p1, p2);
}

SkPath & SkPath_rQuadTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2) {
    return path->rQuadTo(dx1, dy1, dx2, dy2);
}

SkPath & SkPath_conicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return path->conicTo(x1, y1, x2, y2, w);
}

SkPath & SkPath_conicTo_2(SkPath *path, const SkPoint &p1, const SkPoint &p2, SkScalar w) {
    return path->conicTo(p1, p2, w);
}

SkPath & SkPath_rConicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w) {
    return path->rConicTo(dx1, dy2, dx2, dy2, w);
}

SkPath & SkPath_cubicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return path->cubicTo(x1, y1, x2, y2, x3, y3);
}

SkPath & SkPath_cubicTo_2(SkPath *path, const SkPoint &p1, const SkPoint &p2, const SkPoint &p3) {
    return path->cubicTo(p1, p2, p3);
}

SkPath & SkPath_rCubicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3) {
    return path->rCubicTo(dx1, dy1, dx2, dy2, dx3, dy3);
}

SkPath & SkPath_arcTo(SkPath *path, const SkRect &oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo) {
    return path->arcTo(oval, startAngle, sweepAngle, forceMoveTo);
}

SkPath & SkPath_arcTo_2(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius) {
    return path->arcTo(x1, y1, x2, y2, radius);
}

SkPath & SkPath_arcTo_3(SkPath *path, const SkPoint p1, const SkPoint p2, SkScalar radius) {
    return path->arcTo(p1, p2, radius);
}

SkPath & SkPath_arcTo_4(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y) {
    return path->arcTo(rx, ry, xAxisRotate, largeArc, sweep, x, y);
}

SkPath & SkPath_arcTo_5(SkPath *path, const SkPoint r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, const SkPoint xy) {
    return path->arcTo(r, xAxisRotate, largeArc, sweep, xy);
}

SkPath & SkPath_rArcTo(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy) {
    return path->arcTo(rx, ry, xAxisRotate, largeArc, sweep, dx, dy);
}

SkPath & SkPath_close(SkPath *path) {
    return path->close();
}

bool SkPath_isRect(SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction) {
    return path->isRect(rect, isClosed, direction);
}

SkPath & SkPath_addRect(SkPath *path, const SkRect &rect, SkPathDirection dir, unsigned start) {
    return path->addRect(rect, dir, start);
}

SkPath & SkPath_addRect_2(SkPath *path, const SkRect &rect, SkPathDirection dir) {
    return path->addRect(rect, dir);
}

SkPath & SkPath_addRect_3(SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir) {
    return path->addRect(left, top, right, bottom, dir);
}

SkPath & SkPath_addOval(SkPath *path, const SkRect &oval, SkPathDirection dir) {
    return path->addOval(oval, dir);
}

SkPath & SkPath_addOval_2(SkPath *path, const SkRect &oval, SkPathDirection dir, unsigned start) {
    return path->addOval(oval, dir, start);
}

SkPath & SkPath_addCircle(SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir) {
    return path->addCircle(x, y, radius, dir);
}

SkPath & SkPath_addArc(SkPath *path, const SkRect &oval, SkScalar startAngle, SkScalar sweepAngle) {
    return path->addArc(oval, startAngle, sweepAngle);
}

SkPath & SkPath_addRoundRect(SkPath *path, const SkRect &rect, SkScalar rx, SkScalar ry, SkPathDirection di) {
    return path->addRoundRect(rect, rx, ry, di);
}

SkPath & SkPath_addRoundRect_2(SkPath *path, const SkRect &rect, const SkScalar radii[], SkPathDirection dir) {
    return path->addRoundRect(rect, radii, dir);
}

SkPath & SkPath_addRRect(SkPath *path, const SkRRect &rrect, SkPathDirection dir) {
    return path->addRRect(rrect, dir);
}

SkPath & SkPath_addRRect_2(SkPath *path, const SkRRect &rrect, SkPathDirection dir, unsigned start) {
    return path->addRRect(rrect, dir, start);
}

SkPath & SkPath_addPoly(SkPath *path, const SkPoint pts[], int count, bool close) {
    return path->addPoly(pts, count, close);
}

SkPath & SkPath_addPoly_2(SkPath *path, const std::initializer_list<SkPoint> &list, bool close) {
    return path->addPoly(list, close);
}

SkPath & SkPath_addPath(SkPath *path, const SkPath &src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode) {
    return path->addPath(src, dx, dy, mode);
}

SkPath & SkPath_addPath_2(SkPath *path, const SkPath &src, SkPath::AddPathMode modeSkPath) {
    return path->addPath(src, modeSkPath);
}

SkPath & SkPath_addPath_3(SkPath *path, const SkPath &src, const SkMatrix &matrix, SkPath::AddPathMode mode) {
    return path->addPath(src, matrix, mode);
}

SkPath & SkPath_reverseAddPath(SkPath *path, const SkPath &src) {
    return path->reverseAddPath(src);
}

void SkPath_offset(SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst) {
    path->offset(dx, dy, dst);
}

void SkPath_offset_2(SkPath *path, SkScalar dx, SkScalar dy) {
    path->offset(dx, dy);
}

void SkPath_transform(SkPath *path, const SkMatrix &matrix, SkPath *dst, SkApplyPerspectiveClip pc) {
    path->transform(matrix, dst, pc);
}

void SkPath_transform_2(SkPath *path, const SkMatrix &matrix, SkApplyPerspectiveClip pc) {
    path->transform(matrix, pc);
}

SkPath SkPath_makeTransform(SkPath *path, const SkMatrix &m, SkApplyPerspectiveClip pc) {
    return path->makeTransform(m, pc);
}

SkPath SkPath_makeScale(SkPath *path, SkScalar sx, SkScalar sy) {
    return path->makeScale(sx, sy);
}

bool SkPath_getLastPt(SkPath *path, SkPoint *lastPt) {
    return path->getLastPt(lastPt);
}

void SkPath_setLastPt(SkPath *path, SkScalar x, SkScalar y) {
    path->setLastPt(x, y);
}

void SkPath_setLastPt_2(SkPath *path, const SkPoint &p) {
    path->setLastPt(p);
}

uint32_t SkPath_getSegmentMasks(SkPath *path) {
    return path->getSegmentMasks();
}

bool SkPath_contains(SkPath *path, SkScalar x, SkScalar y) {
    return path->contains(x, y);
}

void SkPath_dump(SkPath *path, SkWStream *stream, bool dumpAsHex) {
    path->dump(stream, dumpAsHex);
}

void SkPath_dump_2(SkPath *path) {
    path->dump();
}

void SkPath_dumpHex(SkPath *path) {
    path->dumpHex();
}

void SkPath_dumpArrays(SkPath *path, SkWStream *stream, bool dumpAsHex) {
    path->dumpArrays(stream, dumpAsHex);
}

void SkPath_dumpArrays_2(SkPath *path) {
    path->dumpArrays();
}

size_t SkPath_writeToMemory(SkPath *path, void *buffer) {
    return path->writeToMemory(buffer);
}

sk_sp<SkData> SkPath_serialize(SkPath *path) {
    return path->serialize();
}

size_t SkPath_readFromMemory(SkPath *path, const void *buffer, size_t length) {
    return path->readFromMemory(buffer, length);
}

uint32_t SkPath_getGenerationID(SkPath *path) {
    return path->getGenerationID();
}

bool SkPath_isValid(SkPath *path) {
    return path->isValid();
}


// static

SkPath SkPath_Make(const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile) {
    return SkPath::Make(point, pointCount, i, verbCount, v, conicWeightCount, type, isVolatile);
}

SkPath SkPath_Rect(const SkRect &rect, SkPathDirection dir, unsigned startIndex) {
    return SkPath::Rect(rect, dir, startIndex);
}

SkPath SkPath_Oval(const SkRect &rect, SkPathDirection dir) {
    return SkPath::Oval(rect, dir);
}

SkPath SkPath_Oval_2(const SkRect &rect, SkPathDirection dir, unsigned startIndex) {
    return SkPath::Oval(rect, dir, startIndex);
}

SkPath SkPath_Circle(SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) {
    return SkPath::Circle(center_x, center_y, radius, dir);
}

SkPath SkPath_RRect(const SkRRect &rrect, SkPathDirection dir) {
    return SkPath::RRect(rrect, dir);
}

SkPath SkPath_RRect_2(const SkRRect &rrect, SkPathDirection dir, unsigned startIndex) {
    return SkPath::RRect(rrect, dir, startIndex);
}

SkPath SkPath_RRect_3(const SkRect &bounds, SkScalar rx, SkScalar ry, SkPathDirection dir) {
    return SkPath::RRect(bounds, rx, ry, dir);
}

SkPath SkPath_Polygon(const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile) {
    return SkPath::Polygon(pts, count, isClosed, type, isVolatile);
}

SkPath SkPath_Polygon_2(const std::initializer_list<SkPoint> &list, bool isClosed, SkPathFillType fillType, bool isVolatile) {
    return SkPath::Polygon(list, isClosed, fillType, isVolatile);
}

SkPath SkPath_Line(const SkPoint a, const SkPoint b) {
    return SkPath::Line(a, b);
}

bool SkPath_IsLineDegenerate(const SkPoint &p1, const SkPoint &p2, bool exact) {
    return SkPath::IsLineDegenerate(p1, p2, exact);
}

bool SkPath_IsQuadDegenerate(const SkPoint &p1, const SkPoint &p2, const SkPoint &p3, bool exact) {
    return SkPath::IsQuadDegenerate(p1, p2, p3, exact);
}

bool SkPath_IsCubicDegenerate(const SkPoint &p1, const SkPoint &p2, const SkPoint &p3, const SkPoint &p4, bool exact) {
    return SkPath::IsCubicDegenerate(p1, p2, p3, p4, exact);
}

int SkPath_ConvertConicToQuads(const SkPoint &p0, const SkPoint &p1, const SkPoint &p2, SkScalar w, SkPoint pts[], int pow2) {
    return SkPath::ConvertConicToQuads(p0, p1, p2, w, pts, pow2);
}

//
// SkPath1DPathEffect
//

// static

sk_sp<SkPathEffect> SkPath1DPathEffect_Make(const SkPath &path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style) {
    return SkPath1DPathEffect::Make(path, advance, phase, style);
}

void SkPath1DPathEffect_RegisterFlattenables() {
    SkPath1DPathEffect::RegisterFlattenables();
}

//
// SkPath2DPathEffect
//

// static

sk_sp<SkPathEffect> SkPath2DPathEffect_Make(const SkMatrix &matrix, const SkPath &path) {
    return SkPath2DPathEffect::Make(matrix, path);
}

void SkPath2DPathEffect_RegisterFlattenables() {
    SkPath2DPathEffect::RegisterFlattenables();
}

//
// SkPathBuilder
//

// SkPathBuilder & operator=(const SkPath &)
// SkPathBuilder & operator=(const SkPathBuilder &)

SkPathBuilder *SkPathBuilder_new() {
    return new SkPathBuilder();
}

SkPathBuilder *SkPathBuilder_new_2(SkPathFillType type) {
    return new SkPathBuilder(type);
}

SkPathBuilder *SkPathBuilder_new_3(const SkPath &path) {
    return new SkPathBuilder(path);
}

SkPathBuilder *SkPathBuilder_new_4(const SkPathBuilder &builder) {
    return new SkPathBuilder(builder);
}

void SkPathBuilder_delete(SkPathBuilder *path_builder) {
    delete path_builder;
}

SkPathFillType SkPathBuilder_fillType(SkPathBuilder *path_builder) {
    return path_builder->fillType();
}

SkRect SkPathBuilder_computeBounds(SkPathBuilder *path_builder) {
    return path_builder->computeBounds();
}

SkPath SkPathBuilder_snapshot(SkPathBuilder *path_builder) {
    return path_builder->snapshot();
}

SkPath SkPathBuilder_detach(SkPathBuilder *path_builder) {
    return path_builder->detach();
}

SkPathBuilder & SkPathBuilder_setFillType(SkPathBuilder *path_builder, SkPathFillType ft) {
    return path_builder->setFillType(ft);
}

SkPathBuilder & SkPathBuilder_setIsVolatile(SkPathBuilder *path_builder, bool isVolatile) {
    return path_builder->setIsVolatile(isVolatile);
}

SkPathBuilder & SkPathBuilder_reset(SkPathBuilder *path_builder) {
    return path_builder->reset();
}

SkPathBuilder & SkPathBuilder_moveTo(SkPathBuilder *path_builder, SkPoint pt) {
    return path_builder->moveTo(pt);
}

SkPathBuilder & SkPathBuilder_moveTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return path_builder->moveTo(x, y);
}

SkPathBuilder & SkPathBuilder_lineTo(SkPathBuilder *path_builder, SkPoint pt) {
    return path_builder->lineTo(pt);
}

SkPathBuilder & SkPathBuilder_lineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return path_builder->lineTo(x, y);
}

SkPathBuilder & SkPathBuilder_quadTo(SkPathBuilder *path_builder, SkPoint pt1, SkPoint pt2) {
    return path_builder->quadTo(pt1, pt2);
}

SkPathBuilder & SkPathBuilder_quadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return path_builder->quadTo(x1, y1, x2, y2);
}

SkPathBuilder & SkPathBuilder_quadTo_3(SkPathBuilder *path_builder, const SkPoint pts[2]) {
    return path_builder->quadTo(pts);
}

SkPathBuilder & SkPathBuilder_conicTo(SkPathBuilder *path_builder, SkPoint pt1, SkPoint pt2, SkScalar w) {
    return path_builder->conicTo(pt1, pt2, w);
}

SkPathBuilder & SkPathBuilder_conicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return path_builder->conicTo(x1, y1, x2, y2, w);
}

SkPathBuilder & SkPathBuilder_conicTo_3(SkPathBuilder *path_builder, const SkPoint pts[2], SkScalar w) {
    return path_builder->conicTo(pts, w);
}

SkPathBuilder & SkPathBuilder_cubicTo(SkPathBuilder *path_builder, SkPoint pt1, SkPoint pt2, SkPoint pt3) {
    return path_builder->cubicTo(pt1, pt2, pt3);
}

SkPathBuilder & SkPathBuilder_cubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return path_builder->cubicTo(x1, y1, x2, y2, x3, y3);
}

SkPathBuilder & SkPathBuilder_cubicTo_3(SkPathBuilder *path_builder, const SkPoint pts[3]) {
    return path_builder->cubicTo(pts);
}

SkPathBuilder & SkPathBuilder_close(SkPathBuilder *path_builder) {
    return path_builder->close();
}

SkPathBuilder & SkPathBuilder_polylineTo(SkPathBuilder *path_builder, const SkPoint pts[], int count) {
    return path_builder->polylineTo(pts, count);
}

SkPathBuilder & SkPathBuilder_polylineTo_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> &list) {
    return path_builder->polylineTo(list);
}

SkPathBuilder & SkPathBuilder_rLineTo(SkPathBuilder *path_builder, SkPoint pt) {
    return path_builder->rLineTo(pt);
}

SkPathBuilder & SkPathBuilder_rLineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return path_builder->rLineTo(x, y);
}

SkPathBuilder & SkPathBuilder_rQuadTo(SkPathBuilder *path_builder, SkPoint pt1, SkPoint pt2) {
    return path_builder->rQuadTo(pt1, pt2);
}

SkPathBuilder & SkPathBuilder_rQuadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return path_builder->rQuadTo(x1, y1, x2, y2);
}

SkPathBuilder & SkPathBuilder_rConicTo(SkPathBuilder *path_builder, SkPoint p1, SkPoint p2, SkScalar w) {
    return path_builder->rConicTo(p1, p2, w);
}

SkPathBuilder & SkPathBuilder_rConicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return path_builder->rConicTo(x1, y1, x2, y2, w);
}

SkPathBuilder & SkPathBuilder_rCubicTo(SkPathBuilder *path_builder, SkPoint pt1, SkPoint pt2, SkPoint pt3) {
    return path_builder->rCubicTo(pt1, pt2, pt3);
}

SkPathBuilder & SkPathBuilder_rCubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return path_builder->rCubicTo(x1, y1, x2, y2, x3, y3);
}

SkPathBuilder & SkPathBuilder_arcTo(SkPathBuilder *path_builder, const SkRect &oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo) {
    return path_builder->arcTo(oval, startAngleDeg, sweepAngleDeg, forceMoveTo);
}

SkPathBuilder & SkPathBuilder_arcTo_2(SkPathBuilder *path_builder, SkPoint p1, SkPoint p2, SkScalar radius) {
    return path_builder->arcTo(p1, p2, radius);
}

SkPathBuilder & SkPathBuilder_arcTo_3(SkPathBuilder *path_builder, SkPoint r, SkScalar xAxisRotate, SkPathBuilder::ArcSize largeArc, SkPathDirection sweep, SkPoint xy) {
    return path_builder->arcTo(r, xAxisRotate, largeArc, sweep, xy);
}

SkPathBuilder & SkPathBuilder_addArc(SkPathBuilder *path_builder, const SkRect &oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg) {
    return path_builder->addArc(oval, startAngleDeg, sweepAngleDeg);
}

SkPathBuilder & SkPathBuilder_addRect(SkPathBuilder *path_builder, const SkRect &rect, SkPathDirection dir, unsigned startIndex) {
    return path_builder->addRect(rect, dir, startIndex);
}

SkPathBuilder & SkPathBuilder_addRect_2(SkPathBuilder *path_builder, const SkRect &rect, SkPathDirection dir) {
    return path_builder->addRect(rect, dir);
}

SkPathBuilder & SkPathBuilder_addOval(SkPathBuilder *path_builder, const SkRect &rect, SkPathDirection dir, unsigned startIndex) {
    return path_builder->addOval(rect, dir, startIndex);
}

SkPathBuilder & SkPathBuilder_addOval_2(SkPathBuilder *path_builder, const SkRect &rect, SkPathDirection dir) {
    return path_builder->addOval(rect, dir);
}

SkPathBuilder & SkPathBuilder_addRRect(SkPathBuilder *path_builder, const SkRRect &rect, SkPathDirection dir, unsigned startIndex) {
    return path_builder->addRRect(rect, dir, startIndex);
}

SkPathBuilder & SkPathBuilder_addRRect_2(SkPathBuilder *path_builder, const SkRRect &rrect, SkPathDirection dir) {
    return path_builder->addRRect(rrect, dir);
}

SkPathBuilder & SkPathBuilder_addCircle(SkPathBuilder *path_builder, SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) {
    return path_builder->addCircle(center_x, center_y, radius, dir);
}

SkPathBuilder & SkPathBuilder_addPolygon(SkPathBuilder *path_builder, const SkPoint pts[], int count, bool isClosed) {
    return path_builder->addPolygon(pts, count, isClosed);
}

SkPathBuilder & SkPathBuilder_addPolygon_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> &list, bool isClosed) {
    return path_builder->addPolygon(list, isClosed);
}

SkPathBuilder & SkPathBuilder_addPath(SkPathBuilder *path_builder, const SkPath &path) {
    return path_builder->addPath(path);
}

void SkPathBuilder_incReserve(SkPathBuilder *path_builder, int extraPtCount, int extraVerbCount) {
    path_builder->incReserve(extraPtCount);
}

void SkPathBuilder_incReserve_2(SkPathBuilder *path_builder, int extraPtCount) {
    path_builder->incReserve(extraPtCount);
}

SkPathBuilder & SkPathBuilder_offset(SkPathBuilder *path_builder, SkScalar dx, SkScalar dy) {
    return path_builder->offset(dx, dy);
}

SkPathBuilder & SkPathBuilder_toggleInverseFillType(SkPathBuilder *path_builder) {
    return path_builder->toggleInverseFillType();
}

//
// SkPathEffect
//

SkPathEffect::DashType SkPathEffect_asADash(SkPathEffect *path_effect, SkPathEffect::DashInfo *info) {
    return path_effect->asADash(info);
}

bool SkPathEffect_filterPath(SkPathEffect *path_effect, SkPath *dst, const SkPath &src, SkStrokeRec *rec, const SkRect *cullR) {
    return path_effect->filterPath(dst, src, rec, cullR);
}

bool SkPathEffect_filterPath_2(SkPathEffect *path_effect, SkPath *dst, const SkPath &src, SkStrokeRec *rec, const SkRect *cullR, const SkMatrix &ctm) {
    return path_effect->filterPath(dst, src, rec, cullR, ctm);
}

bool SkPathEffect_needsCTM(SkPathEffect *path_effect) {
    return path_effect->needsCTM();
}

SkPathEffect::Factory SkPathEffect_getFactory(SkPathEffect *path_effect) {
    return path_effect->getFactory();
}

const char * SkPathEffect_getTypeName(SkPathEffect *path_effect) {
    return path_effect->getTypeName();
}

void SkPathEffect_flatten(SkPathEffect *path_effect, SkWriteBuffer &buffer) {
    path_effect->flatten(buffer);
}

SkPathEffect::Type SkPathEffect_getFlattenableType(SkPathEffect *path_effect) {
    return path_effect->getFlattenableType();
}

sk_sp<SkData> SkPathEffect_serialize(SkPathEffect *path_effect, const SkSerialProcs *procs) {
    return path_effect->serialize(procs);
}

size_t SkPathEffect_serialize_2(SkPathEffect *path_effect, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return path_effect->serialize(memory, memory_size, procs);
}

bool SkPathEffect_unique(SkPathEffect *path_effect) {
    return path_effect->unique();
}

void SkPathEffect_ref(SkPathEffect *path_effect) {
    path_effect->ref();
}

void SkPathEffect_unref(SkPathEffect *path_effect) {
    path_effect->unref();
}

// static

sk_sp<SkPathEffect> SkPathEffect_MakeSum(SkPathEffect *path_effect, sk_sp<SkPathEffect> first, sk_sp<SkPathEffect> second) {
    return SkPathEffect::MakeSum(first, second);
}

sk_sp<SkPathEffect> SkPathEffect_MakeCompose(SkPathEffect *path_effect, sk_sp<SkPathEffect> outer, sk_sp<SkPathEffect> inner) {
    return SkPathEffect::MakeCompose(outer, inner);
}

SkFlattenable::Type SkPathEffect_GetFlattenableType(SkPathEffect *path_effect) {
    return SkPathEffect::GetFlattenableType();
}

sk_sp<SkPathEffect> SkPathEffect_Deserialize(SkPathEffect *path_effect, const void *data, size_t size, const SkDeserialProcs *procs) {
    return SkPathEffect::Deserialize(data, size, procs);
}

SkPathEffect::Factory SkPathEffect_NameToFactory(SkPathEffect *path_effect, const char name[]) {
    return SkPathEffect::NameToFactory(name);
}

const char * SkPathEffect_FactoryToName(SkPathEffect *path_effect, SkPathEffect::Factory factory) {
    return SkPathEffect::FactoryToName(factory);
}

void SkPathEffect_Register(SkPathEffect *path_effect, const char name[], SkPathEffect::Factory factory) {
    SkPathEffect::Register(name, factory);
}

//
// SkPathMeasure
//

// SkPathMeasure & operator=(SkPathMeasure &&)

SkPathMeasure *SkPathMeasure_new() {
    return new SkPathMeasure();
}

SkPathMeasure *SkPathMeasure_new_2(const SkPath &path, bool forceClosed, SkScalar resScale) {
    return new SkPathMeasure(path, forceClosed, resScale);
}

//SkPathMeasure *SkPathMeasure_new_3(SkPathMeasure &&measure) {
//    return new SkPathMeasure(measure);
//}

void SkPathMeasure_delete(SkPathMeasure *path_measure) {
    delete path_measure;
}

void SkPathMeasure_setPath(SkPathMeasure *path_measure, const SkPath *path, bool forceClosed) {
    path_measure->setPath(path, forceClosed);
}

SkScalar SkPathMeasure_getLength(SkPathMeasure *path_measure) {
    return path_measure->getLength();
}

bool SkPathMeasure_getPosTan(SkPathMeasure *path_measure, SkScalar distance, SkPoint *position, SkVector *tangent) {
    return path_measure->getPosTan(distance, position, tangent);
}

bool SkPathMeasure_getMatrix(SkPathMeasure *path_measure, SkScalar distance, SkMatrix *matrix, SkPathMeasure::MatrixFlags flags) {
    return path_measure->getMatrix(distance, matrix, flags);
}

bool SkPathMeasure_getSegment(SkPathMeasure *path_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) {
    return path_measure->getSegment(startD, stopD, dst, startWithMoveTo);
}

bool SkPathMeasure_isClosed(SkPathMeasure *path_measure) {
    return path_measure->isClosed();
}

bool SkPathMeasure_nextContour(SkPathMeasure *path_measure) {
    return path_measure->nextContour();
}

//
// SkPicture
//

void SkPicture_delete(SkPicture *picture) {
    delete picture;
}

void SkPicture_playback(SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback) {
    picture->playback(canvas, callback);
}

SkRect SkPicture_cullRect(SkPicture *picture) {
    return picture->cullRect();
}

uint32_t SkPicture_uniqueID(SkPicture *picture) {
    return picture->uniqueID();
}

sk_sp<SkData> SkPicture_serialize(SkPicture *picture, const SkSerialProcs *procs) {
    return picture->serialize(procs);
}

void SkPicture_serialize_2(SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs) {
    picture->serialize(stream, procs);
}

int SkPicture_approximateOpCount(SkPicture *picture) { //, bool nested
    return picture->approximateBytesUsed();
}

size_t SkPicture_approximateBytesUsed(SkPicture *picture) { //, SkPicture *picture_2
    return picture->approximateBytesUsed();
}

sk_sp<SkShader> SkPicture_makeShader(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect) {
    return picture->makeShader(tmx, tmy, mode, localMatrix, tileRect);
}

sk_sp<SkShader> SkPicture_makeShader_2(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode) {
    return picture->makeShader(tmx, tmy, mode);
}

bool SkPicture_unique(SkPicture *picture) {
    return picture->unique();
}

void SkPicture_ref(SkPicture *picture) {
    picture->ref();
}

void SkPicture_unref(SkPicture *picture) {
    picture->unref();
}

// static

sk_sp<SkPicture> SkPicture_MakeFromStream(SkStream *stream, const SkDeserialProcs *procs) {
    return SkPicture::MakeFromStream(stream, procs);
}

sk_sp<SkPicture> SkPicture_MakeFromData(const SkData *data, const SkDeserialProcs *procs) {
    return SkPicture::MakeFromData(data, procs);
}

sk_sp<SkPicture> SkPicture_MakeFromData_2(const void *data, size_t size, const SkDeserialProcs *procs) {
    return SkPicture::MakeFromData(data, size, procs);
}

sk_sp<SkPicture> SkPicture_MakePlaceholder(SkRect cull) {
    return SkPicture::MakePlaceholder(cull);
}

//
// SkPictureRecorder
//

SkPictureRecorder *SkPictureRecorder_new() {
    return new SkPictureRecorder();
}

void SkPictureRecorder_delete(SkPictureRecorder *picture_recorder) {
    delete picture_recorder;
}

SkCanvas * beginRecording(SkPictureRecorder *picture_recorder, const SkRect &bounds, sk_sp<SkBBoxHierarchy> bbh) {
    return picture_recorder->beginRecording(bounds, bbh);
}

SkCanvas * beginRecording_2(SkPictureRecorder *picture_recorder, const SkRect &bounds, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(bounds, bbhFactory);
}

SkCanvas * beginRecording_3(SkPictureRecorder *picture_recorder, SkScalar width, SkScalar height, SkBBHFactory *bbhFactory) {
    return picture_recorder->beginRecording(width, height, bbhFactory);
}

SkCanvas * getRecordingCanvas(SkPictureRecorder *picture_recorder) {
    return picture_recorder->getRecordingCanvas();
}

sk_sp<SkPicture> finishRecordingAsPicture(SkPictureRecorder *picture_recorder) {
    return picture_recorder->finishRecordingAsPicture();
}

sk_sp<SkPicture> finishRecordingAsPictureWithCull(SkPictureRecorder *picture_recorder, const SkRect &cullRect) {
    return picture_recorder->finishRecordingAsPictureWithCull(cullRect);
}

sk_sp<SkDrawable> finishRecordingAsDrawable(SkPictureRecorder *picture_recorder) {
    return picture_recorder->finishRecordingAsDrawable();
}

//
// SkPixelRef
//

SkPixelRef *SkPixelRef_new(int width, int height, void *addr, size_t rowBytes) {
    return new SkPixelRef(width, height, addr, rowBytes);
}

void SkPixelRef_delete(SkPixelRef *pixel_ref) {
    delete pixel_ref;
}

SkISize SkPixelRef_dimensions(SkPixelRef *pixel_ref) {
    return pixel_ref->dimensions();
}

int SkPixelRef_width(SkPixelRef *pixel_ref) {
    return pixel_ref->width();
}

int SkPixelRef_height(SkPixelRef *pixel_ref) {
    return pixel_ref->height();
}

void * SkPixelRef_pixels(SkPixelRef *pixel_ref) {
    pixel_ref->pixels();
}

size_t SkPixelRef_rowBytes(SkPixelRef *pixel_ref) {
    return pixel_ref->rowBytes();
}

uint32_t SkPixelRef_getGenerationID(SkPixelRef *pixel_ref) {
    return pixel_ref->getGenerationID();
}

void SkPixelRef_notifyPixelsChanged(SkPixelRef *pixel_ref) {
    pixel_ref->notifyPixelsChanged();
}

bool SkPixelRef_isImmutable(SkPixelRef *pixel_ref) {
    return pixel_ref->isImmutable();
}

void SkPixelRef_setImmutable(SkPixelRef *pixel_ref) {
    pixel_ref->setImmutable();
}

void SkPixelRef_addGenIDChangeListener(SkPixelRef *pixel_ref, sk_sp<SkIDChangeListener> listener) {
    pixel_ref->addGenIDChangeListener(listener);
}

void SkPixelRef_notifyAddedToCache(SkPixelRef *pixel_ref) {
    pixel_ref->notifyAddedToCache();
}

SkDiscardableMemory * SkPixelRef_diagnostic_only_getDiscardable(SkPixelRef *pixel_ref) {
    return pixel_ref->diagnostic_only_getDiscardable();
}

bool SkPixelRef_unique(SkPixelRef *pixel_ref) {
    return pixel_ref->unique();
}

void SkPixelRef_ref(SkPixelRef *pixel_ref) {
    pixel_ref->ref();
}

void SkPixelRef_unref(SkPixelRef *pixel_ref) {
    pixel_ref->unref();
}

//
// SkPixmap
//

SkPixmap *SkPixmap_new() {
    return new SkPixmap();
}

SkPixmap *SkPixmap_new_2(const SkImageInfo &info, const void *addr, size_t rowBytes) {
    return new SkPixmap(info, addr, rowBytes);
}

void SkPixmap_reset(SkPixmap *pixmap) {
    return pixmap->reset();
}

void SkPixmap_reset_2(SkPixmap *pixmap, const SkImageInfo &info, const void *addr, size_t rowBytes) {
    return pixmap->reset(info, addr, rowBytes);
}

bool SkPixmap_reset_3(SkPixmap *pixmap, const SkMask &mask) {
    return pixmap->reset(mask);
}

void SkPixmap_setColorSpace(SkPixmap *pixmap, sk_sp<SkColorSpace> colorSpace) {
    return pixmap->setColorSpace(colorSpace);
}

bool SkPixmap_extractSubset(SkPixmap *pixmap, SkPixmap *subset, const SkIRect &area) {
    return pixmap->extractSubset(subset, area);
}

const SkImageInfo & SkPixmap_info(SkPixmap *pixmap) {
    return pixmap->info();
}

size_t SkPixmap_rowBytes(SkPixmap *pixmap) {
    return pixmap->rowBytes();
}

const void * SkPixmap_addr(SkPixmap *pixmap) {
    return pixmap->addr();
}

int SkPixmap_width(SkPixmap *pixmap) {
    return pixmap->width();
}

int SkPixmap_height(SkPixmap *pixmap) {
    return pixmap->height();
}

SkISize SkPixmap_dimensions(SkPixmap *pixmap) {
    return pixmap->dimensions();
}

SkColorType SkPixmap_colorType(SkPixmap *pixmap) {
    return pixmap->colorType();
}

SkAlphaType SkPixmap_alphaType(SkPixmap *pixmap) {
    return pixmap->alphaType();
}

SkColorSpace * SkPixmap_colorSpace(SkPixmap *pixmap) {
    return pixmap->colorSpace();
}

sk_sp<SkColorSpace> SkPixmap_refColorSpace(SkPixmap *pixmap) {
    return pixmap->refColorSpace();
}

bool SkPixmap_isOpaque(SkPixmap *pixmap) {
    return pixmap->isOpaque();
}

SkIRect SkPixmap_bounds(SkPixmap *pixmap) {
    return pixmap->bounds();
}

int SkPixmap_rowBytesAsPixels(SkPixmap *pixmap) {
    return pixmap->rowBytesAsPixels();
}

int SkPixmap_shiftPerPixel(SkPixmap *pixmap) {
    return pixmap->shiftPerPixel();
}

size_t SkPixmap_computeByteSize(SkPixmap *pixmap) {
    return pixmap->computeByteSize();
}

bool SkPixmap_computeIsOpaque(SkPixmap *pixmap) {
    return pixmap->computeIsOpaque();
}

SkColor SkPixmap_getColor(SkPixmap *pixmap, int x, int y) {
    return pixmap->getColor(x, y);
}

SkColor4f SkPixmap_getColor4f(SkPixmap *pixmap, int x, int y) {
    return pixmap->getColor4f(x, y);
}

float SkPixmap_getAlphaf(SkPixmap *pixmap, int x, int y) {
    return pixmap->getAlphaf(x, y);
}

const void * SkPixmap_addr_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr(x, y);
}

const uint8_t * SkPixmap_addr8(SkPixmap *pixmap) {
    return pixmap->addr8();
}

const uint16_t * SkPixmap_addr16(SkPixmap *pixmap) {
    return pixmap->addr16();
}

const uint32_t * SkPixmap_addr32(SkPixmap *pixmap) {
    return pixmap->addr32();
}

const uint64_t * SkPixmap_addr64(SkPixmap *pixmap) {
    return pixmap->addr64();
}

const uint16_t * SkPixmap_addrF16(SkPixmap *pixmap) {
    return pixmap->addrF16();
}

const uint8_t * SkPixmap_addr8_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr8(x, y);
}

const uint16_t * SkPixmap_addr16_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr16(x, y);
}

const uint32_t * SkPixmap_addr32_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr32(x, y);
}

const uint64_t * SkPixmap_addr64_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr64(x, y);
}

const uint16_t * SkPixmap_addrF16_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addrF16(x, y);
}

void * SkPixmap_writable_addr(SkPixmap *pixmap) {
    return pixmap->writable_addr();
}

void * SkPixmap_writable_addr_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr(x, y);
}

uint8_t * SkPixmap_writable_addr8(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr8(x, y);
}

uint16_t * SkPixmap_writable_addr16(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr16(x, y);
}

uint32_t * SkPixmap_writable_addr32(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr32(x, y);
}

uint64_t * SkPixmap_writable_addr64(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr64(x, y);
}

uint16_t * SkPixmap_writable_addrF16(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addrF16(x, y);
}

bool SkPixmap_readPixels(SkPixmap *pixmap, const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes) {
    return pixmap->readPixels(dstInfo, dstPixels, dstRowBytes);
}

bool SkPixmap_readPixels_2(SkPixmap *pixmap, const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return pixmap->readPixels(dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkPixmap_readPixels_3(SkPixmap *pixmap, const SkPixmap &dst, int srcX, int srcY) {
    return pixmap->readPixels(dst, srcX, srcY);
}

bool SkPixmap_readPixels_4(SkPixmap *pixmap, const SkPixmap &dst) {
    return pixmap->readPixels(dst);
}

bool SkPixmap_scalePixels(SkPixmap *pixmap, const SkPixmap &dst, const SkSamplingOptions &options) {
    return pixmap->scalePixels(dst, options);
}

bool SkPixmap_erase(SkPixmap *pixmap, SkColor color, const SkIRect &subset) {
    return pixmap->erase(color, subset);
}

bool SkPixmap_erase_2(SkPixmap *pixmap, SkColor color) {
    return pixmap->erase(color);
}

bool SkPixmap_erase_3(SkPixmap *pixmap, const SkColor4f &color, const SkIRect *subset) {
    return pixmap->erase(color, subset);
}

//
// SkPoint3
//

// SkPoint3 operator-()
// void operator+=(const SkPoint3 &v)
// void operator-=(const SkPoint3 &v)

SkScalar SkPoint3_x(SkPoint3 *point3) {
    return point3->x();
}

SkScalar SkPoint3_y(SkPoint3 *point3) {
    return point3->y();
}

SkScalar SkPoint3_z(SkPoint3 *point3) {
    return point3->z();
}

void SkPoint3_set(SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z) {
    point3->set(x, y, z);
}

SkScalar SkPoint3_length(SkPoint3 *point3) {
    return point3->length();
}

bool SkPoint3_normalize(SkPoint3 *point3) {
    return point3->normalize();
}

SkPoint3 SkPoint3_makeScale(SkPoint3 *point3, SkScalar scale) {
    return point3->makeScale(scale);
}

void SkPoint3_scale(SkPoint3 *point3, SkScalar value) {
    point3->scale(value);
}

bool SkPoint3_isFinite(SkPoint3 *point3) {
    return point3->isFinite();
}

SkScalar SkPoint3_dot(SkPoint3 *point3, const SkPoint3 &vec) {
    return point3->dot(vec);
}

SkPoint3 SkPoint3_cross(SkPoint3 *point3, const SkPoint3 &vec) {
    return point3->cross(vec);
}

// static

SkPoint3 SkPoint3_Make(SkScalar x, SkScalar y, SkScalar z) {
    return SkPoint3::Make(x, y, z);
}

SkScalar SkPoint3_Length(SkScalar x, SkScalar y, SkScalar z) {
    return SkPoint3::Length(x, y, z);
}

SkScalar SkPoint3_DotProduct(const SkPoint3 &a, const SkPoint3 &b) {
    return SkPoint3::DotProduct(a, b);
}

SkPoint3 SkPoint3_CrossProduct(const SkPoint3 &a, const SkPoint3 &b) {
    return SkPoint3::CrossProduct(a, b);
}

//
// SkRasterHandleAllocator
//

void SkRasterHandleAllocator_delete(SkRasterHandleAllocator *raster_handle_allocator) {
    delete raster_handle_allocator;
}

bool SkRasterHandleAllocator_allocHandle(SkRasterHandleAllocator *raster_handle_allocator, const SkImageInfo &info, SkRasterHandleAllocator::Rec *rec) {
    return raster_handle_allocator->allocHandle(info, rec);
}

void SkRasterHandleAllocator_updateHandle(SkRasterHandleAllocator *raster_handle_allocator, SkRasterHandleAllocator::Handle handle, const SkMatrix &matrix, const SkIRect &irect) {
    raster_handle_allocator->updateHandle(handle, matrix, irect);
}

// static

// @TODO
//std::unique_ptr<SkCanvas> SkRasterHandleAllocator_MakeCanvas(std::unique_ptr<SkRasterHandleAllocator> allocator, const SkImageInfo &info, const SkRasterHandleAllocator::Rec *rec, const SkSurfaceProps *props) {
//    return SkRasterHandleAllocator::MakeCanvas(allocator, info, rec, props);
//}

//
// SkRect Struct
//

bool SkRect_isEmpty(SkRect *rect) {
    return rect->isEmpty();
}

bool SkRect_isSorted(SkRect *rect) {
    return rect->isSorted();
}

bool SkRect_isFinite(SkRect *rect) {
    return rect->isFinite();
}

float SkRect_x(SkRect *rect) {
    return rect->x();
}

float SkRect_y(SkRect *rect) {
    return rect->y();
}

float SkRect_left(SkRect *rect) {
    return rect->left();
}

float SkRect_top(SkRect *rect) {
    return rect->top();
}

float SkRect_right(SkRect *rect) {
    return rect->right();
}

float SkRect_bottom(SkRect *rect) {
    return rect->bottom();
}

float SkRect_width(SkRect *rect) {
    return rect->width();
}

float SkRect_height(SkRect *rect) {
    return rect->height();
}

float SkRect_centerX(SkRect *rect) {
    return rect->centerX();
}

float SkRect_centerY(SkRect *rect) {
    return rect->centerY();
}

SkPoint SkRect_center(SkRect *rect) {
    return rect->center();
}

void SkRect_toQuad(SkRect *rect, SkPoint quad[4]) {
    rect->toQuad(quad);
}

void SkRect_setEmpty(SkRect *rect) {
    rect->setEmpty();
}

void SkRect_set(SkRect *rect, const SkIRect &src) {
    rect->set(src);
}

void SkRect_setLTRB(SkRect *rect, float left, float top, float right, float bottom) {
    rect->setLTRB(left, top, right, bottom);
}

void SkRect_setBounds(SkRect *rect, const SkPoint pts[], int count) {
    rect->setBounds(pts, count);
}

bool SkRect_setBoundsCheck(SkRect *rect, const SkPoint pts[], int count) {
    return rect->setBoundsCheck(pts, count);
}

void SkRect_setBoundsNoCheck(SkRect *rect, const SkPoint pts[], int count) {
    rect->setBoundsNoCheck(pts, count);
}

void SkRect_set_2(SkRect *rect, const SkPoint &p0, const SkPoint &p1) {
    rect->set(p0, p1);
}

void SkRect_setXYWH(SkRect *rect, float x, float y, float width, float height) {
    rect->setXYWH(x, y, width, height);
}

void SkRect_setWH(SkRect *rect, float width, float height) {
    rect->setWH(width, height);
}

void SkRect_setIWH(SkRect *rect, int32_t width, int32_t height) {
    rect->setIWH(width, height);
}

SkRect SkRect_makeOffset(SkRect *rect, float dx, float dy) {
    return rect->makeOutset(dx, dy);
}

SkRect SkRect_makeOffset_2(SkRect *rect, SkVector v) {
    return rect->makeOffset(v);
}

SkRect SkRect_makeInset(SkRect *rect, float dx, float dy) {
    return rect->makeInset(dx, dy);
}

SkRect SkRect_makeOutset(SkRect *rect, float dx, float dy) {
    return rect->makeOutset(dx, dy);
}

void SkRect_offset(SkRect *rect, float dx, float dy) {
    rect->offset(dx, dy);
}

void SkRect_offset_2(SkRect *rect, const SkPoint &delta) {
    rect->offset(delta);
}

void SkRect_offsetTo(SkRect *rect, float newX, float newY) {
    rect->offsetTo(newX, newY);
}

void SkRect_inset(SkRect *rect, float dx, float dy) {
    rect->inset(dx, dy);
}

void SkRect_outset(SkRect *rect, float dx, float dy) {
    rect->outset(dx, dy);
}

bool SkRect_intersect(SkRect *rect, const SkRect &r) {
    return rect->intersect(r);
}

bool SkRect_intersect_2(SkRect *rect, const SkRect &a, const SkRect &b) {
    return rect->intersect(a, b);
}

bool SkRect_intersects(SkRect *rect, const SkRect &r) {
    return rect->intersects(r);
}

void SkRect_join(SkRect *rect, const SkRect &r) {
    rect->join(r);
}

void SkRect_joinNonEmptyArg(SkRect *rect, const SkRect &r) {
    rect->joinNonEmptyArg(r);
}

void SkRect_joinPossiblyEmptyRect(SkRect *rect, const SkRect &r) {
    rect->joinPossiblyEmptyRect(r);
}

bool SkRect_contains(SkRect *rect, float x, float y) {
    return rect->contains(x, y);
}

bool SkRect_contains_2(SkRect *rect, const SkRect &r) {
    return rect->contains(r);
}

bool SkRect_contains_3(SkRect *rect, const SkIRect &r) {
    return rect->contains(r);
}

void SkRect_round(SkRect *rect, SkIRect *dst) {
    rect->round(dst);
}

void SkRect_roundOut(SkRect *rect, SkIRect *dst) {
    rect->roundOut(dst);
}

void SkRect_roundOut_2(SkRect *rect, SkRect *dst) {
    rect->roundOut(dst);
}

void SkRect_roundIn(SkRect *rect, SkIRect *dst) {
    rect->roundIn(dst);
}

SkIRect SkRect_round_2(SkRect *rect) {
    return rect->round();
}

SkIRect SkRect_roundOut_3(SkRect *rect) {
    return rect->roundOut();
}

SkIRect SkRect_roundIn_2(SkRect *rect) {
    return rect->roundIn();
}

void SkRect_sort(SkRect *rect) {
    rect->sort();
}

SkRect SkRect_makeSorted(SkRect *rect) {
    return rect->makeSorted();
}

const float * SkRect_asScalars(SkRect *rect) {
    return rect->asScalars();
}

void SkRect_dump(SkRect *rect, bool asHex) {
    rect->dump(asHex);
}

void SkRect_dump_2(SkRect *rect) {
    rect->dump();
}

void SkRect_dumpHex(SkRect *rect) {
    rect->dumpHex();
}

// static

SkRect SkRect_MakeEmpty() {
    return SkRect::MakeEmpty();
}

SkRect SkRect_MakeWH(float w, float h) {
    return SkRect::MakeWH(w, h);
}

SkRect SkRect_MakeIWH(int w, int h) {
    return SkRect::MakeIWH(w, h);
}

SkRect SkRect_MakeSize(const SkSize &size) {
    return SkRect::MakeSize(size);
}

SkRect SkRect_MakeLTRB(float l, float t, float r, float b) {
    return SkRect::MakeLTRB(l, t, r, b);
}

SkRect SkRect_MakeXYWH(float x, float y, float w, float h) {
    return SkRect::MakeXYWH(x, y, w, h);
}

SkRect SkRect_Make(const SkISize &size) {
    return SkRect::Make(size);
}

SkRect SkRect_Make_2(const SkIRect &irect) {
    return SkRect::Make(irect);
}

bool SkRect_Intersects(const SkRect &a, const SkRect &b) {
    return SkRect::Intersects(a, b);
}

//
// SkRefCnt
//

bool SkRefCnt_unique(SkRefCnt* ref_cnt) {
    return ref_cnt->unique();
}

void SkRefCnt_ref(SkRefCnt* ref_cnt) {
    ref_cnt->ref();
}

void SkRefCnt_unref(SkRefCnt* ref_cnt) {
    ref_cnt->unref();
}

//
// SkRefCntBase
//

SkRefCntBase *SkRefCntBase_new() {
    return new SkRefCntBase();
}

void SkRefCntBase_delete(SkRefCntBase *ref_cnt_base) {
    delete ref_cnt_base;
}

bool unique(SkRefCntBase *ref_cnt_base) {
    return ref_cnt_base->unique();
}

void ref(SkRefCntBase *ref_cnt_base) {
    ref_cnt_base->ref();
}

void unref(SkRefCntBase *ref_cnt_base) {
    ref_cnt_base->unref();
}

//
// SkRegion
//

//SkRegion & operator=(const SkRegion &region)
//bool operator==(const SkRegion &other)
//bool operator!=(const SkRegion &other)

SkRegion *SkRegion_new() {
    return new SkRegion();
}

SkRegion *SkRegion_new_2(const SkRegion &region) {
    return new SkRegion(region);
}

SkRegion *SkRegion_new_3(const SkIRect &rect) {
    return new SkRegion(rect);
}

void SkRegion_delete(SkRegion *region) {
    delete region;
}

bool SkRegion_set(SkRegion *region, const SkRegion &src) {
    return region->set(src);
}

void SkRegion_swap(SkRegion *region, SkRegion &other) {
    return region->swap(other);
}

bool SkRegion_isEmpty(SkRegion *region) {
    return region->isEmpty();
}

bool SkRegion_isRect(SkRegion *region) {
    return region->isRect();
}

bool SkRegion_isComplex(SkRegion *region) {
    return region->isComplex();
}

const SkIRect & SkRegion_getBounds(SkRegion *region) {
    return region->getBounds();
}

int SkRegion_computeRegionComplexity(SkRegion *region) {
    return region->computeRegionComplexity();
}

bool SkRegion_getBoundaryPath(SkRegion *region, SkPath *path) {
    return region->getBoundaryPath(path);
}

bool SkRegion_setEmpty(SkRegion *region) {
    return region->setEmpty();
}

bool SkRegion_setRect(SkRegion *region, const SkIRect &rect) {
    return region->setRect(rect);
}

bool SkRegion_setRects(SkRegion *region, const SkIRect rects[], int count) {
    return region->setRects(rects, count);
}

bool SkRegion_setRegion(SkRegion *region, const SkRegion &region_2) {
    return region->setRegion(region_2);
}

bool SkRegion_setPath(SkRegion *region, const SkPath &path, const SkRegion &clip) {
    return region->setPath(path, clip);
}

bool SkRegion_intersects(SkRegion *region, const SkIRect &rect) {
    return region->intersects(rect);
}

bool SkRegion_intersects_2(SkRegion *region, const SkRegion &other) {
    return region->intersects(other);
}

bool SkRegion_contains(SkRegion *region, int32_t x, int32_t y) {
    return region->contains(x, y);
}

bool SkRegion_contains_2(SkRegion *region, const SkIRect &other) {
    return region->contains(other);
}

bool SkRegion_contains_3(SkRegion *region, const SkRegion &other) {
    return region->contains(other);
}

bool SkRegion_quickContains(SkRegion *region, const SkIRect &r) {
    return region->quickContains(r);
}

bool SkRegion_quickReject(SkRegion *region, const SkIRect &rect) {
    return region->quickReject(rect);
}

bool SkRegion_quickReject_2(SkRegion *region, const SkRegion &rgn) {
    return region->quickReject(rgn);
}

void SkRegion_translate(SkRegion *region, int dx, int dy) {
    region->translate(dx, dy);
}

void SkRegion_translate_2(SkRegion *region, int dx, int dy, SkRegion *dst) {
    region->translate(dx, dy, dst);
}

bool SkRegion_op(SkRegion *region, const SkIRect &rect, SkRegion::Op op) {
    return region->op(rect, op);
}

bool SkRegion_op_2(SkRegion *region, const SkRegion &rgn, SkRegion::Op op) {
    return region->op(rgn, op);
}

bool SkRegion_op_3(SkRegion *region, const SkIRect &rect, const SkRegion &rgn, SkRegion::Op op) {
    return region->op(rect, rgn, op);
}

bool SkRegion_op_4(SkRegion *region, const SkRegion &rgn, const SkIRect &rect, SkRegion::Op op) {
    return region->op(rgn, rect, op);
}

bool SkRegion_op_5(SkRegion *region, const SkRegion &rgna, const SkRegion &rgnb, SkRegion::Op op) {
    return region->op(rgna, rgnb, op);
}

size_t SkRegion_writeToMemory(SkRegion *region, void *buffer) {
    return region->writeToMemory(buffer);
}

size_t SkRegion_readFromMemory(SkRegion *region, const void *buffer, size_t length) {
    return region->readFromMemory(buffer, length);
}



}

void used() {
    /*
    SkPath *path = SkPath_new();
    SkPoint *p = nullptr;
    p->fX = 0.0;
    p->fY = 0.0;
    SkPath_moveTo(path, p);
     */
}

int main(int argc, char* argv[]) {
    /*
    //used();

    // GLFWを初期化する
    {
        if (glfwInit() != GL_TRUE) {
            fprintf(stderr, "Initialization of GLFW failed.\n");
            exit(EXIT_FAILURE);
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    int width = 800;
    int height = 600;
    GLFWwindow *window;
    {
        window = glfwCreateWindow(width, height, "GUI", NULL, NULL);
        if (!window) {
            fprintf(stderr, "Window creation failed.\n");
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    }

    // 頂点データを作成する
    GLuint vertex_array_object;
    GLuint vertex_buffer_object;
    GLuint element_buffer_object;
    {
        float vertices[] = {
                -1.0f, 1.0f, 0.0f,  // Position 0
                0.0f, 0.0f,         // TexCoord 0
                -1.0f, -1.0f, 0.0f,  // Position 1
                0.0f, 1.0f,         // TexCoord 1
                1.0f, -1.0f, 0.0f,  // Position 2
                1.0f, 1.0f,         // TexCoord 2
                1.0f, 1.0f, 0.0f,  // Position 3
                1.0f, 0.0f          // TexCoord 3
        };
        unsigned int indices[] = {
                0, 1, 2, 0, 2, 3
        };
        glGenVertexArrays(1, &vertex_array_object);
        glGenBuffers(1, &vertex_buffer_object);
        glGenBuffers(1, &element_buffer_object);
        glBindVertexArray(vertex_array_object);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    // シェーダーを作成する
    GLuint shader_program;
    {
        const char *vertex_shader_source =
                "attribute vec4 a_position;"
                "attribute vec2 a_texCoord;"
                "varying vec2 v_texCoord;"
                "void main() {"
                "    gl_Position = a_position;"
                "    v_texCoord = a_texCoord;"
                "}";
        const char *fragment_shader_source =
                "precision mediump float;"
                "varying vec2 v_texCoord;"
                "uniform sampler2D s_texture;"
                "void main() {"
                "    gl_FragColor = texture2D(s_texture, v_texCoord);"
                "}";
        GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    // ウィンドウのピクセルデータを初期化する
    GLubyte *image_pixels;
    int image_width = 800;
    int image_height = 600;
    int image_channels = 0;
    GLuint window_texture;
    {
        image_pixels = stbi_load("adv_sample_image.png", &image_width, &image_height, &image_channels, 0);
        glGenTextures(1, &window_texture);
    }


    // SkBitmapとSkCanvasを初期化する
    SkBitmap* skBitmap = SkBitmap_new();
    {
        SkBitmap_allocN32Pixels(skBitmap, image_width, image_height, false);
        SkCanvas *canvas = SkCanvas_new_4(skBitmap);

        {
            // PNG画像を読み込む
            SkStream_MakeFromFile("image_file", "adv_sample_image.png");
            SkData_MakeFromStream("image_data", static_sk_stream_get("image_file"), SkStream_getLength(static_sk_stream_get("image_file")));
            SkImages_DeferredFromEncodedData("sample_image", "image_data");
        }

        {
            // 画像をキャンバスに描画
            SkCanvas_drawImage_4(canvas, static_sk_image_get("sample_image"), 0, 0);
        }

        {
            // 図形を描画する
            SkPaint *paint = SkPaint_new();
            SkPaint_setBlendMode(paint, SkBlendMode::kOverlay);
            SkPaint_setColor_2(paint, SK_ColorBLUE); // 赤色を選択
            SkRect_MakeXYWH("rect", 20, 20, 400, 600 - 40); // 四角形の位置とサイズ
            SkCanvas_drawRect("rect", canvas, paint); // 四角形を描画
            static_sk_rect_delete("rect");
        }

        {
            // パスを描画する
            const SkScalar scale = 256.0f;
            const SkScalar R = 0.45f * scale;
            const SkScalar TAU = 6.2831853f;
            SkPath *path = SkPath_new();
            SkPath_moveTo_2(path, R, 0.0f);
            for (int i = 1; i < 7; ++i) {
                SkScalar theta = (float)(3 * i) * TAU / 7;
                SkPath_lineTo_2(path,R * cos(theta), R * sin(theta));
            }
            SkPath_close(path);
            SkPaint *paint = SkPaint_new();
            SkPaint_setARGB(paint, 255, 255, 0, 0);
            SkPaint_setAntiAlias(paint, true);
            //canvas->clear(SK_ColorWHITE);
            //canvas.translate(0.5f * scale, 0.5f * scale);
            SkCanvas_drawPath(canvas, path, paint);
        }

        // ピクセルデータを書き込む
        //skBitmap.setPixels(image_pixels);

        // スマートポインタを明示的に解放する
        static_sk_data_delete("image_data");
        static_sk_stream_delete("image_file");
        static_sk_image_delete("sample_image");
    }
    // Skiaのビットマップからピクセルデータを取得
    GLubyte* skia_pixels = (GLubyte*)SkBitmap_getPixels(skBitmap);;



    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glBindTexture(GL_TEXTURE_2D, window_texture);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pixels);
        // Skiaで描画したピクセルデータをOpenGLテクスチャにコピー
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //glBindTexture(GL_TEXTURE_2D, window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, skia_pixels);

        glUseProgram(shader_program);
        glBindVertexArray(vertex_array_object);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindTexture(GL_TEXTURE_2D, 2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 不要なオブジェクトを解放する
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);
    glDeleteBuffers(1, &element_buffer_object);
    glDeleteTextures(1, &window_texture);
    free(image_pixels);
    glfwDestroyWindow(window);
    glfwTerminate();
     */
    return 0;
}
