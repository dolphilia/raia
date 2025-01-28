#ifndef STATIC_SK_COLOR_INFO_INTERNAL_H
#define STATIC_SK_COLOR_INFO_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkImageInfo.h"
int static_sk_color_info_make(SkColorInfo value);
SkColorInfo static_sk_color_info_get(int key);
void static_sk_color_info_set(int key, SkColorInfo value);
#endif // STATIC_SK_COLOR_INFO_INTERNAL_H
