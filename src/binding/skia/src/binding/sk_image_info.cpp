//
// Created by dolphilia on 2024/01/09.
//

#include "sk_image_info.h"

extern "C" {

//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)

SkImageInfo *SkImageInfo_new() {
    return new SkImageInfo();
}

void SkImageInfo_delete(SkImageInfo *image_info) {
    delete image_info;
}

int SkImageInfo_width(SkImageInfo *image_info) {
    return image_info->width();
}

int SkImageInfo_height(SkImageInfo *image_info) {
    return image_info->height();
}

SkColorType SkImageInfo_colorType(SkImageInfo *image_info) {
    return image_info->colorType();
}

SkAlphaType SkImageInfo_alphaType(SkImageInfo *image_info) {
    return image_info->alphaType();
}

SkColorSpace * SkImageInfo_colorSpace(SkImageInfo *image_info) {
    return image_info->colorSpace();
}

sk_color_space_t SkImageInfo_refColorSpace(SkImageInfo *image_info) {
    return static_sk_color_space_make(image_info->refColorSpace());
}

bool SkImageInfo_isEmpty(SkImageInfo *image_info) {
    return image_info->isEmpty();
}

sk_color_info_t SkImageInfo_colorInfo(SkImageInfo *image_info) {
    return static_sk_color_info_make(image_info->colorInfo());
}

bool SkImageInfo_isOpaque(SkImageInfo *image_info) {
    return image_info->isOpaque();
}

sk_i_size_t SkImageInfo_dimensions(SkImageInfo *image_info) {
    return static_sk_i_size_make(image_info->dimensions());
}

sk_i_rect_t SkImageInfo_bounds(SkImageInfo *image_info) {
    return static_sk_i_rect_make(image_info->bounds());
}

bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info) {
    return image_info->gammaCloseToSRGB();
}

sk_image_info_t SkImageInfo_makeWH(SkImageInfo *image_info, int newWidth, int newHeight) {
    return static_sk_image_info_make(image_info->makeWH(newWidth, newHeight));
}

sk_image_info_t SkImageInfo_makeDimensions(SkImageInfo *image_info, sk_i_size_t newSize) {
    return static_sk_image_info_make(image_info->makeDimensions(static_sk_i_size_get(newSize)));
}

sk_image_info_t SkImageInfo_makeAlphaType(SkImageInfo *image_info, SkAlphaType newAlphaType) {
    return static_sk_image_info_make(image_info->makeAlphaType(newAlphaType));
}

sk_image_info_t SkImageInfo_makeColorType(SkImageInfo *image_info, SkColorType newColorType) {
    return static_sk_image_info_make(image_info->makeColorType(newColorType));
}

sk_image_info_t SkImageInfo_makeColorSpace(SkImageInfo *image_info, sk_color_space_t color_space) {
    return static_sk_image_info_make(image_info->makeColorSpace(static_sk_color_space_move(color_space)));
}

int SkImageInfo_bytesPerPixel(SkImageInfo *image_info) {
    return image_info->bytesPerPixel();
}

int SkImageInfo_shiftPerPixel(SkImageInfo *image_info) {
    return image_info->shiftPerPixel();
}

uint64_t SkImageInfo_minRowBytes64(SkImageInfo *image_info) {
    return image_info->minRowBytes64();
}

size_t SkImageInfo_minRowBytes(SkImageInfo *image_info) {
    return image_info->minRowBytes();
}

size_t SkImageInfo_computeOffset(SkImageInfo *image_info, int x, int y, size_t rowBytes) {
    return image_info->computeOffset(x, y, rowBytes);
}

size_t SkImageInfo_computeByteSize(SkImageInfo *image_info, size_t rowBytes) {
    return image_info->computeByteSize(rowBytes);
}

size_t SkImageInfo_computeMinByteSize(SkImageInfo *image_info) {
    return image_info->computeMinByteSize();
}

bool SkImageInfo_validRowBytes(SkImageInfo *image_info, size_t rowBytes) {
    return image_info->validRowBytes(rowBytes);
}

void SkImageInfo_reset(SkImageInfo *image_info) {
    image_info->reset();
}

// static

sk_image_info_t SkImageInfo_Make(int width, int height, SkColorType ct, SkAlphaType at) {
    return static_sk_image_info_make(SkImageInfo::Make(width, height, ct, at));
}

sk_image_info_t SkImageInfo_Make_2(int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) {
    return static_sk_image_info_make(SkImageInfo::Make(width, height, ct, at, static_sk_color_space_move(color_space)));
}

sk_image_info_t SkImageInfo_Make_3(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at) {
    return static_sk_image_info_make(SkImageInfo::Make(static_sk_i_size_get(dimensions), ct, at));
}

sk_image_info_t SkImageInfo_Make_4(sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) {
    return static_sk_image_info_make(SkImageInfo::Make(static_sk_i_size_get(dimensions), ct, at, static_sk_color_space_move(color_space)));
}

sk_image_info_t SkImageInfo_Make_5(sk_i_size_t dimensions, const SkColorInfo *colorInfo) {
    return static_sk_image_info_make(SkImageInfo::Make(static_sk_i_size_get(dimensions), *colorInfo));
}


sk_image_info_t SkImageInfo_MakeN32(int width, int height, SkAlphaType at) {
    return static_sk_image_info_make(SkImageInfo::MakeN32(width, height, at));
}

sk_image_info_t SkImageInfo_MakeN32_2(int width, int height, SkAlphaType at, sk_color_space_t color_space) {
    return static_sk_image_info_make(SkImageInfo::MakeN32(width, height, at, static_sk_color_space_move(color_space)));
}

sk_image_info_t SkImageInfo_MakeS32(int width, int height, SkAlphaType at) {
    return static_sk_image_info_make(SkImageInfo::MakeS32(width, height, at));
}

sk_image_info_t SkImageInfo_MakeN32Premul(int width, int height) {
    return static_sk_image_info_make(SkImageInfo::MakeN32Premul(width, height));
}

sk_image_info_t SkImageInfo_MakeN32Premul_2(int width, int height, sk_color_space_t color_space) {
    return static_sk_image_info_make(SkImageInfo::MakeN32Premul(width, height, static_sk_color_space_move(color_space)));
}

sk_image_info_t SkImageInfo_MakeN32Premul_3(sk_i_size_t dimensions) {
    return static_sk_image_info_make(SkImageInfo::MakeN32Premul(static_sk_i_size_get(dimensions)));
}

sk_image_info_t SkImageInfo_MakeN32Premul_4(sk_i_size_t dimensions, sk_color_space_t color_space) {
    return static_sk_image_info_make(SkImageInfo::MakeN32Premul(static_sk_i_size_get(dimensions), static_sk_color_space_move(color_space)));
}

sk_image_info_t SkImageInfo_MakeA8(int width, int height) {
    return static_sk_image_info_make(SkImageInfo::MakeA8(width, height));
}

sk_image_info_t SkImageInfo_MakeA8_2(sk_i_size_t dimensions) {
    return static_sk_image_info_make(SkImageInfo::MakeA8(static_sk_i_size_get(dimensions)));
}

sk_image_info_t SkImageInfo_MakeUnknown(int width, int height) {
    return static_sk_image_info_make(SkImageInfo::MakeUnknown(width, height));
}

sk_image_info_t SkImageInfo_MakeUnknown_2() {
    return static_sk_image_info_make(SkImageInfo::MakeUnknown());
}

bool SkImageInfo_ByteSizeOverflowed(size_t byteSize) {
    return SkImageInfo::ByteSizeOverflowed(byteSize);
}

}