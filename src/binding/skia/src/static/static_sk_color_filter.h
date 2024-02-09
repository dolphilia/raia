//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
#define RAIA_SKIA_STATIC_SK_COLOR_FILTER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColorFilter.h"

typedef int sk_color_filter_t;

int static_sk_color_filter_make(sk_sp<SkColorFilter> value);
extern "C" void static_sk_color_filter_delete(int key);
extern "C" SkColorFilter *static_sk_color_filter_get(int key);
void static_sk_color_filter_set(int key, sk_sp<SkColorFilter> value);
sk_sp<SkColorFilter> static_sk_color_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
