//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_PATTERN_H
#define RAIA_SKIA_STATIC_SK_SVG_PATTERN_H

#include "modules/svg/include/SkSVGPattern.h"
#include <set>
#include <map>

typedef int sk_svg_pattern_t;

int static_sk_svg_pattern_make(sk_sp<SkSVGPattern> value);
extern "C" void static_sk_svg_pattern_delete(int key);
extern "C" SkSVGPattern *static_sk_svg_pattern_get(int key);
void static_sk_svg_pattern_set(int key, sk_sp<SkSVGPattern> value);
sk_sp<SkSVGPattern> static_sk_svg_pattern_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_PATTERN_H
