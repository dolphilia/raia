//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path_1d_path_effect.h"

extern "C" {

// static

void SkPath1DPathEffect_Make(int sk_path_effect_key_out, const SkPath *path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkPath1DPathEffect::Make(*path, advance, phase, style));
}

void SkPath1DPathEffect_RegisterFlattenables() {
    SkPath1DPathEffect::RegisterFlattenables();
}

}