//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_DIFFUSE_LIGHTING_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_DIFFUSE_LIGHTING_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeLighting.h"

typedef int sk_svg_fe_diffuse_lighting_t;

int static_sk_svg_fe_diffuse_lighting_make(sk_sp<SkSVGFeDiffuseLighting> value);
extern "C" void static_sk_svg_fe_diffuse_lighting_delete(int key);
extern "C" SkSVGFeDiffuseLighting *static_sk_svg_fe_diffuse_lighting_get(int key);
void static_sk_svg_fe_diffuse_lighting_set(int key, sk_sp<SkSVGFeDiffuseLighting> value);
sk_sp<SkSVGFeDiffuseLighting> static_sk_svg_fe_diffuse_lighting_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_DIFFUSE_LIGHTING_H
