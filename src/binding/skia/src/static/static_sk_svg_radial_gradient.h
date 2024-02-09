//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_RADIAL_GRADIENT_H
#define RAIA_SKIA_STATIC_SK_SVG_RADIAL_GRADIENT_H

#include "modules/svg/include/SkSVGRadialGradient.h"
#include <set>
#include <map>

typedef int sk_svg_radial_gradient_t;

int static_sk_svg_radial_gradient_make(sk_sp<SkSVGRadialGradient> value);
extern "C" void static_sk_svg_radial_gradient_delete(int key);
extern "C" SkSVGRadialGradient *static_sk_svg_radial_gradient_get(int key);
void static_sk_svg_radial_gradient_set(int key, sk_sp<SkSVGRadialGradient> value);
sk_sp<SkSVGRadialGradient> static_sk_svg_radial_gradient_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_RADIAL_GRADIENT_H
