//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_H
#define RAIA_SKIA_STATIC_SK_COLOR_H

#include <string>
#include <map>
#include "include/private/base/SkSpan_impl.h"
#include "include/core/SkColor.h"

void static_sk_color_delete(const char *key);
SkSpan<SkColor> static_sk_color_get(const char *key);
void static_color_set(const char *key, SkSpan<SkColor> value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_H
