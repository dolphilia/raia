//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H
#define RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H

#include "include/effects/Sk2DPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkLine2DPathEffect_delete(SkLine2DPathEffect * line2DPathEffect);
// static
RAIA_API sk_path_effect_t SkLine2DPathEffect_Make(SkScalar width, const SkMatrix *matrix);
RAIA_API void SkLine2DPathEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H
