//
// Created by dolphilia on 2024/02/04.
//

#ifndef RAIA_SKIA_SK_SVG_COLOR_H
#define RAIA_SKIA_SK_SVG_COLOR_H

#include "modules/svg/include/SkSVGTypes.h"
#include "../static/static_sk_string.h"

extern "C" {
// SkSVGColor & operator= (const SkSVGColor &)
// SkSVGColor & operator= (SkSVGColor &&)
// bool operator== (const SkSVGColor &other)
// bool operator!= (const SkSVGColor &other)
void SkSVGColor_delete(SkSVGColor *svgColor);
SkSVGColor *SkSVGColor_new();
SkSVGColor *SkSVGColor_new_2(const SkSVGColorType &c);
//SkSVGColor *SkSVGColor_new(SkSVGColor::Type t, SkSVGColor::Vars &&vars);
//SkSVGColor *SkSVGColor_new(const SkSVGColorType &c, SkSVGColor::Vars &&vars);
SkSVGColor *SkSVGColor_new_3(const SkSVGColor &svgColor);
//SkSVGColor *SkSVGColor_new(SkSVGColor &&svgColor);
SkSVGColor::Type SkSVGColor_type(SkSVGColor *svgColor);
const SkSVGColorType * SkSVGColor_color(SkSVGColor *svgColor);
sk_span_sk_string_t SkSVGColor_vars(SkSVGColor *svgColor);
sk_span_sk_string_t SkSVGColor_vars_2(SkSVGColor *svgColor);
}

#endif //RAIA_SKIA_SK_SVG_COLOR_H
