//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
#define RAIA_SKIA_SK_LUMA_COLOR_FILTER_H

#include "include/effects/SkLumaColorFilter.h"
#include "../static/static_sk_color_filter.h"

extern "C" {
void SkLumaColorFilter_delete(SkLumaColorFilter * lumaColorFilter);
// static
sk_color_filter_t SkLumaColorFilter_Make();
}

#endif //RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
