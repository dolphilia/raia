//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_object_bounding_box_units.h"

extern "C" {

// bool operator== (const SkSVGObjectBoundingBoxUnits &other)
// bool operator!= (const SkSVGObjectBoundingBoxUnits &other)

void SkSVGObjectBoundingBoxUnits_delete(SkSVGObjectBoundingBoxUnits *svgObjectBoundingBoxUnits) {
    delete svgObjectBoundingBoxUnits;
}

SkSVGObjectBoundingBoxUnits *SkSVGObjectBoundingBoxUnits_new() {
    return new SkSVGObjectBoundingBoxUnits();
}

SkSVGObjectBoundingBoxUnits *SkSVGObjectBoundingBoxUnits_new_2(SkSVGObjectBoundingBoxUnits::Type t) {
    return new SkSVGObjectBoundingBoxUnits(t);
}

SkSVGObjectBoundingBoxUnits::Type SkSVGObjectBoundingBoxUnits_type (SkSVGObjectBoundingBoxUnits *svgObjectBoundingBoxUnits) {
    return svgObjectBoundingBoxUnits->type();
}

}