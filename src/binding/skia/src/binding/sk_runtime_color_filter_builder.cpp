//
// Created by dolphilia on 2024/01/10.
//

#include "sk_runtime_color_filter_builder.h"

extern "C" {

//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete

SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(sk_runtime_effect_t runtime_effect) {
    return new SkRuntimeColorFilterBuilder(static_sk_runtime_effect_move(runtime_effect));
}

void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    delete runtime_color_filter_builder;
}

sk_color_filter_t SkRuntimeColorFilterBuilder_makeColorFilter(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return static_sk_color_filter_make(runtime_color_filter_builder->makeColorFilter());
}

const SkRuntimeEffect * SkRuntimeColorFilterBuilder_effect(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->effect();
}

SkRuntimeColorFilterBuilder::BuilderUniform SkRuntimeColorFilterBuilder_uniform(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name) {
    return runtime_color_filter_builder->uniform(name);
}

SkRuntimeColorFilterBuilder::BuilderChild SkRuntimeColorFilterBuilder_child(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name) {
    return runtime_color_filter_builder->child(name);
}

const_sk_data_t SkRuntimeColorFilterBuilder_uniforms(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return static_const_sk_data_make(runtime_color_filter_builder->uniforms());
}

const_sk_runtime_effect_child_ptr_t SkRuntimeColorFilterBuilder_children(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return static_const_sk_runtime_effect_child_ptr_make(runtime_color_filter_builder->children());
}

}