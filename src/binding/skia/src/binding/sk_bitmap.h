//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BITMAP_H
#define RAIA_SKIA_SK_BITMAP_H

#include "include/core/SkBitmap.h"
#include "../static/static_sk_pixel_ref.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_image_info.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_pixmap.h"
#include "../static/static_sk_i_size.h"
#include "../static/static_sk_i_point.h"
#include "../static/static_sk_color_4f.h"

extern "C" {
SkBitmap *SkBitmap_new(void);
SkBitmap *SkBitmap_new_2(const SkBitmap *src);
void SkBitmap_delete(SkBitmap *bitmap);
void SkBitmap_allocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque);
void SkBitmap_allocPixels(SkBitmap *bitmap);
void SkBitmap_allocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator);
void SkBitmap_allocPixels_3(SkBitmap *bitmap, const SkImageInfo *info);
void SkBitmap_allocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes);
void SkBitmap_allocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags);
SkAlphaType SkBitmap_alphaType(SkBitmap *bitmap);
sk_image_t SkBitmap_asImage(SkBitmap *bitmap);
sk_i_rect_t SkBitmap_bounds(SkBitmap *bitmap);
int SkBitmap_bytesPerPixel(SkBitmap *bitmap);
SkColorSpace *SkBitmap_colorSpace(SkBitmap *bitmap);
SkColorType SkBitmap_colorType(SkBitmap *bitmap);
size_t SkBitmap_computeByteSize(SkBitmap *bitmap);
sk_i_size_t SkBitmap_dimensions(SkBitmap *bitmap);
bool SkBitmap_drawsNothing(SkBitmap *bitmap);
bool SkBitmap_empty(SkBitmap *bitmap);
void SkBitmap_erase(SkBitmap *bitmap, SkColor c, const SkIRect *area);
void SkBitmap_erase_2(SkBitmap *bitmap, sk_color_4f_t c, const SkIRect *area);
void SkBitmap_eraseArea(SkBitmap *bitmap, const SkIRect *area, SkColor c);
void SkBitmap_eraseARGB(SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b);
void SkBitmap_eraseColor(SkBitmap *bitmap, SkColor c);
void SkBitmap_eraseColor_2(SkBitmap *bitmap, sk_color_4f_t c);
bool SkBitmap_extractAlpha(SkBitmap *bitmap, SkBitmap *dst);
bool SkBitmap_extractAlpha_2(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset);
bool SkBitmap_extractAlpha_3(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset);
bool SkBitmap_extractSubset(SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset);
void *SkBitmap_getAddr(SkBitmap *bitmap, int x, int y);
uint16_t *SkBitmap_getAddr16(SkBitmap *bitmap, int x, int y);
uint32_t *SkBitmap_getAddr32(SkBitmap *bitmap, int x, int y);
uint8_t *SkBitmap_getAddr8(SkBitmap *bitmap, int x, int y);
float SkBitmap_getAlphaf(SkBitmap *bitmap, int x, int y);
void SkBitmap_getBounds(SkBitmap *bitmap, SkIRect *bounds);
void SkBitmap_getBounds2(SkBitmap *bitmap, SkRect *bounds);
SkColor SkBitmap_getColor(SkBitmap *bitmap, int x, int y);
sk_color_4f_t SkBitmap_getColor4f(SkBitmap *bitmap, int x, int y);
uint32_t SkBitmap_getGenerationID(SkBitmap *bitmap);
void *SkBitmap_getPixels(SkBitmap *bitmap);
sk_i_rect_t SkBitmap_getSubset(SkBitmap *bitmap);
int SkBitmap_height(SkBitmap *bitmap);
int SkBitmap_info(SkBitmap *bitmap);
bool SkBitmap_installMaskPixels(SkBitmap *bitmap, SkMaskBuilder *mask);
bool SkBitmap_installPixels(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) ;
bool SkBitmap_installPixels_2(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context);
bool SkBitmap_installPixels_3(SkBitmap *bitmap, const SkPixmap *pixmap);
bool SkBitmap_isImmutable(SkBitmap *bitmap);
bool SkBitmap_isNull(SkBitmap *bitmap);
bool SkBitmap_isOpaque(SkBitmap *bitmap);
sk_shader_t SkBitmap_makeShader(SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkBitmap_makeShader_2(SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkBitmap_makeShader_3(SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
sk_shader_t SkBitmap_makeShader_4(SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
void SkBitmap_notifyPixelsChanged(SkBitmap *bitmap);
bool SkBitmap_peekPixels(SkBitmap *bitmap, SkPixmap *pixmap);
SkPixelRef *SkBitmap_pixelRef(SkBitmap *bitmap);
sk_i_point_t SkBitmap_pixelRefOrigin(SkBitmap *bitmap);
int SkBitmap_pixmap(SkBitmap *bitmap);
bool SkBitmap_readPixels(SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
bool SkBitmap_readPixels_2(SkBitmap *bitmap, const SkPixmap *dst);
bool SkBitmap_readPixels_3(SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY);
bool SkBitmap_readyToDraw(SkBitmap *bitmap);
sk_color_space_t SkBitmap_refColorSpace(SkBitmap *bitmap);
void SkBitmap_reset(SkBitmap *bitmap);
size_t SkBitmap_rowBytes(SkBitmap *bitmap);
int SkBitmap_rowBytesAsPixels(SkBitmap *bitmap);
bool SkBitmap_setAlphaType(SkBitmap *bitmap, SkAlphaType alphaType);
void SkBitmap_setImmutable(SkBitmap *bitmap);
bool SkBitmap_setInfo(SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes);
void SkBitmap_setPixelRef(SkBitmap *bitmap, sk_pixel_ref_t pixelRef, int dx, int dy);
void SkBitmap_setPixels(SkBitmap *bitmap, void *pixels);
int SkBitmap_shiftPerPixel(SkBitmap *bitmap);
void SkBitmap_swap(SkBitmap *bitmap, SkBitmap *other);
bool SkBitmap_tryAllocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque);
bool SkBitmap_tryAllocPixels(SkBitmap *bitmap);
bool SkBitmap_tryAllocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator);
bool SkBitmap_tryAllocPixels_3(SkBitmap *bitmap, const SkImageInfo *info);
bool SkBitmap_tryAllocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes);
bool SkBitmap_tryAllocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags);
int SkBitmap_width(SkBitmap *bitmap);
bool SkBitmap_writePixels(SkBitmap *bitmap, const SkPixmap *src);
bool SkBitmap_writePixels_2(SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY);
// static
bool SkBitmap_ComputeIsOpaque(const SkBitmap *bm);
}

#endif //RAIA_SKIA_SK_BITMAP_H
