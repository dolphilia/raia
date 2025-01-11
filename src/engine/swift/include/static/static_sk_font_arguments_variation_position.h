//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H

#include <set>
#include <map>
#include "include/core/SkFontArguments.h"
#include "export_api.h"

typedef int sk_font_arguments_variation_position_t;

extern "C" {
RAIA_API void static_sk_font_arguments_variation_position_delete(int key);
RAIA_API SkFontArguments::VariationPosition * static_sk_font_arguments_variation_position_get_ptr(int key);
}

int static_sk_font_arguments_variation_position_make(SkFontArguments::VariationPosition value);
SkFontArguments::VariationPosition static_sk_font_arguments_variation_position_get(int key);
void static_sk_font_arguments_variation_position_set(int key, SkFontArguments::VariationPosition value);

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_VARIATION_POSITION_H
