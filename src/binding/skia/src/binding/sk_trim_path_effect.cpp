//
// Created by dolphilia on 2024/01/11.
//

#include "sk_trim_path_effect.h"

extern "C" {

void SkTrimPathEffect_delete(SkTrimPathEffect * trimPathEffect) {
    delete trimPathEffect;
}

// static

sk_path_effect_t SkTrimPathEffect_Make(SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode) {
    return static_sk_path_effect_make(SkTrimPathEffect::Make(startT, stopT, mode));
}

}