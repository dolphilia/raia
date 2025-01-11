//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
#define RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H

#include <set>
#include <string>
#include <map>
#include <tuple>
#include "export_api.h"

typedef int tuple_int_int_t;

extern "C" {
RAIA_API void static_tuple_int_int_delete(int key);
}

int static_tuple_int_int_make(std::tuple<int, int> value);
std::tuple<int, int> static_tuple_int_int_get(int key);
void static_tuple_int_int_set(int key, std::tuple<int, int> value);

#endif //RAIA_SKIA_STATIC_STD_TUPLE_INT_INT_H
