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
#include "export_api.h"

extern "C" {
RAIA_API void SkImage_delete(SkImage *image);
RAIA_API const SkImageInfo * SkImage_imageInfo(SkImage *image);
RAIA_API int SkImage_width(SkImage *image);
RAIA_API int SkImage_height(SkImage *image);
RAIA_API sk_i_size_t SkImage_dimensions(SkImage *image);
RAIA_API sk_i_rect_t SkImage_bounds(SkImage *image);
RAIA_API uint32_t SkImage_uniqueID(SkImage *image);
RAIA_API SkAlphaType SkImage_alphaType(SkImage *image);
RAIA_API SkColorType SkImage_colorType(SkImage *image);
RAIA_API SkColorSpace * SkImage_colorSpace(SkImage *image);
RAIA_API sk_color_space_t SkImage_refColorSpace(SkImage *image);
RAIA_API bool SkImage_isAlphaOnly(SkImage *image);
RAIA_API bool SkImage_isOpaque(SkImage *image);
RAIA_API sk_shader_t SkImage_makeShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
RAIA_API sk_shader_t SkImage_makeShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkImage_makeShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkImage_makeShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkImage_makeRawShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix);
RAIA_API sk_shader_t SkImage_makeRawShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkImage_makeRawShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API sk_shader_t SkImage_makeRawShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm);
RAIA_API bool SkImage_peekPixels(SkImage *image, SkPixmap *pixmap);
RAIA_API bool SkImage_isTextureBacked(SkImage *image);
RAIA_API size_t SkImage_textureSize(SkImage *image);
RAIA_API bool SkImage_isValid(SkImage *image, GrRecordingContext *context);
RAIA_API bool SkImage_readPixels(SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
RAIA_API bool SkImage_readPixels_2(SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
RAIA_API bool SkImage_readPixels_3(SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint);
RAIA_API bool SkImage_readPixels_4(SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint);
RAIA_API void SkImage_asyncRescaleAndReadPixels(SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
RAIA_API void SkImage_asyncRescaleAndReadPixelsYUV420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
RAIA_API void SkImage_asyncRescaleAndReadPixelsYUVA420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context);
RAIA_API bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint);
RAIA_API sk_data_t SkImage_refEncodedData(SkImage *image);
RAIA_API sk_image_t SkImage_makeSubset(SkImage *image, GrDirectContext *direct, const SkIRect *subset);
RAIA_API sk_image_t SkImage_makeSubset_2(SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, sk_image_required_properties_t properties);
RAIA_API bool SkImage_hasMipmaps(SkImage *image);
RAIA_API bool SkImage_isProtected(SkImage *image);
RAIA_API sk_image_t SkImage_withDefaultMipmaps(SkImage *image);
RAIA_API sk_image_t SkImage_makeNonTextureImage(SkImage *image, GrDirectContext *context);
RAIA_API sk_image_t SkImage_makeRasterImage(SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint);
RAIA_API sk_image_t SkImage_makeRasterImage_2(SkImage *image, SkImage::CachingHint cachingHint);
RAIA_API bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode);
RAIA_API bool SkImage_isLazyGenerated(SkImage *image);
RAIA_API sk_image_t SkImage_makeColorSpace(SkImage *image, GrDirectContext *direct, sk_color_space_t color_space);
RAIA_API sk_image_t SkImage_makeColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, sk_color_space_t color_space, sk_image_required_properties_t properties);
RAIA_API sk_image_t SkImage_makeColorTypeAndColorSpace(SkImage *image, GrDirectContext *direct, SkColorType targetColorType, sk_color_space_t color_space);
RAIA_API sk_image_t SkImage_makeColorTypeAndColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, sk_color_space_t color_space, sk_image_required_properties_t properties);
RAIA_API sk_image_t SkImage_reinterpretColorSpace(SkImage *image, sk_color_space_t color_space);
RAIA_API bool SkImage_unique(SkImage *image);
RAIA_API void SkImage_ref(SkImage *image);
RAIA_API void SkImage_unref(SkImage *image);
}

#endif //RAIA_SKIA_SK_IMAGE_H
