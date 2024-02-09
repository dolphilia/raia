//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_length.h"

extern "C" {

// SkSVGLength & operator= (const SkSVGLength &)
// bool operator== (const SkSVGLength &other)
// bool operator!= (const SkSVGLength &other)

void SkSVGLength_delete(SkSVGLength *svgLength) {
    delete svgLength;
}

SkSVGLength *SkSVGLength_new() {
    return new SkSVGLength();
}

SkSVGLength *SkSVGLength_new_2(SkScalar v, SkSVGLength::Unit u) {
    return new SkSVGLength(v, u);
}

SkSVGLength *SkSVGLength_new_3(const SkSVGLength *svgLength) {
    return new SkSVGLength(*svgLength);
}

const SkScalar *SkSVGLength_value (SkSVGLength *svgLength) {
    return &svgLength->value();
}

const SkSVGLength::Unit * SkSVGLength_unit (SkSVGLength *svgLength) {
    return &svgLength->unit();
}

}