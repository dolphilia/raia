//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_H
#define RAIA_SKIA_STATIC_SK_FONT_H

#include <string>
#include <map>
#include "include/core/SkFont.h"

void static_sk_font_delete(const char *key);
SkFont static_sk_font_get(const char *key);
void static_sk_font_set(const char *key, SkFont value);

#endif //RAIA_SKIA_STATIC_SK_FONT_H
