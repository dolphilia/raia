//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_use.h"

static std::set<int> static_sk_svg_use_available_keys;
static std::map<int , sk_sp<SkSVGUse>> static_sk_svg_use;
static int static_sk_svg_use_index = 0;

int static_sk_svg_use_make(sk_sp<SkSVGUse> value) {
    int key;
    if (!static_sk_svg_use_available_keys.empty()) {
        auto it = static_sk_svg_use_available_keys.begin();
        key = *it;
        static_sk_svg_use_available_keys.erase(it);
    } else {
        key = static_sk_svg_use_index++;
    }
    static_sk_svg_use[key] = std::move(value);
    return key;
}

void static_sk_svg_use_delete(int key) {
    static_sk_svg_use[key].reset();
    static_sk_svg_use.erase(key);
    static_sk_svg_use_available_keys.insert(key);
}

SkSVGUse *static_sk_svg_use_get(int key) {
    return static_sk_svg_use[key].get();
}

void static_sk_svg_use_set(int key, sk_sp<SkSVGUse> value) {
    static_sk_svg_use[key] = std::move(value);
}

sk_sp<SkSVGUse> static_sk_svg_use_move(int key) {
    return std::move(static_sk_svg_use[key]);
}
