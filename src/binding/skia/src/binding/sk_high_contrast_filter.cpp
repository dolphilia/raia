//
// Created by dolphilia on 2024/01/08.
//

#include "sk_high_contrast_filter.h"

extern "C" {

// static

void SkHighContrastFilter_Make(int sk_color_filter_key_out, const SkHighContrastConfig * config) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkHighContrastFilter::Make(*config));
}

}