//
// Created by dolphilia on 25/01/29.
//

#ifndef SK_I_POINT_H
#define SK_I_POINT_H

#ifdef __cplusplus
extern "C" {
#endif

// SkIPoint operator-()
// void operator+=(const SkIVector& v)
// void operator-=(const SkIVector& v)

void SkIPoint_delete(void * i_point); // ()
int SkIPoint_x(void * i_point); // () -> int32_t
int SkIPoint_y(void * i_point); // () -> int32_t
bool SkIPoint_isZero(void * i_point); // () -> bool
void SkIPoint_set(void * i_point, int x, int y); // (int32_t x, int32_t y)
bool SkIPoint_equals(void * i_point, int x, int y); // (int32_t x, int32_t y)

// static

int SkIPoint_Make(int x, int y); // (int x, int y) -> sk_i_point_t

#ifdef __cplusplus
}
#endif

#endif //SK_I_POINT_H
