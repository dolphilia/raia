//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_VALUE_H
#define RAIA_SKIA_SK_SVG_VALUE_H

#include "modules/svg/include/SkSVGValue.h"

extern "C" {
void SkSVGValue_delete(SkSVGValue *svgValue);
SkSVGValue::Type SkSVGValue_type (SkSVGValue *svgValue);
//const T * SkSVGValue_as (SkSVGValue *svgValue);
}

#endif //RAIA_SKIA_SK_SVG_VALUE_H
