//
// Created by dolphilia on 2024/01/11.
//

#include "sk_runtime_shader_builder.h"

extern "C" {

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new(const char *sk_runtime_effect_key_in) {
    return new SkRuntimeShaderBuilder(static_sk_runtime_effect_move(sk_runtime_effect_key_in));
}

SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new_2(const SkRuntimeShaderBuilder *builder) {
    return new SkRuntimeShaderBuilder(*builder);
}

void SkRuntimeShaderBuilder_delete(SkRuntimeShaderBuilder *runtime_shader_builder) {
    delete runtime_shader_builder;
}

void SkRuntimeShaderBuilder_makeShader(const char *sk_shader_key_out, SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, runtime_shader_builder->makeShader(localMatrix));
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

void SkRuntimeShaderBuilder_uniforms(const char *sk_data_key_out, SkRuntimeShaderBuilder *runtime_shader_builder) {
    static_const_sk_data_set(sk_data_key_out, runtime_shader_builder->uniforms());
}

void SkRuntimeShaderBuilder_children(const char *sk_runtime_effect_child_ptr_key_out, SkRuntimeShaderBuilder *runtime_shader_builder) {
    static_const_sk_runtime_effect_child_ptr_set(sk_runtime_effect_child_ptr_key_out, runtime_shader_builder->children());
}

}