//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_style_set.h"

extern "C" {

int SkFontStyleSet_count(SkFontStyleSet *font_style_set) {
    return font_style_set->count();
}

void SkFontStyleSet_getStyle(SkFontStyleSet *font_style_set, int index, SkFontStyle * font_style, SkString *style) {
    return font_style_set->getStyle(index, font_style, style);
}

int SkFontStyleSet_createTypeface(SkFontStyleSet *font_style_set, int index) {
    return static_sk_typeface_make(font_style_set->createTypeface(index));
}

int SkFontStyleSet_matchStyle(SkFontStyleSet *font_style_set, const SkFontStyle *pattern) {
    return static_sk_typeface_make(font_style_set->matchStyle(*pattern));
}

bool SkFontStyleSet_unique(SkFontStyleSet *font_style_set) {
    return font_style_set->unique();
}

void SkFontStyleSet_ref(SkFontStyleSet *font_style_set) {
    return font_style_set->ref();
}

void SkFontStyleSet_unref(SkFontStyleSet *font_style_set) {
    return font_style_set->unref();
}

// static

int SkFontStyleSet_CreateEmpty() {
    return static_sk_font_style_set_make(SkFontStyleSet::CreateEmpty());
}

}