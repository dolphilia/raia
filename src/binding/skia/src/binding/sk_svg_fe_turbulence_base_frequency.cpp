//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_turbulence_base_frequency.h"

extern "C" {

void SkSVGFeTurbulenceBaseFrequency_delete(SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency) {
    delete svgFeTurbulenceBaseFrequency;
}

SkSVGFeTurbulenceBaseFrequency *SkSVGFeTurbulenceBaseFrequency_new() {
    return new SkSVGFeTurbulenceBaseFrequency();
}

SkSVGFeTurbulenceBaseFrequency *SkSVGFeTurbulenceBaseFrequency_new_2(SkSVGNumberType freqX, SkSVGNumberType freqY) {
    return new SkSVGFeTurbulenceBaseFrequency(freqX, freqY);
}

SkSVGNumberType SkSVGFeTurbulenceBaseFrequency_freqX (SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency) {
    return svgFeTurbulenceBaseFrequency->freqX();
}

SkSVGNumberType SkSVGFeTurbulenceBaseFrequency_freqY (SkSVGFeTurbulenceBaseFrequency *svgFeTurbulenceBaseFrequency) {
    return svgFeTurbulenceBaseFrequency->freqY();
}

}