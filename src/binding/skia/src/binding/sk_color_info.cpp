//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_info.h"
#include "../static/static_sk_color_info.h"

extern "C" {

SkColorInfo *SkColorInfo_new() {
    return new SkColorInfo();
}

SkColorInfo *SkColorInfo_new_2(SkColorType ct, SkAlphaType at, sk_color_space_t color_space) {
    return new SkColorInfo(ct, at, static_sk_color_space_move(color_space));
}

SkColorInfo *SkColorInfo_new_3(const SkColorInfo *color_info) {
    return new SkColorInfo(*color_info);
}

void SkColorInfo_delete(SkColorInfo *color_info) {
    delete color_info;
}

SkAlphaType SkColorInfo_alphaType(SkColorInfo *color_info) {
    return color_info->alphaType();
}

int SkColorInfo_bytesPerPixel(SkColorInfo *color_info) {
    return color_info->bytesPerPixel();
}

SkColorSpace* SkColorInfo_colorSpace(SkColorInfo *color_info) {
    return color_info->colorSpace();
}

SkColorType SkColorInfo_colorType(SkColorInfo *color_info) {
    return color_info->colorType();
}

bool SkColorInfo_gammaCloseToSRGB(SkColorInfo *color_info) {
    return color_info->gammaCloseToSRGB();
}

bool SkColorInfo_isOpaque(SkColorInfo *color_info) {
    return color_info->isOpaque();
}

sk_color_info_t SkColorInfo_makeAlphaType(SkColorInfo *color_info, SkAlphaType newAlphaType) {
    return static_sk_color_info_make(color_info->makeAlphaType(newAlphaType));
}

sk_color_info_t SkColorInfo_makeColorSpace(SkColorInfo *color_info, sk_color_space_t color_space) {
    return static_sk_color_info_make(color_info->makeColorSpace(static_sk_color_space_move(color_space)));
}

sk_color_info_t SkColorInfo_makeColorType(SkColorInfo *color_info, SkColorType newColorType) {
    return static_sk_color_info_make(color_info->makeColorType(newColorType));
}

sk_color_space_t SkColorInfo_refColorSpace(SkColorInfo *color_info) {
    return static_sk_color_space_make(color_info->refColorSpace());
}

int SkColorInfo_shiftPerPixel(SkColorInfo *color_info) {
    return color_info->shiftPerPixel();
}

}