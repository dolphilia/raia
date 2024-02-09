//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_INFO_H
#define RAIA_SKIA_STATIC_SK_COLOR_INFO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkImageInfo.h"

typedef int sk_color_info_t;

int static_sk_color_info_make(SkColorInfo value);
extern "C" void static_sk_color_info_delete(int key);
SkColorInfo static_sk_color_info_get(int key);
void static_sk_color_info_set(int key, SkColorInfo value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_INFO_H
