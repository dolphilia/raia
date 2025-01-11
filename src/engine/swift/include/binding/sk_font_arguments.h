//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_ARGUMENTS_H
#define RAIA_SKIA_SK_FONT_ARGUMENTS_H

#include "include/core/SkFontArguments.h"
#include "../static/static_sk_font_arguments.h"
#include "../static/static_sk_font_arguments_variation_position.h"
#include "../static/static_sk_font_arguments_palette.h"
#include "export_api.h"

extern "C" {
RAIA_API SkFontArguments *SkFontArguments_new();
RAIA_API void SkFontArguments_delete(SkFontArguments *font_arguments);
RAIA_API sk_font_arguments_t SkFontArguments_setCollectionIndex(SkFontArguments *font_argments, int collectionIndex);
RAIA_API sk_font_arguments_t SkFontArguments_setVariationDesignPosition(SkFontArguments *font_argments, sk_font_arguments_variation_position_t position);
RAIA_API int SkFontArguments_getCollectionIndex(SkFontArguments *font_argments);
RAIA_API sk_font_arguments_variation_position_t SkFontArguments_getVariationDesignPosition(SkFontArguments *font_argments);
RAIA_API sk_font_arguments_t SkFontArguments_setPalette(SkFontArguments *font_argments, sk_font_arguments_palette_t palette);
RAIA_API sk_font_arguments_palette_t SkFontArguments_getPalette(SkFontArguments *font_argments);
}

#endif //RAIA_SKIA_SK_FONT_ARGUMENTS_H
