//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_BLEND_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_BLEND_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeBlend.h"

typedef int sk_svg_fe_blend_t;

int static_sk_svg_fe_blend_make(sk_sp<SkSVGFeBlend> value);
void static_sk_svg_fe_blend_delete(int key);
SkSVGFeBlend *static_sk_svg_fe_blend_get(int key);
void static_sk_svg_fe_blend_set(int key, sk_sp<SkSVGFeBlend> value);
sk_sp<SkSVGFeBlend> static_sk_svg_fe_blend_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_BLEND_H
