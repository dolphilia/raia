//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_offset.h"

static std::set<int> static_sk_svg_fe_offset_available_keys;
static std::map<int , sk_sp<SkSVGFeOffset>> static_sk_svg_fe_offset;
static int static_sk_svg_fe_offset_index = 0;

int static_sk_svg_fe_offset_make(sk_sp<SkSVGFeOffset> value) {
    int key;
    if (!static_sk_svg_fe_offset_available_keys.empty()) {
        auto it = static_sk_svg_fe_offset_available_keys.begin();
        key = *it;
        static_sk_svg_fe_offset_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_offset_index++;
    }
    static_sk_svg_fe_offset[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_offset_delete(int key) {
    static_sk_svg_fe_offset[key].reset();
    static_sk_svg_fe_offset.erase(key);
    static_sk_svg_fe_offset_available_keys.insert(key);
}

SkSVGFeOffset *static_sk_svg_fe_offset_get(int key) {
    return static_sk_svg_fe_offset[key].get();
}

void static_sk_svg_fe_offset_set(int key, sk_sp<SkSVGFeOffset> value) {
    static_sk_svg_fe_offset[key] = std::move(value);
}

sk_sp<SkSVGFeOffset> static_sk_svg_fe_offset_move(int key) {
    return std::move(static_sk_svg_fe_offset[key]);
}
