//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_info.h"
#include "../static/static_sk_color_info.h"

extern "C" {

SkColorInfo *SkColorInfo_new() {
    return new SkColorInfo();
}

SkColorInfo *SkColorInfo_new_2(int sk_color_space_key_in, SkColorType ct, SkAlphaType at) {
    return new SkColorInfo(ct, at, static_sk_color_space_move(sk_color_space_key_in));
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

void SkColorInfo_makeAlphaType(int sk_color_info_key_in, SkColorInfo *color_info, SkAlphaType newAlphaType) {
    static_sk_color_info_set(sk_color_info_key_in, color_info->makeAlphaType(newAlphaType));
}

void SkColorInfo_makeColorSpace(int sk_color_info_key_in, int sk_color_space_key_in, SkColorInfo *color_info) {
    static_sk_color_info_set(sk_color_info_key_in, color_info->makeColorSpace(static_sk_color_space_move(sk_color_space_key_in)));
}

void SkColorInfo_makeColorType(int sk_color_info_key_in, SkColorInfo *color_info, SkColorType newColorType) {
    static_sk_color_info_set(sk_color_info_key_in, color_info->makeColorType(newColorType));
}

int SkColorInfo_refColorSpace(SkColorInfo *color_info) {
    return static_sk_color_space_make(color_info->refColorSpace());
}

int SkColorInfo_shiftPerPixel(SkColorInfo *color_info) {
    return color_info->shiftPerPixel();
}

}