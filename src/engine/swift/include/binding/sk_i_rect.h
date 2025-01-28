//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_I_RECT_H
#define RAIA_SKIA_SK_I_RECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkIRect_delete(void *i_rect); // (SkIRect *i_rect)
int SkIRect_left(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_top(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_right(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_bottom(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_x(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_y(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_topLeft(void *i_rect); // (SkIRect *i_rect) -> sk_i_point_t
int SkIRect_width(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_height(void *i_rect); // (SkIRect *i_rect) -> int32_t
int SkIRect_size(void *i_rect); // (SkIRect *i_rect) -> sk_i_size_t
long long SkIRect_width64(void *i_rect); // (SkIRect *i_rect) -> int64_t
long long SkIRect_height64(void *i_rect); // (SkIRect *i_rect) -> int64_t
bool SkIRect_isEmpty64(void *i_rect); // (SkIRect *i_rect) -> bool
bool SkIRect_isEmpty(void *i_rect); // (SkIRect *i_rect) -> bool
void SkIRect_setEmpty(void *i_rect); // (SkIRect *i_rect)
void SkIRect_setLTRB(void *i_rect, int left, int top, int right, int bottom); // (SkIRect *i_rect, int32_t left, int32_t top, int32_t right, int32_t bottom)
void SkIRect_setXYWH(void *i_rect, int x, int y, int width, int height); // (SkIRect *i_rect, int32_t x, int32_t y, int32_t width, int32_t height)
void SkIRect_setWH(void *i_rect, int width, int height); // (SkIRect *i_rect, int32_t width, int32_t height)
void SkIRect_setSize(void *i_rect, int size); // (SkIRect *i_rect, sk_i_size_t size)
int SkIRect_makeOffset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
int SkIRect_makeOffset_2(void *i_rect, int offset); // (SkIRect *i_rect, sk_i_point_t offset) -> sk_i_rect_t
int SkIRect_makeInset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
int SkIRect_makeOutset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy) -> sk_i_rect_t
void SkIRect_offset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
void SkIRect_offset_2(void *i_rect, const void *delta); // (SkIRect *i_rect, const SkIPoint *delta)
void SkIRect_offsetTo(void *i_rect, int newX, int newY); // (SkIRect *i_rect, int32_t newX, int32_t newY)
void SkIRect_inset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
void SkIRect_outset(void *i_rect, int dx, int dy); // (SkIRect *i_rect, int32_t dx, int32_t dy)
void SkIRect_adjust(void *i_rect, int dL, int dT, int dR, int dB); // (SkIRect *i_rect, int32_t dL, int32_t dT, int32_t dR, int32_t dB)
bool SkIRect_contains(void *i_rect, int x, int y); // (SkIRect *i_rect, int32_t x, int32_t y) -> bool
bool SkIRect_contains_2(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
bool SkIRect_contains_3(void *i_rect, const void *r); // (SkIRect *i_rect, const SkRect *r) -> bool
bool SkIRect_containsNoEmptyCheck(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
bool SkIRect_intersect(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r) -> bool
bool SkIRect_intersect_2(void *i_rect, const void *a, const void *b); // (SkIRect *i_rect, const SkIRect *a, const SkIRect *b) -> bool
void SkIRect_join(void *i_rect, const void *r); // (SkIRect *i_rect, const SkIRect *r)
void SkIRect_sort(void *i_rect); // (SkIRect *i_rect)
int SkIRect_makeSorted(void *i_rect); // (SkIRect *i_rect) -> sk_i_rect_t

// static

int SkIRect_MakeEmpty(); // () -> sk_i_rect_t
int SkIRect_MakeWH(int w, int h); // (int32_t w, int32_t h) -> sk_i_rect_t
int SkIRect_MakeSize(const void *size); // (const SkISize *size) -> sk_i_rect_t
int SkIRect_MakePtSize(int pt, int size); // (sk_i_point_t pt, sk_i_size_t size) -> sk_i_rect_t
int SkIRect_MakeLTRB(int l, int t, int r, int b); // (int32_t l, int32_t t, int32_t r, int32_t b) -> sk_i_rect_t
int SkIRect_MakeXYWH(int x, int y, int w, int h); // (int32_t x, int32_t y, int32_t w, int32_t h) -> sk_i_rect_t
bool SkIRect_Intersects(const void *a, const void *b); // (const SkIRect *a, const SkIRect *b) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_I_RECT_H
