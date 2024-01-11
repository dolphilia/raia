//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_color_info.h"

static std::map<std::string, SkColorInfo> static_sk_color_info;

void static_sk_color_info_delete(const char *key) {
    static_sk_color_info.erase(key);
}

SkColorInfo static_sk_color_info_get(const char *key) {
    return static_sk_color_info[key];
}

void static_sk_color_info_set(const char *key, SkColorInfo value) {
    static_sk_color_info[key] = value;
}