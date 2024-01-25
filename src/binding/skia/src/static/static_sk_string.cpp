//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_string.h"

#include <utility>

static std::map<int , SkString> static_sk_string;

void static_sk_string_delete(int key) {
    static_sk_string.erase(key);
}

SkString static_sk_string_get(int key) {
    return static_sk_string[key];
}

void static_sk_string_set(int key, SkString value) {
    static_sk_string[key] = std::move(value);
}