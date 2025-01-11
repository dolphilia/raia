//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_4F_H
#define RAIA_SKIA_STATIC_SK_COLOR_4F_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColor.h"
#include "export_api.h"

typedef int sk_color_4f_t;

extern "C" {
RAIA_API void static_sk_color_4f_delete(int key);
RAIA_API SkColor4f * static_sk_color_4f_get_ptr(int key);
}

int static_sk_color_4f_make(SkColor4f value);
SkColor4f static_sk_color_4f_get(int key);
void static_sk_color_4f_set(int key, SkColor4f value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_4F_H
