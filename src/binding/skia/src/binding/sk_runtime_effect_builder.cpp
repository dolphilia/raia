//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_effect_builder.h"

extern "C" {

const SkRuntimeEffect * SkRuntimeEffectBuilder_effect(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return runtime_effect_builder->effect();
}

SkRuntimeEffectBuilder::BuilderUniform SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->uniform(name);
}

SkRuntimeEffectBuilder::BuilderChild SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->child(name);
}

void SkRuntimeEffectBuilder_uniforms(const char *sk_data_key_out, SkRuntimeEffectBuilder *runtime_effect_builder) {
    static_const_sk_data_set(sk_data_key_out, runtime_effect_builder->uniforms());
}

void SkRuntimeEffectBuilder_children(const char *sk_runtime_effect_child_ptr_key_out, SkRuntimeEffectBuilder *runtime_effect_builder) {
    static_const_sk_runtime_effect_child_ptr_set(sk_runtime_effect_child_ptr_key_out, runtime_effect_builder->children());
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