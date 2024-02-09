//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_TEXT_PATH_H
#define RAIA_SKIA_STATIC_SK_SVG_TEXT_PATH_H

#include "modules/svg/include/SkSVGText.h"
#include <set>
#include <map>

typedef int sk_svg_text_path_t;

int static_sk_svg_text_path_make(sk_sp<SkSVGTextPath> value);
extern "C" void static_sk_svg_text_path_delete(int key);
extern "C" SkSVGTextPath *static_sk_svg_text_path_get(int key);
void static_sk_svg_text_path_set(int key, sk_sp<SkSVGTextPath> value);
sk_sp<SkSVGTextPath> static_sk_svg_text_path_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_TEXT_PATH_H
