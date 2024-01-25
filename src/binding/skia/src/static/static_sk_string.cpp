//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_string.h"

#include <utility>

static std::map<int , SkString> static_sk_string;
static int static_sk_string_index = 0;

int static_sk_string_make(SkString value) {
    static_sk_string[static_sk_string_index] = std::move(value);
    static_sk_string_index++;
    return static_sk_string_index - 1;
}

void static_sk_string_delete(int key) {
    static_sk_string.erase(key);
}

SkString static_sk_string_get(int key) {
    return static_sk_string[key];
}

void static_sk_string_set(int key, SkString value) {
    static_sk_string[key] = std::move(value);
}