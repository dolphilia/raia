//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_H
#define RAIA_SKIA_STATIC_SK_COLOR_H

#include <set>
#include <string>
#include <map>
#include "include/private/base/SkSpan_impl.h"
#include "include/core/SkColor.h"

typedef int sk_color_t;

int static_sk_color_make(SkSpan<SkColor> value);
extern "C" void static_sk_color_delete(int key);
SkSpan<SkColor> static_sk_color_get(int key);
void static_color_set(int key, SkSpan<SkColor> value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_H
