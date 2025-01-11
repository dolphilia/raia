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
#include "export_api.h"

typedef int sk_color_t;

extern "C" {
RAIA_API void static_sk_color_delete(int key);
RAIA_API SkColor static_sk_color_get_value(int key, int index);
}

int static_sk_color_make(SkSpan<SkColor> value);
SkSpan<SkColor> static_sk_color_get(int key);
void static_color_set(int key, SkSpan<SkColor> value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_H
