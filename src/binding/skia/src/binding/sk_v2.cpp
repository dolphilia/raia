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

SkScalar SkV2_dot(SkV2 *v2, sk_v2_t v) {
    return v2->dot(static_sk_v2_get(v));
}

SkScalar SkV2_cross(SkV2 *v2, sk_v2_t v) {
    return v2->cross(static_sk_v2_get(v));
}

sk_v2_t SkV2_normalize(SkV2 *v2) {
    return static_sk_v2_make(v2->normalize());
}

const float * SkV2_ptr(SkV2 *v2) {
    return v2->ptr();
}

float * SkV2_ptr_2(SkV2 *v2) {
    return v2->ptr();
}

// static

SkScalar SkV2_Dot(sk_v2_t a, sk_v2_t b) {
    return SkV2::Dot(static_sk_v2_get(a), static_sk_v2_get(b));
}

SkScalar SkV2_Cross(sk_v2_t a, sk_v2_t b) {
    return SkV2::Cross(static_sk_v2_get(a), static_sk_v2_get(b));
}

sk_v2_t SkV2_Normalize(sk_v2_t v) {
    return static_sk_v2_make(SkV2::Normalize(static_sk_v2_get(v)));
}

}