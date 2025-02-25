#ifndef STATIC_SK_COLOR_FILTER_INTERNAL_H
#define STATIC_SK_COLOR_FILTER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkColorFilter.h"
int static_sk_color_filter_make(sk_sp<SkColorFilter> value);
void static_sk_color_filter_set(int key, sk_sp<SkColorFilter> value);
sk_sp<SkColorFilter> static_sk_color_filter_get_entity(int key);
#endif // STATIC_SK_COLOR_FILTER_INTERNAL_H
