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
#include "include/core/SkRRect.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSamplingOptions.h"
#include "include/core/SkShader.h"
#include "include/core/SkStream.h"
#include "include/core/SkStrokeRec.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTraceMemoryDump.h"
#include "include/core/SkUnPreMultiply.h"
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
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "include/effects/SkTableMaskFilter.h"
#include "include/effects/SkTrimPathEffect.h"
#include "include/gpu/graphite/Recorder.h"
#include "include/pathops/SkPathOps.h"
#include "modules/skshaper/include/SkShaper.h"

#include <map>
#include <utility>


//
// static
//

// struct
static std::map<std::string, SkRect> static_sk_rect;
static std::map<std::string, SkIRect> static_sk_i_rect;
static std::map<std::string, SkImageInfo> static_sk_image_info;

// class
static std::map<std::string, SkPixmap> static_sk_pixmap;
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
// static
//

// sk_stream

SkStream *static_sk_stream_get(const char *sk_stream_key){
    return static_sk_stream[sk_stream_key].get();
}

void static_sk_stream_delete(const char *sk_stream_key) {
    static_sk_stream[sk_stream_key].reset();
    static_sk_stream.erase(sk_stream_key);
}

// sk_image

SkImage *static_sk_image_get(const char *sk_image_key){
    return static_sk_image[sk_image_key].get();
}

void static_sk_image_delete(const char *sk_image_key) {
    static_sk_image[sk_image_key].reset(); // スマートポインタを明示的に解放する
    static_sk_image.erase(sk_image_key);
}

// sk_image_generator

SkImageGenerator *static_sk_image_generator_get(const char *sk_image_generator_key){
    return static_sk_image_generator[sk_image_generator_key].get();
}

// sk_data

void static_sk_data_delete(const char *sk_data_key) {
    static_sk_data[sk_data_key].reset();
    static_sk_data.erase(sk_data_key);
}

// sk_shader

void static_sk_shader_delete(const char *sk_shader_key) {
    static_sk_shader[sk_shader_key].reset();
    static_sk_shader.erase(sk_shader_key);
}

// sk_rect

void static_sk_rect_delete(const char *sk_rect_key) {
    static_sk_rect.erase(sk_rect_key);
}

//
// SkAlphaType
//

// static

bool SkAlphaType_SkAlphaTypeIsOpaque(SkAlphaType at) {
    return SkAlphaTypeIsOpaque(at);
}

//
// SkAnnotation
//

// SK_API

void SkAnnotation_SkAnnotateLinkToDestination(SkCanvas * canvas, const SkRect * rect, SkData * data) {
    SkAnnotateLinkToDestination(canvas, *rect, data);
}

void SkAnnotation_SkAnnotateNamedDestination(SkCanvas * canvas, const SkPoint * point, SkData * data) {
    SkAnnotateNamedDestination(canvas, *point, data);
}

void SkAnnotation_SkAnnotateRectWithURL(SkCanvas * canvas, const SkRect * rect, SkData * data) {
    SkAnnotateRectWithURL(canvas, *rect, data);
}

//
// SkAutoCanvasRestore
//

SkAutoCanvasRestore *SkAutoCanvasRestore_new(SkCanvas * canvas, bool doSave) {
    return new SkAutoCanvasRestore(canvas, doSave);
}

void SkAutoCanvasRestore_delete(SkAutoCanvasRestore *autoCanvasRestore) {
    delete autoCanvasRestore;
}

void SkAutoCanvasRestore_restore(SkAutoCanvasRestore *autoCanvasRestore) {
    autoCanvasRestore->restore();
}

//
// SkBBHFactory - abstract
//

//
// SkBBoxHierarchy - abstract
//

void SkBBoxHierarchy_insert(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], int N) {
    b_box_hierarchy->insert(rect, N);
}

void SkBBoxHierarchy_insert_2(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], const SkBBoxHierarchy::Metadata metadata[], int N) {
    b_box_hierarchy->insert(rect, metadata, N);
}

void SkBBoxHierarchy_search(SkBBoxHierarchy *b_box_hierarchy, const SkRect *query, std::vector<int> *results) { // @TODO
    b_box_hierarchy->search(*query, results);
}

size_t SkBBoxHierarchy_bytesUsed(SkBBoxHierarchy *b_box_hierarchy) {
    return b_box_hierarchy->bytesUsed();
}

bool SkBBoxHierarchy_unique(SkBBoxHierarchy *b_box_hierarchy) {
    return b_box_hierarchy->unique();
}

void SkBBoxHierarchy_ref(SkBBoxHierarchy *b_box_hierarchy) {
    b_box_hierarchy->ref();
}

void SkBBoxHierarchy_unref(SkBBoxHierarchy *b_box_hierarchy) {
    b_box_hierarchy->unref();
}

//
// SkBitmap
//

SkBitmap *SkBitmap_new(void) {
    return new SkBitmap();
}

SkBitmap *SkBitmap_new_2(const SkBitmap *src) {
    return new SkBitmap(*src);
}

void SkBitmap_delete(SkBitmap *bitmap) {
    delete bitmap;
}

void SkBitmap_allocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque) {
    bitmap->allocN32Pixels(width, height, isOpaque);
}

void SkBitmap_allocPixels(SkBitmap *bitmap) {
    bitmap->allocPixels();
}

void SkBitmap_allocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator) {
    bitmap->allocPixels(allocator);
}

void SkBitmap_allocPixels_3(SkBitmap *bitmap, const SkImageInfo *info) {
    bitmap->allocPixels(*info);
}

void SkBitmap_allocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes) {
    bitmap->allocPixels(*info, rowBytes);
}

void SkBitmap_allocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags) {
    bitmap->allocPixelsFlags(*info, flags);
}

SkAlphaType SkBitmap_alphaType(SkBitmap *bitmap) { // inline
    return bitmap->alphaType();
}

void SkBitmap_asImage(const char *sk_image_key_out, SkBitmap *bitmap) {
    static_sk_image[sk_image_key_out] = bitmap->asImage();
}

void SkBitmap_bounds(const char *sk_i_rect_key_out, SkBitmap *bitmap) { // inline
    static_sk_i_rect[sk_i_rect_key_out] = bitmap->bounds();
}

int SkBitmap_bytesPerPixel(SkBitmap *bitmap) { // inline
    return bitmap->bytesPerPixel();
}

SkColorSpace* SkBitmap_colorSpace(SkBitmap *bitmap) {
    return bitmap->colorSpace();
}

SkColorType SkBitmap_colorType(SkBitmap *bitmap) { // inline
    return bitmap->colorType();
}

size_t SkBitmap_computeByteSize(SkBitmap *bitmap) { // inline
    return bitmap->computeByteSize();
}

SkISize SkBitmap_dimensions(SkBitmap *bitmap) { // inline
    return bitmap->dimensions();
}

bool SkBitmap_drawsNothing(SkBitmap *bitmap) { // inline
    return bitmap->drawsNothing();
}

bool SkBitmap_empty(SkBitmap *bitmap) { // inline
    return bitmap->empty();
}

void SkBitmap_erase(SkBitmap *bitmap, SkColor c, const SkIRect *area) {
    bitmap->erase(c, *area);
}

void SkBitmap_erase_2(SkBitmap *bitmap, SkColor4f c, const SkIRect *area) {
    bitmap->erase(c, *area);
}

void SkBitmap_eraseArea(SkBitmap *bitmap, const SkIRect *area, SkColor c) { // inline
    bitmap->eraseArea(*area, c);
}

void SkBitmap_eraseARGB(SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b) { // inline
    bitmap->eraseARGB(a, r, g, b);
}

void SkBitmap_eraseColor(SkBitmap *bitmap, SkColor c) {
    bitmap->eraseColor(c);
}

void SkBitmap_eraseColor_2(SkBitmap *bitmap, SkColor4f c) {
    bitmap->eraseColor(c);
}

bool SkBitmap_extractAlpha(SkBitmap *bitmap, SkBitmap *dst) { // inline
    return bitmap->extractAlpha(dst);
}

bool SkBitmap_extractAlpha_2(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset) {
    return bitmap->extractAlpha(dst, paint, allocator, offset);
}

bool SkBitmap_extractAlpha_3(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint * offset) { // inline
    return bitmap->extractAlpha(dst, paint, offset);
}

bool SkBitmap_extractSubset(SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset) {
    return bitmap->extractSubset(dst, *subset);
}

void *SkBitmap_getAddr(SkBitmap *bitmap, int x, int y) {
    return bitmap->getAddr(x, y);
}

uint16_t *SkBitmap_getAddr16(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getAddr16(x, y);
}

uint32_t *SkBitmap_getAddr32(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getAddr32(x, y);
}

uint8_t *SkBitmap_getAddr8(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getAddr8(x, y);
}

float SkBitmap_getAlphaf(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getAlphaf(x, y);
}

void SkBitmap_getBounds(SkBitmap *bitmap, SkIRect *bounds) {
    bitmap->getBounds(bounds);
}

void SkBitmap_getBounds2(SkBitmap *bitmap, SkRect *bounds) {
    bitmap->getBounds(bounds);
}

SkColor SkBitmap_getColor(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getColor(x, y);
}

SkColor4f SkBitmap_getColor4f(SkBitmap *bitmap, int x, int y) { // inline
    return bitmap->getColor4f(x, y);
}

uint32_t SkBitmap_getGenerationID(SkBitmap *bitmap) {
    return bitmap->getGenerationID();
}

void *SkBitmap_getPixels(SkBitmap *bitmap) { // inline
    return bitmap->getPixels();
}

void SkBitmap_getSubset(const char* sk_i_rect_key_out, SkBitmap *bitmap) { // inline
    static_sk_i_rect[sk_i_rect_key_out] = bitmap->getSubset();
}

int SkBitmap_height(SkBitmap *bitmap) { // inline
    return bitmap->height();
}

void SkBitmap_info(const char* sk_image_info_key_out, SkBitmap *bitmap) { // inline
    static_sk_image_info[sk_image_info_key_out] = bitmap->info();
}

bool SkBitmap_installMaskPixels(SkBitmap *bitmap, SkMaskBuilder *mask) { // Deprecated
    return bitmap->installMaskPixels(*mask);
}

bool SkBitmap_installPixels(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) { // inline
    return bitmap->installPixels(*info, pixels, rowBytes);
}

bool SkBitmap_installPixels_2(SkBitmap *bitmap, const SkImageInfo *info, void * pixels, size_t rowBytes, void(* releaseProc)(void *addr, void *context), void * context) {
    return bitmap->installPixels(*info, pixels, rowBytes, releaseProc, context);
}

bool SkBitmap_installPixels_3(SkBitmap *bitmap, const SkPixmap *pixmap) {
    return bitmap->installPixels(*pixmap);
}

bool SkBitmap_isImmutable(SkBitmap *bitmap) {
    return bitmap->isImmutable();
}

bool SkBitmap_isNull(SkBitmap *bitmap) {
    return bitmap->isNull();
}

bool SkBitmap_isOpaque(SkBitmap *bitmap) {
    return bitmap->isOpaque();
}

void SkBitmap_makeShader(const char *sk_shader_key_out, SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = bitmap->makeShader(*sampling, *lm);
}

void SkBitmap_makeShader_2(const char *sk_shader_key_out, SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = bitmap->makeShader(*sampling, lm);
}

void SkBitmap_makeShader_3(const char *sk_shader_key_out, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions * sampling, const SkMatrix * localMatrix) {
    static_sk_shader[sk_shader_key_out] = bitmap->makeShader(tmx, tmy, *sampling, localMatrix);
}

void SkBitmap_makeShader_4(const char *sk_shader_key_out, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions * sampling, const SkMatrix * lm) {
    static_sk_shader[sk_shader_key_out] = bitmap->makeShader(tmx, tmy, *sampling, *lm);
}

void SkBitmap_notifyPixelsChanged(SkBitmap *bitmap) {
    bitmap->notifyPixelsChanged();
}

bool SkBitmap_peekPixels(SkBitmap *bitmap, SkPixmap *pixmap) {
    return bitmap->peekPixels(pixmap);
}

SkPixelRef* SkBitmap_pixelRef(SkBitmap *bitmap) { // inline
    return bitmap->pixelRef();
}

SkIPoint SkBitmap_pixelRefOrigin(SkBitmap *bitmap) {
    return bitmap->pixelRefOrigin();
}

SkPixmap SkBitmap_pixmap(SkBitmap *bitmap) { // inline
    return bitmap->pixmap();
}

bool SkBitmap_readPixels(SkBitmap *bitmap, const SkImageInfo * dstInfo, void * dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return bitmap->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkBitmap_readPixels_2(SkBitmap *bitmap, const SkPixmap *dst) { // inline
    return bitmap->readPixels(*dst);
}

bool SkBitmap_readPixels_3(SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY) {
    return bitmap->readPixels(*dst, srcX, srcY);
}

bool SkBitmap_readyToDraw(SkBitmap *bitmap) { // inline
    return bitmap->readyToDraw();
}

void SkBitmap_refColorSpace(const char *sk_color_space_key_out, SkBitmap *bitmap) {
    static_sk_color_space[sk_color_space_key_out] = bitmap->refColorSpace();
}

void SkBitmap_reset(SkBitmap *bitmap) {
    bitmap->reset();
}

size_t SkBitmap_rowBytes(SkBitmap *bitmap) { // inline
    return bitmap->rowBytes();
}

int SkBitmap_rowBytesAsPixels(SkBitmap *bitmap) { // inline
    return bitmap->rowBytesAsPixels();
}

bool SkBitmap_setAlphaType(SkBitmap *bitmap, SkAlphaType alphaType) {
    return bitmap->setAlphaType(alphaType);
}

void SkBitmap_setImmutable(SkBitmap *bitmap) {
    bitmap->setImmutable();
}

bool SkBitmap_setInfo(SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes) {
    return bitmap->setInfo(*imageInfo, rowBytes);
}

void SkBitmap_setPixelRef(const char *sk_pixel_ref_key_in, SkBitmap *bitmap, int dx, int dy) {
    bitmap->setPixelRef(static_sk_pixel_ref[sk_pixel_ref_key_in], dx, dy);
}

void SkBitmap_setPixels(SkBitmap *bitmap, void *pixels) {
    bitmap->setPixels(pixels);
}

int SkBitmap_shiftPerPixel(SkBitmap *bitmap) {
    return bitmap->shiftPerPixel();
}

void SkBitmap_swap(SkBitmap *bitmap, SkBitmap *other) {
    bitmap->swap(*other);
}

bool SkBitmap_tryAllocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque) {
    return bitmap->tryAllocN32Pixels(width, height, isOpaque);
}

bool SkBitmap_tryAllocPixels(SkBitmap *bitmap) { // inline
    return bitmap->tryAllocPixels();
}

bool SkBitmap_tryAllocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator * allocator) {
    return bitmap->tryAllocPixels(allocator);
}

bool SkBitmap_tryAllocPixels_3(SkBitmap *bitmap, const SkImageInfo * info) { // inline
    return bitmap->tryAllocPixels(*info);
}

bool SkBitmap_tryAllocPixels_4(SkBitmap *bitmap, const SkImageInfo * info, size_t rowBytes) {
    return bitmap->tryAllocPixels(*info, rowBytes);
}

bool SkBitmap_tryAllocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags) {
    return bitmap->tryAllocPixelsFlags(*info, flags);
}

int SkBitmap_width(SkBitmap *bitmap) {
    return bitmap->width();
}

bool SkBitmap_writePixels(SkBitmap *bitmap, const SkPixmap *src) { // inline
    return bitmap->writePixels(*src);
}

bool SkBitmap_writePixels_2(SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY) {
    return bitmap->writePixels(*src, dstX, dstY);
}

// static

bool SkBitmap_ComputeIsOpaque(const SkBitmap *bm) { // inline static
    return SkBitmap::ComputeIsOpaque(*bm);
}

//
// SkBlender - abstract
//

SkBlender::Factory SkBlender_getFactory(SkBlender *blender) {
    return blender->getFactory();
}

const char * SkBlender_getTypeName(SkBlender *blender) {
    return blender->getTypeName();
}

void SkBlender_flatten(SkBlender *blender, SkWriteBuffer * write_buffer) {
    blender->flatten(*write_buffer);
}

SkBlender::Type SkBlender_getFlattenableType(SkBlender *blender) {
    return blender->getFlattenableType();
}

void SkBlender_serialize(const char *sk_data_key_out, SkBlender *blender, const SkSerialProcs *serial_procs) {
    static_sk_data[sk_data_key_out] = blender->serialize(serial_procs);
}

size_t SkBlender_serialize_2(SkBlender *blender, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return blender->serialize(memory, memory_size, serial_procs);
}

bool SkBlender_unique(SkBlender *blender) {
    return blender->unique();
}

void SkBlender_ref(SkBlender *blender) {
    blender->ref();
}

void SkBlender_unref(SkBlender *blender) {
    blender->unref();
}

// static

void SkBlender_Mode(const char *sk_blender_key_out, SkBlendMode mode) {
    static_sk_blender[sk_blender_key_out] = SkBlender::Mode(mode);
}

SkBlender::Factory SkBlender_NameToFactory(const char name[]) {
    return SkBlender::NameToFactory(name);
}

const char * SkBlender_FactoryToName(SkBlender::Factory factory) {
    return SkBlender::FactoryToName(factory);
}

void SkBlender_Register(const char name[], SkBlender::Factory factory) {
    SkBlender::Register(name, factory);
}

void SkBlender_Deserialize(const char *sk_flattenable_key_out, SkBlender::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    static_sk_flattenable[sk_flattenable_key_out] = SkBlender::Deserialize(type, data, length, procs);
}

//
// SkBlenders
//

void SkBlenders_Arithmetic(const char *sk_blender_key_out, float k1, float k2, float k3, float k4, bool enforcePremul) {
    static_sk_blender[sk_blender_key_out] = SkBlenders::Arithmetic(k1, k2, k3, k4, enforcePremul);
}

//
// SkBlendMode
//

bool SkBlendMode_SkBlendMode_AsCoeff(SkBlendMode mode, SkBlendModeCoeff * src, SkBlendModeCoeff * dst) {
    return SkBlendMode_AsCoeff(mode, src, dst);
}

const char* SkBlendMode_SkBlendMode_Name(SkBlendMode blendMode) {
    return SkBlendMode_Name(blendMode);
}

//
// SkCanvas
//

SkCanvas *SkCanvas_new() {
    return new SkCanvas();
}

SkCanvas *SkCanvas_new_2(int width, int height, const SkSurfaceProps * props) {
    return new SkCanvas(width, height, props);
}

// SkCanvas *SkCanvas_new_3() { // private
//    return new SkCanvas(static_sk_device);
//}

SkCanvas *SkCanvas_new_4(SkBitmap *bitmap) {
    return new SkCanvas(*bitmap);
}

SkCanvas *SkCanvas_new_5(const SkBitmap *bitmap, const SkSurfaceProps *props) {
    return new SkCanvas(*bitmap, *props);
}

// SkCanvas *SkCanvas_new_6(const SkIRect *bounds) { // protected
//    return new SkCanvas(*bounds);
//}

void SkCanvas_delete(SkCanvas *canvas) {
    delete canvas;
}

void *SkCanvas_accessTopLayerPixels(SkCanvas *canvas, SkImageInfo *info, size_t * rowBytes, SkIPoint * origin) {
    return canvas->accessTopLayerPixels(info, rowBytes, origin);
}

SkRasterHandleAllocator::Handle SkCanvas_accessTopRasterHandle(SkCanvas *canvas) {
    return canvas->accessTopRasterHandle();
}

void SkCanvas_androidFramework_setDeviceClipRestriction(SkCanvas *canvas, const SkIRect *rect) {
    canvas->androidFramework_setDeviceClipRestriction(*rect);
}

void SkCanvas_clear(SkCanvas *canvas, const SkColor4f * color) {
    canvas->clear(*color);
}

void SkCanvas_clear_2(SkCanvas *canvas, SkColor color) {
    canvas->clear(color);
}

void SkCanvas_clipIRect(SkCanvas *canvas, const SkIRect * irect, SkClipOp op) {
    canvas->clipIRect(*irect, op);
}

void SkCanvas_clipPath(SkCanvas *canvas, const SkPath * path, bool doAntiAlias) {
    canvas->clipPath(*path, doAntiAlias);
}

void SkCanvas_clipPath_2(SkCanvas *canvas, const SkPath * path, SkClipOp op) {
    canvas->clipPath(*path, op);
}

void SkCanvas_clipPath_3(SkCanvas *canvas, const SkPath * path, SkClipOp op, bool doAntiAlias) {
    canvas->clipPath(*path, op, doAntiAlias);
}

void SkCanvas_clipRect(SkCanvas *canvas, const SkRect * rect, bool doAntiAlias) {
    canvas->clipRect(*rect, doAntiAlias);
}

void SkCanvas_clipRect_2(SkCanvas *canvas, const SkRect * rect, SkClipOp op) {
    canvas->clipRect(*rect, op);
}

void SkCanvas_clipRect_3(SkCanvas *canvas, const SkRect * rect, SkClipOp op, bool doAntiAlias) {
    canvas->clipRect(*rect, op, doAntiAlias);
}

void SkCanvas_clipRegion(SkCanvas *canvas, const SkRegion * deviceRgn, SkClipOp op) {
    canvas->clipRegion(*deviceRgn, op);
}

void SkCanvas_clipRRect(SkCanvas *canvas, const SkRRect * rrect, bool doAntiAlias) {
    canvas->clipRRect(*rrect, doAntiAlias);
}

void SkCanvas_clipRRect_2(SkCanvas *canvas, const SkRRect * rrect, SkClipOp op) {
    canvas->clipRRect(*rrect, op);
}

void SkCanvas_clipRRect_3(SkCanvas *canvas, const SkRRect * rrect, SkClipOp op, bool doAntiAlias) {
    canvas->clipRRect(*rrect, op, doAntiAlias);
}

void SkCanvas_clipShader(const char *sk_shader_key_in, SkCanvas *canvas, SkClipOp op) {
    canvas->clipShader(static_sk_shader[sk_shader_key_in], op);
}

void SkCanvas_concat(SkCanvas *canvas, const SkM44 * m44) {
    canvas->concat(*m44);
}

void SkCanvas_concat_2(SkCanvas *canvas, const SkMatrix * matrix) {
    canvas->concat(*matrix);
}

// virtual void SkCanvas_didConcat44(SkCanvas *canvas, const SkM44 *) {} // protected
// virtual void SkCanvas_didRestore(SkCanvas *canvas) {} // protected
// virtual void SkCanvas_didScale(SkCanvas *canvas, SkScalar SkScalar) {} // protected
// virtual void SkCanvas_didTranslate(SkCanvas *canvas, SkScalar SkScalar) {} // protected

void SkCanvas_discard(SkCanvas *canvas) {
    canvas->discard();
}

void SkCanvas_drawAnnotation(const char *sk_data_key_in, SkCanvas *canvas, const SkRect * rect, const char key[]) {
    canvas->drawAnnotation(*rect, key, static_sk_data[sk_data_key_in]);
}

void SkCanvas_drawAnnotation_2(SkCanvas *canvas, const SkRect * rect, const char key[], SkData * value) {
    canvas->drawAnnotation(*rect, key, value);
}

void SkCanvas_drawArc(SkCanvas *canvas, const SkRect * oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter, const SkPaint * paint) {
    canvas->drawArc(*oval, startAngle, sweepAngle, useCenter, *paint);
}

void SkCanvas_drawAtlas(SkCanvas *canvas, const SkImage * atlas, const SkRSXform xform[], const SkRect tex[], const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions * sampling, const SkRect * cullRect, const SkPaint * paint) {
    canvas->drawAtlas(atlas, xform, tex, colors, count, mode, *sampling, cullRect, paint);
}

void SkCanvas_drawCircle(SkCanvas *canvas, SkPoint center, SkScalar radius, const SkPaint * paint) {
    canvas->drawCircle(center, radius, *paint);
}

void SkCanvas_drawCircle_2(SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint * paint) {
    canvas->drawCircle(cx, cy, radius, *paint);
}

void SkCanvas_drawColor(SkCanvas *canvas, const SkColor4f * color, SkBlendMode mode) {
    canvas->drawColor(*color, mode);
}

void SkCanvas_drawColor_2(SkCanvas *canvas, SkColor color, SkBlendMode mode) {
    canvas->drawColor(color, mode);
}

void SkCanvas_drawDrawable(SkCanvas *canvas, SkDrawable * drawable, const SkMatrix * matrix) {
    canvas->drawDrawable(drawable, matrix);
}

void SkCanvas_drawDrawable_2(SkCanvas *canvas, SkDrawable * drawable, SkScalar x, SkScalar y) {
    canvas->drawDrawable(drawable, x, y);
}

void SkCanvas_drawDRRect(SkCanvas *canvas, const SkRRect * outer, const SkRRect * inner, const SkPaint * paint) {
    canvas->drawDRRect(*outer, *inner, *paint);
}

void SkCanvas_drawGlyphs(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], const uint32_t clusters[], int textByteCount, const char utf8text[], SkPoint origin, const SkFont * font, const SkPaint * paint) {
    canvas->drawGlyphs(count, glyphs, positions, clusters, textByteCount, utf8text, origin, *font, *paint);
}

void SkCanvas_drawGlyphs_2(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], SkPoint origin, const SkFont * font, const SkPaint * paint) {
    canvas->drawGlyphs(count, glyphs, positions, origin, *font, *paint);
}

void SkCanvas_drawGlyphs_3(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], SkPoint origin, const SkFont * font, const SkPaint * paint) {
    canvas->drawGlyphs(count, glyphs, xforms, origin, *font, *paint);
}

void SkCanvas_drawImage(const char *sk_image_key_in, SkCanvas *canvas, SkScalar left, SkScalar top) {
    canvas->drawImage(static_sk_image[sk_image_key_in], left, top);
}

void SkCanvas_drawImage_2(const char *sk_image_key_in, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImage(static_sk_image[sk_image_key_in], x, y, *sampling, paint);
}

void SkCanvas_drawImage_3(SkCanvas *canvas, const SkImage * image, SkScalar x, SkScalar y, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImage(image, x, y, *sampling, paint);
}

void SkCanvas_drawImage_4(SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top) {
    canvas->drawImage(image, left, top);
}

void SkCanvas_drawImageLattice(SkCanvas *canvas, const SkImage * image, const SkCanvas::Lattice * lattice, const SkRect * dst ) {
    canvas->drawImageLattice(image, *lattice, *dst);
}

void SkCanvas_drawImageLattice_2(SkCanvas *canvas, const SkImage * image, const SkCanvas::Lattice * lattice, const SkRect * dst, SkFilterMode filter, const SkPaint * paint) {
    canvas->drawImageLattice(image, *lattice, *dst, filter, paint);
}

void SkCanvas_drawImageNine(SkCanvas *canvas, const SkImage * image, const SkIRect * center, const SkRect * dst, SkFilterMode filter, const SkPaint * paint) {
    canvas->drawImageNine(image, *center, *dst, filter, paint);
}

void SkCanvas_drawImageRect(const char *sk_image_key_in, SkCanvas *canvas, const SkRect * dst, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImageRect(static_sk_image[sk_image_key_in], *dst, *sampling, paint);
}

void SkCanvas_drawImageRect_2(const char *sk_image_key_in, SkCanvas *canvas, const SkRect * src, const SkRect * dst, const SkSamplingOptions * sampling,const SkPaint * paint, SkCanvas::SrcRectConstraint constraint ) {
    canvas->drawImageRect(static_sk_image[sk_image_key_in], *src, *dst, *sampling, paint, constraint);
}

void SkCanvas_drawImageRect_3(SkCanvas *canvas, const SkImage * image, const SkRect * dst, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImageRect(image, *dst, *sampling, paint);
}

void SkCanvas_drawImageRect_4(SkCanvas *canvas, const SkImage * image, const SkRect * src, const SkRect * dst, const SkSamplingOptions * sampling, const SkPaint * paint, SkCanvas::SrcRectConstraint constraint) {
    canvas->drawImageRect(image, *src, *dst, *sampling, paint, constraint);
}

void SkCanvas_drawIRect(SkCanvas *canvas, const SkIRect * rect, const SkPaint * paint) {
    canvas->drawIRect(*rect, *paint);
}

void SkCanvas_drawLine(SkCanvas *canvas, SkPoint p0, SkPoint p1, const SkPaint * paint) {
    canvas->drawLine(p0, p1, *paint);
}

void SkCanvas_drawLine_2(SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint * paint) {
    canvas->drawLine(x0, y0, x1, y1, *paint);
}

void SkCanvas_drawMesh(const char *sk_blender_key_in, SkCanvas *canvas, const SkMesh * mesh, const SkPaint * paint) {
    canvas->drawMesh(*mesh, static_sk_blender[sk_blender_key_in], *paint);
}

void SkCanvas_drawOval(SkCanvas *canvas, const SkRect * oval, const SkPaint * paint) {
    canvas->drawOval(*oval, *paint);
}

void SkCanvas_drawPaint(SkCanvas *canvas, const SkPaint * paint) {
    canvas->drawPaint(*paint);
}

void SkCanvas_drawPatch(SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4], SkBlendMode mode, const SkPaint * paint) {
    canvas->drawPatch(cubics, colors, texCoords, mode, *paint);
}

void SkCanvas_drawPath(SkCanvas *canvas, const SkPath *path, const SkPaint *paint) {
    canvas->drawPath(*path, *paint);
}

void SkCanvas_drawPicture(const char *sk_picture_key_in, SkCanvas *canvas) {
    canvas->drawPicture(static_sk_picture[sk_picture_key_in]);
}

void SkCanvas_drawPicture_2(const char *sk_picture_key_in, SkCanvas *canvas, const SkMatrix * matrix, const SkPaint * paint) {
    canvas->drawPicture(static_sk_picture[sk_picture_key_in], matrix, paint);
}

void SkCanvas_drawPicture_3(SkCanvas *canvas, const SkPicture * picture) {
    canvas->drawPicture(picture);
}

void SkCanvas_drawPicture_4(SkCanvas *canvas, const SkPicture * picture, const SkMatrix * matrix, const SkPaint * paint) {
    canvas->drawPicture(picture, matrix, paint);
}

void SkCanvas_drawPoint(SkCanvas *canvas, SkPoint p, const SkPaint * paint) {
    canvas->drawPoint(p, *paint);
}

void SkCanvas_drawPoint_2(SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint * paint) {
    canvas->drawPoint(x, y, *paint);
}

void SkCanvas_drawPoints(SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[], const SkPaint * paint) {
    canvas->drawPoints(mode, count, pts, *paint);
}

void SkCanvas_drawRect(const char *sk_rect_key_in, SkCanvas *canvas, const SkPaint *paint) {
    canvas->drawRect(static_sk_rect[sk_rect_key_in], *paint);
}

void SkCanvas_drawRegion(SkCanvas *canvas, const SkRegion * region, const SkPaint * paint) {
    canvas->drawRegion(*region, *paint);
}

void SkCanvas_drawRoundRect(SkCanvas *canvas, const SkRect * rect, SkScalar rx, SkScalar ry, const SkPaint * paint) {
    canvas->drawRoundRect(*rect, rx, ry, *paint);
}

void SkCanvas_drawRRect(SkCanvas *canvas, const SkRRect * rrect, const SkPaint * paint) {
    canvas->drawRRect(*rrect, *paint);
}

void SkCanvas_drawSimpleText(SkCanvas *canvas, const void * text, size_t byteLength, SkTextEncoding encoding, SkScalar x, SkScalar y, const SkFont * font, const SkPaint * paint) {
    canvas->drawSimpleText(text, byteLength, encoding, x, y, *font, *paint);
}

void SkCanvas_drawString(SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont * font, const SkPaint * paint) {
    canvas->drawString(str, x, y, *font, *paint);
}

void SkCanvas_drawString_2(SkCanvas *canvas, const SkString * str, SkScalar x, SkScalar y, const SkFont * font, const SkPaint * paint) {
    canvas->drawString(*str, x, y, *font, *paint);
}

void SkCanvas_drawTextBlob(const char *sk_text_blob_key_in, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint * paint) {
    canvas->drawTextBlob(static_sk_text_blob[sk_text_blob_key_in], x, y, *paint);
}

void SkCanvas_drawTextBlob_2(SkCanvas *canvas, const SkTextBlob * blob, SkScalar x, SkScalar y, const SkPaint * paint) {
    canvas->drawTextBlob(blob, x, y, *paint);
}

void SkCanvas_drawVertices(const char *sk_vertices_key_in, SkCanvas *canvas, SkBlendMode mode, const SkPaint * paint) {
    canvas->drawVertices(static_sk_vertices[sk_vertices_key_in], mode, *paint);
}

void SkCanvas_drawVertices_2(SkCanvas *canvas, const SkVertices * vertices, SkBlendMode mode, const SkPaint * paint) {
    canvas->drawVertices(vertices, mode, *paint);
}

void SkCanvas_experimental_DrawEdgeAAImageSet(SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt, const SkPoint dstClips[], const SkMatrix preViewMatrices[], const SkSamplingOptions * sampling, const SkPaint * paint, SkCanvas::SrcRectConstraint constraint) {
    canvas->experimental_DrawEdgeAAImageSet(imageSet, cnt, dstClips, preViewMatrices, *sampling, paint, constraint);
}

void SkCanvas_experimental_DrawEdgeAAQuad(SkCanvas *canvas, const SkRect * rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, const SkColor4f * color, SkBlendMode mode) {
    canvas->experimental_DrawEdgeAAQuad(*rect, clip, aaFlags, *color, mode);
}

void SkCanvas_experimental_DrawEdgeAAQuad_2(SkCanvas *canvas, const SkRect * rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode) {
    canvas->experimental_DrawEdgeAAQuad(*rect, clip, aaFlags, color, mode);
}

SkISize SkCanvas_getBaseLayerSize(SkCanvas *canvas) { // virtual
    return canvas->getBaseLayerSize();
}

SkSurfaceProps SkCanvas_getBaseProps(SkCanvas *canvas) {
    return canvas->getBaseProps();
}

SkIRect SkCanvas_getDeviceClipBounds(SkCanvas *canvas) {
    return canvas->getDeviceClipBounds();
}

bool SkCanvas_getDeviceClipBounds_2(SkCanvas *canvas, SkIRect * bounds) {
    return canvas->getDeviceClipBounds(bounds);
}

SkRect SkCanvas_getLocalClipBounds(SkCanvas *canvas) {
    return canvas->getLocalClipBounds();
}

bool SkCanvas_getLocalClipBounds_2(SkCanvas *canvas, SkRect * bounds) {
    return canvas->getLocalClipBounds(bounds);
}

SkM44 SkCanvas_getLocalToDevice(SkCanvas *canvas) {
    return canvas->getLocalToDevice();
}

SkMatrix SkCanvas_getLocalToDeviceAs3x3(SkCanvas *canvas) {
    return canvas->getLocalToDeviceAs3x3();
}

bool SkCanvas_getProps(SkCanvas *canvas, SkSurfaceProps * props) {
    return canvas->getProps(props);
}

int SkCanvas_getSaveCount(SkCanvas *canvas) {
    return canvas->getSaveCount();
}

SkSurface* SkCanvas_getSurface(SkCanvas *canvas) {
    return canvas->getSurface();
}

SkSurfaceProps SkCanvas_getTopProps(SkCanvas *canvas) {
    return canvas->getTopProps();
}

SkMatrix SkCanvas_getTotalMatrix(SkCanvas *canvas) {
    return canvas->getTotalMatrix();
}

SkImageInfo SkCanvas_imageInfo(SkCanvas *canvas) {
    return canvas->imageInfo();
}

bool SkCanvas_isClipEmpty(SkCanvas *canvas) {
    return canvas->isClipEmpty();
}

bool SkCanvas_isClipRect(SkCanvas *canvas) {
    return canvas->isClipRect();
}

void SkCanvas_makeSurface(const char *sk_surface_key_out, SkCanvas *canvas, const SkImageInfo * info, const SkSurfaceProps * props) {
    static_sk_surface[sk_surface_key_out] = canvas->makeSurface(*info, props);
}

bool SkCanvas_peekPixels(SkCanvas *canvas, SkPixmap * pixmap) {
    return canvas->peekPixels(pixmap);
}

void SkCanvas_private_draw_shadow_rec(SkCanvas *canvas, const SkPath * path, const SkDrawShadowRec * rec) {
    canvas->private_draw_shadow_rec(*path, *rec);
}

bool SkCanvas_quickReject(SkCanvas *canvas, const SkPath * path) {
    return canvas->quickReject(*path);
}

bool SkCanvas_quickReject_2(SkCanvas *canvas, const SkRect * rect) {
    return canvas->quickReject(*rect);
}

bool SkCanvas_readPixels(SkCanvas *canvas, const SkBitmap * bitmap, int srcX, int srcY) {
    return canvas->readPixels(*bitmap, srcX, srcY);
}

bool SkCanvas_readPixels_2(SkCanvas *canvas, const SkImageInfo * dstInfo, void * dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return canvas->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkCanvas_readPixels_3(SkCanvas *canvas, const SkPixmap * pixmap, int srcX, int srcY) {
    return canvas->readPixels(*pixmap, srcX, srcY);
}

skgpu::graphite::Recorder* SkCanvas_recorder(SkCanvas *canvas) {
    return canvas->recorder();
}

GrRecordingContext* SkCanvas_recordingContext(SkCanvas *canvas) {
    return canvas->recordingContext();
}

void SkCanvas_resetMatrix(SkCanvas *canvas) {
    canvas->resetMatrix();
}

void SkCanvas_restore(SkCanvas *canvas) {
    canvas->restore();
}

void SkCanvas_restoreToCount(SkCanvas *canvas, int saveCount) {
    canvas->restoreToCount(saveCount);
}

void SkCanvas_rotate(SkCanvas *canvas, SkScalar degrees) {
    canvas->rotate(degrees);
}

void SkCanvas_rotate_2(SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py) {
    canvas->rotate(degrees, px, py);
}

int SkCanvas_save(SkCanvas *canvas) {
    return canvas->save();
}

int SkCanvas_saveLayer(SkCanvas *canvas, const SkCanvas::SaveLayerRec * layerRec) {
    return canvas->saveLayer(*layerRec);
}

int SkCanvas_saveLayer_2(SkCanvas *canvas, const SkRect * bounds, const SkPaint * paint) {
    return canvas->saveLayer(*bounds, paint);
}

int SkCanvas_saveLayer_3(SkCanvas *canvas, const SkRect * bounds, const SkPaint * paint) {
    return canvas->saveLayer(bounds, paint);
}

int SkCanvas_saveLayerAlpha(SkCanvas *canvas, const SkRect * bounds, U8CPU alpha) {
    return canvas->saveLayerAlpha(bounds, alpha);
}

int SkCanvas_saveLayerAlphaf(SkCanvas *canvas, const SkRect * bounds, float alpha) {
    return canvas->saveLayerAlphaf(bounds, alpha);
}

void SkCanvas_scale(SkCanvas *canvas, SkScalar sx, SkScalar sy) {
    canvas->scale(sx, sy);
}

void SkCanvas_setMatrix(SkCanvas *canvas, const SkM44 * matrix) {
    canvas->setMatrix(*matrix);
}

void SkCanvas_setMatrix_2(SkCanvas *canvas, const SkMatrix * matrix) {
    canvas->setMatrix(*matrix);
}

void SkCanvas_skew(SkCanvas *canvas, SkScalar sx, SkScalar sy) {
    canvas->skew(sx, sy);
}

void SkCanvas_temporary_internal_getRgnClip(SkCanvas *canvas, SkRegion * region) {
    canvas->temporary_internal_getRgnClip(region);
}

void SkCanvas_translate(SkCanvas *canvas, SkScalar dx, SkScalar dy) {
    canvas->translate(dx, dy);
}

bool SkCanvas_writePixels(SkCanvas *canvas, const SkBitmap * bitmap, int x, int y) {
    return canvas->writePixels(*bitmap, x, y);
}

bool SkCanvas_writePixels_2(SkCanvas *canvas, const SkImageInfo * info, const void * pixels, size_t rowBytes, int x, int y) {
    return canvas->writePixels(*info, pixels, rowBytes, x, y);
}

// static

void SkCanvas_MakeRasterDirect(const char *sk_canvas_key_out, const SkImageInfo * info, void * pixels, size_t rowBytes, const SkSurfaceProps * props) {
    static_sk_canvas[sk_canvas_key_out] = SkCanvas::MakeRasterDirect(*info, pixels, rowBytes, props);
}

void SkCanvas_MakeRasterDirectN32(const char *sk_canvas_key_out, int width, int height, SkPMColor * pixels, size_t rowBytes) {
    static_sk_canvas[sk_canvas_key_out] = SkCanvas::MakeRasterDirectN32(width, height, pixels, rowBytes);
}

//
// SkCapabilities
//

void SkCapabilities_ref(SkCapabilities *capabilities) {
    capabilities->ref();
}

SkSL::Version SkCapabilities_skslVersion(SkCapabilities *capabilities) {
    return capabilities->skslVersion();
}

bool SkCapabilities_unique(SkCapabilities *capabilities) {
    return capabilities->unique();
}

void SkCapabilities_unref(SkCapabilities *capabilities) {
    capabilities->unref();
}

// static

void SkCapabilities_RasterBackend(const char *sk_capabilities_key_out) {
    static_const_sk_capabilities[sk_capabilities_key_out] = SkCapabilities::RasterBackend();
}

//
// SkColor
//

// SK_API

SkColor SkColor_SkColorSetA(SkColor c, U8CPU a) {
    return SkColorSetA(c, a);
}

SkColor SkColor_SkColorSetARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkColorSetARGB(a, r, g, b);
}

void SkColor_SkColorToHSV(SkColor color, SkScalar hsv[3]) {
    SkColorToHSV(color, hsv);
}

SkColor SkColor_SkHSVToColor(const SkScalar hsv[3]) {
    return SkHSVToColor(hsv);
}

SkColor SkColor_SkHSVToColor_2(U8CPU alpha, const SkScalar hsv[3]) {
    return SkHSVToColor(alpha, hsv);
}

SkPMColor SkColor_SkPreMultiplyARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPreMultiplyARGB(a, r, g, b);
}

SkPMColor SkColor_SkPreMultiplyColor(SkColor c) {
    return SkPreMultiplyColor(c);
}

void SkColor_SkRGBToHSV(U8CPU red, U8CPU green, U8CPU blue, SkScalar hsv[3]) {
    SkRGBToHSV(red, green, blue, hsv);
}

//
// SkColorFilter
//

bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor * color, SkBlendMode * mode) {
    return color_filter->asAColorMode(color, mode);
}

bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]) {
    return color_filter->asAColorMatrix(matrix);
}

bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter) {
    return color_filter->isAlphaUnchanged();
}

SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color) {
    return color_filter->filterColor(color);
}

SkColor4f SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f * srcColor, SkColorSpace * srcCS, SkColorSpace * dstCS) {
    return color_filter->filterColor4f(*srcColor, srcCS, dstCS);
}

void SkColorFilter_makeComposed(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in, SkColorFilter *color_filter) {
    static_sk_color_filter[sk_color_filter_key_out] = color_filter->makeComposed(static_sk_color_filter[sk_color_filter_key_in]);
}

void SkColorFilter_makeWithWorkingColorSpace(const char *sk_color_filter_key_out, const char * sk_color_space_key_in, SkColorFilter *color_filter) {
    static_sk_color_filter[sk_color_filter_key_out] = color_filter->makeWithWorkingColorSpace(static_sk_color_space[sk_color_space_key_in]);
}

SkColorFilter::Factory SkColorFilter_getFactory(SkColorFilter *color_filter) {
    return color_filter->getFactory();
}

const char * SkColorFilter_getTypeName(SkColorFilter *color_filter) {
    return color_filter->getTypeName();
}

void SkColorFilter_flatten(SkColorFilter *color_filter, SkWriteBuffer * write_buffer) {
    color_filter->flatten(*write_buffer);
}

SkColorFilter::Type SkColorFilter_getFlattenableType(SkColorFilter *color_filter) {
    return color_filter->getFlattenableType();
}

void SkColorFilter_serialize(const char *sk_data_key_out, SkColorFilter *color_filter, const SkSerialProcs *serial_procs) {
    static_sk_data[sk_data_key_out] = color_filter->serialize(serial_procs);
}

size_t SkColorFilter_serialize_2(SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return color_filter->serialize(memory, memory_size, serial_procs);
}

bool SkColorFilter_unique(SkColorFilter *color_filter) {
    return color_filter->unique();
}

void SkColorFilter_ref(SkColorFilter *color_filter) {
    return color_filter->ref();
}

void SkColorFilter_unref(SkColorFilter *color_filter) {
    color_filter->unref();
}

// static

void SkColorFilter_Deserialize(const char *sk_color_filter_key_out, const void * data, size_t size, const SkDeserialProcs * procs) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilter::Deserialize(data, size, procs);
}

SkColorFilter::Factory SkColorFilter_NameToFactory(const char name[]) {
    return SkColorFilter::NameToFactory(name);
}

const char * SkColorFilter_FactoryToName(SkColorFilter::Factory factory) {
    return SkColorFilter::FactoryToName(factory);
}

void SkColorFilter_Register(const char name[], SkColorFilter::Factory factory) {
    SkColorFilter::Register(name, factory);
}

//void SkFlattenable_Deserialize(const char *sk_flattenable_key, SkColorFilter::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
//    static_sk_flattenable[sk_flattenable_key] = SkFlattenable::Deserialize(type, data, length, procs);
//}

//
// SkColorFilters
//

// static

void SkColorFilters_Blend(const char *sk_color_filter_key_out, const char * sk_color_space_key_in, const SkColor4f * c, SkBlendMode mode) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Blend(*c, static_sk_color_space[sk_color_space_key_in], mode);
}

void SkColorFilters_Blend_2(const char *sk_color_filter_key_out, SkColor c, SkBlendMode mode) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Blend(c, mode);
}

void SkColorFilters_Compose(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in_1, const char *sk_color_filter_key_in_2) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Compose(static_sk_color_filter[sk_color_filter_key_in_1], static_sk_color_filter[sk_color_filter_key_in_2]);
}

void SkColorFilters_HSLAMatrix(const char *sk_color_filter_key_out, const float rowMajor[20]) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::HSLAMatrix(rowMajor);
}

void SkColorFilters_HSLAMatrix_2(const char *sk_color_filter_key_out, const SkColorMatrix *matrix) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::HSLAMatrix(*matrix);
}

void SkColorFilters_Lerp(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in_1, const char *sk_color_filter_key_in_2, float t) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Lerp(t, static_sk_color_filter[sk_color_filter_key_in_1], static_sk_color_filter[sk_color_filter_key_in_2]);
}

void SkColorFilters_Lighting(const char *sk_color_filter_key_out, SkColor mul, SkColor add) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Lighting(mul, add);
}

void SkColorFilters_LinearToSRGBGamma(const char *sk_color_filter_key_out) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::LinearToSRGBGamma();
}

void SkColorFilters_Matrix(const char *sk_color_filter_key_out, const float rowMajor[20]) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Matrix(rowMajor);
}

void SkColorFilters_Matrix_2(const char *sk_color_filter_key_out, const SkColorMatrix *matrix) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Matrix(*matrix);
}

void SkColorFilters_SRGBToLinearGamma(const char *sk_color_filter_key_out) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::SRGBToLinearGamma();
}

void SkColorFilters_Table(const char *sk_color_filter_key_out, const uint8_t table[256]) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Table(table);
}

void SkColorFilters_Table_2(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in, const char *sk_color_table_key) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::Table(static_sk_color_table[sk_color_filter_key_in]);
}

void SkColorFilters_TableARGB(const char *sk_color_filter_key_out, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorFilters::TableARGB(tableA, tableR, tableG, tableB);
}

//
// SkColorInfo
//

SkColorInfo *SkColorInfo_new() {
    return new SkColorInfo();
}

SkColorInfo *SkColorInfo_new_2(const char *sk_color_space_key_in, SkColorType ct, SkAlphaType at) {
    return new SkColorInfo(ct, at, static_sk_color_space[sk_color_space_key_in]);
}

SkColorInfo *SkColorInfo_new_3(const SkColorInfo *color_info) {
    return new SkColorInfo(*color_info);
}

// SkColorInfo *SkColorInfo_new_4(SkColorInfo &&color_info) {}

void SkColorInfo_delete(SkColorInfo *color_info) {
    delete color_info;
}

SkAlphaType SkColorInfo_alphaType(SkColorInfo *color_info) {
    return color_info->alphaType();
}

int SkColorInfo_bytesPerPixel(SkColorInfo *color_info) {
    return color_info->bytesPerPixel();
}

SkColorSpace* SkColorInfo_colorSpace(SkColorInfo *color_info) {
    return color_info->colorSpace();
}

SkColorType SkColorInfo_colorType(SkColorInfo *color_info) {
    return color_info->colorType();
}

bool SkColorInfo_gammaCloseToSRGB(SkColorInfo *color_info) {
    return color_info->gammaCloseToSRGB();
}

bool SkColorInfo_isOpaque(SkColorInfo *color_info) {
    return color_info->isOpaque();
}

SkColorInfo SkColorInfo_makeAlphaType(SkColorInfo *color_info, SkAlphaType newAlphaType) {
    return color_info->makeAlphaType(newAlphaType);
}

SkColorInfo SkColorInfo_makeColorSpace(const char *sk_color_space_key_in, SkColorInfo *color_info) {
    return color_info->makeColorSpace(static_sk_color_space[sk_color_space_key_in]);
}

SkColorInfo SkColorInfo_makeColorType(SkColorInfo *color_info, SkColorType newColorType) {
    return color_info->makeColorType(newColorType);
}

void SkColorInfo_refColorSpace(const char *sk_color_space_key_out, SkColorInfo *color_info) {
    static_sk_color_space[sk_color_space_key_out] = color_info->refColorSpace();
}

int SkColorInfo_shiftPerPixel(SkColorInfo *color_info) {
    return color_info->shiftPerPixel();
}

//
// SkColorMatrix
//

SkColorMatrix *SkColorMatrix_new() {
    return new SkColorMatrix();
}

SkColorMatrix *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34) {
    return new SkColorMatrix(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34);
}

void SkColorMatrix_setIdentity(SkColorMatrix *color_matrix) {
    color_matrix->setIdentity();
}

void SkColorMatrix_setScale(SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale) {
    color_matrix->setScale(rScale, gScale, bScale, aScale);
}

void SkColorMatrix_postTranslate(SkColorMatrix *color_matrix, float dr, float dg, float db, float da) {
    color_matrix->postTranslate(dr, dg, db, da);
}

void SkColorMatrix_setConcat(SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b) {
    color_matrix->setConcat(*a, *b);
}

void SkColorMatrix_preConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->preConcat(*mat);
}

void SkColorMatrix_postConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->postConcat(*mat);
}

void SkColorMatrix_setSaturation(SkColorMatrix *color_matrix, float sat) {
    color_matrix->setSaturation(sat);
}

void SkColorMatrix_setRowMajor(SkColorMatrix *color_matrix, const float src[20]) {
    color_matrix->setRowMajor(src);
}

void SkColorMatrix_getRowMajor(SkColorMatrix *color_matrix, float dst[20]) {
    color_matrix->getRowMajor(dst);
}

// static

SkColorMatrix SkColorMatrix_RGBtoYUV(SkYUVColorSpace color_space) {
    return SkColorMatrix::RGBtoYUV(color_space);
}

SkColorMatrix SkColorMatrix_YUVtoRGB(SkYUVColorSpace color_space) {
    return SkColorMatrix::YUVtoRGB(color_space);
}

//
// SkColorMatrixFilter
//

bool SkColorMatrixFilter_asAColorMode(SkColorMatrixFilter *color_matrix_filter, SkColor *color, SkBlendMode *mode) {
    return color_matrix_filter->asAColorMode(color, mode);
}

bool SkColorMatrixFilter_asAColorMatrix(SkColorMatrixFilter *color_matrix_filter, float matrix[20]) {
    return color_matrix_filter->asAColorMatrix(matrix);
}

bool SkColorMatrixFilter_isAlphaUnchanged(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->isAlphaUnchanged();
}

SkColor SkColorMatrixFilter_filterColor(SkColorMatrixFilter *color_matrix_filter, SkColor color) {
    return color_matrix_filter->filterColor(color);
}

SkColor4f SkColorMatrixFilter_filterColor4f(SkColorMatrixFilter *color_matrix_filter, const SkColor4f &srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) {
    return color_matrix_filter->filterColor4f(srcColor, srcCS, dstCS);
}

void SkColorMatrixFilter_makeComposed(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in, SkColorMatrixFilter *color_matrix_filter) {
    static_sk_color_filter[sk_color_filter_key_out] = color_matrix_filter->makeComposed(static_sk_color_filter[sk_color_filter_key_in]);
}

void SkColorMatrixFilter_makeWithWorkingColorSpace(const char *sk_color_filter_key_out, const char *sk_color_space_key_in, SkColorMatrixFilter *color_matrix_filter) {
    static_sk_color_filter[sk_color_filter_key_out] = color_matrix_filter->makeWithWorkingColorSpace(static_sk_color_space[sk_color_space_key_in]);
}

SkColorMatrixFilter::Factory SkColorMatrixFilter_getFactory(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->getFactory();
}

const char * SkColorMatrixFilter_getTypeName(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->getTypeName();
}

void SkColorMatrixFilter_flatten(SkColorMatrixFilter *color_matrix_filter, SkWriteBuffer * write_buffer) {
    color_matrix_filter->flatten(*write_buffer);
}

SkColorMatrixFilter::Type SkColorMatrixFilter_getFlattenableType(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->getFlattenableType();
}

void SkColorMatrixFilter_serialize(const char *sk_data_key_out, SkColorMatrixFilter *color_matrix_filter, const SkSerialProcs *serial_procs) {
    static_sk_data[sk_data_key_out] = color_matrix_filter->serialize(serial_procs);
}

size_t SkColorMatrixFilter_serialize_2(SkColorMatrixFilter *color_matrix_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return color_matrix_filter->serialize(memory, memory_size, serial_procs);
}

bool SkColorMatrixFilter_unique(SkColorMatrixFilter *color_matrix_filter) {
    return color_matrix_filter->unique();
}

void SkColorMatrixFilter_ref(SkColorMatrixFilter *color_matrix_filter) {
    color_matrix_filter->ref();
}

void SkColorMatrixFilter_unref(SkColorMatrixFilter *color_matrix_filter) {
    color_matrix_filter->unref();
}

// static

void SkColorMatrixFilter_MakeLightingFilter(const char *sk_color_filter_key_out, SkColor mul, SkColor add) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorMatrixFilter::MakeLightingFilter(mul, add);
}

void SkColorMatrixFilter_Deserialize(const char *sk_color_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_color_filter[sk_color_filter_key_out] = SkColorMatrixFilter::Deserialize(data, size, procs);
}

SkColorMatrixFilter::Factory SkColorMatrixFilter_NameToFactory(const char name[]) {
    return SkColorMatrixFilter::NameToFactory(name);
}

const char * SkColorMatrixFilter_FactoryToName(SkColorMatrixFilter::Factory factory) {
    return SkColorMatrixFilter::FactoryToName(factory);
}

void SkColorMatrixFilter_Register(const char name[], SkColorMatrixFilter::Factory factory) {
    SkColorMatrixFilter::Register(name, factory);
}

//
// SkColorPriv
//

// static

unsigned SkColorPriv_SkAlpha255To256(U8CPU alpha) {
    return SkAlpha255To256(alpha);
}

uint32_t SkColorPriv_SkAlphaMulQ(uint32_t c, unsigned scale) {
    return SkAlphaMulQ(c, scale);
}

SkPMColor SkColorPriv_SkPackARGB32(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPackARGB32(a, r, g, b);
}

SkPMColor SkColorPriv_SkPackARGB32NoCheck(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPackARGB32NoCheck(a, r, g, b);
}

SkPMColor SkColorPriv_SkPMSrcOver(SkPMColor src, SkPMColor dst) {
    return SkPMSrcOver(src, dst);
}

SkPMColor SkColorPriv_SkPremultiplyARGBInline(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPremultiplyARGBInline(a, r, g, b);
}

U8CPU SkColorPriv_SkUnitScalarClampToByte(SkScalar x) {
    return SkUnitScalarClampToByte(x);
}

//
// SkColorSpace
//

void SkColorSpace_toProfile(SkColorSpace *color_space, skcms_ICCProfile *profile) {
    color_space->toProfile(profile);
}

bool SkColorSpace_gammaCloseToSRGB(SkColorSpace *color_space) {
    return color_space->gammaCloseToSRGB();
}

bool SkColorSpace_gammaIsLinear(SkColorSpace *color_space) {
    return color_space->gammaIsLinear();
}

bool SkColorSpace_isNumericalTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    return color_space->isNumericalTransferFn(fn);
}

bool SkColorSpace_toXYZD50(SkColorSpace *color_space, skcms_Matrix3x3 *toXYZD50) {
    return color_space->toXYZD50(toXYZD50);
}

uint32_t SkColorSpace_toXYZD50Hash(SkColorSpace *color_space) {
    return color_space->toXYZD50Hash();
}

void SkColorSpace_makeLinearGamma(const char *sk_color_space_key_out, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key_out] = color_space->makeLinearGamma();
}

void SkColorSpace_makeSRGBGamma(const char *sk_color_space_key_out, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key_out] = color_space->makeSRGBGamma();
}

void SkColorSpace_makeColorSpin(const char *sk_color_space_key_out, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key_out] = color_space->makeColorSpin();
}

bool SkColorSpace_isSRGB(SkColorSpace *color_space) {
    return color_space->isSRGB();
}

void SkColorSpace_serialize(const char *sk_data_key_out, SkColorSpace *color_space) {
    static_sk_data[sk_data_key_out] = color_space->serialize();
}

size_t SkColorSpace_writeToMemory(SkColorSpace *color_space, void *memory) {
    return color_space->writeToMemory(memory);
}

void SkColorSpace_transferFn(SkColorSpace *color_space, float gabcdef[7]) {
    color_space->transferFn(gabcdef);
}

void SkColorSpace_transferFn_2(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    color_space->transferFn(fn);
}

void SkColorSpace_invTransferFn(SkColorSpace *color_space, skcms_TransferFunction *fn) {
    color_space->invTransferFn(fn);
}

void SkColorSpace_gamutTransformTo(SkColorSpace *color_space, const SkColorSpace *dst, skcms_Matrix3x3 *src_to_dst) {
    color_space->gamutTransformTo(dst, src_to_dst);
}

uint32_t SkColorSpace_transferFnHash(SkColorSpace *color_space) {
    return color_space->transferFnHash();
}

uint64_t SkColorSpace_hash(SkColorSpace *color_space) {
    return color_space->hash();
}

bool SkColorSpace_unique(SkColorSpace *color_space) {
    return color_space->unique();
}

void SkColorSpace_ref(SkColorSpace *color_space) {
    color_space->ref();
}

void SkColorSpace_unref(SkColorSpace *color_space) {
    color_space->unref();
}

void SkColorSpace_deref(SkColorSpace *color_space) {
    color_space->deref();
}

bool SkColorSpace_refCntGreaterThan(SkColorSpace *color_space, int32_t threadIsolatedTestCnt) {
    return color_space->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

void SkColorSpace_MakeSRGB(const char *sk_color_space_key_out) {
    static_sk_color_space[sk_color_space_key_out] = SkColorSpace::MakeSRGB();
}

void SkColorSpace_MakeSRGBLinear(const char *sk_color_space_key_out) {
    static_sk_color_space[sk_color_space_key_out] = SkColorSpace::MakeSRGBLinear();
}

void SkColorSpace_MakeRGB(const char *sk_color_space_key_out, const skcms_TransferFunction *transferFn, const skcms_Matrix3x3 *toXYZ) {
    static_sk_color_space[sk_color_space_key_out] = SkColorSpace::MakeRGB(*transferFn, *toXYZ);
}

void SkColorSpace_Make(const char *sk_color_space_key_out, const skcms_ICCProfile * profile) {
    static_sk_color_space[sk_color_space_key_out] = SkColorSpace::Make(*profile);
}

void SkColorSpace_Deserialize(const char *sk_color_space_key_out, const void *data, size_t length) {
    static_sk_color_space[sk_color_space_key_out] = SkColorSpace::Deserialize(data, length);
}

bool SkColorSpace_Equals(SkColorSpace *color_space_1, const SkColorSpace *color_space_2) {
    return SkColorSpace::Equals(color_space_1, color_space_2);
}

//
// SkColorSpacePrimaries
//

void SkColorSpacePrimaries_toXYZD50(SkColorSpacePrimaries *color_pace_primaries, skcms_Matrix3x3 *toXYZD50) {
    color_pace_primaries->toXYZD50(toXYZD50);
}

//
// SkColorTable
//

const uint8_t * SkColorTable_alphaTable(SkColorTable *color_table) {
    return color_table->alphaTable();
}

const uint8_t * SkColorTable_redTable(SkColorTable *color_table) {
    return color_table->redTable();
}

const uint8_t * SkColorTable_greenTable(SkColorTable *color_table) {
    return color_table->greenTable();
}

const uint8_t * SkColorTable_blueTable(SkColorTable *color_table) {
    return color_table->blueTable();
}

void SkColorTable_flatten(SkColorTable *color_table, SkWriteBuffer *buffer) {
    color_table->flatten(*buffer);
}

bool SkColorTable_unique(SkColorTable *color_table) {
    return color_table->unique();
}

void SkColorTable_ref(SkColorTable *color_table) {
    return color_table->ref();
}

void SkColorTable_unref(SkColorTable *color_table) {
    color_table->unref();
}

// static

void SkColorTable_Make(const char *sk_color_table_key_out, const uint8_t table[256]) {
    static_sk_color_table[sk_color_table_key_out] = SkColorTable::Make(table);
}

void SkColorTable_Make_2(const char *sk_color_table_key_out, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    static_sk_color_table[sk_color_table_key_out] = SkColorTable::Make(tableA, tableR, tableG, tableB);
}

void SkColorTable_Deserialize(const char *sk_color_table_key_out, SkReadBuffer *buffer) {
    static_sk_color_table[sk_color_table_key_out] = SkColorTable::Deserialize(*buffer);
}

//
// SkContourMeasure
//

SkScalar SkContourMeasure_length(SkContourMeasure *contour_measure) {
    return contour_measure->length();
}

bool SkContourMeasure_getPosTan(SkContourMeasure *contour_measure, SkScalar distance, SkPoint *position, SkVector *tangent) {
    return contour_measure->getPosTan(distance, position, tangent);
}

bool SkContourMeasure_getMatrix(SkContourMeasure *contour_measure, SkScalar distance, SkMatrix *matrix, SkContourMeasure::MatrixFlags flags) {
    return contour_measure->getMatrix(distance, matrix, flags);
}

bool SkContourMeasure_getSegment(SkContourMeasure *contour_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) {
    return contour_measure->getSegment(startD, stopD, dst, startWithMoveTo);
}

bool SkContourMeasure_isClosed(SkContourMeasure *contour_measure) {
    return contour_measure->isClosed();
}

bool SkContourMeasure_unique(SkContourMeasure *contour_measure) {
    return contour_measure->unique();
}

void SkContourMeasure_ref(SkContourMeasure *contour_measure) {
    contour_measure->ref();
}

void SkContourMeasure_unref(SkContourMeasure *contour_measure) {
    contour_measure->unref();
}

//
// SkContourMeasureIter
//

SkContourMeasureIter *SkContourMeasureIter_new() {
    return new SkContourMeasureIter();
}

SkContourMeasureIter *SkContourMeasureIter_new_2(const SkPath *path, bool forceClosed, SkScalar resScale) {
    return new SkContourMeasureIter(*path, forceClosed, resScale);
}

// SkContourMeasureIter *SkContourMeasureIter_new_3(SkContourMeasureIter &&contour_measure_iter) {
//    return new SkContourMeasureIter(contour_measure_iter);
//}

void SkContourMeasureIter_delete(SkContourMeasureIter *contour_measure_iter) {
    delete contour_measure_iter;
}

void SkContourMeasureIter_reset(SkContourMeasureIter *contour_measure_iter, const SkPath *path, bool forceClosed, SkScalar resScale) {
    contour_measure_iter->reset(*path, forceClosed, resScale);
}

void SkContourMeasureIter_next(const char* sk_contour_measure_key_out, SkContourMeasureIter *contour_measure_iter) {
    static_sk_contour_measure[sk_contour_measure_key_out] = contour_measure_iter->next();
}

//
// SkCornerPathEffect
//

// static

void SkCornerPathEffect_Make(const char *sk_path_effect_key_out, SkScalar radius) {
    static_sk_path_effect[sk_path_effect_key_out] = SkCornerPathEffect::Make(radius);
}

void SkCornerPathEffect_RegisterFlattenables() {
    SkCornerPathEffect::RegisterFlattenables();
}

//
// SkCubicMap
//

SkCubicMap *SkCubicMap_new(SkPoint p1, SkPoint p2) {
    return new SkCubicMap(p1, p2);
}

float SkCubicMap_computeYFromX(SkCubicMap * cubic_map, float x) {
    return cubic_map->computeYFromX(x);
}

SkPoint SkCubicMap_computeFromT(SkCubicMap * cubic_map, float t) {
    return cubic_map->computeFromT(t);
}

// static

bool SkCubicMap_IsLinear(SkPoint p1, SkPoint p2) {
    return SkCubicMap::IsLinear(p1, p2);
}

//
// SkCubicResampler
//

SkCubicResampler SkCubicResampler_Mitchell() {
    return SkCubicResampler::Mitchell();
}

SkCubicResampler SkCubicResampler_CatmullRom() {
    return SkCubicResampler::CatmullRom();
}

//
// SkDashPathEffect
//

void SkDashPathEffect_Make(const char *sk_path_effect_key_out, const SkScalar intervals[], int count, SkScalar phase) {
    static_sk_path_effect[sk_path_effect_key_out] = SkDashPathEffect::Make(intervals, count, phase);
}

//
// SkData
//

size_t size(SkData *sk_data) {
    return sk_data->size();
}

bool isEmpty(SkData *sk_data) {
    return sk_data->isEmpty();
}

const void * data(SkData *sk_data) {
    return sk_data->data();
}

const uint8_t * bytes(SkData *sk_data) {
    return sk_data->bytes();
}

void * writable_data(SkData *sk_data) {
    return sk_data->writable_data();
}

size_t copyRange(SkData *sk_data, size_t offset, size_t length, void *buffer) {
    return sk_data->copyRange(offset, length, buffer);
}

bool equals(SkData *sk_data, const SkData *other) {
    return sk_data->equals(other);
}

bool unique(SkData *sk_data) {
    return sk_data->unique();
}

void ref(SkData *sk_data) {
    return sk_data->ref();
}

void unref(SkData *sk_data) {
    sk_data->unref();
}

void deref(SkData *sk_data) {
    sk_data->deref();
}

bool refCntGreaterThan(SkData *sk_data, int32_t threadIsolatedTestCnt) {
    return sk_data->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

void SkData_MakeWithCopy(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeWithCopy(data, length);
}

void SkData_MakeUninitialized(const char *sk_data_key_out, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeUninitialized(length);
}

void SkData_MakeZeroInitialized(const char *sk_data_key_out, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeZeroInitialized(length);
}

void SkData_MakeWithCString(const char *sk_data_key_out, const char cstr[]) {
    static_sk_data[sk_data_key_out] = SkData::MakeWithCString(cstr);
}

void SkData_MakeWithProc(const char *sk_data_key_out, const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) {
    static_sk_data[sk_data_key_out] = SkData::MakeWithProc(ptr, length, proc, ctx);
}

void SkData_MakeWithoutCopy(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeWithoutCopy(data, length);
}

void SkData_MakeFromMalloc(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeFromMalloc(data, length);
}

void SkData_MakeFromFileName(const char *sk_data_key_out, const char path[]) {
    static_sk_data[sk_data_key_out] = SkData::MakeFromFileName(path);
}

void SkData_MakeFromFILE(const char *sk_data_key_out, FILE *f) {
    static_sk_data[sk_data_key_out] = SkData::MakeFromFILE(f);
}

void SkData_MakeFromFD(const char *sk_data_key_out, int fd) {
    static_sk_data[sk_data_key_out] = SkData::MakeFromFD(fd);
}

void SkData_MakeFromStream(const char *sk_data_key_out, SkStream * stream, size_t size) {
    static_sk_data[sk_data_key_out] = SkData::MakeFromStream(stream, size);
}

void SkData_MakeSubset(const char *sk_data_key_out, const SkData *src, size_t offset, size_t length) {
    static_sk_data[sk_data_key_out] = SkData::MakeSubset(src, offset, length);
}

void SkData_MakeEmpty(const char *sk_data_key_out) {
    static_sk_data[sk_data_key_out] = SkData::MakeEmpty();
}

//
// SkDataTable
//

bool SkDataTable_isEmpty(SkDataTable *data_table) {
    return data_table->isEmpty();
}

int SkDataTable_count(SkDataTable *data_table) {
    return data_table->count();
}

size_t SkDataTable_atSize(SkDataTable *data_table, int index) {
    return data_table->atSize(index);
}

const void * SkDataTable_at(SkDataTable *data_table, int index, size_t *size) {
    return data_table->at(index, size);
}

// template<typename T>
// const T * SkDataTable_atT(int index, size_t *size=nullptr) const

const char * SkDataTable_atStr(SkDataTable *data_table, int index) {
    return data_table->atStr(index);
}

bool SkDataTable_unique(SkDataTable *data_table) {
    return data_table->unique();
}

void SkDataTable_ref(SkDataTable *data_table) {
    data_table->ref();
}

void SkDataTable_unref(SkDataTable *data_table) {
    data_table->unref();
}

// static

void SkDataTable_MakeEmpty(const char *sk_data_table_key_out) {
    static_sk_data_table[sk_data_table_key_out] = SkDataTable::MakeEmpty();
}

void SkDataTable_MakeCopyArrays(const char *sk_data_table_key_out, const void *const *ptrs, const size_t sizes[], int count) {
    static_sk_data_table[sk_data_table_key_out] = SkDataTable::MakeCopyArrays(ptrs, sizes, count);
}

void SkDataTable_MakeCopyArray(const char *sk_data_table_key_out, const void *array, size_t elemSize, int count) {
    static_sk_data_table[sk_data_table_key_out] = SkDataTable::MakeCopyArray(array, elemSize, count);
}

void SkDataTable_MakeArrayProc(const char *sk_data_table_key_out, const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context) {
    static_sk_data_table[sk_data_table_key_out] = SkDataTable::MakeArrayProc(array, elemSize, count, proc, context);
}

//
// SkDiscretePathEffect
//

void SkDiscretePathEffect_Make(const char *sk_path_effect_key_out, SkScalar segLength, SkScalar dev, uint32_t seedAssist) {
    static_sk_path_effect[sk_path_effect_key_out] = SkDiscretePathEffect::Make(segLength, dev, seedAssist);
}

void SkDiscretePathEffect_RegisterFlattenables() {
    SkDiscretePathEffect::RegisterFlattenables();
}

//
// SkDocument (abstract)
//

SkCanvas * SkDocument_beginPage(SkDocument * document, SkScalar width, SkScalar height, const SkRect *content) {
    return document->beginPage(width, height, content);
}

void SkDocument_endPage(SkDocument *document) {
    document->endPage();
}
void SkDocument_close(SkDocument *document) {
    document->close();
}
void SkDocument_abort(SkDocument *document) {
    document->abort();
}
bool SkDocument_unique(SkDocument *document) {
    return document->unique();
}
void SkDocument_ref(SkDocument *document) {
    document->ref();
}
void SkDocument_unref(SkDocument *document) {
    document->unref();
}

//
// SkDrawable
//

void SkDrawable_draw(SkDrawable *drawable, SkCanvas * canvas, const SkMatrix * matrix) {
    drawable->draw(canvas, matrix);
}

void SkDrawable_draw_2(SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y) {
    drawable->draw(canvas, x, y);
}

void SkDrawable_snapGpuDrawHandler(const char *gpu_draw_handler_key_out, SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) {
    static_gpu_draw_handler[gpu_draw_handler_key_out] = drawable->snapGpuDrawHandler(backendApi, *matrix, *clipBounds, *bufferInfo);
}

void SkDrawable_makePictureSnapshot(const char *sk_picture_key_out, SkDrawable *drawable) {
    static_sk_picture[sk_picture_key_out] = drawable->makePictureSnapshot();
}

uint32_t SkDrawable_getGenerationID(SkDrawable *drawable) {
    return drawable->getGenerationID();
}

SkRect SkDrawable_getBounds(SkDrawable *drawable) {
    return drawable->getBounds();
}

size_t SkDrawable_approximateBytesUsed(SkDrawable *drawable) {
    return drawable->approximateBytesUsed();
}

void SkDrawable_notifyDrawingChanged(SkDrawable *drawable) {
    drawable->notifyDrawingChanged();
}

SkFlattenable::Type SkDrawable_getFlattenableType(SkDrawable *drawable) {
    return drawable->getFlattenableType();
}

SkDrawable::Factory SkDrawable_getFactory(SkDrawable *drawable) {
    return drawable->getFactory();
}

const char * SkDrawable_getTypeName(SkDrawable *drawable) {
    return drawable->getTypeName();
}

void SkDrawable_flatten(SkDrawable *drawable, SkWriteBuffer *write_buffer) {
    drawable->flatten(*write_buffer);
}

void SkDrawable_serialize(const char *sk_data_key_out, SkDrawable *drawable, const SkSerialProcs *serial_procs) {
    static_sk_data[sk_data_key_out] = drawable->serialize(serial_procs);
}

size_t SkDrawable_serialize_2(SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
    return drawable->serialize(memory, memory_size, serial_procs);
}

bool SkDrawable_unique(SkDrawable *drawable) {
    return drawable->unique();
}

void SkDrawable_ref(SkDrawable *drawable) {
    drawable->ref();
}

void SkDrawable_unref(SkDrawable *drawable) {
    drawable->unref();
}

// static

SkFlattenable::Type SkDrawable_GetFlattenableType() {
    return SkDrawable::GetFlattenableType();
}

void SkDrawable_Deserialize(const char *sk_drawable_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_drawable[sk_drawable_key_out] = SkDrawable::Deserialize(data, size, procs);
}

SkDrawable::Factory SkDrawable_NameToFactory(const char name[]) {
    return SkDrawable::NameToFactory(name);
}

const char * SkDrawable_FactoryToName(SkDrawable::Factory factory) {
    return SkDrawable::FactoryToName(factory);
}

void SkDrawable_Register(const char name[], SkDrawable::Factory factory) {
    SkDrawable::Register(name, factory);
}

//
// SkDrawLooper
//

//SkDrawLooper::Context * SkDrawLooper_makeContext(SkDrawLooper *draw_looper, SkArenaAlloc *arena_alloc) {
//    return draw_looper->makeContext(arena_alloc);
//}
//
//bool SkDrawLooper_canComputeFastBounds(SkDrawLooper *draw_looper, const SkPaint *paint) {
//    return draw_looper->canComputeFastBounds(*paint);
//}
//
//void SkDrawLooper_computeFastBounds(SkDrawLooper *draw_looper, const SkPaint *paint, const SkRect *src, SkRect *dst) {
//    draw_looper->computeFastBounds(*paint, *src, dst);
//}
//
//bool SkDrawLooper_asABlurShadow(SkDrawLooper *draw_looper, SkDrawLooper::BlurShadowRec *blur_shadow_rec) {
//    return draw_looper->asABlurShadow(blur_shadow_rec);
//}
//
//SkFlattenable::Type SkDrawLooper_getFlattenableType(SkDrawLooper *draw_looper) {
//    return draw_looper->getFlattenableType();
//}
//
//void SkDrawLooper_apply(SkDrawLooper *draw_looper, SkCanvas *canvas, const SkPaint *paint, std::function< void(SkCanvas *, const SkPaint &)> fn) { // @TODO
//    draw_looper->apply(canvas, *paint, std::move(fn));
//}
//
//SkDrawLooper::Factory SkDrawLooper_getFactory(SkDrawLooper *draw_looper) {
//    return draw_looper->getFactory();
//}
//
//const char * SkDrawLooper_getTypeName(SkDrawLooper *draw_looper) {
//    return draw_looper->getTypeName();
//}
//
//void SkDrawLooper_flatten(SkDrawLooper *draw_looper, SkWriteBuffer *write_buffer) {
//    draw_looper->flatten(*write_buffer);
//}
//
//void SkDrawLooper_serialize(const char *sk_data_key_out, SkDrawLooper *draw_looper, const SkSerialProcs *serial_procs) {
//    static_sk_data[sk_data_key_out] = draw_looper->serialize(serial_procs);
//}
//
//size_t SkDrawLooper_serialize_2(SkDrawLooper *draw_looper, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) {
//    return draw_looper->serialize(memory, memory_size, serial_procs);
//}
//
//bool SkDrawLooper_unique(SkDrawLooper *draw_looper) {
//    return draw_looper->unique();
//}
//
//void SkDrawLooper_ref(SkDrawLooper *draw_looper) {
//    draw_looper->ref();
//}
//
//void SkDrawLooper_unref(SkDrawLooper *draw_looper) {
//    draw_looper->unref();
//}

// static

//SkFlattenable::Type SkDrawLooper_GetFlattenableType() {
//    return SkDrawLooper::GetFlattenableType();
//}
//
//void SkDrawLooper_Deserialize(const char *sk_draw_looper_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
//    static_sk_draw_looper[sk_draw_looper_key_out] = SkDrawLooper::Deserialize(data, size, procs);
//}
//
//SkDrawLooper::Factory SkDrawLooper_NameToFactory(const char name[]) {
//    SkDrawLooper::NameToFactory(name);
//}
//
//const char * SkDrawLooper_FactoryToName(SkDrawLooper::Factory factory) {
//    return SkDrawLooper::FactoryToName(factory);
//}
//
//void SkDrawLooper_Register(const char name[], SkDrawLooper::Factory factory) {
//    SkDrawLooper::Register(name, factory);
//}

//
// SkDynamicMemoryWStream
//

SkDynamicMemoryWStream *SkDynamicMemoryWStream_new() {
    return new SkDynamicMemoryWStream();
}

//SkDynamicMemoryWStream * SkDynamicMemoryWStream_new_2(SkDynamicMemoryWStream *stream) {
//    return new SkDynamicMemoryWStream(stream);
//}

void SkDynamicMemoryWStream_delete(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    delete dynamic_memory_w_stream;
}

bool SkDynamicMemoryWStream_write(SkDynamicMemoryWStream *dynamic_memory_w_stream, const void *buffer, size_t size) {
    return dynamic_memory_w_stream->write(buffer, size);
}

size_t SkDynamicMemoryWStream_bytesWritten(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return dynamic_memory_w_stream->bytesWritten();
}

bool SkDynamicMemoryWStream_read(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size) {
    return dynamic_memory_w_stream->read(buffer, offset, size);
}

void SkDynamicMemoryWStream_copyTo(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst) {
    return dynamic_memory_w_stream->copyTo(dst);
}

bool SkDynamicMemoryWStream_writeToStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) {
    return dynamic_memory_w_stream->writeToStream(dst);
}

void SkDynamicMemoryWStream_copyToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst) {
    return dynamic_memory_w_stream->copyToAndReset(dst);
}

bool SkDynamicMemoryWStream_writeToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) {
    return dynamic_memory_w_stream->writeToAndReset(dst);
}

bool SkDynamicMemoryWStream_writeToAndReset_2(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst) {
    return dynamic_memory_w_stream->writeToAndReset(dst);
}

void SkDynamicMemoryWStream_prependToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst) {
    dynamic_memory_w_stream->prependToAndReset(dst);
}

void SkDynamicMemoryWStream_detachAsData(const char *sk_data_key_out, SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    static_sk_data[sk_data_key_out] = dynamic_memory_w_stream->detachAsData();
}

void SkDynamicMemoryWStream_detachAsStream(const char *sk_stream_asset_key_out, SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    static_sk_stream_asset[sk_stream_asset_key_out] = dynamic_memory_w_stream->detachAsStream();
}

void SkDynamicMemoryWStream_reset(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->reset();
}

void SkDynamicMemoryWStream_padToAlign4(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->padToAlign4();
}

void SkDynamicMemoryWStream_flush(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->flush();
}

bool SkDynamicMemoryWStream_write8(SkDynamicMemoryWStream *dynamic_memory_w_stream, U8CPU value) {
    return dynamic_memory_w_stream->write8(value);
}

bool SkDynamicMemoryWStream_write16(SkDynamicMemoryWStream *dynamic_memory_w_stream, U16CPU value) {
    return dynamic_memory_w_stream->write16(value);
}

bool SkDynamicMemoryWStream_write32(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v) {
    return dynamic_memory_w_stream->write32(v);
}

bool SkDynamicMemoryWStream_writeText(SkDynamicMemoryWStream *dynamic_memory_w_stream, const char text[]) {
    return dynamic_memory_w_stream->writeText(text);
}

bool SkDynamicMemoryWStream_newline(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return dynamic_memory_w_stream->newline();
}

bool SkDynamicMemoryWStream_writeDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int32_t v) {
    return dynamic_memory_w_stream->writeDecAsText(v);
}

bool SkDynamicMemoryWStream_writeBigDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int64_t v, int minDigits) {
    return dynamic_memory_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkDynamicMemoryWStream_writeHexAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v, int minDigits) {
    return dynamic_memory_w_stream->writeHexAsText(v, minDigits);
}

bool SkDynamicMemoryWStream_writeScalarAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) {
    return dynamic_memory_w_stream->writeScalarAsText(scalar);
}

bool SkDynamicMemoryWStream_writeBool(SkDynamicMemoryWStream *dynamic_memory_w_stream, bool v) {
    return dynamic_memory_w_stream->writeBool(v);
}

bool SkDynamicMemoryWStream_writeScalar(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) {
    return dynamic_memory_w_stream->writeScalar(scalar);
}

bool SkDynamicMemoryWStream_writePackedUInt(SkDynamicMemoryWStream *dynamic_memory_w_stream, size_t length) {
    return dynamic_memory_w_stream->writePackedUInt(length);
}

bool SkDynamicMemoryWStream_writeStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkStream *input, size_t length) {
    return dynamic_memory_w_stream->writeStream(input, length);
}

// static

int SkDynamicMemoryWStream_SizeOfPackedUInt(size_t value) {
    return SkDynamicMemoryWStream::SizeOfPackedUInt(value);
}

//
// SkExecutor
//

void SkExecutor_add(SkExecutor *executor, std::function< void(void)> fn) { // @TODO
    executor->add(std::move(fn));
}

void SkExecutor_borrow(SkExecutor *executor) {
    executor->borrow();
}

// static

void SkExecutor_MakeFIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor[sk_executor_key_out] = SkExecutor::MakeFIFOThreadPool(threads, allowBorrowing);
}

void SkExecutor_MakeLIFOThreadPool(const char *sk_executor_key_out, int threads, bool allowBorrowing) {
    static_sk_executor[sk_executor_key_out] = SkExecutor::MakeLIFOThreadPool(threads, allowBorrowing);
}

SkExecutor & SkExecutor_GetDefault() { // @TODO
    return SkExecutor::GetDefault();
}

void SkExecutor_SetDefault(SkExecutor * executor) {
    SkExecutor::SetDefault(executor);
}

//
// SkFILEStream
//

SkFILEStream *SkFILEStream_new(const char path[]) {
    return new SkFILEStream(path);
}

SkFILEStream *SkFILEStream_new_2(FILE *file) {
    return new SkFILEStream(file);
}

SkFILEStream *SkFILEStream_new_3(FILE *file, size_t size) {
    return new SkFILEStream(file, size);
}

void SkFILEStream_delete(SkFILEStream *file_stream) {
    delete file_stream;
}

bool SkFILEStream_isValid(SkFILEStream *file_stream) {
    return file_stream->isValid();
}

void SkFILEStream_close(SkFILEStream *file_stream) {
    file_stream->close();
}

size_t SkFILEStream_read(SkFILEStream *file_stream, void *buffer, size_t size) {
    return file_stream->read(buffer, size);
}

bool SkFILEStream_isAtEnd(SkFILEStream *file_stream) {
    return file_stream->isAtEnd();
}

bool SkFILEStream_rewind(SkFILEStream *file_stream) {
    return file_stream->rewind();
}

void SkFILEStream_duplicate(const char *sk_stream_asset_key_out, SkFILEStream *file_stream) {
    static_sk_stream_asset[sk_stream_asset_key_out] = file_stream->duplicate();
}

size_t SkFILEStream_getPosition(SkFILEStream *file_stream) {
    return file_stream->getPosition();
}

bool SkFILEStream_seek(SkFILEStream *file_stream, size_t position) {
    return file_stream->seek(position);
}

bool SkFILEStream_move(SkFILEStream *file_stream, long offset) {
    return file_stream->move(offset);
}

void SkFILEStream_fork(const char *sk_stream_asset_key_out, SkFILEStream *file_stream) {
    static_sk_stream_asset[sk_stream_asset_key_out] = file_stream->fork();
}

size_t SkFILEStream_getLength(SkFILEStream *file_stream) {
    return file_stream->getLength();
}

bool SkFILEStream_hasLength(SkFILEStream *file_stream) {
    return file_stream->hasLength();
}

bool SkFILEStream_hasPosition(SkFILEStream *file_stream) {
    return file_stream->hasPosition();
}

size_t SkFILEStream_skip(SkFILEStream *file_stream, size_t size) {
    return file_stream->skip(size);
}

size_t SkFILEStream_peek(SkFILEStream *file_stream, void *ptr, size_t size) {
    return file_stream->peek(ptr, size);
}

bool SkFILEStream_readS8(SkFILEStream *file_stream, int8_t *i) {
    return file_stream->readS8(i);
}

bool SkFILEStream_readS16(SkFILEStream *file_stream, int16_t *i) {
    return file_stream->readS16(i);
}

bool SkFILEStream_readS32(SkFILEStream *file_stream, int32_t *i) {
    return file_stream->readS32(i);
}

bool SkFILEStream_readU8(SkFILEStream *file_stream, uint8_t *i) {
    return file_stream->readU8(i);
}

bool SkFILEStream_readU16(SkFILEStream *file_stream, uint16_t *i) {
    return file_stream->readU16(i);
}

bool SkFILEStream_readU32(SkFILEStream *file_stream, uint32_t *i) {
    return file_stream->readU32(i);
}

bool SkFILEStream_readBool(SkFILEStream *file_stream, bool *b) {
    return file_stream->readBool(b);
}

bool SkFILEStream_readScalar(SkFILEStream *file_stream, SkScalar *scalar) {
    return file_stream->readScalar(scalar);
}

bool SkFILEStream_readPackedUInt(SkFILEStream *file_stream, size_t *size) {
    return file_stream->readPackedUInt(size);
}

const void * SkFILEStream_getMemoryBase(SkFILEStream *file_stream) {
    return file_stream->getMemoryBase();
}

// static

void SkFILEStream_Make(const char *sk_file_stream_key_out, const char path[]) {
    static_sk_file_stream[sk_file_stream_key_out] = SkFILEStream::Make(path);
}

//
// SkFILEWStream
//

SkFILEWStream *SkFILEWStream_new(const char path[]) {
    return new SkFILEWStream(path);
}

void SkFILEWStream_delete(SkFILEWStream *file_w_stream) {
    delete file_w_stream;
}

bool SkFILEWStream_isValid(SkFILEWStream *file_w_stream) {
    return file_w_stream->isValid();
}

bool SkFILEWStream_write(SkFILEWStream *file_w_stream, const void *buffer, size_t size) {
    return file_w_stream->write(buffer, size);
}

void SkFILEWStream_flush(SkFILEWStream *file_w_stream) {
    file_w_stream->flush();
}

void SkFILEWStream_fsync(SkFILEWStream *file_w_stream) {
    return file_w_stream->fsync();
}

size_t SkFILEWStream_bytesWritten(SkFILEWStream *file_w_stream) {
    return file_w_stream->bytesWritten();
}

bool SkFILEWStream_write8(SkFILEWStream *file_w_stream, U8CPU value) {
    return file_w_stream->write8(value);
}

bool SkFILEWStream_write16(SkFILEWStream *file_w_stream, U16CPU value) {
    return file_w_stream->write16(value);
}

bool SkFILEWStream_write32(SkFILEWStream *file_w_stream, uint32_t v) {
    return file_w_stream->write32(v);
}

bool SkFILEWStream_writeText(SkFILEWStream *file_w_stream, const char text[]) {
    return file_w_stream->writeText(text);
}

bool SkFILEWStream_newline(SkFILEWStream *file_w_stream) {
    return file_w_stream->newline();
}

bool SkFILEWStream_writeDecAsText(SkFILEWStream *file_w_stream, int32_t v) {
    return file_w_stream->writeDecAsText(v);
}

bool SkFILEWStream_writeBigDecAsText(SkFILEWStream *file_w_stream, int64_t v, int minDigits) {
    return file_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkFILEWStream_writeHexAsText(SkFILEWStream *file_w_stream, uint32_t v, int minDigits) {
    return file_w_stream->writeHexAsText(v, minDigits);
}

bool SkFILEWStream_writeScalarAsText(SkFILEWStream *file_w_stream, SkScalar scalar) {
    return file_w_stream->writeScalarAsText(scalar);
}

bool SkFILEWStream_writeBool(SkFILEWStream *file_w_stream, bool v) {
    return file_w_stream->writeBool(v);
}

bool SkFILEWStream_writeScalar(SkFILEWStream *file_w_stream, SkScalar scalar) {
    return file_w_stream->writeScalar(scalar);
}

bool SkFILEWStream_writePackedUInt(SkFILEWStream *file_w_stream, size_t size) {
    return file_w_stream->writePackedUInt(size);
}

bool SkFILEWStream_writeStream(SkFILEWStream *file_w_stream, SkStream *input, size_t length) {
    return file_w_stream->writeStream(input, length);
}

// static

int SkFILEWStream_SizeOfPackedUInt(size_t value) {
    return SkFILEWStream::SizeOfPackedUInt(value);
}

//
// SkFlattenable
//

SkFlattenable::Factory SkFlattenable_getFactory(SkFlattenable *flattenable) {
    return flattenable->getFactory();
}

const char * SkFlattenable_getTypeName(SkFlattenable *flattenable) {
    return flattenable->getTypeName();
}

void SkFlattenable_flatten(SkFlattenable *flattenable, SkWriteBuffer * write_buffer) {
    flattenable->flatten(*write_buffer);
}

SkFlattenable::Type SkFlattenable_getFlattenableType(SkFlattenable *flattenable) {
    return flattenable->getFlattenableType();
}

void SkFlattenable_serialize(const char *sk_data_key_out, SkFlattenable *flattenable, const SkSerialProcs * serial_procs) {
    static_sk_data[sk_data_key_out] = flattenable->serialize(serial_procs);
}

size_t SkFlattenable_serialize_2(SkFlattenable *flattenable, void *memory, size_t memory_size, const SkSerialProcs * serial_procs) {
    return flattenable->serialize(memory, memory_size, serial_procs);
}

bool SkFlattenable_unique(SkFlattenable *flattenable) {
    return flattenable->unique();
}

void SkFlattenable_ref(SkFlattenable *flattenable) {
    flattenable->ref();
}

void SkFlattenable_unref(SkFlattenable *flattenable) {
    flattenable->unref();
}

// static

SkFlattenable::Factory SkFlattenable_NameToFactory(const char name[]) {
    return SkFlattenable::NameToFactory(name);
}
const char * SkFlattenable_FactoryToName(SkFlattenable::Factory factory) {
    return SkFlattenable::FactoryToName(factory);
}

void SkFlattenable_Register(const char name[], SkFlattenable::Factory factory) {
    SkFlattenable::Register(name, factory);
}

void SkFlattenable_Deserialize(const char* sk_flattenable_key_out, SkFlattenable::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    static_sk_flattenable[sk_flattenable_key_out] = SkFlattenable::Deserialize(type, data, length, procs);
}

//
// SkFont
//

SkFont *SkFont_new() {
    return new SkFont();
}

SkFont *SkFont_new_2(const char *sk_typeface_key_in, SkScalar size) {
    return new SkFont(static_sk_typeface[sk_typeface_key_in], size);
}

SkFont *SkFont_new_3(const char *sk_typeface_key_in) {
    return new SkFont(static_sk_typeface[sk_typeface_key_in]);
}

SkFont *SkFont_new_4(const char *sk_typeface_key_in, SkScalar size, SkScalar scaleX, SkScalar skewX) {
    return new SkFont(static_sk_typeface[sk_typeface_key_in], size, scaleX, skewX);
}

bool SkFont_isForceAutoHinting(SkFont *font) {
    return font->isForceAutoHinting();
}

bool SkFont_isEmbeddedBitmaps(SkFont *font) {
    return font->isEmbeddedBitmaps();
}

bool SkFont_isSubpixel(SkFont *font) {
    return font->isSubpixel();
}

bool SkFont_isLinearMetrics(SkFont *font) {
    return font->isLinearMetrics();
}

bool SkFont_isEmbolden(SkFont *font) {
    return font->isEmbolden();
}

bool SkFont_isBaselineSnap(SkFont *font) {
    return font->isBaselineSnap();
}

void SkFont_setForceAutoHinting(SkFont *font, bool forceAutoHinting) {
    font->setForceAutoHinting(forceAutoHinting);
}

void SkFont_setEmbeddedBitmaps(SkFont *font, bool embeddedBitmaps) {
    font->setEmbeddedBitmaps(embeddedBitmaps);
}

void SkFont_setSubpixel(SkFont *font, bool subpixel) {
    font->setSubpixel(subpixel);
}

void SkFont_setLinearMetrics(SkFont *font, bool linearMetrics) {
    font->setLinearMetrics(linearMetrics);
}

void SkFont_setEmbolden(SkFont *font, bool embolden) {
    font->setEmbolden(embolden);
}

void SkFont_setBaselineSnap(SkFont *font, bool baselineSnap) {
    font->setBaselineSnap(baselineSnap);
}

SkFont::Edging SkFont_getEdging(SkFont *font) {
    return font->getEdging();
}

void SkFont_setEdging(SkFont *font, SkFont::Edging edging) {
    font->setEdging(edging);
}

void SkFont_setHinting(SkFont *font, SkFontHinting hintingLevel) {
    font->setHinting(hintingLevel);
}

SkFontHinting SkFont_getHinting(SkFont *font) {
    return font->getHinting();
}

SkFont SkFont_makeWithSize(SkFont *font, SkScalar size) {
    return font->makeWithSize(size);
}

SkTypeface * SkFont_getTypeface(SkFont *font) {
    return font->getTypeface();
}

SkScalar SkFont_getSize(SkFont *font) {
    return font->getSize();
}

SkScalar SkFont_getScaleX(SkFont *font) {
    return font->getScaleX();
}

SkScalar SkFont_getSkewX(SkFont *font) {
    return font->getSkewX();
}

void SkFont_refTypeface(const char *sk_typeface_key_out, SkFont *font) {
    static_sk_typeface[sk_typeface_key_out] = font->refTypeface();
}

void SkFont_setTypeface(const char *sk_typeface_key_in, SkFont *font) {
    font->setTypeface(static_sk_typeface[sk_typeface_key_in]);
}

void SkFont_setSize(SkFont *font, SkScalar textSize) {
    font->setSize(textSize);
}

void SkFont_setScaleX(SkFont *font, SkScalar scaleX) {
    font->setScaleX(scaleX);
}

void SkFont_setSkewX(SkFont *font, SkScalar skewX) {
    font->setSkewX(skewX);
}

int SkFont_textToGlyphs(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) {
    return font->textToGlyphs(text, byteLength, encoding, glyphs, maxGlyphCount);
}

SkGlyphID SkFont_unicharToGlyph(SkFont *font, SkUnichar uni) {
    return font->unicharToGlyph(uni);
}

void SkFont_unicharsToGlyphs(SkFont *font, const SkUnichar uni[], int count, SkGlyphID glyphs[]) {
    font->unicharsToGlyphs(uni, count, glyphs);
}

int SkFont_countText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding) {
    return font->countText(text, byteLength, encoding);
}

SkScalar SkFont_measureText(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds) {
    return font->measureText(text, byteLength, encoding, bounds);
}

SkScalar SkFont_measureText_2(SkFont *font, const void *text, size_t byteLength, SkTextEncoding encoding, SkRect *bounds, const SkPaint *paint) {
    return font->measureText(text, byteLength, encoding, bounds, paint);
}

void SkFont_getWidths(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[]) {
    font->getWidths(glyphs, count, widths, bounds);
}

void SkFont_getWidths_2(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], std::nullptr_t ptr) { // @TODO
    font->getWidths(glyphs, count, widths, ptr);
}

void SkFont_getWidths_3(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[]) {
    font->getWidths(glyphs, count, widths);
}

void SkFont_getWidthsBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar widths[], SkRect bounds[], const SkPaint *paint) {
    font->getWidthsBounds(glyphs, count, widths, bounds, paint);
}

void SkFont_getBounds(SkFont *font, const SkGlyphID glyphs[], int count, SkRect bounds[], const SkPaint *paint) {
    font->getBounds(glyphs, count, bounds, paint);
}

void SkFont_getPos(SkFont *font, const SkGlyphID glyphs[], int count, SkPoint pos[], SkPoint origin) {
    font->getPos(glyphs, count, pos, origin);
}

void SkFont_getXPos(SkFont *font, const SkGlyphID glyphs[], int count, SkScalar xpos[], SkScalar origin) {
    font->getXPos(glyphs, count, xpos, origin);
}

std::vector<SkScalar> SkFont_getIntercepts(SkFont *font, const SkGlyphID glyphs[], int count, const SkPoint pos[], SkScalar top, SkScalar bottom, const SkPaint *paint) { // @TODO
    return font->getIntercepts(glyphs, count, pos, top, bottom, paint);
}

bool SkFont_getPath(SkFont *font, SkGlyphID glyphID, SkPath *path) {
    return font->getPath(glyphID, path);
}

void SkFont_getPaths(SkFont *font, const SkGlyphID glyphIDs[], int count, void(*glyphPathProc)(const SkPath *pathOrNull, const SkMatrix &mx, void *ctx), void *ctx) { // @TODO
    font->getPaths(glyphIDs, count, glyphPathProc, ctx);
}

SkScalar SkFont_getMetrics(SkFont *font, SkFontMetrics *metrics) {
    return font->getMetrics(metrics);
}

SkScalar SkFont_getSpacing(SkFont *font) {
    return font->getSpacing();
}

void SkFont_dump(SkFont *font) {
    font->dump();
}

//
// SkFontArguments
//

SkFontArguments *SkFontArguments_new() {
    return new SkFontArguments();
}

SkFontArguments SkFontArguments_setCollectionIndex(SkFontArguments *font_argments, int collectionIndex) {
    return font_argments->setCollectionIndex(collectionIndex);
}

SkFontArguments SkFontArguments_setVariationDesignPosition(SkFontArguments *font_argments, SkFontArguments::VariationPosition position) {
    return font_argments->setVariationDesignPosition(position);
}

int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments) {
    return font_argments->getCollectionIndex();
}

SkFontArguments::VariationPosition SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments) {
    return font_argments->getVariationDesignPosition();
}

SkFontArguments SkFontArguments_setPalette(SkFontArguments *font_argments, SkFontArguments::Palette palette) {
    return font_argments->setPalette(palette);
}

SkFontArguments::Palette SkFontArguments_getPalette(SkFontArguments *font_argments) {
    return font_argments->getPalette();
}

//
// SkFontMetrics
//

bool SkFontMetrics_hasUnderlineThickness(SkFontMetrics *font_metrics, SkScalar *thickness) {
    return font_metrics->hasUnderlineThickness(thickness);
}

bool SkFontMetrics_hasUnderlinePosition(SkFontMetrics *font_metrics, SkScalar *position) {
    return font_metrics->hasUnderlinePosition(position);
}

bool SkFontMetrics_hasStrikeoutThickness(SkFontMetrics *font_metrics, SkScalar *thickness) {
    return font_metrics->hasStrikeoutThickness(thickness);
}

bool SkFontMetrics_hasStrikeoutPosition(SkFontMetrics *font_metrics, SkScalar *position) {
    return font_metrics->hasStrikeoutPosition(position);
}

bool SkFontMetrics_hasBounds(SkFontMetrics *font_metrics) {
    return font_metrics->hasBounds();
}

//
// SkFontMgr
//

int SkFontMgr_countFamilies(SkFontMgr *font_mgr) {
    return font_mgr->countFamilies();
}
void SkFontMgr_getFamilyName(SkFontMgr *font_mgr, int index, SkString *familyName) {
    font_mgr->getFamilyName(index, familyName);
}

void SkFontMgr_createStyleSet(const char *sk_font_style_set_out, SkFontMgr *font_mgr, int index) {
    static_sk_font_style_set[sk_font_style_set_out] = font_mgr->createStyleSet(index);
}

void SkFontMgr_matchFamily(const char *sk_font_style_set_out, SkFontMgr *font_mgr, const char familyName[]) {
    static_sk_font_style_set[sk_font_style_set_out] = font_mgr->matchFamily(familyName);
}

void SkFontMgr_matchFamilyStyle(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style) {
    static_sk_typeface[sk_typeface_key_out] = font_mgr->matchFamilyStyle(familyName, *font_style);
}

void SkFontMgr_matchFamilyStyleCharacter(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], const SkFontStyle *font_style, const char *bcp47[], int bcp47Count, SkUnichar character) {
    static_sk_typeface[sk_typeface_key_out] = font_mgr->matchFamilyStyleCharacter(familyName, *font_style, bcp47, bcp47Count, character);
}

void SkFontMgr_makeFromData(const char *sk_typeface_key_out, const char *sk_data_key_in, SkFontMgr *font_mgr, int ttcIndex) {
    static_sk_typeface[sk_typeface_key_out] = font_mgr->makeFromData(static_sk_data[sk_data_key_in], ttcIndex);
}

// @TODO

//void SkFontMgr_makeFromStream(const char *sk_typeface_key_out, const char *sk_stream_asset_key_in, SkFontMgr *font_mgr, int ttcIndex) {
//    static_sk_typeface[sk_typeface_key_out] = font_mgr->makeFromStream(static_sk_stream_asset[sk_stream_asset_key_in], ttcIndex);
//}

//void SkFontMgr_makeFromStream_2(const char *sk_typeface_key_out, const char *sk_stream_asset_key_in, SkFontMgr *font_mgr, const SkFontArguments *font_argments) {
//    static_sk_typeface[sk_typeface_key_out] = font_mgr->makeFromStream(static_sk_stream_asset[sk_stream_asset_key_in], *font_argments);
//}

void SkFontMgr_makeFromFile(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char path[], int ttcIndex) {
    static_sk_typeface[sk_typeface_key_out] = font_mgr->makeFromFile(path, ttcIndex);
}

void SkFontMgr_legacyMakeTypeface(const char *sk_typeface_key_out, SkFontMgr *font_mgr, const char familyName[], SkFontStyle style) {
    static_sk_typeface[sk_typeface_key_out] = font_mgr->legacyMakeTypeface(familyName, style);
}

bool SkFontMgr_unique(SkFontMgr *font_mgr) {
    return font_mgr->unique();
}

void SkFontMgr_ref(SkFontMgr *font_mgr) {
    font_mgr->ref();
}

void SkFontMgr_unref(SkFontMgr *font_mgr) {
    font_mgr->unref();
}

// static

void SkFontMgr_RefDefault(const char *sk_font_mgr_key_out) {
    static_sk_font_mgr[sk_font_mgr_key_out] = SkFontMgr::RefDefault();
}

void SkFontMgr_RefEmpty(const char *sk_font_mgr_key_out) {
    static_sk_font_mgr[sk_font_mgr_key_out] = SkFontMgr::RefEmpty();
}

//
// SkFontStyle
//

int SkFontStyle_weight (SkFontStyle *font_style) {
    return font_style->weight();
}

int SkFontStyle_width (SkFontStyle *font_style) {
    return font_style->width();
}

SkFontStyle::Slant SkFontStyle_slant (SkFontStyle *font_style) {
    return font_style->slant();
}

//
// SkFontStyleSet
//

int SkFontStyleSet_count(SkFontStyleSet *font_style_set) {
    return font_style_set->count();
}

void SkFontStyleSet_getStyle(SkFontStyleSet *font_style_set, int index, SkFontStyle * font_style, SkString *style) {
    return font_style_set->getStyle(index, font_style, style);
}

void SkFontStyleSet_createTypeface(const char *sk_typeface_key_out, SkFontStyleSet *font_style_set, int index) {
    static_sk_typeface[sk_typeface_key_out] = font_style_set->createTypeface(index);
}

void SkFontStyleSet_matchStyle(const char *sk_typeface_key_out, SkFontStyleSet *font_style_set, const SkFontStyle *pattern) {
    static_sk_typeface[sk_typeface_key_out] = font_style_set->matchStyle(*pattern);
}

bool SkFontStyleSet_unique(SkFontStyleSet *font_style_set) {
    return font_style_set->unique();
}

void SkFontStyleSet_ref(SkFontStyleSet *font_style_set) {
    return font_style_set->ref();
}

void SkFontStyleSet_unref(SkFontStyleSet *font_style_set) {
    return font_style_set->unref();
}

// static

void SkFontStyleSet_CreateEmpty(const char *sk_font_style_set_key_out) {
    static_sk_font_style_set[sk_font_style_set_key_out] = SkFontStyleSet::CreateEmpty();
}

//
// SkGradientShader
//

// static

void SkGradientShader_MakeLinear(const char *sk_shader_key_out, const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeLinear(pts, colors, pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeLinear_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeLinear(pts, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, *interpolation, localMatrix);
}

void SkGradientShader_MakeLinear_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeLinear(pts, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeRadial(const char *sk_shader_key_out, const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeRadial(*center, radius, colors, pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeRadial_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, *interpolation, localMatrix);
}

void SkGradientShader_MakeRadial_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeTwoPointConical(const char *sk_shader_key_out, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeTwoPointConical_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, *interpolation, localMatrix);
}

void SkGradientShader_MakeTwoPointConical_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[],  const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, flags, localMatrix);
}

void SkGradientShader_MakeSweep(const char *sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix);
}

void SkGradientShader_MakeSweep_2(const char *sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeSweep(cx, cy, colors, pos, count, flags, localMatrix);
}

void SkGradientShader_MakeSweep_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, startAngle, endAngle, *interpolation, localMatrix);
}

void SkGradientShader_MakeSweep_4(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space[sk_color_space_key_in], pos, count, mode, startAngle, endAngle, flags, localMatrix);
}

void SkGradientShader_MakeSweep_5(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space[sk_color_space_key_in], pos, count, flags, localMatrix);
}

//
// SkGraphics
//

// static

void SkGraphics_Init() {
    SkGraphics::Init();
}

size_t SkGraphics_GetFontCacheLimit() {
    return SkGraphics::GetFontCacheLimit();
}

size_t SkGraphics_SetFontCacheLimit(size_t bytes) {
    return SkGraphics::SetFontCacheLimit(bytes);
}

size_t SkGraphics_GetFontCacheUsed() {
    return SkGraphics::GetFontCacheUsed();
}

int SkGraphics_GetFontCacheCountUsed() {
    return SkGraphics::GetFontCacheCountUsed();
}

int SkGraphics_GetFontCacheCountLimit() {
    return SkGraphics::GetFontCacheCountLimit();
}

int SkGraphics_SetFontCacheCountLimit(int count) {
    return SkGraphics::SetFontCacheCountLimit(count);
}

void SkGraphics_PurgeFontCache() {
    SkGraphics::PurgeFontCache();
}

void SkGraphics_PurgePinnedFontCache() {
    SkGraphics::PurgePinnedFontCache();
}

size_t SkGraphics_GetResourceCacheTotalBytesUsed() {
    return SkGraphics::GetResourceCacheTotalBytesUsed();
}

size_t SkGraphics_GetResourceCacheTotalByteLimit() {
    return SkGraphics::GetResourceCacheTotalByteLimit();
}

size_t SkGraphics_SetResourceCacheTotalByteLimit(size_t newLimit) {
    return SkGraphics::SetResourceCacheTotalByteLimit(newLimit);
}

void SkGraphics_PurgeResourceCache() {
    SkGraphics::PurgeResourceCache();
}
size_t SkGraphics_GetResourceCacheSingleAllocationByteLimit() {
    return SkGraphics::GetResourceCacheSingleAllocationByteLimit();
}

size_t SkGraphics_SetResourceCacheSingleAllocationByteLimit(size_t newLimit) {
    return SkGraphics::SetResourceCacheSingleAllocationByteLimit(newLimit);
}

void SkGraphics_DumpMemoryStatistics(SkTraceMemoryDump *dump) {
    SkGraphics::DumpMemoryStatistics(dump);
}

void SkGraphics_PurgeAllCaches() {
    SkGraphics::PurgeAllCaches();
}

SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory) {
    return SkGraphics::SetImageGeneratorFromEncodedDataFactory(factory);
}

SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory) {
    return SkGraphics::SetOpenTypeSVGDecoderFactory(factory);
}

SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory() {
    return SkGraphics::GetOpenTypeSVGDecoderFactory();
}

//
// SkHighContrastConfig
//

SkHighContrastConfig *SkHighContrastConfig_new() {
    return new SkHighContrastConfig();
}

SkHighContrastConfig *SkHighContrastConfig_new_2(bool grayscale, SkHighContrastConfig::InvertStyle invertStyle, SkScalar contrast) {
    return new SkHighContrastConfig(grayscale, invertStyle, contrast);
}

bool isValid(SkHighContrastConfig *high_contrast_config) {
    return high_contrast_config->isValid();
}

//
// SkHighContrastFilter
//

// static

void SkHighContrastFilter_Make(const char *sk_color_filter_key_out, const SkHighContrastConfig * config) {
    static_sk_color_filter[sk_color_filter_key_out] = SkHighContrastFilter::Make(*config);
}

//
// SkImage
//

const SkImageInfo & SkImage_imageInfo(SkImage *image) { // @TODO
    return image->imageInfo();
}

int SkImage_width(SkImage *image) {
    return image->width();
}

int SkImage_height(SkImage *image) {
    return image->height();
}

SkISize SkImage_dimensions(SkImage *image) {
    return image->dimensions();
}

SkIRect SkImage_bounds(SkImage *image) { // @TODO
    return image->bounds();
}

uint32_t SkImage_uniqueID(SkImage *image) {
    return image->uniqueID();
}

SkAlphaType SkImage_alphaType(SkImage *image) {
    return image->alphaType();
}

SkColorType SkImage_colorType(SkImage *image) {
    return image->colorType();
}

SkColorSpace * cSkImage_olorSpace(SkImage *image) {
    return image->colorSpace();
}

void SkImage_refColorSpace(const char *sk_color_space_key_out, SkImage *image) {
    static_sk_color_space[sk_color_space_key_out] = image->refColorSpace();
}

bool SkImage_isAlphaOnly(SkImage *image) {
    return image->isAlphaOnly();
}

bool SkImage_isOpaque(SkImage *image) {
    return image->isOpaque();
}

void SkImage_makeShader(const char *sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = image->makeShader(tmx, tmy, *sampling, localMatrix);
}

void SkImage_makeShader_2(const char *sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeShader(tmx, tmy, *sampling, *lm);
}

void SkImage_makeShader_3(const char *sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeShader(*sampling, *lm);
}

void SkImage_makeShader_4(const char *sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeShader(*sampling, lm);
}

void SkImage_makeRawShader(const char *sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    static_sk_shader[sk_shader_key_out] = image->makeRawShader(tmx, tmy, *sampling, localMatrix);
}

void SkImage_makeRawShader_2(const char *sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeRawShader(tmx, tmy, *sampling, *lm);
}

void SkImage_makeRawShader_3(const char *sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeRawShader(*sampling, *lm);
}

void SkImage_makeRawShader_4(const char *sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key_out] = image->makeRawShader(*sampling, lm);
}

bool SkImage_peekPixels(SkImage *image, SkPixmap *pixmap) {
    return image->peekPixels(pixmap);
}

bool SkImage_isTextureBacked(SkImage *image) {
    return image->isTextureBacked();
}

size_t SkImage_textureSize(SkImage *image) {
    return image->textureSize();
}

bool SkImage_isValid(SkImage *image, GrRecordingContext *context) {
    return image->isValid(context);
}

bool SkImage_readPixels(SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(context, *dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_2(SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(context, *dst, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_3(SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_4(SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(*dst, srcX, srcY, cachingHint);
}

void SkImage_asyncRescaleAndReadPixels(SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixels(*info, *srcRect, rescaleGamma, rescaleMode, callback, context);
}

void SkImage_asyncRescaleAndReadPixelsYUV420(const char *sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUV420(yuvColorSpace, static_sk_color_space[sk_color_space_key_in], *srcRect,
                                           *dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkImage_asyncRescaleAndReadPixelsYUVA420(const char *sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUVA420(yuvColorSpace, static_sk_color_space[sk_color_space_key_in], *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint) {
    return image->scalePixels(*dst, *sampling, cachingHint);
}

void SkImage_refEncodedData(const char *sk_data_key_out, SkImage *image) {
    static_sk_data[sk_data_key_out] = image->refEncodedData();
}

void SkImage_makeSubset(const char *sk_image_key_out, SkImage *image, GrDirectContext *direct, const SkIRect *subset) {
    static_sk_image[sk_image_key_out] = image->makeSubset(direct, *subset);
}

void SkImage_makeSubset_2(const char *sk_image_key_out, SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, SkImage::RequiredProperties properties) {
    static_sk_image[sk_image_key_out] = image->makeSubset(recorder, *subset, properties);
}

bool SkImage_hasMipmaps(SkImage *image) {
    return image->hasMipmaps();
}

bool SkImage_isProtected(SkImage *image) {
    return image->isProtected();
}

void SkImage_withDefaultMipmaps(const char *sk_image_key_out, SkImage *image) {
    static_sk_image[sk_image_key_out] = image->withDefaultMipmaps();
}

void SkImage_makeNonTextureImage(const char *sk_image_key_out, SkImage *image, GrDirectContext *context) {
    static_sk_image[sk_image_key_out] = image->makeNonTextureImage(context);
}

void SkImage_makeRasterImage(const char *sk_image_key_out, SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) {
    static_sk_image[sk_image_key_out] = image->makeRasterImage(context, cachingHint);
}

void SkImage_makeRasterImage_2(const char *sk_image_key_out, SkImage *image, SkImage::CachingHint cachingHint) {
    static_sk_image[sk_image_key_out] = image->makeRasterImage(cachingHint);
}

bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) {
    return image->asLegacyBitmap(bitmap, legacyBitmapMode);
}

bool SkImage_isLazyGenerated(SkImage *image) {
    return image->isLazyGenerated();
}

void SkImage_makeColorSpace(const char *sk_image_key_out, const char *sk_color_space_key_in, SkImage *image, GrDirectContext *direct) {
    static_sk_image[sk_image_key_out] = image->makeColorSpace(direct, static_sk_color_space[sk_color_space_key_in]);
}

void SkImage_makeColorSpace_2(const char *sk_image_key_out, const char *sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkImage::RequiredProperties properties) {
    static_sk_image[sk_image_key_out] = image->makeColorSpace(recorder, static_sk_color_space[sk_color_space_key_in], properties);
}

void SkImage_makeColorTypeAndColorSpace(const char *sk_image_key_out, const char *sk_color_space_key_in, SkImage *image, GrDirectContext *direct, SkColorType targetColorType) {
    static_sk_image[sk_image_key_out] = image->makeColorTypeAndColorSpace(direct, targetColorType, static_sk_color_space[sk_color_space_key_in]);
}

void SkImage_makeColorTypeAndColorSpace_2(const char *sk_image_key_out, const char *sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, SkImage::RequiredProperties properties) {
    static_sk_image[sk_image_key_out] = image->makeColorTypeAndColorSpace(recorder, targetColorType, static_sk_color_space[sk_color_space_key_in], properties);
}

void SkImage_reinterpretColorSpace(const char *sk_image_key_out, const char *sk_color_space_key_in, SkImage *image) {
    static_sk_image[sk_image_key_out] = image->reinterpretColorSpace(static_sk_color_space[sk_color_space_key_in]);
}

bool SkImage_unique(SkImage *image) {
    return image->unique();
}

void SkImage_ref(SkImage *image) {
    return image->ref();
}

void SkImage_unref(SkImage *image) {
    return image->unref();
}

//
// SkImages SK_API
//

void SkImages_RasterFromBitmap(const char *sk_image_key_out, const SkBitmap *bitmap) {
    static_sk_image[sk_image_key_out] = SkImages::RasterFromBitmap(*bitmap);
}

void SkImages_RasterFromCompressedTextureData(const char *sk_image_key_out, const char *sk_data_key_in, int width, int height, SkTextureCompressionType type) {
    static_sk_image[sk_image_key_out] = SkImages::RasterFromCompressedTextureData(static_sk_data[sk_data_key_in], width, height, type);
}

void SkImages_DeferredFromEncodedData(const char *sk_image_key_out, const char *sk_data_key_in) {
    static_sk_image[sk_image_key_out] = SkImages::DeferredFromEncodedData(static_sk_data[sk_data_key_in]);
}

void SkImages_DeferredFromGenerator(const char *sk_image_key_out, const char *sk_image_generator_key_in) { // @TODO
    //static_sk_image[sk_image_key_out] = SkImages::DeferredFromGenerator(static_sk_image_generator[sk_image_generator_key_in]);
}

void SkImages_DeferredFromPicture(const char *sk_image_key_out, const char *sk_picture_key_in, const char *sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, SkSurfaceProps props) {
    static_sk_image[sk_image_key_out] = SkImages::DeferredFromPicture(static_sk_picture[sk_picture_key_in], *dimensions, matrix, paint, bitDepth, static_sk_color_space[sk_color_space_key_in], props);
}

void SkImages_DeferredFromPicture_2(const char *sk_image_key_out, const char *sk_picture_key_in, const char *sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint,SkImages::BitDepth bitDepth) {
    static_sk_image[sk_image_key_out] = SkImages::DeferredFromPicture(static_sk_picture[sk_picture_key_in], *dimensions,
                                                                      matrix, paint, bitDepth,
                                                                      static_sk_color_space[sk_color_space_key_in]);
}

void SkImages_RasterFromPixmapCopy(const char *sk_image_key_out, const SkPixmap *pixmap) {
    static_sk_image[sk_image_key_out] = SkImages::RasterFromPixmapCopy(*pixmap);
}

void SkImages_RasterFromPixmap(const char *sk_image_key_out, const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext) {
    static_sk_image[sk_image_key_out] = SkImages::RasterFromPixmap(*pixmap, rasterReleaseProc, releaseContext);
}

void SkImages_RasterFromData(const char *sk_image_key_out, const char *sk_data_key_in, const SkImageInfo *info, size_t rowBytes) {
    static_sk_image[sk_image_key_out] = SkImages::RasterFromData(*info, static_sk_data[sk_data_key_in], rowBytes);
}

void SkImages_MakeWithFilter(const char *sk_image_key_out, const char *sk_image_key_in, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset) {
    static_sk_image[sk_image_key_out] = SkImages::MakeWithFilter(static_sk_image[sk_image_key_in], filter, *subset, *clipBounds, outSubset, offset);
}

//
// SkImageFilter
//

SkIRect SkImageFilter_filterBounds(SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect) {
    return image_filter->filterBounds(*src, *ctm, direction, inputRect);
}

bool SkImageFilter_isColorFilterNode(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->isColorFilterNode(filterPtr);
}

bool SkImageFilter_asColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->asColorFilter(filterPtr);
}

bool SkImageFilter_asAColorFilter(SkImageFilter *image_filter, SkColorFilter **filterPtr) {
    return image_filter->asAColorFilter(filterPtr);
}

int SkImageFilter_countInputs(SkImageFilter *image_filter) {
    return image_filter->countInputs();
}

const SkImageFilter * SkImageFilter_getInput(SkImageFilter *image_filter, int i) {
    return image_filter->getInput(i);
}

SkRect SkImageFilter_computeFastBounds(SkImageFilter *image_filter, const SkRect *bounds) {
    return image_filter->computeFastBounds(*bounds);
}

bool SkImageFilter_canComputeFastBounds(SkImageFilter *image_filter) {
    return image_filter->canComputeFastBounds();
}

void SkImageFilter_makeWithLocalMatrix(const char *sk_image_filter_key_out, SkImageFilter *image_filter, const SkMatrix *matrix) {
    static_sk_image_filter[sk_image_filter_key_out] = image_filter->makeWithLocalMatrix(*matrix);
}

SkImageFilter::Factory SkImageFilter_getFactory(SkImageFilter *image_filter) {
    return image_filter->getFactory();
}

const char * SkImageFilter_getTypeName(SkImageFilter *image_filter) {
    return image_filter->getTypeName();
}

void SkImageFilter_flatten(SkImageFilter *image_filter, SkWriteBuffer *buffer) {
    image_filter->flatten(*buffer);
}

SkImageFilter::Type SkImageFilter_getFlattenableType(SkImageFilter *image_filter) {
    return image_filter->getFlattenableType();
}

void SkImageFilter_serialize(const char *sk_data_key_out, SkImageFilter *image_filter, const SkSerialProcs *procs) {
    static_sk_data[sk_data_key_out] = image_filter->serialize(procs);
}

size_t SkImageFilter_serialize_2(SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return image_filter->serialize(memory, memory_size, procs);
}

bool SkImageFilter_unique(SkImageFilter *image_filter) {
    return image_filter->unique();
}

void SkImageFilter_ref(SkImageFilter *image_filter) {
    image_filter->ref();
}

void SkImageFilter_unref(SkImageFilter *image_filter) {
    image_filter->unref();
}

// static
void SkImageFilter_Deserialize(const char *sk_image_filter_key_out, SkImageFilter *image_filter, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilter::Deserialize(data, size, procs);
}

SkImageFilter::Factory SkImageFilter_NameToFactory(SkImageFilter *image_filter, const char name[]) {
    return SkImageFilter::NameToFactory(name);
}

const char * SkImageFilter_FactoryToName(SkImageFilter *image_filter, SkImageFilter::Factory factory) {
    return SkImageFilter::FactoryToName(factory);
}

void SkImageFilter_Register(SkImageFilter *image_filter, const char name[], SkImageFilter::Factory factory) {
    return SkImageFilter::Register(name, factory);
}

//
// SkImageFilters
//

// static

void SkImageFilters_Arithmetic(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Arithmetic(k1, k2, k3, k4, enforcePMColor, static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2], *cropRect);
}

void SkImageFilters_Blend(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkBlendMode mode, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Blend(mode, static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2], *cropRect);
}

void SkImageFilters_Blend_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, sk_sp<SkBlender> blender, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Blend(blender, static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2], *cropRect);
}

void SkImageFilters_Blur(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Blur(sigmaX, sigmaY, tileMode, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_Blur_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Blur(sigmaX, sigmaY, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_ColorFilter(const char *sk_image_filter_key_out, const char *sk_image_color_key_in, const char *sk_image_filter_key_in, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::ColorFilter(static_sk_color_filter[sk_image_color_key_in], static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_Compose(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Compose(static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2]);
}

void SkImageFilters_Crop(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *rect, SkTileMode tileMode) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Crop(*rect, tileMode, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_Crop_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *rect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Crop(*rect, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_DisplacementMap(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::DisplacementMap(xChannelSelector, yChannelSelector, scale, static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2], *cropRect);
}

void SkImageFilters_DropShadow(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::DropShadow(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_DropShadowOnly(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::DropShadowOnly(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_Empty(const char *sk_image_filter_key_out) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Empty();
}

void SkImageFilters_Image(const char *sk_image_filter_key_out, const char *sk_image_key_in, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Image(static_sk_image[sk_image_key_in], *srcRect, *dstRect, *sampling);
}

void SkImageFilters_Image_2(const char *sk_image_filter_key_out, const char *sk_image_key_in, const SkSamplingOptions *sampling) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Image(static_sk_image[sk_image_key_in], *sampling);
}

void SkImageFilters_Magnifier(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Magnifier(*lensBounds, zoomAmount, inset, *sampling, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_MatrixConvolution(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::MatrixConvolution(*kernelSize, kernel, gain, bias, *kernelOffset, tileMode, convolveAlpha, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_MatrixTransform(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkMatrix *matrix, const SkSamplingOptions *sampling) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::MatrixTransform(*matrix, *sampling, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_Merge(const char *sk_image_filter_key_out, sk_sp<SkImageFilter> *const filters, int count, const SkImageFilters::CropRect *cropRect) { // @TODO
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Merge(filters, count, *cropRect);
}

void SkImageFilters_Merge_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Merge(static_sk_image_filter[sk_image_filter_key_in_1], static_sk_image_filter[sk_image_filter_key_in_2], *cropRect);
}

void SkImageFilters_Offset(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Offset(dx, dy, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_Picture(const char *sk_image_filter_key_out, const char *sk_picture_key_in, const SkRect *targetRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Picture(static_sk_picture[sk_picture_key_in], *targetRect);
}

void SkImageFilters_Picture_2(const char *sk_image_filter_key_out, const char *sk_picture_key_in) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Picture(static_sk_picture[sk_picture_key_in]);
}

void SkImageFilters_RuntimeShader(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, std::string_view childShaderName) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::RuntimeShader(*builder, childShaderName, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_RuntimeShader_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, std::string_view childShaderName) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::RuntimeShader(*builder, sampleRadius, childShaderName, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_RuntimeShader_3(const char *sk_image_filter_key_out, const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> inputs[], int inputCount) { // @TODO
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::RuntimeShader(*builder, childShaderNames, inputs, inputCount);
}

void SkImageFilters_RuntimeShader_4(const char *sk_image_filter_key_out, const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> inputs[], int inputCount) { // @TODO
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::RuntimeShader(*builder, maxSampleRadius, childShaderNames, inputs, inputCount);
}

void SkImageFilters_Shader(const char *sk_image_filter_key_out, const char *sk_shader_key_in, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Shader(static_sk_shader[sk_shader_key_in], *cropRect);
}

void SkImageFilters_Shader_2(const char *sk_image_filter_key_out, const char *sk_shader_key_in, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Shader(static_sk_shader[sk_shader_key_in], dither, *cropRect);
}

void SkImageFilters_Tile(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *src, const SkRect *dst) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Tile(*src, *dst, static_sk_image_filter[sk_image_filter_key_in]);
}

void SkImageFilters_Dilate(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Dilate(radiusX, radiusY, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_Erode(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::Erode(radiusX, radiusY, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_DistantLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::DistantLitDiffuse(*direction, lightColor, surfaceScale, kd, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_PointLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::PointLitDiffuse(*location, lightColor, surfaceScale, kd, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_SpotLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::SpotLitDiffuse(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_DistantLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::DistantLitSpecular(*direction, lightColor, surfaceScale, ks, shininess, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_PointLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::PointLitSpecular(*location, lightColor, surfaceScale, ks, shininess, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

void SkImageFilters_SpotLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter[sk_image_filter_key_out] = SkImageFilters::SpotLitSpecular(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, static_sk_image_filter[sk_image_filter_key_in], *cropRect);
}

//
// SkImageGenerator
//
void SkImageGenerator_delete(SkImageGenerator *image_generator) {
    delete image_generator;
}

uint32_t SkImageGenerator_uniqueID(SkImageGenerator *image_generator) {
    return image_generator->uniqueID();
}

void SkImageGenerator_refEncodedData(const char *sk_data_key_out, SkImageGenerator *image_generator) {
    static_sk_data[sk_data_key_out] = image_generator->refEncodedData();
}

SkImageInfo SkImageGenerator_getInfo(SkImageGenerator *image_generator) {
    return image_generator->getInfo();
}

bool SkImageGenerator_isValid(SkImageGenerator *image_generator, GrRecordingContext *context) {
    return image_generator->isValid(context);
}

bool SkImageGenerator_isProtected(SkImageGenerator *image_generator) {
    return image_generator->isProtected();
}

bool SkImageGenerator_getPixels(SkImageGenerator *image_generator, const SkImageInfo *info, void *pixels, size_t rowBytes) {
    return image_generator->getPixels(*info, pixels, rowBytes);
}

bool SkImageGenerator_getPixels_2(SkImageGenerator *image_generator, const SkPixmap *pm) {
    return image_generator->getPixels(*pm);
}

bool SkImageGenerator_queryYUVAInfo(SkImageGenerator *image_generator, const SkYUVAPixmapInfo::SupportedDataTypes *supportedDataTypes, SkYUVAPixmapInfo *yuvaPixmapInfo) {
    return image_generator->queryYUVAInfo(*supportedDataTypes, yuvaPixmapInfo);
}

bool SkImageGenerator_getYUVAPlanes(SkImageGenerator *image_generator, const SkYUVAPixmaps *yuvaPixmaps) {
    return image_generator->getYUVAPlanes(*yuvaPixmaps);
}

bool SkImageGenerator_isTextureGenerator(SkImageGenerator *image_generator) {
    return image_generator->isTextureGenerator();
}

//
// SkImageInfo
//

SkImageInfo *SkImageInfo_new() {
    return new SkImageInfo();
}

int SkImageInfo_width(SkImageInfo *image_info) {
    return image_info->width();
}

int SkImageInfo_height(SkImageInfo *image_info) {
    return image_info->height();
}

SkColorType SkImageInfo_colorType(SkImageInfo *image_info) {
    return image_info->colorType();
}

SkAlphaType SkImageInfo_alphaType(SkImageInfo *image_info) {
    return image_info->alphaType();
}

SkColorSpace * SkImageInfo_colorSpace(SkImageInfo *image_info) {
    return image_info->colorSpace();
}

void SkImageInfo_refColorSpace(const char *sk_color_space_key_out, SkImageInfo *image_info) {
    static_sk_color_space[sk_color_space_key_out] = image_info->refColorSpace();
}

bool SkImageInfo_isEmpty(SkImageInfo *image_info) {
    return image_info->isEmpty();
}

SkColorInfo SkImageInfo_colorInfo(SkImageInfo *image_info) {
    return image_info->colorInfo();
}

bool SkImageInfo_isOpaque(SkImageInfo *image_info) {
    return image_info->isOpaque();
}

SkISize SkImageInfo_dimensions(SkImageInfo *image_info) {
    return image_info->dimensions();
}

SkIRect SkImageInfo_bounds(SkImageInfo *image_info) {
    return image_info->bounds();
}

bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info) {
    return image_info->gammaCloseToSRGB();
}

SkImageInfo SkImageInfo_makeWH(SkImageInfo *image_info, int newWidth, int newHeight) {
    return image_info->makeWH(newWidth, newHeight);
}

SkImageInfo SkImageInfo_makeDimensions(SkImageInfo *image_info, SkISize newSize) {
    return image_info->makeDimensions(newSize);
}

SkImageInfo SkImageInfo_makeAlphaType(SkImageInfo *image_info, SkAlphaType newAlphaType) {
    return image_info->makeAlphaType(newAlphaType);
}

SkImageInfo SkImageInfo_makeColorType(SkImageInfo *image_info, SkColorType newColorType) {
    return image_info->makeColorType(newColorType);
}

SkImageInfo SkImageInfo_makeColorSpace(SkImageInfo *image_info, const char *sk_color_space_key_in) {
    return image_info->makeColorSpace(static_sk_color_space[sk_color_space_key_in]);
}

int SkImageInfo_bytesPerPixel(SkImageInfo *image_info) {
    return image_info->bytesPerPixel();
}

int SkImageInfo_shiftPerPixel(SkImageInfo *image_info) {
    return image_info->shiftPerPixel();
}

uint64_t SkImageInfo_minRowBytes64(SkImageInfo *image_info) {
    return image_info->minRowBytes64();
}

size_t SkImageInfo_minRowBytes(SkImageInfo *image_info) {
    return image_info->minRowBytes();
}

size_t SkImageInfo_computeOffset(SkImageInfo *image_info, int x, int y, size_t rowBytes) {
    return image_info->computeOffset(x, y, rowBytes);
}

//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)

size_t SkImageInfo_computeByteSize(SkImageInfo *image_info, size_t rowBytes) {
    return image_info->computeByteSize(rowBytes);
}

size_t SkImageInfo_computeMinByteSize(SkImageInfo *image_info) {
    return image_info->computeMinByteSize();
}

bool SkImageInfo_validRowBytes(SkImageInfo *image_info, size_t rowBytes) {
    return image_info->validRowBytes(rowBytes);
}

void SkImageInfo_reset(SkImageInfo *image_info) {
    image_info->reset();
}

// static

SkImageInfo SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at) {
    return SkImageInfo::Make(width, height, ct, at);
}

SkImageInfo SkImageInfo_Make_2(const char *sk_color_space_key_in, int width, int height, SkColorType ct, SkAlphaType at) {
    return SkImageInfo::Make(width, height, ct, at, static_sk_color_space[sk_color_space_key_in]);
}

SkImageInfo SkImageInfo_Make_3(SkISize dimensions, SkColorType ct, SkAlphaType at) {
    return SkImageInfo::Make(dimensions, ct, at);
}

SkImageInfo SkImageInfo_Make_4(const char *sk_color_space_key_in, SkISize dimensions, SkColorType ct, SkAlphaType at) {
    return SkImageInfo::Make(dimensions, ct, at, static_sk_color_space[sk_color_space_key_in]);
}

SkImageInfo SkImageInfo_Make_5(SkISize dimensions, const SkColorInfo *colorInfo) {
    return SkImageInfo::Make(dimensions, *colorInfo);
}

SkImageInfo SkImageInfo_Make_6(SkISize dimensions, SkColorInfo &&colorInfo) { // @TODO
    return SkImageInfo::Make(dimensions, colorInfo);
}

SkImageInfo SkImageInfo_MakeN32(int width, int height, SkAlphaType at) {
    return SkImageInfo::MakeN32(width, height, at);
}

SkImageInfo SkImageInfo_MakeN32_2(const char *sk_color_space_key_in, int width, int height, SkAlphaType at) {
    return SkImageInfo::MakeN32(width, height, at, static_sk_color_space[sk_color_space_key_in]);
}

SkImageInfo SkImageInfo_MakeS32(int width, int height, SkAlphaType at) {
    return SkImageInfo::MakeS32(width, height, at);
}

SkImageInfo SkImageInfo_MakeN32Premul(int width, int height) {
    return SkImageInfo::MakeN32Premul(width, height);
}

SkImageInfo SkImageInfo_MakeN32Premul_2(const char *sk_color_space_key_in, int width, int height) {
    return SkImageInfo::MakeN32Premul(width, height, static_sk_color_space[sk_color_space_key_in]);
}

SkImageInfo SkImageInfo_MakeN32Premul_3(SkISize dimensions) {
    return SkImageInfo::MakeN32Premul(dimensions);
}

SkImageInfo SkImageInfo_MakeN32Premul_4(const char *sk_color_space_key_in, SkISize dimensions) {
    return SkImageInfo::MakeN32Premul(dimensions, static_sk_color_space[sk_color_space_key_in]);
}

SkImageInfo SkImageInfo_MakeA8(int width, int height) {
    return SkImageInfo::MakeA8(width, height);
}

SkImageInfo SkImageInfo_MakeA8_2(SkISize dimensions) {
    return SkImageInfo::MakeA8(dimensions);
}

SkImageInfo SkImageInfo_MakeUnknown(int width, int height) {
    return SkImageInfo::MakeUnknown(width, height);
}

SkImageInfo SkImageInfo_MakeUnknown_2() {
    return SkImageInfo::MakeUnknown();
}

bool SkImageInfo_ByteSizeOverflowed(size_t byteSize) {
    return SkImageInfo::ByteSizeOverflowed(byteSize);
}

//
// SkIRect - Struct
//

int32_t SkIRect_left(SkIRect *i_rect) {
    return i_rect->left();
}

int32_t SkIRect_top(SkIRect *i_rect) {
    return i_rect->top();
}

int32_t SkIRect_right(SkIRect *i_rect) {
    return i_rect->right();
}

int32_t SkIRect_bottom(SkIRect *i_rect) {
    return i_rect->bottom();
}

int32_t SkIRect_x(SkIRect *i_rect) {
    return i_rect->x();
}

int32_t SkIRect_y(SkIRect *i_rect) {
    return i_rect->y();
}

SkIPoint SkIRect_topLeft(SkIRect *i_rect) {
    return i_rect->topLeft();
}

int32_t SkIRect_width(SkIRect *i_rect) {
    return i_rect->width();
}

int32_t SkIRect_height(SkIRect *i_rect) {
    return i_rect->height();
}

SkISize SkIRect_size(SkIRect *i_rect) {
    return i_rect->size();
}

int64_t SkIRect_width64(SkIRect *i_rect) {
    return i_rect->width64();
}

int64_t SkIRect_height64(SkIRect *i_rect) {
    return i_rect->height64();
}

bool SkIRect_isEmpty64(SkIRect *i_rect) {
    return i_rect->isEmpty64();
}

bool SkIRect_isEmpty(SkIRect *i_rect) {
    return i_rect->isEmpty();
}

void SkIRect_setEmpty(SkIRect *i_rect) {
    i_rect->setEmpty();
}

void SkIRect_setLTRB(SkIRect *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom) {
    i_rect->setLTRB(left, top, right, bottom);
}

void SkIRect_setXYWH(SkIRect *i_rect, int32_t x, int32_t y, int32_t width, int32_t height) {
    i_rect->setXYWH(x, y, width, height);
}

void SkIRect_setWH(SkIRect *i_rect, int32_t width, int32_t height) {
    i_rect->setWH(width, height);
}

void SkIRect_setSize(SkIRect *i_rect, SkISize size) {
    i_rect->setSize(size);
}

SkIRect SkIRect_makeOffset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->makeOffset(dx, dy);
}

SkIRect SkIRect_makeOffset_2(SkIRect *i_rect, SkIVector offset) {
    return i_rect->makeOffset(offset);
}

SkIRect SkIRect_makeInset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->makeInset(dx, dy);
}

SkIRect SkIRect_makeOutset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->makeOutset(dx, dy);
}

void SkIRect_offset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->offset(dx, dy);
}

void SkIRect_offset_2(SkIRect *i_rect, const SkIPoint *delta) {
    i_rect->offset(*delta);
}

void SkIRect_offsetTo(SkIRect *i_rect, int32_t newX, int32_t newY) {
    i_rect->offsetTo(newX, newY);
}

void SkIRect_inset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->inset(dx, dy);
}

void SkIRect_outset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    i_rect->outset(dx, dy);
}

void SkIRect_adjust(SkIRect *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB) {
    i_rect->adjust(dL, dT, dR, dB);
}

bool SkIRect_contains(SkIRect *i_rect, int32_t x, int32_t y) {
    return i_rect->contains(x, y);
}

bool SkIRect_contains_2(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->contains(*r);
}

bool SkIRect_contains_3(SkIRect *i_rect, const SkRect *r) {
    return i_rect->contains(*r);
}

bool SkIRect_containsNoEmptyCheck(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->containsNoEmptyCheck(*r);
}

bool SkIRect_intersect(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->intersect(*r);
}

bool SkIRect_intersect_2(SkIRect *i_rect, const SkIRect *a, const SkIRect *b) {
    return i_rect->intersect(*a, *b);
}

void SkIRect_join(SkIRect *i_rect, const SkIRect *r) {
    i_rect->join(*r);
}

void SkIRect_sort(SkIRect *i_rect) {
    i_rect->sort();
}

SkIRect SkIRect_makeSorted(SkIRect *i_rect) {
    return i_rect->makeSorted();
}

// static

SkIRect SkIRect_MakeEmpty() {
    return SkIRect::MakeEmpty();
}

SkIRect SkIRect_MakeWH(int32_t w, int32_t h) {
    return SkIRect::MakeWH(w, h);
}

SkIRect SkIRect_MakeSize(const SkISize *size) {
    return SkIRect::MakeSize(*size);
}

SkIRect SkIRect_MakePtSize(SkIPoint pt, SkISize size) {
    return SkIRect::MakePtSize(pt, size);
}

SkIRect SkIRect_MakeLTRB(int32_t l, int32_t t, int32_t r, int32_t b) {
    return SkIRect::MakeLTRB(l, t, r, b);
}

SkIRect SkIRect_MakeXYWH(int32_t x, int32_t y, int32_t w, int32_t h) {
    return SkIRect::MakeXYWH(x, y, w, h);
}

bool SkIRect_Intersects(const SkIRect *a, const SkIRect *b) {
    return SkIRect::Intersects(*a, *b);
}

//
// SkISize Struct
//

void SkISize_set(SkISize *i_size, int32_t w, int32_t h) {
    i_size->set(w, h);
}

bool SkISize_isZero(SkISize *i_size) {
    return i_size->isZero();
}

bool SkISize_isEmpty(SkISize *i_size) {
    return i_size->isEmpty();
}

void SkISize_setEmpty(SkISize *i_size) {
    return i_size->setEmpty();
}

int32_t SkISize_width(SkISize *i_size) {
    return i_size->width();
}

int32_t SkISize_height(SkISize *i_size) {
    return i_size->height();
}

int64_t SkISize_area(SkISize *i_size) {
    return i_size->area();
}

bool SkISize_equals(SkISize *i_size, int32_t w, int32_t h) {
    return i_size->equals(w, h);
}

// static

SkISize SkISize_Make(int32_t w, int32_t h) {
    return SkISize::Make(w, h);
}

SkISize SkISize_MakeEmpty() {
    return SkISize::MakeEmpty();
}

//
// SkLayerDrawLooper
//

//void SkLayerDrawLooper_delete(SkLayerDrawLooper *layer_draw_looper) {}
//SkDrawLooper::Context * SkLayerDrawLooper_makeContext(SkLayerDrawLooper *layer_draw_looper, SkArenaAlloc *arena_alloc) {}
//bool SkLayerDrawLooper_asABlurShadow(SkLayerDrawLooper *layer_draw_looper, SkLayerDrawLooper::BlurShadowRec *rec) {}
//bool canComputeFastBounds(const SkPaint &paint)
//void computeFastBounds(const SkPaint &paint, const SkRect &src, SkRect *dst)
//SkFlattenable::Type getFlattenableType() const override
//void apply(SkCanvas *canvas, const SkPaint &paint, std::function<void(SkCanvas *, const SkPaint &)>)
//Factory getFactory()
//const char * getTypeName()
//sk_sp<SkData> serialize(const SkSerialProcs *)
//size_t serialize(void *memory, size_t memory_size, const SkSerialProcs *)
//bool unique()
//void ref()
//void unref()

// static

//SkFlattenable::Type GetFlattenableType()
//sk_sp<SkDrawLooper> Deserialize(const void *data, size_t size, const SkDeserialProcs *procs)
//sk_sp<SkFlattenable> Deserialize(Type, const void *data, size_t length, const SkDeserialProcs *procs)
//Factory NameToFactory(const char name[])
//const char * FactoryToName(Factory)
//void Register(const char name[], Factory)

//
// SkLine2DPathEffect
//

// static

void SkLine2DPathEffect_Make(const char *sk_path_effect_key_out, SkScalar width, const SkMatrix *matrix) {
    static_sk_path_effect[sk_path_effect_key_out] = SkLine2DPathEffect::Make(width, *matrix);
}

void SkLine2DPathEffect_RegisterFlattenables() {
    SkLine2DPathEffect::RegisterFlattenables();
}

//
// SkLumaColorFilter Struct
//

// static

void SkLumaColorFilter_Make(const char *sk_color_filter_key_out) {
    static_sk_color_filter[sk_color_filter_key_out] = SkLumaColorFilter::Make();
}

//
// SkM44
//

//SkM44 & operator=(const SkM44 &src)
//bool operator==(const SkM44 &other)
//bool operator!=(const SkM44 &other)
//SkV4 operator*(const SkV4 &v)
//SkV3 operator*(SkV3 v)

SkM44 *SkM44_new(const SkM44 *src) {
    return new SkM44(*src);
}

SkM44 *SkM44_new_2(const SkMatrix *src) {
    return new SkM44(*src);
}

SkM44 *SkM44_new_3() {
    return new SkM44();
}

SkM44 *SkM44_new_4(const SkM44 *a, const SkM44*b) {
    return new SkM44(*a, *b);
}

SkM44 *SkM44_new_5(SkScalar m0, SkScalar m4, SkScalar m8, SkScalar m12, SkScalar m1, SkScalar m5, SkScalar m9, SkScalar m13, SkScalar m2, SkScalar m6, SkScalar m10, SkScalar m14, SkScalar m3, SkScalar m7, SkScalar m11, SkScalar m15) {
    return new SkM44(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15);
}

void SkM44_getColMajor(SkM44 *m44, SkScalar v[]) {
    m44->getColMajor(v);
}

void SkM44_getRowMajor(SkM44 *m44, SkScalar v[]) {
    m44->getRowMajor(v);
}

SkScalar SkM44_rc(SkM44 *m44, int r, int c) {
    return m44->rc(r, c);
}

void SkM44_setRC(SkM44 *m44, int r, int c, SkScalar value) {
    m44->setRC(r, c, value);
}

SkV4 SkM44_row(SkM44 *m44, int i) {
    return m44->row(i);
}

SkV4 SkM44_col(SkM44 *m44, int i) {
    return m44->col(i);
}

void SkM44_setRow(SkM44 *m44, int i, const SkV4 *v) {
    m44->setRow(i, *v);
}

void SkM44_setCol(SkM44 *m44, int i, const SkV4 *v) {
    m44->setCol(i, *v);
}

SkM44 SkM44_setIdentity(SkM44 *m44) {
    return m44->setIdentity();
}

SkM44 SkM44_setTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return m44->setTranslate(x, y, z);
}

SkM44 SkM44_setScale(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return m44->setScale(x, y, z);
}

SkM44 SkM44_setRotateUnitSinCos(SkM44 *m44, SkV3 axis, SkScalar sinAngle, SkScalar cosAngle) {
    return m44->setRotateUnitSinCos(axis, sinAngle, cosAngle);
}

SkM44 SkM44_setRotateUnit(SkM44 *m44, SkV3 axis, SkScalar radians) {
    return m44->setRotateUnit(axis, radians);
}

SkM44 SkM44_setRotate(SkM44 *m44, SkV3 axis, SkScalar radians) {
    return m44->setRotate(axis, radians);
}

SkM44 SkM44_setConcat(SkM44 *m44, const SkM44 *a, const SkM44 *b) {
    return m44->setConcat(*a, *b);
}

SkM44 SkM44_preConcat(SkM44 *m44, const SkM44 *m) {
    return m44->preConcat(*m);
}

SkM44 SkM44_preConcat_2(SkM44 *m44, const SkMatrix *matrix) {
    return m44->preConcat(*matrix);
}

SkM44 SkM44_postConcat(SkM44 *m44, const SkM44 *m) {
    return m44->postConcat(*m);
}

void SkM44_normalizePerspective(SkM44 *m44) {
    m44->normalizePerspective();
}

bool SkM44_isFinite(SkM44 *m44) {
    return m44->isFinite();
}

bool SkM44_invert(SkM44 *m44, SkM44 *inverse) {
    return m44->invert(inverse);
}

SkM44 SkM44_transpose(SkM44 *m44) {
    return m44->transpose();
}

void SkM44_dump(SkM44 *m44) {
    m44->dump();
}

SkV4 SkM44_map(SkM44 *m44, float x, float y, float z, float w) {
    return m44->map(x, y, z, w);
}

SkMatrix SkM44_asM33(SkM44 *m44) {
    return m44->asM33();
}

SkM44 SkM44_preTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return m44->preTranslate(x, y, z);
}

SkM44 SkM44_postTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return m44->postTranslate(x, y, z);
}

SkM44 SkM44_preScale(SkM44 *m44, SkScalar x, SkScalar y) {
    return m44->preScale(x, y);
}

SkM44 SkM44_preScale_2(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return m44->preScale(x, y, z);
}

// static

SkM44 SkM44_Rows(const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3) {
    return SkM44::Rows(*r0, *r1, *r2, *r3);
}

SkM44 SkM44_Cols(const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3) {
    return SkM44::Cols(*c0, *c1, *c2, *c3);
}

SkM44 SkM44_RowMajor(const SkScalar r[16]) {
    return SkM44::RowMajor(r);
}

SkM44 SkM44_ColMajor(const SkScalar c[16]) {
    return SkM44::ColMajor(c);
}

SkM44 SkM44_Translate(SkScalar x, SkScalar y, SkScalar z) {
    return SkM44::Translate(x, y, z);
}

SkM44 SkM44_Scale(SkScalar x, SkScalar y, SkScalar z) {
    return SkM44::Scale(x, y, z);
}

SkM44 SkM44_Rotate(SkV3 axis, SkScalar radians) {
    return SkM44::Rotate(axis, radians);
}

SkM44 SkM44_RectToRect(const SkRect *src, const SkRect *dst) {
    return SkM44::RectToRect(*src, *dst);
}

SkM44 SkM44_LookAt(const SkV3 *eye, const SkV3 *center, const SkV3 *up) {
    return SkM44::LookAt(*eye, *center, *up);
}

SkM44 SkM44_Perspective(float near, float far, float angle) {
    return SkM44::Perspective(near, far, angle);
}

//
// SkMaskFilter
//

SkRect SkMaskFilter_approximateFilteredBounds(SkMaskFilter *mask_filter, const SkRect *src) {
    return mask_filter->approximateFilteredBounds(*src);
}

SkMaskFilter::Factory SkMaskFilter_getFactory(SkMaskFilter *mask_filter) {
    return mask_filter->getFactory();
}

const char * SkMaskFilter_getTypeName(SkMaskFilter *mask_filter) {
    return mask_filter->getTypeName();
}

void SkMaskFilter_flatten(SkMaskFilter *mask_filter, SkWriteBuffer *buffer) {
    return mask_filter->flatten(*buffer);
}

SkMaskFilter::Type SkMaskFilter_getFlattenableType(SkMaskFilter *mask_filter) {
    return mask_filter->getFlattenableType();
}

sk_sp<SkData> SkMaskFilter_serialize(SkMaskFilter *mask_filter, const SkSerialProcs *procs) {
    return mask_filter->serialize(procs);
}

size_t SkMaskFilter_serialize_2(SkMaskFilter *mask_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return mask_filter->serialize(memory, memory_size, procs);
}

bool SkMaskFilter_unique(SkMaskFilter *mask_filter) {
    return mask_filter->unique();
}

void SkMaskFilter_ref(SkMaskFilter *mask_filter) {
    return mask_filter->ref();
}

void SkMaskFilter_unref(SkMaskFilter *mask_filter) {
    return mask_filter->unref();
}


// static

void SkMaskFilter_MakeBlur(const char *sk_mask_filter_key_out, SkBlurStyle style, SkScalar sigma, bool respectCTM) {
    static_sk_mask_filter[sk_mask_filter_key_out] = SkMaskFilter::MakeBlur(style, sigma, respectCTM);
}

void SkMaskFilter_Deserialize(const char *sk_mask_filter_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_mask_filter[sk_mask_filter_key_out] = SkMaskFilter::Deserialize(data, size, procs);
}

SkMaskFilter::Factory SkMaskFilter_NameToFactory(const char name[]) {
    return SkMaskFilter::NameToFactory(name);
}

const char * SkMaskFilter_FactoryToName(SkMaskFilter::Factory factory) {
    return SkMaskFilter::FactoryToName(factory);
}

void SkMaskFilter_Register(const char name[], SkMaskFilter::Factory factory) {
    SkMaskFilter::Register(name, factory);
}

//
// SkMatrix
//

// SkScalar operator[](int index)
// SkScalar & operator[](int index)

SkMatrix *SkMatrix_new(SkMatrix *matrix) {
    return new SkMatrix();
}

SkMatrix::TypeMask SkMatrix_getType(SkMatrix *matrix) {
    return matrix->getType();
}

bool SkMatrix_isIdentity(SkMatrix *matrix) {
    return matrix->isIdentity();
}

bool SkMatrix_isScaleTranslate(SkMatrix *matrix) {
    return matrix->isScaleTranslate();
}

bool SkMatrix_isTranslate(SkMatrix *matrix) {
    return matrix->isTranslate();
}

bool SkMatrix_rectStaysRect(SkMatrix *matrix) {
    return matrix->rectStaysRect();
}

bool SkMatrix_preservesAxisAlignment(SkMatrix *matrix) {
    return matrix->preservesAxisAlignment();
}

bool SkMatrix_hasPerspective(SkMatrix *matrix) {
    return matrix->hasPerspective();
}

bool SkMatrix_isSimilarity(SkMatrix *matrix, SkScalar tol) {
    return matrix->isSimilarity(tol);
}

bool SkMatrix_preservesRightAngles(SkMatrix *matrix, SkScalar tol) {
    return matrix->preservesRightAngles(tol);
}

SkScalar SkMatrix_get(SkMatrix *matrix, int index) {
    return matrix->get(index);
}

SkScalar SkMatrix_rc(SkMatrix *matrix, int r, int c) {
    return matrix->rc(r, c);
}

SkScalar SkMatrix_getScaleX(SkMatrix *matrix) {
    return matrix->getScaleX();
}

SkScalar SkMatrix_getScaleY(SkMatrix *matrix) {
    return matrix->getScaleY();
}

SkScalar SkMatrix_getSkewY(SkMatrix *matrix) {
    return matrix->getSkewY();
}

SkScalar SkMatrix_getSkewX(SkMatrix *matrix) {
    return matrix->getSkewX();
}

SkScalar SkMatrix_getTranslateX(SkMatrix *matrix) {
    return matrix->getTranslateX();
}

SkScalar SkMatrix_getTranslateY(SkMatrix *matrix) {
    return matrix->getTranslateY();
}

SkScalar SkMatrix_getPerspX(SkMatrix *matrix) {
    return matrix->getPerspX();
}

SkScalar SkMatrix_getPerspY(SkMatrix *matrix) {
    return matrix->getPerspY();
}

SkMatrix SkMatrix_set(SkMatrix *matrix, int index, SkScalar value) {
    return matrix->set(index, value);
}

SkMatrix SkMatrix_setScaleX(SkMatrix *matrix, SkScalar v) {
    return matrix->setScaleX(v);
}

SkMatrix SkMatrix_setScaleY(SkMatrix *matrix, SkScalar v) {
    return matrix->setScaleY(v);
}

SkMatrix SkMatrix_setSkewY(SkMatrix *matrix, SkScalar v) {
    return matrix->setSkewY(v);
}

SkMatrix SkMatrix_setSkewX(SkMatrix *matrix, SkScalar v) {
    return matrix->setSkewX(v);
}

SkMatrix SkMatrix_setTranslateX(SkMatrix *matrix, SkScalar v) {
    return matrix->setTranslateX(v);
}

SkMatrix SkMatrix_setTranslateY(SkMatrix *matrix, SkScalar v) {
    return matrix->setTranslateY(v);
}

SkMatrix SkMatrix_setPerspX(SkMatrix *matrix, SkScalar v) {
    return matrix->setPerspX(v);
}

SkMatrix SkMatrix_setPerspY(SkMatrix *matrix, SkScalar v) {
    return matrix->setPerspY(v);
}

SkMatrix SkMatrix_setAll(SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) {
    return matrix->setAll(scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2);
}

void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]) {
    matrix->get9(buffer);
}

SkMatrix SkMatrix_set9(SkMatrix *matrix, const SkScalar buffer[9]) {
    return matrix->set9(buffer);
}

SkMatrix SkMatrix_reset(SkMatrix *matrix) {
    return matrix->reset();
}

SkMatrix SkMatrix_setIdentity(SkMatrix *matrix) {
    return matrix->setIdentity();
}

SkMatrix SkMatrix_setTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return matrix->setTranslate(dx, dy);
}

SkMatrix SkMatrix_setTranslate_2(SkMatrix *matrix, const SkVector *v) {
    return matrix->setTranslate(*v);
}

SkMatrix SkMatrix_setScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return matrix->setScale(sx, sy, px, py);
}

SkMatrix SkMatrix_setScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return matrix->setScale(sx, sy);
}

SkMatrix SkMatrix_setRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return matrix->setRotate(degrees, px, py);
}

SkMatrix SkMatrix_setRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return matrix->setRotate(degrees);
}

SkMatrix SkMatrix_setSinCos(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) {
    return matrix->setSinCos(sinValue, cosValue, px, py);
}

SkMatrix SkMatrix_setSinCos_2(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) {
    return matrix->setSinCos(sinValue, cosValue);
}

SkMatrix SkMatrix_setRSXform(SkMatrix *matrix, const SkRSXform *rsxForm) {
    return matrix->setRSXform(*rsxForm);
}

SkMatrix SkMatrix_setSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return matrix->setSkew(kx, ky, px, py);
}

SkMatrix SkMatrix_setSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return matrix->setSkew(kx, ky);
}

SkMatrix SkMatrix_setConcat(SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) {
    return matrix->setConcat(*a, *b);
}

SkMatrix SkMatrix_preTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return matrix->preTranslate(dx, dy);
}

SkMatrix SkMatrix_preScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return matrix->preScale(sx, sy, px, py);
}

SkMatrix SkMatrix_preScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return matrix->preScale(sx, sy);
}

SkMatrix SkMatrix_preRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return matrix->preRotate(degrees, px, py);
}

SkMatrix SkMatrix_preRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return matrix->preRotate(degrees);
}

SkMatrix SkMatrix_preSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return matrix->preSkew(kx, ky, px, py);
}

SkMatrix SkMatrix_preSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return matrix->preSkew(kx, ky);
}

SkMatrix SkMatrix_preConcat(SkMatrix *matrix, const SkMatrix *other) {
    return matrix->preConcat(*other);
}

SkMatrix SkMatrix_postTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return matrix->postTranslate(dx, dy);
}

SkMatrix SkMatrix_postScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return matrix->postScale(sx, sy, px, py);
}

SkMatrix SkMatrix_postScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return matrix->postScale(sx, sy);
}

SkMatrix SkMatrix_postRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return matrix->postRotate(degrees, px, py);
}

SkMatrix SkMatrix_postRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return matrix->postRotate(degrees);
}

SkMatrix SkMatrix_postSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return matrix->postSkew(kx, ky, px, py);
}

SkMatrix SkMatrix_postSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return matrix->postSkew(kx, ky);
}

SkMatrix SkMatrix_postConcat(SkMatrix *matrix, const SkMatrix *other) {
    return matrix->postConcat(*other);
}

bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) {
    return matrix->setRectToRect(*src, *dst, stf);
}

bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count) {
    return matrix->setPolyToPoly(src, dst, count);
}

bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse) {
    return matrix->invert(inverse);
}

bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]) {
    return matrix->asAffine(affine);
}

SkMatrix SkMatrix_setAffine(SkMatrix *matrix, const SkScalar affine[6]) {
    return matrix->setAffine(affine);
}

void SkMatrix_normalizePerspective(SkMatrix *matrix) {
    matrix->normalizePerspective();
}

void SkMatrix_mapPoints(SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count) {
    matrix->mapPoints(dst, src, count);
}

void SkMatrix_mapPoints_2(SkMatrix *matrix, SkPoint pts[], int count) {
    matrix->mapPoints(pts, count);
}

void SkMatrix_mapHomogeneousPoints(SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count) {
    matrix->mapHomogeneousPoints(dst, src, count);
}

void SkMatrix_mapHomogeneousPoints_2(SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count) {
    matrix->mapHomogeneousPoints(dst, src, count);
}

SkPoint SkMatrix_mapPoint(SkMatrix *matrix, SkPoint pt) {
    return matrix->mapPoint(pt);
}

void SkMatrix_mapXY(SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result) {
    matrix->mapXY(x, y, result);
}

SkPoint SkMatrix_mapXY_2(SkMatrix *matrix, SkScalar x, SkScalar y) {
    return matrix->mapXY(x, y);
}

SkPoint SkMatrix_mapOrigin(SkMatrix *matrix) {
    return matrix->mapOrigin();
}

void SkMatrix_mapVectors(SkMatrix *matrix, SkVector dst[], const SkVector src[], int count) {
    matrix->mapVectors(dst, src, count);
}

void SkMatrix_mapVectors_2(SkMatrix *matrix, SkVector vecs[], int count) {
    matrix->mapVectors(vecs, count);
}

void SkMatrix_mapVector(SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result) {
    matrix->mapVector(dx, dy, result);
}

SkVector SkMatrix_mapVector_2(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return matrix->mapVector(dx, dy);
}

bool SkMatrix_mapRect(SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(dst, *src, pc);
}

bool SkMatrix_mapRect_2(SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(rect, pc);
}

SkRect SkMatrix_mapRect_3(SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(*src, pc);
}

void SkMatrix_mapRectToQuad(SkMatrix *matrix, SkPoint dst[4], const SkRect *rect) {
    matrix->mapRectToQuad(dst, *rect);
}

void SkMatrix_mapRectScaleTranslate(SkMatrix *matrix, SkRect *dst, const SkRect *src) {
    matrix->mapRectScaleTranslate(dst, *src);
}

SkScalar SkMatrix_mapRadius(SkMatrix *matrix, SkScalar radius) {
    return matrix->mapRadius(radius);
}

void SkMatrix_dump(SkMatrix *matrix) {
    matrix->dump();
}

SkScalar SkMatrix_getMinScale(SkMatrix *matrix) {
    return matrix->getMinScale();
}

SkScalar SkMatrix_getMaxScale(SkMatrix *matrix) {
    return matrix->getMaxScale();
}

bool SkMatrix_getMinMaxScales(SkMatrix *matrix, SkScalar scaleFactors[2]) {
    return matrix->getMinMaxScales(scaleFactors);
}

bool SkMatrix_decomposeScale(SkMatrix *matrix, SkSize *scale, SkMatrix *remaining) {
    return matrix->decomposeScale(scale, remaining);
}

void SkMatrix_dirtyMatrixTypeCache(SkMatrix *matrix) {
    matrix->dirtyMatrixTypeCache();
}

void SkMatrix_setScaleTranslate(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty) {
    matrix->setScaleTranslate(sx, sy, tx, ty);
}

bool SkMatrix_isFinite(SkMatrix *matrix) {
    return matrix->isFinite();
}


// static

SkMatrix SkMatrix_Scale(SkScalar sx, SkScalar sy) {
    return SkMatrix::Scale(sx, sy);
}

SkMatrix SkMatrix_Translate(SkScalar dx, SkScalar dy) {
    return SkMatrix::Translate(dx, dy);
}

SkMatrix SkMatrix_Translate_2(SkVector t) {
    return SkMatrix::Translate(t);
}

SkMatrix SkMatrix_Translate_3(SkIVector t) {
    return SkMatrix::Translate(t);
}

SkMatrix SkMatrix_RotateDeg(SkScalar deg) {
    return SkMatrix::RotateDeg(deg);
}

SkMatrix SkMatrix_RotateDeg_2(SkScalar deg, SkPoint pt) {
    return SkMatrix::RotateDeg(deg, pt);
}

SkMatrix SkMatrix_RotateRad(SkScalar rad) {
    return SkMatrix::RotateRad(rad);
}

SkMatrix SkMatrix_Skew(SkScalar kx, SkScalar ky) {
    return SkMatrix::Skew(kx, ky);
}

SkMatrix SkMatrix_RectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) {
    return SkMatrix::RectToRect(*src, *dst, mode);
}

SkMatrix SkMatrix_MakeAll(SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2) {
    return SkMatrix::MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2);
}

SkMatrix SkMatrix_MakeRectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) {
    return SkMatrix::MakeRectToRect(*src, *dst, stf);
}

void SkMatrix_SetAffineIdentity(SkScalar affine[6]) {
    SkMatrix::SetAffineIdentity(affine);
}

SkMatrix SkMatrix_I() {
    return SkMatrix::I();
}

SkMatrix SkMatrix_InvalidMatrix() {
    return SkMatrix::InvalidMatrix();
}

SkMatrix SkMatrix_Concat(const SkMatrix *a, const SkMatrix *b) {
    return SkMatrix::Concat(*a, *b);
}

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

void SkRect_MakeXYWH(const char *sk_rect_key_out, float x, float y, float w, float h) {
    static_sk_rect[sk_rect_key_out] = SkRect::MakeXYWH(x, y, w, h);
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

bool SkRefCntBase_unique(SkRefCntBase *ref_cnt_base) {
    return ref_cnt_base->unique();
}

void SkRefCntBase_ref(SkRefCntBase *ref_cnt_base) {
    ref_cnt_base->ref();
}

void SkRefCntBase_unref(SkRefCntBase *ref_cnt_base) {
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

//
// SkRGBA4f<kAT> Struct Template
//

/*
const float * vec()
float * vec()
std::array<float, 4> array()
float operator[](int index)
float & operator[](int index)
bool isOpaque()
bool fitsInBytes()
SkColor toSkColor()
SkRGBA4f<kPremul_SkAlphaType> premul()
SkRGBA4f<kUnpremul_SkAlphaType> unpremul()
uint32_t toBytes_RGBA()
SkRGBA4f makeOpaque()

// static

SkRGBA4f FromColor(SkColor color)
SkRGBA4f FromPMColor(SkPMColor)
SkRGBA4f FromBytes_RGBA(uint32_t color)
*/

//
// SkRRect
//

//SkRRect & operator=(const SkRRect &rrect)

SkRRect *SkRRect_new() {
    return new SkRRect();
}

SkRRect *SkRRect_new_2(const SkRRect &rrect) {
    return new SkRRect(rrect);
}

SkRRect::Type getType(SkRRect *rrect) {
    return rrect->getType();
}

SkRRect::Type type(SkRRect *rrect) {
    return rrect->type();
}

bool SkRRect_isEmpty(SkRRect *rrect) {
    return rrect->isEmpty();
}

bool SkRRect_isRect(SkRRect *rrect) {
    return rrect->isRect();
}

bool SkRRect_isOval(SkRRect *rrect) {
    return rrect->isOval();
}

bool SkRRect_isSimple(SkRRect *rrect) {
    return rrect->isSimple();
}

bool SkRRect_isNinePatch(SkRRect *rrect) {
    return rrect->isNinePatch();
}

bool SkRRect_isComplex(SkRRect *rrect) {
    return rrect->isComplex();
}

SkScalar SkRRect_width(SkRRect *rrect) {
    return rrect->width();
}

SkScalar SkRRect_height(SkRRect *rrect) {
    return rrect->height();
}

SkVector SkRRect_getSimpleRadii(SkRRect *rrect) {
    return rrect->getSimpleRadii();
}

void SkRRect_setEmpty(SkRRect *rrect, SkRRect *rrect_2) {
    rrect->setEmpty();
}

void SkRRect_setRect(SkRRect *rrect, const SkRect &rect) {
    rrect->setRect(rect);
}

void SkRRect_setOval(SkRRect *rrect, const SkRect &oval) {
    rrect->setOval(oval);
}

void SkRRect_setRectXY(SkRRect *rrect, const SkRect &rect, SkScalar xRad, SkScalar yRad) {
    rrect->setRectXY(rect, xRad, yRad);
}

void SkRRect_setNinePatch(SkRRect *rrect, const SkRect &rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad) {
    rrect->setNinePatch(rect, leftRad, topRad, rightRad, bottomRad);
}

void SkRRect_setRectRadii(SkRRect *rrect, const SkRect &rect, const SkVector radii[4]) {
    rrect->setRectRadii(rect, radii);
}

const SkRect & SkRRect_rect(SkRRect *rrect) {
    return rrect->rect();
}

SkVector SkRRect_radii(SkRRect *rrect, SkRRect::Corner corner) {
    return rrect->radii(corner);
}

const SkRect & SkRRect_getBounds(SkRRect *rrect) {
    return rrect->getBounds();
}

void SkRRect_inset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst) {
    rrect->inset(dx, dy, dst);
}

void SkRRect_inset_2(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->inset(dx, dy);
}

void SkRRect_outset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst) {
    rrect->outset(dx, dy, dst);
}

void SkRRect_outset_2(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->outset(dx, dy);
}

void SkRRect_offset(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->offset(dx, dy);
}

SkRRect SkRRect_makeOffset(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    return rrect->makeOffset(dx, dy);
}

bool SkRRect_contains(SkRRect *rrect, const SkRect &rect) {
    return rrect->contains(rect);
}

bool SkRRect_isValid(SkRRect *rrect) {
    return rrect->isValid();
}

size_t SkRRect_writeToMemory(SkRRect *rrect, void *buffer) {
    return rrect->writeToMemory(buffer);
}

size_t SkRRect_readFromMemory(SkRRect *rrect, const void *buffer, size_t length) {
    return rrect->readFromMemory(buffer, length);
}

bool SkRRect_transform(SkRRect *rrect, const SkMatrix &matrix, SkRRect *dst) {
    return rrect->transform(matrix, dst);
}

void SkRRect_dump(SkRRect *rrect, bool asHex) {
    rrect->dump(asHex);
}

SkString SkRRect_dumpToString(SkRRect *rrect, bool asHex) {
    return rrect->dumpToString(asHex);
}

void SkRRect_dump_2(SkRRect *rrect) {
    rrect->dump();
}

void SkRRect_dumpHex(SkRRect *rrect) {
    rrect->dumpHex();
}

// static

SkRRect SkRRect_MakeEmpty() {
    return SkRRect::MakeEmpty();
}

SkRRect SkRRect_MakeRect(const SkRect &r) {
    return SkRRect::MakeRect(r);
}

SkRRect SkRRect_MakeOval(const SkRect &oval) {
    return SkRRect::MakeOval(oval);
}

SkRRect SkRRect_MakeRectXY(const SkRect &rect, SkScalar xRad, SkScalar yRad) {
    return SkRRect::MakeRectXY(rect, xRad, yRad);
}

//
// SkRSXform
//

bool SkRSXform_rectStaysRect(SkRSXform *rsx_form) {
    return rsx_form->rectStaysRect();
}

void SkRSXform_setIdentity(SkRSXform *rsx_form) {
    rsx_form->setIdentity();
}

void SkRSXform_set(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) {
    rsx_form->set(scos, ssin, tx, ty);
}

void SkRSXform_toQuad(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint quad[4]) {
    rsx_form->toQuad(width, height, quad);
}

void SkRSXform_toQuad_2(SkRSXform *rsx_form, const SkSize &size, SkPoint quad[4]) {
    rsx_form->toQuad(size, quad);
}

void SkRSXform_toTriStrip(SkRSXform *rsx_form, SkScalar width, SkScalar height, SkPoint strip[4]) {
    rsx_form->toTriStrip(width, height, strip);
}

// static

SkRSXform SkRSXform_Make(SkRSXform *rsx_form, SkScalar scos, SkScalar ssin, SkScalar tx, SkScalar ty) {
    return SkRSXform::Make(scos, ssin, tx, ty);
}

SkRSXform SkRSXform_MakeFromRadians(SkRSXform *rsx_form, SkScalar scale, SkScalar radians, SkScalar tx, SkScalar ty, SkScalar ax, SkScalar ay) {
    return SkRSXform::MakeFromRadians(scale, radians, tx, ty, ax, ay);
}

//
// SkRTreeFactory
//

//sk_sp<SkBBoxHierarchy> operator()() const override

//
// SkRuntimeBlendBuilder
//

//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete

SkRuntimeBlendBuilder *SkRuntimeBlendBuilder_new(sk_sp<SkRuntimeEffect> runtime_effect) {
    return new SkRuntimeBlendBuilder(runtime_effect);
}
void SkRuntimeBlendBuilder_delete(SkRuntimeBlendBuilder *runtime_blend_builder) {
    delete runtime_blend_builder;
}
sk_sp<SkBlender> SkRuntimeBlendBuilder_makeBlender(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->makeBlender();
}

const SkRuntimeEffect * SkRuntimeBlendBuilder_effect(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->effect();
}

SkRuntimeBlendBuilder::BuilderUniform SkRuntimeBlendBuilder_uniform(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name) {
    return runtime_blend_builder->uniform(name);
}

SkRuntimeBlendBuilder::BuilderChild SkRuntimeBlendBuilder_child(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name) {
    return runtime_blend_builder->child(name);
}

sk_sp<const SkData> SkRuntimeBlendBuilder_uniforms(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->uniforms();
}

SkSpan<const SkRuntimeEffect::ChildPtr> SkRuntimeBlendBuilder_children(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->children();
}

//
// SkRuntimeColorFilterBuilder
//

//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete

SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(sk_sp<SkRuntimeEffect> runtime_effect) {
    return new SkRuntimeColorFilterBuilder(runtime_effect);
}

void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    delete runtime_color_filter_builder;
}

sk_sp<SkColorFilter> SkRuntimeColorFilterBuilder_makeColorFilter(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->makeColorFilter();
}

const SkRuntimeEffect * SkRuntimeColorFilterBuilder_effect(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->effect();
}

SkRuntimeColorFilterBuilder::BuilderUniform SkRuntimeColorFilterBuilder_uniform(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name) {
    return runtime_color_filter_builder->uniform(name);
}

SkRuntimeColorFilterBuilder::BuilderChild SkRuntimeColorFilterBuilder_child(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name) {
    return runtime_color_filter_builder->child(name);
}

sk_sp<const SkData> SkRuntimeColorFilterBuilder_uniforms(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->uniforms();
}

SkSpan<const SkRuntimeEffect::ChildPtr> SkRuntimeColorFilterBuilder_children(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->children();
}

//
// SkRuntimeEffect
//

void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect) {
    delete runtime_effect;
}

sk_sp<SkShader> SkRuntimeEffect_makeShader(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix) {
    return runtime_effect->makeShader(uniforms, children, childCount, localMatrix);
}

sk_sp<SkShader> SkRuntimeEffect_makeShader_2(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children, const SkMatrix *localMatrix) {
    return runtime_effect->makeShader(uniforms, children, localMatrix);
}

sk_sp<SkColorFilter> SkRuntimeEffect_makeColorFilter(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms) {
    return runtime_effect->makeColorFilter(uniforms);
}

sk_sp<SkColorFilter> SkRuntimeEffect_makeColorFilter_2(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, sk_sp<SkColorFilter> children[], size_t childCount) {
    return runtime_effect->makeColorFilter(uniforms, children, childCount);
}

sk_sp<SkColorFilter> SkRuntimeEffect_makeColorFilter_3(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children) {
    return runtime_effect->makeColorFilter(uniforms, children);
}

sk_sp<SkBlender> SkRuntimeEffect_makeBlender(SkRuntimeEffect *runtime_effect, sk_sp<const SkData> uniforms, SkSpan<const SkRuntimeEffect::ChildPtr> children) {
    return runtime_effect->makeBlender(uniforms, children);
}

const std::string & SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->source();
}

size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->uniformSize();
}

SkSpan<const SkRuntimeEffect::Uniform> SkRuntimeEffect_uniforms(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->uniforms();
}

SkSpan<const SkRuntimeEffect::Child> SkRuntimeEffect_children(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->children();
}

const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, std::string_view name) {
    return runtime_effect->findUniform(name);
}

const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, std::string_view name) {
    return runtime_effect->findChild(name);
}

bool SkRuntimeEffect_allowShader(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowShader();
}

bool SkRuntimeEffect_allowColorFilter(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowColorFilter();
}

bool SkRuntimeEffect_allowBlender(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->allowBlender();
}

bool SkRuntimeEffect_unique(SkRuntimeEffect *runtime_effect) {
    return runtime_effect->unique();
}

void SkRuntimeEffect_ref(SkRuntimeEffect *runtime_effect) {
    runtime_effect->ref();
}

void SkRuntimeEffect_unref(SkRuntimeEffect *runtime_effect) {
    runtime_effect->unref();
}

// static

SkRuntimeEffect::Result SkRuntimeEffect_MakeForColorFilter(SkString sksl, const SkRuntimeEffect::Options &options) {
    return SkRuntimeEffect::MakeForColorFilter(sksl, options);
}

SkRuntimeEffect::Result SkRuntimeEffect_MakeForColorFilter_2(SkString sksl) {
    return SkRuntimeEffect::MakeForColorFilter(sksl);
}

SkRuntimeEffect::Result SkRuntimeEffect_MakeForShader(SkString sksl, const SkRuntimeEffect::Options &options) {
    return SkRuntimeEffect::MakeForShader(sksl, options);
}

SkRuntimeEffect::Result SkRuntimeEffect_MakeForShader_2(SkString sksl) {
    return SkRuntimeEffect::MakeForShader(sksl);
}

SkRuntimeEffect::Result SkRuntimeEffect_MakeForBlender(SkString sksl, const SkRuntimeEffect::Options &options) {
    return SkRuntimeEffect::MakeForBlender(sksl, options);
}

SkRuntimeEffect::Result SkRuntimeEffect_MakeForBlender_2(SkString sksl) {
    return SkRuntimeEffect::MakeForBlender(sksl);
}

SkRuntimeEffect::TracedShader SkRuntimeEffect_MakeTraced(sk_sp<SkShader> shader, const SkIPoint &traceCoord) {
    return SkRuntimeEffect::MakeTraced(shader, traceCoord);
}

void SkRuntimeEffect_RegisterFlattenables() {
    SkRuntimeEffect::RegisterFlattenables();
}

//
// SkRuntimeEffectBuilder
//

const SkRuntimeEffect * SkRuntimeEffectBuilder_effect(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return runtime_effect_builder->effect();
}

SkRuntimeEffectBuilder::BuilderUniform SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->uniform(name);
}

SkRuntimeEffectBuilder::BuilderChild SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->child(name);
}

sk_sp<const SkData> SkRuntimeEffectBuilder_uniforms(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return runtime_effect_builder->uniforms();
}

SkSpan<const SkRuntimeEffect::ChildPtr> SkRuntimeEffectBuilder_children(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return runtime_effect_builder->children();
}

// static

// SkRuntimeEffectBuilder()=delete
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect)
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect, sk_sp<SkData> uniforms)
// SkRuntimeEffectBuilder(SkRuntimeEffectBuilder &&)
// SkRuntimeEffectBuilder(const SkRuntimeEffectBuilder &)
// SkRuntimeEffectBuilder & operator=(SkRuntimeEffectBuilder &&)=delete
// SkRuntimeEffectBuilder & operator=(const SkRuntimeEffectBuilder &)=delete

//
// SkRuntimeShaderBuilder
//

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new(sk_sp<SkRuntimeEffect> effect) {
    return new SkRuntimeShaderBuilder(effect);
}

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new_2(const SkRuntimeShaderBuilder &builder) {
    return new SkRuntimeShaderBuilder(builder);
}

void SkRuntimeShaderBuilder_delete(SkRuntimeShaderBuilder *runtime_shader_builder) {
    delete runtime_shader_builder;
}

sk_sp<SkShader> SkRuntimeShaderBuilder_makeShader(SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix) {
    return runtime_shader_builder->makeShader(localMatrix);
}

const SkRuntimeEffect * SkRuntimeShaderBuilder_effect(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return runtime_shader_builder->effect();
}

SkRuntimeShaderBuilder::BuilderUniform SkRuntimeShaderBuilder_uniform(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name) {
    return runtime_shader_builder->uniform(name);
}

SkRuntimeShaderBuilder::BuilderChild SkRuntimeShaderBuilder_child(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name) {
    return runtime_shader_builder->child(name);
}

sk_sp<const SkData> SkRuntimeShaderBuilder_uniforms(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return runtime_shader_builder->uniforms();
}

SkSpan<const SkRuntimeEffect::ChildPtr> SkRuntimeShaderBuilder_children(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return runtime_shader_builder->children();
}

//
// SkSamplingOptions
//

//bool operator==(const SkSamplingOptions &other)
//bool operator!=(const SkSamplingOptions &other)

SkSamplingOptions *SkSamplingOptions_new() {
    return new SkSamplingOptions();
}

SkSamplingOptions *SkSamplingOptions_new_2(const SkSamplingOptions &options) {
    return new SkSamplingOptions(options);
}

//SkSamplingOptions *SkSamplingOptions_new_3 & operator=(const SkSamplingOptions &that) {
//    return new SkSamplingOptions();
//}

SkSamplingOptions *SkSamplingOptions_new_4(SkFilterMode fm, SkMipmapMode mm) {
    return new SkSamplingOptions(fm, mm);
}

SkSamplingOptions *SkSamplingOptions_new_5(SkFilterMode fm) {
    return new SkSamplingOptions(fm);
}

SkSamplingOptions *SkSamplingOptions_new_6(const SkCubicResampler &c) {
    return new SkSamplingOptions(c);
}

bool SkSamplingOptions_isAniso(SkSamplingOptions *sampling_options) {
    return sampling_options->isAniso();
}

// static

SkSamplingOptions SkSamplingOptions_Aniso(int maxAniso) {
    return SkSamplingOptions::Aniso(maxAniso);
}

//
// SkShader
//

bool SkShader_isOpaque(SkShader *shader) {
    return shader->isOpaque();
}

SkImage * SkShader_isAImage(SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]) {
    return shader->isAImage(localMatrix, xy);
}

bool SkShader_isAImage_2(SkShader *shader) {
    return shader->isAImage();
}

sk_sp<SkShader> SkShader_makeWithLocalMatrix(SkShader *shader, const SkMatrix &matrix) {
    return shader->makeWithLocalMatrix(matrix);
}

sk_sp<SkShader> SkShader_makeWithColorFilter(SkShader *shader, sk_sp<SkColorFilter> filter) {
    return shader->makeWithColorFilter(filter);
}

sk_sp<SkShader> SkShader_makeWithWorkingColorSpace(SkShader *shader, sk_sp<SkColorSpace> space) {
    return shader->makeWithWorkingColorSpace(space);
}

SkShader::Factory SkShader_getFactory(SkShader *shader) {
    return shader->getFactory();
}

const char * SkShader_getTypeName(SkShader *shader) {
    return shader->getTypeName();
}

void SkShader_flatten(SkShader *shader, SkWriteBuffer &buffer) {
    shader->flatten(buffer);
}

SkShader::Type SkShader_getFlattenableType(SkShader *shader) {
    return shader->getFlattenableType();
}

sk_sp<SkData> SkShader_serialize(SkShader *shader, const SkSerialProcs *procs) {
    return shader->serialize(procs);
}

size_t SkShader_serialize_2(SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs) {
    return shader->serialize(memory, memory_size, procs);
}

bool SkShader_unique(SkShader *shader) {
    return shader->unique();
}

void SkShader_ref(SkShader *shader) {
    shader->ref();
}

void SkShader_unref(SkShader *shader) {
    shader->unref();
}

// static

SkShader::Factory SkShader_NameToFactory(SkShader *shader, const char name[]) {
    return SkShader::NameToFactory(name);
}

const char * SkShader_FactoryToName(SkShader *shader, SkShader::Factory factory) {
    return SkShader::FactoryToName(factory);
}

void SkShader_Register(SkShader *shader, const char name[], SkShader::Factory factory) {
    SkShader::Register(name, factory);
}

sk_sp<SkFlattenable> SkShader_Deserialize(SkShader *shader, SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs) {
    return SkShader::Deserialize(type, data, length, procs);
}

//
// SkShaderMaskFilter
//

// static

sk_sp<SkMaskFilter> SkShaderMaskFilter_Make(sk_sp<SkShader> shader) {
    return SkShaderMaskFilter::Make(shader);
}

//
// SkShaper
//

//SkShaper *SkShaper_new() {
//    return new SkShaper();
//}

void SkShaper_delete(SkShaper *shaper) {
    delete shaper;
}

void SkShaper_shape(SkShaper *shaper, const char *utf8, size_t utf8Bytes, const SkFont &srcFont, bool leftToRight, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, srcFont, leftToRight, width, handler);
}

void SkShaper_shape_2(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, font, bidi, script, language, width, handler);
}

void SkShaper_shape_3(SkShaper *shaper, const char *utf8, size_t utf8Bytes, SkShaper::FontRunIterator &font, SkShaper::BiDiRunIterator &bidi, SkShaper::ScriptRunIterator &script, SkShaper::LanguageRunIterator &language, const SkShaper::Feature *features, size_t featuresSize, SkScalar width, SkShaper::RunHandler *handler) {
    shaper->shape(utf8, utf8Bytes, font, bidi, script, language, features, featuresSize, width, handler);
}

// static

std::unique_ptr<SkShaper> SkShaper_MakePrimitive() {
    return SkShaper::MakePrimitive();
}

std::unique_ptr<SkShaper> SkShaper_Make(sk_sp<SkFontMgr> font_mgr) {
    return SkShaper::Make(font_mgr);
}

void SkShaper_PurgeCaches() {
    SkShaper::PurgeCaches();
}

std::unique_ptr<SkShaper::FontRunIterator> SkShaper_MakeFontMgrRunIterator(const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback) {
    return SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, font, fallback);
}

std::unique_ptr<SkShaper::FontRunIterator> SkShaper_MakeFontMgrRunIterator_2(const char *utf8, size_t utf8Bytes, const SkFont &font, sk_sp<SkFontMgr> fallback, const char *requestName, SkFontStyle requestStyle, const SkShaper::LanguageRunIterator *language_run_iterator) {
    return SkShaper::MakeFontMgrRunIterator(utf8, utf8Bytes, font, fallback, requestName, requestStyle, language_run_iterator);
}

std::unique_ptr<SkShaper::BiDiRunIterator> SkShaper_MakeBiDiRunIterator(const char *utf8, size_t utf8Bytes, uint8_t bidiLevel) {
    return SkShaper::MakeBiDiRunIterator(utf8, utf8Bytes, bidiLevel);
}

std::unique_ptr<SkShaper::ScriptRunIterator> SkShaper_MakeScriptRunIterator(const char *utf8, size_t utf8Bytes, SkFourByteTag script) {
    return SkShaper::MakeScriptRunIterator(utf8, utf8Bytes, script);
}

std::unique_ptr<SkShaper::LanguageRunIterator> SkShaper_MakeStdLanguageRunIterator(const char *utf8, size_t utf8Bytes) {
    return SkShaper::MakeStdLanguageRunIterator(utf8, utf8Bytes);
}

//
// SkSize Struct
//

void SkSize_set(SkSize *size, SkScalar w, SkScalar h) {
    size->set(w, h);
}

bool SkSize_isZero(SkSize *size) {
    return size->isZero();
}

bool SkSize_isEmpty(SkSize *size) {
    return size->isEmpty();
}

void SkSize_setEmpty(SkSize *size) {
    size->setEmpty();
}

SkScalar SkSize_width(SkSize *size) {
    return size->width();
}

SkScalar SkSize_height(SkSize *size) {
    return size->height();
}

bool SkSize_equals(SkSize *size, SkScalar w, SkScalar h) {
    return size->equals(w, h);
}

SkISize SkSize_toRound(SkSize *size) {
    return size->toRound();
}

SkISize SkSize_toCeil(SkSize *size) {
    return size->toCeil();
}

SkISize SkSize_toFloor(SkSize *size) {
    return size->toFloor();
}

// static

SkSize SkSize_Make(SkScalar w, SkScalar h) {
    return SkSize::Make(w, h);
}

SkSize SkSize_Make_2(const SkISize &src) {
    return SkSize::Make(src);
}

SkSize SkSize_MakeEmpty() {
    return SkSize::MakeEmpty();
}

//
// SkStream
//

//SkStream *SkStream_new() {
//    return new SkStream();
//}

void SkStream_delete(SkStream *stream) {
    delete stream;
}

size_t SkStream_read(SkStream *stream, void *buffer, size_t size) {
    return stream->read(buffer, size);
}

size_t SkStream_skip(SkStream *stream, size_t size) {
    return stream->skip(size);
}

size_t SkStream_peek(SkStream *stream, void *buffer, size_t size) {
    return stream->peek(buffer, size);
}

bool SkStream_isAtEnd(SkStream *stream) {
    return stream->isAtEnd();
}

bool SkStream_readS8(SkStream *stream, int8_t *i) {
    return stream->readS8(i);
}

bool SkStream_readS16(SkStream *stream, int16_t *i) {
    return stream->readS16(i);
}

bool SkStream_readS32(SkStream *stream, int32_t *i) {
    return stream->readS32(i);
}

bool SkStream_readU8(SkStream *stream, uint8_t *i) {
    return stream->readU8(i);
}

bool SkStream_readU16(SkStream *stream, uint16_t *i) {
    return stream->readU16(i);
}

bool SkStream_readU32(SkStream *stream, uint32_t *i) {
    return stream->readU32(i);
}

bool SkStream_readBool(SkStream *stream, bool *b) {
    return stream->readBool(b);
}

bool SkStream_readScalar(SkStream *stream, SkScalar *v) {
    return stream->readScalar(v);
}

bool SkStream_readPackedUInt(SkStream *stream, size_t *size) {
    return stream->readPackedUInt(size);
}

bool SkStream_rewind(SkStream *stream) {
    return stream->rewind();
}

std::unique_ptr<SkStream> SkStream_duplicate(SkStream *stream) {
    return stream->duplicate();
}

std::unique_ptr<SkStream> SkStream_fork(SkStream *stream) {
    return stream->fork();
}

bool SkStream_hasPosition(SkStream *stream) {
    return stream->hasPosition();
}

size_t SkStream_getPosition(SkStream *stream) {
    return stream->getPosition();
}

bool SkStream_seek(SkStream *stream, size_t size) {
    return stream->seek(size);
}

bool SkStream_move(SkStream *stream, long i) {
    return stream->move(i);
}

bool SkStream_hasLength(SkStream *stream) {
    return stream->hasLength();
}

size_t SkStream_getLength(SkStream *stream) {
    return stream->getLength();
}

const void * SkStream_getMemoryBase(SkStream *stream) {
    return stream->getMemoryBase();
}
// static

void SkStream_MakeFromFile(const char *sk_stream_key_out, const char path[]) { // static
    static_sk_stream[sk_stream_key_out] = SkStream::MakeFromFile(path);
}

//
// SkStreamAsset
//

bool SkStreamAsset_hasLength(SkStreamAsset *stream_asset) {
    return stream_asset->hasLength();
}

size_t SkStreamAsset_getLength(SkStreamAsset *stream_asset) {
    return stream_asset->getLength();
}

std::unique_ptr<SkStreamAsset> SkStreamAsset_duplicate(SkStreamAsset *stream_asset) {
    return stream_asset->duplicate();
}

std::unique_ptr<SkStreamAsset> SkStreamAsset_fork(SkStreamAsset *stream_asset) {
    return stream_asset->fork();
}

bool SkStreamAsset_hasPosition(SkStreamAsset *stream_asset) {
    return stream_asset->hasPosition();
}

size_t SkStreamAsset_getPosition(SkStreamAsset *stream_asset) {
    return stream_asset->getPosition();
}

bool SkStreamAsset_seek(SkStreamAsset *stream_asset, size_t position) {
    return stream_asset->seek(position);
}

bool SkStreamAsset_move(SkStreamAsset *stream_asset, long offset) {
    return stream_asset->move(offset);
}

bool SkStreamAsset_rewind(SkStreamAsset *stream_asset) {
    return stream_asset->rewind();
}

size_t SkStreamAsset_read(SkStreamAsset *stream_asset, void *buffer, size_t size) {
    return stream_asset->read(buffer, size);
}

size_t SkStreamAsset_skip(SkStreamAsset *stream_asset, size_t size) {
    return stream_asset->skip(size);
}

size_t SkStreamAsset_peek(SkStreamAsset *stream_asset, void *buffer, size_t size) {
    return stream_asset->peek(buffer, size);
}

bool SkStreamAsset_isAtEnd(SkStreamAsset *stream_asset) {
    return stream_asset->isAtEnd();
}

bool SkStreamAsset_readS8(SkStreamAsset *stream_asset, int8_t *i) {
    return stream_asset->readS8(i);
}

bool SkStreamAsset_readS16(SkStreamAsset *stream_asset, int16_t *i) {
    return stream_asset->readS16(i);
}

bool SkStreamAsset_readS32(SkStreamAsset *stream_asset, int32_t *i) {
    return stream_asset->readS32(i);
}

bool SkStreamAsset_readU8(SkStreamAsset *stream_asset, uint8_t *i) {
    return stream_asset->readU8(i);
}

bool SkStreamAsset_readU16(SkStreamAsset *stream_asset, uint16_t *i) {
    return stream_asset->readU16(i);
}

bool SkStreamAsset_readU32(SkStreamAsset *stream_asset, uint32_t *i) {
    return stream_asset->readU32(i);
}

bool SkStreamAsset_readBool(SkStreamAsset *stream_asset, bool *b) {
    return stream_asset->readBool(b);
}

bool SkStreamAsset_readScalar(SkStreamAsset *stream_asset, SkScalar *v) {
    return stream_asset->readScalar(v);
}

bool SkStreamAsset_readPackedUInt(SkStreamAsset *stream_asset, size_t *size) {
    return stream_asset->readPackedUInt(size);
}

const void * SkStreamAsset_getMemoryBase(SkStreamAsset *stream_asset) {
    return stream_asset->getMemoryBase();
}

// static

std::unique_ptr<SkStreamAsset> SkStreamAsset_MakeFromFile(const char path[]) {
    return SkStreamAsset::MakeFromFile(path);
}

//
// SkStreamMemory
//

const void * SkStreamMemory_getMemoryBase(SkStreamMemory *stream_memory) {
    return stream_memory->getMemoryBase();
}

std::unique_ptr<SkStreamMemory> SkStreamMemory_duplicate(SkStreamMemory *stream_memory) {
    return stream_memory->duplicate();
}

std::unique_ptr<SkStreamMemory> SkStreamMemory_fork(SkStreamMemory *stream_memory) {
    return stream_memory->fork();
}

bool SkStreamMemory_hasLength(SkStreamMemory *stream_memory) {
    return stream_memory->hasLength();
}

size_t SkStreamMemory_getLength(SkStreamMemory *stream_memory) {
    return stream_memory->getLength();
}

bool SkStreamMemory_hasPosition(SkStreamMemory *stream_memory) {
    return stream_memory->hasPosition();
}

size_t SkStreamMemory_getPosition(SkStreamMemory *stream_memory) {
    return stream_memory->getPosition();
}

bool SkStreamMemory_seek(SkStreamMemory *stream_memory, size_t position) {
    return stream_memory->seek(position);
}

bool SkStreamMemory_move(SkStreamMemory *stream_memory, long offset) {
    return stream_memory->move(offset);
}

bool SkStreamMemory_rewind(SkStreamMemory *stream_memory) {
    return stream_memory->rewind();
}

size_t SkStreamMemory_read(SkStreamMemory *stream_memory, void *buffer, size_t size) {
    return stream_memory->read(buffer, size);
}

size_t SkStreamMemory_skip(SkStreamMemory *stream_memory, size_t size) {
    return stream_memory->skip(size);
}

size_t SkStreamMemory_peek(SkStreamMemory *stream_memory, void *buffer, size_t size) {
    return stream_memory->peek(buffer, size);
}

bool SkStreamMemory_isAtEnd(SkStreamMemory *stream_memory) {
    return stream_memory->isAtEnd();
}

bool SkStreamMemory_readS8(SkStreamMemory *stream_memory, int8_t *i) {
    return stream_memory->readS8(i);
}

bool SkStreamMemory_readS16(SkStreamMemory *stream_memory, int16_t *i) {
    return stream_memory->readS16(i);
}

bool SkStreamMemory_readS32(SkStreamMemory *stream_memory, int32_t *i) {
    return stream_memory->readS32(i);
}

bool SkStreamMemory_readU8(SkStreamMemory *stream_memory, uint8_t *i) {
    return stream_memory->readU8(i);
}

bool SkStreamMemory_readU16(SkStreamMemory *stream_memory, uint16_t *i) {
    return stream_memory->readU16(i);
}

bool SkStreamMemory_readU32(SkStreamMemory *stream_memory, uint32_t *i) {
    return stream_memory->readU32(i);
}

bool SkStreamMemory_readBool(SkStreamMemory *stream_memory, bool *b) {
    return stream_memory->readBool(b);
}

bool SkStreamMemory_readScalar(SkStreamMemory *stream_memory, SkScalar *v) {
    return stream_memory->readScalar(v);
}

bool SkStreamMemory_readPackedUInt(SkStreamMemory *stream_memory, size_t *size) {
    return stream_memory->readPackedUInt(size);
}

// static

std::unique_ptr<SkStreamAsset> SkStreamMemory_MakeFromFile(const char path[]) {
    return SkStreamMemory::MakeFromFile(path);
}

//
// SkStreamRewindable
//

bool SkStreamRewindable_rewind(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->rewind();
}

std::unique_ptr<SkStreamRewindable> SkStreamRewindable_duplicate(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->duplicate();
}

size_t SkStreamRewindable_read(SkStreamRewindable *stream_rewindable, void *buffer, size_t size) {
    return stream_rewindable->read(buffer, size);
}

size_t SkStreamRewindable_skip(SkStreamRewindable *stream_rewindable, size_t size) {
    return stream_rewindable->skip(size);
}

size_t SkStreamRewindable_peek(SkStreamRewindable *stream_rewindable, void *buffer, size_t size) {
    return stream_rewindable->peek(buffer, size);
}

bool SkStreamRewindable_isAtEnd(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->isAtEnd();
}

bool SkStreamRewindable_readS8(SkStreamRewindable *stream_rewindable, int8_t *i) {
    return stream_rewindable->readS8(i);
}

bool SkStreamRewindable_readS16(SkStreamRewindable *stream_rewindable, int16_t *i) {
    return stream_rewindable->readS16(i);
}

bool SkStreamRewindable_readS32(SkStreamRewindable *stream_rewindable, int32_t *i) {
    return stream_rewindable->readS32(i);
}

bool SkStreamRewindable_readU8(SkStreamRewindable *stream_rewindable, uint8_t *i) {
    return stream_rewindable->readU8(i);
}

bool SkStreamRewindable_readU16(SkStreamRewindable *stream_rewindable, uint16_t *i) {
    return stream_rewindable->readU16(i);
}

bool SkStreamRewindable_readU32(SkStreamRewindable *stream_rewindable, uint32_t *i) {
    return stream_rewindable->readU32(i);
}

bool SkStreamRewindable_readBool(SkStreamRewindable *stream_rewindable, bool *b) {
    return stream_rewindable->readBool(b);
}

bool SkStreamRewindable_readScalar(SkStreamRewindable *stream_rewindable, SkScalar *v) {
    return stream_rewindable->readScalar(v);
}

bool SkStreamRewindable_readPackedUInt(SkStreamRewindable *stream_rewindable, size_t *size) {
    return stream_rewindable->readPackedUInt(size);
}

std::unique_ptr<SkStream> SkStreamRewindable_fork(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->fork();
}

bool SkStreamRewindable_hasPosition(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->hasPosition();
}

size_t SkStreamRewindable_getPosition(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getPosition();
}

bool SkStreamRewindable_seek(SkStreamRewindable *stream_rewindable, size_t size) {
    return stream_rewindable->seek(size);
}

bool SkStreamRewindable_move(SkStreamRewindable *stream_rewindable, long i) {
    return stream_rewindable->move(i);
}

bool SkStreamRewindable_hasLength(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->hasLength();
}

size_t SkStreamRewindable_getLength(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getLength();
}

const void * SkStreamRewindable_getMemoryBase(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getMemoryBase();
}

// static

std::unique_ptr<SkStreamAsset> SkStreamRewindable_MakeFromFile(const char path[]) {
    return SkStreamRewindable::MakeFromFile(path);
}

//
// SkStreamSeekable
//

std::unique_ptr<SkStreamSeekable> SkStreamSeekable_duplicate(SkStreamSeekable *stream_seekable) {
    return stream_seekable->duplicate();
}

bool SkStreamSeekable_hasPosition(SkStreamSeekable *stream_seekable) {
    return stream_seekable->hasPosition();
}

size_t SkStreamSeekable_getPosition(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getPosition();
}

bool SkStreamSeekable_seek(SkStreamSeekable *stream_seekable, size_t position) {
    return stream_seekable->seek(position);
}

bool SkStreamSeekable_move(SkStreamSeekable *stream_seekable, long offset) {
    return stream_seekable->move(offset);
}

std::unique_ptr<SkStreamSeekable> SkStreamSeekable_fork(SkStreamSeekable *stream_seekable) {
    return stream_seekable->fork();
}

bool SkStreamSeekable_rewind(SkStreamSeekable *stream_seekable) {
    return stream_seekable->rewind();
}

size_t SkStreamSeekable_read(SkStreamSeekable *stream_seekable, void *buffer, size_t size) {
    return stream_seekable->read(buffer, size);
}

size_t SkStreamSeekable_skip(SkStreamSeekable *stream_seekable, size_t size) {
    return stream_seekable->skip(size);
}

size_t SkStreamSeekable_peek(SkStreamSeekable *stream_seekable, void *buffer, size_t size) {
    return stream_seekable->peek(buffer, size);
}

bool SkStreamSeekable_isAtEnd(SkStreamSeekable *stream_seekable) {
    return stream_seekable->isAtEnd();
}

bool SkStreamSeekable_readS8(SkStreamSeekable *stream_seekable, int8_t *i) {
    return stream_seekable->readS8(i);
}

bool SkStreamSeekable_readS16(SkStreamSeekable *stream_seekable, int16_t *i) {
    return stream_seekable->readS16(i);
}

bool SkStreamSeekable_readS32(SkStreamSeekable *stream_seekable, int32_t *i) {
    return stream_seekable->readS32(i);
}

bool SkStreamSeekable_readU8(SkStreamSeekable *stream_seekable, uint8_t *i) {
    return stream_seekable->readU8(i);
}

bool SkStreamSeekable_readU16(SkStreamSeekable *stream_seekable, uint16_t *i) {
    return stream_seekable->readU16(i);
}

bool SkStreamSeekable_readU32(SkStreamSeekable *stream_seekable, uint32_t *i) {
    return stream_seekable->readU32(i);
}

bool SkStreamSeekable_readBool(SkStreamSeekable *stream_seekable, bool *b) {
    return stream_seekable->readBool(b);
}

bool SkStreamSeekable_readScalar(SkStreamSeekable *stream_seekable, SkScalar *v) {
    return stream_seekable->readScalar(v);
}

bool SkStreamSeekable_readPackedUInt(SkStreamSeekable *stream_seekable, size_t *size) {
    return stream_seekable->readPackedUInt(size);
}

bool SkStreamSeekable_hasLength(SkStreamSeekable *stream_seekable) {
    return stream_seekable->hasLength();
}

size_t SkStreamSeekable_getLength(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getLength();
}

const void * SkStreamSeekable_getMemoryBase(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getMemoryBase();
}

// static

std::unique_ptr<SkStreamAsset> SkStreamSeekable_MakeFromFile(const char path[]) {
    return SkStreamSeekable::MakeFromFile(path);
}

//
// SkString
//

// SkString & operator=(const SkString &)
// SkString & operator=(SkString &&)
// SkString & operator=(const char text[])
// SkString & operator+=(const SkString &s)
// SkString & operator+=(const char text[])
// SkString & operator+=(const char c)
// char operator[](size_t n)
// char & operator[](size_t n)

SkString *SkString_new() {
    return new SkString();
}

SkString *SkString_new_2(size_t len) {
    return new SkString(len);
}

SkString *SkString_new_3(const char text[]) {
    return new SkString(text);
}

SkString *SkString_new_4(const char text[], size_t len) {
    return new SkString(text, len);
}

SkString *SkString_new_5(const SkString &str) {
    return new SkString(str);
}

SkString *SkString_new_6(SkString &&str) {
    return new SkString(str);
}

SkString *SkString_new_7(const std::string &str) {
    return new SkString(str);
}

SkString *SkString_new_8(std::string_view view) {
    return new SkString(view);
}

void SkString_delete(SkString *string) {
    delete string;
}
bool SkString_isEmpty(SkString *string) {
    return string->isEmpty();
}

size_t SkString_size(SkString *string) {
    return string->size();
}

const char * SkString_data(SkString *string) {
    return string->data();
}

char * SkString_data_2(SkString *string) {
    return string->data();
}

const char * SkString_c_str(SkString *string) {
    return string->c_str();
}

bool SkString_equals(SkString *string, const SkString &str) {
    return string->equals(str);
}

bool SkString_equals_2(SkString *string, const char text[]) {
    return string->equals(text);
}

bool SkString_equals_3(SkString *string, const char text[], size_t len) {
    return string->equals(text, len);
}

bool SkString_startsWith(SkString *string, const char prefixStr[]) {
    return string->startsWith(prefixStr);
}

bool SkString_startsWith_2(SkString *string, const char prefixChar) {
    return string->startsWith(prefixChar);
}

//bool SkString_endsWith(SkString *string, const char suffixStr[]) {
//    return string->endsWith(suffixStr);
//}

//bool SkString_endsWith_2(SkString *string, const char suffixChar) {
//    return string->endsWith(suffixChar);
//}

bool SkString_contains(SkString *string, const char substring[]) {
    return string->contains(substring);
}

bool SkString_contains_2(SkString *string, const char subchar) {
    return string->contains(subchar);
}

int SkString_find(SkString *string, const char substring[]) {
    return string->find(substring);
}

int SkString_findLastOf(SkString *string, const char subchar) {
    return string->findLastOf(subchar);
}

void SkString_reset(SkString *string) {
    string->reset();
}

void SkString_resize(SkString *string, size_t len) {
    string->resize(len);
}

void SkString_set(SkString *string, const SkString &src) {
    string->set(src);
}

void SkString_set_2(SkString *string, const char text[]) {
    string->set(text);
}

void SkString_set_3(SkString *string, const char text[], size_t len) {
    string->set(text, len);
}

void SkString_set_4(SkString *string, std::string_view str) {
    string->set(str);
}

void SkString_insert(SkString *string, size_t offset, const char text[]) {
    string->insert(offset, text);
}

void SkString_insert_2(SkString *string, size_t offset, const char text[], size_t len) {
    string->insert(offset, text, len);
}

void SkString_insert_3(SkString *string, size_t offset, const SkString &str) {
    string->insert(offset, str);
}

void SkString_insert_4(SkString *string, size_t offset, std::string_view str) {
    string->insert(offset, str);
}

void SkString_insertUnichar(SkString *string, size_t offset, SkUnichar unichar) {
    string->insertUnichar(offset, unichar);
}

void SkString_insertS32(SkString *string, size_t offset, int32_t value) {
    string->insertS32(offset, value);
}

void SkString_insertS64(SkString *string, size_t offset, int64_t value, int minDigits) {
    string->insertS64(offset, value, minDigits);
}

void SkString_insertU32(SkString *string, size_t offset, uint32_t value) {
    string->insertU32(offset, value);
}

void SkString_insertU64(SkString *string, size_t offset, uint64_t value, int minDigits) {
    string->insertU64(offset, value, minDigits);
}

void SkString_insertHex(SkString *string, size_t offset, uint32_t value, int minDigits) {
    string->insertHex(offset, value, minDigits);
}

void SkString_insertScalar(SkString *string, size_t offset, SkScalar v) {
    string->insertScalar(offset, v);
}

void SkString_append(SkString *string, const char text[]) {
    string->append(text);
}

void SkString_append_2(SkString *string, const char text[], size_t len) {
    string->append(text, len);
}

void SkString_append_3(SkString *string, const SkString &str) {
    string->append(str);
}

void SkString_append_4(SkString *string, std::string_view str) {
    string->append(str);
}

void SkString_appendUnichar(SkString *string, SkUnichar uni) {
    string->appendUnichar(uni);
}

void SkString_appendS32(SkString *string, int32_t value) {
    string->appendS32(value);
}

void SkString_appendS64(SkString *string, int64_t value, int minDigits) {
    string->appendS64(value, minDigits);
}

void SkString_appendU32(SkString *string, uint32_t value) {
    string->appendU32(value);
}

void SkString_appendU64(SkString *string, uint64_t value, int minDigits) {
    string->appendU64(value, minDigits);
}

void SkString_appendHex(SkString *string, uint32_t value, int minDigits) {
    string->appendHex(value, minDigits);
}

void SkString_appendScalar(SkString *string, SkScalar value) {
    string->appendScalar(value);
}

void SkString_prepend(SkString *string, const char text[]) {
    string->prepend(text);
}

void SkString_prepend_2(SkString *string, const char text[], size_t len) {
    string->prepend(text, len);
}

void SkString_prepend_3(SkString *string, const SkString &str) {
    string->prepend(str);
}

void SkString_prepend_4(SkString *string, std::string_view str) {
    string->prepend(str);
}

void SkString_prependUnichar(SkString *string, SkUnichar uni) {
    string->prependUnichar(uni);
}

void SkString_prependS32(SkString *string, int32_t value) {
    string->prependS32(value);
}

void SkString_prependS64(SkString *string, int32_t value, int minDigits) {
    string->prependS64(value, minDigits);
}

void SkString_prependHex(SkString *string, uint32_t value, int minDigits) {
    string->prependHex(value, minDigits);
}

void SkString_prependScalar(SkString *string, SkScalar value) {
    string->prependScalar(value);
}

//void SkString_printf(SkString *string, const char format[],...) {
//    string->
//}

//void SkString_printVAList(SkString *string, const char format[], va_list) {
//    string->
//}

//void SkString_appendf(SkString *string, const char format[],...)  {
//    string->
//}

//void SkString_appendVAList(SkString *string, const char format[], va_list) {
//    string->
//}

//void SkString_prependf(SkString *string, const char format[],...) {
//    string->
//}

//void SkString_prependVAList(SkString *string, const char format[], va_list) {
//    string->
//}

void SkString_remove(SkString *string, size_t offset, size_t length) {
    string->remove(offset, length);
}

void SkString_swap(SkString *string, SkString &other) {
    string->swap(other);
}

//
// SkStrokeRec
//

class SkStrokeRec SkStrokeRec_static(SkStrokeRec::InitStyle style) {
    return SkStrokeRec(style);
}

SkStrokeRec SkStrokeRec_static_2(const SkPaint &paint, SkPaint::Style style, SkScalar resScale) {
    return SkStrokeRec(paint, style, resScale);
}

SkStrokeRec SkStrokeRec(const SkPaint &paint, SkScalar resScale) {
    return SkStrokeRec(paint, resScale);
}

SkStrokeRec::Style SkStrokeRec_getStyle(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getStyle();
}

SkScalar SkStrokeRec_getWidth(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getWidth();
}

SkScalar SkStrokeRec_getMiter(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getMiter();
}

SkPaint::Cap SkStrokeRec_getCap(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getCap();
}

SkPaint::Join SkStrokeRec_getJoin(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getJoin();
}

bool SkStrokeRec_isHairlineStyle(class SkStrokeRec *stroke_rec) {
    return stroke_rec->isHairlineStyle();
}

bool SkStrokeRec_isFillStyle(class SkStrokeRec *stroke_rec) {
    return stroke_rec->isFillStyle();
}

void SkStrokeRec_setFillStyle(class SkStrokeRec *stroke_rec) {
    return stroke_rec->setFillStyle();
}

void SkStrokeRec_setHairlineStyle(class SkStrokeRec *stroke_rec) {
    return stroke_rec->setHairlineStyle();
}

void SkStrokeRec_setStrokeStyle(class SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill) {
    return stroke_rec->setStrokeStyle(width, strokeAndFill);
}

void SkStrokeRec_setStrokeParams(class SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit) {
    return stroke_rec->setStrokeParams(cap, join, miterLimit);
}

SkScalar SkStrokeRec_getResScale(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getResScale();
}

void SkStrokeRec_setResScale(class SkStrokeRec *stroke_rec, SkScalar rs) {
    return stroke_rec->setResScale(rs);
}

bool SkStrokeRec_needToApply(class SkStrokeRec *stroke_rec) {
    return stroke_rec->needToApply();
}

bool SkStrokeRec_applyToPath(class SkStrokeRec *stroke_rec, SkPath *dst, const SkPath &src) {
    return stroke_rec->applyToPath(dst, src);
}

void SkStrokeRec_applyToPaint(class SkStrokeRec *stroke_rec, SkPaint *paint) {
    return stroke_rec->applyToPaint(paint);
}

SkScalar SkStrokeRec_getInflationRadius(class SkStrokeRec *stroke_rec) {
    return stroke_rec->getInflationRadius();
}

bool SkStrokeRec_hasEqualEffect(class SkStrokeRec *stroke_rec, const class SkStrokeRec &other) {
    return stroke_rec->hasEqualEffect(other);
}

// static

SkScalar SkStrokeRec_GetInflationRadius(const SkPaint &paint, SkPaint::Style style) {
    return SkStrokeRec::GetInflationRadius(paint, style);
}

SkScalar SkStrokeRec_GetInflationRadius_2(SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth) {
    return SkStrokeRec::GetInflationRadius(join, miterLimit, cap, strokeWidth);
}

//
// SkSurface
//

bool SkSurface_isCompatible(SkSurface *surface, const GrSurfaceCharacterization &characterization) {
    return surface->isCompatible(characterization);
}

int SkSurface_width(SkSurface *surface) {
    return surface->width();
}

int SkSurface_height(SkSurface *surface) {
    return surface->height();
}

SkImageInfo SkSurface_imageInfo(SkSurface *surface) {
    return surface->imageInfo();
}

uint32_t SkSurface_generationID(SkSurface *surface) {
    return surface->generationID();
}

void SkSurface_notifyContentWillChange(SkSurface *surface, SkSurface::ContentChangeMode mode) {
    surface->notifyContentWillChange(mode);
}

GrRecordingContext * SkSurface_recordingContext(SkSurface *surface) {
    return surface->recordingContext();
}

skgpu::graphite::Recorder * SkSurface_recorder(SkSurface *surface) {
    return surface->recorder();
}

bool SkSurface_replaceBackendTexture(SkSurface *surface, const GrBackendTexture &backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context) {
    return surface->replaceBackendTexture(backendTexture, origin, mode, proc, context);
}

SkCanvas * SkSurface_getCanvas(SkSurface *surface) {
    return surface->getCanvas();
}

sk_sp<const SkCapabilities> SkSurface_capabilities(SkSurface *surface) {
    return surface->capabilities();
}

sk_sp<SkSurface> SkSurface_makeSurface(SkSurface *surface, const SkImageInfo &imageInfo) {
    return surface->makeSurface(imageInfo);
}

sk_sp<SkSurface> SkSurface_makeSurface_2(SkSurface *surface, int width, int height) {
    return surface->makeSurface(width, height);
}

sk_sp<SkImage> SkSurface_makeImageSnapshot(SkSurface *surface) {
    return surface->makeImageSnapshot();
}

sk_sp<SkImage> SkSurface_makeImageSnapshot_2(SkSurface *surface, const SkIRect &bounds) {
    return surface->makeImageSnapshot(bounds);
}

void SkSurface_draw(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions &sampling, const SkPaint *paint) {
    surface->draw(canvas, x, y, sampling, paint);
}

void SkSurface_draw_2(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint) {
    surface->draw(canvas, x, y, paint);
}

bool SkSurface_peekPixels(SkSurface *surface, SkPixmap *pixmap) {
    return surface->peekPixels(pixmap);
}

bool SkSurface_readPixels(SkSurface *surface, const SkPixmap &dst, int srcX, int srcY) {
    return surface->readPixels(dst, srcX, srcY);
}

bool SkSurface_readPixels_2(SkSurface *surface, const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return surface->readPixels(dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkSurface_readPixels_3(SkSurface *surface, const SkBitmap &dst, int srcX, int srcY) {
    return surface->readPixels(dst, srcX, srcY);
}

void SkSurface_asyncRescaleAndReadPixels(SkSurface *surface, const SkImageInfo &info, const SkIRect &srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixels(info, srcRect, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_asyncRescaleAndReadPixelsYUV420(SkSurface *surface, SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixelsYUV420(yuvColorSpace, dstColorSpace, srcRect, dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_asyncRescaleAndReadPixelsYUVA420(SkSurface *surface, SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixelsYUVA420(yuvColorSpace, dstColorSpace, srcRect, dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_writePixels(SkSurface *surface, const SkPixmap &src, int dstX, int dstY) {
    surface->writePixels(src, dstX, dstY);
}

void SkSurface_writePixels_2(SkSurface *surface, const SkBitmap &src, int dstX, int dstY) {
    surface->writePixels(src, dstX, dstY);
}

const SkSurfaceProps & SkSurface_props(SkSurface *surface) {
    return surface->props();
}

bool SkSurface_wait(SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait) {
    return surface->wait(numSemaphores, waitSemaphores, deleteSemaphoresAfterWait);
}

bool SkSurface_characterize(SkSurface *surface, GrSurfaceCharacterization *characterization) {
    return surface->characterize(characterization);
}

bool SkSurface_unique(SkSurface *surface) {
    return surface->unique();
}

void SkSurface_ref(SkSurface *surface) {
    surface->ref();
}

void SkSurface_unref(SkSurface *surface) {
    surface->unref();
}

//
// SkSurfaceProps
//

// SkSurfaceProps & operator=(const SkSurfaceProps &)
// bool operator==(const SkSurfaceProps &that)
// bool operator!=(const SkSurfaceProps &that)

SkSurfaceProps *SkSurfaceProps_new() {
    return new SkSurfaceProps();
}

SkSurfaceProps *SkSurfaceProps_new_2(uint32_t flags, SkPixelGeometry geometry) {
    return new SkSurfaceProps(flags, geometry);
}

SkSurfaceProps *SkSurfaceProps_new_3(const SkSurfaceProps &props) {
    return new SkSurfaceProps(props);
}

SkSurfaceProps SkSurfaceProps_cloneWithPixelGeometry(SkSurfaceProps *surface_props, SkPixelGeometry newPixelGeometry) {
    return surface_props->cloneWithPixelGeometry(newPixelGeometry);
}

uint32_t SkSurfaceProps_flags(SkSurfaceProps *surface_props) {
    return surface_props->flags();
}

SkPixelGeometry SkSurfaceProps_pixelGeometry(SkSurfaceProps *surface_props) {
    return surface_props->pixelGeometry();
}

bool SkSurfaceProps_isUseDeviceIndependentFonts(SkSurfaceProps *surface_props) {
    return surface_props->isUseDeviceIndependentFonts();
}

bool SkSurfaceProps_isAlwaysDither(SkSurfaceProps *surface_props) {
    return surface_props->isAlwaysDither();
}

//
// SVG ...
//

//
// SkTableMaskFilter
//

//SkTableMaskFilter *SkTableMaskFilter_new() {
//    return new SkTableMaskFilter();
//}

// static

void SkTableMaskFilter_MakeGammaTable(uint8_t table[256], SkScalar gamma) {
    SkTableMaskFilter::MakeGammaTable(table, gamma);
}

void SkTableMaskFilter_MakeClipTable(uint8_t table[256], uint8_t min, uint8_t max) {
    SkTableMaskFilter::MakeClipTable(table, min, max);
}

SkMaskFilter * SkTableMaskFilter_Create(const uint8_t table[256]) {
    return SkTableMaskFilter::Create(table);
}

SkMaskFilter * SkTableMaskFilter_CreateGamma(SkScalar gamma) {
    return SkTableMaskFilter::CreateGamma(gamma);
}

SkMaskFilter * SkTableMaskFilter_CreateClip(uint8_t min, uint8_t max) {
    return SkTableMaskFilter::CreateClip(min, max);
}

//
// SkTextBlob
//

const SkRect & SkTextBlob_bounds(SkTextBlob *text_blob) {
    return text_blob->bounds();
}

uint32_t SkTextBlob_uniqueID(SkTextBlob *text_blob) {
    return text_blob->uniqueID();
}

int SkTextBlob_getIntercepts(SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint) {
    return text_blob->getIntercepts(bounds, intervals, paint);
}

size_t SkTextBlob_serialize(SkTextBlob *text_blob, const SkSerialProcs &procs, void *memory, size_t memory_size) {
    return text_blob->serialize(procs, memory, memory_size);
}

sk_sp<SkData> SkTextBlob_serialize_2(SkTextBlob *text_blob, const SkSerialProcs &procs) {
    return text_blob->serialize(procs);
}

bool SkTextBlob_unique(SkTextBlob *text_blob) {
    return text_blob->unique();
}

void SkTextBlob_ref(SkTextBlob *text_blob) {
    text_blob->ref();
}

void SkTextBlob_unref(SkTextBlob *text_blob) {
    text_blob->unref();
}

void SkTextBlob_deref(SkTextBlob *text_blob) {
    text_blob->deref();
}

bool SkTextBlob_refCntGreaterThan(SkTextBlob *text_blob, int32_t threadIsolatedTestCnt) {
    return text_blob->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

sk_sp<SkTextBlob> SkTextBlob_MakeFromText(const void *text, size_t byteLength, const SkFont &font, SkTextEncoding encoding) {
    return SkTextBlob::MakeFromText(text, byteLength, font, encoding);
}

sk_sp<SkTextBlob> SkTextBlob_MakeFromString(const char *string, const SkFont &font, SkTextEncoding encoding) {
    return SkTextBlob::MakeFromString(string, font, encoding);
}

sk_sp<SkTextBlob> SkTextBlob_MakeFromPosTextH(const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont &font, SkTextEncoding encoding) {
    return SkTextBlob::MakeFromPosTextH(text, byteLength, xpos, constY, font, encoding);
}

sk_sp<SkTextBlob> SkTextBlob_MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont &font, SkTextEncoding encoding) {
    return SkTextBlob::MakeFromPosText(text, byteLength, pos, font, encoding);
}

sk_sp<SkTextBlob> SkTextBlob_MakeFromRSXform(const void *text, size_t byteLength, const SkRSXform xform[], const SkFont &font, SkTextEncoding encoding) {
    return SkTextBlob::MakeFromRSXform(text, byteLength, xform, font, encoding);
}

sk_sp<SkTextBlob> SkTextBlob_Deserialize(const void *data, size_t size, const SkDeserialProcs &procs) {
    return SkTextBlob::Deserialize(data, size, procs);
}

//
// SkTextBlobBuilder
//

SkTextBlobBuilder *SkTextBlobBuilder_new() {
    return new SkTextBlobBuilder();
}

void SkTextBlobBuilder_delete(SkTextBlobBuilder *text_blob_builder) {
    delete text_blob_builder;
}

sk_sp<SkTextBlob> SkTextBlobBuilder_make(SkTextBlobBuilder *text_blob_builder) {
    return text_blob_builder->make();
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRun(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, SkScalar x, SkScalar y, const SkRect *bounds) {
    return text_blob_builder->allocRun(font, count, x, y, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunPosH(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, SkScalar y, const SkRect *bounds) {
    return text_blob_builder->allocRunPosH(font, count, y, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunPos(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, const SkRect *bounds) {
    return text_blob_builder->allocRunPos(font, count, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count) {
    return text_blob_builder->allocRunRSXform(font, count);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunText(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, SkScalar x, SkScalar y, int textByteCount, const SkRect *bounds) {
    return text_blob_builder->allocRunText(font, count, x, y, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunTextPosH(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, SkScalar y, int textByteCount, const SkRect *bounds) {
    return text_blob_builder->allocRunTextPosH(font, count, y, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunTextPos(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, int textByteCount, const SkRect *bounds) {
    return text_blob_builder->allocRunTextPos(font, count, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer & SkTextBlobBuilder_allocRunTextRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont &font, int count, int textByteCount, const SkRect *bounds) {
    return text_blob_builder->allocRunTextRSXform(font, count, textByteCount, bounds);
}

//
// SkTextBlobBuilderRunHandler
//

SkTextBlobBuilderRunHandler *SkTextBlobBuilderRunHandler_new(const char *utf8Text, SkPoint offset) {
    return new SkTextBlobBuilderRunHandler(utf8Text, offset);
}

sk_sp<SkTextBlob> SkTextBlobBuilderRunHandler_makeBlob(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    return text_blob_builder_run_handler->makeBlob();
}

SkPoint SkTextBlobBuilderRunHandler_endPoint(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    return text_blob_builder_run_handler->endPoint();
}

void SkTextBlobBuilderRunHandler_beginLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->beginLine();
}

void SkTextBlobBuilderRunHandler_runInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo &run_info) {
    text_blob_builder_run_handler->runInfo(run_info);
}
void SkTextBlobBuilderRunHandler_commitRunInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->commitRunInfo();
}

SkTextBlobBuilderRunHandler::Buffer SkTextBlobBuilderRunHandler_runBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo &run_info) {
    return text_blob_builder_run_handler->runBuffer(run_info);
}

void SkTextBlobBuilderRunHandler_commitRunBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo &run_info) {
    text_blob_builder_run_handler->commitRunBuffer(run_info);
}

void SkTextBlobBuilderRunHandler_commitLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->commitLine();
}

//
// SkTraceMemoryDump
//

void SkTraceMemoryDump_dumpNumericValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *valueName, const char *units, uint64_t value) {
    trace_memory_dump->dumpNumericValue(dumpName, valueName, units, value);
}

void SkTraceMemoryDump_dumpStringValue(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *str1, const char *str2) {
    trace_memory_dump->dumpStringValue(dumpName, str1, str2);
}

void SkTraceMemoryDump_setMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const char *backingType, const char *backingObjectId) {
    trace_memory_dump->setMemoryBacking(dumpName, backingType, backingObjectId);
}

void SkTraceMemoryDump_setDiscardableMemoryBacking(SkTraceMemoryDump *trace_memory_dump, const char *dumpName, const SkDiscardableMemory &discardableMemoryObject) {
    trace_memory_dump->setDiscardableMemoryBacking(dumpName, discardableMemoryObject);
}

SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDump_getRequestedDetails(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->getRequestedDetails();
}

bool SkTraceMemoryDump_shouldDumpWrappedObjects(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->shouldDumpWrappedObjects();
}

void SkTraceMemoryDump_dumpWrappedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b) {
    trace_memory_dump->dumpWrappedState(str, b);
}

bool SkTraceMemoryDump_shouldDumpUnbudgetedObjects(SkTraceMemoryDump *trace_memory_dump) {
    return trace_memory_dump->shouldDumpUnbudgetedObjects();
}

void SkTraceMemoryDump_dumpBudgetedState(SkTraceMemoryDump *trace_memory_dump, const char *str, bool b) {
    trace_memory_dump->dumpBudgetedState(str, b);
}

//
// SkTrimPathEffect
//

sk_sp<SkPathEffect> SkTrimPathEffect_Make(SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode) {
    return SkTrimPathEffect::Make(startT, stopT, mode);
}

//
// SkTypeface
//

SkFontStyle SkTypeface_fontStyle(SkTypeface *typeface) {
    return typeface->fontStyle();
}

bool SkTypeface_isBold(SkTypeface *typeface) {
    return typeface->isBold();
}

bool SkTypeface_isItalic(SkTypeface *typeface) {
    return typeface->isItalic();
}

bool SkTypeface_isFixedPitch(SkTypeface *typeface) {
    return typeface->isFixedPitch();
}

int SkTypeface_getVariationDesignPosition(SkTypeface *typeface, SkFontArguments::VariationPosition::Coordinate coordinates[], int coordinateCount) {
    return typeface->getVariationDesignPosition(coordinates, coordinateCount);
}

int SkTypeface_getVariationDesignParameters(SkTypeface *typeface, SkFontParameters::Variation::Axis parameters[], int parameterCount) {
    return typeface->getVariationDesignParameters(parameters, parameterCount);
}

SkTypefaceID SkTypeface_uniqueID(SkTypeface *typeface) {
    return typeface->uniqueID();
}

sk_sp<SkTypeface> SkTypeface_makeClone(SkTypeface *typeface, const SkFontArguments &arguments) {
    return typeface->makeClone(arguments);
}

void SkTypeface_serialize(SkTypeface *typeface, SkWStream *stream, SkTypeface::SerializeBehavior behavior) {
    typeface->serialize(stream, behavior);
}

sk_sp<SkData> SkTypeface_serialize_2(SkTypeface *typeface, SkTypeface::SerializeBehavior behavior) {
    return typeface->serialize(behavior);
}

void SkTypeface_unicharsToGlyphs(SkTypeface *typeface, const SkUnichar uni[], int count, SkGlyphID glyphs[]) {
    typeface->unicharsToGlyphs(uni, count, glyphs);
}

int SkTypeface_textToGlyphs(SkTypeface *typeface, const void *text, size_t byteLength, SkTextEncoding encoding, SkGlyphID glyphs[], int maxGlyphCount) {
    return typeface->textToGlyphs(text, byteLength, encoding, glyphs, maxGlyphCount);
}

SkGlyphID SkTypeface_unicharToGlyph(SkTypeface *typeface, SkUnichar unichar) {
    return typeface->unicharToGlyph(unichar);
}

int SkTypeface_countGlyphs(SkTypeface *typeface) {
    return typeface->countGlyphs();
}

int SkTypeface_countTables(SkTypeface *typeface) {
    return typeface->countTables();
}

int SkTypeface_getTableTags(SkTypeface *typeface, SkFontTableTag tags[]) {
    return typeface->getTableTags(tags);
}

size_t SkTypeface_getTableSize(SkTypeface *typeface, SkFontTableTag tag) {
    return typeface->getTableSize(tag);
}

size_t SkTypeface_getTableData(SkTypeface *typeface, SkFontTableTag tag, size_t offset, size_t length, void *data) {
    return typeface->getTableData(tag, offset, length, data);
}

sk_sp<SkData> SkTypeface_copyTableData(SkTypeface *typeface, SkFontTableTag tag) {
    return typeface->copyTableData(tag);
}

int SkTypeface_getUnitsPerEm(SkTypeface *typeface) {
    return typeface->getUnitsPerEm();
}

bool SkTypeface_getKerningPairAdjustments(SkTypeface *typeface, const SkGlyphID glyphs[], int count, int32_t adjustments[]) {
    return typeface->getKerningPairAdjustments(glyphs, count, adjustments);
}

SkTypeface::LocalizedStrings * SkTypeface_createFamilyNameIterator(SkTypeface *typeface) {
    return typeface->createFamilyNameIterator();
}

void SkTypeface_getFamilyName(SkTypeface *typeface, SkString *name) {
    typeface->getFamilyName(name);
}

bool SkTypeface_getPostScriptName(SkTypeface *typeface, SkString *name) {
    return typeface->getPostScriptName(name);
}

std::unique_ptr<SkStreamAsset> SkTypeface_openStream(SkTypeface *typeface, int *ttcIndex) {
    return typeface->openStream(ttcIndex);
}

std::unique_ptr<SkStreamAsset> SkTypeface_openExistingStream(SkTypeface *typeface, int *ttcIndex) {
    return typeface->openExistingStream(ttcIndex);
}

//@TODO
//std::unique_ptr<SkScalerContext> SkTypeface_createScalerContext(SkTypeface *typeface, const SkScalerContextEffects &effects, const SkDescriptor *descriptor) {
//    return typeface->createScalerContext(effects, descriptor);
//}

SkRect SkTypeface_getBounds(SkTypeface *typeface) {
    return typeface->getBounds();
}

void SkTypeface_filterRec(SkTypeface *typeface, SkScalerContextRec *rec) {
    typeface->filterRec(rec);
}

void SkTypeface_getFontDescriptor(SkTypeface *typeface, SkFontDescriptor *desc, bool *isLocal) {
    typeface->getFontDescriptor(desc, isLocal);
}

void * SkTypeface_internal_private_getCTFontRef(SkTypeface *typeface) {
    typeface->internal_private_getCTFontRef();
}

// static

bool SkTypeface_Equal(const SkTypeface *facea, const SkTypeface *faceb) {
    return SkTypeface::Equal(facea, faceb);
}

// @TODO
//sk_sp<SkTypeface> SkTypeface_MakeDefault() {
//    return SkTypeface::MakeDefault();
//}

sk_sp<SkTypeface> SkTypeface_MakeEmpty() {
    return SkTypeface::MakeEmpty();
}

sk_sp<SkTypeface> SkTypeface_MakeFromName(const char familyName[], SkFontStyle fontStyle) {
    return SkTypeface::MakeFromName(familyName, fontStyle);
}

sk_sp<SkTypeface> SkTypeface_MakeFromFile(const char path[], int index) {
    return SkTypeface::MakeFromFile(path, index);
}

// @TODO
//sk_sp<SkTypeface> SkTypeface_MakeFromStream(std::unique_ptr<SkStreamAsset> stream, int index) {
//    return SkTypeface::MakeFromStream(stream, index);
//}

sk_sp<SkTypeface> SkTypeface_MakeFromData(sk_sp<SkData> data, int index) {
    return SkTypeface::MakeFromData(data, index);
}

sk_sp<SkTypeface> SkTypeface_MakeDeserialize(SkStream *stream) {
    return SkTypeface::MakeDeserialize(stream);
}

sk_sp<SkTypeface> SkTypeface_MakeDeserialize_2(SkStream *stream, sk_sp<SkFontMgr> lastResortMgr) {
    return SkTypeface::MakeDeserialize(stream, lastResortMgr);
}

void SkTypeface_Register(SkTypeface::FactoryId id, sk_sp<SkTypeface>(*make)(std::unique_ptr<SkStreamAsset>, const SkFontArguments &)) {
    SkTypeface::Register(id, make);
}

//
// SkUnPreMultiply
//

// static

const SkUnPreMultiply::Scale * SkUnPreMultiply_GetScaleTable() {
    return SkUnPreMultiply::GetScaleTable();
}

SkUnPreMultiply::Scale SkUnPreMultiply_GetScale(U8CPU alpha) {
    return SkUnPreMultiply::GetScale(alpha);
}

U8CPU SkUnPreMultiply_ApplyScale(SkUnPreMultiply::Scale scale, U8CPU component) {
    return SkUnPreMultiply::ApplyScale(scale, component);
}

SkColor SkUnPreMultiply_PMColorToColor(SkPMColor c) {
    return SkUnPreMultiply::PMColorToColor(c);
}

//
// SkV2 Struct
//

// bool operator==(const SkV2 v)
// bool operator!=(const SkV2 v)
// SkV2 operator-()
// SkV2 operator+(SkV2 v)
// SkV2 operator-(SkV2 v)
// SkV2 operator*(SkV2 v)
// void operator+=(SkV2 v)
// void operator-=(SkV2 v)
// void operator*=(SkV2 v)
// void operator*=(SkScalar s)
// void operator/=(SkScalar s)

SkScalar SkV2_lengthSquared(SkV2 *v2) {
    return v2->lengthSquared();
}

SkScalar SkV2_length(SkV2 *v2) {
    return v2->length();
}

SkScalar SkV2_dot(SkV2 *v2, SkV2 v) {
    return v2->dot(v);
}

SkScalar SkV2_cross(SkV2 *v2, SkV2 v) {
    return v2->cross(v);
}

SkV2 SkV2_normalize(SkV2 *v2) {
    return v2->normalize();
}

const float * SkV2_ptr(SkV2 *v2) {
    return v2->ptr();
}

float * SkV2_ptr_2(SkV2 *v2) {
    return v2->ptr();
}

// static

SkScalar SkV2_Dot(SkV2 a, SkV2 b) {
    return SkV2::Dot(a, b);
}

SkScalar SkV2_Cross(SkV2 a, SkV2 b) {
    return SkV2::Cross(a, b);
}

SkV2 SkV2_Normalize(SkV2 v) {
    return SkV2::Normalize(v);
}

//
// SkV3 Struct
//

// bool operator==(const SkV3 &v)
// bool operator!=(const SkV3 &v)
// SkV3 operator-()
// SkV3 operator+(const SkV3 &v)
// SkV3 operator-(const SkV3 &v)
// SkV3 operator*(const SkV3 &v)
// void operator+=(SkV3 v)
// void operator-=(SkV3 v)
// void operator*=(SkV3 v)
// void operator*=(SkScalar s)

SkScalar SkV3_lengthSquared(SkV3 *v3) {
    return v3->lengthSquared();
}

SkScalar SkV3_length(SkV3 *v3) {
    return v3->length();
}

SkScalar SkV3_dot(SkV3 *v3, const SkV3 &v) {
    return v3->dot(v);
}

SkV3 SkV3_cross(SkV3 *v3, const SkV3 &v) {
    return v3->cross(v);
}

SkV3 SkV3_normalize(SkV3 *v3) {
    return v3->normalize();
}

const float * SkV3_ptr(SkV3 *v3) {
    return v3->ptr();
}

float * SkV3_ptr_2(SkV3 *v3) {
    return v3->ptr();
}

// static

SkScalar SkV3_Dot(const SkV3 &a, const SkV3 &b) {
    return SkV3::Dot(a, b);
}

SkV3 SkV3_Cross(const SkV3 &a, const SkV3 &b) {
    return SkV3::Cross(a, b);
}

SkV3 SkV3_Normalize(const SkV3 &v) {
    return SkV3::Normalize(v);
}

//
// SkV4 Struct
//

// bool operator==(const SkV4 &v)
// bool operator!=(const SkV4 &v)
// SkV4 operator-()
// SkV4 operator+(const SkV4 &v)
// SkV4 operator-(const SkV4 &v)
// SkV4 operator*(const SkV4 &v)
// float operator[](int i)
// float & operator[](int i)

SkScalar SkV4_lengthSquared(SkV4 *v4) {
    return v4->lengthSquared();
}

SkScalar SkV4_length(SkV4 *v4) {
    return v4->length();
}

SkScalar SkV4_dot(SkV4 *v4, const SkV4 &v) {
    return v4->dot(v);
}

SkV4 SkV4_normalize(SkV4 *v4) {
    return v4->normalize();
}

const float * SkV4_ptr(SkV4 *v4) {
    return v4->ptr();
}

float * SkV4_ptr_2(SkV4 *v4) {
    return v4->ptr();
}

// static

SkScalar SkV4_Dot(const SkV4 &a, const SkV4 &b) {
    return SkV4::Dot(a, b);
}

SkV4 SkV4_Normalize(const SkV4 &v) {
    return SkV4::Normalize(v);
}

//
// SkVertices
//

uint32_t SkVertices_uniqueID(SkVertices *vertices) {
    return vertices->uniqueID();
}

const SkRect & SkVertices_bounds(SkVertices *vertices) {
    return vertices->bounds();
}

size_t SkVertices_approximateSize(SkVertices *vertices) {
    return vertices->approximateSize();
}

//SkVerticesPriv SkVertices_priv(SkVertices *vertices) {
//    return vertices->priv();
//}

//const SkVerticesPriv SkVertices_priv_2(SkVertices *vertices) {
//    return vertices->priv();
//}

bool SkVertices_unique(SkVertices *vertices) {
    return vertices->unique();
}

void SkVertices_ref(SkVertices *vertices) {
    vertices->ref();
}

void SkVertices_unref(SkVertices *vertices) {
    vertices->unref();
}

void SkVertices_deref(SkVertices *vertices) {
    vertices->deref();
}

bool SkVertices_refCntGreaterThan(SkVertices *vertices, int32_t threadIsolatedTestCnt) {
    return vertices->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

sk_sp<SkVertices> SkVertices_MakeCopy(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[], int indexCount, const uint16_t indices[]) {
    return SkVertices::MakeCopy(mode, vertexCount, positions, texs, colors, indexCount, indices);
}

sk_sp<SkVertices> SkVertices_MakeCopy_2(SkVertices::VertexMode mode, int vertexCount, const SkPoint positions[], const SkPoint texs[], const SkColor colors[]) {
    return SkVertices::MakeCopy(mode, vertexCount, positions, texs, colors);
}

//
// SkWStream
//

//SkWStream *SkWStream_new() {
//    return new SkWStream();
//}

void SkWStream_delete(SkWStream *w_stream) {
    delete w_stream;
}

bool SkWStream_write(SkWStream *w_stream, const void *buffer, size_t size) {
    return w_stream->write(buffer, size);
}

void SkWStream_flush(SkWStream *w_stream) {
    return w_stream->flush();
}

size_t SkWStream_bytesWritten(SkWStream *w_stream) {
    return w_stream->bytesWritten();
}

bool SkWStream_write8(SkWStream *w_stream, U8CPU value) {
    return w_stream->write8(value);
}

bool SkWStream_write16(SkWStream *w_stream, U16CPU value) {
    return w_stream->write16(value);
}

bool SkWStream_write32(SkWStream *w_stream, uint32_t v) {
    return w_stream->write32(v);
}

bool SkWStream_writeText(SkWStream *w_stream, const char text[]) {
    return w_stream->writeText(text);
}

bool SkWStream_newline(SkWStream *w_stream) {
    return w_stream->newline();
}

bool SkWStream_writeDecAsText(SkWStream *w_stream, int32_t i) {
    return w_stream->writeDecAsText(i);
}

bool SkWStream_writeBigDecAsText(SkWStream *w_stream, int64_t i, int minDigits) {
    return w_stream->writeBigDecAsText(i, minDigits);
}

bool SkWStream_writeHexAsText(SkWStream *w_stream, uint32_t i, int minDigits) {
    return w_stream->writeHexAsText(i, minDigits);
}

bool SkWStream_writeScalarAsText(SkWStream *w_stream, SkScalar v) {
    return w_stream->writeScalarAsText(v);
}

bool SkWStream_writeBool(SkWStream *w_stream, bool v) {
    return w_stream->writeBool(v);
}

bool SkWStream_writeScalar(SkWStream *w_stream, SkScalar v) {
    return w_stream->writeScalar(v);
}

bool SkWStream_writePackedUInt(SkWStream *w_stream, size_t size) {
    return w_stream->writePackedUInt(size);
}

bool SkWStream_writeStream(SkWStream *w_stream, SkStream *input, size_t length) {
    return w_stream->writeStream(input, length);
}

// static

int SkWStream_SizeOfPackedUInt(size_t value) {
    return SkWStream::SizeOfPackedUInt(value);
}

//
// SkYUVAInfo
//

// SkYUVAInfo & operator=(const SkYUVAInfo &that)
// bool operator==(const SkYUVAInfo &that)
// bool operator!=(const SkYUVAInfo &that)

SkYUVAInfo *SkYUVAInfo_new() {
    return new SkYUVAInfo();
}

SkYUVAInfo *SkYUVAInfo_new_2(const SkYUVAInfo &info) {
    return new SkYUVAInfo(info);
}

SkYUVAInfo *SkYUVAInfo_new_3(SkISize dimensions, SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, SkYUVColorSpace space, SkEncodedOrigin origin, SkYUVAInfo::Siting sitingX, SkYUVAInfo::Siting sitingY) {
    return new SkYUVAInfo(dimensions, config, subsampling, space, origin, sitingX, sitingY);
}

SkYUVAInfo::PlaneConfig SkYUVAInfo_planeConfig(SkYUVAInfo * yuva_info) {
    return yuva_info->planeConfig();
}

SkYUVAInfo::Subsampling SkYUVAInfo_subsampling(SkYUVAInfo * yuva_info) {
    return yuva_info->subsampling();
}

std::tuple<int, int> SkYUVAInfo_planeSubsamplingFactors(SkYUVAInfo * yuva_info, int planeIdx) {
    return yuva_info->planeSubsamplingFactors(planeIdx);
}

SkISize SkYUVAInfo_dimensions(SkYUVAInfo * yuva_info) {
    return yuva_info->dimensions();
}

int SkYUVAInfo_width(SkYUVAInfo * yuva_info) {
    return yuva_info->width();
}

int SkYUVAInfo_height(SkYUVAInfo * yuva_info) {
    return yuva_info->height();
}

SkYUVColorSpace SkYUVAInfo_yuvColorSpace(SkYUVAInfo * yuva_info) {
    return yuva_info->yuvColorSpace();
}

SkYUVAInfo::Siting SkYUVAInfo_sitingX(SkYUVAInfo * yuva_info) {
    return yuva_info->sitingX();
}

SkYUVAInfo::Siting SkYUVAInfo_sitingY(SkYUVAInfo * yuva_info) {
    return yuva_info->sitingY();
}

SkEncodedOrigin SkYUVAInfo_origin(SkYUVAInfo * yuva_info) {
    return yuva_info->origin();
}

SkMatrix SkYUVAInfo_originMatrix(SkYUVAInfo * yuva_info) {
    return yuva_info->originMatrix();
}

bool SkYUVAInfo_hasAlpha(SkYUVAInfo * yuva_info) {
    return yuva_info->hasAlpha();
}

int SkYUVAInfo_planeDimensions(SkYUVAInfo * yuva_info, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) {
    return yuva_info->planeDimensions(planeDimensions);
}

size_t SkYUVAInfo_computeTotalBytes(SkYUVAInfo * yuva_info, const size_t rowBytes[SkYUVAInfo::kMaxPlanes], size_t planeSizes[SkYUVAInfo::kMaxPlanes]) {
    return yuva_info->computeTotalBytes(rowBytes, planeSizes);
}

int SkYUVAInfo_numPlanes(SkYUVAInfo * yuva_info) {
    return yuva_info->numPlanes();
}

int SkYUVAInfo_numChannelsInPlane(SkYUVAInfo * yuva_info, int i) {
    return yuva_info->numChannelsInPlane(i);
}

//SkYUVAInfo::YUVALocations SkYUVAInfo_toYUVALocations(SkYUVAInfo * yuva_info, const uint32_t *channelFlags) {
//    return yuva_info->toYUVALocations(channelFlags);
//}

SkYUVAInfo SkYUVAInfo_makeSubsampling(SkYUVAInfo * yuva_info, SkYUVAInfo::Subsampling subsampling) {
    return yuva_info->makeSubsampling(subsampling);
}

SkYUVAInfo SkYUVAInfo_makeDimensions(SkYUVAInfo * yuva_info, SkISize size) {
    return yuva_info->makeDimensions(size);
}

bool SkYUVAInfo_isValid(SkYUVAInfo * yuva_info) {
    return yuva_info->isValid();
}

// static

std::tuple<int, int> SkYUVAInfo_SubsamplingFactors(SkYUVAInfo::Subsampling subsampling) {
    return SkYUVAInfo::SubsamplingFactors(subsampling);
}

std::tuple<int, int> SkYUVAInfo_PlaneSubsamplingFactors(SkYUVAInfo::PlaneConfig config, SkYUVAInfo::Subsampling subsampling, int planeIdx) {
    return SkYUVAInfo::PlaneSubsamplingFactors(config, subsampling, planeIdx);
}

int SkYUVAInfo_PlaneDimensions(SkISize imageDimensions, SkYUVAInfo::PlaneConfig plane, SkYUVAInfo::Subsampling subsampling, SkEncodedOrigin origin, SkISize planeDimensions[SkYUVAInfo::kMaxPlanes]) {
    return SkYUVAInfo::PlaneDimensions(imageDimensions, plane, subsampling, origin, planeDimensions);
}

int SkYUVAInfo_NumPlanes(SkYUVAInfo::PlaneConfig config) {
    return SkYUVAInfo::NumPlanes(config);
}

int SkYUVAInfo_NumChannelsInPlane(SkYUVAInfo::PlaneConfig config, int i) {
    return SkYUVAInfo::NumChannelsInPlane(config, i);
}

//SkYUVAInfo::YUVALocations SkYUVAInfo_GetYUVALocations(SkYUVAInfo::PlaneConfig config, const uint32_t *planeChannelFlags) {
//    return SkYUVAInfo::GetYUVALocations(config, planeChannelFlags);
//}

bool SkYUVAInfo_HasAlpha(SkYUVAInfo::PlaneConfig config) {
    return SkYUVAInfo::HasAlpha(config);
}

//
// SkYUVAPixmapInfo
//

// SkYUVAPixmapInfo & operator=(const SkYUVAPixmapInfo &)
// bool operator==(const SkYUVAPixmapInfo &)
// bool operator!=(const SkYUVAPixmapInfo &that)

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return new SkYUVAPixmapInfo();
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_2(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAInfo &info, const SkColorType[SkYUVAPixmapInfo::kMaxPlanes], const size_t rowBytes[SkYUVAPixmapInfo::kMaxPlanes]) {
    return new SkYUVAPixmapInfo();
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_3(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAInfo &info, SkYUVAPixmapInfo::DataType type, const size_t rowBytes[SkYUVAPixmapInfo::kMaxPlanes]) {
    return new SkYUVAPixmapInfo();
}

SkYUVAPixmapInfo *SkYUVAPixmapInfo_new_4(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo &info) {
    return new SkYUVAPixmapInfo();
}

const SkYUVAInfo & SkYUVAPixmapInfo_yuvaInfo(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->yuvaInfo();
}

SkYUVColorSpace SkYUVAPixmapInfo_yuvColorSpace(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->yuvColorSpace();
}

int SkYUVAPixmapInfo_numPlanes(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->numPlanes();
}

SkYUVAPixmapInfo::DataType SkYUVAPixmapInfo_dataType(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->dataType();
}

size_t SkYUVAPixmapInfo_rowBytes(SkYUVAPixmapInfo *yuva_pixmap_info, int i) {
    return yuva_pixmap_info->rowBytes(i);
}

const SkImageInfo & SkYUVAPixmapInfo_planeInfo(SkYUVAPixmapInfo *yuva_pixmap_info, int i) {
    return yuva_pixmap_info->planeInfo(i);
}

size_t SkYUVAPixmapInfo_computeTotalBytes(SkYUVAPixmapInfo *yuva_pixmap_info, size_t planeSizes[SkYUVAPixmapInfo::kMaxPlanes]) {
    return yuva_pixmap_info->computeTotalBytes(planeSizes);
}

bool SkYUVAPixmapInfo_initPixmapsFromSingleAllocation(SkYUVAPixmapInfo *yuva_pixmap_info, void *memory, SkPixmap pixmaps[SkYUVAPixmapInfo::kMaxPlanes]) {
    return yuva_pixmap_info->initPixmapsFromSingleAllocation(memory, pixmaps);
}

bool SkYUVAPixmapInfo_isValid(SkYUVAPixmapInfo *yuva_pixmap_info) {
    return yuva_pixmap_info->isValid();
}

bool SkYUVAPixmapInfo_isSupported(SkYUVAPixmapInfo *yuva_pixmap_info, const SkYUVAPixmapInfo::SupportedDataTypes &type) {
    return yuva_pixmap_info->isSupported(type);
}

// static

SkColorType SkYUVAPixmapInfo_DefaultColorTypeForDataType(SkYUVAPixmapInfo *yuva_pixmap_info, SkYUVAPixmapInfo::DataType dataType, int numChannels) {
    return SkYUVAPixmapInfo::DefaultColorTypeForDataType(dataType, numChannels);
}

std::tuple<int, SkYUVAPixmapInfo::DataType> SkYUVAPixmapInfo_NumChannelsAndDataType(SkYUVAPixmapInfo *yuva_pixmap_info, SkColorType type) {
    return SkYUVAPixmapInfo::NumChannelsAndDataType(type);
}

//
// SkYUVAPixmaps
//

// SkYUVAPixmaps & operator=(SkYUVAPixmaps &&that)
// SkYUVAPixmaps & operator=(const SkYUVAPixmaps &that)

SkYUVAPixmaps *SkYUVAPixmaps_new() {
    return new SkYUVAPixmaps();
}

SkYUVAPixmaps *SkYUVAPixmaps_new_2(SkYUVAPixmaps &&that) {
    return new SkYUVAPixmaps(that);
}

SkYUVAPixmaps *SkYUVAPixmaps_new_3(const SkYUVAPixmaps &pixmaps) {
    return new SkYUVAPixmaps(pixmaps);
}

void SkYUVAPixmaps_delete(SkYUVAPixmaps *yuva_pixmaps) {
    delete yuva_pixmaps;
}

bool SkYUVAPixmaps_isValid(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->isValid();
}

const SkYUVAInfo & SkYUVAPixmaps_yuvaInfo(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->yuvaInfo();
}

SkYUVAPixmaps::DataType SkYUVAPixmaps_dataType(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->dataType();
}

SkYUVAPixmapInfo SkYUVAPixmaps_pixmapsInfo(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->pixmapsInfo();
}

int SkYUVAPixmaps_numPlanes(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->numPlanes();
}

const std::array<SkPixmap, SkYUVAPixmaps::kMaxPlanes> & SkYUVAPixmaps_planes(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->planes();
}

const SkPixmap & SkYUVAPixmaps_plane(SkYUVAPixmaps *yuva_pixmaps, int i) {
    return yuva_pixmaps->plane(i);
}

//SkYUVAInfo::YUVALocations SkYUVAPixmaps_toYUVALocations(SkYUVAPixmaps *yuva_pixmaps) {
//    return yuva_pixmaps->toYUVALocations();
//}

bool SkYUVAPixmaps_ownsStorage(SkYUVAPixmaps *yuva_pixmaps) {
    return yuva_pixmaps->ownsStorage();
}

// static

SkColorType SkYUVAPixmaps_RecommendedRGBAColorType(SkYUVAPixmaps::DataType type) {
    return SkYUVAPixmaps::RecommendedRGBAColorType(type);
}

SkYUVAPixmaps SkYUVAPixmaps_Allocate(const SkYUVAPixmapInfo &yuvaPixmapInfo) {
    return SkYUVAPixmaps::Allocate(yuvaPixmapInfo);
}

SkYUVAPixmaps SkYUVAPixmaps_FromData(const SkYUVAPixmapInfo &yuvaPixmapInfo, sk_sp<SkData> data) {
    return SkYUVAPixmaps::FromData(yuvaPixmapInfo, data);
}

SkYUVAPixmaps SkYUVAPixmaps_MakeCopy(const SkYUVAPixmaps &src) {
    return SkYUVAPixmaps::MakeCopy(src);
}

SkYUVAPixmaps SkYUVAPixmaps_FromExternalMemory(const SkYUVAPixmapInfo &yuvaPixmapInfo, void *memory) {
    return SkYUVAPixmaps::FromExternalMemory(yuvaPixmapInfo, memory);
}

SkYUVAPixmaps SkYUVAPixmaps_FromExternalPixmaps(const SkYUVAInfo &yuvaInfo, const SkPixmap pixmaps[SkYUVAPixmaps::kMaxPlanes]) {
    return SkYUVAPixmaps::FromExternalPixmaps(yuvaInfo, pixmaps);
}

}

/*
void used() {
    SkPath *path = SkPath_new();
    SkPoint *p = nullptr;
    p->fX = 0.0;
    p->fY = 0.0;
    SkPath_moveTo_2(path, *p);
}
 */

int main(int argc, char* argv[]) {
/*
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
            SkPaint_setColor(paint, SK_ColorBLUE); // 赤色を選択
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
            SkPath_moveTo(path, R, 0.0f);
            for (int i = 1; i < 7; ++i) {
                SkScalar theta = (float)(3 * i) * TAU / 7;
                SkPath_lineTo(path,R * cos(theta), R * sin(theta));
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
