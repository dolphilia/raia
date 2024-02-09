//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_OFFSET_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_OFFSET_H

#include "modules/svg/include/SkSVGFeOffset.h"
#include <set>
#include <map>

typedef int sk_svg_fe_offset_t;

int static_sk_svg_fe_offset_make(sk_sp<SkSVGFeOffset> value);
extern "C" void static_sk_svg_fe_offset_delete(int key);
extern "C" SkSVGFeOffset *static_sk_svg_fe_offset_get(int key);
void static_sk_svg_fe_offset_set(int key, sk_sp<SkSVGFeOffset> value);
sk_sp<SkSVGFeOffset> static_sk_svg_fe_offset_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_OFFSET_H
