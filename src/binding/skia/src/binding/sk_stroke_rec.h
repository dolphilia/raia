//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STROKE_REC_H
#define RAIA_SKIA_SK_STROKE_REC_H

#include "include/core/SkStrokeRec.h"
#include "../static/static_sk_stroke_rec.h"

extern "C" {
void SkStrokeRec_delete(SkStrokeRec *stroke_rec);
sk_stroke_rec_t SkStrokeRec_static(SkStrokeRec::InitStyle style);
sk_stroke_rec_t SkStrokeRec_static_2(const SkPaint *paint, SkPaint::Style style, SkScalar resScale);
sk_stroke_rec_t SkStrokeRec_static_3(const SkPaint *paint, SkScalar resScale);
SkStrokeRec::Style SkStrokeRec_getStyle(SkStrokeRec *stroke_rec);
SkScalar SkStrokeRec_getWidth(SkStrokeRec *stroke_rec);
SkScalar SkStrokeRec_getMiter(SkStrokeRec *stroke_rec);
SkPaint::Cap SkStrokeRec_getCap(SkStrokeRec *stroke_rec);
SkPaint::Join SkStrokeRec_getJoin(SkStrokeRec *stroke_rec);
bool SkStrokeRec_isHairlineStyle(SkStrokeRec *stroke_rec);
bool SkStrokeRec_isFillStyle(SkStrokeRec *stroke_rec);
void SkStrokeRec_setFillStyle(SkStrokeRec *stroke_rec);
void SkStrokeRec_setHairlineStyle(SkStrokeRec *stroke_rec);
void SkStrokeRec_setStrokeStyle(SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill);
void SkStrokeRec_setStrokeParams(SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit);
SkScalar SkStrokeRec_getResScale(SkStrokeRec *stroke_rec);
void SkStrokeRec_setResScale(SkStrokeRec *stroke_rec, SkScalar rs);
bool SkStrokeRec_needToApply(SkStrokeRec *stroke_rec);
bool SkStrokeRec_applyToPath(SkStrokeRec *stroke_rec, SkPath *dst, const SkPath *src);
void SkStrokeRec_applyToPaint(SkStrokeRec *stroke_rec, SkPaint *paint);
SkScalar SkStrokeRec_getInflationRadius(SkStrokeRec *stroke_rec);
bool SkStrokeRec_hasEqualEffect(SkStrokeRec *stroke_rec, const SkStrokeRec *other);
// static
SkScalar SkStrokeRec_GetInflationRadius(const SkPaint *paint, SkPaint::Style style);
SkScalar SkStrokeRec_GetInflationRadius_2(SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth);
}

#endif //RAIA_SKIA_SK_STROKE_REC_H
