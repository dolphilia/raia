//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_H
#define RAIA_SKIA_STATIC_SK_POINT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"

typedef int sk_point_t;

int static_sk_point_make(SkPoint value);
extern "C" void static_sk_point_delete(int key);
SkPoint static_sk_point_get(int key);
void static_sk_point_set(int key, SkPoint value);

#endif //RAIA_SKIA_STATIC_SK_POINT_H
