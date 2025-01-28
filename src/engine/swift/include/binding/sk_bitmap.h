//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_BITMAP_H
#define RAIA_SKIA_SK_BITMAP_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkBitmap_new(void); // () -> SkBitmap *
void * SkBitmap_new_2(const void *src); // (const SkBitmap *src) -> SkBitmap *
void SkBitmap_delete(void *bitmap); // (SkBitmap *bitmap)
void SkBitmap_allocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque)
void SkBitmap_allocPixels(void *bitmap); // (SkBitmap *bitmap)
void SkBitmap_allocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator)
void SkBitmap_allocPixels_3(void *bitmap, const void *info); // (SkBitmap *bitmap, const SkImageInfo *info)
void SkBitmap_allocPixels_4(void *bitmap, const void *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes)
void SkBitmap_allocPixelsFlags(void *bitmap, const void *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags)
int SkBitmap_alphaType(void *bitmap); // (SkBitmap *bitmap) -> SkAlphaType
int SkBitmap_asImage(void *bitmap); // (SkBitmap *bitmap) -> sk_image_t
int SkBitmap_bounds(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
int SkBitmap_bytesPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
void * SkBitmap_colorSpace(void *bitmap); // (SkBitmap *bitmap) -> SkColorSpace *
int SkBitmap_colorType(void *bitmap); // (SkBitmap *bitmap) -> SkColorType
unsigned long SkBitmap_computeByteSize(void *bitmap); // (SkBitmap *bitmap) -> size_t
int SkBitmap_dimensions(void *bitmap); // (SkBitmap *bitmap) -> sk_i_size_t
bool SkBitmap_drawsNothing(void *bitmap); // (SkBitmap *bitmap) -> bool
bool SkBitmap_empty(void *bitmap); // (SkBitmap *bitmap) -> bool
void SkBitmap_erase(void *bitmap, unsigned int c, const void *area); // (SkBitmap *bitmap, SkColor c, const SkIRect *area)
void SkBitmap_erase_2(void *bitmap, int c, const void *area); // (SkBitmap *bitmap, sk_color_4f_t c, const SkIRect *area)
void SkBitmap_eraseArea(void *bitmap, const void *area, unsigned int c); // (SkBitmap *bitmap, const SkIRect *area, SkColor c)
void SkBitmap_eraseARGB(void *bitmap, unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (SkBitmap *bitmap, U8CPU a, U8CPU r, U8CPU g, U8CPU b)
void SkBitmap_eraseColor(void *bitmap, unsigned int c); // (SkBitmap *bitmap, SkColor c)
void SkBitmap_eraseColor_2(void *bitmap, int c); // (SkBitmap *bitmap, sk_color_4f_t c)
bool SkBitmap_extractAlpha(void *bitmap, void *dst); // (SkBitmap *bitmap, SkBitmap *dst) -> bool
bool SkBitmap_extractAlpha_2(void *bitmap, void *dst, const void *paint, void *allocator, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkBitmap::Allocator *allocator, SkIPoint *offset) -> bool
bool SkBitmap_extractAlpha_3(void *bitmap, void *dst, const void *paint, void *offset); // (SkBitmap *bitmap, SkBitmap *dst, const SkPaint *paint, SkIPoint *offset) -> bool
bool SkBitmap_extractSubset(void *bitmap, void *dst, const void *subset); // (SkBitmap *bitmap, SkBitmap *dst, const SkIRect *subset) -> bool
void * SkBitmap_getAddr(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> void *
void * SkBitmap_getAddr16(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint16_t *
void * SkBitmap_getAddr32(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint32_t *
void * SkBitmap_getAddr8(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> uint8_t *
float SkBitmap_getAlphaf(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> float
void SkBitmap_getBounds(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkIRect *bounds)
void SkBitmap_getBounds2(void *bitmap, void *bounds); // (SkBitmap *bitmap, SkRect *bounds)
unsigned int SkBitmap_getColor(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> SkColor
int SkBitmap_getColor4f(void *bitmap, int x, int y); // (SkBitmap *bitmap, int x, int y) -> sk_color_4f_t
unsigned int SkBitmap_getGenerationID(void *bitmap); // (SkBitmap *bitmap) -> uint32_t
void * SkBitmap_getPixels(void *bitmap); // (SkBitmap *bitmap) -> void *
int SkBitmap_getSubset(void *bitmap); // (SkBitmap *bitmap) -> sk_i_rect_t
int SkBitmap_height(void *bitmap); // (SkBitmap *bitmap) -> int
int SkBitmap_info(void *bitmap); // (SkBitmap *bitmap) -> int
bool SkBitmap_installMaskPixels(void *bitmap, void *mask); // (SkBitmap *bitmap, SkMaskBuilder *mask) -> bool
bool SkBitmap_installPixels(void *bitmap, const void *info, void *pixels, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes) -> bool
bool SkBitmap_installPixels_2(void *bitmap, const void *info, void *pixels, unsigned long rowBytes, void(*releaseProc)(void *addr, void *context), void *context); // (SkBitmap *bitmap, const SkImageInfo *info, void *pixels, size_t rowBytes, void(*releaseProc)(void *addr, void *context), void *context) -> bool
bool SkBitmap_installPixels_3(void *bitmap, const void *pixmap); // (SkBitmap *bitmap, const SkPixmap *pixmap) -> bool
bool SkBitmap_isImmutable(void *bitmap); // (SkBitmap *bitmap) -> bool
bool SkBitmap_isNull(void *bitmap); // (SkBitmap *bitmap) -> bool
bool SkBitmap_isOpaque(void *bitmap); // (SkBitmap *bitmap) -> bool
int SkBitmap_makeShader(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkBitmap_makeShader_2(void *bitmap, const void *sampling, const void *lm); // (SkBitmap *bitmap, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkBitmap_makeShader_3(void *bitmap, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t
int SkBitmap_makeShader_4(void *bitmap, int tmx, int tmy, const void *sampling, const void *lm); // (SkBitmap *bitmap, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
void SkBitmap_notifyPixelsChanged(void *bitmap); // (SkBitmap *bitmap)
bool SkBitmap_peekPixels(void *bitmap, void *pixmap); // (SkBitmap *bitmap, SkPixmap *pixmap) -> bool
void * SkBitmap_pixelRef(void *bitmap); // (SkBitmap *bitmap) -> SkPixelRef *
int SkBitmap_pixelRefOrigin(void *bitmap); // (SkBitmap *bitmap) -> sk_i_point_t
int SkBitmap_pixmap(void *bitmap); // (SkBitmap *bitmap) -> int
bool SkBitmap_readPixels(void *bitmap, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkBitmap *bitmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
bool SkBitmap_readPixels_2(void *bitmap, const void *dst); // (SkBitmap *bitmap, const SkPixmap *dst) -> bool
bool SkBitmap_readPixels_3(void *bitmap, const void *dst, int srcX, int srcY); // (SkBitmap *bitmap, const SkPixmap *dst, int srcX, int srcY) -> bool
bool SkBitmap_readyToDraw(void *bitmap); // (SkBitmap *bitmap) -> bool
int SkBitmap_refColorSpace(void *bitmap); // (SkBitmap *bitmap) -> sk_color_space_t
void SkBitmap_reset(void *bitmap); // (SkBitmap *bitmap)
unsigned long SkBitmap_rowBytes(void *bitmap); // (SkBitmap *bitmap) -> size_t
int SkBitmap_rowBytesAsPixels(void *bitmap); // (SkBitmap *bitmap) -> int
bool SkBitmap_setAlphaType(void *bitmap, int alphaType); // (SkBitmap *bitmap, SkAlphaType alphaType) -> bool
void SkBitmap_setImmutable(void *bitmap); // (SkBitmap *bitmap)
bool SkBitmap_setInfo(void *bitmap, const void *imageInfo, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *imageInfo, size_t rowBytes) -> bool
void SkBitmap_setPixelRef(void *bitmap, int pixelRef, int dx, int dy); // (SkBitmap *bitmap, sk_pixel_ref_t pixelRef, int dx, int dy)
void SkBitmap_setPixels(void *bitmap, void *pixels); // (SkBitmap *bitmap, void *pixels)
int SkBitmap_shiftPerPixel(void *bitmap); // (SkBitmap *bitmap) -> int
void SkBitmap_swap(void *bitmap, void *other); // (SkBitmap *bitmap, SkBitmap *other)
bool SkBitmap_tryAllocN32Pixels(void *bitmap, int width, int height, bool isOpaque); // (SkBitmap *bitmap, int width, int height, bool isOpaque) -> bool
bool SkBitmap_tryAllocPixels(void *bitmap); // (SkBitmap *bitmap) -> bool
bool SkBitmap_tryAllocPixels_2(void *bitmap, void *allocator); // (SkBitmap *bitmap, SkBitmap::Allocator *allocator) -> bool
bool SkBitmap_tryAllocPixels_3(void *bitmap, const void *info); // (SkBitmap *bitmap, const SkImageInfo *info) -> bool
bool SkBitmap_tryAllocPixels_4(void *bitmap, const void *info, unsigned long rowBytes); // (SkBitmap *bitmap, const SkImageInfo *info, size_t rowBytes) -> bool
bool SkBitmap_tryAllocPixelsFlags(void *bitmap, const void *info, unsigned int flags); // (SkBitmap *bitmap, const SkImageInfo *info, uint32_t flags) -> bool
int SkBitmap_width(void *bitmap); // (SkBitmap *bitmap) -> int
bool SkBitmap_writePixels(void *bitmap, const void *src); // (SkBitmap *bitmap, const SkPixmap *src) -> bool
bool SkBitmap_writePixels_2(void *bitmap, const void *src, int dstX, int dstY); // (SkBitmap *bitmap, const SkPixmap *src, int dstX, int dstY) -> bool
// static
bool SkBitmap_ComputeIsOpaque(const void *bm); // (const SkBitmap *bm) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_BITMAP_H
