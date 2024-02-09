//
// Created by dolphilia on 2024/02/08.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_DOM_H
#define RAIA_SKIA_STATIC_SK_SVG_DOM_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGDOM.h"

typedef int sk_svg_dom_t;

int static_sk_svg_dom_make(sk_sp<SkSVGDOM> value);
extern "C" void static_sk_svg_dom_delete(int key);
extern "C" SkSVGDOM *static_sk_svg_dom_get(int key);
void static_sk_svg_dom_set(int key, sk_sp<SkSVGDOM> value);
sk_sp<SkSVGDOM> static_sk_svg_dom_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_DOM_H
