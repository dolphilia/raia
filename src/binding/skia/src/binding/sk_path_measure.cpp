//
// Created by dolphilia on 2024/01/10.
//

#include "sk_path_measure.h"

extern "C" {

// SkPathMeasure & operator=(SkPathMeasure &&)

SkPathMeasure *SkPathMeasure_new() {
    return new SkPathMeasure();
}

SkPathMeasure *SkPathMeasure_new_2(const SkPath *path, bool forceClosed, SkScalar resScale) {
    return new SkPathMeasure(*path, forceClosed, resScale);
}

void SkPathMeasure_delete(SkPathMeasure *path_measure) {
    delete path_measure;
}

void SkPathMeasure_setPath(SkPathMeasure *path_measure, const SkPath *path, bool forceClosed) {
    path_measure->setPath(path, forceClosed);
}

SkScalar SkPathMeasure_getLength(SkPathMeasure *path_measure) {
    return path_measure->getLength();
}

bool SkPathMeasure_getPosTan(SkPathMeasure *path_measure, SkScalar distance, SkPoint *position, SkVector *tangent) {
    return path_measure->getPosTan(distance, position, tangent);
}

bool SkPathMeasure_getMatrix(SkPathMeasure *path_measure, SkScalar distance, SkMatrix *matrix, SkPathMeasure::MatrixFlags flags) {
    return path_measure->getMatrix(distance, matrix, flags);
}

bool SkPathMeasure_getSegment(SkPathMeasure *path_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) {
    return path_measure->getSegment(startD, stopD, dst, startWithMoveTo);
}

bool SkPathMeasure_isClosed(SkPathMeasure *path_measure) {
    return path_measure->isClosed();
}

bool SkPathMeasure_nextContour(SkPathMeasure *path_measure) {
    return path_measure->nextContour();
}

}