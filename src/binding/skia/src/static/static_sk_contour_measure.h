//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkContourMeasure.h"

typedef int sk_contour_measure_t;

int static_sk_contour_measure_make(sk_sp<SkContourMeasure> value);
extern "C" void static_sk_contour_measure_delete(int key);
extern "C" SkContourMeasure *static_sk_contour_measure_get(int key);
void static_sk_contour_measure_set(int key, sk_sp<SkContourMeasure> value);
sk_sp<SkContourMeasure> static_sk_contour_measure_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
