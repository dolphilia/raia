//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_stop.h"

static std::set<int> static_sk_svg_stop_available_keys;
static std::map<int , sk_sp<SkSVGStop>> static_sk_svg_stop;
static int static_sk_svg_stop_index = 0;

int static_sk_svg_stop_make(sk_sp<SkSVGStop> value) {
    int key;
    if (!static_sk_svg_stop_available_keys.empty()) {
        auto it = static_sk_svg_stop_available_keys.begin();
        key = *it;
        static_sk_svg_stop_available_keys.erase(it);
    } else {
        key = static_sk_svg_stop_index++;
    }
    static_sk_svg_stop[key] = std::move(value);
    return key;
}

void static_sk_svg_stop_delete(int key) {
    static_sk_svg_stop[key].reset();
    static_sk_svg_stop.erase(key);
    static_sk_svg_stop_available_keys.insert(key);
}

SkSVGStop *static_sk_svg_stop_get(int key) {
    return static_sk_svg_stop[key].get();
}

void static_sk_svg_stop_set(int key, sk_sp<SkSVGStop> value) {
    static_sk_svg_stop[key] = std::move(value);
}

sk_sp<SkSVGStop> static_sk_svg_stop_move(int key) {
    return std::move(static_sk_svg_stop[key]);
}
