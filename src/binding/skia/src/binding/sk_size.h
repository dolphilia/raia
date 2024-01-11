//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SIZE_H
#define RAIA_SKIA_SK_SIZE_H

#include "include/core/SkSize.h"

extern "C" {
void SkSize_set(SkSize *size, SkScalar w, SkScalar h);
bool SkSize_isZero(SkSize *size);
bool SkSize_isEmpty(SkSize *size);
void SkSize_setEmpty(SkSize *size);
SkScalar SkSize_width(SkSize *size);
SkScalar SkSize_height(SkSize *size);
bool SkSize_equals(SkSize *size, SkScalar w, SkScalar h);
SkISize SkSize_toRound(SkSize *size);
SkISize SkSize_toCeil(SkSize *size);
SkISize SkSize_toFloor(SkSize *size);
// static
SkSize SkSize_Make(SkScalar w, SkScalar h);
SkSize SkSize_Make_2(const SkISize &src);
SkSize SkSize_MakeEmpty();
}

#endif //RAIA_SKIA_SK_SIZE_H
