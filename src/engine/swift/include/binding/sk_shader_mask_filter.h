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
#include "../static/static_sk_shader.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkShaderMaskFilter_delete(SkShaderMaskFilter *shaderMaskFilter);
// static
RAIA_API sk_mask_filter_t SkShaderMaskFilter_Make(sk_shader_t shader);
}

#endif //RAIA_SKIA_SK_SHADER_MASK_FILTER_H
