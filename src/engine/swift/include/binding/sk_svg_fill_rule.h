//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FILL_RULE_H
#define RAIA_SKIA_SK_SVG_FILL_RULE_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGFillRule & operator= (const SkSVGFillRule &)
// bool operator== (const SkSVGFillRule &other)
// bool operator!= (const SkSVGFillRule &other)
void SkSVGFillRule_delete(SkSVGFillRule *svgFillRule);
SkSVGFillRule *SkSVGFillRule_new();
SkSVGFillRule *SkSVGFillRule_new_2(SkSVGFillRule::Type t);
SkSVGFillRule *SkSVGFillRule_new_3(const SkSVGFillRule *svgFillRule);
SkSVGFillRule::Type SkSVGFillRule_type (SkSVGFillRule *svgFillRule);
SkPathFillType SkSVGFillRule_asFillType (SkSVGFillRule *svgFillRule);
}

#endif //RAIA_SKIA_SK_SVG_FILL_RULE_H
