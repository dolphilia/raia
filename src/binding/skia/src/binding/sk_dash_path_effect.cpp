//
// Created by dolphilia on 2024/01/08.
//

#include "sk_dash_path_effect.h"

extern "C" {

void SkDashPathEffect_Make(const char *sk_path_effect_key_out, const SkScalar intervals[], int count, SkScalar phase) {
    static_sk_path_effect_set(sk_path_effect_key_out, SkDashPathEffect::Make(intervals, count, phase));
}

}