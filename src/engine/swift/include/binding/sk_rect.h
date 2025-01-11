//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RECT_H
#define RAIA_SKIA_SK_RECT_H

#include "include/core/SkRect.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkRect_delete(SkRect *rect);
RAIA_API bool SkRect_isEmpty(SkRect *rect);
RAIA_API bool SkRect_isSorted(SkRect *rect);
RAIA_API bool SkRect_isFinite(SkRect *rect);
RAIA_API float SkRect_x(SkRect *rect);
RAIA_API float SkRect_y(SkRect *rect);
RAIA_API float SkRect_left(SkRect *rect);
RAIA_API float SkRect_top(SkRect *rect);
RAIA_API float SkRect_right(SkRect *rect);
RAIA_API float SkRect_bottom(SkRect *rect);
RAIA_API float SkRect_width(SkRect *rect);
RAIA_API float SkRect_height(SkRect *rect);
RAIA_API float SkRect_centerX(SkRect *rect);
RAIA_API float SkRect_centerY(SkRect *rect);
RAIA_API sk_point_t SkRect_center(SkRect *rect);
RAIA_API void SkRect_toQuad(SkRect *rect, SkPoint quad[4]);
RAIA_API void SkRect_setEmpty(SkRect *rect);
RAIA_API void SkRect_set(SkRect *rect, const SkIRect *src);
RAIA_API void SkRect_setLTRB(SkRect *rect, float left, float top, float right, float bottom);
RAIA_API void SkRect_setBounds(SkRect *rect, const SkPoint pts[], int count);
RAIA_API bool SkRect_setBoundsCheck(SkRect *rect, const SkPoint pts[], int count);
RAIA_API void SkRect_setBoundsNoCheck(SkRect *rect, const SkPoint pts[], int count);
RAIA_API void SkRect_set_2(SkRect *rect, const SkPoint *p0, const SkPoint *p1);
RAIA_API void SkRect_setXYWH(SkRect *rect, float x, float y, float width, float height);
RAIA_API void SkRect_setWH(SkRect *rect, float width, float height);
RAIA_API void SkRect_setIWH(SkRect *rect, int32_t width, int32_t height);
RAIA_API sk_rect_t SkRect_makeOffset(SkRect *rect, float dx, float dy);
RAIA_API sk_rect_t SkRect_makeOffset_2(SkRect *rect, sk_point_t v);
RAIA_API sk_rect_t SkRect_makeInset(SkRect *rect, float dx, float dy);
RAIA_API sk_rect_t SkRect_makeOutset(SkRect *rect, float dx, float dy);
RAIA_API void SkRect_offset(SkRect *rect, float dx, float dy);
RAIA_API void SkRect_offset_2(SkRect *rect, const SkPoint *delta);
RAIA_API void SkRect_offsetTo(SkRect *rect, float newX, float newY);
RAIA_API void SkRect_inset(SkRect *rect, float dx, float dy);
RAIA_API void SkRect_outset(SkRect *rect, float dx, float dy);
RAIA_API bool SkRect_intersect(SkRect *rect, const SkRect *r);
RAIA_API bool SkRect_intersect_2(SkRect *rect, const SkRect *a, const SkRect *b);
RAIA_API bool SkRect_intersects(SkRect *rect, const SkRect *r);
RAIA_API void SkRect_join(SkRect *rect, const SkRect *r);
RAIA_API void SkRect_joinNonEmptyArg(SkRect *rect, const SkRect *r);
RAIA_API void SkRect_joinPossiblyEmptyRect(SkRect *rect, const SkRect *r);
RAIA_API bool SkRect_contains(SkRect *rect, float x, float y);
RAIA_API bool SkRect_contains_2(SkRect *rect, const SkRect *r);
RAIA_API bool SkRect_contains_3(SkRect *rect, const SkIRect *r);
RAIA_API void SkRect_round(SkRect *rect, SkIRect *dst);
RAIA_API void SkRect_roundOut(SkRect *rect, SkIRect *dst);
RAIA_API void SkRect_roundOut_2(SkRect *rect, SkRect *dst);
RAIA_API void SkRect_roundIn(SkRect *rect, SkIRect *dst);
RAIA_API sk_i_rect_t SkRect_round_2(SkRect *rect);
RAIA_API sk_i_rect_t SkRect_roundOut_3(SkRect *rect);
RAIA_API sk_i_rect_t SkRect_roundIn_2(SkRect *rect);
RAIA_API void SkRect_sort(SkRect *rect);
RAIA_API sk_rect_t SkRect_makeSorted(SkRect *rect);
RAIA_API const float * SkRect_asScalars(SkRect *rect);
RAIA_API void SkRect_dump(SkRect *rect, bool asHex);
RAIA_API void SkRect_dump_2(SkRect *rect);
RAIA_API void SkRect_dumpHex(SkRect *rect);
// static
RAIA_API sk_rect_t SkRect_MakeEmpty();
RAIA_API sk_rect_t SkRect_MakeWH(float w, float h);
RAIA_API sk_rect_t SkRect_MakeIWH(int w, int h);
RAIA_API sk_rect_t SkRect_MakeSize(const SkSize *size);
RAIA_API sk_rect_t SkRect_MakeLTRB(float l, float t, float r, float b);
RAIA_API sk_rect_t SkRect_MakeXYWH(float x, float y, float w, float h);
RAIA_API sk_rect_t SkRect_Make(const SkISize *size);
RAIA_API sk_rect_t SkRect_Make_2(const SkIRect *irect);
RAIA_API bool SkRect_Intersects(const SkRect *a, const SkRect *b);
}

#endif //RAIA_SKIA_SK_RECT_H
