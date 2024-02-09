//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_input_type.h"

extern "C" {

// bool operator== (const SkSVGFeInputType &other)
// bool operator!= (const SkSVGFeInputType &other)

void SkSVGFeInputType_delete(SkSVGFeInputType *svgFeInputType) {
    delete svgFeInputType;
}

SkSVGFeInputType *SkSVGFeInputType_new(SkSVGFeInputType *svgFeInputType) {
    return new SkSVGFeInputType();
}

SkSVGFeInputType *SkSVGFeInputType_new_2(SkSVGFeInputType *svgFeInputType, SkSVGFeInputType::Type t) {
    return new SkSVGFeInputType(t);
}

SkSVGFeInputType *SkSVGFeInputType_new_3(SkSVGFeInputType *svgFeInputType, const SkSVGStringType *id) {
    return new SkSVGFeInputType(*id);
}

const SkString * SkSVGFeInputType_id (SkSVGFeInputType *svgFeInputType) {
    return &svgFeInputType->id();
}

SkSVGFeInputType::Type SkSVGFeInputType_type (SkSVGFeInputType *svgFeInputType) {
    return svgFeInputType->type();
}

}