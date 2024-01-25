//
// Created by dolphilia on 2024/01/10.
//

#include "sk_runtime_color_filter_builder.h"

extern "C" {

//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete

SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(int sk_runtime_effect_key_in) {
    return new SkRuntimeColorFilterBuilder(static_sk_runtime_effect_move(sk_runtime_effect_key_in));
}

void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    delete runtime_color_filter_builder;
}

void SkRuntimeColorFilterBuilder_makeColorFilter(int sk_color_filter_key_out, SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    static_sk_color_filter_set(sk_color_filter_key_out, runtime_color_filter_builder->makeColorFilter());
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

void SkRuntimeColorFilterBuilder_uniforms(int sk_data_key_out, SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    static_const_sk_data_set(sk_data_key_out, runtime_color_filter_builder->uniforms());
}

void SkRuntimeColorFilterBuilder_children(int sk_runtime_effect_child_ptr_key_out, SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    static_const_sk_runtime_effect_child_ptr_set(sk_runtime_effect_child_ptr_key_out, runtime_color_filter_builder->children());
}

}