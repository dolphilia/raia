//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_text_literal.h"

static std::set<int> static_sk_svg_text_literal_available_keys;
static std::map<int , sk_sp<SkSVGTextLiteral>> static_sk_svg_text_literal;
static int static_sk_svg_text_literal_index = 0;

int static_sk_svg_text_literal_make(sk_sp<SkSVGTextLiteral> value) {
    int key;
    if (!static_sk_svg_text_literal_available_keys.empty()) {
        auto it = static_sk_svg_text_literal_available_keys.begin();
        key = *it;
        static_sk_svg_text_literal_available_keys.erase(it);
    } else {
        key = static_sk_svg_text_literal_index++;
    }
    static_sk_svg_text_literal[key] = std::move(value);
    return key;
}

void static_sk_svg_text_literal_delete(int key) {
    static_sk_svg_text_literal[key].reset();
    static_sk_svg_text_literal.erase(key);
    static_sk_svg_text_literal_available_keys.insert(key);
}

SkSVGTextLiteral *static_sk_svg_text_literal_get(int key) {
    return static_sk_svg_text_literal[key].get();
}

void static_sk_svg_text_literal_set(int key, sk_sp<SkSVGTextLiteral> value) {
    static_sk_svg_text_literal[key] = std::move(value);
}

sk_sp<SkSVGTextLiteral> static_sk_svg_text_literal_move(int key) {
    return std::move(static_sk_svg_text_literal[key]);
}
