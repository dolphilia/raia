//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PIXMAP_H
#define RAIA_SKIA_SK_PIXMAP_H

#include "include/core/SkPixmap.h"
#include "include/core/SkColorSpace.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_i_size.h"
#include "../static/static_sk_color_4f.h"
#include "export_api.h"

extern "C" {
RAIA_API SkPixmap *SkPixmap_new();
RAIA_API SkPixmap *SkPixmap_new_2(const SkImageInfo *info, const void *addr, size_t rowBytes);
RAIA_API void SkPixmap_delete(SkPixmap *pixmap);
RAIA_API void SkPixmap_reset(SkPixmap *pixmap);
RAIA_API void SkPixmap_reset_2(SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes);
RAIA_API bool SkPixmap_reset_3(SkPixmap *pixmap, const SkMask *mask);
RAIA_API void SkPixmap_setColorSpace(SkPixmap *pixmap, sk_color_space_t color_space);
RAIA_API bool SkPixmap_extractSubset(SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area);
RAIA_API const SkImageInfo * SkPixmap_info(SkPixmap *pixmap);
RAIA_API size_t SkPixmap_rowBytes(SkPixmap *pixmap);
RAIA_API const void * SkPixmap_addr(SkPixmap *pixmap);
RAIA_API int SkPixmap_width(SkPixmap *pixmap);
RAIA_API int SkPixmap_height(SkPixmap *pixmap);
RAIA_API sk_i_size_t SkPixmap_dimensions(SkPixmap *pixmap);
RAIA_API SkColorType SkPixmap_colorType(SkPixmap *pixmap);
RAIA_API SkAlphaType SkPixmap_alphaType(SkPixmap *pixmap);
RAIA_API SkColorSpace * SkPixmap_colorSpace(SkPixmap *pixmap);
RAIA_API sk_color_space_t SkPixmap_refColorSpace(SkPixmap *pixmap);
RAIA_API bool SkPixmap_isOpaque(SkPixmap *pixmap);
RAIA_API sk_i_rect_t SkPixmap_bounds(SkPixmap *pixmap);
RAIA_API int SkPixmap_rowBytesAsPixels(SkPixmap *pixmap);
RAIA_API int SkPixmap_shiftPerPixel(SkPixmap *pixmap);
RAIA_API size_t SkPixmap_computeByteSize(SkPixmap *pixmap);
RAIA_API bool SkPixmap_computeIsOpaque(SkPixmap *pixmap);
RAIA_API SkColor SkPixmap_getColor(SkPixmap *pixmap, int x, int y);
RAIA_API sk_color_4f_t SkPixmap_getColor4f(SkPixmap *pixmap, int x, int y);
RAIA_API float SkPixmap_getAlphaf(SkPixmap *pixmap, int x, int y);
RAIA_API const void * SkPixmap_addr_2(SkPixmap *pixmap, int x, int y);
RAIA_API const uint8_t * SkPixmap_addr8(SkPixmap *pixmap);
RAIA_API const uint16_t * SkPixmap_addr16(SkPixmap *pixmap);
RAIA_API const uint32_t * SkPixmap_addr32(SkPixmap *pixmap);
RAIA_API const uint64_t * SkPixmap_addr64(SkPixmap *pixmap);
RAIA_API const uint16_t * SkPixmap_addrF16(SkPixmap *pixmap);
RAIA_API const uint8_t * SkPixmap_addr8_2(SkPixmap *pixmap, int x, int y);
RAIA_API const uint16_t * SkPixmap_addr16_2(SkPixmap *pixmap, int x, int y);
RAIA_API const uint32_t * SkPixmap_addr32_2(SkPixmap *pixmap, int x, int y);
RAIA_API const uint64_t * SkPixmap_addr64_2(SkPixmap *pixmap, int x, int y);
RAIA_API const uint16_t * SkPixmap_addrF16_2(SkPixmap *pixmap, int x, int y);
RAIA_API void * SkPixmap_writable_addr(SkPixmap *pixmap);
RAIA_API void * SkPixmap_writable_addr_2(SkPixmap *pixmap, int x, int y);
RAIA_API uint8_t * SkPixmap_writable_addr8(SkPixmap *pixmap, int x, int y);
RAIA_API uint16_t * SkPixmap_writable_addr16(SkPixmap *pixmap, int x, int y);
RAIA_API uint32_t * SkPixmap_writable_addr32(SkPixmap *pixmap, int x, int y);
RAIA_API uint64_t * SkPixmap_writable_addr64(SkPixmap *pixmap, int x, int y);
RAIA_API uint16_t * SkPixmap_writable_addrF16(SkPixmap *pixmap, int x, int y);
RAIA_API bool SkPixmap_readPixels(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes);
RAIA_API bool SkPixmap_readPixels_2(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
RAIA_API bool SkPixmap_readPixels_3(SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY);
RAIA_API bool SkPixmap_readPixels_4(SkPixmap *pixmap, const SkPixmap *dst);
RAIA_API bool SkPixmap_scalePixels(SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options);
RAIA_API bool SkPixmap_erase(SkPixmap *pixmap, SkColor color, const SkIRect *subset);
RAIA_API bool SkPixmap_erase_2(SkPixmap *pixmap, SkColor color);
RAIA_API bool SkPixmap_erase_3(SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset);
}

#endif //RAIA_SKIA_SK_PIXMAP_H
