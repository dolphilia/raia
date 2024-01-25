//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_I_RECT_H
#define RAIA_SKIA_SK_I_RECT_H

#include "include/core/SkRect.h"
#include "../static/static_sk_i_rect.h"

extern "C" {
int32_t SkIRect_left(SkIRect *i_rect);
int32_t SkIRect_top(SkIRect *i_rect);
int32_t SkIRect_right(SkIRect *i_rect);
int32_t SkIRect_bottom(SkIRect *i_rect);
int32_t SkIRect_x(SkIRect *i_rect);
int32_t SkIRect_y(SkIRect *i_rect);
SkIPoint SkIRect_topLeft(SkIRect *i_rect);
int32_t SkIRect_width(SkIRect *i_rect);
int32_t SkIRect_height(SkIRect *i_rect);
SkISize SkIRect_size(SkIRect *i_rect);
int64_t SkIRect_width64(SkIRect *i_rect);
int64_t SkIRect_height64(SkIRect *i_rect);
bool SkIRect_isEmpty64(SkIRect *i_rect);
bool SkIRect_isEmpty(SkIRect *i_rect);
void SkIRect_setEmpty(SkIRect *i_rect);
void SkIRect_setLTRB(SkIRect *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom);
void SkIRect_setXYWH(SkIRect *i_rect, int32_t x, int32_t y, int32_t width, int32_t height);
void SkIRect_setWH(SkIRect *i_rect, int32_t width, int32_t height);
void SkIRect_setSize(SkIRect *i_rect, SkISize size);
void SkIRect_makeOffset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_makeOffset_2(int sk_i_rect_key_out, SkIRect *i_rect, SkIVector offset);
void SkIRect_makeInset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_makeOutset(int sk_i_rect_key_out, SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_offset(SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_offset_2(SkIRect *i_rect, const SkIPoint *delta);
void SkIRect_offsetTo(SkIRect *i_rect, int32_t newX, int32_t newY);
void SkIRect_inset(SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_outset(SkIRect *i_rect, int32_t dx, int32_t dy);
void SkIRect_adjust(SkIRect *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB);
bool SkIRect_contains(SkIRect *i_rect, int32_t x, int32_t y);
bool SkIRect_contains_2(SkIRect *i_rect, const SkIRect *r);
bool SkIRect_contains_3(SkIRect *i_rect, const SkRect *r);
bool SkIRect_containsNoEmptyCheck(SkIRect *i_rect, const SkIRect *r);
bool SkIRect_intersect(SkIRect *i_rect, const SkIRect *r);
bool SkIRect_intersect_2(SkIRect *i_rect, const SkIRect *a, const SkIRect *b);
void SkIRect_join(SkIRect *i_rect, const SkIRect *r);
void SkIRect_sort(SkIRect *i_rect);
void SkIRect_makeSorted(int sk_i_rect_key_out, SkIRect *i_rect);
// static
void SkIRect_MakeEmpty(int sk_i_rect_key_out);
void SkIRect_MakeWH(int sk_i_rect_key_out, int32_t w, int32_t h);
void SkIRect_MakeSize(int sk_i_rect_key_out, const SkISize *size);
void SkIRect_MakePtSize(int sk_i_rect_key_out, SkIPoint pt, SkISize size);
void SkIRect_MakeLTRB(int sk_i_rect_key_out, int32_t l, int32_t t, int32_t r, int32_t b);
void SkIRect_MakeXYWH(int sk_i_rect_key_out, int32_t x, int32_t y, int32_t w, int32_t h);
bool SkIRect_Intersects(const SkIRect *a, const SkIRect *b);
}

#endif //RAIA_SKIA_SK_I_RECT_H
