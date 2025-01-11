//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_MEASURE_H
#define RAIA_SKIA_SK_PATH_MEASURE_H

#include "include/core/SkPathMeasure.h"
#include "export_api.h"

extern "C" {
// SkPathMeasure & operator=(SkPathMeasure &&)
RAIA_API SkPathMeasure *SkPathMeasure_new();
RAIA_API SkPathMeasure *SkPathMeasure_new_2(const SkPath *path, bool forceClosed, SkScalar resScale);
RAIA_API void SkPathMeasure_delete(SkPathMeasure *path_measure);
RAIA_API void SkPathMeasure_setPath(SkPathMeasure *path_measure, const SkPath *path, bool forceClosed);
RAIA_API SkScalar SkPathMeasure_getLength(SkPathMeasure *path_measure);
RAIA_API bool SkPathMeasure_getPosTan(SkPathMeasure *path_measure, SkScalar distance, SkPoint *position, SkVector *tangent);
RAIA_API bool SkPathMeasure_getMatrix(SkPathMeasure *path_measure, SkScalar distance, SkMatrix *matrix, SkPathMeasure::MatrixFlags flags);
RAIA_API bool SkPathMeasure_getSegment(SkPathMeasure *path_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo);
RAIA_API bool SkPathMeasure_isClosed(SkPathMeasure *path_measure);
RAIA_API bool SkPathMeasure_nextContour(SkPathMeasure *path_measure);
}

#endif //RAIA_SKIA_SK_PATH_MEASURE_H
