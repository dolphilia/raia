//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_ANCHOR_H
#define RAIA_SKIA_SK_SVG_TEXT_ANCHOR_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGTextAnchor &other)
// bool operator!= (const SkSVGTextAnchor &other)
void SkSVGTextAnchor_delete(SkSVGTextAnchor *svgTextAnchor);
SkSVGTextAnchor *SkSVGTextAnchor_new();
SkSVGTextAnchor *SkSVGTextAnchor_new_2(SkSVGTextAnchor::Type t);
SkSVGTextAnchor::Type SkSVGTextAnchor_type (SkSVGTextAnchor *svgTextAnchor);
}

#endif //RAIA_SKIA_SK_SVG_TEXT_ANCHOR_H
