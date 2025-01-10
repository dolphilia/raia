//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_GAUSSIAN_BLUR_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_GAUSSIAN_BLUR_H

#include "modules/svg/include/SkSVGFeGaussianBlur.h"
#include <set>
#include <map>

typedef int sk_svg_fe_gaussian_blur_t;

int static_sk_svg_fe_gaussian_blur_make(sk_sp<SkSVGFeGaussianBlur> value);
extern "C" void static_sk_svg_fe_gaussian_blur_delete(int key);
extern "C" SkSVGFeGaussianBlur *static_sk_svg_fe_gaussian_blur_get(int key);
void static_sk_svg_fe_gaussian_blur_set(int key, sk_sp<SkSVGFeGaussianBlur> value);
sk_sp<SkSVGFeGaussianBlur> static_sk_svg_fe_gaussian_blur_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_GAUSSIAN_BLUR_H
