//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_mask.h"

static std::set<int> static_sk_svg_mask_available_keys;
static std::map<int , sk_sp<SkSVGMask>> static_sk_svg_mask;
static int static_sk_svg_mask_index = 0;

int static_sk_svg_mask_make(sk_sp<SkSVGMask> value) {
    int key;
    if (!static_sk_svg_mask_available_keys.empty()) {
        auto it = static_sk_svg_mask_available_keys.begin();
        key = *it;
        static_sk_svg_mask_available_keys.erase(it);
    } else {
        key = static_sk_svg_mask_index++;
    }
    static_sk_svg_mask[key] = std::move(value);
    return key;
}

void static_sk_svg_mask_delete(int key) {
    static_sk_svg_mask[key].reset();
    static_sk_svg_mask.erase(key);
    static_sk_svg_mask_available_keys.insert(key);
}

SkSVGMask *static_sk_svg_mask_get(int key) {
    return static_sk_svg_mask[key].get();
}

void static_sk_svg_mask_set(int key, sk_sp<SkSVGMask> value) {
    static_sk_svg_mask[key] = std::move(value);
}

sk_sp<SkSVGMask> static_sk_svg_mask_move(int key) {
    return std::move(static_sk_svg_mask[key]);
}
