//
// Created by dolphilia on 2024/01/05.
//

#include "sk_bitmap.h"

extern "C" {

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
    static_sk_image_set(sk_image_key_out, bitmap->asImage());
}

void SkBitmap_bounds(const char *sk_i_rect_key_out, SkBitmap *bitmap) { // inline
    static_sk_i_rect_set(sk_i_rect_key_out, bitmap->bounds());
}

int SkBitmap_bytesPerPixel(SkBitmap *bitmap) { // inline
    return bitmap->bytesPerPixel();
}

SkColorSpace *SkBitmap_colorSpace(SkBitmap *bitmap) {
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

bool SkBitmap_extractAlpha_2(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator,
                             SkIPoint *offset) {
    return bitmap->extractAlpha(dst, paint, allocator, offset);
}

bool SkBitmap_extractAlpha_3(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset) { // inline
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

void SkBitmap_getSubset(const char *sk_i_rect_key_out, SkBitmap *bitmap) { // inline
    static_sk_i_rect_set(sk_i_rect_key_out, bitmap->getSubset());
}

int SkBitmap_height(SkBitmap *bitmap) { // inline
    return bitmap->height();
}

void SkBitmap_info(const char *sk_image_info_key_out, SkBitmap *bitmap) { // inline
    static_sk_image_info_set(sk_image_info_key_out, bitmap->info());
}

bool SkBitmap_installMaskPixels(SkBitmap *bitmap, SkMaskBuilder *mask) { // Deprecated
    return bitmap->installMaskPixels(*mask);
}

bool SkBitmap_installPixels(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) { // inline
    return bitmap->installPixels(*info, pixels, rowBytes);
}

bool SkBitmap_installPixels_2(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes,
                              void(*releaseProc)(void *addr, void *context), void *context) {
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

void SkBitmap_makeShader(const char *sk_shader_key_out, SkBitmap *bitmap, const SkSamplingOptions *sampling,
                         const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, bitmap->makeShader(*sampling, *lm));
}

void SkBitmap_makeShader_2(const char *sk_shader_key_out, SkBitmap *bitmap, const SkSamplingOptions *sampling,
                           const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, bitmap->makeShader(*sampling, lm));
}

void SkBitmap_makeShader_3(const char *sk_shader_key_out, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy,
                           const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, bitmap->makeShader(tmx, tmy, *sampling, localMatrix));
}

void SkBitmap_makeShader_4(const char *sk_shader_key_out, SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy,
                           const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, bitmap->makeShader(tmx, tmy, *sampling, *lm));
}

void SkBitmap_notifyPixelsChanged(SkBitmap *bitmap) {
    bitmap->notifyPixelsChanged();
}

bool SkBitmap_peekPixels(SkBitmap *bitmap, SkPixmap *pixmap) {
    return bitmap->peekPixels(pixmap);
}

SkPixelRef *SkBitmap_pixelRef(SkBitmap *bitmap) { // inline
    return bitmap->pixelRef();
}

SkIPoint SkBitmap_pixelRefOrigin(SkBitmap *bitmap) {
    return bitmap->pixelRefOrigin();
}

void SkBitmap_pixmap(const char *sk_pixmap_key_out, SkBitmap *bitmap) { // inline
    static_sk_pixmap_set(sk_pixmap_key_out, bitmap->pixmap());
}

bool SkBitmap_readPixels(SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX,
                         int srcY) {
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
    static_sk_color_space_set(sk_color_space_key_out, bitmap->refColorSpace());
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
    bitmap->setPixelRef(static_sk_pixel_ref_move(sk_pixel_ref_key_in), dx, dy);
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

bool SkBitmap_tryAllocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator) {
    return bitmap->tryAllocPixels(allocator);
}

bool SkBitmap_tryAllocPixels_3(SkBitmap *bitmap, const SkImageInfo *info) { // inline
    return bitmap->tryAllocPixels(*info);
}

bool SkBitmap_tryAllocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes) {
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

}