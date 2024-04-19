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

extern "C" {
SkPixmap *SkPixmap_new();
SkPixmap *SkPixmap_new_2(const SkImageInfo *info, const void *addr, size_t rowBytes);
void SkPixmap_delete(SkPixmap *pixmap);
void SkPixmap_reset(SkPixmap *pixmap);
void SkPixmap_reset_2(SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes);
bool SkPixmap_reset_3(SkPixmap *pixmap, const SkMask *mask);
void SkPixmap_setColorSpace(SkPixmap *pixmap, sk_color_space_t color_space);
bool SkPixmap_extractSubset(SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area);
const SkImageInfo * SkPixmap_info(SkPixmap *pixmap);
size_t SkPixmap_rowBytes(SkPixmap *pixmap);
const void * SkPixmap_addr(SkPixmap *pixmap);
int SkPixmap_width(SkPixmap *pixmap);
int SkPixmap_height(SkPixmap *pixmap);
sk_i_size_t SkPixmap_dimensions(SkPixmap *pixmap);
SkColorType SkPixmap_colorType(SkPixmap *pixmap);
SkAlphaType SkPixmap_alphaType(SkPixmap *pixmap);
SkColorSpace * SkPixmap_colorSpace(SkPixmap *pixmap);
sk_color_space_t SkPixmap_refColorSpace(SkPixmap *pixmap);
bool SkPixmap_isOpaque(SkPixmap *pixmap);
sk_i_rect_t SkPixmap_bounds(SkPixmap *pixmap);
int SkPixmap_rowBytesAsPixels(SkPixmap *pixmap);
int SkPixmap_shiftPerPixel(SkPixmap *pixmap);
size_t SkPixmap_computeByteSize(SkPixmap *pixmap);
bool SkPixmap_computeIsOpaque(SkPixmap *pixmap);
SkColor SkPixmap_getColor(SkPixmap *pixmap, int x, int y);
sk_color_4f_t SkPixmap_getColor4f(SkPixmap *pixmap, int x, int y);
float SkPixmap_getAlphaf(SkPixmap *pixmap, int x, int y);
const void * SkPixmap_addr_2(SkPixmap *pixmap, int x, int y);
const uint8_t * SkPixmap_addr8(SkPixmap *pixmap);
const uint16_t * SkPixmap_addr16(SkPixmap *pixmap);
const uint32_t * SkPixmap_addr32(SkPixmap *pixmap);
const uint64_t * SkPixmap_addr64(SkPixmap *pixmap);
const uint16_t * SkPixmap_addrF16(SkPixmap *pixmap);
const uint8_t * SkPixmap_addr8_2(SkPixmap *pixmap, int x, int y);
const uint16_t * SkPixmap_addr16_2(SkPixmap *pixmap, int x, int y);
const uint32_t * SkPixmap_addr32_2(SkPixmap *pixmap, int x, int y);
const uint64_t * SkPixmap_addr64_2(SkPixmap *pixmap, int x, int y);
const uint16_t * SkPixmap_addrF16_2(SkPixmap *pixmap, int x, int y);
void * SkPixmap_writable_addr(SkPixmap *pixmap);
void * SkPixmap_writable_addr_2(SkPixmap *pixmap, int x, int y);
uint8_t * SkPixmap_writable_addr8(SkPixmap *pixmap, int x, int y);
uint16_t * SkPixmap_writable_addr16(SkPixmap *pixmap, int x, int y);
uint32_t * SkPixmap_writable_addr32(SkPixmap *pixmap, int x, int y);
uint64_t * SkPixmap_writable_addr64(SkPixmap *pixmap, int x, int y);
uint16_t * SkPixmap_writable_addrF16(SkPixmap *pixmap, int x, int y);
bool SkPixmap_readPixels(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes);
bool SkPixmap_readPixels_2(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
bool SkPixmap_readPixels_3(SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY);
bool SkPixmap_readPixels_4(SkPixmap *pixmap, const SkPixmap *dst);
bool SkPixmap_scalePixels(SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options);
bool SkPixmap_erase(SkPixmap *pixmap, SkColor color, const SkIRect *subset);
bool SkPixmap_erase_2(SkPixmap *pixmap, SkColor color);
bool SkPixmap_erase_3(SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset);
}

#endif //RAIA_SKIA_SK_PIXMAP_H
