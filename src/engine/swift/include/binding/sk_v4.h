//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V4_H
#define RAIA_SKIA_SK_V4_H

#include "include/core/SkM44.h"
#include "../static/static_sk_v4.h"

extern "C" {
// bool operator==(const SkV4 &v)
// bool operator!=(const SkV4 &v)
// SkV4 operator-()
// SkV4 operator+(const SkV4 &v)
// SkV4 operator-(const SkV4 &v)
// SkV4 operator*(const SkV4 &v)
// float operator[](int i)
// float & operator[](int i)
void SkV4_delete(SkV4 *v4);
SkScalar SkV4_lengthSquared(SkV4 *v4);
SkScalar SkV4_length(SkV4 *v4);
SkScalar SkV4_dot(SkV4 *v4, const SkV4 *v);
sk_v4_t SkV4_normalize(SkV4 *v4);
const float * SkV4_ptr(SkV4 *v4);
float * SkV4_ptr_2(SkV4 *v4);
// static
SkScalar SkV4_Dot(const SkV4 *a, const SkV4 *b);
sk_v4_t SkV4_Normalize(const SkV4 *v);
}

#endif //RAIA_SKIA_SK_V4_H
