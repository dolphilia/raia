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

void SkRuntimeBlendBuilder_makeBlender(int sk_blender_key_out, SkRuntimeBlendBuilder *runtime_blend_builder) {
    static_sk_blender_set(sk_blender_key_out, runtime_blend_builder->makeBlender());
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

void SkRuntimeBlendBuilder_uniforms(int sk_data_key_out, SkRuntimeBlendBuilder *runtime_blend_builder) {
    static_const_sk_data_set(sk_data_key_out, runtime_blend_builder->uniforms());
}

void SkRuntimeBlendBuilder_children(int sk_runtime_effect_child_ptr_key_out, SkRuntimeBlendBuilder *runtime_blend_builder) {
    static_const_sk_runtime_effect_child_ptr_set(sk_runtime_effect_child_ptr_key_out, runtime_blend_builder->children());
}

}