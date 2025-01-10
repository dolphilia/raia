//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SIZE_H
#define RAIA_SKIA_SK_SIZE_H

#include "include/core/SkSize.h"
#include "../static/static_sk_i_size.h"
#include "../static/static_sk_size_t.h"

extern "C" {
void SkSize_delete(SkSize *size);
void SkSize_set(SkSize *size, SkScalar w, SkScalar h);
bool SkSize_isZero(SkSize *size);
bool SkSize_isEmpty(SkSize *size);
void SkSize_setEmpty(SkSize *size);
SkScalar SkSize_width(SkSize *size);
SkScalar SkSize_height(SkSize *size);
bool SkSize_equals(SkSize *size, SkScalar w, SkScalar h);
sk_i_size_t SkSize_toRound(SkSize *size);
sk_i_size_t SkSize_toCeil(SkSize *size);
sk_i_size_t SkSize_toFloor(SkSize *size);
// static
sk_size_t SkSize_Make(SkScalar w, SkScalar h);
sk_size_t SkSize_Make_2(const SkISize *src);
sk_size_t SkSize_MakeEmpty();
}

#endif //RAIA_SKIA_SK_SIZE_H
