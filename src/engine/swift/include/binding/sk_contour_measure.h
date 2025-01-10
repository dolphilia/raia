//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_H

#include "include/core/SkContourMeasure.h"

extern "C" {
void SkContourMeasure_delete(SkContourMeasure *contour_measure);
SkScalar SkContourMeasure_length(SkContourMeasure *contour_measure);
bool SkContourMeasure_getPosTan(SkContourMeasure *contour_measure, SkScalar distance, SkPoint *position, SkVector *tangent);
bool SkContourMeasure_getMatrix(SkContourMeasure *contour_measure, SkScalar distance, SkMatrix *matrix, SkContourMeasure::MatrixFlags flags);
bool SkContourMeasure_getSegment(SkContourMeasure *contour_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo);
bool SkContourMeasure_isClosed(SkContourMeasure *contour_measure);
bool SkContourMeasure_unique(SkContourMeasure *contour_measure);
void SkContourMeasure_ref(SkContourMeasure *contour_measure);
void SkContourMeasure_unref(SkContourMeasure *contour_measure);
}

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_H
