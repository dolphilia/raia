//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_r_rect.h"

static std::map<int , SkRRect> static_sk_r_rect;

void static_sk_r_rect_delete(int key) {
    static_sk_r_rect.erase(key);
}

SkRRect static_sk_r_rect_get(int key) {
    return static_sk_r_rect[key];
}

void static_sk_r_rect_set(int key, SkRRect value) {
    static_sk_r_rect[key] = value;
}