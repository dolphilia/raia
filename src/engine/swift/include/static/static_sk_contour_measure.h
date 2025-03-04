//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_contour_measure_t;
void static_sk_contour_measure_delete(int key);
void *static_sk_contour_measure_get_ptr(int key); // -> SkContourMeasure *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
