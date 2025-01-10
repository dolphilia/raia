//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FLATTENABLE_H
#define RAIA_SKIA_STATIC_SK_FLATTENABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFlattenable.h"

typedef int sk_flattenable_t;

int static_sk_flattenable_make(sk_sp<SkFlattenable> value);
extern "C" void static_sk_flattenable_delete(int key);
extern "C" SkFlattenable *static_sk_flattenable_get(int key);
void static_sk_flattenable_set(int key, sk_sp<SkFlattenable> value);
sk_sp<SkFlattenable> static_sk_flattenable_move(int key);

#endif //RAIA_SKIA_STATIC_SK_FLATTENABLE_H
