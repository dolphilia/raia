//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_runtime_effect_t;
void static_sk_runtime_effect_delete(int key);
void *static_sk_runtime_effect_get(int key); // -> SkRuntimeEffect *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
