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
int SkImages_RasterFromBitmap(const SkBitmap *bitmap);
int SkImages_RasterFromCompressedTextureData(int sk_data_key_in, int width, int height, SkTextureCompressionType type);
int SkImages_DeferredFromEncodedData(int sk_data_key_in);
int SkImages_DeferredFromGenerator(int sk_image_generator_key_in);
int SkImages_DeferredFromPicture(int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, SkSurfaceProps props);
int SkImages_DeferredFromPicture_2(int sk_picture_key_in, int sk_color_space_key_in, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint,SkImages::BitDepth bitDepth);
int SkImages_RasterFromPixmapCopy(const SkPixmap *pixmap);
int SkImages_RasterFromPixmap(const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext);
int SkImages_RasterFromData(int sk_data_key_in, const SkImageInfo *info, size_t rowBytes);
int SkImages_MakeWithFilter(int sk_image_key_in, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset);
}

#endif //RAIA_SKIA_SK_IMAGES_H
