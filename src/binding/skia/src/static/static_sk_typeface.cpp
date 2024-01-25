//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_typeface.h"

static std::map<int , sk_sp<SkTypeface>> static_sk_typeface;

void static_sk_typeface_delete(int key) {
    static_sk_typeface[key].reset();
    static_sk_typeface.erase(key);
}

SkTypeface *static_sk_typeface_get(int key) {
    return static_sk_typeface[key].get();
}

void static_sk_typeface_set(int key, sk_sp<SkTypeface> value) {
    static_sk_typeface[key] = std::move(value);
}

sk_sp<SkTypeface> static_sk_typeface_move(int key) {
    return std::move(static_sk_typeface[key]);
}