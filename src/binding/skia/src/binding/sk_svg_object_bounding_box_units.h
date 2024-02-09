//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_OBJECT_BOUNDING_BOX_UNITS_H
#define RAIA_SKIA_SK_SVG_OBJECT_BOUNDING_BOX_UNITS_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGObjectBoundingBoxUnits &other)
// bool operator!= (const SkSVGObjectBoundingBoxUnits &other)
void SkSVGObjectBoundingBoxUnits_delete(SkSVGObjectBoundingBoxUnits *svgObjectBoundingBoxUnits);
SkSVGObjectBoundingBoxUnits *SkSVGObjectBoundingBoxUnits_new();
SkSVGObjectBoundingBoxUnits *SkSVGObjectBoundingBoxUnits_new_2(SkSVGObjectBoundingBoxUnits::Type t);
SkSVGObjectBoundingBoxUnits::Type SkSVGObjectBoundingBoxUnits_type (SkSVGObjectBoundingBoxUnits *svgObjectBoundingBoxUnits);
}

#endif //RAIA_SKIA_SK_SVG_OBJECT_BOUNDING_BOX_UNITS_H
