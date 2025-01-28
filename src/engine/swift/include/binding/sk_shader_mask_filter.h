//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SHADER_MASK_FILTER_H
#define RAIA_SKIA_SK_SHADER_MASK_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkShaderMaskFilter_delete(void *shaderMaskFilter); // (SkShaderMaskFilter *shaderMaskFilter)

// static

int SkShaderMaskFilter_Make(int shader); // (sk_shader_t shader) -> sk_mask_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SHADER_MASK_FILTER_H
