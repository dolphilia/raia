//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_runtime_effect_builder_builder_child_t;
void static_sk_runtime_effect_builder_builder_child_delete(int key);
void * static_sk_runtime_effect_builder_builder_child_get_ptr(int key); // -> SkRuntimeEffectBuilder::BuilderChild *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H
