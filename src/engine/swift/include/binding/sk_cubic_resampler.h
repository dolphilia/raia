//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CUBIC_RESAMPLER_H
#define RAIA_SKIA_SK_CUBIC_RESAMPLER_H

#include "include/core/SkSamplingOptions.h"
#include "../static/static_sk_cubic_resampler.h"

extern "C" {
void SkCubicResampler_delete(SkCubicResampler *cubicResampler);
sk_cubic_resampler_t SkCubicResampler_Mitchell();
sk_cubic_resampler_t SkCubicResampler_CatmullRom();
}

#endif //RAIA_SKIA_SK_CUBIC_RESAMPLER_H
