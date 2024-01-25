//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font.h"

#include <utility>

static std::map<int , SkFont> static_sk_font;
static int static_sk_font_index = 0;

int static_sk_font_make(SkFont value) {
    static_sk_font[static_sk_font_index] = std::move(value);
    static_sk_font_index++;
    return static_sk_font_index - 1;
}

void static_sk_font_delete(int key) {
    static_sk_font.erase(key);
}

SkFont static_sk_font_get(int key) {
    return static_sk_font[key];
}

void static_sk_font_set(int key, SkFont value) {
    static_sk_font[key] = std::move(value);
}