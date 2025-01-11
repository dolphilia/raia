//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_H
#define RAIA_SKIA_SK_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned int SkColor_SkColorSetA(unsigned int c, unsigned int a);
unsigned int SkColor_SkColorSetARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
void SkColor_SkColorToHSV(unsigned int color, float hsv[3]);
unsigned int SkColor_SkHSVToColor(const float hsv[3]);
unsigned int SkColor_SkHSVToColor_2(unsigned int alpha, const float hsv[3]);
unsigned int SkColor_SkPreMultiplyARGB(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
unsigned int SkColor_SkPreMultiplyColor(unsigned int c);
void SkColor_SkRGBToHSV(unsigned int red, unsigned int green, unsigned int blue, float hsv[3]);

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_H
