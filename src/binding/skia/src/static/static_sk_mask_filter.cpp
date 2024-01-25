//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_mask_filter.h"

static std::map<int , sk_sp<SkMaskFilter>> static_sk_mask_filter;

void static_sk_mask_filter_delete(int key) {
    static_sk_mask_filter[key].reset();
    static_sk_mask_filter.erase(key);
}

SkMaskFilter *static_sk_mask_filter_get(int key) {
    return static_sk_mask_filter[key].get();
}

void static_sk_mask_filter_set(int key, sk_sp<SkMaskFilter> value) {
    static_sk_mask_filter[key] = std::move(value);
}

sk_sp<SkMaskFilter> static_sk_mask_filter_move(int key) {
    return std::move(static_sk_mask_filter[key]);
}