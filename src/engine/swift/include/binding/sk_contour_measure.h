//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_H

#include "include/core/SkContourMeasure.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkContourMeasure_delete(SkContourMeasure *contour_measure);
RAIA_API SkScalar SkContourMeasure_length(SkContourMeasure *contour_measure);
RAIA_API bool SkContourMeasure_getPosTan(SkContourMeasure *contour_measure, SkScalar distance, SkPoint *position, SkVector *tangent);
RAIA_API bool SkContourMeasure_getMatrix(SkContourMeasure *contour_measure, SkScalar distance, SkMatrix *matrix, SkContourMeasure::MatrixFlags flags);
RAIA_API bool SkContourMeasure_getSegment(SkContourMeasure *contour_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo);
RAIA_API bool SkContourMeasure_isClosed(SkContourMeasure *contour_measure);
RAIA_API bool SkContourMeasure_unique(SkContourMeasure *contour_measure);
RAIA_API void SkContourMeasure_ref(SkContourMeasure *contour_measure);
RAIA_API void SkContourMeasure_unref(SkContourMeasure *contour_measure);
}

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_H
