//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H

#include "include/effects/Sk1DPathEffect.h"
#include "../static/static_sk_path_effect.h"

extern "C" {
// static
void SkPath1DPathEffect_Make(int sk_path_effect_key_out, const SkPath *path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style);
void SkPath1DPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
