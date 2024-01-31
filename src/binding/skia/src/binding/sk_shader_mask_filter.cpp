//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shader_mask_filter.h"

extern "C" {

void SkShaderMaskFilter_delete(SkShaderMaskFilter *shaderMaskFilter) {
    delete shaderMaskFilter;
}

// static

int SkShaderMaskFilter_Make(int sk_shader_key_in) {
    return static_sk_mask_filter_make(SkShaderMaskFilter::Make(static_sk_shader_move(sk_shader_key_in)));
}

}