//
// Created by dolphilia on 2024/01/08.
//

#include "sk_images.h"

extern "C" {

int SkImages_RasterFromBitmap(const SkBitmap *bitmap) {
    return static_sk_image_make(SkImages::RasterFromBitmap(*bitmap));
}

int SkImages_RasterFromCompressedTextureData(int sk_data_key_in, int width, int height, SkTextureCompressionType type) {
    return static_sk_image_make(SkImages::RasterFromCompressedTextureData(static_sk_data_move(sk_data_key_in), width, height, type));
}

int SkImages_DeferredFromEncodedData(int sk_data_key_in) {
    return static_sk_image_make(SkImages::DeferredFromEncodedData(static_sk_data_move(sk_data_key_in)));
}

int SkImages_DeferredFromGenerator(int sk_image_generator_key_in) {
    return static_sk_image_make(SkImages::DeferredFromGenerator(static_sk_image_generator_move(sk_image_generator_key_in)));
}

int SkImages_DeferredFromPicture(int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, SkSurfaceProps props) {
    return static_sk_image_make(SkImages::DeferredFromPicture(static_sk_picture_move(sk_picture_key_in), *dimensions, matrix, paint, bitDepth, static_sk_color_space_move(sk_color_space_key_in), props));
}

int SkImages_DeferredFromPicture_2(int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint,SkImages::BitDepth bitDepth) {
    return static_sk_image_make(SkImages::DeferredFromPicture(static_sk_picture_move(sk_picture_key_in), *dimensions,
                                                                        matrix, paint, bitDepth,
                                                                        static_sk_color_space_move(sk_color_space_key_in)));
}

int SkImages_RasterFromPixmapCopy(const SkPixmap *pixmap) {
    return static_sk_image_make(SkImages::RasterFromPixmapCopy(*pixmap));
}

int SkImages_RasterFromPixmap(const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext) {
    return static_sk_image_make(SkImages::RasterFromPixmap(*pixmap, rasterReleaseProc, releaseContext));
}

int SkImages_RasterFromData(int sk_data_key_in, const SkImageInfo *info, size_t rowBytes) {
    return static_sk_image_make(SkImages::RasterFromData(*info, static_sk_data_move(sk_data_key_in), rowBytes));
}

int SkImages_MakeWithFilter(int sk_image_key_in, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset) {
    return static_sk_image_make(SkImages::MakeWithFilter(static_sk_image_move(sk_image_key_in), filter, *subset, *clipBounds, outSubset, offset));
}

}