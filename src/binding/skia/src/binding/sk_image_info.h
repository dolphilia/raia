//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_IMAGE_INFO_H
#define RAIA_SKIA_SK_IMAGE_INFO_H

#include "include/core/SkImageInfo.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_color_info.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_image_info.h"

extern "C" {
//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)
SkImageInfo *SkImageInfo_new();
int SkImageInfo_width(SkImageInfo *image_info);
int SkImageInfo_height(SkImageInfo *image_info);
SkColorType SkImageInfo_colorType(SkImageInfo *image_info);
SkAlphaType SkImageInfo_alphaType(SkImageInfo *image_info);
SkColorSpace * SkImageInfo_colorSpace(SkImageInfo *image_info);
int SkImageInfo_refColorSpace(SkImageInfo *image_info);
bool SkImageInfo_isEmpty(SkImageInfo *image_info);
int SkImageInfo_colorInfo(SkImageInfo *image_info);
bool SkImageInfo_isOpaque(SkImageInfo *image_info);
SkISize SkImageInfo_dimensions(SkImageInfo *image_info);
int SkImageInfo_bounds(SkImageInfo *image_info);
bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info);
int SkImageInfo_makeWH(SkImageInfo *image_info, int newWidth, int newHeight);
int SkImageInfo_makeDimensions(SkImageInfo *image_info, SkISize newSize);
int SkImageInfo_makeAlphaType(SkImageInfo *image_info, SkAlphaType newAlphaType);
int SkImageInfo_makeColorType(SkImageInfo *image_info, SkColorType newColorType);
int SkImageInfo_makeColorSpace(SkImageInfo *image_info, int sk_color_space_key_in);
int SkImageInfo_bytesPerPixel(SkImageInfo *image_info);
int SkImageInfo_shiftPerPixel(SkImageInfo *image_info);
uint64_t SkImageInfo_minRowBytes64(SkImageInfo *image_info);
size_t SkImageInfo_minRowBytes(SkImageInfo *image_info);
size_t SkImageInfo_computeOffset(SkImageInfo *image_info, int x, int y, size_t rowBytes);
size_t SkImageInfo_computeByteSize(SkImageInfo *image_info, size_t rowBytes);
size_t SkImageInfo_computeMinByteSize(SkImageInfo *image_info);
bool SkImageInfo_validRowBytes(SkImageInfo *image_info, size_t rowBytes);
void SkImageInfo_reset(SkImageInfo *image_info);
// static
int SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at);
int SkImageInfo_Make_2(int sk_color_space_key_in, int width, int height, SkColorType ct, SkAlphaType at);
int SkImageInfo_Make_3(SkISize dimensions, SkColorType ct, SkAlphaType at);
int SkImageInfo_Make_4(int sk_color_space_key_in, SkISize dimensions, SkColorType ct, SkAlphaType at);
int SkImageInfo_Make_5(SkISize dimensions, const SkColorInfo *colorInfo);
// @TODO
int SkImageInfo_Make_6(SkISize dimensions, SkColorInfo &&colorInfo);
int SkImageInfo_MakeN32(int width, int height, SkAlphaType at);
int SkImageInfo_MakeN32_2(int sk_color_space_key_in, int width, int height, SkAlphaType at);
int SkImageInfo_MakeS32(int width, int height, SkAlphaType at);
int SkImageInfo_MakeN32Premul(int width, int height);
int SkImageInfo_MakeN32Premul_2(int sk_color_space_key_in, int width, int height);
int SkImageInfo_MakeN32Premul_3(SkISize dimensions);
int SkImageInfo_MakeN32Premul_4(int sk_color_space_key_in, SkISize dimensions);
int SkImageInfo_MakeA8(int width, int height);
int SkImageInfo_MakeA8_2(SkISize dimensions);
int SkImageInfo_MakeUnknown(int width, int height);
int SkImageInfo_MakeUnknown_2();
bool SkImageInfo_ByteSizeOverflowed(size_t byteSize);
}

#endif //RAIA_SKIA_SK_IMAGE_INFO_H
