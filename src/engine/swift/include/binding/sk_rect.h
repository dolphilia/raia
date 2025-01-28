//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RECT_H
#define RAIA_SKIA_SK_RECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkRect_delete(void *rect); // (SkRect *rect)
bool SkRect_isEmpty(void *rect); // (SkRect *rect) -> bool
bool SkRect_isSorted(void *rect); // (SkRect *rect) -> bool
bool SkRect_isFinite(void *rect); // (SkRect *rect) -> bool
float SkRect_x(void *rect); // (SkRect *rect) -> float
float SkRect_y(void *rect); // (SkRect *rect) -> float
float SkRect_left(void *rect); // (SkRect *rect) -> float
float SkRect_top(void *rect); // (SkRect *rect) -> float
float SkRect_right(void *rect); // (SkRect *rect) -> float
float SkRect_bottom(void *rect); // (SkRect *rect) -> float
float SkRect_width(void *rect); // (SkRect *rect) -> float
float SkRect_height(void *rect); // (SkRect *rect) -> float
float SkRect_centerX(void *rect); // (SkRect *rect) -> float
float SkRect_centerY(void *rect); // (SkRect *rect) -> float
int SkRect_center(void *rect); // (SkRect *rect) -> sk_point_t
void SkRect_toQuad(void *rect, void * quad); // (SkRect *rect, SkPoint quad[4])
void SkRect_setEmpty(void *rect); // (SkRect *rect)
void SkRect_set(void *rect, const void *src); // (SkRect *rect, const SkIRect *src)
void SkRect_setLTRB(void *rect, float left, float top, float right, float bottom); // (SkRect *rect, float left, float top, float right, float bottom)
void SkRect_setBounds(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
bool SkRect_setBoundsCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count) -> bool
void SkRect_setBoundsNoCheck(void *rect, const void * pts, int count); // (SkRect *rect, const SkPoint pts[], int count)
void SkRect_set_2(void *rect, const void *p0, const void *p1); // (SkRect *rect, const SkPoint *p0, const SkPoint *p1)
void SkRect_setXYWH(void *rect, float x, float y, float width, float height); // (SkRect *rect, float x, float y, float width, float height)
void SkRect_setWH(void *rect, float width, float height); // (SkRect *rect, float width, float height)
void SkRect_setIWH(void *rect, int width, int height); // (SkRect *rect, int32_t width, int32_t height)
int SkRect_makeOffset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
int SkRect_makeOffset_2(void *rect, int v); // (SkRect *rect, sk_point_t v) -> sk_rect_t
int SkRect_makeInset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
int SkRect_makeOutset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy) -> sk_rect_t
void SkRect_offset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
void SkRect_offset_2(void *rect, const void *delta); // (SkRect *rect, const SkPoint *delta)
void SkRect_offsetTo(void *rect, float newX, float newY); // (SkRect *rect, float newX, float newY)
void SkRect_inset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
void SkRect_outset(void *rect, float dx, float dy); // (SkRect *rect, float dx, float dy)
bool SkRect_intersect(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
bool SkRect_intersect_2(void *rect, const void *a, const void *b); // (SkRect *rect, const SkRect *a, const SkRect *b) -> bool
bool SkRect_intersects(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
void SkRect_join(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
void SkRect_joinNonEmptyArg(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
void SkRect_joinPossiblyEmptyRect(void *rect, const void *r); // (SkRect *rect, const SkRect *r)
bool SkRect_contains(void *rect, float x, float y); // (SkRect *rect, float x, float y) -> bool
bool SkRect_contains_2(void *rect, const void *r); // (SkRect *rect, const SkRect *r) -> bool
bool SkRect_contains_3(void *rect, const void *r); // (SkRect *rect, const SkIRect *r) -> bool
void SkRect_round(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
void SkRect_roundOut(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
void SkRect_roundOut_2(void *rect, void *dst); // (SkRect *rect, SkRect *dst)
void SkRect_roundIn(void *rect, void *dst); // (SkRect *rect, SkIRect *dst)
int SkRect_round_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
int SkRect_roundOut_3(void *rect); // (SkRect *rect) -> sk_i_rect_t
int SkRect_roundIn_2(void *rect); // (SkRect *rect) -> sk_i_rect_t
void SkRect_sort(void *rect); // (SkRect *rect)
int SkRect_makeSorted(void *rect); // (SkRect *rect) -> sk_rect_t
const float * SkRect_asScalars(void *rect); // (SkRect *rect) -> const float *
void SkRect_dump(void *rect, bool asHex); // (SkRect *rect, bool asHex)
void SkRect_dump_2(void *rect); // (SkRect *rect)
void SkRect_dumpHex(void *rect); // (SkRect *rect)

// static

int SkRect_MakeEmpty(); // () -> sk_rect_t
int SkRect_MakeWH(float w, float h); // (float w, float h) -> sk_rect_t
int SkRect_MakeIWH(int w, int h); // (int w, int h) -> sk_rect_t
int SkRect_MakeSize(const void *size); // (const SkSize *size) -> sk_rect_t
int SkRect_MakeLTRB(float l, float t, float r, float b); // (float l, float t, float r, float b) -> sk_rect_t
int SkRect_MakeXYWH(float x, float y, float w, float h); // (float x, float y, float w, float h) -> sk_rect_t
int SkRect_Make(const void *size); // (const SkISize *size) -> sk_rect_t
int SkRect_Make_2(const void *irect); // (const SkIRect *irect) -> sk_rect_t
bool SkRect_Intersects(const void *a, const void *b); // (const SkRect *a, const SkRect *b) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RECT_H
