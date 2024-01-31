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

SkISize SkImage_dimensions(SkImage *image) {
    return image->dimensions();
}

int SkImage_bounds(SkImage *image) {
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

SkColorSpace * cSkImage_olorSpace(SkImage *image) {
    return image->colorSpace();
}

int SkImage_refColorSpace(SkImage *image) {
    return static_sk_color_space_make(image->refColorSpace());
}

bool SkImage_isAlphaOnly(SkImage *image) {
    return image->isAlphaOnly();
}

bool SkImage_isOpaque(SkImage *image) {
    return image->isOpaque();
}

int SkImage_makeShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    return static_sk_shader_make(image->makeShader(tmx, tmy, *sampling, localMatrix));
}

int SkImage_makeShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(tmx, tmy, *sampling, *lm));
}

int SkImage_makeShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(*sampling, *lm));
}

int SkImage_makeShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeShader(*sampling, lm));
}

int SkImage_makeRawShader(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    return static_sk_shader_make(image->makeRawShader(tmx, tmy, *sampling, localMatrix));
}

int SkImage_makeRawShader_2(SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeRawShader(tmx, tmy, *sampling, *lm));
}

int SkImage_makeRawShader_3(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    return static_sk_shader_make(image->makeRawShader(*sampling, *lm));
}

int SkImage_makeRawShader_4(SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
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

void SkImage_asyncRescaleAndReadPixelsYUV420(int sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUV420(yuvColorSpace, static_sk_color_space_move(sk_color_space_key_in), *srcRect,
                                           *dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkImage_asyncRescaleAndReadPixelsYUVA420(int sk_color_space_key_in, SkImage *image, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context) {
    image->asyncRescaleAndReadPixelsYUVA420(yuvColorSpace, static_sk_color_space_move(sk_color_space_key_in), *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

bool SkImage_scalePixels(SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint) {
    return image->scalePixels(*dst, *sampling, cachingHint);
}

int SkImage_refEncodedData(SkImage *image) {
    return static_sk_data_make(image->refEncodedData());
}

int SkImage_makeSubset(SkImage *image, GrDirectContext *direct, const SkIRect *subset) {
    return static_sk_image_make(image->makeSubset(direct, *subset));
}

int SkImage_makeSubset_2(SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, SkImage::RequiredProperties properties) {
    return static_sk_image_make(image->makeSubset(recorder, *subset, properties));
}

bool SkImage_hasMipmaps(SkImage *image) {
    return image->hasMipmaps();
}

bool SkImage_isProtected(SkImage *image) {
    return image->isProtected();
}

int SkImage_withDefaultMipmaps(SkImage *image) {
    return static_sk_image_make(image->withDefaultMipmaps());
}

int SkImage_makeNonTextureImage(SkImage *image, GrDirectContext *context) {
    return static_sk_image_make(image->makeNonTextureImage(context));
}

int SkImage_makeRasterImage(SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) {
    return static_sk_image_make(image->makeRasterImage(context, cachingHint));
}

int SkImage_makeRasterImage_2(SkImage *image, SkImage::CachingHint cachingHint) {
    return static_sk_image_make(image->makeRasterImage(cachingHint));
}

bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) {
    return image->asLegacyBitmap(bitmap, legacyBitmapMode);
}

bool SkImage_isLazyGenerated(SkImage *image) {
    return image->isLazyGenerated();
}

int SkImage_makeColorSpace(int sk_color_space_key_in, SkImage *image, GrDirectContext *direct) {
    return static_sk_image_make(image->makeColorSpace(direct, static_sk_color_space_move(sk_color_space_key_in)));
}

int SkImage_makeColorSpace_2(int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkImage::RequiredProperties properties) {
    return static_sk_image_make(image->makeColorSpace(recorder, static_sk_color_space_move(sk_color_space_key_in), properties));
}

int SkImage_makeColorTypeAndColorSpace(int sk_color_space_key_in, SkImage *image, GrDirectContext *direct, SkColorType targetColorType) {
    return static_sk_image_make(image->makeColorTypeAndColorSpace(direct, targetColorType, static_sk_color_space_move(sk_color_space_key_in)));
}

int SkImage_makeColorTypeAndColorSpace_2(int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, SkImage::RequiredProperties properties) {
    return static_sk_image_make(image->makeColorTypeAndColorSpace(recorder, targetColorType, static_sk_color_space_move(sk_color_space_key_in), properties));
}

int SkImage_reinterpretColorSpace(int sk_color_space_key_in, SkImage *image) {
    return static_sk_image_make(image->reinterpretColorSpace(static_sk_color_space_move(sk_color_space_key_in)));
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