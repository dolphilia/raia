//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_spread_method.h"

extern "C" {

// SkSVGSpreadMethod & operator= (const SkSVGSpreadMethod &)
// bool operator== (const SkSVGSpreadMethod &other)
// bool operator!= (const SkSVGSpreadMethod &other)

void SkSVGSpreadMethod_delete(SkSVGSpreadMethod *svgSpreadMethod) {
    delete svgSpreadMethod;
}

SkSVGSpreadMethod *SkSVGSpreadMethod_new() {
    return new SkSVGSpreadMethod();
}

SkSVGSpreadMethod *SkSVGSpreadMethod_new_2(SkSVGSpreadMethod::Type t) {
    return new SkSVGSpreadMethod(t);
}

SkSVGSpreadMethod *SkSVGSpreadMethod_new_3(const SkSVGSpreadMethod *svgSpreadMethod) {
    return new SkSVGSpreadMethod(*svgSpreadMethod);
}

SkSVGSpreadMethod::Type SkSVGSpreadMethod_type (SkSVGSpreadMethod *svgSpreadMethod) {
    return svgSpreadMethod->type();
}

}