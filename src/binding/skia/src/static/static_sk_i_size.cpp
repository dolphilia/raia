//
// Created by dolphilia on 2024/03/30.
//

#include "static_sk_i_size.h"

static std::set<int> static_sk_i_size_available_keys;
static std::map<int , SkISize> static_sk_i_size;
static int static_sk_i_size_index = 0;

int static_sk_i_size_make(SkISize value) {
    int key;
    if (!static_sk_i_size_available_keys.empty()) {
        auto it = static_sk_i_size_available_keys.begin();
        key = *it;
        static_sk_i_size_available_keys.erase(it);
    } else {
        key = static_sk_i_size_index++;
    }
    static_sk_i_size[key] = value;
    return key;
}

void static_sk_i_size_delete(int key) {
    static_sk_i_size.erase(key);
    static_sk_i_size_available_keys.insert(key);
}

SkISize static_sk_i_size_get(int key) {
    return static_sk_i_size[key];
}

void static_sk_i_size_set(int key, SkISize value) {
    static_sk_i_size[key] = value;
}