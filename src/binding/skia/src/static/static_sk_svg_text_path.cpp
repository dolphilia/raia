//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_text_path.h"

static std::set<int> static_sk_svg_text_path_available_keys;
static std::map<int , sk_sp<SkSVGTextPath>> static_sk_svg_text_path;
static int static_sk_svg_text_path_index = 0;

int static_sk_svg_text_path_make(sk_sp<SkSVGTextPath> value) {
    int key;
    if (!static_sk_svg_text_path_available_keys.empty()) {
        auto it = static_sk_svg_text_path_available_keys.begin();
        key = *it;
        static_sk_svg_text_path_available_keys.erase(it);
    } else {
        key = static_sk_svg_text_path_index++;
    }
    static_sk_svg_text_path[key] = std::move(value);
    return key;
}

void static_sk_svg_text_path_delete(int key) {
    static_sk_svg_text_path[key].reset();
    static_sk_svg_text_path.erase(key);
    static_sk_svg_text_path_available_keys.insert(key);
}

SkSVGTextPath *static_sk_svg_text_path_get(int key) {
    return static_sk_svg_text_path[key].get();
}

void static_sk_svg_text_path_set(int key, sk_sp<SkSVGTextPath> value) {
    static_sk_svg_text_path[key] = std::move(value);
}

sk_sp<SkSVGTextPath> static_sk_svg_text_path_move(int key) {
    return std::move(static_sk_svg_text_path[key]);
}
