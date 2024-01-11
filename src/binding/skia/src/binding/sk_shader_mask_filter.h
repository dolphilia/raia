//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SHADER_MASK_FILTER_H
#define RAIA_SKIA_SK_SHADER_MASK_FILTER_H

#include <utility>
#include "include/core/SkShader.h"
#include "include/core/SkMaskFilter.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "../static/static_sk_mask_filter.h"

extern "C" {
// static
void SkShaderMaskFilter_Make(const char *sk_mask_filter_key_out, sk_sp<SkShader> shader);
}

#endif //RAIA_SKIA_SK_SHADER_MASK_FILTER_H
