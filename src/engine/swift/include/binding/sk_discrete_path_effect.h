//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H
#define RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H

#include "include/effects/SkDiscretePathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkDiscretePathEffect_delete(SkDiscretePathEffect * discretePathEffect);
RAIA_API sk_path_effect_t SkDiscretePathEffect_Make(SkScalar segLength, SkScalar dev, uint32_t seedAssist);
RAIA_API void SkDiscretePathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H
