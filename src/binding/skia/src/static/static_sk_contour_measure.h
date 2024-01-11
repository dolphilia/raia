//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
#define RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H

#include <string>
#include <map>
#include "include/core/SkContourMeasure.h"

void static_sk_contour_measure_delete(const char *key);
SkContourMeasure *static_sk_contour_measure_get(const char *key);
void static_sk_contour_measure_set(const char *key, sk_sp<SkContourMeasure> value);
sk_sp<SkContourMeasure> static_sk_contour_measure_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_CONTOUR_MEASURE_H
