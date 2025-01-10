//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_MEASURE_H
#define RAIA_SKIA_SK_PATH_MEASURE_H

#include "include/core/SkPathMeasure.h"

extern "C" {
// SkPathMeasure & operator=(SkPathMeasure &&)
SkPathMeasure *SkPathMeasure_new();
SkPathMeasure *SkPathMeasure_new_2(const SkPath *path, bool forceClosed, SkScalar resScale);
void SkPathMeasure_delete(SkPathMeasure *path_measure);
void SkPathMeasure_setPath(SkPathMeasure *path_measure, const SkPath *path, bool forceClosed);
SkScalar SkPathMeasure_getLength(SkPathMeasure *path_measure);
bool SkPathMeasure_getPosTan(SkPathMeasure *path_measure, SkScalar distance, SkPoint *position, SkVector *tangent);
bool SkPathMeasure_getMatrix(SkPathMeasure *path_measure, SkScalar distance, SkMatrix *matrix, SkPathMeasure::MatrixFlags flags);
bool SkPathMeasure_getSegment(SkPathMeasure *path_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo);
bool SkPathMeasure_isClosed(SkPathMeasure *path_measure);
bool SkPathMeasure_nextContour(SkPathMeasure *path_measure);
}

#endif //RAIA_SKIA_SK_PATH_MEASURE_H
