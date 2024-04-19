//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H

#include <set>
#include <map>
#include "include/core/SkFontArguments.h"

typedef int sk_font_arguments_palette_t;

int static_sk_font_arguments_palette_make(SkFontArguments::Palette value);
extern "C" void static_sk_font_arguments_palette_delete(int key);
SkFontArguments::Palette static_sk_font_arguments_palette_get(int key);
void static_sk_font_arguments_palette_set(int key, SkFontArguments::Palette value);

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_PALETTE_H
