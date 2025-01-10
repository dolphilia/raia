//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_VISIBILITY_H
#define RAIA_SKIA_SK_SVG_VISIBILITY_H

#include "modules/svg/include/SkSVGText.h"

extern "C" {
// SkSVGVisibility & operator= (const SkSVGVisibility &)
// bool operator== (const SkSVGVisibility &other)
// bool operator!= (const SkSVGVisibility &other)
void SkSVGVisibility_delete(SkSVGVisibility *svgVisibility);
SkSVGVisibility *SkSVGVisibility_new();
SkSVGVisibility *SkSVGVisibility_new_2(SkSVGVisibility::Type t);
SkSVGVisibility *SkSVGVisibility_new_3(const SkSVGVisibility *svgVisibility);
SkSVGVisibility::Type SkSVGVisibility_type (SkSVGVisibility *svgVisibility);
}

#endif //RAIA_SKIA_SK_SVG_VISIBILITY_H
