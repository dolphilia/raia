//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image.h"

extern "C" {

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

void SkImage_bounds(int sk_i_rect_key_out, SkImage *image) {
    static_sk_i_rect_set(sk_i_rect_key_out, image->bounds());
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

void SkImage_refColorSpace(int sk_color_space_key_out, SkImage *image) {
    static_sk_color_space_set(sk_color_space_key_out, image->refColorSpace());
}

bool SkImage_isAlphaOnly(SkImage *image) {
    return image->isAlphaOnly();
}

bool SkImage_isOpaque(SkImage *image) {
    return image->isOpaque();
}

void SkImage_makeShader(int sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, image->makeShader(tmx, tmy, *sampling, localMatrix));
}

void SkImage_makeShader_2(int sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeShader(tmx, tmy, *sampling, *lm));
}

void SkImage_makeShader_3(int sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeShader(*sampling, *lm));
}

void SkImage_makeShader_4(int sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeShader(*sampling, lm));
}

void SkImage_makeRawShader(int sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, image->makeRawShader(tmx, tmy, *sampling, localMatrix));
}

void SkImage_makeRawShader_2(int sk_shader_key_out, SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeRawShader(tmx, tmy, *sampling, *lm));
}

void SkImage_makeRawShader_3(int sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeRawShader(*sampling, *lm));
}

void SkImage_makeRawShader_4(int sk_shader_key_out, SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) {
    static_sk_shader_set(sk_shader_key_out, image->makeRawShader(*sampling, lm));
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

void SkImage_refEncodedData(int sk_data_key_out, SkImage *image) {
    static_sk_data_set(sk_data_key_out, image->refEncodedData());
}

void SkImage_makeSubset(int sk_image_key_out, SkImage *image, GrDirectContext *direct, const SkIRect *subset) {
    static_sk_image_set(sk_image_key_out, image->makeSubset(direct, *subset));
}

void SkImage_makeSubset_2(int sk_image_key_out, SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, SkImage::RequiredProperties properties) {
    static_sk_image_set(sk_image_key_out, image->makeSubset(recorder, *subset, properties));
}

bool SkImage_hasMipmaps(SkImage *image) {
    return image->hasMipmaps();
}

bool SkImage_isProtected(SkImage *image) {
    return image->isProtected();
}

void SkImage_withDefaultMipmaps(int sk_image_key_out, SkImage *image) {
    static_sk_image_set(sk_image_key_out, image->withDefaultMipmaps());
}

void SkImage_makeNonTextureImage(int sk_image_key_out, SkImage *image, GrDirectContext *context) {
    static_sk_image_set(sk_image_key_out, image->makeNonTextureImage(context));
}

void SkImage_makeRasterImage(int sk_image_key_out, SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) {
    static_sk_image_set(sk_image_key_out, image->makeRasterImage(context, cachingHint));
}

void SkImage_makeRasterImage_2(int sk_image_key_out, SkImage *image, SkImage::CachingHint cachingHint) {
    static_sk_image_set(sk_image_key_out, image->makeRasterImage(cachingHint));
}

bool SkImage_asLegacyBitmap(SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) {
    return image->asLegacyBitmap(bitmap, legacyBitmapMode);
}

bool SkImage_isLazyGenerated(SkImage *image) {
    return image->isLazyGenerated();
}

void SkImage_makeColorSpace(int sk_image_key_out, int sk_color_space_key_in, SkImage *image, GrDirectContext *direct) {
    static_sk_image_set(sk_image_key_out, image->makeColorSpace(direct, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImage_makeColorSpace_2(int sk_image_key_out, int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkImage::RequiredProperties properties) {
    static_sk_image_set(sk_image_key_out, image->makeColorSpace(recorder, static_sk_color_space_move(sk_color_space_key_in), properties));
}

void SkImage_makeColorTypeAndColorSpace(int sk_image_key_out, int sk_color_space_key_in, SkImage *image, GrDirectContext *direct, SkColorType targetColorType) {
    static_sk_image_set(sk_image_key_out, image->makeColorTypeAndColorSpace(direct, targetColorType, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImage_makeColorTypeAndColorSpace_2(int sk_image_key_out, int sk_color_space_key_in, SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, SkImage::RequiredProperties properties) {
    static_sk_image_set(sk_image_key_out, image->makeColorTypeAndColorSpace(recorder, targetColorType, static_sk_color_space_move(sk_color_space_key_in), properties));
}

void SkImage_reinterpretColorSpace(int sk_image_key_out, int sk_color_space_key_in, SkImage *image) {
    static_sk_image_set(sk_image_key_out, image->reinterpretColorSpace(static_sk_color_space_move(sk_color_space_key_in)));
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