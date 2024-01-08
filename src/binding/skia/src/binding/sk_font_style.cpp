//
// Created by dolphilia on 2024/01/08.
//

#include "sk_font_style.h"

extern "C" {

int SkFontStyle_weight (SkFontStyle *font_style) {
    return font_style->weight();
}

int SkFontStyle_width (SkFontStyle *font_style) {
    return font_style->width();
}

SkFontStyle::Slant SkFontStyle_slant (SkFontStyle *font_style) {
    return font_style->slant();
}

}