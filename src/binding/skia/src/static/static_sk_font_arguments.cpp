//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font_arguments.h"

static std::set<int> static_sk_font_arguments_available_keys;
static std::map<int , SkFontArguments> static_sk_font_arguments;
static int static_sk_font_arguments_index = 0;

int static_sk_font_arguments_make(SkFontArguments value) {
    int key;
    if (!static_sk_font_arguments_available_keys.empty()) {
        auto it = static_sk_font_arguments_available_keys.begin();
        key = *it;
        static_sk_font_arguments_available_keys.erase(it);
    } else {
        key = static_sk_font_arguments_index++;
    }
    static_sk_font_arguments[key] = value;
    return key;
}

void static_sk_font_arguments_delete(int key) {
    static_sk_font_arguments.erase(key);
    static_sk_font_arguments_available_keys.insert(key);
}

SkFontArguments static_sk_font_arguments_get(int key) {
    return static_sk_font_arguments[key];
}

void static_sk_font_arguments_set(int key, SkFontArguments value) {
    static_sk_font_arguments[key] = value;
}