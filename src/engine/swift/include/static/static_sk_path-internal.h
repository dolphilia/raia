#ifndef STATIC_SK_PATH_INTERNAL_H
#define STATIC_SK_PATH_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPath.h"
int static_sk_path_make(const SkPath& value);
SkPath static_sk_path_get(int key);
void static_sk_path_set(int key, const SkPath& value);
#endif // STATIC_SK_PATH_INTERNAL_H
