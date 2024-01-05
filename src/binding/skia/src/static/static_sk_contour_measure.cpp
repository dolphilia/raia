//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_contour_measure.h"

static std::map<std::string, sk_sp<SkContourMeasure>> static_sk_contour_measure;

void static_sk_contour_measure_delete(const char *key) {
    static_sk_contour_measure[key].reset();
    static_sk_contour_measure.erase(key);
}

SkContourMeasure *static_sk_contour_measure_get(const char *key) {
    return static_sk_contour_measure[key].get();
}

void static_sk_contour_measure_set(const char *key, sk_sp<SkContourMeasure> value) {
    static_sk_contour_measure[key] = std::move(value);
}

sk_sp<SkContourMeasure> static_sk_contour_measure_move(const char *key) {
    return std::move(static_sk_contour_measure[key]);
}