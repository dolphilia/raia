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
#include "export_api.h"

extern "C" {
//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)
RAIA_API SkImageInfo *SkImageInfo_new();
RAIA_API void SkImageInfo_delete(SkImageInfo *image_info);
RAIA_API int SkImageInfo_width(SkImageInfo *image_info);
RAIA_API int SkImageInfo_height(SkImageInfo *image_info);
RAIA_API SkColorType SkImageInfo_colorType(SkImageInfo *image_info);
RAIA_API SkAlphaType SkImageInfo_alphaType(SkImageInfo *image_info);
RAIA_API SkColorSpace * SkImageInfo_colorSpace(SkImageInfo *image_info);
RAIA_API sk_color_space_t SkImageInfo_refColorSpace(SkImageInfo *image_info);
RAIA_API bool SkImageInfo_isEmpty(SkImageInfo *image_info);
RAIA_API sk_color_info_t SkImageInfo_colorInfo(SkImageInfo *image_info);
RAIA_API bool SkImageInfo_isOpaque(SkImageInfo *image_info);
RAIA_API sk_i_size_t SkImageInfo_dimensions(SkImageInfo *image_info);
RAIA_API sk_i_rect_t SkImageInfo_bounds(SkImageInfo *image_info);
RAIA_API bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info);
RAIA_API sk_image_info_t SkImageInfo_makeWH(SkImageInfo *image_info, int newWidth, int newHeight);
RAIA_API sk_image_info_t SkImageInfo_makeDimensions(SkImageInfo *image_info, sk_i_size_t newSize);
RAIA_API sk_image_info_t SkImageInfo_makeAlphaType(SkImageInfo *image_info, SkAlphaType newAlphaType);
RAIA_API sk_image_info_t SkImageInfo_makeColorType(SkImageInfo *image_info, SkColorType newColorType);
RAIA_API sk_image_info_t SkImageInfo_makeColorSpace(SkImageInfo *image_info, sk_color_space_t color_space);
RAIA_API int SkImageInfo_bytesPerPixel(SkImageInfo *image_info);
RAIA_API int SkImageInfo_shiftPerPixel(SkImageInfo *image_info);
RAIA_API uint64_t SkImageInfo_minRowBytes64(SkImageInfo *image_info);
RAIA_API size_t SkImageInfo_minRowBytes(SkImageInfo *image_info);
RAIA_API size_t SkImageInfo_computeOffset(SkImageInfo *image_info, int x, int y, size_t rowBytes);
RAIA_API size_t SkImageInfo_computeByteSize(SkImageInfo *image_info, size_t rowBytes);
RAIA_API size_t SkImageInfo_computeMinByteSize(SkImageInfo *image_info);
RAIA_API bool SkImageInfo_validRowBytes(SkImageInfo *image_info, size_t rowBytes);
RAIA_API void SkImageInfo_reset(SkImageInfo *image_info);
// static
RAIA_API sk_image_info_t SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at);
RAIA_API sk_image_info_t SkImageInfo_Make_2(int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space);
RAIA_API sk_image_info_t SkImageInfo_Make_3(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at);
RAIA_API sk_image_info_t SkImageInfo_Make_4(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space);
RAIA_API sk_image_info_t SkImageInfo_Make_5(sk_i_size_t dimensions, const SkColorInfo *colorInfo);
RAIA_API sk_image_info_t SkImageInfo_MakeN32(int width, int height, SkAlphaType at);
RAIA_API sk_image_info_t SkImageInfo_MakeN32_2(int width, int height, SkAlphaType at, sk_color_space_t color_space);
RAIA_API sk_image_info_t SkImageInfo_MakeS32(int width, int height, SkAlphaType at);
RAIA_API sk_image_info_t SkImageInfo_MakeN32Premul(int width, int height);
RAIA_API sk_image_info_t SkImageInfo_MakeN32Premul_2(int width, int height, sk_color_space_t color_space);
RAIA_API sk_image_info_t SkImageInfo_MakeN32Premul_3(sk_i_size_t dimensions);
RAIA_API sk_image_info_t SkImageInfo_MakeN32Premul_4(sk_i_size_t dimensions, sk_color_space_t color_space);
RAIA_API sk_image_info_t SkImageInfo_MakeA8(int width, int height);
RAIA_API sk_image_info_t SkImageInfo_MakeA8_2(sk_i_size_t dimensions);
RAIA_API sk_image_info_t SkImageInfo_MakeUnknown(int width, int height);
RAIA_API sk_image_info_t SkImageInfo_MakeUnknown_2();
RAIA_API bool SkImageInfo_ByteSizeOverflowed(size_t byteSize);
}

#endif //RAIA_SKIA_SK_IMAGE_INFO_H
