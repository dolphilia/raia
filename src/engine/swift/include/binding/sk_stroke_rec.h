//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STROKE_REC_H
#define RAIA_SKIA_SK_STROKE_REC_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStrokeRec_delete(void *stroke_rec); // (SkStrokeRec *stroke_rec)
int SkStrokeRec_static(int style); // (SkStrokeRec::InitStyle style) -> sk_stroke_rec_t
int SkStrokeRec_static_2(const void *paint, int style, float resScale); // (const SkPaint *paint, SkPaint::Style style, SkScalar resScale) -> sk_stroke_rec_t
int SkStrokeRec_static_3(const void *paint, float resScale); // (const SkPaint *paint, SkScalar resScale) -> sk_stroke_rec_t
int SkStrokeRec_getStyle(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkStrokeRec::Style
float SkStrokeRec_getWidth(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkScalar
float SkStrokeRec_getMiter(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkScalar
int SkStrokeRec_getCap(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkPaint::Cap
int SkStrokeRec_getJoin(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkPaint::Join
bool SkStrokeRec_isHairlineStyle(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> bool
bool SkStrokeRec_isFillStyle(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> bool
void SkStrokeRec_setFillStyle(void *stroke_rec); // (SkStrokeRec *stroke_rec)
void SkStrokeRec_setHairlineStyle(void *stroke_rec); // (SkStrokeRec *stroke_rec)
void SkStrokeRec_setStrokeStyle(void *stroke_rec, float width, bool strokeAndFill); // (SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill)
void SkStrokeRec_setStrokeParams(void *stroke_rec, int cap, int join, float miterLimit); // (SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit)
float SkStrokeRec_getResScale(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkScalar
void SkStrokeRec_setResScale(void *stroke_rec, float rs); // (SkStrokeRec *stroke_rec, SkScalar rs)
bool SkStrokeRec_needToApply(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> bool
bool SkStrokeRec_applyToPath(void *stroke_rec, void *dst, const void *src); // (SkStrokeRec *stroke_rec, SkPath *dst, const SkPath *src) -> bool
void SkStrokeRec_applyToPaint(void *stroke_rec, void *paint); // (SkStrokeRec *stroke_rec, SkPaint *paint)
float SkStrokeRec_getInflationRadius(void *stroke_rec); // (SkStrokeRec *stroke_rec) -> SkScalar
bool SkStrokeRec_hasEqualEffect(void *stroke_rec, const void *other); // (SkStrokeRec *stroke_rec, const SkStrokeRec *other) -> bool

// static

float SkStrokeRec_GetInflationRadius(const void *paint, int style); // (const SkPaint *paint, SkPaint::Style style) -> SkScalar
float SkStrokeRec_GetInflationRadius_2(int join, float miterLimit, int cap, float strokeWidth); // (SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth) -> SkScalar

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STROKE_REC_H
