//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
#define RAIA_SKIA_STATIC_SK_COLOR_FILTER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColorFilter.h"
#include "export_api.h"

typedef int sk_color_filter_t;

extern "C" {
RAIA_API void static_sk_color_filter_delete(int key);
RAIA_API SkColorFilter *static_sk_color_filter_get(int key);
}

int static_sk_color_filter_make(sk_sp<SkColorFilter> value);
void static_sk_color_filter_set(int key, sk_sp<SkColorFilter> value);
sk_sp<SkColorFilter> static_sk_color_filter_move(int key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
