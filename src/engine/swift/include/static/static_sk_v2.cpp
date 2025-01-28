//
// Created by dolphilia on 2024/04/04.
//

#include "static_sk_v2.h"
#include "static_sk_v2-internal.h"

static std::set<int> static_sk_v2_available_keys;
static std::map<int , SkV2> static_sk_v2;
static int static_sk_v2_index = 0;

int static_sk_v2_make(SkV2 value) {
    int key;
    if (!static_sk_v2_available_keys.empty()) {
        auto it = static_sk_v2_available_keys.begin();
        key = *it;
        static_sk_v2_available_keys.erase(it);
    } else {
        key = static_sk_v2_index++;
    }
    static_sk_v2[key] = value;
    return key;
}

void static_sk_v2_delete(int key) {
    static_sk_v2.erase(key);
    static_sk_v2_available_keys.insert(key);
}

SkV2 static_sk_v2_get(int key) {
    return static_sk_v2[key];
}

void * static_sk_v2_get_ptr(int key) { // -> SkV2 *
    return &static_sk_v2[key];
}

void static_sk_v2_set(int key, SkV2 value) {
    static_sk_v2[key] = value;
}
