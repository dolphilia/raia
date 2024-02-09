//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_TURBULENCE_BASE_FREQUENCY_H
#define RAIA_SKIA_SK_SVG_FE_TURBULENCE_BASE_FREQUENCY_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
void SkSVGFeTurbulenceBaseFrequency_delete(SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency);
SkSVGFeTurbulenceBaseFrequency *SkSVGFeTurbulenceBaseFrequency_new();
SkSVGFeTurbulenceBaseFrequency *SkSVGFeTurbulenceBaseFrequency_new_2(SkSVGNumberType freqX, SkSVGNumberType freqY);
SkSVGNumberType SkSVGFeTurbulenceBaseFrequency_freqX (SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency);
SkSVGNumberType SkSVGFeTurbulenceBaseFrequency_freqY (SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency);
}

#endif //RAIA_SKIA_SK_SVG_FE_TURBULENCE_BASE_FREQUENCY_H
