//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_font_style.h"

extern "C" {

// bool operator== (const SkSVGFontStyle &other)
// bool operator!= (const SkSVGFontStyle &other)

void SkSVGFontStyle_delete(SkSVGFontStyle *svgFontStyle) {
    delete svgFontStyle;
}

SkSVGFontStyle *SkSVGFontStyle_new() {
    return new SkSVGFontStyle();
}

SkSVGFontStyle *SkSVGFontStyle_new_2(SkSVGFontStyle::Type t) {
    return new SkSVGFontStyle(t);
}

SkSVGFontStyle::Type SkSVGFontStyle_type (SkSVGFontStyle *svgFontStyle) {
    return svgFontStyle->type();
}

}