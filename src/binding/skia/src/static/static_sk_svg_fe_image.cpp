//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_image.h"

static std::set<int> static_sk_svg_fe_image_available_keys;
static std::map<int , sk_sp<SkSVGFeImage>> static_sk_svg_fe_image;
static int static_sk_svg_fe_image_index = 0;

int static_sk_svg_fe_image_make(sk_sp<SkSVGFeImage> value) {
    int key;
    if (!static_sk_svg_fe_image_available_keys.empty()) {
        auto it = static_sk_svg_fe_image_available_keys.begin();
        key = *it;
        static_sk_svg_fe_image_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_image_index++;
    }
    static_sk_svg_fe_image[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_image_delete(int key) {
    static_sk_svg_fe_image[key].reset();
    static_sk_svg_fe_image.erase(key);
    static_sk_svg_fe_image_available_keys.insert(key);
}

SkSVGFeImage *static_sk_svg_fe_image_get(int key) {
    return static_sk_svg_fe_image[key].get();
}

void static_sk_svg_fe_image_set(int key, sk_sp<SkSVGFeImage> value) {
    static_sk_svg_fe_image[key] = std::move(value);
}

sk_sp<SkSVGFeImage> static_sk_svg_fe_image_move(int key) {
    return std::move(static_sk_svg_fe_image[key]);
}
