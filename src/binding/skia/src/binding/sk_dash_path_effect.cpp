//
// Created by dolphilia on 2024/01/08.
//

#include "sk_dash_path_effect.h"

extern "C" {

void SkDashPathEffect_delete(SkDashPathEffect * dashPathEffect) {
    delete dashPathEffect;
}

// static

sk_path_effect_t SkDashPathEffect_Make(const SkScalar intervals[], int count, SkScalar phase) {
    return static_sk_path_effect_make(SkDashPathEffect::Make(intervals, count, phase));
}

}