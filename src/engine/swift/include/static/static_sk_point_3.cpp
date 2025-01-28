//
// Created by dolphilia on 2024/04/05.
//

#include "static_sk_point_3.h"
#include "static_sk_point_3-internal.h"

static std::set<int> static_sk_point_3_available_keys;
static std::map<int , SkPoint3> static_sk_point_3;
static int static_sk_point_3_index = 0;

int static_sk_point_3_make(SkPoint3 value) {
    int key;
    if (!static_sk_point_3_available_keys.empty()) {
        auto it = static_sk_point_3_available_keys.begin();
        key = *it;
        static_sk_point_3_available_keys.erase(it);
    } else {
        key = static_sk_point_3_index++;
    }
    static_sk_point_3[key] = value;
    return key;
}

void static_sk_point_3_delete(int key) {
    static_sk_point_3.erase(key);
    static_sk_point_3_available_keys.insert(key);
}

SkPoint3 static_sk_point_3_get(int key) {
    return static_sk_point_3[key];
}

void * static_sk_point_3_get_ptr(int key) { // -> SkPoint3 *
    return &static_sk_point_3[key];
}

void static_sk_point_3_set(int key, SkPoint3 value) {
    static_sk_point_3[key] = value;
}
