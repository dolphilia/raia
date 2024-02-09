//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_ELLIPSE_H
#define RAIA_SKIA_STATIC_SK_SVG_ELLIPSE_H

#include <set>
#include <map>
#include "modules/svg/include/SkSVGEllipse.h"

typedef int sk_svg_ellipse_t;

int static_sk_svg_ellipse_make(sk_sp<SkSVGEllipse> value);
extern "C" void static_sk_svg_ellipse_delete(int key);
extern "C" SkSVGEllipse *static_sk_svg_ellipse_get(int key);
void static_sk_svg_ellipse_set(int key, sk_sp<SkSVGEllipse> value);
sk_sp<SkSVGEllipse> static_sk_svg_ellipse_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_ELLIPSE_H
