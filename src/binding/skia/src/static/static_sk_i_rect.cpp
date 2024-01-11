//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_i_rect.h"

static std::map<std::string, SkIRect> static_sk_i_rect;

void static_sk_i_rect_delete(const char *key) {
    static_sk_i_rect.erase(key);
}

SkIRect static_sk_i_rect_get(const char *key) {
    return static_sk_i_rect[key];
}

void static_sk_i_rect_set(const char *key, SkIRect value) {
    static_sk_i_rect[key] = value;
}