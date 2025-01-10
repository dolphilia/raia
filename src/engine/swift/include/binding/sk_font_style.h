//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_H
#define RAIA_SKIA_SK_FONT_STYLE_H

#include "include/core/SkFontStyle.h"

extern "C" {
void SkFontStyle_delete(SkFontStyle *font_style);
int SkFontStyle_weight(SkFontStyle *font_style);
int SkFontStyle_width(SkFontStyle *font_style);
SkFontStyle::Slant SkFontStyle_slant(SkFontStyle *font_style);
}

#endif //RAIA_SKIA_SK_FONT_STYLE_H
