//
// Created by dolphilia on 2023/12/26.
//

/*
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
    static_sk_capabilities[sk_capabilities_key_out] = SkCapabilities::RasterBackend();
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

void SkRect_MakeXYWH(const char *sk_rect_key_out, float x, float y, float w, float h) {
    static_sk_rect[sk_rect_key_out] = SkRect::MakeXYWH(x, y, w, h);
}

//
// SkStream
//

size_t SkStream_getLength(SkStream *stream) { // inline virtual
    return stream->getLength();
}

void SkStream_MakeFromFile(const char *sk_stream_key_out, const char path[]) { // static
    static_sk_stream[sk_stream_key_out] = SkStream::MakeFromFile(path);
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
*/