#ifndef STATIC_SK_SIZE_T_INTERNAL_H
#define STATIC_SK_SIZE_T_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkRect.h"
int static_sk_size_make(SkSize value);
SkSize static_sk_size_get_entity(int key);
void static_sk_size_set(int key, SkSize value);
#endif // STATIC_SK_SIZE_T_INTERNAL_H
