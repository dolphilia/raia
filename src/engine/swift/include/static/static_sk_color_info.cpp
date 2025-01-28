//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_color_info.h"

#include <utility>
#include "static_sk_color_info-internal.h"

static std::set<int> static_sk_color_info_available_keys;
static std::map<int , SkColorInfo> static_sk_color_info;
static int static_sk_color_info_index = 0;

int static_sk_color_info_make(SkColorInfo value) {
    int key;
    if (!static_sk_color_info_available_keys.empty()) {
        auto it = static_sk_color_info_available_keys.begin();
        key = *it;
        static_sk_color_info_available_keys.erase(it);
    } else {
        key = static_sk_color_info_index++;
    }
    static_sk_color_info[key] = std::move(value);
    return key;
}

void static_sk_color_info_delete(int key) {
    static_sk_color_info.erase(key);
    static_sk_color_info_available_keys.insert(key);
}

SkColorInfo static_sk_color_info_get(int key) {
    return static_sk_color_info[key];
}

void * static_sk_color_info_get_ptr(int key) { // -> SkColorInfo *
    return &static_sk_color_info[key];
}

void static_sk_color_info_set(int key, SkColorInfo value) {
    static_sk_color_info[key] = std::move(value);
}
