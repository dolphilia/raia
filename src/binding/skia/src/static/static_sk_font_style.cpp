//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_font_style.h"

static std::map<int , SkFontStyle> static_sk_font_style;
static int static_sk_font_style_index = 0;

int static_sk_font_style_make(SkFontStyle value) {
    static_sk_font_style[static_sk_font_style_index] = value;
    static_sk_font_style_index++;
    return static_sk_font_style_index - 1;
}

void static_sk_font_style_delete(int key) {
    static_sk_font_style.erase(key);
}

SkFontStyle static_sk_font_style_get(int key) {
    return static_sk_font_style[key];
}

void static_sk_font_style_set(int key, SkFontStyle value) {
    static_sk_font_style[key] = value;
}