//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_TEXT_H
#define RAIA_SKIA_STATIC_SK_SVG_TEXT_H

#include "modules/svg/include/SkSVGText.h"
#include <set>
#include <map>

typedef int sk_svg_text_t;

int static_sk_svg_text_make(sk_sp<SkSVGText> value);
extern "C" void static_sk_svg_text_delete(int key);
extern "C" SkSVGText *static_sk_svg_text_get(int key);
void static_sk_svg_text_set(int key, sk_sp<SkSVGText> value);
sk_sp<SkSVGText> static_sk_svg_text_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_TEXT_H
