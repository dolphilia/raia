//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_composite.h"

static std::set<int> static_sk_svg_fe_composite_available_keys;
static std::map<int , sk_sp<SkSVGFeComposite>> static_sk_svg_fe_composite;
static int static_sk_svg_fe_composite_index = 0;

int static_sk_svg_fe_composite_make(sk_sp<SkSVGFeComposite> value) {
    int key;
    if (!static_sk_svg_fe_composite_available_keys.empty()) {
        auto it = static_sk_svg_fe_composite_available_keys.begin();
        key = *it;
        static_sk_svg_fe_composite_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_composite_index++;
    }
    static_sk_svg_fe_composite[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_composite_delete(int key) {
    static_sk_svg_fe_composite[key].reset();
    static_sk_svg_fe_composite.erase(key);
    static_sk_svg_fe_composite_available_keys.insert(key);
}

SkSVGFeComposite *static_sk_svg_fe_composite_get(int key) {
    return static_sk_svg_fe_composite[key].get();
}

void static_sk_svg_fe_composite_set(int key, sk_sp<SkSVGFeComposite> value) {
    static_sk_svg_fe_composite[key] = std::move(value);
}

sk_sp<SkSVGFeComposite> static_sk_svg_fe_composite_move(int key) {
    return std::move(static_sk_svg_fe_composite[key]);
}