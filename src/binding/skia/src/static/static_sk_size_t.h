//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_SIZE_T_H
#define RAIA_SKIA_STATIC_SK_SIZE_T_H

#include <set>
#include <map>
#include "include/core/SkRect.h"

typedef int sk_size_t;

int static_sk_size_make(SkSize value);
extern "C" void static_sk_size_delete(int key);
SkSize static_sk_size_get(int key);
void static_sk_size_set(int key, SkSize value);

#endif //RAIA_SKIA_STATIC_SK_SIZE_T_H
