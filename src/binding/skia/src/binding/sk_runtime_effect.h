//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_SK_RUNTIME_EFFECT_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_runtime_effect_uniform.h"
#include "../static/static_sk_runtime_effect_child.h"
#include "../static/static_sk_runtime_effect_child_ptr.h"
#include "../static/static_sk_runtime_effect_result.h"
#include "../static/static_sk_runtime_effect_traced_shader.h"

extern "C" {
void SkRuntimeEffect_delete(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_makeShader(int sk_shader_key_out, int sk_data_key_in, SkRuntimeEffect *runtime_effect, sk_sp<SkShader> children[], size_t childCount, const SkMatrix *localMatrix);
void
SkRuntimeEffect_makeShader_2(int sk_shader_key_out, int sk_data_key_in,
                             int sk_runtime_effect_child_ptr_key_in, SkRuntimeEffect *runtime_effect,
                             const SkMatrix *localMatrix);
void SkRuntimeEffect_makeColorFilter(int sk_color_filter_key_out, int sk_data_key_in,
                                     SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_makeColorFilter_2(int sk_color_filter_key_out, int sk_data_key_in,
                                       SkRuntimeEffect *runtime_effect, sk_sp<SkColorFilter> children[],
                                       size_t childCount);
void SkRuntimeEffect_makeColorFilter_3(int sk_color_filter_key_out, int sk_data_key_in,
                                       int sk_runtime_effect_child_ptr_key_in, SkRuntimeEffect *runtime_effect);
void
SkRuntimeEffect_makeBlender(int sk_blender_key_out, int sk_data_key_in,
                            int sk_runtime_effect_child_ptr_key_in, SkRuntimeEffect *runtime_effect);
const std::string * SkRuntimeEffect_source(SkRuntimeEffect *runtime_effect);
size_t SkRuntimeEffect_uniformSize(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_uniforms(int sk_runtime_effect_uniform_key_out, SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_children(int sk_runtime_effect_child_key_out, SkRuntimeEffect *runtime_effect);
const SkRuntimeEffect::Uniform * SkRuntimeEffect_findUniform(SkRuntimeEffect *runtime_effect, std::string_view name);
const SkRuntimeEffect::Child * SkRuntimeEffect_findChild(SkRuntimeEffect *runtime_effect, std::string_view name);
bool SkRuntimeEffect_allowShader(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowColorFilter(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_allowBlender(SkRuntimeEffect *runtime_effect);
bool SkRuntimeEffect_unique(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_ref(SkRuntimeEffect *runtime_effect);
void SkRuntimeEffect_unref(SkRuntimeEffect *runtime_effect);
// static
void SkRuntimeEffect_MakeForColorFilter(int sk_runtime_effect_result_key_out, int sk_string_key_in,
                                        const SkRuntimeEffect::Options *options);
void SkRuntimeEffect_MakeForColorFilter_2(int sk_runtime_effect_result_key_out, int sk_string_key_in);
void SkRuntimeEffect_MakeForShader(int sk_runtime_effect_result_key_out, int sk_string_key_in, const SkRuntimeEffect::Options *options);
void SkRuntimeEffect_MakeForShader_2(int sk_runtime_effect_result_key_out, int sk_string_key_in);
void SkRuntimeEffect_MakeForBlender(int sk_runtime_effect_result_key_out, int sk_string_key_in, const SkRuntimeEffect::Options *options);
void SkRuntimeEffect_MakeForBlender_2(int sk_runtime_effect_result_key_out, int sk_string_key_in);
void SkRuntimeEffect_MakeTraced(int sk_runtime_effect_traced_shader_key_out, int sk_shader_key_in,
                                const SkIPoint *traceCoord);
void SkRuntimeEffect_RegisterFlattenables();
}

#endif //RAIA_SKIA_SK_RUNTIME_EFFECT_H
