//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_SK_BLEND_MODE_H
#define RAIA_SKIA_SK_BLEND_MODE_H

#include "include/core/SkBlendMode.h"

extern "C" {
bool SkBlendMode_SkBlendMode_AsCoeff(SkBlendMode mode, SkBlendModeCoeff *src, SkBlendModeCoeff *dst);
const char *SkBlendMode_SkBlendMode_Name(SkBlendMode blendMode);
}

#endif //RAIA_SKIA_SK_BLEND_MODE_H
