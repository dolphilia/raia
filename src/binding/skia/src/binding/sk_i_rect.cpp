//
// Created by dolphilia on 2024/01/09.
//

#include "sk_i_rect.h"

extern "C" {

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

SkIPoint SkIRect_topLeft(SkIRect *i_rect) {
    return i_rect->topLeft();
}

int32_t SkIRect_width(SkIRect *i_rect) {
    return i_rect->width();
}

int32_t SkIRect_height(SkIRect *i_rect) {
    return i_rect->height();
}

SkISize SkIRect_size(SkIRect *i_rect) {
    return i_rect->size();
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

void SkIRect_setSize(SkIRect *i_rect, SkISize size) {
    i_rect->setSize(size);
}

void SkIRect_makeOffset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy) {
    static_sk_i_rect_set(sk_i_rect_key_out, i_rect->makeOffset(dx, dy));
}

void SkIRect_makeOffset_2(int sk_i_rect_key_out, SkIRect *i_rect, SkIVector offset) {
    static_sk_i_rect_set(sk_i_rect_key_out, i_rect->makeOffset(offset));
}

void SkIRect_makeInset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy) {
    static_sk_i_rect_set(sk_i_rect_key_out, i_rect->makeInset(dx, dy));
}

void SkIRect_makeOutset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy) {
    static_sk_i_rect_set(sk_i_rect_key_out, i_rect->makeOutset(dx, dy));
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

void SkIRect_makeSorted(int sk_i_rect_key_out, SkIRect *i_rect) {
    static_sk_i_rect_set(sk_i_rect_key_out, i_rect->makeSorted());
}

// static

void SkIRect_MakeEmpty(int sk_i_rect_key_out) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakeEmpty());
}

void SkIRect_MakeWH(int sk_i_rect_key_out, int32_t w, int32_t h) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakeWH(w, h));
}

void SkIRect_MakeSize(int sk_i_rect_key_out, const SkISize *size) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakeSize(*size));
}

void SkIRect_MakePtSize(int sk_i_rect_key_out, SkIPoint pt, SkISize size) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakePtSize(pt, size));
}

void SkIRect_MakeLTRB(int sk_i_rect_key_out, int32_t l, int32_t t, int32_t r, int32_t b) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakeLTRB(l, t, r, b));
}

void SkIRect_MakeXYWH(int sk_i_rect_key_out, int32_t x, int32_t y, int32_t w, int32_t h) {
    static_sk_i_rect_set(sk_i_rect_key_out, SkIRect::MakeXYWH(x, y, w, h));
}

bool SkIRect_Intersects(const SkIRect *a, const SkIRect *b) {
    return SkIRect::Intersects(*a, *b);
}

}