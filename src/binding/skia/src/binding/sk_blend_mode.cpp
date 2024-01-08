//
// Created by dolphilia on 2024/01/06.
//

#include "sk_blend_mode.h"

extern "C" {

bool SkBlendMode_SkBlendMode_AsCoeff(SkBlendMode mode, SkBlendModeCoeff *src, SkBlendModeCoeff *dst) {
    return SkBlendMode_AsCoeff(mode, src, dst);
}

const char *SkBlendMode_SkBlendMode_Name(SkBlendMode blendMode) {
    return SkBlendMode_Name(blendMode);
}

}