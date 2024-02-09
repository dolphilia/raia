//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_STOP_COLOR_H
#define RAIA_SKIA_SK_SVG_STOP_COLOR_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGStopColor & operator= (const SkSVGStopColor &)
// bool operator== (const SkSVGStopColor &other)
// bool operator!= (const SkSVGStopColor &other)
void SkSVGStopColor_delete(SkSVGStopColor *svgStopColor);
SkSVGStopColor *SkSVGStopColor_new();
SkSVGStopColor *SkSVGStopColor_new_2(SkSVGStopColor::Type t);
SkSVGStopColor *SkSVGStopColor_new_3(const SkSVGColorType *c);
SkSVGStopColor *SkSVGStopColor_new_4(const SkSVGStopColor *svgStopColor);
SkSVGStopColor::Type SkSVGStopColor_type (SkSVGStopColor *svgStopColor);
const SkSVGColorType & SkSVGStopColor_color (SkSVGStopColor *svgStopColor);
}

#endif //RAIA_SKIA_SK_SVG_STOP_COLOR_H
