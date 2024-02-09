//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FONT_SIZE_H
#define RAIA_SKIA_SK_SVG_FONT_SIZE_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGFontSize &other)
// bool operator!= (const SkSVGFontSize &other)
void SkSVGFontSize_delete(SkSVGFontSize *svgFontSize);
SkSVGFontSize *SkSVGFontSize_new();
SkSVGFontSize *SkSVGFontSize_new_2(const SkSVGLength *s);
SkSVGFontSize::Type SkSVGFontSize_type (SkSVGFontSize *svgFontSize);
const SkSVGLength & SkSVGFontSize_size (SkSVGFontSize *svgFontSize);
}

#endif //RAIA_SKIA_SK_SVG_FONT_SIZE_H
