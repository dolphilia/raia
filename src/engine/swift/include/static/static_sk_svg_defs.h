//
// Created by dolphilia on 2024/02/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_DEFS_H
#define RAIA_SKIA_STATIC_SK_SVG_DEFS_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGDefs.h"

typedef int sk_svg_defs_t;

int static_sk_svg_defs_make(sk_sp<SkSVGDefs> value);
extern "C" void static_sk_svg_defs_delete(int key);
extern "C" SkSVGDefs *static_sk_svg_defs_get(int key);
void static_sk_svg_defs_set(int key, sk_sp<SkSVGDefs> value);
sk_sp<SkSVGDefs> static_sk_svg_defs_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_DEFS_H
