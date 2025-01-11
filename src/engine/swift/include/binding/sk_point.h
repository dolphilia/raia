//
// Created by dolphilia on 2024/01/29.
//

#ifndef RAIA_SKIA_SK_POINT_H
#define RAIA_SKIA_SK_POINT_H

#include "include/core/SkPoint.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkPoint_delete(SkPoint *point);
RAIA_API float SkPoint_x(sk_point_t point);
RAIA_API float SkPoint_y(sk_point_t point);
RAIA_API float SkPoint_dot(sk_point_t point, const SkVector *vec);
RAIA_API float SkPoint_length(sk_point_t point);
RAIA_API float SkPoint_cross(sk_point_t point, const SkVector *vec);
RAIA_API void SkPoint_set(sk_point_t point, float x, float y);
RAIA_API bool SkPoint_equals(sk_point_t point, float x, float y);
RAIA_API bool SkPoint_isZero(sk_point_t point);
RAIA_API void SkPoint_scale(sk_point_t point, float value);
RAIA_API void SkPoint_scale_2(sk_point_t point, float scale, SkPoint *dst);
RAIA_API bool SkPoint_isFinite(sk_point_t point);
RAIA_API float SkPoint_distanceToOrigin(sk_point_t point);
RAIA_API void SkPoint_iset(sk_point_t point, const SkIPoint *p);
RAIA_API void SkPoint_iset_2(sk_point_t point, int32_t x, int32_t y);
RAIA_API void SkPoint_negate(sk_point_t point);
RAIA_API void SkPoint_setAbs(sk_point_t point, const SkPoint *pt);
RAIA_API bool SkPoint_setLength(sk_point_t point, float length);
RAIA_API bool SkPoint_setNormalize(sk_point_t point, float x, float y);
// static
RAIA_API sk_point_t SkPoint_Make(float x, float y);
RAIA_API float SkPoint_Normalize(SkVector *vec);
RAIA_API float SkPoint_Length(float x, float y);
RAIA_API float SkPoint_CrossProduct(const SkVector *a, const SkVector *b);
RAIA_API float SkPoint_DotProduct(const SkVector *a, const SkVector *b);
RAIA_API float SkPoint_Distance(const SkPoint *a, const SkPoint *b);
RAIA_API void SkPoint_Offset(SkPoint *points, int count, float dx, float dy);
RAIA_API void SkPoint_Offset_2(SkPoint *points, int count, const SkVector *offset);
}

#endif //RAIA_SKIA_SK_POINT_H
