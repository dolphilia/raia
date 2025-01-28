//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkRuntimeShaderBuilder_new(int runtime_effect); // (sk_runtime_effect_t runtime_effect) -> SkRuntimeShaderBuilder *
void *SkRuntimeShaderBuilder_new_2(const void *builder); // (const SkRuntimeShaderBuilder *builder) -> SkRuntimeShaderBuilder *
void SkRuntimeShaderBuilder_delete(void *runtime_shader_builder); // (SkRuntimeShaderBuilder *runtime_shader_builder)
int SkRuntimeShaderBuilder_makeShader(void *runtime_shader_builder, const void *localMatrix); // (SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix) -> sk_shader_t
const void *SkRuntimeShaderBuilder_effect(void *runtime_shader_builder); // (SkRuntimeShaderBuilder *runtime_shader_builder) -> const SkRuntimeEffect *
int SkRuntimeShaderBuilder_uniform(void *runtime_shader_builder, int name); // (SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name) -> sk_runtime_effect_builder_builder_uniform_t
int SkRuntimeShaderBuilder_child(void *runtime_shader_builder, int name); // (SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name) -> sk_runtime_effect_builder_builder_child_t
int SkRuntimeShaderBuilder_uniforms(void *runtime_shader_builder); // (SkRuntimeShaderBuilder *runtime_shader_builder) -> const_sk_data_t
int SkRuntimeShaderBuilder_children(void *runtime_shader_builder); // (SkRuntimeShaderBuilder *runtime_shader_builder) -> const_sk_runtime_effect_child_ptr_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H
