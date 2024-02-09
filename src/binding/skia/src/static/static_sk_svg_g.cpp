//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_g.h"

static std::set<int> static_sk_svg_g_available_keys;
static std::map<int , sk_sp<SkSVGG>> static_sk_svg_g;
static int static_sk_svg_g_index = 0;

int static_sk_svg_g_make(sk_sp<SkSVGG> value) {
    int key;
    if (!static_sk_svg_g_available_keys.empty()) {
        auto it = static_sk_svg_g_available_keys.begin();
        key = *it;
        static_sk_svg_g_available_keys.erase(it);
    } else {
        key = static_sk_svg_g_index++;
    }
    static_sk_svg_g[key] = std::move(value);
    return key;
}

void static_sk_svg_g_delete(int key) {
    static_sk_svg_g[key].reset();
    static_sk_svg_g.erase(key);
    static_sk_svg_g_available_keys.insert(key);
}

SkSVGG *static_sk_svg_g_get(int key) {
    return static_sk_svg_g[key].get();
}

void static_sk_svg_g_set(int key, sk_sp<SkSVGG> value) {
    static_sk_svg_g[key] = std::move(value);
}

sk_sp<SkSVGG> static_sk_svg_g_move(int key) {
    return std::move(static_sk_svg_g[key]);
}
