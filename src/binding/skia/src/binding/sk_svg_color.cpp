//
// Created by dolphilia on 2024/02/04.
//

#include "sk_svg_color.h"

extern "C" {

// SkSVGColor & operator= (const SkSVGColor &)
// SkSVGColor & operator= (SkSVGColor &&)
// bool operator== (const SkSVGColor &other)
// bool operator!= (const SkSVGColor &other)

void SkSVGColor_delete(SkSVGColor *svgColor) {
    delete svgColor;
}

SkSVGColor *SkSVGColor_new() {
    return new SkSVGColor();
}

SkSVGColor *SkSVGColor_new_2(const SkSVGColorType &c) {
    return new SkSVGColor(c);
}

//SkSVGColor *SkSVGColor_new(SkSVGColor::Type t, SkSVGColor::Vars &&vars) {
//    return new SkSVGColor(t, vars);
//}

//SkSVGColor *SkSVGColor_new(const SkSVGColorType &c, SkSVGColor::Vars &&vars) {
//    return new SkSVGColor(c, vars);
//}

SkSVGColor *SkSVGColor_new_3(const SkSVGColor &svgColor) {
    return new SkSVGColor(svgColor);
}

//SkSVGColor *SkSVGColor_new(SkSVGColor &&svgColor) {
//    return new SkSVGColor(svgColor);
//}

SkSVGColor::Type SkSVGColor_type(SkSVGColor *svgColor) {
    return svgColor->type();
}

const SkSVGColorType * SkSVGColor_color(SkSVGColor *svgColor) {
    return &svgColor->color();
}

sk_span_sk_string_t SkSVGColor_vars(SkSVGColor *svgColor) {
    return static_sk_span_sk_string_make(svgColor->vars());
}

sk_span_sk_string_t SkSVGColor_vars_2(SkSVGColor *svgColor) {
    return static_sk_span_sk_string_make(svgColor->vars());
}

}
