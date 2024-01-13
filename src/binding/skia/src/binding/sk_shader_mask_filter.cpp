//
// Created by dolphilia on 2024/01/11.
//

#include "sk_shader_mask_filter.h"

extern "C" {

// static

void SkShaderMaskFilter_Make(const char *sk_mask_filter_key_out, const char *sk_shader_key_in) {
    static_sk_mask_filter_set(sk_mask_filter_key_out, SkShaderMaskFilter::Make(static_sk_shader_move(sk_shader_key_in)));
}

}