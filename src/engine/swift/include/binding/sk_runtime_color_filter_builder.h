//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H
#define RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

//SkRuntimeColorFilterBuilder(const SkRuntimeColorFilterBuilder &)=delete
//SkRuntimeColorFilterBuilder & operator=(const SkRuntimeColorFilterBuilder &)=delete

void *SkRuntimeColorFilterBuilder_new(int runtime_effect); // (sk_runtime_effect_t runtime_effect) -> SkRuntimeColorFilterBuilder *
void SkRuntimeColorFilterBuilder_delete(void *runtime_color_filter_builder); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder)
int SkRuntimeColorFilterBuilder_makeColorFilter(void *runtime_color_filter_builder); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder) -> sk_color_filter_t
const void *SkRuntimeColorFilterBuilder_effect(void *runtime_color_filter_builder); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder) -> const SkRuntimeEffect *
int SkRuntimeColorFilterBuilder_uniform(void *runtime_color_filter_builder, int name); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder, string_view_t name) -> sk_runtime_effect_builder_builder_uniform_t
int SkRuntimeColorFilterBuilder_child(void *runtime_color_filter_builder, int name); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder, string_view_t name) -> sk_runtime_effect_builder_builder_child_t
int SkRuntimeColorFilterBuilder_uniforms(void *runtime_color_filter_builder); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder) -> const_sk_data_t
int SkRuntimeColorFilterBuilder_children(void *runtime_color_filter_builder); // (SkRuntimeColorFilterBuilder *runtime_color_filter_builder) -> const_sk_runtime_effect_child_ptr_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RUNTIME_COLOR_FILTER_BUILDER_H
