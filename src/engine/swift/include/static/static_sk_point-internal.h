#ifndef STATIC_SK_POINT_INTERNAL_H
#define STATIC_SK_POINT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkRect.h"
int static_sk_point_make(SkPoint value);
void static_sk_point_set(int key, SkPoint value);
SkPoint static_sk_point_get_entity(int key);
#endif // STATIC_SK_POINT_INTERNAL_H
