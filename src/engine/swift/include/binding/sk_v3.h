//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V3_H
#define RAIA_SKIA_SK_V3_H

#include "include/core/SkM44.h"
#include "../static/static_sk_v3.h"

extern "C" {
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
void SkV3_delete(SkV3 *v3);
SkScalar SkV3_lengthSquared(SkV3 *v3);
SkScalar SkV3_length(SkV3 *v3);
SkScalar SkV3_dot(SkV3 *v3, const SkV3 *v);
sk_v3_t SkV3_cross(SkV3 *v3, const SkV3 *v);
sk_v3_t SkV3_normalize(SkV3 *v3);
const float * SkV3_ptr(SkV3 *v3);
float * SkV3_ptr_2(SkV3 *v3);
// static
SkScalar SkV3_Dot(const SkV3 *a, const SkV3 *b);
sk_v3_t SkV3_Cross(const SkV3 *a, const SkV3 *b);
sk_v3_t SkV3_Normalize(const SkV3 *v);
}

#endif //RAIA_SKIA_SK_V3_H
