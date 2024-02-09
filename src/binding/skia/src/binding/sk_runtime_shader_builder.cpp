//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_shader_builder.h"

extern "C" {

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new(sk_runtime_effect_t runtime_effect) {
    return new SkRuntimeShaderBuilder(static_sk_runtime_effect_move(runtime_effect));
}

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new_2(const SkRuntimeShaderBuilder *builder) {
    return new SkRuntimeShaderBuilder(*builder);
}

void SkRuntimeShaderBuilder_delete(SkRuntimeShaderBuilder *runtime_shader_builder) {
    delete runtime_shader_builder;
}

sk_shader_t SkRuntimeShaderBuilder_makeShader(SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix) {
    return static_sk_shader_make(runtime_shader_builder->makeShader(localMatrix));
}

const SkRuntimeEffect * SkRuntimeShaderBuilder_effect(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return runtime_shader_builder->effect();
}

SkRuntimeShaderBuilder::BuilderUniform SkRuntimeShaderBuilder_uniform(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name) {
    return runtime_shader_builder->uniform(name);
}

SkRuntimeShaderBuilder::BuilderChild SkRuntimeShaderBuilder_child(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name) {
    return runtime_shader_builder->child(name);
}

const_sk_data_t SkRuntimeShaderBuilder_uniforms(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return static_const_sk_data_make(runtime_shader_builder->uniforms());
}

const_sk_runtime_effect_child_ptr_t SkRuntimeShaderBuilder_children(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_shader_builder->children());
}

}