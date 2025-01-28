//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PIXMAP_H
#define RAIA_SKIA_SK_PIXMAP_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkPixmap_new(); // () -> SkPixmap *
void *SkPixmap_new_2(const void *info, const void *addr, unsigned long rowBytes); // (const SkImageInfo *info, const void *addr, size_t rowBytes) -> SkPixmap *
void SkPixmap_delete(void *pixmap); // (SkPixmap *pixmap)
void SkPixmap_reset(void *pixmap); // (SkPixmap *pixmap)
void SkPixmap_reset_2(void *pixmap, const void *info, const void *addr, unsigned long rowBytes); // (SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes)
bool SkPixmap_reset_3(void *pixmap, const void *mask); // (SkPixmap *pixmap, const SkMask *mask) -> bool
void SkPixmap_setColorSpace(void *pixmap, int color_space); // (SkPixmap *pixmap, sk_color_space_t color_space)
bool SkPixmap_extractSubset(void *pixmap, void *subset, const void *area); // (SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area) -> bool
const void *SkPixmap_info(void *pixmap); // (SkPixmap *pixmap) -> const SkImageInfo *
unsigned long SkPixmap_rowBytes(void *pixmap); // (SkPixmap *pixmap) -> size_t
const void *SkPixmap_addr(void *pixmap); // (SkPixmap *pixmap) -> const void *
int SkPixmap_width(void *pixmap); // (SkPixmap *pixmap) -> int
int SkPixmap_height(void *pixmap); // (SkPixmap *pixmap) -> int
int SkPixmap_dimensions(void *pixmap); // (SkPixmap *pixmap) -> sk_i_size_t
int SkPixmap_colorType(void *pixmap); // (SkPixmap *pixmap) -> SkColorType
int SkPixmap_alphaType(void *pixmap); // (SkPixmap *pixmap) -> SkAlphaType
void *SkPixmap_colorSpace(void *pixmap); // (SkPixmap *pixmap) -> SkColorSpace *
int SkPixmap_refColorSpace(void *pixmap); // (SkPixmap *pixmap) -> sk_color_space_t
bool SkPixmap_isOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
int SkPixmap_bounds(void *pixmap); // (SkPixmap *pixmap) -> sk_i_rect_t
int SkPixmap_rowBytesAsPixels(void *pixmap); // (SkPixmap *pixmap) -> int
int SkPixmap_shiftPerPixel(void *pixmap); // (SkPixmap *pixmap) -> int
unsigned long SkPixmap_computeByteSize(void *pixmap); // (SkPixmap *pixmap) -> size_t
bool SkPixmap_computeIsOpaque(void *pixmap); // (SkPixmap *pixmap) -> bool
unsigned int SkPixmap_getColor(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> SkColor
int SkPixmap_getColor4f(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> sk_color_4f_t
float SkPixmap_getAlphaf(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> float
const void *SkPixmap_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const void *
const void *SkPixmap_addr8(void *pixmap); // (SkPixmap *pixmap) -> const uint8_t *
const void *SkPixmap_addr16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
const void *SkPixmap_addr32(void *pixmap); // (SkPixmap *pixmap) -> const uint32_t *
const void *SkPixmap_addr64(void *pixmap); // (SkPixmap *pixmap) -> const uint64_t *
const void *SkPixmap_addrF16(void *pixmap); // (SkPixmap *pixmap) -> const uint16_t *
const void *SkPixmap_addr8_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint8_t *
const void *SkPixmap_addr16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
const void *SkPixmap_addr32_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint32_t *
const void *SkPixmap_addr64_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint64_t *
const void *SkPixmap_addrF16_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> const uint16_t *
void *SkPixmap_writable_addr(void *pixmap); // (SkPixmap *pixmap) -> void *
void *SkPixmap_writable_addr_2(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> void *
void *SkPixmap_writable_addr8(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint8_t *
void *SkPixmap_writable_addr16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
void *SkPixmap_writable_addr32(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint32_t *
void *SkPixmap_writable_addr64(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint64_t *
void *SkPixmap_writable_addrF16(void *pixmap, int x, int y); // (SkPixmap *pixmap, int x, int y) -> uint16_t *
bool SkPixmap_readPixels(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes) -> bool
bool SkPixmap_readPixels_2(void *pixmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
bool SkPixmap_readPixels_3(void *pixmap, const void *dst, int srcX, int srcY); // (SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY) -> bool
bool SkPixmap_readPixels_4(void *pixmap, const void *dst); // (SkPixmap *pixmap, const SkPixmap *dst) -> bool
bool SkPixmap_scalePixels(void *pixmap, const void *dst, const void *options); // (SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options) -> bool
bool SkPixmap_erase(void *pixmap, unsigned int color, const void *subset); // (SkPixmap *pixmap, SkColor color, const SkIRect *subset) -> bool
bool SkPixmap_erase_2(void *pixmap, unsigned int color); // (SkPixmap *pixmap, SkColor color) -> bool
bool SkPixmap_erase_3(void *pixmap, const void *color, const void *subset); // (SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PIXMAP_H
