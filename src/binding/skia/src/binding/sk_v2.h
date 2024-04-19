//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V2_H
#define RAIA_SKIA_SK_V2_H

#include "include/core/SkM44.h"
#include "../static/static_sk_v2.h"

extern "C" {
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
void SkV2_delete(SkV2 *v2);
SkScalar SkV2_lengthSquared(SkV2 *v2);
SkScalar SkV2_length(SkV2 *v2);
SkScalar SkV2_dot(SkV2 *v2, sk_v2_t v);
SkScalar SkV2_cross(SkV2 *v2, sk_v2_t v);
sk_v2_t SkV2_normalize(SkV2 *v2);
const float * SkV2_ptr(SkV2 *v2);
float * SkV2_ptr_2(SkV2 *v2);
// static
SkScalar SkV2_Dot(sk_v2_t a, sk_v2_t b);
SkScalar SkV2_Cross(sk_v2_t a, sk_v2_t b);
sk_v2_t SkV2_Normalize(sk_v2_t v);
}

#endif //RAIA_SKIA_SK_V2_H
