//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_text.h"

static std::set<int> static_sk_svg_text_available_keys;
static std::map<int , sk_sp<SkSVGText>> static_sk_svg_text;
static int static_sk_svg_text_index = 0;

int static_sk_svg_text_make(sk_sp<SkSVGText> value) {
    int key;
    if (!static_sk_svg_text_available_keys.empty()) {
        auto it = static_sk_svg_text_available_keys.begin();
        key = *it;
        static_sk_svg_text_available_keys.erase(it);
    } else {
        key = static_sk_svg_text_index++;
    }
    static_sk_svg_text[key] = std::move(value);
    return key;
}

void static_sk_svg_text_delete(int key) {
    static_sk_svg_text[key].reset();
    static_sk_svg_text.erase(key);
    static_sk_svg_text_available_keys.insert(key);
}

SkSVGText *static_sk_svg_text_get(int key) {
    return static_sk_svg_text[key].get();
}

void static_sk_svg_text_set(int key, sk_sp<SkSVGText> value) {
    static_sk_svg_text[key] = std::move(value);
}

sk_sp<SkSVGText> static_sk_svg_text_move(int key) {
    return std::move(static_sk_svg_text[key]);
}
