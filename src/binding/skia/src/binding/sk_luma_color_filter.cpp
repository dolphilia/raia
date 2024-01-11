//
// Created by dolphilia on 2024/01/09.
//

#include "sk_luma_color_filter.h"

extern "C" {

// static

void SkLumaColorFilter_Make(const char *sk_color_filter_key_out) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkLumaColorFilter::Make());
}

}