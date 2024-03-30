//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_4F_H
#define RAIA_SKIA_STATIC_SK_COLOR_4F_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColor.h"

typedef int sk_color_4f_t;

int static_sk_color_4f_make(SkColor4f value);
extern "C" void static_sk_color_4f_delete(int key);
SkColor4f static_sk_color_4f_get(int key);
void static_sk_color_4f_set(int key, SkColor4f value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_4F_H
