//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stroke_rec.h"

extern "C" {

void SkStrokeRec_static(const char *sk_stroke_key_out, SkStrokeRec::InitStyle style) {
    static_sk_stroke_rec_set(sk_stroke_key_out, SkStrokeRec(style));
}

void SkStrokeRec_static_2(const char *sk_stroke_key_out, const SkPaint *paint, SkPaint::Style style, SkScalar resScale) {
    static_sk_stroke_rec_set(sk_stroke_key_out, SkStrokeRec(*paint, style, resScale));
}

void SkStrokeRec_static_3(const char *sk_stroke_key_out, const SkPaint *paint, SkScalar resScale) {
    static_sk_stroke_rec_set(sk_stroke_key_out, SkStrokeRec(*paint, resScale));
}

SkStrokeRec::Style SkStrokeRec_getStyle(SkStrokeRec *stroke_rec) {
    return stroke_rec->getStyle();
}

SkScalar SkStrokeRec_getWidth(SkStrokeRec *stroke_rec) {
    return stroke_rec->getWidth();
}

SkScalar SkStrokeRec_getMiter(SkStrokeRec *stroke_rec) {
    return stroke_rec->getMiter();
}

SkPaint::Cap SkStrokeRec_getCap(SkStrokeRec *stroke_rec) {
    return stroke_rec->getCap();
}

SkPaint::Join SkStrokeRec_getJoin(SkStrokeRec *stroke_rec) {
    return stroke_rec->getJoin();
}

bool SkStrokeRec_isHairlineStyle(SkStrokeRec *stroke_rec) {
    return stroke_rec->isHairlineStyle();
}

bool SkStrokeRec_isFillStyle(SkStrokeRec *stroke_rec) {
    return stroke_rec->isFillStyle();
}

void SkStrokeRec_setFillStyle(SkStrokeRec *stroke_rec) {
    return stroke_rec->setFillStyle();
}

void SkStrokeRec_setHairlineStyle(SkStrokeRec *stroke_rec) {
    return stroke_rec->setHairlineStyle();
}

void SkStrokeRec_setStrokeStyle(SkStrokeRec *stroke_rec, SkScalar width, bool strokeAndFill) {
    return stroke_rec->setStrokeStyle(width, strokeAndFill);
}

void SkStrokeRec_setStrokeParams(SkStrokeRec *stroke_rec, SkPaint::Cap cap, SkPaint::Join join, SkScalar miterLimit) {
    return stroke_rec->setStrokeParams(cap, join, miterLimit);
}

SkScalar SkStrokeRec_getResScale(SkStrokeRec *stroke_rec) {
    return stroke_rec->getResScale();
}

void SkStrokeRec_setResScale(SkStrokeRec *stroke_rec, SkScalar rs) {
    return stroke_rec->setResScale(rs);
}

bool SkStrokeRec_needToApply(SkStrokeRec *stroke_rec) {
    return stroke_rec->needToApply();
}

bool SkStrokeRec_applyToPath(SkStrokeRec *stroke_rec, SkPath *dst, const SkPath *src) {
    return stroke_rec->applyToPath(dst, *src);
}

void SkStrokeRec_applyToPaint(SkStrokeRec *stroke_rec, SkPaint *paint) {
    return stroke_rec->applyToPaint(paint);
}

SkScalar SkStrokeRec_getInflationRadius(SkStrokeRec *stroke_rec) {
    return stroke_rec->getInflationRadius();
}

bool SkStrokeRec_hasEqualEffect(SkStrokeRec *stroke_rec, const SkStrokeRec *other) {
    return stroke_rec->hasEqualEffect(*other);
}

// static

SkScalar SkStrokeRec_GetInflationRadius(const SkPaint *paint, SkPaint::Style style) {
    return SkStrokeRec::GetInflationRadius(*paint, style);
}

SkScalar SkStrokeRec_GetInflationRadius_2(SkPaint::Join join, SkScalar miterLimit, SkPaint::Cap cap, SkScalar strokeWidth) {
    return SkStrokeRec::GetInflationRadius(join, miterLimit, cap, strokeWidth);
}

}