//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_effect_builder.h"

extern "C" {

void SkRuntimeEffectBuilder_delete(SkRuntimeEffectBuilder *runtime_effect_builder) {
    delete runtime_effect_builder;
}

const SkRuntimeEffect * SkRuntimeEffectBuilder_effect(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return runtime_effect_builder->effect();
}

sk_runtime_effect_builder_builder_uniform_t SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_uniform_make(runtime_effect_builder->uniform(static_string_view_get(name)));
}

sk_runtime_effect_builder_builder_child_t SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_child_make(runtime_effect_builder->child(static_string_view_get(name)));
}

const_sk_data_t SkRuntimeEffectBuilder_uniforms(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return static_const_sk_data_make(runtime_effect_builder->uniforms());
}

const_sk_runtime_effect_child_ptr_t SkRuntimeEffectBuilder_children(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_effect_builder->children());
}

// static

// SkRuntimeEffectBuilder()=delete
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect)
// SkRuntimeEffectBuilder(sk_sp<SkRuntimeEffect> effect, sk_sp<SkData> uniforms)
// SkRuntimeEffectBuilder(SkRuntimeEffectBuilder &&)
// SkRuntimeEffectBuilder(const SkRuntimeEffectBuilder &)
// SkRuntimeEffectBuilder & operator=(SkRuntimeEffectBuilder &&)=delete
// SkRuntimeEffectBuilder & operator=(const SkRuntimeEffectBuilder &)=delete

}