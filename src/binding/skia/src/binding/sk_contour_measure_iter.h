//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H

#include "include/core/SkContourMeasure.h"
#include "../static/static_sk_contour_measure.h"

extern "C" {
SkContourMeasureIter *SkContourMeasureIter_new();
SkContourMeasureIter *SkContourMeasureIter_new_2(const SkPath *path, bool forceClosed, SkScalar resScale);
void SkContourMeasureIter_delete(SkContourMeasureIter *contour_measure_iter);
void SkContourMeasureIter_reset(SkContourMeasureIter *contour_measure_iter, const SkPath *path, bool forceClosed, SkScalar resScale);
void SkContourMeasureIter_next(const char* sk_contour_measure_key_out, SkContourMeasureIter *contour_measure_iter);
}

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
