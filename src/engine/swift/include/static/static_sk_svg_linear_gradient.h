//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_LINEAR_GRADIENT_H
#define RAIA_SKIA_STATIC_SK_SVG_LINEAR_GRADIENT_H

#include "modules/svg/include/SkSVGLinearGradient.h"
#include <set>
#include <map>

typedef int sk_svg_linear_gradient_t;

int static_sk_svg_linear_gradient_make(sk_sp<SkSVGLinearGradient> value);
extern "C" void static_sk_svg_linear_gradient_delete(int key);
extern "C" SkSVGLinearGradient *static_sk_svg_linear_gradient_get(int key);
void static_sk_svg_linear_gradient_set(int key, sk_sp<SkSVGLinearGradient> value);
sk_sp<SkSVGLinearGradient> static_sk_svg_linear_gradient_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_LINEAR_GRADIENT_H
