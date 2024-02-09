//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_SVG_H
#define RAIA_SKIA_STATIC_SK_SVG_SVG_H

#include "modules/svg/include/SkSVGSVG.h"
#include <set>
#include <map>

typedef int sk_svg_svg_t;

int static_sk_svg_svg_make(sk_sp<SkSVGSVG> value);
extern "C" void static_sk_svg_svg_delete(int key);
extern "C" SkSVGSVG *static_sk_svg_svg_get(int key);
void static_sk_svg_svg_set(int key, sk_sp<SkSVGSVG> value);
sk_sp<SkSVGSVG> static_sk_svg_svg_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_SVG_H
