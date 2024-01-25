//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path_2d_path_effect.h"

extern "C" {

// static

int SkPath2DPathEffect_Make(const SkMatrix *matrix, const SkPath *path) {
    return static_sk_path_effect_make(SkPath2DPathEffect::Make(*matrix, *path));
}

void SkPath2DPathEffect_RegisterFlattenables() {
    SkPath2DPathEffect::RegisterFlattenables();
}

}