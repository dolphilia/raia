//
// Created by dolphilia on 2024/01/11.
//

#include "sk_trim_path_effect.h"

extern "C" {

int SkTrimPathEffect_Make(SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode) {
    return static_sk_path_effect_make(SkTrimPathEffect::Make(startT, stopT, mode));
}

}