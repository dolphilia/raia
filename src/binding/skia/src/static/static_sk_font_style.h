//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_H

#include <string>
#include <map>
#include "include/core/SkFontStyle.h"

void static_sk_font_style_delete(int key);
SkFontStyle static_sk_font_style_get(int key);
void static_sk_font_style_set(int key, SkFontStyle value);

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_H
