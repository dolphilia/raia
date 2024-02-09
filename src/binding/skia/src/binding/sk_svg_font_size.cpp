//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_font_size.h"

extern "C" {

// bool operator== (const SkSVGFontSize &other)
// bool operator!= (const SkSVGFontSize &other)

void SkSVGFontSize_delete(SkSVGFontSize *svgFontSize) {
    delete svgFontSize;
}

SkSVGFontSize *SkSVGFontSize_new() {
    return new SkSVGFontSize();
}

SkSVGFontSize *SkSVGFontSize_new_2(const SkSVGLength *s) {
    return new SkSVGFontSize(*s);
}

SkSVGFontSize::Type SkSVGFontSize_type (SkSVGFontSize *svgFontSize) {
    return svgFontSize->type();
}

const SkSVGLength & SkSVGFontSize_size (SkSVGFontSize *svgFontSize) {
    return svgFontSize->size();
}

}