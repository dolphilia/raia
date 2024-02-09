//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_pattern.h"

static std::set<int> static_sk_svg_pattern_available_keys;
static std::map<int , sk_sp<SkSVGPattern>> static_sk_svg_pattern;
static int static_sk_svg_pattern_index = 0;

int static_sk_svg_pattern_make(sk_sp<SkSVGPattern> value) {
    int key;
    if (!static_sk_svg_pattern_available_keys.empty()) {
        auto it = static_sk_svg_pattern_available_keys.begin();
        key = *it;
        static_sk_svg_pattern_available_keys.erase(it);
    } else {
        key = static_sk_svg_pattern_index++;
    }
    static_sk_svg_pattern[key] = std::move(value);
    return key;
}

void static_sk_svg_pattern_delete(int key) {
    static_sk_svg_pattern[key].reset();
    static_sk_svg_pattern.erase(key);
    static_sk_svg_pattern_available_keys.insert(key);
}

SkSVGPattern *static_sk_svg_pattern_get(int key) {
    return static_sk_svg_pattern[key].get();
}

void static_sk_svg_pattern_set(int key, sk_sp<SkSVGPattern> value) {
    static_sk_svg_pattern[key] = std::move(value);
}

sk_sp<SkSVGPattern> static_sk_svg_pattern_move(int key) {
    return std::move(static_sk_svg_pattern[key]);
}
