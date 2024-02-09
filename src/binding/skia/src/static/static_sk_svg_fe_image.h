//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_IMAGE_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_IMAGE_H

#include "modules/svg/include/SkSVGFeImage.h"
#include <set>
#include <map>

typedef int sk_svg_fe_image_t;

int static_sk_svg_fe_image_make(sk_sp<SkSVGFeImage> value);
extern "C" void static_sk_svg_fe_image_delete(int key);
extern "C" SkSVGFeImage *static_sk_svg_fe_image_get(int key);
void static_sk_svg_fe_image_set(int key, sk_sp<SkSVGFeImage> value);
sk_sp<SkSVGFeImage> static_sk_svg_fe_image_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_IMAGE_H
