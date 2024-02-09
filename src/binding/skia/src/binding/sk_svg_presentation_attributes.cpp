//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_presentation_attributes.h"

extern "C" {

void SkSVGPresentationAttributes_delete(SkSVGPresentationAttributes *svgPresentationAttributes) {
    delete svgPresentationAttributes;
}

// static

sk_svg_presentation_attributes_t SkSVGPresentationAttributes_MakeInitial () {
    return static_sk_svg_presentation_attributes_make(SkSVGPresentationAttributes::MakeInitial());
}

}