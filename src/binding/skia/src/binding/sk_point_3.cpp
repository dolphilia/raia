//
// Created by dolphilia on 2024/01/10.
//

#include "sk_point_3.h"

extern "C" {

// SkPoint3 operator-()
// void operator+=(const SkPoint3 &v)
// void operator-=(const SkPoint3 &v)

void SkPoint3_delete(SkPoint3 *point3) {
    delete point3;
}

SkScalar SkPoint3_x(SkPoint3 *point3) {
    return point3->x();
}

SkScalar SkPoint3_y(SkPoint3 *point3) {
    return point3->y();
}

SkScalar SkPoint3_z(SkPoint3 *point3) {
    return point3->z();
}

void SkPoint3_set(SkPoint3 *point3, SkScalar x, SkScalar y, SkScalar z) {
    point3->set(x, y, z);
}

SkScalar SkPoint3_length(SkPoint3 *point3) {
    return point3->length();
}

bool SkPoint3_normalize(SkPoint3 *point3) {
    return point3->normalize();
}

sk_point_3_t SkPoint3_makeScale(SkPoint3 *point3, SkScalar scale) {
    return static_sk_point_3_make(point3->makeScale(scale));
}

void SkPoint3_scale(SkPoint3 *point3, SkScalar value) {
    point3->scale(value);
}

bool SkPoint3_isFinite(SkPoint3 *point3) {
    return point3->isFinite();
}

SkScalar SkPoint3_dot(SkPoint3 *point3, const SkPoint3 *vec) {
    return point3->dot(*vec);
}

sk_point_3_t SkPoint3_cross(SkPoint3 *point3, const SkPoint3 *vec) {
    return static_sk_point_3_make(point3->cross(*vec));
}

// static

sk_point_3_t SkPoint3_Make(SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_point_3_make(SkPoint3::Make(x, y, z));
}

SkScalar SkPoint3_Length(SkScalar x, SkScalar y, SkScalar z) {
    return SkPoint3::Length(x, y, z);
}

SkScalar SkPoint3_DotProduct(const SkPoint3 *a, const SkPoint3 *b) {
    return SkPoint3::DotProduct(*a, *b);
}

sk_point_3_t SkPoint3_CrossProduct(const SkPoint3 *a, const SkPoint3 *b) {
    return static_sk_point_3_make(SkPoint3::CrossProduct(*a, *b));
}

}