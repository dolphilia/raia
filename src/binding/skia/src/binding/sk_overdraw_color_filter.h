//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H
#define RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H

#include "include/effects/SkOverdrawColorFilter.h"
#include "../static/static_sk_color_filter.h"

extern "C" {
// static
void SkOverdrawColorFilter_MakeWithSkColors(int sk_color_filter_key_out, const SkColor color[SkOverdrawColorFilter::kNumColors]);
}

#endif //RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H
