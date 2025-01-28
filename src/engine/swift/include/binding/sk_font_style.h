//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_H
#define RAIA_SKIA_SK_FONT_STYLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkFontStyle_delete(void *font_style); // (SkFontStyle *font_style)
int SkFontStyle_weight(void *font_style); // (SkFontStyle *font_style) -> int
int SkFontStyle_width(void *font_style); // (SkFontStyle *font_style) -> int
int SkFontStyle_slant(void *font_style); // (SkFontStyle *font_style) -> SkFontStyle::Slant

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FONT_STYLE_H
