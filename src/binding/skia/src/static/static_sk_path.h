//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_H
#define RAIA_SKIA_STATIC_SK_PATH_H

#include <string>
#include <map>
#include "include/core/SkPath.h"

void static_sk_path_delete(const char *key);
SkPath static_sk_path_get(const char *key);
void static_sk_path_set(const char *key, const SkPath& value);

#endif //RAIA_SKIA_STATIC_SK_PATH_H
