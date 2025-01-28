//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V3_H
#define RAIA_SKIA_SK_V3_H

#ifdef __cplusplus
extern "C" {
#endif

// bool operator==(const SkV3 &v)
// bool operator!=(const SkV3 &v)
// SkV3 operator-()
// SkV3 operator+(const SkV3 &v)
// SkV3 operator-(const SkV3 &v)
// SkV3 operator*(const SkV3 &v)
// void operator+=(SkV3 v)
// void operator-=(SkV3 v)
// void operator*=(SkV3 v)
// void operator*=(SkScalar s)

void SkV3_delete(void *v3); // (SkV3 *v3)
float SkV3_lengthSquared(void *v3); // (SkV3 *v3) -> SkScalar
float SkV3_length(void *v3); // (SkV3 *v3) -> SkScalar
float SkV3_dot(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> SkScalar
int SkV3_cross(void *v3, const void *v); // (SkV3 *v3, const SkV3 *v) -> sk_v3_t
int SkV3_normalize(void *v3); // (SkV3 *v3) -> sk_v3_t
const void * SkV3_ptr(void *v3); // (SkV3 *v3) -> const float *
float * SkV3_ptr_2(void *v3); // (SkV3 *v3) -> float *

// static

float SkV3_Dot(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> SkScalar
int SkV3_Cross(const void *a, const void *b); // (const SkV3 *a, const SkV3 *b) -> sk_v3_t
int SkV3_Normalize(const void *v); // (const SkV3 *v) -> sk_v3_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_V3_H
