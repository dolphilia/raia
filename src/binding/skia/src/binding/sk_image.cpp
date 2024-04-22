//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image.h"

extern "C" {

void SkImage_delete(SkImage *image) {
    delete image;
}

const SkImageInfo * SkImage_imageInfo(SkImage *image) {
    return &image->imageInfo();
}

int SkImage_width(SkImage *image) {
    return image->width();
}

int SkImage_height(SkImage *image) {
    return image->height();
}

sk_i_size_t SkImage_dimensions(SkImage *image) {
    return static_sk_i_size_make(image->dimensions());
}

sk_i_rect_t SkImage_bounds(SkImage *image) {
    return static_sk_i_rect_make(image->bounds());
}

uint32_t SkImage_uniqueID(SkImage *image) {
    return image->uniqueID();
}

SkAlphaType SkImage_alphaType(SkImage *image) {
    return image->alphaType();
}

SkColorType SkImage_colorType(SkImage *image) {
    return image->colorType();
}

SkColorSpace * SkImage_colorSpace(SkImage *image) {
    return image->colorSpace();
}

sk_color_space_t SkImage_refColorSpace(SkImage *image) {
    return static_sk_color_space_make(image->refColorSpace());
}

bool SkImage_isAlphaOnly(SkImage *image) {
    return image->isAlphaOnly();
}

bool SkImage_isOpaque(SkImage *image) {
    return image->isOpaque();
}

sk_shader_t SkImage_makeShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    return static_sk_shader_make(image->makeShader(tmx, tmy, *sampling, localMatrix));
}

sk_shader_t SkImage_makeShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(tmx, tmy, *sampling, *lm));
}

sk_shader_t SkImage_makeShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(*sampling, *lm));
}

sk_shader_t SkImage_makeShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(*sampling, lm));
}

sk_shader_t SkImage_makeRawShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    return static_sk_shader_make(image->makeRawShader(tmx, tmy, *sampling, localMatrix));
}

sk_shader_t SkImage_makeRawShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeRawShader(tmx, tmy, *sampling, *lm));
}

sk_shader_t SkImage_makeRawShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeRawShader(*sampling, *lm));
}

sk_shader_t SkImage_makeRawShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeRawShader(*sampling, lm));
}

bool SkImage_peekPixels(SkImage *image, SkPixmap *pixmap) {
    return image->peekPixels(pixmap);
}

bool SkImage_isTextureBacked(SkImage *image) {
    return image->isTextureBacked();
}

size_t SkImage_textureSize(SkImage *image) {
    return image->textureSize();
}

bool SkImage_isValid(SkImage *image, GrRecordingContext *context) {
    return image->isValid(context);
}

bool SkImage_readPixels(SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(context, *dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_2(SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(context, *dst, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_3(SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY, cachingHint);
}

bool SkImage_readPixels_4(SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) {
    return image->readPixels(*dst, srcX, srcY, cachingHint);
}

void SkImage_asyncRescaleAndReadPixels(SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixels(*info, *srcRect, rescaleGamma, rescaleMode, callback, context);
}

void SkImage_asyncRescaleAndReadPixelsYUV420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUV420(yuvColorSpace, static_sk_color_space_move(color_space), *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkImage_asyncRescaleAndReadPixelsYUVA420(SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUVA420(yuvColorSpace, static_sk_color_space_move(color_space), *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint) {
    return image->scalePixels(*dst, *sampling, cachingHint);
}

sk_data_t SkImage_refEncodedData(SkImage *image) {
    return static_sk_data_make(image->refEncodedData());
}

sk_image_t SkImage_makeSubset(SkImage *image, GrDirectContext *direct, const SkIRect *subset) {
    return static_sk_image_make(image->makeSubset(direct, *subset));
}

sk_image_t SkImage_makeSubset_2(SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, sk_image_required_properties_t properties) {
    return static_sk_image_make(image->makeSubset(recorder, *subset, static_sk_image_required_properties_get(properties)));
}

bool SkImage_hasMipmaps(SkImage *image) {
    return image->hasMipmaps();
}

bool SkImage_isProtected(SkImage *image) {
    return image->isProtected();
}

sk_image_t SkImage_withDefaultMipmaps(SkImage *image) {
    return static_sk_image_make(image->withDefaultMipmaps());
}

sk_image_t SkImage_makeNonTextureImage(SkImage *image, GrDirectContext *context) {
    return static_sk_image_make(image->makeNonTextureImage(context));
}

sk_image_t SkImage_makeRasterImage(SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) {
    return static_sk_image_make(image->makeRasterImage(context, cachingHint));
}

sk_image_t SkImage_makeRasterImage_2(SkImage *image, SkImage::CachingHint cachingHint) {
    return static_sk_image_make(image->makeRasterImage(cachingHint));
}

bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) {
    return image->asLegacyBitmap(bitmap, legacyBitmapMode);
}

bool SkImage_isLazyGenerated(SkImage *image) {
    return image->isLazyGenerated();
}

sk_image_t SkImage_makeColorSpace(SkImage *image, GrDirectContext *direct, sk_color_space_t color_space) {
    return static_sk_image_make(image->makeColorSpace(direct, static_sk_color_space_move(color_space)));
}

sk_image_t SkImage_makeColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, sk_color_space_t color_space, sk_image_required_properties_t properties) {
    return static_sk_image_make(image->makeColorSpace(recorder, static_sk_color_space_move(color_space), static_sk_image_required_properties_get(properties)));
}

sk_image_t SkImage_makeColorTypeAndColorSpace(SkImage *image, GrDirectContext *direct, SkColorType targetColorType, sk_color_space_t color_space) {
    return static_sk_image_make(image->makeColorTypeAndColorSpace(direct, targetColorType, static_sk_color_space_move(color_space)));
}

sk_image_t SkImage_makeColorTypeAndColorSpace_2(SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, sk_color_space_t color_space, sk_image_required_properties_t properties) {
    return static_sk_image_make(image->makeColorTypeAndColorSpace(recorder, targetColorType, static_sk_color_space_move(color_space), static_sk_image_required_properties_get(properties)));
}

sk_image_t SkImage_reinterpretColorSpace(SkImage *image, sk_color_space_t color_space) {
    return static_sk_image_make(image->reinterpretColorSpace(static_sk_color_space_move(color_space)));
}

bool SkImage_unique(SkImage *image) {
    return image->unique();
}

void SkImage_ref(SkImage *image) {
    return image->ref();
}

void SkImage_unref(SkImage *image) {
    return image->unref();
}

}