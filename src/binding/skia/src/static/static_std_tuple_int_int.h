//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
#define RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H

#include <string>
#include <map>
#include <tuple>

void static_tuple_int_int_delete(const char *key);
std::tuple<int, int> static_tuple_int_int_get(const char *key);
void static_tuple_int_int_set(const char *key, std::tuple<int, int> value);

#endif //RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
