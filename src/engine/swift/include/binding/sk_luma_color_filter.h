//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
#define RAIA_SKIA_SK_LUMA_COLOR_FILTER_H

#include "include/effects/SkLumaColorFilter.h"
#include "../static/static_sk_color_filter.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkLumaColorFilter_delete(SkLumaColorFilter * lumaColorFilter);
// static
RAIA_API sk_color_filter_t SkLumaColorFilter_Make();
}

#endif //RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
