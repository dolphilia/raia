//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H

#include "include/core/SkContourMeasure.h"
#include "../static/static_sk_contour_measure.h"
#include "export_api.h"

extern "C" {
RAIA_API SkContourMeasureIter *SkContourMeasureIter_new();
RAIA_API SkContourMeasureIter *SkContourMeasureIter_new_2(const SkPath *path, bool forceClosed, SkScalar resScale);
RAIA_API void SkContourMeasureIter_delete(SkContourMeasureIter *contour_measure_iter);
RAIA_API void SkContourMeasureIter_reset(SkContourMeasureIter *contour_measure_iter, const SkPath *path, bool forceClosed, SkScalar resScale);
RAIA_API sk_contour_measure_t SkContourMeasureIter_next(SkContourMeasureIter *contour_measure_iter);
}

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
