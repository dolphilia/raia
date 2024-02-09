//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_color_matrix.h"

static std::set<int> static_sk_svg_fe_color_matrix_available_keys;
static std::map<int , sk_sp<SkSVGFeColorMatrix>> static_sk_svg_fe_color_matrix;
static int static_sk_svg_fe_color_matrix_index = 0;

int static_sk_svg_fe_color_matrix_make(sk_sp<SkSVGFeColorMatrix> value) {
    int key;
    if (!static_sk_svg_fe_color_matrix_available_keys.empty()) {
        auto it = static_sk_svg_fe_color_matrix_available_keys.begin();
        key = *it;
        static_sk_svg_fe_color_matrix_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_color_matrix_index++;
    }
    static_sk_svg_fe_color_matrix[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_color_matrix_delete(int key) {
    static_sk_svg_fe_color_matrix[key].reset();
    static_sk_svg_fe_color_matrix.erase(key);
    static_sk_svg_fe_color_matrix_available_keys.insert(key);
}

SkSVGFeColorMatrix *static_sk_svg_fe_color_matrix_get(int key) {
    return static_sk_svg_fe_color_matrix[key].get();
}

void static_sk_svg_fe_color_matrix_set(int key, sk_sp<SkSVGFeColorMatrix> value) {
    static_sk_svg_fe_color_matrix[key] = std::move(value);
}

sk_sp<SkSVGFeColorMatrix> static_sk_svg_fe_color_matrix_move(int key) {
    return std::move(static_sk_svg_fe_color_matrix[key]);
}