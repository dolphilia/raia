//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_H
#define RAIA_SKIA_SK_IMAGE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkImage_delete(void *image); // (SkImage *image)

// TODO
// const void *SkImage_imageInfo(void *image); // (SkImage *image) -> const SkImageInfo *
int SkImage_width(void *image); // (SkImage *image) -> int
int SkImage_height(void *image); // (SkImage *image) -> int
int SkImage_dimensions(void *image); // (SkImage *image) -> sk_i_size_t
int SkImage_bounds(void *image); // (SkImage *image) -> sk_i_rect_t
unsigned int SkImage_uniqueID(void *image); // (SkImage *image) -> uint32_t
int SkImage_alphaType(void *image); // (SkImage *image) -> SkAlphaType
int SkImage_colorType(void *image); // (SkImage *image) -> SkColorType
void *SkImage_colorSpace(void *image); // (SkImage *image) -> SkColorSpace *
int SkImage_refColorSpace(void *image); // (SkImage *image) -> sk_color_space_t
bool SkImage_isAlphaOnly(void *image); // (SkImage *image) -> bool
bool SkImage_isOpaque(void *image); // (SkImage *image) -> bool
int SkImage_makeShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t
int SkImage_makeShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkImage_makeShader_3(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkImage_makeShader_4(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkImage_makeRawShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t
int SkImage_makeRawShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkImage_makeRawShader_3(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
int SkImage_makeRawShader_4(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
bool SkImage_peekPixels(void *image, void *pixmap); // (SkImage *image, SkPixmap *pixmap) -> bool
bool SkImage_isTextureBacked(void *image); // (SkImage *image) -> bool
unsigned long SkImage_textureSize(void *image); // (SkImage *image) -> size_t
bool SkImage_isValid(void *image, void *context); // (SkImage *image, GrRecordingContext *context) -> bool
bool SkImage_readPixels(void *image, void *context, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY, int cachingHint); // (SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
bool SkImage_readPixels_2(void *image, void *context, const void *dst, int srcX, int srcY, int cachingHint); // (SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
bool SkImage_readPixels_3(void *image, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY, int cachingHint); // (SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
bool SkImage_readPixels_4(void *image, const void *dst, int srcX, int srcY, int cachingHint); // (SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool

// TODO
// void SkImage_asyncRescaleAndReadPixels(void *image, const void *info, const void *srcRect, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
// void SkImage_asyncRescaleAndReadPixelsYUV420(void *image, int yuvColorSpace, sk_color_space_t color_space, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
// void SkImage_asyncRescaleAndReadPixelsYUVA420(void *image, int yuvColorSpace, sk_color_space_t color_space, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
bool SkImage_scalePixels(void *image, const void *dst, const void *sampling, int cachingHint); // (SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint) -> bool
int SkImage_refEncodedData(void *image); // (SkImage *image) -> sk_data_t
int SkImage_makeSubset(void *image, void *direct, const void *subset); // (SkImage *image, GrDirectContext *direct, const SkIRect *subset) -> sk_image_t
int SkImage_makeSubset_2(void *image, void *recorder, const void *subset, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, sk_image_required_properties_t properties) -> sk_image_t
bool SkImage_hasMipmaps(void *image); // (SkImage *image) -> bool
bool SkImage_isProtected(void *image); // (SkImage *image) -> bool
int SkImage_withDefaultMipmaps(void *image); // (SkImage *image) -> sk_image_t
int SkImage_makeNonTextureImage(void *image, void *context); // (SkImage *image, GrDirectContext *context) -> sk_image_t
int SkImage_makeRasterImage(void *image, void *context, int cachingHint); // (SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) -> sk_image_t
int SkImage_makeRasterImage_2(void *image, int cachingHint); // (SkImage *image, SkImage::CachingHint cachingHint) -> sk_image_t
bool SkImage_asLegacyBitmap(void *image, void *bitmap, int legacyBitmapMode); // (SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) -> bool
bool SkImage_isLazyGenerated(void *image); // (SkImage *image) -> bool
int SkImage_makeColorSpace(void *image, void *direct, int color_space); // (SkImage *image, GrDirectContext *direct, sk_color_space_t color_space) -> sk_image_t
int SkImage_makeColorSpace_2(void *image, void *recorder, int color_space, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, sk_color_space_t color_space, sk_image_required_properties_t properties) -> sk_image_t
int SkImage_makeColorTypeAndColorSpace(void *image, void *direct, int targetColorType, int color_space); // (SkImage *image, GrDirectContext *direct, SkColorType targetColorType, sk_color_space_t color_space) -> sk_image_t
int SkImage_makeColorTypeAndColorSpace_2(void *image, void *recorder, int targetColorType, int color_space, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, sk_color_space_t color_space, sk_image_required_properties_t properties) -> sk_image_t
int SkImage_reinterpretColorSpace(void *image, int color_space); // (SkImage *image, sk_color_space_t color_space) -> sk_image_t
bool SkImage_unique(void *image); // (SkImage *image) -> bool
void SkImage_ref(void *image); // (SkImage *image)
void SkImage_unref(void *image); // (SkImage *image)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGE_H
