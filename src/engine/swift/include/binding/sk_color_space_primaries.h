//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H
#define RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H

#include "include/core/SkColorSpace.h"

extern "C" {
void SkColorSpacePrimaries_delete(SkColorSpacePrimaries *color_pace_primaries);
void SkColorSpacePrimaries_toXYZD50(SkColorSpacePrimaries *color_pace_primaries, skcms_Matrix3x3 *toXYZD50);
}

#endif //RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H
