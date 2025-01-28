//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
#define RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkContourMeasureIter_new(); // () -> SkContourMeasureIter *
void *SkContourMeasureIter_new_2(const void *path, bool forceClosed, float resScale); // (const SkPath *path, bool forceClosed, SkScalar resScale) -> SkContourMeasureIter *
void SkContourMeasureIter_delete(void *contour_measure_iter); // (SkContourMeasureIter *contour_measure_iter)
void SkContourMeasureIter_reset(void *contour_measure_iter, const void *path, bool forceClosed, float resScale); // (SkContourMeasureIter *contour_measure_iter, const SkPath *path, bool forceClosed, SkScalar resScale)
int SkContourMeasureIter_next(void *contour_measure_iter); // (SkContourMeasureIter *contour_measure_iter) -> sk_contour_measure_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CONTOUR_MEASURE_ITER_H
