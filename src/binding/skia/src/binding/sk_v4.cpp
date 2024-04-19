//
// Created by dolphilia on 2024/01/11.
//

#include "sk_v4.h"

extern "C" {

// bool operator==(const SkV4 &v)
// bool operator!=(const SkV4 &v)
// SkV4 operator-()
// SkV4 operator+(const SkV4 &v)
// SkV4 operator-(const SkV4 &v)
// SkV4 operator*(const SkV4 &v)
// float operator[](int i)
// float & operator[](int i)

void SkV4_delete(SkV4 *v4) {
    delete v4;
}

SkScalar SkV4_lengthSquared(SkV4 *v4) {
    return v4->lengthSquared();
}

SkScalar SkV4_length(SkV4 *v4) {
    return v4->length();
}

SkScalar SkV4_dot(SkV4 *v4, const SkV4 *v) {
    return v4->dot(*v);
}

sk_v4_t SkV4_normalize(SkV4 *v4) {
    return static_sk_v4_make(v4->normalize());
}

const float * SkV4_ptr(SkV4 *v4) {
    return v4->ptr();
}

float * SkV4_ptr_2(SkV4 *v4) {
    return v4->ptr();
}

// static

SkScalar SkV4_Dot(const SkV4 *a, const SkV4 *b) {
    return SkV4::Dot(*a, *b);
}

sk_v4_t SkV4_Normalize(const SkV4 *v) {
    return static_sk_v4_make(SkV4::Normalize(*v));
}

}