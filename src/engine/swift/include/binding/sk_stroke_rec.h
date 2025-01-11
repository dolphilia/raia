//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STROKE_REC_H
#define RAIA_SKIA_SK_STROKE_REC_H

#include "include/core/SkStrokeRec.h"
#include "../static/static_sk_stroke_rec.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkStrokeRec_delete(SkStrokeRec *stroke_rec);
RAIA_API sk_stroke_rec_t SkStrokeRec_static(SkStrokeRec::InitStyle style);
RAIA_API sk_stroke_rec_t SkStrokeRec_static_2(const SkPaint *paint, SkPaint::Style style, SkScalar resScale);
RAIA_API sk_stroke_rec_t SkStrokeRec_static_3(const SkPaint *paint, SkScalar resScale);
RAIA_API SkStrokeRec::Style SkStrokeRec_getStyle(SkStrokeRec *stroke_rec);
RAIA_API SkScalar SkStrokeRec_getWidth(SkStrokeRec *stroke_rec);
RAIA_API SkScalar SkStrokeRec_getMiter(SkStrokeRec *stroke_rec);
RAIA_API SkPaint::Cap SkStrokeRec_getCap(SkStrokeRec *stroke_rec);
RAIA_API SkPaint::Join SkStrokeRec_getJoin(SkStrokeRec *stroke_rec);
RAIA_API bool SkStrokeRec_isHairlineStyle(SkStrokeRec *stroke_rec);
RAIA_API bool SkStrokeRec_isFillStyle(SkStrokeRec *stroke_rec);
RAIA_API void SkStrokeRec_setFillStyle(SkStrokeRec *stroke_rec);
RAIA_API void SkStrokeRec_setHairlineStyle(SkStrokeRec *stroke_rec);
RAIA_API void SkStrokeRec_setStrokeStyle(SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill);
RAIA_API void SkStrokeRec_setStrokeParams(SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit);
RAIA_API SkScalar SkStrokeRec_getResScale(SkStrokeRec *stroke_rec);
RAIA_API void SkStrokeRec_setResScale(SkStrokeRec *stroke_rec, SkScalar rs);
RAIA_API bool SkStrokeRec_needToApply(SkStrokeRec *stroke_rec);
RAIA_API bool SkStrokeRec_applyToPath(SkStrokeRec *stroke_rec, SkPath *dst, const SkPath *src);
RAIA_API void SkStrokeRec_applyToPaint(SkStrokeRec *stroke_rec, SkPaint *paint);
RAIA_API SkScalar SkStrokeRec_getInflationRadius(SkStrokeRec *stroke_rec);
RAIA_API bool SkStrokeRec_hasEqualEffect(SkStrokeRec *stroke_rec, const SkStrokeRec *other);
// static
RAIA_API SkScalar SkStrokeRec_GetInflationRadius(const SkPaint *paint, SkPaint::Style style);
RAIA_API SkScalar SkStrokeRec_GetInflationRadius_2(SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth);
}

#endif //RAIA_SKIA_SK_STROKE_REC_H
