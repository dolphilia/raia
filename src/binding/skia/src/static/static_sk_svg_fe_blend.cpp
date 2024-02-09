//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_blend.h"

static std::set<int> static_sk_svg_fe_blend_available_keys;
static std::map<int , sk_sp<SkSVGFeBlend>> static_sk_svg_fe_blend;
static int static_sk_svg_fe_blend_index = 0;

int static_sk_svg_fe_blend_make(sk_sp<SkSVGFeBlend> value) {
    int key;
    if (!static_sk_svg_fe_blend_available_keys.empty()) {
        auto it = static_sk_svg_fe_blend_available_keys.begin();
        key = *it;
        static_sk_svg_fe_blend_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_blend_index++;
    }
    static_sk_svg_fe_blend[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_blend_delete(int key) {
    static_sk_svg_fe_blend[key].reset();
    static_sk_svg_fe_blend.erase(key);
    static_sk_svg_fe_blend_available_keys.insert(key);
}

SkSVGFeBlend *static_sk_svg_fe_blend_get(int key) {
    return static_sk_svg_fe_blend[key].get();
}

void static_sk_svg_fe_blend_set(int key, sk_sp<SkSVGFeBlend> value) {
    static_sk_svg_fe_blend[key] = std::move(value);
}

sk_sp<SkSVGFeBlend> static_sk_svg_fe_blend_move(int key) {
    return std::move(static_sk_svg_fe_blend[key]);
}