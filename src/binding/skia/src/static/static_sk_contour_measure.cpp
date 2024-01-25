//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_contour_measure.h"

static std::map<int , sk_sp<SkContourMeasure>> static_sk_contour_measure;

void static_sk_contour_measure_delete(int key) {
    static_sk_contour_measure[key].reset();
    static_sk_contour_measure.erase(key);
}

SkContourMeasure *static_sk_contour_measure_get(int key) {
    return static_sk_contour_measure[key].get();
}

void static_sk_contour_measure_set(int key, sk_sp<SkContourMeasure> value) {
    static_sk_contour_measure[key] = std::move(value);
}

sk_sp<SkContourMeasure> static_sk_contour_measure_move(int key) {
    return std::move(static_sk_contour_measure[key]);
}