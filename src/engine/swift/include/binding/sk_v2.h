//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V2_H
#define RAIA_SKIA_SK_V2_H

#ifdef __cplusplus
extern "C" {
#endif

// bool operator==(const SkV2 v)
// bool operator!=(const SkV2 v)
// SkV2 operator-()
// SkV2 operator+(SkV2 v)
// SkV2 operator-(SkV2 v)
// SkV2 operator*(SkV2 v)
// void operator+=(SkV2 v)
// void operator-=(SkV2 v)
// void operator*=(SkV2 v)
// void operator*=(SkScalar s)
// void operator/=(SkScalar s)

void SkV2_delete(void *v2); // (SkV2 *v2)
float SkV2_lengthSquared(void *v2); // (SkV2 *v2) -> SkScalar
float SkV2_length(void *v2); // (SkV2 *v2) -> SkScalar
float SkV2_dot(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar
float SkV2_cross(void *v2, int v); // (SkV2 *v2, sk_v2_t v) -> SkScalar
int SkV2_normalize(void *v2); // (SkV2 *v2) -> sk_v2_t
const void * SkV2_ptr(void *v2); // (SkV2 *v2) -> const float *
float * SkV2_ptr_2(void *v2); // (SkV2 *v2) -> float *

// static

float SkV2_Dot(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar
float SkV2_Cross(int a, int b); // (sk_v2_t a, sk_v2_t b) -> SkScalar
int SkV2_Normalize(int v); // (sk_v2_t v) -> sk_v2_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_V2_H
