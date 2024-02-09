//
// Created by dolphilia on 2024/01/09.
//

#include "sk_luma_color_filter.h"

extern "C" {

void SkLumaColorFilter_delete(SkLumaColorFilter * lumaColorFilter) {
    delete lumaColorFilter;
}

// static

sk_color_filter_t SkLumaColorFilter_Make() {
    return static_sk_color_filter_make(SkLumaColorFilter::Make());
}

}