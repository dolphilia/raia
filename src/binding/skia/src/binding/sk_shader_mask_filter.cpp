//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shader_mask_filter.h"

extern "C" {

void SkShaderMaskFilter_delete(SkShaderMaskFilter *shaderMaskFilter) {
    delete shaderMaskFilter;
}

// static

sk_mask_filter_t SkShaderMaskFilter_Make(sk_shader_t shader) {
    return static_sk_mask_filter_make(SkShaderMaskFilter::Make(static_sk_shader_move(shader)));
}

}