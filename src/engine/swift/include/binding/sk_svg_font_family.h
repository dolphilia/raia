//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FONT_FAMILY_H
#define RAIA_SKIA_SK_SVG_FONT_FAMILY_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGFontFamily &other)
// bool operator!= (const SkSVGFontFamily &other)
void SkSVGFontFamily_delete(SkSVGFontFamily *svgFontFamily);
SkSVGFontFamily *SkSVGFontFamily_new();
SkSVGFontFamily *SkSVGFontFamily_new_2(const char family[]);
SkSVGFontFamily::Type SkSVGFontFamily_type (SkSVGFontFamily *svgFontFamily);
const SkString * SkSVGFontFamily_family (SkSVGFontFamily *svgFontFamily);
}

#endif //RAIA_SKIA_SK_SVG_FONT_FAMILY_H
