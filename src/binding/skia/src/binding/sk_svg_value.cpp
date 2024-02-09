//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_value.h"

extern "C" {

void SkSVGValue_delete(SkSVGValue *svgValue) {
    delete svgValue;
}

SkSVGValue::Type SkSVGValue_type (SkSVGValue *svgValue) {
    return svgValue->type();
}

//const T * SkSVGValue_as (SkSVGValue *svgValue) {}

}