//
// Created by dolphilia on 2024/01/09.
//

#include "sk_i_rect.h"

extern "C" {

void SkIRect_delete(SkIRect *i_rect) {
    delete i_rect;
}

int32_t SkIRect_left(SkIRect *i_rect) {
    return i_rect->left();
}

int32_t SkIRect_top(SkIRect *i_rect) {
    return i_rect->top();
}

int32_t SkIRect_right(SkIRect *i_rect) {
    return i_rect->right();
}

int32_t SkIRect_bottom(SkIRect *i_rect) {
    return i_rect->bottom();
}

int32_t SkIRect_x(SkIRect *i_rect) {
    return i_rect->x();
}

int32_t SkIRect_y(SkIRect *i_rect) {
    return i_rect->y();
}

sk_i_point_t SkIRect_topLeft(SkIRect *i_rect) {
    return static_sk_i_point_make(i_rect->topLeft());
}

int32_t SkIRect_width(SkIRect *i_rect) {
    return i_rect->width();
}

int32_t SkIRect_height(SkIRect *i_rect) {
    return i_rect->height();
}

sk_i_size_t SkIRect_size(SkIRect *i_rect) {
    return static_sk_i_size_make(i_rect->size());
}

int64_t SkIRect_width64(SkIRect *i_rect) {
    return i_rect->width64();
}

int64_t SkIRect_height64(SkIRect *i_rect) {
    return i_rect->height64();
}

bool SkIRect_isEmpty64(SkIRect *i_rect) {
    return i_rect->isEmpty64();
}

bool SkIRect_isEmpty(SkIRect *i_rect) {
    return i_rect->isEmpty();
}

void SkIRect_setEmpty(SkIRect *i_rect) {
    i_rect->setEmpty();
}

void SkIRect_setLTRB(SkIRect *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom) {
    i_rect->setLTRB(left, top, right, bottom);
}

void SkIRect_setXYWH(SkIRect *i_rect, int32_t x, int32_t y, int32_t width, int32_t height) {
    i_rect->setXYWH(x, y, width, height);
}

void SkIRect_setWH(SkIRect *i_rect, int32_t width, int32_t height) {
    i_rect->setWH(width, height);
}

void SkIRect_setSize(SkIRect *i_rect, sk_i_size_t size) {
    i_rect->setSize(static_sk_i_size_get(size));
}

sk_i_rect_t SkIRect_makeOffset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return static_sk_i_rect_make(i_rect->makeOffset(dx, dy));
}

sk_i_rect_t SkIRect_makeOffset_2(SkIRect *i_rect, sk_i_point_t offset) {
    return static_sk_i_rect_make(i_rect->makeOffset(static_sk_i_point_get(offset)));
}

sk_i_rect_t SkIRect_makeInset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return static_sk_i_rect_make(i_rect->makeInset(dx, dy));
}

sk_i_rect_t SkIRect_makeOutset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return static_sk_i_rect_make(i_rect->makeOutset(dx, dy));
}

void SkIRect_offset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->offset(dx, dy);
}

void SkIRect_offset_2(SkIRect *i_rect, const SkIPoint *delta) {
    i_rect->offset(*delta);
}

void SkIRect_offsetTo(SkIRect *i_rect, int32_t newX, int32_t newY) {
    i_rect->offsetTo(newX, newY);
}

void SkIRect_inset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    return i_rect->inset(dx, dy);
}

void SkIRect_outset(SkIRect *i_rect, int32_t dx, int32_t dy) {
    i_rect->outset(dx, dy);
}

void SkIRect_adjust(SkIRect *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB) {
    i_rect->adjust(dL, dT, dR, dB);
}

bool SkIRect_contains(SkIRect *i_rect, int32_t x, int32_t y) {
    return i_rect->contains(x, y);
}

bool SkIRect_contains_2(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->contains(*r);
}

bool SkIRect_contains_3(SkIRect *i_rect, const SkRect *r) {
    return i_rect->contains(*r);
}

bool SkIRect_containsNoEmptyCheck(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->containsNoEmptyCheck(*r);
}

bool SkIRect_intersect(SkIRect *i_rect, const SkIRect *r) {
    return i_rect->intersect(*r);
}

bool SkIRect_intersect_2(SkIRect *i_rect, const SkIRect *a, const SkIRect *b) {
    return i_rect->intersect(*a, *b);
}

void SkIRect_join(SkIRect *i_rect, const SkIRect *r) {
    i_rect->join(*r);
}

void SkIRect_sort(SkIRect *i_rect) {
    i_rect->sort();
}

sk_i_rect_t SkIRect_makeSorted(SkIRect *i_rect) {
    return static_sk_i_rect_make(i_rect->makeSorted());
}

// static

sk_i_rect_t SkIRect_MakeEmpty() {
    return static_sk_i_rect_make(SkIRect::MakeEmpty());
}

sk_i_rect_t SkIRect_MakeWH(int32_t w, int32_t h) {
    return static_sk_i_rect_make(SkIRect::MakeWH(w, h));
}

sk_i_rect_t SkIRect_MakeSize(const SkISize *size) {
    return static_sk_i_rect_make(SkIRect::MakeSize(*size));
}

sk_i_rect_t SkIRect_MakePtSize(sk_i_point_t pt, sk_i_size_t size) {
    return static_sk_i_rect_make(SkIRect::MakePtSize(static_sk_i_point_get(pt), static_sk_i_size_get(size)));
}

sk_i_rect_t SkIRect_MakeLTRB(int32_t l, int32_t t, int32_t r, int32_t b) {
    return static_sk_i_rect_make(SkIRect::MakeLTRB(l, t, r, b));
}

sk_i_rect_t SkIRect_MakeXYWH(int32_t x, int32_t y, int32_t w, int32_t h) {
    return static_sk_i_rect_make(SkIRect::MakeXYWH(x, y, w, h));
}

bool SkIRect_Intersects(const SkIRect *a, const SkIRect *b) {
    return SkIRect::Intersects(*a, *b);
}

}