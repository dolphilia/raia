//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
#define RAIA_SKIA_SK_LUMA_COLOR_FILTER_H

#include "include/effects/SkLumaColorFilter.h"
#include "../static/static_sk_color_filter.h"

extern "C" {
// static
void SkLumaColorFilter_Make(const char *sk_color_filter_key_out);
}

#endif //RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
