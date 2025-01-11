//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H

#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_runtime_effect.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"
#include "../static/static_std_string_view.h"
#include "../static/static_sk_runtime_effect_builder_builder_uniform.h"
#include "../static/static_sk_runtime_effect_builder_builder_child.h"
#include "export_api.h"

extern "C" {
//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete
RAIA_API SkRuntimeBlendBuilder *SkRuntimeBlendBuilder_new(sk_runtime_effect_t runtime_effect);
RAIA_API void SkRuntimeBlendBuilder_delete(SkRuntimeBlendBuilder *runtime_blend_builder);
RAIA_API sk_blender_t SkRuntimeBlendBuilder_makeBlender(SkRuntimeBlendBuilder *runtime_blend_builder);
RAIA_API const SkRuntimeEffect * SkRuntimeBlendBuilder_effect(SkRuntimeBlendBuilder *runtime_blend_builder);
RAIA_API sk_runtime_effect_builder_builder_uniform_t SkRuntimeBlendBuilder_uniform(SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name);
RAIA_API sk_runtime_effect_builder_builder_child_t SkRuntimeBlendBuilder_child(SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name);
RAIA_API const_sk_data_t SkRuntimeBlendBuilder_uniforms(SkRuntimeBlendBuilder *runtime_blend_builder);
RAIA_API const_sk_runtime_effect_child_ptr_t SkRuntimeBlendBuilder_children(SkRuntimeBlendBuilder *runtime_blend_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H
