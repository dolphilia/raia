//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_STOP_H
#define RAIA_SKIA_STATIC_SK_SVG_STOP_H

#include "modules/svg/include/SkSVGStop.h"
#include <set>
#include <map>

typedef int sk_svg_stop_t;

int static_sk_svg_stop_make(sk_sp<SkSVGStop> value);
extern "C" void static_sk_svg_stop_delete(int key);
extern "C" SkSVGStop *static_sk_svg_stop_get(int key);
void static_sk_svg_stop_set(int key, sk_sp<SkSVGStop> value);
sk_sp<SkSVGStop> static_sk_svg_stop_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_STOP_H
