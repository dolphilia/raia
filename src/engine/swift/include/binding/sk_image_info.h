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
#include "../static/static_sk_i_size.h"

extern "C" {
//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)
SkImageInfo *SkImageInfo_new();
void SkImageInfo_delete(SkImageInfo *image_info);
int SkImageInfo_width(SkImageInfo *image_info);
int SkImageInfo_height(SkImageInfo *image_info);
SkColorType SkImageInfo_colorType(SkImageInfo *image_info);
SkAlphaType SkImageInfo_alphaType(SkImageInfo *image_info);
SkColorSpace * SkImageInfo_colorSpace(SkImageInfo *image_info);
sk_color_space_t SkImageInfo_refColorSpace(SkImageInfo *image_info);
bool SkImageInfo_isEmpty(SkImageInfo *image_info);
sk_color_info_t SkImageInfo_colorInfo(SkImageInfo *image_info);
bool SkImageInfo_isOpaque(SkImageInfo *image_info);
sk_i_size_t SkImageInfo_dimensions(SkImageInfo *image_info);
sk_i_rect_t SkImageInfo_bounds(SkImageInfo *image_info);
bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info);
sk_image_info_t SkImageInfo_makeWH(SkImageInfo *image_info, int newWidth, int newHeight);
sk_image_info_t SkImageInfo_makeDimensions(SkImageInfo *image_info, sk_i_size_t newSize);
sk_image_info_t SkImageInfo_makeAlphaType(SkImageInfo *image_info, SkAlphaType newAlphaType);
sk_image_info_t SkImageInfo_makeColorType(SkImageInfo *image_info, SkColorType newColorType);
sk_image_info_t SkImageInfo_makeColorSpace(SkImageInfo *image_info, sk_color_space_t color_space);
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
sk_image_info_t SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at);
sk_image_info_t SkImageInfo_Make_2(int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space);
sk_image_info_t SkImageInfo_Make_3(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at);
sk_image_info_t SkImageInfo_Make_4(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space);
sk_image_info_t SkImageInfo_Make_5(sk_i_size_t dimensions, const SkColorInfo *colorInfo);
sk_image_info_t SkImageInfo_MakeN32(int width, int height, SkAlphaType at);
sk_image_info_t SkImageInfo_MakeN32_2(int width, int height, SkAlphaType at, sk_color_space_t color_space);
sk_image_info_t SkImageInfo_MakeS32(int width, int height, SkAlphaType at);
sk_image_info_t SkImageInfo_MakeN32Premul(int width, int height);
sk_image_info_t SkImageInfo_MakeN32Premul_2(int width, int height, sk_color_space_t color_space);
sk_image_info_t SkImageInfo_MakeN32Premul_3(sk_i_size_t dimensions);
sk_image_info_t SkImageInfo_MakeN32Premul_4(sk_i_size_t dimensions, sk_color_space_t color_space);
sk_image_info_t SkImageInfo_MakeA8(int width, int height);
sk_image_info_t SkImageInfo_MakeA8_2(sk_i_size_t dimensions);
sk_image_info_t SkImageInfo_MakeUnknown(int width, int height);
sk_image_info_t SkImageInfo_MakeUnknown_2();
bool SkImageInfo_ByteSizeOverflowed(size_t byteSize);
}

#endif //RAIA_SKIA_SK_IMAGE_INFO_H
