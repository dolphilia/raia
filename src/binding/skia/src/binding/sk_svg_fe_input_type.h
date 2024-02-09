//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_INPUT_TYPE_H
#define RAIA_SKIA_SK_SVG_FE_INPUT_TYPE_H

#include "modules/svg/include/SkSVGTypes.h"
#include "../static/static_sk_path.h"

extern "C" {
// bool operator== (const SkSVGFeInputType &other)
// bool operator!= (const SkSVGFeInputType &other)
void SkSVGFeInputType_delete(SkSVGFeInputType *svgFeInputType);
SkSVGFeInputType *SkSVGFeInputType_new(SkSVGFeInputType *svgFeInputType);
SkSVGFeInputType *SkSVGFeInputType_new_2(SkSVGFeInputType *svgFeInputType, SkSVGFeInputType::Type t);
SkSVGFeInputType *SkSVGFeInputType_new_3(SkSVGFeInputType *svgFeInputType, const SkSVGStringType *id);
const SkString * SkSVGFeInputType_id (SkSVGFeInputType *svgFeInputType);
SkSVGFeInputType::Type SkSVGFeInputType_type (SkSVGFeInputType *svgFeInputType);
}

#endif //RAIA_SKIA_SK_SVG_FE_INPUT_TYPE_H
