//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_3_H
#define RAIA_SKIA_STATIC_SK_POINT_3_H

#include <set>
#include <map>
#include "include/core/SkPoint3.h"
#include "export_api.h"

typedef int sk_point_3_t;

extern "C" {
RAIA_API void static_sk_point_3_delete(int key);
RAIA_API SkPoint3 * static_sk_point_3_get_ptr(int key);
}

int static_sk_point_3_make(SkPoint3 value);
SkPoint3 static_sk_point_3_get(int key);
void static_sk_point_3_set(int key, SkPoint3 value);

#endif //RAIA_SKIA_STATIC_SK_POINT_3_H
