//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_runtime_effect_traced_shader_t;
void static_sk_runtime_effect_traced_shader_delete(int key);
void * static_sk_runtime_effect_traced_shader_get_ptr(int key); // -> SkRuntimeEffect::TracedShader *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H
