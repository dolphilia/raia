//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STROKE_REC_H
#define RAIA_SKIA_SK_STROKE_REC_H

#include "include/core/SkStrokeRec.h"
#include "../static/static_sk_stroke_rec.h"

extern "C" {
void SkStrokeRec_static(const char *sk_stroke_key_out, SkStrokeRec::InitStyle style);
void SkStrokeRec_static_2(const char *sk_stroke_key_out, const SkPaint &paint, SkPaint::Style style, SkScalar resScale);
void SkStrokeRec_static_3(const char *sk_stroke_key_out, const SkPaint &paint, SkScalar resScale);
SkStrokeRec::Style SkStrokeRec_getStyle(class SkStrokeRec *stroke_rec);
SkScalar SkStrokeRec_getWidth(class SkStrokeRec *stroke_rec);
SkScalar SkStrokeRec_getMiter(class SkStrokeRec *stroke_rec);
SkPaint::Cap SkStrokeRec_getCap(class SkStrokeRec *stroke_rec);
SkPaint::Join SkStrokeRec_getJoin(class SkStrokeRec *stroke_rec);
bool SkStrokeRec_isHairlineStyle(class SkStrokeRec *stroke_rec);
bool SkStrokeRec_isFillStyle(class SkStrokeRec *stroke_rec);
void SkStrokeRec_setFillStyle(class SkStrokeRec *stroke_rec);
void SkStrokeRec_setHairlineStyle(class SkStrokeRec *stroke_rec);
void SkStrokeRec_setStrokeStyle(class SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill);
void SkStrokeRec_setStrokeParams(class SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit);
SkScalar SkStrokeRec_getResScale(class SkStrokeRec *stroke_rec);
void SkStrokeRec_setResScale(class SkStrokeRec *stroke_rec, SkScalar rs);
bool SkStrokeRec_needToApply(class SkStrokeRec *stroke_rec);
bool SkStrokeRec_applyToPath(class SkStrokeRec *stroke_rec, SkPath *dst, const SkPath &src);
void SkStrokeRec_applyToPaint(class SkStrokeRec *stroke_rec, SkPaint *paint);
SkScalar SkStrokeRec_getInflationRadius(class SkStrokeRec *stroke_rec);
bool SkStrokeRec_hasEqualEffect(class SkStrokeRec *stroke_rec, const class SkStrokeRec &other);
// static
SkScalar SkStrokeRec_GetInflationRadius(const SkPaint &paint, SkPaint::Style style);
SkScalar SkStrokeRec_GetInflationRadius_2(SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth);
}

#endif //RAIA_SKIA_SK_STROKE_REC_H
