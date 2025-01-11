//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TRIM_PATH_EFFECT_H
#define RAIA_SKIA_SK_TRIM_PATH_EFFECT_H

#include "include/effects/SkTrimPathEffect.h"
#include "../static/static_sk_path_effect.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkTrimPathEffect_delete(SkTrimPathEffect * trimPathEffect);
// static
RAIA_API sk_path_effect_t SkTrimPathEffect_Make(SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode);
}

#endif //RAIA_SKIA_SK_TRIM_PATH_EFFECT_H
