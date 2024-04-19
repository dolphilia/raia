//
// Created by dolphilia on 2024/01/10.
//

#include "sk_runtime_blend_builder.h"

extern "C" {

//SkRuntimeBlendBuilder(const SkRuntimeBlendBuilder &)=delete
//SkRuntimeBlendBuilder & operator=(const SkRuntimeBlendBuilder &)=delete

SkRuntimeBlendBuilder *SkRuntimeBlendBuilder_new(sk_runtime_effect_t runtime_effect) {
    return new SkRuntimeBlendBuilder(static_sk_runtime_effect_move(runtime_effect));
}

void SkRuntimeBlendBuilder_delete(SkRuntimeBlendBuilder *runtime_blend_builder) {
    delete runtime_blend_builder;
}

sk_blender_t SkRuntimeBlendBuilder_makeBlender(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_sk_blender_make(runtime_blend_builder->makeBlender());
}

const SkRuntimeEffect * SkRuntimeBlendBuilder_effect(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return runtime_blend_builder->effect();
}

sk_runtime_effect_builder_builder_uniform_t SkRuntimeBlendBuilder_uniform(SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_uniform_make(runtime_blend_builder->uniform(static_string_view_get(name)));
}

sk_runtime_effect_builder_builder_child_t SkRuntimeBlendBuilder_child(SkRuntimeBlendBuilder *runtime_blend_builder, string_view_t name) {
    return static_sk_runtime_effect_builder_builder_child_make(runtime_blend_builder->child(static_string_view_get(name)));
}

const_sk_data_t SkRuntimeBlendBuilder_uniforms(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_const_sk_data_make(runtime_blend_builder->uniforms());
}

const_sk_runtime_effect_child_ptr_t SkRuntimeBlendBuilder_children(SkRuntimeBlendBuilder *runtime_blend_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_blend_builder->children());
}

}