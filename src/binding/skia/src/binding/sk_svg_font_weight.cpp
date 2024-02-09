//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_font_weight.h"

extern "C" {

// bool operator== (const SkSVGFontWeight &other)
// bool operator!= (const SkSVGFontWeight &other)

void SkSVGFontWeight_delete(SkSVGFontWeight *svgFontWeight) {
    delete svgFontWeight;
}

SkSVGFontWeight *SkSVGFontWeight_new() {
    return new SkSVGFontWeight();
}

SkSVGFontWeight *SkSVGFontWeight_new_2(SkSVGFontWeight::Type t) {
    return new SkSVGFontWeight(t);
}

SkSVGFontWeight::Type SkSVGFontWeight_type (SkSVGFontWeight *svgFontWeight) {
    return svgFontWeight->type();
}

}