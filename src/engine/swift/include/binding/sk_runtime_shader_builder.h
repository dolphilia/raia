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
#include "../static/static_sk_runtime_effect_builder_builder_uniform.h"
#include "../static/static_sk_runtime_effect_builder_builder_child.h"
#include "../static/static_std_string_view.h"
#include "export_api.h"

extern "C" {
RAIA_API SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new(sk_runtime_effect_t runtime_effect);
RAIA_API SkRuntimeShaderBuilder *SkRuntimeShaderBuilder_new_2(const SkRuntimeShaderBuilder *builder);
RAIA_API void SkRuntimeShaderBuilder_delete(SkRuntimeShaderBuilder *runtime_shader_builder);
RAIA_API sk_shader_t SkRuntimeShaderBuilder_makeShader(SkRuntimeShaderBuilder *runtime_shader_builder, const SkMatrix *localMatrix);
RAIA_API const SkRuntimeEffect * SkRuntimeShaderBuilder_effect(SkRuntimeShaderBuilder *runtime_shader_builder);
RAIA_API sk_runtime_effect_builder_builder_uniform_t SkRuntimeShaderBuilder_uniform(SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name);
RAIA_API sk_runtime_effect_builder_builder_child_t SkRuntimeShaderBuilder_child(SkRuntimeShaderBuilder *runtime_shader_builder, string_view_t name);
RAIA_API const_sk_data_t SkRuntimeShaderBuilder_uniforms(SkRuntimeShaderBuilder *runtime_shader_builder);
RAIA_API const_sk_runtime_effect_child_ptr_t SkRuntimeShaderBuilder_children(SkRuntimeShaderBuilder *runtime_shader_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_SHADER_BUILDER_H
