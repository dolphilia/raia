//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SIZE_H
#define RAIA_SKIA_SK_SIZE_H

#include "include/core/SkSize.h"
#include "../static/static_sk_i_size.h"
#include "../static/static_sk_size_t.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkSize_delete(SkSize *size);
RAIA_API void SkSize_set(SkSize *size, SkScalar w, SkScalar h);
RAIA_API bool SkSize_isZero(SkSize *size);
RAIA_API bool SkSize_isEmpty(SkSize *size);
RAIA_API void SkSize_setEmpty(SkSize *size);
RAIA_API SkScalar SkSize_width(SkSize *size);
RAIA_API SkScalar SkSize_height(SkSize *size);
RAIA_API bool SkSize_equals(SkSize *size, SkScalar w, SkScalar h);
RAIA_API sk_i_size_t SkSize_toRound(SkSize *size);
RAIA_API sk_i_size_t SkSize_toCeil(SkSize *size);
RAIA_API sk_i_size_t SkSize_toFloor(SkSize *size);
// static
RAIA_API sk_size_t SkSize_Make(SkScalar w, SkScalar h);
RAIA_API sk_size_t SkSize_Make_2(const SkISize *src);
RAIA_API sk_size_t SkSize_MakeEmpty();
}

#endif //RAIA_SKIA_SK_SIZE_H
