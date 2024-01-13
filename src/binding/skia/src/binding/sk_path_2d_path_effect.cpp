//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path_2d_path_effect.h"

extern "C" {

// static

void SkPath2DPathEffect_Make(const char *sk_path_effect_key_out, const SkMatrix *matrix, const SkPath *path) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkPath2DPathEffect::Make(*matrix, *path));
}

void SkPath2DPathEffect_RegisterFlattenables() {
    SkPath2DPathEffect::RegisterFlattenables();
}

}