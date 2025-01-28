//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SIZE_H
#define RAIA_SKIA_SK_SIZE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkSize_delete(void *size); // (SkSize *size)
void SkSize_set(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h)
bool SkSize_isZero(void *size); // (SkSize *size) -> bool
bool SkSize_isEmpty(void *size); // (SkSize *size) -> bool
void SkSize_setEmpty(void *size); // (SkSize *size)
float SkSize_width(void *size); // (SkSize *size) -> SkScalar
float SkSize_height(void *size); // (SkSize *size) -> SkScalar
bool SkSize_equals(void *size, float w, float h); // (SkSize *size, SkScalar w, SkScalar h) -> bool
int SkSize_toRound(void *size); // (SkSize *size) -> sk_i_size_t
int SkSize_toCeil(void *size); // (SkSize *size) -> sk_i_size_t
int SkSize_toFloor(void *size); // (SkSize *size) -> sk_i_size_t

// static

int SkSize_Make(float w, float h); // (SkScalar w, SkScalar h) -> sk_size_t
int SkSize_Make_2(const void *src); // (const SkISize *src) -> sk_size_t
int SkSize_MakeEmpty(); // () -> sk_size_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SIZE_H
