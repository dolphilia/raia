//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_H
#define RAIA_SKIA_SK_COLOR_H

#include "include/core/SkColor.h"

extern "C" {
SkColor SkColor_SkColorSetA(SkColor c, U8CPU a);
SkColor SkColor_SkColorSetARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b);
void SkColor_SkColorToHSV(SkColor color, SkScalar hsv[3]);
SkColor SkColor_SkHSVToColor(const SkScalar hsv[3]);
SkColor SkColor_SkHSVToColor_2(U8CPU alpha, const SkScalar hsv[3]);
SkPMColor SkColor_SkPreMultiplyARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b);
SkPMColor SkColor_SkPreMultiplyColor(SkColor c);
void SkColor_SkRGBToHSV(U8CPU red, U8CPU green, U8CPU blue, SkScalar hsv[3]);
}

#endif //RAIA_SKIA_SK_COLOR_H
