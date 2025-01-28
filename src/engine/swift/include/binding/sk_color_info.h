//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_INFO_H
#define RAIA_SKIA_SK_COLOR_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkColorInfo_new(); // () -> SkColorInfo *
void *SkColorInfo_new_2(int ct, int at, int color_space); // (SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> SkColorInfo *
void *SkColorInfo_new_3(const void *color_info); // (const SkColorInfo *color_info) -> SkColorInfo *
void SkColorInfo_delete(void *color_info); // (SkColorInfo *color_info)
int SkColorInfo_alphaType(void *color_info); // (SkColorInfo *color_info) -> SkAlphaType
int SkColorInfo_bytesPerPixel(void *color_info); // (SkColorInfo *color_info) -> int
void* SkColorInfo_colorSpace(void *color_info); // (SkColorInfo *color_info) -> SkColorSpace*
int SkColorInfo_colorType(void *color_info); // (SkColorInfo *color_info) -> SkColorType
bool SkColorInfo_gammaCloseToSRGB(void *color_info); // (SkColorInfo *color_info) -> bool
bool SkColorInfo_isOpaque(void *color_info); // (SkColorInfo *color_info) -> bool
int SkColorInfo_makeAlphaType(void *color_info, int newAlphaType); // (SkColorInfo *color_info, SkAlphaType newAlphaType) -> sk_color_info_t
int SkColorInfo_makeColorSpace(void *color_info, int color_space); // (SkColorInfo *color_info, sk_color_space_t color_space) -> sk_color_info_t
int SkColorInfo_makeColorType(void *color_info, int newColorType); // (SkColorInfo *color_info, SkColorType newColorType) -> sk_color_info_t
int SkColorInfo_refColorSpace(void *color_info); // (SkColorInfo *color_info) -> sk_color_space_t
int SkColorInfo_shiftPerPixel(void *color_info); // (SkColorInfo *color_info) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_INFO_H
