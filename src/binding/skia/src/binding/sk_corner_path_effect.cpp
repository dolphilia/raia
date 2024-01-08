//
// Created by dolphilia on 2024/01/08.
//

#include "sk_corner_path_effect.h"

extern "C" {

// static

void SkCornerPathEffect_Make(const char *sk_path_effect_key_out, SkScalar radius) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkCornerPathEffect::Make(radius));
}

void SkCornerPathEffect_RegisterFlattenables() {
    SkCornerPathEffect::RegisterFlattenables();
}

}