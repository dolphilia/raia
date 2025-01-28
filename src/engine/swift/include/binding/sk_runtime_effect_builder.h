//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkRuntimeEffectBuilder_delete(void *runtime_effect_builder); // (SkRuntimeEffectBuilder *runtime_effect_builder)
const void *SkRuntimeEffectBuilder_effect(void *runtime_effect_builder); // (SkRuntimeEffectBuilder *runtime_effect_builder) -> const SkRuntimeEffect *
int SkRuntimeEffectBuilder_uniform(void *runtime_effect_builder, int name); // (SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name) -> sk_runtime_effect_builder_builder_uniform_t
int SkRuntimeEffectBuilder_child(void *runtime_effect_builder, int name); // (SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name) -> sk_runtime_effect_builder_builder_child_t
int SkRuntimeEffectBuilder_uniforms(void *runtime_effect_builder); // (SkRuntimeEffectBuilder *runtime_effect_builder) -> const_sk_data_t
int SkRuntimeEffectBuilder_children(void *runtime_effect_builder); // (SkRuntimeEffectBuilder *runtime_effect_builder) -> const_sk_runtime_effect_child_ptr_t

// static

// SkRuntimeEffectBuilder()=delete
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect)
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect, sk_sp<SkData> uniforms)
// SkRuntimeEffectBuilder(SkRuntimeEffectBuilder &&)
// SkRuntimeEffectBuilder(const SkRuntimeEffectBuilder &)
// SkRuntimeEffectBuilder & operator=(SkRuntimeEffectBuilder &&)=delete
// SkRuntimeEffectBuilder & operator=(const SkRuntimeEffectBuilder &)=delete

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_BUILDER_H
