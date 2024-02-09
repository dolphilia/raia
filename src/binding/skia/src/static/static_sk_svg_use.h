//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_USE_H
#define RAIA_SKIA_STATIC_SK_SVG_USE_H

#include "modules/svg/include/SkSVGUse.h"
#include <set>
#include <map>

typedef int sk_svg_use_t;

int static_sk_svg_use_make(sk_sp<SkSVGUse> value);
extern "C" void static_sk_svg_use_delete(int key);
extern "C" SkSVGUse *static_sk_svg_use_get(int key);
void static_sk_svg_use_set(int key, sk_sp<SkSVGUse> value);
sk_sp<SkSVGUse> static_sk_svg_use_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_USE_H
