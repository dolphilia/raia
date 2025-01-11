//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BITMAP_H
#define RAIA_SKIA_SK_BITMAP_H

#include "include/core/SkBitmap.h"
#include "../static/static_sk_color_4f.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_i_point.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_i_size.h"
#include "../static/static_sk_image_info.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_pixel_ref.h"
#include "../static/static_sk_pixmap.h"
#include "../static/static_sk_shader.h"
#include "export_api.h"

extern "C" {
RAIA_API SkBitmap *SkBitmap_new(void);
RAIA_API SkBitmap *SkBitmap_new_2(const SkBitmap *src);
RAIA_API void SkBitmap_delete(SkBitmap *bitmap);
RAIA_API void SkBitmap_allocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque);
RAIA_API void SkBitmap_allocPixels(SkBitmap *bitmap);
RAIA_API void SkBitmap_allocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator);
RAIA_API void SkBitmap_allocPixels_3(SkBitmap *bitmap, const SkImageInfo *info);
RAIA_API void SkBitmap_allocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes);
RAIA_API void SkBitmap_allocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags);
RAIA_API SkAlphaType SkBitmap_alphaType(SkBitmap *bitmap);
RAIA_API sk_image_t SkBitmap_asImage(SkBitmap *bitmap);
RAIA_API sk_i_rect_t SkBitmap_bounds(SkBitmap *bitmap);
RAIA_API int SkBitmap_bytesPerPixel(SkBitmap *bitmap);
RAIA_API SkColorSpace *SkBitmap_colorSpace(SkBitmap *bitmap);
RAIA_API SkColorType SkBitmap_colorType(SkBitmap *bitmap);
RAIA_API size_t SkBitmap_computeByteSize(SkBitmap *bitmap);
RAIA_API sk_i_size_t SkBitmap_dimensions(SkBitmap *bitmap);
RAIA_API bool SkBitmap_drawsNothing(SkBitmap *bitmap);
RAIA_API bool SkBitmap_empty(SkBitmap *bitmap);
RAIA_API void SkBitmap_erase(SkBitmap *bitmap, SkColor c, const SkIRect *area);
RAIA_API void SkBitmap_erase_2(SkBitmap *bitmap, sk_color_4f_t c, const SkIRect *area);
RAIA_API void SkBitmap_eraseArea(SkBitmap *bitmap, const SkIRect *area, SkColor c);
RAIA_API void SkBitmap_eraseARGB(SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b);
RAIA_API void SkBitmap_eraseColor(SkBitmap *bitmap, SkColor c);
RAIA_API void SkBitmap_eraseColor_2(SkBitmap *bitmap, sk_color_4f_t c);
RAIA_API bool SkBitmap_extractAlpha(SkBitmap *bitmap, SkBitmap *dst);
RAIA_API bool SkBitmap_extractAlpha_2(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset);
RAIA_API bool SkBitmap_extractAlpha_3(SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset);
RAIA_API bool SkBitmap_extractSubset(SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset);
RAIA_API void *SkBitmap_getAddr(SkBitmap *bitmap, int x, int y);
RAIA_API uint16_t *SkBitmap_getAddr16(SkBitmap *bitmap, int x, int y);
RAIA_API uint32_t *SkBitmap_getAddr32(SkBitmap *bitmap, int x, int y);
RAIA_API uint8_t *SkBitmap_getAddr8(SkBitmap *bitmap, int x, int y);
RAIA_API float SkBitmap_getAlphaf(SkBitmap *bitmap, int x, int y);
RAIA_API void SkBitmap_getBounds(SkBitmap *bitmap, SkIRect *bounds);
RAIA_API void SkBitmap_getBounds2(SkBitmap *bitmap, SkRect *bounds);
RAIA_API SkColor SkBitmap_getColor(SkBitmap *bitmap, int x, int y);
RAIA_API sk_color_4f_t SkBitmap_getColor4f(SkBitmap *bitmap, int x, int y);
RAIA_API uint32_t SkBitmap_getGenerationID(SkBitmap *bitmap);
RAIA_API void *SkBitmap_getPixels(SkBitmap *bitmap);
RAIA_API sk_i_rect_t SkBitmap_getSubset(SkBitmap *bitmap);
RAIA_API int SkBitmap_height(SkBitmap *bitmap);
RAIA_API int SkBitmap_info(SkBitmap *bitmap);
RAIA_API bool SkBitmap_installMaskPixels(SkBitmap *bitmap, SkMaskBuilder *mask);
RAIA_API bool SkBitmap_installPixels(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) ;
RAIA_API bool SkBitmap_installPixels_2(SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context);
RAIA_API bool SkBitmap_installPixels_3(SkBitmap *bitmap, const SkPixmap *pixmap);
RAIA_API bool SkBitmap_isImmutable(SkBitmap *bitmap);
RAIA_API bool SkBitmap_isNull(SkBitmap *bitmap);
RAIA_API bool SkBitmap_isOpaque(SkBitmap *bitmap);
RAIA_API sk_shader_t SkBitmap_makeShader(SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkBitmap_makeShader_2(SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkBitmap_makeShader_3(SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
RAIA_API sk_shader_t SkBitmap_makeShader_4(SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API void SkBitmap_notifyPixelsChanged(SkBitmap *bitmap);
RAIA_API bool SkBitmap_peekPixels(SkBitmap *bitmap, SkPixmap *pixmap);
RAIA_API SkPixelRef *SkBitmap_pixelRef(SkBitmap *bitmap);
RAIA_API sk_i_point_t SkBitmap_pixelRefOrigin(SkBitmap *bitmap);
RAIA_API int SkBitmap_pixmap(SkBitmap *bitmap);
RAIA_API bool SkBitmap_readPixels(SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
RAIA_API bool SkBitmap_readPixels_2(SkBitmap *bitmap, const SkPixmap *dst);
RAIA_API bool SkBitmap_readPixels_3(SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY);
RAIA_API bool SkBitmap_readyToDraw(SkBitmap *bitmap);
RAIA_API sk_color_space_t SkBitmap_refColorSpace(SkBitmap *bitmap);
RAIA_API void SkBitmap_reset(SkBitmap *bitmap);
RAIA_API size_t SkBitmap_rowBytes(SkBitmap *bitmap);
RAIA_API int SkBitmap_rowBytesAsPixels(SkBitmap *bitmap);
RAIA_API bool SkBitmap_setAlphaType(SkBitmap *bitmap, SkAlphaType alphaType);
RAIA_API void SkBitmap_setImmutable(SkBitmap *bitmap);
RAIA_API bool SkBitmap_setInfo(SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes);
RAIA_API void SkBitmap_setPixelRef(SkBitmap *bitmap, sk_pixel_ref_t pixelRef, int dx, int dy);
RAIA_API void SkBitmap_setPixels(SkBitmap *bitmap, void *pixels);
RAIA_API int SkBitmap_shiftPerPixel(SkBitmap *bitmap);
RAIA_API void SkBitmap_swap(SkBitmap *bitmap, SkBitmap *other);
RAIA_API bool SkBitmap_tryAllocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque);
RAIA_API bool SkBitmap_tryAllocPixels(SkBitmap *bitmap);
RAIA_API bool SkBitmap_tryAllocPixels_2(SkBitmap *bitmap, SkBitmap::Allocator *allocator);
RAIA_API bool SkBitmap_tryAllocPixels_3(SkBitmap *bitmap, const SkImageInfo *info);
RAIA_API bool SkBitmap_tryAllocPixels_4(SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes);
RAIA_API bool SkBitmap_tryAllocPixelsFlags(SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags);
RAIA_API int SkBitmap_width(SkBitmap *bitmap);
RAIA_API bool SkBitmap_writePixels(SkBitmap *bitmap, const SkPixmap *src);
RAIA_API bool SkBitmap_writePixels_2(SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY);
// static
RAIA_API bool SkBitmap_ComputeIsOpaque(const SkBitmap *bm);
}

#endif //RAIA_SKIA_SK_BITMAP_H
