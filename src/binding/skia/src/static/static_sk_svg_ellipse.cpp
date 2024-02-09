//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_ellipse.h"

static std::set<int> static_sk_svg_ellipse_available_keys;
static std::map<int , sk_sp<SkSVGEllipse>> static_sk_svg_ellipse;
static int static_sk_svg_ellipse_index = 0;

int static_sk_svg_ellipse_make(sk_sp<SkSVGEllipse> value) {
    int key;
    if (!static_sk_svg_ellipse_available_keys.empty()) {
        auto it = static_sk_svg_ellipse_available_keys.begin();
        key = *it;
        static_sk_svg_ellipse_available_keys.erase(it);
    } else {
        key = static_sk_svg_ellipse_index++;
    }
    static_sk_svg_ellipse[key] = std::move(value);
    return key;
}

void static_sk_svg_ellipse_delete(int key) {
    static_sk_svg_ellipse[key].reset();
    static_sk_svg_ellipse.erase(key);
    static_sk_svg_ellipse_available_keys.insert(key);
}

SkSVGEllipse *static_sk_svg_ellipse_get(int key) {
    return static_sk_svg_ellipse[key].get();
}

void static_sk_svg_ellipse_set(int key, sk_sp<SkSVGEllipse> value) {
    static_sk_svg_ellipse[key] = std::move(value);
}

sk_sp<SkSVGEllipse> static_sk_svg_ellipse_move(int key) {
    return std::move(static_sk_svg_ellipse[key]);
}