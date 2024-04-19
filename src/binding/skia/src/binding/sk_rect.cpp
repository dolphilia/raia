//
// Created by dolphilia on 2024/01/10.
//

#include "sk_rect.h"

extern "C" {

void SkRect_delete(SkRect *rect) {
    delete rect;
}

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

sk_point_t SkRect_center(SkRect *rect) {
    return static_sk_point_make(rect->center());
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

sk_rect_t SkRect_makeOffset(SkRect *rect, float dx, float dy) {
    return static_sk_rect_make(rect->makeOutset(dx, dy));
}

sk_rect_t SkRect_makeOffset_2(SkRect *rect, sk_point_t v) {
    return static_sk_rect_make(rect->makeOffset(static_sk_point_get(v)));
}

sk_rect_t SkRect_makeInset(SkRect *rect, float dx, float dy) {
    return static_sk_rect_make(rect->makeInset(dx, dy));
}

sk_rect_t SkRect_makeOutset(SkRect *rect, float dx, float dy) {
    return static_sk_rect_make(rect->makeOutset(dx, dy));
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

sk_i_rect_t SkRect_round_2(SkRect *rect) {
    return static_sk_i_rect_make(rect->round());
}

sk_i_rect_t SkRect_roundOut_3(SkRect *rect) {
    return static_sk_i_rect_make(rect->roundOut());
}

sk_i_rect_t SkRect_roundIn_2(SkRect *rect) {
    return static_sk_i_rect_make(rect->roundIn());
}

void SkRect_sort(SkRect *rect) {
    rect->sort();
}

sk_rect_t SkRect_makeSorted(SkRect *rect) {
    return static_sk_rect_make(rect->makeSorted());
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

sk_rect_t SkRect_MakeEmpty() {
    return static_sk_rect_make(SkRect::MakeEmpty());
}

sk_rect_t SkRect_MakeWH(float w, float h) {
    return static_sk_rect_make(SkRect::MakeWH(w, h));
}

sk_rect_t SkRect_MakeIWH(int w, int h) {
    return static_sk_rect_make(SkRect::MakeIWH(w, h));
}

sk_rect_t SkRect_MakeSize(const SkSize *size) {
    return static_sk_rect_make(SkRect::MakeSize(*size));
}

sk_rect_t SkRect_MakeLTRB(float l, float t, float r, float b) {
    return static_sk_rect_make(SkRect::MakeLTRB(l, t, r, b));
}

sk_rect_t SkRect_MakeXYWH(float x, float y, float w, float h) {
    return static_sk_rect_make(SkRect::MakeXYWH(x, y, w, h));
}

sk_rect_t SkRect_Make(const SkISize *size) {
    return static_sk_rect_make(SkRect::Make(*size));
}

sk_rect_t SkRect_Make_2(const SkIRect *irect) {
    return static_sk_rect_make(SkRect::Make(*irect));
}

bool SkRect_Intersects(const SkRect *a, const SkRect *b) {
    return SkRect::Intersects(*a, *b);
}

}