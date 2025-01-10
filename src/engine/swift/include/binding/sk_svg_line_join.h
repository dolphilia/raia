//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_LINE_JOIN_H
#define RAIA_SKIA_SK_SVG_LINE_JOIN_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGLineJoin & operator= (const SkSVGLineJoin &)
// bool operator== (const SkSVGLineJoin &other)
// bool operator!= (const SkSVGLineJoin &other)
void SkSVGLineJoin_delete(SkSVGLineJoin *svgLineJoin);
SkSVGLineJoin *SkSVGLineJoin_new();
SkSVGLineJoin *SkSVGLineJoin_new_2(SkSVGLineJoin::Type t);
SkSVGLineJoin *SkSVGLineJoin_new_3(const SkSVGLineJoin &svgLineJoin);
SkSVGLineJoin::Type SkSVGLineJoin_type (SkSVGLineJoin *svgLineJoin);
}

#endif //RAIA_SKIA_SK_SVG_LINE_JOIN_H
