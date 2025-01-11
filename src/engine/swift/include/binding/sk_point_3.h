//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_POINT_3_H
#define RAIA_SKIA_SK_POINT_3_H

#include "include/core/SkPoint3.h"
#include "../static/static_sk_point_3.h"
#include "export_api.h"

extern "C" {
// SkPoint3 operator-()
// void operator+=(const SkPoint3 &v)
// void operator-=(const SkPoint3 &v)
RAIA_API void SkPoint3_delete(SkPoint3 *point3);
RAIA_API SkScalar SkPoint3_x(SkPoint3 *point3);
RAIA_API SkScalar SkPoint3_y(SkPoint3 *point3);
RAIA_API SkScalar SkPoint3_z(SkPoint3 *point3);
RAIA_API void SkPoint3_set(SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z);
RAIA_API SkScalar SkPoint3_length(SkPoint3 *point3);
RAIA_API bool SkPoint3_normalize(SkPoint3 *point3);
RAIA_API sk_point_3_t SkPoint3_makeScale(SkPoint3 *point3, SkScalar scale);
RAIA_API void SkPoint3_scale(SkPoint3 *point3, SkScalar value);
RAIA_API bool SkPoint3_isFinite(SkPoint3 *point3);
RAIA_API SkScalar SkPoint3_dot(SkPoint3 *point3, const SkPoint3 *vec);
RAIA_API sk_point_3_t SkPoint3_cross(SkPoint3 *point3, const SkPoint3 *vec);
// static
RAIA_API sk_point_3_t SkPoint3_Make(SkScalar x, SkScalar y, SkScalar z);
RAIA_API SkScalar SkPoint3_Length(SkScalar x, SkScalar y, SkScalar z);
RAIA_API SkScalar SkPoint3_DotProduct(const SkPoint3 *a, const SkPoint3 *b);
RAIA_API sk_point_3_t SkPoint3_CrossProduct(const SkPoint3 *a, const SkPoint3 *b);
}

#endif //RAIA_SKIA_SK_POINT_3_H
