//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H

#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"

extern "C" {
//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete
SkRuntimeBlendBuilder *SkRuntimeBlendBuilder_new(sk_sp<SkRuntimeEffect> runtime_effect);
void SkRuntimeBlendBuilder_delete(SkRuntimeBlendBuilder *runtime_blend_builder);
void SkRuntimeBlendBuilder_makeBlender(const char *sk_blender_key_out, SkRuntimeBlendBuilder *runtime_blend_builder);
const SkRuntimeEffect * SkRuntimeBlendBuilder_effect(SkRuntimeBlendBuilder *runtime_blend_builder);
SkRuntimeBlendBuilder::BuilderUniform SkRuntimeBlendBuilder_uniform(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name);
SkRuntimeBlendBuilder::BuilderChild SkRuntimeBlendBuilder_child(SkRuntimeBlendBuilder *runtime_blend_builder, std::string_view name);
void SkRuntimeBlendBuilder_uniforms(const char *sk_data_key_out, SkRuntimeBlendBuilder *runtime_blend_builder);
void SkRuntimeBlendBuilder_children(const char *sk_runtime_effect_child_ptr_key_out, SkRuntimeBlendBuilder *runtime_blend_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H