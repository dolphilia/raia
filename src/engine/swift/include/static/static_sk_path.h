//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_H
#define RAIA_SKIA_STATIC_SK_PATH_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPath.h"
#include "export_api.h"

typedef int sk_path_t;

extern "C" {
RAIA_API void static_sk_path_delete(int key);
RAIA_API SkPath * static_sk_path_get_ptr(int key);
}

int static_sk_path_make(const SkPath& value);
SkPath static_sk_path_get(int key);
void static_sk_path_set(int key, const SkPath& value);

#endif //RAIA_SKIA_STATIC_SK_PATH_H
