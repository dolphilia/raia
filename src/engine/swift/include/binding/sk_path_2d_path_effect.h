//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H

#include "include/effects/Sk2DPathEffect.h"
#include "../static/static_sk_path_effect.h"

extern "C" {
void SkPath2DPathEffect_delete(SkPath2DPathEffect * path2DPathEffect);
// static
sk_path_effect_t SkPath2DPathEffect_Make(const SkMatrix *matrix, const SkPath *path);
void SkPath2DPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
