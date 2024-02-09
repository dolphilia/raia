//
// Created by dolphilia on 2024/02/03.
//

#include "static_sk_svg_circle.h"

static std::set<int> static_sk_svg_circle_available_keys;
static std::map<int , sk_sp<SkSVGCircle>> static_sk_svg_circle;
static int static_sk_svg_circle_index = 0;

int static_sk_svg_circle_make(sk_sp<SkSVGCircle> value) {
    int key;
    if (!static_sk_svg_circle_available_keys.empty()) {
        auto it = static_sk_svg_circle_available_keys.begin();
        key = *it;
        static_sk_svg_circle_available_keys.erase(it);
    } else {
        key = static_sk_svg_circle_index++;
    }
    static_sk_svg_circle[key] = std::move(value);
    return key;
}

void static_sk_svg_circle_delete(int key) {
    static_sk_svg_circle[key].reset();
    static_sk_svg_circle.erase(key);
    static_sk_svg_circle_available_keys.insert(key);
}

SkSVGCircle *static_sk_svg_circle_get(int key) {
    return static_sk_svg_circle[key].get();
}

void static_sk_svg_circle_set(int key, sk_sp<SkSVGCircle> value) {
    static_sk_svg_circle[key] = std::move(value);
}

sk_sp<SkSVGCircle> static_sk_svg_circle_move(int key) {
    return std::move(static_sk_svg_circle[key]);
}