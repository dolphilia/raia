//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_color.h"

static std::set<int> static_sk_color_available_keys;
static std::map<int , SkSpan<SkColor>> static_sk_color;
static int static_sk_color_index = 0;

int static_sk_color_make(SkSpan<SkColor> value) {
    int key;
    if (!static_sk_color_available_keys.empty()) {
        auto it = static_sk_color_available_keys.begin();
        key = *it;
        static_sk_color_available_keys.erase(it);
    } else {
        key = static_sk_color_index++;
    }
    static_sk_color[key] = value;
    return key;
}

void static_sk_color_delete(int key) {
    static_sk_color.erase(key);
    static_sk_color_available_keys.insert(key);
}

SkSpan<SkColor> static_sk_color_get(int key) {
    return static_sk_color[key];
}

void static_color_set(int key, SkSpan<SkColor> value) {
    static_sk_color[key] = value;
}