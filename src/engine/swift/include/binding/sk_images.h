//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGES_H
#define RAIA_SKIA_SK_IMAGES_H

#ifdef __cplusplus
extern "C" {
#endif

int SkImages_RasterFromBitmap(const void *bitmap); // (const SkBitmap *bitmap) -> sk_image_t
int SkImages_RasterFromCompressedTextureData(int data, int width, int height, int type); // (sk_data_t data, int width, int height, SkTextureCompressionType type) -> sk_image_t
int SkImages_DeferredFromEncodedData(int data); // (sk_data_t data) -> sk_image_t
int SkImages_DeferredFromGenerator(int image_generator); // (sk_image_generator_t image_generator) -> sk_image_t
int SkImages_DeferredFromPicture(int picture, const void *dimensions, const void *matrix, const void *paint, int bitDepth, int color_space, int props); // (sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space, sk_surface_props_t props) -> sk_image_t
int SkImages_DeferredFromPicture_2(int picture, const void *dimensions, const void *matrix, const void *paint, int bitDepth, int color_space); // (sk_picture_t picture, const SkISize *dimensions, const SkMatrix *matrix, const SkPaint *paint, SkImages::BitDepth bitDepth, sk_color_space_t color_space) -> sk_image_t
int SkImages_RasterFromPixmapCopy(const void *pixmap); // (const SkPixmap *pixmap) -> sk_image_t
int SkImages_RasterFromPixmap(const void *pixmap, void (*rasterReleaseProc)(const void *, void *), void * releaseContext); // (const SkPixmap *pixmap, SkImages::RasterReleaseProc rasterReleaseProc, SkImages::ReleaseContext releaseContext) -> sk_image_t
int SkImages_RasterFromData(const void *info, int data, unsigned long rowBytes); // (const SkImageInfo *info, sk_data_t data, size_t rowBytes) -> sk_image_t
int SkImages_MakeWithFilter(int image, const void *filter, const void *subset, const void *clipBounds, void *outSubset, void *offset); // (sk_image_t image, const SkImageFilter *filter, const SkIRect *subset, const SkIRect *clipBounds, SkIRect *outSubset, SkIPoint *offset) -> sk_image_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGES_H
