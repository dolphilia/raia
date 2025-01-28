//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_POINT_3_H
#define RAIA_SKIA_SK_POINT_3_H

#ifdef __cplusplus
extern "C" {
#endif

// SkPoint3 operator-()
// void operator+=(const SkPoint3 &v)
// void operator-=(const SkPoint3 &v)
void SkPoint3_delete(void *point3); // (SkPoint3 *point3)
float SkPoint3_x(void *point3); // (SkPoint3 *point3) -> SkScalar
float SkPoint3_y(void *point3); // (SkPoint3 *point3) -> SkScalar
float SkPoint3_z(void *point3); // (SkPoint3 *point3) -> SkScalar
void SkPoint3_set(void *point3, float x, float y, float z); // (SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z)
float SkPoint3_length(void *point3); // (SkPoint3 *point3) -> SkScalar
bool SkPoint3_normalize(void *point3); // (SkPoint3 *point3) -> bool
int SkPoint3_makeScale(void *point3, float scale); // (SkPoint3 *point3, SkScalar scale) -> sk_point_3_t
void SkPoint3_scale(void *point3, float value); // (SkPoint3 *point3, SkScalar value)
bool SkPoint3_isFinite(void *point3); // (SkPoint3 *point3) -> bool
float SkPoint3_dot(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> SkScalar
int SkPoint3_cross(void *point3, const void *vec); // (SkPoint3 *point3, const SkPoint3 *vec) -> sk_point_3_t

// static

int SkPoint3_Make(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_point_3_t
float SkPoint3_Length(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> SkScalar
float SkPoint3_DotProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> SkScalar
int SkPoint3_CrossProduct(const void *a, const void *b); // (const SkPoint3 *a, const SkPoint3 *b) -> sk_point_3_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_POINT_3_H
