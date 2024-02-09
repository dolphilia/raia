//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_stop_color.h"

extern "C" {

// SkSVGStopColor & operator= (const SkSVGStopColor &)
// bool operator== (const SkSVGStopColor &other)
// bool operator!= (const SkSVGStopColor &other)

void SkSVGStopColor_delete(SkSVGStopColor *svgStopColor) {
    delete svgStopColor;
}

SkSVGStopColor *SkSVGStopColor_new() {
    return new SkSVGStopColor();
}

SkSVGStopColor *SkSVGStopColor_new_2(SkSVGStopColor::Type t) {
    return new SkSVGStopColor(t);
}

SkSVGStopColor *SkSVGStopColor_new_3(const SkSVGColorType *c) {
    return new SkSVGStopColor(*c);
}

SkSVGStopColor *SkSVGStopColor_new_4(const SkSVGStopColor *svgStopColor) {
    return new SkSVGStopColor(*svgStopColor);
}

SkSVGStopColor::Type SkSVGStopColor_type (SkSVGStopColor *svgStopColor) {
    return svgStopColor->type();
}

const SkSVGColorType & SkSVGStopColor_color (SkSVGStopColor *svgStopColor) {
    return svgStopColor->color();
}

}