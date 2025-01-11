//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H

#include "include/effects/Sk1DPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkPath1DPathEffect_delete(SkPath1DPathEffect * path1DPathEffect);
// static
RAIA_API sk_path_effect_t SkPath1DPathEffect_Make(const SkPath *path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style);
RAIA_API void SkPath1DPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
