//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RECT_H
#define RAIA_SKIA_SK_RECT_H

#include "include/core/SkRect.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_i_rect.h"

extern "C" {
bool SkRect_isEmpty(SkRect *rect);
bool SkRect_isSorted(SkRect *rect);
bool SkRect_isFinite(SkRect *rect);
float SkRect_x(SkRect *rect);
float SkRect_y(SkRect *rect);
float SkRect_left(SkRect *rect);
float SkRect_top(SkRect *rect);
float SkRect_right(SkRect *rect);
float SkRect_bottom(SkRect *rect);
float SkRect_width(SkRect *rect);
float SkRect_height(SkRect *rect);
float SkRect_centerX(SkRect *rect);
float SkRect_centerY(SkRect *rect);
SkPoint SkRect_center(SkRect *rect);
void SkRect_toQuad(SkRect *rect, SkPoint quad[4]);
void SkRect_setEmpty(SkRect *rect);
void SkRect_set(SkRect *rect, const SkIRect &src);
void SkRect_setLTRB(SkRect *rect, float left, float top, float right, float bottom);
void SkRect_setBounds(SkRect *rect, const SkPoint pts[], int count);
bool SkRect_setBoundsCheck(SkRect *rect, const SkPoint pts[], int count);
void SkRect_setBoundsNoCheck(SkRect *rect, const SkPoint pts[], int count);
void SkRect_set_2(SkRect *rect, const SkPoint &p0, const SkPoint &p1);
void SkRect_setXYWH(SkRect *rect, float x, float y, float width, float height);
void SkRect_setWH(SkRect *rect, float width, float height);
void SkRect_setIWH(SkRect *rect, int32_t width, int32_t height);
void SkRect_makeOffset(const char *sk_rect_key_out, SkRect *rect, float dx, float dy);
void SkRect_makeOffset_2(const char *sk_rect_key_out, SkRect *rect, SkVector v);
void SkRect_makeInset(const char *sk_rect_key_out, SkRect *rect, float dx, float dy);
void SkRect_makeOutset(const char *sk_rect_key_out, SkRect *rect, float dx, float dy);
void SkRect_offset(SkRect *rect, float dx, float dy);
void SkRect_offset_2(SkRect *rect, const SkPoint &delta);
void SkRect_offsetTo(SkRect *rect, float newX, float newY);
void SkRect_inset(SkRect *rect, float dx, float dy);
void SkRect_outset(SkRect *rect, float dx, float dy);
bool SkRect_intersect(SkRect *rect, const SkRect &r);
bool SkRect_intersect_2(SkRect *rect, const SkRect &a, const SkRect &b);
bool SkRect_intersects(SkRect *rect, const SkRect &r);
void SkRect_join(SkRect *rect, const SkRect &r);
void SkRect_joinNonEmptyArg(SkRect *rect, const SkRect &r);
void SkRect_joinPossiblyEmptyRect(SkRect *rect, const SkRect &r);
bool SkRect_contains(SkRect *rect, float x, float y);
bool SkRect_contains_2(SkRect *rect, const SkRect &r);
bool SkRect_contains_3(SkRect *rect, const SkIRect &r);
void SkRect_round(SkRect *rect, SkIRect *dst);
void SkRect_roundOut(SkRect *rect, SkIRect *dst);
void SkRect_roundOut_2(SkRect *rect, SkRect *dst);
void SkRect_roundIn(SkRect *rect, SkIRect *dst);
void SkRect_round_2(const char *sk_i_rect_key_out, SkRect *rect);
void SkRect_roundOut_3(const char *sk_i_rect_key_out, SkRect *rect);
void SkRect_roundIn_2(const char *sk_i_rect_key_out, SkRect *rect);
void SkRect_sort(SkRect *rect);
void SkRect_makeSorted(const char *sk_rect_key_out, SkRect *rect);
const float * SkRect_asScalars(SkRect *rect);
void SkRect_dump(SkRect *rect, bool asHex);
void SkRect_dump_2(SkRect *rect);
void SkRect_dumpHex(SkRect *rect);
// static
void SkRect_MakeEmpty(const char *sk_rect_key_out);
void SkRect_MakeWH(const char *sk_rect_key_out, float w, float h);
void SkRect_MakeIWH(const char *sk_rect_key_out, int w, int h);
void SkRect_MakeSize(const char *sk_rect_key_out, const SkSize &size);
void SkRect_MakeLTRB(const char *sk_rect_key_out, float l, float t, float r, float b);
void SkRect_MakeXYWH(const char *sk_rect_key_out, float x, float y, float w, float h);
void SkRect_Make(const char *sk_rect_key_out, const SkISize &size);
void SkRect_Make_2(const char *sk_rect_key_out, const SkIRect &irect);
bool SkRect_Intersects(const SkRect &a, const SkRect &b);
}

#endif //RAIA_SKIA_SK_RECT_H
