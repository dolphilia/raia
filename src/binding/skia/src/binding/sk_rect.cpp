//
// Created by dolphilia on 2024/01/10.
//

#include "sk_rect.h"

extern "C" {

bool SkRect_isEmpty(SkRect *rect) {
    return rect->isEmpty();
}

bool SkRect_isSorted(SkRect *rect) {
    return rect->isSorted();
}

bool SkRect_isFinite(SkRect *rect) {
    return rect->isFinite();
}

float SkRect_x(SkRect *rect) {
    return rect->x();
}

float SkRect_y(SkRect *rect) {
    return rect->y();
}

float SkRect_left(SkRect *rect) {
    return rect->left();
}

float SkRect_top(SkRect *rect) {
    return rect->top();
}

float SkRect_right(SkRect *rect) {
    return rect->right();
}

float SkRect_bottom(SkRect *rect) {
    return rect->bottom();
}

float SkRect_width(SkRect *rect) {
    return rect->width();
}

float SkRect_height(SkRect *rect) {
    return rect->height();
}

float SkRect_centerX(SkRect *rect) {
    return rect->centerX();
}

float SkRect_centerY(SkRect *rect) {
    return rect->centerY();
}

SkPoint SkRect_center(SkRect *rect) {
    return rect->center();
}

void SkRect_toQuad(SkRect *rect, SkPoint quad[4]) {
    rect->toQuad(quad);
}

void SkRect_setEmpty(SkRect *rect) {
    rect->setEmpty();
}

void SkRect_set(SkRect *rect, const SkIRect *src) {
    rect->set(*src);
}

void SkRect_setLTRB(SkRect *rect, float left, float top, float right, float bottom) {
    rect->setLTRB(left, top, right, bottom);
}

void SkRect_setBounds(SkRect *rect, const SkPoint pts[], int count) {
    rect->setBounds(pts, count);
}

bool SkRect_setBoundsCheck(SkRect *rect, const SkPoint pts[], int count) {
    return rect->setBoundsCheck(pts, count);
}

void SkRect_setBoundsNoCheck(SkRect *rect, const SkPoint pts[], int count) {
    rect->setBoundsNoCheck(pts, count);
}

void SkRect_set_2(SkRect *rect, const SkPoint *p0, const SkPoint *p1) {
    rect->set(*p0, *p1);
}

void SkRect_setXYWH(SkRect *rect, float x, float y, float width, float height) {
    rect->setXYWH(x, y, width, height);
}

void SkRect_setWH(SkRect *rect, float width, float height) {
    rect->setWH(width, height);
}

void SkRect_setIWH(SkRect *rect, int32_t width, int32_t height) {
    rect->setIWH(width, height);
}

void SkRect_makeOffset(int sk_rect_key_out, SkRect *rect, float dx, float dy) {
    static_sk_rect_set(sk_rect_key_out, rect->makeOutset(dx, dy));
}

void SkRect_makeOffset_2(int sk_rect_key_out, SkRect *rect, SkVector v) {
    static_sk_rect_set(sk_rect_key_out, rect->makeOffset(v));
}

void SkRect_makeInset(int sk_rect_key_out, SkRect *rect, float dx, float dy) {
    static_sk_rect_set(sk_rect_key_out, rect->makeInset(dx, dy));
}

void SkRect_makeOutset(int sk_rect_key_out, SkRect *rect, float dx, float dy) {
    static_sk_rect_set(sk_rect_key_out, rect->makeOutset(dx, dy));
}

void SkRect_offset(SkRect *rect, float dx, float dy) {
    rect->offset(dx, dy);
}

void SkRect_offset_2(SkRect *rect, const SkPoint *delta) {
    rect->offset(*delta);
}

void SkRect_offsetTo(SkRect *rect, float newX, float newY) {
    rect->offsetTo(newX, newY);
}

void SkRect_inset(SkRect *rect, float dx, float dy) {
    rect->inset(dx, dy);
}

void SkRect_outset(SkRect *rect, float dx, float dy) {
    rect->outset(dx, dy);
}

bool SkRect_intersect(SkRect *rect, const SkRect *r) {
    return rect->intersect(*r);
}

bool SkRect_intersect_2(SkRect *rect, const SkRect *a, const SkRect *b) {
    return rect->intersect(*a, *b);
}

bool SkRect_intersects(SkRect *rect, const SkRect *r) {
    return rect->intersects(*r);
}

void SkRect_join(SkRect *rect, const SkRect *r) {
    rect->join(*r);
}

void SkRect_joinNonEmptyArg(SkRect *rect, const SkRect *r) {
    rect->joinNonEmptyArg(*r);
}

void SkRect_joinPossiblyEmptyRect(SkRect *rect, const SkRect *r) {
    rect->joinPossiblyEmptyRect(*r);
}

bool SkRect_contains(SkRect *rect, float x, float y) {
    return rect->contains(x, y);
}

bool SkRect_contains_2(SkRect *rect, const SkRect *r) {
    return rect->contains(*r);
}

bool SkRect_contains_3(SkRect *rect, const SkIRect *r) {
    return rect->contains(*r);
}

void SkRect_round(SkRect *rect, SkIRect *dst) {
    rect->round(dst);
}

void SkRect_roundOut(SkRect *rect, SkIRect *dst) {
    rect->roundOut(dst);
}

void SkRect_roundOut_2(SkRect *rect, SkRect *dst) {
    rect->roundOut(dst);
}

void SkRect_roundIn(SkRect *rect, SkIRect *dst) {
    rect->roundIn(dst);
}

void SkRect_round_2(int sk_i_rect_key_out, SkRect *rect) {
    static_sk_i_rect_set(sk_i_rect_key_out, rect->round());
}

void SkRect_roundOut_3(int sk_i_rect_key_out, SkRect *rect) {
    static_sk_i_rect_set(sk_i_rect_key_out, rect->roundOut());
}

void SkRect_roundIn_2(int sk_i_rect_key_out, SkRect *rect) {
    static_sk_i_rect_set(sk_i_rect_key_out, rect->roundIn());
}

void SkRect_sort(SkRect *rect) {
    rect->sort();
}

void SkRect_makeSorted(int sk_rect_key_out, SkRect *rect) {
    static_sk_rect_set(sk_rect_key_out, rect->makeSorted());
}

const float * SkRect_asScalars(SkRect *rect) {
    return rect->asScalars();
}

void SkRect_dump(SkRect *rect, bool asHex) {
    rect->dump(asHex);
}

void SkRect_dump_2(SkRect *rect) {
    rect->dump();
}

void SkRect_dumpHex(SkRect *rect) {
    rect->dumpHex();
}

// static

void SkRect_MakeEmpty(int sk_rect_key_out) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeEmpty());
}

void SkRect_MakeWH(int sk_rect_key_out, float w, float h) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeWH(w, h));
}

void SkRect_MakeIWH(int sk_rect_key_out, int w, int h) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeIWH(w, h));
}

void SkRect_MakeSize(int sk_rect_key_out, const SkSize *size) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeSize(*size));
}

void SkRect_MakeLTRB(int sk_rect_key_out, float l, float t, float r, float b) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeLTRB(l, t, r, b));
}

void SkRect_MakeXYWH(int sk_rect_key_out, float x, float y, float w, float h) {
    static_sk_rect_set(sk_rect_key_out, SkRect::MakeXYWH(x, y, w, h));
}

void SkRect_Make(int sk_rect_key_out, const SkISize *size) {
    static_sk_rect_set(sk_rect_key_out, SkRect::Make(*size));
}

void SkRect_Make_2(int sk_rect_key_out, const SkIRect *irect) {
    static_sk_rect_set(sk_rect_key_out, SkRect::Make(*irect));
}

bool SkRect_Intersects(const SkRect *a, const SkRect *b) {
    return SkRect::Intersects(*a, *b);
}

}