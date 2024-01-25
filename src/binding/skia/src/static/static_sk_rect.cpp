//
// Created by dolphilia on 2024/01/04.
//

#include "static_sk_rect.h"

static std::map<int , SkRect> static_sk_rect;
static int static_sk_rect_index = 0;

int static_sk_rect_make(SkRect value) {
    static_sk_rect[static_sk_rect_index] = value;
    static_sk_rect_index++;
    return static_sk_rect_index - 1;
}

void static_sk_rect_delete(int key) {
    static_sk_rect.erase(key);
}

SkRect static_sk_rect_get(int key) {
    return static_sk_rect[key];
}

void static_sk_rect_set(int key, SkRect value) {
    static_sk_rect[key] = value;
}