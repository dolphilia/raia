//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkContourMeasure_delete(void *contour_measure); // (SkContourMeasure *contour_measure)
float SkContourMeasure_length(void *contour_measure); // (SkContourMeasure *contour_measure) -> SkScalar
bool SkContourMeasure_getPosTan(void *contour_measure, float distance, void *position, void *tangent); // (SkContourMeasure *contour_measure, SkScalar distance, SkPoint *position, SkVector *tangent) -> bool
bool SkContourMeasure_getMatrix(void *contour_measure, float distance, void *matrix, int flags); // (SkContourMeasure *contour_measure, SkScalar distance, SkMatrix *matrix, SkContourMeasure::MatrixFlags flags) -> bool
bool SkContourMeasure_getSegment(void *contour_measure, float startD, float stopD, void *dst, bool startWithMoveTo); // (SkContourMeasure *contour_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) -> bool
bool SkContourMeasure_isClosed(void *contour_measure); // (SkContourMeasure *contour_measure) -> bool
bool SkContourMeasure_unique(void *contour_measure); // (SkContourMeasure *contour_measure) -> bool
void SkContourMeasure_ref(void *contour_measure); // (SkContourMeasure *contour_measure)
void SkContourMeasure_unref(void *contour_measure); // (SkContourMeasure *contour_measure)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_H
