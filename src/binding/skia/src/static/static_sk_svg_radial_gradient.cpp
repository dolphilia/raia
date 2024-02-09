//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_radial_gradient.h"

static std::set<int> static_sk_svg_radial_gradient_available_keys;
static std::map<int , sk_sp<SkSVGRadialGradient>> static_sk_svg_radial_gradient;
static int static_sk_svg_radial_gradient_index = 0;

int static_sk_svg_radial_gradient_make(sk_sp<SkSVGRadialGradient> value) {
    int key;
    if (!static_sk_svg_radial_gradient_available_keys.empty()) {
        auto it = static_sk_svg_radial_gradient_available_keys.begin();
        key = *it;
        static_sk_svg_radial_gradient_available_keys.erase(it);
    } else {
        key = static_sk_svg_radial_gradient_index++;
    }
    static_sk_svg_radial_gradient[key] = std::move(value);
    return key;
}

void static_sk_svg_radial_gradient_delete(int key) {
    static_sk_svg_radial_gradient[key].reset();
    static_sk_svg_radial_gradient.erase(key);
    static_sk_svg_radial_gradient_available_keys.insert(key);
}

SkSVGRadialGradient *static_sk_svg_radial_gradient_get(int key) {
    return static_sk_svg_radial_gradient[key].get();
}

void static_sk_svg_radial_gradient_set(int key, sk_sp<SkSVGRadialGradient> value) {
    static_sk_svg_radial_gradient[key] = std::move(value);
}

sk_sp<SkSVGRadialGradient> static_sk_svg_radial_gradient_move(int key) {
    return std::move(static_sk_svg_radial_gradient[key]);
}
