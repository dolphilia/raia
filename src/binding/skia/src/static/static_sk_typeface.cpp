//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_typeface.h"

static std::map<std::string, sk_sp<SkTypeface>> static_sk_typeface;

void static_sk_typeface_delete(const char *key) {
    static_sk_typeface[key].reset();
    static_sk_typeface.erase(key);
}

SkTypeface *static_sk_typeface_get(const char *key) {
    return static_sk_typeface[key].get();
}

void static_sk_typeface_set(const char *key, sk_sp<SkTypeface> value) {
    static_sk_typeface[key] = std::move(value);
}

sk_sp<SkTypeface> static_sk_typeface_move(const char *key) {
    return std::move(static_sk_typeface[key]);
}