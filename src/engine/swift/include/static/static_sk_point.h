//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_H
#define RAIA_SKIA_STATIC_SK_POINT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"
#include "export_api.h"

typedef int sk_point_t;

extern "C" {
RAIA_API void static_sk_point_delete(int key);
RAIA_API SkPoint * static_sk_point_get_ptr(int key);
RAIA_API SkPoint static_sk_point_get(int key);
}

int static_sk_point_make(SkPoint value);
void static_sk_point_set(int key, SkPoint value);

#endif //RAIA_SKIA_STATIC_SK_POINT_H
