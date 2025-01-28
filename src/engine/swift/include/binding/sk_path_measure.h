//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PATH_MEASURE_H
#define RAIA_SKIA_SK_PATH_MEASURE_H

#ifdef __cplusplus
extern "C" {
#endif

// SkPathMeasure & operator=(SkPathMeasure &&)

void *SkPathMeasure_new(); // () -> SkPathMeasure *
void *SkPathMeasure_new_2(const void *path, bool forceClosed, float resScale); // (const SkPath *path, bool forceClosed, SkScalar resScale) -> SkPathMeasure *
void SkPathMeasure_delete(void *path_measure); // (SkPathMeasure *path_measure)
void SkPathMeasure_setPath(void *path_measure, const void *path, bool forceClosed); // (SkPathMeasure *path_measure, const SkPath *path, bool forceClosed)
float SkPathMeasure_getLength(void *path_measure); // (SkPathMeasure *path_measure) -> SkScalar
bool SkPathMeasure_getPosTan(void *path_measure, float distance, void *position, void *tangent); // (SkPathMeasure *path_measure, SkScalar distance, SkPoint *position, SkVector *tangent) -> bool
bool SkPathMeasure_getMatrix(void *path_measure, float distance, void *matrix, int flags); // (SkPathMeasure *path_measure, SkScalar distance, SkMatrix *matrix, SkPathMeasure::MatrixFlags flags) -> bool
bool SkPathMeasure_getSegment(void *path_measure, float startD, float stopD, void *dst, bool startWithMoveTo); // (SkPathMeasure *path_measure, SkScalar startD, SkScalar stopD, SkPath *dst, bool startWithMoveTo) -> bool
bool SkPathMeasure_isClosed(void *path_measure); // (SkPathMeasure *path_measure) -> bool
bool SkPathMeasure_nextContour(void *path_measure); // (SkPathMeasure *path_measure) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_MEASURE_H
