//
// Created by dolphilia on 2024/04/08.
//

#include "static_sk_size_t.h"

static std::set<int> static_sk_size_available_keys;
static std::map<int , SkSize> static_sk_size;
static int static_sk_size_index = 0;

int static_sk_size_make(SkSize value) {
    int key;
    if (!static_sk_size_available_keys.empty()) {
        auto it = static_sk_size_available_keys.begin();
        key = *it;
        static_sk_size_available_keys.erase(it);
    } else {
        key = static_sk_size_index++;
    }
    static_sk_size[key] = value;
    return key;
}

void static_sk_size_delete(int key) {
    static_sk_size.erase(key);
    static_sk_size_available_keys.insert(key);
}

SkSize static_sk_size_get(int key) {
    return static_sk_size[key];
}

void static_sk_size_set(int key, SkSize value) {
    static_sk_size[key] = value;
}