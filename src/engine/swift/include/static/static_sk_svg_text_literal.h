//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_TEXT_LITERAL_H
#define RAIA_SKIA_STATIC_SK_SVG_TEXT_LITERAL_H

#include "modules/svg/include/SkSVGText.h"
#include <set>
#include <map>

typedef int sk_svg_text_literal_t;

int static_sk_svg_text_literal_make(sk_sp<SkSVGTextLiteral> value);
extern "C" void static_sk_svg_text_literal_delete(int key);
extern "C" SkSVGTextLiteral *static_sk_svg_text_literal_get(int key);
void static_sk_svg_text_literal_set(int key, sk_sp<SkSVGTextLiteral> value);
sk_sp<SkSVGTextLiteral> static_sk_svg_text_literal_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_TEXT_LITERAL_H
