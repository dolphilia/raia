//
// Created by dolphilia on 2024/01/08.
//

#include "sk_dash_path_effect.h"

extern "C" {

int SkDashPathEffect_Make(const SkScalar intervals[], int count, SkScalar phase) {
    return static_sk_path_effect_make(SkDashPathEffect::Make(intervals, count, phase));
}

}