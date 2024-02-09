//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_MASK_H
#define RAIA_SKIA_STATIC_SK_SVG_MASK_H

#include "modules/svg/include/SkSVGMask.h"
#include <set>
#include <map>

typedef int sk_svg_mask_t;

int static_sk_svg_mask_make(sk_sp<SkSVGMask> value);
extern "C" void static_sk_svg_mask_delete(int key);
extern "C" SkSVGMask *static_sk_svg_mask_get(int key);
void static_sk_svg_mask_set(int key, sk_sp<SkSVGMask> value);
sk_sp<SkSVGMask> static_sk_svg_mask_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_MASK_H
