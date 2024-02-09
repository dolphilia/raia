//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_line.h"

static std::set<int> static_sk_svg_line_available_keys;
static std::map<int , sk_sp<SkSVGLine>> static_sk_svg_line;
static int static_sk_svg_line_index = 0;

int static_sk_svg_line_make(sk_sp<SkSVGLine> value) {
    int key;
    if (!static_sk_svg_line_available_keys.empty()) {
        auto it = static_sk_svg_line_available_keys.begin();
        key = *it;
        static_sk_svg_line_available_keys.erase(it);
    } else {
        key = static_sk_svg_line_index++;
    }
    static_sk_svg_line[key] = std::move(value);
    return key;
}

void static_sk_svg_line_delete(int key) {
    static_sk_svg_line[key].reset();
    static_sk_svg_line.erase(key);
    static_sk_svg_line_available_keys.insert(key);
}

SkSVGLine *static_sk_svg_line_get(int key) {
    return static_sk_svg_line[key].get();
}

void static_sk_svg_line_set(int key, sk_sp<SkSVGLine> value) {
    static_sk_svg_line[key] = std::move(value);
}

sk_sp<SkSVGLine> static_sk_svg_line_move(int key) {
    return std::move(static_sk_svg_line[key]);
}
