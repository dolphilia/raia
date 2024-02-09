//
// Created by dolphilia on 2024/02/05.
//

#include "sk_svg_dash_array.h"

extern "C" {

// SkSVGDashArray & operator= (const SkSVGDashArray &)
// bool operator== (const SkSVGDashArray &other)
// bool operator!= (const SkSVGDashArray &other)

void SkSVGDashArray_delete(SkSVGDashArray *svgDashArray) {
    delete svgDashArray;
}

SkSVGDashArray *SkSVGDashArray_new() {
    return new SkSVGDashArray();
}

SkSVGDashArray *SkSVGDashArray_new_2(SkSVGDashArray::Type t) {
    return new SkSVGDashArray(t);
}

//SkSVGDashArray *SkSVGDashArray_new(std::vector< SkSVGLength > &&dashArray) {
//    return new SkSVGDashArray(dashArray);
//}

SkSVGDashArray *SkSVGDashArray_new_3(const SkSVGDashArray &svgDashArray) {
    return new SkSVGDashArray(svgDashArray);
}

SkSVGDashArray::Type SkSVGDashArray_type(SkSVGDashArray *svgDashArray) {
    return svgDashArray->type();
}

const std::vector< SkSVGLength > * SkSVGDashArray_dashArray(SkSVGDashArray *svgDashArray) {
    return &svgDashArray->dashArray();
}

}