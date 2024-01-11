//
// Created by dolphilia on 2024/01/09.
//

#include "static_sk_path.h"

static std::map<std::string, SkPath> static_sk_path;

void static_sk_path_delete(const char *key) {
    static_sk_path.erase(key);
}

SkPath static_sk_path_get(const char *key) {
    return static_sk_path[key];
}

void static_sk_path_set(const char *key, const SkPath& value) {
    static_sk_path[key] = value;
}