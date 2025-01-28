//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V4_H
#define RAIA_SKIA_SK_V4_H

#ifdef __cplusplus
extern "C" {
#endif

// bool operator==(const SkV4 &v)
// bool operator!=(const SkV4 &v)
// SkV4 operator-()
// SkV4 operator+(const SkV4 &v)
// SkV4 operator-(const SkV4 &v)
// SkV4 operator*(const SkV4 &v)
// float operator[](int i)
// float & operator[](int i)

void SkV4_delete(void *v4); // (SkV4 *v4)
float SkV4_lengthSquared(void *v4); // (SkV4 *v4) -> SkScalar
float SkV4_length(void *v4); // (SkV4 *v4) -> SkScalar
float SkV4_dot(void *v4, const void *v); // (SkV4 *v4, const SkV4 *v) -> SkScalar
int SkV4_normalize(void *v4); // (SkV4 *v4) -> sk_v4_t
const void * SkV4_ptr(void *v4); // (SkV4 *v4) -> const float *
float * SkV4_ptr_2(void *v4); // (SkV4 *v4) -> float *

// static

float SkV4_Dot(const void *a, const void *b); // (const SkV4 *a, const SkV4 *b) -> SkScalar
int SkV4_Normalize(const void *v); // (const SkV4 *v) -> sk_v4_t

#ifdef __cplusplus
}
#endif


#endif //RAIA_SKIA_SK_V4_H
