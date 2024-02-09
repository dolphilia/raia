//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_H
#define RAIA_SKIA_STATIC_SK_PATH_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPath.h"

typedef int sk_path_t;

int static_sk_path_make(const SkPath& value);
extern "C" void static_sk_path_delete(int key);
SkPath static_sk_path_get(int key);
void static_sk_path_set(int key, const SkPath& value);

#endif //RAIA_SKIA_STATIC_SK_PATH_H
