//
// Created by dolphilia on 2024/01/08.
//

#include "sk_contour_measure.h"

extern "C" {

void SkContourMeasure_delete(SkContourMeasure *contour_measure) {
    delete &contour_measure;
}

SkScalar SkContourMeasure_length(SkContourMeasure *contour_measure) {
    return contour_measure->length();
}

bool SkContourMeasure_getPosTan(SkContourMeasure *contour_measure, SkScalar distance, SkPoint *position, SkVector *tangent) {
    return contour_measure->getPosTan(distance, position, tangent);
}

bool SkContourMeasure_getMatrix(SkContourMeasure *contour_measure, SkScalar distance, SkMatrix *matrix, SkContourMeasure::MatrixFlags flags) {
    return contour_measure->getMatrix(distance, matrix, flags);
}

bool SkContourMeasure_getSegment(SkContourMeasure *contour_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) {
    return contour_measure->getSegment(startD, stopD, dst, startWithMoveTo);
}

bool SkContourMeasure_isClosed(SkContourMeasure *contour_measure) {
    return contour_measure->isClosed();
}

bool SkContourMeasure_unique(SkContourMeasure *contour_measure) {
    return contour_measure->unique();
}

void SkContourMeasure_ref(SkContourMeasure *contour_measure) {
    contour_measure->ref();
}

void SkContourMeasure_unref(SkContourMeasure *contour_measure) {
    contour_measure->unref();
}

}