#ifndef STATIC_STD_TUPLE_INT_INT_INTERNAL_H
#define STATIC_STD_TUPLE_INT_INT_INTERNAL_H
#include <set>
#include <map>
#include <tuple>
int static_tuple_int_int_make(std::tuple<int, int> value);
std::tuple<int, int> static_tuple_int_int_get(int key);
void static_tuple_int_int_set(int key, std::tuple<int, int> value);
#endif // STATIC_STD_TUPLE_INT_INT_INTERNAL_H
