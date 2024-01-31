//
// Created by dolphilia on 2024/01/08.
//

#include "sk_cubic_resampler.h"

extern "C" {

void SkCubicResampler_delete(SkCubicResampler *cubicResampler) {
    delete cubicResampler;
}

SkCubicResampler SkCubicResampler_Mitchell() {
    return SkCubicResampler::Mitchell();
}

SkCubicResampler SkCubicResampler_CatmullRom() {
    return SkCubicResampler::CatmullRom();
}

}