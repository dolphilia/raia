//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_style_set.h"

static std::map<int , sk_sp<SkFontStyleSet>> static_sk_font_style_set;

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