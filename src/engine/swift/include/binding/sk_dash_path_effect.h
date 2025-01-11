//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DASH_PATH_EFFECT_H
#define RAIA_SKIA_SK_DASH_PATH_EFFECT_H

#include "include/effects/SkDashPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkDashPathEffect_delete(SkDashPathEffect * dashPathEffect);
// static
RAIA_API sk_path_effect_t SkDashPathEffect_Make(const SkScalar intervals[], int count, SkScalar phase);
}

#endif //RAIA_SKIA_SK_DASH_PATH_EFFECT_H
