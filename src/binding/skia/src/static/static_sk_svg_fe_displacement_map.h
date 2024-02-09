//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_DISPLACEMENT_MAP_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_DISPLACEMENT_MAP_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeDisplacementMap.h"

typedef int sk_svg_fe_displacement_map_t;

int static_sk_svg_fe_displacement_map_make(sk_sp<SkSVGFeDisplacementMap> value);
extern "C" void static_sk_svg_fe_displacement_map_delete(int key);
extern "C" SkSVGFeDisplacementMap *static_sk_svg_fe_displacement_map_get(int key);
void static_sk_svg_fe_displacement_map_set(int key, sk_sp<SkSVGFeDisplacementMap> value);
sk_sp<SkSVGFeDisplacementMap> static_sk_svg_fe_displacement_map_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_DISPLACEMENT_MAP_H
