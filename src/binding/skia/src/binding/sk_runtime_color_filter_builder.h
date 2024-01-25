//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H

#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_runtime_effect.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"

extern "C" {
//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete
SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(int sk_runtime_effect_key_in);
void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
int SkRuntimeColorFilterBuilder_makeColorFilter(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
const SkRuntimeEffect * SkRuntimeColorFilterBuilder_effect(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
SkRuntimeColorFilterBuilder::BuilderUniform SkRuntimeColorFilterBuilder_uniform(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name);
SkRuntimeColorFilterBuilder::BuilderChild SkRuntimeColorFilterBuilder_child(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, std::string_view name);
int SkRuntimeColorFilterBuilder_uniforms(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
int SkRuntimeColorFilterBuilder_children(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H
