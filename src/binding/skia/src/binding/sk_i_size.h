//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_I_SIZE_H
#define RAIA_SKIA_SK_I_SIZE_H

#include "include/core/SkSize.h"
#include "../static/static_sk_i_size.h"

extern "C" {
void SkISize_delete(SkISize *i_size);
void SkISize_set(SkISize *i_size, int32_t w, int32_t h) ;
bool SkISize_isZero(SkISize *i_size);
bool SkISize_isEmpty(SkISize *i_size);
void SkISize_setEmpty(SkISize *i_size);
int32_t SkISize_width(SkISize *i_size);
int32_t SkISize_height(SkISize *i_size);
int64_t SkISize_area(SkISize *i_size);
bool SkISize_equals(SkISize *i_size, int32_t w, int32_t h);
// static
sk_i_size_t SkISize_Make(int32_t w, int32_t h);
sk_i_size_t SkISize_MakeEmpty();
}

#endif //RAIA_SKIA_SK_I_SIZE_H
