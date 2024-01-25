//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_i_rect.h"

static std::map<int , SkIRect> static_sk_i_rect;
static int static_sk_i_rect_index = 0;

int static_sk_i_rect_make(SkIRect value) {
    static_sk_i_rect[static_sk_i_rect_index] = value;
    static_sk_i_rect_index++;
    return static_sk_i_rect_index - 1;
}

void static_sk_i_rect_delete(int key) {
    static_sk_i_rect.erase(key);
}

SkIRect static_sk_i_rect_get(int key) {
    return static_sk_i_rect[key];
}

void static_sk_i_rect_set(int key, SkIRect value) {
    static_sk_i_rect[key] = value;
}