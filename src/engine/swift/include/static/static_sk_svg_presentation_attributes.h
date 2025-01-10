//
// Created by dolphilia on 2024/02/08.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_PRESENTATION_ATTRIBUTES_H
#define RAIA_SKIA_STATIC_SK_SVG_PRESENTATION_ATTRIBUTES_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGAttribute.h"

typedef int sk_svg_presentation_attributes_t;

int static_sk_svg_presentation_attributes_make(SkSVGPresentationAttributes value);
extern "C" void static_sk_svg_presentation_attributes_delete(int key);
SkSVGPresentationAttributes static_sk_svg_presentation_attributes_get(int key);
void static_sk_svg_presentation_attributes_set(int key, SkSVGPresentationAttributes value);

#endif //RAIA_SKIA_STATIC_SK_SVG_PRESENTATION_ATTRIBUTES_H
