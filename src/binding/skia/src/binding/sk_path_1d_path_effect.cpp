//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path_1d_path_effect.h"

extern "C" {

void SkPath1DPathEffect_delete(SkPath1DPathEffect * path1DPathEffect) {
    delete path1DPathEffect;
}

// static

sk_path_effect_t SkPath1DPathEffect_Make(const SkPath *path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style) {
    return static_sk_path_effect_make(SkPath1DPathEffect::Make(*path, advance, phase, style));
}

void SkPath1DPathEffect_RegisterFlattenables() {
    SkPath1DPathEffect::RegisterFlattenables();
}

}