//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_filter.h"

static std::map<int , sk_sp<SkImageFilter>> static_sk_image_filter;

void static_sk_image_filter_delete(int key) {
    static_sk_image_filter[key].reset();
    static_sk_image_filter.erase(key);
}

SkImageFilter *static_sk_image_filter_get(int key) {
    return static_sk_image_filter[key].get();
}

void static_sk_image_filter_set(int key, sk_sp<SkImageFilter> value) {
    static_sk_image_filter[key] = std::move(value);
}

sk_sp<SkImageFilter> static_sk_image_filter_move(int key) {
    return std::move(static_sk_image_filter[key]);
}