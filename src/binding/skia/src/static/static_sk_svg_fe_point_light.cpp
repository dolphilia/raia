//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_point_light.h"

static std::set<int> static_sk_svg_fe_point_light_available_keys;
static std::map<int , sk_sp<SkSVGFePointLight>> static_sk_svg_fe_point_light;
static int static_sk_svg_fe_point_light_index = 0;

int static_sk_svg_fe_point_light_make(sk_sp<SkSVGFePointLight> value) {
    int key;
    if (!static_sk_svg_fe_point_light_available_keys.empty()) {
        auto it = static_sk_svg_fe_point_light_available_keys.begin();
        key = *it;
        static_sk_svg_fe_point_light_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_point_light_index++;
    }
    static_sk_svg_fe_point_light[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_point_light_delete(int key) {
    static_sk_svg_fe_point_light[key].reset();
    static_sk_svg_fe_point_light.erase(key);
    static_sk_svg_fe_point_light_available_keys.insert(key);
}

SkSVGFePointLight *static_sk_svg_fe_point_light_get(int key) {
    return static_sk_svg_fe_point_light[key].get();
}

void static_sk_svg_fe_point_light_set(int key, sk_sp<SkSVGFePointLight> value) {
    static_sk_svg_fe_point_light[key] = std::move(value);
}

sk_sp<SkSVGFePointLight> static_sk_svg_fe_point_light_move(int key) {
    return std::move(static_sk_svg_fe_point_light[key]);
}
