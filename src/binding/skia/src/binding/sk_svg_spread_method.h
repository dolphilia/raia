//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_SPREAD_METHOD_H
#define RAIA_SKIA_SK_SVG_SPREAD_METHOD_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGSpreadMethod & operator= (const SkSVGSpreadMethod &)
// bool operator== (const SkSVGSpreadMethod &other)
// bool operator!= (const SkSVGSpreadMethod &other)
void SkSVGSpreadMethod_delete(SkSVGSpreadMethod *svgSpreadMethod);
SkSVGSpreadMethod *SkSVGSpreadMethod_new();
SkSVGSpreadMethod *SkSVGSpreadMethod_new_2(SkSVGSpreadMethod::Type t);
SkSVGSpreadMethod *SkSVGSpreadMethod_new_3(const SkSVGSpreadMethod *svgSpreadMethod);
SkSVGSpreadMethod::Type SkSVGSpreadMethod_type (SkSVGSpreadMethod *svgSpreadMethod);
}

#endif //RAIA_SKIA_SK_SVG_SPREAD_METHOD_H
