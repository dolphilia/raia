//
// Created by dolphilia on 2024/01/09.
//

#include "sk_line_2d_path_effect.h"

extern "C" {

void SkLine2DPathEffect_delete(SkLine2DPathEffect * line2DPathEffect) {
    delete line2DPathEffect;
}

// static

sk_path_effect_t SkLine2DPathEffect_Make(SkScalar width, const SkMatrix *matrix) {
    return static_sk_path_effect_make(SkLine2DPathEffect::Make(width, *matrix));
}

void SkLine2DPathEffect_RegisterFlattenables() {
    SkLine2DPathEffect::RegisterFlattenables();
}

}