//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_PATH_H
#define RAIA_SKIA_STATIC_SK_SVG_PATH_H

#include "modules/svg/include/SkSVGPath.h"
#include <set>
#include <map>

typedef int sk_svg_path_t;

int static_sk_svg_path_make(sk_sp<SkSVGPath> value);
extern "C" void static_sk_svg_path_delete(int key);
extern "C" SkSVGPath *static_sk_svg_path_get(int key);
void static_sk_svg_path_set(int key, sk_sp<SkSVGPath> value);
sk_sp<SkSVGPath> static_sk_svg_path_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_PATH_H
