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

sk_runtime_effect_builder_builder_uniform_t SkRuntimeShaderBuilder_uniform(SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_uniform_make(runtime_shader_builder->uniform(static_string_view_get(name)));
}

sk_runtime_effect_builder_builder_child_t SkRuntimeShaderBuilder_child(SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_child_make(runtime_shader_builder->child(static_string_view_get(name)));
}

const_sk_data_t SkRuntimeShaderBuilder_uniforms(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return static_const_sk_data_make(runtime_shader_builder->uniforms());
}

const_sk_runtime_effect_child_ptr_t SkRuntimeShaderBuilder_children(SkRuntimeShaderBuilder *runtime_shader_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_shader_builder->children());
}

}