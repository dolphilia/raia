//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_IMAGE_INFO_H
#define RAIA_SKIA_SK_IMAGE_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

//bool operator==(const SkImageInfo &other)
//bool operator!=(const SkImageInfo &other)
void *SkImageInfo_new(); // () -> SkImageInfo *
void SkImageInfo_delete(void *image_info); // (SkImageInfo *image_info)
int SkImageInfo_width(void *image_info); // (SkImageInfo *image_info) -> int
int SkImageInfo_height(void *image_info); // (SkImageInfo *image_info) -> int
int SkImageInfo_colorType(void *image_info); // (SkImageInfo *image_info) -> SkColorType
int SkImageInfo_alphaType(void *image_info); // (SkImageInfo *image_info) -> SkAlphaType
void *SkImageInfo_colorSpace(void *image_info); // (SkImageInfo *image_info) -> SkColorSpace *
int SkImageInfo_refColorSpace(void *image_info); // (SkImageInfo *image_info) -> sk_color_space_t
bool SkImageInfo_isEmpty(void *image_info); // (SkImageInfo *image_info) -> bool
int SkImageInfo_colorInfo(void *image_info); // (SkImageInfo *image_info) -> sk_color_info_t
bool SkImageInfo_isOpaque(void *image_info); // (SkImageInfo *image_info) -> bool
int SkImageInfo_dimensions(void *image_info); // (SkImageInfo *image_info) -> sk_i_size_t
int SkImageInfo_bounds(void *image_info); // (SkImageInfo *image_info) -> sk_i_rect_t
bool SkImageInfo_gammaCloseToSRGB(void *image_info); // (SkImageInfo *image_info) -> bool
int SkImageInfo_makeWH(void *image_info, int newWidth, int newHeight); // (SkImageInfo *image_info, int newWidth, int newHeight) -> sk_image_info_t
int SkImageInfo_makeDimensions(void *image_info, int newSize); // (SkImageInfo *image_info, sk_i_size_t newSize) -> sk_image_info_t
int SkImageInfo_makeAlphaType(void *image_info, int newAlphaType); // (SkImageInfo *image_info, SkAlphaType newAlphaType) -> sk_image_info_t
int SkImageInfo_makeColorType(void *image_info, int newColorType); // (SkImageInfo *image_info, SkColorType newColorType) -> sk_image_info_t
int SkImageInfo_makeColorSpace(void *image_info, int color_space); // (SkImageInfo *image_info, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_bytesPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
int SkImageInfo_shiftPerPixel(void *image_info); // (SkImageInfo *image_info) -> int
unsigned long long SkImageInfo_minRowBytes64(void *image_info); // (SkImageInfo *image_info) -> uint64_t
unsigned long SkImageInfo_minRowBytes(void *image_info); // (SkImageInfo *image_info) -> size_t
unsigned long SkImageInfo_computeOffset(void *image_info, int x, int y, unsigned long rowBytes); // (SkImageInfo *image_info, int x, int y, size_t rowBytes) -> size_t
unsigned long SkImageInfo_computeByteSize(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> size_t
unsigned long SkImageInfo_computeMinByteSize(void *image_info); // (SkImageInfo *image_info) -> size_t
bool SkImageInfo_validRowBytes(void *image_info, unsigned long rowBytes); // (SkImageInfo *image_info, size_t rowBytes) -> bool
void SkImageInfo_reset(void *image_info); // (SkImageInfo *image_info)

// static

int SkImageInfo_Make(int width, int height, int ct, int at); // (int width, int height, SkColorType ct, SkAlphaType at) -> sk_image_info_t
int SkImageInfo_Make_2(int width, int height, int ct, int at, int color_space); // (int width, int height, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_Make_3(int dimensions, int ct, int at); // (sk_i_size_t dimensions, SkColorType ct, SkAlphaType at) -> sk_image_info_t
int SkImageInfo_Make_4(int dimensions, int ct, int at, int color_space); // (sk_i_size_t dimensions, SkColorType ct, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_Make_5(int dimensions, const void *colorInfo); // (sk_i_size_t dimensions, const SkColorInfo *colorInfo) -> sk_image_info_t
int SkImageInfo_MakeN32(int width, int height, int at); // (int width, int height, SkAlphaType at) -> sk_image_info_t
int SkImageInfo_MakeN32_2(int width, int height, int at, int color_space); // (int width, int height, SkAlphaType at, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_MakeS32(int width, int height, int at); // (int width, int height, SkAlphaType at) -> sk_image_info_t
int SkImageInfo_MakeN32Premul(int width, int height); // (int width, int height) -> sk_image_info_t
int SkImageInfo_MakeN32Premul_2(int width, int height, int color_space); // (int width, int height, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_MakeN32Premul_3(int dimensions); // (sk_i_size_t dimensions) -> sk_image_info_t
int SkImageInfo_MakeN32Premul_4(int dimensions, int color_space); // (sk_i_size_t dimensions, sk_color_space_t color_space) -> sk_image_info_t
int SkImageInfo_MakeA8(int width, int height); // (int width, int height) -> sk_image_info_t
int SkImageInfo_MakeA8_2(int dimensions); // (sk_i_size_t dimensions) -> sk_image_info_t
int SkImageInfo_MakeUnknown(int width, int height); // (int width, int height) -> sk_image_info_t
int SkImageInfo_MakeUnknown_2(); // () -> sk_image_info_t
bool SkImageInfo_ByteSizeOverflowed(unsigned long byteSize); // (size_t byteSize) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGE_INFO_H
