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
#include "../static/static_sk_surface_props.h"

extern "C" {
sk_image_t SkImages_RasterFromBitmap(const SkBitmap *bitmap);
sk_image_t SkImages_RasterFromCompressedTextureData(sk_data_t data, int width, int height, SkTextureCompressionType type);
sk_image_t SkImages_DeferredFromEncodedData(sk_data_t data);
sk_image_t SkImages_DeferredFromGenerator(sk_image_generator_t image_generator);
sk_image_t SkImages_DeferredFromPicture(sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space, sk_surface_props_t props);
sk_image_t SkImages_DeferredFromPicture_2(sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space);
sk_image_t SkImages_RasterFromPixmapCopy(const SkPixmap *pixmap);
sk_image_t SkImages_RasterFromPixmap(const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext);
sk_image_t SkImages_RasterFromData(const SkImageInfo *info, sk_data_t data, size_t rowBytes);
sk_image_t SkImages_MakeWithFilter(sk_image_t image, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset);
}

#endif //RAIA_SKIA_SK_IMAGES_H
