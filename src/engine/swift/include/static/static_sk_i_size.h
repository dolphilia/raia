//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_I_SIZE_H
#define RAIA_SKIA_STATIC_SK_I_SIZE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"

typedef int sk_i_size_t;

int static_sk_i_size_make(SkISize value);
extern "C" void static_sk_i_size_delete(int key);
SkISize static_sk_i_size_get(int key);
void static_sk_i_size_set(int key, SkISize value);

#endif //RAIA_SKIA_STATIC_SK_I_SIZE_H
