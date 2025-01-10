//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_TILED_IMAGE_UTILS_H
#define RAIA_SKIA_SK_TILED_IMAGE_UTILS_H

#include "include/core/SkTiledImageUtils.h"

extern "C" {
void SkTiledImageUtils_DrawImageRect(SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_DrawImageRect_2(SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_DrawImageRect_3(SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_DrawImageRect_4(SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_DrawImage(SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_DrawImage_2(SkCanvas *canvas, const sk_sp< SkImage > *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkTiledImageUtils_GetImageKeyValues(const SkImage *image, uint32_t keyValues[SkTiledImageUtils::kNumImageKeyValues]);
}

#endif //RAIA_SKIA_SK_TILED_IMAGE_UTILS_H
