//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color.h"

extern "C" {

// SK_API

SkColor SkColor_SkColorSetA(SkColor c, U8CPU a) {
    return SkColorSetA(c, a);
}

SkColor SkColor_SkColorSetARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkColorSetARGB(a, r, g, b);
}

void SkColor_SkColorToHSV(SkColor color, SkScalar hsv[3]) {
    SkColorToHSV(color, hsv);
}

SkColor SkColor_SkHSVToColor(const SkScalar hsv[3]) {
    return SkHSVToColor(hsv);
}

SkColor SkColor_SkHSVToColor_2(U8CPU alpha, const SkScalar hsv[3]) {
    return SkHSVToColor(alpha, hsv);
}

SkPMColor SkColor_SkPreMultiplyARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPreMultiplyARGB(a, r, g, b);
}

SkPMColor SkColor_SkPreMultiplyColor(SkColor c) {
    return SkPreMultiplyColor(c);
}

void SkColor_SkRGBToHSV(U8CPU red, U8CPU green, U8CPU blue, SkScalar hsv[3]) {
    SkRGBToHSV(red, green, blue, hsv);
}

}