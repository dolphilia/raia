//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MASK_FILTER_H
#define RAIA_SKIA_STATIC_SK_MASK_FILTER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkMaskFilter.h"
#include "export_api.h"

typedef int sk_mask_filter_t;

extern "C" {
RAIA_API void static_sk_mask_filter_delete(int key);
RAIA_API SkMaskFilter *static_sk_mask_filter_get(int key);
}

int static_sk_mask_filter_make(sk_sp<SkMaskFilter> value);
void static_sk_mask_filter_set(int key, sk_sp<SkMaskFilter> value);
sk_sp<SkMaskFilter> static_sk_mask_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_MASK_FILTER_H
