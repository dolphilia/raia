//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_color_filter.h"

static std::map<std::string, sk_sp<SkColorFilter>> static_sk_color_filter;

void static_sk_color_filter_delete(const char *key) {
    static_sk_color_filter[key].reset();
    static_sk_color_filter.erase(key);
}

SkColorFilter *static_sk_color_filter_get(const char *key) {
    return static_sk_color_filter[key].get();
}

void static_sk_color_filter_set(const char *key, sk_sp<SkColorFilter> value) {
    static_sk_color_filter[key] = std::move(value);
}

sk_sp<SkColorFilter> static_sk_color_filter_move(const char *key) {
    return std::move(static_sk_color_filter[key]);
}