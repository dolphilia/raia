//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_SPOT_LIGHT_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_SPOT_LIGHT_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include <set>
#include <map>

typedef int sk_svg_fe_spot_light_t;

int static_sk_svg_fe_spot_light_make(sk_sp<SkSVGFeSpotLight> value);
extern "C" void static_sk_svg_fe_spot_light_delete(int key);
extern "C" SkSVGFeSpotLight *static_sk_svg_fe_spot_light_get(int key);
void static_sk_svg_fe_spot_light_set(int key, sk_sp<SkSVGFeSpotLight> value);
sk_sp<SkSVGFeSpotLight> static_sk_svg_fe_spot_light_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_SPOT_LIGHT_H
