//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_SK_FONT_STYLE_SET_H

#include "include/core/SkFontMgr.h"
#include "../static/static_sk_typeface.h"
#include "../static/static_sk_font_style_set.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkFontStyleSet_delete(SkFontStyleSet *font_style_set);
RAIA_API int SkFontStyleSet_count(SkFontStyleSet *font_style_set);
RAIA_API void SkFontStyleSet_getStyle(SkFontStyleSet *font_style_set, int index, SkFontStyle * font_style, SkString *style);
RAIA_API sk_typeface_t SkFontStyleSet_createTypeface(SkFontStyleSet *font_style_set, int index);
RAIA_API sk_typeface_t SkFontStyleSet_matchStyle(SkFontStyleSet *font_style_set, const SkFontStyle *pattern);
RAIA_API bool SkFontStyleSet_unique(SkFontStyleSet *font_style_set);
RAIA_API void SkFontStyleSet_ref(SkFontStyleSet *font_style_set);
RAIA_API void SkFontStyleSet_unref(SkFontStyleSet *font_style_set);
// static
RAIA_API sk_font_style_set_t SkFontStyleSet_CreateEmpty();
}

#endif //RAIA_SKIA_SK_FONT_STYLE_SET_H
