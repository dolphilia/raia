//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H
#define RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H

#include "include/effects/SkHighContrastFilter.h"
#include "../static/static_sk_color_filter.h"

extern "C" {
void SkHighContrastFilter_delete(SkHighContrastFilter * highContrastFilter);
// static
sk_color_filter_t SkHighContrastFilter_Make(const SkHighContrastConfig * config);
}

#endif //RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H
