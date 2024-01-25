//
// Created by dolphilia on 2024/01/08.
//

#include "sk_high_contrast_filter.h"

extern "C" {

// static

int SkHighContrastFilter_Make(const SkHighContrastConfig * config) {
    return static_sk_color_filter_make(SkHighContrastFilter::Make(*config));
}

}