//
// Created by dolphilia on 2024/01/09.
//

#include "sk_luma_color_filter.h"

extern "C" {

// static

int SkLumaColorFilter_Make() {
    return static_sk_color_filter_make(SkLumaColorFilter::Make());
}

}