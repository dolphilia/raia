//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font.h"

static std::map<std::string, SkFont> static_sk_font;

void static_sk_font_delete(const char *key) {
    static_sk_font.erase(key);
}

SkFont static_sk_font_get(const char *key) {
    return static_sk_font[key];
}

void static_sk_font_set(const char *key, SkFont value) {
    static_sk_font[key] = std::move(value);
}