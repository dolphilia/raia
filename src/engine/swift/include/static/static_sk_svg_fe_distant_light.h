//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_DISTANT_LIGHT_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_DISTANT_LIGHT_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeLightSource.h"

typedef int sk_svg_fe_distant_light_t;

int static_sk_svg_fe_distant_light_make(sk_sp<SkSVGFeDistantLight> value);
extern "C" void static_sk_svg_fe_distant_light_delete(int key);
extern "C" SkSVGFeDistantLight *static_sk_svg_fe_distant_light_get(int key);
void static_sk_svg_fe_distant_light_set(int key, sk_sp<SkSVGFeDistantLight> value);
sk_sp<SkSVGFeDistantLight> static_sk_svg_fe_distant_light_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_DISTANT_LIGHT_H
