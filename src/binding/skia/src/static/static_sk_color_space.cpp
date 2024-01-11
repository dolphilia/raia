//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_color_space.h"

static std::map<std::string, sk_sp<SkColorSpace>> static_sk_color_space;

void static_sk_color_space_delete(const char *key) {
    static_sk_color_space[key].reset();
    static_sk_color_space.erase(key);
}

SkColorSpace *static_sk_color_space_get(const char *key) {
    return static_sk_color_space[key].get();
}

void static_sk_color_space_set(const char *key, sk_sp<SkColorSpace> value) {
    static_sk_color_space[key] = std::move(value);
}

sk_sp<SkColorSpace> static_sk_color_space_move(const char *key) {
    return std::move(static_sk_color_space[key]);
}