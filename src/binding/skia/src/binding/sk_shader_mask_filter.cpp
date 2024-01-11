//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shader_mask_filter.h"

extern "C" {

// static

void SkShaderMaskFilter_Make(const char *sk_mask_filter_key_out, sk_sp<SkShader> shader) {
    static_sk_mask_filter_set(sk_mask_filter_key_out, SkShaderMaskFilter::Make(std::move(shader)));
}

}