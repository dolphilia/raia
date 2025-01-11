//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_V3_H
#define RAIA_SKIA_SK_V3_H

#include "include/core/SkM44.h"
#include "../static/static_sk_v3.h"
#include "export_api.h"

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
RAIA_API void SkV3_delete(SkV3 *v3);
RAIA_API SkScalar SkV3_lengthSquared(SkV3 *v3);
RAIA_API SkScalar SkV3_length(SkV3 *v3);
RAIA_API SkScalar SkV3_dot(SkV3 *v3, const SkV3 *v);
RAIA_API sk_v3_t SkV3_cross(SkV3 *v3, const SkV3 *v);
RAIA_API sk_v3_t SkV3_normalize(SkV3 *v3);
RAIA_API const float * SkV3_ptr(SkV3 *v3);
RAIA_API float * SkV3_ptr_2(SkV3 *v3);
// static
RAIA_API SkScalar SkV3_Dot(const SkV3 *a, const SkV3 *b);
RAIA_API sk_v3_t SkV3_Cross(const SkV3 *a, const SkV3 *b);
RAIA_API sk_v3_t SkV3_Normalize(const SkV3 *v);
}

#endif //RAIA_SKIA_SK_V3_H
