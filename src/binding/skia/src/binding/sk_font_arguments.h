//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_ARGUMENTS_H
#define RAIA_SKIA_SK_FONT_ARGUMENTS_H

#include "include/core/SkFontArguments.h"
#include "../static/static_sk_font_arguments.h"

extern "C" {
SkFontArguments *SkFontArguments_new();
int SkFontArguments_setCollectionIndex(SkFontArguments *font_argments, int collectionIndex);
int SkFontArguments_setVariationDesignPosition(SkFontArguments *font_argments, SkFontArguments::VariationPosition position);
int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments);
SkFontArguments::VariationPosition SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments);
int SkFontArguments_setPalette(SkFontArguments *font_argments, SkFontArguments::Palette palette);
SkFontArguments::Palette SkFontArguments_getPalette(SkFontArguments *font_argments);
}

#endif //RAIA_SKIA_SK_FONT_ARGUMENTS_H
