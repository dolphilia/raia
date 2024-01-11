//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_INFO_H
#define RAIA_SKIA_STATIC_SK_COLOR_INFO_H

#include <string>
#include <map>
#include "include/core/SkImageInfo.h"

void static_sk_color_info_delete(const char *key);
SkColorInfo static_sk_color_info_get(const char *key);
void static_sk_color_info_set(const char *key, SkColorInfo value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_INFO_H
