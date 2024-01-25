//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_color_space.h"

#include <utility>

static std::map<int , sk_sp<SkColorSpace>> static_sk_color_space;
static int static_sk_color_space_index = 0;

int static_sk_color_space_make(sk_sp<SkColorSpace> value) {
    static_sk_color_space[static_sk_color_space_index] = std::move(value);
    static_sk_color_space_index++;
    return static_sk_color_space_index - 1;
}

void static_sk_color_space_delete(int key) {
    static_sk_color_space[key].reset();
    static_sk_color_space.erase(key);
}

SkColorSpace *static_sk_color_space_get(int key) {
    return static_sk_color_space[key].get();
}

void static_sk_color_space_set(int key, sk_sp<SkColorSpace> value) {
    static_sk_color_space[key] = std::move(value);
}

sk_sp<SkColorSpace> static_sk_color_space_move(int key) {
    return std::move(static_sk_color_space[key]);
}