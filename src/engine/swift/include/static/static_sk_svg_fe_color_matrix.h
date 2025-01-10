//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_COLOR_MATRIX_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_COLOR_MATRIX_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeColorMatrix.h"

typedef int sk_svg_fe_color_matrix_t;

int static_sk_svg_fe_color_matrix_make(sk_sp<SkSVGFeColorMatrix> value);
extern "C" void static_sk_svg_fe_color_matrix_delete(int key);
extern "C" SkSVGFeColorMatrix *static_sk_svg_fe_color_matrix_get(int key);
void static_sk_svg_fe_color_matrix_set(int key, sk_sp<SkSVGFeColorMatrix> value);
sk_sp<SkSVGFeColorMatrix> static_sk_svg_fe_color_matrix_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_COLOR_MATRIX_H
