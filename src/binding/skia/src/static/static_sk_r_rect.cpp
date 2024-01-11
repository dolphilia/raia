//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_r_rect.h"

static std::map<std::string, SkRRect> static_sk_r_rect;

void static_sk_r_rect_delete(const char *key) {
    static_sk_r_rect.erase(key);
}

SkRRect static_sk_r_rect_get(const char *key) {
    return static_sk_r_rect[key];
}

void static_sk_r_rect_set(const char *key, SkRRect value) {
    static_sk_r_rect[key] = value;
}