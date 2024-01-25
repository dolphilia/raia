//
// Created by dolphilia on 2024/01/11.
//

#include "sk_trim_path_effect.h"

extern "C" {

void SkTrimPathEffect_Make(int sk_path_effect_key_out, SkScalar startT, SkScalar stopT, SkTrimPathEffect::Mode mode) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkTrimPathEffect::Make(startT, stopT, mode));
}

}