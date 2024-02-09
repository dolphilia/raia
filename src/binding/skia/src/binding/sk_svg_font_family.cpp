//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_font_family.h"

extern "C" {

// bool operator== (const SkSVGFontFamily &other)
// bool operator!= (const SkSVGFontFamily &other)

void SkSVGFontFamily_delete(SkSVGFontFamily *svgFontFamily) {
    delete svgFontFamily;
}

SkSVGFontFamily *SkSVGFontFamily_new() {
    return new SkSVGFontFamily();
}

SkSVGFontFamily *SkSVGFontFamily_new_2(const char family[]) {
    return new SkSVGFontFamily(family);
}

SkSVGFontFamily::Type SkSVGFontFamily_type (SkSVGFontFamily *svgFontFamily) {
    return svgFontFamily->type();
}

const SkString * SkSVGFontFamily_family (SkSVGFontFamily *svgFontFamily) {
    return &svgFontFamily->family();
}

}