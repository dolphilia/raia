//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_TURBULENCE_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_TURBULENCE_H

#include "modules/svg/include/SkSVGFeTurbulence.h"
#include <set>
#include <map>

typedef int sk_svg_fe_turbulence_t;

int static_sk_svg_fe_turbulence_make(sk_sp<SkSVGFeTurbulence> value);
extern "C" void static_sk_svg_fe_turbulence_delete(int key);
extern "C" SkSVGFeTurbulence *static_sk_svg_fe_turbulence_get(int key);
void static_sk_svg_fe_turbulence_set(int key, sk_sp<SkSVGFeTurbulence> value);
sk_sp<SkSVGFeTurbulence> static_sk_svg_fe_turbulence_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_TURBULENCE_H
