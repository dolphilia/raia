//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFontStyle.h"
#include "export_api.h"

typedef int sk_font_style_t;

extern "C" {
RAIA_API void static_sk_font_style_delete(int key);
RAIA_API SkFontStyle * static_sk_font_style_get_ptr(int key);
}

int static_sk_font_style_make(SkFontStyle value);
SkFontStyle static_sk_font_style_get(int key);
void static_sk_font_style_set(int key, SkFontStyle value);

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_H
