//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_INFO_H
#define RAIA_SKIA_SK_COLOR_INFO_H

#include "include/core/SkImageInfo.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_color_info.h"
#include "export_api.h"

extern "C" {
RAIA_API SkColorInfo *SkColorInfo_new();
RAIA_API SkColorInfo *SkColorInfo_new_2(SkColorType ct, SkAlphaType at, sk_color_space_t color_space);
RAIA_API SkColorInfo *SkColorInfo_new_3(const SkColorInfo *color_info);
RAIA_API void SkColorInfo_delete(SkColorInfo *color_info);
RAIA_API SkAlphaType SkColorInfo_alphaType(SkColorInfo *color_info);
RAIA_API int SkColorInfo_bytesPerPixel(SkColorInfo *color_info);
RAIA_API SkColorSpace* SkColorInfo_colorSpace(SkColorInfo *color_info);
RAIA_API SkColorType SkColorInfo_colorType(SkColorInfo *color_info);
RAIA_API bool SkColorInfo_gammaCloseToSRGB(SkColorInfo *color_info);
RAIA_API bool SkColorInfo_isOpaque(SkColorInfo *color_info);
RAIA_API sk_color_info_t SkColorInfo_makeAlphaType(SkColorInfo *color_info, SkAlphaType newAlphaType);
RAIA_API sk_color_info_t SkColorInfo_makeColorSpace(SkColorInfo *color_info, sk_color_space_t color_space);
RAIA_API sk_color_info_t SkColorInfo_makeColorType(SkColorInfo *color_info, SkColorType newColorType);
RAIA_API sk_color_space_t SkColorInfo_refColorSpace(SkColorInfo *color_info);
RAIA_API int SkColorInfo_shiftPerPixel(SkColorInfo *color_info);
}

#endif //RAIA_SKIA_SK_COLOR_INFO_H
