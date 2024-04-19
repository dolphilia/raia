//
// Created by dolphilia on 2024/04/04.
//

#include "static_sk_v3.h"

static std::set<int> static_sk_v3_available_keys;
static std::map<int , SkV3> static_sk_v3;
static int static_sk_v3_index = 0;

int static_sk_v3_make(SkV3 value) {
    int key;
    if (!static_sk_v3_available_keys.empty()) {
        auto it = static_sk_v3_available_keys.begin();
        key = *it;
        static_sk_v3_available_keys.erase(it);
    } else {
        key = static_sk_v3_index++;
    }
    static_sk_v3[key] = value;
    return key;
}

void static_sk_v3_delete(int key) {
    static_sk_v3.erase(key);
    static_sk_v3_available_keys.insert(key);
}

SkV3 static_sk_v3_get(int key) {
    return static_sk_v3[key];
}

void static_sk_v3_set(int key, SkV3 value) {
    static_sk_v3[key] = value;
}