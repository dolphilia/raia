//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_turbulence.h"

static std::set<int> static_sk_svg_fe_turbulence_available_keys;
static std::map<int , sk_sp<SkSVGFeTurbulence>> static_sk_svg_fe_turbulence;
static int static_sk_svg_fe_turbulence_index = 0;

int static_sk_svg_fe_turbulence_make(sk_sp<SkSVGFeTurbulence> value) {
    int key;
    if (!static_sk_svg_fe_turbulence_available_keys.empty()) {
        auto it = static_sk_svg_fe_turbulence_available_keys.begin();
        key = *it;
        static_sk_svg_fe_turbulence_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_turbulence_index++;
    }
    static_sk_svg_fe_turbulence[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_turbulence_delete(int key) {
    static_sk_svg_fe_turbulence[key].reset();
    static_sk_svg_fe_turbulence.erase(key);
    static_sk_svg_fe_turbulence_available_keys.insert(key);
}

SkSVGFeTurbulence *static_sk_svg_fe_turbulence_get(int key) {
    return static_sk_svg_fe_turbulence[key].get();
}

void static_sk_svg_fe_turbulence_set(int key, sk_sp<SkSVGFeTurbulence> value) {
    static_sk_svg_fe_turbulence[key] = std::move(value);
}

sk_sp<SkSVGFeTurbulence> static_sk_svg_fe_turbulence_move(int key) {
    return std::move(static_sk_svg_fe_turbulence[key]);
}
