//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H

#include <set>
#include <map>
#include "include/core/SkFontArguments.h"
#include "export_api.h"

typedef int sk_font_arguments_palette_t;

extern "C" {
RAIA_API void static_sk_font_arguments_palette_delete(int key);
RAIA_API SkFontArguments::Palette * static_sk_font_arguments_palette_get_ptr(int key);
}

int static_sk_font_arguments_palette_make(SkFontArguments::Palette value);
SkFontArguments::Palette static_sk_font_arguments_palette_get(int key);
void static_sk_font_arguments_palette_set(int key, SkFontArguments::Palette value);

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
