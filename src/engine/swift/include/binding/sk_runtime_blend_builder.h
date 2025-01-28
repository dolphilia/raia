//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete

void *SkRuntimeBlendBuilder_new(int runtime_effect); // (sk_runtime_effect_t runtime_effect) -> SkRuntimeBlendBuilder *
void SkRuntimeBlendBuilder_delete(void *runtime_blend_builder); // (SkRuntimeBlendBuilder *runtime_blend_builder)
int SkRuntimeBlendBuilder_makeBlender(void *runtime_blend_builder); // (SkRuntimeBlendBuilder *runtime_blend_builder) -> sk_blender_t
const void *SkRuntimeBlendBuilder_effect(void *runtime_blend_builder); // (SkRuntimeBlendBuilder *runtime_blend_builder) -> const SkRuntimeEffect *
int SkRuntimeBlendBuilder_uniform(void *runtime_blend_builder, int name); // (SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name) -> sk_runtime_effect_builder_builder_uniform_t
int SkRuntimeBlendBuilder_child(void *runtime_blend_builder, int name); // (SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name) -> sk_runtime_effect_builder_builder_child_t
int SkRuntimeBlendBuilder_uniforms(void *runtime_blend_builder); // (SkRuntimeBlendBuilder *runtime_blend_builder) -> const_sk_data_t
int SkRuntimeBlendBuilder_children(void *runtime_blend_builder); // (SkRuntimeBlendBuilder *runtime_blend_builder) -> const_sk_runtime_effect_child_ptr_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RUNTIME_BLEND_BUILDER_H
