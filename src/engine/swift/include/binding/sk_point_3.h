//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_POINT_3_H
#define RAIA_SKIA_SK_POINT_3_H

#include "include/core/SkPoint3.h"
#include "../static/static_sk_point_3.h"

extern "C" {
// SkPoint3 operator-()
// void operator+=(const SkPoint3 &v)
// void operator-=(const SkPoint3 &v)
void SkPoint3_delete(SkPoint3 *point3);
SkScalar SkPoint3_x(SkPoint3 *point3);
SkScalar SkPoint3_y(SkPoint3 *point3);
SkScalar SkPoint3_z(SkPoint3 *point3);
void SkPoint3_set(SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z);
SkScalar SkPoint3_length(SkPoint3 *point3);
bool SkPoint3_normalize(SkPoint3 *point3);
sk_point_3_t SkPoint3_makeScale(SkPoint3 *point3, SkScalar scale);
void SkPoint3_scale(SkPoint3 *point3, SkScalar value);
bool SkPoint3_isFinite(SkPoint3 *point3);
SkScalar SkPoint3_dot(SkPoint3 *point3, const SkPoint3 *vec);
sk_point_3_t SkPoint3_cross(SkPoint3 *point3, const SkPoint3 *vec);
// static
sk_point_3_t SkPoint3_Make(SkScalar x, SkScalar y, SkScalar z);
SkScalar SkPoint3_Length(SkScalar x, SkScalar y, SkScalar z);
SkScalar SkPoint3_DotProduct(const SkPoint3 *a, const SkPoint3 *b);
sk_point_3_t SkPoint3_CrossProduct(const SkPoint3 *a, const SkPoint3 *b);
}

#endif //RAIA_SKIA_SK_POINT_3_H
