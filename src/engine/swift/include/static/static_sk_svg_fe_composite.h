//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_COMPOSITE_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_COMPOSITE_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGFeComposite.h"

typedef int sk_svg_fe_composite_t;

int static_sk_svg_fe_composite_make(sk_sp<SkSVGFeComposite> value);
extern "C" void static_sk_svg_fe_composite_delete(int key);
extern "C" SkSVGFeComposite *static_sk_svg_fe_composite_get(int key);
void static_sk_svg_fe_composite_set(int key, sk_sp<SkSVGFeComposite> value);
sk_sp<SkSVGFeComposite> static_sk_svg_fe_composite_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_COMPOSITE_H
