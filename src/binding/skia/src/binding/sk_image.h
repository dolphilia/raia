//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_H
#define RAIA_SKIA_SK_IMAGE_H

#include "include/core/SkImage.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_i_rect.h"

extern "C" {
void SkImage_delete(SkImage *image);
const SkImageInfo * SkImage_imageInfo(SkImage *image);
int SkImage_width(SkImage *image);
int SkImage_height(SkImage *image);
SkISize SkImage_dimensions(SkImage *image);
int SkImage_bounds(SkImage *image);
uint32_t SkImage_uniqueID(SkImage *image);
SkAlphaType SkImage_alphaType(SkImage *image);
SkColorType SkImage_colorType(SkImage *image);
SkColorSpace * cSkImage_olorSpace(SkImage *image);
int SkImage_refColorSpace(SkImage *image);
bool SkImage_isAlphaOnly(SkImage *image);
bool SkImage_isOpaque(SkImage *image);
int SkImage_makeShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
int SkImage_makeShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
int SkImage_makeShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
int SkImage_makeShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
int SkImage_makeRawShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
int SkImage_makeRawShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
int SkImage_makeRawShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
int SkImage_makeRawShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
bool SkImage_peekPixels(SkImage *image, SkPixmap *pixmap);
bool SkImage_isTextureBacked(SkImage *image);
size_t SkImage_textureSize(SkImage *image);
bool SkImage_isValid(SkImage *image, GrRecordingContext *context);
bool SkImage_readPixels(SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_2(SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_3(SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_4(SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
void SkImage_asyncRescaleAndReadPixels(SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
void SkImage_asyncRescaleAndReadPixelsYUV420(int sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
void SkImage_asyncRescaleAndReadPixelsYUVA420(int sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint);
int SkImage_refEncodedData(SkImage *image);
int SkImage_makeSubset(SkImage *image, GrDirectContext *direct, const SkIRect *subset);
int SkImage_makeSubset_2(SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, SkImage::RequiredProperties properties);
bool SkImage_hasMipmaps(SkImage *image);
bool SkImage_isProtected(SkImage *image);
int SkImage_withDefaultMipmaps(SkImage *image);
int SkImage_makeNonTextureImage(SkImage *image, GrDirectContext *context);
int SkImage_makeRasterImage(SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint);
int SkImage_makeRasterImage_2(SkImage *image, SkImage::CachingHint cachingHint);
bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode);
bool SkImage_isLazyGenerated(SkImage *image);
int SkImage_makeColorSpace(int sk_color_space_key_in, SkImage *image, GrDirectContext *direct);
int SkImage_makeColorSpace_2(int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkImage::RequiredProperties properties);
int SkImage_makeColorTypeAndColorSpace(int sk_color_space_key_in, SkImage *image, GrDirectContext *direct, SkColorType targetColorType);
int SkImage_makeColorTypeAndColorSpace_2(int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, SkImage::RequiredProperties properties);
int SkImage_reinterpretColorSpace(int sk_color_space_key_in, SkImage *image);
bool SkImage_unique(SkImage *image);
void SkImage_ref(SkImage *image);
void SkImage_unref(SkImage *image);
}

#endif //RAIA_SKIA_SK_IMAGE_H
