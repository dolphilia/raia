//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RECT_H
#define RAIA_SKIA_SK_RECT_H

#include "include/core/SkRect.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_point.h"

extern "C" {
void SkRect_delete(SkRect *rect);
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
sk_point_t SkRect_center(SkRect *rect);
void SkRect_toQuad(SkRect *rect, SkPoint quad[4]);
void SkRect_setEmpty(SkRect *rect);
void SkRect_set(SkRect *rect, const SkIRect *src);
void SkRect_setLTRB(SkRect *rect, float left, float top, float right, float bottom);
void SkRect_setBounds(SkRect *rect, const SkPoint pts[], int count);
bool SkRect_setBoundsCheck(SkRect *rect, const SkPoint pts[], int count);
void SkRect_setBoundsNoCheck(SkRect *rect, const SkPoint pts[], int count);
void SkRect_set_2(SkRect *rect, const SkPoint *p0, const SkPoint *p1);
void SkRect_setXYWH(SkRect *rect, float x, float y, float width, float height);
void SkRect_setWH(SkRect *rect, float width, float height);
void SkRect_setIWH(SkRect *rect, int32_t width, int32_t height);
sk_rect_t SkRect_makeOffset(SkRect *rect, float dx, float dy);
sk_rect_t SkRect_makeOffset_2(SkRect *rect, sk_point_t v);
sk_rect_t SkRect_makeInset(SkRect *rect, float dx, float dy);
sk_rect_t SkRect_makeOutset(SkRect *rect, float dx, float dy);
void SkRect_offset(SkRect *rect, float dx, float dy);
void SkRect_offset_2(SkRect *rect, const SkPoint *delta);
void SkRect_offsetTo(SkRect *rect, float newX, float newY);
void SkRect_inset(SkRect *rect, float dx, float dy);
void SkRect_outset(SkRect *rect, float dx, float dy);
bool SkRect_intersect(SkRect *rect, const SkRect *r);
bool SkRect_intersect_2(SkRect *rect, const SkRect *a, const SkRect *b);
bool SkRect_intersects(SkRect *rect, const SkRect *r);
void SkRect_join(SkRect *rect, const SkRect *r);
void SkRect_joinNonEmptyArg(SkRect *rect, const SkRect *r);
void SkRect_joinPossiblyEmptyRect(SkRect *rect, const SkRect *r);
bool SkRect_contains(SkRect *rect, float x, float y);
bool SkRect_contains_2(SkRect *rect, const SkRect *r);
bool SkRect_contains_3(SkRect *rect, const SkIRect *r);
void SkRect_round(SkRect *rect, SkIRect *dst);
void SkRect_roundOut(SkRect *rect, SkIRect *dst);
void SkRect_roundOut_2(SkRect *rect, SkRect *dst);
void SkRect_roundIn(SkRect *rect, SkIRect *dst);
sk_i_rect_t SkRect_round_2(SkRect *rect);
sk_i_rect_t SkRect_roundOut_3(SkRect *rect);
sk_i_rect_t SkRect_roundIn_2(SkRect *rect);
void SkRect_sort(SkRect *rect);
sk_rect_t SkRect_makeSorted(SkRect *rect);
const float * SkRect_asScalars(SkRect *rect);
void SkRect_dump(SkRect *rect, bool asHex);
void SkRect_dump_2(SkRect *rect);
void SkRect_dumpHex(SkRect *rect);
// static
sk_rect_t SkRect_MakeEmpty();
sk_rect_t SkRect_MakeWH(float w, float h);
sk_rect_t SkRect_MakeIWH(int w, int h);
sk_rect_t SkRect_MakeSize(const SkSize *size);
sk_rect_t SkRect_MakeLTRB(float l, float t, float r, float b);
sk_rect_t SkRect_MakeXYWH(float x, float y, float w, float h);
sk_rect_t SkRect_Make(const SkISize *size);
sk_rect_t SkRect_Make_2(const SkIRect *irect);
bool SkRect_Intersects(const SkRect *a, const SkRect *b);
}

#endif //RAIA_SKIA_SK_RECT_H
