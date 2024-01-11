//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_ARGUMENTS_H
#define RAIA_SKIA_SK_FONT_ARGUMENTS_H

#include "include/core/SkFontArguments.h"
#include "../static/static_sk_font_arguments.h"

extern "C" {
SkFontArguments *SkFontArguments_new();
void SkFontArguments_setCollectionIndex(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, int collectionIndex);
void SkFontArguments_setVariationDesignPosition(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, SkFontArguments::VariationPosition position);
int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments);
SkFontArguments::VariationPosition SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments);
void SkFontArguments_setPalette(const char *sk_font_arguments_key_out, SkFontArguments *font_argments, SkFontArguments::Palette palette);
SkFontArguments::Palette SkFontArguments_getPalette(SkFontArguments *font_argments);
}

#endif //RAIA_SKIA_SK_FONT_ARGUMENTS_H
