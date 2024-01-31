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

SkRuntimeEffectBuilder::BuilderUniform SkRuntimeEffectBuilder_uniform(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->uniform(name);
}

SkRuntimeEffectBuilder::BuilderChild SkRuntimeEffectBuilder_child(SkRuntimeEffectBuilder *runtime_effect_builder, std::string_view name) {
    return runtime_effect_builder->child(name);
}

int SkRuntimeEffectBuilder_uniforms(SkRuntimeEffectBuilder *runtime_effect_builder) {
    return static_const_sk_data_make(runtime_effect_builder->uniforms());
}

int SkRuntimeEffectBuilder_children(SkRuntimeEffectBuilder *runtime_effect_builder) {
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