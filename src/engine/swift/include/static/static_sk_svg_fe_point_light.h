//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_POINT_LIGHT_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_POINT_LIGHT_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include <set>
#include <map>

typedef int sk_svg_fe_point_light_t;

int static_sk_svg_fe_point_light_make(sk_sp<SkSVGFePointLight> value);
extern "C" void static_sk_svg_fe_point_light_delete(int key);
extern "C" SkSVGFePointLight *static_sk_svg_fe_point_light_get(int key);
void static_sk_svg_fe_point_light_set(int key, sk_sp<SkSVGFePointLight> value);
sk_sp<SkSVGFePointLight> static_sk_svg_fe_point_light_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_POINT_LIGHT_H
