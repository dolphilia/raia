//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H

#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_runtime_effect.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"

extern "C" {
SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new(const char *sk_runtime_effect_key_in);
SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new_2(const SkRuntimeShaderBuilder *builder);
void SkRuntimeShaderBuilder_delete(SkRuntimeShaderBuilder *runtime_shader_builder);
void SkRuntimeShaderBuilder_makeShader(const char *sk_shader_key_out, SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix);
const SkRuntimeEffect * SkRuntimeShaderBuilder_effect(SkRuntimeShaderBuilder *runtime_shader_builder);
SkRuntimeShaderBuilder::BuilderUniform SkRuntimeShaderBuilder_uniform(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name);
SkRuntimeShaderBuilder::BuilderChild SkRuntimeShaderBuilder_child(SkRuntimeShaderBuilder *runtime_shader_builder, std::string_view name);
void SkRuntimeShaderBuilder_uniforms(const char *sk_data_key_out, SkRuntimeShaderBuilder *runtime_shader_builder);
void SkRuntimeShaderBuilder_children(const char *sk_runtime_effect_child_ptr_key_out, SkRuntimeShaderBuilder *runtime_shader_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H
