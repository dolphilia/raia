//
// Created by dolphilia on 2024/01/04.
//

#include "static_sk_rect.h"

static std::map<std::string, SkRect> static_sk_rect;

void static_sk_rect_delete(const char *key) {
    static_sk_rect.erase(key);
}

SkRect static_sk_rect_get(const char *key) {
    return static_sk_rect[key];
}

void static_sk_rect_set(const char *key, SkRect value) {
    static_sk_rect[key] = value;
}