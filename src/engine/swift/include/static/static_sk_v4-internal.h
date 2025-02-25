#ifndef STATIC_SK_V4_INTERNAL_H
#define STATIC_SK_V4_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkM44.h"
int static_sk_v4_make(SkV4 value);
SkV4 static_sk_v4_get_entity(int key);
void static_sk_v4_set(int key, SkV4 value);
#endif // STATIC_SK_V4_INTERNAL_H
