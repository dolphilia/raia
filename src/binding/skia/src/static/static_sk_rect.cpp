//
// Created by dolphilia on 2024/01/04.
//

#include "static_sk_rect.h"

static std::map<std::string, SkRect> static_sk_rect;

void static_sk_rect_delete(const char *sk_rect_key) {
    static_sk_rect.erase(sk_rect_key);
}

SkRect static_sk_rect_get(const char *sk_rect_key) {
    return static_sk_rect[sk_rect_key];
}

void static_sk_rect_set(const char *sk_rect_key, SkRect rect) {
    static_sk_rect[sk_rect_key] = rect;
}