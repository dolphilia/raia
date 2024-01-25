//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_r_rect.h"

static std::map<int , SkRRect> static_sk_r_rect;
static int static_sk_r_rect_index = 0;

int static_sk_r_rect_make(SkRRect value) {
    static_sk_r_rect[static_sk_r_rect_index] = value;
    static_sk_r_rect_index++;
    return static_sk_r_rect_index - 1;
}

void static_sk_r_rect_delete(int key) {
    static_sk_r_rect.erase(key);
}

SkRRect static_sk_r_rect_get(int key) {
    return static_sk_r_rect[key];
}

void static_sk_r_rect_set(int key, SkRRect value) {
    static_sk_r_rect[key] = value;
}