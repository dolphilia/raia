//
// Created by dolphilia on 2024/01/08.
//

#include "sk_images.h"

extern "C" {

void SkImages_RasterFromBitmap(const char *sk_image_key_out, const SkBitmap *bitmap) {
    static_sk_image_set(sk_image_key_out, SkImages::RasterFromBitmap(*bitmap));
}

void SkImages_RasterFromCompressedTextureData(const char *sk_image_key_out, const char *sk_data_key_in, int width, int height, SkTextureCompressionType type) {
    static_sk_image_set(sk_image_key_out, SkImages::RasterFromCompressedTextureData(static_sk_data_move(sk_data_key_in), width, height, type));
}

void SkImages_DeferredFromEncodedData(const char *sk_image_key_out, const char *sk_data_key_in) {
    static_sk_image_set(sk_image_key_out, SkImages::DeferredFromEncodedData(static_sk_data_move(sk_data_key_in)));
}

void SkImages_DeferredFromGenerator(const char *sk_image_key_out, const char *sk_image_generator_key_in) {
    static_sk_image_set(sk_image_key_out, SkImages::DeferredFromGenerator(static_sk_image_generator_move(sk_image_generator_key_in)));
}

void SkImages_DeferredFromPicture(const char *sk_image_key_out, const char *sk_picture_key_in, const char *sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, SkSurfaceProps props) {
    static_sk_image_set(sk_image_key_out, SkImages::DeferredFromPicture(static_sk_picture_move(sk_picture_key_in), *dimensions, matrix, paint, bitDepth, static_sk_color_space_move(sk_color_space_key_in), props));
}

void SkImages_DeferredFromPicture_2(const char *sk_image_key_out, const char *sk_picture_key_in, const char *sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint,SkImages::BitDepth bitDepth) {
    static_sk_image_set(sk_image_key_out, SkImages::DeferredFromPicture(static_sk_picture_move(sk_picture_key_in), *dimensions,
                                                                        matrix, paint, bitDepth,
                                                                        static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImages_RasterFromPixmapCopy(const char *sk_image_key_out, const SkPixmap *pixmap) {
    static_sk_image_set(sk_image_key_out, SkImages::RasterFromPixmapCopy(*pixmap));
}

void SkImages_RasterFromPixmap(const char *sk_image_key_out, const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext) {
    static_sk_image_set(sk_image_key_out, SkImages::RasterFromPixmap(*pixmap, rasterReleaseProc, releaseContext));
}

void SkImages_RasterFromData(const char *sk_image_key_out, const char *sk_data_key_in, const SkImageInfo *info, size_t rowBytes) {
    static_sk_image_set(sk_image_key_out, SkImages::RasterFromData(*info, static_sk_data_move(sk_data_key_in), rowBytes));
}

void SkImages_MakeWithFilter(const char *sk_image_key_out, const char *sk_image_key_in, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset) {
    static_sk_image_set(sk_image_key_out, SkImages::MakeWithFilter(static_sk_image_move(sk_image_key_in), filter, *subset, *clipBounds, outSubset, offset));
}

}