//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_FLOOD_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_FLOOD_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeFlood.h"

typedef int sk_svg_fe_flood_t;

int static_sk_svg_fe_flood_make(sk_sp<SkSVGFeFlood> value);
void static_sk_svg_fe_flood_delete(int key);
SkSVGFeFlood *static_sk_svg_fe_flood_get(int key);
void static_sk_svg_fe_flood_set(int key, sk_sp<SkSVGFeFlood> value);
sk_sp<SkSVGFeFlood> static_sk_svg_fe_flood_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_FLOOD_H
