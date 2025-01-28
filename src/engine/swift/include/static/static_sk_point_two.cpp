//
// Created by dolphilia on 24/06/20.
//

#include "static_sk_point_two.h"
#include "static_sk_point_two-internal.h"

static std::set<int> static_sk_point_two_available_keys;
static std::map<int , SkPoint[2]> static_sk_point_two;
static int static_sk_point_two_index = 0;

int static_sk_point_two_make(SkPoint value1, SkPoint value2) {
    int key;
    if (!static_sk_point_two_available_keys.empty()) {
        auto it = static_sk_point_two_available_keys.begin();
        key = *it;
        static_sk_point_two_available_keys.erase(it);
    } else {
        key = static_sk_point_two_index++;
    }
    static_sk_point_two[key][0] = value1;
    static_sk_point_two[key][1] = value2;
    return key;
}

int static_sk_point_two_make_float(float fx1, float fy1, float fx2, float fy2) {
    int key;
    if (!static_sk_point_two_available_keys.empty()) {
        auto it = static_sk_point_two_available_keys.begin();
        key = *it;
        static_sk_point_two_available_keys.erase(it);
    } else {
        key = static_sk_point_two_index++;
    }
    static_sk_point_two[key][0].fX = fx1;
    static_sk_point_two[key][0].fY = fy1;
    static_sk_point_two[key][1].fX = fx2;
    static_sk_point_two[key][1].fY = fy2;
    return key;
}

void static_sk_point_two_delete(int key) {
    static_sk_point_two.erase(key);
    static_sk_point_two_available_keys.insert(key);
}

//SkPoint static_sk_point_two_get(int key) {
//    return static_sk_point_two[key];
//}

void * static_sk_point_two_get_ptr(int key) { // -> SkPoint *
    return reinterpret_cast<SkPoint *>(&static_sk_point_two[key]);
}

void static_sk_point_two_set(int key, SkPoint value1, SkPoint value2) {
    static_sk_point_two[key][0] = value1;
    static_sk_point_two[key][1] = value2;
}
