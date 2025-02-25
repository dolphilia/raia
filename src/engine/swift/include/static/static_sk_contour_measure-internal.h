#ifndef STATIC_SK_CONTOUR_MEASURE_INTERNAL_H
#define STATIC_SK_CONTOUR_MEASURE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkContourMeasure.h"
int static_sk_contour_measure_make(sk_sp<SkContourMeasure> value);
void static_sk_contour_measure_set(int key, sk_sp<SkContourMeasure> value);
sk_sp<SkContourMeasure> static_sk_contour_measure_get_entity(int key);
#endif // STATIC_SK_CONTOUR_MEASURE_INTERNAL_H
