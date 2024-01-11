//
// Created by dolphilia on 2024/01/11.
//

#include "static_tuple_int_int.h"

static std::map<std::string, std::tuple<int, int>> static_tuple_int_int;

void static_tuple_int_int_delete(const char *key) {
    static_tuple_int_int.erase(key);
}

std::tuple<int, int> static_tuple_int_int_get(const char *key, int index) {
    return static_tuple_int_int[key];
}

void static_tuple_int_int_set(const char *key, std::tuple<int, int> value) {
    static_tuple_int_int[key] = std::move(value);
}