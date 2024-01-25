//
// Created by dolphilia on 2024/01/10.
//

#include "sk_runtime_blend_builder.h"

extern "C" {

//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete

SkRuntimeBlendBuilder *SkRuntimeBlendBuilder_new(int sk_runtime_effect_key_in) {
    return new SkRuntimeBlendBuilder(static_sk_runtime_effect_move(sk_runtime_effect_key_in));
}

void SkRuntimeBlendBuilder_delete(SkRuntimeBlendBuilder *runtime_blend_builder) {
    delete runtime_blend_builder;
}

int SkRuntimeBlendBuilder_makeBlender(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_sk_blender_make(runtime_blend_builder->makeBlender());
}

const SkRuntimeEffect * SkRuntimeBlendBuilder_effect(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->effect();
}

SkRuntimeBlendBuilder::BuilderUniform SkRuntimeBlendBuilder_uniform(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name) {
    return runtime_blend_builder->uniform(name);
}

SkRuntimeBlendBuilder::BuilderChild SkRuntimeBlendBuilder_child(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name) {
    return runtime_blend_builder->child(name);
}

int SkRuntimeBlendBuilder_uniforms(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_const_sk_data_make(runtime_blend_builder->uniforms());
}

int SkRuntimeBlendBuilder_children(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_blend_builder->children());
}

}