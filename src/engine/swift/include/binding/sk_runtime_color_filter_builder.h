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
#include "../static/static_sk_runtime_effect_builder_builder_uniform.h"
#include "../static/static_sk_runtime_effect_builder_builder_child.h"
#include "../static/static_std_string_view.h"

extern "C" {
//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete
SkRuntimeColorFilterBuilder *SkRuntimeColorFilterBuilder_new(sk_runtime_effect_t runtime_effect);
void SkRuntimeColorFilterBuilder_delete(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
sk_color_filter_t SkRuntimeColorFilterBuilder_makeColorFilter(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
const SkRuntimeEffect * SkRuntimeColorFilterBuilder_effect(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
sk_runtime_effect_builder_builder_uniform_t SkRuntimeColorFilterBuilder_uniform(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, string_view_t name);
sk_runtime_effect_builder_builder_child_t SkRuntimeColorFilterBuilder_child(SkRuntimeColorFilterBuilder *runtime_color_filter_builder, string_view_t name);
const_sk_data_t SkRuntimeColorFilterBuilder_uniforms(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
const_sk_runtime_effect_child_ptr_t SkRuntimeColorFilterBuilder_children(SkRuntimeColorFilterBuilder *runtime_color_filter_builder);
}

#endif //RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H
