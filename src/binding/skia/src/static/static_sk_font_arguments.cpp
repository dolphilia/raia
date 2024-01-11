//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font_arguments.h"

static std::map<std::string, SkFontArguments> static_sk_font_arguments;

void static_sk_font_arguments_delete(const char *key) {
    static_sk_font_arguments.erase(key);
}

SkFontArguments static_sk_font_arguments_get(const char *key) {
    return static_sk_font_arguments[key];
}

void static_sk_font_arguments_set(const char *key, SkFontArguments value) {
    static_sk_font_arguments[key] = value;
}