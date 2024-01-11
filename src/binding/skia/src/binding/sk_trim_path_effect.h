//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TRIM_PATH_EFFECT_H
#define RAIA_SKIA_SK_TRIM_PATH_EFFECT_H

#include "include/effects/SkTrimPathEffect.h"
#include "../static/static_sk_path_effect.h"

extern "C" {
void SkTrimPathEffect_Make(const char *sk_path_effect_key_out, SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode);
}

#endif //RAIA_SKIA_SK_TRIM_PATH_EFFECT_H