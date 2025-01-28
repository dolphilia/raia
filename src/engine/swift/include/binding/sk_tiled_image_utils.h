//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_TILED_IMAGE_UTILS_H
#define RAIA_SKIA_SK_TILED_IMAGE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkTiledImageUtils_DrawImageRect(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_DrawImageRect_2(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_DrawImageRect_3(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_DrawImageRect_4(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_DrawImage(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_DrawImage_2(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const sk_sp< SkImage > *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkTiledImageUtils_GetImageKeyValues(const void *image, void * keyValues); // (const SkImage *image, uint32_t keyValues[SkTiledImageUtils::kNumImageKeyValues])

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TILED_IMAGE_UTILS_H
