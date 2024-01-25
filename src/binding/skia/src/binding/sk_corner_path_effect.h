//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
#define RAIA_SKIA_SK_CORNER_PATH_EFFECT_H

#include "include/effects/SkCornerPathEffect.h"
#include "../static/static_sk_path_effect.h"

extern "C" {
// static
int SkCornerPathEffect_Make(SkScalar radius);
void SkCornerPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
