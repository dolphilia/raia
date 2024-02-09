//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_t_span.h"

static std::set<int> static_sk_svg_t_span_available_keys;
static std::map<int , sk_sp<SkSVGTSpan>> static_sk_svg_t_span;
static int static_sk_svg_t_span_index = 0;

int static_sk_svg_t_span_make(sk_sp<SkSVGTSpan> value) {
    int key;
    if (!static_sk_svg_t_span_available_keys.empty()) {
        auto it = static_sk_svg_t_span_available_keys.begin();
        key = *it;
        static_sk_svg_t_span_available_keys.erase(it);
    } else {
        key = static_sk_svg_t_span_index++;
    }
    static_sk_svg_t_span[key] = std::move(value);
    return key;
}

void static_sk_svg_t_span_delete(int key) {
    static_sk_svg_t_span[key].reset();
    static_sk_svg_t_span.erase(key);
    static_sk_svg_t_span_available_keys.insert(key);
}

SkSVGTSpan *static_sk_svg_t_span_get(int key) {
    return static_sk_svg_t_span[key].get();
}

void static_sk_svg_t_span_set(int key, sk_sp<SkSVGTSpan> value) {
    static_sk_svg_t_span[key] = std::move(value);
}

sk_sp<SkSVGTSpan> static_sk_svg_t_span_move(int key) {
    return std::move(static_sk_svg_t_span[key]);
}
