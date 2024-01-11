//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_H

#include <string>
#include <map>
#include "include/core/SkFontStyle.h"

void static_sk_font_style_delete(const char *key);
SkFontStyle static_sk_font_style_get(const char *key);
void static_sk_font_style_set(const char *key, SkFontStyle value);

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_H
