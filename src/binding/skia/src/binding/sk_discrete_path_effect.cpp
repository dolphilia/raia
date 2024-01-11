//
// Created by dolphilia on 2024/01/08.
//

#include "sk_discrete_path_effect.h"

extern "C" {

void SkDiscretePathEffect_Make(const char *sk_path_effect_key_out, SkScalar segLength, SkScalar dev, uint32_t seedAssist) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkDiscretePathEffect::Make(segLength, dev, seedAssist));
}

void SkDiscretePathEffect_RegisterFlattenables() {
    SkDiscretePathEffect::RegisterFlattenables();
}

}