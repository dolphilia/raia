//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_SK_RUNTIME_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkRuntimeEffect_delete(void *runtime_effect); // (SkRuntimeEffect *runtime_effect)
int SkRuntimeEffect_makeShader(void *runtime_effect, int data, void * children, unsigned long childCount, const void *localMatrix); // (SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix) -> sk_shader_t
int SkRuntimeEffect_makeShader_2(void *runtime_effect, int data, int runtime_effect_child_ptr, const void *localMatrix); // (SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr, const SkMatrix *localMatrix) -> sk_shader_t
int SkRuntimeEffect_makeColorFilter(void *runtime_effect, int data); // (SkRuntimeEffect *runtime_effect, sk_data_t data) -> sk_color_filter_t
int SkRuntimeEffect_makeColorFilter_2(void *runtime_effect, int data, void * children, unsigned long childCount); // (SkRuntimeEffect *runtime_effect, sk_data_t data, sk_sp<SkColorFilter> children[], size_t childCount) -> sk_color_filter_t
int SkRuntimeEffect_makeColorFilter_3(void *runtime_effect, int data, int runtime_effect_child_ptr); // (SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr) -> sk_color_filter_t
int SkRuntimeEffect_makeBlender(void *runtime_effect, int data, int runtime_effect_child_ptr); // (SkRuntimeEffect *runtime_effect, sk_data_t data, const_sk_runtime_effect_child_ptr_t runtime_effect_child_ptr) -> sk_blender_t
const void *SkRuntimeEffect_source(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> const std::string *
unsigned long SkRuntimeEffect_uniformSize(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> size_t
int SkRuntimeEffect_uniforms(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> int
int SkRuntimeEffect_children(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> int
const void *SkRuntimeEffect_findUniform(void *runtime_effect, int name); // (SkRuntimeEffect *runtime_effect, string_view_t name) -> const SkRuntimeEffect::Uniform *
const void *SkRuntimeEffect_findChild(void *runtime_effect, int name); // (SkRuntimeEffect *runtime_effect, string_view_t name) -> const SkRuntimeEffect::Child *
bool SkRuntimeEffect_allowShader(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> bool
bool SkRuntimeEffect_allowColorFilter(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> bool
bool SkRuntimeEffect_allowBlender(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> bool
bool SkRuntimeEffect_unique(void *runtime_effect); // (SkRuntimeEffect *runtime_effect) -> bool
void SkRuntimeEffect_ref(void *runtime_effect); // (SkRuntimeEffect *runtime_effect)
void SkRuntimeEffect_unref(void *runtime_effect); // (SkRuntimeEffect *runtime_effect)

// static

int SkRuntimeEffect_MakeForColorFilter(int string, const void *options); // (sk_string_t string, const SkRuntimeEffect::Options *options) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeForColorFilter_2(int string); // (sk_string_t string) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeForShader(int string, const void *options); // (sk_string_t string, const SkRuntimeEffect::Options *options) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeForShader_2(int string); // (sk_string_t string) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeForBlender(int string, const void *options); // (sk_string_t string, const SkRuntimeEffect::Options *options) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeForBlender_2(int string); // (sk_string_t string) -> sk_runtime_effect_result_t
int SkRuntimeEffect_MakeTraced(int shader, const void *traceCoord); // (sk_shader_t shader, const SkIPoint *traceCoord) -> sk_runtime_effect_result_t
void SkRuntimeEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_H
