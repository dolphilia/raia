//
// Created by dolphilia on 2024/02/03.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_CIRCLE_H
#define RAIA_SKIA_STATIC_SK_SVG_CIRCLE_H

#include <set>
#include <string>
#include <map>
#include "modules/svg/include/SkSVGCircle.h"

typedef int sk_svg_circle_t;

int static_sk_svg_circle_make(sk_sp<SkSVGCircle> value);
extern "C" void static_sk_svg_circle_delete(int key);
extern "C" SkSVGCircle *static_sk_svg_circle_get(int key);
void static_sk_svg_circle_set(int key, sk_sp<SkSVGCircle> value);
sk_sp<SkSVGCircle> static_sk_svg_circle_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_CIRCLE_H
