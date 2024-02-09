//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_LENGTH_H
#define RAIA_SKIA_SK_SVG_LENGTH_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGLength & operator= (const SkSVGLength &)
// bool operator== (const SkSVGLength &other)
// bool operator!= (const SkSVGLength &other)
void SkSVGLength_delete(SkSVGLength *svgLength);
SkSVGLength *SkSVGLength_new();
SkSVGLength *SkSVGLength_new_2(SkScalar v, SkSVGLength::Unit u);
SkSVGLength *SkSVGLength_new_3(const SkSVGLength *svgLength);
const SkScalar *SkSVGLength_value (SkSVGLength *svgLength);
const SkSVGLength::Unit * SkSVGLength_unit (SkSVGLength *svgLength);
}

#endif //RAIA_SKIA_SK_SVG_LENGTH_H
