//
// Created by dolphilia on 2024/01/11.
//

#include "sk_v3.h"

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

SkScalar SkV3_lengthSquared(SkV3 *v3) {
    return v3->lengthSquared();
}

SkScalar SkV3_length(SkV3 *v3) {
    return v3->length();
}

SkScalar SkV3_dot(SkV3 *v3, const SkV3 &v) {
    return v3->dot(v);
}

SkV3 SkV3_cross(SkV3 *v3, const SkV3 &v) {
    return v3->cross(v);
}

SkV3 SkV3_normalize(SkV3 *v3) {
    return v3->normalize();
}

const float * SkV3_ptr(SkV3 *v3) {
    return v3->ptr();
}

float * SkV3_ptr_2(SkV3 *v3) {
    return v3->ptr();
}

// static

SkScalar SkV3_Dot(const SkV3 &a, const SkV3 &b) {
    return SkV3::Dot(a, b);
}

SkV3 SkV3_Cross(const SkV3 &a, const SkV3 &b) {
    return SkV3::Cross(a, b);
}

SkV3 SkV3_Normalize(const SkV3 &v) {
    return SkV3::Normalize(v);
}

}