//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H

#include "include/effects/Sk2DPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkPath2DPathEffect_delete(SkPath2DPathEffect * path2DPathEffect);
// static
RAIA_API sk_path_effect_t SkPath2DPathEffect_Make(const SkMatrix *matrix, const SkPath *path);
RAIA_API void SkPath2DPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
