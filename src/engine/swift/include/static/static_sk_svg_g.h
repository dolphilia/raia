//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_G_H
#define RAIA_SKIA_STATIC_SK_SVG_G_H

#include "modules/svg/include/SkSVGG.h"
#include <set>
#include <map>

typedef int sk_svg_g_t;

int static_sk_svg_g_make(sk_sp<SkSVGG> value);
extern "C" void static_sk_svg_g_delete(int key);
extern "C" SkSVGG *static_sk_svg_g_get(int key);
void static_sk_svg_g_set(int key, sk_sp<SkSVGG> value);
sk_sp<SkSVGG> static_sk_svg_g_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_G_H
