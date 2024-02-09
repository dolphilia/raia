//
// Created by dolphilia on 2024/02/05.
//

#include "static_sk_svg_defs.h"

static std::set<int> static_sk_svg_defs_available_keys;
static std::map<int , sk_sp<SkSVGDefs>> static_sk_svg_defs;
static int static_sk_svg_defs_index = 0;

int static_sk_svg_defs_make(sk_sp<SkSVGDefs> value) {
    int key;
    if (!static_sk_svg_defs_available_keys.empty()) {
        auto it = static_sk_svg_defs_available_keys.begin();
        key = *it;
        static_sk_svg_defs_available_keys.erase(it);
    } else {
        key = static_sk_svg_defs_index++;
    }
    static_sk_svg_defs[key] = std::move(value);
    return key;
}

void static_sk_svg_defs_delete(int key) {
    static_sk_svg_defs[key].reset();
    static_sk_svg_defs.erase(key);
    static_sk_svg_defs_available_keys.insert(key);
}

SkSVGDefs *static_sk_svg_defs_get(int key) {
    return static_sk_svg_defs[key].get();
}

void static_sk_svg_defs_set(int key, sk_sp<SkSVGDefs> value) {
    static_sk_svg_defs[key] = std::move(value);
}

sk_sp<SkSVGDefs> static_sk_svg_defs_move(int key) {
    return std::move(static_sk_svg_defs[key]);
}