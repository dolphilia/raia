//
// Created by dolphilia on 2024/01/04.
//

#include "static_sk_rect.h"

static std::map<int , SkRect> static_sk_rect;

void static_sk_rect_delete(int key) {
    static_sk_rect.erase(key);
}

SkRect static_sk_rect_get(int key) {
    return static_sk_rect[key];
}

void static_sk_rect_set(int key, SkRect value) {
    static_sk_rect[key] = value;
}