//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_gaussian_blur.h"

static std::set<int> static_sk_svg_fe_gaussian_blur_available_keys;
static std::map<int , sk_sp<SkSVGFeGaussianBlur>> static_sk_svg_fe_gaussian_blur;
static int static_sk_svg_fe_gaussian_blur_index = 0;

int static_sk_svg_fe_gaussian_blur_make(sk_sp<SkSVGFeGaussianBlur> value) {
    int key;
    if (!static_sk_svg_fe_gaussian_blur_available_keys.empty()) {
        auto it = static_sk_svg_fe_gaussian_blur_available_keys.begin();
        key = *it;
        static_sk_svg_fe_gaussian_blur_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_gaussian_blur_index++;
    }
    static_sk_svg_fe_gaussian_blur[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_gaussian_blur_delete(int key) {
    static_sk_svg_fe_gaussian_blur[key].reset();
    static_sk_svg_fe_gaussian_blur.erase(key);
    static_sk_svg_fe_gaussian_blur_available_keys.insert(key);
}

SkSVGFeGaussianBlur *static_sk_svg_fe_gaussian_blur_get(int key) {
    return static_sk_svg_fe_gaussian_blur[key].get();
}

void static_sk_svg_fe_gaussian_blur_set(int key, sk_sp<SkSVGFeGaussianBlur> value) {
    static_sk_svg_fe_gaussian_blur[key] = std::move(value);
}

sk_sp<SkSVGFeGaussianBlur> static_sk_svg_fe_gaussian_blur_move(int key) {
    return std::move(static_sk_svg_fe_gaussian_blur[key]);
}
