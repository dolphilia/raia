//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_font_style_set.h"

#include <utility>
#include "static_sk_font_style_set-internal.h"

static std::set<int> static_sk_font_style_set_available_keys;
static std::map<int , sk_sp<SkFontStyleSet>> static_sk_font_style_set;
static int static_sk_font_style_set_index = 0;

int static_sk_font_style_set_make(sk_sp<SkFontStyleSet> value) {
    int key;
    if (!static_sk_font_style_set_available_keys.empty()) {
        auto it = static_sk_font_style_set_available_keys.begin();
        key = *it;
        static_sk_font_style_set_available_keys.erase(it);
    } else {
        key = static_sk_font_style_set_index++;
    }
    static_sk_font_style_set[key] = std::move(value);
    return key;
}

void static_sk_font_style_set_delete(int key) {
    static_sk_font_style_set[key].reset();
    static_sk_font_style_set.erase(key);
    static_sk_font_style_set_available_keys.insert(key);
}

void *static_sk_font_style_set_get(int key) { // -> SkFontStyleSet *
    return static_sk_font_style_set[key].get();
}

void static_sk_font_style_set_set(int key, sk_sp<SkFontStyleSet> value) {
    static_sk_font_style_set[key] = std::move(value);
}

sk_sp<SkFontStyleSet> static_sk_font_style_set_move(int key) {
    return std::move(static_sk_font_style_set[key]);
}
