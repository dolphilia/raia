//
// Created by dolphilia on 2024/01/08.
//

#include "sk_cubic_resampler.h"

extern "C" {

void SkCubicResampler_delete(SkCubicResampler *cubicResampler) {
    delete cubicResampler;
}

sk_cubic_resampler_t SkCubicResampler_Mitchell() {
    return static_sk_cubic_resampler_make(SkCubicResampler::Mitchell());
}

sk_cubic_resampler_t SkCubicResampler_CatmullRom() {
    return static_sk_cubic_resampler_make(SkCubicResampler::CatmullRom());
}

}