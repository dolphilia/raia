//
// Created by dolphilia on 2024/01/11.
//

#include "static_std_tuple_int_int.h"

static std::map<int , std::tuple<int, int>> static_tuple_int_int;
static int static_tuple_int_int_index = 0;

int static_tuple_int_int_make(std::tuple<int, int> value) {
    static_tuple_int_int[static_tuple_int_int_index] = value;
    static_tuple_int_int_index++;
    return static_tuple_int_int_index - 1;
}

void static_tuple_int_int_delete(int key) {
    static_tuple_int_int.erase(key);
}

std::tuple<int, int> static_tuple_int_int_get(int key) {
    return static_tuple_int_int[key];
}

void static_tuple_int_int_set(int key, std::tuple<int, int> value) {
    static_tuple_int_int[key] = value;
}