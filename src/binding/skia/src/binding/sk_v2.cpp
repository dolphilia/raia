//
// Created by dolphilia on 2024/01/11.
//

#include "sk_v2.h"

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

void SkV2_delete(SkV2 *v2) {
    delete v2;
}

SkScalar SkV2_lengthSquared(SkV2 *v2) {
    return v2->lengthSquared();
}

SkScalar SkV2_length(SkV2 *v2) {
    return v2->length();
}

SkScalar SkV2_dot(SkV2 *v2, SkV2 v) {
    return v2->dot(v);
}

SkScalar SkV2_cross(SkV2 *v2, SkV2 v) {
    return v2->cross(v);
}

SkV2 SkV2_normalize(SkV2 *v2) {
    return v2->normalize();
}

const float * SkV2_ptr(SkV2 *v2) {
    return v2->ptr();
}

float * SkV2_ptr_2(SkV2 *v2) {
    return v2->ptr();
}

// static

SkScalar SkV2_Dot(SkV2 a, SkV2 b) {
    return SkV2::Dot(a, b);
}

SkScalar SkV2_Cross(SkV2 a, SkV2 b) {
    return SkV2::Cross(a, b);
}

SkV2 SkV2_Normalize(SkV2 v) {
    return SkV2::Normalize(v);
}

}