//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_RECT_H
#define RAIA_SKIA_STATIC_SK_SVG_RECT_H

#include "modules/svg/include/SkSVGRect.h"
#include <set>
#include <map>

typedef int sk_svg_rect_t;

int static_sk_svg_rect_make(sk_sp<SkSVGRect> value);
extern "C" void static_sk_svg_rect_delete(int key);
extern "C" SkSVGRect *static_sk_svg_rect_get(int key);
void static_sk_svg_rect_set(int key, sk_sp<SkSVGRect> value);
sk_sp<SkSVGRect> static_sk_svg_rect_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_RECT_H
