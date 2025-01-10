//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_POLY_H
#define RAIA_SKIA_STATIC_SK_SVG_POLY_H

#include "modules/svg/include/SkSVGPoly.h"
#include <set>
#include <map>

typedef int sk_svg_poly_t;

int static_sk_svg_poly_make(sk_sp<SkSVGPoly> value);
extern "C" void static_sk_svg_poly_delete(int key);
extern "C" SkSVGPoly *static_sk_svg_poly_get(int key);
void static_sk_svg_poly_set(int key, sk_sp<SkSVGPoly> value);
sk_sp<SkSVGPoly> static_sk_svg_poly_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_POLY_H
