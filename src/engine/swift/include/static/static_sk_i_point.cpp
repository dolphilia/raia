//
// Created by dolphilia on 2024/03/30.
//

#include "static_sk_i_point.h"
#include "static_sk_i_point-internal.h"

static std::set<int> static_sk_i_point_available_keys;
static std::map<int , SkIPoint> static_sk_i_point;
static int static_sk_i_point_index = 0;

int static_sk_i_point_make(SkIPoint value) {
    int key;
    if (!static_sk_i_point_available_keys.empty()) {
        auto it = static_sk_i_point_available_keys.begin();
        key = *it;
        static_sk_i_point_available_keys.erase(it);
    } else {
        key = static_sk_i_point_index++;
    }
    static_sk_i_point[key] = value;
    return key;
}

void static_sk_i_point_delete(int key) {
    static_sk_i_point.erase(key);
    static_sk_i_point_available_keys.insert(key);
}

SkIPoint static_sk_i_point_get(int key) {
    return static_sk_i_point[key];
}

void * static_sk_i_point_get_ptr(int key) { // -> SkIPoint *
    return &static_sk_i_point[key];
}

void static_sk_i_point_set(int key, SkIPoint value) {
    static_sk_i_point[key] = value;
}
