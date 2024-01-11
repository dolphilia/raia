//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CUBIC_RESAMPLER_H
#define RAIA_SKIA_SK_CUBIC_RESAMPLER_H

#include "include/core/SkSamplingOptions.h"

extern "C" {
SkCubicResampler SkCubicResampler_Mitchell();
SkCubicResampler SkCubicResampler_CatmullRom();
}

#endif //RAIA_SKIA_SK_CUBIC_RESAMPLER_H
