//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int const_sk_runtime_effect_uniform_t;
void static_const_sk_runtime_effect_uniform_delete(int key);
const void * static_const_sk_runtime_effect_uniform_get_ptr(int key, int index); // -> const SkRuntimeEffect::Uniform *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
