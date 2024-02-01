//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font.h"

#include <utility>

static std::set<int> static_sk_font_available_keys;
static std::map<int , SkFont> static_sk_font;
static int static_sk_font_index = 0;

int static_sk_font_make(SkFont value) {
    int key;
    if (!static_sk_font_available_keys.empty()) {
        auto it = static_sk_font_available_keys.begin();
        key = *it;
        static_sk_font_available_keys.erase(it);
    } else {
        key = static_sk_font_index++;
    }
    static_sk_font[key] = std::move(value);
    return key;
}

void static_sk_font_delete(int key) {
    static_sk_font.erase(key);
    static_sk_font_available_keys.insert(key);
}

SkFont static_sk_font_get(int key) {
    return static_sk_font[key];
}

void static_sk_font_set(int key, SkFont value) {
    static_sk_font[key] = std::move(value);
}