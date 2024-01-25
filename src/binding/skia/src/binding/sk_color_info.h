//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_INFO_H
#define RAIA_SKIA_SK_COLOR_INFO_H

#include "include/core/SkImageInfo.h"
#include "../static/static_sk_color_space.h"

extern "C" {
SkColorInfo *SkColorInfo_new();
SkColorInfo *SkColorInfo_new_2(int sk_color_space_key_in, SkColorType ct, SkAlphaType at);
SkColorInfo *SkColorInfo_new_3(const SkColorInfo *color_info);
void SkColorInfo_delete(SkColorInfo *color_info);
SkAlphaType SkColorInfo_alphaType(SkColorInfo *color_info);
int SkColorInfo_bytesPerPixel(SkColorInfo *color_info);
SkColorSpace* SkColorInfo_colorSpace(SkColorInfo *color_info);
SkColorType SkColorInfo_colorType(SkColorInfo *color_info);
bool SkColorInfo_gammaCloseToSRGB(SkColorInfo *color_info);
bool SkColorInfo_isOpaque(SkColorInfo *color_info);
void SkColorInfo_makeAlphaType(int sk_color_info_key_in, SkColorInfo *color_info, SkAlphaType newAlphaType);
void SkColorInfo_makeColorSpace(int sk_color_info_key_in, int sk_color_space_key_in, SkColorInfo *color_info);
void SkColorInfo_makeColorType(int sk_color_info_key_in, SkColorInfo *color_info, SkColorType newColorType);
void SkColorInfo_refColorSpace(int sk_color_space_key_out, SkColorInfo *color_info);
int SkColorInfo_shiftPerPixel(SkColorInfo *color_info);
}

#endif //RAIA_SKIA_SK_COLOR_INFO_H
