//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGES_H
#define RAIA_SKIA_SK_IMAGES_H

#include "include/core/SkImage.h"
#include "include/core/SkSurfaceProps.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_picture.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_image_generator.h"

extern "C" {
void SkImages_RasterFromBitmap(int sk_image_key_out, const SkBitmap *bitmap);
void SkImages_RasterFromCompressedTextureData(int sk_image_key_out, int sk_data_key_in, int width, int height, SkTextureCompressionType type);
void SkImages_DeferredFromEncodedData(int sk_image_key_out, int sk_data_key_in);
void SkImages_DeferredFromGenerator(int sk_image_key_out, int sk_image_generator_key_in);
void SkImages_DeferredFromPicture(int sk_image_key_out, int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, SkSurfaceProps props);
void SkImages_DeferredFromPicture_2(int sk_image_key_out, int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint,SkImages::BitDepth bitDepth);
void SkImages_RasterFromPixmapCopy(int sk_image_key_out, const SkPixmap *pixmap);
void SkImages_RasterFromPixmap(int sk_image_key_out, const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext);
void SkImages_RasterFromData(int sk_image_key_out, int sk_data_key_in, const SkImageInfo *info, size_t rowBytes);
void SkImages_MakeWithFilter(int sk_image_key_out, int sk_image_key_in, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset);
}

#endif //RAIA_SKIA_SK_IMAGES_H
