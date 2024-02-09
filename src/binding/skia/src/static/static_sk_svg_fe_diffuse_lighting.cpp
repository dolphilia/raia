//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_diffuse_lighting.h"

static std::set<int> static_sk_svg_fe_diffuse_lighting_available_keys;
static std::map<int , sk_sp<SkSVGFeDiffuseLighting>> static_sk_svg_fe_diffuse_lighting;
static int static_sk_svg_fe_diffuse_lighting_index = 0;

int static_sk_svg_fe_diffuse_lighting_make(sk_sp<SkSVGFeDiffuseLighting> value) {
    int key;
    if (!static_sk_svg_fe_diffuse_lighting_available_keys.empty()) {
        auto it = static_sk_svg_fe_diffuse_lighting_available_keys.begin();
        key = *it;
        static_sk_svg_fe_diffuse_lighting_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_diffuse_lighting_index++;
    }
    static_sk_svg_fe_diffuse_lighting[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_diffuse_lighting_delete(int key) {
    static_sk_svg_fe_diffuse_lighting[key].reset();
    static_sk_svg_fe_diffuse_lighting.erase(key);
    static_sk_svg_fe_diffuse_lighting_available_keys.insert(key);
}

SkSVGFeDiffuseLighting *static_sk_svg_fe_diffuse_lighting_get(int key) {
    return static_sk_svg_fe_diffuse_lighting[key].get();
}

void static_sk_svg_fe_diffuse_lighting_set(int key, sk_sp<SkSVGFeDiffuseLighting> value) {
    static_sk_svg_fe_diffuse_lighting[key] = std::move(value);
}

sk_sp<SkSVGFeDiffuseLighting> static_sk_svg_fe_diffuse_lighting_move(int key) {
    return std::move(static_sk_svg_fe_diffuse_lighting[key]);
}