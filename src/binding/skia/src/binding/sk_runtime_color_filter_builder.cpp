//
// Created by dolphilia on 2024/01/10.
//

#include "sk_runtime_color_filter_builder.h"

#include <utility>
#include "include/effects/SkRuntimeEffect.h"

extern "C" {

//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete

SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(sk_sp<SkRuntimeEffect> runtime_effect) {
    return new SkRuntimeColorFilterBuilder(std::move(runtime_effect));
}

void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    delete runtime_color_filter_builder;
}

sk_sp<SkColorFilter> SkRuntimeColorFilterBuilder_makeColorFilter(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->makeColorFilter();
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

sk_sp<const SkData> SkRuntimeColorFilterBuilder_uniforms(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->uniforms();
}

SkSpan<const SkRuntimeEffect::ChildPtr> SkRuntimeColorFilterBuilder_children(SkRuntimeColorFilterBuilder *runtime_color_filter_builder) {
    return runtime_color_filter_builder->children();
}

}