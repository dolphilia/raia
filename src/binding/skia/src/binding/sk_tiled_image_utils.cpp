//
// Created by dolphilia on 2024/01/13.
//

#include "sk_tiled_image_utils.h"

extern "C" {

void SkTiledImageUtils_DrawImageRect(SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImageRect(canvas, image, *src, *dst, *sampling, paint, constraint);
}

void SkTiledImageUtils_DrawImageRect_2(SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImageRect(canvas, *image, *src, *dst, *sampling, paint, constraint);
}

void SkTiledImageUtils_DrawImageRect_3(SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImageRect(canvas, image, *dst, *sampling, paint, constraint);
}

void SkTiledImageUtils_DrawImageRect_4(SkCanvas *canvas, const sk_sp< SkImage > *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImageRect(canvas, *image, *dst, *sampling, paint, constraint);
}

void SkTiledImageUtils_DrawImage(SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImage(canvas, image, x, y, *sampling, paint, constraint);
}

void SkTiledImageUtils_DrawImage_2(SkCanvas *canvas, const sk_sp< SkImage > *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint) {
    SkTiledImageUtils::DrawImage(canvas, *image, x, y, *sampling, paint, constraint);
}

void SkTiledImageUtils_GetImageKeyValues(const SkImage *image, uint32_t keyValues[SkTiledImageUtils::kNumImageKeyValues]) {
    SkTiledImageUtils::GetImageKeyValues(image, keyValues);
}

}