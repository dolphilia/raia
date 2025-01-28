//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_H
#define RAIA_SKIA_SK_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned int SkColor_SkColorSetA(unsigned int c, unsigned int a); // (SkColor c, U8CPU a) -> SkColor
unsigned int SkColor_SkColorSetARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (U8CPU a, U8CPU r, U8CPU g, U8CPU b) -> SkColor
void SkColor_SkColorToHSV(unsigned int color, float hsv[3]); // (SkColor color, SkScalar hsv[3])
unsigned int SkColor_SkHSVToColor(const float hsv[3]); // (const SkScalar hsv[3]) -> SkColor
unsigned int SkColor_SkHSVToColor_2(unsigned int alpha, const float hsv[3]); // (U8CPU alpha, const SkScalar hsv[3]) -> SkColor
unsigned int SkColor_SkPreMultiplyARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (U8CPU a, U8CPU r, U8CPU g, U8CPU b) -> SkPMColor
unsigned int SkColor_SkPreMultiplyColor(unsigned int c); // (SkColor c) -> SkPMColor
void SkColor_SkRGBToHSV(unsigned int red, unsigned int green, unsigned int blue, float hsv[3]); // (U8CPU red, U8CPU green, U8CPU blue, SkScalar hsv[3])

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_H
