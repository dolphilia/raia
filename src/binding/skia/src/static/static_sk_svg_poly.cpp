//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_poly.h"

static std::set<int> static_sk_svg_poly_available_keys;
static std::map<int , sk_sp<SkSVGPoly>> static_sk_svg_poly;
static int static_sk_svg_poly_index = 0;

int static_sk_svg_poly_make(sk_sp<SkSVGPoly> value) {
    int key;
    if (!static_sk_svg_poly_available_keys.empty()) {
        auto it = static_sk_svg_poly_available_keys.begin();
        key = *it;
        static_sk_svg_poly_available_keys.erase(it);
    } else {
        key = static_sk_svg_poly_index++;
    }
    static_sk_svg_poly[key] = std::move(value);
    return key;
}

void static_sk_svg_poly_delete(int key) {
    static_sk_svg_poly[key].reset();
    static_sk_svg_poly.erase(key);
    static_sk_svg_poly_available_keys.insert(key);
}

SkSVGPoly *static_sk_svg_poly_get(int key) {
    return static_sk_svg_poly[key].get();
}

void static_sk_svg_poly_set(int key, sk_sp<SkSVGPoly> value) {
    static_sk_svg_poly[key] = std::move(value);
}

sk_sp<SkSVGPoly> static_sk_svg_poly_move(int key) {
    return std::move(static_sk_svg_poly[key]);
}
