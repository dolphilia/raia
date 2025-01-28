//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_runtime_effect_result_t;
void static_sk_runtime_effect_result_delete(int key);
void * static_sk_runtime_effect_result_get_ptr(int key); // -> SkRuntimeEffect::Result *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
