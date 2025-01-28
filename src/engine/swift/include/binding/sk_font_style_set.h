//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_SK_FONT_STYLE_SET_H

#ifdef __cplusplus
extern "C" {
#endif

void SkFontStyleSet_delete(void *font_style_set); // (SkFontStyleSet *font_style_set)
int SkFontStyleSet_count(void *font_style_set); // (SkFontStyleSet *font_style_set) -> int
void SkFontStyleSet_getStyle(void *font_style_set, int index, void *font_style, void *style); // (SkFontStyleSet *font_style_set, int index, SkFontStyle *font_style, SkString *style)
int SkFontStyleSet_createTypeface(void *font_style_set, int index); // (SkFontStyleSet *font_style_set, int index) -> sk_typeface_t
int SkFontStyleSet_matchStyle(void *font_style_set, const void *pattern); // (SkFontStyleSet *font_style_set, const SkFontStyle *pattern) -> sk_typeface_t
bool SkFontStyleSet_unique(void *font_style_set); // (SkFontStyleSet *font_style_set) -> bool
void SkFontStyleSet_ref(void *font_style_set); // (SkFontStyleSet *font_style_set)
void SkFontStyleSet_unref(void *font_style_set); // (SkFontStyleSet *font_style_set)

// static

int SkFontStyleSet_CreateEmpty(); // () -> sk_font_style_set_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FONT_STYLE_SET_H
