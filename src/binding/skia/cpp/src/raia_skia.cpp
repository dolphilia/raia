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
#include "include/core/SkImage.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPixelRef.h"
#include "include/core/SkRect.h"
#include "include/core/SkShader.h"
#include "include/core/SkStream.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkVertices.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/gpu/graphite/Recorder.h"

#include <map>

//
// static
//

static std::map<std::string, std::unique_ptr<SkStream>> static_sk_stream;
static std::map<std::string, std::unique_ptr<SkCanvas>> static_sk_canvas;
static std::map<std::string, sk_sp<SkData>> static_sk_data;
static std::map<std::string, sk_sp<SkImage>> static_sk_image;
static std::map<std::string, sk_sp<SkShader>> static_sk_shader;
static std::map<std::string, sk_sp<SkColorSpace>> static_sk_color_space;
static std::map<std::string, sk_sp<SkPixelRef>> static_sk_pixel_ref;
static std::map<std::string, sk_sp<SkBlender>> static_sk_blender;
static std::map<std::string, sk_sp<SkPicture>> static_sk_picture;
static std::map<std::string, sk_sp<SkTextBlob>> static_sk_text_blob;
static std::map<std::string, sk_sp<SkVertices>> static_sk_vertices;
static std::map<std::string, sk_sp<SkSurface>> static_sk_surface;
static std::map<std::string, sk_sp<const SkCapabilities>> static_sk_capabilities;
static std::map<std::string, sk_sp<SkColorFilter>> static_sk_color_filter;
static std::map<std::string, sk_sp<SkFlattenable>> static_sk_flattenable;
static std::map<std::string, sk_sp<SkColorTable>> static_sk_color_table;
static std::map<std::string, sk_sp<SkContourMeasure>> static_sk_contour_measure;
static std::map<std::string, sk_sp<SkPathEffect>> static_sk_path_effect;
static std::map<std::string, sk_sp<SkDataTable>> static_sk_data_table;
//static std::map<std::string, sk_sp<SkColorMatrix>> static_sk_color_matrix;

// static std::map<std::string, sk_sp<SkDevice>> static_sk_device;
static std::map<std::string, SkRect> static_sk_rect;

extern "C" {

//
// static
//

SkStream *static_sk_stream_get(const char *sk_stream_key){
    return static_sk_stream[sk_stream_key].get();
}

SkImage *static_sk_image_get(const char *sk_image_key){
    return static_sk_image[sk_image_key].get();
}

void static_sk_rect_delete(const char *sk_rect_key) {
    static_sk_rect.erase(sk_rect_key);
}

void static_sk_data_delete(const char *sk_data_key) {
    static_sk_data[sk_data_key].reset();
    static_sk_data.erase(sk_data_key);
}

void static_sk_stream_delete(const char *sk_stream_key) {
    static_sk_stream[sk_stream_key].reset();
    static_sk_stream.erase(sk_stream_key);
}

void static_sk_image_delete(const char *sk_image_key) {
    static_sk_image[sk_image_key].reset(); // スマートポインタを明示的に解放する
    static_sk_image.erase(sk_image_key);
}

void static_sk_shader_delete(const char *sk_shader_key) {
    static_sk_shader[sk_shader_key].reset();
    static_sk_shader.erase(sk_shader_key);
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

void SkBitmap_allocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque = false) {
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

void SkBitmap_asImage(const char *sk_image_key, SkBitmap *bitmap) {
    static_sk_image[sk_image_key] = bitmap->asImage();
}

SkIRect SkBitmap_bounds(SkBitmap *bitmap) { // inline
    return bitmap->bounds();
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

bool SkBitmap_ComputeIsOpaque(const SkBitmap *bm) { // inline static
    return SkBitmap::ComputeIsOpaque(*bm);
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

SkIRect SkBitmap_getSubset(SkBitmap *bitmap) { // inline
    return bitmap->getSubset();
}

int SkBitmap_height(SkBitmap *bitmap) { // inline
    return bitmap->height();
}

SkImageInfo SkBitmap_info(SkBitmap *bitmap) { // inline
    return bitmap->info();
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

void SkBitmap_makeShader(const char *sk_shader_key, SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key] = bitmap->makeShader(*sampling, *lm);
}

void SkBitmap_makeShader_2(const char *sk_shader_key, SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader[sk_shader_key] = bitmap->makeShader(*sampling, lm);
}

void SkBitmap_makeShader_3(const char *sk_shader_key, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions * sampling, const SkMatrix * localMatrix) {
    static_sk_shader[sk_shader_key] = bitmap->makeShader(tmx, tmy, *sampling, localMatrix);
}

void SkBitmap_makeShader_4(const char *sk_shader_key, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions * sampling, const SkMatrix * lm) {
    static_sk_shader[sk_shader_key] = bitmap->makeShader(tmx, tmy, *sampling, *lm);
}

void SkBitmap_notifyPixelsChanged(SkBitmap *bitmap) {
    bitmap->notifyPixelsChanged();
}

// SkBitmap& SkBitmap::operator=(const SkBitmap & src)
// SkBitmap& SkBitmap::operator=(SkBitmap && src)

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

void SkBitmap_refColorSpace(const char *sk_color_space_key, SkBitmap *bitmap) {
    static_sk_color_space[sk_color_space_key] = bitmap->refColorSpace();
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

bool SkBitmap_setInfo(SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes /* = 0 */) {
    return bitmap->setInfo(*imageInfo, rowBytes);
}

void SkBitmap_setPixelRef(const char *sk_pixel_ref_key, SkBitmap *bitmap, int dx, int dy) {
    bitmap->setPixelRef(static_sk_pixel_ref[sk_pixel_ref_key], dx, dy);
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

bool SkBitmap_tryAllocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque /* = false */) {
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

//
// SkBlender
//

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

void SkCanvas_clipShader(const char *sk_shader_key, SkCanvas *canvas, SkClipOp op) {
    canvas->clipShader(static_sk_shader[sk_shader_key], op);
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

void SkCanvas_drawAnnotation(const char *sk_data_key, SkCanvas *canvas, const SkRect * rect, const char key[]) {
    canvas->drawAnnotation(*rect, key, static_sk_data[sk_data_key]);
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

void SkCanvas_drawImage(const char *sk_image_key, SkCanvas *canvas, SkScalar left, SkScalar top) {
    canvas->drawImage(static_sk_image[sk_image_key], left, top);
}

void SkCanvas_drawImage_2(const char *sk_image_key, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImage(static_sk_image[sk_image_key], x, y, *sampling, paint);
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

void SkCanvas_drawImageRect(const char *sk_image_key, SkCanvas *canvas, const SkRect * dst, const SkSamplingOptions * sampling, const SkPaint * paint) {
    canvas->drawImageRect(static_sk_image[sk_image_key], *dst, *sampling, paint);
}

void SkCanvas_drawImageRect_2(const char *sk_image_key, SkCanvas *canvas, const SkRect * src, const SkRect * dst, const SkSamplingOptions * sampling,const SkPaint * paint, SkCanvas::SrcRectConstraint constraint ) {
    canvas->drawImageRect(static_sk_image[sk_image_key], *src, *dst, *sampling, paint, constraint);
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

void SkCanvas_drawMesh(const char *sk_blender_key, SkCanvas *canvas, const SkMesh * mesh, const SkPaint * paint) {
    canvas->drawMesh(*mesh, static_sk_blender[sk_blender_key], *paint);
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

void SkCanvas_drawPicture(const char *sk_picture_key, SkCanvas *canvas) {
    canvas->drawPicture(static_sk_picture[sk_picture_key]);
}

void SkCanvas_drawPicture_2(const char *sk_picture_key, SkCanvas *canvas, const SkMatrix * matrix, const SkPaint * paint) {
    canvas->drawPicture(static_sk_picture[sk_picture_key], matrix, paint);
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

void SkCanvas_drawRect(const char *sk_rect_key, SkCanvas *canvas, const SkPaint *paint) {
    canvas->drawRect(static_sk_rect[sk_rect_key], *paint);
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

void SkCanvas_drawTextBlob(const char *sk_text_blob_key, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint * paint) {
    canvas->drawTextBlob(static_sk_text_blob[sk_text_blob_key], x, y, *paint);
}

void SkCanvas_drawTextBlob_2(SkCanvas *canvas, const SkTextBlob * blob, SkScalar x, SkScalar y, const SkPaint * paint) {
    canvas->drawTextBlob(blob, x, y, *paint);
}

void SkCanvas_drawVertices(const char *sk_vertices_key, SkCanvas *canvas, SkBlendMode mode, const SkPaint * paint) {
    canvas->drawVertices(static_sk_vertices[sk_vertices_key], mode, *paint);
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

void SkCanvas_makeSurface(const char *sk_surface_key, SkCanvas *canvas, const SkImageInfo * info, const SkSurfaceProps * props) {
    static_sk_surface[sk_surface_key] = canvas->makeSurface(*info, props);
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

void SkCanvas_MakeRasterDirect(const char *sk_canvas_key, const SkImageInfo * info, void * pixels, size_t rowBytes, const SkSurfaceProps * props) {
    static_sk_canvas[sk_canvas_key] = SkCanvas::MakeRasterDirect(*info, pixels, rowBytes, props);
}

void SkCanvas_MakeRasterDirectN32(const char *sk_canvas_key, int width, int height, SkPMColor * pixels, size_t rowBytes) {
    static_sk_canvas[sk_canvas_key] = SkCanvas::MakeRasterDirectN32(width, height, pixels, rowBytes);
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

void SkCapabilities_RasterBackend(const char *sk_capabilities_key) {
    static_sk_capabilities[sk_capabilities_key] = SkCapabilities::RasterBackend();
}

//
// SkColor
//

// static

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

bool SkColorFilter_asAColorMatrix(SkColorFilter *color_filter, float matrix[20]) {
    return color_filter->asAColorMatrix(matrix);
}

bool SkColorFilter_asAColorMode(SkColorFilter *color_filter, SkColor * color, SkBlendMode * mode) {
    return color_filter->asAColorMode(color, mode);
}

SkColor SkColorFilter_filterColor(SkColorFilter *color_filter, SkColor color) {
    return color_filter->filterColor(color);
}

SkColor4f SkColorFilter_filterColor4f(SkColorFilter *color_filter, const SkColor4f * srcColor, SkColorSpace * srcCS, SkColorSpace * dstCS) {
    return color_filter->filterColor4f(*srcColor, srcCS, dstCS);
}

bool SkColorFilter_isAlphaUnchanged(SkColorFilter *color_filter) {
    return color_filter->isAlphaUnchanged();
}

void SkColorFilter_makeComposed(const char *sk_color_filter_key, SkColorFilter *color_filter) {
    static_sk_color_filter[sk_color_filter_key] = color_filter->makeComposed(static_sk_color_filter[sk_color_filter_key]);
}

void SkColorFilter_makeWithWorkingColorSpace(const char *sk_color_filter_key, const char * sk_color_space_key, SkColorFilter *color_filter) {
    static_sk_color_filter[sk_color_filter_key] = color_filter->makeWithWorkingColorSpace(static_sk_color_space[sk_color_space_key]);
}

// static

void SkColorFilter_Deserialize(const char *sk_color_filter_key, const void * data, size_t size, const SkDeserialProcs * procs) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilter::Deserialize(data, size, procs);
}

//
// SkColorFilters
//

// static

void SkColorFilters_Blend(const char *sk_color_filter_key, const char * sk_color_space_key, const SkColor4f * c, SkBlendMode mode) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Blend(*c, static_sk_color_space[sk_color_space_key], mode);
}

void SkColorFilters_Blend_2(const char *sk_color_filter_key, SkColor c, SkBlendMode mode) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Blend(c, mode);
}

void SkColorFilters_Compose(const char *sk_color_filter_key_1, const char *sk_color_filter_key_2) {
    static_sk_color_filter[sk_color_filter_key_1] = SkColorFilters::Compose(static_sk_color_filter[sk_color_filter_key_1], static_sk_color_filter[sk_color_filter_key_2]);
}

void SkColorFilters_HSLAMatrix(const char *sk_color_filter_key, const float rowMajor[20]) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::HSLAMatrix(rowMajor);
}

void SkColorFilters_HSLAMatrix_2(const char *sk_color_filter_key, const SkColorMatrix *matrix) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::HSLAMatrix(*matrix);
}

void SkColorFilters_Lerp(const char *sk_color_filter_key_1, const char *sk_color_filter_key_2, float t) {
    static_sk_color_filter[sk_color_filter_key_1] = SkColorFilters::Lerp(t, static_sk_color_filter[sk_color_filter_key_1], static_sk_color_filter[sk_color_filter_key_2]);
}

void SkColorFilters_Lighting(const char *sk_color_filter_key, SkColor mul, SkColor add) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Lighting(mul, add);
}

void SkColorFilters_LinearToSRGBGamma(const char *sk_color_filter_key) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::LinearToSRGBGamma();
}

void SkColorFilters_Matrix(const char *sk_color_filter_key, const float rowMajor[20]) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Matrix(rowMajor);
}

void SkColorFilters_Matrix_2(const char *sk_color_filter_key, const SkColorMatrix *matrix) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Matrix(*matrix);
}

void SkColorFilters_SRGBToLinearGamma(const char *sk_color_filter_key) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::SRGBToLinearGamma();
}

void SkColorFilters_Table(const char *sk_color_filter_key, const uint8_t table[256]) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Table(table);
}

void SkColorFilters_Table_2(const char *sk_color_filter_key, const char *sk_color_table_key) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::Table(static_sk_color_table[sk_color_table_key]);
}

void SkColorFilters_TableARGB(const char *sk_color_filter_key, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    static_sk_color_filter[sk_color_filter_key] = SkColorFilters::TableARGB(tableA, tableR, tableG, tableB);
}

//
// SkColorInfo
//

SkColorInfo *SkColorInfo_new() {
    return new SkColorInfo();
}

SkColorInfo *SkColorInfo_new_2(const char *sk_color_space_key, SkColorType ct, SkAlphaType at) {
    return new SkColorInfo(ct, at, static_sk_color_space[sk_color_space_key]);
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

SkColorInfo SkColorInfo_makeColorSpace(const char *sk_color_space_key, SkColorInfo *color_info) {
    return color_info->makeColorSpace(static_sk_color_space[sk_color_space_key]);
}

SkColorInfo SkColorInfo_makeColorType(SkColorInfo *color_info, SkColorType newColorType) {
    return color_info->makeColorType(newColorType);
}

void SkColorInfo_refColorSpace(const char *sk_color_space_key, SkColorInfo *color_info) {
    static_sk_color_space[sk_color_space_key] = color_info->refColorSpace();
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

void setIdentity(SkColorMatrix *color_matrix) {
    color_matrix->setIdentity();
}

void setScale(SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale) {
    color_matrix->setScale(rScale, gScale, bScale, aScale);
}

void postTranslate(SkColorMatrix *color_matrix, float dr, float dg, float db, float da) {
    color_matrix->postTranslate(dr, dg, db, da);
}

void setConcat(SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b) {
    color_matrix->setConcat(*a, *b);
}

void preConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->preConcat(*mat);
}

void postConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->postConcat(*mat);
}

void setSaturation(SkColorMatrix *color_matrix, float sat) {
    color_matrix->setSaturation(sat);
}

void setRowMajor(SkColorMatrix *color_matrix, const float src[20]) {
    color_matrix->setRowMajor(src);
}

void getRowMajor(SkColorMatrix *color_matrix, float dst[20]) {
    color_matrix->getRowMajor(dst);
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

void SkColorSpace_makeLinearGamma(const char *sk_color_space_key, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key] = color_space->makeLinearGamma();
}

void SkColorSpace_makeSRGBGamma(const char *sk_color_space_key, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key] = color_space->makeSRGBGamma();
}

void SkColorSpace_makeColorSpin(const char *sk_color_space_key, SkColorSpace *color_space) {
    static_sk_color_space[sk_color_space_key] = color_space->makeColorSpin();
}

bool SkColorSpace_isSRGB(SkColorSpace *color_space) {
    return color_space->isSRGB();
}

void SkColorSpace_serialize(const char *sk_data_key, SkColorSpace *color_space) {
    static_sk_data[sk_data_key] = color_space->serialize();
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

void SkColorTable_Make(const char *sk_color_table_key, const uint8_t table[256]) {
    static_sk_color_table[sk_color_table_key] = SkColorTable::Make(table);
}

void SkColorTable_Make_2(const char *sk_color_table_key, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    static_sk_color_table[sk_color_table_key] = SkColorTable::Make(tableA, tableR, tableG, tableB);
}

void SkColorTable_Deserialize(const char *sk_color_table_key, SkReadBuffer *buffer) {
    static_sk_color_table[sk_color_table_key] = SkColorTable::Deserialize(*buffer);
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

void SkContourMeasureIter_next(const char* sk_contour_measure_key, SkContourMeasureIter *contour_measure_iter) {
    static_sk_contour_measure[sk_contour_measure_key] = contour_measure_iter->next();
}

//
// SkCornerPathEffect
//

// static

void SkCornerPathEffect_Make(const char *sk_path_effect_key, SkScalar radius) {
    static_sk_path_effect[sk_path_effect_key] = SkCornerPathEffect::Make(radius);
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

bool SkCubicMap_IsLinear(SkPoint p1, SkPoint p2) {
    return SkCubicMap::IsLinear(p1, p2);
}

//
// SkDashPathEffect
//

void SkDashPathEffect_Make(const char *sk_path_effect_key, const SkScalar intervals[], int count, SkScalar phase) {
    static_sk_path_effect[sk_path_effect_key] = SkDashPathEffect::Make(intervals, count, phase);
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

void SkData_MakeWithCopy(const char *sk_data_key, const void *data, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeWithCopy(data, length);
}

void SkData_MakeUninitialized(const char *sk_data_key, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeUninitialized(length);
}

void SkData_MakeZeroInitialized(const char *sk_data_key, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeZeroInitialized(length);
}

void SkData_MakeWithCString(const char *sk_data_key, const char cstr[]) {
    static_sk_data[sk_data_key] = SkData::MakeWithCString(cstr);
}

void SkData_MakeWithProc(const char *sk_data_key, const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) {
    static_sk_data[sk_data_key] = SkData::MakeWithProc(ptr, length, proc, ctx);
}

void SkData_MakeWithoutCopy(const char *sk_data_key, const void *data, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeWithoutCopy(data, length);
}

void SkData_MakeFromMalloc(const char *sk_data_key, const void *data, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeFromMalloc(data, length);
}

void SkData_MakeFromFileName(const char *sk_data_key, const char path[]) {
    static_sk_data[sk_data_key] = SkData::MakeFromFileName(path);
}

void SkData_MakeFromFILE(const char *sk_data_key, FILE *f) {
    static_sk_data[sk_data_key] = SkData::MakeFromFILE(f);
}

void SkData_MakeFromFD(const char *sk_data_key, int fd) {
    static_sk_data[sk_data_key] = SkData::MakeFromFD(fd);
}

void SkData_MakeFromStream(const char *sk_data_key, SkStream * stream, size_t size) {
    static_sk_data[sk_data_key] = SkData::MakeFromStream(stream, size);
}

void SkData_MakeSubset(const char *sk_data_key, const SkData *src, size_t offset, size_t length) {
    static_sk_data[sk_data_key] = SkData::MakeSubset(src, offset, length);
}

void SkData_MakeEmpty(const char *sk_data_key) {
    static_sk_data[sk_data_key] = SkData::MakeEmpty();
}

//
// SkData
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

void SkDataTable_MakeEmpty(const char *sk_data_table_key) {
    static_sk_data_table[sk_data_table_key] = SkDataTable::MakeEmpty();
}

void SkDataTable_MakeCopyArrays(const char *sk_data_table_key, const void *const *ptrs, const size_t sizes[], int count) {
    static_sk_data_table[sk_data_table_key] = SkDataTable::MakeCopyArrays(ptrs, sizes, count);
}

void SkDataTable_MakeCopyArray(const char *sk_data_table_key, const void *array, size_t elemSize, int count) {
    static_sk_data_table[sk_data_table_key] = SkDataTable::MakeCopyArray(array, elemSize, count);
}

void SkDataTable_MakeArrayProc(const char *sk_data_table_key, const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context) {
    static_sk_data_table[sk_data_table_key] = SkDataTable::MakeArrayProc(array, elemSize, count, proc, context);
}

//
// SkFont
//

//
// SkImage
//

void SkImages_DeferredFromEncodedData(const char *sk_image_key, const char *data_key) {
    static_sk_image[sk_image_key] = SkImages::DeferredFromEncodedData(static_sk_data[data_key]);
}

//
// SkImageInfo
//

//
// SkIPoint
//

//
// SkIRect
//

//
// SkMatrix
//

//
// SkPaint
//

void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode) {
    paint->setBlendMode(mode);
}

void SkPaint_setColor(SkPaint *paint, const SkColor4f *color,  SkColorSpace *colorSpace) {
    paint->setColor(*color, colorSpace);
}

void SkPaint_setColor_2(SkPaint *paint, SkColor color) {
    paint->setColor(color);
}

//
// SkPath
//

SkPath *SkPath_new() {
    return new SkPath();
}

void SkPath_close(SkPath *path) {
    path->close();
}

void SkPath_lineTo(SkPath *path, const SkPoint *p) {
    path->lineTo(*p);
}

void SkPath_lineTo_2(SkPath *path, SkScalar x, SkScalar y) {
    path->lineTo(x, y);
}

void SkPath_moveTo(SkPath *path, const SkPoint *p) {
    path->moveTo(*p);
}

void SkPath_moveTo_2(SkPath *path, SkScalar x, SkScalar y) {
    path->moveTo(x, y);
}

//
// SkPicture
//

//
// SkPixmap
//

//
// SkPoint
//

SkPaint *SkPaint_new() {
    return new SkPaint();
}

void SkPaint_setAntiAlias(SkPaint *paint, bool aa) {
    paint->setAntiAlias(aa);
}

void SkPaint_setARGB(SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    paint->setARGB(a, r, g, b);
}

//
// SkRRect
//

//
// SkRect
//

void SkRect_MakeXYWH(const char *sk_rect_key, float x, float y, float w, float h) {
    static_sk_rect[sk_rect_key] = SkRect::MakeXYWH(x, y, w, h);
}

//
// SkStream
//

size_t SkStream_getLength(const char *sk_stream_key) { // inline virtual
    return static_sk_stream[sk_stream_key]->getLength();
}

void SkStream_MakeFromFile(const char *sk_stream_key, const char path[]) { // static
    static_sk_stream[sk_stream_key] = SkStream::MakeFromFile(path);
}

//
// SkRegion
//

//
// SkSurface
//

//
// SkTextBlob
//

//
// SkTextBlobBuilder
//

}

int main(int argc, char* argv[]) {
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
        SkBitmap_allocN32Pixels(skBitmap, image_width, image_height);
        SkCanvas *canvas = SkCanvas_new_4(skBitmap);

        {
            // PNG画像を読み込む
            SkStream_MakeFromFile("image_file", "adv_sample_image.png");
            SkData_MakeFromStream("image_data", static_sk_stream_get("image_file"), SkStream_getLength("image_file"));
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
    return 0;
}