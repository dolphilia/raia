//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_PRESENTATION_ATTRIBUTES_H
#define RAIA_SKIA_SK_SVG_PRESENTATION_ATTRIBUTES_H

#include "modules/svg/include/SkSVGAttribute.h"
#include "../static/static_sk_svg_presentation_attributes.h"

extern "C" {
void SkSVGPresentationAttributes_delete(SkSVGPresentationAttributes *svgPresentationAttributes);
// static
sk_svg_presentation_attributes_t SkSVGPresentationAttributes_MakeInitial ();
}

#endif //RAIA_SKIA_SK_SVG_PRESENTATION_ATTRIBUTES_H
