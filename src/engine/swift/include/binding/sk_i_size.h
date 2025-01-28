//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_I_SIZE_H
#define RAIA_SKIA_SK_I_SIZE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkISize_delete(void *i_size); // (SkISize *i_size)
void SkISize_set(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h)
bool SkISize_isZero(void *i_size); // (SkISize *i_size) -> bool
bool SkISize_isEmpty(void *i_size); // (SkISize *i_size) -> bool
void SkISize_setEmpty(void *i_size); // (SkISize *i_size)
int SkISize_width(void *i_size); // (SkISize *i_size) -> int32_t
int SkISize_height(void *i_size); // (SkISize *i_size) -> int32_t
long long SkISize_area(void *i_size); // (SkISize *i_size) -> int64_t
bool SkISize_equals(void *i_size, int w, int h); // (SkISize *i_size, int32_t w, int32_t h) -> bool

// static

int SkISize_Make(int w, int h); // (int32_t w, int32_t h) -> sk_i_size_t
int SkISize_MakeEmpty(); // () -> sk_i_size_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_I_SIZE_H
