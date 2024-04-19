//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_3_H
#define RAIA_SKIA_STATIC_SK_POINT_3_H

#include <set>
#include <map>
#include "include/core/SkPoint3.h"

typedef int sk_point_3_t;

int static_sk_point_3_make(SkPoint3 value);
extern "C" void static_sk_point_3_delete(int key);
SkPoint3 static_sk_point_3_get(int key);
void static_sk_point_3_set(int key, SkPoint3 value);

#endif //RAIA_SKIA_STATIC_SK_POINT_3_H
