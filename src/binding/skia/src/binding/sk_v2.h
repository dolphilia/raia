//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V2_H
#define RAIA_SKIA_SK_V2_H

#include "include/core/SkM44.h"

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
SkScalar SkV2_lengthSquared(SkV2 *v2);
SkScalar SkV2_length(SkV2 *v2);
SkScalar SkV2_dot(SkV2 *v2, SkV2 v);
SkScalar SkV2_cross(SkV2 *v2, SkV2 v);
SkV2 SkV2_normalize(SkV2 *v2);
const float * SkV2_ptr(SkV2 *v2);
float * SkV2_ptr_2(SkV2 *v2);
// static
SkScalar SkV2_Dot(SkV2 a, SkV2 b);
SkScalar SkV2_Cross(SkV2 a, SkV2 b);
SkV2 SkV2_Normalize(SkV2 v);
}

#endif //RAIA_SKIA_SK_V2_H
