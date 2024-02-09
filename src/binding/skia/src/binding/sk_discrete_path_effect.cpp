//
// Created by dolphilia on 2024/01/08.
//

#include "sk_discrete_path_effect.h"

extern "C" {

void SkDiscretePathEffect_delete(SkDiscretePathEffect * discretePathEffect) {
    delete discretePathEffect;
}

sk_path_effect_t SkDiscretePathEffect_Make(SkScalar segLength, SkScalar dev, uint32_t seedAssist) {
    return static_sk_path_effect_make(SkDiscretePathEffect::Make(segLength, dev, seedAssist));
}

void SkDiscretePathEffect_RegisterFlattenables() {
    SkDiscretePathEffect::RegisterFlattenables();
}

}