//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FONT_WEIGHT_H
#define RAIA_SKIA_SK_SVG_FONT_WEIGHT_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGFontWeight &other)
// bool operator!= (const SkSVGFontWeight &other)
void SkSVGFontWeight_delete(SkSVGFontWeight *svgFontWeight);
SkSVGFontWeight *SkSVGFontWeight_new();
SkSVGFontWeight *SkSVGFontWeight_new_2(SkSVGFontWeight::Type t);
SkSVGFontWeight::Type SkSVGFontWeight_type (SkSVGFontWeight *svgFontWeight);
}

#endif //RAIA_SKIA_SK_SVG_FONT_WEIGHT_H
