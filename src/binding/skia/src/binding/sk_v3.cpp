//
// Created by dolphilia on 2024/01/11.
//

#include "sk_v3.h"

bool SkV3_Equal(const SkV3 &v1, const SkV3 &v2) {
    return v1 == v2;
}

bool SkV3_NotEqual(const SkV3 &v1, const SkV3 &v2) {
    return  v1 != v2;
}

SkV3 SkV3_Minus(const SkV3 &v1, const SkV3 &v2) {
    return v1 - v2;
}

SkV3 SkV3_Plus(const SkV3 &v1, const SkV3 &v2) {
    return v1 + v2;
}

SkV3 SkV3_Star(const SkV3 &v1, const SkV3 &v2) {
    return v1 * v2;
}

void SkV3_PlusAssign(SkV3 &v1, const SkV3 &v2) {
    v1 += v2;
}

void SkV3_MinusAssign(SkV3 &v1, const SkV3 &v2) {
    v1 -= v2;
}

void SkV3_StarAssign(SkV3 &v1, const SkV3 &v2) {
    v1 *= v2;
}

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

void SkV3_delete(SkV3 *v3) {
    delete v3;
}

SkScalar SkV3_lengthSquared(SkV3 *v3) {
    return v3->lengthSquared();
}

SkScalar SkV3_length(SkV3 *v3) {
    return v3->length();
}

SkScalar SkV3_dot(SkV3 *v3, const SkV3 *v) {
    return v3->dot(*v);
}

sk_v3_t SkV3_cross(SkV3 *v3, const SkV3 *v) {
    return static_sk_v3_make(v3->cross(*v));
}

sk_v3_t SkV3_normalize(SkV3 *v3) {
    return static_sk_v3_make(v3->normalize());
}

const float * SkV3_ptr(SkV3 *v3) {
    return v3->ptr();
}

float * SkV3_ptr_2(SkV3 *v3) {
    return v3->ptr();
}

// static

SkScalar SkV3_Dot(const SkV3 *a, const SkV3 *b) {
    return SkV3::Dot(*a, *b);
}

sk_v3_t SkV3_Cross(const SkV3 *a, const SkV3 *b) {
    return static_sk_v3_make(SkV3::Cross(*a, *b));
}

sk_v3_t SkV3_Normalize(const SkV3 *v) {
    return static_sk_v3_make(SkV3::Normalize(*v));
}

}