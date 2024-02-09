//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_rect.h"

static std::set<int> static_sk_svg_rect_available_keys;
static std::map<int , sk_sp<SkSVGRect>> static_sk_svg_rect;
static int static_sk_svg_rect_index = 0;

int static_sk_svg_rect_make(sk_sp<SkSVGRect> value) {
    int key;
    if (!static_sk_svg_rect_available_keys.empty()) {
        auto it = static_sk_svg_rect_available_keys.begin();
        key = *it;
        static_sk_svg_rect_available_keys.erase(it);
    } else {
        key = static_sk_svg_rect_index++;
    }
    static_sk_svg_rect[key] = std::move(value);
    return key;
}

void static_sk_svg_rect_delete(int key) {
    static_sk_svg_rect[key].reset();
    static_sk_svg_rect.erase(key);
    static_sk_svg_rect_available_keys.insert(key);
}

SkSVGRect *static_sk_svg_rect_get(int key) {
    return static_sk_svg_rect[key].get();
}

void static_sk_svg_rect_set(int key, sk_sp<SkSVGRect> value) {
    static_sk_svg_rect[key] = std::move(value);
}

sk_sp<SkSVGRect> static_sk_svg_rect_move(int key) {
    return std::move(static_sk_svg_rect[key]);
}
