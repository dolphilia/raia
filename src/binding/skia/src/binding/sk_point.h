//
// Created by dolphilia on 2024/01/29.
//

#ifndef RAIA_SKIA_SK_POINT_H
#define RAIA_SKIA_SK_POINT_H

#include "include/core/SkPoint.h"

extern "C" {
void SkPoint_delete(SkPoint *point);
float SkPoint_x(SkPoint point);
float SkPoint_y(SkPoint point);
float SkPoint_dot(SkPoint point, const SkVector *vec);
float SkPoint_length(SkPoint point);
float SkPoint_cross(SkPoint point, const SkVector *vec);
void SkPoint_set(SkPoint point, float x, float y);
bool SkPoint_equals(SkPoint point, float x, float y);
bool SkPoint_isZero(SkPoint point);
void SkPoint_scale(SkPoint point, float value);
void SkPoint_scale_2(SkPoint point, float scale, SkPoint *dst);
bool SkPoint_isFinite(SkPoint point);
float SkPoint_distanceToOrigin(SkPoint point);
void SkPoint_iset(SkPoint point, const SkIPoint *p);
void SkPoint_iset_2(SkPoint point, int32_t x, int32_t y);
void SkPoint_negate(SkPoint point);
void SkPoint_setAbs(SkPoint point, const SkPoint *pt);
bool SkPoint_setLength(SkPoint point, float length);
bool SkPoint_setNormalize(SkPoint point, float x, float y);
// static
SkPoint SkPoint_Make(float x, float y);
float SkPoint_Normalize(SkVector *vec);
float SkPoint_Length(float x, float y);
float SkPoint_CrossProduct(const SkVector *a, const SkVector *b);
float SkPoint_DotProduct(const SkVector *a, const SkVector *b);
float SkPoint_Distance(const SkPoint *a, const SkPoint *b);
void SkPoint_Offset(SkPoint *points, int count, float dx, float dy);
void SkPoint_Offset_2(SkPoint *points, int count, const SkVector *offset);
}

#endif //RAIA_SKIA_SK_POINT_H
