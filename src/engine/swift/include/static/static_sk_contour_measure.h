//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkContourMeasure.h"
#include "export_api.h"

typedef int sk_contour_measure_t;

extern "C" {
RAIA_API void static_sk_contour_measure_delete(int key);
RAIA_API SkContourMeasure *static_sk_contour_measure_get(int key);
}

int static_sk_contour_measure_make(sk_sp<SkContourMeasure> value);
void static_sk_contour_measure_set(int key, sk_sp<SkContourMeasure> value);
sk_sp<SkContourMeasure> static_sk_contour_measure_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
