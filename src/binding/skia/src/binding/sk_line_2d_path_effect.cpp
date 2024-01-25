//
// Created by dolphilia on 2024/01/09.
//

#include "sk_line_2d_path_effect.h"

extern "C" {

// static

void SkLine2DPathEffect_Make(int sk_path_effect_key_out, SkScalar width, const SkMatrix *matrix) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkLine2DPathEffect::Make(width, *matrix));
}

void SkLine2DPathEffect_RegisterFlattenables() {
    SkLine2DPathEffect::RegisterFlattenables();
}

}