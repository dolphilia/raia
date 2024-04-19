//
// Created by dolphilia on 2024/01/29.
//

#include "sk_point.h"

extern "C" {

void SkPoint_delete(SkPoint *point) {
    delete point;
}

float SkPoint_x(sk_point_t point) {
    return static_sk_point_get(point).x();
}

float SkPoint_y(sk_point_t point) {
    return static_sk_point_get(point).y();
}

float SkPoint_dot(sk_point_t point, const SkVector *vec) {
    return static_sk_point_get(point).dot(*vec);
}

float SkPoint_length(sk_point_t point) {
    return static_sk_point_get(point).length();
}

float SkPoint_cross(sk_point_t point, const SkVector *vec) {
    return static_sk_point_get(point).cross(*vec);
}

void SkPoint_set(sk_point_t point, float x, float y) {
    static_sk_point_get(point).set(x, y);
}

bool SkPoint_equals(sk_point_t point, float x, float y) {
    return static_sk_point_get(point).equals(x, y);
}

bool SkPoint_isZero(sk_point_t point) {
    return static_sk_point_get(point).isZero();
}

void SkPoint_scale(sk_point_t point, float value) {
    static_sk_point_get(point).scale(value);
}

void SkPoint_scale_2(sk_point_t point, float scale, SkPoint *dst) {
    static_sk_point_get(point).scale(scale, dst);
}

bool SkPoint_isFinite(sk_point_t point) {
    return static_sk_point_get(point).isFinite();
}

float SkPoint_distanceToOrigin(sk_point_t point) {
    return static_sk_point_get(point).distanceToOrigin();
}

void SkPoint_iset(sk_point_t point, const SkIPoint *p) {
    static_sk_point_get(point).iset(*p);
}

void SkPoint_iset_2(sk_point_t point, int32_t x, int32_t y) {
    static_sk_point_get(point).iset(x, y);
}

void SkPoint_negate(sk_point_t point) {
    static_sk_point_get(point).negate();
}

void SkPoint_setAbs(sk_point_t point, const SkPoint *pt) {
    static_sk_point_get(point).setAbs(*pt);
}

bool SkPoint_setLength(sk_point_t point, float length) {
    return static_sk_point_get(point).setLength(length);
}

bool SkPoint_setNormalize(sk_point_t point, float x, float y) {
    return static_sk_point_get(point).setNormalize(x, y);
}

// static

sk_point_t SkPoint_Make(float x, float y) {
    return static_sk_point_make(SkPoint::Make(x, y));
}

float SkPoint_Normalize(SkVector *vec) {
    return SkPoint::Normalize(vec);
}

float SkPoint_Length(float x, float y) {
    return SkPoint::Length(x, y);
}

float SkPoint_CrossProduct(const SkVector *a, const SkVector *b) {
    return SkPoint::CrossProduct(*a, *b);
}

float SkPoint_DotProduct(const SkVector *a, const SkVector *b) {
    return SkPoint::DotProduct(*a, *b);
}

float SkPoint_Distance(const SkPoint *a, const SkPoint *b) {
    return SkPoint::Distance(*a, *b);
}

void SkPoint_Offset(SkPoint *points, int count, float dx, float dy) {
    SkPoint::Offset(points, count, dx, dy);
}

void SkPoint_Offset_2(SkPoint *points, int count, const SkVector *offset) {
    SkPoint::Offset(points, count, *offset);
}

}