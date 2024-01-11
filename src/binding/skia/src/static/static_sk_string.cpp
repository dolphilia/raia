//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_string.h"

#include <utility>

static std::map<std::string, SkString> static_sk_string;

void static_sk_string_delete(const char *key) {
    static_sk_string.erase(key);
}

SkString static_sk_string_get(const char *key) {
    return static_sk_string[key];
}

void static_sk_string_set(const char *key, SkString value) {
    static_sk_string[key] = std::move(value);
}