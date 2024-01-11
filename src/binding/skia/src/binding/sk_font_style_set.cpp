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

void SkFontStyleSet_createTypeface(const char *sk_typeface_key_out, SkFontStyleSet *font_style_set, int index) {
    static_sk_typeface_set(sk_typeface_key_out, font_style_set->createTypeface(index));
}

void SkFontStyleSet_matchStyle(const char *sk_typeface_key_out, SkFontStyleSet *font_style_set, const SkFontStyle *pattern) {
    static_sk_typeface_set(sk_typeface_key_out, font_style_set->matchStyle(*pattern));
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

void SkFontStyleSet_CreateEmpty(const char *sk_font_style_set_key_out) {
    static_sk_font_style_set_set(sk_font_style_set_key_out, SkFontStyleSet::CreateEmpty());
}

}