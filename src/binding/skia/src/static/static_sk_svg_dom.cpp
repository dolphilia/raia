//
// Created by dolphilia on 2024/02/08.
//

#include "static_sk_svg_dom.h"

static std::set<int> static_sk_svg_dom_available_keys;
static std::map<int , sk_sp<SkSVGDOM>> static_sk_svg_dom;
static int static_sk_svg_dom_index = 0;

int static_sk_svg_dom_make(sk_sp<SkSVGDOM> value) {
    int key;
    if (!static_sk_svg_dom_available_keys.empty()) {
        auto it = static_sk_svg_dom_available_keys.begin();
        key = *it;
        static_sk_svg_dom_available_keys.erase(it);
    } else {
        key = static_sk_svg_dom_index++;
    }
    static_sk_svg_dom[key] = std::move(value);
    return key;
}

void static_sk_svg_dom_delete(int key) {
    static_sk_svg_dom[key].reset();
    static_sk_svg_dom.erase(key);
    static_sk_svg_dom_available_keys.insert(key);
}

SkSVGDOM *static_sk_svg_dom_get(int key) {
    return static_sk_svg_dom[key].get();
}

void static_sk_svg_dom_set(int key, sk_sp<SkSVGDOM> value) {
    static_sk_svg_dom[key] = std::move(value);
}

sk_sp<SkSVGDOM> static_sk_svg_dom_move(int key) {
    return std::move(static_sk_svg_dom[key]);
}