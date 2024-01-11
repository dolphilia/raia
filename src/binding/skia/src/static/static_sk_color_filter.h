//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
#define RAIA_SKIA_STATIC_SK_COLOR_FILTER_H

#include <string>
#include <map>
#include "include/core/SkColorFilter.h"

void static_sk_color_filter_delete(const char *key);
SkColorFilter *static_sk_color_filter_get(const char *key);
void static_sk_color_filter_set(const char *key, sk_sp<SkColorFilter> value);
sk_sp<SkColorFilter> static_sk_color_filter_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_FILTER_H
