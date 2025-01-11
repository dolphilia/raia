//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
#define RAIA_SKIA_SK_CORNER_PATH_EFFECT_H

#include "include/effects/SkCornerPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkCornerPathEffect_delete(SkCornerPathEffect * cornerPathEffect);
// static
RAIA_API sk_path_effect_t SkCornerPathEffect_Make(SkScalar radius);
RAIA_API void SkCornerPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
