//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_SPECULAR_LIGHTING_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_SPECULAR_LIGHTING_H

#include "modules/svg/include/SkSVGFeLighting.h"
#include <set>
#include <map>

typedef int sk_svg_fe_specular_lighting_t;

int static_sk_svg_fe_specular_lighting_make(sk_sp<SkSVGFeSpecularLighting> value);
extern "C" void static_sk_svg_fe_specular_lighting_delete(int key);
extern "C" SkSVGFeSpecularLighting *static_sk_svg_fe_specular_lighting_get(int key);
void static_sk_svg_fe_specular_lighting_set(int key, sk_sp<SkSVGFeSpecularLighting> value);
sk_sp<SkSVGFeSpecularLighting> static_sk_svg_fe_specular_lighting_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_SPECULAR_LIGHTING_H
