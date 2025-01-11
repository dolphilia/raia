//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FONT_STYLE_H
#define RAIA_SKIA_SK_FONT_STYLE_H

#include "include/core/SkFontStyle.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkFontStyle_delete(SkFontStyle *font_style);
RAIA_API int SkFontStyle_weight(SkFontStyle *font_style);
RAIA_API int SkFontStyle_width(SkFontStyle *font_style);
RAIA_API SkFontStyle::Slant SkFontStyle_slant(SkFontStyle *font_style);
}

#endif //RAIA_SKIA_SK_FONT_STYLE_H
