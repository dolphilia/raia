//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_T_SPAN_H
#define RAIA_SKIA_STATIC_SK_SVG_T_SPAN_H

#include "modules/svg/include/SkSVGText.h"
#include <set>
#include <map>

typedef int sk_svg_t_span_t;

int static_sk_svg_t_span_make(sk_sp<SkSVGTSpan> value);
extern "C" void static_sk_svg_t_span_delete(int key);
extern "C" SkSVGTSpan *static_sk_svg_t_span_get(int key);
void static_sk_svg_t_span_set(int key, sk_sp<SkSVGTSpan> value);
sk_sp<SkSVGTSpan> static_sk_svg_t_span_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_T_SPAN_H
