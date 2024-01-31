//
// Created by dolphilia on 2024/01/29.
//

#include "sk_point.h"

extern "C" {

void SkPoint_delete(SkPoint *point) {
    delete point;
}

float SkPoint_x(SkPoint point) {
    return point.x();
}

float SkPoint_y(SkPoint point) {
    return point.y();
}

float SkPoint_dot(SkPoint point, const SkVector *vec) {
    return point.dot(*vec);
}

float SkPoint_length(SkPoint point) {
    return point.length();
}

float SkPoint_cross(SkPoint point, const SkVector *vec) {
    return point.cross(*vec);
}

void SkPoint_set(SkPoint point, float x, float y) {
    point.set(x, y);
}

bool SkPoint_equals(SkPoint point, float x, float y) {
    return point.equals(x, y);
}

bool SkPoint_isZero(SkPoint point) {
    return point.isZero();
}

void SkPoint_scale(SkPoint point, float value) {
    point.scale(value);
}

void SkPoint_scale_2(SkPoint point, float scale, SkPoint *dst) {
    point.scale(scale, dst);
}

bool SkPoint_isFinite(SkPoint point) {
    return point.isFinite();
}

float SkPoint_distanceToOrigin(SkPoint point) {
    return point.distanceToOrigin();
}

void SkPoint_iset(SkPoint point, const SkIPoint *p) {
    point.iset(*p);
}

void SkPoint_iset_2(SkPoint point, int32_t x, int32_t y) {
    point.iset(x, y);
}

void SkPoint_negate(SkPoint point) {
    point.negate();
}

void SkPoint_setAbs(SkPoint point, const SkPoint *pt) {
    point.setAbs(*pt);
}

bool SkPoint_setLength(SkPoint point, float length) {
    return point.setLength(length);
}

bool SkPoint_setNormalize(SkPoint point, float x, float y) {
    return point.setNormalize(x, y);
}

// static

SkPoint SkPoint_Make(float x, float y) {
    return SkPoint::Make(x, y);
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