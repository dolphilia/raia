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

void SkContourMeasureIter_next(const char* sk_contour_measure_key_out, SkContourMeasureIter *contour_measure_iter) {
    static_sk_contour_measure_set(sk_contour_measure_key_out, contour_measure_iter->next());
}

}