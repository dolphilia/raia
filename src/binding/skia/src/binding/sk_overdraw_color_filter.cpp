//
// Created by dolphilia on 2024/01/09.
//

#include "sk_overdraw_color_filter.h"

extern "C" {

// static
void SkOverdrawColorFilter_MakeWithSkColors(int sk_color_filter_key_out, const SkColor color[SkOverdrawColorFilter::kNumColors]) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkOverdrawColorFilter::MakeWithSkColors(color));
}

}