//
// Created by dolphilia on 2024/01/08.
//

#include "sk_contour_measure_iter.h"

extern "C" {

SkContourMeasureIter *SkContourMeasureIter_new() {
    return new SkContourMeasureIter();
}

SkContourMeasureIter *SkContourMeasureIter_new_2(const SkPath *path, bool forceClosed, SkScalar resScale) {
    return new SkContourMeasureIter(*path, forceClosed, resScale);
}

void SkContourMeasureIter_delete(SkContourMeasureIter *contour_measure_iter) {
    delete contour_measure_iter;
}

void SkContourMeasureIter_reset(SkContourMeasureIter *contour_measure_iter, const SkPath *path, bool forceClosed, SkScalar resScale) {
    contour_measure_iter->reset(*path, forceClosed, resScale);
}

sk_contour_measure_t SkContourMeasureIter_next(SkContourMeasureIter *contour_measure_iter) {
    return static_sk_contour_measure_make(contour_measure_iter->next());
}

}