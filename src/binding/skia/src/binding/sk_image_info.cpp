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

void SkImageInfo_refColorSpace(int sk_color_space_key_out, SkImageInfo *image_info) {
    static_sk_color_space_set(sk_color_space_key_out, image_info->refColorSpace());
}

bool SkImageInfo_isEmpty(SkImageInfo *image_info) {
    return image_info->isEmpty();
}

void SkImageInfo_colorInfo(int sk_color_info_key_out, SkImageInfo *image_info) {
    static_sk_color_info_set(sk_color_info_key_out, image_info->colorInfo());
}

bool SkImageInfo_isOpaque(SkImageInfo *image_info) {
    return image_info->isOpaque();
}

SkISize SkImageInfo_dimensions(SkImageInfo *image_info) {
    return image_info->dimensions();
}

void SkImageInfo_bounds(int sk_i_rect_key_out, SkImageInfo *image_info) {
    static_sk_i_rect_set(sk_i_rect_key_out, image_info->bounds());
}

bool SkImageInfo_gammaCloseToSRGB(SkImageInfo *image_info) {
    return image_info->gammaCloseToSRGB();
}

void SkImageInfo_makeWH(int sk_image_info_key_out, SkImageInfo *image_info, int newWidth, int newHeight) {
    static_sk_image_info_set(sk_image_info_key_out, image_info->makeWH(newWidth, newHeight));
}

void SkImageInfo_makeDimensions(int sk_image_info_key_out, SkImageInfo *image_info, SkISize newSize) {
    static_sk_image_info_set(sk_image_info_key_out, image_info->makeDimensions(newSize));
}

void SkImageInfo_makeAlphaType(int sk_image_info_key_out, SkImageInfo *image_info, SkAlphaType newAlphaType) {
    static_sk_image_info_set(sk_image_info_key_out, image_info->makeAlphaType(newAlphaType));
}

void SkImageInfo_makeColorType(int sk_image_info_key_out, SkImageInfo *image_info, SkColorType newColorType) {
    static_sk_image_info_set(sk_image_info_key_out, image_info->makeColorType(newColorType));
}

void SkImageInfo_makeColorSpace(int sk_image_info_key_out, SkImageInfo *image_info, int sk_color_space_key_in) {
    static_sk_image_info_set(sk_image_info_key_out, image_info->makeColorSpace(static_sk_color_space_move(sk_color_space_key_in)));
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

void SkImageInfo_Make(int sk_image_info_key_out, int width, int height, SkColorType ct, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(width, height, ct, at));
}

void SkImageInfo_Make_2(int sk_image_info_key_out, int sk_color_space_key_in, int width, int height, SkColorType ct, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(width, height, ct, at, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImageInfo_Make_3(int sk_image_info_key_out, SkISize dimensions, SkColorType ct, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(dimensions, ct, at));
}

void SkImageInfo_Make_4(int sk_image_info_key_out, int sk_color_space_key_in, SkISize dimensions, SkColorType ct, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(dimensions, ct, at, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImageInfo_Make_5(int sk_image_info_key_out, SkISize dimensions, const SkColorInfo *colorInfo) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(dimensions, *colorInfo));
}

void SkImageInfo_Make_6(int sk_image_info_key_out, SkISize dimensions, SkColorInfo &&colorInfo) { // @TODO
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::Make(dimensions, colorInfo));
}

void SkImageInfo_MakeN32(int sk_image_info_key_out, int width, int height, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32(width, height, at));
}

void SkImageInfo_MakeN32_2(int sk_image_info_key_out, int sk_color_space_key_in, int width, int height, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32(width, height, at, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImageInfo_MakeS32(int sk_image_info_key_out, int width, int height, SkAlphaType at) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeS32(width, height, at));
}

void SkImageInfo_MakeN32Premul(int sk_image_info_key_out, int width, int height) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32Premul(width, height));
}

void SkImageInfo_MakeN32Premul_2(int sk_image_info_key_out, int sk_color_space_key_in, int width, int height) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32Premul(width, height, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImageInfo_MakeN32Premul_3(int sk_image_info_key_out, SkISize dimensions) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32Premul(dimensions));
}

void SkImageInfo_MakeN32Premul_4(int sk_image_info_key_out, int sk_color_space_key_in, SkISize dimensions) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeN32Premul(dimensions, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkImageInfo_MakeA8(int sk_image_info_key_out, int width, int height) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeA8(width, height));
}

void SkImageInfo_MakeA8_2(int sk_image_info_key_out, SkISize dimensions) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeA8(dimensions));
}

void SkImageInfo_MakeUnknown(int sk_image_info_key_out, int width, int height) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeUnknown(width, height));
}

void SkImageInfo_MakeUnknown_2(int sk_image_info_key_out) {
    static_sk_image_info_set(sk_image_info_key_out, SkImageInfo::MakeUnknown());
}

bool SkImageInfo_ByteSizeOverflowed(size_t byteSize) {
    return SkImageInfo::ByteSizeOverflowed(byteSize);
}

}