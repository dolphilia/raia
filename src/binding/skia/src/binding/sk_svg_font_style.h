//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FONT_STYLE_H
#define RAIA_SKIA_SK_SVG_FONT_STYLE_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGFontStyle &other)
// bool operator!= (const SkSVGFontStyle &other)
void SkSVGFontStyle_delete(SkSVGFontStyle *svgFontStyle);
SkSVGFontStyle *SkSVGFontStyle_new();
SkSVGFontStyle *SkSVGFontStyle_new_2(SkSVGFontStyle::Type t);
SkSVGFontStyle::Type SkSVGFontStyle_type (SkSVGFontStyle *svgFontStyle);
}

#endif //RAIA_SKIA_SK_SVG_FONT_STYLE_H
