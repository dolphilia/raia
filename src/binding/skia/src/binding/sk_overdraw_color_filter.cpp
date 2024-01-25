//
// Created by dolphilia on 2024/01/09.
//

#include "sk_overdraw_color_filter.h"

extern "C" {

// static
int SkOverdrawColorFilter_MakeWithSkColors(const SkColor color[SkOverdrawColorFilter::kNumColors]) {
    return static_sk_color_filter_make(SkOverdrawColorFilter::MakeWithSkColors(color));
}

}