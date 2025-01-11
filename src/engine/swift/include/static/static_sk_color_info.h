//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_INFO_H
#define RAIA_SKIA_STATIC_SK_COLOR_INFO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkImageInfo.h"
#include "export_api.h"

typedef int sk_color_info_t;

extern "C" {
RAIA_API void static_sk_color_info_delete(int key);
RAIA_API SkColorInfo * static_sk_color_info_get_ptr(int key);
}

int static_sk_color_info_make(SkColorInfo value);
SkColorInfo static_sk_color_info_get(int key);
void static_sk_color_info_set(int key, SkColorInfo value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_INFO_H
