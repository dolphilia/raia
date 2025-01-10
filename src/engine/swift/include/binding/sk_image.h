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
#include "../static/static_sk_image_required_properties.h"
#include "../static/static_sk_i_size.h"

extern "C" {
void SkImage_delete(SkImage *image);
const SkImageInfo * SkImage_imageInfo(SkImage *image);
int SkImage_width(SkImage *image);
int SkImage_height(SkImage *image);
sk_i_size_t SkImage_dimensions(SkImage *image);
sk_i_rect_t SkImage_bounds(SkImage *image);
uint32_t SkImage_uniqueID(SkImage *image);
SkAlphaType SkImage_alphaType(SkImage *image);
SkColorType SkImage_colorType(SkImage *image);
SkColorSpace * SkImage_colorSpace(SkImage *image);
sk_color_space_t SkImage_refColorSpace(SkImage *image);
bool SkImage_isAlphaOnly(SkImage *image);
bool SkImage_isOpaque(SkImage *image);
sk_shader_t SkImage_makeShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
sk_shader_t SkImage_makeShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkImage_makeShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkImage_makeShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkImage_makeRawShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
sk_shader_t SkImage_makeRawShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkImage_makeRawShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
sk_shader_t SkImage_makeRawShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
bool SkImage_peekPixels(SkImage *image, SkPixmap *pixmap);
bool SkImage_isTextureBacked(SkImage *image);
size_t SkImage_textureSize(SkImage *image);
bool SkImage_isValid(SkImage *image, GrRecordingContext *context);
bool SkImage_readPixels(SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_2(SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_3(SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
bool SkImage_readPixels_4(SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
void SkImage_asyncRescaleAndReadPixels(SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
void SkImage_asyncRescaleAndReadPixelsYUV420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
void SkImage_asyncRescaleAndReadPixelsYUVA420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint);
sk_data_t SkImage_refEncodedData(SkImage *image);
sk_image_t SkImage_makeSubset(SkImage *image, GrDirectContext *direct, const SkIRect *subset);
sk_image_t SkImage_makeSubset_2(SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, sk_image_required_properties_t properties);
bool SkImage_hasMipmaps(SkImage *image);
bool SkImage_isProtected(SkImage *image);
sk_image_t SkImage_withDefaultMipmaps(SkImage *image);
sk_image_t SkImage_makeNonTextureImage(SkImage *image, GrDirectContext *context);
sk_image_t SkImage_makeRasterImage(SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint);
sk_image_t SkImage_makeRasterImage_2(SkImage *image, SkImage::CachingHint cachingHint);
bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode);
bool SkImage_isLazyGenerated(SkImage *image);
sk_image_t SkImage_makeColorSpace(SkImage *image, GrDirectContext *direct, sk_color_space_t color_space);
sk_image_t SkImage_makeColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, sk_color_space_t color_space, sk_image_required_properties_t properties);
sk_image_t SkImage_makeColorTypeAndColorSpace(SkImage *image, GrDirectContext *direct, SkColorType targetColorType, sk_color_space_t color_space);
sk_image_t SkImage_makeColorTypeAndColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, sk_color_space_t color_space, sk_image_required_properties_t properties);
sk_image_t SkImage_reinterpretColorSpace(SkImage *image, sk_color_space_t color_space);
bool SkImage_unique(SkImage *image);
void SkImage_ref(SkImage *image);
void SkImage_unref(SkImage *image);
}

#endif //RAIA_SKIA_SK_IMAGE_H
