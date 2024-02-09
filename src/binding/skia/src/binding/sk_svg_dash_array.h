//
// Created by dolphilia on 2024/02/05.
//

#ifndef RAIA_SKIA_SK_SVG_DASH_ARRAY_H
#define RAIA_SKIA_SK_SVG_DASH_ARRAY_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGDashArray & operator= (const SkSVGDashArray &)
// bool operator== (const SkSVGDashArray &other)
// bool operator!= (const SkSVGDashArray &other)
void SkSVGDashArray_delete(SkSVGDashArray *svgDashArray);
SkSVGDashArray *SkSVGDashArray_new();
SkSVGDashArray *SkSVGDashArray_new_2(SkSVGDashArray::Type t);
//SkSVGDashArray *SkSVGDashArray_new(std::vector< SkSVGLength > &&dashArray);
SkSVGDashArray *SkSVGDashArray_new_3(const SkSVGDashArray &svgDashArray);
SkSVGDashArray::Type SkSVGDashArray_type(SkSVGDashArray *svgDashArray);
const std::vector< SkSVGLength > * SkSVGDashArray_dashArray(SkSVGDashArray *svgDashArray);
}

#endif //RAIA_SKIA_SK_SVG_DASH_ARRAY_H
