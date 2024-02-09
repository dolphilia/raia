//
// Created by dolphilia on 2024/01/08.
//

#include "sk_corner_path_effect.h"

extern "C" {

void SkCornerPathEffect_delete(SkCornerPathEffect * cornerPathEffect) {
    delete cornerPathEffect;
}

// static

sk_path_effect_t SkCornerPathEffect_Make(SkScalar radius) {
    return static_sk_path_effect_make(SkCornerPathEffect::Make(radius));
}

void SkCornerPathEffect_RegisterFlattenables() {
    SkCornerPathEffect::RegisterFlattenables();
}

}