//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
#define RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H

#include <string>
#include <map>
#include <tuple>

int static_tuple_int_int_make(std::tuple<int, int> value);
void static_tuple_int_int_delete(int key);
std::tuple<int, int> static_tuple_int_int_get(int key);
void static_tuple_int_int_set(int key, std::tuple<int, int> value);

#endif //RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
