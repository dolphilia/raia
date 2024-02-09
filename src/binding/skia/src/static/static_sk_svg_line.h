//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_LINE_H
#define RAIA_SKIA_STATIC_SK_SVG_LINE_H

#include "modules/svg/include/SkSVGLine.h"
#include <set>
#include <map>

typedef int sk_svg_line_t;

int static_sk_svg_line_make(sk_sp<SkSVGLine> value);
extern "C" void static_sk_svg_line_delete(int key);
extern "C" SkSVGLine *static_sk_svg_line_get(int key);
void static_sk_svg_line_set(int key, sk_sp<SkSVGLine> value);
sk_sp<SkSVGLine> static_sk_svg_line_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_LINE_H
