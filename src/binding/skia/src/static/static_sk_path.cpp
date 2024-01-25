//
// Created by dolphilia on 2024/01/09.
//

#include "static_sk_path.h"

static std::map<int , SkPath> static_sk_path;

void static_sk_path_delete(int key) {
    static_sk_path.erase(key);
}

SkPath static_sk_path_get(int key) {
    return static_sk_path[key];
}

void static_sk_path_set(int key, const SkPath& value) {
    static_sk_path[key] = value;
}