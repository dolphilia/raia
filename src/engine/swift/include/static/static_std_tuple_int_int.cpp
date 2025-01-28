//
// Created by dolphilia on 2024/01/11.
//

#include "static_std_tuple_int_int.h"
#include "static_std_tuple_int_int-internal.h"

static std::set<int> static_tuple_int_int_available_keys;
static std::map<int , std::tuple<int, int>> static_tuple_int_int;
static int static_tuple_int_int_index = 0;

int static_tuple_int_int_make(std::tuple<int, int> value) {
    int key;
    if (!static_tuple_int_int_available_keys.empty()) {
        auto it = static_tuple_int_int_available_keys.begin();
        key = *it;
        static_tuple_int_int_available_keys.erase(it);
    } else {
        key = static_tuple_int_int_index++;
    }
    static_tuple_int_int[key] = value;
    return key;
}

void static_tuple_int_int_delete(int key) {
    static_tuple_int_int.erase(key);
    static_tuple_int_int_available_keys.insert(key);
}

std::tuple<int, int> static_tuple_int_int_get(int key) {
    return static_tuple_int_int[key];
}

void static_tuple_int_int_set(int key, std::tuple<int, int> value) {
    static_tuple_int_int[key] = value;
}
