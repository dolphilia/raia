//
// Created by dolphilia on 2024/01/08.
//

#include "sk_images.h"

extern "C" {

sk_image_t SkImages_RasterFromBitmap(const SkBitmap *bitmap) {
    return static_sk_image_make(SkImages::RasterFromBitmap(*bitmap));
}

sk_image_t SkImages_RasterFromCompressedTextureData(sk_data_t data, int width, int height, SkTextureCompressionType type) {
    return static_sk_image_make(SkImages::RasterFromCompressedTextureData(static_sk_data_move(data), width, height, type));
}

sk_image_t SkImages_DeferredFromEncodedData(sk_data_t data) {
    return static_sk_image_make(SkImages::DeferredFromEncodedData(static_sk_data_move(data)));
}

sk_image_t SkImages_DeferredFromGenerator(sk_image_generator_t image_generator) {
    return static_sk_image_make(SkImages::DeferredFromGenerator(static_sk_image_generator_move(image_generator)));
}

sk_image_t SkImages_DeferredFromPicture(sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space, sk_surface_props_t props) {
    return static_sk_image_make(SkImages::DeferredFromPicture(static_sk_picture_move(picture), *dimensions, matrix, paint, bitDepth, static_sk_color_space_move(color_space), static_sk_surface_props_get(props)));
}

sk_image_t SkImages_DeferredFromPicture_2(sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space) {
    return static_sk_image_make(SkImages::DeferredFromPicture(static_sk_picture_move(picture), *dimensions, matrix, paint, bitDepth, static_sk_color_space_move(color_space)));
}

sk_image_t SkImages_RasterFromPixmapCopy(const SkPixmap *pixmap) {
    return static_sk_image_make(SkImages::RasterFromPixmapCopy(*pixmap));
}

sk_image_t SkImages_RasterFromPixmap(const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext) {
    return static_sk_image_make(SkImages::RasterFromPixmap(*pixmap, rasterReleaseProc, releaseContext));
}

sk_image_t SkImages_RasterFromData(const SkImageInfo *info, sk_data_t data, size_t rowBytes) {
    return static_sk_image_make(SkImages::RasterFromData(*info, static_sk_data_move(data), rowBytes));
}

sk_image_t SkImages_MakeWithFilter(sk_image_t image, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset) {
    return static_sk_image_make(SkImages::MakeWithFilter(static_sk_image_move(image), filter, *subset, *clipBounds, outSubset, offset));
}

}