//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_font_arguments.h"

static std::map<int , SkFontArguments> static_sk_font_arguments;
static int static_sk_font_arguments_index = 0;

int static_sk_font_arguments_make(SkFontArguments value) {
    static_sk_font_arguments[static_sk_font_arguments_index] = value;
    static_sk_font_arguments_index++;
    return static_sk_font_arguments_index - 1;
}

void static_sk_font_arguments_delete(int key) {
    static_sk_font_arguments.erase(key);
}

SkFontArguments static_sk_font_arguments_get(int key) {
    return static_sk_font_arguments[key];
}

void static_sk_font_arguments_set(int key, SkFontArguments value) {
    static_sk_font_arguments[key] = value;
}