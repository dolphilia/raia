//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_FE_MORPHOLOGY_H
#define RAIA_SKIA_STATIC_SK_SVG_FE_MORPHOLOGY_H

#include "modules/svg/include/SkSVGFeMorphology.h"
#include <set>
#include <map>

typedef int sk_svg_fe_morphology_t;

int static_sk_svg_fe_morphology_make(sk_sp<SkSVGFeMorphology> value);
extern "C" void static_sk_svg_fe_morphology_delete(int key);
extern "C" SkSVGFeMorphology *static_sk_svg_fe_morphology_get(int key);
void static_sk_svg_fe_morphology_set(int key, sk_sp<SkSVGFeMorphology> value);
sk_sp<SkSVGFeMorphology> static_sk_svg_fe_morphology_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_FE_MORPHOLOGY_H
