//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_SK_FONT_STYLE_SET_H

#include "include/core/SkFontMgr.h"
#include "../static/static_sk_typeface.h"
#include "../static/static_sk_font_style_set.h"

extern "C" {
void SkFontStyleSet_delete(SkFontStyleSet *font_style_set);
int SkFontStyleSet_count(SkFontStyleSet *font_style_set);
void SkFontStyleSet_getStyle(SkFontStyleSet *font_style_set, int index, SkFontStyle * font_style, SkString *style);
sk_typeface_t SkFontStyleSet_createTypeface(SkFontStyleSet *font_style_set, int index);
sk_typeface_t SkFontStyleSet_matchStyle(SkFontStyleSet *font_style_set, const SkFontStyle *pattern);
bool SkFontStyleSet_unique(SkFontStyleSet *font_style_set);
void SkFontStyleSet_ref(SkFontStyleSet *font_style_set);
void SkFontStyleSet_unref(SkFontStyleSet *font_style_set);
// static
sk_font_style_set_t SkFontStyleSet_CreateEmpty();
}

#endif //RAIA_SKIA_SK_FONT_STYLE_SET_H
