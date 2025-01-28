//
// Created by dolphilia on 2024/01/29.
//

#ifndef RAIA_SKIA_SK_POINT_H
#define RAIA_SKIA_SK_POINT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkPoint_delete(void *point); // (SkPoint *point)
float SkPoint_x(int point); // (sk_point_t point) -> float
float SkPoint_y(int point); // (sk_point_t point) -> float
float SkPoint_dot(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
float SkPoint_length(int point); // (sk_point_t point) -> float
float SkPoint_cross(int point, const void *vec); // (sk_point_t point, const SkVector *vec) -> float
void SkPoint_set(int point, float x, float y); // (sk_point_t point, float x, float y)
bool SkPoint_equals(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool
bool SkPoint_isZero(int point); // (sk_point_t point) -> bool
void SkPoint_scale(int point, float value); // (sk_point_t point, float value)
void SkPoint_scale_2(int point, float scale, void *dst); // (sk_point_t point, float scale, SkPoint *dst)
bool SkPoint_isFinite(int point); // (sk_point_t point) -> bool
float SkPoint_distanceToOrigin(int point); // (sk_point_t point) -> float
void SkPoint_iset(int point, const void *p); // (sk_point_t point, const SkIPoint *p)
void SkPoint_iset_2(int point, int x, int y); // (sk_point_t point, int32_t x, int32_t y)
void SkPoint_negate(int point); // (sk_point_t point)
void SkPoint_setAbs(int point, const void *pt); // (sk_point_t point, const SkPoint *pt)
bool SkPoint_setLength(int point, float length); // (sk_point_t point, float length) -> bool
bool SkPoint_setNormalize(int point, float x, float y); // (sk_point_t point, float x, float y) -> bool

// static

int SkPoint_Make(float x, float y); // (float x, float y) -> sk_point_t
float SkPoint_Normalize(void *vec); // (SkVector *vec) -> float
float SkPoint_Length(float x, float y); // (float x, float y) -> float
float SkPoint_CrossProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
float SkPoint_DotProduct(const void *a, const void *b); // (const SkVector *a, const SkVector *b) -> float
float SkPoint_Distance(const void *a, const void *b); // (const SkPoint *a, const SkPoint *b) -> float
void SkPoint_Offset(void *points, int count, float dx, float dy); // (SkPoint *points, int count, float dx, float dy)
void SkPoint_Offset_2(void *points, int count, const void *offset); // (SkPoint *points, int count, const SkVector *offset)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_POINT_H
