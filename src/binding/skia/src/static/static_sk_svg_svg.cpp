//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_svg.h"

static std::set<int> static_sk_svg_svg_available_keys;
static std::map<int , sk_sp<SkSVGSVG>> static_sk_svg_svg;
static int static_sk_svg_svg_index = 0;

int static_sk_svg_svg_make(sk_sp<SkSVGSVG> value) {
    int key;
    if (!static_sk_svg_svg_available_keys.empty()) {
        auto it = static_sk_svg_svg_available_keys.begin();
        key = *it;
        static_sk_svg_svg_available_keys.erase(it);
    } else {
        key = static_sk_svg_svg_index++;
    }
    static_sk_svg_svg[key] = std::move(value);
    return key;
}

void static_sk_svg_svg_delete(int key) {
    static_sk_svg_svg[key].reset();
    static_sk_svg_svg.erase(key);
    static_sk_svg_svg_available_keys.insert(key);
}

SkSVGSVG *static_sk_svg_svg_get(int key) {
    return static_sk_svg_svg[key].get();
}

void static_sk_svg_svg_set(int key, sk_sp<SkSVGSVG> value) {
    static_sk_svg_svg[key] = std::move(value);
}

sk_sp<SkSVGSVG> static_sk_svg_svg_move(int key) {
    return std::move(static_sk_svg_svg[key]);
}
