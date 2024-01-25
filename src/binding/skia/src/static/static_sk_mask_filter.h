//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MASK_FILTER_H
#define RAIA_SKIA_STATIC_SK_MASK_FILTER_H

#include <string>
#include <map>
#include "include/core/SkMaskFilter.h"

void static_sk_mask_filter_delete(int key);
SkMaskFilter *static_sk_mask_filter_get(int key);
void static_sk_mask_filter_set(int key, sk_sp<SkMaskFilter> value);
sk_sp<SkMaskFilter> static_sk_mask_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_MASK_FILTER_H
