//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_displacement_map.h"

static std::set<int> static_sk_svg_fe_displacement_map_available_keys;
static std::map<int , sk_sp<SkSVGFeDisplacementMap>> static_sk_svg_fe_displacement_map;
static int static_sk_svg_fe_displacement_map_index = 0;

int static_sk_svg_fe_displacement_map_make(sk_sp<SkSVGFeDisplacementMap> value) {
    int key;
    if (!static_sk_svg_fe_displacement_map_available_keys.empty()) {
        auto it = static_sk_svg_fe_displacement_map_available_keys.begin();
        key = *it;
        static_sk_svg_fe_displacement_map_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_displacement_map_index++;
    }
    static_sk_svg_fe_displacement_map[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_displacement_map_delete(int key) {
    static_sk_svg_fe_displacement_map[key].reset();
    static_sk_svg_fe_displacement_map.erase(key);
    static_sk_svg_fe_displacement_map_available_keys.insert(key);
}

SkSVGFeDisplacementMap *static_sk_svg_fe_displacement_map_get(int key) {
    return static_sk_svg_fe_displacement_map[key].get();
}

void static_sk_svg_fe_displacement_map_set(int key, sk_sp<SkSVGFeDisplacementMap> value) {
    static_sk_svg_fe_displacement_map[key] = std::move(value);
}

sk_sp<SkSVGFeDisplacementMap> static_sk_svg_fe_displacement_map_move(int key) {
    return std::move(static_sk_svg_fe_displacement_map[key]);
}