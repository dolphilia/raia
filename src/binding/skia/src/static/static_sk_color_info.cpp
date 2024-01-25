//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_color_info.h"

#include <utility>

static std::map<int , SkColorInfo> static_sk_color_info;
static int static_sk_color_info_index = 0;

int static_sk_color_info_make(SkColorInfo value) {
    static_sk_color_info[static_sk_color_info_index] = std::move(value);
    static_sk_color_info_index++;
    return static_sk_color_info_index - 1;
}

void static_sk_color_info_delete(int key) {
    static_sk_color_info.erase(key);
}

SkColorInfo static_sk_color_info_get(int key) {
    return static_sk_color_info[key];
}

void static_sk_color_info_set(int key, SkColorInfo value) {
    static_sk_color_info[key] = std::move(value);
}