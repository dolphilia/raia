//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_turbulence_type.h"

extern "C" {

void SkSVGFeTurbulenceType_delete(SkSVGFeTurbulenceType *svgFeTurbulenceType) {
    delete svgFeTurbulenceType;
}

SkSVGFeTurbulenceType *SkSVGFeTurbulenceType_new() {
    return new SkSVGFeTurbulenceType();
}

SkSVGFeTurbulenceType *SkSVGFeTurbulenceType_new_2(SkSVGFeTurbulenceType::Type type) {
    return new SkSVGFeTurbulenceType(type);
}

}