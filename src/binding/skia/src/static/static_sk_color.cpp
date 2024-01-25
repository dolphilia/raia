//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_color.h"

static std::map<int , SkSpan<SkColor>> static_const_sk_color;
static int static_const_sk_color_index = 0;

int static_const_sk_color_make(SkSpan<SkColor> value) {
    static_const_sk_color[static_const_sk_color_index] = value;
    static_const_sk_color_index++;
    return static_const_sk_color_index - 1;
}

void static_sk_color_delete(int key) {
    static_const_sk_color.erase(key);
}

SkSpan<SkColor> static_sk_color_get(int key) {
    return static_const_sk_color[key];
}

void static_color_set(int key, SkSpan<SkColor> value) {
    static_const_sk_color[key] = value;
}