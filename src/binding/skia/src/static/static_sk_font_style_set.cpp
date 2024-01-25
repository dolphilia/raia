//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_style_set.h"

#include <utility>

static std::map<int , sk_sp<SkFontStyleSet>> static_sk_font_style_set;
static int static_sk_font_style_set_index = 0;

int static_sk_font_style_set_make(sk_sp<SkFontStyleSet> value) {
    static_sk_font_style_set[static_sk_font_style_set_index] = std::move(value);
    static_sk_font_style_set_index++;
    return static_sk_font_style_set_index - 1;
}

void static_sk_font_style_set_delete(int key) {
    static_sk_font_style_set[key].reset();
    static_sk_font_style_set.erase(key);
}

SkFontStyleSet *static_sk_font_style_set_get(int key) {
    return static_sk_font_style_set[key].get();
}

void static_sk_font_style_set_set(int key, sk_sp<SkFontStyleSet> value) {
    static_sk_font_style_set[key] = std::move(value);
}

sk_sp<SkFontStyleSet> static_sk_font_style_set_move(int key) {
    return std::move(static_sk_font_style_set[key]);
}